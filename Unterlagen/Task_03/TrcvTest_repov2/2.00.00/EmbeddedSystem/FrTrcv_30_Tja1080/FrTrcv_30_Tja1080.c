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
/*  \file  FrTrcv_30_Tja1080.c
 *  \brief  MICROSAR FR Transceiver Driver
 *
 *  \details  FlexRay transceiver driver implementation
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

#define FRTRCV_30_TJA1080_SOURCE

/**************************************************************************************************
* Include files
**************************************************************************************************/
/* FlexRay transceiver driver declarations */
#include "FrTrcv_30_Tja1080.h"
#include "FrTrcv_30_Tja1080_Cbk.h"
#include "FrTrcv_30_Tja1080_Phy.h"

#if ( FRTRCV_30_TJA1080_DEV_ERROR_REPORT == STD_ON )
# include "Det.h"
#endif


/***************************************************************************/
/* Version check                                                           */
/***************************************************************************/
/* Check the version of Msn header file */
#if (  (FRTRCV_30_TJA1080_SW_MAJOR_VERSION != (4u)) \
    || (FRTRCV_30_TJA1080_SW_MINOR_VERSION != (1u)) \
    || (FRTRCV_30_TJA1080_SW_PATCH_VERSION != (0u)) ) /* COV_FRTRCV_30_TJA1080_MSR_CONSISTENCYCHECK */
# error "Vendor specific version numbers of FrTrcv_30_Tja1080.c and FrTrcv_30_Tja1080.h are inconsistent"
#endif


/**************************************************************************************************
* Defines / Constants
**************************************************************************************************/

/****************************************************************************/
/* 32 Bit Constants for export                                              */
/****************************************************************************/
#define FRTRCV_30_TJA1080_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */

#if FRTRCV_30_TJA1080_PROD_ERROR_DETECT == STD_ON
/* PRQA S 3684 1 */ /* MD_FRTRCV_3684 */ /* PRQA S 3447 1 */ /* MD_FRTRCV_3447 */
extern CONST(Dem_EventIdType, FRTRCV_30_TJA1080_CONST) FrTrcv_30_Tja1080_DEM_E_BusError_Channel[];
#endif

#define FRTRCV_30_TJA1080_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */


/**************************************************************************************************
* Macros
**************************************************************************************************/

/* FrTrcv052: */
#if ( FRTRCV_30_TJA1080_PROD_ERROR_DETECT == STD_ON )
# if ( FRTRCV_30_TJA1080_TRCV_DEM_CALLBACK == STD_ON )
   /* PRQA S 3453 12 */ /* MD_MSR_19.7 */
#  define FrTrcv_DemReportErrorFailed(eventId) Appl_FrTrcv_30_Tja1080_ReportErrorStatusFailed(eventId)
#  define FrTrcv_DemReportErrorPreFailed(eventId) Appl_FrTrcv_30_Tja1080_ReportErrorStatusPreFailed(eventId)
#  define FrTrcv_DemReportErrorPrePassed(eventId) Appl_FrTrcv_30_Tja1080_ReportErrorStatusPrePassed(eventId)
# else
#  define FrTrcv_DemReportErrorFailed(eventId) ((void)Dem_ReportErrorStatus((Dem_EventIdType)(eventId), (uint8)(DEM_EVENT_STATUS_FAILED)))
#  define FrTrcv_DemReportErrorPreFailed(eventId) ((void)Dem_ReportErrorStatus((Dem_EventIdType)(eventId), (uint8)(DEM_EVENT_STATUS_PREFAILED)))
#  define FrTrcv_DemReportErrorPrePassed(eventId) ((void)Dem_ReportErrorStatus((Dem_EventIdType)(eventId), (uint8)(DEM_EVENT_STATUS_PREPASSED)))
# endif
#else
# define FrTrcv_DemReportErrorFailed(eventId)
# define FrTrcv_DemReportErrorPreFailed(eventId)
# define FrTrcv_DemReportErrorPrePassed(eventId)
#endif

/**************************************************************************************************
* Typedef and Struct definitions
**************************************************************************************************/
#define FRTRCV_30_TJA1080_UNINIT  (FrTrcv_30_Tja1080_InitStatusType)0u /* The FrTrcv is not initialized and is not usable. */
#define FRTRCV_30_TJA1080_INIT    (FrTrcv_30_Tja1080_InitStatusType)1u /* The FrTrcv is initialized and is usable. */

/**************************************************************************************************
* Data definitions
**************************************************************************************************/

/******************************************************************************/
/* Local Data definitions with unspecified size                               */
/******************************************************************************/
#define FRTRCV_30_TJA1080_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */
/*! Contains the global initialization state of the component */
volatile VAR( FrTrcv_30_Tja1080_InitStatusType, FRTRCV_30_TJA1080_VAR_ZERO_INIT ) FrTrcv_30_Tja1080_IsInitialized = 0; /* PRQA S 3408 */ /* MD_FRTRCV_3408 */

#define FRTRCV_30_TJA1080_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */


#define FRTRCV_30_TJA1080_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */
/*! Contains the wake up reason of each configured Transceiver channel */
VAR( FrTrcv_TrcvWUReasonType, FRTRCV_30_TJA1080_VAR_NOINIT ) FrTrcv_30_Tja1080_TrcvWUReason[FRTRCV_30_TJA1080_MAX_NUM_OF_BTR_BUSSES]; /* PRQA S 3408 */ /* MD_FRTRCV_3408 */

#define FRTRCV_30_TJA1080_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */


#define FRTRCV_30_TJA1080_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */

#if ( FRTRCV_30_TJA1080_TRCV_DIAGNOSIS == STD_ON )
/*! Contains the error state flags of each configured Transceiver channel */
VAR( uint32, FRTRCV_30_TJA1080_VAR_NOINIT ) FrTrcv_30_Tja1080_BusErrorState[FRTRCV_30_TJA1080_MAX_NUM_OF_BTR_BUSSES]; /* PRQA S 3408 */ /* MD_FRTRCV_3408 */
#endif

#define FRTRCV_30_TJA1080_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */


/**************************************************************************************************
* Prototypes for local functions
**************************************************************************************************/

#define FRTRCV_30_TJA1080_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */


#if ( FRTRCV_30_TJA1080_TRCV_DIAGNOSIS == STD_ON )
/**********************************************************************************************************************
 *  FrTrcv_30_Tja1080_ErrorDiagnosis()
 *********************************************************************************************************************/
/*! 
 *  \brief       Check for transceiver errors.
 *  \details     Determine all errors signaled in the status word and memorize them for later read out. DEM is notified
 *               whether error detected or not.
 *  \param[in]   FrTrcv_TrcvIdx    The selected FlexRay bus transceiver.
 *  \param[in]   trcvCurrentStatusWord  The transceiver status word. Pointer must be valid. 
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      FRTRCV_30_TJA1080_TRCV_DIAGNOSIS.
 *  \trace DSGN-FrTrcv22842
 **********************************************************************************************************************/
FRTRCV_30_TJA1080_LOCAL_INLINE FUNC(void, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_ErrorDiagnosis(uint8 trcvIdx, FrTrcv_30_Tja1080_StatusWordType trcvCurrentStatusWord);
#endif


/**********************************************************************************************************************
 * FrTrcv_30_Tja1080_CheckWakeupEvent()
 **********************************************************************************************************************/
/*! \brief       Check for current and pending wakeup events.
 *  \details     Determine wake up events and possible errors from the status word Wake up and diagnosis are optional features
 *  \param[in]   FrTrcv_TrcvIdx    The selected FlexRay bus transceiver.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace DSGN-FrTrcv22842
 *********************************************************************************************************************/
FRTRCV_30_TJA1080_LOCAL FUNC(void, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_CheckWakeupEvent( FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_ONLY );



/**************************************************************************************************
 *  Implementation
 **************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  FrTrcv_30_Tja1080_ErrorDiagnosis()
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Check status word for error bits and get corresponding AR error flags
 *   - #15 Enter FRTRCV_30_TJA1080_EXCLUSIVE_AREA_0 section to allow atomic rmw of FrTrcv_30_Tja1080_BusErrorState
 *   - #16 Leave FRTRCV_30_TJA1080_EXCLUSIVE_AREA_0 section to allow atomic rmw of FrTrcv_30_Tja1080_BusErrorState
 *  - #20 If error detected trigger the DEM with DEM_EVENT_STATUS_PREFAILED
 *  - #30 If error is gone trigger DEM with DEM_EVENT_STATUS_PREPASSED
 * \endinternal
 */
#if ( FRTRCV_30_TJA1080_TRCV_DIAGNOSIS == STD_ON )
FRTRCV_30_TJA1080_LOCAL_INLINE FUNC(void, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_ErrorDiagnosis(uint8 trcvIdx, FrTrcv_30_Tja1080_StatusWordType trcvCurrentStatusWord)
{
  uint8_least i;
  uint8_least error_detected;

  FrTrcv_30_Tja1080_BusErrorState[trcvIdx] = (uint32)0u; /* SBSW_FRTRCV_TRCVIDX */
  error_detected = FALSE;
  /* #10 Check status word for error bits and get corresponding AR error flags */
  for(i=0; i<FrTrcv_30_Tja1080_Phy_StatusMaskTableSize; i++)
  {
    if( (trcvCurrentStatusWord & FrTrcv_30_Tja1080_Phy_StatusMaskTable[i]) > (FrTrcv_30_Tja1080_StatusWordType)0u )
    {
      /* We detected an error, memorize */
      error_detected = TRUE;
      /* #15 Enter FRTRCV_30_TJA1080_EXCLUSIVE_AREA_0 section to allow atomic rmw of FrTrcv_30_Tja1080_BusErrorState */
      FrTrcv_EnterCritical_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      FrTrcv_30_Tja1080_BusErrorState[trcvIdx] |= FrTrcv_30_Tja1080_Phy_ErrorTable[i]; /* SBSW_FRTRCV_TRCVIDX */
      /* #16 Leave FRTRCV_30_TJA1080_EXCLUSIVE_AREA_0 section to allow atomic rmw of FrTrcv_30_Tja1080_BusErrorState */
      FrTrcv_LeaveCritical_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
  }

  if( error_detected == TRUE )
  {
    /* #20 If error detected trigger the DEM with DEM_EVENT_STATUS_PREFAILED */
    FrTrcv_DemReportErrorPreFailed(FrTrcv_30_Tja1080_DEM_E_BusError_Channel[trcvIdx]);
  }
  else
  {
    /* #30 If error is gone trigger DEM with DEM_EVENT_STATUS_PREPASSED */
    FrTrcv_DemReportErrorPrePassed(FrTrcv_30_Tja1080_DEM_E_BusError_Channel[trcvIdx]);
  }
}
#endif


/**********************************************************************************************************************
 * FrTrcv_30_Tja1080_CheckWakeupEvent()
 **********************************************************************************************************************/
/*!
 * \internal
 * - #10 Get new transceiver status flags
 * - #20 Perform error diagnosis if configured
 * - #30 Get current mode as wake up is only detected in low power states (optional step if WAKEUP_SUPPORT is enabled) \trace DSGN-FrTrcv22819 
 * -  #40 Check for remote or local wake up with remote wake up having a higher priority
 * -   #50 if a wake up was detected, notify the EcuM about it
 * - #60 Otherwise nothing to be considered in active state \trace DSGN-FrTrcv22818
 * \endinternal
 */
FRTRCV_30_TJA1080_LOCAL FUNC(void, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_CheckWakeupEvent( FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_ONLY )
{
  /* ----- Local Variables ---------------------------------------------- */
#if ( FRTRCV_30_TJA1080_TRCV_DIAGNOSIS == STD_ON ) || ( FRTRCV_30_TJA1080_WAKEUP_SUPPORT == STD_ON )
  FrTrcv_30_Tja1080_StatusWordType trcvCurrentStatusWord;
#endif
#if ( FRTRCV_30_TJA1080_WAKEUP_SUPPORT == STD_ON )
  FrTrcv_TrcvModeType FrTrcv_TrcvMode;
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get new transceiver status flags */
#if ( FRTRCV_30_TJA1080_TRCV_DIAGNOSIS == STD_ON ) || ( FRTRCV_30_TJA1080_WAKEUP_SUPPORT == STD_ON )
  FrTrcv_30_Tja1080_Phy_ReadStatusWord(FRTRCV_30_TJA1080_CHANNEL_IDX, &trcvCurrentStatusWord); /* SBSW_FRTRCV_CALL_READSTATUSWORD */
#endif
#if ( FRTRCV_30_TJA1080_TRCV_DIAGNOSIS == STD_ON )
  /* #20 Perform error diagnosis if configured */
  FrTrcv_30_Tja1080_ErrorDiagnosis(FRTRCV_30_TJA1080_CHANNEL_IDX, trcvCurrentStatusWord);
#endif

#if ( FRTRCV_30_TJA1080_WAKEUP_SUPPORT == STD_ON )
  if( FrTrcv_30_Tja1080_Config[FRTRCV_30_TJA1080_CHANNEL_IDX].FrTrcv_WakeupByBusUsed > 0u )
  {
    /* #30 Get current mode as wake up is only detected in low power states (optional step if WAKEUP_SUPPORT is enabled) \trace DSGN-FrTrcv22819 */
    FrTrcv_30_Tja1080_Phy_GetMode(FRTRCV_30_TJA1080_CHANNEL_IDX, &FrTrcv_TrcvMode); /* SBSW_FRTRCV_CALL_TRCVPHYGETMODE */
    /* Without diagnosis, only STANDBY and SLEEP is relevant for wakeup */
    if( (FrTrcv_TrcvMode == FRTRCV_TRCVMODE_STANDBY) || (FrTrcv_TrcvMode == FRTRCV_TRCVMODE_SLEEP) )
    {
      /* #40 Check for remote or local wake up with remote wake up having a higher priority */
      if((trcvCurrentStatusWord & (FrTrcv_30_Tja1080_StatusWordType)FRTRCV_30_TJA1080_REMOTEWAKEUP) > (FrTrcv_30_Tja1080_StatusWordType)0u)
      {
        FrTrcv_30_Tja1080_TrcvWUReason[FRTRCV_30_TJA1080_CHANNEL_IDX] = FRTRCV_WU_BY_BUS; /* SBSW_FRTRCV_TRCVIDX */
        /* #50 if a wake up was detected, notify the EcuM about it */
        EcuM_SetWakeupEvent(FrTrcv_30_Tja1080_Config[FRTRCV_30_TJA1080_CHANNEL_IDX].FrTrcv_WakeupSourceRef);
      }
      else
      if((trcvCurrentStatusWord & (FrTrcv_30_Tja1080_StatusWordType)FRTRCV_30_TJA1080_LOCALWAKEUP) > (FrTrcv_30_Tja1080_StatusWordType)0u)
      {
        FrTrcv_30_Tja1080_TrcvWUReason[FRTRCV_30_TJA1080_CHANNEL_IDX] = FRTRCV_WU_BY_PIN; /* SBSW_FRTRCV_TRCVIDX */
        EcuM_SetWakeupEvent(FrTrcv_30_Tja1080_Config[FRTRCV_30_TJA1080_CHANNEL_IDX].FrTrcv_WakeupSourceRef);
      }
      else
      {
        /* Concluding else */
      }
    }
    /* #60 Otherwise nothing to be considered in active state \trace DSGN-FrTrcv22818 */
  }
#endif
} /* PRQA S 6080 */ /* MD_MSR_STMIF */


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

#if ( FRTRCV_30_TJA1080_API_OPTIMIZATION == STD_ON )
# define FrTrcv_30_Tja1080_CheckWakeupEvent(TrcvIdx)    FrTrcv_30_Tja1080_CheckWakeupEvent() /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif /* #if ( FRTRCV_30_TJA1080_API_OPTIMIZATION == STD_ON ) */


/***********************************************************************************************************************
 *  FrTrcv_30_Tja1080_InitMemory()
 **********************************************************************************************************************/
/*! 
 * \internal
 * - Set module to uninitialized state.
 * \endinternal
 */
FUNC(void, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_InitMemory( void )
{
  /* ----- Implementation ----------------------------------------------- */
  FrTrcv_30_Tja1080_IsInitialized = FRTRCV_30_TJA1080_UNINIT;
}


/**********************************************************************************************************************
 * FrTrcv_30_Tja1080_Init()
 **********************************************************************************************************************/
/*!
 * \internal
 * - #10 Iterate over all configured channels.
 *  - #20 Initialize physical transceiver, if required
 *  - #30 Initialize variables to initial/default values
 *  - #40 Check for pending wakeup events if wake up detection is enabled, throw DEM error if diagnosis is enabled
 *  - #50 Set the transceiver to a default state
 * \endinternal
 */
FUNC(void, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_Init( void )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 i;

  /* ----- Implementation ----------------------------------------------- */
  FrTrcv_30_Tja1080_IsInitialized = FRTRCV_30_TJA1080_UNINIT;
  /* #10 Iterate over all configured channels. */
  for(i = 0u; i < FrTrcv_30_Tja1080_MaxNumOfBtrBusses; i++)
  {
    /* #20 Initialize physical transceiver, if required */
    FrTrcv_30_Tja1080_Phy_Init(i);

    /* #30 Initialize variables to initial/default values */
#if ( FRTRCV_30_TJA1080_TRCV_DIAGNOSIS == STD_ON )
      FrTrcv_30_Tja1080_BusErrorState[i] = (uint32)0u; /* SBSW_FRTRCV_TRCVIDXLOOPCONDITION */
#endif
    FrTrcv_30_Tja1080_TrcvWUReason[i] = FRTRCV_WU_NOT_SUPPORTED; /* SBSW_FRTRCV_TRCVIDXLOOPCONDITION */
    /* #40 Check for pending wakeup events if wake up detection is enabled, throw DEM error if diagnosis is enabled */
    if( FrTrcv_30_Tja1080_Config[i].FrTrcv_WakeupByBusUsed > 0u)
    {
      FrTrcv_30_Tja1080_TrcvWUReason[i] = FRTRCV_WU_RESET; /* SBSW_FRTRCV_TRCVIDXLOOPCONDITION */
      FrTrcv_30_Tja1080_CheckWakeupEvent( i );
    }
    /* #50 Set the transceiver to a default state */
    (void)FrTrcv_30_Tja1080_Phy_SetMode(i, FrTrcv_30_Tja1080_Config[i].FrTrcv_InitState);
  }

  FrTrcv_30_Tja1080_IsInitialized = FRTRCV_30_TJA1080_INIT;
}


/***********************************************************************************************************************
 *  FrTrcv_30_Tja1080_MainFunction()
 **********************************************************************************************************************/
/*!
 * \internal
 * - #10 Only if initialized...
 *  - #20 Iterate over all configured channels.
 *   - #30 ...and if polling is used: check for pending wakeup events if wake up detection is enabled, throw DEM error if diagnosis is enabled.
 * \endinternal
 */
FUNC(void, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_MainFunction( void )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 trcvChannel;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Only if initialized... */
  if( FrTrcv_30_Tja1080_IsInitialized == FRTRCV_30_TJA1080_INIT )
  {
    /* #20 Iterate over all configured channels. */
    for(trcvChannel = 0u; trcvChannel < FrTrcv_30_Tja1080_MaxNumOfBtrBusses; trcvChannel++ )
    {
      /* #30 ...and if polling is used: check for pending wakeup events if wake up detection is enabled, throw DEM error if diagnosis is enabled. */
      if( FrTrcv_30_Tja1080_Config[trcvChannel].FrTrcv_WakeupByNodeUsedPolling == FRTRCV_WAKEUP_POLLING )
      {
        FrTrcv_30_Tja1080_CheckWakeupEvent(trcvChannel);
      }
    }
  }
}


#if ( FRTRCV_30_TJA1080_VERSION_INFO_API == STD_ON )
/***********************************************************************************************************************
 *  FrTrcv_30_Tja1080_GetVersionInfo()
 **********************************************************************************************************************/
/*!
 * \internal
 * - #10 Check versioninfo for NULL pointer. Note: no uninit check is performed.
 *  - #20 Set versioninfo with corresponding macros from component header.
 * \endinternal
 */
FUNC(void, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, FRTRCV_30_TJA1080_APPL_DATA) versioninfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FRTRCV_30_TJA1080_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if ( FRTRCV_30_TJA1080_DEV_ERROR_DETECT == STD_ON )
  if (versioninfo == NULL_PTR)
  {
    errorId = FRTRCV_30_TJA1080_E_FR_INVALID_POINTER;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  {
    versioninfo->vendorID         = (FRTRCV_30_TJA1080_VENDOR_ID); /* SBSW_FRTRCV_PARAM_GETVERSION */
    versioninfo->moduleID         = (FRTRCV_30_TJA1080_MODULE_ID); /* SBSW_FRTRCV_PARAM_GETVERSION */
    versioninfo->sw_major_version = (FRTRCV_30_TJA1080_SW_MAJOR_VERSION); /* SBSW_FRTRCV_PARAM_GETVERSION */
    versioninfo->sw_minor_version = (FRTRCV_30_TJA1080_SW_MINOR_VERSION); /* SBSW_FRTRCV_PARAM_GETVERSION */
    versioninfo->sw_patch_version = (FRTRCV_30_TJA1080_SW_PATCH_VERSION); /* SBSW_FRTRCV_PARAM_GETVERSION */
  }

  /* ----- Development Error Report --------------------------------------- */
#if ( FRTRCV_30_TJA1080_DEV_ERROR_REPORT == STD_ON )
  if (errorId != FRTRCV_30_TJA1080_E_NO_ERROR)
  {
    Det_ReportError(FRTRCV_30_TJA1080_MODULE_ID, FRTRCV_30_TJA1080_INSTANCE_ID_DET, FRTRCV_30_TJA1080_SID_GETVERSIONINFO, errorId);
  }
#else
  FRTRCV_30_TJA1080_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif
}
#endif


/***********************************************************************************************************************
 *  FrTrcv_30_Tja1080_SetTransceiverMode()
 **********************************************************************************************************************/
/*!
 * \internal
 * - #10 Check channel index and initialization state
 * - #20 Determine if valid mode (normal, standby, sleep, receiveonly) is requested and set mode
 * -  #30 Try to set the transceiver mode and return E_NOT_OK if this failed
 *  - #35 Set wake up reason to FRTRCV_WU_INTERNALLY in case of active mode
 * -  #40 Perform immediate detection of possible wake up event
 * -  #50 If invalid mode is requested, return no transceiver control error 
 * \endinternal
 */
FUNC(Std_ReturnType, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_SetTransceiverMode(FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_ONLY, FrTrcv_TrcvModeType FrTrcv_TrcvMode)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRTRCV_30_TJA1080_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if ( FRTRCV_30_TJA1080_DEV_ERROR_DETECT == STD_ON )
# if ( FRTRCV_30_TJA1080_API_OPTIMIZATION == STD_OFF )
  if( FRTRCV_30_TJA1080_CHANNEL_IDX >= FrTrcv_30_Tja1080_MaxNumOfBtrBusses )
  {
    errorId = FRTRCV_30_TJA1080_E_FR_INVALID_TRCVIDX;
  }
  else
# endif
  if( FrTrcv_30_Tja1080_IsInitialized == FRTRCV_30_TJA1080_UNINIT )
  {
    errorId = FRTRCV_30_TJA1080_E_FR_UNINIT;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  {
    /* #20 Determine if valid mode (normal, standby, sleep, receiveonly) is requested and set mode */
    switch(FrTrcv_TrcvMode)
    {
      case FRTRCV_TRCVMODE_NORMAL :
      case FRTRCV_TRCVMODE_RECEIVEONLY :
      case FRTRCV_TRCVMODE_STANDBY :
      case FRTRCV_TRCVMODE_SLEEP :
      {
        /* #30 Try to set the transceiver mode and return E_NOT_OK if this failed */
        retVal = FrTrcv_30_Tja1080_Phy_SetMode(FRTRCV_30_TJA1080_CHANNEL_IDX, FrTrcv_TrcvMode);
        if( retVal == E_NOT_OK ) /* COV_FRTRCV_30_TJA1080_SETMODE */
        {
          errorId = FRTRCV_30_TJA1080_E_FR_NO_CONTROL_TRCV;
        }
        else
        {
          /* #35 Set wake up reason to FRTRCV_WU_INTERNALLY in case of active mode */
#if ( FRTRCV_30_TJA1080_WAKEUP_SUPPORT == STD_ON )
          if( (FrTrcv_TrcvMode == FRTRCV_TRCVMODE_NORMAL) || (FrTrcv_TrcvMode == FRTRCV_TRCVMODE_RECEIVEONLY) )
          {
            FrTrcv_30_Tja1080_TrcvWUReason[FRTRCV_30_TJA1080_CHANNEL_IDX] = FRTRCV_WU_INTERNALLY; /* SBSW_FRTRCV_TRCVIDX */
          }
#endif
        }
        /* #40 Perform immediate detection of possible wake up event */
        FrTrcv_30_Tja1080_CheckWakeupEvent(FRTRCV_30_TJA1080_CHANNEL_IDX);
      } break;
      default :
      {
        /* #50 If invalid mode is requested, return no transceiver control error */
        errorId = FRTRCV_30_TJA1080_E_FR_NO_CONTROL_TRCV;
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if ( FRTRCV_30_TJA1080_DEV_ERROR_REPORT == STD_ON )
  if( errorId != FRTRCV_30_TJA1080_E_NO_ERROR )
  {
    Det_ReportError(FRTRCV_30_TJA1080_MODULE_ID, FRTRCV_30_TJA1080_INSTANCE_ID_DET, FRTRCV_30_TJA1080_SID_SETTRANSCEIVERMODE, errorId);
  }
#else
  FRTRCV_30_TJA1080_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif

  return(retVal);
} /* PRQA S 6080 */ /* MD_MSR_STMIF */


/***********************************************************************************************************************
 *  FrTrcv_30_Tja1080_GetTransceiverMode()
 **********************************************************************************************************************/
/*!
 * \internal
 * - #10 Check parameters and initialization state
 * - #20 Get current mode from PHY
 * \endinternal
 */
FUNC(Std_ReturnType, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_GetTransceiverMode(FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_ONLY, P2VAR(FrTrcv_TrcvModeType, AUTOMATIC, FRTRCV_30_TJA1080_APPL_DATA) FrTrcv_TrcvModePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRTRCV_30_TJA1080_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if ( FRTRCV_30_TJA1080_DEV_ERROR_DETECT == STD_ON )
# if ( FRTRCV_30_TJA1080_API_OPTIMIZATION == STD_OFF )
  if( FRTRCV_30_TJA1080_CHANNEL_IDX >= FrTrcv_30_Tja1080_MaxNumOfBtrBusses )
  {
    errorId = FRTRCV_30_TJA1080_E_FR_INVALID_TRCVIDX;
  }
  else
# endif
  if( FrTrcv_30_Tja1080_IsInitialized == FRTRCV_30_TJA1080_UNINIT )
  {
    errorId = FRTRCV_30_TJA1080_E_FR_UNINIT;
  }
  else
  if( FrTrcv_TrcvModePtr == NULL_PTR )
  {
    errorId = FRTRCV_30_TJA1080_E_FR_INVALID_POINTER;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  {
    /* #20 Get current mode from PHY */
    FrTrcv_30_Tja1080_Phy_GetMode(FRTRCV_30_TJA1080_CHANNEL_IDX, FrTrcv_TrcvModePtr); /* SBSW_FRTRCV_CALL_TRCVPHYGETMODE */
    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
#if ( FRTRCV_30_TJA1080_DEV_ERROR_REPORT == STD_ON )
  if( errorId != FRTRCV_30_TJA1080_E_NO_ERROR )
  {
    Det_ReportError(FRTRCV_30_TJA1080_MODULE_ID, FRTRCV_30_TJA1080_INSTANCE_ID_DET, FRTRCV_30_TJA1080_SID_GETTRANSCEIVERMODE, errorId);
  }
#else
  FRTRCV_30_TJA1080_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif

  return(retVal);
}


/***********************************************************************************************************************
 *  FrTrcv_30_Tja1080_GetTransceiverWUReason()
 **********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Check parameters and initialization state
 * - #20 Return last wake up reason, determined in FrTrcv_CheckWakeupEvent
 * \endinternal
 */
FUNC(Std_ReturnType, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_GetTransceiverWUReason(FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_ONLY, P2VAR(FrTrcv_TrcvWUReasonType, AUTOMATIC, FRTRCV_30_TJA1080_APPL_DATA) FrTrcv_TrcvWUReasonPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRTRCV_30_TJA1080_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if ( FRTRCV_30_TJA1080_DEV_ERROR_DETECT == STD_ON )
# if ( FRTRCV_30_TJA1080_API_OPTIMIZATION == STD_OFF )
  if( FRTRCV_30_TJA1080_CHANNEL_IDX >= FrTrcv_30_Tja1080_MaxNumOfBtrBusses )
  {
    errorId = FRTRCV_30_TJA1080_E_FR_INVALID_TRCVIDX;
  }
  else
# endif
  if( FrTrcv_30_Tja1080_IsInitialized == FRTRCV_30_TJA1080_UNINIT )
  {
    errorId = FRTRCV_30_TJA1080_E_FR_UNINIT;
  }
  else
  if( FrTrcv_TrcvWUReasonPtr == NULL_PTR )
  {
    errorId = FRTRCV_30_TJA1080_E_FR_INVALID_POINTER;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  {
    /* #20 Return last wake up reason, determined in FrTrcv_CheckWakeupEvent */
    *FrTrcv_TrcvWUReasonPtr = FrTrcv_30_Tja1080_TrcvWUReason[FRTRCV_30_TJA1080_CHANNEL_IDX]; /* SBSW_FRTRCV_PARAM_WUREASON */
    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
#if ( FRTRCV_30_TJA1080_DEV_ERROR_REPORT == STD_ON )
  if( errorId != FRTRCV_30_TJA1080_E_NO_ERROR )
  {
    Det_ReportError(FRTRCV_30_TJA1080_MODULE_ID, FRTRCV_30_TJA1080_INSTANCE_ID_DET, FRTRCV_30_TJA1080_SID_GETTRANSCEIVERWUREASON, errorId);
  }
#else
  FRTRCV_30_TJA1080_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif

  return(retVal);
}


/***********************************************************************************************************************
 *  FrTrcv_30_Tja1080_ClearTransceiverWakeup()
 **********************************************************************************************************************/
/*!
 * \internal
 * - #10 Check parameters and initialization state
 * - #30 Clear wake up state and set initial wake up reason
 * \endinternal
 */
FUNC(Std_ReturnType, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_ClearTransceiverWakeup(FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_ONLY)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRTRCV_30_TJA1080_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if ( FRTRCV_30_TJA1080_DEV_ERROR_DETECT == STD_ON )
# if ( FRTRCV_30_TJA1080_API_OPTIMIZATION == STD_OFF )
  if( FRTRCV_30_TJA1080_CHANNEL_IDX >= FrTrcv_30_Tja1080_MaxNumOfBtrBusses )
  {
    errorId = FRTRCV_30_TJA1080_E_FR_INVALID_TRCVIDX;
  }
  else
# endif
  if( FrTrcv_30_Tja1080_IsInitialized == FRTRCV_30_TJA1080_UNINIT )
  {
    errorId = FRTRCV_30_TJA1080_E_FR_UNINIT;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  {
    /* #30 Clear wake up state and set initial wake up reason */
    FrTrcv_30_Tja1080_TrcvWUReason[FRTRCV_30_TJA1080_CHANNEL_IDX] = FRTRCV_WU_RESET; /* SBSW_FRTRCV_TRCVIDX */
    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
#if ( FRTRCV_30_TJA1080_DEV_ERROR_REPORT == STD_ON )
  if( errorId != FRTRCV_30_TJA1080_E_NO_ERROR )
  {
    Det_ReportError(FRTRCV_30_TJA1080_MODULE_ID, FRTRCV_30_TJA1080_INSTANCE_ID_DET, FRTRCV_30_TJA1080_SID_CLEARTRANSCEIVERWAKEUP, errorId);
  }
#else
  FRTRCV_30_TJA1080_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif

  return(retVal);
}


/* FrTrcv442: */
/***********************************************************************************************************************
 *  FrTrcv_30_Tja1080_DisableTransceiverBranch()
 **********************************************************************************************************************/
/*!
 * \internal
 * - #10 Empty function due to the fact that the Tja1080 does not have branches
 * \endinternal
 */
FUNC(Std_ReturnType, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_DisableTransceiverBranch(FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_ONLY, uint8 FrTrcv_BranchIdx)
{
  /* avoid compiler warning due to unused parameters */
  FRTRCV_30_TJA1080_DUMMY_STATEMENT_CONST(FRTRCV_30_TJA1080_CHANNEL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  FRTRCV_30_TJA1080_DUMMY_STATEMENT(FrTrcv_BranchIdx); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */

  return(E_NOT_OK);
}

/* FrTrcv443: */
/***********************************************************************************************************************
 *  FrTrcv_30_Tja1080_EnableTransceiverBranch()
 **********************************************************************************************************************/
/*!
 * \internal
 * - #10 Empty function due to the fact that the Tja1080 does not have branches
 * \endinternal
 */
FUNC(Std_ReturnType, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_EnableTransceiverBranch(FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_ONLY, uint8 FrTrcv_BranchIdx)
{
  /* avoid compiler warning due to unused parameters */
  FRTRCV_30_TJA1080_DUMMY_STATEMENT_CONST(FRTRCV_30_TJA1080_CHANNEL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  FRTRCV_30_TJA1080_DUMMY_STATEMENT(FrTrcv_BranchIdx); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */

  return(E_OK);
}


/* FrTrcv419: */
/***********************************************************************************************************************
 *  FrTrcv_30_Tja1080_GetTransceiverError()
 **********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Check parameters and initialization state
 * - #20 Return last transceiver error or no error if FRTRCV_30_TJA1080_TRCV_DIAGNOSIS is disabled
 * - #30 Enter FRTRCV_30_TJA1080_EXCLUSIVE_AREA_0 section to allow atomic read of FrTrcv_30_Tja1080_BusErrorState
 * - #40 Leave FRTRCV_30_TJA1080_EXCLUSIVE_AREA_0 section to allow atomic read of FrTrcv_30_Tja1080_BusErrorState
 * \endinternal
 */
FUNC(Std_ReturnType, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_GetTransceiverError(FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_ONLY, uint8 FrTrcv_BranchIdx, P2VAR(uint32, AUTOMATIC, FRTRCV_30_TJA1080_APPL_DATA) FrTrcv_BusErrorStatePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRTRCV_30_TJA1080_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if ( FRTRCV_30_TJA1080_DEV_ERROR_DETECT == STD_ON )
# if ( FRTRCV_30_TJA1080_API_OPTIMIZATION == STD_OFF )
  if( FRTRCV_30_TJA1080_CHANNEL_IDX >= FrTrcv_30_Tja1080_MaxNumOfBtrBusses )
  {
    errorId = FRTRCV_30_TJA1080_E_FR_INVALID_TRCVIDX;
  }
  else
# endif
  if( FrTrcv_BusErrorStatePtr == NULL_PTR )
  {
    errorId = FRTRCV_30_TJA1080_E_FR_INVALID_POINTER;
  }
  else
  if( FrTrcv_30_Tja1080_IsInitialized == FRTRCV_30_TJA1080_UNINIT )
  {
    errorId = FRTRCV_30_TJA1080_E_FR_UNINIT;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  {
    /* #20 Return last transceiver error or no error if FRTRCV_30_TJA1080_TRCV_DIAGNOSIS is disabled */
#if ( FRTRCV_30_TJA1080_TRCV_DIAGNOSIS == STD_ON )
      /* #30 Enter FRTRCV_30_TJA1080_EXCLUSIVE_AREA_0 section to allow atomic read of FrTrcv_30_Tja1080_BusErrorState */
      FrTrcv_EnterCritical_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      *FrTrcv_BusErrorStatePtr = FrTrcv_30_Tja1080_BusErrorState[FRTRCV_30_TJA1080_CHANNEL_IDX]; /* SBSW_FRTRCV_PARAM_TRCVERROR */
      /* #40 Leave FRTRCV_30_TJA1080_EXCLUSIVE_AREA_0 section to allow atomic read of FrTrcv_30_Tja1080_BusErrorState */
      FrTrcv_LeaveCritical_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
#else
      *FrTrcv_BusErrorStatePtr = 0u; /* SBSW_FRTRCV_PARAM_TRCVERROR */
      FRTRCV_30_TJA1080_DUMMY_STATEMENT_CONST(FRTRCV_30_TJA1080_CHANNEL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif
    /* avoid compiler warning due to unused parameters */
    FRTRCV_30_TJA1080_DUMMY_STATEMENT(FrTrcv_BranchIdx); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
#if ( FRTRCV_30_TJA1080_DEV_ERROR_REPORT == STD_ON )
  if( errorId != FRTRCV_30_TJA1080_E_NO_ERROR )
  {
    Det_ReportError(FRTRCV_30_TJA1080_MODULE_ID, FRTRCV_30_TJA1080_INSTANCE_ID_DET, FRTRCV_30_TJA1080_SID_GETTRANSCEIVERERROR, errorId);
  }
#else
  FRTRCV_30_TJA1080_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif

  return(retVal);
}


/***********************************************************************************************************************
 *  FrTrcv_30_Tja1080_CheckWakeupByTransceiver()
 **********************************************************************************************************************/
/*!
 * \internal
 * - #10 If this function is called before the module is initialized, do nothing.
 * - #20 Otherwise: Perform wake up or bus error diagnosis check if enabled.
 * \endinternal
 */
FUNC(void, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_CheckWakeupByTransceiver(FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_ONLY)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FRTRCV_30_TJA1080_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if ( FRTRCV_30_TJA1080_API_OPTIMIZATION == STD_OFF )
  if( FRTRCV_30_TJA1080_CHANNEL_IDX >= FrTrcv_30_Tja1080_MaxNumOfBtrBusses )
  {
    errorId = FRTRCV_30_TJA1080_E_FR_INVALID_TRCVIDX;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  {
    /* #10 If this function is called before the module is initialized, do nothing. */
    if( FrTrcv_30_Tja1080_IsInitialized == FRTRCV_30_TJA1080_INIT )
    {
      /* #20 Otherwise: Perform wake up or bus error diagnosis check if enabled. */
      FrTrcv_30_Tja1080_CheckWakeupEvent(FRTRCV_30_TJA1080_CHANNEL_IDX);
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (( FRTRCV_30_TJA1080_DEV_ERROR_REPORT == STD_ON ) && ( FRTRCV_30_TJA1080_API_OPTIMIZATION == STD_OFF ))
  if( errorId != FRTRCV_30_TJA1080_E_NO_ERROR )
  {
    Det_ReportError(FRTRCV_30_TJA1080_MODULE_ID, FRTRCV_30_TJA1080_INSTANCE_ID_DET, FRTRCV_30_TJA1080_SID_CHECKWAKEUPBYTRANSCEIVER, errorId);
  }
#else
  FRTRCV_30_TJA1080_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif
}


#define FRTRCV_30_TJA1080_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */


/* module specific MISRA deviations:
  MD_FRTRCV_3408: Rule 8.8
      Reason:     Declaration is defined in the component implementation file
      Risk:       There is no risk as generator and implementation match. This is checked in the test environment.
      Prevention: Covered by code review.
  MD_FRTRCV_3447: Rule 8.8
      Reason:     Constant is used module internally. There is no need for external visibility
      Risk:       There is no risk as visibility of variables do not influence functionality.
      Prevention: Covered by code review.
  MD_FRTRCV_3684: Rule 8.12
      Reason:     Array is declared without size to prevent unwanted compiler optimization in case of size 1
      Risk:       There is no risk, as no sizeof operator is used on this array.
      Prevention: Covered by code review.
*/


/* COV_JUSTIFICATION_BEGIN

\ID COV_FRTRCV_30_TJA1080_SOURCE
\ACCEPT XF
\REASON Only False branch is covered because COV_FRTRCV_30_TJA1080_SOURCE is only defined in FrTrcv_30_Tja1080.c
        and the macros shall only be redefined in the C-file (not in the header). Otherwise the single channel
        API optimization will cause an compiler warning.

\ID COV_FRTRCV_30_TJA1080_MSR_HEADERGUARD
\ACCEPT TX
\REASON [COV_MSR_HEADERGUARD]

\ID COV_FRTRCV_30_TJA1080_MSR_COMPATIBILITY
\ACCEPT TX
\REASON [COV_MSR_COMPATIBILITY]

\ID COV_FRTRCV_30_TJA1080_MSR_CONSISTENCYCHECK
\ACCEPT XF xf xf xf
\REASON [COV_MSR_CONSISTENCYCHECK]

\ID COV_FRTRCV_30_TJA1080_SETMODE
\ACCEPT XF
\REASON The called function is transceiver dependent and can be modified. For the used Trcv it always returns E_OK.

COV_JUSTIFICATION_END */


/* SBSW_JUSTIFICATION_BEGIN

  \ID SBSW_FRTRCV_TRCVIDX
  \DESCRIPTION Array write access; access might exceed array bounds. Correct index is expected.
  \COUNTERMEASURE \M [SBSW_CM_FRTRCV_CONFIGPARAMETER_CHECK] [SBSW_CM_FRTRCV_BOUNDSPARAMETER_CHECK]
  
  \ID SBSW_FRTRCV_TRCVIDXLOOPCONDITION
  \DESCRIPTION Array write access; access might exceed array bounds. Index must be within bounds.
  \COUNTERMEASURE \M Check Array size against loop condition.

  \ID SBSW_FRTRCV_PARAM_GETVERSION
  \DESCRIPTION    The FrTrcv_GetVersionInfo writes to the 'versioninfo' pointer parameter. It is checked against NULL,
                  but this does not guarantee that the referenced memory is valid. The calling module must provide a valid pointer.
  \COUNTERMEASURE \S Add constraint to the safety manual. [SBSW_CM_FRTRCV_API_POINTER]

  \ID SBSW_FRTRCV_PARAM_WUREASON
  \DESCRIPTION    The FrTrcv_GetTransceiverWUReason writes to the 'FrTrcv_TrcvWUReasonPtr' pointer parameter. It is checked against NULL,
                  but this does not guarantee that the referenced memory is valid. The calling module must provide a valid pointer.
  \COUNTERMEASURE \S Add constraint to the safety manual. [SBSW_CM_FRTRCV_API_POINTER]

  \ID SBSW_FRTRCV_PARAM_TRCVERROR
  \DESCRIPTION    The FrTrcv_GetTransceiverError writes to the 'FrTrcv_BusErrorStatePtr' pointer parameter. It is checked against NULL,
                  but this does not guarantee that the referenced memory is valid. The calling module must provide a valid pointer.
  \COUNTERMEASURE \S Add constraint to the safety manual. [SBSW_CM_FRTRCV_API_POINTER]

  \ID SBSW_FRTRCV_CALL_READSTATUSWORD
  \DESCRIPTION    The function FrTrcv_30_Tja1080_Phy_ReadStatusWord is called with two parameters, an index and a pointer
                  - The index is checked in the calling functions
				    - FrTrcv_30_Tja1080_Init uses the same size as loop condition as in the definition of the array is index is used for
					- FrTrcv_30_Tja1080_MainFunction uses FrTrcv_30_Tja1080_MaxNumOfBtrBusses which has the same size by definition
					- FrTrcv_30_Tja1080_CheckWakeupByTransceiver uses DET check
				  - The pointer is a reference to a locally defined variable
  \COUNTERMEASURE \M DET must be enabled. [SBSW_CM_FRTRCV_CONFIGPARAMETER_CHECK]
  
  \ID SBSW_FRTRCV_CALL_TRCVPHYGETMODE
  \DESCRIPTION    The function FrTrcv_30_Tja1080_Phy_GetMode is called with two parameters, an index and a pointer
				  - The index is only used for read access in the called function.
				  - The pointer is passed from the calling function
  \COUNTERMEASURE \M DET must be enabled. [SBSW_CM_FRTRCV_CONFIGPARAMETER_CHECK]

  \ID SBSW_CM_FRTRCV_BOUNDSPARAMETER_CHECK
  \DESCRIPTION    Verify the correct size of selected parameters
  \COUNTERMEASURE \M It must be verified that the generated constant FrTrcv_30_Tja1080_MaxNumOfBtrBusses has the same size than the define
                     FRTRCV_30_TJA1080_MAX_NUM_OF_BTR_BUSSES

  \ID SBSW_CM_FRTRCV_CONFIGPARAMETER_CHECK
  \DESCRIPTION    Verify configuration parameters to be enabled
  \COUNTERMEASURE \M The switch FRTRCV_30_TJA1080_DEV_ERROR_DETECT must be enabled

  \ID SBSW_CM_FRTRCV_API_POINTER
  \DESCRIPTION    Pointers passed to FRTRCV API must point to a valid memory range.
  \COUNTERMEASURE \N Caller ensures valid pointers [SMI-16]
  
SBSW_JUSTIFICATION_END */


/**********************************************************************************************************************
 *  END OF FILE: FrTrcv_30_Tja1080.c
 *********************************************************************************************************************/
