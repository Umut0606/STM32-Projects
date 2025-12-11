/*
 * button.h
 *
 *  Created on: Dec 4, 2025
 *      Author: USER
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include <stdint.h>

// ========== FONKSİYON PROTOTİPLERİ ==========
void Button_Init(void);
// Debouncing (zıplama önleme) mantığı burada uygulanabilir.
uint8_t Button_IsPressed(void);

#endif /* INC_BUTTON_H_ */
