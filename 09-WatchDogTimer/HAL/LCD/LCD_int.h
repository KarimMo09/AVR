/*
 * LCD_int.h
 *
 *  Created on: May 19, 2022
 *      Author: Karim
 */
#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

#define LCD_CLEAR		0b00000001
#define LCD_LINE0		0
#define LCD_LINE1		1

#define LCD_CTRL_PORT   DIO_PORTC
#define LCD_DATA_PORT	DIO_PORTA
#define LCD_RS_PIN 		DIO_PIN0
#define LCD_RW_PIN		DIO_PIN1
#define LCD_EN_PIN		DIO_PIN2



#define CLR_SCREEN           0x01
#define CURSOR_ON_DISPLAN_ON 0x0e
#define RETURN_HOME          0x02
#define ENTRY_MODE           0x06
#define SHIFT_SCREEN_LEFT	 0x07
#define ROW_ONE				 0x00
#define ROW_TWO				 0x40
#define INIT_CURSOR_POS		 0x80
#define COLUMN1				 0
#define COLUMN2				 1
#define COLUMN3				 2
#define COLUMN4				 3
#define COLUMN5				 4
#define COLUMN6				 5
#define COLUMN7				 6
#define COLUMN8				 7
#define COLUMN9				 8
#define COLUMN10			 9
#define COLUMN11			 10
#define COLUMN12			 11
#define COLUMN13			 12
#define COLUMN14			 13
#define COLUMN15			 14
#define COLUMN16 			 15
#define COLUMN17 			 16


void HLCD_vSendCommand(u8 A_u8Command);
void HLCD_vSendChar(u8 A_u8Char);
void HLCD_vInit(void);
void HLCD_vPrintString(u8 A_u8String[] );
void HLCD_vPrintNumber(s32 A_s32Number);
void HLCD_vSetCursorPosition(u8 A_u8LinePos, u8 A_u8LineNo);
void HLCD_vSaveCustomChar(u8 A_u8CgramIndex,u8 A_u8CustomCharData[] );
void HLCD_vDisplayCustomChar(u8 A_u8CgramIndex);


#endif
/*
#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

#define LCD_CTRL_PORT        DIO_PORTB
#define LCD_DATA_PORT        DIO_PORTA
#define LCD_RS_PIN           DIO_PIN0
#define LCD_RW_PIN           DIO_PIN1
#define LCD_EN_PIN           DIO_PIN2

#define CLR_SCREEN           0x01
#define CURSOR_ON_DISPLAN_ON 0x0e
#define RETURN_HOME          0x02
#define ENTRY_MODE           0x06
#define SHIFT_SCREEN_LEFT	 0x07
#define ROW_ONE				 0x00
#define ROW_TWO				 0x40
#define INIT_CURSOR_POS		 0x80
#define COLUMN1				 0
#define COLUMN2				 1
#define COLUMN3				 2
#define COLUMN4				 3
#define COLUMN5				 4
#define COLUMN6				 5
#define COLUMN7				 6
#define COLUMN8				 7
#define COLUMN9				 8
#define COLUMN10			 9
#define COLUMN11			 10
#define COLUMN12			 11
#define COLUMN13			 12
#define COLUMN14			 13
#define COLUMN15			 14
#define COLUMN16 			 15
#define COLUMN17 			 16




void HLCD_vClrScreen(void);
void HLCD_vSendCommand(u8 A_u8Cmd);
void HLCD_vSendChar(u8 A_u8Char);
void HLCD_vInit(void);
void HLCD_vPrintString(char A_s8String[] );
void HLCD_vPrintNumber(s32 A_s32Number );
void HLCD_vSetCursorPosition(u8 A_u8LinePos ,u8 A_u8LineNo);
void HLCD_vSaveCustomChar(u8 A_u8CgramIndex,u8 A_u8CustomCharData[] )
void HLCD_vDisplayCustomChar(u8 A_u8CgramIndex)


#endif  HAL_LCD_LCD_INT_H_ */
