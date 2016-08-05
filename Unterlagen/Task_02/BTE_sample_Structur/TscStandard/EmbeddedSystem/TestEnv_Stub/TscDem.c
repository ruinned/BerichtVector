/***********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2015 by Vector Informatik GmbH.                                               All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 * --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 * ------------------------------------------------------------------------------------------------------------------*/
/**     \file  TscDem.c
 *     \brief  TscStub source file for Dem
 *   \details  
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 **********************************************************************************************************************/

#define MIP_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include <stdio.h>
#include "TscDem.h"
#include "BteLog.h"

/***********************************************************************************************************************
 *  VERSION CHECK
 **********************************************************************************************************************/
#if ( (TSCDEM_MAJOR_VERSION != 1) || \
      (TSCDEM_MINOR_VERSION != 0) || \
      (TSCDEM_RELEASE_VERSION != 0))
#error "Header and Source file are inconsistent (version)!"
#endif


/***********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/
/*--- stub function control data ------------------------------------------------------------------------------------*/


/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
static void TscDem_Event_Init( tBteEvent *pEvent );
//static void TscDem_Event_Log( tBteEvent *pEvent, const char* text_name, const char* text_param );
static void TscDem_Event_Log( tBteEvent *pEvent);

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/
/***********************************************************************************************************************
  Name:        TscDem_Event_Init
  Description: 
***********************************************************************************************************************/
static void TscDem_Event_Init( tBteEvent *pEvent)
{
  BteEvent_Init( pEvent );
  pEvent->comp = kTscDem_CI;
}
/***********************************************************************************************************************
  Name:        TscDem_Event_Log
  Description: 
***********************************************************************************************************************/
//static void TscDem_Event_Log( tBteEvent *pEvent, const char* text_name, const char* text_param)
//{
//  if (pEvent->type == kBteEventType_Command || pEvent->type == kBteEventType_Command)
//  {
//    pEvent->caller = kTscDem_CI;
//  }
//  else if (pEvent->type == kBteEventType_Default)
//  {
//    pEvent->callee = kTscDem_CI;
//  }
//  BteLog_Event_Log( pEvent );
//  //BteLog_Event_Log( pEvent, text_name, text_param);
//}
static void TscDem_Event_Log( tBteEvent *pEvent)
{
  if (pEvent->type == kBteEventType_Command || pEvent->type == kBteEventType_Command)
  {
    pEvent->caller = kTscDem_CI;
  }
  else if (pEvent->type == kBteEventType_Default)
  {
    pEvent->callee = kTscDem_CI;
  }
  BteLog_Event_Log( pEvent );
}

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
/*--- standard BTE function definition ------------------------------------------------------------------------------*/
/***********************************************************************************************************************
  Name:        TscDem_Init
  Description: 
***********************************************************************************************************************/
void TscDem_Init( void)
{
//#if defined (USE_EXTERNAL_LOG)
  BteLog_SetStubName(kTscDem_CI,"Dem");
//#endif
  TscDem_EventMask_EnableAll();

  /*--- init stub function control data ---*/

}
/***********************************************************************************************************************
  Name:        TscDem_Cyclic1ms
  Description: 
***********************************************************************************************************************/
void TscDem_Cyclic1ms( void)
{
}

#define DEM_CODE
/*--- wrapper function definition -----------------------------------------------------------------------------------*/

typedef uint8 Dem_EventIdType;
typedef uint8 Dem_EventStatusType;

/*--- stub function definition --------------------------------------------------------------------------------------*/
/***********************************************************************************************************************
 *  Dem_ReportErrorStatus
 **********************************************************************************************************************/
FUNC(void, DEM_CODE) Dem_ReportErrorStatus( Dem_EventIdType EventId, Dem_EventStatusType EventStatus )
{
  tBteEvent evnt;

  /*--- event logging ---*/
  TscDem_Event_Init( &evnt );
  evnt.code = kTscDem_Dem_ReportErrorStatus;
  evnt.data1 = (uint32)EventId;
  evnt.data2 = (uint32)EventStatus;
  evnt.numParam = 2;
  (void)sprintf( evnt.text_name, "Dem_ReportErrorStatus" );
  (void)sprintf( evnt.text_param, "(EventId=%d, EventStatus=%d)", EventId, EventStatus);
  //TscDem_Event_Log( &evnt , "Dem_ReportErrorStatus" , "(EventId=%d, EventStatus=%d)" );

  /*--- test handling ---*/
  /* N/A */
}


/*--- stub function control definition ------------------------------------------------------------------------------*/

/*--- stub assert event function definition -------------------------------------------------------------------------*/


/***********************************************************************************************************************
 *  END OF FILE
 **********************************************************************************************************************/

