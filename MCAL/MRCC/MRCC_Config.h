/*
 * RCC_Config.h
 *
 *  Created on: Aug 10, 2023
 *      Author: seifm
 */

#ifndef MCAL_MRCC_CONFIG_H_
#define MCAL_MRCC_CONFIG_H_



	/*- CLKSRC option :
			         1) HSI
			         2) HSE
			         3) PLL
*/
       #define CLKSRC  HSE
/*
   - HSE option :
                 1)_HSE_CRYSTAL
                 2)_HSE_RC
*/

       #define HSE_SRC  _HSE_CRYSTAL
/*
   - PLL option :
	            1) _HSE_PLL
                2) _HSI_PLL
 */
      #define PLL_SRC   _HSE_PLL


#endif /* MCAL_MRCC_CONFIG_H_ */
