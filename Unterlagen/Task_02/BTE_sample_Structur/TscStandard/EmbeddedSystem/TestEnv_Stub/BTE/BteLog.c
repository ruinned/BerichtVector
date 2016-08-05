/***********************************************************************************************************************
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
1.01.00   2009-11-11  vismas                minor fixes
seperated handling of eventlist and event log
extended API for logging
***********************************************************************************************************************/

#define V_BTELOG_SOURCE

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h> 

#include "BteLog.h"
#if defined ( VGEN_ENABLE_TSCPANEL )
#include "os.h"
#endif

#include "BteReport.h"
#include "BteTestHandler.h"

/***********************************************************************************************************************
Version check
***********************************************************************************************************************/
#if ( BTELOG_VERSION != 0x0101 )
#error "Header and Source file are inconsistent (version)!"
#endif
#if ( BTELOG_RELEASE_VERSION != 0x00 )
#error "Header and Source file are inconsistent (release version)!"
#endif

/***********************************************************************************************************************
Local configuration
***********************************************************************************************************************/
#if defined ( kBteNumberOfStubs )
#else
#define kBteNumberOfStubs                     12
#endif

/***********************************************************************************************************************
Local data defines
***********************************************************************************************************************/
#define kBteEventMask_EnableAll                 0xf0
#define kBteEventMask_DisableAll                0xf1
#define kBteEventMask_Enable                    0xf2
#define kBteEventMask_Disable                   0xf3


/***********************************************************************************************************************
Local macro defines
***********************************************************************************************************************/

/***********************************************************************************************************************
Local typedefs
***********************************************************************************************************************/

typedef struct stBteLog {
  uint8 eventListMask[256/8];
  uint8 eventLogMask[256/8];
#if defined (USE_EXTERNAL_LOG)
  uint8 stubName[50];
#endif
} tBteLog;

/***********************************************************************************************************************
Global data definitions (RAM)
***********************************************************************************************************************/
#if defined ( BTELOG_ENABLE_AUTOSAR_STDTYPES )
uint8 bteLog_StdReturnType2String_string[20];
#endif

/***********************************************************************************************************************
Global data definitions (ROM)
***********************************************************************************************************************/

/***********************************************************************************************************************
Local data definitions (RAM)
***********************************************************************************************************************/
static tBteLog bteStub[kBteNumberOfStubs];

/***********************************************************************************************************************
Local data definitions (ROM)
***********************************************************************************************************************/

/***********************************************************************************************************************
Local function prototypes
***********************************************************************************************************************/

/***********************************************************************************************************************
Global function definitions
***********************************************************************************************************************/
/***********************************************************************************************************************
Name:         BteLog_Init
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteLog_Init( void )
{
  uint8 stubId;
  for( stubId=0; stubId<kBteNumberOfStubs; stubId++ )
  {
    BteLog_EventMask_DisableAll( stubId );
    //BteLog_SetStubName( stubId, "undefined" );
  }
}

/***********************************************************************************************************************
Name:         BteLog_SetStubName
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteLog_SetStubName( uint8 stubId, uint8 *name )
{
#if defined (USE_PRINTF)
  (void)sprintf(bteStub[stubId].stubName, "%s", name);
#endif
}

/***********************************************************************************************************************
Name:         BteLog_GetStubName
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
uint8 *BteLog_GetStubName( uint8 stubId )
{
#if defined (USE_PRINTF)
  return bteStub[stubId].stubName;
#endif
}


/***********************************************************************************************************************
Name:         BteLog_EventMask_EnableAll
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteLog_EventMask_EnableAll( uint8 stubId )
{
  BteLog_EventListMask_EnableAll(stubId);
  BteLog_EventLogMask_EnableAll(stubId);
}

/***********************************************************************************************************************
Name:         BteLog_EventMask_DisableAll
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteLog_EventMask_DisableAll( uint8 stubId )
{
  BteLog_EventListMask_DisableAll(stubId);
  BteLog_EventLogMask_DisableAll(stubId);
}

/***********************************************************************************************************************
Name:         BteLog_EventMask_Enable
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteLog_EventMask_Enable( uint8 stubId, uint8 eventId )
{
  BteLog_EventListMask_Enable(stubId,eventId);
  BteLog_EventLogMask_Enable(stubId,eventId);
}

/***********************************************************************************************************************
Name:         BteLog_EventMask_Disable
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteLog_EventMask_Disable( uint8 stubId, uint8 eventId )
{
  BteLog_EventListMask_Disable(stubId,eventId);
  BteLog_EventLogMask_Disable(stubId,eventId);
}




/***********************************************************************************************************************
Name:         BteLog_EventListMask_EnableAll
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteLog_EventListMask_EnableAll( uint8 stubId )
{
  uint8 index;

  if( stubId < kBteNumberOfStubs )
  {
    for( index=0; index<(256/8); index++ )
    {
      bteStub[stubId].eventListMask[index]=0xFF;
    }
  }
  else
  {
    BteError("BteLog: StubId exceeds defined limit");
  }

}

/***********************************************************************************************************************
Name:         BteLog_EventListMask_DisableAll
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteLog_EventListMask_DisableAll( uint8 stubId )
{
  uint8 index;

  if( stubId < kBteNumberOfStubs )
  {
    for( index=0; index<(256/8); index++ )
    {
      bteStub[stubId].eventListMask[index]=0x00;
    }
  }
  else
  {
    BteError("BteLog: StubId exceeds defined limit,");
  }
}

/***********************************************************************************************************************
Name:         BteLog_EventListMask_Enable
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteLog_EventListMask_Enable( uint8 stubId, uint8 eventId )
{
  if( stubId < kBteNumberOfStubs )
  {
    bteStub[stubId].eventListMask[eventId/8] |= 1<<(eventId & 0x07);
  }
  else
  {
    BteError("BteLog: StubId exceeds defined limit,");
  }
}

/***********************************************************************************************************************
Name:         BteLog_EventListMask_Disable
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteLog_EventListMask_Disable( uint8 stubId, uint8 eventId )
{
  if( stubId < kBteNumberOfStubs )
  {
    bteStub[stubId].eventListMask[eventId/8] &= (uint8)(~(uint8)(1u<<(eventId & 0x07u)));
  }
  else
  {
    BteError("BteLog: StubId exceeds defined limit,");
  }
}

/***********************************************************************************************************************
Name:         BteLog_EventListMask_Check
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
uint8 BteLog_EventListMask_Check( uint8 stubId, uint8 eventId )
{
  uint8 rval;

  if( (bteStub[stubId].eventListMask[eventId/8] & (uint8)(1<<((uint8)(eventId & 0x07)))) != 0 )
  {
    rval = 1;
  }
  else
  {
    rval = 0;
  }
  return( rval );
}


/***********************************************************************************************************************
Name:         BteLog_EventLogMask_EnableAll
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteLog_EventLogMask_EnableAll( uint8 stubId )
{
  uint8 index;

  if( stubId < kBteNumberOfStubs )
  {
    for( index=0; index<(256/8); index++ )
    {
      bteStub[stubId].eventLogMask[index]=0xFF;
    }
  }
  else
  {
    BteError("BteLog: StubId exceeds defined limit");
  }

}

/***********************************************************************************************************************
Name:         BteLog_EventLogMask_DisableAll
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteLog_EventLogMask_DisableAll( uint8 stubId )
{
  uint8 index;

  if( stubId < kBteNumberOfStubs )
  {
    for( index=0; index<(256/8); index++ )
    {
      bteStub[stubId].eventLogMask[index]=0x00;
    }
  }
  else
  {
    BteError("BteLog: StubId exceeds defined limit,");
  }
}

/***********************************************************************************************************************
Name:         BteLog_EventLogMask_Enable
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteLog_EventLogMask_Enable( uint8 stubId, uint8 eventId )
{
  if( stubId < kBteNumberOfStubs )
  {
    bteStub[stubId].eventLogMask[eventId/8] |= 1<<(eventId & 0x07);
  }
  else
  {
    BteError("BteLog: StubId exceeds defined limit,");
  }
}

/***********************************************************************************************************************
Name:         BteLog_EventLogMask_Disable
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteLog_EventLogMask_Disable( uint8 stubId, uint8 eventId )
{
  if( stubId < kBteNumberOfStubs )
  {
    bteStub[stubId].eventLogMask[eventId/8] &= (uint8)(~(uint8)(1u<<(eventId & 0x07u)));
  }
  else
  {
    BteError("BteLog: StubId exceeds defined limit,");
  }
}

/***********************************************************************************************************************
Name:         BteLog_EventLogMask_Check
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
uint8 BteLog_EventLogMask_Check( uint8 stubId, uint8 eventId )
{
  uint8 rval;

  if( (bteStub[stubId].eventLogMask[eventId/8] & (uint8)(1<<((uint8)(eventId & 0x07)))) != 0 )
  {
    rval = 1;
  }
  else
  {
    rval = 0;
  }
  return( rval );
}

/***********************************************************************************************************************
Name:         BteLog_Event_Log
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteLog_Event_Init( tBteEvent *pEvent )
{
  BteEvent_Init(pEvent);
  pEvent->time = BteTestCase_GetTime();
}

/***********************************************************************************************************************
Name:         BteLog_Event_InitExt
Parameter:    *pEvent
Return value: ---
Description:  This function initializes the data elements of an event.
***********************************************************************************************************************/
void BteLog_Event_InitExt( tBteEvent *pEvent, uint8 comp, uint8 code, uint8* name )
{
  BteLog_Event_Init(pEvent);
  pEvent->comp = comp;
  pEvent->code = code;
  (void)sprintf( pEvent->text_name, name );
}

/***********************************************************************************************************************
Name:         BteLog_Event_Log
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
//void BteLog_Event_Log( tBteEvent *pEvent, const char* text_name, const char* text_param)
//{
//  pEvent->time = BteTestCase_GetTime();
//
//  if( BteEventFilter_Apply(pEvent) != 0 )
//  {
//    ApplBteLog_Trigger();
//#if defined ( BTETLOG_ENABLE_TRIGGERCALLBACK )
//    ApplBteLog_TriggerOccurred();
//#endif
//  }
//
//  if( (pEvent->type == kBteEventType_Command) || 
//    ((BteLog_EventLogMask_Check(pEvent->comp, pEvent->code))!= 0) )
//  {
//#if defined (USE_EXTERNAL_LOG)
//    uint8 tempText[150];
//    (void)sprintf( pEvent->text_name, text_name );
//
//    switch(pEvent->numParam) 
//    {
//    case 1:			
//      (void)sprintf( pEvent->text_param, text_param, pEvent->data1); 
//      break;
//    case 2:			
//      (void)sprintf( pEvent->text_param, text_param, pEvent->data1, pEvent->data2); 
//      break;
//    case 3:			
//      (void)sprintf( pEvent->text_param, text_param, pEvent->data1, pEvent->data2, pEvent->data3); 
//      break;		
//    case 4:			
//      (void)sprintf( pEvent->text_param, text_param, pEvent->data1, pEvent->data2, pEvent->data3, pEvent->data4); 
//      break;
//    case 5:			
//      (void)sprintf( pEvent->text_param, text_param, pEvent->data1, pEvent->data2, pEvent->data3, pEvent->data4, pEvent->data5); 
//      break;		
//    default:
//      (void)sprintf( pEvent->text_param, text_param);
//      break;
//    }
//
//    sprintf( tempText, "%s %s", pEvent->text_name, pEvent->text_param );
//    if( pEvent->type == kBteEventType_Command )
//    {
//      BteReport_WriteElement( "cmd", pEvent->time, tempText );
//    }
//    else if ( pEvent->type == kBteEventType_Error )
//    {
//      BteReport_WriteElement( "fail", pEvent->time, tempText );
//    }
//    else
//    {
//      BteReport_WriteElement( "", pEvent->time, tempText );
//    }
//
//    BteTraceReport_WriteElement( pEvent );
//#endif
//
//#if defined USE_INTERNAL_LOG
//    BteLogList_Add( pEvent );	// Fuege neues Event hinzu
//#endif
//
//#if defined ( VGEN_ENABLE_TSCPANEL )
//    (void)sprintf( tempText, "%7d %s%s", pEvent->time, pEvent->text_name, pEvent->text_param );
//    CANoeAPI_WriteString( tempText );
//#endif
//  }
//
//#if defined ( BTE_ENABLE_EVENTLIST )
//  if( (BteLog_EventListMask_Check(pEvent->comp, pEvent->code))!= 0 )
//  {
//    BteEventList_Add( pEvent );
//  }
//#endif
//
//
//#if defined ( BTE_ENABLE_EVENTCALLCONTEXTLIST )
//  if( pEvent->type != kBteEventType_Internal )
//  {
//    BteEventCallContextList_Add( pEvent );
//  }
//#endif
//}

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
#if defined (USE_EXTERNAL_LOG)
    uint8 tempText[150];

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
#endif

#if defined USE_INTERNAL_LOG
    BteLogList_Add_Event( pEvent );
#endif

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

/***********************************************************************************************************************
Name:         BteLog_TimerStart
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteLog_TimerStart( tBteEvent *pEvent )
{
  pEvent = pEvent;
  BteTimer_Start();
}

/***********************************************************************************************************************
Name:         BteLog_TimerStop
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteLog_TimerStop( tBteEvent *pEvent )
{
  uint32 timediff;

  timediff = BteTimer_Stop();
  BteEventTimingList_Add( pEvent, timediff );
}

/***********************************************************************************************************************
Name:         BteLog_Debug
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteLog_Debug(char *text)
{
#if defined ( VGEN_ENABLE_TSCPANEL ) || defined ( BTE_ENABLE_TRACEREPORT )
  char tempText[120];
#endif

#if defined ( BTE_ENABLE_TRACEREPORT )
  (void)sprintf(tempText," note left of Appl: %s", text);
  BteTraceReport_Write(tempText);
#endif


  BteReport_WriteInfo(text);

#if defined ( VGEN_ENABLE_TSCPANEL )
  (void)sprintf( tempText, "%7d %s", BteTestCase_GetTime(), text );
  CANoeAPI_WriteString( tempText );
#endif
}

/***********************************************************************************************************************
Name:         BteLog_WriteConfig
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteLog_WriteConfigText( uint8 *attrName, uint8* attrValue )
{
#if defined (USE_EXTERNAL_LOG)
  uint8 text[150];

  (void)sprintf(text,"<configAttr name=\"%s\" value=\"%s\"></configAttr>", attrName, attrValue);
  BteReport_Write(text);
#endif
}

/***********************************************************************************************************************
Name:         BteLog_WriteConfigValue
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteLog_WriteConfigValue( uint8 *attrName, uint32 attrValue )
{
#if defined (USE_EXTERNAL_LOG)
  uint8 text[150];

  (void)sprintf(text,"<configAttr name=\"%s\" value=\"%d\"></configAttr>", attrName, attrValue);
  BteReport_Write(text);
#endif
}

/***********************************************************************************************************************
Name:         BteLog_WriteConfigAsrSwitch
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteLog_WriteConfigAsrSwitch( uint8 *attrName, uint32 attrValue )
{
#if defined (USE_EXTERNAL_LOG)
  uint8 text[150];

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
#endif
}

#if defined ( BTELOG_ENABLE_AUTOSAR_STDTYPES )
/***********************************************************************************************************************
Name:         BteLog_StdReturnType2String
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
uint8* BteLog_StdReturnType2String(Std_ReturnType rval)
{
#if defined (USE_EXTERNAL_LOG)
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
#endif
}
#endif

void BteLog_ConfigGroup_Begin( char *text )
{
#if defined (USE_EXTERNAL_LOG)
  char text2[300];
  (void)sprintf(text2,"<configGroup name=\"%s\">",text);
  BteReport_Write(text2);
#endif
}


void BteLog_ConfigGroup_End( void )
{
#if defined (USE_EXTERNAL_LOG)
  BteReport_Write("</configGroup>");
#endif
}

void BteLog_VersionGroup_Begin( char *text )
{
#if defined (USE_EXTERNAL_LOG)
  char text2[300];
  (void)sprintf(text2,"<versionData name=\"%s\">",text);
  BteReport_Write(text2);
#endif
}

void BteLog_VersionGroup_End( void )
{
#if defined (USE_EXTERNAL_LOG)
  BteReport_Write("</versionData>");
#endif
}


/***********************************************************************************************************************
Local function definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
EOF
***********************************************************************************************************************/
