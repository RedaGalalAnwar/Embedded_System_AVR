/***********************************************************************************************************/
/***********************************************************************************************************/
/*********************         Author : reda galal anwer         *******************************************/
/*********************			 Layer : HAL                     *******************************************/
/*********************			 SWC : stepper motor 						  ******************************/
/***************************** Version : 1.2 ***************************************************************/
/***********************************************************************************************************/
/***********************************************************************************************************/



#define F_CPU		8000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interfacing.h"
#include "StepperMotor_config.h"
#include "StepperMotor_interfacing.h"



void Stepper_Bipolar_Init(void)
{
	DIO_u8SetPinDirection(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN1,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN2,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN3,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN4,DIO_u8PIN_OUTPUT);
}



void Stepper_Unipolar_Init(void)
{
	
	DIO_u8SetPinDirection(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN1,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN2,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN3,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN4,DIO_u8PIN_OUTPUT);
	
}


void Stepper_Bipolar_CW(void)
{



	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN4,DIO_u8PIN_LOW);
	_delay_ms(delay);

	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN3,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN4,DIO_u8PIN_LOW);
	_delay_ms(delay);

	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN4,DIO_u8PIN_LOW);
	_delay_ms(delay);

	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN4,DIO_u8PIN_HIGH);
	_delay_ms(delay);
	
}


void Stepper_Bipolar_CCW(void)
{



	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN4,DIO_u8PIN_HIGH);
	_delay_ms(delay);

	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN4,DIO_u8PIN_LOW);
	_delay_ms(delay);

	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN3,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN4,DIO_u8PIN_LOW);
	_delay_ms(delay);

	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Bipolar_PORT,Stepper_Bipolar_PIN4,DIO_u8PIN_LOW);
	_delay_ms(delay);
	
}



void Stepper_Unipolar_CW(void)
{
	




	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN4,DIO_u8PIN_LOW);
	_delay_ms(delay);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN3,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN4,DIO_u8PIN_LOW);

	_delay_ms(delay);

	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN4,DIO_u8PIN_HIGH);
	_delay_ms(delay);
		DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN1,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN2,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN3,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN4,DIO_u8PIN_LOW);
		_delay_ms(delay);
}



void Stepper_Unipolar_CCW(void)
{


	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN4,DIO_u8PIN_LOW);
	_delay_ms(delay);

	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN4,DIO_u8PIN_HIGH);
	_delay_ms(delay);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN3,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN4,DIO_u8PIN_LOW);
	_delay_ms(delay);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN4,DIO_u8PIN_LOW);

	_delay_ms(delay);


	
}



void Stepper_Unipolar_CW_Halfstep(void)
{




	
	
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN4,DIO_u8PIN_LOW);
	_delay_ms(delay);
	
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN4,DIO_u8PIN_LOW);
	_delay_ms(delay);
	
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN3,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN4,DIO_u8PIN_LOW);
	_delay_ms(delay);
	
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN3,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN4,DIO_u8PIN_LOW);

	_delay_ms(delay);
	
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN3,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN4,DIO_u8PIN_HIGH);
	
	_delay_ms(delay);

	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN4,DIO_u8PIN_HIGH);
	_delay_ms(delay);
	
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN4,DIO_u8PIN_HIGH);
	
	_delay_ms(delay);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN4,DIO_u8PIN_LOW);
	_delay_ms(delay);
}




void Stepper_Unipolar_CCW_Halfstep(void)
{


	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN4,DIO_u8PIN_LOW);
	
	_delay_ms(delay);

	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN4,DIO_u8PIN_HIGH);
	_delay_ms(delay);
	
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN4,DIO_u8PIN_HIGH);
	_delay_ms(delay);
	
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN3,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN4,DIO_u8PIN_HIGH);
	_delay_ms(delay);
	
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN3,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN4,DIO_u8PIN_LOW);
	_delay_ms(delay);
	
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN3,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN4,DIO_u8PIN_LOW);

	_delay_ms(delay);
	
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN4,DIO_u8PIN_LOW);
	
	_delay_ms(delay);

	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Stepper_Unipolar_PORT,Stepper_Unipolar_PIN4,DIO_u8PIN_LOW);
	_delay_ms(delay);
	

}



void Stepper_Unipolar_CW_Withangle(u16 angle)
{
	u32 i=0 , n=0;
	n=(512*angle)/360;


	for (i=0;i<n;i++)
	{
		Stepper_Unipolar_CW();
		
	}
	
}



void Stepper_Unipolar_CCW_Withangle(u16 angle)
{
	u32 i=0 , n;
	n=(512*angle)/360;


	for (i=0;i<n;i++)
	{
		Stepper_Unipolar_CCW();
		
	}
	
}