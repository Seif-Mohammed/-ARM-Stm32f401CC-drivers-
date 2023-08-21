#include "../LIB/STD_Types.h"
#include "../LIB/BIT_Math.h"
#include "../MCAL/MEXTI_Private.h"
#include "../MCAL/MEXTI_Interface.h"

static void(*MEXTI_PF0)(void) = STD_TYPE_NULL;
static void(*MEXTI_PF1)(void) = STD_TYPE_NULL;

void MEXTI_Enable(u8 Copy_u8EXTI_Num ){
	switch(Copy_u8EXTI_Num){
	case MEXTI_InterruptLine0:
		SET_BIT(MEXTI -> EXTI_IMR , 0);
		break;
	case MEXTI_InterruptLine1:
		SET_BIT(MEXTI -> EXTI_IMR , 1);
		break;
	case MEXTI_InterruptLine2:
		SET_BIT(MEXTI -> EXTI_IMR , 2);
		break;
	case MEXTI_InterruptLine3:
		SET_BIT(MEXTI -> EXTI_IMR , 3);
		break;
	case MEXTI_InterruptLine4:
		SET_BIT(MEXTI -> EXTI_IMR , 4);
		break;
	case MEXTI_InterruptLine5:
		SET_BIT(MEXTI -> EXTI_IMR , 5);
		break;
	case MEXTI_InterruptLine6:
		SET_BIT(MEXTI -> EXTI_IMR , 6);
		break;
	case MEXTI_InterruptLine7:
		SET_BIT(MEXTI -> EXTI_IMR , 7);
		break;
	case MEXTI_InterruptLine8:
		SET_BIT(MEXTI -> EXTI_IMR , 8);
		break;
	case MEXTI_InterruptLine9:
		SET_BIT(MEXTI -> EXTI_IMR , 9);
		break;
	case MEXTI_InterruptLine10:
		SET_BIT(MEXTI -> EXTI_IMR , 10);
		break;
	case MEXTI_InterruptLine11:
		SET_BIT(MEXTI -> EXTI_IMR , 11);
		break;
	case MEXTI_InterruptLine12:
		SET_BIT(MEXTI -> EXTI_IMR , 12);
		break;
	case MEXTI_InterruptLine13:
		SET_BIT(MEXTI -> EXTI_IMR , 13);
		break;
	case MEXTI_InterruptLine14:
		SET_BIT(MEXTI -> EXTI_IMR , 14);
		break;
	case MEXTI_InterruptLine15:
		SET_BIT(MEXTI -> EXTI_IMR , 15);
		break;
	default:
		break;

}
}

void MEXTI_DisableEXTI(u8 Copy_u8EXTI_Num){
	switch(Copy_u8EXTI_Num){
	case MEXTI_InterruptLine0:
		CLR_BIT(MEXTI -> EXTI_IMR , 0);
		break;
	case MEXTI_InterruptLine1:
		CLR_BIT(MEXTI -> EXTI_IMR , 1);
		break;
	case MEXTI_InterruptLine2:
		CLR_BIT(MEXTI -> EXTI_IMR , 2);
		break;
	case MEXTI_InterruptLine3:
		CLR_BIT(MEXTI -> EXTI_IMR , 3);
		break;
	case MEXTI_InterruptLine4:
		CLR_BIT(MEXTI -> EXTI_IMR , 4);
		break;
	case MEXTI_InterruptLine5:
		CLR_BIT(MEXTI -> EXTI_IMR , 5);
		break;
	case MEXTI_InterruptLine6:
		CLR_BIT(MEXTI -> EXTI_IMR , 6);
		break;
	case MEXTI_InterruptLine7:
		CLR_BIT(MEXTI -> EXTI_IMR , 7);
		break;
	case MEXTI_InterruptLine8:
		CLR_BIT(MEXTI -> EXTI_IMR , 8);
		break;
	case MEXTI_InterruptLine9:
		CLR_BIT(MEXTI -> EXTI_IMR , 9);
		break;
	case MEXTI_InterruptLine10:
		CLR_BIT(MEXTI -> EXTI_IMR , 10);
		break;
	case MEXTI_InterruptLine11:
		CLR_BIT(MEXTI -> EXTI_IMR , 11);
		break;
	case MEXTI_InterruptLine12:
		CLR_BIT(MEXTI -> EXTI_IMR , 12);
		break;
	case MEXTI_InterruptLine13:
		CLR_BIT(MEXTI -> EXTI_IMR , 13);
		break;
	case MEXTI_InterruptLine14:
		CLR_BIT(MEXTI -> EXTI_IMR , 14);
		break;
	case MEXTI_InterruptLine15:
		CLR_BIT(MEXTI -> EXTI_IMR , 15);
		break;
	default:
		break;
}
}

void MEXTI_Enable_SoftwareEXTI(u8 InterruptNumber){
	MEXTI -> EXTI_RTSR |= (1<<InterruptNumber); // It will Be Clear Alone
}

void MEXTI_TriggerSelect(u8 InterruptNumber,u8 Copy_SelectTrigger){
	if (Copy_SelectTrigger == MEXTI_U8_RisingEdge_Source	)					// Notic In Rising

		SET_BIT( MEXTI -> EXTI_RTSR, InterruptNumber );

	else if (Copy_SelectTrigger == MEXTI_U8_FallingEdge_Source)						// Notic In Falling

		SET_BIT( MEXTI -> EXTI_FTSR, InterruptNumber );

	else if( Copy_SelectTrigger == MEXTI_U8_AnyChange_Source)	{					// Any Logical Change

		SET_BIT( MEXTI -> EXTI_FTSR, InterruptNumber );
		SET_BIT( MEXTI -> EXTI_RTSR, InterruptNumber );
	}
}

void MEXTI_U8_SetCallBack(u8 InterruptNumber , void(*Copy_PF)(void)){
	if(Copy_PF != STD_TYPE_NULL && InterruptNumber <= MEXTI_InterruptLine15){
		switch(InterruptNumber){
		case MEXTI_InterruptLine0:
			MEXTI_PF0 = Copy_PF;
			break;
		case MEXTI_InterruptLine1:
			MEXTI_PF1 = Copy_PF;
			break;
		default:
			break;
		}
	}
}

void IQHandler_EXTI0(void){
	MEXTI_PF0();
	SET_BIT(MEXTI -> EXTI_PR , 0);
}
void IQHandler_EXTI1(void){
	MEXTI_PF1();
	SET_BIT(MEXTI -> EXTI_PR , 1);
}

void Set_EXTIConfig(u8 InterruptNumber , u8 GPIO_PortNo){
	switch(InterruptNumber){
	case MEXTI_InterruptLine0:
		MSYSCFG_EXTICR1 &= EXTIConfigMask1;  /*Clear the EXTI0 bits*/
		MSYSCFG_EXTICR1 |= GPIO_PortNo; /*therefore the chosen pin in Px[0] */
		break;
	case MEXTI_InterruptLine1:
			MSYSCFG_EXTICR1 &= EXTIConfigMask2;
			MSYSCFG_EXTICR1 |= GPIO_PortNo;/*therefore the chosen pin in Px[1] */
			break;
	default:
		break;
	}
}

