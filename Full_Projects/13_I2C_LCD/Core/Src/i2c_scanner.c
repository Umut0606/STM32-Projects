/*
 * i2c_scanner.c
 *
 *  Created on: Aug 22, 2025
 *      Author: USER
 */


#include "i2c_scanner.h"
#include <stdio.h>

extern I2C_HandleTypeDef hi2c1;

void I2C_Scanner(void)
{
    HAL_StatusTypeDef result;
    printf("I2C Scanner Basladi...\r\n");
    for(uint8_t i=1; i<128; i++)
    {
        result = HAL_I2C_IsDeviceReady(&hi2c1, (uint16_t)(i<<1), 1, 10);
        if(result == HAL_OK)
        {
            printf("I2C cihaz bulundu! Adres: 0x%X\r\n", i);
        }
    }
}
