/**
 * @file epaper_displays.c
 * @author Thomas Pineau et Milovan Paget
 * @brief Gestion de l'affichage e-paper avec machine à états et navigation de menu
 *
 * Ce fichier implémente une machine à états pour la gestion de l'affichage e-paper,
 * incluant la navigation dans les menus, l'affichage des différentes vues (pouls, pas, NFC)
 * et la gestion des interactions utilisateur via boutons et encodeur rotatif.
 *
 */

#include "stm32g4_sys.h"
#include "stm32g4_systick.h"
#include "stm32g4_gpio.h"
#include "stm32g4_uart.h"
#include "stm32g4_utils.h"

#include <stdio.h>

// Headers e-paper
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
 */
typedef enum {
    MAIN,           // État principal - initialisation du menu
    POULS,          // État de mesure du pouls
    PAS,            // État d'affichage de l'historique des pas
    NFC,            // État du menu NFC
    PARAMETRES,     // État des paramètres
    IDLE,           // État d'attente avec gestion du timeout
    DONE            // État de fin, retour au menu principal
} State_t;

/// État actuel de la machine à états
static State_t currentState = MAIN;

// Variables pour la gestion du menu
/// Position actuelle dans le menu (1-4)
int etatActuel = 1;
/// Indicateur de mise à jour nécessaire du menu
bool menuNeedsUpdate = true;
/// Dernière vérification des boutons (timestamp)
static uint32_t lastButtonCheck = 0;
/// Intervalle de vérification des boutons en millisecondes
#define MENU_CHECK_INTERVAL 10

/// Nombre total d'états dans le menu principal
int nombreEtats = 4;

/// Timestamp de début de l'état IDLE
static uint32_t idleStartTime = 0;
/// Timeout en millisecondes avant retour automatique au menu principal
#define IDLE_TIMEOUT_MS 7000

/**
 * @brief Machine à états principale pour la gestion de l'affichage e-paper
 *
 * Cette fonction gère les transitions entre les différents états de l'interface utilisateur,
 * incluant l'affichage des menus, la gestion du timeout d'inactivité et les transitions
 * vers les sous-modules (pouls, pas, NFC, paramètres).
 *
 * @return SM_State_t État de la machine (SM_RUNNING, SM_FINISHED)
 * @post L'affichage e-paper est mis à jour selon l'état actuel
 */
SM_State_t EPD_StateMachine(void) {
    switch (currentState) {
    case MAIN:
        // Initialisation du menu principal
        currentState = IDLE;
        idleStartTime = HAL_GetTick(); // Initialise le timer IDLE
        EPD_Display_Reset();
        EPD_Display_MenuPrincipal();
        return SM_RUNNING;

    case POULS:
        // Gestion de la mesure du pouls
        if (EPD_Pouls_StateMachine() == 1) {
            currentState = DONE;
            printf("Sortie de la machine à états EPD_POULS");
        }
        break;

    case PAS:
        // Affichage de l'historique des pas
        currentState = IDLE;
        idleStartTime = HAL_GetTick(); // Réinitialiser le timer IDLE
        EPD_Display_Reset();
        EPD_Display_HistoriquePas();
        return SM_RUNNING;

    case NFC:
        // Affichage du menu NFC
        currentState = IDLE;
        EPD_Display_Reset();
        EPD_Display_MenuNFC();
        return SM_RUNNING;

    case PARAMETRES:
        // Retour au menu principal depuis les paramètres
        currentState = MAIN;
        EPD_Display_Reset();
        return SM_RUNNING;

    case IDLE:
        // Gestion de l'état d'attente avec timeout
        if (HAL_GetTick() - idleStartTime > IDLE_TIMEOUT_MS) {
            currentState = MAIN;
            printf("Timeout IDLE - retour au menu principal");
            return SM_FINISHED;
        }
        EPD_HandleMenuNavigation();
        return SM_RUNNING;

    case DONE:
        // Fin d'un sous-module, retour au menu principal
        currentState = MAIN;
        printf("MAE_MENU secondaire: Finished");
        return SM_FINISHED;
    }
    return SM_RUNNING;
}

/**
 * @brief Gestion de la navigation dans le menu via les boutons
 *
 * Cette fonction vérifie périodiquement l'état du bouton central pour détecter
 * les sélections d'éléments de menu et déclenche les transitions d'état appropriées.
 * Elle gère également la mise à jour de l'affichage du menu.
 *
 * @pre L'état actuel doit être IDLE
 * @post La sélection du menu peut changer d'état ou l'affichage peut être mis à jour
 */
void EPD_HandleMenuNavigation(void) {
    uint32_t currentTime = HAL_GetTick();

    // Vérifier le bouton central pour sélection
    if (currentTime - lastButtonCheck > MENU_CHECK_INTERVAL) {
        lastButtonCheck = currentTime;

        if (read_central_button()) {
            // Bouton central pressé - sélectionner l'état actuel
            switch(etatActuel) {
            case 1:
                currentState = POULS;
                break;
            case 2:
                currentState = PAS;
                break;
            case 3:
                currentState = NFC;
                break;
            case 4:
                currentState = PARAMETRES;
                break;
            }
            menuNeedsUpdate = true;

            // Réinitialiser le timer IDLE lors d'une interaction
            idleStartTime = HAL_GetTick();
        }
    }

    if (menuNeedsUpdate) {
        EPD_UpdateMenuDisplay();
        menuNeedsUpdate = false;
    }
}

/**
 * @brief Callback appelé par l'encodeur rotatif pour changer la sélection du menu
 *
 * Cette fonction est appelée lorsque l'encodeur rotatif détecte une rotation.
 * Elle met à jour la position actuelle dans le menu avec gestion circulaire
 * et anti-rebond.
 *
 * @param direction Direction de rotation (>0: suivant, <0: précédent)
 * @pre direction doit être différent de 0
 * @post etatActuel est mis à jour et menuNeedsUpdate est activé
 */
void EPD_MenuEncoderCallback(int direction) {
    static uint32_t lastChangeTime = 0;
    uint32_t now = HAL_GetTick();

    // Anti-rebond : 100 ms
    if (now - lastChangeTime < 100) {
        return;
    }

    lastChangeTime = now;

    if (direction > 0) { // Avancer dans le menu
        etatActuel++;
        if (etatActuel > nombreEtats) {
            etatActuel = 1;
        }
    } else if (direction < 0) { // Reculer dans le menu
        etatActuel--;
        if (etatActuel < 1) {
            etatActuel = nombreEtats;
        }
    }

    menuNeedsUpdate = true;
}

/**
 * @brief Affichage du menu principal avec les 4 options disponibles
 *
 * Initialise et affiche le menu principal avec les icônes pour les différentes
 * fonctionnalités : statistiques, pouls, NFC et paramètres.
 *
 * @post Le menu principal est affiché sur l'e-paper
 * @post etatActuel est réinitialisé à 1
 */
void EPD_Display_MenuPrincipal(void) {
    #define NOMBRE_ETATS 4
    etatActuel = 1;  // Réinitialiser à l'état 1 quand on arrive sur le menu principal
    menuNeedsUpdate = true;

    // Affichage initial du menu
    EPD_DrawMenuFrames();
    EPD_UpdateMenuDisplay();
}

/**
 * @brief Dessine les cadres et icônes fixes du menu principal
 *
 * Cette fonction affiche les 4 boîtes du menu avec leurs icônes respectives :
 * - Statistiques (coin supérieur gauche)
 * - Pouls (coin supérieur droit)
 * - NFC/Hack (coin inférieur gauche)
 * - Paramètres (coin inférieur droit)
 *
 * @post Les éléments graphiques fixes du menu sont affichés
 */
void EPD_DrawMenuFrames(void) {
    // Dessiner les cadres et icônes du menu
    Paint_DrawBitMap_Paste(menuBox, 21, 21, 71, 71, false);
    Paint_DrawBitMap_Paste(statIcon, 21+(71/2)/2+1, 21+(71/2)/2+1, 36, 36, false);

    Paint_DrawBitMap_Paste(menuBox, 21+71+16, 21, 71, 71, false);
    Paint_DrawBitMap_Paste(hommeCoeur, 21+(71/2)/2+1+89, 21+(71/2)/2+1, 36, 36, false);

    Paint_DrawBitMap_Paste(menuBox, 21, 21+71+16, 71, 71, false);
    Paint_DrawBitMap_Paste(hack, 21+(71/2)/2+1, 21+(71/2)/2+1+87, 36, 36, false);

    Paint_DrawBitMap_Paste(menuBox, 21+71+16, 21+71+16, 71, 71, false);
    Paint_DrawBitMap_Paste(settings, 21+(71/2)/2+1+87, 21+(71/2)/2+1+87, 36, 36, false);
}

/**
 * @brief Met à jour les indicateurs de sélection du menu
 *
 * Affiche les points pleins/vides sous chaque option du menu pour indiquer
 * quelle option est actuellement sélectionnée.
 *
 * @pre etatActuel doit être entre 1 et 4
 * @post L'affichage e-paper est mis à jour avec les nouveaux indicateurs
 */
void EPD_UpdateMenuDisplay(void) {
    // Mettre à jour les indicateurs de sélection
    switch(etatActuel) {
        case 1:
            Paint_DrawBitMap_Paste(filledDot, 21+(71/2)-1, 21+71+5, 5, 5, false);
            Paint_DrawBitMap_Paste(emptyDot, 21+(71/2)-1+87, 21+71+5, 5, 5, false);
            Paint_DrawBitMap_Paste(emptyDot, 21+(71/2)-1, 21+(71/2)-1+87+43, 5, 5, false);
            Paint_DrawBitMap_Paste(emptyDot, 21+(71/2)-1+87, 21+(71/2)-1+87+43, 5, 5, false);
            break;
        case 2:
            Paint_DrawBitMap_Paste(emptyDot, 21+(71/2)-1, 21+71+5, 5, 5, false);
            Paint_DrawBitMap_Paste(filledDot, 21+(71/2)-1+87, 21+71+5, 5, 5, false);
            Paint_DrawBitMap_Paste(emptyDot, 21+(71/2)-1, 21+(71/2)-1+87+43, 5, 5, false);
            Paint_DrawBitMap_Paste(emptyDot, 21+(71/2)-1+87, 21+(71/2)-1+87+43, 5, 5, false);
            break;
        case 3:
            Paint_DrawBitMap_Paste(emptyDot, 21+(71/2)-1, 21+71+5, 5, 5, false);
            Paint_DrawBitMap_Paste(emptyDot, 21+(71/2)-1+87, 21+71+5, 5, 5, false);
            Paint_DrawBitMap_Paste(filledDot, 21+(71/2)-1, 21+(71/2)-1+87+43, 5, 5, false);
            Paint_DrawBitMap_Paste(emptyDot, 21+(71/2)-1+87, 21+(71/2)-1+87+43, 5, 5, false);
            break;
        case 4:
            Paint_DrawBitMap_Paste(emptyDot, 21+(71/2)-1, 21+71+5, 5, 5, false);
            Paint_DrawBitMap_Paste(emptyDot, 21+(71/2)-1+87, 21+71+5, 5, 5, false);
            Paint_DrawBitMap_Paste(emptyDot, 21+(71/2)-1, 21+(71/2)-1+87+43, 5, 5, false);
            Paint_DrawBitMap_Paste(filledDot, 21+(71/2)-1+87, 21+(71/2)-1+87+43, 5, 5, false);
            break;
    }
    EPD_1IN54_V2_DisplayPart(BlackImage);
}

/**
 * @brief Affichage du menu NFC avec 3 options
 *
 * Affiche le sous-menu NFC avec les options satellite, plume et note musicale,
 * avec l'option "Dupliquer" sélectionnée par défaut.
 *
 * @post L'interface NFC est affichée sur l'e-paper
 */
void EPD_Display_MenuNFC(void) {
    Paint_DrawBitMap_Paste(menuBoxPetit, 12, 68, 54, 54, false);
    Paint_DrawBitMap_Paste(satellite, 12+(54/2)/2-1, 158/2+1, 30, 30, false);
    Paint_DrawBitMap_Paste(emptyDot, 12+(54/2)-1, 130, 5, 5, false);

    Paint_DrawBitMap_Paste(menuBoxPetit, 200-12-53-53-8, 68, 54, 54, false);
    Paint_DrawBitMap_Paste(plume, 12+(54/2)/2+10+54-1, 158/2+1, 30, 30, false);
    Paint_DrawBitMap_Paste(filledDot, 12+(54/2)-1+7+54, 130, 5, 5, false);

    Paint_DrawBitMap_Paste(menuBoxPetit, 200-12-53, 68, 54, 54, false);
    Paint_DrawBitMap_Paste(mrnote, 12+(54/2)/2+10+54+4+54-1, 158/2+1, 30, 30, false);
    Paint_DrawBitMap_Paste(emptyDot, 12+(54/2)-1+7+54+7+54, 130, 5, 5, false);

    Paint_DrawString_EN(56, 163, "Dupliquer", &PixeloidSans18, BLACK, WHITE);
    EPD_1IN54_V2_DisplayPart(BlackImage);
}

/**
 * @brief Affichage de l'écran "Mesure en cours"
 *
 * Affiche un message d'information pendant qu'une mesure de pouls est en cours,
 * avec des instructions pour l'utilisateur.
 *
 * @post L'écran de mesure en cours est affiché
 */
void EPD_Display_MesureEnCours(void) {
    EPD_Display_Reset();
    Paint_DrawBitMap_Paste(cadre, 77, 17, 49, 49, false);



    Paint_DrawBitMap_Paste(info, 97, 29, 9, 23, false);




    Paint_DrawString_EN(15, 70, "Mesure en cours", &PixeloidSans18, BLACK, WHITE);
    Paint_DrawString_EN(21-3, 90+7, "   Ne bougez pas", &PixeloidSans15, BLACK, WHITE);
    Paint_DrawString_EN(22-3, 107+7, "pendant la mesure.", &PixeloidSans15, BLACK, WHITE);
    EPD_1IN54_V2_DisplayPart(BlackImage);
}

/**
 * @brief Affichage des résultats de mesure du pouls
 *
 * Affiche les résultats d'une mesure de pouls terminée avec succès,
 * incluant la valeur en BPM et une indication visuelle du niveau de santé.
 *
 * @param bpm_moy Fréquence cardiaque moyenne mesurée
 * @pre bpm_moy doit être une valeur positive valide
 * @post L'écran des résultats est affiché avec classification santé
 */
void EPD_Display_MesureTerminee(float bpm_moy) {
    EPD_Display_Reset();
    Paint_DrawBitMap_Paste(cadre, 77, 17, 49, 49, false);
    Paint_DrawBitMap_Paste(ok, 89, 33, 27, 19, false);
    Paint_DrawString_EN(15, 70, "Mesure terminee", &PixeloidSans18, BLACK, WHITE);

    Paint_DrawBitMap_Paste(coeur, 22+7, 114+33-38, 47, 36, false);

    char texte[20];
    sprintf(texte, "%d bpm", (int)roundf(bpm_moy));
    Paint_DrawString_EN(89-3, 113, texte, &PixeloidSans22, BLACK, WHITE);

    Paint_DrawBitMap_Paste(bande, 10-4, 165, 187, 21, false); // Bande des indicateurs de santé

    // Déterminer le niveau de santé à partir du pouls
    int dot_index;
    if (bpm_moy < 120) {
        dot_index = 0; // Zone verte
    } else if (bpm_moy < 160) {
        dot_index = 1; // Zone orange
    } else {
        dot_index = 2; // Zone rouge
    }

    int dot_x[3] = { 32-4+8, 97-4+8, 163-4+8 };

    // Affichage des indicateurs de santé
    for (int i = 0; i < 3; i++) {
        Paint_DrawBitMap_Paste(i == dot_index ? filledDot : emptyDot, dot_x[i], 189, 5, 5, false);
    }

    // Légendes des zones de fréquence cardiaque
    Paint_DrawString_EN(32-4, 169, "<120", &PixeloidSans12, BLACK, WHITE);
    Paint_DrawString_EN(97-4, 169, "<160", &PixeloidSans12, BLACK, WHITE);
    Paint_DrawString_EN(163-3, 169, ">160", &PixeloidSans12, BLACK, WHITE);

    EPD_1IN54_V2_DisplayPart(BlackImage);
}

/**
 * @brief Affichage de l'écran "Mesure annulée"
 *
 * Affiche un message d'erreur lorsqu'une mesure de pouls a été interrompue
 * ou a échoué, avec des conseils pour l'utilisateur.
 *
 * @post L'écran d'annulation est affiché
 */
void EPD_Display_MesureAnnulee(void) {
    Paint_DrawBitMap_Paste(cadre, 77, 17, 49, 49, false);
    Paint_DrawBitMap_Paste(croix, 91, 31, 21, 21, false);
    Paint_DrawString_EN(20, 70, "Mesure annulee", &PixeloidSans18, BLACK, WHITE);
    Paint_DrawString_EN(21-3, 90+7, "   Ne bougez pas", &PixeloidSans15, BLACK, WHITE);
    Paint_DrawString_EN(22-3, 107+7, "pendant la mesure.", &PixeloidSans15, BLACK, WHITE);
}

/**
 * @brief Affichage de l'historique des pas avec navigation
 *
 * Affiche les données d'activité physique pour une date donnée,
 * incluant le nombre de pas et la distance parcourue, avec des flèches
 * de navigation pour changer de jour.
 *
 * @post L'écran historique des pas est affiché
 */
void EPD_Display_HistoriquePas(void) {
    EPD_Display_Reset();

    // Navigation par flèches
    Paint_DrawBitMap_Paste(leftArrow, 9, 155, 33, 33, false);
    Paint_DrawString_EN(52, 163, "mar 29/04", &PixeloidSans16, BLACK, WHITE);
    Paint_DrawBitMap_Paste(rightArrow, 158, 155, 33, 33, false);

    // Icônes et données d'activité
    Paint_DrawBitMap_Paste(montagne, 33-3, 32, 45, 45, false);
    Paint_DrawBitMap_Paste(position, 34-3, 92, 45, 45, false);
    Paint_DrawString_EN(90-3, 45, "2904 pas", &PixeloidSans18, BLACK, WHITE);
    Paint_DrawString_EN(90-3, 106, "4.6 km", &PixeloidSans18, BLACK, WHITE);

    EPD_1IN54_V2_DisplayPart(BlackImage);
}

/**
 * @brief Affichage de l'écran d'accueil avec informations de base
 *
 * Affiche l'heure, la date et les statistiques quotidiennes (pas et distance)
 * sur l'écran principal en mode veille.
 *
 * @param pas Nombre de pas effectués dans la journée
 * @pre pas doit être une valeur positive
 * @post L'écran d'accueil est affiché avec les informations actualisées
 */
void EPD_Display_Idle(uint16_t pas) {
    //Paint_DrawString_EN(49, 16, RTC_GetDate(), &PixeloidSans18, BLACK, WHITE);
    //Paint_DrawString_EN(40, 40, RTC_GetHeure(), &PixeloidSans36, BLACK, WHITE);

    Paint_DrawBitMap(image);

    /*char texte_pas[20];
    sprintf(texte_pas, "%d", pas);
    //Paint_DrawString_EN(57-4-3-2, 165, texte_pas, &PixeloidSans16, BLACK, WHITE);
    Paint_DrawString_EN(57-4-3-2, 165, "0", &PixeloidSans16, BLACK, WHITE);

    Paint_DrawBitMap_Paste(petite_position, 110-4-3-2, 158, 29, 28, false);

    // Conversion pas vers kilomètres (approximation : 1 km ≈ 1400 pas)
    float km = pas / 1400.0;
    char texte_km[20];
    sprintf(texte_km, "%.1f km", km);
    //Paint_DrawString_EN(150-4-4-3-2, 165, texte_km, &PixeloidSans16, BLACK, WHITE);
    Paint_DrawString_EN(150-4-4-3-2, 165, "0.0 km", &PixeloidSans16, BLACK, WHITE);*/


    EPD_1IN54_V2_Display(BlackImage);
}

/**
 * @brief Affichage de l'image de base sur l'e-paper
 *
 * Fonction utilitaire pour afficher l'image de base stockée en mémoire.
 *
 * @post L'image de base est affichée sur l'e-paper
 */
void EPD_DisplayBaseImage(void) {
    EPD_1IN54_V2_DisplayPartBaseImage(BlackImage);
}

/**
 * @brief Démonstration des mises à jour partielles de l'écran
 *
 * Fonction de test qui montre différentes animations et transitions
 * entre les écrans pour démontrer les capacités de mise à jour partielle
 * de l'e-paper.
 *
 * @post Une séquence d'animations est affichée puis retour au menu principal
 */
void EPD_PartialUpdate(void) {
    // Effacement complet
    Paint_DrawRectangle(0, 0, Paint.Width - 1, Paint.Height - 1, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    EPD_1IN54_V2_DisplayPart(BlackImage);

    // Affichage des éléments fixes
    Paint_DrawBitMap_Paste(leftArrow, 9, 155, 33, 33, false);
    Paint_DrawBitMap_Paste(rightArrow, 158, 155, 33, 33, false);
    Paint_DrawBitMap_Paste(montagne, 33-3, 32, 45, 45, false);
    Paint_DrawBitMap_Paste(position, 34-3, 92, 45, 45, false);
    EPD_1IN54_V2_DisplayPart(BlackImage);

    HAL_Delay(200);

    Paint_DrawString_EN(90-3, 45, "2907 pas", &PixeloidSans18, BLACK, WHITE);
    Paint_DrawString_EN(52, 163, "mar 29/04", &PixeloidSans16, BLACK, WHITE);
    Paint_DrawString_EN(90-3, 106, "4.6 km", &PixeloidSans18, BLACK, WHITE);
    EPD_1IN54_V2_DisplayPart(BlackImage);

    HAL_Delay(200);

    // Effacement des données
    Paint_DrawString_EN(90-3, 45, "2907 pas", &PixeloidSans18, BLACK, BLACK);
    Paint_DrawString_EN(52, 163, "mar 29/04", &PixeloidSans16, BLACK, BLACK);
    Paint_DrawString_EN(90-3, 106, "4.6 km", &PixeloidSans18, BLACK, BLACK);
    EPD_1IN54_V2_DisplayPart(BlackImage);

    HAL_Delay(100);

    Paint_DrawString_EN(90-3, 45, "8412 pas", &PixeloidSans18, BLACK, WHITE);
    Paint_DrawString_EN(52, 163, "mer 30/04", &PixeloidSans16, BLACK, WHITE);
    Paint_DrawString_EN(90-3, 106, "7.3 km", &PixeloidSans18, BLACK, WHITE);
    EPD_1IN54_V2_DisplayPart(BlackImage);

    HAL_Delay(200);

    // Effacement des données
    Paint_DrawString_EN(90-3, 45, "8412 pas", &PixeloidSans18, BLACK, BLACK);
    Paint_DrawString_EN(52, 163, "mer 30/04", &PixeloidSans16, BLACK, BLACK);
    Paint_DrawString_EN(90-3, 106, "7.3 km", &PixeloidSans18, BLACK, BLACK);
    EPD_1IN54_V2_DisplayPart(BlackImage);

    HAL_Delay(300);

    Paint_DrawString_EN(90-3, 45, "11645 pas", &PixeloidSans18, BLACK, WHITE);
    Paint_DrawString_EN(52, 163, "jeu 01/05", &PixeloidSans16, BLACK, WHITE);
    Paint_DrawString_EN(90-3, 106, "12.2 km", &PixeloidSans18, BLACK, WHITE);
    EPD_1IN54_V2_DisplayPart(BlackImage);

    HAL_Delay(300);

    // Effacement complet
    Paint_DrawRectangle(0, 0, Paint.Width - 1, Paint.Height - 1, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    EPD_1IN54_V2_DisplayPart(BlackImage);

    HAL_Delay(500);

    // Démonstration du menu principal
    EPD_Display_MenuPrincipal();
    EPD_1IN54_V2_DisplayPart(BlackImage);
    HAL_Delay(300);

    Paint_DrawRectangle(0, 0, Paint.Width - 1, Paint.Height - 1, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    EPD_1IN54_V2_DisplayPart(BlackImage);

    HAL_Delay(500);

    // Démonstration du menu NFC
    EPD_Display_MenuNFC();
    EPD_1IN54_V2_DisplayPart(BlackImage);
    HAL_Delay(300);

    Paint_DrawRectangle(0, 0, Paint.Width - 1, Paint.Height - 1, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    EPD_1IN54_V2_DisplayPart(BlackImage);
}

/**
 * @brief Réinitialisation de l'affichage e-paper
 *
 * Efface complètement l'écran e-paper en le remplissant de noir,
 * préparant ainsi l'affichage pour de nouveaux contenus.
 *
 */
void EPD_Display_Reset(void) {
    Paint_DrawRectangle(0, 0, Paint.Width - 1, Paint.Height - 1, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    EPD_1IN54_V2_DisplayPart(BlackImage);
}
