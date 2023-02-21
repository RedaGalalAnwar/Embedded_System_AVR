/************************************************************************************/
/************************************************************************************/
/*************			Author : Reda galal anwer	*********************************/
/*************			Layer : MCALL				*********************************/
/*************			SWC : I2C				    *********************************/
/*************			Version : 1.00		        *********************************/
/************************************************************************************/


#include "I2C_register.h"
#include "I2C_interface.h"
#include "I2C_privit.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"

void TWI_Master_INIT(u8 SlaveAddress)
{
/*set clock frequency as 400Kbps */	
TWDR=2;		
CLR_BIT(TWSR,TWSR_TWPS0);
CLR_BIT(TWSR,TWSR_TWPS1);


if (SlaveAddress!=0)
{
	/* set the slave address in the 7 MSB in the data register */
	TWAR=SlaveAddress<<1;
}

/*Enable TWI*/	
	SET_BIT(TWCR,TWCR_TWEN);
	
}


void TWI_Slave_INIT(u8 SlaveAddress)
{
	/* set the slave address in the 7 MSB in the data register */
	TWAR=SlaveAddress<<1;
	
	/*Enable TWI*/
	SET_BIT(TWCR,TWCR_TWEN);
}



TWI_ErrStatus TWI_SendSartCondition(void)
{
	TWI_ErrStatus state =No_Error;
	
	/*Send start condition on the bus*/
	SET_BIT(TWCR,TWCR_TWSTA);
	
	/*clear the flag to start the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);
	
	/*busy waiting until the flag is raised again and the previous operation is complete*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	
	if ((TWSR &0xF8) !=START_ACK)
	{
		state =StartCondition_Error;
	}
	else
	{
		/* do nothing */
		
	}
	return state;
	
}


TWI_ErrStatus TWI_SendRepeatedStart(void)
{
	TWI_ErrStatus state =No_Error;
	
		/*Send start condition on the bus*/
		SET_BIT(TWCR,TWCR_TWSTA);
		
		/*clear the flag to start the previous operation */
		SET_BIT(TWCR,TWCR_TWINT);
	
		/*busy waiting until the flag is raised again and the previous operation is complete*/
		while(GET_BIT(TWCR,TWCR_TWINT)==0);
	
	if ((TWSR &0xF8) !=REP_START_ACK)
	{
		state =RepeatedStart_Error;
	}
	else
	{
		/* do nothing */
		
	}
	return state;
}


TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 SlaveAddress)
{
	TWI_ErrStatus state =No_Error;
	
	/*Clear start condition on the bus*/
	CLR_BIT(TWCR,TWCR_TWSTA);
	
	/* set the slave address in the 7 MSB in the data register */
	TWAR=SlaveAddress<<1;
	CLR_BIT(TWAR,0);  /* for write request */
	
	/*clear the flag to start the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);
	
	/*busy waiting until the flag is raised again and the previous operation is complete*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	
if ((TWSR &0xF8) !=SLAVE_ADD_RW_ACK)
{
	state =SlaveAddressWithWrite_Error;
}
else
{
	/* do nothing */
	
}
return state;	
}


TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 SlaveAddress)
{
		TWI_ErrStatus state =No_Error;
		
		/*Clear start condition on the bus*/
		CLR_BIT(TWCR,TWCR_TWSTA);
		
		/* set the slave address in the 7 MSB in the data register */
		TWAR=SlaveAddress<<1;
		SET_BIT(TWAR,0);  /* for Read request */
		
		/*clear the flag to start the previous operation */
		SET_BIT(TWCR,TWCR_TWINT);
		
		/*busy waiting until the flag is raised again and the previous operation is complete*/
		while(GET_BIT(TWCR,TWCR_TWINT)==0);
		
		if ((TWSR &0xF8) !=SLAVE_ADD_RD_ACK)
		{
			state =SlaveAddressWithRead_Error;
		}
		else
		{
			/* do nothing */
			
		}
		return state;	
}


TWI_ErrStatus TWI_MasterWriteDataByte(u8 data_byte)
{
	TWI_ErrStatus state =No_Error;
	
	
	/*write the data byte*/
	TWDR=data_byte;
		/*clear the flag to start the previous operation */
		SET_BIT(TWCR,TWCR_TWINT);
		
		/*busy waiting until the flag is raised again and the previous operation is complete*/
		while(GET_BIT(TWCR,TWCR_TWINT)==0);
		
		if ((TWSR &0xF8) !=MSTR_WR_BYTE_ACK)
		{
			state =MasterWriteByte_Error;
		}
		else
		{
			/* do nothing */
			
		}
		return state;
}


TWI_ErrStatus TWI__MasterReadDataByte(u8 *data_byte)
{
		TWI_ErrStatus state =No_Error;
		
		/*Enable master generation ACK bit after receiving the data*/
			SET_BIT(TWCR,TWCR_TWEA);
			
		/*clear the flag to start the previous operation */
		SET_BIT(TWCR,TWCR_TWINT);
		
		/*busy waiting until the flag is raised again and the previous operation is complete*/
		while(GET_BIT(TWCR,TWCR_TWINT)==0);
		
		if ((TWSR &0xF8) !=MSTR_RD_BYTE_ACK)
		{
			state =MasterReadByte_Error;
		}
		else
		{
			*data_byte=TWDR;
			
		}
		return state;
	
	
}

void TWI_SendStopCondition(void)
{
	
	/* send stop condition on the bus*/
	SET_BIT(TWCR,TWCR_TWSTO);
	
	
	/*clear the flag to start the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);
	
}


TWI_ErrStatus SendByte(u8 SlaveAddress , u8 data)
{
	
	
	 TWI_SendSartCondition();
	TWI_SendSlaveAddressWithWrite( SlaveAddress);
	 TWI_MasterWriteDataByte( data);
	 TWI_SendStopCondition();
	
}

TWI_ErrStatus RecieveByte(u8 SlaveAddress , u8 data)
{
	
	
	TWI_SendSartCondition();
	TWI_SendSlaveAddressWithRead( SlaveAddress);
	TWI__MasterReadDataByte( data);
	TWI_SendStopCondition();
	
}

TWI_ErrStatus SendString(u8 SlaveAddress , u8 *ptr)
{
	
	
	TWI_SendSartCondition();
	TWI_SendSlaveAddressWithWrite( SlaveAddress);
	
	for (int i=0;i<ptr[i];i++)
	{
		TWI_MasterWriteDataByte( ptr[i]);
	}
	
	TWI_SendStopCondition();
	
}