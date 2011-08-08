/**************************************************************************//**
 * @file main.cpp
 * @brief This file contains main loop
 * @author Dawid Bazan <dawidbazan@gmail.com>
 * @author Dariusz Synowiec <devemouse@gmail.com>
 * @version 0.1.0
 * @date    May 2011
 * @bug There is no bug. left this to have a reference.
 *****************************************************************************/

/**
 * \mainpage LPC176x Startup project
 *
 * \section intro_sec Introduction
 *
 * The project main goal is to provide a template startup project for LPC176x micro.
 * See README for more details.
 *
 */

#define VERSION_STRING "v0.1.0"

#include "lamp.h"
#include "SystemTick.h"
#include "ssp.h"

#include "LPC17xx.h"

Lamp ssp_isr_entered(PORT_1, PIN_22, false, false);

/**************************************************************************//**
 * Default_Handler is an ISR handler for every unknown interrupt.
 * This one is optional and placed here as an example. User might want to e.g.
 * set some debug pin here
 *****************************************************************************/
void Default_Handler(void)
{
   /* Go into an infinite loop */
   while (1)
   {}
}

/**************************************************************************//**
 * SysTick_Handler is an ISR handler for SysTick interrupt
 *****************************************************************************/
void SysTick_Handler(void)
{
   SystemTick::SysTick_Handler();
}

/**************************************************************************//**
 * SSP0_IRQHandler is an ISR handler for SysTick interrupt
 *****************************************************************************/
void SSP0_IRQHandler(void)
{
   ssp_isr_entered.on();
}

/**************************************************************************//**
 * SSP1_IRQHandler is an ISR handler for SysTick interrupt
 *****************************************************************************/
void SSP1_IRQHandler(void)
{
   ssp_isr_entered.on();
}

/**************************************************************************//**
 * This function is run from RAM not from ROM
 *****************************************************************************/
__attribute__((section(".fastcode")))
void fastCodeFunct(void);


/**************************************************************************//**
 * enableCLKOUT
 * After calling this function you will have cpu clock divided by 10 on pin 1.27
 *****************************************************************************/
void enableCLKOUT(void)
{
   LPC_GPIO1->FIODIR_b27 = 1;          // 1 - output
   LPC_SC->CLKOUTCFG     = 0x00000190; // 0x0100 - enable, 0x00A0 - divide by 10
   LPC_PINCON->PINSEL3   = 0x00400000; // set pin as CLKOUT
}

/**************************************************************************//**
 * main
 * Function from which everything starts...
 *
 * @return on embedded targets this function shall never return
 *****************************************************************************/
int main(void)
{
   //enableCLKOUT();
   ssp_isr_entered.off();

   Lamp the_inverted_blinker(PORT_1, PIN_26, false, true);
   Lamp the_blinker(PORT_1, PIN_25, false, false);

   SystemTick systick;

   SSP_CFG_Type LCD_SPI_config;

   SSP_PinCFG_Type LCD_SPI_PinConfig = {
      /* SCK_Pin     , SSEL_Pin        , MISO_Pin        , MOSI_Pin        , SSPMode         , CSPinConfig */
      SSP0_SCK_P1_20 , SSP0_SSEL_P1_21 , SSP0_MISO_P1_23 , SSP0_MOSI_P1_24 , SSP_MASTER_MODE , SSP_CS_DEFAULT , {0 , 0}
   };

   SSP::ConfigStructInit(&LCD_SPI_config);
   //LCD_SPI_config.ClockRate = 10;
   SSP LCD(LPC_SSP0, &LCD_SPI_config);
   LCD.PinConfig(&LCD_SPI_PinConfig);


   (void)systick.initialize();

   while (1)
   {
   ssp_isr_entered.off();
      the_blinker.toggle();
      LCD.SendData(0xFF);
      LCD.SendData(0xFF);
      LCD.SendData(0xFF);
      LCD.SendData(0xFF);
      LCD.SendData(0xFF);
      LCD.SendData(0xFF);
      systick.wait_ms(100);
      the_blinker.toggle();
      the_inverted_blinker.toggle();
      LCD.SendData(0xFF);
      LCD.SendData(0xFF);
      LCD.SendData(0xFF);
      LCD.SendData(0xFF);
      LCD.SendData(0xFF);
      systick.wait_ms(100);
   }
   return(0);
} /* main */
