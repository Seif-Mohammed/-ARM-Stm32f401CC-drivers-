/*
 * SYSTICK_Private.h
 *
 *  Created on: Aug 15, 2023
 *      Author: seifm
 */

#ifndef MCAL_MSYSTICK_PRIVATE_H_
#define MCAL_MSYSTICK_PRIVATE_H_

#define SYSTICK_BaseAdd 0xE000E010

typedef struct {
	u32 STK_CTRL;
	u32 STK_LOAD;
	u32 STK_VAL;
	u32 STK_CALIB;
}SYSTICK_MemMap_t;

#define SYSTICK ((volatile SYSTICK_MemMap_t*)(SYSTICK_BaseAdd))

/*(STK_CTRL)*/
#define MSYSTICK_Flag	16


#endif /* MCAL_MSYSTICK_PRIVATE_H_ */
