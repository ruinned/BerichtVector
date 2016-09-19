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
#include <avr/io.h>
#include <avr/interrupt.h>
#include "trcvDio.h"
#include "spi.h"
#include "dio.h"
#include <util/delay.h>

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

#define kFrTrcv_30_Tja1080_delay_tEN_half 0x00

void Appl_FrTrcv_30_Tja1080_Wait(uint8 TimerIndex)
{
  switch(TimerIndex)
  {
    case kFrTrcv_30_Tja1080_delay_tEN_half:
    _delay_us(2);
    break;
  }

}

/**********************************************************************************************************************
*  GLOBAL FUNCTIONS
**********************************************************************************************************************/


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
  void trcvDio_Init(uint8 trcvType_local)
  {  
    dio_Init(trcvType_local);
    trcvDio_ReadWord(0);
  }

  /**********************************************************************************************************************
  * trcvDio_writeWord()
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
  uint16 trcvDio_ReadWord(uint8 device)
  {
    uint8_least   cnt;
    FrTrcv_30_Tja1080_StatusWordType result;
    Dio_LevelType TrcvEN;

    result = (FrTrcv_30_Tja1080_StatusWordType)0xFFFF; /* Initial state - no events */

    /* #10 Enter FRTRCV_30_TJA1080_EXCLUSIVE_AREA_1 as reading the status word is timing critical */
    disable(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    /* #20 Preserve the current transceiver state given by EN */
    TrcvEN = dio_ReadChannel(dio_EN);

    /* #30 Create initial condition to read status word (either 14bits or 15bits depending on EN) */
    cnt=(uint8_least)15u;
    if( TrcvEN == (Dio_LevelType)STD_HIGH )
    { /* #40 Correct initial EN state (EN is clock signal) */
      cnt=(uint8_least)14u;
    }

    for( ; cnt > (uint8_least)0u; cnt-- )
    {      
      /* #50 loop over all status bits and read them. Insert wait states for proper timing */
      dio_WriteChannel(dio_EN, (Dio_LevelType)STD_LOW);
      Appl_FrTrcv_30_Tja1080_Wait((uint8)kFrTrcv_30_Tja1080_delay_tEN_half);
      result <<= 1u;
      dio_WriteChannel(dio_EN, (Dio_LevelType)STD_HIGH);
      Appl_FrTrcv_30_Tja1080_Wait((uint8)kFrTrcv_30_Tja1080_delay_tEN_half);
      if( dio_ReadChannel(dio_ERRN) == (Dio_LevelType)STD_HIGH )
      {
        result |= (FrTrcv_30_Tja1080_StatusWordType)1u;
      }
    }

    /* #60 Restore previous transceiver state */
    dio_WriteChannel(dio_EN, TrcvEN);
    /* #70 Leave FRTRCV_30_TJA1080_EXCLUSIVE_AREA_1 as reading the status word is timing critical */
    enable(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    /* #80 High-active flags have to be returned, the transceiver delivers low-active flags --> invert them */
    return(result ^ (FrTrcv_30_Tja1080_StatusWordType)0xFFFF);
  }

  /**********************************************************************************************************************
  * trcvDio_up()
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
  void trcvDio_up(void)
  {
  }

  /**********************************************************************************************************************
  * trcvDio_down()
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
  void trcvDio_down(void)
  {
  }


  #define TRCV_STOP_SEC_CODE
  #include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

  /**********************************************************************************************************************
  *  END OF FILE: trcv.c
  *********************************************************************************************************************/
