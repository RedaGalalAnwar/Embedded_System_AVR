/***********************************************************************************************************/
/***********************************************************************************************************/
/*********************         Author : reda galal anwer         *******************************************/
/*********************			 Layer : HAL                     *******************************************/
/*********************			 SWC : stepper motor 						  ******************************/
/***************************** Version : 1.2 ***************************************************************/
/***********************************************************************************************************/
/***********************************************************************************************************/

#ifndef STEPPER_CONFIG_H_
#define STEPPER_CONFIG_H_

#define Stepper_Bipolar_PORT		DIO_u8PORTC 
#define Stepper_Unipolar_PORT		DIO_u8PORTA


#define Stepper_Bipolar_PIN1		DIO_u8PIN4
#define Stepper_Bipolar_PIN2		DIO_u8PIN5
#define Stepper_Bipolar_PIN3		DIO_u8PIN6
#define Stepper_Bipolar_PIN4		DIO_u8PIN7


#define Stepper_Unipolar_PIN1		DIO_u8PIN0
#define Stepper_Unipolar_PIN2		DIO_u8PIN1
#define Stepper_Unipolar_PIN3		DIO_u8PIN2
#define Stepper_Unipolar_PIN4		DIO_u8PIN3


#define  delay   500

#endif