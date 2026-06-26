/**
 * @file encodeur_rotatif.h
 * @author Thomas Pineau et Milovan Paget
 * @brief Interface pour la gestion de l'encodeur rotatif
 *
 * Ce fichier contient les déclarations des fonctions pour la gestion
 * d'un encodeur rotatif avec détection de direction et anti-rebond.
 */

#ifndef BOUTONS_ENCODEUR_ROTATIF_H_
#define BOUTONS_ENCODEUR_ROTATIF_H_

/**
 * @brief Lit la valeur codée actuelle de l'encodeur rotatif
 *
 * Cette fonction lit les états des deux pins de l'encodeur (MSB et LSB)
 * et retourne une valeur codée sur 2 bits représentant l'état actuel.
 *
 * @return int Valeur codée de l'encodeur (0-3)
 *         - Bit 1 (MSB) : état du pin gauche
 *         - Bit 0 (LSB) : état du pin droit
 *
 * @pre Les GPIO des boutons gauche et droit doivent être configurés
 * @post Aucun changement d'état, fonction de lecture pure
 *
 * @note La valeur retournée est calculée comme : (MSB << 1) | LSB
 */
int readEncoder();

/**
 * @brief Fonction de callback pour traiter les interruptions de l'encodeur
 *
 * Cette fonction est appelée lors des interruptions générées par les
 * changements d'état de l'encodeur rotatif. Elle détermine la direction
 * de rotation et met à jour les variables globales correspondantes.
 *
 * @param pin Numéro du pin ayant généré l'interruption
 *
 * @pre Les GPIO de l'encodeur doivent être configurés avec interruptions
 * @pre La fonction EPD_MenuEncoderCallback doit être définie
 * @pre HAL_GetTick() doit être fonctionnel pour l'anti-rebond
 * @post Les variables globales encoderPos et lastPos sont mises à jour
 * @post La fonction EPD_MenuEncoderCallback est appelée avec la direction
 *
 * @note Implémente un anti-rebond de 5ms pour filtrer les parasites
 * @note Utilise une machine d'états pour détecter la direction de rotation
 * @note Affiche la direction sur la console (UP/DOWN)
 */
void encoder_callback(uint8_t pin);

#endif /* BOUTONS_ENCODEUR_ROTATIF_H_ */
