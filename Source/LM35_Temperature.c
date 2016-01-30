/*
 * LM35_Temperature.c
 *
 *  Created on: Jan 30, 2016
 *  Author: Teja Chintalapati
 *	Contact: teja.chintalapati@gmail.com
 *	Description: This file will read Temperature from LM35 and will return it
 *
 */

/******************************************************************************
 * INCLUDES
 */

#include "mainApp.h"

/******************************************************************************
 * FUNCTION DEFINITIONS
 */

float getTemperatureLM35(void)
{
	ADC12_B_startConversion( ADC12_B_BASE, ADCSTARTMEMORY, ADC12_B_SINGLECHANNEL );

	__low_power_mode_3();   											// LPM3, ADC12_B_ISR will force exit

	//Temperature = (ADCValue*Vref)/ADCResolution; Porting the same equation to IQMath library
	float temperature = _IQ7toF(_IQ7div(_IQ7mpy(_IQ7(ADCValue), _IQ7(VRef)), _IQ7(ADC)));

	return temperature;
}
