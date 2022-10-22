 

#define F_CPU		8000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interfacing.h"
#include "LCD_PRIVET.h"
#include "LCD_interface.h"



int main(void)
{
LCD_Init();
LCD_WriteString("reda");
LCD_DisplayStringRowColumn("galal",0,5);
LCD_GoToRowColumn(1,8);
LCD_WriteNumberInBinary(5);
LCD_GoToRowColumn(0,12);
s16 y=-250;
LCD_WriteNumber(y);
LCD_DisplayNumberRowColumn(50,1,4);
_delay_ms(2000);
LCD_ClearScrean();
LCD_DisplayStringRowColumn("welcome",0,5);
for (u8 i=0;i<10;i++)
{
	LCD_ScrollDisplayRight();
	_delay_ms(100);
}
for (u8 i=0;i<20;i++)
{
	LCD_ScrollDisplayLEFT();
	_delay_ms(100);
}
LCD_ClearScrean();
LCD_DisplayStringRowColumn("counter : ",0,0);
 u8 x=0;


    while (1) 
    {

		
		
LCD_GoToRowColumn(1,0);
LCD_WriteNumber(x);
x++;;
_delay_ms(500);
}		
		
	}

		
	

