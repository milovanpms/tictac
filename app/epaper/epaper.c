/*
 * epaper.c
 *
 *  Created on: Apr 2, 2025
 *      Author: Milovan PMS
 */

// https://www.waveshare.com/wiki/1.54inch_e-Paper_Module_(B)_Manual#Working_With_STM32

#include <epaper/stm32g4_epaper_config.h>
#include "config.h"
#include "stm32g4_sys.h"

#include "stm32g4_systick.h"
#include "stm32g4_gpio.h"
#include "stm32g4_uart.h"
#include "stm32g4_utils.h"

#include <stdio.h>

// Epaper headers
#include "./epaper/stm32g4_epaper_com.h"
#include "./epaper/stm32g4_epaper_paint.h"
#include "epaper.h"
#include "epaper_bitmaps.h"

// The shown image is stored in this variable
UBYTE *BlackImage;

// SPI handle
SPI_HandleTypeDef hspi1;

// SPI init
void EPD_SPI_Init(void)
{
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_SPI1_CLK_ENABLE();

    // Configuration des broches SPI (SCK, MISO, MOSI)
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // PA5 = SCK, PA6 = MISO, PA7 = MOSI
    GPIO_InitStruct.Pin = GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // SPI init
    hspi1.Instance = SPI1;
    hspi1.Init.Mode = SPI_MODE_MASTER;
    hspi1.Init.Direction = SPI_DIRECTION_2LINES;
    hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
    hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
    hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
    hspi1.Init.NSS = SPI_NSS_SOFT;
    hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64; // Vitesse SPI (plus c'est haut plus c'est lent)
    hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
    hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
    hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
    hspi1.Init.CRCPolynomial = 7;
    hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
    hspi1.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;

    if (HAL_SPI_Init(&hspi1) != HAL_OK)
    {
        printf("SPI Init Error\r\n");
        while(1);
    }
}

void EPD_Init(void) {
    // Screen initialising
    EPD_1IN54_V2_Init();
    EPD_1IN54_V2_Clear();

    // Create a buffer image
    UWORD Image_Size = ((EPD_WIDTH % 8 == 0) ? (EPD_WIDTH / 8) : (EPD_WIDTH / 8 + 1)) * EPD_HEIGHT;

    if ((BlackImage = (UBYTE *)malloc(Image_Size)) == NULL) {
        printf("Failed to allocate memory for image\r\n");
        return;
    }

    printf("Allocated %d bytes for image buffer\r\n", Image_Size);

    // Erase the buffer image
    memset(BlackImage, 0xFF, Image_Size);

    // Initializes the graphics library
    Paint_NewImage(BlackImage, EPD_WIDTH, EPD_HEIGHT, 90, BLACK);
    Paint_SelectImage(BlackImage);
    Paint_Clear(BLACK);
}

void EPD_Init_Partial(void) {
    // Screen initialising in full mode first
    EPD_1IN54_V2_Init();

    // Fill screen with black
    EPD_1IN54_V2_Clear_Black();

    // Wait for the display to refresh
    HAL_Delay(200);

    // Now initialize in partial mode
    EPD_1IN54_V2_Init_Partial();

    // Create a buffer image
    UWORD Image_Size = ((EPD_WIDTH % 8 == 0) ? (EPD_WIDTH / 8) : (EPD_WIDTH / 8 + 1)) * EPD_HEIGHT;

    if ((BlackImage = (UBYTE *)malloc(Image_Size)) == NULL) {
        printf("Failed to allocate memory for image\r\n");
        return;
    }

    printf("Allocated %d bytes for image buffer\r\n", Image_Size);

    // Initialize the buffer image with BLACK (0x00) instead of WHITE (0xFF)
    memset(BlackImage, 0x00, Image_Size);

    // Initializes the graphics library
    Paint_NewImage(BlackImage, EPD_WIDTH, EPD_HEIGHT, 90, BLACK);
    Paint_SelectImage(BlackImage);
    Paint_Clear(BLACK);
}

