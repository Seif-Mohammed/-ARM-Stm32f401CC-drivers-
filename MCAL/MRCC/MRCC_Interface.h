/*
 * RCC_Interface.h
 *
 *  Created on: Aug 10, 2023
 *      Author: seifm
 */

#ifndef MCAL_MRCC_INTERFACE_H_
#define MCAL_MRCC_INTERFACE_H_

typedef enum{
   AHB1 =0 ,
   AHB2  ,
   APB1  ,
   APB2
}BusName_t;
#define AHB1_BUS   0
#define AHB2_BUS   1
#define APB1_BUS   2
#define APB2_BUS   3

/*********** AHB1 peripheral clock enable register ***************/

#define _PERIPHERAL_EN_GPIOA     0
#define _PERIPHERAL_EN_GPIOB     1
#define _PERIPHERAL_EN_GPIOC     2
#define _PERIPHERAL_EN_GPIOD     3
#define _PERIPHERAL_EN_GPIOE     4
#define _PERIPHERAL_EN_GPIOH     7
#define _PERIPHERAL_EN_CRCEN     12
#define _PERIPHERAL_EN_DMA1EN    21
#define _PERIPHERAL_EN_DMA2EN    22


	/********* APB1 peripheral clock enable register *********/

#define PERIPHERAL_EN_TIM2						0
#define PERIPHERAL_EN_TIM3						1
#define PERIPHERAL_EN_TIM4						2
#define PERIPHERAL_EN_TIM5					    3
#define PERIPHERAL_EN_TIM6						4
#define PERIPHERAL_EN_TIM7						5
#define PERIPHERAL_EN_TIM12					    6
#define PERIPHERAL_EN_TIM13					    7
#define PERIPHERAL_EN_TIM14					    8
#define PERIPHERAL_EN_WWDG						11
#define PERIPHERAL_EN_SPI2						14
#define PERIPHERAL_EN_SPI3						15
#define PERIPHERAL_EN_UART2						17
#define PERIPHERAL_EN_UART3						18
#define PERIPHERAL_EN_UART4						19
#define PERIPHERAL_EN_UART5						20
#define PERIPHERAL_EN_I2C1						21
#define PERIPHERAL_EN_I2C2						22
#define PERIPHERAL_EN_I2C3						23
#define PERIPHERAL_EN_CAN1						25
#define PERIPHERAL_EN_CAN2						26
#define PERIPHERAL_EN_PWR						28
#define PERIPHERAL_EN_DAC						29



/********** APB2 peripheral clock enable register (RCC_APB2ENR) *********/

#define PERIPHERAL_EN_TIM1  				 0
#define PERIPHERAL_EN_TIM8					 1
#define PERIPHERAL_EN_USART1				 4
#define PERIPHERAL_EN_USART6				 5
#define PERIPHERAL_EN_ADC1					 8
#define PERIPHERAL_EN_ADC2					 9
#define PERIPHERAL_EN_ADC3					 10
#define PERIPHERAL_EN_SDIO					 11
#define PERIPHERAL_EN_SPI1					 12
#define PERIPHERAL_EN_SYSCFG				 14
#define PERIPHERAL_EN_TIM9					 16
#define PERIPHERAL_EN_TIM10					 17
#define PERIPHERAL_EN_TIM11 				 18

void MRCC_init(void);
void MRCC_EnablePeripheralClock(BusName_t BusName , u8 Perphiral_Name);
void MRCC_DisablePeripheralClock(BusName_t BusName , u8 Perphiral_Name);



#endif /* MCAL_MRCC_INTERFACE_H_ */
