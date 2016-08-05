/**************************************************************************************************
   Project Name: FlexRay Stack
      File Name: Det.c

    Description: Development Error Tracer

  -------------------------------------------------------------------------------------------------
       C O P Y R I G H T
  -------------------------------------------------------------------------------------------------
       Copyright (c) 2004 by Vector Informatik GmbH. All rights reserved.



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

  -------------------------------------------------------------------------------------------------
                 R E V I S I O N   H I S T O R Y
  -------------------------------------------------------------------------------------------------
   Date         Ver      Author  Description
   ----------   -------  ------  ------------------------------------------------------------------

**************************************************************************************************/

/**************************************************************************************************
* Include files
**************************************************************************************************/
#include "Dem.h"
#include "TscAppl.h"
#include "TscTest.h"

#include "BteLog.h"


Std_ReturnType Dem_ReportErrorStatus( Dem_EventIdType EventId, uint8  EventStatus )
{
  uint8 Result[32];
  tBteEvent evnt;

  /*--- event handling ---*/
  BteEvent_Init( &evnt );
  evnt.comp = kTscDem_CI;
  evnt.code = kTscDet_Dem_ReportError;

  evnt.data1 = (uint8)EventId;
  evnt.data2 = (uint8)EventStatus;
  evnt.type = kBteEventType_Command;

  TscTest_PrintDetError(EventId, Result);
  (void)sprintf( evnt.text_param, "EventId:%02X, EventStatus:%02X (%s)\n", EventId, EventStatus, Result);
  (void)sprintf( evnt.text_name, "Dem_ReportErrorStatus" );

  BteLog_Event_Log( &evnt );
  return(E_OK);
}


/*---- End of File ---------------------------------------------------------*/
