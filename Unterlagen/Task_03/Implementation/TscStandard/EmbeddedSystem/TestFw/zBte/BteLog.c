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
         File:  BteLog.c
      Project:  Bte
       Module:  -
    Generator:  -
  Description:  BTE
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
  1.00.00   2007-12-01  vismas                creation
  1.01.00   2009-11-11  vismas                minor fixes
                                              seperated handling of eventlist and event log
                                              extended API for logging
**********************************************************************************************************************/

#define V_BTELOG_SOURCE

/**********************************************************************************************************************
  Includes
**********************************************************************************************************************/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h> 

#include "BteLog.h"
#if defined ( VGEN_ENABLE_TSCPANEL )
#include "os.h"
#endif

#include "BteReport.h"
#include "BteTestHandler.h"

/**********************************************************************************************************************
  Version check
**********************************************************************************************************************/
#if ( BTELOG_VERSION != 0x0101 )
  #error "Header and Source file are inconsistent (version)!"
#endif
#if ( BTELOG_RELEASE_VERSION != 0x00 )
  #error "Header and Source file are inconsistent (release version)!"
#endif

/**********************************************************************************************************************
  Local configuration
**********************************************************************************************************************/
#if defined ( kBteNumberOfStubs )
#else
  #define kBteNumberOfStubs                     12
#endif

/**********************************************************************************************************************
  Local data defines
**********************************************************************************************************************/
#define kBteEventMask_EnableAll                 0xf0
#define kBteEventMask_DisableAll                0xf1
#define kBteEventMask_Enable                    0xf2
#define kBteEventMask_Disable                   0xf3


/**********************************************************************************************************************
  Local macro defines
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local typedefs
**********************************************************************************************************************/
typedef struct stBteLog {
  vuint8 eventListMask[256/8];
  vuint8 eventLogMask[256/8];
  vuint8 stubName[50];
} tBteLog;

/**********************************************************************************************************************
  Global data definitions (RAM)
**********************************************************************************************************************/
#if defined ( BTELOG_ENABLE_AUTOSAR_STDTYPES )
vuint8 bteLog_StdReturnType2String_string[20];
#endif

/**********************************************************************************************************************
  Global data definitions (ROM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local data definitions (RAM)
**********************************************************************************************************************/
static tBteLog bteStub[kBteNumberOfStubs];

/**********************************************************************************************************************
  Local data definitions (ROM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local function prototypes
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global function definitions
**********************************************************************************************************************/
/**********************************************************************************************************************
  Name:         BteLog_Init
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteLog_Init( void )
{
  vuint8 stubId;
  for( stubId=0; stubId<kBteNumberOfStubs; stubId++ )
  {
    BteLog_EventMask_DisableAll( stubId );
    BteLog_SetStubName( stubId, "undefined" );
  }
}

/**********************************************************************************************************************
  Name:         BteLog_SetStubName
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteLog_SetStubName( vuint8 stubId, vuint8 *name )
{
  (void)sprintf(bteStub[stubId].stubName, "%s", name);
}

/**********************************************************************************************************************
  Name:         BteLog_GetStubName
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
vuint8 *BteLog_GetStubName( vuint8 stubId )
{
  return bteStub[stubId].stubName;
}


/**********************************************************************************************************************
  Name:         BteLog_EventMask_EnableAll
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteLog_EventMask_EnableAll( vuint8 stubId )
{
  BteLog_EventListMask_EnableAll(stubId);
  BteLog_EventLogMask_EnableAll(stubId);
}

/**********************************************************************************************************************
  Name:         BteLog_EventMask_DisableAll
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteLog_EventMask_DisableAll( vuint8 stubId )
{
  BteLog_EventListMask_DisableAll(stubId);
  BteLog_EventLogMask_DisableAll(stubId);
}

/**********************************************************************************************************************
  Name:         BteLog_EventMask_Enable
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteLog_EventMask_Enable( vuint8 stubId, vuint8 eventId )
{
  BteLog_EventListMask_Enable(stubId,eventId);
  BteLog_EventLogMask_Enable(stubId,eventId);
}

/**********************************************************************************************************************
  Name:         BteLog_EventMask_Disable
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteLog_EventMask_Disable( vuint8 stubId, vuint8 eventId )
{
  BteLog_EventListMask_Disable(stubId,eventId);
  BteLog_EventLogMask_Disable(stubId,eventId);
}




/**********************************************************************************************************************
  Name:         BteLog_EventListMask_EnableAll
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteLog_EventListMask_EnableAll( vuint8 stubId )
{
  vuint8 index;
  tBteEvent evnt;

  if( stubId < kBteNumberOfStubs )
  {
    for( index=0; index<(256/8); index++ )
    {
      bteStub[stubId].eventListMask[index]=0xFF;
    }
    BteLog_Event_Init( &evnt );
    evnt.code = kBteEventMask_EnableAll;
    (void)sprintf( evnt.text_name, "BteEventMask_EnableAll" );
    (void)sprintf( evnt.text_param, "(stubId=%d)", stubId );
    /* BteLog_Event_Log( &evnt ); */
  }
  else
  {
    BteError("BteLog: StubId exceeds defined limit");
  }

}

/**********************************************************************************************************************
  Name:         BteLog_EventListMask_DisableAll
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteLog_EventListMask_DisableAll( vuint8 stubId )
{
  vuint8 index;
  tBteEvent evnt;

  if( stubId < kBteNumberOfStubs )
  {
    for( index=0; index<(256/8); index++ )
    {
      bteStub[stubId].eventListMask[index]=0x00;
    }

    BteLog_Event_Init( &evnt );
    evnt.code = kBteEventMask_DisableAll;
    (void)sprintf( evnt.text_name, "BteEventMask_DisableAll" );
    (void)sprintf( evnt.text_param, "(stubId=%d)", stubId );
    /* BteLog_Event_Log( &evnt ); */
  }
  else
  {
    BteError("BteLog: StubId exceeds defined limit,");
  }
}

/**********************************************************************************************************************
  Name:         BteLog_EventListMask_Enable
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteLog_EventListMask_Enable( vuint8 stubId, vuint8 eventId )
{
  tBteEvent evnt;

  if( stubId < kBteNumberOfStubs )
  {
    bteStub[stubId].eventListMask[eventId/8] |= 1<<(eventId & 0x07);

    BteLog_Event_Init( &evnt );
    evnt.code = kBteEventMask_Enable;
    evnt.data1 = eventId;
    (void)sprintf( evnt.text_name, "BteEventMask_Enable" );
    (void)sprintf( evnt.text_param, "(stubId=%d, eventId=0x%x)", stubId, eventId );
    /* BteLog_Event_Log( &evnt ); */
  }
  else
  {
    BteError("BteLog: StubId exceeds defined limit,");
  }
}

/**********************************************************************************************************************
  Name:         BteLog_EventListMask_Disable
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteLog_EventListMask_Disable( vuint8 stubId, vuint8 eventId )
{
  tBteEvent evnt;

  if( stubId < kBteNumberOfStubs )
  {
    bteStub[stubId].eventListMask[eventId/8] &= (vuint8)(~(vuint8)(1u<<(eventId & 0x07u)));

    BteLog_Event_Init( &evnt );
    evnt.code = kBteEventMask_Disable;
    evnt.data1 = eventId;
    (void)sprintf( evnt.text_name, "BteEventMask_Disable" );
    (void)sprintf( evnt.text_param, "(stubId=%d, eventId=0x%x)", stubId, eventId );
    /* BteLog_Event_Log( &evnt ); */
  }
  else
  {
    BteError("BteLog: StubId exceeds defined limit,");
  }
}

/**********************************************************************************************************************
  Name:         BteLog_EventListMask_Check
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
vuint8 BteLog_EventListMask_Check( vuint8 stubId, vuint8 eventId )
{
  vuint8 rval;

  if( (bteStub[stubId].eventListMask[eventId/8] & (vuint8)(1<<((vuint8)(eventId & 0x07)))) != 0 )
  {
    rval = 1;
  }
  else
  {
    rval = 0;
  }
  return( rval );
}


/**********************************************************************************************************************
  Name:         BteLog_EventLogMask_EnableAll
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteLog_EventLogMask_EnableAll( vuint8 stubId )
{
  vuint8 index;
  tBteEvent evnt;

  if( stubId < kBteNumberOfStubs )
  {
    for( index=0; index<(256/8); index++ )
    {
      bteStub[stubId].eventLogMask[index]=0xFF;
    }
    BteLog_Event_Init( &evnt );
    evnt.code = kBteEventMask_EnableAll;
    (void)sprintf( evnt.text_name, "BteEventMask_EnableAll" );
    (void)sprintf( evnt.text_param, "(stubId=%d)", stubId );
    /* BteLog_Event_Log( &evnt ); */
  }
  else
  {
    BteError("BteLog: StubId exceeds defined limit");
  }

}

/**********************************************************************************************************************
  Name:         BteLog_EventLogMask_DisableAll
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteLog_EventLogMask_DisableAll( vuint8 stubId )
{
  vuint8 index;
  tBteEvent evnt;

  if( stubId < kBteNumberOfStubs )
  {
    for( index=0; index<(256/8); index++ )
    {
      bteStub[stubId].eventLogMask[index]=0x00;
    }

    BteLog_Event_Init( &evnt );
    evnt.code = kBteEventMask_DisableAll;
    (void)sprintf( evnt.text_name, "BteEventMask_DisableAll" );
    (void)sprintf( evnt.text_param, "(stubId=%d)", stubId );
    /* BteLog_Event_Log( &evnt ); */
  }
  else
  {
    BteError("BteLog: StubId exceeds defined limit,");
  }
}

/**********************************************************************************************************************
  Name:         BteLog_EventLogMask_Enable
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteLog_EventLogMask_Enable( vuint8 stubId, vuint8 eventId )
{
  tBteEvent evnt;

  if( stubId < kBteNumberOfStubs )
  {
    bteStub[stubId].eventLogMask[eventId/8] |= 1<<(eventId & 0x07);

    BteLog_Event_Init( &evnt );
    evnt.code = kBteEventMask_Enable;
    evnt.data1 = eventId;
    (void)sprintf( evnt.text_name, "BteEventMask_Enable" );
    (void)sprintf( evnt.text_param, "(stubId=%d, eventId=0x%x)", stubId, eventId );
    /* BteLog_Event_Log( &evnt ); */
  }
  else
  {
    BteError("BteLog: StubId exceeds defined limit,");
  }
}

/**********************************************************************************************************************
  Name:         BteLog_EventLogMask_Disable
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteLog_EventLogMask_Disable( vuint8 stubId, vuint8 eventId )
{
  tBteEvent evnt;

  if( stubId < kBteNumberOfStubs )
  {
    bteStub[stubId].eventLogMask[eventId/8] &= (vuint8)(~(vuint8)(1u<<(eventId & 0x07u)));

    BteLog_Event_Init( &evnt );
    evnt.code = kBteEventMask_Disable;
    evnt.data1 = eventId;
    (void)sprintf( evnt.text_name, "BteEventMask_Disable" );
    (void)sprintf( evnt.text_param, "(stubId=%d, eventId=0x%x)", stubId, eventId );
    /* BteLog_Event_Log( &evnt ); */
  }
  else
  {
    BteError("BteLog: StubId exceeds defined limit,");
  }
}

/**********************************************************************************************************************
  Name:         BteLog_EventLogMask_Check
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
vuint8 BteLog_EventLogMask_Check( vuint8 stubId, vuint8 eventId )
{
  vuint8 rval;

  if( (bteStub[stubId].eventLogMask[eventId/8] & (vuint8)(1<<((vuint8)(eventId & 0x07)))) != 0 )
  {
    rval = 1;
  }
  else
  {
    rval = 0;
  }
  return( rval );
}

/**********************************************************************************************************************
  Name:         BteLog_Event_Log
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteLog_Event_Init( tBteEvent *pEvent )
{
  BteEvent_Init(pEvent);
  pEvent->time = BteTestCase_GetTime();
}

/**********************************************************************************************************************
  Name:         BteLog_Event_Log
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteLog_Event_Log( tBteEvent *pEvent )
{
  pEvent->time = BteTestCase_GetTime();

  if( BteEventFilter_Apply(pEvent) != 0 )
  {
    ApplBteLog_Trigger();
#if defined ( BTETLOG_ENABLE_TRIGGERCALLBACK )
    ApplBteLog_TriggerOccurred();
#endif
  }

  if( (pEvent->type == kBteEventType_Command) || 
       ((BteLog_EventLogMask_Check(pEvent->comp, pEvent->code))!= 0) )
  {
    vuint8 tempText[150];

    sprintf( tempText, "%s %s", pEvent->text_name, pEvent->text_param );
    if( pEvent->type == kBteEventType_Command )
    {
      BteReport_WriteElement( "cmd", pEvent->time, tempText );
    }
    else if ( pEvent->type == kBteEventType_Error )
    {
      BteReport_WriteElement( "fail", pEvent->time, tempText );
    }
    else
    {
      BteReport_WriteElement( "", pEvent->time, tempText );
    }

    BteTraceReport_WriteElement( pEvent );

#if defined ( VGEN_ENABLE_TSCPANEL )
    (void)sprintf( tempText, "%7d %s%s", pEvent->time, pEvent->text_name, pEvent->text_param );
    CANoeAPI_WriteString( tempText );
#endif
  }

  #if defined ( BTE_ENABLE_EVENTLIST )
  if( (BteLog_EventListMask_Check(pEvent->comp, pEvent->code))!= 0 )
  {
    BteEventList_Add( pEvent );
  }
  #endif


  #if defined ( BTE_ENABLE_EVENTCALLCONTEXTLIST )
  if( pEvent->type != kBteEventType_Internal )
  {
    BteEventCallContextList_Add( pEvent );
  }
  #endif
}

/**********************************************************************************************************************
  Name:         BteLog_TimerStart
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteLog_TimerStart( tBteEvent *pEvent )
{
  pEvent = pEvent;
  BteTimer_Start();
}

/**********************************************************************************************************************
  Name:         BteLog_TimerStop
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteLog_TimerStop( tBteEvent *pEvent )
{
  vuint32 timediff;

  timediff = BteTimer_Stop();
  BteEventTimingList_Add( pEvent, timediff );
}

/**********************************************************************************************************************
  Name:         BteLog_Debug
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteLog_Debug(vuint8 *text)
{
  #if defined ( VGEN_ENABLE_TSCPANEL )
  vuint8 tempText[120];
  #endif

  BteReport_WriteInfo(text);

  #if defined ( VGEN_ENABLE_TSCPANEL )
  (void)sprintf( tempText, "%7d %s", BteTestCase_GetTime(), text );
  CANoeAPI_WriteString( tempText );
  #endif
}

/**********************************************************************************************************************
  Name:         BteLog_WriteConfig
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteLog_WriteConfigText( vuint8 *attrName, vuint8* attrValue )
{
  vuint8 text[150];

  (void)sprintf(text,"<configAttr name=\"%s\" value=\"%s\"></configAttr>", attrName, attrValue);
  BteReport_Write(text);
}

/**********************************************************************************************************************
  Name:         BteLog_WriteConfigValue
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteLog_WriteConfigValue( vuint8 *attrName, vuint32 attrValue )
{
  vuint8 text[150];

  (void)sprintf(text,"<configAttr name=\"%s\" value=\"%d\"></configAttr>", attrName, attrValue);
  BteReport_Write(text);
}

/**********************************************************************************************************************
  Name:         BteLog_WriteConfigAsrSwitch
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteLog_WriteConfigAsrSwitch( vuint8 *attrName, vuint32 attrValue )
{
  vuint8 text[150];

  if( attrValue==kBte_STD_ON )
  {
    (void)sprintf(text,"<configAttr name=\"%s\" value=\"STD_ON\"></configAttr>", attrName);
  }
  else
  {
    if( attrValue==kBte_STD_OFF )
    {
      (void)sprintf(text,"<configAttr name=\"%s\" value=\"STD_OFF\"></configAttr>", attrName);
    }
    else
    {
      (void)sprintf(text,"<configAttr name=\"%s\" value=\"unknown\"></configAttr>", attrName);
    }
  }
  BteReport_Write(text);
}

#if defined ( BTELOG_ENABLE_AUTOSAR_STDTYPES )
/**********************************************************************************************************************
  Name:         BteLog_StdReturnType2String
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
vuint8* BteLog_StdReturnType2String(Std_ReturnType rval)
{
  if( rval==E_OK )
  {
    (void)sprintf(bteLog_StdReturnType2String_string,"E_OK");
  }
  else if( rval==E_NOT_OK )
  {
    (void)sprintf(bteLog_StdReturnType2String_string,"E_NOT_OK");
  }
  else
  {
    (void)sprintf(bteLog_StdReturnType2String_string,"unknown");
  }
  return bteLog_StdReturnType2String_string;
}
#endif

/**********************************************************************************************************************
  Local function definitions
**********************************************************************************************************************/

/**********************************************************************************************************************
  EOF
**********************************************************************************************************************/
