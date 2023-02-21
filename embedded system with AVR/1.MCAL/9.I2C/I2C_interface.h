/************************************************************************************/
/************************************************************************************/
/*************			Author : Reda galal anwer	*********************************/
/*************			Layer : MCALL				*********************************/
/*************			SWC : I2C				    *********************************/
/*************			Version : 1.00		        *********************************/
/************************************************************************************/

#include "STD_TYPES.h"
#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

typedef enum
{
	No_Error,
	StartCondition_Error,
	RepeatedStart_Error,
	SlaveAddressWithWrite_Error,
	SlaveAddressWithRead_Error,
	MasterWriteByte_Error,
	MasterReadByte_Error
	
	}TWI_ErrStatus;


void TWI_Master_INIT(u8 SlaveAddress);
void TWI_Slave_INIT(u8 SlaveAddress);

TWI_ErrStatus TWI_SendSartCondition(void);
TWI_ErrStatus TWI_SendRepeatedStart(void);

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 SlaveAddress);
TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 SlaveAddress);
TWI_ErrStatus TWI_MasterWriteDataByte(u8 data_byte);
TWI_ErrStatus TWI__MasterReadDataByte(u8 *data_byte);

void TWI_SendStopCondition(void);



TWI_ErrStatus SendByte(u8 SlaveAddress , u8 data);
TWI_ErrStatus RecieveByte(u8 SlaveAddress , u8 data);
TWI_ErrStatus SendString(u8 SlaveAddress , u8 *ptr);

#endif