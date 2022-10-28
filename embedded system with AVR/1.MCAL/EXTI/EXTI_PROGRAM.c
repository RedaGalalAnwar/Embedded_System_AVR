/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/*************			Author : Reda galal anwer	*********************************/
/*************			Layer : MCAL				*********************************/
/*************			SWC : EXTI				    *********************************/
/*************			Version : 1.00		        *********************************/
/************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_REGISTER.h"
#include "EXTI_INTERFACING.h"
#include "EXTI_CONFIG.h"
#include "EXTI_PRIVET.h"


void (*EXTI_INT0_FUNC)(void)=NULL;	//Global pointer to function for getting adders of ISR   for INT0
void (*EXTI_INT1_FUNC)(void)=NULL;	//Global pointer to function for getting adders of ISR   for INT1
void (*EXTI_INT2_FUNC)(void)=NULL;	//Global pointer to function for getting adders of ISR   for INT2






/*************************		external interrupt for INT0 initialize **********************/
void EXTI_INIT_INT0(void)
{
	/*********** sense control ***********/
#if INT0_Sense == Low_Level
CLR_BIT(MCUCR,MCUCR_ISC00);
CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_Sense == On_Change
SET_BIT(MCUCR,MCUCR_ISC00);
CLR_BIT(MCUCR,MCUCR_ISC01);
	
#elif INT0_Sense == Falling_Edge
CLR_BIT(MCUCR,MCUCR_ISC00);
SET_BIT(MCUCR,MCUCR_ISC01);	
	
#elif INT0_Sense == Rising_Edge
SET_BIT(MCUCR,MCUCR_ISC00);
SET_BIT(MCUCR,MCUCR_ISC01);

#else
#error " Wrong INT0_Sense Configuration option "

#endif

   /******** enable or disable ********/
#if INT0_State == Enable
SET_BIT(GICR,GICR_INT0);
#elif INT0_State == Disable
CLR_BIT(GICR,GICR_INT0);
#else
#error " Wrong INT0_State Configuration option "
#endif	
}



/*************************		external interrupt for INT1 initialize **********************/

void EXTI_INIT_INT1(void)
{
	
	/*********** sense control ***********/
#if INT1_Sense == Low_Level
CLR_BIT(MCUCR,MCUCR_ISC10);
CLR_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_Sense == On_Change
SET_BIT(MCUCR,MCUCR_ISC10);
CLR_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_Sense == Falling_Edge
CLR_BIT(MCUCR,MCUCR_ISC10);
SET_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_Sense == Rising_Edge
SET_BIT(MCUCR,MCUCR_ISC10);
SET_BIT(MCUCR,MCUCR_ISC11);

#else
#error " Wrong INT1_Sense Configuration option "

#endif	
	
	
	/******** enable or disable ********/
	
	#if INT1_State == Enable
	SET_BIT(GICR,GICR_INT1);
	#elif INT1_State == Disable
	CLR_BIT(GICR,GICR_INT1);
	#else
	#error " Wrong INT1_State Configuration option "
	#endif
	
}


/*************************		external interrupt for INT2 initialize **********************/


void EXTI_INIT_INT2(void)
{
	
	/*********** sense control ***********/
#if INT2_Sense == Falling_Edge
CLR_BIT(MCUCSR,MCUCSR_INT2);


#elif INT2_Sense == Rising_Edge
SET_BIT(MCUCSR,MCUCSR_INT2);	
#else	
#error " Wrong INT2_Sense Configuration option "	
#endif



	/******** enable or disable ********/
	
	#if INT2_State == Enable
	SET_BIT(GICR,GICR_INT2);
	#elif INT2_State == Disable
	CLR_BIT(GICR,GICR_INT2);
	#else
	#error " Wrong INT2_State Configuration option "
	#endif	
	
}

/**********************************************************************************************************************************/
/************************		call back interrupt	for INT0	****************************/

u8 EXTI_INT0_CallBack(void(*INT0_FUNC)(void))
{
	
EXTI_INT0_FUNC=INT0_FUNC;	
	
}

/***********************  ISR Function ***********************************************/

void __vector_1 (void) __attribute__((signal));
void __vector_1(void)
{
	EXTI_INT0_FUNC();
}



/**********************************************************************************************************************************/
/************************		call back interrupt	for INT1	****************************/

u8 EXTI_INT1_CallBack(void(*INT1_FUNC)(void))
{
	
	EXTI_INT1_FUNC=INT1_FUNC;
	
}

/***********************  ISR Function ***********************************************/

void __vector_2 (void) __attribute__((signal));
void __vector_2(void)
{
	EXTI_INT1_FUNC();
}


/**********************************************************************************************************************************/
/************************		call back interrupt	for INT2	****************************/

u8 EXTI_INT2_CallBack(void(*INT2_FUNC)(void))
{
	
	EXTI_INT2_FUNC=INT2_FUNC;
	
}

/***********************  ISR Function ***********************************************/

void __vector_3 (void) __attribute__((signal));
void __vector_3(void)
{
	EXTI_INT2_FUNC();
}