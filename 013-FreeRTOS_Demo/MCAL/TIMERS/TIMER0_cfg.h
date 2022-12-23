/*
 * TIMERS_cfg.h
 *
 *  Created on: Jul 19, 2022
 *      Author: Karim
 */

#ifndef MCAL_TIMERS_TIMER0_CFG_H_
#define MCAL_TIMERS_TIMER0_CFG_H_

/*--------------------TIMER0 Configuration-------------------*/

#define TIMER0_ENABLE       ENABLE

/* Options
 * TIMER_OVF
 * TIMER_PHASECORRECT
 * TIMER_CTC
 * TIMER_FASTPWM
 */
#define    TIMER0_MODE       TIMER_FASTPWM


/* Options
 * NORMAL_MODE
 * TOGGLE_OC0
 * CLEAR_OC0
 * SET_OC0
 */
#define 	TIMER0_COMPARE_MATCH_OP_MODE        CLEAR_OC0

/* Options
 * ENABLE
 * DISABLE
 */
#define TIMER0_OVF_INTERRUPT_ENABLE      DISABLE
#define TIMER0_CTC_INTERRUPT_ENABLE      DISABLE
/* Options
 * 1- NOPRESCALING
 * 2- TIMER0_PS_8
 * 3- TIMER0_PS_64
 * 4- TIMER0_PS_256
 * 5- TIMER0_PS_1024
 * 6- EX_CLK_FALLING_EDGE
 * 7- EX_CLK_FALLING_EDGE
 */
#define TIMER0_PRESCALER                  TIMER0_PS_8



#endif /* MCAL_TIMERS_TIMER0_CFG_H_ */
