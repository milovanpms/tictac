/**
 * @file epaper_displays.h
 * @author Thomas Pineau et Milovan Paget
 * @brief Header pour la gestion de l'affichage e-paper avec machine à états
 *
 * Ce fichier définit les prototypes des fonctions et les énumérations pour
 * la gestion de l'affichage e-paper, incluant les différents écrans de l'interface
 * utilisateur et la machine à états de navigation.
 *
 * Created on: May 8, 2025
 */

#ifndef EPAPER_EPAPER_DISPLAYS_H_
#define EPAPER_EPAPER_DISPLAYS_H_

#include "epaper.h"

/**
 * @brief Affichage du menu principal avec les 4 options disponibles
 *
 * Initialise et affiche le menu principal avec les icônes pour les différentes
 * fonctionnalités : statistiques, pouls, NFC et paramètres.
 *
 * @post Le menu principal est affiché sur l'e-paper
 * @post etatActuel est réinitialisé à 1
 */
void EPD_Display_MenuPrincipal(void);

/**
 * @brief Affichage du menu NFC avec 3 options
 *
 * Affiche le sous-menu NFC avec les options satellite, plume et note musicale,
 * avec l'option "Dupliquer" sélectionnée par défaut.
 *
 * @post L'interface NFC est affichée sur l'e-paper
 */
void EPD_Display_MenuNFC(void);

/**
 * @brief Affichage du menu de mesure du pouls
 *
 * Fonction pour afficher l'interface de mesure du pouls (prototype).
 * L'implémentation dépend du module epaper_pouls.
 */
void EPD_Display_MenuPouls(void);

/**
 * @brief Affichage de l'écran "Mesure en cours"
 *
 * Affiche un message d'information pendant qu'une mesure de pouls est en cours,
 * avec des instructions pour l'utilisateur.
 *
 * @post L'écran de mesure en cours est affiché
 */
void EPD_Display_MesureEnCours(void);

/**
 * @brief Affichage des résultats de mesure du pouls
 *
 * Affiche les résultats d'une mesure de pouls terminée avec succès,
 * incluant la valeur en BPM et une indication visuelle du niveau de santé.
 *
 * @param bpm_moy Fréquence cardiaque moyenne mesurée
 * @pre bpm_moy doit être une valeur positive valide
 * @post L'écran des résultats est affiché avec classification santé
 */
void EPD_Display_MesureTerminee(float bpm_moy);

/**
 * @brief Affichage de l'écran "Mesure annulée"
 *
 * Affiche un message d'erreur lorsqu'une mesure de pouls a été interrompue
 * ou a échoué, avec des conseils pour l'utilisateur.
 *
 * @post L'écran d'annulation est affiché
 */
void EPD_Display_MesureAnnulee(void);

/**
 * @brief Affichage de l'historique des pas avec navigation
 *
 * Affiche les données d'activité physique pour une date donnée,
 * incluant le nombre de pas et la distance parcourue, avec des flèches
 * de navigation pour changer de jour.
 *
 * @post L'écran historique des pas est affiché
 */
void EPD_Display_HistoriquePas(void);

/**
 * @brief Affichage de l'écran d'accueil avec informations de base
 *
 * Affiche l'heure, la date et les statistiques quotidiennes (pas et distance)
 * sur l'écran principal en mode veille.
 *
 * @param pas Nombre de pas effectués dans la journée
 * @pre pas doit être une valeur positive
 * @post L'écran d'accueil est affiché avec les informations actualisées
 */
void EPD_Display_Idle(uint16_t pas);

/**
 * @brief Affichage de l'image de base sur l'e-paper
 *
 * Fonction utilitaire pour afficher l'image de base stockée en mémoire.
 *
 * @post L'image de base est affichée sur l'e-paper
 */
void EPD_DisplayBaseImage(void);

/**
 * @brief Démonstration des mises à jour partielles de l'écran
 *
 * Fonction de test qui montre différentes animations et transitions
 * entre les écrans pour démontrer les capacités de mise à jour partielle
 * de l'e-paper.
 *
 * @post Une séquence d'animations est affichée puis retour au menu principal
 */
void EPD_PartialUpdate(void);

/**
 * @brief Réinitialisation de l'affichage e-paper
 *
 * Efface complètement l'écran e-paper en le remplissant de noir,
 * préparant ainsi l'affichage pour de nouveaux contenus.
 *
 * @post L'écran e-paper est complètement effacé (noir)
 */
void EPD_Display_Reset(void);

/**
 * @brief Traitement de la machine à états pour les affichages EPD
 *
 * Fonction de traitement principal pour la machine à états des affichages.
 * Cette fonction doit être appelée périodiquement dans la boucle principale.
 */
void EPD_StateMachine_Process(void);

/**
 * @brief Gestion de la navigation dans le menu via les boutons
 *
 * Cette fonction vérifie périodiquement l'état du bouton central pour détecter
 * les sélections d'éléments de menu et déclenche les transitions d'état appropriées.
 * Elle gère également la mise à jour de l'affichage du menu.
 *
 * @pre L'état actuel doit être IDLE
 * @post La sélection du menu peut changer d'état ou l'affichage peut être mis à jour
 */
void EPD_HandleMenuNavigation(void);

/**
 * @brief Callback appelé par l'encodeur rotatif pour changer la sélection du menu
 *
 * Cette fonction est appelée lorsque l'encodeur rotatif détecte une rotation.
 * Elle met à jour la position actuelle dans le menu avec gestion circulaire
 * et anti-rebond.
 *
 * @param direction Direction de rotation (>0: suivant, <0: précédent)
 * @pre direction doit être différent de 0
 * @post etatActuel est mis à jour et menuNeedsUpdate est activé
 */
void EPD_MenuEncoderCallback(int direction);

/**
 * @brief Dessine les cadres et icônes fixes du menu principal
 *
 * Cette fonction affiche les 4 boîtes du menu avec leurs icônes respectives :
 * - Statistiques (coin supérieur gauche)
 * - Pouls (coin supérieur droit)
 * - NFC/Hack (coin inférieur gauche)
 * - Paramètres (coin inférieur droit)
 *
 * @post Les éléments graphiques fixes du menu sont affichés
 */
void EPD_DrawMenuFrames(void);

/**
 * @brief Met à jour les indicateurs de sélection du menu
 *
 * Affiche les points pleins/vides sous chaque option du menu pour indiquer
 * quelle option est actuellement sélectionnée.
 *
 * @pre etatActuel doit être entre 1 et 4
 * @post L'affichage e-paper est mis à jour avec les nouveaux indicateurs
 */
void EPD_UpdateMenuDisplay(void);

/**
 * @brief Énumération des états pour la machine à états EPD
 *
 * Cette énumération définit les différents états possibles de l'interface
 * utilisateur e-paper, permettant une navigation structurée entre les écrans.
 */
typedef enum {
    EPD_INACTIVE,    ///< État inactif (pas dans le menu)
    EPD_MAIN,        ///< Menu principal affiché
    EPD_POULS,       ///< Vue de mesure du pouls active
    EPD_PAS,         ///< Vue de l'historique des pas active
    EPD_NFC,         ///< Vue du menu NFC active
    EPD_PARAMETRES,  ///< Vue des paramètres active
    EPD_EXIT         ///< Signal de sortie vers la machine à états principale
} EPD_State_t;

#endif /* EPAPER_EPAPER_DISPLAYS_H_ */
