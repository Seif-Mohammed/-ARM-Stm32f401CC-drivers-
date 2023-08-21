/*
 * MGPIO_Private.h
 *
 *  Created on: Aug 10, 2023
 *      Author: seifm
 */

#ifndef MCAL_MGPIO_PRIVATE_H_
#define MCAL_MGPIO_PRIVATE_H_

#define GPIOA_BaseAddress 0x40020000
#define GPIOB_BaseAddress 0x40020400
#define GPIOC_BaseAddress 0x40020800

#define RCC	((volatile GPIO*)GPIO_BaseAddress)
typedef struct{
	u32 MODER;
	u32 OTYPER;
	u32 OSPEEDR;
	u32 PUPDR;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 LCKR;
	u32 AFRL;
	u32 AFRH;
}GPIO;
#define GPIOA ((volatile GPIO*)(GPIOA_BaseAddress))
#define GPIOB ((volatile GPIO*)(GPIOB_BaseAddress))
#define GPIOC ((volatile GPIO*)(GPIOC_BaseAddress))



#endif /* MCAL_MGPIO_PRIVATE_H_ */
