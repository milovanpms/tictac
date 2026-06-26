/**
 * @file heartbeat.c
 * @author Thomas Pineau et Milovan Paget
 * @brief Implémentation du système de mesure de fréquence cardiaque par PPG
 *
 * Ce module implémente un système complet de mesure de fréquence cardiaque
 * utilisant un capteur photopléthysmographique (PPG) HW827. Il inclut :
 * - Acquisition de données via ADC
 * - Filtrage passe-bande du signal PPG
 * - Détection de pics cardiaques
 * - Calcul du BPM (battements par minute)
 *
 * Le système échantillonne à ~71 Hz pendant ~10 secondes pour obtenir
 * une mesure fiable de la fréquence cardiaque.
 */

#include "config.h"
#include "stm32g4_sys.h"

#include "heartbeat.h"
#include "stm32g4_adc.h"

#include <stdio.h>
#include <math.h>

/** @brief Buffer de stockage des données PPG brutes (740 échantillons) */
static uint16_t hw827_data[HW827_RECORDING_SIZE];

/** @brief Index courant dans le buffer de données */
static uint16_t hw827_index = 0;

/**
 * @brief Initialise le module de mesure PPG HW827
 *
 * Cette fonction configure l'ADC nécessaire pour la lecture
 * des données du capteur PPG.
 *
 * @pre Le système STM32 doit être initialisé
 * @post L'ADC est configuré et prêt pour les mesures
 *
 * @note Utilise BSP_ADC_init() pour la configuration matérielle
 */
void HW827_Init(void) {
    BSP_ADC_init();
}

/**
 * @brief Enregistre les données PPG pendant environ 10 secondes
 *
 * Cette fonction acquiert 740 échantillons à une fréquence de 71  Hz
 * (intervalle de 14ms) et les stocke dans le buffer hw827_data[].
 * Un indicateur de progression est affiché si le mode test est activé.
 *
 * @pre HW827_Init() doit avoir été appelée
 * @pre L'ADC doit être configuré et fonctionnel
 * @post hw827_data[] contient 740 échantillons PPG bruts
 * @post hw827_index est remis à zéro
 *
 * @note Fonction bloquante pendant environ 10.36 secondes
 * @note Affiche "[###...###]" si HW827_TEST_MODE = 1
 * @note Utilise HAL_Delay() pour respecter la fréquence d'échantillonnage
 */
void HW827_Recording_Process_1ms(void) {
    printf("recording");

    // Affichage du début de progression en mode test
    if(HW827_TEST_MODE) {
        printf("recording operation working \n");
        printf("[");
    }

    // Acquisition des 740 échantillons
    while(hw827_index < HW827_RECORDING_SIZE) {
        // Lecture de la valeur ADC du capteur PPG
        hw827_data[hw827_index++] = BSP_ADC_getValue(ADC_1);
        printf("#"); // Indicateur de progression

        // Délai pour respecter la fréquence d'échantillonnage (14ms)
        HAL_Delay(HW827_SAMPLE_TIME);
    }

    // Affichage de fin de progression
    if(HW827_TEST_MODE) {
        printf("]\n");
    }

    // Remise à zéro de l'index pour le prochain enregistrement
    hw827_index = 0;
}

/**
 * @brief Affiche les données PPG au format CSV compatible MATLAB
 *
 * Cette fonction imprime le contenu du buffer hw827_data[] au format
 * CSV pour permettre l'analyse des données avec des outils externes.
 *
 * @pre HW827_Recording_Process_1ms() doit avoir été appelée
 * @post Les données sont affichées sur la sortie standard
 *
 * @note Format de sortie : "bat = [valeur1 ; valeur2 ; ... ; valeur740];"
 * @note Compatible avec MATLAB/Octave pour l'importation directe
 */
void HW827_Recording_PrintCSV(void) {
    printf("bat = [\n");
    for (int i = 0; i < HW827_RECORDING_SIZE; i++) {
        printf("%u ;\n", hw827_data[i]);
    }
    printf("];");
}

/*--------------------------------------------------------------*/
/* FONCTIONS DE TRAITEMENT DU SIGNAL PPG                       */
/*--------------------------------------------------------------*/

/**
 * @brief Applique un filtre passe-bande simplifié au signal PPG
 *
 * Implémente un filtrage en deux étapes :
 * 1. Filtre passe-bas par moyenne mobile sur 5 points (≈14.28 Hz)
 * 2. Filtre passe-haut par soustraction de la moyenne mobile
 *
 * Cette approche centre le signal autour de zéro et atténue :
 * - Les composantes haute fréquence (bruit)
 * - Les variations lentes (mouvement, respiration)
 *
 * @param input Signal PPG brut en float
 * @param output Signal filtré centré autour de zéro
 * @param len Nombre d'échantillons à traiter (HW827_RECORDING_SIZE)
 *
 * @pre input[] doit contenir len échantillons valides
 * @pre output[] doit être alloué pour len échantillons
 * @post output[i] = input[i] - moyenne_mobile(input[i])
 *
 * @note Fenêtre de moyenne mobile : 5 échantillons
 * @note Gestion des bords par duplication des valeurs extrêmes
 * @note Fréquence de coupure passe-bas ≈ FS/5 = 14.28 Hz
 */
void bandpass_filter_ppg(const float *input, float *output, uint16_t len) {
    const uint8_t M = 5; // Taille de la fenêtre de moyenne mobile
    float tmp[HW827_RECORDING_SIZE]; // Buffer temporaire pour le passe-bas
    float sum = 0.0f;

    // 1) Filtre passe-bas : moyenne mobile sur 5 points

    // Initialisation avec duplication de input[0]
    sum = input[0] * 5.0f;
    tmp[0] = sum / 5.0f;

    // Cas particulier pour i=1 (4×input[0] + input[1])
    tmp[1] = (input[0] * 4.0f + input[1]) / 5.0f;

    // Fenêtre glissante pour i = 2...(len-3)
    for (uint16_t i = 2; i < len - 2; i++) {
        if (i == 2) {
            // Première somme complète : input[0] à input[4]
            sum = input[0] + input[1] + input[2] + input[3] + input[4];
        } else {
            // Fenêtre glissante : retire input[i-3], ajoute input[i+2]
            sum = sum - input[i - 3] + input[i + 2];
        }
        tmp[i] = sum / 5.0f;
    }

    // Gestion des derniers échantillons
    tmp[len - 2] = (input[len - 5] + input[len - 4] + input[len - 3] +
                    input[len - 2] + input[len - 1]) / 5.0f;
    tmp[len - 1] = tmp[len - 2];

    // 2) Filtre passe-haut : soustraction de la moyenne mobile
    for (uint16_t i = 0; i < len; i++) {
        output[i] = input[i] - tmp[i];
    }
}

/**
 * @brief Détecte les pics locaux dans un signal filtré
 *
 * Recherche les maxima locaux qui satisfont trois conditions :
 * 1. Valeur supérieure au seuil donné
 * 2. Valeur supérieure aux échantillons adjacents (pic local)
 * 3. Distance minimale respectée avec le pic précédent
 *
 * @param signal Signal filtré à analyser
 * @param len Nombre d'échantillons dans le signal
 * @param threshold Seuil minimal pour qu'un pic soit détecté
 * @param min_dist Distance minimale en échantillons entre deux pics
 * @param peak_locs Tableau de sortie contenant les indices des pics
 *
 * @return Nombre total de pics détectés
 *
 * @pre signal[] doit contenir len échantillons valides
 * @pre peak_locs[] doit pouvoir contenir au moins len éléments
 * @pre threshold > 0 et min_dist > 0
 * @post peak_locs[0..retval-1] contient les indices des pics détectés
 *
 * @note Évite les bords du signal (i = 1 à len-2)
 * @note Un pic est défini comme : signal[i] > signal[i-1] ET signal[i] > signal[i+1]
 * @note La distance minimale évite la détection de multiples pics pour un même battement
 */
uint16_t find_peaks(const float *signal, uint16_t len, float threshold, uint16_t min_dist, float *peak_locs) {
    uint16_t count = 0;        // Nombre de pics détectés
    uint16_t last_peak = 0;    // Position du dernier pic détecté

    // Parcours du signal en évitant les bords
    for (uint16_t i = 1; i < len - 1; i++) {
        // Vérification des trois conditions de détection
        if (signal[i] > threshold &&           // Condition 1 : seuil
            signal[i] > signal[i - 1] &&       // Condition 2a : pic local (gauche)
            signal[i] > signal[i + 1])         // Condition 2b : pic local (droite)
        {
            // Condition 3 : distance minimale avec le pic précédent
            if (count == 0 || (i - last_peak) >= min_dist) {
                peak_locs[count++] = (float)i;  // Stockage de l'index du pic
                last_peak = i;                  // Mise à jour du dernier pic
            }
        }
    }
    return count;
}

/**
 * @brief Calcule la fréquence cardiaque en BPM à partir des données PPG
 *
 * Cette fonction effectue un traitement complet du signal PPG :
 * 1. Conversion des données brutes uint16_t vers float
 * 2. Application du filtre passe-bande (selon HW827_BYPASS_FILTER)
 * 3. Calcul des statistiques (moyenne, écart-type)
 * 4. Détection des pics avec seuil adaptatif
 * 5. Calcul du BPM moyen basé sur les intervalles entre pics
 *
 * @param nb_battements Pointeur vers le nombre de pics détectés
 * @param bpm_moy Pointeur vers le BPM moyen calculé
 *
 * @pre HW827_Recording_Process_1ms() doit avoir été appelée
 * @pre nb_battements et bpm_moy doivent pointer vers des variables valides
 * @post *nb_battements = nombre de battements cardiaques détectés
 * @post *bpm_moy = fréquence cardiaque moyenne en BPM (0 si < 2 pics)
 *
 * @note Mode normal : seuil = 0.1 × écart-type du signal filtré
 * @note Mode bypass : seuil = max(0.1 × écart-type, 50) pour signal brut
 * @note Affiche des informations de debug détaillées sur la console
 * @note Calcul BPM : 60 / (intervalle_entre_pics_en_secondes)
 */
void calcule_bpm(uint16_t *nb_battements, float *bpm_moy) {
    float input_f[HW827_RECORDING_SIZE];   // Signal converti en float
    float filtered[HW827_RECORDING_SIZE];  // Signal filtré

    // 1) Conversion des données brutes uint16_t → float
    for (uint16_t i = 0; i < HW827_RECORDING_SIZE; i++) {
        input_f[i] = (float)hw827_data[i];
    }

    // 2) Application du filtrage selon la configuration
    if (!HW827_BYPASS_FILTER) {
        // Mode normal : application du filtre passe-bande
        bandpass_filter_ppg(input_f, filtered, HW827_RECORDING_SIZE);
    } else {
        // Mode bypass : utilisation du signal brut
        for (uint16_t i = 0; i < HW827_RECORDING_SIZE; i++) {
            filtered[i] = input_f[i];
        }
    }

    // 3) Affichage d'échantillons pour vérification (debug)
    printf("Filtered[0]   = %.1f\r\n", filtered[0]);
    printf("Filtered[10]  = %.1f\r\n", filtered[10]);
    printf("Filtered[100] = %.1f\r\n", filtered[100]);
    printf("Filtered[200] = %.1f\r\n", filtered[200]);
    printf("Filtered[500] = %.1f\r\n", filtered[500]);

    // 4) Calcul des statistiques du signal filtré

    // Calcul de la moyenne
    float mean = 0.0f;
    for (uint16_t i = 0; i < HW827_RECORDING_SIZE; i++) {
        mean += filtered[i];
    }
    mean /= (float)HW827_RECORDING_SIZE;

    // Calcul de l'écart-type
    float std = 0.0f;
    for (uint16_t i = 0; i < HW827_RECORDING_SIZE; i++) {
        float diff = filtered[i] - mean;
        std += diff * diff;
    }
    std = sqrtf(std / (float)HW827_RECORDING_SIZE);

    // 5) Détermination du seuil de détection adaptatif
    float seuil;
    if (!HW827_BYPASS_FILTER) {
        // Mode filtré : seuil basé sur l'écart-type
        seuil = 0.1f * std;
    } else {
        // Mode bypass : seuil plus élevé pour signal brut
        seuil = fmaxf(0.1f * std, 50.0f);
    }

    printf("Mean = %.1f, Std = %.1f, Seuil = %.1f\r\n", mean, std, seuil);

    // 5a) Statistiques de dépassement de seuil (debug)
    uint16_t overThresh = 0;
    for (uint16_t i = 0; i < HW827_RECORDING_SIZE; i++) {
        if (filtered[i] > seuil) {
            overThresh++;
        }
    }
    printf("Nb d'éch > seuil : %u\r\n", overThresh);

    // 6) Détection des pics cardiaques
    float peak_locs[HW827_RECORDING_SIZE]; // Indices des pics détectés
    uint16_t nb = find_peaks(
        filtered,
        HW827_RECORDING_SIZE,
        seuil,
        MIN_PEAK_DIST_SAMPLES,
        peak_locs
    );
    printf("Pics trouvés : %u\r\n", nb);

    // 7) Calcul du BPM moyen basé sur les intervalles entre pics
    float bpm_sum = 0.0f;
    for (uint16_t i = 1; i < nb; i++) {
        // Calcul de l'intervalle temporel entre deux pics consécutifs
        float dt = (peak_locs[i] - peak_locs[i - 1]) * HW827_SAMPLE_PERIODE;

        if (dt > 0.0f) {
            // Conversion intervalle → BPM : 60 secondes / intervalle
            float bpm_inst = 60.0f / dt;
            bpm_sum += bpm_inst;

            // Debug : affichage des intervalles et BPM instantanés
            printf("Intervalle %u→%u : dt=%.3f s → BPM=%.1f\r\n",
                   (uint16_t)peak_locs[i - 1],
                   (uint16_t)peak_locs[i],
                   dt,
                   bpm_inst
            );
        }
    }

    // 8) Calcul des résultats finaux
    *nb_battements = nb;
    *bpm_moy = (nb > 1) ? (bpm_sum / (float)(nb - 1)) : 0.0f;

    printf("Résultat final : NbPics=%u, BPM moyen=%.1f\r\n", *nb_battements, *bpm_moy);
}
