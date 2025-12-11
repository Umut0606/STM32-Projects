/*
 * led.c
 *
 *  Created on: Dec 4, 2025
 *      Author: USER
 */

#include "led.h"
#include "peripherals.h" // Düşük seviye adreslere erişim için

// LED_Init, sadece LED ile ilgili (PD12) pin yapılandırmasını yapar.
void LED_Init(void) {
	// 1. Saat Sinyalini Etkinleştirme (GPIOD için)
	RCC_AHB1ENR |= (1UL << 3);

	// 2. LED Pinini (PD12) Çıkış Moduna Ayarlama (01)
#define LED_MODE_POS (LED_PIN * 2)
	GPIOD_MODER &= ~(0b11UL << LED_MODE_POS); // Önce temizle (00 yap)
	GPIOD_MODER |= (0b01UL << LED_MODE_POS);  // Sonra 01 yap
}

void LED_On(void) {
	GPIOD_ODR |= (1UL << LED_PIN);
}

void LED_Off(void) {
	GPIOD_ODR &= ~(1UL << LED_PIN);
}

void LED_Toggle(void) {
	// XOR (^) ile mevcut değeri tersine çevir.
	GPIOD_ODR ^= (1UL << LED_PIN);
}
