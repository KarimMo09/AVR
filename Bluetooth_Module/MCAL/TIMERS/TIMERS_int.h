/*
 * TIMERS_int.h
 *
 *  Created on: Jul 19, 2022
 *      Author: Karim
 */

#ifndef MCAL_TIMERS_TIMERS_INT_H_
#define MCAL_TIMERS_TIMERS_INT_H_

#define TIM_CB_OVF	1
#define TIM_CB_CTC	2
#define TIMER0      0
#define TIMER1      1
#define TIMER2      2
#define OC0         3
#define OC1A        5
#define OC1B        4
#define OC2         7
#define CHANNEL_A   1
#define CHANNEL_B   2

typedef enum
{
	ICU_Falling,
	ICU_Raising
}ICU_Trigger_t;

void MTIMERS_vInit(void);

void MTIMERS_vStartTimer(u8 A_u8TimerId);

void MTIMERS_vSetPreLoadVal(u8 A_u8TimerId,u16 A_u16PreLoadVal);

void MTIMERS_vSetCompareValue(u8 A_u8TimerId,u16 A_u16CompareVal);

void MTIMERS_vSetCompareValueTIM1(u8 A_u8Channel, u16 A_u16CompareVal);


void MTIMERS_vSetInterval_OVF_Asynch(u8 A_u8TimerId,u16 A_u16IntervalCounts, void (*A_fptr)(void));

void MTIMERS_vSetInterval_CTC_Asynch(u8 A_u8TimerId,u16 A_u16IntervalCounts,
									 u16 A_u16CompareValue,
									 void (*A_fptr)(void));


void MTIMERS_vSetInterval_TIM1_CTC_Asynch(u8 A_u8Channel,u16 A_u16IntervalCounts,
		                             	  u16 A_u16CompareValueChannel,
										  void (*A_fptr)(void));


u16 MTIMERS_u16GetElapsedTime(u8 A_u8TimerId);
u16 MTIMERS_u16GetCapturedValue();
void MTIMERS_vSetIcuTrigger(ICU_Trigger_t A_xIcuTrigger );
void MTIMERS_vEnableIntterupts(u8 A_u8Interrupt_type);
void MTIMERS_DisableIntterupts(u8 A_u8Interrupt_type);
void MTIMERS_vSetCallback(u8 A_u8Interrupt_type,void (*A_fptr)(void));


void MTIMERS_vStopTimer(u8 A_u8TimerId);

#endif /* MCAL_TIMERS_TIMERS_INT_H_ */
