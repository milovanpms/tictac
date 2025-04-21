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
void SPI_Init(void)
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

// Init and demo function
void EPD_Demo(void)
{
    printf("EPD_1IN54_V2 Demo\r\n");

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
    Paint_NewImage(BlackImage, EPD_WIDTH, EPD_HEIGHT, 270, WHITE);
    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);

    // Dessine du texte
    //Paint_DrawString_EN(10, 20, "STM32G431KB", &Font16, WHITE, BLACK);
    //Paint_DrawString_EN(10, 40, "TOP 7 FAVE", &Font16, WHITE, BLACK);

    // Dessine des formes
    //Paint_DrawRectangle(10, 60, 190, 90, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
    //Paint_DrawLine(10, 60, 190, 90, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    //Paint_DrawLine(190, 60, 10, 90, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);

    //Paint_DrawCircle(100, 120, 30, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
    Paint_DrawBitMap(image);
    // Affiche l'image (le texte, les formes, tout ce qu'on veut) sur l'écran
    EPD_1IN54_V2_Display(BlackImage);

    // Met en veille profonde l'écran après affichage
    EPD_1IN54_V2_Sleep();

    // Libére la mémoire
    free(BlackImage);
    BlackImage = NULL;
}

// Init and demo function
void EPD_Demo_Text(void)
{
    printf("EPD_1IN54_V2 Demo\r\n");

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
    Paint_NewImage(BlackImage, EPD_WIDTH, EPD_HEIGHT, 270, WHITE);
    Paint_SelectImage(BlackImage);
    Paint_Clear(BLACK);

    // Dessine du texte
    // PixeloidSans18: OK
    //Paint_DrawString_EN(12, 20, "Mesure en cours", &PixeloidSans18, BLACK, WHITE);
    //Paint_DrawString_EN(12, 40, "Mesure terminee", &PixeloidSans18, BLACK, WHITE);
    //Paint_DrawString_EN(12, 60, "Mesure annulee", &PixeloidSans18, BLACK, WHITE);
    //Paint_DrawString_EN(12, 100, "Je m'appelle Milovan et j'aime beaucoup programmer.", &PixeloidSans18, BLACK, WHITE);

    // Mesure en cours
    Paint_DrawBitMap_Paste(cadre, 77, 17, 49, 49, false); // Ne pas bouger le cadre
    Paint_DrawBitMap_Paste(info, 97, 29, 9, 23, false);
    Paint_DrawString_EN(15, 70, "Mesure en cours", &PixeloidSans18, BLACK, WHITE); // OK
    Paint_DrawString_EN(21, 90+7, "   Ne bougez pas", &PixeloidSans15, BLACK, WHITE); // OK
    Paint_DrawString_EN(22, 107+7, "pendant la mesure.", &PixeloidSans15, BLACK, WHITE); // OK
    Paint_DrawBitMap_Paste(coeur, 22+7, 114+33, 47, 36, false);
    Paint_DrawString_EN(85+4, 150, "90 bpm", &PixeloidSans22, BLACK, WHITE); // OK*/

    /*// Mesure terminée
    Paint_DrawBitMap_Paste(cadre, 77, 17, 49, 49, false); // Ne pas bouger le cadre
    Paint_DrawBitMap_Paste(ok, 89, 33, 27, 19, false);
    Paint_DrawString_EN(15, 70, "aaaaa", &PixeloidSans18, BLACK, WHITE); // OK
    Paint_DrawBitMap_Paste(grosPouce, 22+7, 114+33, 38, 45, false);
    Paint_DrawString_EN(85+4, 150, "90 bpm", &PixeloidSans18, BLACK, WHITE); // OK*/


    // Tests taille polices
    //Paint_DrawString_EN(30, 0, "<140 <180 >180", &PixeloidSans12, BLACK, WHITE);
    //Paint_DrawString_EN(30, 20, "<140 <180 >180", &PixeloidSans15, BLACK, WHITE);
    //Paint_DrawString_EN(30, 40, "<140 <180 >180", &PixeloidSans16, BLACK, WHITE); // OK
    //Paint_DrawString_EN(30, 60, "<140 <180 >180", &PixeloidSans17, BLACK, WHITE); // OK
    //Paint_DrawString_EN(12, 80, "Mesure", &PixeloidSans16, BLACK, WHITE); // OK
    //Paint_DrawString_EN(12, 100, "Mesure", &PixeloidSans17, BLACK, WHITE); // OK

    //Paint_DrawString_EN(12, 40, "Mesure terminee", &PixeloidSans16, BLACK, WHITE);
    //Paint_DrawString_EN(12, 60, "Mesure annulee", &PixeloidSans16, BLACK, WHITE);
    //Paint_DrawString_EN(12, 100, "Je m'appelle Milovan et j'aime beaucoup programmer.", &PixeloidSans16, BLACK, WHITE);

    // Dessine des formes
    //Paint_DrawRectangle(10, 60, 190, 90, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
    //Paint_DrawLine(10, 60, 190, 90, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    //Paint_DrawLine(190, 60, 10, 90, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);

    //Paint_DrawCircle(100, 120, 30, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
    //Paint_DrawBitMap(image);

    // Affiche l'image (le texte, les formes, tout ce qu'on veut) sur l'écran
    EPD_1IN54_V2_Display(BlackImage);

    // Met en veille profonde l'écran après affichage
    EPD_1IN54_V2_Sleep();

    // Libére la mémoire
    free(BlackImage);
    BlackImage = NULL;
}

