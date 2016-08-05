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
/**        \file      Mip_Cfg.h
 *   Generation Time: 2014-10-13 11:05:10
 *           Project: CanLinFrIpMemWd - Version 1.0
 *          Delivery: -
 *      Tool Version: DaVinci Configurator  5.8.12
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Mip
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: 
 *    License Scope : The usage is restricted to -
 *********************************************************************************************************************/

#if !defined (MIP_CFG_H)
#define MIP_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
/* if exist Mip_Types.h use it, otherwise: ComStack_Types.h for Com-related components, otherwise Std_Types.h */
#include "Mip_Types.h"
#include "Dem.h"

/* -----------------------------------------------------------------------------
    &&&~ Version Defines
 ----------------------------------------------------------------------------- */

# define Generator_VERSION 0x0300u
# define Generator_RELEASE_VERSION 0x00u

#define MIP_CFG_MAJOR_VERSION 1
#define MIP_CFG_MINOR_VERSION 1

//#define MIP_DUMMY_STATEMENT(a)  (a)=(a) /* PRQA S 3453 */
//#define MIP_DUMMY_STATEMENT(a)  (void)(a) /* PRQA S 3453 */
#define MIP_DUMMY_STATEMENT(a) /* PRQA S 3453 */

#define MIP_GENTOOL_GENY_MAJOR_VERSION 0x03u
#define MIP_GENTOOL_GENY_MINOR_VERSION 0x02u
#define MIP_GENTOOL_GENY_PATCH_VERSION 0x01u

#define MIP_INSTANCE_ID 0

#define MIP_ENABLE_TIME_MEASUREMENT
#define MIP_CONFIG_VARIANT                  (0x01u)
#define MIP_DEV_ERROR_DETECT                STD_ON
#define MIP_DEV_ERROR_REPORT                STD_ON
#define MIP_PROD_ERROR_DETECT               STD_OFF
#define MIP_CRC_CHECK                       STD_ON
#define MIP_USE_RTE                       STD_OFF
#define MIP_PRECOMPILE_CRC                  (0x64660D91u)
#define MIP_USE_EXTENDED_ASR_VERSION_CHECK
#define MIP_VERSION_INFO_API                STD_ON

#if (MIP_CRC_CHECK == STD_ON)
#define MIP_START_SEC_CONST_32
#include "MemMap.h"
extern CONST(uint32, MIP_CONST) Mip_LinktimeCRC_Linktime;
#define MIP_STOP_SEC_CONST_32
#include "MemMap.h"
#endif
#define MIP_CYCLE_TIME 10


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
extern uint8 Sample[];   /* PRQA S 3684 */
extern uint8 SampleSize;
extern uint8 Sample2[][3]; /* PRQA S 3684 */
extern uint8 SampleSize2;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
extern uint8 Mip_ChannelCount;
extern uint8 Mip_ChannelSpecificRamVariable[]; /* PRQA S 3684 */
extern uint8 Mip_ChannelSpecificRomConstant[]; /* PRQA S 3684 */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*! Example function pointer type definition */
typedef P2FUNC(void, MIP_APPL_CODE, Mip_NotificationType) (void);
/*! Example struct type definition */
typedef struct
{
  uint32 MyStructValue1; /*<! Description of MyStructValue1 */
  uint32 MyStructValue2; /*<! Description of MyStructValue2 */
} Mip_ChannelConfigType;

/*! Example struct type definition */
typedef struct
{
  P2CONST(Mip_ChannelConfigType, AUTOMATIC, MIP_PBCFG) ChannelConfig_t;
  Mip_NotificationType Notification_pt;
  uint8 NrOfChannels;
} Mip_ConfigType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#if (MIP_PROD_ERROR_DETECT == STD_ON)
  #if (MIP_CONFIG_VARIANT==0x01u)
  #else
  extern Dem_EventIdType Mip_DemError_E_DUMMY;
  extern Dem_EventIdType Mip_DemError_E_DUMMY2;
  #endif
#endif


#define MIP_START_SEC_PBCFG
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
extern CONST(Mip_ChannelConfigType, MIP_CONST) Mip_ChannelConfig_Ch0;
extern CONST(Mip_ConfigType, MIP_CONST) Mip_ConfigStruct;
#define MIP_STOP_SEC_PBCFG
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif  /* MIP_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Mip_Cfg.h
 *********************************************************************************************************************/
