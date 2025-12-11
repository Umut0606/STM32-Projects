/*
 * led.h
 *
 *  Created on: Nov 28, 2025
 *      Author: USER
 */
// led.h - LED Kontrol Fonksiyon Protokolleri
#ifndef LED_H
#define LED_H

#include "peripherals.h"
//peripherals.h den geliyor
// PD12 pininin ODR kaydındaki bit pozisyonu
#define LED_PIN             (1U << LED_PIN_POS) // LED_PIN_POS = 12

void LED_Init(void);
void LED_On(void);
void LED_Off(void);
void LED_Toggle(void);

#endif // LED_H
