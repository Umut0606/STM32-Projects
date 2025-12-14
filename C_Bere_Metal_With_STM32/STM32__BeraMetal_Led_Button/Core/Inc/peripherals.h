/*
 * peripherals.h
 *
 *  Created on: Dec 14, 2025
 *      Author: USER
 */

#ifndef PERIPHERALS_H
#define PERIPHERALS_H

#include <stdint.h>

/* ================= GPIO REGISTER MAP ================= */
typedef struct
{
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
} GPIO_RegDef_t;

/* ================= BASE ADDRESSES ================= */
#define GPIOA_BASE   (0x40020000UL)
#define GPIOD_BASE   (0x40020C00UL)
#define RCC_BASE     (0x40023800UL)

/* ================= PERIPHERAL DEFINITIONS ================= */
#define GPIOA   ((GPIO_RegDef_t *)GPIOA_BASE)
#define GPIOD   ((GPIO_RegDef_t *)GPIOD_BASE)

/* ================= RCC ================= */
#define RCC_AHB1ENR   (*(volatile uint32_t *)(RCC_BASE + 0x30UL))

#define RCC_GPIOA_EN  (1U << 0)
#define RCC_GPIOD_EN  (1U << 3)

/* ================= PIN DEFINITIONS ================= */
#define LED_PIN        12U   /* PD12 */
#define BUTTON_PIN     0U    /* PA0 */

void Peripherals_Init(void);

#endif
