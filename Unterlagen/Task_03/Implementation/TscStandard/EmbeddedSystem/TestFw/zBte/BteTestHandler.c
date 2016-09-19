/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  Copyright (c) 2007 by Vector Informatik GmbH.                                                  All rights reserved.

                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
         File:  BteTestHandler.c
      Project:  BteTestHandler
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
**********************************************************************************************************************/

#define V_BTETESTHANDLER_SOURCE

/**********************************************************************************************************************
  Includes
**********************************************************************************************************************/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

#include "BteTestHandler.h"
#include "BteEventList.h"
#include "BteTiming.h"
#include "BteCallContext.h"
#include "BteReport.h"
#include "BteLog.h"
#include "TscTest.h"

/**********************************************************************************************************************
  Version check
**********************************************************************************************************************/
#if ( BTE_TESTHANDLER_VERSION != 0x0100 )
  #error "Header and Source file are inconsistent (version)!"
#endif
#if ( BTE_TESTHANDLER_RELEASE_VERSION != 0x00 )
  #error "Header and Source file are inconsistent (release version)!"
#endif

/**********************************************************************************************************************
  Local data defines
**********************************************************************************************************************/
/*--- test result ---------------------------------------------------------------------------------------------------*/
#define kBteResult_OK                                                         0x01
#define kBteResult_FAIL                                                       0x02
#define kBteResult_NA                                                         0x03
#define kBteResult_WARN                                                       0x04

#define kBteTextSize                                                          1000

/**********************************************************************************************************************
  Local macro defines
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local typedefs
**********************************************************************************************************************/
/*--- test result ---------------------------------------------------------------------------------------------------*/
typedef struct stBteResult
{
  vuint16  nrOfOK;
  vuint16  nrOfFAIL;
  vuint16  nrOfWARN;
  vuint16  nrOfNA;
  vuint16  nrTotal;
  vuint8   state;
} tBteResult;

/*--- test plan -----------------------------------------------------------------------------------------------------*/
typedef struct stBteTestPlan
{
  tBteResult result;
} tBteTestPlan;

/*--- test case -----------------------------------------------------------------------------------------------------*/
typedef struct stBteTestCase
{
  vuint32 timer;
  tBteResult result;
  vuint8  description_id[100];
  vuint8  description_name[200];
  vuint8  description_parameter[200];
  vuint8  description_purpose[200];
  vuint8  description_reference[200];
  vuint8  description_text[1000];
} tBteTestCase;

typedef struct stBteTestGroup
{
  vuint8 level;
} tBteTestGroup;

typedef enum
{
  BTETEST_TRIGGER_RUNNING = 0,
  BTETEST_TRIGGER_OCCURRED = 1,
  BTETEST_TRIGGER_TIMEOUT = 2,
  BTETEST_TRIGGER_STOPPED = 255
} tBteTestHandler_Trigger;

/**********************************************************************************************************************
  Global data definitions (RAM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global data definitions (ROM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local data definitions (RAM)
**********************************************************************************************************************/
static tBteTestCase bteTestCase;
static tBteTestPlan bteTestPlan;
static tBteTestGroup bteTestGroup;
static tBteTestHandler_Trigger bteTestHandler_Trigger;
static vuint32 bteTestHandler_TriggerOccurrenceTime;
static vuint32 bteTestHandler_TriggerRemainingTime;


/**********************************************************************************************************************
  Local data definitions (ROM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local function prototypes
**********************************************************************************************************************/
/*--- test result ---------------------------------------------------------------------------------------------------*/
static void BteResult_Init( tBteResult *pResult );
static void BteResult_Update( tBteResult *pResult, vuint8 type );

/*--- test case -----------------------------------------------------------------------------------------------------*/
static void BteTestCase_Init(void);
static void BteTestCase_Report_Start(void );
static void BteTestCase_Report_Stop(void);

/*--- test plan -----------------------------------------------------------------------------------------------------*/

/**********************************************************************************************************************
  Global function prototypes
**********************************************************************************************************************/
/*--- test plan -----------------------------------------------------------------------------------------------------*/
/**********************************************************************************************************************
  Name:         BteTestPlan_Start
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteTestPlan_Start( void )
{
  BteResult_Init( &bteTestPlan.result );

  BteEventCallContextList_Clear();
  BteEventTimingList_Clear();

  bteTestGroup.level=0;

  printf("start of test plan\n");
  BteReport_Open("report_TSC.xml");
}

/**********************************************************************************************************************
  Name:         BteTestPlan_End
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteTestPlan_End( void )
{
  /*
  if( BteTestPlan_GetResult() > 0 )
  {
    BteReport_Write("<result>fail</result>");
  }
  else
  {
    BteReport_Write("<result>ok</result>");
  }
  */

  BteReport_Close();
}

/**********************************************************************************************************************
  Name:         BteTestPlan_GetResult
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
vuint16 BteTestPlan_GetResult( void )
{
  return( bteTestPlan.result.nrOfFAIL );
}

/*---------------------------------------------------------------------------------------------------------------------
  TestGroup
---------------------------------------------------------------------------------------------------------------------*/
/**********************************************************************************************************************
  Name:         BteTestGroup_Start
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteTestGroup_Start( vuint8 *name )
{
  vuint8 index;
  vuint8 tempText[200];
  (void)sprintf(tempText, "<testgroup name=\"%s\">", name );
  BteReport_Write(tempText);

  (void)sprintf(tempText, "startTestGroup name=\"%s\"", name );
  //BteTraceReport_Write(tempText);

  bteTestGroup.level++;

  printf("\n");
  for( index=0; index<bteTestGroup.level; index++ )
  {
    printf("  ");
  }
  printf("%s: ", name);
}

/**********************************************************************************************************************
  Name:         BteTestGroup_End
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteTestGroup_End( void )
{
  BteReport_Write("</testgroup>");
  bteTestGroup.level--;
}

/*---------------------------------------------------------------------------------------------------------------------
  TestCase
---------------------------------------------------------------------------------------------------------------------*/
/**********************************************************************************************************************
  Name:         BteTestCase_Error
  Parameter:    
  Return value: 
  Description:  This API increases the test case error counter.
**********************************************************************************************************************/
void BteTestCase_Error( void )
{
  BteResult_Update( &bteTestCase.result, kBteResult_FAIL );
}

/**********************************************************************************************************************
  Name:         BteTestCase_Warning
  Parameter:    
  Return value: 
  Description:  This API increases the test case warning counter.
**********************************************************************************************************************/
void BteTestCase_Warning( void )
{
  BteResult_Update( &bteTestCase.result, kBteResult_WARN );
}

/**********************************************************************************************************************
  Name:         BteTestCase_NA
  Parameter:    
  Return value: 
  Description:  This API sets the result of the test case to N/A and outputs a 
                justification text to the test report.
**********************************************************************************************************************/
void BteTestCase_NA( vuint8 *text )
{
  vuint8 text2[kBteTextSize];

  (void)sprintf( text2, "<NA_Text>%s</NA_Text>", text );
  BteReport_Write( text2 );
  BteResult_Update( &bteTestCase.result, kBteResult_NA );
}

/**********************************************************************************************************************
  Name:         BteTestCase_GetTime
  Parameter:    
  Return value: time: time since test case has been started
  Description:  This API returns the time since the test case has been started.
**********************************************************************************************************************/
vuint32 BteTestCase_GetTime( void )
{
  return( bteTestCase.timer );
}

/**********************************************************************************************************************
  Name:         BteTestCase_SetData
  Parameter:    
  Return value: 
  Description:  This API sets data of the testcase.
**********************************************************************************************************************/
void BteTestCase_SetData( vuint8 type, vuint8 *text )
{
  switch( type )
  {
    /*--------------------------*/
    case TC_PARAMETER:
      sprintf( bteTestCase.description_parameter, text );
      break;
    /*--------------------------*/
    case TC_NAME:
      sprintf( bteTestCase.description_name, text );
      break;
    /*--------------------------*/
    case TC_PURPOSE:
      sprintf( bteTestCase.description_purpose, text );
      break;
    /*--------------------------*/
    case TC_REFERENCE:
      sprintf( bteTestCase.description_reference, text );
      break;
    /*--------------------------*/
    case TC_DESCRIPTION:
      sprintf( bteTestCase.description_text, text );
      break;
    /*--------------------------*/
    case TC_ID:
      sprintf( bteTestCase.description_id, text );
      break;
    /*--------------------------*/
    default:
      break;
  }
}

/**********************************************************************************************************************
  Name:         BteTestCase_SetState
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void BteTestCase_SetState( tBteTestCaseState state )
{
  switch( state )
  {
    /*----------------------------------------------------------------------*/
    case BTETESTCASE_INIT:
      BteTraceReport2_Write("== INIT ==");
      BteTimer_Init();
      BteCriticalSection_Init();
      BteTestCase_Init();
      bteTestHandler_Trigger = BTETEST_TRIGGER_STOPPED;
      bteTestHandler_TriggerOccurrenceTime = 0u;
      bteTestHandler_TriggerRemainingTime = 0u;
      break;
    /*----------------------------------------------------------------------*/
    case BTETESTCASE_STARTTESTCASE:
      BteTestCase_Report_Start();
      break;
    /*----------------------------------------------------------------------*/
    case BTETESTCASE_STARTTESTLOG:
      BteReport_Write("<log>");
#if defined VGEN_ENABLE_TSCTEST
      BteLog_Init();
      ApplBteTestCase_Init();
#endif
      break;
      /*----------------------------------------------------------------------*/
    case BTETESTCASE_PREPARE:
      BteTraceReport2_Write("== PREPARE ==");
      BteTestCase_Report_Start();
      BteReport_Write("<log>");
#if defined ( BTE_ENABLE_REDUCED_LOGGING )
      BteReport_Open_TestcaseReport();
      BteReport_Select_TestcaseReport();
#endif
      BteReport_WriteSect( "--- PREPARE ---" );
#if defined VGEN_ENABLE_TSCTEST
      BteLog_Init();
      ApplBteTestCase_Init();
#endif
      break;
    /*----------------------------------------------------------------------*/
    case BTETESTCASE_EXECUTE:
      BteTraceReport2_Write("== EXECUTE ==");
      bteTestCase.timer = 0x0000; /* reset timer to have proper references */
      BteEventList_Clear();
      BteEventFilter_Clear();
      BteReport_WriteSect( "--- EXECUTE ---" );
      break;
    /*----------------------------------------------------------------------*/
    case BTETESTCASE_ANALYSIS:
      BteTraceReport2_Write("== ANALYSIS ==");
      BteReport_WriteSect( "--- ANALYSIS ---" );
      break;
    /*----------------------------------------------------------------------*/
    case BTETESTCASE_STOP:
      BteTraceReport2_Write("== END ==");
#if defined ( BTE_ENABLE_REDUCED_LOGGING )
      BteReport_Close_TestcaseReport();
      BteReport_Select_MainReport();
      switch( bteTestCase.result.state )
      {
        case kBteResult_FAIL:
          BteReport_Copy_Testcase2Main();
          break;
      }
#endif
      BteTestCase_Report_Stop();
      switch( bteTestCase.result.state )
      {
        case kBteResult_OK:
          printf("x");
          break;
        case kBteResult_WARN:
          printf("W");
          break;
        case kBteResult_FAIL:
          printf("F");
          break;
        case kBteResult_NA:
          printf("-");
          break;
      }
      BteResult_Update( &bteTestPlan.result, bteTestCase.result.state );
      break;
  }
}

/*---------------------------------------------------------------------------------------------------------------------
  Trigger Handling
---------------------------------------------------------------------------------------------------------------------*/

/**********************************************************************************************************************
  Name:         BteWait
  Parameter:    timedelay
  Return value: ---
  Description:  This functions waits until the given time in [ms] has elapsed.
                In order to let the application continue operation, a callback is executed each 1ms.
                This callback is meant to implement the application actions with the waiting time.
**********************************************************************************************************************/
void BteWait( vuint32 timedelay )
{
  vuint32 time;

  for( time=0; time<timedelay; time++ )
  {
    ApplBteTestCase_Cyclic1ms();
    bteTestCase.timer++;
  }
}

/**********************************************************************************************************************
  Name:         BteTest_WaitTrigger
  Parameter:    ---
  Return value: ---
  Description:  This API waits until a trigger event is reported (or a timeout occurs).
**********************************************************************************************************************/
vuint8 BteWaitTriggerWithTimeout( vuint32 timeout )
{
  vuint32 timer;
  
  timer = timeout;

  bteTestHandler_Trigger=BTETEST_TRIGGER_RUNNING;
  /* check if trigger event occured */
  while( bteTestHandler_Trigger==BTETEST_TRIGGER_RUNNING )
  {
    /* perform single time step (1ms) */
    BteWait(1);

    /* backup solution: if trigger never occurs, loop will be left when timer expires*/
    timer--;
    if( (timer == 0) && (bteTestHandler_Trigger != BTETEST_TRIGGER_OCCURRED) )
    {
      bteTestHandler_Trigger = BTETEST_TRIGGER_TIMEOUT;
    }
  }
  /* trigger occured => continue execution */
  bteTestHandler_TriggerOccurrenceTime = (bteTestCase.timer - 1);
  bteTestHandler_TriggerRemainingTime = timer;
  return bteTestHandler_Trigger;
}

/**********************************************************************************************************************
  Name:         BteWaitTrigger
  Parameter:    ---
  Return value: ---
  Description:  
**********************************************************************************************************************/
vuint8 BteWaitTrigger( void )
{
  return( BteWaitTriggerWithTimeout( 0xFFFF ) );
}

/**********************************************************************************************************************
  Name:         BteGetTriggerTime
  Parameter:    
  Return value: ---
  Description:  
**********************************************************************************************************************/
void BteGetTriggerTime( vuint32 * occurrenceTime, vuint32 * remainingTime )
{
  if( occurrenceTime != 0 ) 
  {
    *occurrenceTime = bteTestHandler_TriggerOccurrenceTime;
  }
  if( remainingTime != 0 )
  {
    *remainingTime = bteTestHandler_TriggerRemainingTime;
  }
}

/**********************************************************************************************************************
  Name:         ApplBteLog_Trigger
  Parameter:    ---
  Return value: ---
  Description:  This API notifies a trigger event.
**********************************************************************************************************************/
void ApplBteLog_Trigger( void )
{
  bteTestHandler_Trigger = BTETEST_TRIGGER_OCCURRED;
}


/**********************************************************************************************************************
  Local function definitions
**********************************************************************************************************************/
/*--- test result ---------------------------------------------------------------------------------------------------*/
/**********************************************************************************************************************
  Name:         BteResult_Init
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
static void BteResult_Init( tBteResult *pResult )
{
  pResult->nrOfOK = 0;
  pResult->nrOfFAIL = 0;
  pResult->nrOfWARN = 0;
  pResult->nrOfNA = 0;
  pResult->nrTotal = 0;
  pResult->state = kBteResult_OK;
}

/**********************************************************************************************************************
  Name:         BteResult_Update
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
static void BteResult_Update( tBteResult *pResult, vuint8 type )
{
  pResult->nrTotal++;
  switch( type )
  {
    case kBteResult_OK:
      pResult->nrOfOK++;
      break;
    case kBteResult_FAIL:
      pResult->nrOfFAIL++;
      if( pResult->state != kBteResult_NA )
      {
        pResult->state = kBteResult_FAIL;
      }
      break;
    case kBteResult_WARN:
      pResult->nrOfWARN++;
      if( pResult->state == kBteResult_OK )
      {
        pResult->state = kBteResult_WARN;
      }
      break;
    case kBteResult_NA:
      pResult->nrOfNA++;
      pResult->state = kBteResult_NA;
      break;
  }
}

/*--- test case -----------------------------------------------------------------------------------------------------*/
/**********************************************************************************************************************
  Name:         BteTestCase_Init
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
static void BteTestCase_Init(void)
{
  BteResult_Init( &bteTestCase.result );
  bteTestCase.timer = 0x0000;
  (void)sprintf( bteTestCase.description_name, "" );
  (void)sprintf( bteTestCase.description_parameter, "" );
  (void)sprintf( bteTestCase.description_text, "" );
  (void)sprintf( bteTestCase.description_purpose, "");
  (void)sprintf( bteTestCase.description_reference, "" );
  (void)sprintf( bteTestCase.description_id, "" );
}

/**********************************************************************************************************************
  Name:         BteTestCase_Report_Start
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
static void BteTestCase_Report_Start()
{
#if defined ( _V_RESSOURCE_ )
#else
  BteReport_StartTestCase(bteTestCase.description_id,
                          bteTestCase.description_name,
                          bteTestCase.description_text);
  BteReport_StartTestRun( bteTestCase.description_parameter );
#endif
}

/**********************************************************************************************************************
  Name:         BteTestCase_Report_Stop
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
static void BteTestCase_Report_Stop()
{
  BteReport_Write("</log>");
  switch( bteTestCase.result.state )
  {
    case kBteResult_FAIL:
      BteReport_Write("<result>fail</result>");
      break;
    case kBteResult_WARN:
      BteReport_Write("<result>warn</result>");
      break;
    case kBteResult_NA:
      BteReport_Write("<result>N/A</result>");
      break;
    default:
      BteReport_Write("<result>ok</result>");
      break;
  }
  BteReport_StopTestRun();
  BteReport_StopTestCase();
}

/*--- test plan -----------------------------------------------------------------------------------------------------*/
/**********************************************************************************************************************
  EOF
**********************************************************************************************************************/
