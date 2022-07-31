/*
 * LCD_prg.h
 *
 *  Created on: May 19, 2022
 *      Author: Karim
 */


#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/DIO/DIO_prv.h"
#include <util/delay.h>
#include "LCD_cfg.h"
#include "LCD_int.h"



void HLCD_vSendCommand(u8 A_u8Command)
{
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_RS_PIN, DIO_LOW); // RS->LOW
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_RW_PIN, DIO_LOW); // RW-> LOW
	MDIO_vSetPortVal(LCD_DATA_PORT, A_u8Command);

	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_EN_PIN, DIO_HIGH); // EN pulse sequence
	_delay_ms(1);
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_EN_PIN, DIO_LOW); // EN pulse sequence
	_delay_ms(1);
}

void HLCD_vSendChar(u8 A_u8Char)
{
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_RS_PIN, DIO_HIGH); // RS->LOW
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_RW_PIN, DIO_LOW); // RW-> LOW
	MDIO_vSetPortVal(LCD_DATA_PORT, A_u8Char);

	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_EN_PIN, DIO_HIGH); // EN pulse sequence
	_delay_ms(1);
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_EN_PIN, DIO_LOW); // EN pulse sequence
	_delay_ms(1);
}

void HLCD_vInit(void)
{
	/* set your pin directions */
	MDIO_vSetPortDir(LCD_DATA_PORT, 0xff);
	MDIO_vSetPinDir(LCD_CTRL_PORT, LCD_RS_PIN, DIO_OUTPUT);
	MDIO_vSetPinDir(LCD_CTRL_PORT, LCD_RW_PIN, DIO_OUTPUT);
	MDIO_vSetPinDir(LCD_CTRL_PORT, LCD_EN_PIN, DIO_OUTPUT);
	/* start init sequence  */
	_delay_ms(50);
	HLCD_vSendCommand(0b00111000);
	_delay_ms(1);
	HLCD_vSendCommand(0b00001100);
	_delay_ms(1);
	HLCD_vSendCommand(0b00000001);
	_delay_ms(3);
	HLCD_vSendCommand(0b00000110);
	_delay_ms(1);
}

void HLCD_vPrintString(u8 A_u8String[] )
{
	for(u8 L_u8i =0; A_u8String[L_u8i] != '\0' ; L_u8i++)
	{
		HLCD_vSendChar(A_u8String[L_u8i]);
	}
}/*
void HLCD_vPrintNumber(s32 A_s32Number)
{
	u8 L_u8Digits[10] = {0};
	u8 L_u8Counter = 0;
	// TODO: IMplement negative number handling
	// TODO: implement Zero in units corner case
	// save reversed in array
	while(A_s32Number > 0)
	{
		L_u8Digits[L_u8Counter] = A_s32Number%10 ;
		L_u8Counter++;
		A_s32Number /= 10 ;
	}

	// print array in reverese
	for(s8 L_s8PrintIndex=0; L_s8PrintIndex >= 0; L_s8PrintIndex-- )
	{
		HLCD_vSendChar('0' + L_u8Digits[L_s8PrintIndex]);
	}
}*/
void HLCD_vSetCursorPosition(u8 A_u8LinePos, u8 A_u8LineNo)
{
	switch(A_u8LineNo)
	{
	case LCD_LINE0:
			HLCD_vSendCommand(0x80 + A_u8LinePos + 0);
		break;
	case LCD_LINE1:
			HLCD_vSendCommand(0x80 + A_u8LinePos + 64);
		break;
	}
}
void HLCD_vSaveCustomChar(u8 A_u8CgramIndex,u8 A_u8CustomCharData[] )
{
	/* 1-Set CGRAM Address */
	HLCD_vSendCommand(0b01000000 + (A_u8CgramIndex *8));
	/* 2- send custom char data */
	for(u8 L_u8Idx=0; L_u8Idx <8; L_u8Idx++)
	{
		HLCD_vSendChar(A_u8CustomCharData[L_u8Idx]);
	}
	/* 3-Set DDRAM Address */
	HLCD_vSendCommand(0x80);
}
void HLCD_vPrintNumber(s32 A_s32Number )
{
	u8 L_u8DigitNum[10]={0};
	s8 L_s8Digit=0;
	if(A_s32Number<0)
	{
		A_s32Number*=-1;
		HLCD_vSendChar('-');
	}
	else if(A_s32Number==0)
	{
		HLCD_vSendChar(0+48);
	}
	while(A_s32Number)
		{
			L_u8DigitNum[L_s8Digit]=A_s32Number%10;
			A_s32Number/=10;
			L_s8Digit++;
		}
	for(L_s8Digit-=1 ; L_s8Digit>=0 ; L_s8Digit--)
	{
		HLCD_vSendChar(L_u8DigitNum[L_s8Digit]+48);
	}

}
void HLCD_vDisplayCustomChar(u8 A_u8CgramIndex)
{
	if(A_u8CgramIndex < 8)
	{
		HLCD_vSendChar(A_u8CgramIndex);
	}
}
/*
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"
#include <util/delay.h>
#include "LCD_int.h"

void HLCD_vInit(void)
{
	//Set you pin direction
	DIO_vSetPortDir(LCD_DATA_PORT,PORT_OUTPUT);
	DIO_vSetPinDir(LCD_CTRL_PORT,LCD_RS_PIN,DIO_OUTPUT);
	DIO_vSetPinDir(LCD_CTRL_PORT,LCD_RW_PIN,DIO_OUTPUT);
	DIO_vSetPinDir(LCD_CTRL_PORT,LCD_EN_PIN,DIO_OUTPUT);

	//Start init sequence
	_delay_ms(50);
	HLCD_vSendCommand(0x38);   //function set 2 lines used &5*7 dot
	_delay_ms(1);
	HLCD_vSendCommand(0x0E);   //Display on cursor off blinkink off
	_delay_ms(1);
	HLCD_vSendCommand(CLR_SCREEN);   //clear display
	_delay_ms(3);
	HLCD_vSendCommand(0x06);   //entry mode
	_delay_ms(1);
	// end initialization
}

void HLCD_vClrScreen(void)
{
	HLCD_vSendCommand(CLR_SCREEN);
}
void HLCD_vSendCommand(u8 A_u8Cmd)
{
	//Control RS and RW Pins
	
	DIO_vSetPinVal(LCD_CTRL_PORT,LCD_RS_PIN,DIO_LOW);
	DIO_vSetPinVal(LCD_CTRL_PORT,LCD_RW_PIN,DIO_LOW);
	
	// Write Command on the data Pins
	DIO_vSetPortVal(LCD_DATA_PORT,A_u8Cmd);
	
	// Pulse on the enable pin
	DIO_vSetPinVal(LCD_CTRL_PORT,LCD_EN_PIN,DIO_HIGH);
	_delay_ms(1);
	DIO_vSetPinVal(LCD_CTRL_PORT,LCD_EN_PIN,DIO_LOW);
	_delay_ms(1);
}

void HLCD_vSendChar(u8 A_u8Char)
{
	//Control RS and RW Pins

	DIO_vSetPinVal(LCD_CTRL_PORT,LCD_RS_PIN,DIO_HIGH);
	DIO_vSetPinVal(LCD_CTRL_PORT,LCD_RW_PIN,DIO_LOW);
	
	// Write Data on the data Pins
	DIO_vSetPortVal(LCD_DATA_PORT,A_u8Char);
	
	// Pulse on the enable pin
	DIO_vSetPinVal(LCD_CTRL_PORT,LCD_EN_PIN,DIO_HIGH);
	_delay_ms(1);
	DIO_vSetPinVal(LCD_CTRL_PORT,LCD_EN_PIN,DIO_LOW);
	_delay_ms(1);
}
void HLCD_vPrintString(char A_s8String[] )
{
	static u8 L_su8Row=ROW_ONE;
	u8 flag=0;
	for(u8 L_u8Char=0;A_s8String[L_u8Char] !='\0';L_u8Char++)
	{
		HLCD_vSendChar(A_s8String[L_u8Char]);
		_delay_ms(200);
		if(L_u8Char==COLUMN16 && L_su8Row==ROW_ONE)
		{
			HLCD_vSetCursorPosition(ROW_ONE ,COLUMN17);
			HLCD_vSendCommand(SHIFT_SCREEN_LEFT);
			L_su8Row=ROW_TWO;
			flag=1;
		}
		//else if(A_s8String[L_u8Char] =='\0' && L_su8Row==ROW_ONE)
			L_su8Row=ROW_TWO;

		else if(L_u8Char==COLUMN16 && L_su8Row==ROW_TWO)
		{
			HLCD_vSetCursorPosition(ROW_TWO ,COLUMN17);
			HLCD_vSendCommand(SHIFT_SCREEN_LEFT);
			L_su8Row=ROW_ONE;
			flag=1;
		}
		//else if(A_s8String[L_u8Char] =='\0' && L_su8Row==ROW_TWO)
			L_su8Row=ROW_ONE;
	}
	if(L_su8Row==ROW_ONE && flag==0)
		L_su8Row=ROW_TWO;
	else if (L_su8Row==ROW_TWO && flag==0)
		L_su8Row=ROW_ONE;
	_delay_ms(1000);
	HLCD_vSendCommand(RETURN_HOME);
	HLCD_vSendCommand(ENTRY_MODE);




}
void HLCD_vPrintNumber(s32 A_s32Number )
{
	u8 L_u8DigitNum[10]={0};
	s8 L_s8Digit=0;
	if(A_s32Number<0)
	{
		A_s32Number*=-1;
		HLCD_vSendChar('-');
	}
	else if(A_s32Number==0)
	{
		HLCD_vSendChar(0+48);
	}
	while(A_s32Number)
		{
			L_u8DigitNum[L_s8Digit]=A_s32Number%10;
			A_s32Number/=10;
			L_s8Digit++;
		}
	for(L_s8Digit-=1 ; L_s8Digit>=0 ; L_s8Digit--)
	{
		HLCD_vSendChar(L_u8DigitNum[L_s8Digit]+48);
	}

}
void HLCD_vSetCursorPosition(u8 A_u8LinePos ,u8 A_u8LineNo)
{
	if(A_u8LinePos==ROW_TWO)
	{
		HLCD_vSendCommand(INIT_CURSOR_POS+ROW_TWO+A_u8LineNo);
	}
	else
	{
		HLCD_vSendCommand(INIT_CURSOR_POS+ROW_ONE+A_u8LineNo);
	}

}
void HLCD_vSaveCustomChar(u8 A_u8CgramIndex,u8 A_u8CustomCharData[] )
{
	// 1-Set CGRAM Address
	HLCD_vSendCommand(0b01000000 + (A_u8CgramIndex *8));
	// 2- send custom char data
	for(u8 L_u8Idx=0; L_u8Idx <8; L_u8Idx++)
	{
		HLCD_vSendChar(A_u8CustomCharData[L_u8Idx]);
	}
	// 3-Set DDRAM Address
	HLCD_vSendCommand(0x80);
}
void HLCD_vDisplayCustomChar(u8 A_u8CgramIndex)
{
	if(A_u8CgramIndex < 8)
	{
		HLCD_vSendChar(A_u8CgramIndex);
	}
}
*/
