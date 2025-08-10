#include "lcd.h"
#include "stm32f4xx_hal.h"

// LCD Pinlerini tanımla
#define RS_Pin GPIO_PIN_0
#define RS_Port GPIOD
#define E_Pin  GPIO_PIN_1
#define E_Port GPIOD
#define D4_Pin GPIO_PIN_4
#define D4_Port GPIOD
#define D5_Pin GPIO_PIN_5
#define D5_Port GPIOD
#define D6_Pin GPIO_PIN_6
#define D6_Port GPIOD
#define D7_Pin GPIO_PIN_7
#define D7_Port GPIOD

// Komut gönderme fonksiyonu
void lcd_send_cmd(char cmd)
{
    char cmd_high = (cmd >> 4) & 0x0F; // Üst nibble
    char cmd_low = cmd & 0x0F;         // Alt nibble

    // RS = 0 (komut)
    HAL_GPIO_WritePin(RS_Port, RS_Pin, GPIO_PIN_RESET);

    // Yüksek nibble gönder
    HAL_GPIO_WritePin(D4_Port, D4_Pin, (cmd_high >> 0) & 0x01);
    HAL_GPIO_WritePin(D5_Port, D5_Pin, (cmd_high >> 1) & 0x01);
    HAL_GPIO_WritePin(D6_Port, D6_Pin, (cmd_high >> 2) & 0x01);
    HAL_GPIO_WritePin(D7_Port, D7_Pin, (cmd_high >> 3) & 0x01);

    HAL_GPIO_WritePin(E_Port, E_Pin, GPIO_PIN_SET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(E_Port, E_Pin, GPIO_PIN_RESET);

    // Düşük nibble gönder
    HAL_GPIO_WritePin(D4_Port, D4_Pin, (cmd_low >> 0) & 0x01);
    HAL_GPIO_WritePin(D5_Port, D5_Pin, (cmd_low >> 1) & 0x01);
    HAL_GPIO_WritePin(D6_Port, D6_Pin, (cmd_low >> 2) & 0x01);
    HAL_GPIO_WritePin(D7_Port, D7_Pin, (cmd_low >> 3) & 0x01);

    HAL_GPIO_WritePin(E_Port, E_Pin, GPIO_PIN_SET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(E_Port, E_Pin, GPIO_PIN_RESET);
}

// Data gönderme fonksiyonu
void lcd_send_data(char data)
{
    char data_high = (data >> 4) & 0x0F;
    char data_low = data & 0x0F;

    // RS = 1 (veri)
    HAL_GPIO_WritePin(RS_Port, RS_Pin, GPIO_PIN_SET);

    // Yüksek nibble gönder
    HAL_GPIO_WritePin(D4_Port, D4_Pin, (data_high >> 0) & 0x01);
    HAL_GPIO_WritePin(D5_Port, D5_Pin, (data_high >> 1) & 0x01);
    HAL_GPIO_WritePin(D6_Port, D6_Pin, (data_high >> 2) & 0x01);
    HAL_GPIO_WritePin(D7_Port, D7_Pin, (data_high >> 3) & 0x01);

    HAL_GPIO_WritePin(E_Port, E_Pin, GPIO_PIN_SET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(E_Port, E_Pin, GPIO_PIN_RESET);

    // Düşük nibble gönder
    HAL_GPIO_WritePin(D4_Port, D4_Pin, (data_low >> 0) & 0x01);
    HAL_GPIO_WritePin(D5_Port, D5_Pin, (data_low >> 1) & 0x01);
    HAL_GPIO_WritePin(D6_Port, D6_Pin, (data_low >> 2) & 0x01);
    HAL_GPIO_WritePin(D7_Port, D7_Pin, (data_low >> 3) & 0x01);

    HAL_GPIO_WritePin(E_Port, E_Pin, GPIO_PIN_SET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(E_Port, E_Pin, GPIO_PIN_RESET);
}

void lcd_clear(void)
{
    lcd_send_cmd(0x01);
    HAL_Delay(2);
}

void lcd_put_cur(int row, int col)
{
    switch(row)
    {
        case 0:
            lcd_send_cmd(0x80 + col);
            break;
        case 1:
            lcd_send_cmd(0xC0 + col);
            break;
    }
}

void lcd_send_string(char *str)
{
    while(*str) lcd_send_data(*str++);
}

void lcd_init(void)
{
    HAL_Delay(50);
    lcd_send_cmd(0x02); // 4-bit mode
    lcd_send_cmd(0x28); // 2 line, 5x7 matrix
    lcd_send_cmd(0x0C); // display on, cursor off
    lcd_send_cmd(0x06); // increment cursor
    lcd_send_cmd(0x01); // clear display
    HAL_Delay(2);
}


