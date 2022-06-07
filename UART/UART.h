/*
 * UART.h
 *
 * 
 *  
 */ 


#ifndef UART_H_
#define UART_H_

#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

void USART_Init( unsigned int ubrr);
void USART_Transmit( unsigned char data );
unsigned char USART_Receive( void );
int uart_putchar(char c, FILE *stream);

void UART_Init(unsigned int ubrr_val);
int uart_putchar(char c, FILE *stream);


#endif /* UART_H_ */