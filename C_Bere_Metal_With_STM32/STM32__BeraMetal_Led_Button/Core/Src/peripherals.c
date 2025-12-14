/*
 * peripherals.c
 *
 *  Created on: Dec 14, 2025
 *      Author: USER
 */


#include "peripherals.h"

void Peripherals_Init(void)
{
    /* Clock enable */
    RCC_AHB1ENR |= RCC_GPIOA_EN;
    RCC_AHB1ENR |= RCC_GPIOD_EN;
}
