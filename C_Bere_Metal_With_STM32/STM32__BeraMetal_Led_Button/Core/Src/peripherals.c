/*
 * peripherals.c
 *
 *  Created on: Dec 8, 2025
 *      Author: USER
 */

#include "peripherals.h"

void Peripheral_Init(void) {
	// Tüm portlar için saat sinyallerini burada etkinleştir
	RCC_AHB1ENR |= (1UL << 0); // GPIOA Saati
	RCC_AHB1ENR |= (1UL << 3); // GPIOD Saati
	// Diğer çevre birimleri (TIMER, ADC vb.) saatleri buraya gelecek
}
