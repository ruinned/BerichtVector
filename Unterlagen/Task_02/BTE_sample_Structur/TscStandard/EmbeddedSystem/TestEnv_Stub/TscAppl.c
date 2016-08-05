/***********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  Copyright (c) 2015 by Vector Informatik GmbH.                                                  All rights reserved.

                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
         File:  TscAppl.c
      Project:  Tsc for Mip
       Module:  -
    Generator:  -
  Description:  
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
  2.00.00   2008-08-22  vismas                creation
***********************************************************************************************************************/

#define V_TSCAPPL_SOURCE
#define _CRT_SECURE_NO_DEPRECATE
/***********************************************************************************************************************
  Includes
***********************************************************************************************************************/
#include "TscAppl.h"
#include "BteLog.h"

/***********************************************************************************************************************
  Version check
***********************************************************************************************************************/
#if ( TSCAPPL_VERSION != 0x0200 )
# error "Header and Source file are inconsistent (version)!"
#endif
#if ( TSCAPPL_RELEASE_VERSION != 0x00 )
# error "Header and Source file are inconsistent (release version)!"
#endif

/***********************************************************************************************************************
  Local data defines
***********************************************************************************************************************/

/***********************************************************************************************************************
  Local macro defines
***********************************************************************************************************************/

/***********************************************************************************************************************
  Local typedefs
***********************************************************************************************************************/

/***********************************************************************************************************************
  Global data definitions (RAM)
***********************************************************************************************************************/

/***********************************************************************************************************************
  Global data definitions (ROM)
***********************************************************************************************************************/

/***********************************************************************************************************************
  Local data definitions (RAM)
***********************************************************************************************************************/
static uint8 tscAppl_TaskCounter;

/***********************************************************************************************************************
  Local data definitions (ROM)
***********************************************************************************************************************/

/***********************************************************************************************************************
  Local function prototypes
***********************************************************************************************************************/

/***********************************************************************************************************************
  Global function prototypes
***********************************************************************************************************************/
/*---------------------------------------------------------------------------------------------------------------------
  Generic Control Functions
---------------------------------------------------------------------------------------------------------------------*/
/***********************************************************************************************************************
  Name:         TscAppl_Init
  Parameter:    
  Return value: 
  Description:  
***********************************************************************************************************************/
void TscAppl_Init( void )
{
  /* initialize local variables */
  tscAppl_TaskCounter=0;

  /* initialize event mask */
  TscAppl_EventMask_EnableAll();
}

/***********************************************************************************************************************
  Name:         TscAppl_Cyclic1ms
  Parameter:    
  Return value: 
  Description:  
***********************************************************************************************************************/
void TscAppl_Cyclic1ms( void )
{
  /* call cyclic task of CUT */
  if( tscAppl_TaskCounter == 0 )
  {
    TscAppl_Mip_MainFunction();
  }
  tscAppl_TaskCounter++;
  if( tscAppl_TaskCounter >= 10 )
  {
    tscAppl_TaskCounter=0;
  }
}

/*---------------------------------------------------------------------------------------------------------------------
  Specific Control Functions
---------------------------------------------------------------------------------------------------------------------*/
/* none */

/*---------------------------------------------------------------------------------------------------------------------
  Stimulation Functions
---------------------------------------------------------------------------------------------------------------------*/
/***********************************************************************************************************************
  Name:         TscAppl_Mip_InitMemory
  Parameter:    
  Return value: 
  Description:  
***********************************************************************************************************************/
void TscAppl_Mip_InitMemory(void)
{
  tBteEvent evnt;

  BteCallContext_Set( kBte_Task );
  BteCriticalSection_Enter();

  BteLog_Event_InitExt(&evnt, kTscAppl_CI, kTscAppl_Mip_InitMemory, "Mip_InitMemory");
  evnt.type = kBteEventType_Command;
  evnt.numParam = 0;
 
  (void)sprintf( evnt.text_param, "()"  );
  BteLog_Event_Log( &evnt );
  //BteLog_Event_Log( &evnt, "Mip_InitMemory", "()");

  BteLog_TimerStart( &evnt );
  Mip_InitMemory();
  BteLog_TimerStop( &evnt );

  BteCriticalSection_Leave();
}

/***********************************************************************************************************************
  Name:         TscAppl_Mip_Init
  Parameter:    
  Return value: 
  Description:  
***********************************************************************************************************************/
void TscAppl_Mip_Init(P2CONST(Mip_ConfigType, AUTOMATIC, MIP_PBCFG) config)
{
  tBteEvent evnt;

  BteCallContext_Set( kBte_Task );
  BteCriticalSection_Enter();

  BteLog_Event_InitExt(&evnt, kTscAppl_CI, kTscAppl_Mip_Init, "Mip_Init");
  evnt.type = kBteEventType_Command;
  evnt.numParam = 0;
  (void)sprintf( evnt.text_param, "()"  );
  BteLog_Event_Log( &evnt );
  //BteLog_Event_Log( &evnt, "Mip_Init", "()");

  BteLog_TimerStart( &evnt );
  Mip_Init(config);
  BteLog_TimerStop( &evnt );

  BteCriticalSection_Leave();
}

/***********************************************************************************************************************
  Name:         TscAppl_Mip_MainFunction
  Parameter:    
  Return value: 
  Description:  
***********************************************************************************************************************/
void TscAppl_Mip_MainFunction(void)
{
  tBteEvent evnt;

  BteCallContext_Set( kBte_Task );

  BteLog_Event_InitExt(&evnt, kTscAppl_CI, kTscAppl_Mip_MainFunction, "Mip_MainFunction");
  evnt.type = kBteEventType_Command;
  evnt.numParam = 0;
  (void)sprintf( evnt.text_param, "()"  );
  /* no logging because of high frequency */
  BteLog_Event_Log( &evnt );
  //BteLog_Event_Log( &evnt, "Mip_MainFunction", "()");

  BteLog_TimerStart( &evnt );
  Mip_MainFunction();
  BteLog_TimerStop( &evnt );
}

/***********************************************************************************************************************
  Name:         TscAppl_Mip_GetVersionInfo
  Parameter:    
  Return value: 
  Description:  
***********************************************************************************************************************/
FUNC( void, MIP_CODE ) TscAppl_Mip_GetVersionInfo( P2VAR( Std_VersionInfoType, AUTOMATIC, MIP_APPL_VAR ) versioninfo)
{
  tBteEvent evnt;

  BteCallContext_Set( kBte_Task );

  BteLog_Event_InitExt(&evnt, kTscAppl_CI, kTscAppl_Mip_MainFunction, "Mip_GetVersionInfo");
  evnt.type = kBteEventType_Command;
  evnt.numParam = 0;
  /*evnt.code=0x33;
  evnt.data1= 0x44444444;
  evnt.data5= 0x88888888;
*/


  (void)sprintf( evnt.text_param, "()"  );
  BteLog_Event_Log(&evnt);
  //BteLog_Event_Log( &evnt, "Mip_GetVersionInfo", "()");

  BteLog_TimerStart( &evnt );
#if ( MIP_VERSION_INFO_API == STD_ON )
  Mip_GetVersionInfo(versioninfo);
#else
  (void)versioninfo;
#endif
  BteLog_TimerStop( &evnt );
}


/*---------------------------------------------------------------------------------------------------------------------
  Stub functions
---------------------------------------------------------------------------------------------------------------------*/
/* none */

/***********************************************************************************************************************
  Local function definition
***********************************************************************************************************************/

/***********************************************************************************************************************
  EOF
***********************************************************************************************************************/
