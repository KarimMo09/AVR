/*
 * LCD_prg.h
 *
 *  Created on: May 19, 2022
 *      Author: Karim
 */


#include "../../LIB/STD_TYPES.h"

#include <util/delay.h>

#include "../../MCAL/DIO/DIO_INT.h"
#include "LCD_int.h"
#include "LCD_cfg.h"
#include "LCD_prv.h"



void HLCD_vInit(void)
{
	/*------Set  pin direction-----*/
#if LCD_MODE==EIGHT_BITS
	MDIO_vSetPortDir(LCD_DATA_PORT,PORT_OUTPUT);
	MDIO_vSetPinDir(LCD_CTRL_PORT,LCD_RS_PIN,DIO_OUTPUT);
	MDIO_vSetPinDir(LCD_CTRL_PORT,LCD_RW_PIN,DIO_OUTPUT);
	MDIO_vSetPinDir(LCD_CTRL_PORT,LCD_EN_PIN,DIO_OUTPUT);
	/*-----Start init sequence-----*/
	HLCD_vSendCommand(EIGHT_BITS);
	_delay_ms(1);
#elif LCD_MODE==FOUR_BITS
	    MDIO_vSetLowNibble(LCD_DATA_PORT,PORT_OUTPUT);
		MDIO_vSetPinDir(LCD_CTRL_PORT,LCD_RS_PIN,DIO_OUTPUT);
		MDIO_vSetPinDir(LCD_CTRL_PORT,LCD_RW_PIN,DIO_OUTPUT);
		MDIO_vSetPinDir(LCD_CTRL_PORT,LCD_EN_PIN,DIO_OUTPUT);
		HLCD_vSendCommand(FOUR_BITS);
		_delay_ms(1);
#endif
	HLCD_vSendCommand(CURSOR_ON_DISPLAN_ON);
	_delay_ms(1);
	HLCD_vSendCommand(CLR_SCREEN);
	_delay_ms(3);
	HLCD_vSendCommand(ENTRY_MODE);
	_delay_ms(1);
	// end initialization
}
void HLCD_vFallingEdge(void)
{
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_EN_PIN, DIO_HIGH); // EN pulse sequence
	_delay_ms(1);
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_EN_PIN, DIO_LOW); // EN pulse sequence
	_delay_ms(1);
}
void HLCD_vSendCommand(u8 A_u8Command)
{
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_RS_PIN, DIO_LOW); // RS->LOW
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_RW_PIN, DIO_LOW); // RW-> LOW
	MDIO_vSetPortVal(LCD_DATA_PORT, A_u8Command);
	HLCD_vFallingEdge();
}
void HLCD_vClrScreen(void)
{
	HLCD_vSendCommand(CLR_SCREEN);
}
void HLCD_vSendChar(u8 A_u8Char)
{
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_RS_PIN, DIO_HIGH); // RS->HIGH
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_RW_PIN, DIO_LOW); // RW-> LOW
	MDIO_vSetPortVal(LCD_DATA_PORT, A_u8Char);
	HLCD_vFallingEdge();
}

void HLCD_vPrintString(char *A_pu8String )
{

	/*HLCD_vClrScreen();
	static u8 LS_u8Colm=0;*/
	while(*A_pu8String!='\0')
	{
		/*LS_u8Colm++;
		if(G_u8Colm==17)
			{
			  	HLCD_vSetCursorPosition(LCD_LINE1,COLUMN1);
		    }
		else if(LS_u8Colm==33)
			{
				HLCD_vClrScreen();
				HLCD_vSetCursorPosition(LCD_LINE0,COLUMN1);
			}*/
		HLCD_vSendChar(*A_pu8String);
		A_pu8String++;
	}
}
void HLCD_vSetCursorPosition(u8 A_u8LineNo ,u8 A_u8LColumn)
{
	if(A_u8LineNo==LCD_LINE1)
	{
		HLCD_vSendCommand(INIT_CURSOR_POS+ROW_TWO+A_u8LColumn);
	}
	else
	{
		HLCD_vSendCommand(INIT_CURSOR_POS+ROW_ONE+A_u8LColumn);
	}

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
		HLCD_vSendChar('0');
	}
	while(A_s32Number)
		{
			L_u8DigitNum[L_s8Digit]=A_s32Number%10;
			A_s32Number/=10;
			L_s8Digit++;
		}
	for(L_s8Digit-=1 ; L_s8Digit>=0 ; L_s8Digit--)
	{
		HLCD_vSendChar(L_u8DigitNum[L_s8Digit]+'0');
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
void HLCD_vDisplayCustomChar(u8 A_u8CgramIndex)
{
	if(A_u8CgramIndex < 8)
	{
		HLCD_vSendChar(A_u8CgramIndex);
	}
}

