/**************************************************************************//**
 * @file    Lamp.h
 * @brief   File contains class declaration of Lamp class.
 * @author  Dawid Bazan <dawidbazan@gmail.com>
 * @author  Dariusz Synowiec <devemouse@gmail.com>
 * @version 0.1.0
 * @date    May 2011
 *****************************************************************************/

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
 * Lamp provides abstraction for a lamp connected to uC.
 */
class Lamp {
   public:
      /*****************************************************
       * Constructors
       *****************************************************/
      /**
       * Default empty construcor
       */
      Lamp() {};

      /**
       * Constructor allowing to assign a pin, change the initial state and specify if lamp logic is inverted or not.
       * @param[in] Pin port and pin to which Lamp is connected.
       * @param[in] initial_state false=lamp off(default), true=lamp on.
       * @param[in] inverted false=lamp is ON by setting pin to "0", true=lamp is OFF by setting pin to "1".
       */
      Lamp(Port_e _portnum, Pin_e _pinnum, bool initial_state /* = false */, bool inverted /* = false */);

      /**
       * Default destructor
       */
      ~Lamp() {};

      /*****************************************************
       * Functions: modifiers (set), selectors (get)
       *****************************************************/
      /**
       * Function used for verifying if a lamp is on or not.
       * @return true if lamp is on, false otherwise.
       */
      bool is_on() {return ((port->FIOSET & (1 << pinnum)) > 0);}

      /**
       * Turns the lap on
       */
      void __INLINE on(void) {port->FIOSET = (_inverted << pinnum);}

      /**
       * Turns the lap off
       */
      void __INLINE off(void) {port->FIOCLR = (_inverted << pinnum);}

      /**
       * Toggles the lap
       */
      void __INLINE toggle(void) {port->FIOPIN ^= (1 << pinnum);}

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
      Pin_e pinnum;
      volatile LPC_GPIO_TypeDef *port;

      bool _is_on; /**< Whether a lamp is on. */
      bool _inverted; /**< Whether a lamp is inverted. */
      uint32_t on_mask;
};
