/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/*************			Author : Reda galal anwer	*********************************/
/*************			Layer : MCAL				*********************************/
/*************			SWC : ADC				    *********************************/
/*************			Version : 1.00		        *********************************/
/************************************************************************************/

#ifndef ADC_INTERFACING_H_
#define ADC_INTERFACING_H_


u8 ADC_INIT(ADC_VoltRef vref,ADC_Prescaler prescaler);
u16 ADC_AnalogRead(ADC_Channel channel);


u8 ADC_StartConversion_Synch_8bits(ADC_Channel channel ,u8* reading, u32 TimeOut);
u8 ADC_StratConversion_Asynch_8bits(ADC_Channel channel ,u8* reading,void(*Notifaction_FUNC)(void));


s32 MAP(s32 input_min,s32 input_max,s32 output_min,s32 output_max,s32 input_value);







#endif