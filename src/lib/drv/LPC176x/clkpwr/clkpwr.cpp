
#include "clkpwr.h"


void CLKPWR::SetPCLKDiv (uint32_t ClkType, uint32_t DivVal)
{
	uint32_t bitpos;

	bitpos = (ClkType < 32) ? (ClkType) : (ClkType - 32);

	/* PCLKSEL0 selected */
	if (ClkType < 32)
	{
		/* Clear two bit at bit position */
		//LPC_SC->PCLKSEL0 &= (~(CLKPWR_PCLKSEL_BITMASK(bitpos))) &CLKPWR_PCLKSEL0_BITMASK;
		LPC_SC->PCLKSEL0 &= (~(CLKPWR_PCLKSEL_BITMASK(bitpos)));

		/* Set two selected bit */
		//LPC_SC->PCLKSEL0 |= (CLKPWR_PCLKSEL_SET(bitpos, DivVal)) &CLKPWR_PCLKSEL0_BITMASK;
		LPC_SC->PCLKSEL0 |= (CLKPWR_PCLKSEL_SET(bitpos, DivVal));
	}
	/* PCLKSEL1 selected */
	else
	{
		/* Clear two bit at bit position */
		//LPC_SC->PCLKSEL1 &= (~(CLKPWR_PCLKSEL_BITMASK(bitpos))) &CLKPWR_PCLKSEL1_BITMASK;
		LPC_SC->PCLKSEL1 &= ~(CLKPWR_PCLKSEL_BITMASK(bitpos));

		/* Set two selected bit */
		//LPC_SC->PCLKSEL1 |= (CLKPWR_PCLKSEL_SET(bitpos, DivVal)) &CLKPWR_PCLKSEL1_BITMASK;
		LPC_SC->PCLKSEL1 |= (CLKPWR_PCLKSEL_SET(bitpos, DivVal));
	}
}

uint32_t CLKPWR::GetPCLKSEL (uint32_t ClkType)
{
	uint32_t bitpos, retval;

	if (ClkType < 32)
	{
		bitpos = ClkType;
		retval = LPC_SC->PCLKSEL0;
	}
	else
	{
		bitpos = ClkType - 32;
		retval = LPC_SC->PCLKSEL1;
	}

	retval = CLKPWR_PCLKSEL_GET(bitpos, retval);
	return retval;
}



uint32_t CLKPWR::GetPCLK (uint32_t ClkType)
{
	uint32_t retval, div;

	retval = GetSystemCoreClock();
	div = CLKPWR::GetPCLKSEL(ClkType);

	switch (div)
	{
	case 0:
		div = 4;
		break;

	case 1:
		div = 1;
		break;

	case 2:
		div = 2;
		break;

	case 3:
		div = 8;
		break;
	}
	retval /= div;

	return retval;
}


void CLKPWR::ConfigPPWR (uint32_t PPType, FunctionalState NewState)
{
	if (NewState == ENABLE)
	{
		LPC_SC->PCONP |= PPType & CLKPWR_PCONP_BITMASK;
	}
	else if (NewState == DISABLE)
	{
		LPC_SC->PCONP &= (~PPType) & CLKPWR_PCONP_BITMASK;
	}
}
