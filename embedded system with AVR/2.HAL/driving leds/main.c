/*
 * leds with two switchs.c
 *
 * Created: 8/30/2022 7:33:56 PM
 * Author : reda
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>



int main(void)
{

	DDRD = 0xFF;             //set port D as output
	DDRB=DDRB &(~(1<<3));    //set PB3 as input
	DDRB=DDRB &(~(1<<5));    // set PB5 as input 

    int count =0;
	PORTB=PORTB|(1<<3);     // turn on PB3 as pull up resistor
	while (1)
 {
		
      if(!(PINB&(1<<3)))
	  {
		count++;
		while(!(PINB&(1<<3)));  
	  }
	  
     else if(PINB&(1<<5))
     {
	count--;
	while(PINB&(1<<5));
     }
	
if(count>7)   count=0;
 else if(count<0)   count=7;

PORTD=(1<<count);	//turn on one led by shifting
	}
}



