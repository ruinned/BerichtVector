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
/*  \file  FrTrcv_30_Tja1080_Cbk.h
 *  \brief  MICROSAR FR Transceiver Driver
 *
 *  \details  FlexRay transceiver driver cbk header file
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
#if !defined (FRTRCV_30_TJA1080_CBK_H) /* COV_FRTRCV_30_TJA1080_MSR_HEADERGUARD */
# define FRTRCV_30_TJA1080_CBK_H

#include "FrTrcv_30_Tja1080_Cfg.h"

# define FRTRCV_30_TJA1080_CBK_MAJOR_VERSION  0x04
# define FRTRCV_30_TJA1080_CBK_MINOR_VERSION  0x00
# define FRTRCV_30_TJA1080_CBK_PATCH_VERSION  0x00

# define FRTRCV_30_TJA1080_START_SEC_CODE
# include "MemMap.h"

/* wakeup notification */
/***********************************************************************************************************************
 *  FrTrcv_30_Tja1080_CheckWakeupByTransceiver()
 **********************************************************************************************************************/
/*! \brief       This function is triggered by interrupts or used for polling.
 *  \details     This function is called by the application to check for wake up and error events.
 *  \param[in]   FrTrcv_TrcvIdx          The selected FlexRay bus transceiver
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace SPEC-43505, SPEC-43601, SPEC-43529, SPEC-43603, SPEC-43590, SPEC-43645, SPEC-22374, SPEC-43691
 *  \trace SPEC-43569, SPEC-43647 no notification to DET due to ICU initialization issue ESCAN00060091
 *  \trace SPEC-22425 Is also used for Diagnosis of bus errors and therefore always present, SPEC-43530, SPEC-43605
 *  \trace SPEC-43610 The function is not reentrant.
 *  \trace CREQ-757
 **********************************************************************************************************************/
FUNC(void, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_CheckWakeupByTransceiver(FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_ONLY);

/***********************************************************************************************************************
 *  Appl_FrTrcv_30_Tja1080_Wait()
 **********************************************************************************************************************/
/*! \brief       Is called to delay a specified time
 *  \details     The transceiver requires a certain timing during access. This timing is provided by this call-back
 *               which must delay a certain amount of time
 *  \param[in]   TimerIndex          The selected delay time
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 **********************************************************************************************************************/
FUNC(void, FRTRCV_30_TJA1080_CODE) Appl_FrTrcv_30_Tja1080_Wait(uint8 TimerIndex);

# if ( FRTRCV_30_TJA1080_PROD_ERROR_DETECT == STD_ON ) && ( FRTRCV_30_TJA1080_TRCV_DEM_CALLBACK == STD_ON )
/* PRQA S 0777 3 */ /* MD_MSR_5.1_777 */
/***********************************************************************************************************************
 *  Appl_FrTrcv_30_Tja1080_ReportErrorStatusFailed()
 **********************************************************************************************************************/
/*! \brief       This call-out is called to report an error condition.
 *  \details     This call-out is called if there was an error during transceiver access.
 *  \param[in]   eventId          The error Id of the notified error as defined in the DEM.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      FRTRCV_30_TJA1080_TRCV_DEM_CALLBACK, FRTRCV_30_TJA1080_PROD_ERROR_DETECT
 *  \trace DSGN-FrTrcv22768
 **********************************************************************************************************************/
FUNC(void, FRTRCV_30_TJA1080_CODE) Appl_FrTrcv_30_Tja1080_ReportErrorStatusFailed(Dem_EventIdType eventId); /* PRQA S 0777 */ /* MD_MSR_5.1_777 */
/***********************************************************************************************************************
 *  Appl_FrTrcv_30_Tja1080_ReportErrorStatusPreFailed()
 **********************************************************************************************************************/
/*! \brief       This call-out is called to report an error condition.
 *  \details     This call-out is called if there was an error detected by the transceiver like low voltage or clamp error.
 *  \param[in]   eventId          The error Id of the notified error as defined in the DEM.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      FRTRCV_30_TJA1080_TRCV_DEM_CALLBACK, FRTRCV_30_TJA1080_PROD_ERROR_DETECT
 *  \trace DSGN-FrTrcv22768
 **********************************************************************************************************************/
FUNC(void, FRTRCV_30_TJA1080_CODE) Appl_FrTrcv_30_Tja1080_ReportErrorStatusPreFailed(Dem_EventIdType eventId); /* PRQA S 0777 */ /* MD_MSR_5.1_777 */
/***********************************************************************************************************************
 *  Appl_FrTrcv_30_Tja1080_ReportErrorStatusPrePassed()
 **********************************************************************************************************************/
/*! \brief       This call-out is called to report if an error healed.
 *  \details     This call-out is called if there was no error detected by the transceiver.
 *  \param[in]   eventId          The healing Id as defined in the DEM.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      FRTRCV_30_TJA1080_TRCV_DEM_CALLBACK, FRTRCV_30_TJA1080_PROD_ERROR_DETECT
 *  \trace DSGN-FrTrcv22768
 **********************************************************************************************************************/
FUNC(void, FRTRCV_30_TJA1080_CODE) Appl_FrTrcv_30_Tja1080_ReportErrorStatusPrePassed(Dem_EventIdType eventId); /* PRQA S 0777 */ /* MD_MSR_5.1_777 */
# endif

# define FRTRCV_30_TJA1080_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */

/* PRQA S 3453 2 */ /*  MD_MSR_19.7 */
# if ( FRTRCV_30_TJA1080_API_OPTIMIZATION == STD_ON )
#  if !defined ( FRTRCV_30_TJA1080_SOURCE ) /* COV_FRTRCV_30_TJA1080_SOURCE */
#   define FrTrcv_30_Tja1080_CheckWakeupByTransceiver(TrcvIdx) FrTrcv_30_Tja1080_CheckWakeupByTransceiver() /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif
# endif /* #if ( FRTRCV_30_TJA1080_API_OPTIMIZATION == STD_ON ) */

#endif
  /* FRTRCV_30_TJA1080_CBK_H */

/**********************************************************************************************************************
 *  END OF FILE: FrTrcv_30_Tja1080_Cbk.h
 *********************************************************************************************************************/
