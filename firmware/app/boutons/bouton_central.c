/**
 * @file bouton_central.c
 * @author Milovan Paget
 * @brief Implémentation de la gestion du bouton central avec anti-rebond
 *
 * Ce module gère la lecture du bouton central en implémentant un système
 * d'anti-rebond temporel pour éviter les fausses détections dues aux
 * rebonds mécaniques du bouton.
 */

#include "config.h"
#include "stm32g4_sys.h"

#include "stm32g4_systick.h"
#include "stm32g4_gpio.h"
#include "stm32g4_uart.h"
#include "stm32g4_utils.h"
#include "stm32g4_adc.h"
#include "stm32g4_rtc.h"
#include "stm32g4_extit.h"

/** @brief Temps d'anti-rebond en millisecondes */
#define DEBOUNCE_TIME 50

/**
 * @brief Lit l'état du bouton central avec détection de front montant et anti-rebond
 *
 * Cette fonction implémente un système d'anti-rebond temporel pour détecter
 * uniquement les nouveaux appuis sur le bouton central. Elle utilise des
 * variables statiques pour mémoriser l'état précédent et le temps du dernier appui.
 *
 * @return true si le bouton vient d'être pressé (front montant détecté)
 * @return false si le bouton n'est pas pressé ou s'il était déjà pressé
 *
 * @pre Le GPIO du bouton central (BTN_CENTRAL_GPIO, BTN_CENTRAL_PIN) doit être configuré
 * @pre HAL_GetTick() doit être fonctionnel pour la gestion temporelle
 * @post Les variables statiques internes sont mises à jour
 *
 * @note Utilise un délai d'anti-rebond de 50ms pour filtrer les rebonds
 * @note La fonction détecte uniquement les fronts montants (transition 0→1)
 * @note Variables statiques utilisées pour la persistance entre appels :
 *       - last_state : dernier état lu du bouton
 *       - last_press_time : timestamp du dernier appui valide
 */
bool read_central_button() {
    static bool last_state = false;            // Dernier état du bouton
    static uint32_t last_press_time = 0;       // Timestamp du dernier appui

    // Lecture de l'état actuel du bouton (GPIO_PIN_SET = bouton pressé)
    bool current_state = HAL_GPIO_ReadPin(BTN_CENTRAL_GPIO, BTN_CENTRAL_PIN) == GPIO_PIN_SET;

    // Détection du front montant avec anti-rebond
    if (current_state && !last_state) { // Front montant détecté
        uint32_t current_time = HAL_GetTick();

        // Vérification de l'anti-rebond (délai de 50ms minimum)
        if (current_time - last_press_time > DEBOUNCE_TIME) {
            last_press_time = current_time;
            last_state = current_state;
            return true; // Nouvel appui valide détecté
        }
    }

    // Mise à jour de l'état pour le prochain appel
    last_state = current_state;
    return false; // Pas de nouvel appui
}
