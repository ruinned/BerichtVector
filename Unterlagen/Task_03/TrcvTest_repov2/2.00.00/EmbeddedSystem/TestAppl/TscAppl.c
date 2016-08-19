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
         File:  TscAppl.c
      Project:  Tsc_Tp_AsrTpFr
       Module:  -
    Generator:  -
  Description:  -
**********************************************************************************************************************/


#define V_TSCAPPL_SOURCE

/**********************************************************************************************************************
  Includes
**********************************************************************************************************************/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

#include "TscAppl.h"
#include "BteLog.h"

#include "string.h"
#include <stdlib.h>/*wnk*/
#include <conio.h>/*wnk*/

/**********************************************************************************************************************
  Version check
**********************************************************************************************************************/
#if ( TSCAPPL_VERSION != 0x0100 )
  #error "Header and Source file are inconsistent (version)!"
#endif
#if ( TSCAPPL_RELEASE_VERSION != 0x00 )
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
/* Critical section handling */
static int exclAreaEnterCount = 0;
static int exclAreaExitCount = 0;
static boolean exclAreaErr = FALSE;

/**********************************************************************************************************************
  Global data definitions (ROM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local data definitions (RAM)
**********************************************************************************************************************/
static uint16 tscAppl_TaskCounter_Appl;
static uint16 tscAppl_TaskCounter_CUT[NUMBER_OF_FR_CHANNELS];
static uint8 i;

/**********************************************************************************************************************
  Local data definitions (ROM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local function prototypes
**********************************************************************************************************************/
static void TscAppl_Event_Init( tBteEvent *pEvent );

/**********************************************************************************************************************
  Global function prototypes
**********************************************************************************************************************/

/*--- generic control -----------------------------------------------------------------------------------------------*/
/**********************************************************************************************************************
  Name:         TscAppl_Init
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void TscAppl_Init( void )
{
  /*--- initialize local variables ---*/

  tscAppl_TaskCounter_Appl = 0;
  for( i=0; i<NUMBER_OF_FR_CHANNELS; i++ )
  {
    tscAppl_TaskCounter_CUT[i] = i;
  }

  /*--- set initial event mask ---*/
  TscAppl_EventMask_DisableAll();

  /*--- initialize CUT ---*/
  FrTrcv_30_Tja1080_Init();
}

/**********************************************************************************************************************
  Name:         TscAppl_Cyclic1ms
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void TscAppl_Cyclic1ms( void )
{
  /* call cyclic task of CUT */
  for( i=0; i<NUMBER_OF_FR_CHANNELS; i++ )
  {
    if( tscAppl_TaskCounter_CUT[i] == 0 )
    {
      FrTrcv_30_Tja1080_MainFunction();
    }
    /* handle task counter (channel-specific, CUT) */
    tscAppl_TaskCounter_CUT[i]++;
    if( tscAppl_TaskCounter_CUT[i] >= FRTRCV_TASK_CALL_CYCLE(i) )
    {
      tscAppl_TaskCounter_CUT[i]=0;
    }
  }

  /*--- application task ---*/
  if( tscAppl_TaskCounter_Appl == 0)
  {
  }
  tscAppl_TaskCounter_Appl++;
  if( tscAppl_TaskCounter_Appl >= 10 )
  {
    tscAppl_TaskCounter_Appl = 0;
  }
}

/**********************************************************************************************************************
  Name:         TscAppl_EventMask_EnableAll
  Parameter:    ---
  Return value: ---
  Description:  
**********************************************************************************************************************/
void TscAppl_EventMask_EnableAll( void )
{
  BteLog_EventMask_EnableAll( kTscAppl_CI );
}

/**********************************************************************************************************************
  Name:         TscAppl_EventMask_DisableAll
  Parameter:    ---
  Return value: ---
  Description:  
**********************************************************************************************************************/
void TscAppl_EventMask_DisableAll( void )
{
  BteLog_EventMask_DisableAll( kTscAppl_CI );
}

/**********************************************************************************************************************
  Name:         TscAppl_EventMask_Enable
  Parameter:    eventId
  Return value: ---
  Description:  
**********************************************************************************************************************/
void TscAppl_EventMask_Enable( uint8 eventId )
{
  BteLog_EventMask_Enable( kTscAppl_CI, eventId );
}

/**********************************************************************************************************************
  Name:         TscAppl_EventMask_Disable
  Parameter:    eventId
  Return value: ---
  Description:  
**********************************************************************************************************************/
void TscAppl_EventMask_Disable( uint8 eventId )
{
  BteLog_EventMask_Disable( kTscAppl_CI, eventId );
}

/*--- specific control ----------------------------------------------------------------------------------------------*/

/*--- test stimulation ----------------------------------------------------------------------------------------------*/


/**********************************************************************************************************************
  Local function definition
**********************************************************************************************************************/
/**********************************************************************************************************************
  Name:          TscAppl_Event_Init
  Parameter:     
  Return value:  
  Description:   
**********************************************************************************************************************/
static void TscAppl_Event_Init( tBteEvent *pEvent )
{
  BteLog_Event_Init( pEvent );
  pEvent->comp = kTscAppl_CI;
}

/**********************************************************************************************************************
  Name:          TscAppl_EnterExclusiveArea
  Parameter:     
  Return value:  
  Description:   
**********************************************************************************************************************/
void TscAppl_EnterExclusiveArea(int area)
{
  switch(area)
  {
    case SCHM_EA_SUSPENDALLINTERRUPTS:
      exclAreaEnterCount++;
      break;
    default:
      exclAreaErr = 1;
      break;
  }
}

/**********************************************************************************************************************
  Name:          BteLog_Event_Log
  Parameter:     
  Return value:  
  Description:   
**********************************************************************************************************************/
void TscAppl_ExitExclusiveArea(int area)
{
  switch(area)
  {
    case SCHM_EA_SUSPENDALLINTERRUPTS:
      exclAreaExitCount++;
      break;
    default:
      exclAreaErr = 1;
      break;
  }
}



/**********************************************************************************************************************
  EOF
**********************************************************************************************************************/