/*
 * led.c
 *
 *  Created on: Dec 14, 2025
 *      Author: USER
 */


#include "led.h"
#include "peripherals.h"

#define LED_PORT   GPIOD

void LED_Init(void)
{
    /* Output mode */
    LED_PORT->MODER &= ~(3U << (LED_PIN * 2));
    LED_PORT->MODER |=  (1U << (LED_PIN * 2));

    /* Push-pull, no pull-up/down */
    LED_PORT->OTYPER &= ~(1U << LED_PIN);
    LED_PORT->PUPDR  &= ~(3U << (LED_PIN * 2));
}

void LED_On(void)
{
    LED_PORT->BSRR = (1U << LED_PIN);
}

void LED_Off(void)
{
    LED_PORT->BSRR = (1U << (LED_PIN + 16));
}

void LED_Toggle(void)
{
    LED_PORT->ODR ^= (1U << LED_PIN);
}
