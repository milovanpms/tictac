/**
 * @file epaper.c
 * @author Milovan Paget
 * @brief Implémentation des fonctions de contrôle de l'écran e-paper 1.54"
 *
 * Ce fichier implémente les fonctions nécessaires pour contrôler l'écran e-paper
 * 1.54". Il gère l'initialisation SPI, la configuration de l'écran
 * en mode complet ou partiel, et la gestion du buffer d'image.
 *
 * L'écran e-paper utilise une interface SPI pour la communication et supporte
 * deux modes d'affichage :
 * - Mode complet : Mise à jour complète de l'écran (lent mais précis)
 * - Mode partiel : Mise à jour rapide de zones spécifiques (plus rapide)
 *
 * @note Basé sur la documentation Waveshare : https://www.waveshare.com/wiki/1.54inch_e-Paper_Module_(B)_Manual#Working_With_STM32
 */

#include <epaper/stm32g4_epaper_config.h>
#include "config.h"
#include "stm32g4_sys.h"

#include "stm32g4_systick.h"
#include "stm32g4_gpio.h"
#include "stm32g4_uart.h"
#include "stm32g4_utils.h"

#include <stdio.h>

// En-têtes de l'écran e-paper
#include "./epaper/stm32g4_epaper_com.h"
#include "./epaper/stm32g4_epaper_paint.h"
#include "epaper.h"
#include "epaper_bitmaps.h"

/** @brief Buffer contenant l'image actuellement affichée à l'écran */
UBYTE *BlackImage;

/** @brief Handle de l'interface SPI1 utilisée pour communiquer avec l'écran */
SPI_HandleTypeDef hspi1;

/**
 * @brief Initialise l'interface SPI pour la communication avec l'écran e-paper
 *
 * Cette fonction configure les broches GPIO nécessaires pour la communication SPI
 * (SCK, MISO, MOSI) et initialise le périphérique SPI1 avec les paramètres
 * optimaux pour l'écran e-paper 1.54".
 *
 * Configuration SPI :
 * - Mode maître
 * - Prescaler de 8 pour ajuster la vitesse
 *
 * @pre Les horloges des périphériques GPIOA et SPI1 doivent être disponibles
 * @post L'interface SPI est configurée et les interruptions sont activées
 * @post Les broches PA5 (SCK), PA6 (MISO), PA7 (MOSI) sont configurées
 *
 * @note En cas d'échec de l'initialisation, le programme entre dans une boucle infinie
 * @note La priorité d'interruption SPI est configurée à 3 (priorité basse)
 */
void EPD_SPI_Init(void)
{
    // Activation des horloges pour GPIOA et SPI1
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_SPI1_CLK_ENABLE();

    // Configuration des broches SPI (SCK, MISO, MOSI)
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // PA5 = SCK, PA6 = MISO, PA7 = MOSI
    GPIO_InitStruct.Pin = GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;            // Pas de résistance de tirage
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;  // Vitesse élevée
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // Configuration du périphérique SPI1
    hspi1.Instance = SPI1;
    hspi1.Init.Mode = SPI_MODE_MASTER; // Mode maître
    hspi1.Init.Direction = SPI_DIRECTION_2LINES;
    hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
    hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
    hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
    hspi1.Init.NSS = SPI_NSS_SOFT;
    hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8; // Prescaler de vitesse (plus c'est haut plus c'est lent)
    hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
    hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
    hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
    hspi1.Init.CRCPolynomial = 7;
    hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
    hspi1.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;

    // Initialisation du SPI avec vérification d'erreur
    if (HAL_SPI_Init(&hspi1) != HAL_OK)
    {
        printf("Erreur lors de l'initialisation SPI\r\n");
        while(1); // Blocage en cas d'erreur
    }
}

/**
 * @brief Initialise l'écran e-paper en mode complet
 *
 * Cette fonction effectue l'initialisation complète de l'écran e-paper en mode
 * standard. Elle configure l'écran, efface son contenu, alloue la mémoire
 * nécessaire pour le buffer d'image et initialise la bibliothèque graphique.
 *
 * Le mode complet permet un contrôle total de l'écran mais les mises à jour
 * sont relativement lentes (plusieurs secondes).
 *
 * @pre L'interface SPI doit être initialisée via EPD_SPI_Init()
 * @pre Le module DEV doit être configuré
 * @post L'écran est initialisé et effacé
 * @post Le buffer d'image est alloué et configuré avec fond blanc
 * @post La bibliothèque Paint est initialisée avec rotation de 90°
 *
 * @note La mémoire est allouée dynamiquement avec malloc()
 * @note En cas d'échec d'allocation mémoire, la fonction retourne sans initialiser
 */
void EPD_Init(void) {
    printf("Initialisation de l'écran e-paper en mode complet...\n");

    // Initialisation et effacement de l'écran
    EPD_1IN54_V2_Init();
    EPD_1IN54_V2_Clear();

    // Calcul de la taille du buffer d'image
    // Formule : ((largeur + 7) / 8) * hauteur pour les écrans 1 bit par pixel
    UWORD Image_Size = ((EPD_WIDTH % 8 == 0) ? (EPD_WIDTH / 8) : (EPD_WIDTH / 8 + 1)) * EPD_HEIGHT;

    // Allocation dynamique du buffer d'image
    if ((BlackImage = (UBYTE *)malloc(Image_Size)) == NULL) {
        printf("Échec de l'allocation mémoire pour le buffer d'image\r\n");
        return;
    }

    printf("Allocation de %d octets pour le buffer d'image\r\n", Image_Size);

    // Initialisation du buffer avec du blanc (0xFF)
    memset(BlackImage, 0xFF, Image_Size);

    // Initialisation de la bibliothèque graphique
    // Paramètres : buffer, largeur, hauteur, rotation (90°), couleur de fond
    Paint_NewImage(BlackImage, EPD_WIDTH, EPD_HEIGHT, 90, BLACK);
    Paint_SelectImage(BlackImage);
    Paint_Clear(BLACK); // Effacement avec fond noir

    printf("Initialisation de l'écran e-paper terminée\n");
}

/**
 * @brief Initialise l'écran e-paper en mode partiel pour des mises à jour rapides
 *
 * Cette fonction initialise l'écran e-paper en mode partiel, qui permet des
 * mises à jour beaucoup plus rapides que le mode complet. Le processus se fait
 * en deux étapes :
 * 1. Initialisation complète avec fond noir
 * 2. Passage en mode partiel pour les mises à jour suivantes
 *
 * Le mode partiel est idéal pour les applications temps réel comme l'affichage
 * de l'heure, du nombre de pas, etc.
 *
 * @pre L'interface SPI doit être initialisée via EPD_SPI_Init()
 * @pre Le module DEV doit être configuré
 * @post L'écran est initialisé en mode partiel avec fond noir
 * @post Le buffer d'image est alloué et configuré avec fond noir
 * @post La bibliothèque Paint est initialisée avec rotation de 90°
 *
 * @note Le délai de 200ms permet à l'écran de terminer le rafraîchissement initial
 * @note Le buffer est initialisé avec 0x00 (noir) au lieu de 0xFF (blanc)
 * @note En cas d'échec d'allocation mémoire, la fonction retourne sans initialiser
 */
void EPD_Init_Partial(void) {
    printf("Initialisation de l'écran e-paper en mode partiel...\n");

    // Première étape : initialisation complète de l'écran
    EPD_1IN54_V2_Init();

    // Remplissage de l'écran avec du noir pour établir une base stable
    EPD_1IN54_V2_Clear_Black();

    // Attente de la fin du rafraîchissement de l'écran
    HAL_Delay(200);

    // Deuxième étape : passage en mode partiel
    EPD_1IN54_V2_Init_Partial();

    // Calcul de la taille du buffer d'image
    UWORD Image_Size = ((EPD_WIDTH % 8 == 0) ? (EPD_WIDTH / 8) : (EPD_WIDTH / 8 + 1)) * EPD_HEIGHT;

    // Allocation dynamique du buffer d'image
    if ((BlackImage = (UBYTE *)malloc(Image_Size)) == NULL) {
        printf("Échec de l'allocation mémoire pour le buffer d'image\r\n");
        return;
    }

    printf("Allocation de %d octets pour le buffer d'image\r\n", Image_Size);

    // Initialisation du buffer avec du noir (0x00) pour le mode partiel
    memset(BlackImage, 0x00, Image_Size);

    // Initialisation de la bibliothèque graphique avec rotation de 90°
    Paint_NewImage(BlackImage, EPD_WIDTH, EPD_HEIGHT, 90, BLACK);
    Paint_SelectImage(BlackImage);
    Paint_Clear(BLACK); // Fond noir pour le mode partiel

    printf("Initialisation en mode partiel terminée avec succès\n");
}
