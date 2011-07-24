/**************************************************************************//**
 * @file    pinout.h
 * @brief   : Contains list of pins available on LPC17xx
 * @author  Dariusz Synowiec <devemouse@gmail.com>
 * @version 0.0.0dev
 * @date    July 2011
 *****************************************************************************/
#ifndef _PINOUT_H_
#define _PINOUT_H_

/******************************************************************************
 * Include files
 *****************************************************************************/
#include "LPC17xx.h"

/***********************************************************************
 ** Macros define for Pin Number of Port
 **********************************************************************/

typedef enum {
  /* pin name     = (port <<8) | pin */

   /* PORT 0
    * Pins 12, 13, 14, and 31 of this port are not available.
    */
   PIN_P0_0    = (0<<8) | 0,
   PIN_P0_1    = (0<<8) | 1,
   PIN_P0_2    = (0<<8) | 2,
   PIN_P0_3    = (0<<8) | 3,
#ifdef LQFP_100
   PIN_P0_4    = (0<<8) | 4,
   PIN_P0_5    = (0<<8) | 5,
#endif
   PIN_P0_6    = (0<<8) | 6,
   PIN_P0_7    = (0<<8) | 7,
   PIN_P0_8    = (0<<8) | 8,
   PIN_P0_9    = (0<<8) | 9,
   PIN_P0_10   = (0<<8) | 10,
   PIN_P0_11   = (0<<8) | 11,
   PIN_P0_15   = (0<<8) | 15,
   PIN_P0_16   = (0<<8) | 16,
   PIN_P0_17   = (0<<8) | 17,
   PIN_P0_18   = (0<<8) | 18,
#ifdef LQFP_100
   PIN_P0_19   = (0<<8) | 19,
   PIN_P0_20   = (0<<8) | 20,
   PIN_P0_21   = (0<<8) | 21,
#endif
   PIN_P0_22   = (0<<8) | 22,
#ifdef LQFP_100
   PIN_P0_23   = (0<<8) | 23,
   PIN_P0_24   = (0<<8) | 24,
#endif
   PIN_P0_25   = (0<<8) | 25,
   PIN_P0_26   = (0<<8) | 26,
#ifdef LQFP_100
   PIN_P0_27   = (0<<8) | 27,
   PIN_P0_28   = (0<<8) | 28,
#endif
   PIN_P0_29   = (0<<8) | 29,
   PIN_P0_30   = (0<<8) | 30,

   /*  PORT 1
    *  Pins 2, 3, 5, 6, 7, 11, 12, and 13 of this port are not  available.
    */
   PIN_P1_0    = (1<<8) | 0,
   PIN_P1_1    = (1<<8) | 1,
   PIN_P1_4    = (1<<8) | 4,
   PIN_P1_8    = (1<<8) | 8,
   PIN_P1_9    = (1<<8) | 9,
   PIN_P1_10   = (1<<8) | 10,
   PIN_P1_14   = (1<<8) | 14,
   PIN_P1_15   = (1<<8) | 15,
#ifdef LQFP_100
   PIN_P1_16   = (1<<8) | 16,
   PIN_P1_17   = (1<<8) | 17,
#endif
   PIN_P1_18   = (1<<8) | 18,
   PIN_P1_19   = (1<<8) | 19,
   PIN_P1_20   = (1<<8) | 20,
#ifdef LQFP_100
   PIN_P1_21   = (1<<8) | 21,
#endif
   PIN_P1_22   = (1<<8) | 22,
   PIN_P1_23   = (1<<8) | 23,
   PIN_P1_24   = (1<<8) | 24,
   PIN_P1_25   = (1<<8) | 25,
   PIN_P1_26   = (1<<8) | 26,
#ifdef LQFP_100
   PIN_P1_27   = (1<<8) | 27,
#endif
   PIN_P1_28   = (1<<8) | 28,
   PIN_P1_29   = (1<<8) | 29,
   PIN_P1_30   = (1<<8) | 30,
   PIN_P1_31   = (1<<8) | 31,

   /* PORT 2
    * Pins 14 through 31 of this port are not available. 
    */
   PIN_P2_0    = (2<<8) | 0,
   PIN_P2_1    = (2<<8) | 1,
   PIN_P2_2    = (2<<8) | 2,
   PIN_P2_3    = (2<<8) | 3,
   PIN_P2_4    = (2<<8) | 4,
   PIN_P2_5    = (2<<8) | 5,
   PIN_P2_6    = (2<<8) | 6,
   PIN_P2_7    = (2<<8) | 7,
   PIN_P2_8    = (2<<8) | 8,
   PIN_P2_9    = (2<<8) | 9,
   PIN_P2_10   = (2<<8) | 10,
#ifdef LQFP_100
   PIN_P2_11   = (2<<8) | 11,
   PIN_P2_12   = (2<<8) | 12,
   PIN_P2_13   = (2<<8) | 13,
#endif

   /* PORT 3
    * Pins 0 through 24, and 27 through 31 of this port are not available.
    */
#ifdef LQFP_100
   PIN_P3_25   = (3<<8) | 25,
   PIN_P3_26   = (3<<8) | 26,
#endif

   /* PORT 4
    * Pins 0 through 27, 30, and 31 of this port are not available.
    */
   PIN_P4_28   = (4 << 8) | 28,
   PIN_P4_29   = (4 << 8) | 29,
} PortPin_e;

#endif /* _PINOUT_H_ */
