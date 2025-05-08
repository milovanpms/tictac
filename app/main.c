/**
 *******************************************************************************
 * @file    main.c
 * @author  jjo & Waveshare
 * @date    Mar 29, 2024
 * @brief   Fichier principal avec intégration de l'écran e-paper
 *******************************************************************************
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

// Epaper header
#include "./epaper/epaper.h"
#include "./epaper/epaper_displays.h"

// Heartbeat header
#include "./heartbeat/heartbeat.h"


void write_LED(bool b)
{
    HAL_GPIO_WritePin(LED_GREEN_GPIO, LED_GREEN_PIN, b);
}


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


int main(void)
{
    HAL_Init();
    BSP_GPIO_enable();
    BSP_UART_init(UART2_ID, 115200);
    BSP_SYS_set_std_usart(UART2_ID, UART2_ID, UART2_ID);
    BSP_ADC_init();

    // Initialise la LED verte
    BSP_GPIO_pin_config(LED_GREEN_GPIO, LED_GREEN_PIN, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_HIGH, GPIO_NO_AF);

    // Initialise le SPI
    EPD_SPI_Init();

    // Initialise le module e-paper
    DEV_Module_Init();
    //EPD_Init();
    EPD_Init_Partial();

    //EPD_Display_MenuPrincipal();

    // Affiche l'image (le texte, les formes, tout ce qu'on veut) sur l'écran
    //EPD_1IN54_V2_Display(BlackImage);

    EPD_DisplayBaseImage();

    // Attendre un peu (simulation de delay)
    HAL_Delay(500);

    // Rafraîchissements partiels
    EPD_PartialUpdate();

    // Attendre un peu puis mise en veille
    HAL_Delay(500);

    // Met en veille profonde l'écran après affichage
    EPD_1IN54_V2_Sleep();

    // Libére la mémoire
    free(BlackImage);
    BlackImage = NULL;

    while (1)
    {
        //write_LED(true);
        //HAL_Delay(1000);
        //write_LED(false);
        //HAL_Delay(1000);
    	//printf("%u\n", heartbeat());
    	//HAL_Delay(100);
    }
}
