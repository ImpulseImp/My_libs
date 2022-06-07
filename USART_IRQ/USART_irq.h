/*
 * USART_irq.h
 *
 * Created: 6/1/2022 4:20:13 PM
 *  Author: impul
 */ 


#ifndef USART_IRQ_H_
#define USART_IRQ_H_

/* USART Buffer Defines */
#define USART_RX_BUFFER_SIZE 8     /* 2,4,8,16,32,64,128 or 256 bytes */
#define USART_TX_BUFFER_SIZE 8     /* 2,4,8,16,32,64,128 or 256 bytes */
#define USART_RX_BUFFER_MASK (USART_RX_BUFFER_SIZE - 1)
#define USART_TX_BUFFER_MASK (USART_TX_BUFFER_SIZE - 1)
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1
/*#if (USART_RX_BUFFER_SIZE & USART_RX_BUFFER_MASK)
#error RX buffer size is not a power of 2
#endif
#if (USART_TX_BUFFER_SIZE & USART_TX_BUFFER_MASK)
#error TX buffer size is not a power of 2
#endif */


/* Prototypes */
void USART1_Init(unsigned int ubrr_val);
unsigned char USART1_Receive(void);
void USART1_Transmit(unsigned char data);

 int uart_putchar(char c, FILE *stream);


#endif /* USART_IRQ_H_ */