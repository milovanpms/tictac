/**
 *******************************************************************************
 * @file 	main.c
 * @author 	jjo
 * @date 	Mar 29, 2024
 * @brief	Fichier principal de votre projet sur carte Nucléo STM32G431KB
 *******************************************************************************
 */

#include "config.h"
#include "stm32g4_sys.h"

#include "stm32g4_systick.h"
#include "stm32g4_gpio.h"
#include "stm32g4_uart.h"
#include "stm32g4_utils.h"

#include <stdio.h>

#define BLINK_DELAY	100 // millisecondes


void write_LED(bool b)
{
	HAL_GPIO_WritePin(LED_GREEN_GPIO, LED_GREEN_PIN, b);
}


bool char_received(uart_id_t uart_id)
{
	if( BSP_UART_data_ready(uart_id) ) // Si un caractère est reçu sur l'UART2
	{
		// On utilise le caractère pour vider le buffer de réception
		BSP_UART_get_next_byte(uart_id);
		return true;
	}
	else
		return false;
}


int main(void)
{
	// Permet d'initialiser toutes les couches basses des drivers (Hardware Abstraction Layer)
	HAL_Init();

	BSP_GPIO_enable();
	BSP_UART_init(UART2_ID,115200);

	// Indique que les printf sont dirigés vers l'UART2
	BSP_SYS_set_std_usart(UART2_ID, UART2_ID, UART2_ID);

	// Initialisation du port de la LED verte
	BSP_GPIO_pin_config(LED_GREEN_GPIO, LED_GREEN_PIN, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH,GPIO_NO_AF);

	//printf("Hi <Student>, can you read me?\n");

	while (1)
	{
		write_LED(true);
		HAL_Delay(BLINK_DELAY);
		write_LED(false);
		HAL_Delay(BLINK_DELAY);
	}
}
