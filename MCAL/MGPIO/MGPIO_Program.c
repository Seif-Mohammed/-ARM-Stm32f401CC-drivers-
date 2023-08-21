#include "../LIB/STD_Types.h"
#include "../LIB/BIT_Math.h"
#include "../MCAL/MGPIO_Interface.h"
#include "../MCAL/MGPIO_Private.h"


void MGPIO_SetPinMode(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 PinModer){
	switch(Copy_u8PortID)
	{
	  case MGPIO_PORTA : GPIOA->MODER |= (u32) ( PinModer << ( 2U* Copy_u8PinID )) ; break;
	  case MGPIO_PORTB : GPIOB->MODER |= (u32) ( PinModer << ( 2U* Copy_u8PinID )) ; break;
	  case MGPIO_PORTC : GPIOC->MODER |= (u32) ( PinModer << ( 2U* Copy_u8PinID )) ; break;
	  default : /*ERROR*/ break ;
    }

}

void MGPIO_SetOutputType(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Type){
	switch(Copy_u8PortID)
	{
	  case MGPIO_PORTA :GPIOA->OTYPER |= (u32) ( Copy_u8Type << ( Copy_u8PinID )) ; break;
	  case MGPIO_PORTB: GPIOB->OTYPER |= (u32) ( Copy_u8Type << ( Copy_u8PinID )) ; break;
	  case MGPIO_PORTC :GPIOC->OTYPER |= (u32) ( Copy_u8Type << ( Copy_u8PinID )) ; break;
	  default : /*ERROR*/ break ;
     }
}

void MGPIO_SetPinOutputSpeed(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8SPEED){
	switch(Copy_u8PortID)
	{
	  case MGPIO_PORTA : GPIOA->OSPEEDR |= (u32) ( Copy_u8SPEED << ( 2U* Copy_u8PinID )) ; break;
	  case MGPIO_PORTB : GPIOB->OSPEEDR |= (u32) ( Copy_u8SPEED << ( 2U* Copy_u8PinID )) ; break;
	  case MGPIO_PORTC : GPIOC->OSPEEDR |= (u32) ( Copy_u8SPEED << ( 2U* Copy_u8PinID )) ; break;
	  default : /*ERROR*/ break ;
	}
}

void MGPIO_SetPinInputPullType(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Type){
	switch(Copy_u8PortID)
	{
		case MGPIO_PORTA : GPIOA->PUPDR |= (u32) ( Copy_u8Type << ( 2U* Copy_u8PinID )) ; break;
		case MGPIO_PORTB : GPIOB->PUPDR |= (u32) ( Copy_u8Type << ( 2U* Copy_u8PinID )) ; break;
		case MGPIO_PORTC : GPIOC->PUPDR |= (u32) ( Copy_u8Type << ( 2U* Copy_u8PinID )) ; break;
		default : /*ERROR*/ break ;
	}

}

void MGPIO_GetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 *Copy_PinValue){
	    u8 PinValue=0;
		switch(Copy_u8PortID){
		case MGPIO_PORTA:
		PinValue = GET_BIT(GPIOA->IDR,Copy_u8PinID);
			     break;
		case MGPIO_PORTB:
			PinValue=GET_BIT(GPIOB -> IDR,Copy_u8PinID );
			     break;
		case MGPIO_PORTC:
			PinValue=GET_BIT(GPIOC -> IDR,Copy_u8PinID );
			     break;
		}
		*Copy_PinValue = PinValue ;
}

void MGPIO_SetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Value){
	if(Copy_u8Value == MGPIO_HIGH){
		switch(Copy_u8PortID){
		case MGPIO_PORTA:
			SET_BIT(GPIOA -> ODR,Copy_u8PinID );
			     break;
		case MGPIO_PORTB:
			SET_BIT(GPIOB -> ODR,Copy_u8PinID );
			     break;
		case MGPIO_PORTC:
			SET_BIT(GPIOC -> ODR,Copy_u8PinID );
			     break;
		}
	}
	if(Copy_u8Value == MGPIO_LOW){
		switch(Copy_u8PortID){
		case MGPIO_PORTA:
			CLR_BIT(GPIOA -> ODR,Copy_u8PinID );
			     break;
		case MGPIO_PORTB:
			CLR_BIT(GPIOB -> ODR,Copy_u8PinID );
			     break;
		case MGPIO_PORTC:
			CLR_BIT(GPIOC -> ODR,Copy_u8PinID );
			     break;
		}
	}

}

void MGPIO_SetPortValue(u8 Copy_u8PortID,u16 Copy_u8Value){
	if(Copy_u8Value == MGPIO_HIGH){
			switch(Copy_u8PortID){
			case MGPIO_PORTA:
				GPIOA->ODR=0xFFFF;
				     break;
			case MGPIO_PORTB:
				GPIOB->ODR=0xFFFF;
				     break;
			case MGPIO_PORTC:
				GPIOC->ODR=0xFFFF;
				     break;
			}
		}
		if(Copy_u8Value == MGPIO_LOW){
			switch(Copy_u8PortID){
			case MGPIO_PORTA:
				GPIOA->ODR=0;
				     break;
			case MGPIO_PORTB:
				GPIOA->ODR=0;
				     break;
			case MGPIO_PORTC:
				GPIOA->ODR=0;
				     break;
			}
		}
}

u16 MGPIO_u16GetPortValue(u8 Copy_u8PortID){
	u16 PortValue=0;
	switch(Copy_u8PortID){
		case MGPIO_PORTA:
		PortValue = GPIOA->IDR;
			     break;
		case MGPIO_PORTB:
			PortValue = GPIOB->IDR;
			     break;
		case MGPIO_PORTC:
			PortValue = GPIOC->IDR;
			     break;
		}
	return PortValue;
}

void MGPIO_SetPortMode(u8 Copy_u8PortID,u8 Copy_u8Mode){
	if(Copy_u8Mode == MGPIO_MODE_INPUT){
			switch(Copy_u8PortID){
			case MGPIO_PORTA:
				GPIOA->MODER=0;
				     break;
			case MGPIO_PORTB:
				GPIOA->MODER=0;
				break;
			case MGPIO_PORTC:
				GPIOA->MODER=0;
				     break;

			}
		}
			if(Copy_u8Mode == MGPIO_MODE_OUTPUT){
				for(u8 pinID=0;pinID<=16;pinID++){
					MGPIO_vSetPinMode(Copy_u8PortID,pinID,Copy_u8Mode);
				}
		}
			if(Copy_u8Mode == MGPIO_MODE_ANALOG){
				switch(Copy_u8PortID){
				case MGPIO_PORTA:
					GPIOA->MODER=0xFFFFFFFF;
					     break;
				case MGPIO_PORTB:
					GPIOB->MODER=0xFFFFFFFF;
					     break;
				case MGPIO_PORTC:
					GPIOC->MODER=0xFFFFFFFF;
					     break;

				}
			}
			if(Copy_u8Mode == MGPIO_MODE_ALTFN){
				for(u8 pinID=0;pinID<=16;pinID++){
					MGPIO_vSetPinMode(Copy_u8PortID,pinID,Copy_u8Mode);
				}
			}

}

void MGPIO_SetAltFunction(u8 Copy_u8PortID,u8 Copy_PinID,u8 Copy_FuncID){
	u8 index = 0;
	if(Copy_PinID <= 7){
		switch(Copy_u8PortID){
		case MGPIO_PORTA:
			GPIOA-> AFRL &=~(0b11 << (Copy_PinID *4));
			GPIOA -> AFRL |= (Copy_FuncID <<(Copy_PinID *4));
			     break;
		case MGPIO_PORTB:
			GPIOB-> AFRL &=~(0b11 << (Copy_PinID *4));
			GPIOB -> AFRL |= (Copy_FuncID <<(Copy_PinID *4));
			     break;
		case MGPIO_PORTC:
			GPIOC-> AFRL &=~(0b11 << (Copy_PinID *4));
			GPIOC -> AFRL |= (Copy_FuncID <<(Copy_PinID *4));
			     break;

		}
	}else{
		switch(Copy_u8PortID){
		case MGPIO_PORTA:
			GPIOA-> AFRH &=~(0b11 << (Copy_PinID *4));
			GPIOA -> AFRH |= (Copy_FuncID <<((Copy_PinID-8) *4));
			     break;
		case MGPIO_PORTB:
			GPIOB-> AFRH &=~(0b11 << (Copy_PinID *4));
			GPIOB -> AFRH |= (Copy_FuncID <<((Copy_PinID-8) *4));
			     break;
		case MGPIO_PORTC:
			GPIOC-> AFRH &=~(0b11 << (Copy_PinID *4));
			GPIOC -> AFRH |= (Copy_FuncID <<((Copy_PinID-8) *4));
			     break;

		}

	}
}

void MGPIO_Fastset(u8 Copy_u8PortID,u8 Copy_pinID){
	switch(Copy_u8PortID){
	case MGPIO_PORTA:
		SET_BIT(GPIOA->BSRR,Copy_pinID);
		     break;
	case MGPIO_PORTB:
		SET_BIT(GPIOB->BSRR,Copy_pinID);
		     break;
	case MGPIO_PORTC:
		SET_BIT(GPIOC->BSRR,Copy_pinID);
		     break;

	}
}
