#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_config.h"
#include "ADC_interfacing.h"
#include "ADC_register.h"
#include "ADC_privit.h"


u8* ADC_reading=NULL;
void(*callback_FUNC)(void)=NULL;
u8 state= idle;

u8 ADC_INIT(ADC_VoltRef vref,ADC_Prescaler prescaler)
{
/*****************  volt reference *******************/	
	switch(vref)
	{
		case VRef_AVCC :
		SET_BIT(ADMUX,ADMUX_REFS0) ;
		CLR_BIT(ADMUX,ADMUX_REFS1) ;
		break ;
		case VRef_AREF :
		CLR_BIT(ADMUX,ADMUX_REFS0) ;
		CLR_BIT(ADMUX,ADMUX_REFS0) ;
		break ;
		
		case VRef_256v :
		SET_BIT(ADMUX,ADMUX_REFS0) ;
		SET_BIT(ADMUX,ADMUX_REFS1) ;
		break ;
		
		default:
		return 1 ;		
	}

#if BITMODE ==EIGHT_BITS
/*activate left adjust result *************************/	
SET_BIT(ADMUX,ADMUX_ADLAR);
/*activate right adjust result ************************/
#elif BITMODE==TEN_BITS
CLR_BIT(ADMUX,ADMUX_ADLAR);
#else
#error "wrong BIT MODE configartion option "
#endif


/*****  prescaler division factor*****/
ADCSRA &=0b11111000;
ADCSRA |=prescaler;

/*ADC Enable ****************************/
SET_BIT(ADCSRA,ADCSRA_ADEN);	
}



/**********************************************************************************************************************************/
u16 ADC_AnalogRead(ADC_Channel channel)
{
/*clear the MUX BIT*/	
ADMUX&=0b11100000;
/*set required channel in the MUX*/	
ADMUX|=channel;
/*start conversion*/	
SET_BIT(ADCSRA,ADCSRA_ADSC);	
/*polling (busy waiting) until the conversion complete flag is set*/
while(GET_BIT(ADCSRA,ADCSRA_ADIF)==0);
/*clear the flag by putting 1 in it*/
SET_BIT(ADCSRA,ADCSRA_ADIF);
/*reading 8 bit */
#if BITMODE == EIGHT_BITS
return ADCH;	
#elif BITMODE == TEN_BITS
							/*u16 AD=ADCL|((u16)ADCH<<8);
							return AD;*/
return ADC;
#else
#error "wrong BIT MODE configartion option "
#endif

}



/*******************************************************************************************************************************/
u8 ADC_StartConversion_Synch_8bits(ADC_Channel channel ,u8* reading, u32 TimeOut)
{
	
u32 counter=0;	
u8 error_state =OK;
if (state==idle)
{	
	state=busy;
	/*clear the MUX BIT*/
	ADMUX&=0b11100000;
	/*set required channel in the MUX*/
	ADMUX|=channel;
	/*start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/*polling (busy waiting) until the conversion complete flag is set and counter reaching the timeout*/
	while((GET_BIT(ADCSRA,ADCSRA_ADIF)==0)&&(counter!=TimeOut) )
	{
		counter++;
	}
	if (counter==TimeOut)
	{
		error_state=NOK;
	}
	else
	{
		/*clear the flag by putting 1 in it*/
		SET_BIT(ADCSRA,ADCSRA_ADIF);
		*reading=ADCH;
		state=idle;
	}	
}
else
{
	error_state=BusyFunc;
}

return  error_state;	
}


/*******************************************************************************************************************************/
u8 ADC_StratConversion_Asynch_8bits(ADC_Channel channel ,u8* reading,void(*Notifaction_FUNC)(void))
{
u8 error_state =OK;
if (state==idle)
{
	if ((reading==NULL)||(Notifaction_FUNC==NULL))
	{
		error_state=NULL_pointer;
		
	}
	else
	{
		state=busy;
		ADC_reading=reading;
		callback_FUNC=Notifaction_FUNC;

		/*clear the MUX BIT*/
		ADMUX&=0b11100000;
		/*set required channel in the MUX*/
		ADMUX|=channel;
		/*start conversion*/
		SET_BIT(ADCSRA,ADCSRA_ADSC);
		/** enble ADC interrupt **/
		SET_BIT(ADCSRA,ADCSRA_ADIE);
	}
}

else
{
error_state=BusyFunc;	
}

	
	
return error_state;	
}
/**************************  ISR function   ******************************/
void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
*ADC_reading=ADCH;
state=idle;

callback_FUNC();

CLR_BIT(ADCSRA,ADCSRA_ADIE);	
}


/********************************************************************************************************************************/
s32 MAP(s32 input_min,s32 input_max,s32 output_min,s32 output_max,s32 input_value)
{
	s32 output_value;
	output_value=(		( (output_max-output_min)*(input_value-input_min) ) /(input_max-input_min)		)+output_min;
	return output_value;
}