/**************************************************************************//**
 * @file    pinsel.h
 * @brief   : Contains all macro definitions and class declaration for
 *              support for Pin connect block firmware library on LPC17xx
 * @author  Dariusz Synowiec <devemouse@gmail.com>
 * @version 0.0.0dev
 * @date    June 2011
 *****************************************************************************/

/******************************************************************************
 * Include files
 *****************************************************************************/
#include "inttypes.h"
#include "LPC17xx.h"

/******************************************************************************
 * Forward declarations
 *****************************************************************************/

#ifndef _PINSEL_H_
#define _PINSEL_H_

#define LQFP_80 1
#define LQFP_100 2
#define PACKAGE LQFP_100

#ifdef __cplusplus
extern "C"
{
#endif


/* Pin selection define */
/* I2C Pin Configuration register bit description */
#define PINSEL_I2CPADCFG_SDADRV0  (1<<0) /**< Drive mode control for the SDA0 pin, P0.27 */
#define PINSEL_I2CPADCFG_SDAI2C0  (1<<1) /**< I2C mode control for the SDA0 pin, P0.27 */
#define PINSEL_I2CPADCFG_SCLDRV0  (1<<2) /**< Drive mode control for the SCL0 pin, P0.28 */
#define PINSEL_I2CPADCFG_SCLI2C0  (1<<3) /**< I2C mode control for the SCL0 pin, P0.28 */

/*************************** GLOBAL/PUBLIC MACROS ***************************/

/*********************************************************************//**
 ** Macros define for PORT Selection
 ***********************************************************************/

/***********************************************************************
 ** Macros define for Pin Function selection
 **********************************************************************/
typedef enum {
   PINSEL_FUNC_0  = 0,   /**< default function*/
   PINSEL_FUNC_1  = 1,   /**< first alternate function*/
   PINSEL_FUNC_2  = 2,   /**< second alternate function*/
   PINSEL_FUNC_3  = 3,   /**< third or reserved alternate function*/
} PINSEL_Pin_Function_e;

/***********************************************************************
 ** Macros define for Pin Number of Port
 **********************************************************************/

typedef enum {
  /* encoding:
   *    ---- -OOO ---I IIII
   * where:
   *    O - port, I - pin */

  /* pin name     = port | pin */
   PINSEL_P0_0    = (0<<8) | 0,
   PINSEL_P0_1    = (0<<8) | 1,
   PINSEL_P0_2    = (0<<8) | 2,
   PINSEL_P0_3    = (0<<8) | 3,
#if PACKAGE == LQFP_100
   PINSEL_P0_4    = (0<<8) | 4,
   PINSEL_P0_5    = (0<<8) | 5,
#endif
   PINSEL_P0_6    = (0<<8) | 6,
   PINSEL_P0_7    = (0<<8) | 7,
   PINSEL_P0_8    = (0<<8) | 8,
   PINSEL_P0_9    = (0<<8) | 9,
   PINSEL_P0_10   = (0<<8) | 10,
   PINSEL_P0_11   = (0<<8) | 11,
/* PINSEL_P0_12 does not exist */
/* PINSEL_P0_13 does not exist */
/* PINSEL_P0_14 does not exist */
   PINSEL_P0_15   = (0<<8) | 15,
   PINSEL_P0_16   = (0<<8) | 16,
   PINSEL_P0_17   = (0<<8) | 17,
   PINSEL_P0_18   = (0<<8) | 18,
#if PACKAGE == LQFP_100
   PINSEL_P0_19   = (0<<8) | 19,
   PINSEL_P0_20   = (0<<8) | 20,
   PINSEL_P0_21   = (0<<8) | 21,
#endif
   PINSEL_P0_22   = (0<<8) | 22,
#if PACKAGE == LQFP_100
   PINSEL_P0_23   = (0<<8) | 23,
   PINSEL_P0_24   = (0<<8) | 24,
#endif
   PINSEL_P0_25   = (0<<8) | 25,
   PINSEL_P0_26   = (0<<8) | 26,
#if PACKAGE == LQFP_100
   PINSEL_P0_27   = (0<<8) | 27,
   PINSEL_P0_28   = (0<<8) | 28,
#endif
   PINSEL_P0_29   = (0<<8) | 29,
   PINSEL_P0_30   = (0<<8) | 30,
/* PINSEL_P0_31 does not exist */

   PINSEL_P1_0    = (1<<8) | 0,
   PINSEL_P1_1    = (1<<8) | 1,
/* PINSEL_P1_2 does not exist */
/* PINSEL_P1_3 does not exist */
   PINSEL_P1_4    = (1<<8) | 4,
/* PINSEL_P1_5 does not exist */
/* PINSEL_P1_6 does not exist */
/* PINSEL_P1_7 does not exist */
   PINSEL_P1_8    = (1<<8) | 8,
   PINSEL_P1_9    = (1<<8) | 9,
   PINSEL_P1_10   = (1<<8) | 10,
/* PINSEL_P1_11 does not exist */
/* PINSEL_P1_12 does not exist */
/* PINSEL_P1_13 does not exist */
   PINSEL_P1_14   = (1<<8) | 14,
   PINSEL_P1_15   = (1<<8) | 15,
#if PACKAGE == LQFP_100
   PINSEL_P1_16   = (1<<8) | 16,
   PINSEL_P1_17   = (1<<8) | 17,
#endif
   PINSEL_P1_18   = (1<<8) | 18,
   PINSEL_P1_19   = (1<<8) | 19,
   PINSEL_P1_20   = (1<<8) | 20,
#if PACKAGE == LQFP_100
   PINSEL_P1_21   = (1<<8) | 21,
#endif
   PINSEL_P1_22   = (1<<8) | 22,
   PINSEL_P1_23   = (1<<8) | 23,
   PINSEL_P1_24   = (1<<8) | 24,
   PINSEL_P1_25   = (1<<8) | 25,
   PINSEL_P1_26   = (1<<8) | 26,
#if PACKAGE == LQFP_100
   PINSEL_P1_27   = (1<<8) | 27,
#endif
   PINSEL_P1_28   = (1<<8) | 28,
   PINSEL_P1_29   = (1<<8) | 29,
   PINSEL_P1_30   = (1<<8) | 30,
   PINSEL_P1_31   = (1<<8) | 31,

   PINSEL_P2_0    = (2<<8) | 0,
   PINSEL_P2_1    = (2<<8) | 1,
   PINSEL_P2_2    = (2<<8) | 2,
   PINSEL_P2_3    = (2<<8) | 3,
   PINSEL_P2_4    = (2<<8) | 4,
   PINSEL_P2_5    = (2<<8) | 5,
   PINSEL_P2_6    = (2<<8) | 6,
   PINSEL_P2_7    = (2<<8) | 7,
   PINSEL_P2_8    = (2<<8) | 8,
   PINSEL_P2_9    = (2<<8) | 9,
   PINSEL_P2_10   = (2<<8) | 10,
#if PACKAGE == LQFP_100
   PINSEL_P2_11   = (2<<8) | 11,
   PINSEL_P2_12   = (2<<8) | 12,
   PINSEL_P2_13   = (2<<8) | 13,
#endif
/* PINSEL_P2_14 does not exist */
/* PINSEL_P2_15 does not exist */
/* PINSEL_P2_16 does not exist */
/* PINSEL_P2_17 does not exist */
/* PINSEL_P2_18 does not exist */
/* PINSEL_P2_19 does not exist */
/* PINSEL_P2_20 does not exist */
/* PINSEL_P2_21 does not exist */
/* PINSEL_P2_22 does not exist */
/* PINSEL_P2_23 does not exist */
/* PINSEL_P2_24 does not exist */
/* PINSEL_P2_25 does not exist */
/* PINSEL_P2_26 does not exist */
/* PINSEL_P2_27 does not exist */
/* PINSEL_P2_28 does not exist */
/* PINSEL_P2_29 does not exist */
/* PINSEL_P2_30 does not exist */
/* PINSEL_P2_31 does not exist */

/* PINSEL_P3_0 does not exist */
/* PINSEL_P3_1 does not exist */
/* PINSEL_P3_2 does not exist */
/* PINSEL_P3_3 does not exist */
/* PINSEL_P3_4 does not exist */
/* PINSEL_P3_5 does not exist */
/* PINSEL_P3_6 does not exist */
/* PINSEL_P3_7 does not exist */
/* PINSEL_P3_8 does not exist */
/* PINSEL_P3_9 does not exist */
/* PINSEL_P3_10 does not exist */
/* PINSEL_P3_11 does not exist */
/* PINSEL_P3_12 does not exist */
/* PINSEL_P3_13 does not exist */
/* PINSEL_P3_14 does not exist */
/* PINSEL_P3_15 does not exist */
/* PINSEL_P3_16 does not exist */
/* PINSEL_P3_17 does not exist */
/* PINSEL_P3_18 does not exist */
/* PINSEL_P3_19 does not exist */
/* PINSEL_P3_20 does not exist */
/* PINSEL_P3_21 does not exist */
/* PINSEL_P3_22 does not exist */
/* PINSEL_P3_23 does not exist */
/* PINSEL_P3_24 does not exist */
#if PACKAGE == LQFP_100
   PINSEL_P3_25   = (3<<8) | 25,
   PINSEL_P3_26   = (3<<8) | 26,
#endif
/* PINSEL_P3_27 does not exist */
/* PINSEL_P3_28 does not exist */
/* PINSEL_P3_29 does not exist */
/* PINSEL_P3_30 does not exist */
/* PINSEL_P3_31 does not exist */

/* PINSEL_P4_0 does not exist */
/* PINSEL_P4_1 does not exist */
/* PINSEL_P4_2 does not exist */
/* PINSEL_P4_3 does not exist */
/* PINSEL_P4_4 does not exist */
/* PINSEL_P4_5 does not exist */
/* PINSEL_P4_6 does not exist */
/* PINSEL_P4_7 does not exist */
/* PINSEL_P4_8 does not exist */
/* PINSEL_P4_9 does not exist */
/* PINSEL_P4_10 does not exist */
/* PINSEL_P4_11 does not exist */
/* PINSEL_P4_12 does not exist */
/* PINSEL_P4_13 does not exist */
/* PINSEL_P4_14 does not exist */
/* PINSEL_P4_15 does not exist */
/* PINSEL_P4_16 does not exist */
/* PINSEL_P4_17 does not exist */
/* PINSEL_P4_18 does not exist */
/* PINSEL_P4_19 does not exist */
/* PINSEL_P4_20 does not exist */
/* PINSEL_P4_21 does not exist */
/* PINSEL_P4_22 does not exist */
/* PINSEL_P4_23 does not exist */
/* PINSEL_P4_24 does not exist */
/* PINSEL_P4_25 does not exist */
/* PINSEL_P4_26 does not exist */
/* PINSEL_P4_27 does not exist */
   PINSEL_P4_28   = (4 << 8) | 28,
   PINSEL_P4_29   = (4 << 8) | 29,
/* PINSEL_P4_30 does not exist */
/* PINSEL_P4_31 does not exist */
} PINSEL_PortPin_e;



/** SPI function pin selection group 0 */
#define SPI_PINSEL_SCK_P0_15    (PINSEL_PIN_15)
#define SPI_PINFUNC_SCK_P0_15   (PINSEL_FUNC_3)

#define SPI_PINSEL_SSEL_P0_16   (PINSEL_PIN_16)
#define SPI_PINFUNC_SSEL_P0_16  (PINSEL_FUNC_3)

#define SPI_PINSEL_MISO_P0_17   (PINSEL_PIN_17)
#define SPI_PINFUNC_MISO_P0_17  (PINSEL_FUNC_3)

#define SPI_PINSEL_MOSI_P0_18   (PINSEL_PIN_18)
#define SPI_PINFUNC_MOSI_P0_18  (PINSEL_FUNC_3)


/***********************************************************************
 * Macros define for Pin mode
 **********************************************************************/
typedef enum {
   PINSEL_PINMODE_PULLUP   = 0, /**< Internal pull-up resistor */
   PINSEL_PINMODE_TRISTATE = 2, /**< Tri-state */
   PINSEL_PINMODE_PULLDOWN = 3, /**< Internal pull-down resistor */
} PINSEL_PinMode_e;


/***********************************************************************
 * Macros define for Pin mode (normal/open drain)
 **********************************************************************/
typedef enum {
   PINSEL_PINMODE_NORMAL       = 0,   /**< Pin is in the normal (not open drain) mode.*/
   PINSEL_PINMODE_OPENDRAIN    = 1,   /**< Pin is in the open drain mode */
} PINSEL_PinOpenDrain_e;


/***********************************************************************
 * Macros define for I2C mode
 ***********************************************************************/
#define PINSEL_I2C_Normal_Mode      ((0))   /**< The standard drive mode */
#define PINSEL_I2C_Fast_Mode        ((1))   /**<  Fast Mode Plus drive mode */

/**************************** GLOBAL/PUBLIC TYPES ***************************/

/** Pin configuration structure */
typedef struct
{
    PINSEL_PortPin_e Pin;          /**< Pin Number, should be PINSEL_Pn_x,
                                        where n should be in range from 0 to 4 and
                                        where x should be in range from 0 to 31 */
    PINSEL_Pin_Function_e Funcnum; /**< Function Number, should be PINSEL_FUNC_x,
                                        where x should be in range from 0 to 3 */
    PINSEL_PinMode_e Pinmode;    /**< Pin Mode, should be:
                        - PINSEL_PINMODE_PULLUP: Internal pull-up resistor
                        - PINSEL_PINMODE_TRISTATE: Tri-state
                        - PINSEL_PINMODE_PULLDOWN: Internal pull-down resistor */
    PINSEL_PinOpenDrain_e OpenDrain;  /**< OpenDrain mode, should be:
                        - PINSEL_PINMODE_NORMAL: Pin is in the normal (not open drain) mode
                        - PINSEL_PINMODE_OPENDRAIN: Pin is in the open drain mode */
} PINSEL_CFG_Type;

#ifdef __cplusplus
}
#endif

/**
 * PINSEL class
 */
class PINSEL {
   public:
      /*****************************************************
       * Constructors
       *****************************************************/
      /**
       * Default empty construcor
       */
      PINSEL();

      /**
       * Default destructor
       */
      ~PINSEL() {};

      /*****************************************************
       * Functions: modifiers (set), selectors (get)
       *****************************************************/
      /*********************************************************************//**
       * @brief       Setup the pin selection function
       * @param[in]   pinnum Pin number should be one of the values from PINSEL_PortPin_e 
       *
       * @param[in]   funcnum Function number,
       *              should be one of the following:
       *              - PINSEL_FUNC_0 : default function
       *              - PINSEL_FUNC_1 : first alternate function
       *              - PINSEL_FUNC_2 : second alternate function
       *              - PINSEL_FUNC_3 : third alternate function
       *
       * @return      None
       **********************************************************************/
      static void SetPinFunc ( PINSEL_PortPin_e pinnum, PINSEL_Pin_Function_e funcnum);

      /*********************************************************************//**
       * @brief       Configure trace function
       * @param[in]   NewState State of the Trace function configuration,
       *              should be one of the following:
       *              - ENABLE : Enable Trace Function
       *              - DISABLE : Disable Trace Function
       *
       * @return      None
       **********************************************************************/
      static void ConfigTraceFunc (FunctionalState NewState);

      /*********************************************************************//**
       * @brief       Setup resistor mode for each pin
       * @param[in]   pinnum Pin number should be one of the values from PINSEL_PortPin_e 
       *
       * @param[in]   modenum: Mode number,
       *              should be one of the following:
       *              - PINSEL_PINMODE_PULLUP : Internal pull-up resistor
       *              - PINSEL_PINMODE_TRISTATE : Tri-state
       *              - PINSEL_PINMODE_PULLDOWN : Internal pull-down resistor
       *
       * @return      None
       **********************************************************************/
      static void SetResistorMode (  PINSEL_PortPin_e pinnum, PINSEL_PinMode_e modenum);

      /*********************************************************************//**
       * @brief       Setup Open drain mode for each pin
       * @param[in]   pinnum Pin number should be one of the values from PINSEL_PortPin_e 
       *
       * @param[in]   modenum  Open drain mode number,
       *              should be one of the following:
       *              - PINSEL_PINMODE_NORMAL : Pin is in the normal (not open drain) mode
       *              - PINSEL_PINMODE_OPENDRAIN : Pin is in the open drain mode
       *
       * @return      None
       **********************************************************************/
      static void SetOpenDrainMode(  PINSEL_PortPin_e pinnum, PINSEL_PinOpenDrain_e modenum);

      /*********************************************************************//**
       * @brief       Setup I2C0 pins
       * @param[in]   i2cPinMode I2C pin mode,
       *              should be one of the following:
       *              - PINSEL_I2C_Normal_Mode : The standard drive mode
       *              - PINSEL_I2C_Fast_Mode : Fast Mode Plus drive mode
       *
       * @param[in]   filterSlewRateEnable  should be:
       *              - ENABLE: Enable filter and slew rate.
       *              - DISABLE: Disable filter and slew rate.
       *
       * @return      None
       **********************************************************************/
      static void SetI2C0Pins(uint8_t i2cPinMode, FunctionalState filterSlewRateEnable);

      /*********************************************************************//**
       * @brief       Configure Pin corresponding to specified parameters passed
       *              in the PinCfg
       * @param[in]   PinCfg  Pointer to a PINSEL_CFG_Type structure
       *                    that contains the configuration information for the
       *                    specified pin.
       * @return      None
       **********************************************************************/
      static void ConfigPin(PINSEL_CFG_Type *PinCfg);

      /*****************************************************
       * Iterators
       *****************************************************/

      /*****************************************************
       * Public attributes
       *****************************************************/

   protected:
      /*****************************************************
       * Protected functions
       *****************************************************/

      /*****************************************************
       * Protected attributes
       *****************************************************/

   private:
      /*****************************************************
       * Private functions
       *****************************************************/

      /*****************************************************
       * Private attributes
       *****************************************************/
};


#endif /* _PINSEL_H_ */
