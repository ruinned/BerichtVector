/***********************************************************************************************************************
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
***********************************************************************************************************************/

#define V_BTETESTHANDLER_SOURCE

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "BteCfg.h"
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#if defined ( _V_RESSOURCE_ )
#else
#if defined ( BTE_ENABLE_TESTREPORT )
#include <windows.h>
#endif
#endif

#include "BteTestHandler.h"
#include "BteEventList.h"
#include "BteTiming.h"
#include "BteCallContext.h"
#include "BteReport.h"
#include "BteLog.h"
//#include "TscTest.h"

/***********************************************************************************************************************
Version check
***********************************************************************************************************************/
#if ( BTE_TESTHANDLER_VERSION != 0x0100 )
#error "Header and Source file are inconsistent (version)!"
#endif
#if ( BTE_TESTHANDLER_RELEASE_VERSION != 0x00 )
#error "Header and Source file are inconsistent (release version)!"
#endif

/***********************************************************************************************************************
Local data defines
***********************************************************************************************************************/
/*--- test result ---------------------------------------------------------------------------------------------------*/
#define kBteResult_OK                                                         0x01
#define kBteResult_FAIL                                                       0x02
#define kBteResult_NA                                                         0x03
#define kBteResult_WARN                                                       0x04

#define kBteTextSize                                                          1000

/***********************************************************************************************************************
Local macro defines
***********************************************************************************************************************/

/***********************************************************************************************************************
Local typedefs
***********************************************************************************************************************/
/*--- TestResult ---------------------------------------------------------------------------------------------------*/
typedef struct stBteResult
{
  uint16  nrOfOK;
  uint16  nrOfFAIL;
  uint16  nrOfWARN;
  uint16  nrOfNA;
  uint16  nrTotal;
  uint8   state;
} tBteResult;

/*--- TestReport -----------------------------------------------------------------------------------------------------*/
typedef struct stBteTestReport
{
  tBteResult result;
  uint8     isOpen;
} tBteTestReport;

typedef struct stBteTestGroup
{
  uint8 level;
} tBteTestGroup;

typedef struct stBteTestSequence
{
  uint16 id_num;
  uint8 isOpen;
#if defined ( USE_PRINTF )
  char  description_id[50];
  char  description_name[100];
  char  description_parameter[100];
  char  description_purpose[100];
  char  description_reference[100];
  char  description_text[1000];
#endif
} tBteTestSequence;

typedef struct stBteTestRun
{
  uint32 timer;
  tBteResult result;
} tBteTestRun;


typedef enum
{
  BTETEST_TRIGGER_RUNNING = 0,
  BTETEST_TRIGGER_OCCURRED = 1,
  BTETEST_TRIGGER_TIMEOUT = 2,
  BTETEST_TRIGGER_STOPPED = 255
} tBteTestHandler_Trigger;

/***********************************************************************************************************************
Global data definitions (RAM)
***********************************************************************************************************************/

/***********************************************************************************************************************
Global data definitions (ROM)
***********************************************************************************************************************/

/***********************************************************************************************************************
Local data definitions (RAM)
***********************************************************************************************************************/
static tBteTestReport bteTestReport;

static tBteTestGroup bteTestGroup;
static tBteTestRun bteTestRun;
static tBteTestSequence bteTestSequence;


static tBteTestHandler_Trigger bteTestHandler_Trigger;
static uint32 bteTestHandler_TriggerOccurrenceTime;
static uint32 bteTestHandler_TriggerRemainingTime;


/***********************************************************************************************************************
Local data definitions (ROM)
***********************************************************************************************************************/

/***********************************************************************************************************************
Local function prototypes
***********************************************************************************************************************/
/*--- TestResult ---------------------------------------------------------------------------------------------------*/
static void BteTestResult_Init( tBteResult *pResult );
static void BteTestResult_Update( tBteResult *pResult, uint8 type );
static void BteTestResult_WriteReport( tBteResult *pResult );
static void BteTestResult_WriteConsole( tBteResult *pResult );
/*--- TestLog ---------------------------------------------------------------------------------------------------*/
static void BteTestLog_Begin( void );
static void BteTestLog_End( void );


/***********************************************************************************************************************
Global function prototypes
***********************************************************************************************************************/
/*--- test report -----------------------------------------------------------------------------------------------------*/
/***********************************************************************************************************************
Name:         BteTestReport_Init
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteTestReport_Init( void )
{
  BteTestResult_Init( &bteTestReport.result );
  bteTestReport.isOpen = 0;
}

/***********************************************************************************************************************
Name:         BteTest_Begin
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteTest_Begin( void )
{
  BteTestReport_Init();

  if( bteTestReport.isOpen == 0 )
  {
    bteTestReport.isOpen = 1;

    BteEventCallContextList_Clear();
    BteEventTimingList_Clear();
    BteTestGroup_Init();
    BteTestSequence_Init();
#if defined ( USE_PRINTF )
    /* console */
    printf("start...\n");
#endif
    /* report */
    BteReport_Open("BteReport.xml");
    //    BteReport_Write("<testplan name=\"TestReport Temp\" type=\"structured\">");

  }
#if defined USE_INTERNAL_LOG
  BteLogList_Clear();
#endif
}

/***********************************************************************************************************************
Name:         BteTest_End
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteTest_End( void )
{

  BteTestHandler_BackgroundTest_Log();

  if( bteTestReport.isOpen != 0 )
  {
    bteTestReport.isOpen = 0;

    /* report */
    //    BteReport_Write("</testplan>");
    BteReport_Close();
#if defined ( USE_PRINTF )
    /* console */
    printf("...done\n");
#endif
  }
}

/***********************************************************************************************************************
Name:         BteTest_GetResult
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
uint16 BteTest_GetResult( void )
{
  return( bteTestReport.result.nrOfFAIL );
}

/*---------------------------------------------------------------------------------------------------------------------
TestGroup
---------------------------------------------------------------------------------------------------------------------*/
/***********************************************************************************************************************
Name:         BteTestGroup_Init
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteTestGroup_Init( void )
{
  bteTestGroup.level = 0;
}

/***********************************************************************************************************************
Name:         BteTestGroup_Begin
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteTestGroup_Begin( uint8 *name )
{
#if defined (BTE_ENABLE_TESTREPORT)
  uint8 index;
  uint8 tempText[200];
  /* report */
  (void)sprintf(tempText, "<testgroup name=\"%s\">", name );
  BteReport_Write(tempText);

  /* console */
  printf("\n");

  for( index=0; index<bteTestGroup.level; index++ )
  {
    printf("  ");
  }
  printf("%s: ", name);
#endif
  bteTestGroup.level++;
  /* undelying elements */
  BteTestSequence_Init();
}

/***********************************************************************************************************************
Name:         BteTestGroup_End
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteTestGroup_End( void )
{
  if( bteTestGroup.level > 0 )
  {
#if defined (BTE_ENABLE_TESTREPORT)
    /* report */
    BteReport_Write("</testgroup>");
#endif

    bteTestGroup.level--;
  }
}

/*---------------------------------------------------------------------------------------------------------------------
TestSequence
---------------------------------------------------------------------------------------------------------------------*/
/***********************************************************************************************************************
Name:         BteTestSequence_Init
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteTestSequence_Init( void )
{
  bteTestSequence.isOpen = 0;
}

/***********************************************************************************************************************
Name:         BteTestSequence_BeginID
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteTestSequence_BeginID( uint16 id )
{
#if defined (BTE_ENABLE_TESTREPORT)
  char tempText[100];
#endif

  BteTestSequence_PreBegin();

  BteLogList_AddTestcase( id );

#if defined (BTE_ENABLE_TESTREPORT) || defined  (BTE_ENABLE_TRACEREPORT)

  // wenn Anwender eine ID Nummer angibt
  if (id)
  {
    (void)sprintf(tempText,"TCASE-%u",id);
  }
  else // wenn er eine anzugeben vergisst
  {
    (void)sprintf(tempText, "%s", bteTestSequence.description_id );
  }
  BteTestSequence_BeginReport(tempText);
#endif
#if defined ( USE_INTERNAL_LOG )
  BteTestSequence_Begin_Intern();
  BteTestCase_ResetData_ID(); // Zum Ueberpruefen notwendig, ob der Benutzer neue Eintraege gemacht hat, das muesste aber auch bei einer init routine gemacht werden!!!
#endif
}

/***********************************************************************************************************************
Name:         BteTestSequence_Begin
Parameter:
Return value:
Description:  new method
***********************************************************************************************************************/
void BteTestSequence_PreBegin()
{
  /* close possible open TestSequence */
  if( bteTestSequence.isOpen == 1 )
  {
    BteTestSequence_End();
  }
  bteTestSequence.isOpen = 1;
}

void BteTestSequence_BeginReport( uint8 *id )
{
#if defined (BTE_ENABLE_TESTREPORT)

  char tempText[200];

  /* report */
  (void)sprintf(tempText, "<testcase id=\"%s\" name=\"\">", id ); // diese beiden Zeilen sind nur fuer die neuen Markus Testcasemethoden noetig
  BteReport_Write(tempText);

  BteTestRun_Begin( bteTestSequence.description_parameter );
  BteTestLog_Begin();
#endif
#if defined (BTE_ENABLE_TRACEREPORT)
  /* trace report */
  (void)sprintf(tempText,"Trace_%s.vuml", id );
  BteTraceReport_Open(tempText);
  BteTraceReport_Write("@startuml");
  (void)sprintf(tempText, "title %s", id );
  BteTraceReport_Write(tempText);
  BteTraceReport_Write("hide footbox");
  //  BteTraceReport_Write("skin BlueModern");
  BteTraceReport_Write("participant Appl");
  BteTraceReport_Write("participant DUT");
  BteTraceReport_Write("participant Dem");
  BteTraceReport_Write("participant Det");
  BteTraceReport_Write("participant EcuM");
  BteTraceReport_Write("participant SchM");
#endif
}

void BteTestSequence_Begin_Intern()
{
  /* init testsequence data */
  BteTestResult_Init( &bteTestRun.result );
  bteTestRun.timer = 0x0000;

  BteTimer_Init();
  BteCriticalSection_Init();
  BteEventList_Clear();
  BteEventFilter_Clear();
  bteTestHandler_Trigger = BTETEST_TRIGGER_STOPPED;
  bteTestHandler_TriggerOccurrenceTime = 0u;
  bteTestHandler_TriggerRemainingTime = 0u;
  BteLog_Init();
#if defined VGEN_ENABLE_TSCTEST
  BteTraceReport_Write("== INIT ==");
  ApplBteTestCase_Init();
#endif
  BteTraceReport_Write("== RUN ==");
}

void BteTestSequence_Begin(uint8 *text)
{
  BteTestSequence_PreBegin();
  BteTestSequence_BeginReport(text);
  BteTestSequence_Begin_Intern();
}


/***********************************************************************************************************************
Name:         BteTestSequence_End
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteTestSequence_End( void )
{
  if( bteTestSequence.isOpen != 0 )
  {

    bteTestSequence.isOpen = 0;
#if defined ( BTE_ENABLE_TESTREPORT )
    /* report */
    BteTestLog_End();
    BteTestResult_WriteReport( &bteTestRun.result );
    BteTestRun_End();
    BteReport_Write("</testcase>");
#endif
#if defined (BTE_ENABLE_TRACEREPORT)
    /* trace report */
    BteTraceReport_Write("== END ==");
    BteTraceReport_Write("@enduml");
    BteTraceReport_Close();

    /* result */
    BteTestResult_WriteConsole( &bteTestRun.result );
#endif
    BteTestResult_Update( &bteTestReport.result, bteTestRun.result.state );
  }
}

/*---------------------------------------------------------------------------------------------------------------------
TestRun
---------------------------------------------------------------------------------------------------------------------*/
/***********************************************************************************************************************
Name:         BteTestRun_Init
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteTestRun_Init( void )
{
}

/***********************************************************************************************************************
Name:         BteTestRun_Begin
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteTestRun_Begin( char *parameter )
{
#if defined ( _V_RESSOURCE_ )
#else
#if defined ( BTE_ENABLE_TESTREPORT )
  char tempText[kBteTextSize];
  SYSTEMTIME time;
  GetLocalTime (&time);

  (void)sprintf( tempText, "<testrun date=\"%04d-%02d-%02d %02d:%02d:%02d\" executor=\"%s\" parameter=\"config=%s %s\">",  
    time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond,
    getenv("USERNAME"),
    getenv("EmbeddedSystem.ActiveTestData.Reference"), parameter );
  BteReport_Write(tempText);
#endif
#endif
}

/***********************************************************************************************************************
Name:         BteTestRun_End
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteTestRun_End( void )
{
  BteReport_Write("</testrun>");
}

/***********************************************************************************************************************
Name:         BteTestRun_Error
Parameter:    
Return value: 
Description:  This API increases the test case error counter.
***********************************************************************************************************************/
void BteTestRun_Error( void )
{
  BteTestResult_Update( &bteTestRun.result, kBteResult_FAIL );
}

/***********************************************************************************************************************
Name:         BteTestRun_Warning
Parameter:    
Return value: 
Description:  This API increases the test case warning counter.
***********************************************************************************************************************/
void BteTestRun_Warning( void )
{
  BteTestResult_Update( &bteTestRun.result, kBteResult_WARN );
}

/***********************************************************************************************************************
Name:         BteTestRun_NA
Parameter:    
Return value: 
Description:  This API sets the result of the test case to N/A and outputs a 
justification text to the test report.
***********************************************************************************************************************/
void BteTestRun_NA( char *text )
{
#if defined ( BTE_ENABLE_TESTREPORT )
  char text2[kBteTextSize];

  (void)sprintf( text2, "<NA_Text>%s</NA_Text>", text );
  BteReport_Write( text2 );
#endif
  BteTestResult_Update( &bteTestRun.result, kBteResult_NA );
}

/*---------------------------------------------------------------------------------------------------------------------
TestLog
---------------------------------------------------------------------------------------------------------------------*/
/***********************************************************************************************************************
Name:         BteTestLog_Begin
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
static void BteTestLog_Begin( void )
{
  BteReport_Write("<log>");
}

/***********************************************************************************************************************
Name:         BteTestLog_End
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
static void BteTestLog_End( void )
{
  BteReport_Write("</log>");
}

/*---------------------------------------------------------------------------------------------------------------------
TCASE
---------------------------------------------------------------------------------------------------------------------*/
/***********************************************************************************************************************
Name:         BteTCASE_Begin
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteTCASE_Begin( uint8 *id )
{
#if defined ( BTE_ENABLE_TESTREPORT )
  uint8 tempText[200];
  (void)sprintf(tempText, "<TCASE id=\"%s\">", id );
  BteReport_Write(tempText);
#endif
#if defined ( BTE_ENABLE_TRACEREPORT )
  (void)sprintf(tempText, "== TCASE %s start ==", id );
  BteTraceReport_Write(tempText);
#endif
}

/***********************************************************************************************************************
Name:         BteTCASE_End
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteTCASE_End( void )
{
#if defined ( BTE_ENABLE_TESTREPORT )
  uint8 tempText[200];
  BteReport_Write("</TCASE>");
#endif
#if defined ( BTE_ENABLE_TRACEREPORT )
  (void)sprintf(tempText, "== TCASE end ==" );
  BteTraceReport_Write(tempText);
#endif
}


/*---------------------------------------------------------------------------------------------------------------------
TestCase
---------------------------------------------------------------------------------------------------------------------*/



/***********************************************************************************************************************
Name:         BteTestCase_GetTime
Parameter:    
Return value: time: time since test case has been started
Description:  This API returns the time since the test case has been started.
***********************************************************************************************************************/
uint32 BteTestCase_GetTime( void )
{
  return( bteTestRun.timer );
}

/***********************************************************************************************************************
Name:         BteTestCase_SetData
Parameter:    
Return value: 
Description:  This API sets data of the testcase.
***********************************************************************************************************************/
void BteTestCase_SetData( uint8 type, char *text )
{
#if defined ( USE_PRINTF )
  switch( type )
  {
    /*--------------------------*/
  case TC_PARAMETER:
    sprintf( bteTestSequence.description_parameter, text );
    break;
    /*--------------------------*/
  case TC_NAME:
    sprintf( bteTestSequence.description_name, text );
    break;
    /*--------------------------*/
  case TC_PURPOSE:
    sprintf( bteTestSequence.description_purpose, text );
    break;
    /*--------------------------*/
  case TC_REFERENCE:
    sprintf( bteTestSequence.description_reference, text );
    break;
    /*--------------------------*/
  case TC_DESCRIPTION:
    sprintf( bteTestSequence.description_text, text );
    break;
    /*--------------------------*/
  case TC_ID:
    sprintf( bteTestSequence.description_id, text );
    break;
    /*--------------------------*/
  default:
    break;
  }
#endif
}

/***********************************************************************************************************************
Name:         BteTestCase_ResetData_ID
Parameter:
Return value:
Description:  This API resets data of the testcase.
***********************************************************************************************************************/
void BteTestCase_ResetData_ID()
{
  bteTestSequence.id_num = 0;
}

/***********************************************************************************************************************
Name:         BteTestCase_SetData_ID
Parameter:
Return value:
Description:  This API resets data of the testcase.
***********************************************************************************************************************/
void BteTestCase_SetData_ID( uint16 id_num )
{
  bteTestSequence.id_num = id_num;
}

/***********************************************************************************************************************
Name:         BteTestCase_SetState
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteTestCase_SetState( tBteTestCaseState state )
{
#if defined ( BTE_ENABLE_TESTREPORT )
  uint8 tempText[100];
#endif

  switch( state )
  {
    /*----------------------------------------------------------------------*/
  case BTETESTCASE_INIT:
    BteTimer_Init();
    BteCriticalSection_Init();
    bteTestHandler_Trigger = BTETEST_TRIGGER_STOPPED;
    bteTestHandler_TriggerOccurrenceTime = 0u;
    bteTestHandler_TriggerRemainingTime = 0u;
    break;
    /*----------------------------------------------------------------------*/
  case BTETESTCASE_STARTTESTCASE:
#if defined ( BTE_ENABLE_TESTREPORT )
    if (bteTestSequence.id_num)
    {
      (void)sprintf(tempText,"<testcase id=\"TCASE-%u\" name=\"\">",bteTestSequence.id_num);
    }
    else // wenn er eine anzugeben vergisst
    {
      (void)sprintf(tempText, "<testcase id=\"%s\" name=\"\">", bteTestSequence.description_id );
    }
    BteReport_Write(tempText);
#endif
    BteLogList_AddTestcase( bteTestSequence.id_num );

    break;
    /*----------------------------------------------------------------------*/
  case BTETESTCASE_STARTTESTLOG:
    //      BteTraceReport_Open(text);
    BteTestLog_Begin();
#if defined VGEN_ENABLE_TSCTEST
    BteLog_Init();
    ApplBteTestCase_Init();
#endif
    break;
    /*----------------------------------------------------------------------*/
  case BTETESTCASE_PREPARE:
    //      BteTraceReport_Open(text);
    //     (void)sprintf(tempText, "<testcase id=\"%s\">", bteTestSequence.description_id );
#if defined ( BTE_ENABLE_TESTREPORT )
    BteReport_Write(tempText);
    BteTestLog_Begin();
    BteReport_WriteSect( "--- PREPARE ---" );
#endif
#if defined VGEN_ENABLE_TSCTEST
    BteLog_Init();
    ApplBteTestCase_Init();
#endif
    break;
    /*----------------------------------------------------------------------*/
  case BTETESTCASE_EXECUTE:
    bteTestRun.timer = 0x0000; /* reset timer to have proper references */
    BteEventList_Clear();
    BteEventFilter_Clear();
    BteReport_WriteSect( "--- EXECUTE ---" );
    break;
    /*----------------------------------------------------------------------*/
  case BTETESTCASE_STOP:
    BteTraceReport_Close();
#if defined ( BTE_ENABLE_TESTREPORT )
    BteReport_Write("</log>");
    switch( bteTestRun.result.state )
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
    BteReport_Write("</testcase>");
#endif
    BteTestResult_Update( &bteTestReport.result, bteTestRun.result.state );
    break;
  }
}

/*---------------------------------------------------------------------------------------------------------------------
Trigger Handling
---------------------------------------------------------------------------------------------------------------------*/

/***********************************************************************************************************************
Name:         BteWait
Parameter:    timedelay
Return value: ---
Description:  This functions waits until the given time in [ms] has elapsed.
In order to let the application continue operation, a callback is executed each 1ms.
This callback is meant to implement the application actions with the waiting time.
***********************************************************************************************************************/
void BteWait( uint32 timedelay )
{
  uint32 time;

  for( time=0; time<timedelay; time++ )
  {
    ApplBteTestCase_Cyclic1ms();
    bteTestRun.timer++;
  }
}

/***********************************************************************************************************************
Name:         BteTest_WaitTrigger
Parameter:    ---
Return value: ---
Description:  This API waits until a trigger event is reported (or a timeout occurs).
***********************************************************************************************************************/
uint8 BteWaitTriggerWithTimeout( uint32 timeout )
{
  uint32 timer;

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
  bteTestHandler_TriggerOccurrenceTime = (bteTestRun.timer - 1);
  bteTestHandler_TriggerRemainingTime = timer;
  return bteTestHandler_Trigger;
}

/***********************************************************************************************************************
Name:         BteWaitTrigger
Parameter:    ---
Return value: ---
Description:  
***********************************************************************************************************************/
uint8 BteWaitTrigger( void )
{
  return( BteWaitTriggerWithTimeout( 0xFFFF ) );
}

/***********************************************************************************************************************
Name:         BteGetTriggerTime
Parameter:    
Return value: ---
Description:  
***********************************************************************************************************************/
void BteGetTriggerTime( uint32 * occurrenceTime, uint32 * remainingTime )
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

/***********************************************************************************************************************
Name:         ApplBteLog_Trigger
Parameter:    ---
Return value: ---
Description:  This API notifies a trigger event.
***********************************************************************************************************************/
void ApplBteLog_Trigger( void )
{
  bteTestHandler_Trigger = BTETEST_TRIGGER_OCCURRED;
}


/***********************************************************************************************************************
Local function definitions
***********************************************************************************************************************/
/*--- test result ---------------------------------------------------------------------------------------------------*/
/***********************************************************************************************************************
Name:         BteTestResult_Init
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
static void BteTestResult_Init( tBteResult *pResult )
{
  pResult->nrOfOK = 0;
  pResult->nrOfFAIL = 0;
  pResult->nrOfWARN = 0;
  pResult->nrOfNA = 0;
  pResult->nrTotal = 0;
  pResult->state = kBteResult_OK;
}

/***********************************************************************************************************************
Name:         BteTestResult_Update
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
static void BteTestResult_Update( tBteResult *pResult, uint8 type )
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

/***********************************************************************************************************************
Name:         BteTestResult_WriteReport
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
static void BteTestResult_WriteReport( tBteResult *pResult )
{

  switch( pResult->state )
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

}

/***********************************************************************************************************************
Name:         BteTestResult_WriteConsole
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
static void BteTestResult_WriteConsole( tBteResult *pResult )
{
#if defined ( USE_PRINTF )
  switch( pResult->state )
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
#endif
}


/*--- test case -----------------------------------------------------------------------------------------------------*/

#define kBteBgrTest_MaxCount  100
typedef struct {
  tBteBgrTest_Id total;
  tBteBgrTest_Id fail;
  uint8 used;
#if defined ( USE_PRINTF )
  char text[30];
#endif
} tBteBgrTest;

static tBteBgrTest bteBgrTest[kBteBgrTest_MaxCount];

#define kTscApplCheckConsistency 0x01
void BteTestHandler_BackgroundTest_Clear(void)
{
  uint16 i;
  for(i=0; i<kBteBgrTest_MaxCount; i++)
  {
    bteBgrTest[i].used = 0;
    bteBgrTest[i].total = 0;
    bteBgrTest[i].fail = 0;
#if defined ( USE_PRINTF )
    (void)sprintf(bteBgrTest[i].text,"");
#endif

  }
}


void BteTestHandler_BackgroundTest_Init(tBteBgrTest_Id id, char *text)
{
  if( bteBgrTest[id].used == 0 )
  {
    bteBgrTest[id].used = 1;
    bteBgrTest[id].total = 0;
    bteBgrTest[id].fail = 0;
# if defined (USE_PRINTF)
    (void)sprintf(bteBgrTest[id].text,"%s", text);
#endif
  }
  else
  {
    BteError("id multiply used");
  }
}

void BteTestHandler_BackgroundTest_Set(tBteBgrTest_Id id, uint8 state)
{
  if( bteBgrTest[id].used != 0 )
  {
    bteBgrTest[id].total++;
    if( state  != 0 ) 
    {
      bteBgrTest[id].fail++;
    }
  }
  else
  {
    BteError("id not defined");
  }
}
void BteTestHandler_BackgroundTest_Log(void)
{
#if defined (BTE_ENABLE_TESTREPORT)
  uint8 text[200];
  uint16 i;
#endif
  //BteTestSequence_Begin("BteTestHandler_BackgroundTest_Log");
#if defined (USE_INTERNAL_LOG)
  BteTestSequence_BeginID(3); // Der Anwender soll diese Methode verwenden
#endif
#if defined (BTE_ENABLE_TESTREPORT)
  for(i=0; i<kBteBgrTest_MaxCount; i++)
  {
    if( bteBgrTest[i].used != 0 )
    {
      if( bteBgrTest[i].total > 0 )
      {

        uint8 text2[50];
        (void)sprintf(text2,"%s",bteBgrTest[i].text);
        //        BteTCASE_Begin(text2);
        (void)sprintf(text,"Test condition checked %d times", bteBgrTest[i].total);
        BteOk(text);
        if( bteBgrTest[i].fail != 0 )
        {
          (void)sprintf(text,"Test condition failed %d times", bteBgrTest[i].fail);
          BteError(text);
        }
        //        BteTCASE_End();

      }

    }
    else
    {
      //no action
    }
  }
#endif

  BteTestSequence_End();
}


#if defined ( _V_RESSOURCE_ )
void ApplBteTestCase_Cyclic1ms( void )
{}
void ApplBteTestCase_Init( void )
{}
int main( void )
{}
#endif

/*--- test plan -----------------------------------------------------------------------------------------------------*/
/***********************************************************************************************************************
EOF
***********************************************************************************************************************/