#ifndef MCAL_RCC_PRIVATE_H_
#define MCAL_RCC_PRIVATE_H_

#define RCC_BaseAddress 	0x40023800
typedef struct
{
  u32 CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
  u32 PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
  u32 CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
  u32 CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
  u32 AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
  u32 AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
  u32 RESERVED0;     /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
  u32 RESERVED1;     /*!< Reserved, 0x1C                                                                    */
  u32 APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
  u32 APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
  u32 RESERVED2[2];  /*!< Reserved, 0x28-0x2C                                                               */
  u32 AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
  u32 AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
  u32 RESERVED3;     /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
  u32 RESERVED4;     /*!< Reserved, 0x3C                                                                    */
  u32 APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
  u32 APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
  u32 RESERVED5[2];  /*!< Reserved, 0x48-0x4C                                                               */
  u32 AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
  u32 AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
  u32 RESERVED6;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
  u32 RESERVED7;     /*!< Reserved, 0x5C                                                                    */
  u32 APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
  u32 APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
  u32 RESERVED8[2];  /*!< Reserved, 0x68-0x6C                                                               */
  u32 BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
  u32 CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
  u32 RESERVED9[2];  /*!< Reserved, 0x78-0x7C                                                               */
  u32 SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
  u32 PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
  u32 RESERVED10[1]; /*!< Reserved, 0x88                                                                    */
  u32 DCKCFGR;       /*!< RCC Dedicated Clocks configuration register,                 Address offset: 0x8C */
}RCC;

#define MRCC	((volatile RCC*)RCC_BaseAddress)
#define HSEON 	16
#define HSEBYP 	18
#define HSEON 	16
#define CSSON 	19
#define SW0		0


#endif
