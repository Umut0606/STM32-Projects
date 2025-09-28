#include "led.h"
#include "stm32f4xx_hal.h"

LED::LED(GPIO_TypeDef *port, uint16_t pin, bool active_low) noexcept :
		m_port(port), m_pin(pin), m_active_low(active_low) {
	// Pin'i output olarak başlat (opsiyonel, HAL ile yapılandırılmamışsa)
	GPIO_InitTypeDef GPIO_InitStruct = { };
	GPIO_InitStruct.Pin = m_pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(m_port, &GPIO_InitStruct);

	off(); // Başlangıçta LED kapalı
}

void LED::write(bool state) noexcept {
	GPIO_PinState ps = (state ^ m_active_low) ? GPIO_PIN_SET : GPIO_PIN_RESET;
	HAL_GPIO_WritePin(m_port, m_pin, ps);
}

void LED::on() noexcept {
	write(true);
}
void LED::off() noexcept {
	write(false);
}

void LED::toggle() noexcept {
	HAL_GPIO_TogglePin(m_port, m_pin);
}

void LED::blink(uint32_t ms_on, uint32_t ms_off, uint32_t times) noexcept {
	for (uint32_t i = 0; i < times; ++i) {
		on();
		HAL_Delay(ms_on);
		off();
		HAL_Delay(ms_off);
	}
}
