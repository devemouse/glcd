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
typedef enum {
   PINSEL_PORT_0   = 0,   /**< PORT 0*/
   PINSEL_PORT_1   = 1,   /**< PORT 1*/
   PINSEL_PORT_2   = 2,   /**< PORT 2*/
   PINSEL_PORT_3   = 3,   /**< PORT 3*/
   PINSEL_PORT_4   = 4,   /**< PORT 4*/
} PINSEL_Port_e;


/***********************************************************************
 ** Macros define for Pin Function selection
 **********************************************************************/
typedef enum {
   PINSEL_FUNC_0  = 0,   /**< default function*/
   PINSEL_FUNC_1  = 1,   /**< first alternate function*/
   PINSEL_FUNC_2  = 2,   /**< second alternate function*/
   PINSEL_FUNC_3  = 3,   /**< third or reserved alternate function*/
} PINSEL_Pin_Function_e;

/** SPI function pin selection group 0 */
#define SPI_PINSEL_SCK_P0_15    ((PINSEL_PinNum_e)(15))
#define SPI_PINFUNC_SCK_P0_15   ((PINSEL_Pin_Function_e)(3))

#define SPI_PINSEL_SSEL_P0_16   ((PINSEL_PinNum_e)(16))
#define SPI_PINFUNC_SSEL_P0_16  ((PINSEL_Pin_Function_e)(3))

#define SPI_PINSEL_MISO_P0_17   ((PINSEL_PinNum_e)(17))
#define SPI_PINFUNC_MISO_P0_17  ((PINSEL_Pin_Function_e)(3))

#define SPI_PINSEL_MOSI_P0_18   ((PINSEL_PinNum_e)(18))
#define SPI_PINFUNC_MOSI_P0_18  ((PINSEL_Pin_Function_e)(3))


/***********************************************************************
 ** Macros define for Pin Number of Port
 **********************************************************************/
typedef enum {
   PINSEL_PIN_0    = 0,   /**< Pin 0 */
   PINSEL_PIN_1    = 1,   /**< Pin 1 */
   PINSEL_PIN_2    = 2,   /**< Pin 2 */
   PINSEL_PIN_3    = 3,   /**< Pin 3 */
   PINSEL_PIN_4    = 4,   /**< Pin 4 */
   PINSEL_PIN_5    = 5,   /**< Pin 5 */
   PINSEL_PIN_6    = 6,   /**< Pin 6 */
   PINSEL_PIN_7    = 7,   /**< Pin 7 */
   PINSEL_PIN_8    = 8,   /**< Pin 8 */
   PINSEL_PIN_9    = 9,   /**< Pin 9 */
   PINSEL_PIN_10   = 10,  /**< Pin 10 */
   PINSEL_PIN_11   = 11,  /**< Pin 11 */
   PINSEL_PIN_12   = 12,  /**< Pin 12 */
   PINSEL_PIN_13   = 13,  /**< Pin 13 */
   PINSEL_PIN_14   = 14,  /**< Pin 14 */
   PINSEL_PIN_15   = 15,  /**< Pin 15 */
   PINSEL_PIN_16   = 16,  /**< Pin 16 */
   PINSEL_PIN_17   = 17,  /**< Pin 17 */
   PINSEL_PIN_18   = 18,  /**< Pin 18 */
   PINSEL_PIN_19   = 19,  /**< Pin 19 */
   PINSEL_PIN_20   = 20,  /**< Pin 20 */
   PINSEL_PIN_21   = 21,  /**< Pin 21 */
   PINSEL_PIN_22   = 22, /**< Pin 22 */
   PINSEL_PIN_23   = 23, /**< Pin 23 */
   PINSEL_PIN_24   = 24, /**< Pin 24 */
   PINSEL_PIN_25   = 25, /**< Pin 25 */
   PINSEL_PIN_26   = 26, /**< Pin 26 */
   PINSEL_PIN_27   = 27, /**< Pin 27 */
   PINSEL_PIN_28   = 28, /**< Pin 28 */
   PINSEL_PIN_29   = 29, /**< Pin 29 */
   PINSEL_PIN_30   = 30,  /**< Pin 30 */
   PINSEL_PIN_31   = 31,  /**< Pin 31 */
} PINSEL_PinNum_e;


/***********************************************************************
 * Macros define for Pin mode
 **********************************************************************/
#define PINSEL_PINMODE_PULLUP       ((0))   /**< Internal pull-up resistor*/
#define PINSEL_PINMODE_TRISTATE     ((2))   /**< Tri-state */
#define PINSEL_PINMODE_PULLDOWN     ((3))   /**< Internal pull-down resistor */


/***********************************************************************
 * Macros define for Pin mode (normal/open drain)
 **********************************************************************/
#define PINSEL_PINMODE_NORMAL       ((0))   /**< Pin is in the normal (not open drain) mode.*/
#define PINSEL_PINMODE_OPENDRAIN    ((1))   /**< Pin is in the open drain mode */


/***********************************************************************
 * Macros define for I2C mode
 ***********************************************************************/
#define PINSEL_I2C_Normal_Mode      ((0))   /**< The standard drive mode */
#define PINSEL_I2C_Fast_Mode        ((1))   /**<  Fast Mode Plus drive mode */

/**************************** GLOBAL/PUBLIC TYPES ***************************/

/** Pin configuration structure */
typedef struct
{
    PINSEL_Port_e Portnum;    /**< Port Number, should be PINSEL_PORT_x,
                        where x should be in range from 0 to 4 */
    PINSEL_PinNum_e Pinnum;     /**< Pin Number, should be PINSEL_PIN_x,
                        where x should be in range from 0 to 31 */
    PINSEL_Pin_Function_e Funcnum;    /**< Function Number, should be PINSEL_FUNC_x,
                        where x should be in range from 0 to 3 */
    uint8_t Pinmode;    /**< Pin Mode, should be:
                        - PINSEL_PINMODE_PULLUP: Internal pull-up resistor
                        - PINSEL_PINMODE_TRISTATE: Tri-state
                        - PINSEL_PINMODE_PULLDOWN: Internal pull-down resistor */
    uint8_t OpenDrain;  /**< OpenDrain mode, should be:
                        - PINSEL_PINMODE_NORMAL: Pin is in the normal (not open drain) mode
                        - PINSEL_PINMODE_OPENDRAIN: Pin is in the open drain mode */
    uint8_t Reserved[3];    /**< Reserved */
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
       * @param[in]   portnum PORT number,
       *              should be one of the following:
       *              - PINSEL_PORT_0 : Port 0
       *              - PINSEL_PORT_1 : Port 1
       *              - PINSEL_PORT_2 : Port 2
       *              - PINSEL_PORT_3 : Port 3
       *
       * @param[in]   pinnum  Pin number,
       *              should be one of the following:
       *              - PINSEL_PIN_0 : Pin 0
       *              - PINSEL_PIN_1 : Pin 1
       *              - PINSEL_PIN_2 : Pin 2
       *              - PINSEL_PIN_3 : Pin 3
       *              - PINSEL_PIN_4 : Pin 4
       *              - PINSEL_PIN_5 : Pin 5
       *              - PINSEL_PIN_6 : Pin 6
       *              - PINSEL_PIN_7 : Pin 7
       *              - PINSEL_PIN_8 : Pin 8
       *              - PINSEL_PIN_9 : Pin 9
       *              - PINSEL_PIN_10 : Pin 10
       *              - PINSEL_PIN_11 : Pin 11
       *              - PINSEL_PIN_12 : Pin 12
       *              - PINSEL_PIN_13 : Pin 13
       *              - PINSEL_PIN_14 : Pin 14
       *              - PINSEL_PIN_15 : Pin 15
       *              - PINSEL_PIN_16 : Pin 16
       *              - PINSEL_PIN_17 : Pin 17
       *              - PINSEL_PIN_18 : Pin 18
       *              - PINSEL_PIN_19 : Pin 19
       *              - PINSEL_PIN_20 : Pin 20
       *              - PINSEL_PIN_21 : Pin 21
       *              - PINSEL_PIN_22 : Pin 22
       *              - PINSEL_PIN_23 : Pin 23
       *              - PINSEL_PIN_24 : Pin 24
       *              - PINSEL_PIN_25 : Pin 25
       *              - PINSEL_PIN_26 : Pin 26
       *              - PINSEL_PIN_27 : Pin 27
       *              - PINSEL_PIN_28 : Pin 28
       *              - PINSEL_PIN_29 : Pin 29
       *              - PINSEL_PIN_30 : Pin 30
       *              - PINSEL_PIN_31 : Pin 31
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
      static void SetPinFunc ( PINSEL_Port_e portnum, PINSEL_PinNum_e pinnum, PINSEL_Pin_Function_e funcnum);

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
       * @param[in]   portnum PORT number,
       *              should be one of the following:
       *              - PINSEL_PORT_0 : Port 0
       *              - PINSEL_PORT_1 : Port 1
       *              - PINSEL_PORT_2 : Port 2
       *              - PINSEL_PORT_3 : Port 3
       * @param[in]   pinnum  Pin number,
       *              should be one of the following:
       *              - PINSEL_PIN_0 : Pin 0
       *              - PINSEL_PIN_1 : Pin 1
       *              - PINSEL_PIN_2 : Pin 2
       *              - PINSEL_PIN_3 : Pin 3
       *              - PINSEL_PIN_4 : Pin 4
       *              - PINSEL_PIN_5 : Pin 5
       *              - PINSEL_PIN_6 : Pin 6
       *              - PINSEL_PIN_7 : Pin 7
       *              - PINSEL_PIN_8 : Pin 8
       *              - PINSEL_PIN_9 : Pin 9
       *              - PINSEL_PIN_10 : Pin 10
       *              - PINSEL_PIN_11 : Pin 11
       *              - PINSEL_PIN_12 : Pin 12
       *              - PINSEL_PIN_13 : Pin 13
       *              - PINSEL_PIN_14 : Pin 14
       *              - PINSEL_PIN_15 : Pin 15
       *              - PINSEL_PIN_16 : Pin 16
       *              - PINSEL_PIN_17 : Pin 17
       *              - PINSEL_PIN_18 : Pin 18
       *              - PINSEL_PIN_19 : Pin 19
       *              - PINSEL_PIN_20 : Pin 20
       *              - PINSEL_PIN_21 : Pin 21
       *              - PINSEL_PIN_22 : Pin 22
       *              - PINSEL_PIN_23 : Pin 23
       *              - PINSEL_PIN_24 : Pin 24
       *              - PINSEL_PIN_25 : Pin 25
       *              - PINSEL_PIN_26 : Pin 26
       *              - PINSEL_PIN_27 : Pin 27
       *              - PINSEL_PIN_28 : Pin 28
       *              - PINSEL_PIN_29 : Pin 29
       *              - PINSEL_PIN_30 : Pin 30
       *              - PINSEL_PIN_31 : Pin 31
       *
       * @param[in]   modenum: Mode number,
       *              should be one of the following:
       *              - PINSEL_PINMODE_PULLUP : Internal pull-up resistor
       *              - PINSEL_PINMODE_TRISTATE : Tri-state
       *              - PINSEL_PINMODE_PULLDOWN : Internal pull-down resistor
       *
       * @return      None
       **********************************************************************/
      static void SetResistorMode ( PINSEL_Port_e portnum, PINSEL_PinNum_e pinnum, uint8_t modenum);

      /*********************************************************************//**
       * @brief       Setup Open drain mode for each pin
       * @param[in]   portnum PORT number,
       *              should be one of the following:
       *              - PINSEL_PORT_0 : Port 0
       *              - PINSEL_PORT_1 : Port 1
       *              - PINSEL_PORT_2 : Port 2
       *              - PINSEL_PORT_3 : Port 3
       *
       * @param[in]   pinnum  Pin number,
       *              should be one of the following:
       *              - PINSEL_PIN_0 : Pin 0
       *              - PINSEL_PIN_1 : Pin 1
       *              - PINSEL_PIN_2 : Pin 2
       *              - PINSEL_PIN_3 : Pin 3
       *              - PINSEL_PIN_4 : Pin 4
       *              - PINSEL_PIN_5 : Pin 5
       *              - PINSEL_PIN_6 : Pin 6
       *              - PINSEL_PIN_7 : Pin 7
       *              - PINSEL_PIN_8 : Pin 8
       *              - PINSEL_PIN_9 : Pin 9
       *              - PINSEL_PIN_10 : Pin 10
       *              - PINSEL_PIN_11 : Pin 11
       *              - PINSEL_PIN_12 : Pin 12
       *              - PINSEL_PIN_13 : Pin 13
       *              - PINSEL_PIN_14 : Pin 14
       *              - PINSEL_PIN_15 : Pin 15
       *              - PINSEL_PIN_16 : Pin 16
       *              - PINSEL_PIN_17 : Pin 17
       *              - PINSEL_PIN_18 : Pin 18
       *              - PINSEL_PIN_19 : Pin 19
       *              - PINSEL_PIN_20 : Pin 20
       *              - PINSEL_PIN_21 : Pin 21
       *              - PINSEL_PIN_22 : Pin 22
       *              - PINSEL_PIN_23 : Pin 23
       *              - PINSEL_PIN_24 : Pin 24
       *              - PINSEL_PIN_25 : Pin 25
       *              - PINSEL_PIN_26 : Pin 26
       *              - PINSEL_PIN_27 : Pin 27
       *              - PINSEL_PIN_28 : Pin 28
       *              - PINSEL_PIN_29 : Pin 29
       *              - PINSEL_PIN_30 : Pin 30
       *              - PINSEL_PIN_31 : Pin 31
       *
       * @param[in]   modenum  Open drain mode number,
       *              should be one of the following:
       *              - PINSEL_PINMODE_NORMAL : Pin is in the normal (not open drain) mode
       *              - PINSEL_PINMODE_OPENDRAIN : Pin is in the open drain mode
       *
       * @return      None
       **********************************************************************/
      static void SetOpenDrainMode( PINSEL_Port_e portnum, PINSEL_PinNum_e pinnum, uint8_t modenum);

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
