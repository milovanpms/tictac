/*
 * epaper.h
 *
 *  Created on: Apr 2, 2025
 *      Author: Milovan PMS
 */

#ifndef EPAPER_EPAPER_H_
#define EPAPER_EPAPER_H_

// Epaper screen size
#define EPD_WIDTH   EPD_1IN54_V2_WIDTH
#define EPD_HEIGHT  EPD_1IN54_V2_HEIGHT

void SPI_Init(void);
void EPD_Demo(void);

#endif /* EPAPER_EPAPER_H_ */
