/*
 * led.h
 *
 *  Created on: Dec 4, 2025
 *      Author: USER
 */

#ifndef INC_LED_H_
#define INC_LED_H_

// ========== FONKSİYON PROTOTİPLERİ ==========
void LED_Init(void);     // Sadece LED'e ait init (GPIO_Init'e gerek kalmayacak)
void LED_On(void);
void LED_Off(void);
void LED_Toggle(void);

#endif /* INC_LED_H_ */
