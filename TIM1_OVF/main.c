/*
 * tim1_overflow.c
 *
 * Created: 6/28/2022 12:51:48 AM
 * Author : Impulse
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#define LED1 PB0
#define toggle_LED1 PORTB ^= (1 << PB0)


void tim1_init(void)
{
	TCCR1B |= (1 << CS12); // prescelar 256
	TIMSK1 |= (1 << TOIE1); // Timer/Counter1, Overflow Interrupt Enable
	sei(); //Global interrupt enable
	
}

 ISR (TIMER1_OVF_vect)
 {
	 toggle_LED1;  //(1.048606833 sec) 
	 
 }


int main(void)
{
	DDRB = (1 << LED1); //set LED PIN as an output
	tim1_init();
    /* Replace with your application code */
    while (1) 
    {
    }
}

