
#include "spi.h"
#include "clkpwr.h"
#include "pinsel.h"


#define CHECK_PARAM(expr)

SPI::SPI()
{
   /* Set up clock and power for UART module */
   CLKPWR::ConfigPPWR (CLKPWR_PCONP_PCSPI, ENABLE);
   /* As default, peripheral clock for UART0 module
    * is set to FCCLK / 2 */
   CLKPWR::SetPCLKDiv(CLKPWR_PCLKSEL_SPI, CLKPWR_PCLKSEL_CCLK_DIV_2);
}


Status SPI::SetClock (LPC_SPI_TypeDef *SPIx, uint32_t target_clock)
{
    uint32_t spi_pclk;
    uint32_t prescale, temp = 0;

    CHECK_PARAM(PARAM_SPIx(SPIx));

    if (SPIx == (LPC_SPI_TypeDef *)LPC_SPI_BASE)
    {
        spi_pclk =  CLKPWR::GetPCLK (CLKPWR_PCLKSEL_SPI);
    }

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



void SPI::PinConfig(LPC_SPI_TypeDef *, SPI_PinCFG_Type *SPIPinCfg, int32_t spiMode)
{
    CHECK_PARAM(PARAM_SPIx(SPIx));
    CHECK_PARAM(PARAM_SPI_SCK(SPIPinCfg->SCK_Pin));
    CHECK_PARAM(PARAM_SPI_SSEL(SPIPinCfg->SSEL_Pin));
    CHECK_PARAM(PARAM_SPI_MISO(SPIPinCfg->MISO_Pin));
    CHECK_PARAM(PARAM_SPI_MOSI(SPIPinCfg->MOSI_Pin));

    // SCK pin
    switch (SPIPinCfg->SCK_Pin)
    {
    case SPI_SCK_P0_15:
       PINSEL::SetPinFunc (PINSEL_PORT_0, SPI_PINSEL_SCK_P0_15, SPI_PINFUNC_SCK_P0_15);
       PINSEL::SetResistorMode (PINSEL_PORT_0, SPI_PINSEL_SCK_P0_15, PINSEL_PINMODE_PULLUP);
        break;
    }


    // SSEL pin
    switch (SPIPinCfg->SSEL_Pin)
    {
    case SPI_SSEL_P0_16:
        if (spiMode == SPI_SLAVE_MODE)
        {
           PINSEL::SetPinFunc (PINSEL_PORT_0, SPI_PINSEL_SSEL_P0_16, SPI_PINFUNC_SSEL_P0_16);
           PINSEL::SetResistorMode (PINSEL_PORT_0, SPI_PINSEL_SSEL_P0_16, PINSEL_PINMODE_PULLUP);
        }
        else
        {
            // Release SSEL pin as default function
           PINSEL::SetPinFunc (PINSEL_PORT_0, SPI_PINSEL_SSEL_P0_16, PINSEL_FUNC_0);
           PINSEL::SetResistorMode (PINSEL_PORT_0, SPI_PINSEL_SSEL_P0_16, PINSEL_PINMODE_PULLUP);
        }
        break;
    }


    // MISO pin
    switch (SPIPinCfg->MISO_Pin)
    {
    case SPI_MISO_P0_17:
       PINSEL::SetPinFunc (PINSEL_PORT_0, SPI_PINSEL_MISO_P0_17, SPI_PINFUNC_MISO_P0_17);
       PINSEL::SetResistorMode (PINSEL_PORT_0, SPI_PINSEL_MISO_P0_17, PINSEL_PINMODE_PULLUP);
        break;
    }

    // MOSI pin
    switch (SPIPinCfg->MOSI_Pin)
    {
    case SPI_MOSI_P0_18:
       PINSEL::SetPinFunc (PINSEL_PORT_0, SPI_PINSEL_MOSI_P0_18, SPI_PINFUNC_MOSI_P0_18);
       PINSEL::SetResistorMode (PINSEL_PORT_0, SPI_PINSEL_MOSI_P0_18, PINSEL_PINMODE_PULLUP);
        break;
    }
}


void SPI::PinConfigStructInit(SPI_PinCFG_Type *SPI_PinInitStruct)
{
    SPI_PinInitStruct->MISO_Pin = SPI_MISO_P0_17;
    SPI_PinInitStruct->MOSI_Pin = SPI_MOSI_P0_18;
    SPI_PinInitStruct->SCK_Pin = SPI_SCK_P0_15;
    SPI_PinInitStruct->SSEL_Pin = SPI_SSEL_P0_16;
}


void SPI::DeInit(LPC_SPI_TypeDef* SPIx)
{
    CHECK_PARAM(PARAM_SPIx(SPIx));

    if (SPIx == (LPC_SPI_TypeDef *)LPC_SPI_BASE)
    {
        /* Set up clock and power for SPI module */
       CLKPWR::ConfigPPWR (CLKPWR_PCONP_PCSPI, DISABLE);
    }
}



void SPI::Init(LPC_SPI_TypeDef *SPIx, SPI_CFG_Type *SPI_ConfigStruct)
{
    SPI_PinCFG_Type defaultSPIPinCfg;
    uint32_t tmp;

    CHECK_PARAM(PARAM_SPIx(SPIx));

    if(SPIx == (LPC_SPI_TypeDef *)LPC_SPI_BASE)
    {
        /* Set up clock and power for UART module */
       CLKPWR::ConfigPPWR (CLKPWR_PCONP_PCSPI, ENABLE);
        /* As default, peripheral clock for UART0 module
         * is set to FCCLK / 2 */
       CLKPWR::SetPCLKDiv(CLKPWR_PCLKSEL_SPI, CLKPWR_PCLKSEL_CCLK_DIV_2);
        // Set UART0 function pin as default
        defaultSPIPinCfg.SCK_Pin = SPI_SCK_P0_15;
        defaultSPIPinCfg.SSEL_Pin = SPI_SSEL_P0_16;
        defaultSPIPinCfg.MISO_Pin = SPI_MISO_P0_17;
        defaultSPIPinCfg.MOSI_Pin = SPI_MOSI_P0_18;
        PinConfig(SPIx, &defaultSPIPinCfg, SPI_ConfigStruct->Mode);
    }

    // Configure SPI, interrupt is disable as default
    tmp = ((SPI_ConfigStruct->CPHA) | (SPI_ConfigStruct->CPOL) \
        | (SPI_ConfigStruct->DataOrder) | (SPI_ConfigStruct->Databit) \
        | (SPI_ConfigStruct->Mode) | SPI_SPCR_BIT_EN) & SPI_SPCR_BITMASK;
    // write back to SPI control register
    SPIx->SPCR = tmp;

    // Set clock rate for SPI peripheral
    SetClock(SPIx, SPI_ConfigStruct->ClockRate);

    // If interrupt flag is set, Write '1' to Clear interrupt flag
    if (SPIx->SPINT & SPI_SPINT_INTFLAG)
    {
        SPIx->SPINT = SPI_SPINT_INTFLAG;
    }
}



void SPI::ConfigStructInit(SPI_CFG_Type *SPI_InitStruct)
{
    SPI_InitStruct->CPHA = SPI_CPHA_FIRST;
    SPI_InitStruct->CPOL = SPI_CPOL_HI;
    SPI_InitStruct->ClockRate = 1000000;
    SPI_InitStruct->DataOrder = SPI_DATA_MSB_FIRST;
    SPI_InitStruct->Databit = SPI_DATABIT_8;
    SPI_InitStruct->Mode = SPI_MASTER_MODE;
}


void SPI::Cmd(LPC_SPI_TypeDef* , FunctionalState )
{

}



void SPI::SendData(LPC_SPI_TypeDef* SPIx, uint16_t Data)
{
    CHECK_PARAM(PARAM_SPIx(SPIx));

    SPIx->SPDR = Data & SPI_SPDR_BITMASK;
}



uint16_t SPI::ReceiveData(LPC_SPI_TypeDef* SPIx)
{
    CHECK_PARAM(PARAM_SPIx(SPIx));

    return ((uint16_t) (SPIx->SPDR & SPI_SPDR_BITMASK));
}



void SPI::IntCmd(LPC_SPI_TypeDef *SPIx, FunctionalState NewState)
{
    CHECK_PARAM(PARAM_SPIx(SPIx));
    CHECK_PARAM(PARAM_FUNCTIONALSTATE(NewState));

    if (NewState == ENABLE)
    {
        SPIx->SPCR |= SPI_SPCR_SPIE;
    }
    else
    {
        SPIx->SPCR &= (~SPI_SPCR_SPIE) & SPI_SPCR_BITMASK;
    }
}


IntStatus SPI::GetIntStatus (LPC_SPI_TypeDef *SPIx)
{
    CHECK_PARAM(PARAM_SPIx(SPIx));

    return ((SPIx->SPINT & SPI_SPINT_INTFLAG) ? SET : RESET);
}


void SPI::ClearIntPending(LPC_SPI_TypeDef *SPIx)
{
    CHECK_PARAM(PARAM_SPIx(SPIx));

    SPIx->SPINT = SPI_SPINT_INTFLAG;
}


uint32_t SPI::GetStatus(LPC_SPI_TypeDef* SPIx)
{
    CHECK_PARAM(PARAM_SPIx(SPIx));

    return (SPIx->SPSR & SPI_SPSR_BITMASK);
}



FlagStatus SPI::CheckStatus (uint32_t inputSPIStatus,  uint8_t SPIStatus)
{
    //CHECK_PARAM(PARAM_SPI_STAT(SPIStatus));

    return ((inputSPIStatus & SPIStatus) ? SET : RESET);
}
