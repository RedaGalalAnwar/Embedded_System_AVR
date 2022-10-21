#define  F_CPU 8000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include  "DIO_interfacing.h"



int main(void)
{
DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PIN_INPUT);
DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_INPUT);
DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN5,DIO_u8PIN_OUTPUT);
DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_HIGH);
u8 status,status_pin;


    while (1) 
    {		
DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN1,&status);
DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN3,&status_pin);
if (status)
{

			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN5,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);

	


		
	}
else if(!status_pin)
{
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN5,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);

	
}
else
{
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN5,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);	
	
}
	}
}
