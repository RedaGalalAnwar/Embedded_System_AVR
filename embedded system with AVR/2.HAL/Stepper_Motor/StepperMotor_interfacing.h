/***********************************************************************************************************/
/***********************************************************************************************************/
/*********************         Author : reda galal anwer         *******************************************/
/*********************			 Layer : HAL                     *******************************************/
/*********************			 SWC : stepper motor 						  ******************************/
/***************************** Version : 1.2 ***************************************************************/
/***********************************************************************************************************/
/***********************************************************************************************************/


#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_


void Stepper_Bipolar_Init(void);
void Stepper_Unipolar_Init(void);

void Stepper_Bipolar_CW(void);
void Stepper_Bipolar_CCW(void);


void Stepper_Unipolar_CW(void);
void Stepper_Unipolar_CCW(void);


void Stepper_Unipolar_CW_Halfstep(void);
void Stepper_Unipolar_CCW_Halfstep(void);


void Stepper_Unipolar_CW_Withangle(u16 angle);
void Stepper_Unipolar_CCW_Withangle(u16 angle);


#endif