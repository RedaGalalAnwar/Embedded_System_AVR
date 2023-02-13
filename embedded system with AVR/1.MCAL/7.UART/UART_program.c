/***********************************************************************************************************/
/***********************************************************************************************************/
/*********************         Author : reda galal anwer         *******************************************/
/*********************			 Layer : MCAL                    *******************************************/
/*********************			 SWC : UART 					  ******************************************/
/***************************** Version : 1.1 ***************************************************************/
/***********************************************************************************************************/
/***********************************************************************************************************/

#include "UART_register.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "UART_interface.h"


void UART_INIT(void)
{
u8 value=0;

/*****  register select : UCSRC *****/
SET_BIT(value,7);

/*** charchacter size 8 bits *****/
SET_BIT(value,UCSRC_UCSZ1);
SET_BIT(value,UCSRC_UCSZ0);
	
UCSRC=value;
UBRRL=51;  /*** baud rate 9600 ***/

SET_BIT(UCSRB,UCSRB_RXEN);  /**** reciever enable ****/
SET_BIT(UCSRB,UCSRB_TXEN);	/**** transimetter enable ****/ 

/* by default :
no parity
Asynchronous mode 
no interrupt 
*/

	
}

u8 UART_Read(void)
{
	
	
/*polling until receive complete (flag)*/
while(GET_BIT(UCSRA,UCSRA_RXC)==0); 	
	
	return UDR;
	
	
}
void UART_Send(u8 data)
{
	
	
/* polling until data register empty */
while(GET_BIT(UCSRA,UCSRA_UDRE)==0);	
	
UDR=data;	
	
	
}

void UART_SendString(char *ptr)
{
	u8 i=0;
	while (ptr[i]!='\0')
	{
		UART_Send(ptr[i]);
		i++;
	}
}


/*
void UART_SendString(char *ptr)
{
	u8 i=0;
for (i=0;i<ptr[i];i++)
{
		UART_Send(ptr[i]);
	
}
	
}

*/