/*
 * Lcd.c
 *
 *  Created on: Sep 12, 2022
 *      Author: 10
 */


#include "Lcd.h"
#include <string.h>


#define GET_BIT(REG,PIN) ((REG>>PIN) & 0x1)


//ProtoType of static is defined in source file itself(Private declaration)
static ES_t LCD_ES_tTrigger_Enable(void);
static ES_t LCD_ES_tSet_Cursor_Pos(uint8_t row,uint8_t column);

//We make it static cuz we won't use it anywhere but here
static ES_t LCD_ES_tTrigger_Enable(void){
//	MCAL_GPIO_WritePin(LCD_CMD_PORT, EN, GPIO_PIN_HIGH);
	MCAL_GPIO_WritePin(LCD_CMD_PORT, EN, GPIO_PIN_HIGH);
//	_delay_us(10);
	wait_ms(1);
	MCAL_GPIO_WritePin(LCD_CMD_PORT, EN, GPIO_PIN_LOW);
//	MCAL_GPIO_WritePin(LCD_CMD_PORT, EN, LOW);
//	_delay_us(2000);
	wait_ms(2);
	return ES_OK;
}


ES_t Lcd_ES_tInit(){

	GPIO_PinConfig_t PinCfg;

	// Pins Configuration for LCD

	// RS output push pull mode
	PinCfg.GPIO_PinNumber = RS;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PUSHPULL;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_CMD_PORT, &PinCfg);

	// EN output push pull mode
	PinCfg.GPIO_PinNumber = EN;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PUSHPULL;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_CMD_PORT, &PinCfg);

	// D4 output push pull mode
	PinCfg.GPIO_PinNumber = D4;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PUSHPULL;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	// D5 output push pull mode
	PinCfg.GPIO_PinNumber = D5;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PUSHPULL;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	// D6 output push pull mode
	PinCfg.GPIO_PinNumber = D6;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PUSHPULL;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	// D7 output push pull mode
	PinCfg.GPIO_PinNumber = D7;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PUSHPULL;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);



#if LCD_MODE == FOUR_BIT_MODE
	Lcd_ES_tsendCmd(Four_BitMode);   /* Go into 4-bit operating mode*/
	Lcd_ES_tsendCmd(D4_D7);  /* 2 Line, 5*7 matrix in 4-bit mode */
	Lcd_ES_tsendCmd(CursorON);  /* Display on cursor off */
	Lcd_ES_tsendCmd(IncrCursor);  /* Increment cursor (shift cursor to right) */
	Lcd_ES_tsendCmd(CLR_Display);  /* Clear display screen */
	return ES_OK;
#elif LCD_MODE == EIGHT_BIT_MODE
	Lcd_ES_tsendCmd(Eight_BitMode);
	Lcd_ES_tsendCmd(CursorON);  /* Display on cursor off */
	Lcd_ES_tsendCmd(IncrCursor);  /* Increment cursor (shift cursor to right) */
	Lcd_ES_tsendCmd(CLR_Display);  /* Clear display screen */
	return ES_OK;
#endif
}

/*
 * RS = 0 // To send command
 * RW = 0 //To write on the LCD
 *  4-bit mode
 * Send higher nibble(1/2 Byte)
 * Send Trigger Enable
 * Send Lower nibble
 * Send Trigger Enable
 * delay
 *
 *
 *	Ex. 0x28 0b 0010 1000  //Read bit by bit and see if it is low or high
 */

void wait_ms(uint32_t time){
	uint32_t i,j;
	for(i=0;i<time;i++)
		for(j=0;j<255;j++);
}

ES_t lcd_ES_tclear()
{
	Lcd_ES_tsendCmd(CLR_Display);
	wait_ms(2);
	return ES_OK;
}

ES_t Lcd_ES_tsendCmd(uint8_t cmd){
//	MCAL_GPIO_WritePin(LCD_CMD_PORT, RS, LOW);
	MCAL_GPIO_WritePin(LCD_CMD_PORT, RS, GPIO_PIN_LOW);
//	MCAL_GPIO_WritePin(LCD_CMD_PORT, RW, LOW);
	MCAL_GPIO_WritePin(LCD_CMD_PORT, RW, GPIO_PIN_LOW);
	// DIO_ES_tGetPinValue, MCAL_GPIO_WritePin
	// if(GET_BIT(cmd,7)){Dio_Write(D7,HIGH);}else{Dio_write(D7,LOW);}
	// We use ternary operator instead
#if LCD_MODE == FOUR_BIT_MODE
	(GET_BIT(cmd,7)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D7,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D7,GPIO_PIN_LOW);
	(GET_BIT(cmd,6)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D6,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D6,GPIO_PIN_LOW);
	(GET_BIT(cmd,5)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D5,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D5,GPIO_PIN_LOW);
	(GET_BIT(cmd,4)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D4,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D4,GPIO_PIN_LOW);
	//Trigger Enable
	LCD_ES_tTrigger_Enable();
	(GET_BIT(cmd,3)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D7,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D7,GPIO_PIN_LOW);
	(GET_BIT(cmd,2)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D6,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D6,GPIO_PIN_LOW);
	(GET_BIT(cmd,1)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D5,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D5,GPIO_PIN_LOW);
	(GET_BIT(cmd,0)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D4,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D4,GPIO_PIN_LOW);
	//Trigger Enable
	LCD_ES_tTrigger_Enable();
	return ES_OK;
#elif LCD_MODE == EIGHT_BIT_MODE
	(GET_BIT(cmd,7)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D7,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D7,GPIO_PIN_LOW);
	(GET_BIT(cmd,6)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D6,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D6,GPIO_PIN_LOW);
	(GET_BIT(cmd,5)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D5,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D5,GPIO_PIN_LOW);
	(GET_BIT(cmd,4)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D4,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D4,GPIO_PIN_LOW);
	(GET_BIT(cmd,3)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D3,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D3,GPIO_PIN_LOW);
	(GET_BIT(cmd,2)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D2,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D2,GPIO_PIN_LOW);
	(GET_BIT(cmd,1)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D1,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D1,GPIO_PIN_LOW);
	(GET_BIT(cmd,0)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D0,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D0,GPIO_PIN_LOW);
	//Trigger Enable
	LCD_ES_tTrigger_Enable();
	return ES_OK;
#endif
}
ES_t Lcd_ES_tsendChar(uint8_t data){
#if LCD_MODE == FOUR_BIT_MODE
	MCAL_GPIO_WritePin(LCD_CMD_PORT, RS, GPIO_PIN_HIGH);
	MCAL_GPIO_WritePin(LCD_CMD_PORT, RW, GPIO_PIN_LOW);
	(GET_BIT(data,7)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D7,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D7,GPIO_PIN_LOW);
	(GET_BIT(data,6)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D6,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D6,GPIO_PIN_LOW);
	(GET_BIT(data,5)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D5,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D5,GPIO_PIN_LOW);
	(GET_BIT(data,4)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D4,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D4,GPIO_PIN_LOW);
	//Trigger Enable
	LCD_ES_tTrigger_Enable();
	(GET_BIT(data,3)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D7,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D7,GPIO_PIN_LOW);
	(GET_BIT(data,2)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D6,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D6,GPIO_PIN_LOW);
	(GET_BIT(data,1)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D5,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D5,GPIO_PIN_LOW);
	(GET_BIT(data,0)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D4,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D4,GPIO_PIN_LOW);
	//Trigger Enable
	LCD_ES_tTrigger_Enable();
	return ES_OK;
#elif LCD_MODE == EIGHT_BIT_MODE
	(GET_BIT(data,7)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D7,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D7,GPIO_PIN_LOW);
	(GET_BIT(data,6)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D6,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D6,GPIO_PIN_LOW);
	(GET_BIT(data,5)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D5,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D5,GPIO_PIN_LOW);
	(GET_BIT(data,4)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D4,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D4,GPIO_PIN_LOW);
	(GET_BIT(data,3)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D3,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D3,GPIO_PIN_LOW);
	(GET_BIT(data,2)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D2,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D2,GPIO_PIN_LOW);
	(GET_BIT(data,1)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D1,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D1,GPIO_PIN_LOW);
	(GET_BIT(data,0)) ? MCAL_GPIO_WritePin(LCD_DATA_PORT, D0,GPIO_PIN_HIGH) : MCAL_GPIO_WritePin(LCD_DATA_PORT, D0,GPIO_PIN_LOW);
	//Trigger Enable
	LCD_ES_tTrigger_Enable();
	return ES_OK;
#endif

}

ES_t Lcd_ES_tsendString(char *data)
{
	MCAL_GPIO_WritePin(LCD_CMD_PORT, RS, GPIO_PIN_HIGH);
	MCAL_GPIO_WritePin(LCD_CMD_PORT, RW, GPIO_PIN_LOW);

	unsigned char i=0;
	while(data[i]!=0)
	{
		Lcd_ES_tsendChar(data[i]);
		i++;
	}
	return ES_OK;
}

ES_t Lcd_ES_tsendString_xy(char *data,uint8_t row,uint8_t col){
	MCAL_GPIO_WritePin(LCD_CMD_PORT, RS, GPIO_PIN_HIGH);
	MCAL_GPIO_WritePin(LCD_CMD_PORT, RW, GPIO_PIN_LOW);

	LCD_ES_tSet_Cursor_Pos(row,col);
	Lcd_ES_tsendString(data);
	return ES_OK;

}


//A function to display Numbers instead of characters
ES_t Lcd_ES_tdisplayNum(uint16_t num)
{
	MCAL_GPIO_WritePin(LCD_CMD_PORT, RS, GPIO_PIN_HIGH);
	MCAL_GPIO_WritePin(LCD_CMD_PORT, RW, GPIO_PIN_LOW);

	uint8_t ch[10],i=0,j=0;
	if(num == 0)
	{
		Lcd_ES_tsendChar('0');
	}
	else
	{
		while(num)
		{
			ch[i] = num % 10 + '0';  //To convert int to char
			num /= 10;
			i++;
		} //Thus number entered is reversed so, we want to display it correctly
		for(j=i;j>0;j--)
		{
			Lcd_ES_tsendChar(ch[j-1]);
		}
	}
	return ES_OK;
}

ES_t Lcd_ES_tdisplayNum_xy(uint16_t num,uint8_t row,uint8_t col){

	MCAL_GPIO_WritePin(LCD_CMD_PORT, RS, GPIO_PIN_HIGH);
	MCAL_GPIO_WritePin(LCD_CMD_PORT, RW, GPIO_PIN_LOW);


	if(row == 1){
		Lcd_ES_tsendCmd(Force1stline);
		wait_ms(1);
	}else if(row == 2){
		Lcd_ES_tsendCmd(Force2ndline);
		wait_ms(10);
	}else{
		return ES_NOT_OK;
	}


	for(int j=1;j<=col;j++){
		Lcd_ES_tsendCmd(ShiftRight);
	}

	Lcd_ES_tdisplayNum(num);
	return ES_OK;

}

ES_t Lcd_ES_tsendChar_xy(uint8_t data,uint8_t row,uint8_t col){
	MCAL_GPIO_WritePin(LCD_CMD_PORT, RS, GPIO_PIN_HIGH);
	MCAL_GPIO_WritePin(LCD_CMD_PORT, RW, GPIO_PIN_LOW);


	if(row == 1){
		Lcd_ES_tsendCmd(Force1stline);
		wait_ms(1);
	}else if(row == 2){
		Lcd_ES_tsendCmd(Force2ndline);
		wait_ms(10);
	}else{
		return ES_NOT_OK;
	}

	for(int j=1;j<=col;j++){
		Lcd_ES_tsendCmd(ShiftRight);
	}
	Lcd_ES_tsendChar(data);
	return ES_OK;
}

static ES_t LCD_ES_tSet_Cursor_Pos(uint8_t row,uint8_t column){
	column--;
	switch(row){
	         case 1:
	        	 Lcd_ES_tsendCmd((0x80 + column));
	        	 break;
	         case 2:
	        	 Lcd_ES_tsendCmd((0xc0 + column));
	        	 break;
	         default:
	        	 return ES_NOT_OK;
	}
	return ES_OK;
}

/************************************************************************/
ES_t LCD_ES_tGoTo(uint8_t Line, uint8_t x){
	if(0 == Line)
	{
		if ( x <=15)
		{
			Lcd_ES_tsendCmd(0x80 + x);
		}
	}
	else if (1 == Line)
	{
		if ( x <=15)
		{
			Lcd_ES_tsendCmd(0xC0 + x);
		}
	}else{
		return ES_NOT_OK;
	}
	return ES_OK;
}

                                                      
/************************************************************************/

