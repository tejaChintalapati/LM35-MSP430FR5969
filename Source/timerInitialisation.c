/*
 * timerInitialisation.c
 *
 *  Created on: Jan 27, 2016
 *  Author: Teja Chintalapati
 *	Contact: teja.chintalapati@gmail.com
 *	Description: This file will initialise TimerA to trigger ADC once every 5 seconds
 *	ADC inturn gives temperature reading
 *
 */

/******************************************************************************
 * INCLUDES
 */

#include "mainApp.h"

/******************************************************************************
 * FUNCTION DEFINITIONS
 */

void timerConfiguration(void)
{
	//Setup Timer
	Timer_A_initContinuousModeParam initTimerAParam = {0};
	initTimerAParam.clockSource = 				TIMER_A_CLOCKSOURCE_ACLK;
	initTimerAParam.clockSourceDivider = 		TIMER_A_CLOCKSOURCE_DIVIDER_1;
	initTimerAParam.timerInterruptEnable_TAIE =	TIMER_A_TAIE_INTERRUPT_ENABLE;
	initTimerAParam.timerClear = 				TIMER_A_DO_CLEAR;
	initTimerAParam.startTimer = 				false;
	Timer_A_initContinuousMode(TIMER_A0_BASE, &initTimerAParam);

	Timer_A_clear(TIMER_A0_BASE);
	Timer_A_startCounter(TIMER_A0_BASE, TIMER_A_CONTINUOUS_MODE);
}

/******************************************************************************
 * TIMER ISR
 */
#pragma vector = TIMER0_A1_VECTOR
__interrupt void timer0_ISR(void)
{
	switch(__even_in_range(TA0IV, 0x14))
	{
	case TA0IV_NONE: break;                 // (0x00) None
	case TA0IV_TACCR1: break;               // (0x02) CCR1 IFG
	case TA0IV_TACCR2: break;               // (0x04) CCR2 IFG
	case TA0IV_3: break;                    // (0x06) Reserved
	case TA0IV_4: break;                    // (0x08) Reserved
	case TA0IV_5: break;                    // (0x0A) Reserved
	case TA0IV_6: break;                    // (0x0C) Reserved
	case TA0IV_TAIFG:                       // (0x0E) TA1IFG - TAR overflow
		_low_power_mode_off_on_exit();
		break;
	default: _never_executed();
	}
}
