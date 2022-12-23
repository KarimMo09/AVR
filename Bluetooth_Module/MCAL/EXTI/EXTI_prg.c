/*
 * EXTI_prg.c
 *
 *  Created on: Jul 19, 2022
 *      Author: Karim
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "../DIO/DIO_int.h"
#include "EXTI_prv.h"
#include "EXTI_cfg.h"
#include "EXTI_int.h"

void MEXTI_vInit(void)
{
#if EXTI_LINE0==ENABLE
    /* 1- Sense control     */
#if EXTI_LIN0_SENSE_CTRL==EXTI_FALLING
	/* falling edge         */

	SET_BIT(MCUCR,ISC01);
	CLR_BIT(MCUCR,ISC00);
#elif EXTI_LIN0_SENSE_CTRL==EXTI_RAISING
	/* Raising edge         */

	SET_BIT(MCUCR, ISC01);
	SET_BIT(MCUCR, ISC00);
#elif EXTI_LIN0_SENSE_CTRL==EXTI_ONCHANGE
	/* On change       */

	SET_BIT(MCUCR, ISC00);
	CLR_BIT(MCUCR, ISC01);
#elif EXTI_LIN0_SENSE_CTRL==EXTI_LOWLEVEL
	/* On change       */

	CLR_BIT(MCUCR, ISC00);
	CLR_BIT(MCUCR, ISC00);
#else
#error " Sense control must be falling edge,raising edge or on change")
#endif

	  /* 2- Enable interrupt  */
	   SET_BIT(GICR , INT0);
#endif


#if EXTI_LINE1==ENABLE
    /* 1- Sense control     */
#if EXTI_LIN1_SENSE_CTRL==EXTI_FALLING
	/* falling edge         */

	SET_BIT(MCUCR, ISC11 );
	CLR_BIT(MCUCR, ISC10 );
#elif EXTI_LIN1_SENSE_CTRL==EXTI_RAISING
	/* Raising edge         */

	SET_BIT(MCUCR, ISC11);
	SET_BIT(MCUCR, ISC10);
#elif EXTI_LIN1_SENSE_CTRL==EXTI_ONCHANGE
	/* On change       */

	SET_BIT(MCUCR, ISC10);
	CLR_BIT(MCUCR, ISC11);
#elif EXTI_LIN1_SENSE_CTRL==EXTI_LOWLEVEL
	/* On change       */

	CLR_BIT(MCUCR, ISC11);
	CLR_BIT(MCUCR, ISC10);
#else
#error " Sense control must be falling edge,raising edge or on change")
#endif

	  /* 2- Enable interrupt  */
	   SET_BIT(GICR , INT1);
#endif


#if EXTI_LINE2==ENABLE
    /* 1- Sense control     */
#if EXTI_LIN2_SENSE_CTRL==EXTI_FALLING
	/* falling edge         */
	CLR_BIT(MCUCSR, ISC2);
#elif EXTI_LIN2_SENSE_CTRL==EXTI_RAISING
	/* Raising edge         */
#else
#error " Sense control must be falling edge OR raising edge")
#endif

	  /* 2- Enable interrupt  */
	   SET_BIT(GICR , INT2);
#endif

}
