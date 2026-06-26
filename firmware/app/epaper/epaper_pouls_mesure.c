/**
 * @file epaper_pouls_mesure.c
 * @author Thomas Pineau et Milovan Paget
 * @brief Gestion de la machine à états pour la mesure de pouls avec capteur HW827
 *
 * Ce fichier implémente la logique de mesure du pouls en utilisant le capteur HW827.
 * Il gère le processus complet de mesure : initialisation, acquisition des données,
 * calcul du BPM moyen et affichage des résultats sur l'écran e-paper.
 * La mesure s'effectue en temps réel avec traitement des battements détectés.
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
 * @brief Énumération des états de la machine à états de mesure de pouls
 *
 * Cette énumération définit les états du processus de mesure :
 * - MESURE : État d'acquisition et de traitement des données du capteur
 * - DONE : État d'affichage des résultats et d'attente avant retour
 */
typedef enum {
	MESURE,
	DONE
} State_t;

// Variables pour la gestion du menu
static uint32_t lastButtonCheck = 0;
#define MENU_CHECK_INTERVAL 10 ///< Intervalle de vérification des boutons en ms

static State_t currentState = MESURE; ///< État actuel de la machine à états de mesure

/**
 * @brief Machine à états pour la gestion complète de la mesure de pouls
 *
 * Cette fonction implémente le processus complet de mesure du pouls :
 * 1. Initialisation de l'affichage et démarrage de la mesure
 * 2. Acquisition continue des données du capteur HW827
 * 3. Traitement et calcul du BPM moyen
 * 4. Affichage des résultats pendant 5 secondes
 * 5. Retour automatique au menu précédent
 *
 * @return SM_State_t État de la machine (SM_RUNNING ou SM_FINISHED)
 * @pre Le capteur HW827 doit être initialisé et fonctionnel
 * @pre L'écran e-paper doit être prêt pour l'affichage
 * @post Une mesure complète de pouls est effectuée et affichée
 * @post Les données de mesure sont sauvegardées au format CSV
 */
SM_State_t EPD_Pouls_Mesure_StateMachine(void) {
    static bool mesure_started = false;    // Flag d'initialisation de la mesure
    static bool display_done = false;      // Flag d'affichage des résultats
    static uint32_t done_start_time = 0;   // Timestamp pour le délai d'affichage
    uint16_t nb_battements;                // Nombre de battements détectés
    static float bpm_moy;                  // BPM moyen calculé

    switch (currentState) {
        case MESURE:
            if (!mesure_started) {
                EPD_Display_Reset();            // Réinitialise l'écran une seule fois
                EPD_Display_MesureEnCours();   // Affiche l'interface de mesure
                mesure_started = true;
            }

            // Traitement continu des données du capteur HW827
            HW827_Recording_Process_1ms();
            HW827_Recording_PrintCSV();

            // Calcul du BPM moyen et nombre de battements
            calcule_bpm(&nb_battements, &bpm_moy);
            printf("Battements detectes : %u\r\n", nb_battements);
            printf("BPM moyen : %.2f\r\n", bpm_moy);

            currentState = DONE;
            return SM_RUNNING;

        case DONE:
            if (!display_done) {
                EPD_Display_MesureTerminee(bpm_moy);  // Affiche les résultats une seule fois
                done_start_time = HAL_GetTick(); // Démarre le timer d'affichage
                display_done = true;
            }

            // Attente non-bloquante de 5 secondes pour permettre à l'utilisateur de voir les résultats
            if (HAL_GetTick() - done_start_time >= 5000) {
            	// Réinitialisation des variables pour la prochaine mesure
            	currentState = MESURE;
            	mesure_started = false;
            	display_done = false;
            	done_start_time = 0;
                return SM_FINISHED;
            } else {
                return SM_RUNNING;
            }

        default:
            return SM_RUNNING;
    }
}
