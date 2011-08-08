#include "LPC17xx.h"
#include "lamp.h"
#include "pinsel.h"
#include "clkpwr.h"

Lamp::Lamp(Port_e _portnum, Pin_e _pinnum, bool initial_state /* = false */, bool inverted /* = false */)
   : pinnum(_pinnum), _is_on(initial_state), _inverted(!inverted)
{
   CLKPWR::ConfigPPWR (CLKPWR_PCONP_PCGPIO, ENABLE);  // power up GPIO
   PINSEL pinsel( _portnum, _pinnum, PINSEL::FUNC_0); // enable GPIO function on pin

   port = &((LPC_GPIO_TypeDef*)LPC_GPIO_BASE)[_portnum];
   port->FIODIR |= (1 << pinnum);


   if (initial_state) {on();} else {off();}
}

