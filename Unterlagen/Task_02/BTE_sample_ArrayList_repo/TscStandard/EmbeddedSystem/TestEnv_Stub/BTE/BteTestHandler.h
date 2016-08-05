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
         File:  BteTestHandler.h
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

#ifndef V_BTETESTHANDLER_HEADER
#define V_BTETESTHANDLER_HEADER

/***********************************************************************************************************************
  Includes
***********************************************************************************************************************/
#include "Bte.h"

/***********************************************************************************************************************
  Version data
***********************************************************************************************************************/
#define BTE_TESTHANDLER_VERSION                 0x0100
#define BTE_TESTHANDLER_RELEASE_VERSION         0x00

/***********************************************************************************************************************
  Global data defines
***********************************************************************************************************************/
#define BTETESTCASE_OK                          0
#define BTETESTCASE_FAIL                        1
#define BTETESTCASE_NA                          2

#define TC_NAME                                 0x04
#define TC_PARAMETER                            0x06
#define TC_PURPOSE                              0x01
#define TC_REFERENCE                            0x02
#define TC_DESCRIPTION                          0x03
#define TC_ID                                   0x05


/***********************************************************************************************************************
  Global typedefs
***********************************************************************************************************************/
typedef enum
{
  BTETESTCASE_INIT,
  BTETESTCASE_STARTTESTCASE,
  BTETESTCASE_STARTTESTLOG,
  BTETESTCASE_PREPARE,
  BTETESTCASE_EXECUTE,
  BTETESTCASE_STOP
} tBteTestCaseState;

/***********************************************************************************************************************
  Global data prototypes (RAM)
***********************************************************************************************************************/

/***********************************************************************************************************************
  Global data prototypes (ROM)
***********************************************************************************************************************/

/***********************************************************************************************************************
  Global function prototypes
***********************************************************************************************************************/
/*---------------------------------------------------------------------------------------------------------------------
  TestReport
---------------------------------------------------------------------------------------------------------------------*/
#define BteTestPlan_Start       BteTest_Begin
#define BteTestPlan_End         BteTest_End
#define BteTestPlan_GetResult   BteTest_GetResult
void BteTestReport_Init( void );
void BteTest_Begin( void );
void BteTest_End( void );
uint16 BteTest_GetResult( void );

/*---------------------------------------------------------------------------------------------------------------------
  TestGroup
---------------------------------------------------------------------------------------------------------------------*/
#define BteTestGroup_Start    BteTestGroup_Begin
#define BteTestGroup_End      BteTestGroup_End
void BteTestGroup_Init( void );
void BteTestGroup_Begin( uint8 *name );
void BteTestGroup_End( void );

/*---------------------------------------------------------------------------------------------------------------------
  TestSequence
---------------------------------------------------------------------------------------------------------------------*/
void BteTestSequence_Init( void );
void BteTestSequence_Begin( uint8 *id);
void BteTestSequence_End( void );
void BteTestSequence_BeginID( uint16 id);


/*---------------------------------------------------------------------------------------------------------------------
  TestRun
---------------------------------------------------------------------------------------------------------------------*/
void BteTestRun_Init( void );
void BteTestRun_Begin( char *parameter );
void BteTestRun_End( void );
void BteTestRun_Error( void );
void BteTestRun_Warning( void );
void BteTestRun_NA( char *text );
#define BteTestCase_NA BteTestRun_NA


/*---------------------------------------------------------------------------------------------------------------------
  TCASE
---------------------------------------------------------------------------------------------------------------------*/
void BteTCASE_Begin( uint8 *id );
void BteTCASE_End( void );


typedef uint16 tBteBgrTest_Id ;

void BteTestHandler_BackgroundTest_Log(void);
void BteTestHandler_BackgroundTest_Set(tBteBgrTest_Id id, uint8 state);
void BteTestHandler_BackgroundTest_Init(tBteBgrTest_Id id, char *text);

/*---------------------------------------------------------------------------------------------------------------------
  TestCase
---------------------------------------------------------------------------------------------------------------------*/


uint32 BteTestCase_GetTime( void );
uint8 BteTestCase_GetResult( void );

void BteTestCase_SetData( uint8 type, char *text );
void BteTestCase_SetState( tBteTestCaseState state );
void BteTestCase_SetTestCaseID( uint16 id_num );


void BteWait( uint32 timedelay );
uint8 BteWaitTrigger( void );
uint8 BteWaitTriggerWithTimeout( uint32 timeout );
void BteGetTriggerTime( uint32 * occurrenceTime, uint32 * remainingTime );

void ApplBteTestCase_Init( void );
void ApplBteTestCase_Cyclic1ms( void );

#endif /* V_BTETESTHANDLER_HEADER */

/***********************************************************************************************************************
  EOF
***********************************************************************************************************************/
