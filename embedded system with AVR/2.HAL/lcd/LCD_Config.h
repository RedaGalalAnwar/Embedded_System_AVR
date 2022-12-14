/***********************************************************************************************************/
/***********************************************************************************************************/
/*********************         Author : reda galal anwer         *******************************************/
/*********************			 Layer : HAL                     *******************************************/
/*********************			 SWC : LCD 						  ******************************************/
/***************************** Version : 1.2 ***************************************************************/
/***********************************************************************************************************/
/***********************************************************************************************************/


#ifndef LCD_PRIVET_H
#define LCD_PRIVET_H

#define LCD_PORT    DIO_u8PORTA
#define RS_PORT     DIO_u8PORTB
#define RW_PORT		DIO_u8PORTB
#define EN_PORT		DIO_u8PORTB
#define RS 			DIO_u8PIN0  
#define EN 			DIO_u8PIN1  
#define RW          DIO_u8PIN2  
#define Mode  4      // choose if you want 4_bit mode or 8_bit mode or

#if(Mode==4)
#define Higher_Pin  // choose if you want Higher_pin from pin4 to pin7  or Lower_pin from pin0 to pin3
#endif
  
#endif
