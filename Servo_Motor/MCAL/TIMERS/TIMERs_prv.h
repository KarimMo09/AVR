/*
 * TIMER_prv.h
 *
 *  Created on: Jul 19, 2022
 *      Author: Karim
 */

#ifndef MCAL_TIMERS_TIMERS_PRV_H_
#define MCAL_TIMERS_TIMERS_PRV_H_

/*------------CONFIGURATION------------*/
#define    	DISABLE		  	 	 1
#define    	ENABLE	    	 	 2
#define     CLR_CS_BITS          0xF8
#define     TIMERS_INTERRUPTS	 8

/*------------Timers  mode------------*/
#define    	TIMER_OVF   	 	  1
#define    	TIMER_PHASECORRECT    2
#define    	TIMER_CTC    		  3
#define    	TIMER_FASTPWM    	  4
/*Modes only for timer1  */
#define    	TIMER1_PHASECORRECT_OCR1A    TIMER_PHASECORRECT
#define    	TIMER1_FASTPWM_OCR1A         TIMER_FASTPWM
#define    	TIMER1_CTC_OCR1A    		     TIMER_CTC
#define    	TIMER1_PHASECORRECT_ICR1          5
#define    	TIMER1_FASTPWM_ICR1               6
#define    	TIMER1_PHASECORRECT_8_BITS        7
#define    	TIMER1_PHASECORRECT_9_BITS        8
#define    	TIMER1_PHASECORRECT_10_BITS       9
#define    	TIMER1_PHASE_FREQ_CORRECT_OCR1A   10
#define    	TIMER1_PHASE_FREQ_CORRECT_ICR1    11
#define    	TIMER1_FASTPWM_8_BITS             12
#define    	TIMER1_FASTPWM_9_BITS             13
#define    	TIMER1_FASTPWM_10_BITS            14
#define    	TIMER1_CTC_ICR1                   15

/*------------OUTPUT COMPARE MODE------------*/

#define    	NORMAL_MODE  	 	 1
#define    	TOGGLE_OC0    	 	 2
#define    	CLEAR_OC0  		 	 3
#define    	SET_OC0   	 		 4

#define    	NORMAL_MODE_OC1A 	 	 1
#define    	NORMAL_MODE_OC1B 	 	 2
#define    	TOGGLE_OC1A      	 	 3
#define    	NON_INVERTING_OC1A     	 4
#define    	INVERTING_OC1A   	     5
#define    	TOGGLE_OC1B    	 	     6
#define    	NON_INVERTING_OC1B       7
#define    	INVERTING_OC1B   	     8

#define    	TOGGLE_OC2    	 	 1
#define    	CLEAR_OC2  		 	 2
#define    	SET_OC2   	 		 3


/*------------PRESCALING------------*/
#define 	NO_PRESCALING		 0b001
#define 	TIMER0_PS_8			 0b010
#define 	TIMER0_PS_64		 0b011
#define		TIMER0_PS_256		 0b100
#define 	TIMER0_PS_1024		 0b101
#define 	EX_CLK_FALLING_EDGE	 0b110
#define 	EX_CLK_RAISING_EDGE	 0b111

#define 	NO_PRESCALING		 0b001
#define 	TIMER1_PS_8			 0b010
#define 	TIMER1_PS_64		 0b011
#define		TIMER1_PS_256		 0b100
#define 	TIMER1_PS_1024		 0b101
#define 	EX_CLK_FALLING_EDGE	 0b110
#define 	EX_CLK_RAISING_EDGE	 0b111

#define 	TIMER2_PS_8			 0b010
#define 	TIMER2_PS_32		 0b011
#define 	TIMER2_PS_64		 0b100
#define 	TIMER2_PS_128		 0b101
#define		TIMER2_PS_256		 0b110
#define 	TIMER2_PS_1024		 0b111

/*---------------TMR0 REG----------------*/
#define TCCR0		*((volatile u8*)(0x53))
#define TCNT0		*((volatile u8*)(0x52))
#define OCR0		*((volatile u8*)(0x5C))
/*---------------TMR1 REG--------------- */
#define TCCR1A		*((volatile u8*)(0x4F))
#define TCCR1B		*((volatile u8*)(0x4E))
#define TCNT1		*((volatile u16*)(0x4C))
#define OCR1A		*((volatile u16*)(0x4A))
#define OCR1B		*((volatile u16*)(0x48))
#define ICR1		*((volatile u16*)(0x46))
/*---------------TMR2 REG---------------*/
#define TCCR2		*((volatile u8*)(0x45))
#define TCNT2		*((volatile u8*)(0x44))
#define OCR2		*((volatile u8*)(0x43))

#define TIMSK		*((volatile u8*)(0x59))
#define TIFR		*((volatile u8*)(0x58))

/*---------------TCCR0 BITS---------------*/
#define CS00	 0
#define CS01	 1
#define CS02	 2
#define WGM01	 3
#define COM00	 4
#define COM01	 5
#define WGM00	 6
#define FOC0	 7
/*****************/
/***TCCR1A  BITS***/

#define WGM10	 0
#define WGM11 	 1
#define FOC1B	 2
#define FOC1A 	 3
#define COM1B0 	 4
#define COM1B1	 5
#define COM1A0 	 6
#define COM1A1 	 7
/******************/
/***TCCR1B  BITS***/
#define CS10	 0
#define CS11 	 1
#define CS12 	 2
#define WGM12 	 3
#define WGM13 	 4
#define ICES1	 6
#define ICNC1 	 7
/*****************/
/***TCCR2 BITS***/
#define CS20	 0
#define CS21	 1
#define CS22	 2
#define WGM21	 3
#define COM20	 4
#define COM21	 5
#define WGM20	 6
#define FOC2	 7
/*****************/

/***TIFR BITS***/
#define	TOV0	 0
#define OCF0	 1
#define TOV1	 2
#define OCF1B	 3
#define OCF1A	 4
#define ICF1	 5
#define TOV2	 6
#define OCF2	 7
/****************/
/***TIMSK BITS***/
#define TOIE0	 0
#define OCIE0	 1
#define TOIE1	 2
#define OCIE1B	 3
#define OCIE1A	 4
#define TICIE1	 5
#define TOIE2	 6
#define OCIE2	 7
/****************/
#endif /* MCAL_TIMERS_TIMERS_PRV_H_ */
