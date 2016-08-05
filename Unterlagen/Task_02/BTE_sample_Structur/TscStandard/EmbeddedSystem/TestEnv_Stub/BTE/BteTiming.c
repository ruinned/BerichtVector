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
         File:  BteTiming.c
      Project:  zBte
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
  1.00.00   2008-05-28  vismas                creation
  1.01.00   2009-11-11  vismas                minor corrections
***********************************************************************************************************************/

#define V_BTETIMING_SOURCE

/***********************************************************************************************************************
  Includes
***********************************************************************************************************************/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include "BteCfg.h"
#if defined ( BTE_ENABLE_TIME_MEASUREMENT )
#include <windows.h>
#endif

#include "BteTiming.h"
#include "BteTestHandler.h"
#include "BteReport.h"


/***********************************************************************************************************************
  Version check
***********************************************************************************************************************/
#if ( BTETIMING_VERSION != 0x0101 )
  #error "Header and Source file are inconsistent (version)!"
#endif
#if ( BTETIMING_RELEASE_VERSION != 0x00 )
  #error "Header and Source file are inconsistent (release version)!"
#endif

/***********************************************************************************************************************
  Local data defines
***********************************************************************************************************************/
/*--- Timer ---------------------------------------------------------------------------------------------------------*/
#define kBteTimer_MaxNesting                                                  10

/*--- Event Timing List ---------------------------------------------------------------------------------------------*/
#if defined ( kBteEventTimingList_size )
#else
  #define kBteEventTimingList_size                                            100
#endif

/***********************************************************************************************************************
  Local macro defines
***********************************************************************************************************************/

/***********************************************************************************************************************
  Local typedefs
***********************************************************************************************************************/
/*--- Timer ---------------------------------------------------------------------------------------------------------*/
#if defined ( BTE_ENABLE_TIME_MEASUREMENT )
#else
  #define LONGLONG uint8
#endif

typedef struct stBteTimer
{
  uint8    nrTimeStamps;
  LONGLONG  freq;
  LONGLONG  timeStart[kBteTimer_MaxNesting];
  LONGLONG  timeStop[kBteTimer_MaxNesting];
} tBteTimer;

/*--- Event Timing List ---------------------------------------------------------------------------------------------*/
typedef struct stBteEventTiming
{
  uint8 comp;
  uint8 code;
  uint8 name[100];
  uint32 min;
  uint32 max;
  uint32 sum;
  uint32 occurence;
} tBteEventTiming;

typedef struct stBteTimingDataList
{
  uint16             size;
  tBteEventTiming    elem[kBteEventTimingList_size];
} tBteEventTimingList;

/***********************************************************************************************************************
  Global data definitions (RAM)
***********************************************************************************************************************/

/***********************************************************************************************************************
  Global data definitions (ROM)
***********************************************************************************************************************/

/***********************************************************************************************************************
  Local data definitions (RAM)
***********************************************************************************************************************/
/*--- Timer ---------------------------------------------------------------------------------------------------------*/
static tBteTimer bteTimer;

/*--- Event Timing List ---------------------------------------------------------------------------------------------*/
static tBteEventTimingList bteEventTimingList;

/***********************************************************************************************************************
  Local data definitions (ROM)
***********************************************************************************************************************/

/***********************************************************************************************************************
  Local function prototypes
***********************************************************************************************************************/

/***********************************************************************************************************************
  Global function definitions
***********************************************************************************************************************/
/*--- Timer ---------------------------------------------------------------------------------------------------------*/
/***********************************************************************************************************************
  Name:         BteEventTimer_Init
  Parameter:    ---
  Return value: ---
  Description:  
***********************************************************************************************************************/
void BteTimer_Init( void )
{
  #if defined ( BTE_ENABLE_TIME_MEASUREMENT )
  uint8 i;

  bteTimer.nrTimeStamps = 0;
  for( i=0; i<kBteTimer_MaxNesting; i++ )
  {
    bteTimer.timeStart[i] = 0;
    bteTimer.timeStop[i] = 0;
  }
  QueryPerformanceFrequency((LARGE_INTEGER*)&bteTimer.freq);
  #endif
}

/***********************************************************************************************************************
  Name:         BteTimer_Start
  Parameter:    ---
  Return value: ---
  Description:  
***********************************************************************************************************************/
void BteTimer_Start( void )
{
  #if defined ( BTE_ENABLE_TIME_MEASUREMENT )
  if( bteTimer.nrTimeStamps < kBteTimer_MaxNesting )
  {
    QueryPerformanceCounter((LARGE_INTEGER*)&bteTimer.timeStart[bteTimer.nrTimeStamps]);
    bteTimer.nrTimeStamps++;
  }
  #endif
}

/***********************************************************************************************************************
  Name:         BteTimer_Stop
  Parameter:    ---
  Return value: time difference since last timer start
  Description:  
***********************************************************************************************************************/
uint32 BteTimer_Stop( void )
{
  double dTimeDiff = 0;

  #if defined ( BTE_ENABLE_TIME_MEASUREMENT )
  if( bteTimer.nrTimeStamps > 0 )
  {
    bteTimer.nrTimeStamps--;
    QueryPerformanceCounter((LARGE_INTEGER*)&bteTimer.timeStop[bteTimer.nrTimeStamps]);
  }
  dTimeDiff = (double)(bteTimer.timeStop[bteTimer.nrTimeStamps]-bteTimer.timeStart[bteTimer.nrTimeStamps]);
  /*
  dTimeDiff /= (double)bteTimer.freq;
  dTimeDiff *= 1000000000;
  */
  #endif
  return ((uint32)dTimeDiff);
}

/*--- Event Timing List ---------------------------------------------------------------------------------------------*/
/***********************************************************************************************************************
  Name:         BteEventTimingList_Clear
  Parameter:    ---
  Return value: ---
  Description:  This function clears the event list.
***********************************************************************************************************************/
void BteEventTimingList_Clear( void )
{
  uint16 listIndex;

  for( listIndex=0; listIndex<kBteEventTimingList_size; listIndex++ )
  {
    tBteEventTiming *elem = &bteEventTimingList.elem[listIndex];

    elem->code = 0x00;
    elem->comp = 0x00;
#if defined USE_EXTERNAL_LOG
    sprintf( elem->name, "---" );
#endif
    elem->min = 0;
    elem->max = 0;
    elem->sum = 0;
    elem->occurence = 0;
  }
  bteEventTimingList.size = 0;
}

/***********************************************************************************************************************
  Name:         BteEventTimingList_Add
  Parameter:    *pEvent
  Return value: ---
  Description:  
***********************************************************************************************************************/
void BteEventTimingList_Add( tBteEvent *pEvent, uint32 time )
{
  uint16 listIndex;
  uint8 alreadyInList = 0;

  for( listIndex=0; listIndex<bteEventTimingList.size; listIndex++ )
  {
    tBteEventTiming *elem = &bteEventTimingList.elem[listIndex];

    if( (elem->code == pEvent->code) && 
        (elem->comp == pEvent->comp) )
    {
      alreadyInList = 1;

      /* update values */
      if( time < elem->min )
      {
        elem->min = time;
      }
      if( time > elem->max )
      {
        elem->max = time;
      }
      if( (elem->sum) < (0xFFFFFFFF - time) )
      {
        elem->sum += time;
        elem->occurence++;
      }
      break;
    }
  }

  if( alreadyInList == 0 )
  {
    if( bteEventTimingList.size < kBteEventTimingList_size )
    {
      tBteEventTiming *elem = &bteEventTimingList.elem[bteEventTimingList.size];

      elem->code = pEvent->code;
      elem->comp = pEvent->comp;
#if defined USE_EXTERNAL_LOG
      (void)sprintf(elem->name, pEvent->text_name);
#endif

      elem->min = time;
      elem->max = time;
      elem->sum = time;
      elem->occurence = 1;

      bteEventTimingList.size++;
    }
  }
}

/***********************************************************************************************************************
  Name:         BteEventTimingList_Log
  Parameter:    *pEvent
  Return value: ---
  Description:  
***********************************************************************************************************************/
void BteEventTimingList_WriteReport( char *textTcId )
{
  char text[200];
  uint8 i;

  (void)sprintf(text, "<testcase id=\"%s\" name=\"\">", textTcId );
  BteReport_Write(text);
  BteTestRun_Begin("");
  BteReport_Write("<FunctionRuntime>");
  for( i=0; i<bteEventTimingList.size; i++ )
  {
    uint32 avg;
    tBteEventTiming *timingData;
    timingData = &bteEventTimingList.elem[i];
    if( timingData->occurence != 0 )
    {
      avg = timingData->sum/timingData->occurence;
    }
    else
    {
      avg = 0;
    }
    (void)sprintf( text, "<function name=\"%s\" min=\"%d\" max=\"%d\" occurence=\"%d\" sum=\"%d\" avg=\"%d\"></function>"
                                                                              ,timingData->name
                                                                              ,timingData->min
                                                                              ,timingData->max
                                                                              ,timingData->occurence
                                                                              ,timingData->sum 
                                                                              ,avg );
    BteReport_Write(text);
  }
  BteReport_Write("</FunctionRuntime>");
  BteReport_Write("<result>ok</result>");
  BteTestRun_End();
  BteReport_Write("</testcase>");
}

/***********************************************************************************************************************
  Local function definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
  EOF
***********************************************************************************************************************/
