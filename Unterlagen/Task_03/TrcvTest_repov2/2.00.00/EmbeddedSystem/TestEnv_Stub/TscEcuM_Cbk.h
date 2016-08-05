

/*
   !! B E T A   V E R S I O N !!

  These programs are fully operative programs. 
  However, they are not thoroughly tested yet (beta-version). 
  With regard to the fact that the programs are a beta-version only, 
  Vector Informatik´s liability shall be expressly excluded in cases of ordinary negligence, 
  to the extent admissible by law or statute.
*/


/**************************************************************************************************
   Project Name: AUTOSAR FR Transceiver Driver
      File Name: FrTrcv.h

    Description: FlexRay tranceiver driver header

  -------------------------------------------------------------------------------------------------
       C O P Y R I G H T
  -------------------------------------------------------------------------------------------------
       Copyright (c) 2007 by Vector Informatik GmbH. All rights reserved.



       This software is copyright protected and proporietary to Vector Informatik GmbH. 
       Vector Informatik GmbH grants to you only those rights as set out in the
       license conditions. All other rights remain with Vector Informatik GmbH.


       Use of this source code is subject to the License Agreement "license.txt"
       distributed with this file. You may not use this source code unless you
       agree to the terms of the License Agreement.

       REMOVAL OF THESE COMMENTS IS A VIOLATION OF THE LICENSE AGREEMENT.

  -------------------------------------------------------------------------------------------------
                A U T H O R   I D E N T I T Y
  -------------------------------------------------------------------------------------------------
   Initials     Name                      Company
   --------     ---------------------     ---------------------------------------------------------
   wnk          Knut Winkelbach           Vector Informatik GmbH
   hr           Andreas Herkommer         Vector Informatik GmbH
   ssr          Sebastian Schmar          Vector Informatik GmbH
  -------------------------------------------------------------------------------------------------
                R E V I S I O N   H I S T O R Y
  -------------------------------------------------------------------------------------------------
   Date         Ver      Author  Description
   ----------   -------  ------  ------------------------------------------------------------------
   2005-05-24   1.00.00  hr      Creation
   2006-05-22   1.02.00  ber     Adaptation to AUTOSAR 2.0
   2006-08-24   2.00.00  hr      Complete rework for Gen2
   2006-12-15   2.01.00  ber     Import wakeup source definition from EcuM.h
   2007-07-26   2.02.00  ssr     Initialize FrTrcv_Status word with zero, 
                                 delete readout of status word within init phase
   2007-08-31   2.03.00  hr      Minor Updates, Memory Mapping
**************************************************************************************************/

#if !defined(__ECUM_CBK_H__)
#define __ECUM_CBK_H__


/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "Std_Types.h"            /* Include standard types */


/******************************************************************************/
/* Version check                                                              */
/******************************************************************************/


/*******************************************************************************
* Prototypes of callback functions
*******************************************************************************/
typedef uint8 EcuM_WakeupSourceType;
//#define ECUM_WKSOURCE_FRTRCV_FR ECUM_WKSOURCE_FR_CHANNEL_0
//#define ECUM_WKSOURCE_FR_CHANNEL_0 ( 1u << 5u )

extern void EcuM_SetWakeupEvent(EcuM_WakeupSourceType events);

extern FUNC(void, ECUM_CODE) EcuM_GeneratorCompatibilityError(uint16 ModuleId, uint8 InstanceId);



#endif /* __ECUM_CBK_H__ */
