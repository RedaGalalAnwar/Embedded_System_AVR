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

#include "STD_TYPES.h"
#include "DIO_register.h"
#include "DIO_interfacing.h"
#include "keypad_Config.h"
#include "keypad_interfacing.h"

/*u8 arr[ROW][COLUMN]={{'7','8','9','/'},
					{'4','5','6','*'},
					{'1','2','3','-'},
					{'c','0','=','+'}};

u8 KEYPAD_GetPressedKey(void)
{
DIO_u8SetPinDirection(KEYPAD_Rows_Port,FIRST_OUT,DIO_u8PIN_INPUT);	
DIO_u8SetPinDirection(KEYPAD_Rows_Port,FIRST_OUT+1,DIO_u8PIN_INPUT);	
DIO_u8SetPinDirection(KEYPAD_Rows_Port,FIRST_OUT+2,DIO_u8PIN_INPUT);	
DIO_u8SetPinDirection(KEYPAD_Rows_Port,FIRST_OUT+3,DIO_u8PIN_INPUT);	

DIO_u8SetPinDirection(KEYPAD_Columns_Port,FIRST_IN,DIO_u8PIN_INPUT);	
DIO_u8SetPinDirection(KEYPAD_Columns_Port,FIRST_IN+1,DIO_u8PIN_INPUT);
DIO_u8SetPinDirection(KEYPAD_Columns_Port,FIRST_IN+2,DIO_u8PIN_INPUT);
DIO_u8SetPinDirection(KEYPAD_Columns_Port,FIRST_IN+3,DIO_u8PIN_INPUT);

u8 r,c,key=default_key,key_Status;
DIO_u8SetPinValue(KEYPAD_Rows_Port,FIRST_OUT,DIO_u8PIN_HIGH);
DIO_u8SetPinValue(KEYPAD_Rows_Port,FIRST_OUT+1,DIO_u8PIN_HIGH);
DIO_u8SetPinValue(KEYPAD_Rows_Port,FIRST_OUT+2,DIO_u8PIN_HIGH);
DIO_u8SetPinValue(KEYPAD_Rows_Port,FIRST_OUT+3,DIO_u8PIN_HIGH);	

for (r=0;r<ROW;r++)
{
	DIO_u8SetPinValue(KEYPAD_Rows_Port,FIRST_OUT+r,DIO_u8PIN_LOW);
	for (c=0;c<COLUMN;c++)
	{
	DIO_u8GetPinValue(KEYPAD_Columns_Port,FIRST_IN+c,&key_Status);
		if (!key_Status)
		{
			key=arr[r][c];
			while(!key_Status);
		}	
	}
	DIO_u8SetPinValue(KEYPAD_Rows_Port,FIRST_OUT+r,DIO_u8PIN_HIGH);
}

	return key;
}*/
u8 Keypad_GetPressedKey(void)
{
	u8 local_u8KeyPressed=default_key , c, r, local_u8PinState;
	u8 local_u8KPDArr[ROWS][COULMNS] = KPD_ARR;
	u8 local_u8CoulmnArr[COULMNS] = {KPD_COULMN0_PIN, KPD_COULMN1_PIN, KPD_COULMN2_PIN, KPD_COULMN3_PIN};
	u8 local_u8RowArr[ROWS] = {KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN};
	
	DIO_u8SetPortDirection(KPD_PORT, 0x0F);
	
	DIO_u8SetPinValue(KPD_PORT, KPD_ROW0_PIN, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT, KPD_ROW1_PIN, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT, KPD_ROW2_PIN, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT, KPD_ROW3_PIN, DIO_u8PIN_HIGH);
	
	for(c = 0; c < COULMNS; c++)
	{
		DIO_u8SetPinValue(KPD_PORT, local_u8CoulmnArr[c], DIO_u8PIN_LOW);
		for(r = 0; r < ROWS; r++)
		{
			 DIO_u8GetPinValue(KPD_PORT, local_u8RowArr[r],&local_u8PinState);
			if(local_u8PinState == DIO_u8PIN_LOW)
			{
				local_u8KeyPressed = local_u8KPDArr[r][c];
				
				while (local_u8PinState == DIO_u8PIN_LOW)
				local_u8PinState =  local_u8RowArr[r];
							
			}
		}
		
		DIO_u8SetPinValue(KPD_PORT, local_u8CoulmnArr[c], DIO_u8PIN_HIGH);
	}
	
	return local_u8KeyPressed;
}
