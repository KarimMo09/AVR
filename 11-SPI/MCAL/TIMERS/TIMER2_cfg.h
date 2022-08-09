/*
 * TIMER2_cfg.h
 *
 *  Created on: Jul 28, 2022
 *      Author: Karim
 */

#ifndef MCAL_TIMERS_TIMER2_CFG_H_
#define MCAL_TIMERS_TIMER2_CFG_H_

#define TIMER2_ENABLE       DISABLE

/* Options
 * TIMER_OVF
 * TIMER_PHASECORRECT
 * TIMER_CTC
 * TIMER_FASTPWM
 */
#define    TIMER2_MODE       TIMER_CTC


/* Options
 * NORMAL_MODE
 * TOGGLE_OC0
 * CLEAR_OC0
 * SET_OC0
 */
#define 	TIMER2_COMPARE_MATCH_OP_MODE        NORMAL_MODE

/* Options
 * ENABLE
 * DISABLE
 */
#define TIMER2_INTERRUPT_ENABLE      ENABLE
/* Options
 * 1- NOPRESCALING
 * 2- TIMER2_PS_8
 * 3- TIMER2_PS_32
 * 4- TIMER2_PS_64
 * 5- TIMER2_PS_128
 * 6- TIMER2_PS_256
 * 7- TIMER2_PS_1024
 */
#define TIMER2_PRESCALER                  TIMER0_PS_256

#endif /* MCAL_TIMERS_TIMER2_CFG_H_ */
