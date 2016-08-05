/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2014 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  dio.c
 *        \brief  dio source file
 *
 *        \details basic input/output and port configuration
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#define DIO_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "dio.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of dio header file */
#if (  (DIO_SW_MAJOR_VERSION != (1u)) \
    || (DIO_SW_MINOR_VERSION != (0u)) \
    || (DIO_SW_PATCH_VERSION != (0u)) )
# error "Vendor specific version numbers of dio.c and dio.h are inconsistent"
#endif


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
/*! \brief Example symbolic constant */
#define MSN_MY_SYMBOLIC_CONSTANT        (0x05u)
/*! \brief Reset value for ... */
#define MSN_MY_RESETVALUE               (0x00u)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/* Preprocessor define STATIC is no longer available in Compiler.h in MSR4 - provide local define */
#if !defined (STATIC)
# define STATIC static
#endif

typedef struct
{
    volatile uint8 *pinPortOut;
    volatile uint8 *pinPortIn;
    uint8 pinBit;
} PortPinDescriptorType;

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/
PortPinDescriptorType PortPinDescriptorMap[] =
  { { &PORTB, &PINB, 0x01 }, /* 0: FR_RXD */
    { &PORTB, &PINB, 0x02 }, /* 1: FR_TXD */
    { &PORTB, &PINB, 0x04 }, /* 2: CS1 */
    { &PORTB, &PINB, 0x08 }, /* 3: STBN */
    { &PORTB, &PINB, 0x10 }, /* 4: ERRN */
    { &PORTB, &PINB, 0x20 }, /* 5: EN */
    { &PORTD, &PIND, 0x01 }, /* 6: RXD */
    { &PORTD, &PIND, 0x02 }, /* 7: TXD */
    { &PORTD, &PIND, 0x04 }, /* 8: INTN1 */
    { &PORTD, &PIND, 0x08 }, /* 9: INTN2 */
    { &PORTD, &PIND, 0x10 }, /* 10:TXEN_int */
    { &PORTD, &PIND, 0x20 }, /* 11:FR_TXEN */
    { &PORTD, &PIND, 0x40 }, /* 12:TXD_int */
    { &PORTD, &PIND, 0x80 }, /* 13:RXD_int */
    { &PORTC, &PINC, 0x01 }, /* 14:Vin/VBat */
    { &PORTC, &PINC, 0x02 }, /* 15:Clamp_GND_BP */
    { &PORTC, &PINC, 0x04 }, /* 16:Clamp_GND_BM */
    { &PORTC, &PINC, 0x08 }, /* 17:STBY_int */
    { &PORTC, &PINC, 0x10 }, /* 18:CS2 */
    { &PORTC, &PINC, 0x20 }  /* 19:LED */
};

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define DIO_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/




/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  dio_InitMemory()
 **********************************************************************************************************************/
/*! \brief      Function for *_INIT_*-variable initialization
 *  \details    Service to initialize module global variables at power up. This function can be used to initialize the
 *              variables in *_INIT_* sections in case they are not initialized by the startup code.
 *  \pre        Module must not be initialized
 *  \pre        Function shall be called from task level
 **********************************************************************************************************************/
void dio_InitMemory(void)
{
  /* ----- Implementation ----------------------------------------------- */

}  /* dio_InitMemory() */


/**********************************************************************************************************************
 * dio_Init()
 **********************************************************************************************************************/
/*! \brief      Initialization function
 *  \details    This function initializes the module dio. It initializes all variables and and sets the module state to
 *              initialized.
 *  \param[in]  -
 *  \pre        Interrupts have to be disabled.
 *  \pre        The module has to be uninitialized.
 *  \pre        dio_InitMemory has been called unless dio_ModuleInitialized is initialized by start-up code.
 *  \note       Specification of module initialization
 **********************************************************************************************************************/
void dio_Init(void)
{
  PORTB = PORTB_INIT;
  DDRB = DDRB_INIT;

  PORTC = PORTC_INIT;
  DDRC = DDRC_INIT;

  PORTD = PORTD_INIT;
  DDRD = DDRD_INIT;
}

/**********************************************************************************************************************
 * dio_WriteChannel()
 **********************************************************************************************************************/
/*! \brief      Write port channel
 *  \details    
 *  \param[in]  -
 *  \pre        -
 *  \note       -
 **********************************************************************************************************************/
void dio_WriteChannel(uint8 Channel, uint8 value)
{
  *PortPinDescriptorMap[Channel].pinPortOut |= PortPinDescriptorMap[Channel].pinBit;
}

/**********************************************************************************************************************
 * dio_ReadChannel()
 **********************************************************************************************************************/
/*! \brief      Read port channel
 *  \details    
 *  \param[in]  -
 *  \pre        -
 *  \note       -
 **********************************************************************************************************************/
uint8 dio_ReadChannel(uint8 Channel)
{
  uint8 retVal;

  retVal = (PortPinDescriptorMap[Channel].pinBit == (*PortPinDescriptorMap[Channel].pinPortIn & PortPinDescriptorMap[Channel].pinBit));
  return(retVal);
}

#define DIO_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Justification for module-specific MISRA deviations:
 MD_dio_770: rule 14.5
      Reason:     A 'continue' statement has been used for efficiency reasons.
      Risk:       Poor readability of the code, unpredicted program flow.
      Prevention: Program flow has been verified by component tests and review.
*/

/**********************************************************************************************************************
 *  END OF FILE: dio.c
 *********************************************************************************************************************/
