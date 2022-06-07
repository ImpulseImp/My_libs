
#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "USART.h"

int main(void) {

	USART_Init(MYUBRR);
	printf("Hey Imp\n");

	
	while (1) {
	char imp[] = {"This is a test"};
	char i;
	for(i=0; i<15; i++)
	{

		putchar(imp[i]); // by using i as an index.
		_delay_ms(200);
	}	

		while(1);
	}
	
}