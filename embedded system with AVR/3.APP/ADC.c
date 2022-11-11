#define F_CPU 8000000UL


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_config.h"
#include "ADC_interfacing.h"
#include "ADC_register.h"
#include "ADC_privit.h"
#include "DIO_interfacing.h"
#include "DIO_register.h"
#include "LCD_Config.h"
#include "LCD_interface.h"
#include "Sensors.h"

u8 ADC_read1,ADC_read2;
void turnOn_notification(void);
int main(void)
{
	LCD_Init();
  ADC_INIT(VRef_AVCC,ADC_SCALER_128);
  u16 status;
  u16 temp;
  u16 LDR;
  DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_INPUT);
  DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_INPUT);
  DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_INPUT);
  DIO_u8SetPortDirection(DIO_u8PORTB,DIO_u8PORT_OUTPUT);

LCD_DisplayStringRowColumn("VOLT:",0,0);
LCD_DisplayStringRowColumn("TEMP:",1,0);
LCD_DisplayStringRowColumn("mV",0,12);
LCD_DisplayStringRowColumn("C'",1,12);
LCD_DisplayStringRowColumn("LDR : ",2,0);
 
    while (1) 
    {
		
status=VoltRead_InMilli_10Bits(ADC_CH_0);
temp=TEMP_Read_10Bits(ADC_CH_1);
LDR=VoltRead_InMilli_10Bits(ADC_CH_2);


 LCD_GoToRowColumn(0,7);
LCD_WriteNumberIn4Digit(status);


 LCD_GoToRowColumn(1,7);
 LCD_WriteNumberIn4Digit(temp);
 /**********************check the value of the LDR *************/
if (LDR>3&&LDR<120)
{
LCD_DisplayStringRowColumn(" dark",3,0);
DIO_u8SetPortValue(DIO_u8PORTB,DIO_u8PORT_HIGH);	
}
else if (LDR>121&&LDR<1000)
{
LCD_DisplayStringRowColumn("light is weak",3,0);
DIO_u8SetPortValue(DIO_u8PORTB,0b00001111);	
}
else if (LDR>1000&&LDR<=2500)
{
LCD_DisplayStringRowColumn("light is high",3,0);
DIO_u8SetPortValue(DIO_u8PORTB,DIO_u8PORT_LOW);	
}
/*****************************************************************************************************/
ADC_StartConversion_Synch_8bits(ADC_CH_4,&ADC_read1,50000);
ADC_StratConversion_Asynch_8bits(ADC_CH_5,&ADC_read2,&turnOn_notification);
/*****************************************************************************************************/
		
    }
}

void turnOn_notification(void)
{
	DIO_u8SetPortValue(DIO_u8PORTD,ADC_read2);
}