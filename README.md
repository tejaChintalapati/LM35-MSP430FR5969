# LM35-MSP430FR5969

This project will let you interface LM35 with MSP430FR5969 launchpad.

Project is written in such a way that individual modules such as timers/ADC and Hardware multiplier code 
can be taken and be re-used in your project.

If you are required to change Input pin of MCU, you can do so by changing required bits in 'mainApp.h"

Steps:
1. Make changes in mainApp.h
2. Please check "interruptRegisterChoice" for "ADC12_B_clearInterrupt()" and "InterruptMasks" for "ADC12_B_disableInterrupt" in driverlib/FR5969/adc12_b.h
and change those values accordingly.
3. Cut the part of code in interrupt ISR and paste it in appropriate location
4. Dont forget to wake the CPU up from LPM
