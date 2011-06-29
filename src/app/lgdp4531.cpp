#include "lgdp4531.h"
#include "spi.h"

GLCD::GLCD(SPI &spi)
{
   spi.set_baud(0);
}

int GLCD::initialize()
{
   return -1;
}
