/**
 * @file encodeur_rotatif.c
 * @author Thomas Pineau et Milovan Paget
 * @brief Implémentation de la gestion de l'encodeur rotatif avec détection de direction
 *
 * Ce module gère un encodeur rotatif en détectant la direction de rotation
 * grâce à une machine d'états et en implémentant un système d'anti-rebond
 * pour éviter les fausses détections.
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

#include "../epaper/epaper.h"

/** @brief Position actuelle de l'encodeur (volatile pour accès interrupt) */
volatile int encoderPos = 0;

/** @brief Dernière position de l'encodeur (volatile pour accès interrupt) */
volatile int lastPos = 0;

/** @brief Timestamp du dernier traitement d'anti-rebond (volatile pour accès interrupt) */
volatile uint32_t lastDebounceTime = 0;

/** @brief Temps d'anti-rebond en millisecondes (optimisé à 5ms) */
#define DEBOUNCE_TIME 5

/** @brief Fonction callback externe du menu principal pour traiter les mouvements d'encodeur */
extern void EPD_MenuEncoderCallback(int direction);

/** @brief Dernier état de l'encodeur sur 2 bits (volatile pour accès interrupt) */
static volatile uint8_t lastEncoderState = 0;

/** @brief Compteur de changements d'état (volatile pour accès interrupt) */
static volatile uint8_t stateChangeCount = 0;

/**
 * @brief Lit la valeur codée actuelle de l'encodeur rotatif
 *
 * Cette fonction lit les états des deux pins de l'encodeur rotatif
 * et combine leurs valeurs pour former un code sur 2 bits.
 *
 * @return int Valeur codée de l'encodeur (0-3)
 *         - 0 (00) : les deux pins sont à 0
 *         - 1 (01) : pin gauche=0, pin droit=1
 *         - 2 (10) : pin gauche=1, pin droit=0
 *         - 3 (11) : les deux pins sont à 1
 *
 * @pre Les GPIO BTN_GAUCHE_GPIO/BTN_GAUCHE_PIN et BTN_DROIT_GPIO/BTN_DROIT_PIN
 *      doivent être configurés en entrée
 * @post Aucun changement d'état, fonction de lecture pure
 *
 * @note MSB = pin gauche, LSB = pin droit
 * @note Formule : (MSB << 1) | LSB
 */
int readEncoder() {
    int MSB = HAL_GPIO_ReadPin(BTN_GAUCHE_GPIO, BTN_GAUCHE_PIN);
    int LSB = HAL_GPIO_ReadPin(BTN_DROIT_GPIO, BTN_DROIT_PIN);
    return (MSB << 1) | LSB;
}

/**
 * @brief Fonction de callback pour traiter les interruptions de l'encodeur rotatif
 *
 * Cette fonction implémente une machine d'états pour détecter la direction
 * de rotation de l'encodeur. Elle utilise les transitions entre états pour
 * déterminer si la rotation est horaire (CW) ou anti-horaire (CCW).
 *
 * @param pin Numéro du pin ayant généré l'interruption (non utilisé dans l'implémentation)
 *
 * @pre Les GPIO PA12 et PB5 doivent être configurés avec interruptions
 * @pre HAL_GetTick() doit retourner un timestamp valide
 * @pre La fonction externe EPD_MenuEncoderCallback() doit être définie
 * @post encoderPos est incrémenté/décrémenté selon la direction
 * @post lastEncoderState et lastDebounceTime sont mis à jour
 * @post EPD_MenuEncoderCallback est appelée avec la direction détectée
 *
 * @note Anti-rebond de 5ms pour filtrer les parasites électriques
 */
void encoder_callback(uint8_t pin)
{
    uint32_t currentTime = HAL_GetTick();

    // Anti-rebond temporel pour éviter les fausses détections
    if ((currentTime - lastDebounceTime) < DEBOUNCE_TIME) {
        return;
    }

    // Lecture de l'état actuel des pins A (PA12) et B (PB5) de l'encodeur
    uint8_t pinA = (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_12) != GPIO_PIN_RESET) ? 1 : 0;
    uint8_t pinB = (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5) != GPIO_PIN_RESET) ? 1 : 0;

    // Combinaison en un état sur 2 bits : pinA=MSB, pinB=LSB
    uint8_t currentState = (pinA << 1) | pinB;

    // Vérification si l'état a réellement changé (évite les traitements inutiles)
    if (currentState == lastEncoderState) {
        return;
    }

    // Détermination de la direction basée sur la transition d'état
    int8_t direction = 0;

    // Machine d'états pour détecter la direction de rotation
    // Basée sur les séquences de Gray typiques d'un encodeur rotatif
    switch (lastEncoderState) {
        case 0b00: // État 0 : 00
            if (currentState == 0b01) direction = 1;
            else if (currentState == 0b10) direction = -1;
            break;
        case 0b01: // État 1 : 01
            if (currentState == 0b11) direction = 1;
            else if (currentState == 0b00) direction = -1;
            break;
        case 0b11: // État 3 : 11
            if (currentState == 0b10) direction = 1;
            else if (currentState == 0b01) direction = -1;
            break;
        case 0b10: // État 2 : 10
            if (currentState == 0b00) direction = 1;
            else if (currentState == 0b11) direction = -1;
            break;
    }

    // Mise à jour de l'état et du timestamp
    lastEncoderState = currentState;
    lastDebounceTime = currentTime;

    // Traitement de la direction détectée
    if (direction == 1) {
        encoderPos++;
        printf("DOWN\r\n"); // Affichage console pour debug
        EPD_MenuEncoderCallback(-1); // Signal "descente" pour l'interface EPD
    } else if (direction == -1) {
        encoderPos--;
        printf("UP\r\n"); // Affichage console pour debug
        EPD_MenuEncoderCallback(1); // Signal "montée" pour l'interface EPD
    }
}
