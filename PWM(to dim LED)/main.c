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
#define LED_ON PORTB |= (1 << LED1)
#define LED_OFF PORTB &= ~(1 << LED1)



void PWM_init(void)  // freq 20 kHz 12.5% duty cycle
{
	TCCR1B |= (1<<CS10) | (1 << WGM12); // no prescelar CTC mode
	TIMSK1 |= (1 << OCIE1A) | (1 << OCIE1B); //output compare IRQ
	OCR1A = 800;   //  800 = (F_CPU/(10000*2*1)-1); (10kHz)
	OCR1B = 100;
	sei();
}
	
 ISR (TIMER1_COMPA_vect)
 {
	 LED_ON; 
	 
 }

 ISR (TIMER1_COMPB_vect)
 {
	 LED_OFF;
	 
 }

int main(void)
{
	DDRB = (1 << LED1); //set LED PIN as an output
	PWM_init();
    /* Replace with your application code */
    while (1) 
    {
    }
}

