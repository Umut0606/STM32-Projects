/*
 * lcd_i2c.h
 *
 *  Created on: Aug 22, 2025
 *      Author: USER
 */
#ifndef INC_LCD_I2C_H_
#define INC_LCD_I2C_H_
#define LCD_ADDRESS (0x27 << 1)   // scanner çıktısına göre 0x27 ya da 0x3F yaz
#include "stm32f4xx_hal.h"

void lcd_init(I2C_HandleTypeDef *hi2c, uint8_t lcd_addr);
void lcd_clear(void);
void lcd_set_cursor(uint8_t row, uint8_t col);
void lcd_send_string(char *str);
void lcd_send_cmd(char cmd);
void lcd_send_data(char data);

#endif /* INC_LCD_I2C_H_ */
