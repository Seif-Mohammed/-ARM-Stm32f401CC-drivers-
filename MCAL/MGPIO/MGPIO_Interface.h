/*
 * MGPIO_Interface.h
 *
 *  Created on: Aug 10, 2023
 *      Author: seifm
 */

#ifndef MCAL_MGPIO_INTERFACE_H_
#define MCAL_MGPIO_INTERFACE_H_

#define MGPIO_PORTA		0
#define MGPIO_PORTB 		1
#define MGPIO_PORTC 		2

#define MGPIO_PIN_0        		   0
#define MGPIO_PIN_1        		   1
#define MGPIO_PIN_2        		   2
#define MGPIO_PIN_3        		   3
#define MGPIO_PIN_4        		   4
#define MGPIO_PIN_5        		   5
#define MGPIO_PIN_6        		   6
#define MGPIO_PIN_7        		   7
#define MGPIO_PIN_8        		   8
#define MGPIO_PIN_9        		   9
#define MGPIO_PIN_10       		   10
#define MGPIO_PIN_11       		   11
#define MGPIO_PIN_12       		   12
#define MGPIO_PIN_13       		   13
#define MGPIO_PIN_14       		   14
#define MGPIO_PIN_15       		   15
/*****************************  Pin Mode *****************************/
#define MGPIO_MODE_INPUT     	 (0b00)
#define MGPIO_MODE_OUTPUT    	 (0b01)
#define MGPIO_MODE_ALTFN     	 (0b10)
#define MGPIO_MODE_ANALOG    	 (0b11)
/*****************************  Output type *****************************/

#define MGPIO_NO_PULL 	0b00
#define MGPIO_PULL_UP 	0b01
#define MGPIO_PULL_DOWN 	0b10

#define MGPIO_HIGH 	1
#define MGPIO_LOW 	0

// OSPEEDR values
#define MGPIO_LOW_SPEED 		0b00
#define MGPIO_MEDIUM_SPEED 	0b01
#define MGPIO_HIGH_SPEED 	0b10
#define MGPIO_ULTRA_SPEED  	0b11

#define MGPIO_OpenDrain 1
#define MGPIO_PUSHPULL 0
/**************************************************************/
#define MGPIO_ALTFN_0           0b0000
#define MGPIO_ALTFN_1           0b0001
#define MGPIO_ALTFN_2           0b0010
#define MGPIO_ALTFN_3           0b0011
#define MGPIO_ALTFN_4           0b0100
#define MGPIO_ALTFN_5           0b0101
#define MGPIO_ALTFN_6           0b0110
#define MGPIO_ALTFN_7           0b0111
#define MGPIO_ALTFN_8           0b1000
#define MGPIO_ALTFN_9           0b1001
#define MGPIO_ALTFN_10          0b1010
#define MGPIO_ALTFN_11          0b1011
#define MGPIO_ALTFN_12          0b1100
#define MGPIO_ALTFN_13          0b1101
#define MGPIO_ALTFN_14          0b1110
#define MGPIO_ALTFN_15          0b1111

void MGPIO_SetPinMode(u8 PortID , u8 PinNO , u8 PinModer);
void MGPIO_SetOutputType(u8 PortID , u8 PinNO , u8 OutputType /*push pull OR open drain*/);
void MGPIO_SetPinOutputSpeed(u8 PortID , u8 PinNO , u8 PinSpeed);
void MGPIO_SetPinInputPullType(u8 PortID , u8 PinNO , u8 PinPull);
void MGPIO_GetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 *Copy_PinValue);
void MGPIO_SetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Value);
void MGPIO_Fastset(u8 Copy_u8PortID,u8 Copy_pinID);
void MGPIO_PinLock(u8 Copy_u8PortNum ,u8 Copy_u8PinNum );
void MGPIO_SetPortValue(u8 Copy_u8PortID,u16 Copy_u8Value);
u16 MGPIO_GetPortValue(u8 Copy_u8PortID);
void MGPIO_SetAltFunction(u8 Copy_u8PortID,u8 Copy_PinID,u8 Copy_FuncID);


#endif /* MCAL_MGPIO_INTERFACE_H_ */
