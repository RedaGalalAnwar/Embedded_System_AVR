/************************************************************************************/
/************************************************************************************/
/*************			Author : Reda galal anwer	*********************************/
/*************			Layer : MCALL				*********************************/
/*************			SWC : I2C				    *********************************/
/*************			Version : 1.00		        *********************************/
/************************************************************************************/


#ifndef I2C_PRIVIT_H_
#define I2C_PRIVIT_H_

#define START_ACK					 0x08       /* start has been sent  */
#define REP_START_ACK				 0x10		/* Repeated start*/
#define SLAVE_ADD_RW_ACK			 0x18		/*master transmitted (salve address +write request)*/
#define SLAVE_ADD_RD_ACK			 0x40		/*master transmitted (salve address +read request)*/
#define MSTR_WR_BYTE_ACK			 0x28		/*master transmitted data ACK */
#define MSTR_RD_BYTE_ACK			 0x50		/*master RECIEVED data with ACK */
#define MSTR_RD_BYTE_NACK			 0x58	    /*master RECIEVED data with not ACK */
#define SLAVE_ADD_RCVD_RD_REQ		 0xA8		/*mean that slave address is received with read request*/
#define SLAVE_ADD_RCVD_RW_REQ		 0x60		/*mean that slave address is received with write request*/
#define SLAVE_DATA_RECIEVED			 0x80		/*mean that a byte is received  */
#define SLAVE_BYTE_TRANSMITTED		 0xB8		/*mean that the written byte is transmitted  */


#endif