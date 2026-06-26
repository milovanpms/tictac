/**
 * @file rtc.c
 * @author Thomas Pineau et Milovan Paget
 * @brief Implémentation du module de gestion de l'horloge temps réel (RTC)
 *
 * Ce fichier contient l'implémentation des fonctions de gestion du RTC.
 * Il fournit des fonctions pour initialiser le RTC et
 * récupérer la date et l'heure sous forme formatée.
 *
 */

#include "config.h"
#include "stm32g4_sys.h"

#include "stm32g4_systick.h"
#include "stm32g4_gpio.h"
#include "stm32g4_uart.h"
#include "stm32g4_utils.h"
#include "stm32g4_adc.h"
#include "stm32g4_rtc.h"
#include "./HC-05/stm32g4_hc05.h"

#include "rtc.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/** @brief Structure de temps initialisée par défaut à 00:00:00 */
RTC_TimeTypeDef time = {0, 00, 00};

/** @brief Structure de date initialisée par défaut au 1er janvier (samedi) */
RTC_DateTypeDef date = {SATURDAY, JANUARY, 1, 00};

/** @brief Tableau des noms des jours de la semaine en français */
const char * weekday_str[7] = {"Lun", "Mar", "Mer", "Jeu", "Ven", "Sam", "Dim"};

/** @brief Buffer pour stocker la chaîne de date formatée (taille 64 caractères) */
char buffer_date[64];

/** @brief Buffer pour stocker la chaîne d'heure formatée (taille 64 caractères) */
char buffer_heure[64];

/**
 * @brief Initialise le module RTC avec les valeurs par défaut
 *
 * Cette fonction configure et initialise l'horloge temps réel en utilisant
 * les fonctions BSP. Elle définit une heure et une date par défaut puis
 * lit les valeurs configurées pour s'assurer de la synchronisation.
 *
 * @pre Le système doit être initialisé
 * @post Le RTC est configuré et opérationnel avec les valeurs par défaut
 *       (1er janvier, samedi, 00:00:00)
 */
void RTC_Init() {
	// Initialisation du RTC via la couche BSP
	BSP_RTC_init();

	// Configuration de l'heure par défaut
	BSP_RTC_set_time(&time);

	// Configuration de la date par défaut
	BSP_RTC_set_date(&date);

	// Lecture des valeurs configurées pour synchronisation
	BSP_RTC_get_time_and_date(&time, &date);
}

/**
 * @brief Récupère la date actuelle formatée
 *
 * Lit la date courante depuis le RTC et la formate sous la forme
 * "Jour JJ/MM" où Jour est l'abréviation du jour de la semaine,
 * JJ le numéro du jour et MM le numéro du mois.
 *
 * @return Pointeur vers une chaîne de caractères contenant la date formatée
 *         (ex: "Lun 15/05" pour lundi 15 mai)
 * @pre Le RTC doit être initialisé avec RTC_Init()
 * @post La date actuelle est lue depuis le RTC et formatée dans buffer_date
 */
char* RTC_GetDate() {
	// Lecture de l'heure et de la date actuelles
	BSP_RTC_get_time_and_date(&time, &date);

	// Formatage de la date : "Jour JJ/MM"
	snprintf(buffer_date, sizeof(buffer_date), "%s %02d/%02d",
	         weekday_str[date.WeekDay], date.Date, date.Month);

	return buffer_date;
}

/**
 * @brief Récupère l'heure actuelle formatée
 *
 * Lit l'heure courante depuis le RTC et la formate sous la forme
 * "HH:MM" au format 24 heures avec padding de zéros.
 *
 * @return Pointeur vers une chaîne de caractères contenant l'heure formatée
 *         (ex: "14:30" pour 14h30 ou "09:05" pour 9h05)
 * @pre Le RTC doit être initialisé avec RTC_Init()
 * @post L'heure actuelle est lue depuis le RTC et formatée dans buffer_heure
 */
char* RTC_GetHeure() {
	// Lecture de l'heure et de la date actuelles
	BSP_RTC_get_time_and_date(&time, &date);

	// Formatage de l'heure : "HH:MM"
	snprintf(buffer_heure, sizeof(buffer_heure), "%02d:%02d",
	         time.Hours, time.Minutes);

	return buffer_heure;
}
