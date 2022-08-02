/*
 * KPD_prg.c
 *
 *  Created on: May 17, 2022
 *      Author: Karim
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Bit_math.h"
#include <util/delay.h>

#include "../../MCAL/DIO/DIO_INT.h"


#include "KPD_int.h"



void KPD_vInit(void)
{
	MDIO_vSetPortDir(KPD_PORT, KPD_PORT_Dir);
	MDIO_vSetPortVal(KPD_PORT, PORT_OUTPUT);
}

u8   KPD_u8GetPressedKey(void)
{
	u8 pressed_key=NOT_PRESSED;
	u8 num[4][4]={{1,4,7,10},{2,5,8,0},{3,6,9,11},{12,13,14,15}};
	for(u8 col=0 ;col<4 ;col++)
	{
		/*activate current column*/
			MDIO_vSetPinVal(KPD_PORT,col,DIO_LOW);
			for(u8 row=0 ;row<4 ;row++)
			{
				if(MDIO_u8GetPinVal(KPD_PORT,row+4)==0)
				{
					pressed_key= num[row][col];/*key number*/
				}
				while(MDIO_u8GetPinVal(KPD_PORT,row+4)==0);
				_delay_ms(10);
			}
			/*deactivate column*/
			MDIO_vSetPinVal(KPD_PORT,col,DIO_HIGH);
		}
		return pressed_key;
}

