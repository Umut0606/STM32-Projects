/*
 * led.c
 *
 *  Created on: Nov 28, 2025
 *      Author: USER
 */

// led.c - PD12 LED Kontrol Fonksiyonları (Bare Metal)
#include "led.h"
#include <stdint.h>

void LED_Init(void) {
	// 1. Saat Sinyalini Aç (RCC): GPIO Port D'ye saat sinyali ver
	// RCC_AHB1ENR kaydında GPIODEN (3. bit) set edilir.
	RCC_AHB1ENR |= GPIODEN_BIT;

	// 2. Mod Kaydını Ayarla (MODER): PD12 pinini Çıkış (Output) moduna getir.
	// Önce ilgili bitleri sıfırla (00) // sıfırlamak için
	GPIOD->MODER &= ~(0x3 << (LED_PIN_POS * 2));

	// Sonra 01 (Output) değerini yaz
	GPIOD->MODER |= (0x1 << (LED_PIN_POS * 2));

	// Başlangıçta LED'i Kapat (Opsiyonel)
	LED_Off();
}

// LED'i AÇ (Pin'e Yüksek/HIGH sinyali gönder)
void LED_On(void) {
	// ODR (Output Data Register) kaydında LED'in bitini '1' yapar.
	// Bitwise OR işlemi (|=) ile LED_PIN bitini set ederken diğer bitleri korur.
	GPIOD->ODR |= LED_PIN;
}

// LED'i KAPAT (Pin'e Alçak/LOW sinyali gönder)
void LED_Off(void) {
	// ODR (Output Data Register) kaydında LED'in bitini '0' yapar.
	// Bitwise AND NOT işlemi (~&) ile LED_PIN bitini sıfırlarken diğer bitleri korur.
	GPIOD->ODR &= ~LED_PIN;
}

// LED'in Durumunu Değiştir (Açık ise Kapat, Kapalı ise Aç)
void LED_Toggle(void) {
	// ODR (Output Data Register) üzerinde XOR işlemi ile mevcut durumu tersine çevir.
	GPIOD->ODR ^= LED_PIN;
}
