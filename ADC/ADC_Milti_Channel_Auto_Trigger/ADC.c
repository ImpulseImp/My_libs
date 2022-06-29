#include <avr/io.h>
#include <stdio.h>
#include "ADC.h"


uint16_t readADC(uint8_t channel) {
	ADMUX = (0xf0 & ADMUX) | channel;
	ADCSRA |= (1 << ADSC); //start conversion
	ADCSRA |= (1 << ADATE); // auto-trigger
	return (ADC);
}

void ADC_Init(void)
{
	// Set up ADC
	ADMUX |= (1 << REFS0); /* reference voltage on AVCC */
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1); // ADC clock prescaler /64  250kHz add (1 << ADPS0) to be in range of 200 kHz
	ADCSRA |= (1 << ADEN); //ADC Enable
}
