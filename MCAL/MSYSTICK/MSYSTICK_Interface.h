/*
 * SYSTICK_Interface.h
 *
 *  Created on: Aug 15, 2023
 *      Author: seifm
 */

#ifndef MCAL_MSYSTICK_INTERFACE_H_
#define MCAL_MSYSTICK_INTERFACE_H_

#define MSYSTICK_CLKSRCBIT (0x00000002)
#define MSYSTICK_ENBIT 0
#define MSYSTICK_COUNTFLAG 16
#define MSYSTICK_INTEN 1

void MSYSTICK_InitClkSource(void);
void MSYSTICK_Start(u32 Copy_u8Ticks);
void MSYSTICK_DelayMs(u32 Copy_u32Delay);
u32 MSYSTICK_GetElapsedTime(void);
u32 MSYSTICK_GetRemaningTime(void);
u8 MSYSTICK_ReadFlag( void );

void MSYSTICK_SetCallBack( void (*ptr)(void) );
void MSYSTICK_Handler(void);
void MSYSTICK_Stop(void);

#define NO_ERROR 0
#define ERROR 1


#endif /* MCAL_MSYSTICK_INTERFACE_H_ */
