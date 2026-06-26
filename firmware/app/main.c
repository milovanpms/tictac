/**
 * @file main.c
 * @author Thomas Pineau et Milovan Paget
 * @brief Fichier principal du projet de montre connectée avec écran e-paper, podomètre, capteur de pouls et communication Bluetooth
 * @date 12 mai 2025
 * @version 1.0
 *
 * Ce fichier contient la machine à états principale du système embarqué qui gère :
 * - L'affichage sur écran e-paper 1.54"
 * - Le comptage de pas via le capteur MPU6050
 * - La mesure du pouls avec le capteur HW827
 * - La communication Bluetooth HC-05
 * - L'interface utilisateur (boutons et encodeur rotatif)
 * - La gestion du temps via RTC
 *
 * @note Basé sur la documentation Waveshare : https://www.waveshare.com/wiki/1.54inch_e-Paper_Module_(B)_Manual#Working_With_STM32
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
#include "stm32g4_timer.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Bibliothèques Bluetooth (HC-05)
#include "./HC-05/stm32g4_hc05.h"
#include "./bluetooth/bluetooth_msg_process.h"

// Bibliothèque podomètre (MPU6050)
#include "./MPU6050/stm32g4_mpu6050.h"

// Bibliothèques écran e-paper
#include "./epaper/epaper.h"
#include "./epaper/epaper_displays.h"

// Bibliothèque RTC
#include "./rtc/rtc.h"

// Bibliothèques bouton central et encodeur rotatif
#include "./boutons/bouton_central.h"
#include "./boutons/encodeur_rotatif.h"

// Bibliothèque capteur de pouls (HW827)
#include "./heartbeat/heartbeat.h"

/**
 * @brief Énumération des états de la machine à états principale
 *
 * Cette énumération définit les différents états possibles du système :
 * - INIT : Phase d'initialisation de tous les périphériques
 * - IDLE : Mode veille avec affichage et actualisation de l'heure
 * - MENU : Navigation dans le menu principal
 * - DETECTION : Détection active des entrées utilisateur
 */
typedef enum {
    INIT,      // Initialisation des périphériques
    IDLE,      // Veille, affichage et actualisation de l'heure
    MENU,      // Menu principal
    DETECTION  // Détection active d'une entrée utilisateur
} State_t;

// Variables globales du système

/** @brief Structure de données du capteur MPU6050 */
MPU6050_t MPU6050_Data;

/** @brief Compteur de pas détectés par interruption */
volatile uint16_t pas_interupt = 0;

/** @brief Variable pour la mesure de l'encodeur rotatif */
volatile int lastEncoded = 0;

/** @brief État actuel de la machine à états */
State_t currentState = INIT;

/** @brief Indicateur du mode veille (true si en mode IDLE) */
bool inIdleMode = true;

/**
 * @brief Vérifie si un caractère a été reçu sur l'UART spécifié
 *
 * Cette fonction permet de détecter la réception d'un caractère sur une interface UART
 * sans bloquer l'exécution du programme.
 *
 * @param uart_id Identifiant de l'interface UART à vérifier
 * @return true si un caractère a été reçu, false sinon
 *
 * @pre L'interface UART doit être initialisée
 * @post Le caractère reçu est consommé s'il y en a un
 */
bool char_received(uart_id_t uart_id)
{
    if (BSP_UART_data_ready(uart_id))
    {
        BSP_UART_get_next_byte(uart_id);
        return true;
    }
    else
        return false;
}

/**
 * @brief Vérifie et met à jour l'affichage de l'heure si nécessaire
 *
 * Cette fonction compare l'heure actuelle avec la précédente et met à jour
 * l'affichage sur l'écran e-paper uniquement si l'heure ou la date a changé.
 * L'optimisation évite les rafraîchissements inutiles de l'écran.
 *
 * @pre Le système RTC doit être initialisé
 * @pre L'écran e-paper doit être initialisé
 * @pre Le système doit être en mode IDLE
 * @post L'affichage est mis à jour si l'heure/date a changé
 *
 * @note Cette fonction ne fait rien si le système n'est pas en mode IDLE
 */
void check_and_update_time_display() {
    static RTC_TimeTypeDef previousTime = {0};
    static RTC_DateTypeDef previousDate = {0};
    static bool first_run = true;

    if (!inIdleMode) return; // Ne pas mettre à jour si pas en mode IDLE

    RTC_TimeTypeDef currentTime;
    RTC_DateTypeDef currentDate;
    BSP_RTC_get_time_and_date(&currentTime, &currentDate);

    // Vérifier si l'heure ou la date ont changé
    if (first_run ||
        currentTime.Minutes != previousTime.Minutes ||
        currentTime.Hours != previousTime.Hours ||
        currentDate.Date != previousDate.Date) {

        // Mettre à jour l'affichage avec le nombre de pas
        EPD_Display_Idle(pas_interupt);

        // Sauvegarder l'heure et la date actuelles
        previousTime = currentTime;
        previousDate = currentDate;
        first_run = false;
    }
}

/**
 * @brief Machine à états principale du système
 *
 * Cette fonction implémente la logique principale du système.
 * Elle gère les transitions entre les différents états :
 * - Initialisation complète du système
 * - Mode veille avec affichage de l'heure
 * - Navigation dans les menus
 * - Détection des interactions utilisateur
 *
 * @pre Aucune précondition spécifique
 * @post L'état du système peut changer selon les conditions
 *
 * @note Cette fonction est appelée en boucle infinie dans main()
 */
void stateMachine() {
    static RTC_TimeTypeDef previousTime = {0};
    static RTC_DateTypeDef previousDate = {0};
    static bool first_run = true;

    switch (currentState) {
        case INIT:
            printf("Initialisation du système...\n");
            currentState = IDLE;

            // Initialisation de la couche d'abstraction matérielle STM32
            HAL_Init();

            // Configuration des broches GPIO
            BSP_GPIO_enable();

            // Initialisation UART2 pour le débogage (115200 bauds)
            BSP_UART_init(UART2_ID, 115200);
            BSP_SYS_set_std_usart(UART2_ID, UART2_ID, UART2_ID);

            // Initialisation UART1 pour la communication Bluetooth (115200 bauds)
            BSP_UART_init(UART1_ID, 115200);

            // Initialisation du convertisseur analogique-numérique
            BSP_ADC_init();

            // Initialisation de l'horloge temps réel
            RTC_Init();

            // Initialisation du capteur de mouvement MPU6050
            if (MPU6050_Init(&MPU6050_Data, GPIOA, GPIO_PIN_0, MPU6050_Device_0,
                             MPU6050_Accelerometer_8G, MPU6050_Gyroscope_2000s) != MPU6050_Result_Ok) {
                printf("Erreur lors de l'initialisation du MPU6050\n");
                while(1); // Blocage en cas d'erreur critique
            } else {
                printf("MPU6050 initialisé avec succès\n");
            }

            // Configuration du Timer 4 pour la détection de pas (période de 30 ms)
            BSP_TIMER_run_us(TIMER4_ID, 30000, true);

            // Configuration de la LED verte comme sortie
            BSP_GPIO_pin_config(LED_GREEN_GPIO, LED_GREEN_PIN, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_HIGH, GPIO_NO_AF);

            // Configuration des boutons de l'encodeur rotatif avec interruptions
            BSP_GPIO_pin_config(BTN_GAUCHE_GPIO, BTN_GAUCHE_PIN, GPIO_MODE_IT_RISING_FALLING, GPIO_PULLUP, GPIO_SPEED_FREQ_LOW, GPIO_NO_AF);
            BSP_GPIO_pin_config(BTN_DROIT_GPIO, BTN_DROIT_PIN, GPIO_MODE_IT_RISING_FALLING, GPIO_PULLUP, GPIO_SPEED_FREQ_LOW, GPIO_NO_AF);

            // Configuration du bouton central comme entrée
            BSP_GPIO_pin_config(BTN_CENTRAL_GPIO, BTN_CENTRAL_PIN, GPIO_MODE_INPUT, GPIO_PULLDOWN, GPIO_SPEED_FREQ_LOW, GPIO_NO_AF);

            // Enregistrement des callbacks pour les interruptions de l'encodeur
            BSP_EXTIT_set_callback(encoder_callback, 12, true);  // Broche PA12
            BSP_EXTIT_set_callback(encoder_callback, 5, true);   // Broche PB5

            // Initialisation de l'état de l'encodeur
            lastEncoded = readEncoder();

            // Initialisation du capteur de pouls HW827
            HW827_Init();

            // Initialisation de l'interface SPI pour l'écran e-paper
            EPD_SPI_Init();

            // Initialisation du module écran
            DEV_Module_Init();

            // Initialisation de l'écran en mode partiel (plus rapide)
            EPD_Init();

            // Affichage de l'image de base
            EPD_DisplayBaseImage();

            inIdleMode = true;
            printf("Initialisation terminée\n");

            break;

        case IDLE:
            printf("Passage en mode IDLE\n");
            currentState = DETECTION;

            // Réinitialisation de l'écran et affichage de l'état de veille
            EPD_Display_Reset();
            EPD_Display_Idle(pas_interupt);

            // Activation du mode veille
            inIdleMode = true;

            // Mémorisation de l'heure actuelle pour éviter les rafraîchissements inutiles
            BSP_RTC_get_time_and_date(&previousTime, &previousDate);
            first_run = false;

            break;

        case MENU:
            // Désactivation du mode veille lors de l'entrée dans un menu
            inIdleMode = false;

            // Exécution de la machine à états de l'écran
            if (EPD_StateMachine() == 1) {
                currentState = IDLE;
                printf("Sortie de la machine à états EPD\n");
            }
            break;

        case DETECTION:
            // Traitement des données reçues via UART (Bluetooth)
            handle_uart_reception();

            // Vérification et mise à jour de l'affichage de l'heure
            check_and_update_time_display();

            // Affichage périodique du nombre de pas (pour le débogage)
            //printf("Pas détectés : %u\r\n", pas_interupt);

            // Détection de l'appui sur le bouton central
            if (read_central_button()) {
                BSP_UART_puts(UART2_ID, "BOUTON CENTRAL APPUYÉ\r\n", strlen("BOUTON CENTRAL APPUYÉ\r\n"));
                currentState = MENU;
                printf("Entrée dans le menu\n");
            }
            break;

        default:
            // État non défini, retour à l'initialisation
            printf("État inconnu, retour à l'initialisation\n");
            currentState = INIT;
            break;
    }
}

/**
 * @brief Fonction principale du programme
 *
 * Point d'entrée du programme qui lance la boucle infinie de la machine à états.
 * Le système fonctionne en mode événementiel, traitant continuellement les
 * entrées utilisateur et les données des capteurs.
 *
 * @return int Code de retour (jamais atteint dans ce cas)
 *
 * @pre Tous les périphériques matériels doivent être correctement connectés
 * @post Le système fonctionne en continu jusqu'à extinction
 *
 * @note Cette fonction ne se termine jamais en fonctionnement normal
 */
int main(void) {
    printf("Démarrage du système de Tictac\n");

    // Boucle principale infinie
    while (1) {
        stateMachine();
    }

    return 0; // Jamais atteint
}
