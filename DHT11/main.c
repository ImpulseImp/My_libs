/*
 * DHT_11.c
 *
 * Created: 6/20/2022 7:57:02 PM
 * Author : Impulse
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdio.h>         // for printf function
#include <stdlib.h>       //for itoa function
#include <util/delay.h> 
#include "UART.h"


#define DHT11_dataPIN PD5 //PIN5 on arduino

char buff[0]; //buffer for itoa function
uint8_t temp; // here we store our temperature in  temp= buffer[2] ( temp is a 3rd byte from datasheet)
uint8_t hum;  // here we store our humidity in hum= buffer[0] ( hum is a 1st byte from datasheet)
int temperature; //variable to printf our temperature
int humidity;    //variable to printf our humidity


void dht11_data(void)
{
	 uint8_t buffer[5]; //here we store data from DHT11
	 uint8_t cnt = 7;   // 7 to store 8 bytes in one bufer
	 uint8_t idx = 0;   // after we store first bit in buffer[0] we start to filling next one (buffer[1])
	 
	 for (int i=0; i< 5; i++) {buffer[i] = 0;} //empty buffer 
	   DDRD |= (1<<DHT11_dataPIN);   //  set PIN5 as output
	   PORTD |= (1<<DHT11_dataPIN);  //  set PIN5 high                        
	   _delay_ms(1000);             // wait at least 1sec (from datasheet)
	   PORTD &= ~(1<<DHT11_dataPIN); //set PIN5 LOW
	   _delay_ms(20);                // wait at least 18ms (I set it to 20 but it works with 18 as well)
	   PORTD |= (1<<DHT11_dataPIN);  // set PIN5 high
	   _delay_us(44);                //wait for response (might be from 20-40us)
	   DDRD &= ~(1<<DHT11_dataPIN);  //set PIN5 as input
       while(PIND & (1<<DHT11_dataPIN));       /*  here we just wait              */
       while((PIND & (1<<DHT11_dataPIN))==0);  /*  for a response signal          */
       while(PIND & (1<<DHT11_dataPIN));       /*  from DHT11                     */
	   
	   for (int q=0; q<40; q++) // start collecting our 40 bytes from DHT11
	   {
		   while((PIND & (1<<DHT11_dataPIN)) == 0); //get the first byte
		   _delay_us(30);                          // if the voltage level high more than 30us it's a 1
		   if(PIND & (1<<DHT11_dataPIN))buffer[idx] |= (1 << cnt); //store 1 in buffer
		   if (cnt == 0)
		   {
			   cnt = 7;
			   idx++;
		   }
		   else cnt--;	   //if the voltage level high less than 30us it's a 0
		   while(PIND & (1<<DHT11_dataPIN));
	   }
	   temp= buffer[2]; //our temperature
	   hum=  buffer[0]; //our humidity
	 //  itoa(temp,buffer,10);   // here 2 means binary 10dec
	 //  printf("Temperature value = %s", buffer);
	//   itoa(hum,buffer,10);   // here 2 means binary 10dec
	//   printf("       Hum value = %s\n", buffer);
	   _delay_ms(200);
}

uint8_t read_temp(){return temp;}
uint8_t read_hum(){return hum;}

int main(void)
{	 
	USART_Init(MYUBRR);

    while (1) 
    {

   dht11_data();
   temperature = read_temp();
   humidity = read_hum();
   itoa(temperature,buff,10);   // here 10 means dec value
   printf("Temperature = %s °C", buff);
   itoa(humidity,buff,10);   // here 10 means dec value
   printf("  Humidity = %s%%\n", buff);

    }
}

