/*
 * MEXTI_Private.h
 *
 *  Created on: Aug 14, 2023
 *      Author: seifm
 */

#ifndef MCAL_MEXTI_PRIVATE_H_
#define MCAL_MEXTI_PRIVATE_H_

#define MEXTI_BaseAddress 0x40013C00
#define MSYSCFG_EXTICR1 *((volatile u32 *)0x40013808)  /*select the source input pin for the EXTI*/

#define GPIOA 0
#define GPIOB 1
#define GPIOC 2
#define GPIOD 3
#define EXTIConfigMask1 0xFFFFFFF0UL
#define EXTIConfigMask2 0xFFFFFF0FUL
#define EXTIConfigMask3 0xFFFFF0FFUL
#define EXTIConfigMask4 0xFFFF0FFFUL

typedef struct{
	u32 EXTI_IMR;
	u32 EXTI_EMR;
	u32 EXTI_RTSR;
	u32 EXTI_FTSR;
	u32 EXTI_SWIER;
	u32 EXTI_PR;
}EXTI;

#define MEXTI	((volatile EXTI*)MEXTI_BaseAddress)

#endif /* MCAL_MEXTI_PRIVATE_H_ */
