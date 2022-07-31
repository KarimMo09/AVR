/*
 * ADC_prg.c
 *
 *  Created on: Jul 22, 2022
 *      Author: Karim
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Bit_math.h"
#include "ADC_int.h"
#include "ADC_prv.h"
#include "ADC_cfg.h"

void (* G_fpADC_Callback)(void);

/* pointer to function take adc reading*/
void (* G_fpADC_Callback_5)(u16 A_u16ADC_Data);

volatile u16* G_pu16ADC_Data= NULL;

Flagstatus_t xAdcFlag= ADC_NOTCOMPLETE ;
void MADC_vInit(void)
{
	/* 1-Enable ADC*/
	SET_BIT(ADCSRA,ADEN);

	/* 2- Ref voltage selection     */
#if ADC_REF_VOLT==AVCC
	CLR_BIT(ADMUX, REFS1);
	SET_BIT(ADMUX, REFS0);
#elif ADC_REF_VOLT==INTERNAL_REF
	CLR_BIT(ADMUX, REFS1);
	CLR_BIT(ADMUX, REFS0);
#elif ADC_REF_VOLT==AREF
	SET_BIT(ADMUX, REFS1);
	SET_BIT(ADMUX, REFS0);
#else
#error "Please select correct refence voltage"
#endif

	/* 3- Data adjustment direction */
	CLR_BIT(ADMUX,ADLAR);
	/* 4- Select Prescaler Bits     */
	ADCSRA=(ADCSRA & ADC_CLR_PRESC_BITS ) | (ADC_PRESCALER );

	/* 5- Auto trigger enable and its source*/
	CLR_BIT(ADCSRA, ADATE);

	/* 6- Interrupt Disable/Enable  */
#if ADC_INTERRUPT_ENABLE==DISABLE
	CLR_BIT(ADCSRA, ADIE);
#elif ADC_INTERRUPT_ENABLE==ENABLE
	SET_BIT(ADCSRA, ADIE);
#endif

}
#if ADC_INTERRUPT_ENABLE==DISABLE
16  MADC_u16AnalogRead(u8 A_u8ChannelNo)
{
	//u16 L_u16ADCData=0;
	/* 1- Select Channel   */
	ADMUX= (ADMUX & ADC_CLR_CH_SEL_BITS) | (A_u8ChannelNo & NUM_OF_CHANNEL );
	/* 2- Start Conversion */
	SET_BIT(ADCSRA, ADSC);
	/* 3- Poll on flag     */
	while (GET_BIT(ADCSRA, ADIF)!=1);
	/* 4- Clear flag       */
	SET_BIT(ADCSRA ,ADIF);
	/* 5- Return ADC data  */
	/*L_u16ADCData= ADCL ;
	L_u16ADCData |=(ADCH<<8 );
	return L_u16ADCData;*/
	return ADC;

}
#elif ADC_INTERRUPT_ENABLE==ENABLE
void MADC_vStartConversion(u8 A_u8ChannelNo)
{
	    /* 1- Select Channel   */
		ADMUX= (ADMUX & ADC_CLR_CH_SEL_BITS) | (A_u8ChannelNo & NUM_OF_CHANNEL );
		/* 2- Start Conversion */
		SET_BIT(ADCSRA, ADSC);

}
Flagstatus_t MADC_xGetFlagStatus(void)
{

	if(GET_BIT(ADCSRA,ADIF)==0)
	{
		xAdcFlag=ADC_COMPLETE;

	}
	return xAdcFlag;
}

void MADC_vRstFlag(void)
{
	xAdcFlag= ADC_NOTCOMPLETE ;
}

/*Alternative method*/

void MADC_vStartADCConversion_Asynch(u8 A_u8ChannelNo, volatile u16* A_pu16ADCData, void (*A_fptr)(u16 ))
{
	/* 1- Set callback function pointer*/
	//G_fpADC_Callback=A_fptr;
	G_fpADC_Callback_5=A_fptr;

	/* 2- Set ADC data pointer */
	G_pu16ADC_Data=A_pu16ADCData ;


	/* 1- Select Channel   */
	ADMUX= (ADMUX & ADC_CLR_CH_SEL_BITS) | (A_u8ChannelNo & NUM_OF_CHANNEL );
	/* 2- Start Conversion */
	SET_BIT(ADCSRA, ADSC);
}

/*ADC ISR with callback(void) */
/*void __vector_16(void)	__attribute__((signal));//compiler command
void __vector_16(void)
{

	if(G_pu16ADC_Data!=NULL)
	{
		*G_pu16ADC_Data=ADC;
	}
	else
	{

	}

	if(G_fpADC_Callback!=NULL )
	{

		G_fpADC_Callback();
	}
    xAdcFlag= ADC_COMPLETE ;
}
#endif*/
/*ADC ISR with callback(ADC_Data) */
void __vector_16(void)	__attribute__((signal));//compiler command
void __vector_16(void)
{

	if(G_fpADC_Callback_5!=NULL )
	{

		G_fpADC_Callback_5(ADC);
	}
    xAdcFlag= ADC_COMPLETE ;
}
#endif






