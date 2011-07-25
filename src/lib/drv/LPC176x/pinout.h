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
   PORT_0   = 0,   /**< PORT 0*/
   PORT_1   = 1,   /**< PORT 1*/
   PORT_2   = 2,   /**< PORT 2*/
   PORT_3   = 3,   /**< PORT 3*/
   PORT_4   = 4,   /**< PORT 4*/
} Port_e;

typedef enum {
   PIN_0    = 0,   /**< Pin 0 */
   PIN_1    = 1,   /**< Pin 1 */
   PIN_2    = 2,   /**< Pin 2 */
   PIN_3    = 3,   /**< Pin 3 */
   PIN_4    = 4,   /**< Pin 4 */
   PIN_5    = 5,   /**< Pin 5 */
   PIN_6    = 6,   /**< Pin 6 */
   PIN_7    = 7,   /**< Pin 7 */
   PIN_8    = 8,   /**< Pin 8 */
   PIN_9    = 9,   /**< Pin 9 */
   PIN_10   = 10,  /**< Pin 10 */
   PIN_11   = 11,  /**< Pin 11 */
   PIN_12   = 12,  /**< Pin 12 */
   PIN_13   = 13,  /**< Pin 13 */
   PIN_14   = 14,  /**< Pin 14 */
   PIN_15   = 15,  /**< Pin 15 */
   PIN_16   = 16,  /**< Pin 16 */
   PIN_17   = 17,  /**< Pin 17 */
   PIN_18   = 18,  /**< Pin 18 */
   PIN_19   = 19,  /**< Pin 19 */
   PIN_20   = 20,  /**< Pin 20 */
   PIN_21   = 21,  /**< Pin 21 */
   PIN_22   = 22, /**< Pin 22 */
   PIN_23   = 23, /**< Pin 23 */
   PIN_24   = 24, /**< Pin 24 */
   PIN_25   = 25, /**< Pin 25 */
   PIN_26   = 26, /**< Pin 26 */
   PIN_27   = 27, /**< Pin 27 */
   PIN_28   = 28, /**< Pin 28 */
   PIN_29   = 29, /**< Pin 29 */
   PIN_30   = 30,  /**< Pin 30 */
   PIN_31   = 31,  /**< Pin 31 */
} Pin_e;

#endif /* _PINOUT_H_ */
