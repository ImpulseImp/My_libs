// from make AVR programming
// https://github.com/hexagon5un/AVR-Programming/blob/master/Chapter10_Pulse-Width-Modulation/bruteForcePWM/pwm.c

#define F_CPU 16000000UL
#include <avr/io.h>                        /* Defines pins, ports, etc */
#include <util/delay.h>                     /* Functions to waste time */


#define LED_DELAY 20

int main(void) {

  uint8_t brightness = 0;
  int8_t direction = 1;
  uint8_t i;

  // -------- Inits --------- //

  DDRB = 0xff;                                     /* Init all LEDs */

  // ------ Event loop ------ //
  while (1) {

    // PWM
    for (i = 0; i < 255; i++) {
      if (i < brightness) {
        PORTB = 0xff;                                    /* turn on */
      }
      else {
        PORTB = 0;                                      /* turn off */
      }
      _delay_us(LED_DELAY);
    }

    // Brighten and dim
    if (brightness == 0) {
      direction = 1;
    }
    if (brightness == 255) {
      direction = -1;
    }
    brightness += direction;

  }                                                  /* End event loop */
  return 0;                            /* This line is never reached */
}
