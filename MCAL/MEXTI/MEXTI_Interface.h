/*
 * MEXTI_Interface.h
 *
 *  Created on: Aug 14, 2023
 *      Author: seifm
 */

#ifndef MCAL_MEXTI_INTERFACE_H_
#define MCAL_MEXTI_INTERFACE_H_


void MEXTI_EnableEXTI(u8 Copy_u8EXTI_Num );
void MEXTI_DisableEXTI(u8 Copy_u8EXTI_Numu );
void MEXTI_Enable_SoftwareEXTI(u8 InterruptNumber);
void MEXTI_TriggerSelect(u8 Copy_Line,u8 Copy_u8SelectTrigger);
void MEXTI_SetCallBack(u8 Copy_u8EXTI_Num , void(*Copy_PF)(void));
void Set_EXTIConfig(u8 InterruptNumber , u8 GPIO_PortNo);

/*Interrupt number*/
#define MEXTI_InterruptLine0 	0
#define MEXTI_InterruptLine1 	1
#define MEXTI_InterruptLine2	2
#define MEXTI_InterruptLine3 	3
#define MEXTI_InterruptLine4 	4
#define MEXTI_InterruptLine5 	5
#define MEXTI_InterruptLine6	6
#define MEXTI_InterruptLine7 	7
#define MEXTI_InterruptLine8 	8
#define MEXTI_InterruptLine9 	9
#define MEXTI_InterruptLine10 	10
#define MEXTI_InterruptLine11 	11
#define MEXTI_InterruptLine12	12
#define MEXTI_InterruptLine13 	13
#define MEXTI_InterruptLine14	14
#define MEXTI_InterruptLine15	15
#define MEXTI_InterruptLine16	16

#define MEXTI_U8_LowLevel_Source 			0
#define MEXTI_U8_AnyChange_Source 			1
#define MEXTI_U8_FallingEdge_Source 		2
#define MEXTI_U8_RisingEdge_Source 			3

#endif /* MCAL_MEXTI_INTERFACE_H_ */
