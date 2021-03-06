/**
 * @file	: lpc17xx_timer.h
 * @brief	: Contains all functions support for SPI firmware library on LPC17xx
 * @version	: 1.0
 * @date	: 14. April. 2009
 * @author	:
 * *----------------------------------------------------------------------------
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
 **********************************************************************/
#ifndef __LPC17XX_TIMER_H_
#define __LPC17XX_TIMER_H_

#include "LPC17xx.h"
#include "lpc_types.h"

/****************************** PRIVATE MACROS ******************************/
/** @addtogroup PRIVATE_MACROS
 * @{
 */


/** @defgroup TIM_PINSEL
 * @{
 */
/**Pin selection define */
/** Timer 0 - Capture input pin */
#define TIM0_PINSEL_CAP0_P1_26	{1, 26, 3, \
								PINSEL_PINMODE_PULLUP, \
								PINSEL_PINMODE_NORMAL}

#define TIM0_PINSEL_CAP1_P1_27	{1, 27, 3, \
								PINSEL_PINMODE_PULLUP, \
								PINSEL_PINMODE_NORMAL}


/** Timer 1 - Capture input pin */
#define TIM1_PINSEL_CAP0_P1_18	{1, 18, 3, \
								PINSEL_PINMODE_PULLUP, \
								PINSEL_PINMODE_NORMAL}

#define TIM1_PINSEL_CAP1_P1_19	{1, 19, 3, \
								PINSEL_PINMODE_PULLUP, \
								PINSEL_PINMODE_NORMAL}


/** Timer 2 - Capture input pin */
#define TIM2_PINSEL_CAP0_P0_4	{0, 4, 3, \
								PINSEL_PINMODE_PULLUP, \
								PINSEL_PINMODE_NORMAL}

#define TIM2_PINSEL_CAP1_P0_5	{0, 5, 3, \
								PINSEL_PINMODE_PULLUP, \
								PINSEL_PINMODE_NORMAL}


/** Timer 3 - Capture input pin */
#define TIM3_PINSEL_CAP0_P0_23	{0, 23, 3, \
								PINSEL_PINMODE_PULLUP, \
								PINSEL_PINMODE_NORMAL}

#define TIM3_PINSEL_CAP1_P0_24	{0, 24, 3, \
								PINSEL_PINMODE_PULLUP, \
								PINSEL_PINMODE_NORMAL}

/** Timer 0 - Match output pin */
#define TIM0_PINSEL_MAT0_P1_28	{1, 28, 3, \
								PINSEL_PINMODE_PULLUP, \
								PINSEL_PINMODE_NORMAL}

#define TIM0_PINSEL_MAT1_P1_29	{1, 29, 3, \
								PINSEL_PINMODE_PULLUP, \
								PINSEL_PINMODE_NORMAL}


/** Timer 1 - Match output pin */
#define TIM1_PINSEL_MAT0_P1_22	{1, 22, 3, \
								PINSEL_PINMODE_PULLUP, \
								PINSEL_PINMODE_NORMAL}

#define TIM1_PINSEL_MAT1_P1_23	{1, 23, 3, \
								PINSEL_PINMODE_PULLUP, \
								PINSEL_PINMODE_NORMAL}


/** Timer 2 - Match output pin */
#define TIM2_PINSEL_MAT0_P0_6	{0, 6, 3, \
								PINSEL_PINMODE_PULLUP, \
								PINSEL_PINMODE_NORMAL}

#define TIM2_PINSEL_MAT1_P0_7	{0, 7, 3, \
								PINSEL_PINMODE_PULLUP, \
								PINSEL_PINMODE_NORMAL}

#define TIM2_PINSEL_MAT2_P0_8	{0, 8, 3, \
								PINSEL_PINMODE_PULLUP, \
								PINSEL_PINMODE_NORMAL}

#define TIM2_PINSEL_MAT3_P0_9	{0, 9, 3, \
								PINSEL_PINMODE_PULLUP, \
								PINSEL_PINMODE_NORMAL}


/** Timer 3 - Match output pin */
#define TIM3_PINSEL_MAT0_P0_10	{0, 10, 3, \
								PINSEL_PINMODE_PULLUP, \
								PINSEL_PINMODE_NORMAL}

#define TIM3_PINSEL_MAT1_P0_11	{0, 11, 3, \
								PINSEL_PINMODE_PULLUP, \
								PINSEL_PINMODE_NORMAL}


/* Max number of pin on each pin function */
#define	TIMER_MAX_MATCH_PIN 10
#define	TIMER_MAX_CAPTION_PIN 8
/**
 * @}
 */

/************************** TIMER/COUNTER Control **************************/
/** @defgroup TIM_REGISTER_BIT_DEFINITION
 * @{
 */
/**********************************************************************
** Interrupt information
**********************************************************************/
/** Macro to clean interrupt pending */
#define TIM_IR_CLR(n) _BIT(n)

/**********************************************************************
** Timer interrupt register definitions
**********************************************************************/
/** Macro for getting a timer match interrupt bit */
#define TIM_MATCH_INT(n)		(_BIT(n & 0x0F))
/** Macro for getting a capture event interrupt bit */
#define TIM_CAP_INT(n)     (_BIT(((n & 0x0F) + 4)))

/**********************************************************************
* Timer control register definitions
**********************************************************************/
/** Timer/counter enable bit */
#define TIM_ENABLE			((uint32_t)(1<<0))
/** Timer/counter reset bit */
#define TIM_RESET			((uint32_t)(1<<1))
/** Timer control bit mask */
#define TIM_TCR_MASKBIT		((uint32_t)(3))

/**********************************************************************
* Timer match control register definitions
**********************************************************************/
/** Bit location for interrupt on MRx match, n = 0 to 3 */
#define TIM_INT_ON_MATCH(n)      	(_BIT((n * 3)))
/** Bit location for reset on MRx match, n = 0 to 3 */
#define TIM_RESET_ON_MATCH(n)    	(_BIT(((n * 3) + 1)))
/** Bit location for stop on MRx match, n = 0 to 3 */
#define TIM_STOP_ON_MATCH(n)     	(_BIT(((n * 3) + 2)))
/** Timer Match control bit mask */
#define TIM_MCR_MASKBIT			   ((uint32_t)(0x0FFF))
/** Timer Match control bit mask for specific channel*/
#define	TIM_MCR_CHANNEL_MASKBIT(n)		((uint32_t)(7<<n))
/**********************************************************************
* Timer capture control register definitions
**********************************************************************/
/** Bit location for CAP.n on CRx rising edge, n = 0 to 3 */
#define TIM_CAP_RISING(n)   	(_BIT((n * 3)))
/** Bit location for CAP.n on CRx falling edge, n = 0 to 3 */
#define TIM_CAP_FALLING(n)   	(_BIT(((n * 3) + 1)))
/** Bit location for CAP.n on CRx interrupt enable, n = 0 to 3 */
#define TIM_INT_ON_CAP(n)    	(_BIT(((n * 3) + 2)))
/** Mask bit for rising and falling edge bit */
#define TIM_EDGE_MASK(n)		(_SBF((n * 3), 0x03))
/** Timer capture control bit mask */
#define TIM_CCR_MASKBIT			((uint32_t)(0x3F))
/** Timer Capture control bit mask for specific channel*/
#define	TIM_CCR_CHANNEL_MASKBIT(n)		((uint32_t)(7<<n))

/**********************************************************************
* Timer external match register definitions
**********************************************************************/
/** Bit location for output state change of MAT.n when external match
   happens, n = 0 to 3 */
#define TIM_EM(n)    			_BIT(n)
/** Output state change of MAT.n when external match happens: no change */
#define TIM_EM_NOTHING    	((uint8_t)(0x0))
/** Output state change of MAT.n when external match happens: low */
#define TIM_EM_LOW         	((uint8_t)(0x1))
/** Output state change of MAT.n when external match happens: high */
#define TIM_EM_HIGH        	((uint8_t)(0x2))
/** Output state change of MAT.n when external match happens: toggle */
#define TIM_EM_TOGGLE      	((uint8_t)(0x3))
/** Macro for setting for the MAT.n change state bits */
#define TIM_EM_SET(n,s) 	(_SBF(((n << 1) + 4), (s & 0x03)))
/** Mask for the MAT.n change state bits */
#define TIM_EM_MASK(n) 		(_SBF(((n << 1) + 4), 0x03))
/** Timer external match bit mask */
#define TIM_EMR_MASKBIT	0x0FFF
/**********************************************************************
* Timer Count Control Register definitions
**********************************************************************/
/** Mask to get the Counter/timer mode bits */
#define TIM_CTCR_MODE_MASK  0x3
/** Mask to get the count input select bits */
#define TIM_CTCR_INPUT_MASK 0xC
/** Timer Count control bit mask */
#define TIM_CTCR_MASKBIT	0xF
#define TIM_COUNTER_MODE ((uint8_t)(1))

/**
 * @}
 */

/**
 * @}
 */
/**************************** GLOBAL/PUBLIC TYPES ***************************/
/** @addtogroup PUBLIC_TYPES
 * @{
 */

/** @defgroup TIM_TYPES
 * @{
 */
/***********************************************************************
 * Timer device enumeration
**********************************************************************/
/** @brief interrupt  type */
typedef enum
{
	TIM_MR0_INT =0, /*!< interrupt for Match channel 0*/
	TIM_MR1_INT =1, /*!< interrupt for Match channel 1*/
	TIM_MR2_INT =2, /*!< interrupt for Match channel 2*/
	TIM_MR3_INT =3, /*!< interrupt for Match channel 3*/
	TIM_CR0_INT =4, /*!< interrupt for Capture channel 0*/
	TIM_CR1_INT =5, /*!< interrupt for Capture channel 1*/
}TIM_INT_TYPE;
#define PARAM_TIM_INT_TYPE(TYPE)	((TYPE ==TIM_MR0_INT)||\
									 (TYPE ==TIM_MR1_INT)||\
									 (TYPE ==TIM_MR2_INT)||\
									 (TYPE ==TIM_MR3_INT)||\
									 (TYPE ==TIM_CR0_INT)||\
									 (TYPE ==TIM_CR1_INT))
/** @brief Timer/counter operating mode */
typedef enum
{
	TIM_TIMER_MODE = 0,				/*!< Timer mode */
	TIM_COUNTER_RISING_MODE,		/*!< Counter rising mode */
	TIM_COUNTER_FALLING_MODE,		/*!< Counter falling mode */
	TIM_COUNTER_ANY_MODE			/*!< Counter on both edges */
} TIM_MODE_OPT;
#define PARAM_TIM_MODE_OPT(MODE)	((	MODE	==TIM_TIMER_MODE)|| \
									(	MODE	==TIM_COUNTER_RISING_MODE)|| \
									(	MODE	==TIM_COUNTER_RISING_MODE)|| \
								    (	MODE	==TIM_COUNTER_RISING_MODE))
/** @brief Timer/Counter prescale option */
typedef enum
{
	TIM_PRESCALE_TICKVAL = 0,		/*!< Prescale in absolute value */
	TIM_PRESCALE_USVAL				/*!< Prescale in microsecond value */
} TIM_PRESCALE_OPT;
#define PARAM_TIM_PRESCALE_OPT(OPT)	((	OPT	==	TIM_PRESCALE_TICKVAL)|| \
										(	OPT	==	TIM_PRESCALE_USVAL))
/** @brief Counter input option */
typedef enum
{
	TIM_COUNTER_INCAP0 = 0,			/*!< CAPn.0 input pin for TIMERn */
	TIM_COUNTER_INCAP1,				/*!< CAPn.1 input pin for TIMERn */
} TIM_COUNTER_INPUT_OPT;
#define PARAM_TIM_COUNTER_INPUT_OPT(OPT)	((	OPT	==	TIM_COUNTER_INCAP0)|| \
											(	OPT	==	TIM_COUNTER_INCAP1))
/** @brief Timer/Counter external match option */
typedef enum
{
	TIM_EXTMATCH_NOTHING = 0,		/*!< Do nothing for external output pin if match */
	TIM_EXTMATCH_LOW,				/*!< Force external output pin to low if match */
	TIM_EXTMATCH_HIGH,				/*!< Force external output pin to high if match */
	TIM_EXTMATCH_TOGGLE				/*!< Toggle external output pin if match */
}TIM_EXTMATCH_OPT;
#define PARAM_TIM_EXTMATCH_OPT(OPT)	((	OPT	==	TIM_EXTMATCH_NOTHING)|| \
									(	OPT	==	TIM_EXTMATCH_LOW)|| \
									(	OPT	==	TIM_EXTMATCH_HIGH)|| \
									(	OPT	==	TIM_EXTMATCH_TOGGLE))
/** @brief Timer/counter capture mode options */
typedef enum {
	TIM_CAPTURE_NONE = 0,	/*!< No Capture */
	TIM_CAPTURE_RISING,		/*!< Rising capture mode */
	TIM_CAPTURE_FALLING,	/*!< Falling capture mode */
	TIM_CAPTURE_ANY			/*!< On both edges */
} TIM_CAP_MODE_OPT;
#define PARAM_TIM_CAP_MODE_OPT(OPT)	((	OPT	==	TIM_CAPTURE_NONE)|| \
									(	OPT	==	TIM_CAPTURE_RISING)|| \
									(	OPT	==	TIM_CAPTURE_FALLING)|| \
									(	OPT	==	TIM_CAPTURE_ANY))
/** Configuration structure in TIMER mode */
typedef struct
{

	uint8_t PrescaleOption;
	uint8_t Reserved[3];
	uint32_t PrescaleValue;
} TIM_TIMERCFG_Type;

/** Configuration structure in COUNTER mode */
typedef struct {

	uint8_t CounterOption;
	uint8_t CountInputSelect;
	uint8_t Reserved[2];
} TIM_COUNTERCFG_Type;


/*
 * Pin configuration structure here...
 */

/** Match channel configuration structure */
typedef struct {
	uint8_t MatchChannel;	/**< Match channel, should be in range
							from 0..3 */
	uint8_t IntOnMatch;		/**< Interrupt On match, should be:
							- ENABLE: Enable this function.
							- DISABLE: Disable this function.
							*/
	uint8_t StopOnMatch;	/**< Stop On match, should be:
							- ENABLE: Enable this function.
							- DISABLE: Disable this function.
							*/
	uint8_t ResetOnMatch;	/**< Reset On match, should be:
							- ENABLE: Enable this function.
							- DISABLE: Disable this function.
							*/

	uint8_t ExtMatchOutputType;	/**< External Match Output type, should be:
							 -	 0:	Do nothing for external output pin if match
							 -   1:	Force external output pin to low if match
							 - 	 2: Force external output pin to high if match
							 -   3: Toggle external output pin if match.
							*/
	uint8_t Reserved[3];	/** Reserved */
	uint32_t MatchValue;	/** Match value */
} TIM_MATCHCFG_Type;


/** Capture Input configuration structure */
typedef struct {
	uint8_t CaptureChannel;	/**< Capture channel, should be in range
							from 0..1 */
	uint8_t RisingEdge;		/**< caption rising edge, should be:
							- ENABLE: Enable rising edge.
							- DISABLE: Disable this function.
							*/
	uint8_t FallingEdge;		/**< caption falling edge, should be:
							- ENABLE: Enable falling edge.
							- DISABLE: Disable this function.
								*/
	uint8_t IntOnCaption;	/**< Interrupt On caption, should be:
							- ENABLE: Enable interrupt function.
							- DISABLE: Disable this function.
							*/

} TIM_CAPTURECFG_Type;

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

/** @defgroup TIM_MACROS
 * @{
 */
/** Macro to determine if it is valid TIMER peripheral */
#define PARAM_TIMx(n)	((((uint32_t *)n)==((uint32_t *)TIM0)) \
						|| (((uint32_t *)n)==((uint32_t *)TIM1)) \
						|| (((uint32_t *)n)==((uint32_t *)TIM2)) \
						|| (((uint32_t *)n)==((uint32_t *)TIM3)))


/**
 * @}
 */

/**
 * @}
 */


/************************** GLOBAL/PUBLIC FUNCTIONS *************************/
/** @addtogroup PUBLIC_FUNCTION_PROTOTYPES
 * @{
 */

/** @defgroup TIM_FUNCTIONS
 * @{
 */
FlagStatus TIM_GetIntStatus(TIM_TypeDef *TIMx, uint8_t IntFlag);
void TIM_ClearIntPending(TIM_TypeDef *TIMx, uint8_t IntFlag);
void TIM_Cmd(TIM_TypeDef *TIMx, FunctionalState NewState);
void TIM_ResetCounter(TIM_TypeDef *TIMx);
void TIM_Init(TIM_TypeDef *TIMx, uint8_t TimerCounterMode, void *TIM_ConfigStruct);
void TIM_DeInit(TIM_TypeDef *TIMx);
void TIM_ConfigStructInit(uint8_t TimerCounterMode, void *TIM_ConfigStruct);
void TIM_ConfigMatch(TIM_TypeDef *TIMx, TIM_MATCHCFG_Type *TIM_MatchConfigStruct);
void TIM_SetMatchExt(TIM_TypeDef *TIMx,TIM_EXTMATCH_OPT ext_match );
void TIM_ConfigCapture(TIM_TypeDef *TIMx, TIM_CAPTURECFG_Type *TIM_CaptureConfigStruct);
uint32_t TIM_GetCaptureValue(TIM_TypeDef *TIMx, uint8_t CaptureChannel);
/**
 * @}
 */

/**
 * @}
 */

#endif /* __LPC17XX_TIMER_H_ */
