#include "LPC17xx.h"
#include "lamp.h"

#include "clkpwr.h"
Lamp::Lamp(Pin &pin, bool initial_state = false, bool inverted = false)
   : _pin(&pin), _is_on(initial_state), _inverted(!inverted)
{
   CLKPWR::ConfigPPWR (CLKPWR_PCONP_PCGPIO, ENABLE);  // power up GPIO

   _pin->port->FIODIR |= (1 << _pin->pin);

   if (initial_state) {on();} else {off();}
}
