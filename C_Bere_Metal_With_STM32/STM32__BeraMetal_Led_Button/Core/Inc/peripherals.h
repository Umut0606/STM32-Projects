/*
 * peripherals.h
 *
 *  Created on: Dec 4, 2025
 *      Author: USER
 */

#ifndef INC_PERIPHERALS_H_
#define INC_PERIPHERALS_H_

#include <stdint.h>

// ========== YAZMAÇ ADRESLERİ (Örn: STM32) ==========
#define RCC_BASE      0x40023800
#define GPIOD_BASE    0x40020C00  // LED Portu
#define GPIOA_BASE    0x40020000  // Buton Portu

// Yazmaç Pointerları (Doğrudan donanım adreslerine erişim)
#define RCC_AHB1ENR   (*(volatile uint32_t *)(RCC_BASE + 0x30))
#define GPIOD_MODER   (*(volatile uint32_t *)(GPIOD_BASE + 0x00))
#define GPIOD_ODR     (*(volatile uint32_t *)(GPIOD_BASE + 0x14))
#define GPIOA_MODER   (*(volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_IDR     (*(volatile uint32_t *)(GPIOA_BASE + 0x10))
#define GPIOA_PUPDR   (*(volatile uint32_t *)(GPIOA_BASE + 0x0C))

// ========== PIN TANIMLARI ==========
#define LED_PIN       12  // GPIOD Pin 12
#define BUTTON_PIN    0   // GPIOA Pin 0

// ========== FONKSİYON PROTOTİPLERİ ==========
// Düşük seviye pin yapılandırması bu modülde yer alsın.
void Peripheral_Init(void);

#endif /* INC_PERIPHERALS_H_ */
