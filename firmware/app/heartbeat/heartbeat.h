/**
 * @file heartbeat.h
 * @author Thomas Pineau
 * @brief Interface pour la mesure de fréquence cardiaque par photopléthysmographie (PPG)
 *
 * Ce module implémente un système de mesure de fréquence cardiaque utilisant
 * un capteur PPG HW827. Il inclut l'acquisition de données, le filtrage du signal,
 * la détection de pics et le calcul du BPM (battements par minute).
 */

#ifndef HEARTBEAT_H
#define HEARTBEAT_H

#include <stdint.h>

/*--------------------------------------------------------------*/
/* 1) PÉRIODE D'ÉCHANTILLONNAGE ET FRÉQUENCE D'ÉCHANTILLONNAGE */
/*--------------------------------------------------------------*/

/** @brief Temps d'échantillonnage en millisecondes */
#define HW827_SAMPLE_TIME      14

/** @brief Période d'échantillonnage en secondes (0.014 s) */
#define HW827_SAMPLE_PERIODE   (HW827_SAMPLE_TIME / 1000.0f)

/** @brief Fréquence d'échantillonnage en Hz (≈ 71 Hz) */
#define FS  (1000.0f / HW827_SAMPLE_TIME)

/** @brief Distance minimale entre deux pics en secondes */
#define MIN_PEAK_DIST_SEC      0.4f

/** @brief Distance minimale entre deux pics en échantillons (≈ 28 échantillons) */
#define MIN_PEAK_DIST_SAMPLES  ((uint16_t)(FS * MIN_PEAK_DIST_SEC))

/*--------------------------------------------------------------*/
/* 2) TAILLES DE TABLEAUX ET MODES DE TEST                        */
/*--------------------------------------------------------------*/

/** @brief Nombre d'échantillons à enregistrer (~10 s à 71 Hz) */
#define HW827_RECORDING_SIZE   740

/** @brief Mode test pour affichage des progressions (1=activé, 0=désactivé) */
#define HW827_TEST_MODE        1

/** @brief Mode bypass du filtre (1=bypass, 0=filtrage normal) */
#define HW827_BYPASS_FILTER    0

/*--------------------------------------------------------------*/
/* 3) PROTOTYPES DES FONCTIONS PRINCIPALES                       */
/*--------------------------------------------------------------*/

/**
 * @brief Initialise le module de mesure PPG
 *
 * Cette fonction initialise l'ADC et les ressources nécessaires
 * pour la mesure de fréquence cardiaque.
 *
 * @pre Le système STM32 doit être initialisé
 * @post L'ADC est configuré et prêt pour les mesures PPG
 *
 * @note Doit être appelée avant toute utilisation du module
 */
void HW827_Init(void);

/**
 * @brief Enregistre les données PPG pendant environ 10 secondes
 *
 * Cette fonction acquiert 740 échantillons à une fréquence de 71 Hz
 * et les stocke dans le buffer interne hw827_data[].
 *
 * @pre HW827_Init() doit avoir été appelée
 * @pre L'ADC doit être fonctionnel
 * @post Le buffer hw827_data[] contient les données PPG brutes
 * @post L'index interne est remis à zéro
 *
 * @note Fonction bloquante pendant ~10 secondes
 * @note Affiche une progression si HW827_TEST_MODE est activé
 */
void HW827_Recording_Process_1ms(void);

/**
 * @brief Affiche les données PPG au format CSV sur la console
 *
 * Cette fonction imprime le contenu du buffer hw827_data[]
 * au format CSV pour analyse externe (ex: MATLAB, Python).
 *
 * @pre HW827_Recording_Process_1ms() doit avoir été appelée
 * @post Les données sont affichées sur la sortie standard
 *
 * @note Format de sortie : "bat = [valeur1 ; valeur2 ; ... ; valeurN];"
 */
void HW827_Recording_PrintCSV(void);

/*--------------------------------------------------------------*/
/* 4) PROTOTYPES DES FONCTIONS DE TRAITEMENT DU SIGNAL          */
/*--------------------------------------------------------------*/

/**
 * @brief Applique un filtre passe-bande au signal PPG
 *
 * Implémente un filtre passe-bande simplifié utilisant une moyenne mobile
 * de 5 points (passe-bas) suivie d'une soustraction (passe-haut) pour
 * centrer le signal autour de zéro.
 *
 * @param input Signal PPG brut en float
 * @param output Signal filtré en float (centré autour de zéro)
 * @param len Nombre d'échantillons à traiter
 *
 * @pre input[] doit contenir len échantillons valides
 * @pre output[] doit être alloué pour len échantillons
 * @post output[] contient le signal filtré passe-bande
 *
 * @note Fréquence de coupure low-pass ≈ 14 Hz (FS/5)
 * @note Le signal de sortie est centré autour de zéro
 */
void bandpass_filter_ppg(const float *input, float *output, uint16_t len);

/**
 * @brief Détecte les pics locaux dans un signal filtré
 *
 * Recherche les maxima locaux dans le signal qui dépassent un seuil donné
 * et respectent une distance minimale entre pics consécutifs.
 *
 * @param signal Signal filtré à analyser
 * @param len Nombre d'échantillons dans le signal
 * @param threshold Seuil minimal pour la détection de pics
 * @param min_dist Distance minimale en échantillons entre deux pics
 * @param peak_locs Tableau de sortie contenant les indices des pics détectés
 *
 * @return Nombre total de pics détectés
 *
 * @pre signal[] doit contenir len échantillons valides
 * @pre peak_locs[] doit être alloué pour au moins len éléments
 * @pre threshold > 0 et min_dist > 0
 * @post peak_locs[0..retval-1] contient les indices des pics détectés
 *
 * @note Un pic est défini comme signal[i] > signal[i-1] ET signal[i] > signal[i+1]
 * @note La fonction évite les pics trop proches (bruit/artéfacts)
 */
uint16_t find_peaks(const float *signal, uint16_t len, float threshold, uint16_t min_dist, float *peak_locs);

/**
 * @brief Calcule la fréquence cardiaque en BPM à partir des données PPG
 *
 * Cette fonction traite les données PPG brutes pour calculer le nombre
 * de battements cardiaques et le BPM moyen. Elle effectue :
 * - Conversion uint16_t vers float
 * - Filtrage passe-bande (optionnel selon HW827_BYPASS_FILTER)
 * - Calcul statistiques (moyenne, écart-type)
 * - Détection de pics avec seuil dynamique
 * - Calcul du BPM moyen
 *
 * @param nb_battements Pointeur vers la variable recevant le nombre de pics détectés
 * @param bpm_moy Pointeur vers la variable recevant le BPM moyen calculé
 *
 * @pre HW827_Recording_Process_1ms() doit avoir été appelée
 * @pre nb_battements et bpm_moy doivent pointer vers des variables valides
 * @post *nb_battements contient le nombre de battements détectés
 * @post *bpm_moy contient le BPM moyen (0 si moins de 2 pics détectés)
 *
 * @note En mode bypass (HW827_BYPASS_FILTER=1), utilise un seuil fixe élevé
 * @note En mode normal, utilise un seuil dynamique basé sur l'écart-type
 * @note Affiche des informations de debug sur la console si activé
 */
void calcule_bpm(uint16_t *nb_battements, float *bpm_moy);

#endif // HEARTBEAT_H
