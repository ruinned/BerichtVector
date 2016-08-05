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
         File:  BteLog.h
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

#ifndef V_BTELOG_HEADER
#define V_BTELOG_HEADER

/***********************************************************************************************************************
  Includes
***********************************************************************************************************************/
#include "Bte.h"

#include "BteLogList.h"
#include "BteEventList.h"
#include "BteCallContext.h"
#include "BteTiming.h"
#include "BteCheck.h"

#if defined ( BTELOG_ENABLE_AUTOSAR_STDTYPES )
#include "Std_Types.h"
#endif

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

/***********************************************************************************************************************
  Version data
***********************************************************************************************************************/
#define BTELOG_VERSION                        0x0101
#define BTELOG_RELEASE_VERSION                0x00

/***********************************************************************************************************************
  Global data defines
***********************************************************************************************************************/
#define kBte_STD_ON     1u
#define kBte_STD_OFF    0u

/***********************************************************************************************************************
  Global macro defines
***********************************************************************************************************************/

/***********************************************************************************************************************
  Global typedefs
***********************************************************************************************************************/

/***********************************************************************************************************************
  Global data prototypes (RAM)
***********************************************************************************************************************/

/***********************************************************************************************************************
  Global data prototypes (ROM)
***********************************************************************************************************************/

/***********************************************************************************************************************
  Global function prototypes
***********************************************************************************************************************/
void BteLog_Init( void );
void BteLog_SetStubName( uint8 stubId, uint8 *name );
uint8* BteLog_GetStubName( uint8 stubId );
void BteLog_EventMask_EnableAll( uint8 stubId );
void BteLog_EventMask_DisableAll( uint8 stubId );
void BteLog_EventMask_Enable( uint8 stubId, uint8 eventId );
void BteLog_EventMask_Disable( uint8 stubId, uint8 eventId );

void BteLog_EventLogMask_EnableAll( uint8 stubId );
void BteLog_EventLogMask_DisableAll( uint8 stubId );
void BteLog_EventLogMask_Enable( uint8 stubId, uint8 eventId );
void BteLog_EventLogMask_Disable( uint8 stubId, uint8 eventId );
uint8 BteLog_EventLogMask_Check( uint8 stubId, uint8 eventId );

void BteLog_EventListMask_EnableAll( uint8 stubId );
void BteLog_EventListMask_DisableAll( uint8 stubId );
void BteLog_EventListMask_Enable( uint8 stubId, uint8 eventId );
void BteLog_EventListMask_Disable( uint8 stubId, uint8 eventId );
uint8 BteLog_EventListMask_Check( uint8 stubId, uint8 eventId );

void BteLog_Event_Init( tBteEvent *pEvent );
void BteLog_Event_InitExt( tBteEvent *pEvent, uint8 comp, uint8 code, uint8* name );
void BteLog_Event_Log( tBteEvent *pEvent );

void BteLog_TimerStart( tBteEvent *pEvent );
void BteLog_TimerStop( tBteEvent *pEvent );

void BteLog_Debug(char *text);
#define BteLog_WriteConfig    BteLog_WriteConfigText
void BteLog_WriteConfigText( uint8 *attrName, uint8* attrValue );
void BteLog_WriteConfigValue( uint8 *attrName, uint32 attrValue );
void BteLog_WriteConfigAsrSwitch( uint8 *attrName, uint32 attrValue );

#if defined ( BTELOG_ENABLE_AUTOSAR_STDTYPES )
uint8* BteLog_StdReturnType2String(Std_ReturnType rval);
#endif

void ApplBteLog_Trigger( void );
#if defined ( BTETLOG_ENABLE_TRIGGERCALLBACK )
void ApplBteLog_TriggerOccurred( void );
#endif

void BteLog_ConfigGroup_Begin( char *text );
void BteLog_ConfigGroup_End( void );

void BteLog_VersionGroup_Begin( char *text );
void BteLog_VersionGroup_End( void );


#endif /* V_BTELOG_HEADER */

/***********************************************************************************************************************
  EOF
***********************************************************************************************************************/
