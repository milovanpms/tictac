/*
 * epaper.h
 *
 *  Created on: Apr 2, 2025
 *      Author: Milovan PMS
 */

#ifndef EPAPER_EPAPER_H_
#define EPAPER_EPAPER_H_

#include "./epaper/stm32g4_epaper_com.h"

// Epaper screen size
#define EPD_WIDTH   EPD_1IN54_V2_WIDTH
#define EPD_HEIGHT  EPD_1IN54_V2_HEIGHT

void EPD_SPI_Init(void);
void EPD_Init(void);
void EPD_Init_Partial(void);

// The shown image is stored in this variable
extern UBYTE *BlackImage;

// SPI handle
extern SPI_HandleTypeDef hspi1;

#endif /* EPAPER_EPAPER_H_ */
