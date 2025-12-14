/*
 * button.c
 *
 *  Created on: Dec 14, 2025
 *      Author: USER
 */


#include "button.h"
#include "peripherals.h"

#define BUTTON_PORT  GPIOA

void Button_Init(void)
{
    /* Input mode */
    BUTTON_PORT->MODER &= ~(3U << (BUTTON_PIN * 2));

    /* Pull-down */
    BUTTON_PORT->PUPDR &= ~(3U << (BUTTON_PIN * 2));
    BUTTON_PORT->PUPDR |=  (2U << (BUTTON_PIN * 2));
}

uint8_t Button_IsPressed(void)
{
    static uint8_t last_state = 0;
    uint8_t current_state =
        (BUTTON_PORT->IDR & (1U << BUTTON_PIN)) ? 1U : 0U;

    if ((current_state == 1U) && (last_state == 0U))
    {
        last_state = 1U;
        return 1U;   /* Rising edge */
    }

    if (current_state == 0U)
    {
        last_state = 0U;
    }

    return 0U;
}
