/*
 * utils.c
 *
 *  Created on: Nov 28, 2025
 *      Author: USER
 */

// utils.c - Basit Bloklamalı Gecikme (Busy-Waiting)
#include "utils.h"

// STM32F407 için kabaca ayarlanmış döngü sayısı
// NOT: Bu değer işlemcinin hızına ve derleyici optimizasyonuna göre değişir.
#define CYCLES_PER_MS       10000

void delay_ms(uint32_t ms) {
	for (uint32_t i = 0; i < ms; i++) {
		for (volatile uint32_t j = 0; j < CYCLES_PER_MS; j++) {
			// Hiçbir şey yapma, sadece zaman kaybet (Busy-Wait)
			__asm__("nop");
		}
	}
}
