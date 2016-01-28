/*
 * 	portInitialisation.c
 *
 *  Created on: Jan 27, 2016
 *  Author: Teja Chintalapati
 *	Contact: teja.chintalapati@gmail.com
 *	Description: This file will initialise all ports as Inputs with pull down resistors.
 *				 This configuration is the one that consumes least power in FR5969 Launchpad
 *
 */

/******************************************************************************
 * INCLUDES
 */

#include "mainApp.h"

/******************************************************************************
 * FUNCTION DEFINITIONS
 */

void unusedPinsConfiguration(void)
{
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P1, allPins);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P2, allPins);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P3, allPins);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P4, allPins);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_PJ, allPins);
	PM5CTL0 &= ~ LOCKLPM5;
}
