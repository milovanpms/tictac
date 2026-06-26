/**
 * @file epaper_pouls.h
 * @author Thomas Pineau et Milovan Paget
 * @brief En-tête pour la gestion de l'interface utilisateur de mesure de pouls sur écran e-paper
 *
 * Ce fichier contient les déclarations des fonctions publiques pour la gestion
 * de la machine à états de l'interface utilisateur de mesure de pouls.
 * Il définit l'API pour la navigation dans les menus et l'affichage sur écran e-paper.
 */

#ifndef EPAPER_EPAPER_POULS_H_
#define EPAPER_EPAPER_POULS_H_

#include "epaper.h"

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
SM_State_t EPD_Pouls_StateMachine(void);

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
void EPD_Pouls_HandleMenuNavigation(void);

/**
 * @brief Dessine les cadres et icônes du menu principal
 *
 * Cette fonction affiche les éléments graphiques statiques du menu :
 * les boîtes de sélection et les icônes associées à chaque option
 * (statistiques et mesure de pouls).
 *
 * @pre L'écran e-paper doit être initialisé
 * @post Les éléments graphiques du menu sont dessinés sur l'écran
 */
void EPD_Pouls_DrawMenuFrames(void);

/**
 * @brief Met à jour l'affichage du menu selon la sélection actuelle
 *
 * Cette fonction actualise les indicateurs visuels de sélection dans le menu
 * (points remplis/vides) et les textes correspondants selon l'état actuel du menu.
 * Elle gère la navigation circulaire entre les options.
 *
 * @pre etatActuel doit être défini (1 ou 2)
 * @pre La police PixeloidSans18 doit être disponible
 * @post L'affichage du menu est mis à jour avec la sélection actuelle
 * @post L'écran e-paper affiche partiellement les modifications
 */
void EPD_Pouls_UpdateMenuDisplay(void);

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
void EPD_Pouls_Display_MenuPouls(void);

#endif /* EPAPER_EPAPER_POULS_H_ */
