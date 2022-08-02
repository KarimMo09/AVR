/*
 * SSD_prg.c
 *
 *  Created on: May 17, 2022
 *      Author: Karim
 */
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_INT.h"
#include  "SSD_int.h"

static const u8 CGS_u8SSD_Nums[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};


void SSD_vInit       (u8 A_u8SsdNo)
{
	if( A_u8SsdNo ==SSD1)
	{
		MDIO_vSetPortDir(SSD1_PORT,PORT_OUTPUT);
	}
	else if( A_u8SsdNo ==SSD2)
		{
			MDIO_vSetPortDir(SSD2_PORT,PORT_OUTPUT);
		}


}
void SSD_vDisplayNum (  u8 A_u8SsdNo ,u8 A_u8Num )
{
	if(A_u8SsdNo ==SSD1)
	{
		/*input validation */
		if(A_u8Num<10)
		{
		#if SSD_TYPE==COM_ANODE
			MDIO_vSetPortVal(SSD1_PORT,CGS_u8SSD_Nums[A_u8Num]);
		#elif SSD_TYPE==COM_CATHODE
			MDIO_vSetPortVal(SSD1_PORT,~CGS_u8SSD_Nums[A_u8Num ]);
		#endif
		}

	}
	else if(A_u8SsdNo == SSD2)
		{
			/*input validation */
			if(A_u8Num<10)
			{
			#if SSD_TYPE==COM_ANODE
				MDIO_vSetPortVal(SSD2_PORT,CGS_u8SSD_Nums[A_u8Num]);
			#elif SSD_TYPE==COM_CATHODE
				MDIO_vSetPortVal(SSD2_PORT,~CGS_u8SSD_Nums[A_u8Num ]);
			#endif
			}

		}


}

void SSD_vTurnOff    ( u8 A_u8SsdNo  )
{
	if(A_u8SsdNo ==SSD1)
	{
#if SSD_TYPE==COM_ANODE
	MDIO_vSetPortVal(SSD2_PORT,0);
#elif SSD_TYPE==COM_CATHODE
	MDIO_vSetPortVal(SSD2_PORT,0xff);
#endif
	}
	else if(A_u8SsdNo ==SSD2)
	{
#if SSD_TYPE==COM_ANODE
	MDIO_vSetPortVal(SSD2_PORT,0);
#elif SSD_TYPE==COM_CATHODE
	MDIO_vSetPortVal(SSD2_PORT,0xff);
#endif
	}


}
