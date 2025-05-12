/*
 * main.c
 *
 *  Created on: May 12, 2025
 *      Author: Milovan
 */

// https://www.waveshare.com/wiki/1.54inch_e-Paper_Module_(B)_Manual#Working_With_STM32

#include "config.h"
#include "stm32g4_sys.h"

#include "stm32g4_systick.h"
#include "stm32g4_gpio.h"
#include "stm32g4_uart.h"
#include "stm32g4_utils.h"
#include "stm32g4_adc.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Epaper header
#include "./epaper/epaper.h"
#include "./epaper/epaper_displays.h"

// Heartbeat header
#include "./heartbeat/heartbeat.h"


void write_LED(bool b)
{
    HAL_GPIO_WritePin(LED_GREEN_GPIO, LED_GREEN_PIN, b);
}

Bouton_t detecter_bouton() {
	if (HAL_GPIO_ReadPin(BTN_GAUCHE_GPIO, BTN_GAUCHE_PIN) == true) {
		return GAUCHE;
	} else if (HAL_GPIO_ReadPin(BTN_CENTRAL_GPIO, BTN_CENTRAL_PIN) == true) {
		return CENTRAL;
	} else if (HAL_GPIO_ReadPin(BTN_DROIT_GPIO, BTN_DROIT_PIN) == true) {
		return DROIT;
	} else {
		return RIEN;
	}
}

Bouton_t boutonPresse;

bool char_received(uart_id_t uart_id)
{
    if (BSP_UART_data_ready(uart_id))
    {
        BSP_UART_get_next_byte(uart_id);
        return true;
    }
    else
        return false;
}

// Définition des états
typedef enum {
    INIT,
    IDLE,
	DISPLAY,
	FREE,
	SLEEP,
	MENU
} State_t;

State_t currentState = INIT;

void stateMachine() {
    switch (currentState) {
        case INIT:
            currentState = IDLE;

            // Initialisation de la couche d'abstraction matérielle
            HAL_Init();

            // Initialisation GPIO
            BSP_GPIO_enable();

            // Initialisation de la communication UART2 (115200 bauds)
            BSP_UART_init(UART2_ID, 115200);
            BSP_SYS_set_std_usart(UART2_ID, UART2_ID, UART2_ID);

            // Initialisation ADC
            BSP_ADC_init();

            // Configuration de la LED verte
            BSP_GPIO_pin_config(LED_GREEN_GPIO, LED_GREEN_PIN, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_HIGH, GPIO_NO_AF);

            // Configuration des boutons
            BSP_GPIO_pin_config(BTN_GAUCHE_GPIO, BTN_GAUCHE_PIN, GPIO_MODE_INPUT, GPIO_PULLDOWN, GPIO_SPEED_FREQ_LOW, GPIO_NO_AF); // Bouton Gauche
            BSP_GPIO_pin_config(BTN_CENTRAL_GPIO, BTN_CENTRAL_PIN, GPIO_MODE_INPUT, GPIO_PULLDOWN, GPIO_SPEED_FREQ_LOW, GPIO_NO_AF); // Bouton Central
            BSP_GPIO_pin_config(BTN_DROIT_GPIO, BTN_DROIT_PIN, GPIO_MODE_INPUT, GPIO_PULLDOWN, GPIO_SPEED_FREQ_LOW, GPIO_NO_AF);  // Bouton Droit

            // Initialisation du SPI de l'écran
            EPD_SPI_Init();

            // Initialisation de l'écran
            DEV_Module_Init();

            // Initialisation de l'écran en mode complet
            //EPD_Init();

            // Initialisation de l'écran en mode partiel
            EPD_Init_Partial();

        	// Affiche le contenu de base (rien)
            EPD_DisplayBaseImage();
            break;

        case IDLE:
        	currentState = IDLE;
        	do {
        		boutonPresse = detecter_bouton();
        		HAL_Delay(100);
        	}
        	while (boutonPresse == RIEN);
        	switch(boutonPresse) {
        		case GAUCHE:
        			break;
        		case CENTRAL:
        			currentState = MENU;
        			break;
        		case DROIT:
        			break;
        		case RIEN:
        			break;
        	}
        	break;

        case DISPLAY:
        	currentState = FREE;

            EPD_PartialUpdate();
            break;

        case MENU:
        	currentState = MENU;

        	EPD_StateMachine();
            break;

        case FREE:
        	currentState = INIT;
            // Libére la mémoire
            free(BlackImage);
            BlackImage = NULL;
            break;

        case SLEEP:
        	currentState = INIT;
            // Met en veille profonde l'écran (après un affichage par exemple)
        	// WIP: Je ne sais pas comment on sort de veille profonde
            EPD_1IN54_V2_Sleep();
            break;

        default:
            currentState = INIT;
            break;
    }
}

int main(void) {
    while (1) {
        stateMachine();

        HAL_Delay(500);
    }

    return 0;
}
