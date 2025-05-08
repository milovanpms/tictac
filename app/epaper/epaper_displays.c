/*
 * epaper_displays.c
 *
 *  Created on: May 8, 2025
 *      Author: Milovan
 */

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

void EPD_Display_MenuPrincipal(void) {
    //////////////////
    // AFFICHAGE: Menu principal
    Paint_DrawBitMap_Paste(menuBox, 21, 21, 71, 71, false); // Ne pas bouger les cadres
    Paint_DrawBitMap_Paste(statIcon, 21+(71/2)/2+1, 21+(71/2)/2+1, 36, 36, false);
    Paint_DrawBitMap_Paste(filledDot, 21+(71/2)-1, 21+71+5, 5, 5, false);

    Paint_DrawBitMap_Paste(menuBox, 21+71+16, 21, 71, 71, false); // Ne pas bouger les cadres
    Paint_DrawBitMap_Paste(hommeCoeur, 21+(71/2)/2+1+89, 21+(71/2)/2+1, 36, 36, false);
    Paint_DrawBitMap_Paste(emptyDot, 21+(71/2)-1+87, 21+71+5, 5, 5, false);

    Paint_DrawBitMap_Paste(menuBox, 21, 21+71+16, 71, 71, false); // Ne pas bouger les cadres
    Paint_DrawBitMap_Paste(hack, 21+(71/2)/2+1, 21+(71/2)/2+1+87, 36, 36, false);
    Paint_DrawBitMap_Paste(emptyDot, 21+(71/2)-1, 21+(71/2)-1+87+43, 5, 5, false);

    Paint_DrawBitMap_Paste(menuBox, 21+71+16, 21+71+16, 71, 71, false); // Ne pas bouger les cadres
    Paint_DrawBitMap_Paste(settings, 21+(71/2)/2+1+87, 21+(71/2)/2+1+87, 36, 36, false);
    Paint_DrawBitMap_Paste(emptyDot, 21+(71/2)-1+87, 21+(71/2)-1+87+43, 5, 5, false);
    //
    //////////////////
}

void EPD_Display_MenuRF(void) {
    //////////////////
    // AFFICHAGE: Menu RF
    Paint_DrawBitMap_Paste(menuBoxPetit, 12, 68, 54, 54, false); // Ne pas bouger les cadres
    Paint_DrawBitMap_Paste(satellite, 12+(54/2)/2-1, 158/2+1, 30, 30, false);
    Paint_DrawBitMap_Paste(emptyDot, 12+(54/2)-1, 130, 5, 5, false);

    Paint_DrawBitMap_Paste(menuBoxPetit, 200-12-53-53-8, 68, 54, 54, false); // Ne pas bouger les cadres
    Paint_DrawBitMap_Paste(plume, 12+(54/2)/2+10+54-1, 158/2+1, 30, 30, false);
    Paint_DrawBitMap_Paste(filledDot, 12+(54/2)-1+7+54, 130, 5, 5, false);

    Paint_DrawBitMap_Paste(menuBoxPetit, 200-12-53, 68, 54, 54, false); // Ne pas bouger les cadres
    Paint_DrawBitMap_Paste(mrnote, 12+(54/2)/2+10+54+4+54-1, 158/2+1, 30, 30, false);
    Paint_DrawBitMap_Paste(emptyDot, 12+(54/2)-1+7+54+7+54, 130, 5, 5, false);

    Paint_DrawString_EN(56, 163, "Dupliquer", &PixeloidSans18, BLACK, WHITE); // OK
    //
    //////////////////
}

void EPD_Display_MesureEnCours(void) {
    //////////////////
    // AFFICHAGE: Mesure en cours
    Paint_DrawBitMap_Paste(cadre, 77, 17, 49, 49, false); // Ne pas bouger le cadre
    Paint_DrawBitMap_Paste(info, 97, 29, 9, 23, false);
    Paint_DrawString_EN(15, 70, "Mesure en cours", &PixeloidSans18, BLACK, WHITE); // OK
    Paint_DrawString_EN(21-3, 90+7, "   Ne bougez pas", &PixeloidSans15, BLACK, WHITE); // OK
    Paint_DrawString_EN(22-3, 107+7, "pendant la mesure.", &PixeloidSans15, BLACK, WHITE); // OK
    Paint_DrawBitMap_Paste(coeur, 22+5, 114+33, 47, 36, false); // TODO: Déplacer vers la gauche le coeur quand on a un BPM à 3 chiffres
    Paint_DrawString_EN(85+2, 150, "121 bpm", &PixeloidSans22, BLACK, WHITE); // TODO: Déplacer vers la gauche le BPM quand on a un BPM à 3 chiffres
    //
    //////////////////
}

void EPD_Display_MesureTerminee(void) {
    //////////////////
    // AFFICHAGE: Mesure terminée
    Paint_DrawBitMap_Paste(cadre, 77, 17, 49, 49, false); // Ne pas bouger le cadre
    Paint_DrawBitMap_Paste(ok, 89, 33, 27, 19, false);
    Paint_DrawString_EN(15, 70, "Mesure terminee", &PixeloidSans18, BLACK, WHITE); // OK

    // Variante symbole santé (c'est moins propre mais plus intuitif)
    //Paint_DrawBitMap_Paste(grosPouce, 22+7+3, 114+33-42, 38, 45, false);
    //Paint_DrawString_EN(83+1, 158-42, "90 bpm", &PixeloidSans22, BLACK, WHITE); // OK

    // Variante coeur (c'est plus propre mais moins intuitif)
    Paint_DrawBitMap_Paste(coeur, 22+7, 114+33-38, 47, 36, false);
    Paint_DrawString_EN(85+4, 158-38-7, "90 bpm", &PixeloidSans22, BLACK, WHITE); // OK

    Paint_DrawBitMap_Paste(bande, 10-4, 165, 187, 21, false);
    Paint_DrawString_EN(32-4, 169, "<120", &PixeloidSans12, BLACK, WHITE);
    Paint_DrawString_EN(97-4, 169, "<160", &PixeloidSans12, BLACK, WHITE);
    Paint_DrawString_EN(163-3, 169, ">160", &PixeloidSans12, BLACK, WHITE);
    Paint_DrawBitMap_Paste(filledDot, 32-4+8, 189, 5, 5, false);
    Paint_DrawBitMap_Paste(emptyDot, 97-4+8, 189, 5, 5, false);
    Paint_DrawBitMap_Paste(emptyDot, 163-4+8, 189, 5, 5, false);
    //
    //////////////////
}

void EPD_Display_MesureAnnulee(void) {
    //////////////////
    // AFFICHAGE: Mesure annulée
    Paint_DrawBitMap_Paste(cadre, 77, 17, 49, 49, false); // Ne pas bouger le cadre
    Paint_DrawBitMap_Paste(croix, 91, 31, 21, 21, false);
    Paint_DrawString_EN(20, 70, "Mesure annulee", &PixeloidSans18, BLACK, WHITE); // OK
    Paint_DrawString_EN(21-3, 90+7, "   Ne bougez pas", &PixeloidSans15, BLACK, WHITE); // OK
    Paint_DrawString_EN(22-3, 107+7, "pendant la mesure.", &PixeloidSans15, BLACK, WHITE); // OK
    //
    //////////////////
}

void EPD_Display_HistoriquePas(void) {
    //////////////////
    // AFFICHAGE: Historique des pas
    Paint_DrawBitMap_Paste(leftArrow, 9, 155, 33, 33, false);
    Paint_DrawString_EN(52, 163, "mar 29/04", &PixeloidSans16, BLACK, WHITE); // OK
    Paint_DrawBitMap_Paste(rightArrow, 158, 155, 33, 33, false);
    Paint_DrawBitMap_Paste(montagne, 33-3, 32, 45, 45, false);
    Paint_DrawBitMap_Paste(position, 34-3, 92, 45, 45, false);
    Paint_DrawString_EN(90-3, 45, "2904 pas", &PixeloidSans18, BLACK, WHITE); // OK
    Paint_DrawString_EN(90-3, 106, "4.6 km", &PixeloidSans18, BLACK, WHITE); // OK
    //
    //////////////////
}

void EPD_DisplayBaseImage(void) {
    // Ne rien mettre ici car encre faible
    EPD_1IN54_V2_DisplayPartBaseImage(BlackImage);
}

void EPD_PartialUpdate(void) {
    Paint_DrawBitMap_Paste(leftArrow, 9, 155, 33, 33, false);
    Paint_DrawBitMap_Paste(rightArrow, 158, 155, 33, 33, false);
    Paint_DrawBitMap_Paste(montagne, 33-3, 32, 45, 45, false);
    Paint_DrawBitMap_Paste(position, 34-3, 92, 45, 45, false);
    EPD_1IN54_V2_DisplayPart(BlackImage);

    HAL_Delay(200);

    Paint_DrawString_EN(90-3, 45, "2907 pas", &PixeloidSans18, BLACK, WHITE); // OK
    Paint_DrawString_EN(52, 163, "mar 29/04", &PixeloidSans16, BLACK, WHITE); // OK
    Paint_DrawString_EN(90-3, 106, "4.6 km", &PixeloidSans18, BLACK, WHITE); // OK
    EPD_1IN54_V2_DisplayPart(BlackImage);

    HAL_Delay(200);

    Paint_DrawString_EN(90-3, 45, "2907 pas", &PixeloidSans18, BLACK, BLACK); // OK
    Paint_DrawString_EN(52, 163, "mar 29/04", &PixeloidSans16, BLACK, BLACK); // OK
    Paint_DrawString_EN(90-3, 106, "4.6 km", &PixeloidSans18, BLACK, BLACK); // OK
    EPD_1IN54_V2_DisplayPart(BlackImage);

    HAL_Delay(100);

    Paint_DrawString_EN(90-3, 45, "8412 pas", &PixeloidSans18, BLACK, WHITE); // OK
    Paint_DrawString_EN(52, 163, "mer 30/04", &PixeloidSans16, BLACK, WHITE); // OK
    Paint_DrawString_EN(90-3, 106, "7.3 km", &PixeloidSans18, BLACK, WHITE); // OK
    EPD_1IN54_V2_DisplayPart(BlackImage);

    HAL_Delay(200);

    Paint_DrawString_EN(90-3, 45, "8412 pas", &PixeloidSans18, BLACK, BLACK); // OK
    Paint_DrawString_EN(52, 163, "mer 30/04", &PixeloidSans16, BLACK, BLACK); // OK
    Paint_DrawString_EN(90-3, 106, "7.3 km", &PixeloidSans18, BLACK, BLACK); // OK
    EPD_1IN54_V2_DisplayPart(BlackImage);

    HAL_Delay(300);

    Paint_DrawString_EN(90-3, 45, "11645 pas", &PixeloidSans18, BLACK, WHITE); // OK
    Paint_DrawString_EN(52, 163, "jeu 01/05", &PixeloidSans16, BLACK, WHITE); // OK
    Paint_DrawString_EN(90-3, 106, "12.2 km", &PixeloidSans18, BLACK, WHITE); // OK
    EPD_1IN54_V2_DisplayPart(BlackImage);

    HAL_Delay(300);

    Paint_DrawRectangle(0, 0, Paint.Width - 1, Paint.Height - 1, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    EPD_1IN54_V2_DisplayPart(BlackImage);

    HAL_Delay(500);

    EPD_Display_MenuPrincipal();
    EPD_1IN54_V2_DisplayPart(BlackImage);
    HAL_Delay(300);

    Paint_DrawRectangle(0, 0, Paint.Width - 1, Paint.Height - 1, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    EPD_1IN54_V2_DisplayPart(BlackImage);

    HAL_Delay(500);

    EPD_Display_MenuRF();
    EPD_1IN54_V2_DisplayPart(BlackImage);
    HAL_Delay(300);

    Paint_DrawRectangle(0, 0, Paint.Width - 1, Paint.Height - 1, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    EPD_1IN54_V2_DisplayPart(BlackImage);

}


