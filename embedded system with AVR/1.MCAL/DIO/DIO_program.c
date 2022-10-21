/****************************************************************/
/****************************************************************/
/************		Author:	Reda galal anwer	*****************/
/************		Layer: 	 MCAL				*****************/
/************		SWC: 	 DIO				*****************/
/************		Version: 1.00				*****************/
/****************************************************************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include  "DIO_interfacing.h"


u8 DIO_u8SetPinDirection(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Direction)
{
	if(Copy_u8PIN > 7 || (Copy_u8Direction != DIO_u8PIN_INPUT && Copy_u8Direction != DIO_u8PIN_OUTPUT))
	{
		return 1;
	}
	switch(Copy_u8PORT)
	{
		case DIO_u8PORTA:
		if(Copy_u8Direction == DIO_u8PIN_OUTPUT)
		{
			SET_BIT(DDRA, Copy_u8PIN);
		}
		else
		{
			CLR_BIT(DDRA, Copy_u8PIN);
		}
	break;
		case DIO_u8PORTB:
		if(Copy_u8Direction == DIO_u8PIN_OUTPUT)
		{
			SET_BIT(DDRB, Copy_u8PIN);
		}
		else
		{
			CLR_BIT(DDRB, Copy_u8PIN);
		}
	break;
		case DIO_u8PORTC:
		if(Copy_u8Direction == DIO_u8PIN_OUTPUT)
		{
			SET_BIT(DDRC, Copy_u8PIN);
		}
		else
		{
			CLR_BIT(DDRC, Copy_u8PIN);
		}
	break;
		case DIO_u8PORTD:
		if(Copy_u8Direction == DIO_u8PIN_OUTPUT)
		{
			SET_BIT(DDRD, Copy_u8PIN);
		}
		else
		{
			CLR_BIT(DDRD, Copy_u8PIN);
		}
	break;
		default:
		return 1;
	}
	return 0;
}


u8 DIO_u8SetPortDirection(u8 Copy_u8PORT, u8 Copy_u8Direction)
{
	switch(Copy_u8PORT)
	{
		case DIO_u8PORTA:
		DDRA = Copy_u8Direction;
	break;
		case DIO_u8PORTB:
		DDRB = Copy_u8Direction;
	break;
		case DIO_u8PORTC:
		DDRC = Copy_u8Direction;
	break;
		case DIO_u8PORTD:
		DDRD = Copy_u8Direction;
	break;
		default:
		return 1;
	}
	return 0;
}


u8 DIO_u8GetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN, u8* Copy_pu8Value)
{
	if (Copy_u8PIN>7)
	{
		return 1;
	}
   switch(Copy_u8PORT)
   {
		  case DIO_u8PORTA :		
		*Copy_pu8Value= GET_BIT(PINA,Copy_u8PIN);
	break;		
		  case DIO_u8PORTB :
	    *Copy_pu8Value= GET_BIT(PINB,Copy_u8PIN);	
	break;
		  case DIO_u8PORTC :
	     *Copy_pu8Value=  GET_BIT(PINC,Copy_u8PIN);
    break;
		  case DIO_u8PORTD :
		 *Copy_pu8Value=  GET_BIT(PIND,Copy_u8PIN);
	break;
		  default:
		  return 1 ;		  
   }		
return 0;	
}



u8 DIO_u8SetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Value)
{
	
  if ((Copy_u8PIN >7) || (Copy_u8Value != DIO_u8PIN_HIGH && Copy_u8Value!=DIO_u8PIN_LOW) )
  {
	return 1;
  }

     switch(Copy_u8PORT)
     {
        case DIO_u8PORTA :
			if (Copy_u8Value==DIO_u8PIN_HIGH)
			{
				SET_BIT(PORTA,Copy_u8PIN);
			}
			else
			{
				CLR_BIT(PORTA,Copy_u8PIN);
			}
	break;

		case DIO_u8PORTB : 
			if (Copy_u8Value==DIO_u8PIN_HIGH)
			{
			SET_BIT(PORTB,Copy_u8PIN);
			}
			else
			{
			CLR_BIT(PORTB,Copy_u8PIN);
			}
	break;
		case DIO_u8PORTC :
			if (Copy_u8Value==DIO_u8PIN_HIGH)
			{
			SET_BIT(PORTC,Copy_u8PIN);
			}
			else
			{
			CLR_BIT(PORTC,Copy_u8PIN);
			}	
	break;		
		case DIO_u8PORTD :
			if (Copy_u8Value==DIO_u8PIN_HIGH)
			{
			SET_BIT(PORTD,Copy_u8PIN);
			}
			else
			{
			CLR_BIT(PORTD,Copy_u8PIN);
			}
	break;			
		default : 
		return 1;
     }
return 0;		
}

u8 DIO_u8SetPortValue(u8 Copy_u8PORT, u8 Copy_u8Value)
{
	
switch(Copy_u8PORT)
{
	case DIO_u8PORTA:
	PORTA = Copy_u8Value;
break;
	case DIO_u8PORTB:
	PORTB = Copy_u8Value;
break;
	case DIO_u8PORTC:
	PORTC = Copy_u8Value;
break;
	case DIO_u8PORTD:
	PORTD = Copy_u8Value;
break;
	default:
	return 1;
}
		
return 0;		
}