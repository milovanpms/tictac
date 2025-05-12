/*
 * epaper_displays.h
 *
 *  Created on: May 8, 2025
 *      Author: Milovan
 */

#ifndef EPAPER_EPAPER_DISPLAYS_H_
#define EPAPER_EPAPER_DISPLAYS_H_

void EPD_Display_MenuPrincipal(void);
void EPD_Display_MenuRF(void);
void EPD_Display_MesureEnCours(void);
void EPD_Display_MesureTerminee(void);
void EPD_Display_MesureAnnulee(void);
void EPD_Display_HistoriquePas(void);

void EPD_DisplayBaseImage(void);
void EPD_PartialUpdate(void);

void EPD_StateMachine(void);

#endif /* EPAPER_EPAPER_DISPLAYS_H_ */
