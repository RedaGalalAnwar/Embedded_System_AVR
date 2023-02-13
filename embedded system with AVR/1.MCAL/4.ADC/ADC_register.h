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

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_



		/*ADC multiplexer selection register */
#define ADMUX   	*((volatile u8*)0x27)
#define ADMUX_REFS1	7
#define ADMUX_REFS0	6
#define ADMUX_ADLAR	5




		/*ADC control and status register*/
#define ADCSRA  	*((volatile u8*)0x26)
#define  ADCSRA_ADEN	7			/*ADC enable******************/
#define  ADCSRA_ADSC	6			/*ADC start convertion********/
#define  ADCSRA_ADATE	5			/*ADC AUTO trigger enable*****/
#define  ADCSRA_ADIF	4			/*ADC interrupt flag**********/
#define  ADCSRA_ADIE	3			/*ADC interrupt enable *******/
#define  ADCSRA_ADPS2	2			/*ADC prescaler select BIT2**/
#define  ADCSRA_ADPS1	1			/*ADC prescaler select BIT11*/
#define  ADCSRA_ADPS0	0			/*ADC prescaler select BIT0**/




/*********ADC data register HIGH byte for 8bits mode  ********/
#define ADCH    	*((volatile u8*)0x25)
/*********ADC data register LOW byte for 10bits mode**********/
#define ADCL		*((volatile u8*)0x24)
/************* for for 10bits mode ***************************/
#define ADC			*((volatile u16*)0x24)






#endif