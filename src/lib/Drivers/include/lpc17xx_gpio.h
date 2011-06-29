/***********************************************************************//**
 * @file	: lpc17xx_gpio.h
 * @brief	: Contains all macro definitions and function prototypes
 * 				support for GPIO firmware library on LPC17xx
 * @version	: 1.0
 * @date	: 23. Apr. 2009
 * @author	: HieuNguyen
 **************************************************************************
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * products. This software is supplied "AS IS" without any warranties.
 * NXP Semiconductors assumes no responsibility or liability for the
 * use of the software, conveys no license or title under any patent,
 * copyright, or mask work right to the product. NXP Semiconductors
 * reserves the right to make changes in the software without
 * notification. NXP Semiconductors also make no representation or
 * warranty that such application will be suitable for the specified
 * use without further testing or modification.
 **************************************************************************/

#ifndef LPC17XX_GPIO_H_
#define LPC17XX_GPIO_H_

#include "LPC17xx.h"
#include "lpc_types.h"


#ifdef __cplusplus
extern "C"
{
#endif


/**************************** GLOBAL/PUBLIC TYPES ***************************/
/** @addtogroup PUBLIC_TYPES
 * @{
 */

/** @defgroup GPIO_TYPES
 * @{
 */

/**
 * @brief Fast GPIO port byte type definition
 */
typedef struct {
	__IO uint8_t FIODIR[4];		/**< FIO direction register in byte-align */
	   uint32_t RESERVED0[3];	/**< Reserved */
	__IO uint8_t FIOMASK[4];	/**< FIO mask register in byte-align */
	__IO uint8_t FIOPIN[4];		/**< FIO pin register in byte align */
	__IO uint8_t FIOSET[4];		/**< FIO set register in byte-align */
	__O  uint8_t FIOCLR[4];		/**< FIO clear register in byte-align */
} GPIO_Byte_TypeDef;


/*
 * @brief Fast GPIO port half-word type definition
 */
typedef struct {
	__IO uint16_t FIODIRL;		/**< FIO direction register lower halfword part */
	__IO uint16_t FIODIRU;		/**< FIO direction register upper halfword part */
	   uint32_t RESERVED0[3];	/**< Reserved */
	__IO uint16_t FIOMASKL;		/**< FIO mask register lower halfword part */
	__IO uint16_t FIOMASKU;		/**< FIO mask register upper halfword part */
	__IO uint16_t FIOPINL;		/**< FIO pin register lower halfword part */
	__IO uint16_t FIOPINU;		/**< FIO pin register upper halfword part */
	__IO uint16_t FIOSETL;		/**< FIO set register lower halfword part */
	__IO uint16_t FIOSETU;		/**< FIO set register upper halfword part */
	__O  uint16_t FIOCLRL;		/**< FIO clear register lower halfword part */
	__O  uint16_t FIOCLRU;		/**< FIO clear register upper halfword part */
} GPIO_HalfWord_TypeDef;


/**
 * @}
 */

/**
 * @}
 */
/*************************** GLOBAL/PUBLIC MACROS ***************************/
/** @addtogroup PUBLIC_MACROS
 * @{
 */
/** @defgroup GPIO_MACROS
 * @{
 */

/** Fast GPIO port 0 byte accessible definition */
#define GPIO0_Byte	((GPIO_Byte_TypeDef *)(GPIO0))
/** Fast GPIO port 1 byte accessible definition */
#define GPIO1_Byte	((GPIO_Byte_TypeDef *)(GPIO1))
/** Fast GPIO port 2 byte accessible definition */
#define GPIO2_Byte	((GPIO_Byte_TypeDef *)(GPIO2))
/** Fast GPIO port 3 byte accessible definition */
#define GPIO3_Byte	((GPIO_Byte_TypeDef *)(GPIO3))
/** Fast GPIO port 4 byte accessible definition */
#define GPIO4_Byte	((GPIO_Byte_TypeDef *)(GPIO4))



/** Fast GPIO port 0 half-word accessible definition */
#define GPIO0_HalfWord	((GPIO_HalfWord_TypeDef *)(GPIO0))
/** Fast GPIO port 1 half-word accessible definition */
#define GPIO1_HalfWord	((GPIO_HalfWord_TypeDef *)(GPIO1))
/** Fast GPIO port 2 half-word accessible definition */
#define GPIO2_HalfWord	((GPIO_HalfWord_TypeDef *)(GPIO2))
/** Fast GPIO port 3 half-word accessible definition */
#define GPIO3_HalfWord	((GPIO_HalfWord_TypeDef *)(GPIO3))
/** Fast GPIO port 4 half-word accessible definition */
#define GPIO4_HalfWord	((GPIO_HalfWord_TypeDef *)(GPIO4))

/**
 * @}
 */

/**
 * @}
 */


/************************** GLOBAL/PUBLIC FUNCTIONS *************************/

/**
 * @addtogroup PUBLIC_FUNCTION_PROTOTYPES
 * @{
 */

/** @defgroup GPIO_FUNCTIONS
 * @{
 */

/* GPIO style ------------------------------- */
void GPIO_SetDir(uint8_t portNum, uint32_t bitValue, uint8_t dir);
void GPIO_SetValue(uint8_t portNum, uint32_t bitValue);
void GPIO_ClearValue(uint8_t portNum, uint32_t bitValue);
uint32_t GPIO_ReadValue(uint8_t portNum);

/* FIO (word-accessible) style ------------------------------- */
void FIO_SetDir(uint8_t portNum, uint32_t bitValue, uint8_t dir);
void FIO_SetValue(uint8_t portNum, uint32_t bitValue);
void FIO_ClearValue(uint8_t portNum, uint32_t bitValue);
uint32_t FIO_ReadValue(uint8_t portNum);
void FIO_SetMask(uint8_t portNum, uint32_t bitValue, uint8_t maskValue);

/* FIO (halfword-accessible) style ------------------------------- */
void FIO_HalfWordSetDir(uint8_t portNum, uint8_t halfwordNum, uint16_t bitValue, uint8_t dir);
void FIO_HalfWordSetMask(uint8_t portNum, uint8_t halfwordNum, uint16_t bitValue, uint8_t maskValue);
void FIO_HalfWordSetValue(uint8_t portNum, uint8_t halfwordNum, uint16_t bitValue);
void FIO_HalfWordClearValue(uint8_t portNum, uint8_t halfwordNum, uint16_t bitValue);
uint16_t FIO_HalfWordReadValue(uint8_t portNum, uint8_t halfwordNum);

/* FIO (byte-accessible) style ------------------------------- */
void FIO_ByteSetDir(uint8_t portNum, uint8_t byteNum, uint8_t bitValue, uint8_t dir);
void FIO_ByteSetMask(uint8_t portNum, uint8_t byteNum, uint8_t bitValue, uint8_t maskValue);
void FIO_ByteSetValue(uint8_t portNum, uint8_t byteNum, uint8_t bitValue);
void FIO_ByteClearValue(uint8_t portNum, uint8_t byteNum, uint8_t bitValue);
uint8_t FIO_ByteReadValue(uint8_t portNum, uint8_t byteNum);



/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* LPC17XX_GPIO_H_ */
