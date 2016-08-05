/***********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  Copyright (c) 2007 by Vector Informatik GmbH.                                                  All rights reserved.

                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
         File:  BteCfg.h
      Project:  zBte
       Module:  -
    Generator:  -
  Description:  BTE
***********************************************************************************************************************/

/***********************************************************************************************************************
  AUTHOR IDENTITY
-----------------------------------------------------------------------------------------------------------------------
  Initials     Name                      Company
-----------------------------------------------------------------------------------------------------------------------
  vismas       Markus Schwarz            Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
-----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Change Id     Description
-----------------------------------------------------------------------------------------------------------------------
  1.00.00   2007-12-01  vismas                creation
***********************************************************************************************************************/

#ifndef V_BTECFG_HEADER
#define V_BTECFG_HEADER

/***********************************************************************************************************************
  Includes
***********************************************************************************************************************/
#if defined _TSI
#define BTE_ENABLE_TIME_MEASUREMENT
#define BTE_ENABLE_TESTREPORT
#define BTE_DISABLE_TRACEREPORT
#define BTE_ENABLE_EVENTLIST
#define BTE_ENABLE_EVENTCALLCONTEXTLIST
#define BTE_ENABLE_EVENTTIMINGLIST
#define BTE_ENABLE_CALLCONTEXT
#define BTE_ENABLE_CRITICALSECTION
#define BTE_ENABLE_PANEL

#define VGEN_DISABLE_TSCTEST
#define VGEN_ENABLE_TSCPANEL
#endif

#if defined _TSC
#define BTE_ENABLE_TIME_MEASUREMENT
#define BTE_ENABLE_TESTREPORT
#define BTE_ENABLE_TRACEREPORT
#define BTE_ENABLE_EVENTLIST
#define BTE_ENABLE_EVENTCALLCONTEXTLIST
#define BTE_ENABLE_EVENTTIMINGLIST
#define BTE_ENABLE_CALLCONTEXT
#define BTE_ENABLE_CRITICALSECTION
#define BTE_DISABLE_PANEL

#define USE_EXTERNAL_LOG
#define USE_INTERNAL_LOG
#define USE_PRINTF

#define VGEN_ENABLE_TSCTEST
#define VGEN_DISABLE_TSCPANEL
#endif

#define kBteExclusiveAreaCount      2

#define BTELOG_ENABLE_AUTOSAR_STDTYPES

#endif /* V_BTECFG_HEADER */

/***********************************************************************************************************************
  EOF
***********************************************************************************************************************/
