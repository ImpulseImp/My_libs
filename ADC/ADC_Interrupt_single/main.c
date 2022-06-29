#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include "UART.h"
int adcValueLow;
int adcValue;

/*
ADMUX

MUX3 MUX2 MUX1 MUX0   0 0 0 0

   0000 ADC0  PC0
   0001 ADC1  PC1
   0010 ADC2  PC2
   0011 ADC3  PC3
   0100 ADC4  PC4
   0101 ADC5  PC5
   0110 ADC6
   0111 ADC7*/

void ADC_init(void) // ADC = ((Vin*1024)/Vref)
{
	ADMUX  |= (1 << REFS0) | (1 << MUX1); //PC2
	ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); //ADC enable, 128 prescelar is 125 kHz 
	ADCSRA |= (1 << ADSC) | (1 << ADATE) | (1 << ADIE); // Start ADC Conversion in ADC Auto Trigger mode, Interrupt enable
	sei();
}
ISR (ADC_vect)
{
	adcValue = ADCW; // pseudo-register that allows get the data from ADCL and ADCH at once.
}
int main(void)
{
	USART_Init(MYUBRR);
	printf("Hi Impulse");
	ADC_init();


    while (1) 
 {
	printf("ADC is:%d \n", adcValue);			
 }
}
