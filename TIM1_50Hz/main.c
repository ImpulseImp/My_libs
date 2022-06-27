/*
 * 
 *
 * Created: 6/28/2022 12:51:48 AM
 * Author : Impulse
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#define LED1 PB0
#define toggle_LED1 PORTB ^= (1 << PB0)


void tim1_frequancy(uint8_t frequancy)
{
	
	TCCR1B |= (1 << WGM12); // CTC mode
	TCCR1B |= (1<<CS12); // prescelar 256
	TIMSK1 |= (1 << OCIE1A); // Timer/Counter1, Output Compare A Match Interrupt Enable
	OCR1A = (F_CPU/(frequancy*2*256)-1); // frequency equation 
	sei(); //Global interrupt enable
	
}

 ISR (TIMER1_COMPA_vect)
 {
	 toggle_LED1;  //(1.048606833 sec) 
	 
 }


int main(void)
{
	DDRB = (1 << LED1); //set LED PIN as an output
	tim1_frequancy(50); // 50 Hz
    /* Replace with your application code */
    while (1) 
    {
    }
}

