/**********************************************************************************************************************
*  COPYRIGHT
*  -------------------------------------------------------------------------------------------------------------------
*  \verbatim
*  Copyright (c) 2016 by Vector Informatik GmbH.                                                  All rights reserved.
*
*                This software is copyright protected and proprietary to Vector Informatik GmbH.
*                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
*                All other rights remain with Vector Informatik GmbH.
*  \endverbatim
*  -------------------------------------------------------------------------------------------------------------------
*  FILE DESCRIPTION
*  -----------------------------------------------------------------------------------------------------------------*/
/*  \file  FrTrcv_30_Tja1080_Phy.c
*  \brief  MICROSAR FR Transceiver Driver
*
*  \details  FlexRay transceiver driver physical implementation
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

#define FRTRCV_30_TJA1080_PHY_SOURCE

/**************************************************************************************************
* Include files
**************************************************************************************************/
#include "FrTrcv_30_Tja1080.h"
#include "FrTrcv_30_Tja1080_Cbk.h"
#include "FrTrcv_30_Tja1080_Phy.h"


/**************************************************************************************************
* Macros
**************************************************************************************************/
#if ( FRTRCV_30_TJA1080_USERDIO == STD_ON )
# define DIO_WRITE(channel, value) Appl_FrTrcv_30_Tja1080_Dio_WriteChannel(channel, value) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# define DIO_READ(channel) Appl_FrTrcv_30_Tja1080_Dio_ReadChannel(channel) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#else
# define DIO_WRITE(channel, value) Dio_WriteChannel(channel, value) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# define DIO_READ(channel) Dio_ReadChannel(channel) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

/**************************************************************************************************
* Typedef and Struct definitions
**************************************************************************************************/
#if ( FRTRCV_30_TJA1080_WUPINT_CBK == STD_ON )
/*! Function ptr to enable/disable ICU notification */
typedef P2FUNC( void, FRTRCV_30_TJA1080_CODE, trcvIcuFctPtrType )( uint8 );
#endif

/**************************************************************************************************
* Defines / Constants
**************************************************************************************************/
#define FRTRCV_30_TJA1080_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */

/*! These are the I/O pins used for Transceiver access.
Currently two Transceiver channels are defined. Adjust this to your needs */
FRTRCV_30_TJA1080_LOCAL CONST( FrTrcv_30_Tja1080_ChannelType, FRTRCV_30_TJA1080_CONST ) FrTrcv_30_Tja1080_Channel[2] =
{
  { /*<! I/O used for Transceiver 1 */
    (Dio_ChannelType)Dio_FrTrcv_EN_A,
      (Dio_ChannelType)Dio_FrTrcv_STBN_A,
      (Dio_ChannelType)Dio_FrTrcv_ERRN_A,
  },
  { /*<! I/O used for Transceiver 2 */
    (Dio_ChannelType)Dio_FrTrcv_EN_B,
      (Dio_ChannelType)Dio_FrTrcv_STBN_B,
      (Dio_ChannelType)Dio_FrTrcv_ERRN_B,
    }
    /* ..... */
    /*<! Add more Transceivers, if required */
};

/* PRQA S 3218 12 */ /* MD_FRTRCV_3218 */
/* Modes are { Normal, Standby, Sleep, Receiveonly } */
FRTRCV_30_TJA1080_LOCAL CONST(Dio_LevelType, FRTRCV_30_TJA1080_CONST) FrTrcv_30_Tja1080_TrcvPinEn[4] = 
{ (Dio_LevelType)STD_HIGH, (Dio_LevelType)STD_LOW, (Dio_LevelType)STD_HIGH, (Dio_LevelType)STD_LOW };
FRTRCV_30_TJA1080_LOCAL CONST(Dio_LevelType, FRTRCV_30_TJA1080_CONST) FrTrcv_30_Tja1080_TrcvPinStbn[4] =
{ (Dio_LevelType)STD_HIGH, (Dio_LevelType)STD_LOW, (Dio_LevelType)STD_LOW, (Dio_LevelType)STD_HIGH };
#if ( FRTRCV_30_TJA1080_WUPINT_CBK == STD_ON )
FRTRCV_30_TJA1080_LOCAL CONST(trcvIcuFctPtrType, FRTRCV_30_TJA1080_CONST) FrTrcv_30_Tja1080_TrcvIcuFctPtr[4] =
{ Appl_FrTrcv_30_Tja1080_DisableNotification, Appl_FrTrcv_30_Tja1080_EnableNotification,
Appl_FrTrcv_30_Tja1080_EnableNotification, Appl_FrTrcv_30_Tja1080_DisableNotification };
#endif
/* Modes read from DIO pins */
FRTRCV_30_TJA1080_LOCAL CONST(FrTrcv_TrcvModeType, FRTRCV_30_TJA1080_CONST) FrTrcv_30_Tja1080_TrcvModeTable[4] =
{ (FrTrcv_TrcvModeType)FRTRCV_TRCVMODE_STANDBY, (FrTrcv_TrcvModeType)FRTRCV_TRCVMODE_RECEIVEONLY,
(FrTrcv_TrcvModeType)FRTRCV_TRCVMODE_SLEEP, (FrTrcv_TrcvModeType)FRTRCV_TRCVMODE_NORMAL };


#if ( FRTRCV_30_TJA1080_TRCV_DIAGNOSIS == STD_ON )
/*! The following table contains the bit vectors for the respective failures */
CONST(FrTrcv_30_Tja1080_StatusWordType, FRTRCV_30_TJA1080_CONST) FrTrcv_30_Tja1080_Phy_StatusMaskTable[6] = 
{
  (FrTrcv_30_Tja1080_StatusWordType) FRTRCV_30_TJA1080_BUSERROR,
  (FrTrcv_30_Tja1080_StatusWordType) FRTRCV_30_TJA1080_TEMPHIGH,
  (FrTrcv_30_Tja1080_StatusWordType) FRTRCV_30_TJA1080_TXEN_CLAMPED,
  (FrTrcv_30_Tja1080_StatusWordType) FRTRCV_30_TJA1080_UVVBAT,
  (FrTrcv_30_Tja1080_StatusWordType) FRTRCV_30_TJA1080_UVVCC,
  (FrTrcv_30_Tja1080_StatusWordType) FRTRCV_30_TJA1080_UVVIO,
};
/*! The following table contains the error flags for each possible transceiver failure */
CONST(uint32, FRTRCV_30_TJA1080_CONST) FrTrcv_30_Tja1080_Phy_ErrorTable[6] = 
{
  (uint32)(FRTRCV_30_TJA1080_BDE_GLOBAL | FRTRCV_30_TJA1080_BDE_NOISE),
  (uint32)(FRTRCV_30_TJA1080_BDE_GLOBAL | FRTRCV_30_TJA1080_BDE_OVER_TEMPERATURE),
  (uint32)(FRTRCV_30_TJA1080_BDE_GLOBAL | FRTRCV_30_TJA1080_BDE_TXEN_TIMEOUT),
  (uint32)(FRTRCV_30_TJA1080_BDE_GLOBAL | FRTRCV_30_TJA1080_BDE_UNDERVOLTAGE),
  (uint32)(FRTRCV_30_TJA1080_BDE_GLOBAL | FRTRCV_30_TJA1080_BDE_UNDERVOLTAGE),
  (uint32)(FRTRCV_30_TJA1080_BDE_GLOBAL | FRTRCV_30_TJA1080_BDE_UNDERVOLTAGE)
};
/* PRQA S 0777 1 */ /* MD_MSR_5.1_777 */
CONST(uint8, FRTRCV_30_TJA1080_CONST) FrTrcv_30_Tja1080_Phy_StatusMaskTableSize =
  sizeof(FrTrcv_30_Tja1080_Phy_StatusMaskTable) / sizeof(FrTrcv_30_Tja1080_Phy_StatusMaskTable[0]);
#endif


#define FRTRCV_30_TJA1080_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */

/**************************************************************************************************
* Macros
**************************************************************************************************/


/**************************************************************************************************
* Data definitions
**************************************************************************************************/


/**************************************************************************************************
* Prototypes for local functions
**************************************************************************************************/
#define FRTRCV_30_TJA1080_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */


/**************************************************************************************************
*  Implementation
**************************************************************************************************/

/**********************************************************************************************************************
* FrTrcv_30_Tja1080_Phy_Init()
**********************************************************************************************************************/
/*!
* \internal
* - #10 If the Transceiver "FRTRCV_30_TJA1080_CHANNEL_IDX" requires initialization, it can be done here
* \endinternal
*/
FUNC(void, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_Phy_Init( FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_ONLY )
{
#if ( FRTRCV_30_TJA1080_API_OPTIMIZATION == STD_ON )
#else
  FRTRCV_30_TJA1080_DUMMY_STATEMENT(FRTRCV_30_TJA1080_CHANNEL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif
  /* #10 If the Transceiver "FRTRCV_30_TJA1080_CHANNEL_IDX" requires initialization, it can be done here */
}


/***********************************************************************************************************************
*  FrTrcv_30_Tja1080_Phy_SetMode()
**********************************************************************************************************************/
/*!
* \internal
* - #5 Check range of parameter for function pointer call/array access
*  - #10 Enter FRTRCV_30_TJA1080_EXCLUSIVE_AREA_0 as mode change requires a deterministic minimum delay
*  - #20 Disable ICU notifications if switched to operational mode if FRTRCV_30_TJA1080_WUPINT_CBK is STD_ON
*  - #30 Set the connected Transceiver to the requested mode
*  - #40 Give EN time to reach the mode control block to avoid unwanted state changes
*  - #50 Enable ICU notifications if switched to low power mode if FRTRCV_30_TJA1080_WUPINT_CBK is STD_ON
*  - #60 Leave FRTRCV_30_TJA1080_EXCLUSIVE_AREA_0 as mode change requires a deterministic minimum delay
* \endinternal
*/
FUNC(Std_ReturnType, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_Phy_SetMode
  (
  FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_ONLY,
  FrTrcv_TrcvModeType FrTrcv_TrcvMode
  )
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* #5 Check range of parameter for function pointer call/array access */
  if( FrTrcv_TrcvMode >= (sizeof(FrTrcv_30_Tja1080_TrcvPinStbn) / sizeof(FrTrcv_30_Tja1080_TrcvPinStbn[0])) )
  {
  }
  else
    /* ----- Implementation ----------------------------------------------- */
  {
    /* #10 Enter FRTRCV_30_TJA1080_EXCLUSIVE_AREA_0 as mode change requires a deterministic minimum delay */
    FrTrcv_EnterCritical_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

#if ( FRTRCV_30_TJA1080_WUPINT_CBK == STD_ON )
    /* #20 Disable ICU notifications if switched to operational mode if FRTRCV_30_TJA1080_WUPINT_CBK is STD_ON */
    if( FrTrcv_30_Tja1080_Config[FRTRCV_30_TJA1080_CHANNEL_IDX].FrTrcv_WakeupByNodeUsedPolling == FRTRCV_WAKEUP_INTERRUPT )
    { /* Enable/Disable Wakeup Interrupt */
      if( FrTrcv_30_Tja1080_TrcvIcuFctPtr[FrTrcv_TrcvMode] == Appl_FrTrcv_30_Tja1080_DisableNotification )
      {
        FrTrcv_30_Tja1080_TrcvIcuFctPtr[FrTrcv_TrcvMode](FRTRCV_30_TJA1080_CHANNEL_IDX); /* SBSW_FRTRCV_FCTPTRCALL */
      }
    }
#endif

    /* #30 Set the connected Transceiver to the requested mode */
    if( FrTrcv_30_Tja1080_TrcvPinStbn[FrTrcv_TrcvMode] == (Dio_LevelType)STD_HIGH ) /* lint -e{661} */
    {
      DIO_WRITE(FrTrcv_30_Tja1080_Channel[FRTRCV_30_TJA1080_CHANNEL_IDX].TrcvPinSTBN, (Dio_LevelType)STD_HIGH);
      DIO_WRITE(FrTrcv_30_Tja1080_Channel[FRTRCV_30_TJA1080_CHANNEL_IDX].TrcvPinEN, FrTrcv_30_Tja1080_TrcvPinEn[FrTrcv_TrcvMode]);
      /* #40 Give EN time to reach the mode control block to avoid unwanted state changes */
      Appl_FrTrcv_30_Tja1080_Wait( (uint8)kFrTrcv_30_Tja1080_delay_tDet );
    }
    else
    {
      DIO_WRITE(FrTrcv_30_Tja1080_Channel[FRTRCV_30_TJA1080_CHANNEL_IDX].TrcvPinEN, FrTrcv_30_Tja1080_TrcvPinEn[FrTrcv_TrcvMode]);
      /* #40 Give EN time to reach the mode control block to avoid unwanted state changes */
      Appl_FrTrcv_30_Tja1080_Wait( (uint8)kFrTrcv_30_Tja1080_delay_tDet );
      DIO_WRITE(FrTrcv_30_Tja1080_Channel[FRTRCV_30_TJA1080_CHANNEL_IDX].TrcvPinSTBN, (Dio_LevelType)STD_LOW);
    }

#if ( FRTRCV_30_TJA1080_WUPINT_CBK == STD_ON )
    if( FrTrcv_30_Tja1080_Config[FRTRCV_30_TJA1080_CHANNEL_IDX].FrTrcv_WakeupByNodeUsedPolling == FRTRCV_WAKEUP_INTERRUPT )
    { 
      /* #50 Enable ICU notifications if switched to low power mode if FRTRCV_30_TJA1080_WUPINT_CBK is STD_ON */
      if( Appl_FrTrcv_30_Tja1080_EnableNotification == FrTrcv_30_Tja1080_TrcvIcuFctPtr[FrTrcv_TrcvMode] )
      {
        FrTrcv_30_Tja1080_TrcvIcuFctPtr[FrTrcv_TrcvMode](FRTRCV_30_TJA1080_CHANNEL_IDX); /* SBSW_FRTRCV_FCTPTRCALL */
      }
    }
#endif
    /* #60 Leave FRTRCV_30_TJA1080_EXCLUSIVE_AREA_0 as mode change requires a deterministic minimum delay */
    FrTrcv_LeaveCritical_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    retVal = E_OK;
  }

  return(retVal);
}


/***********************************************************************************************************************
*  FrTrcv_30_Tja1080_Phy_GetMode()
**********************************************************************************************************************/
/*!
* \internal
* - #10 Enter FRTRCV_30_TJA1080_EXCLUSIVE_AREA_0 as mode read must be done consistently
* - #20 Read STBN and EN pin to determine corresponding mode
* - #30 Leave FRTRCV_30_TJA1080_EXCLUSIVE_AREA_0 as mode read must be done consistently
* \endinternal
*/
FUNC(void, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_Phy_GetMode
  (
  FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_ONLY,
  P2VAR(FrTrcv_TrcvModeType, AUTOMATIC, FRTRCV_30_TJA1080_APPL_DATA) FrTrcv_TrcvModePtr
  )
{
  uint8_least modeIdx;
  modeIdx = 0u;

  /* #10 Enter FRTRCV_30_TJA1080_EXCLUSIVE_AREA_0 as mode read must be done consistently */
  FrTrcv_EnterCritical_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* #20 Read STBN and EN pin to determine corresponding mode */
  if( DIO_READ(FrTrcv_30_Tja1080_Channel[FRTRCV_30_TJA1080_CHANNEL_IDX].TrcvPinSTBN) == (Dio_LevelType)STD_HIGH )
  {
    modeIdx |= (uint8)1u;
  }
  if( DIO_READ(FrTrcv_30_Tja1080_Channel[FRTRCV_30_TJA1080_CHANNEL_IDX].TrcvPinEN) == (Dio_LevelType)STD_HIGH )
  {
    modeIdx |= (uint8)2u;
  }
  /* #30 Leave FRTRCV_30_TJA1080_EXCLUSIVE_AREA_0 as mode read must be done consistently */
  FrTrcv_LeaveCritical_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  *FrTrcv_TrcvModePtr = FrTrcv_30_Tja1080_TrcvModeTable[modeIdx]; /* SBSW_FRTRCV_PARAM_TRCVMODE */
}


/***********************************************************************************************************************
*  FrTrcv_30_Tja1080_Phy_ReadStatusWord()
**********************************************************************************************************************/
/*!
* \internal
* - #10 Enter FRTRCV_30_TJA1080_EXCLUSIVE_AREA_1 as reading the status word is timing critical
* - #20 Preserve the current transceiver state given by EN
* - #30 Create initial condition to read status word (either 14bits or 15bits depending on EN)
* - #40 Correct initial EN state (EN is clock signal)
* - #50 loop over all status bits and read them. Insert wait states for proper timing
* - #60 Restore previous transceiver state
* - #70 Leave FRTRCV_30_TJA1080_EXCLUSIVE_AREA_1 as reading the status word is timing critical
* - #80 High-active flags have to be returned, the transceiver delivers low-active flags --> invert them
* \endinternal
*/
FUNC(void, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_Phy_ReadStatusWord
  (
  FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_ONLY,
  P2VAR(FrTrcv_30_Tja1080_StatusWordType, AUTOMATIC, FRTRCV_30_TJA1080_APPL_DATA) TrcvStatusWord
  )
{

#if defined(ARDUINO)
  if(FrTrcv_TrcvIdx == 0)
  {
    ArdCom_WriteReadTRCVStatusWord(0x00,TrcvStatusWord);
  }
  else
#endif
  {

    uint8_least   cnt;
    FrTrcv_30_Tja1080_StatusWordType result;
    Dio_LevelType TrcvEN;

    result = (FrTrcv_30_Tja1080_StatusWordType)FRTRCV_30_TJA1080_STATUS_INVERT_MASK; /* Initial state - no events */

    /* #10 Enter FRTRCV_30_TJA1080_EXCLUSIVE_AREA_1 as reading the status word is timing critical */
    FrTrcv_EnterCritical_1(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    /* #20 Preserve the current transceiver state given by EN */
    TrcvEN = DIO_READ(FrTrcv_30_Tja1080_Channel[FRTRCV_30_TJA1080_CHANNEL_IDX].TrcvPinEN);

    /* #30 Create initial condition to read status word (either 14bits or 15bits depending on EN) */
    cnt=(uint8_least)15u;
    if( TrcvEN == (Dio_LevelType)STD_HIGH )
    { /* #40 Correct initial EN state (EN is clock signal) */
      cnt=(uint8_least)14u;
    }

    for( ; cnt > (uint8_least)0u; cnt-- )
    { 
      /* #50 loop over all status bits and read them. Insert wait states for proper timing */
      DIO_WRITE(FrTrcv_30_Tja1080_Channel[FRTRCV_30_TJA1080_CHANNEL_IDX].TrcvPinEN, (Dio_LevelType)STD_LOW);
      Appl_FrTrcv_30_Tja1080_Wait((uint8)kFrTrcv_30_Tja1080_delay_tEN_half);
      result <<= 1u;
      DIO_WRITE(FrTrcv_30_Tja1080_Channel[FRTRCV_30_TJA1080_CHANNEL_IDX].TrcvPinEN, (Dio_LevelType)STD_HIGH);
      Appl_FrTrcv_30_Tja1080_Wait((uint8)kFrTrcv_30_Tja1080_delay_tEN_half);
      if( DIO_READ(FrTrcv_30_Tja1080_Channel[FRTRCV_30_TJA1080_CHANNEL_IDX].TrcvPinERRN) == (Dio_LevelType)STD_HIGH )
      {
        result |= (FrTrcv_30_Tja1080_StatusWordType)1u;
      }
    }

    /* #60 Restore previous transceiver state */
    DIO_WRITE(FrTrcv_30_Tja1080_Channel[FRTRCV_30_TJA1080_CHANNEL_IDX].TrcvPinEN, TrcvEN);
    /* #70 Leave FRTRCV_30_TJA1080_EXCLUSIVE_AREA_1 as reading the status word is timing critical */
    FrTrcv_LeaveCritical_1(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    /* #80 High-active flags have to be returned, the transceiver delivers low-active flags --> invert them */
    *TrcvStatusWord = result ^ (FrTrcv_30_Tja1080_StatusWordType)FRTRCV_30_TJA1080_STATUS_INVERT_MASK; /* SBSW_FRTRCV_PARAM_TRCVSTATUSWORD */
  }
}


#define FRTRCV_30_TJA1080_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */


/* module specific MISRA deviations:
MD_FRTRCV_3218: Rule 8.7
Reason:     Must be handled in global scope, otherwise AUTOSAR Memory Mapping will not work.
Risk:       -
Prevention: Covered by code review.
*/

/* COV_JUSTIFICATION_BEGIN

\ID COV_FRTRCV_30_TJA1080_PHY_SOURCE
\ACCEPT TX
\REASON Only False branch is covered because COV_FRTRCV_30_TJA1080_SOURCE is only defined in FrTrcv_30_Tja1080.c
and the macros shall only be redefined in the C-file (not in the header). Otherwise the single channel
API optimization will cause an compiler warning.

\ID COV_FRTRCV_30_TJA1080_PHY_MSR_HEADERGUARD
\ACCEPT TX
\REASON [COV_MSR_HEADERGUARD]

COV_JUSTIFICATION_END */


/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_FRTRCV_PARAM_TRCVMODE
\DESCRIPTION    The function FrTrcv_30_Tja1080_Phy_GetMode writes to the 'FrTrcv_TrcvModePtr' pointer parameter.
The parameter can not be checked for validity. The calling module must provide a valid pointer.
\COUNTERMEASURE \N The calling module is a vector module and will either provide a valid pointer.

\ID SBSW_FRTRCV_PARAM_TRCVSTATUSWORD
\DESCRIPTION    The function FrTrcv_30_Tja1080_Phy_ReadStatusWord writes to the 'TrcvStatusWord' pointer parameter.
The parameter can not be checked for validity. The calling module must provide a valid pointer.
\COUNTERMEASURE \N The calling module is a vector module and will either provide a valid pointer or describe
the requirement in the SafetyManual

\ID SBSW_FRTRCV_FCTPTRCALL
\DESCRIPTION    Function pointer is called. Pointer is taken from a table by an index parameter FrTrcv_TrcvMode.
Index Parameter must be within limits.
\COUNTERMEASURE \R Index parameter is checked against table bounds at #5.

SBSW_JUSTIFICATION_END */

/**********************************************************************************************************************
*  END OF FILE: FrTrcv_30_Tja1080_Phy.c
*********************************************************************************************************************/
