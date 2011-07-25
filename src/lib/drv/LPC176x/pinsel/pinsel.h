/**************************************************************************//**
 * @file    pinsel.h
 * @brief   : Contains all macro definitions and class declaration for
 *              support for Pin connect block firmware library on LPC17xx
 * @author  Dariusz Synowiec <devemouse@gmail.com>
 * @version 0.0.0dev
 * @date    June 2011
 *****************************************************************************/
#ifndef _PINSEL_H_
#define _PINSEL_H_

/******************************************************************************
 * Include files
 *****************************************************************************/
#include "inttypes.h"
#include "LPC17xx.h"
#include "pinout.h"

/******************************************************************************
 * Forward declarations
 *****************************************************************************/

/**
 * PINSEL class
 */
class PINSEL {
   public:
      /***********************************************************************
       * Enums that define Pin mode
       **********************************************************************/
      typedef enum {
         PINMODE_PULLUP   = 0, /**< Internal pull-up resistor */
         PINMODE_REPEATER = 1, /**< If the pin is at a logic high and enables
                                        the pull-down resistor if the pin is at a
                                        logic low */
         PINMODE_TRISTATE = 2, /**< Tri-state */
         PINMODE_PULLDOWN = 3, /**< Internal pull-down resistor */
      } PinMode_e;

      typedef enum {
         PINMODE_NORMAL       = 0,   /**< Pin is in the normal (not open drain) mode.*/
         PINMODE_OPENDRAIN    = 1,   /**< Pin is in the open drain mode */
      } PinOpenDrain_e;

      typedef enum {
         I2C_Normal_Mode = 0,   /**< The standard drive mode */
         I2C_Fast_Mode   = 1,   /**<  Fast Mode Plus drive mode */
      } I2C_Mode_e;

      typedef enum {
         FUNC_0             = 0,   /**< default function*/
         FUNC_1             = 1,   /**< first alternate function*/
         FUNC_2             = 2,   /**< second alternate function*/
         FUNC_3             = 3,   /**< third or reserved alternate function*/

         P0_0_GPIO          = 0,
         P0_0_RD1           = 1,
         P0_0_TXD3          = 2,
         P0_0_SDA1          = 3,

         P0_1_GPIO          = 0,
         P0_1_TD1           = 1,
         P0_1_RXD3          = 2,
         P0_1_SCL1          = 3,

         P0_2_GPIO          = 0,
         P0_2_TXD0          = 1,
         P0_2_AD0_7         = 2,

         P0_3_GPIO          = 0,
         P0_3_RXD0          = 1,
         P0_3_AD0_6         = 2,

         P0_4_GPIO          = 0,
         P0_4_I2SRX_CLK     = 1,
         P0_4_RD2           = 2,
         P0_4_CAP2_0        = 3,

         P0_5_GPIO          = 0,
         P0_5_I2SRX_WS      = 1,
         P0_5_TD2           = 2,
         P0_5_CAP2_1        = 3,

         P0_6_GPIO          = 0,
         P0_6_I2SRX_SDA     = 1,
         P0_6_SSEL1         = 2,
         P0_6_MAT2_0        = 3,

         P0_7_GPIO          = 0,
         P0_7_I2STX_CLK     = 1,
         P0_7_SCK1          = 2,
         P0_7_MAT2_1        = 3,

         P0_8_GPIO          = 0,
         P0_8_I2STX_WS      = 1,
         P0_8_MISO1         = 2,
         P0_8_MAT2_2        = 3,

         P0_9_GPIO          = 0,
         P0_9_I2STX_SDA     = 1,
         P0_9_MOSI1         = 2,
         P0_9_MAT2_3        = 3,

         P0_10_GPIO         = 0,
         P0_10_XD2          = 1,
         P0_10_SDA2         = 2,
         P0_10_MAT3_0       = 3,

         P0_11_GPIO         = 0,
         P0_11_RXD2         = 1,
         P0_11_SCL2         = 2,
         P0_11_MAT3_1       = 3,

         P0_15_GPIO         = 0,
         P0_15_XD1          = 1,
         P0_15_SCK0         = 2,
         P0_15_SCK          = 3,

         P0_16_GPIO         = 0,
         P0_16_RXD1         = 1,
         P0_16_SSEL0        = 2,
         P0_16_SSEL         = 3,

         P0_17_GPIO         = 0,
         P0_17_CTS1         = 1,
         P0_17_MISO0        = 2,
         P0_17_MISO         = 3,

         P0_18_GPIO         = 0,
         P0_18_DCD1         = 1,
         P0_18_MOSI0        = 2,
         P0_18_MOSI         = 3,

         P0_19_GPIO         = 0,
         P0_19_DSR1         = 1,
         P0_19_SDA1         = 3,

         P0_20_GPIO         = 0,
         P0_20_DTR1         = 1,
         P0_20_SCL1         = 3,

         P0_21_GPIO         = 0,
         P0_21_RI1          = 1,
         P0_21_RD1          = 3,

         P0_22_GPIO         = 0,
         P0_22_RTS1         = 1,
         P0_22_TD1          = 3,

         P0_23_GPIO         = 0,
         P0_23_AD0_0        = 1,
         P0_23_I2SRX_CLK    = 2,
         P0_23_CAP3_0       = 3,

         P0_24_GPIO         = 0,
         P0_24_AD0_1        = 1,
         P0_24_I2SRX_WS     = 2,
         P0_24_CAP3_1       = 3,

         P0_25_GPIO         = 0,
         P0_25_AD0_2        = 1,
         P0_25_I2SRX_SDA    = 2,
         P0_25_TXD3         = 3,

         P0_26_GPIO         = 0,
         P0_26_AD0_3        = 1,
         P0_26_AOUT         = 2,
         P0_26_RXD3         = 3,

         P0_27_GPIO         = 0,
         P0_27_SDA0         = 1,
         P0_27_USB_SDA      = 2,

         P0_28_GPIO         = 0,
         P0_28_SCL0         = 1,
         P0_28_USB_SCL      = 2,

         P0_29_GPIO         = 0,
         P0_29_USB_D_PLUS   = 1,

         P0_30_GPIO         = 0,
         P0_30_USB_D_MINUS  = 1,

         P1_0_GPIO          = 0,
         P1_0_ENET_TXD0     = 1,

         P1_1_GPIO          = 0,
         P1_1_ENET_TXD1     = 1,

         P1_4_GPIO          = 0,
         P1_4_ENET_TX_EN    = 1,

         P1_8_GPIO          = 0,
         P1_8_ENET_CRS      = 1,

         P1_9_GPIO          = 0,
         P1_9_ENET_RXD0     = 1,

         P1_10_GPIO         = 0,
         P1_10_ENET_RXD1    = 1,

         P1_14_GPIO         = 0,
         P1_14_ENET_RX_ER   = 1,

         P1_15_GPIO         = 0,
         P1_15_ENET_REF_CLK = 1,

         P1_16_GPIO         = 0,
         P1_16_ENET_MDC     = 1,

         P1_17_GPIO         = 0,
         P1_17_ENET_MDIO    = 1,

         P1_18_GPIO         = 0,
         P1_18_USB_UP_LED   = 1,
         P1_18_PWM1_1       = 2,
         P1_18_CAP1_0       = 3,

         P1_19_GPIO         = 0,
         P1_19_MCOA0        = 1,
         P1_19_USB_PPWR     = 2,
         P1_19_CAP1_1       = 3,

         P1_20_GPIO         = 0,
         P1_20_MCI0         = 1,
         P1_20_PWM1_2       = 2,
         P1_20_SCK0         = 3,

         P1_21_GPIO         = 0,
         P1_21_MCABORT      = 1,
         P1_21_PWM1_3       = 2,
         P1_21_SSEL0        = 3,

         P1_22_GPIO         = 0,
         P1_22_MCOB0        = 1,
         P1_22_USB_PWRD     = 2,
         P1_22_MAT1_0       = 3,

         P1_23_GPIO         = 0,
         P1_23_MCI1         = 1,
         P1_23_PWM1_4       = 2,
         P1_23_MISO0        = 3,

         P1_24_GPIO         = 0,
         P1_24_MCI2         = 1,
         P1_24_PWM1_5       = 2,
         P1_24_MOSI0        = 3,

         P1_25_GPIO         = 0,
         P1_25_MCOA1        = 1,
         P1_25_MAT1_1       = 3,

         P1_26_GPIO         = 0,
         P1_26_MCOB1        = 1,
         P1_26_PWM1_6       = 2,
         P1_26_CAP0_0       = 3,

         P1_27_GPIO         = 0,
         P1_27_CLKOUT       = 1,
         P1_27_USB_OVRCR    = 2,
         P1_27_CAP0_1       = 3,

         P1_28_GPIO         = 0,
         P1_28_MCOA2        = 1,
         P1_28_PCAP1_0      = 2,
         P1_28_MAT0_0       = 3,

         P1_29_GPIO         = 0,
         P1_29_MCOB2        = 1,
         P1_29_PCAP1_1      = 2,
         P1_29_MAT0_1       = 3,

         P1_30_GPIO         = 0,
         P1_30_VBUS         = 2,
         P1_30_AD0_4        = 3,

         P1_31_GPIO         = 0,
         P1_31_SCK1         = 2,
         P1_31_AD0_5        = 3,

         P2_0_GPIO          = 0,
         P2_0_PWM1_1        = 1,
         P2_0_TXD1          = 2,

         P2_1_GPIO          = 0,
         P2_1_PWM1_2        = 1,
         P2_1_RXD1          = 2,

         P2_2_GPIO          = 0,
         P2_2_PWM1_3        = 1,
         P2_2_CTS1          = 2,

         P2_3_GPIO          = 0,
         P2_3_PWM1_4        = 1,
         P2_3_DCD1          = 2,

         P2_4_GPIO          = 0,
         P2_4_PWM1_5        = 1,
         P2_4_DSR1          = 2,

         P2_5_GPIO          = 0,
         P2_5_PWM1_6        = 1,
         P2_5_DTR1          = 2,

         P2_6_GPIO          = 0,
         P2_6_PCAP1_0       = 1,
         P2_6_RI1           = 2,

         P2_7_GPIO          = 0,
         P2_7_RD2           = 1,
         P2_7_RTS1          = 2,

         P2_8_GPIO          = 0,
         P2_8_TD2           = 1,
         P2_8_TXD2          = 2,
         P2_8_ENET_MDC      = 3,

         P2_9_GPIO          = 0,
         P2_9_USB_CONNECT   = 1,
         P2_9_RXD2          = 2,
         P2_9_ENET_MDIO     = 3,

         P2_10_GPIO         = 0,
         P2_10_EINT0        = 1,
         P2_10_NMI          = 2,

         P2_11_GPIO         = 0,
         P2_11_EINT1        = 1,
         P2_11_I2STX_CLK    = 3,

         P2_12_GPIO         = 0,
         P2_12_EINT2        = 1,
         P2_12_I2STX_WS     = 3,

         P2_13_GPIO         = 0,
         P2_13_EINT3        = 1,
         P2_13_I2STX_SDA    = 3,

         P3_25_GPIO         = 0,
         P3_25_MAT0_0       = 2,
         P3_25_PWM1_2       = 3,

         P3_26_GPIO         = 0,
         P3_26_STCLK        = 1,
         P3_26_MAT0_1       = 2,
         P3_26_PWM1_3       = 3,

         P4_28_GPIO         = 0,
         P4_28_RX_MCLK      = 1,
         P4_28_MAT2_0       = 2,
         P4_28_TXD3         = 3,

         P4_29_GPIO         = 0,
         P4_29_TX_MCLK      = 1,
         P4_29_MAT2_1       = 2,
         P4_29_RXD3         = 3,
      } PinFunction_e;

      /** Pin configuration structure */
      typedef struct
      {
         Port_e Portnum;    /**< Port Number, should be PINSEL_PORT_x,
                                     where x should be in range from 0 to 4 */
         Pin_e Pinnum;     /**< Pin Number, should be PINSEL_PIN_x,
                               where x should be in range from 0 to 31 */
         PinFunction_e Funcnum;    /**< Function Number, should be PINSEL_FUNC_x,
                               where x should be in range from 0 to 3 */
         PinMode_e Pinmode;    /**< Pin Mode, should be:
                               - PINSEL_PINMODE_PULLUP: Internal pull-up resistor
                               - PINSEL_PINMODE_TRISTATE: Tri-state
                               - PINSEL_PINMODE_PULLDOWN: Internal pull-down resistor */
         PinOpenDrain_e OpenDrain;  /**< OpenDrain mode, should be:
                               - PINSEL_PINMODE_NORMAL: Pin is in the normal (not open drain) mode
                               - PINSEL_PINMODE_OPENDRAIN: Pin is in the open drain mode */
      } CFG_Type;



      /*****************************************************
       * Constructors
       *****************************************************/
      /** 
       * @brief Parametrised constructor
       *
       * @param[in] Pin pin number, should be PIN_Pn_x,
       *             where n should be in range from 0 to 4 and
       *             where x should be in range from 0 to 31
       * @param[in] funcnum Function Number
       * @param[in] Pinmode Pin Mode, should be from PinFunction_e enum
       * @param[in] OpenDrain disbable/enable open drain
       *                - PINMODE_NORMAL: Pin is in the normal (not open drain) mode
       *                - PINMODE_OPENDRAIN: Pin is in the open drain mode 
       */
      PINSEL( Port_e _portnum, Pin_e _pinnum, PinFunction_e Funcnum,
              PinMode_e Pinmode = PINMODE_PULLUP, PinOpenDrain_e OpenDrain = PINMODE_NORMAL);

      /*********************************************************************//**
       * @brief       Configure Pin corresponding to specified parameters passed
       *              in the PinCfg
       * @param[in]   PinCfg  Pointer to a PINSEL_CFG_Type structure
       *                    that contains the configuration information for the
       *                    specified pin.
       * @return      None
       **********************************************************************/
      PINSEL(CFG_Type *PinCfg);

      /*****************************************************
       * Functions: modifiers (set), selectors (get)
       *****************************************************/
      /*********************************************************************//**
       * @brief       Setup the pin selection function
       * @param[in]   pinnum Pin number should be one of the values from PortPin_e 
       *
       * @param[in]   funcnum should be from PinFunction_e enum
       *
       * @return      None
       **********************************************************************/
      void SetPinFunc ( PinFunction_e funcnum);

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
       * @param[in]   pinnum Pin number should be one of the values from PortPin_e 
       *
       * @param[in]   modenum: Mode number,
       *              should be one of the following:
       *              - PINMODE_PULLUP : Internal pull-up resistor
       *              - PINMODE_TRISTATE : Tri-state
       *              - PINMODE_PULLDOWN : Internal pull-down resistor
       *
       * @return      None
       **********************************************************************/
      void SetResistorMode ( PinMode_e modenum);

      /*********************************************************************//**
       * @brief       Setup Open drain mode for each pin
       * @param[in]   pinnum Pin number should be one of the values from PortPin_e 
       *
       * @param[in]   modenum  Open drain mode number,
       *              should be one of the following:
       *              - PINMODE_NORMAL : Pin is in the normal (not open drain) mode
       *              - PINMODE_OPENDRAIN : Pin is in the open drain mode
       *
       * @return      None
       **********************************************************************/
      void SetOpenDrainMode(  PinOpenDrain_e modenum);

      /*********************************************************************//**
       * @brief       Setup I2C0 pins (P0_27 - SDA0; P0_28 - SCL0)
       * @param[in]   i2cPinMode I2C pin mode,
       *              should be one of the following:
       *              - I2C_Normal_Mode : The standard drive mode
       *              - I2C_Fast_Mode : Fast Mode Plus drive mode
       *
       * @param[in]   filterSlewRateEnable  should be:
       *              - ENABLE: Enable filter and slew rate.
       *              - DISABLE: Disable filter and slew rate.
       *
       * @return      None
       **********************************************************************/
      void SetI2C0Pins(I2C_Mode_e i2cPinMode, FunctionalState filterSlewRateEnable);

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
      Pin_e pinnum;
      Port_e portnum;
      /*****************************************************
       * Private functions
       *****************************************************/

      /*****************************************************
       * Private attributes
       *****************************************************/
};


#endif /* _PINSEL_H_ */
