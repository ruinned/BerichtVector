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
/*  \file  FrTrcv_30_Tja1080.h
 *  \brief  MICROSAR FR Transceiver Driver
 *
 *  \details  FlexRay transceiver driver header file
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Andreas Herkommer             hr            Vector Informatik GmbH
 *  Klaus Bergdolt                ber           Vector Informatik GmbH
 *  Sebastian Schmar              ssr           Vector Informatik GmbH
 *  Oliver Reineke                ore           Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2005-05-24  hr      -             Creation
 *  01.02.00   2006-05-22  ber     -             Adaptation to AUTOSAR 2.0
 *  02.00.00   2006-08-24  hr      -             Complete rework for Gen2
 *  02.01.00   2006-12-15  ber     -             Import wakeup source definition from EcuM.h
 *  02.02.00   2007-07-26  ssr     -             Initialize FrTrcv_Status word with zero, 
 *                                               delete readout of status word within init phase
 *  02.03.00   2007-08-31  hr      -             Minor Updates, Memory Mapping
 *  02.03.01   2007-12-16  hr      -             ESCAN00023747 Development Error Tracer was triggered by wrong compares
 *  03.00.00   2008-02-05  hr      -             Complete rework for AUTOSAR Release 3.0
 *  03.00.01   2008-02-12  hr      -             Minor updates
 *  03.00.02   2008-02-13  hr      -             Editorial changes
 *  03.00.03   2008-03-12  hr      -             Compiler Abstraction
 *             2008-03-12  hr      -             New configuration parameters
 *             2008-03-12  hr      -             MISRA checks
 *  03.00.04   2008-03-28  hr      -             Incorporated Review findings
 *  03.00.05   2008-04-01  hr      ESCAN00025654 Clear Transceiver Wakeup
 *  03.00.06   2008-04-18  hr      ESCAN00025971 DEM events wrapper
 *             2008-04-18  hr      ESCAN00025640 Version check of GENy component against implementation
 *             2008-04-18  hr      ESCAN00026133 Support of InitMemory service
 *             2008-04-18  hr      ESCAN00026286 Wakeup detected init
 *             2008-04-18  hr      ESCAN00026287 interrupt & polling in CB
 *             2008-04-18  hr      -             Lib version check
 *  03.00.07   2008-06-04  hr      ESCAN00027346 Removed FRTRCV_WU_POWER_ON and FRTRCV_LOCALWAKEUP detection
 *  03.00.08   2008-07-04  hr      ESCAN00026625 Extension for MSR3.0 generator version checks
 *  03.00.09   2008-08-18  hr      ESCAN00029287 Single Channel API incomplete for FrTrcv_30_Tja1080dio_Cbk_WakeupByTransceiver
 *             2008-08-18  hr      ESCAN00029454 Library issue with number of Transceivers
 *  03.01.00   2008-10-01  hr      ESCAN00029735 instanceID by FrTrcv_30_Tja1080dio_GetVersionInfo not set
 *  03.02.00   2008-11-07  hr      ESCAN00031137 ERRN Pin not low for wakeup detection
 *  03.03.00   2008-11-19  hr      ESCAN00030263 PreCompile and Linktime Crc Check
 *  03.04.00   2008-11-27  hr      ESCAN00031637 Remove Support of SWS Req FrTrcv309
 *  03.05.00   2008-12-02  hr      ESCAN00031775 Remove unnecessary MISRA violations
 *  03.05.01   2009-02-25  hr      ESCAN00033397 Missing extern in call-back declaration
 *             2009-02-25  hr      ESCAN00029695 AUTOSAR Dummy Statements
 *             2009-02-25  hr      ESCAN00033495 Wrong MemMap.h sections used
 *             2009-02-25  hr      ESCAN00034964 Single Channel API change for AUTOSAR SWS compliance
 *  03.05.02   2009-05-05  hr      ESCAN00034905 Wrong MemMap.h Stop section defines
 *  03.05.03   2009-05-06  hr      ESCAN00034037 Compile warnings by extended version checks
 *  03.05.04   2009-07-30  hr      ESCAN00036155 pre-processor checks for building the library
 *  03.05.05   2009-10-29  hr      ESCAN00038804 Support Vendor Id and vendor api infix in file and API names
 *  03.05.06   2010-01-19  hr      ESCAN00040215 Extended Version Check causes compile error
 *             2010-02-08  hr      ESCAN00040646 Remove dio in naming
 *  03.05.07   2010-03-26  hr      ESCAN00041864 EcuM_SetWakeupEvent call with active interrupt locks
 *             2010-04-21  hr      ESCAN00040839 Move FrTrcv_TrcvModeType and FrTrcv_TrcvWUReasonType to Fr_GeneralTypes.h
 *  03.05.08   2010-05-18  hr      ESCAN00042990 Missing MISRA2004 justifications
 *                                 ESCAN00043289 Interrupts are enabled to early in FrTrcv_Phy
 *  03.05.09   2010-07-15  hr      ESCAN00044081 Transceiver might hang in Goto-Sleep Mode
 *  03.06.00   2011-02-22  hr      ESCAN00047306 Adapt MainFunction for usage with IdentityManagerConfig
 *  03.06.01   2011-07-19  ore     ESCAN00050103 Extern declaration with array size is used
 *             2011-08-15  ore     ESCAN00035705 Similar DET Usage
 *             2011-08-15  ore     ESCAN00048980 Support of FrTrcvWakeUpSupport configuration parameter
 *  03.06.02   2011-11-04  hr      ESCAN00054673 Compilation error if different FlexRay transceivers are used
 *             2011-11-17  hr      ESCAN00054897 Wake up is detected while in Normal Mode
 *  03.07.00   2011-11-18  hr      ESCAN00054957 Extend implementation with ASR4 API
 *  03.07.01   2011-12-07  hr      ESCAN00053417 AR3-2069: Remove non-SchM code for critical section handling
 *  03.07.02   2012-07-20  hr      ESCAN00060219 Support ASR4 critical section handling 
 *                         hr      ESCAN00060220 Cfg5: compiler error with missing DRVTRANS_TJA1080_FR_ASR_DLL_VERSION
 *                         hr      ESCAN00060980 compiler error: GetVersionInfo API writes Instance ID
 *  03.08.00   2012-11-12  hr      ESCAN00056613 Delay loop optimized away, replace with timer call outs
 *                         hr      ESCAN00061053 Support user dio call out
 *                         hr      ESCAN00060091 DET error caused by early ICU notification.
 *                         hr      ESCAN00060220 Cfg5: compiler error with missing DRVTRANS_TJA1080_FR_ASR_DLL_VERSION
 *  03.08.01   2013-04-25  hr      ESCAN00066931 FrTrcv_30_Tja1080_TrcvInit shall be named FrTrcv_30_Tja1080_Init
 *                         hr      ESCAN00066941 Variable in section noinit is initialized during InitMemory
 *                         hr      ESCAN00066940 Variable enclosed in memory mapping sections inside function
 *                         hr      ESCAN00066856 AR4-220: redefine STATIC to static
 *                         hr      ESCAN00067027 Create seperate Exclusive Areas for SetMode/ReadStatusWord
 *  03.09.00   2013-07-11  hr      ESCAN00066938 Implement FrTrcv_30_Tja1080_GetTransceiverError
 *                         hr      ESCAN00069547 Improve AR compatibility by adding <vendor>_<device> infix
 *  04.00.00   2015-01-15  hr      ESCAN00080595 UNINIT DET check of function FrTrcv_GetTransceiverError does not work
 *                         hr      ESCAN00080737 Diagnosis not working if wake up detection is not enabled
 *                         hr      ESCAN00081035 DEM status not triggered continuously when healed
 *                         hr      ESCAN00080313 FEAT-427: SafeBSW Step I
 *             2015-05-21  hr      ESCAN00081798 FEAT-1275: SafeBSW Step 2
 *             2015-10-15  hr      ESCAN00085850 Wake Up reason not set to FRTRCV_WU_INTERNALLY if mode is set to NORMAL
 *                         hr      ESCAN00085867 Default mode might overwrite wake up during FrTrcv_Init
 *             2015-10-29  hr      ESCAN00086143 No explicit wake up detection in FrTrcv_SetTransceiverMode
 *  04.01.00   2016-02-03  hr      ESCAN00088026 Implement HSI description
 *                         hr      ESCAN00088930 FEAT-1688: SafeBSW Step 4
 *             2016-03-16  hr      ESCAN00088950 Critical section missing
 *********************************************************************************************************************/
#if !defined (FRTRCV_30_TJA1080_H) /* COV_FRTRCV_30_TJA1080_MSR_HEADERGUARD */
# define FRTRCV_30_TJA1080_H


/**************************************************************************************************
* Include files
**************************************************************************************************/
# include "ComStack_Types.h"
# include "Fr_GeneralTypes.h"
# include "FrTrcv_30_Tja1080_Cfg.h"
# include "SchM_FrTrcv_30_Tja1080.h"

# if ( FRTRCV_30_TJA1080_WAKEUP_SUPPORT == STD_ON )
#  include "EcuM_Cbk.h"
# endif

# if ( FRTRCV_30_TJA1080_PROD_ERROR_DETECT == STD_ON )
#  include "Dem.h"
# endif


/**************************************************************************************************
* Version
**************************************************************************************************/

/* Vendor and module identification */
# define FRTRCV_30_TJA1080_VENDOR_ID (30u) /* Vector = 30 */
# define FRTRCV_30_TJA1080_MODULE_ID (71u) /* FlexRay Trcv = 71 */

/* ----- AUTOSAR Software specification version information ----- */
# define FRTRCV_30_TJA1080_AR_RELEASE_MAJOR_VERSION     (4u)
# define FRTRCV_30_TJA1080_AR_RELEASE_MINOR_VERSION     (0u)
# define FRTRCV_30_TJA1080_AR_RELEASE_REVISION_VERSION  (3u)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define FRTRCV_30_TJA1080_SW_MAJOR_VERSION     (4u)
# define FRTRCV_30_TJA1080_SW_MINOR_VERSION     (1u)
# define FRTRCV_30_TJA1080_SW_PATCH_VERSION     (0u)

# define FRTRCV_30_TJA1080_INSTANCE_ID_DET      (0x00u)


/**************************************************************************************************
* Global defines
**************************************************************************************************/
/* Critical section 1 is used for timing critical sections which must not be interrupted by any interrupt */
/* Critical section 0 is used for critical sections which can be interrupted by other CAT1 interrupts */
# define FrTrcv_EnterCritical_0() SchM_Enter_FrTrcv_30_Tja1080_FRTRCV_30_TJA1080_EXCLUSIVE_AREA_0()
# define FrTrcv_LeaveCritical_0() SchM_Exit_FrTrcv_30_Tja1080_FRTRCV_30_TJA1080_EXCLUSIVE_AREA_0()
# define FrTrcv_EnterCritical_1() SchM_Enter_FrTrcv_30_Tja1080_FRTRCV_30_TJA1080_EXCLUSIVE_AREA_1()
# define FrTrcv_LeaveCritical_1() SchM_Exit_FrTrcv_30_Tja1080_FRTRCV_30_TJA1080_EXCLUSIVE_AREA_1()

# if ( FRTRCV_30_TJA1080_API_OPTIMIZATION == STD_ON )
  /* The channel handle can be optimized in single channel configurations. */
  /* Definition of channel parameter. */
/* PRQA S 3460 1 */ /*  MD_MSR_19.4 */
#  define FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_ONLY    void
#  define FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_FIRST
#  define FRTRCV_30_TJA1080_CHANNEL_IDX                0u
# else
  /* Definition of channel parameter. */
#  define FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_ONLY    uint8 FrTrcv_TrcvIdx
#  define FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_FIRST   uint8 FrTrcv_TrcvIdx,
#  define FRTRCV_30_TJA1080_CHANNEL_IDX                FrTrcv_TrcvIdx
# endif

# if !defined ( FRTRCV_30_TJA1080_LOCAL ) /* COV_FRTRCV_30_TJA1080_MSR_COMPATIBILITY */
#  define FRTRCV_30_TJA1080_LOCAL static
# endif

# if !defined ( FRTRCV_30_TJA1080_LOCAL_INLINE ) /* COV_FRTRCV_30_TJA1080_MSR_COMPATIBILITY */
#  define FRTRCV_30_TJA1080_LOCAL_INLINE static
# endif


/* ----- API service IDs ----- */
# define FRTRCV_30_TJA1080_SID_INIT                              0u
# define FRTRCV_30_TJA1080_SID_SETTRANSCEIVERMODE                1u
# define FRTRCV_30_TJA1080_SID_GETTRANSCEIVERMODE                5u
# define FRTRCV_30_TJA1080_SID_GETTRANSCEIVERWUREASON            6u
# define FRTRCV_30_TJA1080_SID_GETVERSIONINFO                    7u
# define FRTRCV_30_TJA1080_SID_GETTRANSCEIVERERROR               8u
# define FRTRCV_30_TJA1080_SID_CLEARTRANSCEIVERWAKEUP           12u
# define FRTRCV_30_TJA1080_SID_MAINFUNCTION                     13u
# define FRTRCV_30_TJA1080_SID_CHECKWAKEUPBYTRANSCEIVER         14u
# define FRTRCV_30_TJA1080_SID_DISABLETRANSCEIVERBRANCH         15u
# define FRTRCV_30_TJA1080_SID_ENABLETRANSCEIVERBRANCH          16u 

/* ----- FrTrcv420: Bit mask for transceiver errors ----- */
# define FRTRCV_30_TJA1080_BDE_GLOBAL                           0x0001u
# define FRTRCV_30_TJA1080_BDE_SHORT_CIRCUIT_BM_BP              0x0002u
# define FRTRCV_30_TJA1080_BDE_BP_SHORT_CIRCUIT_GND             0x0004u
# define FRTRCV_30_TJA1080_BDE_BP_SHORT_CIRCUIT_VCC             0x0008u
# define FRTRCV_30_TJA1080_BDE_BM_SHORT_CIRCUIT_GND             0x0010u
# define FRTRCV_30_TJA1080_BDE_BM_SHORT_CIRCUIT_VCC             0x0020u
# define FRTRCV_30_TJA1080_BDE_GENERAL_FAULT                    0x0040u
# define FRTRCV_30_TJA1080_BDE_UNDERVOLTAGE                     0x0080u
# define FRTRCV_30_TJA1080_BDE_TXEN_TIMEOUT                     0x0100u
# define FRTRCV_30_TJA1080_BDE_OVER_TEMPERATURE                 0x0200u
# define FRTRCV_30_TJA1080_BDE_NOISE                            0x0400u

/* ----- Error codes ----- */
# define FRTRCV_30_TJA1080_E_NO_ERROR                           0x00u
# define FRTRCV_30_TJA1080_E_FR_INVALID_TRCVIDX                 0x01u
# define FRTRCV_30_TJA1080_E_FR_UNINIT                          0x10u
# define FRTRCV_30_TJA1080_E_FR_TRCV_NOT_STANDBY                0x11u
# define FRTRCV_30_TJA1080_E_FR_TRCV_NOT_NORMAL                 0x12u
# define FRTRCV_30_TJA1080_E_FR_TRCV_NOT_SLEEP                  0x13u
# define FRTRCV_30_TJA1080_E_FR_TRCV_NOT_RECEIVEONLY            0x14u
# define FRTRCV_30_TJA1080_E_FR_NO_CONTROL_TRCV                 0x15u
/* Additional development errors, not officially specified yet */
# define FRTRCV_30_TJA1080_E_FR_INVALID_POINTER                 0x20u
# define FRTRCV_30_TJA1080_E_FR_GENERATOR_COMPATIBILITY_ERROR   0x21u


/**************************************************************************************************
* Global data types and structures
**************************************************************************************************/

# if !defined (FRTRCV_WAKEUP_NONE) /* COV_FRTRCV_30_TJA1080_MSR_COMPATIBILITY */
#  define FRTRCV_WAKEUP_NONE              (uint8)0u
# endif
# if !defined (FRTRCV_WAKEUP_POLLING) /* COV_FRTRCV_30_TJA1080_MSR_COMPATIBILITY */
#  define FRTRCV_WAKEUP_POLLING           (uint8)1u
# endif
# if !defined (FRTRCV_WAKEUP_INTERRUPT) /* COV_FRTRCV_30_TJA1080_MSR_COMPATIBILITY */
#  define FRTRCV_WAKEUP_INTERRUPT         (uint8)2u
# endif

/*! Type defining the configuration structure used in FrTrcv_Cfg.c */
typedef struct
{
  FrTrcv_TrcvModeType    FrTrcv_InitState;       /*<! The initial operation mode */  
# if ( FRTRCV_30_TJA1080_WAKEUP_SUPPORT == STD_ON )  
  EcuM_WakeupSourceType  FrTrcv_WakeupSourceRef; /*<! Wake up source reference */
# else
  uint32                 FrTrcv_WakeupSourceRef; /*<! Wake Up Source Reference dummy*/
# endif  
  uint8                  FrTrcv_WakeupByNodeUsedPolling; /*<! Is wake up detected by polling oder isr */
  uint8                  FrTrcv_WakeupByBusUsed; /*<! Is wake up supported on this channel */
} FrTrcv_30_Tja1080_GenConfigType;

/*! Type used for DET init check */
typedef uint8 FrTrcv_30_Tja1080_InitStatusType;

/**************************************************************************************************
* Prototypes of export variables
**************************************************************************************************/

/****************************************************************************/
/* Constants for export with unspecified size                               */
/****************************************************************************/
# define FRTRCV_30_TJA1080_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */

extern CONST( uint8, FRTRCV_30_TJA1080_CONST ) FrTrcv_30_Tja1080_MaxNumOfBtrBusses;
extern CONST( FrTrcv_30_Tja1080_GenConfigType, FRTRCV_30_TJA1080_CONST ) FrTrcv_30_Tja1080_Config[]; /* PRQA S 3684 */ /* MD_FRTRCV_3684 */

# define FRTRCV_30_TJA1080_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */

/****************************************************************************/
/* 32 Bit Constants for export                                              */
/****************************************************************************/
# define FRTRCV_30_TJA1080_START_SEC_CONST_32BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */

# define FRTRCV_30_TJA1080_STOP_SEC_CONST_32BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */


/**************************************************************************************************
* Prototypes of export functions
**************************************************************************************************/

# define FRTRCV_30_TJA1080_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */

/***********************************************************************************************************************
 *  FrTrcv_30_Tja1080_InitMemory()
 **********************************************************************************************************************/
/*! \brief       Initialize static variables.
 *  \details     This function must be used if the startup code does not initialize the memory.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 **********************************************************************************************************************/
FUNC(void, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_InitMemory( void );

/**********************************************************************************************************************
 * FrTrcv_30_Tja1080_Init()
 **********************************************************************************************************************/
/*! \brief       Component initialization function.
 *  \details     This function initializes the module FrTrcv. It initializes all variables and sets the module state to
 *               initialized. Furthermore pending wake up events are checked and the transceiver device is set to a
 *               default mode.
 *  \pre         FrTrcv_InitMemory has been called unless FrTrcv_ModuleInitialized is initialized by start-up code.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace SPEC-43639, SPEC-43524 DIO can not fail, SPEC-43532, SPEC-43648, SPEC-43506, SPEC-43677
 *  \trace SPEC-43566 Always performed if diagnosis is enabled. Parameter FrTrcvErrorCheckInInit not evaluated
 *  \trace SPEC-43673, SPEC-43620, SPEC-43688, SPEC-43670, SPEC-43578, SPEC-43577, SPEC-43666
 *  \trace CREQ-705
 **********************************************************************************************************************/
FUNC(void, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_Init(void);

/***********************************************************************************************************************
 *  FrTrcv_30_Tja1080_MainFunction()
 **********************************************************************************************************************/
/*! \fn          FrTrcv_30_Tja1080_MainFunction
 *  \brief       Cyclic task function of the comnponent
 *  \details     The MainFunction must be called cyclically to perform tasks used in polling use case like wake up and
 *               error detection.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace SPEC-22506, SPEC-22509 The SchM always expects a MainFunction. Therefore this optimnization was omitted.
 *  \trace SPEC-43557 Internal function is used to detect the error information. GetTransceiverError is only used for reporting.
 *  \trace SPEC-43683, SPEC-43511, SPEC-43547, SPEC-43665, SPEC-43580, SPEC-22464, SPEC-22393
 *  \trace SPEC-22401, SPEC-43653, SPEC-43509
 **********************************************************************************************************************/
/* In ASR4 MainFunction prototype is declared in SchM */

# if ( FRTRCV_30_TJA1080_VERSION_INFO_API == STD_ON )
/***********************************************************************************************************************
 *  FrTrcv_30_Tja1080_GetVersionInfo()
 **********************************************************************************************************************/
/*! \brief       Returns the version information.
 *  \details     FrTrcv_30_Tja1080_GetVersionInfo() returns version information,
 *               vendor ID and AUTOSAR module ID of the component.
 *  \param[out]  versioninfo             Pointer to where to store the version information. Parameter must be valid.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      FRTRCV_30_TJA1080_VERSION_INFO_API
 *  \trace SPEC-22475, SPEC-43644, SPEC-43608, SPEC-43552, SPEC-43538, SPEC-43607, SPEC-22455, SPEC-22481, SPEC-43619
 *  \trace SPEC-22519 not realized to keep complexity low
 *  \trace CREQ-756
 **********************************************************************************************************************/
FUNC(void, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, FRTRCV_30_TJA1080_APPL_DATA) versioninfo);
# endif

/***********************************************************************************************************************
 *  FrTrcv_30_Tja1080_SetTransceiverMode()
 **********************************************************************************************************************/
/*! \brief       Changes the operation mode of the selected transceiver.
 *  \details     If the requested mode is not supported an equivalent mode is selected. If the mode change was not
 *               successful, E_NOT_OK is returned.
 *  \param[in]   FrTrcv_TrcvIdx   The selected FlexRay bus transceiver
 *  \param[in]   FrTrcv_TrcvMode  The Transceiver mode that shall be set
 *  \return      E_NOT_OK - Transceiver state change failed or function has been called with invalid parameters
 *  \return      E_OK - success
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace SPEC-43674, SPEC-43635, SPEC-43513, SPEC-43563, SPEC-43640 Name of call-out is fixed, SPEC-43526
 *  \trace SPEC-43681, SPEC-43562, SPEC-43551, SPEC-43539, SPEC-43572, SPEC-22377, SPEC-22484
 *  \trace SPEC-43710 State transisitions can not fail on DIO transceivers.
 *  \trace SPEC-43630, SPEC-22397, SPEC-43525, SPEC-43664 Disabled branches are not re-enabled by SetTransceiverMode, they are re-enabled by hw
 *  \trace SPEC-43708, SPEC-22499
 *  \trace CREQ-758
 **********************************************************************************************************************/
FUNC(Std_ReturnType, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_SetTransceiverMode(FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_FIRST FrTrcv_TrcvModeType FrTrcv_TrcvMode);

/***********************************************************************************************************************
 *  FrTrcv_30_Tja1080_GetTransceiverMode()
 **********************************************************************************************************************/
/*! \brief       Reads the operation mode of the selected transceiver.
 *  \details     Returns the current transceiver mode on the selected channel.
 *  \param[in]   FrTrcv_TrcvIdx        The selected FlexRay bus transceiver.
 *  \param[out]  FrTrcv_TrcvModePtr    Output parameter reference for current Trcv mode. Pointer must be valid and is not
 *                                     used in an array write access.
 *  \return      E_NOT_OK - function has been called with invalid parameters
 *  \return      E_OK - success
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace SPEC-22382, SPEC-22434, SPEC-43527, SPEC-22487, SPEC-22413, SPEC-43536
 *  \trace CREQ-759
 **********************************************************************************************************************/
FUNC(Std_ReturnType, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_GetTransceiverMode(FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_FIRST P2VAR(FrTrcv_TrcvModeType, AUTOMATIC, FRTRCV_30_TJA1080_APPL_DATA) FrTrcv_TrcvModePtr);

/***********************************************************************************************************************
 *  FrTrcv_30_Tja1080_GetTransceiverWUReason()
 **********************************************************************************************************************/
/*! \brief       Returns the wakeup reason of the selected bus.
 *  \details     Returns the current transceiver wake up reason on the selected channel.
 *  \param[in]   FrTrcv_TrcvIdx          The selected FlexRay bus transceiver.
 *  \param[out]  FrTrcv_TrcvWUReasonPtr  Output parameter reference for wake up reason. Pointer has to be valid.
 *  \return      E_NOT_OK - function has been called with invalid parameters
 *  \return      E_OK - success
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace SPEC-43531, SPEC-43519, SPEC-43537, SPEC-43621, SPEC-22522, SPEC-22415, SPEC-43542
 *  \trace CREQ-761
 **********************************************************************************************************************/
FUNC(Std_ReturnType, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_GetTransceiverWUReason(FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_FIRST P2VAR(FrTrcv_TrcvWUReasonType, AUTOMATIC, FRTRCV_30_TJA1080_APPL_DATA) FrTrcv_TrcvWUReasonPtr); /* PRQA S 0777 */ /* MD_MSR_5.1_777 */

/***********************************************************************************************************************
 *  FrTrcv_30_Tja1080_ClearTransceiverWakeup()
 **********************************************************************************************************************/
/*! \brief       Clears pending wakeup events.
 *  \details     Clears pending wake up events and resets the wake up reason on the selected channel.
 *  \param[in]   FrTrcv_TrcvIdx          The selected FlexRay bus transceiver
 *  \return      E_NOT_OK - function has been called with invalid parameters
 *  \return      E_OK - success
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace SPEC-43614, SPEC-22530, SPEC-43694, SPEC-43696, SPEC-43625, SPEC-43685
 *  \trace CREQ-760, CREQ-761
 **********************************************************************************************************************/
FUNC(Std_ReturnType, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_ClearTransceiverWakeup(FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_ONLY);

/***********************************************************************************************************************
 *  FrTrcv_30_Tja1080_DisableTransceiverBranch()
 **********************************************************************************************************************/
/*! \brief       Disables a specific transceiver branch.
 *  \details     The Tja1080 has no branches therefore this API does not perform any action.
 *  \param[in]   FrTrcv_TrcvIdx          The selected FlexRay bus transceiver
 *  \param[in]   FrTrcv_BranchIdx        The selected FlexRay bus transceiver branch
 *  \return      E_NOT_OK - branch was not disabled
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace SPEC-43671, SPEC-43571, SPEC-43709, SPEC-43576
 *  \trace CREQ-763
 **********************************************************************************************************************/
FUNC(Std_ReturnType, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_DisableTransceiverBranch(FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_FIRST uint8 FrTrcv_BranchIdx);

/***********************************************************************************************************************
 *  FrTrcv_30_Tja1080_EnableTransceiverBranch()
 **********************************************************************************************************************/
/*! \brief       Enables a specific transceiver branch.
 *  \details     The Tja1080 has no branches therefore this API does not perform any action.
 *  \param[in]   FrTrcv_TrcvIdx          The selected FlexRay bus transceiver
 *  \param[in]   FrTrcv_BranchIdx        The selected FlexRay bus transceiver branch
 *  \return      E_OK - success
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace SPEC-43572, SPEC-43535, SPEC-43695, SPEC-43707
 *  \trace CREQ-762
 **********************************************************************************************************************/
FUNC(Std_ReturnType, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_EnableTransceiverBranch(FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_FIRST uint8 FrTrcv_BranchIdx);

/***********************************************************************************************************************
 *  FrTrcv_30_Tja1080_GetTransceiverError()
 **********************************************************************************************************************/
/*! \brief       Returns the error status of a specified branch.
 *  \details     This function returns the latest error reason, detected during FrTrcv_30_Tja1080_CheckWakeupByTransceiver.
 *  \param[in]   FrTrcv_TrcvIdx          The selected FlexRay bus transceiver
 *  \param[in]   FrTrcv_BranchIdx        The selected FlexRay bus transceiver branch
 *  \param[out]  FrTrcv_BusErrorState    The detailed bus error state. Pointer must be valid. See \trace FrTrcv420 in this header file
 *                                       for a detailed description of the individual bits of the result word.
 *  \return      E_NOT_OK - function has been called with invalid parameters
 *  \return      E_OK - success
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace SPEC-43688, SPEC-43533, SPEC-43657, SPEC-43555, SPEC-43618, SPEC-43705, SPEC-43594, SPEC-43582, SPEC-43586
 *  \trace SPEC-43646, SPEC-43661, SPEC-43568
 *  \trace CREQ-755
 **********************************************************************************************************************/
FUNC(Std_ReturnType, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_GetTransceiverError(FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_FIRST uint8 FrTrcv_BranchIdx, P2VAR(uint32, AUTOMATIC, FRTRCV_30_TJA1080_APPL_DATA) FrTrcv_BusErrorStatePtr); /* PRQA S 0777 */ /* MD_MSR_5.1_777 */

/* Single Channel API optimization: \trace DSGN-FrTrcv22793 */
/* PRQA S 3453 9 */ /* MD_MSR_19.7 */
# if ( FRTRCV_30_TJA1080_API_OPTIMIZATION == STD_ON ) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define FrTrcv_30_Tja1080_DisableTransceiverBranch(FrTrcv_TrcvIdx, FrTrcv_BranchIdx)                    FrTrcv_30_Tja1080_DisableTransceiverBranch(FrTrcv_BranchIdx)
#  define FrTrcv_30_Tja1080_EnableTransceiverBranch(FrTrcv_TrcvIdx, FrTrcv_BranchIdx)                     FrTrcv_30_Tja1080_EnableTransceiverBranch(FrTrcv_BranchIdx)
#  define FrTrcv_30_Tja1080_GetTransceiverError(FrTrcv_TrcvIdx, FrTrcv_BranchIdx, FrTrcv_BusErrorState)   FrTrcv_30_Tja1080_GetTransceiverError(FrTrcv_BranchIdx, FrTrcv_BusErrorState)
#  define FrTrcv_30_Tja1080_SetTransceiverMode(TrcvIdx, FrTrcv_TrcvMode)     FrTrcv_30_Tja1080_SetTransceiverMode(FrTrcv_TrcvMode)
#  define FrTrcv_30_Tja1080_GetTransceiverMode(TrcvIdx, FrTrcv_TrcvModePtr)  FrTrcv_30_Tja1080_GetTransceiverMode(FrTrcv_TrcvModePtr)
#  define FrTrcv_30_Tja1080_GetTransceiverWUReason(TrcvIdx, FrTrcv_TrcvWUReasonPtr) FrTrcv_30_Tja1080_GetTransceiverWUReason(FrTrcv_TrcvWUReasonPtr)
#  if !defined ( FRTRCV_30_TJA1080_SOURCE ) /* COV_FRTRCV_30_TJA1080_SOURCE */
#   define FrTrcv_30_Tja1080_ClearTransceiverWakeup(TrcvIdx)                 FrTrcv_30_Tja1080_ClearTransceiverWakeup()
#  endif
# endif /* #if ( FRTRCV_30_TJA1080_API_OPTIMIZATION == STD_ON ) */

# define FRTRCV_30_TJA1080_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */


/*!
 * \exclusivearea FRTRCV_30_TJA1080_EXCLUSIVE_AREA_0
 * Ensures consistency of non-time critical sections. They may be interrupted by application functionality or time critical CAT1 interrupts.
 * \protects DIO access
 * \usedin FrTrcv_30_Tja1080_Phy_SetMode, FrTrcv_30_Tja1080_Phy_GetMode
 * \exclude all functions provided by the FrTrcv
 * \length LONG Call to other BSW module
 * \endexclusivearea
 *
 * \exclusivearea FRTRCV_30_TJA1080_EXCLUSIVE_AREA_1
 * Ensures consistency of time critical sections. They may not be interrupted by anything.
 * \protects DIO access
 * \usedin FrTrcv_30_Tja1080_Phy_ReadStatusWord
 * \exclude all functions provided by the FrTrcv
 * \length LONG Call to other BSW module
 * \endexclusivearea
 */

/***** end of header file ************************************************************************/
#endif
  /* ifndef FRTRCV_30_TJA1080_H */

/**********************************************************************************************************************
 *  END OF FILE: FrTrcv_30_Tja1080.h
 *********************************************************************************************************************/
