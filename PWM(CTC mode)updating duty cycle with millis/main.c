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
	TCCR1B |= (1<<CS10) | (1 << WGM12); // no prescaler CTC mode
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

 ISR (TIMER0_COMPA_vect)
 {
	 uint16_t period = OCR1A;
	 uint16_t duty = OCR1B;
	 if ( duty < period)
	 {
		 duty++;
	 } 
	 else
	 {
		  duty=0;
	 }
	  OCR1B = duty;
 }
void millis_tim0 (uint8_t millis)
{
	TCCR0A |=(1 << WGM01);
	TCCR0B |= (1 << CS00) | (1 << CS02); //set prescaler of 1024
	// = millis*7,8125-1
	OCR0A = millis*7.8125-1; // OCR0A = 14;
	TIMSK0 |= (1 << OCIE0A);
}

int main(void)
{
	DDRB = (1 << LED1); //set LED PIN as an output
	PWM_init();
	millis_tim0 (2);
    /* Replace with your application code */
    while (1) 
    {
    }
}

