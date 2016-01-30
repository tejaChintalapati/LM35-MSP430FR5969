/*
 * 	pinInitialisation.c
 *
 *  Created on: Jan 30, 2016
 *  Author: Teja Chintalapati
 *	Contact: teja.chintalapati@gmail.com
 *	Description: This file will initialise all pins required in this program
 *
 */

/******************************************************************************
 * INCLUDES
 */

#include "mainApp.h"

/******************************************************************************
 * FUNCTION DEFINITIONS
 */

void pinConfiguration(void)
{
    /*
     * Set LFXT clock pins to crystal input. By default, they're configured as GPIO.
     * If you don't configure these pins, your code will be stuck in CS_turnOnLFXT function
     */
    GPIO_setAsPeripheralModuleFunctionInputPin( GPIO_PORT_PJ, GPIO_PIN4 + GPIO_PIN5, GPIO_PRIMARY_MODULE_FUNCTION );

    //Set P1.2 as Ternary Module Function Output. We'll connect LM35 Output pin to this pin
    GPIO_setAsPeripheralModuleFunctionOutputPin( ADCPORT, ADCPIN, GPIO_TERNARY_MODULE_FUNCTION );

}
