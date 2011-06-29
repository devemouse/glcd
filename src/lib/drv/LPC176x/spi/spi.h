/**************************************************************************//**
 * @file    spi.h
 * @brief   File contains class declaration of spi peripheral class
 * @author  Dariusz Synowiec <devemouse@gmail.com>
 * @version 0.0.0dev
 * @date    June 2011
 *****************************************************************************/

#ifndef _SPI_H_
#define _SPI_H_
/******************************************************************************
 * Include files
 *****************************************************************************/
#include "inttypes.h"
#include "LPC17xx.h"

#ifdef __cplusplus
extern "C"
{
#endif

/****************************** PRIVATE MACROS ******************************/
/** SPI function pin selection group 0 
 * @todo Move those into PINSEL
 * */
#define SPI_PINSEL_SCK_P0_15    ((PINSEL_PinNum_e)(15))
#define SPI_PINFUNC_SCK_P0_15   ((PINSEL_Pin_Function_e)(3))

#define SPI_PINSEL_SSEL_P0_16   ((PINSEL_PinNum_e)(16))
#define SPI_PINFUNC_SSEL_P0_16  ((PINSEL_Pin_Function_e)(3))

#define SPI_PINSEL_MISO_P0_17   ((PINSEL_PinNum_e)(17))
#define SPI_PINFUNC_MISO_P0_17  ((PINSEL_Pin_Function_e)(3))

#define SPI_PINSEL_MOSI_P0_18   ((PINSEL_PinNum_e)(18))
#define SPI_PINFUNC_MOSI_P0_18  ((PINSEL_Pin_Function_e)(3))

/*********************************************************************//**
 * Macro defines for SPI Control Register
 **********************************************************************/
/** Bit enable, the SPI controller sends and receives the number
 *  of bits selected by bits 11:8 */
#define SPI_SPCR_BIT_EN         ((uint32_t)(1<<2))
/** Clock phase control bit */
#define SPI_SPCR_CPHA_SECOND    ((uint32_t)(1<<3))
/** Clock polarity control bit */
#define SPI_SPCR_CPOL_LOW       ((uint32_t)(1<<4))
/** SPI master mode enable */
#define SPI_SPCR_MSTR           ((uint32_t)(1<<5))
/** LSB enable bit */
#define SPI_SPCR_LSBF           ((uint32_t)(1<<6))
/** SPI interrupt enable bit */
#define SPI_SPCR_SPIE           ((uint32_t)(1<<7))
/**  When bit 2 of this register is 1, this field controls the
number of bits per transfer */
#define SPI_SPCR_BITS(n)        ((n==0) ? ((uint32_t)0) : ((uint32_t)((n&0x0F)<<8)))
/** SPI Control bit mask */
#define SPI_SPCR_BITMASK        ((uint32_t)(0xFFC))


/*********************************************************************//**
 * Macro defines for  SPI Status Register
 **********************************************************************/
/** Slave abort */
#define SPI_SPSR_ABRT       ((uint32_t)(1<<3))
/** Mode fault */
#define SPI_SPSR_MODF       ((uint32_t)(1<<4))
/** Read overrun */
#define SPI_SPSR_ROVR       ((uint32_t)(1<<5))
/** Write collision */
#define SPI_SPSR_WCOL       ((uint32_t)(1<<6))
/** SPI transfer complete flag */
#define SPI_SPSR_SPIF       ((uint32_t)(1<<7))
/** SPI Status bit mask */
#define SPI_SPSR_BITMASK    ((uint32_t)(0xF8))


/*********************************************************************//**
 * Macro defines for SPI Data Register
 **********************************************************************/
/** SPI Data low bit-mask */
#define SPI_SPDR_LO_MASK    ((uint32_t)(0xFF))
/** SPI Data high bit-mask */
#define SPI_SPDR_HI_MASK    ((uint32_t)(0xFF00))
/** SPI Data bit-mask */
#define SPI_SPDR_BITMASK    ((uint32_t)(0xFFFF))


/*********************************************************************//**
 * Macro defines for SPI Clock Counter Register
 **********************************************************************/
/** SPI clock counter setting */
#define SPI_SPCCR_COUNTER(n)    ((uint32_t)(n&0xFF))
/** SPI clock counter bit-mask */
#define SPI_SPCCR_BITMASK       ((uint32_t)(0xFF))


/***********************************************************************
 * Macro defines for SPI Test Control Register
 **********************************************************************/
/** SPI Test bit */
#define SPI_SPTCR_TEST_MASK ((uint32_t)(0xFE))
/** SPI Test register bit mask */
#define SPI_SPTCR_BITMASK   ((uint32_t)(0xFE))



/*********************************************************************//**
 * Macro defines for SPI Test Status Register
 **********************************************************************/
/** Slave abort */
#define SPI_SPTSR_ABRT      ((uint32_t)(1<<3))
/** Mode fault */
#define SPI_SPTSR_MODF      ((uint32_t)(1<<4))
/** Read overrun */
#define SPI_SPTSR_ROVR      ((uint32_t)(1<<5))
/** Write collision */
#define SPI_SPTSR_WCOL      ((uint32_t)(1<<6))
/** SPI transfer complete flag */
#define SPI_SPTSR_SPIF      ((uint32_t)(1<<7))
/** SPI Status bit mask */
#define SPI_SPTSR_MASKBIT   ((uint32_t)(0xF8))



/*********************************************************************//**
 * Macro defines for SPI Interrupt Register
 **********************************************************************/
/** SPI interrupt flag */
#define SPI_SPINT_INTFLAG   ((uint32_t)(1<<0))
/** SPI interrupt register bit mask */
#define SPI_SPINT_BITMASK   ((uint32_t)(0x01))


/**************************** GLOBAL/PUBLIC TYPES ***************************/
/*********************************************************************//**
 * SPI configuration parameter defines
 **********************************************************************/
/** Clock phase control bit */
typedef enum {
   SPI_CPHA_FIRST  = ((uint32_t)(0)),
   SPI_CPHA_SECOND = SPI_SPCR_CPHA_SECOND,
} SPI_CPHA_e;

/** Clock polarity control bit */
typedef enum {
   SPI_CPOL_HI = ((uint32_t)(0)),
   SPI_CPOL_LO = SPI_SPCR_CPOL_LOW,
} SPI_CPOL_e;

/** SPI master mode enable */
typedef enum {
   SPI_SLAVE_MODE  = ((uint32_t)(0)),
   SPI_MASTER_MODE = SPI_SPCR_MSTR,
} SPI_Mode_e;

/** LSB enable bit */
typedef enum {
   SPI_DATA_MSB_FIRST = ((uint32_t)(0)),
   SPI_DATA_LSB_FIRST = SPI_SPCR_LSBF,
} SPI_DataMode_e;

/** SPI data bit number defines */
typedef enum {
 SPI_DATABIT_16    = SPI_SPCR_BITS(0),        /*!< Databit number = 16 */
 SPI_DATABIT_8     = SPI_SPCR_BITS(0x08),     /*!< Databit number = 8 */
 SPI_DATABIT_9     = SPI_SPCR_BITS(0x09),     /*!< Databit number = 9 */
 SPI_DATABIT_10    = SPI_SPCR_BITS(0x0A),     /*!< Databit number = 10 */
 SPI_DATABIT_11    = SPI_SPCR_BITS(0x0B),     /*!< Databit number = 11 */
 SPI_DATABIT_12    = SPI_SPCR_BITS(0x0C),     /*!< Databit number = 12 */
 SPI_DATABIT_13    = SPI_SPCR_BITS(0x0D),     /*!< Databit number = 13 */
 SPI_DATABIT_14    = SPI_SPCR_BITS(0x0E),     /*!< Databit number = 14 */
 SPI_DATABIT_15    = SPI_SPCR_BITS(0x0F),     /*!< Databit number = 15 */
}SPI_DataBit_e;

/** SPI configuration structure */
typedef struct {
   /** Databit number, should be SPI_DATABIT_x, where x is in range from 8 - 16 */
   SPI_DataBit_e Databit;

   /** Clock phase, should be: 
    *   - SPI_CPHA_FIRST: first clock edge 
    *   - SPI_CPHA_SECOND: second clock edge
    */
    SPI_CPHA_e CPHA;

    /** Clock polarity, should be: 
     *   - SPI_CPOL_HI: high level
     *   - SPI_CPOL_LO: low level
     */
    SPI_CPOL_e CPOL;

    /** SPI mode, should be: 
     *   - SPI_MASTER_MODE: Master mode 
     *   - SPI_SLAVE_MODE: Slave mode 
     */
    SPI_Mode_e Mode;

    /** Data order, should be: 
     *   - SPI_DATA_MSB_FIRST: MSB first 
     *   - SPI_DATA_LSB_FIRST: LSB first 
     */
    SPI_DataMode_e DataOrder;

    /** Clock rate,in Hz, should not exceed */
    uint32_t ClockRate;
} SPI_CFG_Type;

/*************************** GLOBAL/PUBLIC MACROS ***************************/

/*********************************************************************//**
 * SPI Status Flag defines
 **********************************************************************/
typedef uint32_t SPI_Status_t;
/** Slave abort */
#define SPI_STAT_ABRT       (SPI_Status_t)SPI_SPSR_ABRT
/** Mode fault */
#define SPI_STAT_MODF       (SPI_Status_t)SPI_SPSR_MODF
/** Read overrun */
#define SPI_STAT_ROVR       (SPI_Status_t)SPI_SPSR_ROVR
/** Write collision */
#define SPI_STAT_WCOL       (SPI_Status_t)SPI_SPSR_WCOL
/** SPI transfer complete flag */
#define SPI_STAT_SPIF       (SPI_Status_t)SPI_SPSR_SPIF

#ifdef __cplusplus
}
#endif
/******************************************************************************
 * Forward declarations
 *****************************************************************************/

/**
 * SPI driver class
 */
class SPI {
   public:
      /*****************************************************
       * Constructors
       *****************************************************/
      /**
       * @brief Initializes the SPI peripheral with defualt parameters.
       */
      SPI();

      /********************************************************************//**
       * @brief       Initializes the SPI peripheral according to the specified parameters
       * @param[in]   SPI_ConfigStruct SPI_CFG_Type structure that contains 
       *              the configuration information for the specified SPI peripheral
       * @return      None
       *********************************************************************/
      SPI(SPI_CFG_Type &SPI_ConfigStruct);

      /**
       * Default destructor
       */
      ~SPI() {DeInit();};

      /*****************************************************
       * Functions: modifiers (set), selectors (get)
       *****************************************************/

      /*********************************************************************//**
       * @brief      Setup clock rate for SPI peripheral
       * @param[in]  target_clock : clock of SPI (Hz)
       * @return     Status of process (ERROR or SUCCESS)
       ***********************************************************************/
      Status     SetClock ( uint32_t target_clock);

      /*********************************************************************//**
       * @brief       Set all pins used as SPI function 
       * @param[in]   spiMode SPI mode, should be:
       *               - SPI_SLAVE_MODE: SLAVE mode
       *               - SPI_MASTER_MODE: MASTER mode
       * @return      None
       **********************************************************************/
      void       PinConfig( SPI_Mode_e spiMode);

      /*********************************************************************//**
       * @brief       De-initializes the SPI peripheral registers to their
       *                  default reset values.
       * @return      None
       **********************************************************************/
      void       DeInit();


      /*********************************************************************//**
       * @brief       Transmit a single data through SPI peripheral
       * @param[in]   Data    Data to transmit (must be 16 or 8-bit long,
       *                      this depend on SPI data bit number configured)
       * @return      none
       **********************************************************************/
      void       Write( uint16_t Data);

      /*********************************************************************//**
       * @brief       Receive a single data from SPI peripheral
       * @return      Data received (16-bit long)
       **********************************************************************/
      uint16_t   Read();

      /********************************************************************//**
       * @brief       Enable or disable SPI interrupt.
       * @param[in]   NewState New state of specified UART interrupt type,
       *              should be:
       *               - ENALBE: Enable this SPI interrupt.
       *               - DISALBE: Disable this SPI interrupt.
       * @return      None
       *********************************************************************/
      void       IntCmd( FunctionalState NewState);

      /********************************************************************//**
       * @brief       Checks whether the SPI interrupt flag is set or not.
       * @return      The new state of SPI Interrupt Flag (SET or RESET)
       *********************************************************************/
      IntStatus  GetIntStatus ();

      /********************************************************************//**
       * @brief       Clear SPI interrupt flag.
       * @return      None
       *********************************************************************/
      void       ClearIntPending();

      /********************************************************************//**
       * @brief       Get current value of SPI Status register in SPI peripheral.
       * @return      Current value of SPI Status register in SPI peripheral.
       * Note:    The return value of this function must be used with
       *          SPI_CheckStatus() to determine current flag status
       *          corresponding to each SPI status type. Because some flags in
       *          SPI Status register will be cleared after reading, the next reading
       *          SPI Status register could not be correct. So this function used to
       *          read SPI status register in one time only, then the return value
       *          used to check all flags.
       *********************************************************************/
      SPI_Status_t   GetStatus();

      /********************************************************************//**
       * @brief       Checks whether the specified SPI Status flag is set or not
       *              via inputSPIStatus parameter.
       * @param[in]   inputSPIStatus Value to check status of each flag type.
       *              This value is the return value from SPI_GetStatus().
       * @param[in]   SPIStatus   Specifies the SPI status flag to check,
       *              should be one of the following:
       *              - SPI_STAT_ABRT: Slave abort.
       *              - SPI_STAT_MODF: Mode fault.
       *              - SPI_STAT_ROVR: Read overrun.
       *              - SPI_STAT_WCOL: Write collision.
       *              - SPI_STAT_SPIF: SPI transfer complete.
       * @return      The new state of SPIStatus (SET or RESET)
       *********************************************************************/
      FlagStatus CheckStatus (SPI_Status_t inputSPIStatus,  uint8_t SPIStatus);

      /*****************************************************
       * Iterators
       *****************************************************/

      /*****************************************************
       * Public attributes
       *****************************************************/

   protected:
      /*****************************************************
       * Protected functions
       *****************************************************/

      /********************************************************************//**
       * @brief       Initializes the SPI peripheral according to the specified
       *               parameters in the UART_ConfigStruct.
       * @param[in]   SPI_ConfigStruct Pointer to a SPI_CFG_Type structure
       *                    that contains the configuration information for the
       *                    specified SPI peripheral.
       * @return      None
       *********************************************************************/
      void Init(SPI_CFG_Type &SPI_ConfigStruct);

      /*****************************************************
       * Protected attributes
       *****************************************************/

   private:
      /*****************************************************
       * Private functions
       *****************************************************/

      /*****************************************************
       * Private attributes
       *****************************************************/
      volatile LPC_SPI_TypeDef* SPIx;
};

#endif /* _SPI_H_ */
