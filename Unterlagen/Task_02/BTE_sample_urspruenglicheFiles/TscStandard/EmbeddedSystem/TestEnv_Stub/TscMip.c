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
/**     \file  TscMip.c
 *     \brief  TscCut source file for Mip
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
#include "TscMip.h"
#include "BteLog.h"

/***********************************************************************************************************************
 *  VERSION CHECK
 **********************************************************************************************************************/
#if ( (TSCMIP_MAJOR_VERSION != 1) || \
      (TSCMIP_MINOR_VERSION != 0) || \
      (TSCMIP_RELEASE_VERSION != 0))
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

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
static void TscMip_Event_Init( tBteEvent *pEvent );
static void TscMip_Event_Log( tBteEvent *pEvent );

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/
/***********************************************************************************************************************
  Name:        TscMip_Event_Init
  Description: 
***********************************************************************************************************************/
static void TscMip_Event_Init( tBteEvent *pEvent)
{
  BteEvent_Init( pEvent );
  pEvent->comp = kTscMip_CI;
}
/***********************************************************************************************************************
  Name:        TscMip_Event_Log
  Description: 
***********************************************************************************************************************/
static void TscMip_Event_Log( tBteEvent *pEvent)
{
  if (pEvent->type == kBteEventType_Command || pEvent->type == kBteEventType_Command)
  {
    pEvent->caller = kTscMip_CI;
  }
  else if (pEvent->type == kBteEventType_Default)
  {
    pEvent->callee = kTscMip_CI;
  }
  BteLog_Event_Log( pEvent );
}

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
/*--- standard BTE function definition ------------------------------------------------------------------------------*/
/***********************************************************************************************************************
  Name:        TscMip_Init
  Description: 
***********************************************************************************************************************/
void TscMip_Init( void)
{
  BteLog_SetStubName(kTscMip_CI,"Mip");
  TscMip_EventMask_EnableAll();

}
/***********************************************************************************************************************
  Name:        TscMip_Cyclic1ms
  Description: 
***********************************************************************************************************************/
void TscMip_Cyclic1ms( void)
{
}

/*--- wrapper function definition -----------------------------------------------------------------------------------*/
/***********************************************************************************************************************
 *  Mip_SampleA
 **********************************************************************************************************************/
FUNC(Std_ReturnType, MIP_CODE) TscMip_SampleA( void )
{
  tBteEvent evnt;
  Std_ReturnType rval;

  /*--- event logging ---*/
  TscMip_Event_Init( &evnt );
  evnt.code = kTscMip_Mip_SampleA;
  evnt.type = kBteEventType_Command;
  (void)sprintf( evnt.text_name, "Mip_SampleA" );
  (void)sprintf( evnt.text_param, "()");
  TscMip_Event_Log( &evnt );

  /*--- wrapper handling ---*/
  BteCallContext_Set(kBte_Task|kBte_IR);
  BteLog_TimerStart( &evnt );
  rval = Mip_SampleA();
  BteLog_TimerStop( &evnt );

  return rval;
}

/***********************************************************************************************************************
 *  Mip_SampleB
 **********************************************************************************************************************/
FUNC(Std_ReturnType, MIP_CODE) TscMip_SampleB( uint8 handle )
{
  tBteEvent evnt;
  Std_ReturnType rval;

  /*--- event logging ---*/
  TscMip_Event_Init( &evnt );
  evnt.code = kTscMip_Mip_SampleB;
  evnt.type = kBteEventType_Command;
  evnt.data1 = (uint32)handle;
  (void)sprintf( evnt.text_name, "Mip_SampleB" );
  (void)sprintf( evnt.text_param, "(handle=%d)", handle);
  TscMip_Event_Log( &evnt );

  /*--- wrapper handling ---*/
  BteCallContext_Set(kBte_Task|kBte_IR);
  BteLog_TimerStart( &evnt );
  rval = Mip_SampleB(handle);
  BteLog_TimerStop( &evnt );

  return rval;
}

/***********************************************************************************************************************
 *  Mip_SampleC
 **********************************************************************************************************************/
FUNC(Std_ReturnType, MIP_CODE) TscMip_SampleC( uint8 handle, uint16 value )
{
  tBteEvent evnt;
  Std_ReturnType rval;

  /*--- event logging ---*/
  TscMip_Event_Init( &evnt );
  evnt.code = kTscMip_Mip_SampleC;
  evnt.type = kBteEventType_Command;
  evnt.data1 = (uint32)handle;
  evnt.data2 = (uint32)value;
  (void)sprintf( evnt.text_name, "Mip_SampleC" );
  (void)sprintf( evnt.text_param, "(handle=%d, value=%d)", handle, value);
  TscMip_Event_Log( &evnt );

  /*--- wrapper handling ---*/
  BteCallContext_Set(kBte_Task|kBte_IR);
  BteLog_TimerStart( &evnt );
  rval = Mip_SampleC(handle, value);
  BteLog_TimerStop( &evnt );

  return rval;
}

/***********************************************************************************************************************
 *  Mip_SampleD
 **********************************************************************************************************************/
FUNC(Std_ReturnType, MIP_CODE) TscMip_SampleD( uint8 handle, uint16 ptr )
{
  tBteEvent evnt;
  Std_ReturnType rval;

  /*--- event logging ---*/
  TscMip_Event_Init( &evnt );
  evnt.code = kTscMip_Mip_SampleD;
  evnt.type = kBteEventType_Command;
  evnt.data1 = (uint32)handle;
  evnt.data2 = (uint32)ptr;
  (void)sprintf( evnt.text_name, "Mip_SampleD" );
  (void)sprintf( evnt.text_param, "(handle=%d, ptr=%d)", handle, ptr);
  TscMip_Event_Log( &evnt );

  /*--- wrapper handling ---*/
  BteCallContext_Set(kBte_Task|kBte_IR);
  BteLog_TimerStart( &evnt );
  rval = Mip_SampleD(handle, ptr);
  BteLog_TimerStop( &evnt );

  return rval;
}

/***********************************************************************************************************************
 *  Mip_GetVersionInfo
 **********************************************************************************************************************/
FUNC(void, MIP_CODE) TscMip_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
  tBteEvent evnt;

  /*--- event logging ---*/
  TscMip_Event_Init( &evnt );
  evnt.code = kTscMip_Mip_GetVersionInfo;
  evnt.type = kBteEventType_Command;
  evnt.data1 = (uint32)versioninfo;
  (void)sprintf( evnt.text_name, "Mip_GetVersionInfo" );
  (void)sprintf( evnt.text_param, "(versioninfo=%d)", versioninfo);
  TscMip_Event_Log( &evnt );

  /*--- wrapper handling ---*/
#if ( MIP_VERSION_INFO_API == STD_ON )
  BteCallContext_Set(kBte_Task);
  Mip_GetVersionInfo(versioninfo);
  BteLog_TimerStop( &evnt );
#else
  (void)versioninfo;
#endif
}

/***********************************************************************************************************************
 *  Mip_Init
 **********************************************************************************************************************/
FUNC(void, MIP_CODE) TscMip_Mip_Init( Mip_ConfigType *ConfigPtr )
{
  tBteEvent evnt;

  /*--- event logging ---*/
  TscMip_Event_Init( &evnt );
  evnt.code = kTscMip_Mip_Init;
  evnt.type = kBteEventType_Command;
  evnt.data1 = (uint32)&ConfigPtr;
  (void)sprintf( evnt.text_name, "Mip_Init" );
  (void)sprintf( evnt.text_param, "(ConfigPtr=%d)", ConfigPtr);
  TscMip_Event_Log( &evnt );

  /*--- wrapper handling ---*/
  BteCallContext_Set(kBte_Task);
  BteLog_TimerStart( &evnt );
  Mip_Init(ConfigPtr);
  BteLog_TimerStop( &evnt );
}

/***********************************************************************************************************************
 *  Mip_InitMemory
 **********************************************************************************************************************/
FUNC(void, MIP_CODE) TscMip_InitMemory( void )
{
  tBteEvent evnt;

  /*--- event logging ---*/
  TscMip_Event_Init( &evnt );
  evnt.code = kTscMip_Mip_InitMemory;
  evnt.type = kBteEventType_Command;
  (void)sprintf( evnt.text_name, "Mip_InitMemory" );
  (void)sprintf( evnt.text_param, "()");
  TscMip_Event_Log( &evnt );

  /*--- wrapper handling ---*/
  BteCallContext_Set(kBte_Task);
  BteLog_TimerStart( &evnt );
  Mip_InitMemory();
  BteLog_TimerStop( &evnt );
}

/***********************************************************************************************************************
 *  Mip_MainFunction
 **********************************************************************************************************************/
FUNC(void, MIP_CODE) TscMip_MainFunction( void )
{
  tBteEvent evnt;

  /*--- event logging ---*/
  TscMip_Event_Init( &evnt );
  evnt.code = kTscMip_Mip_MainFunction;
  evnt.type = kBteEventType_Command;
  (void)sprintf( evnt.text_name, "Mip_MainFunction" );
  (void)sprintf( evnt.text_param, "()");
  TscMip_Event_Log( &evnt );

  /*--- wrapper handling ---*/
  BteCallContext_Set(kBte_Task);
  BteLog_TimerStart( &evnt );
  Mip_MainFunction();
  BteLog_TimerStop( &evnt );
}

/***********************************************************************************************************************
 *  Mip_UnInit
 **********************************************************************************************************************/
FUNC(void, MIP_CODE) TscMip_UnInit( void )
{
  tBteEvent evnt;

  /*--- event logging ---*/
  TscMip_Event_Init( &evnt );
  evnt.code = kTscMip_Mip_UnInit;
  evnt.type = kBteEventType_Command;
  (void)sprintf( evnt.text_name, "Mip_UnInit" );
  (void)sprintf( evnt.text_param, "()");
  TscMip_Event_Log( &evnt );

  /*--- wrapper handling ---*/
  BteCallContext_Set(kBte_Task);
  BteLog_TimerStart( &evnt );
  Mip_UnInit();
  BteLog_TimerStop( &evnt );
}



/***********************************************************************************************************************
 *  END OF FILE
 **********************************************************************************************************************/

