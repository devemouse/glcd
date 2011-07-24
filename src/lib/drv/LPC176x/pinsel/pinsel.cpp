
#include "pinsel.h"


PINSEL::PINSEL( PortPin_e Pin, PinFunction_e Funcnum,
      PinMode_e Pinmode, PinOpenDrain_e OpenDrain)
{
    SetPinFunc(Pin, Funcnum);
    SetResistorMode(Pin, Pinmode);
    SetOpenDrainMode(Pin, OpenDrain);
}


void PINSEL::SetPinFunc (  PortPin_e pinnum, PinFunction_e funcnum)
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



void PINSEL::SetResistorMode ( PortPin_e pinnum, PinMode_e modenum)
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



void PINSEL::SetOpenDrainMode( PortPin_e pinnum, PinOpenDrain_e modenum)
{
    if (modenum == PINMODE_OPENDRAIN){
        *(&LPC_PINCON->PINMODE_OD0 + (pinnum & 0x0700)) |= (0x01UL << pinnum);
    } else {
        *(&LPC_PINCON->PINMODE_OD0 + (pinnum & 0x0700)) &= ~(0x01UL << pinnum);
    }
}


void PINSEL::SetI2C0Pins(I2C_Mode_e i2cPinMode, FunctionalState filterSlewRateEnable)
{
    uint32_t regVal;

    /* I2C Pin Configuration register bit description */
#define I2CPADCFG_SDADRV0  (1<<0) /* Drive mode control for the SDA0 pin, P0.27 */
#define I2CPADCFG_SDAI2C0  (1<<1) /* I2C mode control for the SDA0 pin, P0.27 */
#define I2CPADCFG_SCLDRV0  (1<<2) /* Drive mode control for the SCL0 pin, P0.28 */
#define I2CPADCFG_SCLI2C0  (1<<3) /* I2C mode control for the SCL0 pin, P0.28 */

    if (i2cPinMode == I2C_Fast_Mode){
        regVal = I2CPADCFG_SCLDRV0 | I2CPADCFG_SDADRV0;
    }

    if (filterSlewRateEnable == DISABLE){
        regVal = I2CPADCFG_SCLI2C0 | I2CPADCFG_SDAI2C0;
    }
    LPC_PINCON->I2CPADCFG = regVal;
}

