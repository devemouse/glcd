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
#define PACKAGE LQFP_1

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

/***********************************************************************
 ** Macros define for Pin Number of Port
 **********************************************************************/

typedef enum {
  /* pin name     = (port <<8) | pin */

   /* PORT 0
    * Pins 12, 13, 14, and 31 of this port are not available.
    */
   PINSEL_P0_0    = (0<<8) | 0,
   PINSEL_P0_1    = (0<<8) | 1,
   PINSEL_P0_2    = (0<<8) | 2,
   PINSEL_P0_3    = (0<<8) | 3,
#if PACKAGE == LQFP_1
   PINSEL_P0_4    = (0<<8) | 4,
   PINSEL_P0_5    = (0<<8) | 5,
#endif
   PINSEL_P0_6    = (0<<8) | 6,
   PINSEL_P0_7    = (0<<8) | 7,
   PINSEL_P0_8    = (0<<8) | 8,
   PINSEL_P0_9    = (0<<8) | 9,
   PINSEL_P0_10   = (0<<8) | 10,
   PINSEL_P0_11   = (0<<8) | 11,
   PINSEL_P0_15   = (0<<8) | 15,
   PINSEL_P0_16   = (0<<8) | 16,
   PINSEL_P0_17   = (0<<8) | 17,
   PINSEL_P0_18   = (0<<8) | 18,
#if PACKAGE == LQFP_1
   PINSEL_P0_19   = (0<<8) | 19,
   PINSEL_P0_20   = (0<<8) | 20,
   PINSEL_P0_21   = (0<<8) | 21,
#endif
   PINSEL_P0_22   = (0<<8) | 22,
#if PACKAGE == LQFP_1
   PINSEL_P0_23   = (0<<8) | 23,
   PINSEL_P0_24   = (0<<8) | 24,
#endif
   PINSEL_P0_25   = (0<<8) | 25,
   PINSEL_P0_26   = (0<<8) | 26,
#if PACKAGE == LQFP_1
   PINSEL_P0_27   = (0<<8) | 27,
   PINSEL_P0_28   = (0<<8) | 28,
#endif
   PINSEL_P0_29   = (0<<8) | 29,
   PINSEL_P0_30   = (0<<8) | 30,

   /*  PORT 1
    *  Pins 2, 3, 5, 6, 7, 11, 12, and 13 of this port are not  available.
    */
   PINSEL_P1_0    = (1<<8) | 0,
   PINSEL_P1_1    = (1<<8) | 1,
   PINSEL_P1_4    = (1<<8) | 4,
   PINSEL_P1_8    = (1<<8) | 8,
   PINSEL_P1_9    = (1<<8) | 9,
   PINSEL_P1_10   = (1<<8) | 10,
   PINSEL_P1_14   = (1<<8) | 14,
   PINSEL_P1_15   = (1<<8) | 15,
#if PACKAGE == LQFP_1
   PINSEL_P1_16   = (1<<8) | 16,
   PINSEL_P1_17   = (1<<8) | 17,
#endif
   PINSEL_P1_18   = (1<<8) | 18,
   PINSEL_P1_19   = (1<<8) | 19,
   PINSEL_P1_20   = (1<<8) | 20,
#if PACKAGE == LQFP_1
   PINSEL_P1_21   = (1<<8) | 21,
#endif
   PINSEL_P1_22   = (1<<8) | 22,
   PINSEL_P1_23   = (1<<8) | 23,
   PINSEL_P1_24   = (1<<8) | 24,
   PINSEL_P1_25   = (1<<8) | 25,
   PINSEL_P1_26   = (1<<8) | 26,
#if PACKAGE == LQFP_1
   PINSEL_P1_27   = (1<<8) | 27,
#endif
   PINSEL_P1_28   = (1<<8) | 28,
   PINSEL_P1_29   = (1<<8) | 29,
   PINSEL_P1_30   = (1<<8) | 30,
   PINSEL_P1_31   = (1<<8) | 31,

   /* PORT 2
    * Pins 14 through 31 of this port are not available. 
    */
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
#if PACKAGE == LQFP_1
   PINSEL_P2_11   = (2<<8) | 11,
   PINSEL_P2_12   = (2<<8) | 12,
   PINSEL_P2_13   = (2<<8) | 13,
#endif

   /* PORT 3
    * Pins 0 through 24, and 27 through 31 of this port are not available.
    */
#if PACKAGE == LQFP_1
   PINSEL_P3_25   = (3<<8) | 25,
   PINSEL_P3_26   = (3<<8) | 26,
#endif

   /* PORT 4
    * Pins 0 through 27, 30, and 31 of this port are not available.
    */
   PINSEL_P4_28   = (4 << 8) | 28,
   PINSEL_P4_29   = (4 << 8) | 29,
} PINSEL_PortPin_e;

typedef enum {
   PINSEL_P0_0_GPIO          = (0 << 0),
   PINSEL_P0_0_RD1           = (1 << 0),
   PINSEL_P0_0_TXD3          = (2 << 0),
   PINSEL_P0_0_SDA1          = (3 << 0),

   PINSEL_P0_1_GPIO          = (0 << 2),
   PINSEL_P0_1_TD1           = (1 << 2),
   PINSEL_P0_1_RXD3          = (2 << 2),
   PINSEL_P0_1_SCL1          = (3 << 2),

   PINSEL_P0_2_GPIO          = (0 << 4),
   PINSEL_P0_2_TXD0          = (1 << 4),
   PINSEL_P0_2_AD0_7         = (2 << 4),

   PINSEL_P0_3_GPIO          = (0 << 6),
   PINSEL_P0_3_RXD0          = (1 << 6),
   PINSEL_P0_3_AD0_6         = (2 << 6),

   PINSEL_P0_4_GPIO          = (0 << 8),
   PINSEL_P0_4_I2SRX_CLK     = (1 << 8),
   PINSEL_P0_4_RD2           = (2 << 8),
   PINSEL_P0_4_CAP2_0        = (3 << 8),

   PINSEL_P0_5_GPIO          = (0 << 10),
   PINSEL_P0_5_I2SRX_WS      = (1 << 10),
   PINSEL_P0_5_TD2           = (2 << 10),
   PINSEL_P0_5_CAP2_1        = (3 << 10),

   PINSEL_P0_6_GPIO          = (0 << 12),
   PINSEL_P0_6_I2SRX_SDA     = (1 << 12),
   PINSEL_P0_6_SSEL1         = (2 << 12),
   PINSEL_P0_6_MAT2_0        = (3 << 12),

   PINSEL_P0_7_GPIO          = (0 << 14),
   PINSEL_P0_7_I2STX_CLK     = (1 << 14),
   PINSEL_P0_7_SCK1          = (2 << 14),
   PINSEL_P0_7_MAT2_1        = (3 << 14),

   PINSEL_P0_8_GPIO          = (0 << 16),
   PINSEL_P0_8_I2STX_WS      = (1 << 16),
   PINSEL_P0_8_MISO1         = (2 << 16),
   PINSEL_P0_8_MAT2_2        = (3 << 16),

   PINSEL_P0_9_GPIO          = (0 << 18),
   PINSEL_P0_9_I2STX_SDA     = (1 << 18),
   PINSEL_P0_9_MOSI1         = (2 << 18),
   PINSEL_P0_9_MAT2_3        = (3 << 18),

   PINSEL_P0_10_GPIO         = (0 << 20),
   PINSEL_P0_10_XD2          = (1 << 20),
   PINSEL_P0_10_SDA2         = (2 << 20),
   PINSEL_P0_10_MAT3_0       = (3 << 20),

   PINSEL_P0_11_GPIO         = (0 << 22),
   PINSEL_P0_11_RXD2         = (1 << 22),
   PINSEL_P0_11_SCL2         = (2 << 22),
   PINSEL_P0_11_MAT3_1       = (3 << 22),

   PINSEL_P0_15_GPIO         = (0 << 30),
   PINSEL_P0_15_XD1          = (1 << 30),
   PINSEL_P0_15_SCK0         = (2 << 30),
   PINSEL_P0_15_SCK          = (3 << 30),

   PINSEL_P0_16_GPIO         = (0 << 0),
   PINSEL_P0_16_RXD1         = (1 << 0),
   PINSEL_P0_16_SSEL0        = (2 << 0),
   PINSEL_P0_16_SSEL         = (3 << 0),

   PINSEL_P0_17_GPIO         = (0 << 2),
   PINSEL_P0_17_CTS1         = (1 << 2),
   PINSEL_P0_17_MISO0        = (2 << 2),
   PINSEL_P0_17_MISO         = (3 << 2),

   PINSEL_P0_18_GPIO         = (0 << 4),
   PINSEL_P0_18_DCD1         = (1 << 4),
   PINSEL_P0_18_MOSI0        = (2 << 4),
   PINSEL_P0_18_MOSI         = (3 << 4),

   PINSEL_P0_19_GPIO         = (0 << 6),
   PINSEL_P0_19_DSR1         = (1 << 6),
   PINSEL_P0_19_SDA1         = (3 << 6),

   PINSEL_P0_20_GPIO         = (0 << 8),
   PINSEL_P0_20_DTR1         = (1 << 8),
   PINSEL_P0_20_SCL1         = (3 << 8),

   PINSEL_P0_21_GPIO         = (0 << 10),
   PINSEL_P0_21_RI1          = (1 << 10),
   PINSEL_P0_21_RD1          = (3 << 10),

   PINSEL_P0_22_GPIO         = (0 << 12),
   PINSEL_P0_22_RTS1         = (1 << 12),
   PINSEL_P0_22_TD1          = (3 << 12),

   PINSEL_P0_23_GPIO         = (0 << 14),
   PINSEL_P0_23_AD0_0        = (1 << 14),
   PINSEL_P0_23_I2SRX_CLK    = (2 << 14),
   PINSEL_P0_23_CAP3_0       = (3 << 14),

   PINSEL_P0_24_GPIO         = (0 << 16),
   PINSEL_P0_24_AD0_1        = (1 << 16),
   PINSEL_P0_24_I2SRX_WS     = (2 << 16),
   PINSEL_P0_24_CAP3_1       = (3 << 16),

   PINSEL_P0_25_GPIO         = (0 << 18),
   PINSEL_P0_25_AD0_2        = (1 << 18),
   PINSEL_P0_25_I2SRX_SDA    = (2 << 18),
   PINSEL_P0_25_TXD3         = (3 << 18),

   PINSEL_P0_26_GPIO         = (0 << 20),
   PINSEL_P0_26_AD0_3        = (1 << 20),
   PINSEL_P0_26_AOUT         = (2 << 20),
   PINSEL_P0_26_RXD3         = (3 << 20),

   PINSEL_P0_27_GPIO         = (0 << 22),
   PINSEL_P0_27_SDA0         = (1 << 22),
   PINSEL_P0_27_USB_SDA      = (2 << 22),

   PINSEL_P0_28_GPIO         = (0 << 24),
   PINSEL_P0_28_SCL0         = (1 << 24),
   PINSEL_P0_28_USB_SCL      = (2 << 24),

   PINSEL_P0_29_GPIO         = (0 << 26),
   PINSEL_P0_29_USB_D_PLUS   = (1 << 26),

   PINSEL_P0_30_GPIO         = (0 << 28),
   PINSEL_P0_30_USB_D_MINUS  = (1 << 28),

   PINSEL_P1_0_GPIO          = (0 << 0),
   PINSEL_P1_0_ENET_TXD0     = (1 << 0),

   PINSEL_P1_1_GPIO          = (0 << 2),
   PINSEL_P1_1_ENET_TXD1     = (1 << 2),

   PINSEL_P1_4_GPIO          = (0 << 8),
   PINSEL_P1_4_ENET_TX_EN    = (1 << 8),

   PINSEL_P1_8_GPIO          = (0 << 16),
   PINSEL_P1_8_ENET_CRS      = (1 << 16),

   PINSEL_P1_9_GPIO          = (0 << 18),
   PINSEL_P1_9_ENET_RXD0     = (1 << 18),

   PINSEL_P1_10_GPIO         = (0 << 20),
   PINSEL_P1_10_ENET_RXD1    = (1 << 20),

   PINSEL_P1_14_GPIO         = (0 << 28),
   PINSEL_P1_14_ENET_RX_ER   = (1 << 28),

   PINSEL_P1_15_GPIO         = (0 << 30),
   PINSEL_P1_15_ENET_REF_CLK = (1 << 30),

   PINSEL_P1_16_GPIO         = (0 << 0),
   PINSEL_P1_16_ENET_MDC     = (1 << 0),

   PINSEL_P1_17_GPIO         = (0 << 2),
   PINSEL_P1_17_ENET_MDIO    = (1 << 2),

   PINSEL_P1_18_GPIO         = (0 << 4),
   PINSEL_P1_18_USB_UP_LED   = (1 << 4),
   PINSEL_P1_18_PWM1_1       = (2 << 4),
   PINSEL_P1_18_CAP1_0       = (3 << 4),

   PINSEL_P1_19_GPIO         = (0 << 6),
   PINSEL_P1_19_MCOA0        = (1 << 6),
   PINSEL_P1_19_USB_PPWR     = (2 << 6),
   PINSEL_P1_19_CAP1_1       = (3 << 6),

   PINSEL_P1_20_GPIO         = (0 << 8),
   PINSEL_P1_20_MCI0         = (1 << 8),
   PINSEL_P1_20_PWM1_2       = (2 << 8),
   PINSEL_P1_20_SCK0         = (3 << 8),

   PINSEL_P1_21_GPIO         = (0 << 10),
   PINSEL_P1_21_MCABORT      = (1 << 10),
   PINSEL_P1_21_PWM1_3       = (2 << 10),
   PINSEL_P1_21_SSEL0        = (3 << 10),

   PINSEL_P1_22_GPIO         = (0 << 12),
   PINSEL_P1_22_MCOB0        = (1 << 12),
   PINSEL_P1_22_USB_PWRD     = (2 << 12),
   PINSEL_P1_22_MAT1_0       = (3 << 12),

   PINSEL_P1_23_GPIO         = (0 << 14),
   PINSEL_P1_23_MCI1         = (1 << 14),
   PINSEL_P1_23_PWM1_4       = (2 << 14),
   PINSEL_P1_23_MISO0        = (3 << 14),

   PINSEL_P1_24_GPIO         = (0 << 16),
   PINSEL_P1_24_MCI2         = (1 << 16),
   PINSEL_P1_24_PWM1_5       = (2 << 16),
   PINSEL_P1_24_MOSI0        = (3 << 16),

   PINSEL_P1_25_GPIO         = (0 << 18),
   PINSEL_P1_25_MCOA1        = (1 << 18),
   PINSEL_P1_25_MAT1_1       = (3 << 18),

   PINSEL_P1_26_GPIO         = (0 << 20),
   PINSEL_P1_26_MCOB1        = (1 << 20),
   PINSEL_P1_26_PWM1_6       = (2 << 20),
   PINSEL_P1_26_CAP0_0       = (3 << 20),

   PINSEL_P1_27_GPIO         = (0 << 22),
   PINSEL_P1_27_CLKOUT       = (1 << 22),
   PINSEL_P1_27_USB_OVRCR    = (2 << 22),
   PINSEL_P1_27_CAP0_1       = (3 << 22),

   PINSEL_P1_28_GPIO         = (0 << 24),
   PINSEL_P1_28_MCOA2        = (1 << 24),
   PINSEL_P1_28_PCAP1_0      = (2 << 24),
   PINSEL_P1_28_MAT0_0       = (3 << 24),

   PINSEL_P1_29_GPIO         = (0 << 26),
   PINSEL_P1_29_MCOB2        = (1 << 26),
   PINSEL_P1_29_PCAP1_1      = (2 << 26),
   PINSEL_P1_29_MAT0_1       = (3 << 26),

   PINSEL_P1_30_GPIO         = (0 << 28),
   PINSEL_P1_30_VBUS         = (2 << 28),
   PINSEL_P1_30_AD0_4        = (3 << 28),

   PINSEL_P1_31_GPIO         = (0 << 30),
   PINSEL_P1_31_SCK1         = (2 << 30),
   PINSEL_P1_31_AD0_5        = (3 << 30),

   PINSEL_P2_0_GPIO          = (0 << 0),
   PINSEL_P2_0_PWM1_1        = (1 << 0),
   PINSEL_P2_0_TXD1          = (2 << 0),

   PINSEL_P2_1_GPIO          = (0 << 2),
   PINSEL_P2_1_PWM1_2        = (1 << 2),
   PINSEL_P2_1_RXD1          = (2 << 2),

   PINSEL_P2_2_GPIO          = (0 << 4),
   PINSEL_P2_2_PWM1_3        = (1 << 4),
   PINSEL_P2_2_CTS1          = (2 << 4),

   PINSEL_P2_3_GPIO          = (0 << 6),
   PINSEL_P2_3_PWM1_4        = (1 << 6),
   PINSEL_P2_3_DCD1          = (2 << 6),

   PINSEL_P2_4_GPIO          = (0 << 8),
   PINSEL_P2_4_PWM1_5        = (1 << 8),
   PINSEL_P2_4_DSR1          = (2 << 8),

   PINSEL_P2_5_GPIO          = (0 << 10),
   PINSEL_P2_5_PWM1_6        = (1 << 10),
   PINSEL_P2_5_DTR1          = (2 << 10),

   PINSEL_P2_6_GPIO          = (0 << 12),
   PINSEL_P2_6_PCAP1_0       = (1 << 12),
   PINSEL_P2_6_RI1           = (2 << 12),

   PINSEL_P2_7_GPIO          = (0 << 14),
   PINSEL_P2_7_RD2           = (1 << 14),
   PINSEL_P2_7_RTS1          = (2 << 14),

   PINSEL_P2_8_GPIO          = (0 << 16),
   PINSEL_P2_8_TD2           = (1 << 16),
   PINSEL_P2_8_TXD2          = (2 << 16),
   PINSEL_P2_8_ENET_MDC      = (3 << 16),

   PINSEL_P2_9_GPIO          = (0 << 18),
   PINSEL_P2_9_USB_CONNECT   = (1 << 18),
   PINSEL_P2_9_RXD2          = (2 << 18),
   PINSEL_P2_9_ENET_MDIO     = (3 << 18),

   PINSEL_P2_10_GPIO         = (0 << 20),
   PINSEL_P2_10_EINT0        = (1 << 20),
   PINSEL_P2_10_NMI          = (2 << 20),

   PINSEL_P2_11_GPIO         = (0 << 22),
   PINSEL_P2_11_EINT1        = (1 << 22),
   PINSEL_P2_11_I2STX_CLK    = (3 << 22),

   PINSEL_P2_12_GPIO         = (0 << 24),
   PINSEL_P2_12_EINT2        = (1 << 24),
   PINSEL_P2_12_I2STX_WS     = (3 << 24),

   PINSEL_P2_13_GPIO         = (0 << 26),
   PINSEL_P2_13_EINT3        = (1 << 26),
   PINSEL_P2_13_I2STX_SDA    = (3 << 26),

   PINSEL_P3_25_GPIO         = (0 << 18),
   PINSEL_P3_25_MAT0_0       = (2 << 18),
   PINSEL_P3_25_PWM1_2       = (3 << 18),

   PINSEL_P3_26_GPIO         = (0 << 20),
   PINSEL_P3_26_STCLK        = (1 << 20),
   PINSEL_P3_26_MAT0_1       = (2 << 20),
   PINSEL_P3_26_PWM1_3       = (3 << 20),

   PINSEL_P4_28_GPIO         = (0 << 24),
   PINSEL_P4_28_RX_MCLK      = (1 << 24),
   PINSEL_P4_28_MAT2_0       = (2 << 24),
   PINSEL_P4_28_TXD3         = (3 << 24),

   PINSEL_P4_29_GPIO         = (0 << 26),
   PINSEL_P4_29_TX_MCLK      = (1 << 26),
   PINSEL_P4_29_MAT2_1       = (2 << 26),
   PINSEL_P4_29_RXD3         = (3 << 26),

} PINSEL_PinFunction_e;


/***********************************************************************
 * Macros define for Pin mode
 **********************************************************************/
typedef enum {
   PINSEL_PINMODE_PULLUP   = 0, /**< Internal pull-up resistor */
   PINSEL_PINMODE_REPEATER = 1, /**< If the pin is at a logic high and enables
                                     the pull-down resistor if the pin is at a
                                     logic low */
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
    PINSEL_PinFunction_e Funcnum; /**< Function Number, should be PINSEL_FUNC_x,
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
       * @brief Parametrised constructor
       *
       * @param[in] Pin pin number, should be PINSEL_Pn_x,
       *             where n should be in range from 0 to 4 and
       *             where x should be in range from 0 to 31
       * @param[in] funcnum Function Number
       * @param[in] Pinmode Pin Mode, should be:
       *                - PINSEL_PINMODE_PULLUP: Internal pull-up resistor
       *                - PINSEL_PINMODE_TRISTATE: Tri-state
       *                - PINSEL_PINMODE_PULLDOWN: Internal pull-down resistor
       * @param[in] OpenDrain disbable/enable open drain
       *                - PINSEL_PINMODE_NORMAL: Pin is in the normal (not open drain) mode
       *                - PINSEL_PINMODE_OPENDRAIN: Pin is in the open drain mode 
       * @return      None
       */
      PINSEL( PINSEL_PortPin_e Pin, PINSEL_PinFunction_e Funcnum,
              PINSEL_PinMode_e Pinmode, PINSEL_PinOpenDrain_e OpenDrain);

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
      static void SetPinFunc ( PINSEL_PortPin_e pinnum, PINSEL_PinFunction_e funcnum);

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
