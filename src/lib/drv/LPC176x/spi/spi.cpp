
#include "spi.h"
#include "clkpwr.h"
#include "pinsel.h"


SPI::SPI()
{
   SPIx = LPC_SPI;

   SPI_CFG_Type SPI_InitStruct;

   SPI_InitStruct.CPHA = SPI_CPHA_FIRST;
   SPI_InitStruct.CPOL = SPI_CPOL_HI;
   SPI_InitStruct.ClockRate = 1000000;
   SPI_InitStruct.DataOrder = SPI_DATA_MSB_FIRST;
   SPI_InitStruct.Databit = SPI_DATABIT_8;
   SPI_InitStruct.Mode = SPI_MASTER_MODE;

   Init(SPI_InitStruct);
}

SPI::SPI(SPI_CFG_Type &SPI_ConfigStruct)
{
   Init(SPI_ConfigStruct);
}



Status SPI::SetClock ( uint32_t target_clock)
{
    uint32_t spi_pclk;
    uint32_t prescale, temp = 0;

    spi_pclk =  CLKPWR::GetPCLK (CLKPWR_PCLKSEL_SPI);

    prescale = 8;

    while (temp < spi_pclk)
    {
        prescale++;
        if(prescale > 255)
        {
            break;
        }

        temp = target_clock * prescale;
    }

    if ((prescale < 8) && (target_clock > spi_pclk))
    {
        return ERROR;
    }

    SPIx->SPCCR = SPI_SPCCR_COUNTER(prescale);

    return SUCCESS;
}



void SPI::PinConfig(SPI_Mode_e spiMode)
{
    // SCK pin
    PINSEL sckPin(PIN_P0_15, PINSEL::P0_15_SCK, PINSEL::PINMODE_PULLUP);


    // SSEL pin
    if (spiMode == SPI_SLAVE_MODE)
    {
       PINSEL sselPin (PIN_P0_16, PINSEL::P0_16_SSEL, PINSEL::PINMODE_PULLUP);
    }
    else
    {
       // Release SSEL pin as default function
       PINSEL sselPin(PIN_P0_16, PINSEL::P0_16_GPIO, PINSEL::PINMODE_PULLUP);
    }

    // MISO pin
    PINSEL misoPin(PIN_P0_17, PINSEL::P0_17_MISO, PINSEL::PINMODE_PULLUP);

    // MOSI pin
    PINSEL mosiPin(PIN_P0_18, PINSEL::P0_18_MOSI, PINSEL::PINMODE_PULLUP);
}

void SPI::DeInit()
{
    if (SPIx == LPC_SPI)
    {
        /* Set up clock and power for SPI module */
       CLKPWR::ConfigPPWR (CLKPWR_PCONP_PCSPI, DISABLE);
    }
}





void SPI::Write( uint16_t Data)
{
    SPIx->SPDR = Data & SPI_SPDR_BITMASK;
}



uint16_t SPI::Read()
{
    return ((uint16_t) (SPIx->SPDR & SPI_SPDR_BITMASK));
}



void SPI::IntCmd( FunctionalState NewState)
{
    if (NewState == ENABLE)
    {
        SPIx->SPCR |= SPI_SPCR_SPIE;
    }
    else
    {
        SPIx->SPCR &= (~SPI_SPCR_SPIE) & SPI_SPCR_BITMASK;
    }
}


IntStatus SPI::GetIntStatus ()
{
    return ((SPIx->SPINT & SPI_SPINT_INTFLAG) ? SET : RESET);
}


void SPI::ClearIntPending()
{
    SPIx->SPINT = SPI_SPINT_INTFLAG;
}


SPI_Status_t SPI::GetStatus()
{
    return ((SPI_Status_t)(SPIx->SPSR & SPI_SPSR_BITMASK));
}



FlagStatus SPI::CheckStatus (SPI_Status_t inputSPIStatus,  uint8_t SPIStatus)
{
    return (((uint32_t)inputSPIStatus & SPIStatus) ? SET : RESET);
}



void SPI::Init(SPI_CFG_Type &SPI_ConfigStruct)
{
    /* Set up clock and power for UART module */
    CLKPWR::ConfigPPWR (CLKPWR_PCONP_PCSPI, ENABLE);
    /* As default, peripheral clock for UART0 module
     * is set to FCCLK / 2 */
    CLKPWR::SetPCLKDiv(CLKPWR_PCLKSEL_SPI, CLKPWR_PCLKSEL_CCLK_DIV_2);

    PinConfig( SPI_ConfigStruct.Mode);

    // Configure SPI, interrupt is disable as default
    SPIx->SPCR = ((SPI_ConfigStruct.CPHA) | (SPI_ConfigStruct.CPOL) \
                 | (SPI_ConfigStruct.DataOrder) | (SPI_ConfigStruct.Databit) \
                 | (SPI_ConfigStruct.Mode) | SPI_SPCR_BIT_EN) & SPI_SPCR_BITMASK;

    // Set clock rate for SPI peripheral
    SetClock( SPI_ConfigStruct.ClockRate);

    // If interrupt flag is set, Write '1' to Clear interrupt flag
    if (SPIx->SPINT & SPI_SPINT_INTFLAG)
    {
        SPIx->SPINT = SPI_SPINT_INTFLAG;
    }
}
