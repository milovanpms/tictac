/**
 * @file bluetooth_msg_process.h
 * @author Milovan Paget
 * @brief Interface pour le traitement des messages Bluetooth
 */

#ifndef BLUETOOTH_BLUETOOTH_MSG_PROCESS_H_
#define BLUETOOTH_BLUETOOTH_MSG_PROCESS_H_

/**
 * @brief Gère la réception des caractères UART du module Bluetooth
 *
 * @pre Module UART1 initialisé
 * @post Messages complets traités automatiquement
 */
void handle_uart_reception();

/**
 * @brief Traite les messages complets reçus via Bluetooth
 *
 * @pre Message complet dans le buffer de réception
 * @post Buffer réinitialisé après traitement
 */
void process_received_message();

#endif /* BLUETOOTH_BLUETOOTH_MSG_PROCESS_H_ */
