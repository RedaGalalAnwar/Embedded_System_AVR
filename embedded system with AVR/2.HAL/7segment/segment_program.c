/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/*************			Author : Reda galal anwer	*********************************/
/*************			Layer : Hall				*********************************/
/*************			SWC : 7segment				    *****************************/
/*************			Version : 1.00		        *********************************/
/************************************************************************************/

#define F_CPU 8000000UL
#include <util//delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interfacing.h"
#include "segment_config.h"
#include "segment_interfacing.h"




void Segment_Display(u8 num)
{

DIO_u8SetPinDirection(Segment_PORT,PIN1,DIO_u8PIN_OUTPUT);	
DIO_u8SetPinDirection(Segment_PORT,PIN2,DIO_u8PIN_OUTPUT);		
DIO_u8SetPinDirection(Segment_PORT,PIN3,DIO_u8PIN_OUTPUT);	
DIO_u8SetPinDirection(Segment_PORT,PIN4,DIO_u8PIN_OUTPUT);	



if (num>9) num=0;
if(num<0)  num=9;


switch(num)
{
	case 0:
	DIO_u8SetPinValue(Segment_PORT,PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Segment_PORT,PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Segment_PORT,PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Segment_PORT,PIN4,DIO_u8PIN_LOW);
	break;
	case 1:
	DIO_u8SetPinValue(Segment_PORT,PIN1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Segment_PORT,PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Segment_PORT,PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Segment_PORT,PIN4,DIO_u8PIN_LOW);
	break;
	case 2:
	DIO_u8SetPinValue(Segment_PORT,PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Segment_PORT,PIN2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Segment_PORT,PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Segment_PORT,PIN4,DIO_u8PIN_LOW);
	break;
	case 3:
	DIO_u8SetPinValue(Segment_PORT,PIN1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Segment_PORT,PIN2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Segment_PORT,PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Segment_PORT,PIN4,DIO_u8PIN_LOW);
	break;
	case 4:
	DIO_u8SetPinValue(Segment_PORT,PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Segment_PORT,PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Segment_PORT,PIN3,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Segment_PORT,PIN4,DIO_u8PIN_LOW);
	break;
	case 5:
	DIO_u8SetPinValue(Segment_PORT,PIN1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Segment_PORT,PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Segment_PORT,PIN3,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Segment_PORT,PIN4,DIO_u8PIN_LOW);
	break;
	case 6:
	DIO_u8SetPinValue(Segment_PORT,PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Segment_PORT,PIN2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Segment_PORT,PIN3,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Segment_PORT,PIN4,DIO_u8PIN_LOW);
	break;
	case 7:
	DIO_u8SetPinValue(Segment_PORT,PIN1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Segment_PORT,PIN2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Segment_PORT,PIN3,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Segment_PORT,PIN4,DIO_u8PIN_LOW);
	break;
	case 8:
	DIO_u8SetPinValue(Segment_PORT,PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Segment_PORT,PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Segment_PORT,PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Segment_PORT,PIN4,DIO_u8PIN_HIGH);
	break;
	case 9:
	DIO_u8SetPinValue(Segment_PORT,PIN1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Segment_PORT,PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Segment_PORT,PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Segment_PORT,PIN4,DIO_u8PIN_HIGH);
	break;
	default:
	return 1;
	
}

	
}