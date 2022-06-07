/*
 * ADC.h
 *
 * Created: 6/7/2022 3:33:39 PM
 *  Author: impul
 */ 


#ifndef ADC_H_
#define ADC_H_

void ADC_Init(void);
uint16_t readADC(uint8_t channel);
//ISR(ADC_vect);


#endif /* ADC_H_ */