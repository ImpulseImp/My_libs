/*
 * ADC_single.c
 *
 * Created: 6/29/2022 2:56:32 PM
 * Author : Impulse
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdio.h>
#include "UART.h"
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
	ADMUX  |= (1 << REFS0); //PC0
	ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // 128 prescelar is 125 kHz 
	ADCSRA |= (1 << ADSC) | (1 << ADATE); // Start ADC Conversion in ADC Auto Trigger mode
	
}
	
	



int main(void)
{
	USART_Init(MYUBRR);
	printf("Hi Impulse");
	ADC_init();

    /* Replace with your application code */
    while (1) 
    {
		adcValue = ADC; /* read ADC */
		printf("ADC is:%d \n", adcValue);			
    }
}
