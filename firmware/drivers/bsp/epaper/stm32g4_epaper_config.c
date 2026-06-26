/*****************************************************************************
* | File      	:   stm32g4_epaper_config.c
* | Author      :   Waveshare team
* | Function    :   Hardware underlying interface
* | Info        :
*                Used to shield the underlying layers of each master
*                and enhance portability
*----------------
* |	This version:   V2.0
* | Date        :   2018-10-30
* | Info        :
# ******************************************************************************
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/

#include <epaper/stm32g4_epaper_config.h>
#include <stdbool.h>
#include "stm32g4xx_hal.h"
void DEV_Digital_Write(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t value)
{
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin, (GPIO_PinState)value);
}

uint8_t DEV_Digital_Read(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    return HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);
}

void DEV_SPI_WriteByte(uint8_t data)
{
    HAL_SPI_Transmit(&EPD_SPI_HANDLE, &data, 1, 100);
}

// Variable globale pour optimiser (déclare ça dans ton .h)
static volatile uint8_t spi_dummy_read;

// LA FONCTION MAGIQUE qui règle ton problème
/*void DEV_SPI_WriteByte(uint8_t data) {
    // ÉTAPE 1 : Attente TX libre (ULTRA-RAPIDE, pas de timeout lent)
    register uint32_t timeout = 1000; // Court mais suffisant
    while (!(SPI1->SR & SPI_SR_TXE)) {
        if (--timeout == 0) return; // Sortie rapide si problème
        __NOP(); // Une seule instruction, pas de boucle
    }

    // ÉTAPE 2 : Envoi donnée (registre direct = INSTANTANÉ)
    *(__IO uint8_t *)&SPI1->DR = data;

    // ÉTAPE 3 : ASTUCE CRITIQUE - Attente intelligente
    // On attend JUSTE ce qu'il faut pour l'E-Paper, pas plus
    timeout = 500; // Réduit de moitié vs solution 2
    while ((SPI1->SR & SPI_SR_BSY)) {
        if (--timeout == 0) break; // Pas de blocage infini
        // PAS de __NOP() ici = plus rapide pour le MPU6050
    }

    // ÉTAPE 4 : Nettoyage RX (OBLIGATOIRE pour E-Paper)
    if (SPI1->SR & SPI_SR_RXNE) {
        spi_dummy_read = *(__IO uint8_t*)&SPI1->DR;
    }

    // ÉTAPE 5 : LE DÉLAI MINIMAL pour E-Paper (CRUCIAL)
    // Seulement 3 NOPs au lieu de 10 = 5x plus rapide !
    __NOP(); __NOP(); __NOP();
}*/

void DEV_Delay_ms(uint32_t ms)
{
    HAL_Delay(ms);
}

void DEV_Module_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.Pin = EPD_CS_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(EPD_CS_GPIO, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = EPD_RST_PIN;
    HAL_GPIO_Init(EPD_RST_GPIO, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = EPD_DC_PIN;
    HAL_GPIO_Init(EPD_DC_GPIO, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = EPD_BUSY_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    HAL_GPIO_Init(EPD_BUSY_GPIO, &GPIO_InitStruct);

    // TODO: Directement initialiser SPI ici au lieu du main()

    DEV_Digital_Write(EPD_CS_GPIO, EPD_CS_PIN, 1);
    printf("DEV_Module_Init OK\r\n");
}

void DEV_Module_Exit(void)
{
    DEV_Digital_Write(EPD_CS_GPIO, EPD_CS_PIN, 0);
}
