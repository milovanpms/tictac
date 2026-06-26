/**
 * @file epaper.h
 * @author Milovan PMS
 * @brief Fichier d'en-tête pour la gestion de l'écran e-paper 1.54" Waveshare
 *
 * Ce fichier contient les déclarations des fonctions et structures nécessaires
 * pour contrôler l'écran e-paper 1.54" via l'interface SPI.
 * L'écran utilise un mode d'affichage noir et blanc avec support du mode partiel
 * pour des mises à jour plus rapides.
 *
 * @note Basé sur la documentation Waveshare : https://www.waveshare.com/wiki/1.54inch_e-Paper_Module_(B)_Manual#Working_With_STM32
 */

#ifndef EPAPER_EPAPER_H_
#define EPAPER_EPAPER_H_

#include "./epaper/stm32g4_epaper_com.h"

/** @brief État actuel de la machine à états de l'écran */
extern int etatActuel;

/** @brief Indicateur de mise à jour nécessaire du menu */
extern bool menuNeedsUpdate;

/** @brief Nombre total d'états dans la machine à états */
extern int nombreEtats;

/**
 * @brief États de la machine à états de l'écran e-paper
 *
 * Cette énumération définit les états possibles de la machine à états
 * qui gère l'affichage et les interactions avec l'écran e-paper.
 */
typedef enum {
    SM_RUNNING,  ///< Machine à états en cours d'exécution
    SM_FINISHED  ///< Machine à états terminée
} SM_State_t;

/** @brief Largeur de l'écran e-paper en pixels */
#define EPD_WIDTH   EPD_1IN54_V2_WIDTH

/** @brief Hauteur de l'écran e-paper en pixels */
#define EPD_HEIGHT  EPD_1IN54_V2_HEIGHT

/**
 * @brief Initialise l'interface SPI pour l'écran e-paper
 *
 * Configure les broches GPIO (PA5=SCK, PA6=MISO, PA7=MOSI) et initialise
 * le périphérique SPI1 avec les paramètres optimaux pour l'écran e-paper.
 *
 * @pre Les horloges GPIOA et SPI1 doivent être disponibles
 * @post L'interface SPI est configurée et prête à communiquer avec l'écran
 *
 * @note En cas d'erreur d'initialisation, le programme entre dans une boucle infinie
 */
void EPD_SPI_Init(void);

/**
 * @brief Initialise l'écran e-paper en mode complet
 *
 * Effectue l'initialisation complète de l'écran e-paper, alloue la mémoire
 * pour le buffer d'image et configure la bibliothèque graphique Paint.
 * Ce mode permet un contrôle total de l'écran mais les mises à jour sont lentes.
 *
 * @pre L'interface SPI doit être initialisée
 * @pre Le module DEV doit être initialisé
 * @post L'écran est prêt pour l'affichage en mode complet
 * @post Le buffer d'image est alloué et initialisé
 *
 * @note Utilise malloc() pour allouer le buffer d'image
 */
void EPD_Init(void);

/**
 * @brief Initialise l'écran e-paper en mode partiel
 *
 * Initialise l'écran d'abord en mode complet avec un fond noir, puis passe
 * en mode partiel pour permettre des mises à jour plus rapides de zones
 * spécifiques de l'écran. Idéal pour les applications temps réel.
 *
 * @pre L'interface SPI doit être initialisée
 * @pre Le module DEV doit être initialisé
 * @post L'écran est configuré en mode partiel avec fond noir
 * @post Le buffer d'image est alloué et initialisé
 *
 * @note Le mode partiel permet des mises à jour plus rapides mais avec certaines limitations
 */
void EPD_Init_Partial(void);

/** @brief Pointeur vers le buffer d'image affiché à l'écran */
extern UBYTE *BlackImage;

/** @brief Handle de l'interface SPI utilisée pour l'écran */
extern SPI_HandleTypeDef hspi1;

#endif /* EPAPER_EPAPER_H_ */
