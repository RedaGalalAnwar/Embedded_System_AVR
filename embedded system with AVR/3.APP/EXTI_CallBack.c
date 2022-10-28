

#define F_CPU 8000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_register.h"
#include "GIE_interfacing.h"
#include "DIO_register.h"
#include "DIO_interfacing.h"
#include "EXTI_REGISTER.h"
#include "EXTI_CONFIG.h"
#include "EXTI_INTERFACING.h"
#include "EXTI_PRIVET.h"

void ISR_FUNC();
int main(void)
{

EXTI_INIT_INT2();
DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_INPUT);
DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
//DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_LOW);

EXTI_INT2_CallBack(&ISR_FUNC);
GIE_Enable();
    while (1) 
    {
		
		
		
		
    }
}

void ISR_FUNC()
{
DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);	
_delay_ms(5000);
DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);

}