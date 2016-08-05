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
/**        \file      Mip_Lcfg.c
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

#define MIP_LCFG_SOURCE

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Mip.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#if (MIP_GENTOOL_GENY_MAJOR_VERSION != 0x03u)
#error "Issm_Lcfg.c : Incompatible SYSSERVICE_ISSM_VOLVO_AB_GENTOOL_GENY_MAJOR_VERSION in generated File!"
#endif

#if (MIP_GENTOOL_GENY_MINOR_VERSION != 0x02u)
#error "Issm_Lcfg.c : Incompatible SYSSERVICE_ISSM_VOLVO_AB_GENTOOL_GENY_MINOR_VERSION in generated File!"
#endif

#if (MIP_GENTOOL_GENY_PATCH_VERSION != 0x01u)
#error "Issm_Lcfg.c : Incompatible SYSSERVICE_ISSM_VOLVO_AB_GENTOOL_GENY_PATCH_VERSION in generated File!"
#endif





























/* -----------------------------------------------------------------------------
    &&&~ 
 ----------------------------------------------------------------------------- */

#if (MIP_CRC_CHECK == STD_ON)
#define MIP_START_SEC_CONST_32
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

CONST(uint32, MIP_CONST) Mip_LinktimeCRC_Linktime = (uint32) 0x19D9B4B4u;
#define MIP_STOP_SEC_CONST_32
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#endif
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
uint8 Sample[] = {
 0,1,2,3,4
};
uint8 Sample2[2][3] = {
  {1,2,3},
  {1,2,3}
};

uint8 SampleSize = 5;
uint8 SampleSize2 = 3;

uint8 Mip_ChannelCount = 2;

uint8 Mip_ChannelSpecificRamVariable[2];
uint8 Mip_ChannelSpecificRomConstant[2] = {1,2};

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#if (MIP_PROD_ERROR_DETECT == STD_ON)
  #if (MIP_CONFIG_VARIANT==0x01u)
  #else
  //only for LT/PB
  Dem_EventIdType Mip_DemError_E_DUMMY = MIP_E_DUMMY;
  Dem_EventIdType Mip_DemError_E_DUMMY2 = MIP_E_DUMMY2;
  #endif
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  END OF FILE: Mip_Lcfg.c
 *********************************************************************************************************************/
