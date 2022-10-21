#define F_CPU 8000000UL
#include <util//delay.h>
#include <avr/io.h>


	int arr[]={0b10111111,0b10000110,0b11011011,0b11001111,0b11100110,0b11101101,0b11111100,0b10000111,0b11111111,0b11101111};
int segment(int i)
{
PORTC=arr[i%10];
PORTD=arr[i/10];
	
}

int segment2(int i)
{

	PORTB&=~(1<<PB0);
	PORTB |= (1<<PB1);
	PORTB |= (1<<PB2);
	PORTB |= (1<<PB3);
	PORTA=arr[i%10];
	_delay_ms(1);

		
		PORTB |= (1<<PB0);
		PORTB&=~(1<<PB1);
		PORTB |= (1<<PB2);
		PORTB |= (1<<PB3);
		PORTA=arr[i%100/10];
		_delay_ms(1);

		PORTB |= (1<<PB0);

		PORTB |= (1<<PB1);
			PORTB&=~(1<<PB2);
		PORTB |= (1<<PB3);
		PORTA=arr[i/100];
		_delay_ms(1);

			PORTB |=(1<<PB0);
	
		PORTB |= (1<<PB1);
		PORTB |= (1<<PB2);
	PORTB&=~(1<<PB3);
		PORTA=arr[i/1000];
		_delay_ms(1);
	
}


int main(void)
{

	DDRA=0xFF;
	DDRC=0xFF;
	DDRD=0xFF;
	DDRB |=(1<<PB0);	
   	DDRB |=(1<<PB1);  
	DDRB |=(1<<PB2);
	DDRB |=(1<<PB3);	

	
    while (1) 
    {
		for (int i=0;i<=10000;i++)
		{
			for (int x=0;x<50;x++)
			{
				segment2(i);
			}
		segment(i);
	
	
		}
    }
}

