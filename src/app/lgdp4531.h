/**************************************************************************//**
 * @file    lgdp4531.h
 * @brief   File contains class declaration of GLCD class.
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

/**
 * GLCD provides interface to Graphical LCD lgdp4531.
 */
class GLCD {
   public:
      /*****************************************************
       * Constructors
       *****************************************************/
      /**
       * Default empty construcor
       */
      GLCD() {};

      /**
       * Constructor allowing to assign a pin, change the initial state and specify if lamp logic is inverted or not.
       * @param[in] Pin port and pin to which Lamp is connected.
       * @param[in] initial_state false=lamp off(default), true=lamp on.
       * @param[in] inverted false=lamp is ON by setting pin to "0", true=lamp is OFF by setting pin to "1".
       */

      /**
       * Default destructor
       */
      ~GLCD() {};

      /*****************************************************
       * Functions: modifiers (set), selectors (get)
       *****************************************************/

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
