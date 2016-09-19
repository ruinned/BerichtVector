/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: FrTrcv
 *           Program: 
 *          Customer: N/A
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: 
 *    License Scope : The usage is restricted to CBD0000000_D16
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: FrTrcv_30_Tja1080_Cfg.c
 *   Generation Time: 2016-03-07 16:12:20
 *           Project: CanCanFr - Version 1.0
 *          Delivery: CBD0000000_D16
 *      Tool Version: DaVinci Configurator  5.11.16 SP1
 *
 *
 *********************************************************************************************************************/


#include "FrTrcv_30_Tja1080.h"

#define FRTRCV_30_TJA1080_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

CONST(uint8, FRTRCV_30_TJA1080_CONST) FrTrcv_30_Tja1080_MaxNumOfBtrBusses = FRTRCV_30_TJA1080_MAX_NUM_OF_BTR_BUSSES;
/* -----------------------------------------------------------------------------
    &&&~ Data definition
 ----------------------------------------------------------------------------- */

/* Transceiver initial state and capabilities */
CONST(FrTrcv_30_Tja1080_GenConfigType, FRTRCV_30_TJA1080_CONST) FrTrcv_30_Tja1080_Config[FRTRCV_30_TJA1080_MAX_NUM_OF_BTR_BUSSES] = 
{
  {
    FRTRCV_TRCVMODE_STANDBY /*  FrTrcv_InitState  */ , 
    0x00000080UL /*  FrTrcv_WakeupSourceRef  */ , 
    FRTRCV_WAKEUP_POLLING /*  FrTrcv_WakeupByNodeUsedPolling  */ , 
    0x01U /*  FrTrcv_WakeupByBusUsed  */ 
  }, 
  {
    FRTRCV_TRCVMODE_NORMAL /*  FrTrcv_InitState  */ , 
    0x00000080UL /*  FrTrcv_WakeupSourceRef  */ , 
    FRTRCV_WAKEUP_POLLING /*  FrTrcv_WakeupByNodeUsedPolling  */ , 
    0x01U /*  FrTrcv_WakeupByBusUsed  */ 
  }
};

#if FRTRCV_30_TJA1080_PROD_ERROR_DETECT == STD_ON
CONST(Dem_EventIdType, FRTRCV_30_TJA1080_CONST) FrTrcv_30_Tja1080_DEM_E_NoControl = 0; /* PRQA S 3408 */ /* MD_FRTRCV_3408 */

CONST(Dem_EventIdType, FRTRCV_30_TJA1080_CONST) FrTrcv_30_Tja1080_DEM_E_BusError_Channel[FRTRCV_30_TJA1080_MAX_NUM_OF_BTR_BUSSES] = /* PRQA S 3408 */ /* MD_FRTRCV_3408 */
{
  DemConf_DemEventParameter_DEM_EVENT_E_FR_ERRN_TRCV_0, 
  DemConf_DemEventParameter_DEM_EVENT_E_FR_ERRN_TRCV_1
};
#endif

#define FRTRCV_30_TJA1080_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* END of Checksum exclude for
  - DrvTrans_Tja1080FrAsrPreCompileCRC */
    
