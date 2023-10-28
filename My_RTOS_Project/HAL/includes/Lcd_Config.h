/*
 * Lcd_Config.h
 *
 *  Created on: Sep 12, 2022
 *      Author: 10
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

//This is a file to define index of pins

// LCD is attached to PORTB

// DIO_U8_PIN_0

#define LCD_MODE FOUR_BIT_MODE

#define EIGHT_BIT_MODE 0
#define FOUR_BIT_MODE 1

#define LCD_DATA_PORT GPIOA

#define D7 GPIO_PIN_7
#define D6 GPIO_PIN_6
#define D5 GPIO_PIN_5
#define D4 GPIO_PIN_4
// Added in case of eight bit
#define D3 GPIO_PIN_7
#define D2 GPIO_PIN_2
#define D1 GPIO_PIN_1
#define D0 GPIO_PIN_0

#define LCD_CMD_PORT GPIOB

#define RS GPIO_PIN_0  //
#define RW GPIO_PIN_2  //
#define EN GPIO_PIN_1  //

#endif /* HAL_LCD_LCD_CONFIG_H_ */
