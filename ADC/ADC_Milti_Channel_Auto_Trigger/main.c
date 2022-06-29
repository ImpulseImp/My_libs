#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdio.h>
#include "UART.h"
#include "ADC.h"

int adcValue;


	
int main(void)
{
	USART_Init(MYUBRR);
	printf("Hi Impulse");
    ADC_Init();


    while (1) 
    {
	adcValue = readADC(PC1);		
	printf("ADC:%d\n",adcValue);
    }
}
