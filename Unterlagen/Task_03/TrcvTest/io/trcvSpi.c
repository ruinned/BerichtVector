/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2015 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  trcv.c
 *        \brief  trcv source file
 *
 *        \details basic input/output
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

#define TRCV_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "trcvSpi.h"
#include "spi.h"
#include "dio.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of trcv header file */
#if (  (TRCV_SW_MAJOR_VERSION != (1u)) \
    || (TRCV_SW_MINOR_VERSION != (0u)) \
    || (TRCV_SW_PATCH_VERSION != (0u)) )
# error "Vendor specific version numbers of trcv.c and trcv.h are inconsistent"
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

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define TRCV_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/




/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  trcv_InitMemory()
 **********************************************************************************************************************/
/*! \brief      Function for *_INIT_*-variable initialization
 *  \details    Service to initialize module global variables at power up. This function can be used to initialize the
 *              variables in *_INIT_* sections in case they are not initialized by the startup code.
 *  \pre        Module must not be initialized
 *  \pre        Function shall be called from task level
 **********************************************************************************************************************/
void trcvSpi_InitMemory(void)
{
  /* ----- Implementation ----------------------------------------------- */

}  /* trcv_InitMemory() */


/**********************************************************************************************************************
 * trcv_Init()
 **********************************************************************************************************************/
/*! \brief      Initialization function
 *  \details    This function initializes the module trcv. It initializes all variables and and sets the module state to
 *              initialized.
 *  \param[in]  -
 *  \pre        Interrupts have to be disabled.
 *  \pre        The module has to be uninitialized.
 *  \pre        trcv_InitMemory has been called unless trcv_ModuleInitialized is initialized by start-up code.
 *  \note       Specification of module initialization
 **********************************************************************************************************************/
void trcvSpi_Init(void)
{
}

/**********************************************************************************************************************
 * trcvSpi_writeWord()
 **********************************************************************************************************************/
/*! \brief      
 *  \details    
 *              
 *  \param[in]  -
 *  \pre        
 *  \pre        The module has to be initialized.
 *  \pre        trcv_InitMemory has been called unless trcv_ModuleInitialized is initialized by start-up code.
 *  \note       
 **********************************************************************************************************************/
uint16 trcvSpi_writeWord(uint16 data, uint8 device)
{
  uint16 result;

  /* Enable CS */
  if(device == 0)
  {
    CS1_ON();
  }
  else
  {
    CS2_ON();
  }

  /* Read/Write 16 bit word */
  result  = (uint16)spi_transfer(data >> 8) << 8;
  result |= spi_transfer(data & 0xff);

  /* Disable CS */
  if(device == 0)
  {
    CS1_OFF();
  }
  else
  {
    CS2_OFF();
  }

  return(result);
}

/**********************************************************************************************************************
 * trcvSpi_up()
 **********************************************************************************************************************/
/*! \brief      
 *  \details    
 *              
 *  \param[in]  -
 *  \pre        
 *  \pre        The module has to be initialized.
 *  \pre        trcv_InitMemory has been called unless trcv_ModuleInitialized is initialized by start-up code.
 *  \note       
 **********************************************************************************************************************/
void trcvSpi_up(void)
{
}

/**********************************************************************************************************************
 * trcvSpi_down()
 **********************************************************************************************************************/
/*! \brief      
 *  \details    
 *              
 *  \param[in]  -
 *  \pre        
 *  \pre        The module has to be initialized.
 *  \pre        trcv_InitMemory has been called unless trcv_ModuleInitialized is initialized by start-up code.
 *  \note       
 **********************************************************************************************************************/
void trcvSpi_down(void)
{
}


#define TRCV_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  END OF FILE: trcv.c
 *********************************************************************************************************************/
