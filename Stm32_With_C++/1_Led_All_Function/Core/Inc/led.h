/*
 * led.h
 *
 *  Created on: Sep 27, 2025
 *      Author: USER
 *  Description: Simple LED control class for STM32 using HAL library.
 */

#ifndef LED_H
#define LED_H

#include "stm32f4xx_hal.h"

class LED {
public:
	// Constructor: port ve pin belirlenir, aktif-low seçeneği isteğe bağlı
	LED(GPIO_TypeDef *port, uint16_t pin, bool active_low = false) noexcept;

	// LED'i yakar
	void on() noexcept;

	// LED'i söndürür
	void off() noexcept;

	// LED'in mevcut durumunu tersine çevirir
	void toggle() noexcept;

	// LED'i belirli sürelerde yakıp söndürür (bloklayıcı)
	void blink(uint32_t ms_on, uint32_t ms_off, uint32_t times = 1) noexcept;

	// LED durumunu manuel olarak yazdırır
	void write(bool state) noexcept;

private:
	GPIO_TypeDef *m_port;  // LED bağlı GPIO portu
	uint16_t m_pin;        // LED bağlı pin
	bool m_active_low;     // Aktif-low LED kullanımı
};

#endif // LED_H
