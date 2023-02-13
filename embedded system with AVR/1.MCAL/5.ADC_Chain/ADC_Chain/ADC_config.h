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

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*****************  volt reference **********************************/
typedef enum
{
VRef_AREF	,
VRef_AVCC	,
VRef_256v	
	
}ADC_VoltRef;


/***************  prescaler division factor***************************/
typedef enum 
{
	ADC_SCALER_2 = 1,
	ADC_SCALER_4 ,
	ADC_SCALER_8 ,
	ADC_SCALER_16 ,
	ADC_SCALER_32 ,
	ADC_SCALER_64 ,
	ADC_SCALER_128	
}ADC_Prescaler;


/**********   analog channel and gain selection bits   ****************/
typedef enum
{
	ADC_CH_0 ,
	ADC_CH_1 ,
	ADC_CH_2 ,
	ADC_CH_3 ,
	ADC_CH_4 ,
	ADC_CH_5 ,
	ADC_CH_6 ,
	ADC_CH_7 ,
		
}ADC_Channel;







#endif