/**
 * @file bouton_central.h
 * @author Milovan Paget
 * @brief Interface pour la gestion du bouton central avec anti-rebond
 *
 * Ce fichier contient les déclarations des fonctions pour la lecture
 * du bouton central avec gestion de l'anti-rebond temporel.
 */

#ifndef BOUTONS_BOUTON_CENTRAL_H_
#define BOUTONS_BOUTON_CENTRAL_H_

/**
 * @brief Lit l'état du bouton central avec détection de front montant et anti-rebond
 *
 * Cette fonction détecte uniquement les nouveaux appuis sur le bouton central,
 * en filtrant les rebonds mécaniques grâce à un délai d'anti-rebond.
 *
 * @return true si le bouton vient d'être pressé (front montant détecté)
 * @return false si le bouton n'est pas pressé ou s'il était déjà pressé
 *
 * @pre Le GPIO du bouton central doit être correctement configuré
 * @post L'état interne de la fonction est mis à jour pour le prochain appel
 *
 * @note La fonction utilise un anti-rebond de 50ms pour éviter les fausses détections
 * @note Cette fonction doit être appelée régulièrement dans la boucle principale
 */
bool read_central_button();

#endif /* BOUTONS_BOUTON_CENTRAL_H_ */
