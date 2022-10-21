/*
 * 8 leds with two switchs.c
 *
 * Created: 9/1/2022 11:42:21 AM
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
		while (!(PINB&(1<<5)))
		  { 
			
				PORTD=(1<<count);
				_delay_ms(500);
				count++;
				if(count>7)   count=0;
		  }   
	  }
	  
     else if(PINB&(1<<5))
     {
    while(PINB&(1<<3))
	   {
		PORTD=(1<<count);
		_delay_ms(500);
		count--;
		if(count<0)    count=7;
	   }
   }
 
 
 
	}
}

