#define F_CPU 16000000UL
#include avrio.h
#include stdio.h
#include utildelay.h
#include utildelay.h
#include avrinterrupt.h
#include UART.h
#include ADC.h



int main(void) {
	 -------- Inits --------- 
	UART_Init(MYUBRR);
	ADC_Init();
  printf(Hey Impn);

	while (1) {
    int	pot1 = readADC(PC0);
    int	pot2 = readADC(PC1);
	int	pot3 = readADC(PC2);
	printf(Pot 1 is %d  , pot1);
	printf(Pot 2 is %d  , pot2);
	printf(Pot 3 is %d  n, pot3);
	 
		} 		
	}