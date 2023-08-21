#include "../src/LIB/BIT_Math.h"
#include "../src/LIB/Std_types.h"
#include "MCAL/MGPIO_Interface.h"
#include "MCAL/MRCC_Interface.h"
#include "MCAL/MSYSTICK_Interface.h"
#include "MCAL/MNVIC_Interface.h"
#include "MCAL/MEXTI_Interface.h"

void ISR(void){
	MGPIO_SetPinValue(MGPIO_PORTA,1,MGPIO_LOW);
	MGPIO_SetPinValue(MGPIO_PORTA,2,MGPIO_LOW);
	MGPIO_SetPinValue(MGPIO_PORTA,3,MGPIO_HIGH);
	MSYSTICK_DelayMs(5000); // so passengers can pass
}

int main(void)
{	/********Initializations********/
	MRCC_init();
	MRCC_EnablePeripheralClock( AHB1 , MRCC_PERIPHERAL_EN_GPIOA );
	MRCC_EnablePeripheralClock( APB2 , MRCC_PERIPHERAL_EN_SYSCFG);
	MNVIC_EnableInterrupt(EXTI0_IRQ);
	MEXTI_EnableEXTI(MEXTI_InterruptLine0);
	MEXTI_TriggerSelect(MEXTI_InterruptLine0 , MEXTI_U8_RisingEdge_Source);
	Set_EXTIConfig( MEXTI_InterruptLine0 , MGPIO_PORTA );
	MEXTI_TriggerSelect(MEXTI_InterruptLine0 , MEXTI_U8_RisingEdge_Source);
	MEXTI_SetCallBack(MEXTI_InterruptLine0 , &ISR);
	/*********GPIO PIN Configurations**********/
	MGPIO_SetOutputType(MGPIO_PORTA , MGPIO_PIN_1 , MGPIO_PUSHPULL );
	MGPIO_SetOutputType(MGPIO_PORTA , MGPIO_PIN_2 , MGPIO_PUSHPULL );
	MGPIO_SetOutputType(MGPIO_PORTA , MGPIO_PIN_3 , MGPIO_PUSHPULL );
	MGPIO_SetPinMode(MGPIO_PORTA, MGPIO_PIN_0, MGPIO_MODE_INPUT);
	MGPIO_SetPinMode(MGPIO_PORTA, MGPIO_PIN_1, MGPIO_MODE_OUTPUT);
	MGPIO_SetPinMode(MGPIO_PORTA, MGPIO_PIN_2, MGPIO_MODE_OUTPUT);
	MGPIO_SetPinMode(MGPIO_PORTA, MGPIO_PIN_3, MGPIO_MODE_OUTPUT);

	while(1)
	{
		MGPIO_SetPinValue(MGPIO_PORTA,1,MGPIO_HIGH);
		MGPIO_SetPinValue(MGPIO_PORTA,2,MGPIO_LOW);
		MGPIO_SetPinValue(MGPIO_PORTA,3,MGPIO_LOW);
		MSYSTICK_DelayMs(5000);
		for (u8 i = 0; i < 3; ++i) {
			MGPIO_SetPinValue(MGPIO_PORTA,2,MGPIO_HIGH);
			MSYSTICK_DelayMs(500);
			MGPIO_SetPinValue(MGPIO_PORTA,2,MGPIO_LOW);
			MSYSTICK_DelayMs(500);
		}
		MGPIO_SetPinValue(MGPIO_PORTA,3,MGPIO_HIGH);
		MGPIO_SetPinValue(MGPIO_PORTA,1,MGPIO_LOW);
		MGPIO_SetPinValue(MGPIO_PORTA,2,MGPIO_LOW);
		MSYSTICK_DelayMs(5000);
	}
	return 0;
}

/*int main(void)
{


	MRCC_init();
	MRCC_EnableClock( GPIOA_EN );
	MGPIO_SetOutputType(GPIO_PORTA , _PIN_0 , GPIO_PUSHPULL );
	MGPIO_SetPinOutputSpeed(GPIO_PORTA , _PIN_0 , GPIO_LOW_SPEED);
	MGPIO_SetPinMode(GPIO_PORTA, _PIN_0,GPIO_MODE_OUTPUT);

	while(1)
	{
		MGPIO_SetPinValue(GPIO_PORTB,1,GPIO_HIGH);

	}
	return 0;
}
*/
