/*
 * peripherals.h
 *
 *  Created on: Nov 28, 2025
 *      Author: USER
 */

// peripherals.h - GPIO ve RCC Kayıtçı Adres Tanımları
#ifndef PERIPHERALS_H
#define PERIPHERALS_H

#include <stdint.h>

// --- GPIO Port D (PD12 LED'in bulunduğu port) ---
#define GPIOD_BASE          (0x40020C00)

// GPIO Kayıtçı Yapısını Struct ile Modeller
typedef volatile struct {
	uint32_t MODER;     // Uzaklik +0x00: Mod Kaydı
	uint32_t OTYPER;    // Uzaklik +0x04: Tip Kaydı
	uint32_t OSPEEDR;   // Uzaklik +0x08: Hız Kaydı
	uint32_t PUPDR;     // Uzaklik +0x0C: Pull-Up/Down Kaydı
	uint32_t IDR;       // Uzaklik +0x10: Giriş Veri Kaydı
	uint32_t ODR;       // Uzaklik +0x14: Çıkış Veri Kaydı
	uint32_t BSRR;      // Uzaklik +0x18: Bit Set/Reset Kaydı
} GPIO_Type;

// GPIOD Base Adresini Struct'a Cast Etme
#define GPIOD               ((GPIO_Type *)GPIOD_BASE)

// --- RCC (Saat Kontrolü) Tanımları ---
#define RCC_BASE            (0x40023800)
#define RCC_AHB1ENR         (*((volatile uint32_t *)(RCC_BASE + 0x30))) // AHB1 Saat Etkinleştirme Kaydı

// --- PD12 Pini için Bit Pozisyonları ---
#define LED_PIN_POS         12      // PD12
#define GPIODEN_BIT         (1U << 3) // RCC AHB1ENR Kaydındaki GPIOD Saat Biti

#endif // PERIPHERALS_H
