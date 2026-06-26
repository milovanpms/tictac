/**
 * @file epaper_pouls_mesure.h
 * @author Thomas Pineau et Milovan Paget
 * @brief En-tête pour la gestion de la mesure de pouls avec capteur HW827
 *
 * Ce fichier contient les déclarations des fonctions publiques pour la gestion
 * de la machine à états de mesure de pouls. Il définit l'API pour le processus
 * complet de mesure incluant l'acquisition des données, le calcul du BPM
 * et l'affichage des résultats.
 */

#ifndef EPAPER_EPAPER_POULS_MESURE_H_
#define EPAPER_EPAPER_POULS_MESURE_H_

#include "epaper.h"

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
SM_State_t EPD_Pouls_Mesure_StateMachine(void);

#endif /* EPAPER_EPAPER_POULS_MESURE_H_ */
