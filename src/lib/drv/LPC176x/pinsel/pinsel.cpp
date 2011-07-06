
#include "pinsel.h"


PINSEL::PINSEL( PINSEL_PortPin_e Pin, PINSEL_PinFunction_e Funcnum,
      PINSEL_PinMode_e Pinmode, PINSEL_PinOpenDrain_e OpenDrain)
{
    SetPinFunc(Pin, Funcnum);
    SetResistorMode(Pin, Pinmode);
    SetOpenDrainMode(Pin, OpenDrain);
}


void PINSEL::SetPinFunc (  PINSEL_PortPin_e pinnum, PINSEL_PinFunction_e funcnum)
{
    uint32_t pinnum_t = (pinnum & 0x1F);
    uint32_t pinselreg_idx = 2 * (pinnum & 0x0700);
    //TODO: remove this warning
    uint32_t *pPinCon = (uint32_t *)&LPC_PINCON->PINSEL0;

    if (pinnum_t >= 16) {
        pinnum_t -= 16;
        pinselreg_idx++;
    }
    *(uint32_t *)(pPinCon + pinselreg_idx) &= ~(0x03UL << (pinnum_t * 2));
    *(uint32_t *)(pPinCon + pinselreg_idx) |= (uint32_t)funcnum;
}



void PINSEL::ConfigTraceFunc(FunctionalState NewState)
{
    if (NewState == ENABLE) {
        LPC_PINCON->PINSEL10 |= (0x01UL << 3);
    } else if (NewState == DISABLE) {
        LPC_PINCON->PINSEL10 &= ~(0x01UL << 3);
    }
}



void PINSEL::SetResistorMode ( PINSEL_PortPin_e pinnum, PINSEL_PinMode_e modenum)
{
    uint32_t pinnum_t = (pinnum & 0x1F);
    uint32_t pinmodereg_idx = 2 * (pinnum & 0x0700);
    //TODO: remove this warning
    uint32_t *pPinCon = (uint32_t *)&LPC_PINCON->PINMODE0;

    if (pinnum_t >= 16) {
        pinnum_t -= 16;
        pinmodereg_idx++ ;
    }

    *(uint32_t *)(pPinCon + pinmodereg_idx) &= ~(0x03UL << (pinnum_t * 2));
    *(uint32_t *)(pPinCon + pinmodereg_idx) |= ((uint32_t)modenum) << (pinnum_t * 2);
}



void PINSEL::SetOpenDrainMode( PINSEL_PortPin_e pinnum, PINSEL_PinOpenDrain_e modenum)
{
    if (modenum == PINSEL_PINMODE_OPENDRAIN){
        *(&LPC_PINCON->PINMODE_OD0 + (pinnum & 0x0700)) |= (0x01UL << pinnum);
    } else {
        *(&LPC_PINCON->PINMODE_OD0 + (pinnum & 0x0700)) &= ~(0x01UL << pinnum);
    }
}


void PINSEL::SetI2C0Pins(PINSEL_I2C_Mode_e i2cPinMode, FunctionalState filterSlewRateEnable)
{
    uint32_t regVal;

    if (i2cPinMode == PINSEL_I2C_Fast_Mode){
        regVal = PINSEL_I2CPADCFG_SCLDRV0 | PINSEL_I2CPADCFG_SDADRV0;
    }

    if (filterSlewRateEnable == DISABLE){
        regVal = PINSEL_I2CPADCFG_SCLI2C0 | PINSEL_I2CPADCFG_SDAI2C0;
    }
    LPC_PINCON->I2CPADCFG = regVal;
}

