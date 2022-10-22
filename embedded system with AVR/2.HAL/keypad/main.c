
#define F_CPU		8000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interfacing.h"
#include "keypad_Config.h"
#include "keypad_interfacing.h"
#include "segment_config.h"
#include "segment_interfacing.h"



int main(void)
{
	LCD_Init();
	Stepper_Unipolar_Init();
	Stepper_Bipolar_Init();
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_OUTPUT);
//	LCD_DisplayStringRowColumn("reda",0,0);
	
	
u8 x,num=0 ;

LCD_DisplayStringRowColumn("number :",0,0);
LCD_DisplayStringRowColumn("bin :",1,0);
	LCD_GoToRowColumn(0,8);

	

    while (1) 
    {
x=Keypad_GetPressedKey();
 if (x!=default_key)
 {
	if ((x>='0') && (x<='9'))
	{
	num=(num*10)+(x-'0');
	LCD_WriteData(x);	
	_delay_ms(100);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_HIGH);
	}
	 else if (x=='=')
	 {
	LCD_GoToRowColumn(1,6);
	LCD_WriteNumberInBinary(num);
	
	LCD_GoToRowColumn(0,8);
	num=0;	 
	_delay_ms(100);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_HIGH);
	 }
	 else if (x=='c')
	 {
		 LCD_ClearScrean();
		 LCD_DisplayStringRowColumn("number :",0,0);
		 LCD_DisplayStringRowColumn("bin :",1,0);
		 LCD_GoToRowColumn(0,8);
		 	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_LOW);
	 }	 
	//x=Keypad_GetPressedKey();
//LCD_WriteData(x);
    Segment_Display(x-'0');
//_delay_ms(250);
 }


Stepper_Bipolar_CW();
Stepper_Unipolar_CCW();



  }
  
  
 
}
