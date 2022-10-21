/***********************************************************************************************************/
/***********************************************************************************************************/
/*********************         Author : reda galal anwer         *******************************************/
/*********************			 Layer : HAL                     *******************************************/
/*********************			 SWC : LCD 						  ******************************************/
/***************************** Version : 1.2 ***************************************************************/
/***********************************************************************************************************/
/***********************************************************************************************************/


#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H


#include "STD_TYPES.h"



#define line1 1
#define line2 2
#define SetCursorLocation 0x80
#define lcd_clr 0b00000001			//0x01
#define ReturnHomme 0x02
#define Displayright 0b00011100       //0x05
#define Displayleft 0b00011000		//0x07
#define DisplayAndCursorOff  0x08
#define cursorleft 0b00010000		//0x10
#define cursorright 0b00010100

void LCD_Init(void);

void LCD_WriteCommand(u8 Command);

void LCD_WriteData(u8 Data);

void LCD_WriteString(char *Ptr);


void LCD_GoToRowColumn(u8 row , u8 col);

void LCD_WriteNumber(s64 num);

void LCD_WriteNumberInBinary(u8 num);

void LCD_ClearScrean(void);

void LCD_DisplayStringRowColumn(u8 *Ptr,u8 row,u8 col);
void LCD_DisplayNumberRowColumn(s64 num,u8 row,u8 col);

void LCD_ScrollDisplayRight(void);
void LCD_ScrollDisplayLEFT(void);
//void LCD_ScreanOff(void);

	



#endif