#include "i2c.h"
#include <avr/io.h>

void initI2C(void) {
	TWBR = 72;                               /* set bit rate, see p. 242 */
	/* 16MHz / (16+2*TWBR*1) = 100kHz */
	TWCR = (1 << TWEN);                                       /* enable */
}

void i2cWaitForComplete(void) {
	loop_until_bit_is_set(TWCR, TWINT);
}

void i2cStart(void) {
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);
	i2cWaitForComplete();
}

void i2cStop(void) {
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 <<TWSTO);
}

uint8_t i2cReadAck(void) {
	TWCR = (1 << TWINT) | (1 <<TWEN) | (1 << TWEA);
	i2cWaitForComplete();
	return (TWDR);
}

uint8_t i2cReadNoAck(void) {
	TWCR = (1 << TWINT) | (1 << TWEN);
	i2cWaitForComplete();
	return (TWDR);
}

void i2cSend(uint8_t data) {
	TWDR = data;
	TWCR = (1 << TWINT) | (1 <<TWEN);                  /* init and enable */
	i2cWaitForComplete();
}

uint8_t i2cGetStatus(void)
{
	uint8_t status;
	//mask status
	status = TWSR & 0xF8;
	return status;
}
