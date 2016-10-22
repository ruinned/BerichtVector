/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  Copyright (c) 2009 by Vector Informatik GmbH.                                                  All rights reserved.

                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
         File:  TscDet.c
      Project:  TscFrTrcv
       Module:  -
    Generator:  -
  Description:  Component test suite for component CddMirror
**********************************************************************************************************************/

/**********************************************************************************************************************
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
  1.00.00   2009-02-27  vismas                creation
**********************************************************************************************************************/

#define V_TSCDET_SOURCE

/**********************************************************************************************************************
  Includes
**********************************************************************************************************************/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

#include "TscDet.h"
#include "TscAppl.h"
#include "TscTest.h"

#include "BteLog.h"

/**********************************************************************************************************************
  Version check
**********************************************************************************************************************/
#if ( TSCDET_VERSION != 0x0100 )
  #error "Header and Source file are inconsistent (version)!"
#endif
#if ( TSCDET_RELEASE_VERSION != 0x00 )
  #error "Header and Source file are inconsistent (release version)!"
#endif

/**********************************************************************************************************************
  Local data defines
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local macro defines
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local typedefs
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global data definitions (RAM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global data definitions (ROM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local data definitions (RAM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local data definitions (ROM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local function prototypes
**********************************************************************************************************************/
static void TscDet_Event_Log( tBteEvent *pEvent );

/**********************************************************************************************************************
  Global function definition
**********************************************************************************************************************/
/*--- generic control -----------------------------------------------------------------------------------------------*/
/**********************************************************************************************************************
  Name:         TscDet_Init
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void TscDet_Init( void )
{
  /* set initial event mask */
  TscDet_EventMask_DisableAll();
}

/**********************************************************************************************************************
  Name:         TscDet_Cyclic1ms
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void TscDet_Cyclic1ms()
{
}

/**********************************************************************************************************************
  Name:         TscDet_EventMask_EnableAll
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void TscDet_EventMask_EnableAll( void )
{
  BteLog_EventMask_EnableAll( kTscDet_CI );
}

/**********************************************************************************************************************
  Name:         TscDet_EventMask_DisableAll
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void TscDet_EventMask_DisableAll( void )
{
  BteLog_EventMask_DisableAll( kTscDet_CI );
}

/**********************************************************************************************************************
  Name:         TscDet_EventMask_Enable
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void TscDet_EventMask_Enable( uint8 eventId )
{
  BteLog_EventMask_Enable( kTscDet_CI, eventId );
}

/**********************************************************************************************************************
  Name:         TscDet_EventMask_Disable
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void TscDet_EventMask_Disable( uint8 eventId )
{
  BteLog_EventMask_Disable( kTscDet_CI, eventId );
}

/*--- specific control ----------------------------------------------------------------------------------------------*/

/*--- test stimulation ----------------------------------------------------------------------------------------------*/

/*--- stub functions ------------------------------------------------------------------------------------------------*/
/**********************************************************************************************************************
  Name:          Det_ReportError
  Parameter:     See SWS DET
  Return value:  See SWS DET
  Description:   See SWS DET
**********************************************************************************************************************/
void Det_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId)
{
  uint8 Result[32];
  tBteEvent evnt;

  /*--- event handling ---*/
  BteEvent_Init( &evnt );
  evnt.comp = kTscDet_CI;
  evnt.code = kTscDet_Det_ReportError;

  evnt.data1 = (uint8)ModuleId;
  evnt.data2 = (uint8)InstanceId;
  evnt.data3 = (uint8)ApiId;
  evnt.data4 = (uint8)ErrorId;
  evnt.type = kBteEventType_Command;

  TscTest_PrintDetError(ErrorId, Result);
  (void)sprintf( evnt.text_param, "ModuleId:%02X, InstanceId:%02X, ApiId:%02X, ErrorId:%02X (%s)\n", ModuleId, InstanceId, ApiId, ErrorId, Result);
  (void)sprintf( evnt.text_name, "Det_ReportError" );

  BteLog_Event_Log( &evnt );
}

/**********************************************************************************************************************
  Local function definition
**********************************************************************************************************************/

/**********************************************************************************************************************
  Name:          TscDet_Event_Log
  Parameter:     
  Return value:  
  Description:   
**********************************************************************************************************************/
static void TscDet_Event_Log( tBteEvent *pEvent )
{
  BteLog_Event_Log( pEvent );
}

/**********************************************************************************************************************
  EOF
**********************************************************************************************************************/
