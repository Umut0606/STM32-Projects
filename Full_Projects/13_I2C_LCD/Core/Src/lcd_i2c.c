/*
 * lcd_i2c.c
 *
 *  Created on: Aug 22, 2025
 *      Author: USER
 */


#include "lcd_i2c.h"

static I2C_HandleTypeDef *_hi2c;
static uint8_t _lcd_addr;

void lcd_send_cmd(char cmd) {
    uint8_t data_t[4];
    uint8_t data_u, data_l;
    data_u = (cmd & 0xF0);
    data_l = ((cmd << 4) & 0xF0);
    data_t[0] = data_u | 0x0C;  // en=1, rs=0
    data_t[1] = data_u | 0x08;  // en=0, rs=0
    data_t[2] = data_l | 0x0C;  // en=1, rs=0
    data_t[3] = data_l | 0x08;  // en=0, rs=0
    HAL_I2C_Master_Transmit(_hi2c, _lcd_addr, data_t, 4, 100);
}

void lcd_send_data(char data) {
    uint8_t data_t[4];
    uint8_t data_u, data_l;
    data_u = (data & 0xF0);
    data_l = ((data << 4) & 0xF0);
    data_t[0] = data_u | 0x0D;  // en=1, rs=1
    data_t[1] = data_u | 0x09;  // en=0, rs=1
    data_t[2] = data_l | 0x0D;  // en=1, rs=1
    data_t[3] = data_l | 0x09;  // en=0, rs=1
    HAL_I2C_Master_Transmit(_hi2c, _lcd_addr, data_t, 4, 100);
}

void lcd_clear(void) {
    lcd_send_cmd(0x01);
    HAL_Delay(2);
}

void lcd_set_cursor(uint8_t row, uint8_t col) {
    uint8_t row_offsets[] = {0x80, 0xC0};
    lcd_send_cmd(row_offsets[row] + col);
}

void lcd_send_string(char *str) {
    while (*str) lcd_send_data(*str++);
}

void lcd_init(I2C_HandleTypeDef *hi2c, uint8_t lcd_addr) {
    _hi2c = hi2c;
    _lcd_addr = lcd_addr;

    HAL_Delay(50);
    lcd_send_cmd(0x30);
    HAL_Delay(5);
    lcd_send_cmd(0x30);
    HAL_Delay(1);
    lcd_send_cmd(0x30);
    lcd_send_cmd(0x20); // 4-bit mode

    lcd_send_cmd(0x28); // function set: 4-bit, 2 line, 5x8 dots
    lcd_send_cmd(0x08); // display off
    lcd_send_cmd(0x01); // clear display
    HAL_Delay(2);
    lcd_send_cmd(0x06); // entry mode
    lcd_send_cmd(0x0C); // display on, cursor off
}
