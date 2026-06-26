/**
 * @file bluetooth_msg_process.c
 * @author Milovan Paget
 * @brief Traitement des messages Bluetooth reçus via UART
 */

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "config.h"
#include "stm32g4_sys.h"

#include "stm32g4_systick.h"
#include "stm32g4_gpio.h"
#include "stm32g4_uart.h"
#include "stm32g4_utils.h"
#include "stm32g4_adc.h"
#include "stm32g4_rtc.h"
#include "./HC-05/stm32g4_hc05.h"
#include "./rtc/rtc.h"

#define BUFFER_SIZE 64 // Taille maximale du buffer de réception

// Buffer de réception des caractères UART
char receive_buffer[BUFFER_SIZE];
// Index courant dans le buffer de réception
uint8_t buffer_index = 0;
// Indicateur de message complet reçu
bool message_complete = false;

/**
 * @brief Gère la réception des caractères UART du module Bluetooth
 *
 * Cette fonction lit les caractères disponibles sur UART1, les stocke dans un buffer
 * et détecte la fin des messages (caractères '\n' ou '\r'). Les caractères reçus
 * sont également renvoyés en écho sur UART2.
 *
 * @pre Le module UART1 doit être initialisé et configuré
 * @post Le message complet est stocké dans receive_buffer si terminateur détecté
 */
void handle_uart_reception() {
    uint8_t received_char;

    while (BSP_UART_data_ready(UART1_ID)) {
        received_char = BSP_UART_getc(UART1_ID);

        // Écho du caractère reçu sur UART2 pour débogage
        BSP_UART_putc(UART2_ID, received_char);

        if (received_char == '\n' || received_char == '\r') {
            // Fin du message détectée
            if (buffer_index > 0) {
                receive_buffer[buffer_index] = '\0';
                message_complete = true;
                process_received_message();
            }
        } else if (buffer_index < BUFFER_SIZE - 1) {
            // Ajouter le caractère au buffer si place disponible
            receive_buffer[buffer_index++] = received_char;
        }
    }
}

/**
 * @brief Traite les messages complets reçus via Bluetooth (via l'application mobile)
 *
 * Analyse le premier caractère du message envoyé par l'application pour déterminer le
 * type de commande et exécute l'action correspondante. Actuellement supporte :
 * - 'z' : Réglage de la date et l'heure (format: z16:12:00;29/04/2005)
 *
 * @pre Un message complet doit être présent dans receive_buffer
 * @post Le buffer de réception est réinitialisé après traitement
 *
 * @note Format attendu pour réglage date/heure : zHH:MM:SS;DD/MM/YYYY
 */
void process_received_message() {
    switch(receive_buffer[0]) {
        case 'z': // Commande de réglage de la date et l'heure
            // Exemple: z16:12:00;29/04/2005 pour régler l'heure à 16h12m00s le 29/04/2005
            {
                int hours, minutes, seconds, day, month, year;

                // Analyse du format de la commande
                if (sscanf(receive_buffer + 1, "%d:%d:%d;%d/%d/%d",
                          &hours, &minutes, &seconds, &day, &month, &year) == 6) {

                    // Mise à jour des structures de temps et date
                    time.Hours = hours;
                    time.Minutes = minutes;
                    time.Seconds = seconds;
                    date.Date = day;
                    date.Month = month;
                    date.Year = year;

                    // Application des nouveaux réglages au RTC
                    BSP_RTC_set_time(&time);
                    BSP_RTC_set_date(&date);
                }
            }
            break;

        default:
            // Commande non reconnue - pas d'action
            break;
    }

    // Réinitialisation du buffer pour le prochain message
    memset(receive_buffer, 0, BUFFER_SIZE);
    buffer_index = 0;
    message_complete = false;
}
