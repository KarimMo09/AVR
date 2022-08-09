 /* SPI_prg.c
 *
 *  Created on: Aug 2, 2022
 *      Author: Karim
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Bit_math.h"
#include "../DIO/DIO_int.h"
#include "SPI_int.h"
#include "SPI_prv.h"
#include "SPI_cfg.h"


static void (*GS_fpSPI_Transfer_Complete_Callback)(u8 )= NULL;
u8 L_u8SPCR=0;
void MSPI_vInit(void)
{

	/*--------Enable SPI-------------*/
	SET_BIT(L_u8SPCR,SPE);

	/*--------SPI Mode-------------*/
#if   SPI_MODE==MASTER
	  SET_BIT(L_u8SPCR,MSTR);
	  /*-----------Configure SPI Pins--------------*/
	  MDIO_vSetPinDir(DIO_PORTB,MOSI,DIO_OUTPUT);
	  MDIO_vSetPinDir(DIO_PORTB,MISO,DIO_INPUT);
	  MDIO_vSetPinDir(DIO_PORTB,SCK,DIO_OUTPUT);
	  MDIO_vSetPinDir(DIO_PORTB,SS,DIO_OUTPUT);
#elif SPI_MODE==SLAVE
	  CLR_BIT(L_u8SPCR,MSTR);
	  MDIO_vSetPinDir(DIO_PORTB,MISO,DIO_OUTPUT);
	  MDIO_vSetPinDir(DIO_PORTB,MOSI,DIO_INPUT);
	  MDIO_vSetPinDir(DIO_PORTB,SCK,DIO_INPUT);
	  MDIO_vSetPinDir(DIO_PORTB,SS,DIO_INPUT);

#endif
	/*---Interrupt Enable/Disable---*/
#if   SPI_INTRRUPT_ENABLE==ENABLE
	  SET_BIT(L_u8SPCR,SPIE);
#elif SPI_INTRRUPT_ENABLE==DISABLE
	  CLR_BIT(L_u8SPCR,SPIE);
#endif
	  /*---------Data Order--------*/
#if   DATA_ORDER==MSB
	  SET_BIT(L_u8SPCR,DORD);
#elif DATA_ORDER==LSB
	  CLR_BIT(L_u8SPCR,DORD);
#endif

	  /*---------Clock Polarity--------*/
#if   CLOCK_POLARITY==FALLING_EDGE_LEADING_RAISING_EDGE_TRAILLING
	  SET_BIT(L_u8SPCR,CPOL);
#elif CLOCK_POLARITY==RAISING_EDGE_LEADING_FALLING_EDGE_TRAILLING
	  CLR_BIT(L_u8SPCR,CPOL);
#endif

	  /*---------Clock Phase--------*/
#if   CLOCK_PHASE==LEADING_EDGE_SETUP_TRAILLING_EDGE_SAMPLE
	  SET_BIT(L_u8SPCR,CPHA);
#elif CLOCK_PHASE==LEADING_EDGE_SAMPLE_TRAILLING_EDGE_SETUP
	  CLR_BIT(L_u8SPCR,CPHA);
#endif

	  /*---------SCK Frequency--------*/
#if   SPI_SPEED==NORMAL_SPEED
	  CLR_BIT(L_u8SPCR,SPI2X);
  #if   SCK_FREQUENCY==F_OSC_4
	    CLR_BIT(L_u8SPCR,SPR0);
	    CLR_BIT(L_u8SPCR,SPR1);
  #elif SCK_FREQUENCY==F_OSC_16
	    SET_BIT(L_u8SPCR,SPR0);
	    CLR_BIT(L_u8SPCR,SPR1);
  #elif SCK_FREQUENCY==F_OSC_64
	    CLR_BIT(L_u8SPCR,SPR0);
	    SET_BIT(L_u8SPCR,SPR1);
  #elif SCK_FREQUENCY==F_OSC_128
	    SET_BIT(L_u8SPCR,SPR0);
	    SET_BIT(L_u8SPCR,SPR1);
  #endif

#elif SPI_SPEED==DOUBLE_MASTER_SPEED
	  SET_BIT(L_u8SPCR,SPI2X);
  #if   SCK_FREQUENCY==F_OSC_2
	    CLR_BIT(L_u8SPCR,SPR0);
	    CLR_BIT(L_u8SPCR,SPR1);
  #elif SCK_FREQUENCY==F_OSC_8
	    SET_BIT(L_u8SPCR,SPR0);
	    CLR_BIT(L_u8SPCR,SPR1);
  #elif SCK_FREQUENCY==F_OSC_32
	    CLR_BIT(L_u8SPCR,SPR0);
	    SET_BIT(L_u8SPCR,SPR1);
  #elif SCK_FREQUENCY==F_OSC_64
	    SET_BIT(L_u8SPCR,SPR0);
	    SET_BIT(L_u8SPCR,SPR1);
 #endif
#endif

	    /*----Assign configuration in SPCR reg----------*/
	    SPCR=L_u8SPCR;
}


u8 MSPI_u8TransceiveChar(u8 A_u8Data)
{
	    SPDR=A_u8Data;
		/*Wait until data is received in SPI register*/
		while(GET_BIT(SPSR,SPIF)==0);
		/*read the received data*/
		return SPDR ;
}
void MSPI_vTransmmitData(u8 A_u8Data)
{
	SPDR=A_u8Data;
	while(GET_BIT(SPSR,SPIF)==0 ) ;

}

u8  MSPI_u8RecieveData(void)
{
	SPDR=DUMMY_DATA;
	while(GET_BIT(SPSR,SPIF) ==0 ) ;
	return SPDR;
}

void MSPI_vSendString(char * A_Send_Str)
{
	while(*A_Send_Str!='\0' )
			{
			    MSPI_vTransmmitData(*A_Send_Str);
		    	A_Send_Str++;
			}
}

void MSPI_vReceiveString(char *A_Recieved_Str)
{

	do
	{
	  *A_Recieved_Str=MSPI_u8RecieveData();
	}while(*A_Recieved_Str++!='\0' && *A_Recieved_Str!='\r' && *A_Recieved_Str!='\n');
}

void MSPI_vEnableIntterupt()
{
	SET_BIT(L_u8SPCR,SPIE);
	SPCR=L_u8SPCR;
}

void MSPI_DisableIntterupt()
{
	CLR_BIT(L_u8SPCR,SPIE);
	SPCR=L_u8SPCR;
}

void MSPI_vSetCallback(void (* A_fptr)(u8 ) )
{
	GS_fpSPI_Transfer_Complete_Callback=A_fptr;

}
/*---------------ISR SPI Transfer Complete---------------*/
void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{

	if ( GS_fpSPI_Transfer_Complete_Callback != NULL)
		{
		  GS_fpSPI_Transfer_Complete_Callback(SPDR);
		}
}
