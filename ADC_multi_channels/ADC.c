/*
 * ADC.c
 *
 * 
 * 
 */ 
#include <avr/io.h>
#include <stdio.h>
#include "ADC.h"

/*ISR(ADC_vect)
{
	// user code here
}*/

uint16_t readADC(uint8_t channel) {
	ADMUX = (0xf0 & ADMUX) | channel;
	ADCSRA |= (1 << ADSC);
	loop_until_bit_is_clear(ADCSRA, ADSC);
	return (ADC);
}

void ADC_Init(void)
{
	// Set up ADC
	ADMUX |= (1 << REFS0); /* reference voltage on AVCC */
	ADCSRA |= (1 << ADPS2) | (1 << ADPS0); /* ADC clock prescaler /8 */
	ADCSRA |= (1 << ADEN);
}