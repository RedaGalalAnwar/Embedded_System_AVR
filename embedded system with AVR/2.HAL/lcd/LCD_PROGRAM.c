/***********************************************************************************************************/
/***********************************************************************************************************/
/*********************         Author : reda galal anwer         *******************************************/
/*********************			 Layer : HAL                     *******************************************/
/*********************			 SWC : LCD 						  ******************************************/
/***************************** Version : 1.2 ***************************************************************/
/***********************************************************************************************************/
/***********************************************************************************************************/


#define F_CPU		8000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interfacing.h"
#include "LCD_Config.h"
#include "LCD_interface.h"



void LCD_Init(void)
{
	DIO_u8SetPinDirection(RS_PORT,RS,DIO_u8PIN_OUTPUT); //RS
	DIO_u8SetPinDirection(EN_PORT,EN,DIO_u8PIN_OUTPUT); //EN
	DIO_u8SetPinDirection(RW_PORT,RW,DIO_u8PIN_OUTPUT); //RW


#if(Mode==4)
#ifdef Higher_Pin
//DIO_u8SetPortDirection(LCD_PORT,| 0xF0);
DDRB|=0xF0;
_delay_ms(50);
LCD_WriteCommand(0x02);
_delay_ms(1);
LCD_WriteCommand(0x28);

#else
DDRB|=0x0F;
_delay_ms(50);
LCD_WriteCommand(0x02);
_delay_ms(1);
LCD_WriteCommand(0x28);
//DIO_u8SetPortDirection(LCD_PORT,| 0x0F);
#endif

	
	
#elif(Mode==8)	
DIO_u8SetPortDirection(LCD_PORT,0xFF);
_delay_ms(50);
LCD_WriteCommand(0x38);//set cursor location  0x38
#endif


_delay_ms(1);
LCD_WriteCommand(0x0C);//set cursor off
//LCD_WriteCommand(0x0E);//set cursor on
_delay_ms(1);
LCD_WriteCommand(0x01);
_delay_ms(2);
LCD_WriteCommand(0x06);//cursor increment
_delay_ms(1);
}

void LCD_WriteCommand(u8 Command)
{
	/* Rs = 0*/
	DIO_u8SetPinValue(RS_PORT,RS,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(RW_PORT,RW,DIO_u8PIN_LOW);
	/* RW = 0*/

#if(Mode==4)
#ifdef Higher_Pin
   DIO_u8SetPortValue(LCD_PORT,  ( (LCD_PORT & 0x0F) | (Command & 0xF0) )  );
#else
   DIO_u8SetPortValue(LCD_PORT,  ( (LCD_PORT & 0xF0) | ((Command & 0xF0)>>4) )  );
#endif
 
_delay_ms(1);
DIO_u8SetPinValue(EN_PORT,EN,DIO_u8PIN_HIGH); //EN
_delay_ms(1);
DIO_u8SetPinValue(EN_PORT,EN,DIO_u8PIN_LOW);
_delay_ms(1);

#ifdef Higher_Pin
DIO_u8SetPortValue(LCD_PORT,  ( (LCD_PORT & 0x0F) | ((Command & 0x0F)<<4) )  );
#else
DIO_u8SetPortValue(LCD_PORT,  ( (LCD_PORT & 0xF0) | (Command & 0x0F) )  );
#endif


#elif(Mode==8)
DIO_u8SetPortValue(LCD_PORT,Command);
#endif
		
	
/*Set Enable */
DIO_u8SetPinValue(EN_PORT,EN,DIO_u8PIN_HIGH); //EN
_delay_ms(1);
DIO_u8SetPinValue(EN_PORT,EN,DIO_u8PIN_LOW);
_delay_ms(1);

}
void LCD_WriteData(u8 Data)
{
	/* Rs = 1*/
	DIO_u8SetPinValue(RS_PORT,RS,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(RW_PORT,RW,DIO_u8PIN_LOW);
	/* RW = 0*/
	
#if(Mode==4)
#ifdef Higher_Pin
DIO_u8SetPortValue(LCD_PORT,  ( (LCD_PORT & 0x0F) | (Data & 0xF0) )  );
#else
DIO_u8SetPortValue(LCD_PORT,  ( (LCD_PORT & 0xF0) | ((Data & 0xF0)>>4) )  );
#endif

_delay_ms(1);
/*Set Enable */
DIO_u8SetPinValue(EN_PORT,EN,DIO_u8PIN_HIGH); //EN
_delay_ms(1);
DIO_u8SetPinValue(EN_PORT,EN,DIO_u8PIN_LOW);
_delay_ms(1);

#ifdef Higher_Pin
DIO_u8SetPortValue(LCD_PORT,  ( (LCD_PORT & 0x0F) | ((Data & 0x0F)<<4) )  );
#else
DIO_u8SetPortValue(LCD_PORT,  ( (LCD_PORT & 0xF0) | (Data & 0x0F) )  );
#endif

#elif(Mode==8)
DIO_u8SetPortValue(LCD_PORT,Data);
#endif	
_delay_ms(1);
/*Set Enable */
DIO_u8SetPinValue(EN_PORT,EN,DIO_u8PIN_HIGH); //EN
_delay_ms(1);
DIO_u8SetPinValue(EN_PORT,EN,DIO_u8PIN_LOW);
_delay_ms(1);
}

					/****************************************************************************************************/

void LCD_WriteString(char *ptr)
{
	u8 i=0;
	while(ptr[i]!='\0')
	{
		LCD_WriteData(ptr[i]);
		i++;
	}
}


void LCD_GoToRowColumn(u8 row ,u8 col)
{
u8 address;

switch(row)
{
    case 0:
      address=col;
	  break;
	 case 1:
	 address=col+0x40;
	 break;
	 case 2:
	 address=col+0x10;
	 break;
	 case 3:
	 address=col+0x50;
	 break;	
}

LCD_WriteCommand(address + SetCursorLocation);
	
}


void LCD_WriteNumber(s64 num)
{
	u8 i=0,j,rem,arr[16];
	if (num==0)
	{
		LCD_WriteData('0');
	}
	else 
	{
		if (num<0)
		{
			num=num*(-1);
			LCD_WriteData('-');
		}
		while (num>0)
		{
			rem=num%10;
			arr[i]=rem+'0';
			i++;
			num=num/10;	
		}
		for (j=i;j>0;j--)
		{
			LCD_WriteData(arr[j-1]);
		}
	}
		
}


void LCD_WriteNumberInBinary(u8 num)
{
	s8 i;
	for (i=7;i>=0;i--)
	{
		LCD_WriteData(((num>>i)&1)+'0');
	}
}


void LCD_ClearScrean(void)
{
	LCD_WriteCommand(lcd_clr);
}


void LCD_DisplayNumberRowColumn(s64 num , u8 row , u8 col)
{
	LCD_GoToRowColumn(row,col);
	LCD_WriteNumber(num);
}


void LCD_DisplayStringRowColumn(u8 *ptr,u8 row, u8 col)
{
	LCD_GoToRowColumn(row,col);
	LCD_WriteString(ptr);
}

void LCD_ScrollDisplayRight(void)
{
	LCD_WriteCommand(Displayright);
}


void LCD_ScrollDisplayLEFT(void)
{
	LCD_WriteCommand(Displayleft);
}


