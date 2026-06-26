/**
 * @file rtc.h
 * @author Milovan Paget
 * @brief Module de gestion de l'horloge temps réel (RTC)
 *
 * Ce module fournit une interface simplifiée pour l'initialisation et la lecture
 * de l'horloge temps réel. Il permet d'obtenir la date et l'heure actuelles
 * sous forme de chaînes de caractères formatées.
 *
 */

#ifndef RTC_RTC_H_
#define RTC_RTC_H_

#include "stm32g4_rtc.h"

/** @brief Tableau des noms des jours de la semaine en français */
extern const char * weekday_str[7];

/** @brief Structure contenant les informations de temps (heures, minutes, secondes) */
extern RTC_TimeTypeDef time;

/** @brief Structure contenant les informations de date (jour, mois, année, jour de la semaine) */
extern RTC_DateTypeDef date;

/**
 * @brief Initialise le module RTC avec les valeurs par défaut
 *
 * Cette fonction configure et initialise l'horloge temps réel avec une date
 * et une heure par défaut (1er janvier, samedi, 00:00:00).
 *
 * @pre Le système STM32G4 doit être initialisé
 * @post Le RTC est configuré et opérationnel avec les valeurs par défaut
 */
void RTC_Init();

/**
 * @brief Récupère la date actuelle formatée
 *
 * Lit la date courante depuis le RTC et la formate sous la forme
 * "Jour JJ/MM" (ex: "Lun 15/05").
 *
 * @return Pointeur vers une chaîne de caractères contenant la date formatée
 * @pre Le RTC doit être initialisé avec RTC_Init()
 * @post La date actuelle est lue et formatée dans un buffer interne
 */
char* RTC_GetDate();

/**
 * @brief Récupère l'heure actuelle formatée
 *
 * Lit l'heure courante depuis le RTC et la formate sous la forme
 * "HH:MM" au format 24h (ex: "14:30").
 *
 * @return Pointeur vers une chaîne de caractères contenant l'heure formatée
 * @pre Le RTC doit être initialisé avec RTC_Init()
 * @post L'heure actuelle est lue et formatée dans un buffer interne
 */
char* RTC_GetHeure();

#endif /* RTC_RTC_H_ */
