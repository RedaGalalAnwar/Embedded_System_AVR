/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/*************			Author : Reda galal anwer	*********************************/
/*************			Layer : HAll				*********************************/
/*************			SWC : keypad				    *****************************/
/*************			Version : 1.00		        *********************************/
/************************************************************************************/

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

/*
#define KEYPAD_Columns_Port  DIO_u8PORTD
#define KEYPAD_Rows_Port    DIO_u8PORTB
#define FIRST_OUT      DIO_u8PIN4  
#define FIRST_IN       DIO_u8PIN0   
#define ROW 4
#define COLUMN 4

*/
					
#define default_key  '.'


//#define KPD_NO_PRESSED 0XFF
#define KPD_ARR  {{'7', '8', '9', '/'},{'4', '5', '6', '*'},{'1', '2', '3', '-'},{'C', '0', '=', '+'}}
#define COULMNS 4
#define ROWS 4
#define KPD_PORT DIO_u8PORTD

#define KPD_COULMN0_PIN  DIO_u8PIN0
#define KPD_COULMN1_PIN  DIO_u8PIN1
#define KPD_COULMN2_PIN  DIO_u8PIN2
#define KPD_COULMN3_PIN  DIO_u8PIN3

#define KPD_ROW0_PIN  DIO_u8PIN4
#define KPD_ROW1_PIN  DIO_u8PIN5
#define KPD_ROW2_PIN  DIO_u8PIN6
#define KPD_ROW3_PIN  DIO_u8PIN7

#endif

