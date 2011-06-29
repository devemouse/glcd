#include "spi.h"
#include "LPC17xx.h"
#include "clkpwr.h"

SPI::SPI()
{
   /* Set up clock and power for UART module */
   CLKPWR::ConfigPPWR (CLKPWR_PCONP_PCSPI, ENABLE);
   /* As default, peripheral clock for UART0 module
    * is set to FCCLK / 2 */
   CLKPWR::SetPCLKDiv(CLKPWR_PCLKSEL_SPI, CLKPWR_PCLKSEL_CCLK_DIV_2);
}
