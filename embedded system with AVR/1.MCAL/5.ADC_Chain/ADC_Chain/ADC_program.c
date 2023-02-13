#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_config.h"
#include "ADC_interfacing.h"
#include "ADC_register.h"
#include "ADC_privit.h"


static* ADC_reading=NULL;
static void(*callback_FUNC)(void)=NULL;
u8 state= idle;

static u8 * ChannelArr=NULL;
static u8 SizeArr;
static u16 * ResultArr=NULL;
static u8 ChainIndex=0;

static u8 ADC_source=0;

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


/*activate left adjust result *************************/	
SET_BIT(ADMUX,ADMUX_ADLAR);




/*****  prescaler division factor*****/
ADCSRA &=0b11111000;
ADCSRA |=prescaler;

/*ADC Enable ****************************/
SET_BIT(ADCSRA,ADCSRA_ADEN);	
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
		ADC_source=Single_Channel;
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


/******************************************************************************************************************/
u8 ADC_StartChain_Asynch_8bits(Chain_Type * chain)
{
	
u8 error_state =OK;
	if (state==idle)
	{
		if (chain==NULL)
		{
		error_state=NULL_pointer;
		
		}
		else
		{
		state=busy;
		ADC_source=Chain_Channel;
		ChannelArr=chain->channel;
		ResultArr=chain->result;
		SizeArr=chain->size;
		callback_FUNC=chain->notificationFunc;
		ChainIndex=0;
		
		ADMUX&=0b11100000;
		ADMUX|=ChannelArr[ChainIndex];
		
		SET_BIT(ADCSRA,ADCSRA_ADSC);
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
	
	if(ADC_source=Single_Channel)
	{
		*ADC_reading=ADCH;
		state=idle;

		callback_FUNC();

		CLR_BIT(ADCSRA,ADCSRA_ADIE);
	}
	
	
	else if (ADC_source=Chain_Channel)
	{
	ResultArr[ChainIndex]=ADCH;
	ChainIndex++;
     	if (ChainIndex==SizeArr)
	    {
		state=idle;
		callback_FUNC();
			CLR_BIT(ADCSRA,ADCSRA_ADIE);
		
	    }
	  	else
		{
				ADMUX&=0b11100000;
				ADMUX|=ChannelArr[ChainIndex];
				
				SET_BIT(ADCSRA,ADCSRA_ADSC);
		}
		
	}
}

