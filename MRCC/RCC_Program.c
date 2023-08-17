#include "../LIB/STD_Types.h"
#include "../LIB/BIT_Math.h"
#include "../MCAL/RCC_Interface.h"
#include "../MCAL/RCC_Config.h"
#include "../MCAL/RCC_Private.h"
void MRCC_init(void){
#if CLKSRC == HSI
	/* 1- EN HSI */
	SET_BIT(MRCC->CR , 0U);
	/* 2- CLK SYS --> HSI */
	CLR_BIT(MRCC->CFGR, 0U);
	CLR_BIT(MRCC->CFGR, 1U);
	/********** HSE **********/
#elif CLKSRC == HSE

	#if HSE_SRC == CRYSTAL
	/* 1- EN HSE */
		SET_BIT(MRCC->CR , 16U);
		/* 2- Disable BYP */
		CLR_BIT(MRCC->CR,18U);
		/* 3- CLK SYS --> HSE */
		SET_BIT(MRCC->CFGR, 0U);
		CLR_BIT(MRCC->CFGR, 1U);

	#elif HSE_SRC == RC
		/* 1- EN HSE */
		SET_BIT(MRCC->CR , 16U);
		/* 2- Enable BYP */
		SET_BIT(MRCC->CR,18U);
		/* 3- CLK SYS --> HSE */
		SET_BIT(MRCC->CFGR, 0U);
		CLR_BIT(MRCC->CFGR, 1U);
	#else
    /* Error*/
	#endif

	/********** PLL **********/
#elif CLKSRC == PLL

    #if PLL_SRC == _HSE_PLL
     /*1-Enable HSE */
			SET_BIT(MRCC->CR,16U);
			/* while ( GET_BIT(RCC_CR, 17)==0);*/
			/*2- EN PLL*/
			SET_BIT(MRCC->,24U);
			/* while ( GET_BIT(RCC_CR, 25)==0);*/
			/* 3- PLL From HSE */
			SET_BIT(MRCC->PLLCFGR, 22U);
			/* 4- System Clk  PLL */
			CLR_BIT(MRCC->CFGR,0U);
			SET_BIT(MRCC->CFGR,1U);

    #elif PLL_SRC == _HSI_PLL
            /*Enable HSI */
		     SET_BIT(MRCC->CR,0U);
			/*2- EN PLL*/
			SET_BIT(MRCC->CR,24U);
			/* 3- PLL From HSI */
			CLR_BIT(MRCC->PLLCFGR, 22U);
			/* 4- System Clk  PLL */
			CLR_BIT(MRCC->CFGR,0U);
			SET_BIT(MRCC->CFGR,1U);
    #else
            /* Error*/
	#endif
/****************************************************/

#else
					/* Error*/
#endif
}
void MRCC_EnableClock(u8 Perphiral_Name){
switch(Perphiral_Name){
case GPIOA:
	SET_BIT(MRCC -> AHB1ENR,0);
	break;
case GPIOB:
	SET_BIT(MRCC -> AHB1ENR,1);
	break;
case GPIOC:
	SET_BIT(MRCC -> AHB1ENR,2);
	break;
case GPIOD:
	SET_BIT(MRCC -> AHB1ENR,3);
	break;
case DMA2:
	SET_BIT(MRCC -> AHB1ENR,22);
	break;
case DMA1:
	SET_BIT(MRCC -> AHB1ENR,21);
	break;
case CRC:
	SET_BIT(MRCC -> AHB1ENR,12);
	break;
case WWDG:
	SET_BIT(MRCC -> APB1ENR,11);
	break;
case I2C3:
	SET_BIT(MRCC -> APB1ENR,23);
	break;
case I2C2:
	SET_BIT(MRCC -> APB1ENR,22);
	break;
case I2C1:
	SET_BIT(MRCC -> APB1ENR,21);
	break;
case USART6:
	SET_BIT(MRCC -> APB2ENR,5);
	break;
case USART2:
	SET_BIT(MRCC -> APB1ENR,17);
	break;
case USART1:
	SET_BIT(MRCC -> APB2ENR,4);
	break;
case SPI4:
	SET_BIT(MRCC -> APB2ENR,13);
	break;
case SPI3:
	SET_BIT(MRCC -> APB1ENR,15);
	break;
case SPI2:
	SET_BIT(MRCC -> APB1ENR,14);
	break;
case SPI1:
	SET_BIT(MRCC -> APB2ENR,12);
	break;
case TIM11:
	SET_BIT(MRCC -> APB2ENR,18);
	break;
case TIM10:
	SET_BIT(MRCC -> APB2ENR,17);
	break;
case TIM9:
	SET_BIT(MRCC -> APB2ENR,16);
	break;
case TIM5:
	SET_BIT(MRCC -> APB1ENR,3);
	break;
case TIM4:
	SET_BIT(MRCC -> APB1ENR,2);
	break;
case TIM3:
	SET_BIT(MRCC -> APB1ENR,1);
	break;
case TIM2:
	SET_BIT(MRCC -> APB1ENR,0);
	break;
case TIM1:
	SET_BIT(MRCC -> APB2ENR,0);
	break;
case ADC1:
	SET_BIT(MRCC -> APB2ENR,8);
	break;
default:
	break;
}
}
void MRCC_DisableClock(u8 Perphiral_Name){

switch(Perphiral_Name){
case GPIOA:
	CLR_BIT(MRCC -> AHB1ENR,0);
	break;
case GPIOB:
	CLR_BIT(MRCC -> AHB1ENR,1);
	break;
case GPIOC:
	CLR_BIT(MRCC -> AHB1ENR,2);
	break;
case GPIOD:
	CLR_BIT(MRCC -> AHB1ENR,3);
	break;
case DMA2:
	CLR_BIT(MRCC -> AHB1ENR,22);
	break;
case DMA1:
	CLR_BIT(MRCC -> AHB1ENR,21);
	break;
case CRC:
	CLR_BIT(MRCC -> AHB1ENR,12);
	break;
case WWDG:
	CLR_BIT(MRCC -> APB1ENR,11);
	break;
case I2C3:
	CLR_BIT(MRCC -> APB1ENR,23);
	break;
case I2C2:
	CLR_BIT(MRCC -> APB1ENR,22);
	break;
case I2C1:
	CLR_BIT(MRCC -> APB1ENR,21);
	break;
case USART6:
	CLR_BIT(MRCC -> APB2ENR,5);
	break;
case USART2:
	CLR_BIT(MRCC -> APB1ENR,17);
	break;
case USART1:
	CLR_BIT(MRCC -> APB2ENR,4);
	break;
case SPI4:
	CLR_BIT(MRCC -> APB2ENR,13);
	break;
case SPI3:
	CLR_BIT(MRCC -> APB1ENR,15);
	break;
case SPI2:
	CLR_BIT(MRCC -> APB1ENR,14);
	break;
case SPI1:
	CLR_BIT(MRCC -> APB2ENR,12);
	break;
case TIM11:
	CLR_BIT(MRCC -> APB2ENR,18);
	break;
case TIM10:
	CLR_BIT(MRCC -> APB2ENR,17);
	break;
case TIM9:
	CLR_BIT(MRCC -> APB2ENR,16);
	break;
case TIM5:
	CLR_BIT(MRCC -> APB1ENR,3);
	break;
case TIM4:
	CLR_BIT(MRCC -> APB1ENR,2);
	break;
case TIM3:
	CLR_BIT(MRCC -> APB1ENR,1);
	break;
case TIM2:
	CLR_BIT(MRCC -> APB1ENR,0);
	break;
case TIM1:
	CLR_BIT(MRCC -> APB2ENR,0);
	break;
case ADC1:
	CLR_BIT(MRCC -> APB2ENR,8);
	break;
default:
	break;
}
}
void MRCC_voidEnableSecuritySystem(void)
{
	SET_BIT( MRCC -> CR  , CSSON);
}
void MRCC_voidDisableSecuritySystem(void)
{
	CLR_BIT( MRCC -> CR  , CSSON);
}
