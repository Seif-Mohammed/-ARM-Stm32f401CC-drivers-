/*
 * RCC_Interface.h
 *
 *  Created on: Aug 10, 2023
 *      Author: seifm
 */

#ifndef MCAL_RCC_INTERFACE_H_
#define MCAL_RCC_INTERFACE_H_

#define	GPIOA	0
#define	GPIOB	1
#define	GPIOC	2
#define	GPIOD	3
#define	DMA2	4
#define	DMA1	5
#define	CRC		6
#define	WWDG	7
#define	I2C3	8
#define	I2C2	11
#define	I2C1	14
#define	USART6	15
#define	USART5  17
#define	USART4  18
#define	USART3  19
#define	USART2	20
#define	USART1	21
#define	SPI4	22
#define	SPI3	23
#define	SPI2	25
#define	SPI1	26
#define	TIM11	28
#define	TIM10	29
#define	TIM9	30
#define	TIM8	31
#define	TIM7	32
#define	TIM6	33
#define	TIM5	34
#define	TIM4	35
#define	TIM3	36
#define	TIM2	37
#define	TIM1	38
#define	ADC1	39

void MRCC_init(void);
void_MRCC_EnableClock(enum Periphral Perphiral_Name);
void_MRCC_DisableClock(enum Periphral Perphiral_Name);



#endif /* MCAL_RCC_INTERFACE_H_ */
