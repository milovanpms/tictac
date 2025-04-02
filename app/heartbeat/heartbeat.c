/*
 * heartbeat.c
 *
 *  Created on: Apr 2, 2025
 *      Author: Milovan
 */

#include "config.h"
#include "stm32g4_sys.h"

#include "stm32g4_systick.h"
#include "stm32g4_gpio.h"
#include "stm32g4_uart.h"
#include "stm32g4_utils.h"
#include "stm32g4_adc.h"

#include <stdio.h>

// On utilise l'ADC_1 (Broche PA0) pour le capteur de pouls

uint16_t heartbeat() {
	return BSP_ADC_getValue(ADC_1);
}
