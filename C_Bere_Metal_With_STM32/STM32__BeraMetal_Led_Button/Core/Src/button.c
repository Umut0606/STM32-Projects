/*
 * button.c
 *
 *  Created on: Dec 4, 2025
 *      Author: USER
 */

#include "button.h"
#include "peripherals.h" // Düşük seviye adreslere erişim için

// Button_Init, sadece Buton ile ilgili (PA0) pin yapılandırmasını yapar.
void Button_Init(void) {
	// 1. Saat Sinyalini Etkinleştirme (GPIOA için)
	RCC_AHB1ENR |= (1UL << 0);

	// 2. Buton Pinini (PA0) Giriş Moduna Ayarlama (00)
#define BUTTON_MODE_POS (BUTTON_PIN * 2)
	GPIOA_MODER &= ~(0b11UL << BUTTON_MODE_POS); // 00 olarak ayarla

	// 3. Pull-Down Direncini Etkinleştirme (10)
#define BUTTON_PUPD_POS (BUTTON_PIN * 2)
	GPIOA_PUPDR &= ~(0b11UL << BUTTON_PUPD_POS); // Önce temizle (00 yap)
	GPIOA_PUPDR |= (0b10UL << BUTTON_PUPD_POS);  // Sonra 10 yap (Pull-Down)
}

uint8_t Button_IsPressed(void) {
	// IDR (Giriş Veri Kaydı) oku ve Buton bitini maskele
	// Pull-Down olduğu için, okunan değer 1 ise basılıdır.
	if (GPIOA_IDR & (1UL << BUTTON_PIN)) {
		return 1; // Basılı (TRUE)
	} else {
		return 0; // Basılı Değil (FALSE)
	}
}
