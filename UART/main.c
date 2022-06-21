/*
 * 
 *
 *
 * 
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "UART.h"

int main(void) {

	USART_Init(MYUBRR);
        printf("Hey Imp\n");

	
	while (1) {
 
 int imp[] = {"This is a test"};
 for(int i=0; i<15; i++)
 {

   putchar(imp[i]); // by using i as an index.
    _delay_ms(200);
	 
 }
 while(1);
		} 
		
	}