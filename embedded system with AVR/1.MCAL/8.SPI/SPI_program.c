/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/*************			Author : Reda galal anwer	*********************************/
/*************			Layer : MCALL				*********************************/
/*************			SWC : SPI				    *********************************/
/*************			Version : 1.00		        *********************************/
/************************************************************************************/


#include "SPI_interface.h"
#include "SPI_register.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"


void SPI_Master_INIT(void)
{
/* 1 for select master  */
SET_BIT(SPCR,SPCR_MSTR);	
	
	
/* prescaller divided by 16  : clock speed */	
SET_BIT(SPCR,SPCR_SPR0);
CLR_BIT(SPCR,SPCR_SPR1);	
CLR_BIT(SPSR,SPSR_SPI2X);	
	
/*  SPI enable  */
SET_BIT(SPCR,SPCR_SPE);	
}



void SPI_Salve_INIT(void)
{
	
/*  0 for select slave  */
CLR_BIT(SPCR,SPCR_MSTR);		
	
	
/*  SPI enable  */
SET_BIT(SPCR,SPCR_SPE);	
}



u8 SPI_TranSceve(u8 data)
{
	
/*  send data */
SPDR=data;

/* polling until transfer complete */
while(GET_BIT(SPSR,SPSR_SPIF)==0);

/*  receive data */
return SPDR;	
	
	
}