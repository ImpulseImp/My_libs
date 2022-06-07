/*
 * 
 *
 * 
 * 
 */ 
#include <avr/io.h>
#include <stdio.h>
#include "USART.h"


static FILE mystdout = FDEV_SETUP_STREAM(USART_putchar, NULL,
_FDEV_SETUP_WRITE);

void USART_Init( unsigned int ubrr)
{
	stdout = &mystdout;
	/*Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	//Enable receiver and transmitter
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	/* Set frame format: 8data, 2stop bit */
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}

void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) );
	/* Put data into buffer, sends the data */
	UDR0 = data;
}

unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) );
	/* Get and return received data from buffer */
	return UDR0;
}


int USART_putchar(char c, FILE *stream)
{
	if (c == '\n')
	USART_putchar('\r', stream);
	loop_until_bit_is_set(UCSR0A, UDRE0);
	UDR0 = c;
	return 0;
}