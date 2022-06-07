#define F_CPU 16000000
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

#include <util/delay.h>
#include <avr/interrupt.h>
#include "USART_irq.h"

int main(void)
{
	/* Set the baudrate to 9600 bps using 8MHz internal RC oscillator */
	USART1_Init(MYUBRR);   
    
		sei();
  printf("HELLO IMPULSE\n");

	while (1) {
				/* Echo the received character */
		USART1_Transmit(USART1_Receive());
	}
	
	return 0;
}



