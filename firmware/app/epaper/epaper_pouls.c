/**
 * @file epaper_pouls.c
 * @author Thomas Pineau et Milovan Paget
 * @brief Gestion de la machine à états pour l'interface utilisateur de mesure de pouls sur écran e-paper
 *
 * Ce fichier implémente une machine à états pour gérer l'interface utilisateur d'un système
 * de mesure de pouls utilisant un écran e-paper. Il gère la navigation dans les menus,
 * les transitions entre les différents états (menu, mesure, historique) et l'affichage
 * des éléments graphiques sur l'écran e-paper.
 */

#include "stm32g4_sys.h"
#include "stm32g4_systick.h"
#include "stm32g4_gpio.h"
#include "stm32g4_uart.h"
#include "stm32g4_utils.h"

#include <stdio.h>

// En-têtes Epaper
#include "./epaper/stm32g4_epaper_com.h"
#include "./epaper/stm32g4_epaper_paint.h"
#include "epaper.h"
#include "epaper_bitmaps.h"

#include "config.h"

#include "./rtc/rtc.h"

#include "./boutons/bouton_central.h"
#include "./boutons/encodeur_rotatif.h"

#include "epaper_displays.h"
#include "epaper_pouls.h"

/**
 * @brief Énumération des états de la machine à états principale
 *
 * Cette énumération définit les différents états possibles du système :
 * - MENU : Affichage du menu principal
 * - MESURE : Mode de mesure du pouls
 * - HISTORIQUE : Consultation de l'historique des mesures
 * - IDLE : État d'attente avec timeout
 * - DONE : État de fin, retour au menu
 */
typedef enum {
	MENU,
	MESURE,
	HISTORIQUE,
	IDLE,
	DONE
} State_t;

// Variables pour la gestion du menu
static uint32_t lastButtonCheck = 0;
#define MENU_CHECK_INTERVAL 10 ///< Intervalle de vérification des boutons en ms

static uint32_t idleStartTime = 0;
#define IDLE_TIMEOUT_MS 7000  ///< Timeout d'inactivité en ms (7 secondes)

static State_t currentState = MENU; ///< État actuel de la machine à états

/**
 * @brief Machine à états principale pour la gestion de l'interface de mesure de pouls
 *
 * Cette fonction implémente la logique de la machine à états principale qui gère
 * les transitions entre les différents modes de l'application (menu, mesure, historique).
 * Elle gère également le timeout d'inactivité et les retours automatiques au menu.
 *
 * @return SM_State_t État de la machine à états (SM_RUNNING ou SM_FINISHED)
 * @pre Le système doit être initialisé correctement
 * @post L'état de la machine est mis à jour selon la logique définie
 */
SM_State_t EPD_Pouls_StateMachine(void) {
    switch (currentState) {
		case MENU:
			currentState = IDLE;
			idleStartTime = HAL_GetTick(); // Initialise le timer IDLE
			EPD_Display_Reset();
			EPD_Pouls_Display_MenuPouls();
			printf("Entrée dans le MENU");
			return SM_RUNNING;
		case MESURE:
	        if (EPD_Pouls_Mesure_StateMachine() == 1) {
				currentState = DONE;
	            printf("Sortie de la machine à états EPD_POULS_MESURE");
	        }
			return SM_RUNNING;
		case HISTORIQUE:
			currentState = DONE;
			EPD_Display_Reset();
			return SM_RUNNING;
		case IDLE:
	        // Vérifier le timeout IDLE
	        if (HAL_GetTick() - idleStartTime > IDLE_TIMEOUT_MS) {
	            currentState = MENU;
	            printf("Timeout IDLE - retour au menu principal");
	            return SM_FINISHED;
	        }
			EPD_Pouls_HandleMenuNavigation();
			return SM_RUNNING;
		case DONE:
			currentState = MENU;
			printf("MAE_POULS secondaire: Finished");
			return SM_FINISHED;
    }
    return SM_RUNNING;
}

/**
 * @brief Gestionnaire de la navigation dans le menu principal
 *
 * Cette fonction gère les interactions utilisateur dans le menu principal,
 * notamment la détection des pressions sur le bouton central avec anti-rebond
 * et la mise à jour de l'affichage du menu selon les sélections.
 *
 * @pre L'écran e-paper doit être initialisé
 * @pre Les variables globales etatActuel et menuNeedsUpdate doivent être définies
 * @post L'état de la machine peut changer vers MESURE ou HISTORIQUE selon la sélection
 * @post L'affichage du menu est mis à jour si nécessaire
 */
void EPD_Pouls_HandleMenuNavigation(void) {
    uint32_t currentTime = HAL_GetTick();

    // Vérifier le bouton central (anti-rebond)
    if (currentTime - lastButtonCheck > MENU_CHECK_INTERVAL) {
        lastButtonCheck = currentTime;

        if (read_central_button()) {
            switch(etatActuel) {
                case 1:
                    currentState = MESURE;
                    printf("ENTREE DANS ETAT MESURE");
                    break;
                case 2:
                    currentState = HISTORIQUE;
                    printf("ENTREE DANS ETAT HISTORIQUE");
                    break;
            }
            menuNeedsUpdate = true;
        }
    }

    if (menuNeedsUpdate) {
        EPD_Pouls_UpdateMenuDisplay();
        menuNeedsUpdate = false;
    }
}

/**
 * @brief Dessine les cadres et icônes du menu principal
 *
 * Cette fonction affiche les éléments graphiques statiques du menu :
 * les boîtes de sélection et les icônes associées à chaque option
 * (statistiques et mesure de pouls).
 *
 * @pre L'écran e-paper doit être initialisé
 * @pre Les bitmaps menuBox, statIcon et hommeCoeur doivent être définis
 * @post Les éléments graphiques du menu sont dessinés sur l'écran
 */
void EPD_Pouls_DrawMenuFrames(void) {
    // Dessiner les cadres et icônes du menu
    Paint_DrawBitMap_Paste(menuBox, 21, 50+9, 71, 71, false);
    Paint_DrawBitMap_Paste(statIcon, 21+(71/2)/2+1, 21+(71/2)/2+1+29+9, 36, 36, false);

    Paint_DrawBitMap_Paste(menuBox, 21+71+16, 50+9, 71, 71, false);
    Paint_DrawBitMap_Paste(hommeCoeur, 21+(71/2)/2+1+89, 21+(71/2)/2+1+29+9, 36, 36, false);
}

/**
 * @brief Met à jour l'affichage du menu selon la sélection actuelle
 *
 * Cette fonction actualise les indicateurs visuels de sélection dans le menu
 * (points remplis/vides) et les textes correspondants selon l'état actuel du menu.
 * Elle gère la navigation circulaire entre les options.
 *
 * @pre etatActuel doit être défini (1 ou 2)
 * @pre Les bitmaps filledDot et emptyDot doivent être définis
 * @pre La police PixeloidSans18 doit être disponible
 * @post L'affichage du menu est mis à jour avec la sélection actuelle
 * @post L'écran e-paper affiche partiellement les modifications
 */
void EPD_Pouls_UpdateMenuDisplay(void) {
    if (etatActuel > 2) etatActuel = 1;
    if (etatActuel < 1) etatActuel = 2;

    // Mettre à jour les indicateurs de sélection
    switch(etatActuel) {
		case 1:
			Paint_DrawBitMap_Paste(filledDot, 21+(71/2)-1, 21+71+5+29+13, 5, 5, false);
			Paint_DrawBitMap_Paste(emptyDot, 21+(71/2)-1+87, 21+71+5+29+13, 5, 5, false);
		    Paint_DrawString_EN(50, 167, "Historique", &PixeloidSans18, BLACK, BLACK); // Efface le texte précédent
		    Paint_DrawString_EN(56, 167, "Mesurer", &PixeloidSans18, BLACK, WHITE);
			break;
		case 2:
			Paint_DrawBitMap_Paste(emptyDot, 21+(71/2)-1, 21+71+5+29+13, 5, 5, false);
			Paint_DrawBitMap_Paste(filledDot, 21+(71/2)-1+87, 21+71+5+29+13, 5, 5, false);
		    Paint_DrawString_EN(56, 167, "Mesurer", &PixeloidSans18, BLACK, BLACK); // Efface le texte précédent
		    Paint_DrawString_EN(50, 167, "Historique", &PixeloidSans18, BLACK, WHITE);
			break;
    }
    EPD_1IN54_V2_DisplayPart(BlackImage);
}

/**
 * @brief Initialise et affiche le menu principal de mesure de pouls
 *
 * Cette fonction configure les paramètres initiaux du menu (nombre d'états, état actuel)
 * et déclenche l'affichage complet du menu avec ses cadres et indicateurs de sélection.
 *
 * @pre L'écran e-paper doit être initialisé
 * @pre Les variables globales nombreEtats, etatActuel et menuNeedsUpdate doivent être définies
 * @post Le menu est affiché avec l'état initial (état 1 sélectionné)
 * @post Les variables de gestion du menu sont initialisées
 */
void EPD_Pouls_Display_MenuPouls(void) {
	#define NOMBRE_ETATS 2 ///< Nombre d'options dans le menu principal
	nombreEtats = 2;
	etatActuel = 1;  // Réinitialiser à l'état 1 quand on arrive sur le menu principal
	menuNeedsUpdate = true;

	// Affichage du menu
	EPD_Pouls_DrawMenuFrames();
	EPD_Pouls_UpdateMenuDisplay();
}
