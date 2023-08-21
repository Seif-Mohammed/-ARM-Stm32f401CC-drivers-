#include "../LIB/STD_Types.h"
#include "../LIB/BIT_Math.h"
#include "MRCC_Config.h"
#include "MRCC_Interface.h"
#include "MRCC_Private.h"
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

void MRCC_EnablePeripheralClock(BusName_t BusName , u8 Perphiral_Name){
	switch(BusName)
		{
			case AHB1_BUS:  SET_BIT(MRCC->AHB1ENR,Perphiral_Name );         break ;
			case AHB2_BUS:  SET_BIT(MRCC->AHB2ENR,Perphiral_Name );         break ;
			case APB1_BUS:  SET_BIT(MRCC->APB1ENR,Perphiral_Name );         break ;
			case APB2_BUS:  SET_BIT(MRCC->APB2ENR,Perphiral_Name );         break ;
			default :     /*   ERROR   */          break ;

		}
}
void MRCC_DisablePeripheralClock(BusName_t BusName , u8 Perphiral_Name){

	switch(BusName)
		{
			case AHB1_BUS:  CLR_BIT(MRCC->AHB1ENR,Perphiral_Name );         break ;
			case AHB2_BUS:  CLR_BIT(MRCC->AHB2ENR,Perphiral_Name );         break ;
			case APB1_BUS:  CLR_BIT(MRCC->APB1ENR,Perphiral_Name );         break ;
			case APB2_BUS:  CLR_BIT(MRCC->APB2ENR,Perphiral_Name );         break ;
			default :     /* ERROR */          break ;
		}
}

void MRCC_voidEnableSecuritySystem(void){
	SET_BIT( MRCC -> CR  , CSSON);
}

void MRCC_voidDisableSecuritySystem(void){
	CLR_BIT( MRCC -> CR  , CSSON);
}
