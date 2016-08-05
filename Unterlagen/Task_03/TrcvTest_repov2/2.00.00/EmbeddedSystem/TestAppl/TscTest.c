/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  Copyright (c) 2008 by Vector Informatik GmbH.                                                  All rights reserved.

                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
         File:  TscTest.c
      Project:  Tsc_Tp_AsrTpFr
       Module:  -
    Generator:  -
  Description:  
**********************************************************************************************************************/

#define V_TSCTEST_SOURCE

/**********************************************************************************************************************
  Includes
**********************************************************************************************************************/
#include "TscTest.h"
#include "TscAppl.h"
#include "TscDet.h"
#include "FrTrcv_30_Tja1080.h"
#include "FrTrcv_30_Tja1080_Phy.h"
#include "Dio.h"
#include "TscDem.h"
//#include "ArduinoCom.h"
#include "ArdTest.h"

/* stub modules */
/* __ORGANI_INCLUDE__ */

/* test framework */
#include "BteLog.h"
#include "BteTestHandler.h"
#include "BteReport.h"

/* Testapp.-specific functionality */
#include "string.h"/*wnk*/
#include <conio.h>/*wnk*/

/**********************************************************************************************************************
  Version check
**********************************************************************************************************************/
#if ( TSCTEST_VERSION != 0x0100 )
# error "Header and Source file are inconsistent (version)!"
#endif
#if ( TSCTEST_RELEASE_VERSION != 0x00 )
# error "Header and Source file are inconsistent (release version)!"
#endif

/**********************************************************************************************************************
  Local configuration
**********************************************************************************************************************/

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
uint8 enableDemError = 0;
extern FUNC(void, FRTRCV_CODE) FrTrcv_30_Tja1080_MainFunction( void );

/**********************************************************************************************************************
  Global data definitions (ROM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local data definitions (RAM)
**********************************************************************************************************************/
static uint32 ICU_enabled = 0;
static uint32 ICU_disabled = 0;
static uint8 tscTest_TaskCounter[1];
static uint8 text[1000];
static uint8 evText[40];

/**********************************************************************************************************************
  Local data definitions (ROM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local function prototypes
**********************************************************************************************************************/
/* --- Helper functions ---------------------------------------------------------------------------------------------*/
static void TscTest_SetFilter( tBteEventFilter_Element filterElem, tBteEventFilter_Operand filterOp,
                              uint32 value1, uint32 value2 );
static void TscTest_SetFilterEventEQ( uint32 comp, uint32 code, uint32 data1, uint32 data2, uint32 data3, uint32 data4, uint32 data5, uint32 dl  );
static void TscTest_SetNewFilterEventEQ( uint32 comp, uint32 code, uint32 data1 , uint32 data2, uint32 data3 , uint32 data4, uint32 data5, uint32 dl);
static void TscTest_AssertEventOccurrenceEQ1Data( uint32 comp, uint32 code, uint32 data1, uint8 *txt, uint32 occurrence );
static void TscTest_AssertEventOccurrenceEQ2Data( uint32 comp, uint32 code, uint32 data1, uint32 data2, uint8 *txt, uint32 occurrence );
static void TscTest_AssertEventOccurrenceEQ3Data( uint32 comp, uint32 code, uint32 data1, uint32 data2, uint32 data3, uint8 *txt, uint32 occurrence );
static void TscTest_AssertEventOccurrenceEQ4Data( uint32 comp, uint32 code, uint32 data1, uint32 data2, uint32 data3, uint32 data4, uint8 *txt, uint32 occurrence );
static void TscTest_AssertEventOccurrenceEQ5Data( uint32 comp, uint32 code, uint32 data1, uint32 data2, uint32 data3, uint32 data4, uint32 data5, uint8 *txt, uint32 occurrence );
static void TscTest_SetFilterEventEQ( uint32 comp, uint32 code, uint32 data1, uint32 data2, uint32 data3, uint32 data4, uint32 data5, uint32 dl );
static void TscTest_SetFilter( tBteEventFilter_Element filterElem, tBteEventFilter_Operand filterOp,
                              uint32 value1, uint32 value2 );





FUNC(void, FRTRCV_CODE) Appl_FrTrcv_30_Tja1080_Wait(uint8 TimerIndex)
{
  TimerIndex = TimerIndex;
}

void Appl_FrTrcv_30_Tja1080_DisableNotification(uint8 Icu_Channel)
{
  ICU_disabled++;
}
void Appl_FrTrcv_30_Tja1080_EnableNotification(uint8 Icu_Channel)
{
  ICU_enabled++;
}

void Appl_FrTrcv_30_Tja1080_ReportErrorStatusFailed(Dem_EventIdType eventId)
{
  (void)Dem_ReportErrorStatus(eventId, (uint8)(DEM_EVENT_STATUS_FAILED));
}

void Appl_FrTrcv_30_Tja1080_ReportErrorStatusPreFailed(Dem_EventIdType eventId)
{
  (void)Dem_ReportErrorStatus(eventId, (uint8)(DEM_EVENT_STATUS_PREFAILED));
}

void Appl_FrTrcv_30_Tja1080_ReportErrorStatusPrePassed(Dem_EventIdType eventId)
{
  (void)Dem_ReportErrorStatus(eventId, (uint8)(DEM_EVENT_STATUS_PREPASSED));
}

FUNC(void, FRTRCV_CODE) Appl_FrTrcv_30_Tja1080_Dio_WriteChannel(Dio_ChannelType channel, Dio_LevelType value)
{
  Dio_WriteChannel(channel, value);
}

FUNC(Dio_LevelType, FRTRCV_CODE) Appl_FrTrcv_30_Tja1080_Dio_ReadChannel(Dio_ChannelType channel)
{
  return Dio_ReadChannel(channel);
}


/**********************************************************************************************************************
  Name:         TscTest_PrintDetError
  Parameter:    
  Return value: -
  Description:  
**********************************************************************************************************************/
void TscTest_PrintDetError(uint16 Result, char* str)
{
  switch(Result)
  {
    case FRTRCV_30_TJA1080_E_FR_INVALID_TRCVIDX:
      sprintf(str, "FRTRCV_E_FR_INVALID_TRCVIDX");
      break;
    case FRTRCV_30_TJA1080_E_FR_UNINIT:
      sprintf(str, "FRTRCV_E_FR_UNINIT");
      break;
    case FRTRCV_30_TJA1080_E_FR_TRCV_NOT_STANDBY:
      sprintf(str, "FRTRCV_E_FR_TRCV_NOT_STANDBY");
      break;
    case FRTRCV_30_TJA1080_E_FR_TRCV_NOT_NORMAL:
      sprintf(str, "FRTRCV_E_FR_TRCV_NOT_NORMAL");
      break;
    case FRTRCV_30_TJA1080_E_FR_TRCV_NOT_SLEEP:
      sprintf(str, "FRTRCV_E_FR_TRCV_NOT_SLEEP");
      break;
    case FRTRCV_30_TJA1080_E_FR_TRCV_NOT_RECEIVEONLY:
      sprintf(str, "FRTRCV_E_FR_TRCV_NOT_RECEIVEONLY");
      break;
    case FRTRCV_30_TJA1080_E_FR_INVALID_POINTER:
      sprintf(str, "FRTRCV_E_FR_INVALID_POINTER");
      break;
    case FRTRCV_30_TJA1080_E_FR_GENERATOR_COMPATIBILITY_ERROR:
      sprintf(str, "FRTRCV_E_FR_GENERATOR_COMPATIBILITY_ERROR");
      break;
    default:
      sprintf(str, "Unknown DET-Error-Code");
      break;
  };
}


/**********************************************************************************************************************
  Name:         TscTest_SetFilter
  Parameter:    
  Return value: -
  Description:  
**********************************************************************************************************************/
static void TscTest_SetFilter( tBteEventFilter_Element filterElem, tBteEventFilter_Operand filterOp,
                              uint32 value1, uint32 value2 )
{
  if( value1 != 0xFF )
  {
    BteEventFilter_Set( filterElem, filterOp, value1, value2 );
  }
}

/**********************************************************************************************************************
  Name:         TscTest_SetFilterEQ
  Parameter:    
  Return value: -
  Description:  
**********************************************************************************************************************/
static void TscTest_SetFilterEventEQ( uint32 comp, uint32 code, uint32 data1, uint32 data2, uint32 data3, uint32 data4, uint32 data5, uint32 dl  )
{
  TscTest_SetFilter( kBte_COMP, kBte_EQ, comp, 0xFF );
  TscTest_SetFilter( kBte_CODE, kBte_EQ, code, 0xFF );
  TscTest_SetFilter( kBte_DATA1, kBte_EQ, data1, 0xFF );
  TscTest_SetFilter( kBte_DATA2, kBte_EQ, data2, 0xFF );
  TscTest_SetFilter( kBte_DATA3, kBte_EQ, data3, 0xFF );
  TscTest_SetFilter( kBte_DATA4, kBte_EQ, data4, 0xFF );
  TscTest_SetFilter( kBte_DATA5, kBte_EQ, data5, 0xFF );
  TscTest_SetFilter( kBte_DL, kBte_EQ, dl, 0xFF );
}

/**********************************************************************************************************************
  Name:         TscTest_SetNewFilterEventEQ
  Parameter:    
  Return value: -
  Description:  
**********************************************************************************************************************/
static void TscTest_SetNewFilterEventEQ( uint32 comp, uint32 code, uint32 data1 , uint32 data2, uint32 data3 , uint32 data4, uint32 data5, uint32 dl)
{
  BteEventFilter_Clear();
  TscTest_SetFilterEventEQ( comp, code, data1, data2, data3, data4, data5, dl );
}

/**********************************************************************************************************************
  Name:         TscTest_AssertEventOccurrenceEQ0Data
  Parameter:    
  Return value: -
  Description:  
**********************************************************************************************************************/
static void TscTest_AssertEventOccurrenceEQ0Data( uint32 comp, uint32 code, uint8 *txt, uint32 occurrence )
{
  TscTest_SetNewFilterEventEQ( comp, code, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF );
  (void)sprintf( evText, "%s", txt );
  (void)sprintf( text, "%s should occur %d times", txt, occurrence );
  BteAssert_EQ( BteEventList_GetSize(), occurrence, text );
}

/**********************************************************************************************************************
  Name:         TscTest_AssertEventOccurrenceEQ1Data
  Parameter:    
  Return value: -
  Description:  
**********************************************************************************************************************/
static void TscTest_AssertEventOccurrenceEQ1Data( uint32 comp, uint32 code, uint32 data1, 
                                                  uint8 *txt, uint32 occurrence )
{
  TscTest_SetNewFilterEventEQ( comp, code, data1, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF );
  (void)sprintf( evText, "%s", txt );
  (void)sprintf( text, "%s should occur %d times", txt, occurrence );
  BteAssert_EQ( BteEventList_GetSize(), occurrence, text );
}


/**********************************************************************************************************************
  Name:         TscTest_AssertEventOccurrenceEQ2Data
  Parameter:    
  Return value: -
  Description:  
**********************************************************************************************************************/
static void TscTest_AssertEventOccurrenceEQ2Data( uint32 comp, uint32 code, uint32 data1, uint32 data2, 
                                            uint8 *txt, uint32 occurrence )
{
  TscTest_SetNewFilterEventEQ( comp, code, data1, data2, 0xFF, 0xFF, 0xFF, 0xFF );
  (void)sprintf( evText, "%s", txt );
  (void)sprintf( text, "%s should occur %d times with following data 0x%04X, 0x%04X", txt, occurrence, data1, data2);
  BteAssert_EQ( BteEventList_GetSize(), occurrence, text );
}

/**********************************************************************************************************************
  Name:         TscTest_AssertEventOccurrenceEQ3Data
  Parameter:    
  Return value: -
  Description:  
**********************************************************************************************************************/
static void TscTest_AssertEventOccurrenceEQ3Data( uint32 comp, uint32 code, uint32 data1, uint32 data2, uint32 data3, uint8 *txt, uint32 occurrence )
{
  TscTest_SetNewFilterEventEQ( comp, code, data1, data2, data3, 0xFF, 0xFF, 0xFF);
  (void)sprintf( evText, "%s", txt );
  (void)sprintf( text, "%s should occur %d times with following data 0x%04X, 0x%04X, 0x%04X", txt, occurrence, data1, data2, data3);
  BteAssert_EQ( BteEventList_GetSize(), occurrence, text );
}

/**********************************************************************************************************************
  Name:         TscTest_AssertEventOccurrenceEQ4Data
  Parameter:    
  Return value: -
  Description:  
**********************************************************************************************************************/
static void TscTest_AssertEventOccurrenceEQ4Data( uint32 comp, uint32 code, uint32 data1, uint32 data2, uint32 data3, uint32 data4, 
                                            uint8 *txt, uint32 occurrence )
{
  TscTest_SetNewFilterEventEQ( comp, code, data1, data2, data3, data4, 0xFF, 0xFF);
  (void)sprintf( evText, "%s", txt );
  (void)sprintf( text, "%s should occur %d times with following data 0x%04X, 0x%04X, 0x%04X, 0x%04X", txt, occurrence, data1, data2, data3, data4);
  BteAssert_EQ( BteEventList_GetSize(), occurrence, text );
}

/**********************************************************************************************************************
  Name:         TscTest_AssertEventOccurrenceEQ5Data
  Parameter:    
  Return value: -
  Description:  
**********************************************************************************************************************/
static void TscTest_AssertEventOccurrenceEQ5Data( uint32 comp, uint32 code, uint32 data1, uint32 data2, uint32 data3, uint32 data4, uint32 data5, 
                                            uint8 *txt, uint32 occurrence )
{
  TscTest_SetNewFilterEventEQ( comp, code, data1, data2, data3, data4, data5, 0xFF);
  (void)sprintf( evText, "%s", txt );
  (void)sprintf( text, "%s should occur %d times with following data 0x%04X, 0x%04X, 0x%04X, 0x%04X, 0x%04X", txt, occurrence, data1, data2, data3, data4, data5);
  BteAssert_EQ( BteEventList_GetSize(), occurrence, text );
}

/**********************************************************************************************************************
  Name:         TscTest_AssertEventOccurrenceEQ6Data
  Parameter:    
  Return value: -
  Description:  
**********************************************************************************************************************/
static void TscTest_AssertEventOccurrenceEQ6Data( uint32 comp, uint32 code, uint32 data1, uint32 data2, uint32 data3, uint32 data4, uint32 data5, uint32 dl,
                                            uint8 *txt, uint32 occurrence )
{
  TscTest_SetNewFilterEventEQ( comp, code, data1, data2, data3, data4, data5, dl);
  (void)sprintf( evText, "%s", txt );
  (void)sprintf( text, "%s should occur %d times", txt, occurrence );
  BteAssert_EQ( BteEventList_GetSize(), occurrence, text );
}


/* --- Test cases ---------------------------------------------------------------------------------------------------*/
/* due to the large amount of test cases, the prototypes are not listed here */

/* --- Test handling ------------------------------------------------------------------------------------------------*/
static void TscTest_Init( void );
static void TscTest_Cyclic1ms( void );
static void TscTest_CyclicCheck( void );
static uint16 TscTest_TestPlan( void );

/**********************************************************************************************************************
  Global function definitions
**********************************************************************************************************************/
/**********************************************************************************************************************
  Name:         main
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
int main( void )
{
  return (TscTest_TestPlan());
}


/**********************************************************************************************************************
  Callbacks
**********************************************************************************************************************/
/**********************************************************************************************************************
  Name:         ApplBteTestCase_Init
  Parameter:    ---
  Return value: ---
  Description:  
**********************************************************************************************************************/
void ApplBteTestCase_Init( void )
{
  /* initialize all stubs, TscAppl and TscTest */
/* __ORGANI_INCLUDE__ */
  TscAppl_Init();
  TscTest_Init();

  /* set initial event masks and specific controls for each Tsc module */
}

/**********************************************************************************************************************
  Name:         ApplBteTestCase_Cyclic1ms
  Parameter:    ---
  Return value: ---
  Description:  
**********************************************************************************************************************/
void ApplBteTestCase_Cyclic1ms( void )
{
  /*--- TestEnv_Stub ---*/
/* __ORGANI_INCLUDE__ */

  /*--- TestAppl ---*/
  TscAppl_Cyclic1ms();
  TscTest_Cyclic1ms();
}

/**********************************************************************************************************************
  Local function definitions
**********************************************************************************************************************/


/**********************************************************************************************************************
  Name:          TC_EmbeddedVersion
  Parameter:     
  Return value:  
  Description:   Report Versions and check expected values
**********************************************************************************************************************/
static void TC_EmbeddedVersion( void )
{
  BteReport_Write("<EmbeddedVersion name=\"Version of embedded components\">");
  BteReport_Write("<versionData name=\"Test Object\">");
//#error "Adapt to version defines of your component and remove the remaining Examples"
  //Examples:
  //CANbedded
  //BteReport_WriteVersion("Nm_DirOsek",NM_DIROSEK_VERSION>>8, NM_DIROSEK_VERSION&0xFF, NM_DIROSEK_RELEASE_VERSION);
  //BteReport_WriteVersion("Nm_DirOsek.dll",NM_DIROSEKDLL_VERSION>>8, NM_DIROSEKDLL_VERSION&0xFF, NM_DIROSEKDLL_RELEASE_VERSION);
  //AUTOSAR
  BteReport_WriteVersion("FrTrcv Software Version",FRTRCV_30_TJA1080_SW_MAJOR_VERSION, FRTRCV_30_TJA1080_SW_MINOR_VERSION, FRTRCV_30_TJA1080_SW_PATCH_VERSION);
  BteReport_WriteVersion("FrTrcv AUTOSAR Release",FRTRCV_30_TJA1080_AR_RELEASE_MAJOR_VERSION, FRTRCV_30_TJA1080_AR_RELEASE_MINOR_VERSION, FRTRCV_30_TJA1080_AR_RELEASE_REVISION_VERSION);
  //BteReport_WriteVersion("Tp_AsrTpFr.dll",TP_ASRTPFR_GENTOOL_GENY_MAJOR_VERSION, TP_ASRTPFR_GENTOOL_GENY_MINOR_VERSION, TP_ASRTPFR_GENTOOL_GENY_PATCH_VERSION);
  BteReport_Write("</versionData>");
  BteReport_Write("<versionData name=\"Test Data\">");
  BteReport_Write("</versionData>");
  BteReport_Write("<versionData name=\"Test Environment\">");
  BteReport_WriteVersion("TscAppl",TSCAPPL_VERSION>>8, TSCAPPL_VERSION&0xFF, TSCAPPL_RELEASE_VERSION);
/* __ORGANI_INCLUDE__ */
  BteReport_WriteVersion("TscTest",TSCTEST_VERSION>>8, TSCTEST_VERSION&0xFF, TSCTEST_RELEASE_VERSION  );
  BteReport_Write("</versionData>");
  BteReport_Write("</EmbeddedVersion>");

  /* Check expected configuration values */
  BteTestCase_SetState( BTETESTCASE_INIT );
  BteTestCase_SetData( TC_NAME, "TC_EmbeddedVersion");
  BteTestCase_SetData( TC_DESCRIPTION, "Check versions");

  /*-START--------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_PREPARE );

  /*-EXECUTE------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_EXECUTE );

  /*-ANALYSIS-----------------------------------*/
  BteTestCase_SetState( BTETESTCASE_ANALYSIS );

//#error "Adapt to version checks of your component and remove the remaining Examples"
  //Examples:
  /* Check ROM versions */
  /*BteAssert_EQ( FRTP_SW_MAJOR_VERSION, FrTp_MainVersion, "Version check error: ROM constants do not match with defined version numbers!");*/
  /*BteAssert_EQ( FRTP_SW_MINOR_VERSION, FrTp_SubVersion, "Version check error: ROM constants do not match with defined version numbers!");*/
  /*BteAssert_EQ( FRTP_SW_PATCH_VERSION, FrTp_ReleaseVersion, "Version check error: ROM constants do not match with defined version numbers!");*/
  /* Check for GENy BETA DLL Usage */
//  BteAssert_NEQ( DRVTRANS_TJA1080FRDIOASR_RELEASE_VERSION, 0xFF, "GENy DLL BETA Version Check" );

  /*-STOP---------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STOP );
}

/**********************************************************************************************************************
  Name:          TC_EmbeddedConfiguration
  Parameter:     
  Return value:  
  Description:   Report Embedded Configuration and check expected values
**********************************************************************************************************************/
static void TC_EmbeddedConfiguration( void )
{
  //sint8 error[100];

  BteReport_Write("<EmbeddedConfig name=\"Configuration of code\">");
//#error "Adapt to the configuration of your component and remove the remaining Examples"
  //Examples:
  BteReport_Write("<configGroup name=\"Number of Channels (Link-Time)\">");
  BteLog_WriteConfigValue("Number of FlexRay Channels", 1 );
  BteReport_Write("</configGroup>");  

  BteReport_Write("<configGroup name=\"Features and Options (Pre-Compile)\">");

#if (FRTRCV_30_TJA1080_VERSION_INFO_API == STD_ON)
  BteLog_WriteConfigValue("FRTRCV_30_TJA1080_VERSION_INFO_API STD_OFF", 1);
#else
  BteLog_WriteConfigValue("FRTRCV_30_TJA1080_VERSION_INFO_API STD_OFF", 0);
#endif
#if (FRTRCV_30_TJA1080_DEV_ERROR_DETECT == STD_ON)
  BteLog_WriteConfigValue("FRTRCV_30_TJA1080_DEV_ERROR_DETECT STD_OFF", 1);
#else
  BteLog_WriteConfigValue("FRTRCV_30_TJA1080_DEV_ERROR_DETECT STD_OFF", 0);
#endif
  BteReport_Write("</configGroup>");
  BteReport_Write("</EmbeddedConfig>");

  /* Check expected configuration values */
  BteTestCase_SetState( BTETESTCASE_INIT );
  BteTestCase_SetData( TC_NAME, "TC_EmbeddedConfiguration");
  BteTestCase_SetData( TC_DESCRIPTION, "Check Configuration");

  /*-START--------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_PREPARE );

  /*-EXECUTE------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_EXECUTE );

  /*-ANALYSIS-----------------------------------*/
  BteTestCase_SetState( BTETESTCASE_ANALYSIS );

  /*-STOP---------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STOP );
}

/*--- API -----------------------------------------------------------------------------------------------------------*/

/*--- FEATURES ------------------------------------------------------------------------------------------------------*/


/**********************************************************************************************************************
  Name:          Test_VersionInfoApi
  Parameter:     
  Return value:  
  Description:   Verify Version Information
**********************************************************************************************************************/
static void Test_VersionInfoApi()
{
#if ( FRTRCV_30_TJA1080_VERSION_INFO_API == STD_ON )
  Std_VersionInfoType versioninfo;
#endif

  /* Check expected configuration values */
  BteTestCase_SetState( BTETESTCASE_INIT );
  BteTestCase_SetData( TC_NAME, "Version Info API Tests");
  BteTestCase_SetData( TC_ID, "TCASE-25905");
  BteTestCase_SetData( TC_DESCRIPTION, "Check Version Info API");
  sprintf( text, "Channel = %d", 0 );
  BteTestCase_SetData( TC_PARAMETER, text );

  /*-START--------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_PREPARE );
  FrTrcv_30_Tja1080_InitMemory();
  FrTrcv_30_Tja1080_Init();
  sprintf( text, "DrvTrans_Init called; no return value.");
  BteReport_Write(text);

  /*-EXECUTE------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_EXECUTE );

  /* -------------------- TCASE25905 -------------------- */
  BteEventList_Clear();
  TscDet_EventMask_EnableAll();
  BteLog_EventMask_EnableAll( kTscAppl_CI );

#if ( FRTRCV_30_TJA1080_VERSION_INFO_API == STD_ON )
  FrTrcv_30_Tja1080_GetVersionInfo(&versioninfo); /* Call API to get version information */
  /* Assert that all version information is correct in its parameters and matches the component version information. */
  BteAssert_EQ( versioninfo.moduleID, FRTRCV_30_TJA1080_MODULE_ID, "TCASE25905: moduleID" );
  BteAssert_EQ( versioninfo.sw_major_version, FRTRCV_30_TJA1080_SW_MAJOR_VERSION, "TCASE25905: sw_major_version" );
  BteAssert_EQ( versioninfo.sw_minor_version, FRTRCV_30_TJA1080_SW_MINOR_VERSION, "TCASE25905: sw_minor_version" );
  BteAssert_EQ( versioninfo.sw_patch_version, FRTRCV_30_TJA1080_SW_PATCH_VERSION, "TCASE25905: sw_patch_version" );
  BteAssert_EQ( versioninfo.vendorID, FRTRCV_30_TJA1080_VENDOR_ID, "TCASE25905: vendorID" );
#else
  sprintf( text, "TCASE25905: VersionInfoAPI off, not tested.");
  BteReport_Write(text);
#endif
  /*-ANALYSIS-----------------------------------*/
  BteTestCase_SetState( BTETESTCASE_ANALYSIS );

  /*-STOP---------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STOP );
}
/* End of Test_VersionInfoApi */

/**********************************************************************************************************************
  Name:          Test_DET_343426
  Parameter:     
  Return value:  
  Description:   Verify Version Information
**********************************************************************************************************************/
static void Test_DET_343426()
{
# if ( FRTRCV_30_TJA1080_DEV_ERROR_DETECT == STD_ON )
  /* Check expected configuration values */
  BteTestCase_SetState( BTETESTCASE_INIT );
  BteTestCase_SetData( TC_NAME, "Verify DET check - FrTrcv_30_xxx_GetVersionInfo");
  BteTestCase_SetData( TC_ID, "TCASE-343426");
  BteTestCase_SetData( TC_DESCRIPTION, "");
  sprintf( text, "Channel = %d", 0 );
  BteTestCase_SetData( TC_PARAMETER, text );

  /*-START--------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_PREPARE );
  FrTrcv_30_Tja1080_InitMemory();
  FrTrcv_30_Tja1080_Init();
  sprintf( text, "DrvTrans_Init called; no return value.");
  BteReport_Write(text);

  /*-EXECUTE------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_EXECUTE );

  /* Emulate wakeup event */
  /* -------------------- TCASE25905 -------------------- */
  /* Verify that EcuM was called */
  BteEventList_Clear();
  TscDet_EventMask_EnableAll();
  BteLog_EventMask_EnableAll( kTscAppl_CI );

#if ( FRTRCV_30_TJA1080_VERSION_INFO_API == STD_ON )
  FrTrcv_30_Tja1080_GetVersionInfo( (Std_VersionInfoType*)NULL_PTR );
# if  ( FRTRCV_30_TJA1080_DEV_ERROR_REPORT == STD_ON )
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_GETVERSIONINFO, FRTRCV_30_TJA1080_E_FR_INVALID_POINTER, "TCASE-343426: NULLPTR DET of FrTrcv_30_Tja1080_GetVersionInfo", 1u );
# endif
#else
  sprintf( text, "TCASE25905: GetVersionInfo off, not tested.");
  BteReport_Write(text);
#endif
  /*-ANALYSIS-----------------------------------*/
  BteTestCase_SetState( BTETESTCASE_ANALYSIS );

  /*-STOP---------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STOP );
#endif
}
/* End of Test_DET_343426 */


/**********************************************************************************************************************
  Name:          Test_WakeUp
  Parameter:     
  Return value:  
  Description:   Verify Wake Up handling
**********************************************************************************************************************/
static void Test_WakeUp()
{ 
  FrTrcv_TrcvWUReasonType   FrTrcv_TrcvWUReason;
  FrTrcv_TrcvWUReasonType   FrTrcv_TrcvWUReasonCompare;

  /* Check expected configuration values */
  BteTestCase_SetState( BTETESTCASE_INIT );
  BteTestCase_SetData( TC_NAME, "Wake Up Tests");
  BteTestCase_SetData( TC_ID, "TCASE-18152");
  BteTestCase_SetData( TC_DESCRIPTION, "Check Wake Up");
  sprintf( text, "Channel = %d", 0 );
  BteTestCase_SetData( TC_PARAMETER, text );

  /*-START--------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_PREPARE );
  FrTrcv_30_Tja1080_InitMemory();
  FrTrcv_30_Tja1080_Init();
  sprintf( text, "DrvTrans_Init called; no return value.");
  BteReport_Write(text);

  /*-EXECUTE------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_EXECUTE );

  /* Emulate wakeup event */
  FrTrcv_30_Tja1080_Init();
  /* -------------------- TCASE18152 -------------------- */
  /* Verify that EcuM was called */
  BteEventList_Clear();
  TscDet_EventMask_EnableAll();
  BteLog_EventMask_EnableAll( kTscAppl_CI );

  /* Mode = STANDBY */
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_STANDBY);
  /* We first check for no wup happening */
  if( FRTRCV_WAKEUP_POLLING == FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByNodeUsedPolling )
  {
    FrTrcv_30_Tja1080_MainFunction();
    /* In case customer does call the CheckWakeUp... API which is allowed */
    FrTrcv_30_Tja1080_CheckWakeupByTransceiver(1);
  } else
  {
    FrTrcv_30_Tja1080_CheckWakeupByTransceiver(0);
    FrTrcv_30_Tja1080_CheckWakeupByTransceiver(1);
  }
  TscTest_AssertEventOccurrenceEQ1Data( kTscAppl_CI, kTscAppl_FrTrcv_EcuM_WUP, FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupSourceRef, "TCASE18152: 4. Assert that EcuM is not called", 0u );

  FrTrcv_30_Tja1080_GetTransceiverWUReason(0, &FrTrcv_TrcvWUReason);
  FrTrcv_TrcvWUReasonCompare = FRTRCV_WU_NOT_SUPPORTED;
  if( FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByBusUsed > 0u)
  {
    FrTrcv_TrcvWUReasonCompare = FRTRCV_WU_RESET;
  }
  BteAssert_EQ( FrTrcv_TrcvWUReason, FrTrcv_TrcvWUReasonCompare, "TCASE18152: 6. Assert wakeup reason to be FRTRCV_WU_RESET or FRTRCV_WU_NOT_SUPPORTED depending if wake up detection is enabled on channel" );

  /* Mode = STANDBY */
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_STANDBY);
  Dio_SetTransceiverStatusWord(0, 0, FRTRCV_30_TJA1080_REMOTEWAKEUP);
  if( FRTRCV_WAKEUP_POLLING == FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByNodeUsedPolling )
  {
    FrTrcv_30_Tja1080_MainFunction();
    /* In case customer does call the CheckWakeUp... API which is allowed */
    //FrTrcv_30_Tja1080_CheckWakeupByTransceiver(1);
  } else
  {
    FrTrcv_30_Tja1080_CheckWakeupByTransceiver(0);
  }
  FrTrcv_TrcvWUReasonCompare = FRTRCV_WU_NOT_SUPPORTED;
  if( FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByBusUsed > 0u )
  {
    TscTest_AssertEventOccurrenceEQ1Data( kTscAppl_CI, kTscAppl_FrTrcv_EcuM_WUP, FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupSourceRef, "TCASE18152: 10. Assert that EcuM is called with the configured WakeupSourceRef", 1u );
    FrTrcv_TrcvWUReasonCompare = FRTRCV_WU_BY_BUS;
  }
  FrTrcv_30_Tja1080_GetTransceiverWUReason(0, &FrTrcv_TrcvWUReason);
  BteAssert_EQ( FrTrcv_TrcvWUReason, FrTrcv_TrcvWUReasonCompare, "TCASE18152: 12. Assert wakeup reason to be FRTRCV_WU_BY_BUS or FRTRCV_WU_NOT_SUPPORTED depending if wake up detection is enabled on channel" );

  /* Transceiver muss in normal mode wechseln, danach wieder in sleep mode, damit der letzte status word vom remote wake up geloescht wird */
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_NORMAL);  

  /* Mode = SLEEP */
  BteEventList_Clear();  
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_SLEEP);
  Dio_SetTransceiverStatusWord(0, 1, FRTRCV_30_TJA1080_LOCALWAKEUP);
  if( FRTRCV_WAKEUP_POLLING == FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByNodeUsedPolling )
  {
    FrTrcv_30_Tja1080_MainFunction();
  } else
  {
    FrTrcv_30_Tja1080_CheckWakeupByTransceiver(0);
  }
  FrTrcv_TrcvWUReasonCompare = FRTRCV_WU_NOT_SUPPORTED;
  if( FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByBusUsed > 0u )
  {
    TscTest_AssertEventOccurrenceEQ1Data( kTscAppl_CI, kTscAppl_FrTrcv_EcuM_WUP, FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupSourceRef, "TCASE18152: 16. Assert that EcuM is called with the configured WakeupSourceRef", 1u );
    FrTrcv_TrcvWUReasonCompare = FRTRCV_WU_BY_PIN;
  }
  FrTrcv_30_Tja1080_GetTransceiverWUReason(0, &FrTrcv_TrcvWUReason);
  BteAssert_EQ( FrTrcv_TrcvWUReason, FrTrcv_TrcvWUReasonCompare, "TCASE18152: 18. Assert wakeup reason to be FRTRCV_WU_BY_PIN or FRTRCV_WU_NOT_SUPPORTED depending if wake up detection is enabled on channel" );

  /* -------------------- TCASE18152 -------------------- */
  FrTrcv_30_Tja1080_ClearTransceiverWakeup(0);
  FrTrcv_30_Tja1080_GetTransceiverWUReason(0, &FrTrcv_TrcvWUReason);
  BteAssert_EQ( FrTrcv_TrcvWUReason, FRTRCV_WU_RESET, "TCASE18152: 21. Assert wakeup reason to be FRTRCV_WU_RESET" );

  BteEventList_Clear();
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_NORMAL);
  FrTrcv_30_Tja1080_GetTransceiverWUReason(0, &FrTrcv_TrcvWUReason);
#if ( FRTRCV_30_TJA1080_WAKEUP_SUPPORT == STD_ON )
  FrTrcv_TrcvWUReasonCompare = FRTRCV_WU_INTERNALLY;
#else
  FrTrcv_TrcvWUReasonCompare = FRTRCV_WU_NOT_SUPPORTED;
#endif
  BteAssert_EQ( FrTrcv_TrcvWUReason, FrTrcv_TrcvWUReasonCompare, "TCASE18152: Assert wakeup reason to be FRTRCV_WU_INTERNALLY or FRTRCV_WU_NOT_SUPPORTED depending if wake up detection is enabled on channel" );


  /*-ANALYSIS-----------------------------------*/
  BteTestCase_SetState( BTETESTCASE_ANALYSIS );

  /*-STOP---------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STOP );
}
/* End of Test_WakeUp */


/**********************************************************************************************************************
  Name:          Test_WakeUpSleep
  Parameter:     
  Return value:  
  Description:   Verify Wake Up handling during Sleep transition
**********************************************************************************************************************/
static void Test_WakeUpSleep()
{ 
  FrTrcv_TrcvWUReasonType   FrTrcv_TrcvWUReason;
  FrTrcv_TrcvWUReasonType   FrTrcv_TrcvWUReasonCompare;

  /* Check expected configuration values */
  BteTestCase_SetState( BTETESTCASE_INIT );
  BteTestCase_SetData( TC_NAME, "Wake Up Tests during Sleep");
  BteTestCase_SetData( TC_ID, "TCASE-337526");
  BteTestCase_SetData( TC_DESCRIPTION, "Check Wake Up during Sleep transition");
  sprintf( text, "Channel = %d", 0 );
  BteTestCase_SetData( TC_PARAMETER, text );

  /*-START--------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_PREPARE );
  FrTrcv_30_Tja1080_InitMemory();
  FrTrcv_30_Tja1080_Init();
  sprintf( text, "DrvTrans_Init called; no return value.");
  BteReport_Write(text);

  /*-EXECUTE------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_EXECUTE );

  /* Emulate wakeup event */
  FrTrcv_30_Tja1080_Init();
  /* -------------------- TCASE-337526 -------------------- */
  /* Verify that EcuM was called */
  BteEventList_Clear();
  TscDet_EventMask_EnableAll();
  BteLog_EventMask_EnableAll( kTscAppl_CI );

  /* Mode = STANDBY */
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_STANDBY);
  TscTest_AssertEventOccurrenceEQ1Data( kTscAppl_CI, kTscAppl_FrTrcv_EcuM_WUP, FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupSourceRef, "TCASE-337526: 20. Assert that EcuM is not called", 0u );
  Dio_SetTransceiverStatusWord(0, 1, FRTRCV_30_TJA1080_REMOTEWAKEUP);
  /* Mode = SLEEP */
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_SLEEP);

  FrTrcv_TrcvWUReasonCompare = FRTRCV_WU_NOT_SUPPORTED;
  if( FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByBusUsed > 0u )
  {
    TscTest_AssertEventOccurrenceEQ1Data( kTscAppl_CI, kTscAppl_FrTrcv_EcuM_WUP, FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupSourceRef, "TCASE-337526: 50. Assert that EcuM is called with the configured WakeupSourceRef", 1u );
    FrTrcv_TrcvWUReasonCompare = FRTRCV_WU_BY_BUS;
  }
  FrTrcv_30_Tja1080_GetTransceiverWUReason(0, &FrTrcv_TrcvWUReason);
  BteAssert_EQ( FrTrcv_TrcvWUReason, FrTrcv_TrcvWUReasonCompare, "TCASE-337526: 70. Assert wakeup reason to be FRTRCV_WU_BY_BUS or FRTRCV_WU_NOT_SUPPORTED depending if wake up detection is enabled on channel" );

  /*-ANALYSIS-----------------------------------*/
  BteTestCase_SetState( BTETESTCASE_ANALYSIS );

  /*-STOP---------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STOP );
}
/* End of Test_WakeUp */


/**********************************************************************************************************************
  Name:          Test_ModeChange
  Parameter:     
  Return value:  
  Description:   Verify Mode Change handling
**********************************************************************************************************************/
static void Test_ModeChange()
{
  FrTrcv_TrcvModeType       FrTrcv_TrcvMode;
  Std_ReturnType            retVal;

  /* Check expected configuration values */
  BteTestCase_SetState( BTETESTCASE_INIT );
  BteTestCase_SetData( TC_NAME, "Mode Change Tests");
  BteTestCase_SetData( TC_ID, "TCASE-20997");
  BteTestCase_SetData( TC_DESCRIPTION, "Mode Change Tests");

  /*-START--------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_PREPARE );
  FrTrcv_30_Tja1080_InitMemory();
  FrTrcv_30_Tja1080_Init();
  sprintf( text, "DrvTrans_Init called; no return value." );
  BteReport_Write(text);

  /*-EXECUTE------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_EXECUTE );

  /* Emulate wakeup event */
  /* -------------------- TCASE20997 -------------------- */
  /* Initial mode change */
  FrTrcv_30_Tja1080_GetTransceiverMode(0, &FrTrcv_TrcvMode);
  BteAssert_EQ( FrTrcv_TrcvMode, FrTrcv_30_Tja1080_Config[0].FrTrcv_InitState, "TCASE20997: 30. Assert if configured initial mode is set" );

  /* -------------------- TCASE20997 -------------------- */
  /* #1 DSGN-FrTrcvCon1545 */
  ICU_disabled = 0; ICU_enabled = 0;
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_NORMAL);
  FrTrcv_30_Tja1080_GetTransceiverMode(0, &FrTrcv_TrcvMode);
  BteAssert_EQ( FrTrcv_TrcvMode, FRTRCV_TRCVMODE_NORMAL, "TCASE20997: #1 Assert if mode is default -> FRTRCV_TRCVMODE_NORMAL" );
#if ( FRTRCV_30_TJA1080_WUPINT_CBK == STD_ON )
  if( FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByNodeUsedPolling == FRTRCV_WAKEUP_INTERRUPT )
  {
    BteAssert_EQ( ICU_enabled, 0, "TCASE20997: ICU enabled" );
    BteAssert_EQ( ICU_disabled, 1, "TCASE20997: ICU disabled" );
  }
#endif
  /* #2 DSGN-FrTrcvCon1472 */
  ICU_disabled = 0; ICU_enabled = 0;
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_NORMAL);
  FrTrcv_30_Tja1080_GetTransceiverMode(0, &FrTrcv_TrcvMode);
  BteAssert_EQ( FrTrcv_TrcvMode, FRTRCV_TRCVMODE_NORMAL, "TCASE20997: #2 Assert if mode is FRTRCV_TRCVMODE_NORMAL -> FRTRCV_TRCVMODE_NORMAL" );
#if ( FRTRCV_30_TJA1080_WUPINT_CBK == STD_ON )
  if( FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByNodeUsedPolling == FRTRCV_WAKEUP_INTERRUPT )
  {
    BteAssert_EQ( ICU_enabled, 0, "TCASE20997: ICU enabled" );
    BteAssert_EQ( ICU_disabled, 1, "TCASE20997: ICU disabled" );
  }
#endif
  /* #3 DSGN-FrTrcvCon1468 */
  ICU_disabled = 0; ICU_enabled = 0;
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_RECEIVEONLY);
  FrTrcv_30_Tja1080_GetTransceiverMode(0, &FrTrcv_TrcvMode);
  BteAssert_EQ( FrTrcv_TrcvMode, FRTRCV_TRCVMODE_RECEIVEONLY, "TCASE20997: #3 Assert if mode is FRTRCV_TRCVMODE_NORMAL -> FRTRCV_TRCVMODE_RECEIVEONLY" );
#if ( FRTRCV_30_TJA1080_WUPINT_CBK == STD_ON )
  if( FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByNodeUsedPolling == FRTRCV_WAKEUP_INTERRUPT )
  {
    BteAssert_EQ( ICU_enabled, 0, "TCASE20997: ICU enabled" );
    BteAssert_EQ( ICU_disabled, 1, "TCASE20997: ICU disabled" );
  }
#endif
  /* #4 DSGN-FrTrcvCon1473 */
  ICU_disabled = 0; ICU_enabled = 0;
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_RECEIVEONLY);
  FrTrcv_30_Tja1080_GetTransceiverMode(0, &FrTrcv_TrcvMode);
  BteAssert_EQ( FrTrcv_TrcvMode, FRTRCV_TRCVMODE_RECEIVEONLY, "TCASE20997: #4 Assert if mode is FRTRCV_TRCVMODE_RECEIVE_ONLY -> FRTRCV_TRCVMODE_RECEIVEONLY" );
#if ( FRTRCV_30_TJA1080_WUPINT_CBK == STD_ON )
  if( FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByNodeUsedPolling == FRTRCV_WAKEUP_INTERRUPT )
  {
    BteAssert_EQ( ICU_enabled, 0, "TCASE20997: ICU enabled" );
    BteAssert_EQ( ICU_disabled, 1, "TCASE20997: ICU disabled" );
  }
#endif
  /* #5 DSGN-FrTrcvCon1467 */
  ICU_disabled = 0; ICU_enabled = 0;
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_STANDBY);
  FrTrcv_30_Tja1080_GetTransceiverMode(0, &FrTrcv_TrcvMode);
  BteAssert_EQ( FrTrcv_TrcvMode, FRTRCV_TRCVMODE_STANDBY, "TCASE20997: #5 Assert if mode is FRTRCV_TRCVMODE_RECEIVEONLY -> FRTRCV_TRCVMODE_STANDBY" );
#if ( FRTRCV_30_TJA1080_WUPINT_CBK == STD_ON )
  if( FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByNodeUsedPolling == FRTRCV_WAKEUP_INTERRUPT )
  {
    BteAssert_EQ( ICU_enabled, 1, "TCASE20997: ICU enabled" );
    BteAssert_EQ( ICU_disabled, 0, "TCASE20997: ICU disabled" );
  }
#endif
  /* #6 DSGN-FrTrcvCon1541 */
  ICU_disabled = 0; ICU_enabled = 0;
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_RECEIVEONLY);
  FrTrcv_30_Tja1080_GetTransceiverMode(0, &FrTrcv_TrcvMode);
  BteAssert_EQ( FrTrcv_TrcvMode, FRTRCV_TRCVMODE_RECEIVEONLY, "TCASE20997: #6 Assert if mode is FRTRCV_TRCVMODE_STANDBY -> FRTRCV_TRCVMODE_RECEIVEONLY" );
#if ( FRTRCV_30_TJA1080_WUPINT_CBK == STD_ON )
  if( FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByNodeUsedPolling == FRTRCV_WAKEUP_INTERRUPT )
  {
    BteAssert_EQ( ICU_enabled, 0, "TCASE20997: ICU enabled" );
    BteAssert_EQ( ICU_disabled, 1, "TCASE20997: ICU disabled" );
  }
#endif
  /* #7 DSGN-FrTrcvCon1471 */
  ICU_disabled = 0; ICU_enabled = 0;
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_SLEEP);
  FrTrcv_30_Tja1080_GetTransceiverMode(0, &FrTrcv_TrcvMode);
  BteAssert_EQ( FrTrcv_TrcvMode, FRTRCV_TRCVMODE_SLEEP, "TCASE20997: #7 Assert if mode is FRTRCV_TRCVMODE_RECEIVEONLY -> FRTRCV_TRCVMODE_SLEEP" );
#if ( FRTRCV_30_TJA1080_WUPINT_CBK == STD_ON )
  if( FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByNodeUsedPolling == FRTRCV_WAKEUP_INTERRUPT )
  {
    BteAssert_EQ( ICU_enabled, 1, "TCASE20997: ICU enabled" );
    BteAssert_EQ( ICU_disabled, 0, "TCASE20997: ICU disabled" );
  }
#endif
  /* #8 DSGN-FrTrcvCon1464 */
  ICU_disabled = 0; ICU_enabled = 0;
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_RECEIVEONLY);
  FrTrcv_30_Tja1080_GetTransceiverMode(0, &FrTrcv_TrcvMode);
  BteAssert_EQ( FrTrcv_TrcvMode, FRTRCV_TRCVMODE_RECEIVEONLY, "TCASE20997: #8 Assert if mode is FRTRCV_TRCVMODE_SLEEP -> FRTRCV_TRCVMODE_RECEIVEONLY" );
#if ( FRTRCV_30_TJA1080_WUPINT_CBK == STD_ON )
  if( FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByNodeUsedPolling == FRTRCV_WAKEUP_INTERRUPT )
  {
    BteAssert_EQ( ICU_enabled, 0, "TCASE20997: ICU enabled" );
    BteAssert_EQ( ICU_disabled, 1, "TCASE20997: ICU disabled" );
  }
#endif
  /* #9 DSGN-FrTrcvCon1469 */
  ICU_disabled = 0; ICU_enabled = 0;
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_NORMAL);
  FrTrcv_30_Tja1080_GetTransceiverMode(0, &FrTrcv_TrcvMode);
  BteAssert_EQ( FrTrcv_TrcvMode, FRTRCV_TRCVMODE_NORMAL, "TCASE20997: #9 Assert if mode is FRTRCV_TRCVMODE_RECEIVE_ONLY -> FRTRCV_TRCVMODE_NORMAL" );
#if ( FRTRCV_30_TJA1080_WUPINT_CBK == STD_ON )
  if( FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByNodeUsedPolling == FRTRCV_WAKEUP_INTERRUPT )
  {
    BteAssert_EQ( ICU_enabled, 0, "TCASE20997: ICU enabled" );
    BteAssert_EQ( ICU_disabled, 1, "TCASE20997: ICU disabled" );
  }
#endif
  /* #10 DSGN-FrTrcvCon1465 */
  ICU_disabled = 0; ICU_enabled = 0;
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_STANDBY);
  FrTrcv_30_Tja1080_GetTransceiverMode(0, &FrTrcv_TrcvMode);
  BteAssert_EQ( FrTrcv_TrcvMode, FRTRCV_TRCVMODE_STANDBY, "TCASE20997: #10 Assert if mode is FRTRCV_TRCVMODE_NORMAL -> FRTRCV_TRCVMODE_STANDBY" );
#if ( FRTRCV_30_TJA1080_WUPINT_CBK == STD_ON )
  if( FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByNodeUsedPolling == FRTRCV_WAKEUP_INTERRUPT )
  {
    BteAssert_EQ( ICU_enabled, 1, "TCASE20997: ICU enabled" );
    BteAssert_EQ( ICU_disabled, 0, "TCASE20997: ICU disabled" );
  }
#endif
  /* #11 DSGN-FrTrcvCon1475 */
  ICU_disabled = 0; ICU_enabled = 0;
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_STANDBY);
  FrTrcv_30_Tja1080_GetTransceiverMode(0, &FrTrcv_TrcvMode);
  BteAssert_EQ( FrTrcv_TrcvMode, FRTRCV_TRCVMODE_STANDBY, "TCASE20997: #11 Assert if mode is FRTRCV_TRCVMODE_STANDBY -> FRTRCV_TRCVMODE_STANDBY" );
#if ( FRTRCV_30_TJA1080_WUPINT_CBK == STD_ON )
  if( FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByNodeUsedPolling == FRTRCV_WAKEUP_INTERRUPT )
  {
    BteAssert_EQ( ICU_enabled, 1, "TCASE20997: ICU enabled" );
    BteAssert_EQ( ICU_disabled, 0, "TCASE20997: ICU disabled" );
  }
#endif
  /* #12 DSGN-FrTrcvCon1466 */
  ICU_disabled = 0; ICU_enabled = 0;
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_SLEEP);
  FrTrcv_30_Tja1080_GetTransceiverMode(0, &FrTrcv_TrcvMode);
  BteAssert_EQ( FrTrcv_TrcvMode, FRTRCV_TRCVMODE_SLEEP, "TCASE20997: #12 Assert if mode is FRTRCV_TRCVMODE_STANDBY -> FRTRCV_TRCVMODE_SLEEP" );
#if ( FRTRCV_30_TJA1080_WUPINT_CBK == STD_ON )
  if( FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByNodeUsedPolling == FRTRCV_WAKEUP_INTERRUPT )
  {
    BteAssert_EQ( ICU_enabled, 1, "TCASE20997: ICU enabled" );
    BteAssert_EQ( ICU_disabled, 0, "TCASE20997: ICU disabled" );
  }
#endif
  /* #13 DSGN-FrTrcvCon1544 */
  ICU_disabled = 0; ICU_enabled = 0;
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_STANDBY);
  FrTrcv_30_Tja1080_GetTransceiverMode(0, &FrTrcv_TrcvMode);
  BteAssert_EQ( FrTrcv_TrcvMode, FRTRCV_TRCVMODE_STANDBY, "TCASE20997: #13 Assert if mode is FRTRCV_TRCVMODE_SLEEP -> FRTRCV_TRCVMODE_STANDBY" );
#if ( FRTRCV_30_TJA1080_WUPINT_CBK == STD_ON )
  if( FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByNodeUsedPolling == FRTRCV_WAKEUP_INTERRUPT )
  {
    BteAssert_EQ( ICU_enabled, 1, "TCASE20997: ICU enabled" );
    BteAssert_EQ( ICU_disabled, 0, "TCASE20997: ICU disabled" );
  }
#endif
  /* #14 DSGN-FrTrcvCon1594 */
  ICU_disabled = 0; ICU_enabled = 0;
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_NORMAL);
  FrTrcv_30_Tja1080_GetTransceiverMode(0, &FrTrcv_TrcvMode);
  BteAssert_EQ( FrTrcv_TrcvMode, FRTRCV_TRCVMODE_NORMAL, "TCASE20997: #14 Assert if mode is FRTRCV_TRCVMODE_STANDBY -> FRTRCV_TRCVMODE_NORMAL" );
#if ( FRTRCV_30_TJA1080_WUPINT_CBK == STD_ON )
  if( FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByNodeUsedPolling == FRTRCV_WAKEUP_INTERRUPT )
  {
    BteAssert_EQ( ICU_enabled, 0, "TCASE20997: ICU enabled" );
    BteAssert_EQ( ICU_disabled, 1, "TCASE20997: ICU disabled" );
  }
#endif
  /* #15 DSGN-FrTrcvCon1470 */
  ICU_disabled = 0; ICU_enabled = 0;
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_SLEEP);
  FrTrcv_30_Tja1080_GetTransceiverMode(0, &FrTrcv_TrcvMode);
  BteAssert_EQ( FrTrcv_TrcvMode, FRTRCV_TRCVMODE_SLEEP, "TCASE20997: #15 Assert if mode is FRTRCV_TRCVMODE_NORMAL -> FRTRCV_TRCVMODE_SLEEP" );
#if ( FRTRCV_30_TJA1080_WUPINT_CBK == STD_ON )
  if( FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByNodeUsedPolling == FRTRCV_WAKEUP_INTERRUPT )
  {
    BteAssert_EQ( ICU_enabled, 1, "TCASE20997: ICU enabled" );
    BteAssert_EQ( ICU_disabled, 0, "TCASE20997: ICU disabled" );
  }
#endif
  /* #16 DSGN-FrTrcvCon1474 */
  ICU_disabled = 0; ICU_enabled = 0;
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_SLEEP);
  FrTrcv_30_Tja1080_GetTransceiverMode(0, &FrTrcv_TrcvMode);
  BteAssert_EQ( FrTrcv_TrcvMode, FRTRCV_TRCVMODE_SLEEP, "TCASE20997: #16 Assert if mode is FRTRCV_TRCVMODE_SLEEP -> FRTRCV_TRCVMODE_SLEEP" );
#if ( FRTRCV_30_TJA1080_WUPINT_CBK == STD_ON )
  if( FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByNodeUsedPolling == FRTRCV_WAKEUP_INTERRUPT )
  {
    BteAssert_EQ( ICU_enabled, 1, "TCASE20997: ICU enabled" );
    BteAssert_EQ( ICU_disabled, 0, "TCASE20997: ICU disabled" );
  }
#endif
  /* #17 DSGN-FrTrcvCon1463 */
  ICU_disabled = 0; ICU_enabled = 0;
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_NORMAL);
  FrTrcv_30_Tja1080_GetTransceiverMode(0, &FrTrcv_TrcvMode);
  BteAssert_EQ( FrTrcv_TrcvMode, FRTRCV_TRCVMODE_NORMAL, "TCASE20997: #17 Assert if mode is FRTRCV_TRCVMODE_SLEEP -> FRTRCV_TRCVMODE_NORMAL" );
#if ( FRTRCV_30_TJA1080_WUPINT_CBK == STD_ON )
  if( FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByNodeUsedPolling == FRTRCV_WAKEUP_INTERRUPT )
  {
    BteAssert_EQ( ICU_enabled, 0, "TCASE20997: ICU enabled" );
    BteAssert_EQ( ICU_disabled, 1, "TCASE20997: ICU disabled" );
  }
#endif

  /* We injected an error for FRTRCV_TRCVMODE_RECEIVEONLY therefore it should fail */
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_ILLEGAL);
  FrTrcv_30_Tja1080_GetTransceiverMode(0, &FrTrcv_TrcvMode);
  BteAssert_EQ( FrTrcv_TrcvMode, FRTRCV_TRCVMODE_NORMAL, "TCASE20997: Assert if mode is unchanged" );

  /* We call FrTrcv_30_Tja1080_Phy_SetMode with mode not zero based */
  retVal = FrTrcv_30_Tja1080_Phy_SetMode(0, FRTRCV_TRCVMODE_ILLEGAL);
  BteAssert_EQ( retVal, E_NOT_OK, "TCASE20997: Assert if E_NOT_OK is returned" );

  /*-ANALYSIS-----------------------------------*/
  BteTestCase_SetState( BTETESTCASE_ANALYSIS );

  /*-STOP---------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STOP );
}
/* End of Test_ModeChange */


/**********************************************************************************************************************
  Name:          Test_DET_18149
  Parameter:     
  Return value:  
  Description:   Verify API
**********************************************************************************************************************/
static void Test_DET_18149()
{
#if ( FRTRCV_30_TJA1080_DEV_ERROR_DETECT == STD_ON )
  uint32                    FrTrcv_BusErrorState;
  FrTrcv_TrcvWUReasonType   FrTrcv_TrcvWUReason;
  FrTrcv_TrcvModeType       FrTrcv_TrcvMode;
  Std_ReturnType            retVal;
#endif

  /* Check expected configuration values */
  BteTestCase_SetState( BTETESTCASE_INIT );
  BteTestCase_SetData( TC_NAME, "DET Tests");
  BteTestCase_SetData( TC_ID, "TCASE-18149");
  BteTestCase_SetData( TC_DESCRIPTION, "Check API -> DET");

  /*-START--------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_PREPARE );
  FrTrcv_30_Tja1080_InitMemory();
  FrTrcv_30_Tja1080_Init();
  sprintf( text, "DrvTrans_Init called; no return value.");
  BteReport_Write(text);

  /*-EXECUTE------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_EXECUTE );

  BteEventList_Clear();
  TscDet_EventMask_EnableAll();

  /* -------------------- TCASE18149 NoInit -------------------- */
  sprintf( text, "Call FrTrcv_InitMemory() to reset init state");
  BteReport_Write(text);
  /* DeInit */
  FrTrcv_30_Tja1080_InitMemory();

#if ( FRTRCV_30_TJA1080_DEV_ERROR_DETECT == STD_ON )
  /* -------------------- TCASE18149 SetTransceiverMode -------------------- */
  BteEventList_Clear();
  TscDet_EventMask_EnableAll();

  retVal = FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_NORMAL);
  BteAssert_EQ( retVal, E_NOT_OK, "TCASE18149: 2. Assert return value E_NOT_OK of FrTrcv_30_xxx_SetTransceiverMode" );
#if ( FRTRCV_30_TJA1080_DEV_ERROR_REPORT == STD_ON )
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_SETTRANSCEIVERMODE, FRTRCV_30_TJA1080_E_FR_UNINIT, "TCASE18149: Assert UNINIT DET error of FrTrcv_30_xxx_SetTransceiverMode", 1u );
#endif

  /* -------------------- TCASE18149 GetTransceiverMode -------------------- */
  retVal = FrTrcv_30_Tja1080_GetTransceiverMode(0, &FrTrcv_TrcvMode);
  BteAssert_EQ( retVal, E_NOT_OK, "TCASE18149: 4. Assert return value E_NOT_OK of FrTrcv_30_xxx_GetTransceiverMode" );
#if ( FRTRCV_30_TJA1080_DEV_ERROR_REPORT == STD_ON )
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_GETTRANSCEIVERMODE, FRTRCV_30_TJA1080_E_FR_UNINIT, "TCASE18149: Assert UNINIT DET error of FrTrcv_30_xxx_GetTransceiverMode", 1u );
#endif

  /* -------------------- TCASE18149 GetTransceiverWUReason -------------------- */
  retVal = FrTrcv_30_Tja1080_GetTransceiverWUReason(0, &FrTrcv_TrcvWUReason);
  BteAssert_EQ( retVal, E_NOT_OK, "TCASE18149: 6. Assert return value E_NOT_OK of FrTrcv_30_xxx_GetTransceiverWUReason" );
#if ( FRTRCV_30_TJA1080_DEV_ERROR_REPORT == STD_ON )
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_GETTRANSCEIVERWUREASON, FRTRCV_30_TJA1080_E_FR_UNINIT, "TCASE18149: Assert UNINIT DET error of FrTrcv_30_xxx_GetTransceiverWUReason", 1u );
#endif

  /* -------------------- TCASE18149 ClearTransceiverWakeup -------------------- */
  retVal = FrTrcv_30_Tja1080_ClearTransceiverWakeup(0);
  BteAssert_EQ( retVal, E_NOT_OK, "TCASE18149: 8. Assert return value E_NOT_OK of FrTrcv_30_xxx_ClearTransceiverWakeup" );
#if ( FRTRCV_30_TJA1080_DEV_ERROR_REPORT == STD_ON )
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_CLEARTRANSCEIVERWAKEUP, FRTRCV_30_TJA1080_E_FR_UNINIT, "TCASE18149: Assert UNINIT DET error of FrTrcv_30_xxx_ClearTransceiverWakeup", 1u );
#endif

  /* -------------------- TCASE18149 ClearTransceiverWakeup -------------------- */
  retVal = FrTrcv_30_Tja1080_GetTransceiverError(0, 0, &FrTrcv_BusErrorState);
  BteAssert_EQ( retVal, E_NOT_OK, "TCASE18149: 10. Assert return value E_NOT_OK of FrTrcv_30_xxx_GetTransceiverError" );
#if ( FRTRCV_30_TJA1080_DEV_ERROR_REPORT == STD_ON )
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_CLEARTRANSCEIVERWAKEUP, FRTRCV_30_TJA1080_E_FR_UNINIT, "TCASE18149: Assert UNINIT DET error of FrTrcv_30_xxx_GetTransceiverError", 1u );
#endif

  /* -------------------- TCASE18149 DisableTransceiverBranch -------------------- */
  retVal = FrTrcv_30_Tja1080_DisableTransceiverBranch(0, 0);
  BteAssert_EQ( retVal, E_NOT_OK, "TCASE18149: Assert return value E_NOT_OK of FrTrcv_30_xxx_DisableTransceiverBranch" );

  /* -------------------- TCASE18149 EnableTransceiverBranch -------------------- */
  retVal = FrTrcv_30_Tja1080_EnableTransceiverBranch(0, 0);
  /* Contrary to other APIs this one returns E_OK as it contains no code / no branches on Tja1080 */
  BteAssert_EQ( retVal, E_OK, "TCASE18149: Assert return value E_OK of FrTrcv_30_xxx_EnableTransceiverBranch" );
#endif

  /* -------------------- TCASE18149 CheckWakeupByTransceiver -------------------- */
  FrTrcv_30_Tja1080_CheckWakeupByTransceiver(0);
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_CHECKWAKEUPBYTRANSCEIVER, FRTRCV_30_TJA1080_E_FR_UNINIT, "TCASE18149: Assert no UNINT DET error of FrTrcv_30_xxx_CheckWakeupByTransceiver", 0u );

  /* -------------------- TCASE18149 FrTrcv_30_Tja1080_MainFunction -------------------- */
  FrTrcv_30_Tja1080_MainFunction();
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_MAINFUNCTION, FRTRCV_30_TJA1080_E_FR_UNINIT, "TCASE18149: Assert no UNINT DET error of FrTrcv_30_xxx_MainFunction", 0u );

  /* -------------------- TCASE18149 Init Other -------------------- */
  sprintf( text, "Call FrTrcv_Init() to initialize init state");
  BteReport_Write(text);
  /* Init */
  FrTrcv_30_Tja1080_Init();

  /* -------------------- TCASE18149 MainFunction -------------------- */
  /* No DET checks in MainFunction therefore no DET error expected here */
  FrTrcv_30_Tja1080_MainFunction();
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_MAINFUNCTION, FRTRCV_30_TJA1080_E_FR_UNINIT, "TCASE18149: Assert no UNINT DET error of FrTrcv_30_xxx_MainFunction", 0u );

  /*-ANALYSIS-----------------------------------*/
  BteTestCase_SetState( BTETESTCASE_ANALYSIS );

  /*-STOP---------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STOP );
}
/* End of Test_DET */


/**********************************************************************************************************************
  Name:          Test_DET_371379
  Parameter:     
  Return value:  
  Description:   Verify API
**********************************************************************************************************************/
static void Test_DET_371379()
{
  FrTrcv_TrcvModeType       FrTrcv_TrcvMode;
  Std_ReturnType            retVal;

  /* Check expected configuration values */
  BteTestCase_SetState( BTETESTCASE_INIT );
  BteTestCase_SetData( TC_NAME, "DET Tests");
  BteTestCase_SetData( TC_ID, "TCASE-371379");
  BteTestCase_SetData( TC_DESCRIPTION, "Check API -> DET");

  /*-START--------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_PREPARE );
  FrTrcv_30_Tja1080_InitMemory();
  FrTrcv_30_Tja1080_Init();
  sprintf( text, "DrvTrans_Init called; no return value.");
  BteReport_Write(text);

  /*-EXECUTE------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_EXECUTE );

  /* -------------------- TCASE-371379 GetTransceiverMode -------------------- */
  BteEventList_Clear();
  TscDet_EventMask_EnableAll();

  /* Gutfall */
  retVal = FrTrcv_30_Tja1080_GetTransceiverMode(0, &FrTrcv_TrcvMode);
  BteAssert_EQ( retVal, E_OK, "TCASE-371379: 3. Assert that E_OK is returned" );
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_GETTRANSCEIVERMODE, FRTRCV_30_TJA1080_E_FR_UNINIT, "TCASE-371379: 2. Assert that no DET is called", 0u );

#if ( FRTRCV_30_TJA1080_DEV_ERROR_DETECT == STD_ON )
  /* Invalid Trcv Idx */
# if( FRTRCV_30_TJA1080_API_OPTIMIZATION == STD_OFF )
  retVal = FrTrcv_30_Tja1080_GetTransceiverMode(2, &FrTrcv_TrcvMode);
  BteAssert_EQ( retVal, E_NOT_OK, "TCASE-371379: 6. Assert that E_NOT_OK is returned" );
#if ( FRTRCV_30_TJA1080_DEV_ERROR_REPORT == STD_ON )
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_GETTRANSCEIVERMODE, FRTRCV_30_TJA1080_E_FR_INVALID_TRCVIDX, "TCASE-371379: 5. Assert FRTRCV_30_xxx_E_FR_INVALID_TRCVIDX DET error", 1u );
#endif
# endif
  /* Null Ptr */
  BteEventList_Clear();
  retVal = FrTrcv_30_Tja1080_GetTransceiverMode(0, (FrTrcv_TrcvModeType*)NULL_PTR);
  BteAssert_EQ( retVal, E_NOT_OK, "TCASE-371379: 9. Assert that E_NOT_OK is returned" );
#if ( FRTRCV_30_TJA1080_DEV_ERROR_REPORT == STD_ON )
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_GETTRANSCEIVERMODE, FRTRCV_30_TJA1080_E_FR_INVALID_POINTER, "TCASE-371379: 8. Assert FRTRCV_30_xxx_E_FR_INVALID_POINTER DET error", 1u );
#endif
#endif

  /*-ANALYSIS-----------------------------------*/
  BteTestCase_SetState( BTETESTCASE_ANALYSIS );

  /*-STOP---------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STOP );
}
/* End of Test_DET */


/**********************************************************************************************************************
  Name:          Test_DET_333504
  Parameter:     
  Return value:  
  Description:   Verify API
**********************************************************************************************************************/
static void Test_DET_333504()
{
  Std_ReturnType            retVal;

  /* Check expected configuration values */
  BteTestCase_SetState( BTETESTCASE_INIT );
  BteTestCase_SetData( TC_NAME, "DET Tests");
  BteTestCase_SetData( TC_ID, "TCASE-333504");
  BteTestCase_SetData( TC_DESCRIPTION, "Check API -> DET");

  /*-START--------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_PREPARE );
  FrTrcv_30_Tja1080_InitMemory();
  FrTrcv_30_Tja1080_Init();
  sprintf( text, "DrvTrans_Init called; no return value.");
  BteReport_Write(text);

  /*-EXECUTE------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_EXECUTE );

  /* -------------------- TCASE333504 ClearTransceiverWakeup -------------------- */
  BteEventList_Clear();
  TscDet_EventMask_EnableAll();

  /* Gutfall */
  retVal = FrTrcv_30_Tja1080_ClearTransceiverWakeup(0);
  BteAssert_EQ( retVal, E_OK, "TCASE333504: 3. Assert that E_OK is returned" );
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_CLEARTRANSCEIVERWAKEUP, FRTRCV_30_TJA1080_E_FR_UNINIT, "TCASE333504: 2. Assert that no DET is called", 0u );

#if ( FRTRCV_30_TJA1080_DEV_ERROR_DETECT == STD_ON )
  /* Invalid Trcv Idx */
  BteEventList_Clear();
# if( FRTRCV_30_TJA1080_API_OPTIMIZATION == STD_OFF )
  retVal = FrTrcv_30_Tja1080_ClearTransceiverWakeup(2);
  BteAssert_EQ( retVal, E_NOT_OK, "TCASE333504: 6. Assert that E_NOT_OK is returned" );
#if ( FRTRCV_30_TJA1080_DEV_ERROR_REPORT == STD_ON )
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_CLEARTRANSCEIVERWAKEUP, FRTRCV_30_TJA1080_E_FR_INVALID_TRCVIDX, "TCASE333504: 5. Assert FRTRCV_30_xxx_E_FR_INVALID_TRCVIDX DET error", 1u );
#endif
# endif
#endif

  /*-ANALYSIS-----------------------------------*/
  BteTestCase_SetState( BTETESTCASE_ANALYSIS );

  /*-STOP---------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STOP );
}
/* End of Test_DET */


/**********************************************************************************************************************
  Name:          Test_DET_333505
  Parameter:     
  Return value:  
  Description:   Verify API
**********************************************************************************************************************/
static void Test_DET_333505()
{
  FrTrcv_TrcvWUReasonType   FrTrcv_TrcvWUReason;
  Std_ReturnType            retVal;

  /* Check expected configuration values */
  BteTestCase_SetState( BTETESTCASE_INIT );
  BteTestCase_SetData( TC_NAME, "DET Tests");
  BteTestCase_SetData( TC_ID, "TCASE-333505");
  BteTestCase_SetData( TC_DESCRIPTION, "Check API -> DET");

  /*-START--------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_PREPARE );
  FrTrcv_30_Tja1080_InitMemory();
  FrTrcv_30_Tja1080_Init();
  sprintf( text, "DrvTrans_Init called; no return value.");
  BteReport_Write(text);

  /*-EXECUTE------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_EXECUTE );

  /* -------------------- TCASE333505 GetTransceiverWUReason -------------------- */
  BteEventList_Clear();
  TscDet_EventMask_EnableAll();

  /* Gutfall */
  retVal = FrTrcv_30_Tja1080_GetTransceiverWUReason(0, &FrTrcv_TrcvWUReason);
  BteAssert_EQ( retVal, E_OK, "TCASE333505: 3. Assert that E_OK is returned" );
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_GETTRANSCEIVERWUREASON, FRTRCV_30_TJA1080_E_FR_UNINIT, "TCASE333505: 2. Assert that no DET is called", 0u );

#if ( FRTRCV_30_TJA1080_DEV_ERROR_DETECT == STD_ON )
  /* Invalid Trcv Idx */
# if( FRTRCV_30_TJA1080_API_OPTIMIZATION == STD_OFF )
  BteEventList_Clear();
  retVal = FrTrcv_30_Tja1080_GetTransceiverWUReason(2, &FrTrcv_TrcvWUReason);
  BteAssert_EQ( retVal, E_NOT_OK, "TCASE333505: 6. Assert that E_NOT_OK is returned" );
#if ( FRTRCV_30_TJA1080_DEV_ERROR_REPORT == STD_ON )
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_GETTRANSCEIVERWUREASON, FRTRCV_30_TJA1080_E_FR_INVALID_TRCVIDX, "TCASE333505: 5. Assert FRTRCV_30_xxx_E_FR_INVALID_TRCVIDX DET error", 1u );
#endif
# endif

  /* Null Ptr */
  BteEventList_Clear();
  retVal = FrTrcv_30_Tja1080_GetTransceiverWUReason(0, (FrTrcv_TrcvWUReasonType*)NULL_PTR);
  BteAssert_EQ( retVal, E_NOT_OK, "TCASE102520: 9. Assert that E_NOT_OK is returned" );
#if ( FRTRCV_30_TJA1080_DEV_ERROR_REPORT == STD_ON )
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_GETTRANSCEIVERWUREASON, FRTRCV_30_TJA1080_E_FR_INVALID_POINTER, "TCASE102520: 8. Assert FRTRCV_30_xxx_E_FR_INVALID_POINTER DET error", 1u );
#endif
#endif

  /*-ANALYSIS-----------------------------------*/
  BteTestCase_SetState( BTETESTCASE_ANALYSIS );

  /*-STOP---------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STOP );
}
/* End of Test_DET */


/**********************************************************************************************************************
  Name:          Test_DET_333506
  Parameter:     
  Return value:  
  Description:   Verify API
**********************************************************************************************************************/
static void Test_DET_333506()
{
  uint32                    FrTrcv_BusErrorState;
  Std_ReturnType            retVal;

  /* Check expected configuration values */
  BteTestCase_SetState( BTETESTCASE_INIT );
  BteTestCase_SetData( TC_NAME, "DET Tests");
  BteTestCase_SetData( TC_ID, "TCASE-333506");
  BteTestCase_SetData( TC_DESCRIPTION, "Check API -> DET");

  /*-START--------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_PREPARE );
  FrTrcv_30_Tja1080_InitMemory();
  FrTrcv_30_Tja1080_Init();
  sprintf( text, "DrvTrans_Init called; no return value.");
  BteReport_Write(text);

  /*-EXECUTE------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_EXECUTE );

  /* -------------------- TCASE333506 GetTransceiverError -------------------- */
  BteEventList_Clear();
  TscDet_EventMask_EnableAll();

  /* Gutfall */
  retVal = FrTrcv_30_Tja1080_GetTransceiverError(0, 0, &FrTrcv_BusErrorState);
  BteAssert_EQ( retVal, E_OK, "TCASE333506: 3. Assert that E_OK is returned" );
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_GETTRANSCEIVERERROR, FRTRCV_30_TJA1080_E_FR_UNINIT, "TCASE333506: 2. Assert that no DET is called", 0u );

#if ( FRTRCV_30_TJA1080_DEV_ERROR_DETECT == STD_ON )
  /* Invalid Trcv Idx */
# if( FRTRCV_30_TJA1080_API_OPTIMIZATION == STD_OFF )
  BteEventList_Clear();
  retVal = FrTrcv_30_Tja1080_GetTransceiverError(2, 0, &FrTrcv_BusErrorState);
  BteAssert_EQ( retVal, E_NOT_OK, "TCASE333506: 6. Assert that E_NOT_OK is returned" );
#if ( FRTRCV_30_TJA1080_DEV_ERROR_REPORT == STD_ON )
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_GETTRANSCEIVERERROR, FRTRCV_30_TJA1080_E_FR_INVALID_TRCVIDX, "TCASE333506: 5. Assert FRTRCV_30_xxx_E_FR_INVALID_TRCVIDX DET error", 1u );
#endif
# endif

  /* Null Ptr */
  BteEventList_Clear();
  retVal = FrTrcv_30_Tja1080_GetTransceiverError(0, 0, (uint32*)NULL_PTR);
  BteAssert_EQ( retVal, E_NOT_OK, "TCASE333506: 9. Assert that E_NOT_OK is returned" );
#if ( FRTRCV_30_TJA1080_DEV_ERROR_REPORT == STD_ON )
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_GETTRANSCEIVERERROR, FRTRCV_30_TJA1080_E_FR_INVALID_POINTER, "TCASE333506: NULLPTR DET of FrTrcv_30_Tja1080_GetTransceiverError", 1u );
#endif
#endif


  /*-ANALYSIS-----------------------------------*/
  BteTestCase_SetState( BTETESTCASE_ANALYSIS );

  /*-STOP---------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STOP );
}
/* End of Test_DET */


/**********************************************************************************************************************
  Name:          Test_DET_333507
  Parameter:     
  Return value:  
  Description:   Verify API
**********************************************************************************************************************/
static void Test_DET_333507()
{
  Std_ReturnType            retVal;

  /* Check expected configuration values */
  BteTestCase_SetState( BTETESTCASE_INIT );
  BteTestCase_SetData( TC_NAME, "DET Tests");
  BteTestCase_SetData( TC_ID, "TCASE-333507");
  BteTestCase_SetData( TC_DESCRIPTION, "Check API -> DET");

  /*-START--------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_PREPARE );
  FrTrcv_30_Tja1080_InitMemory();
  FrTrcv_30_Tja1080_Init();
  sprintf( text, "DrvTrans_Init called; no return value.");
  BteReport_Write(text);

  /*-EXECUTE------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_EXECUTE );

  /* -------------------- TCASE333507 SetTransceiverMode -------------------- */
  BteEventList_Clear();
  TscDet_EventMask_EnableAll();

  /* Gutfall */
  retVal = FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_NORMAL);
  BteAssert_EQ( retVal, E_OK, "TCASE333507: 3. Assert that E_OK is returned" );
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_SETTRANSCEIVERMODE, FRTRCV_30_TJA1080_E_FR_UNINIT, "TCASE333507: 2. Assert that no DET is called.", 0u );

#if ( FRTRCV_30_TJA1080_DEV_ERROR_DETECT == STD_ON )
  /* Invalid Trcv Idx */
# if( FRTRCV_30_TJA1080_API_OPTIMIZATION == STD_OFF )
  retVal = FrTrcv_30_Tja1080_SetTransceiverMode(2, FRTRCV_TRCVMODE_NORMAL);
  BteAssert_EQ( retVal, E_NOT_OK, "TCASE333507: 6. Assert that E_NOT_OK is returned" );
#if ( FRTRCV_30_TJA1080_DEV_ERROR_REPORT == STD_ON )
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_SETTRANSCEIVERMODE, FRTRCV_30_TJA1080_E_FR_INVALID_TRCVIDX, "TCASE333507: 5. Assert FRTRCV_30_xxx_E_FR_INVALID_TRCVIDX DET error", 1u );
#endif
# endif

  /* Invalid Mode */
  BteEventList_Clear();
  retVal = FrTrcv_30_Tja1080_SetTransceiverMode(0, 0xff);
  BteAssert_EQ( retVal, E_NOT_OK, "TCASE333507: 9. Assert that E_NOT_OK is returned" );
#if ( FRTRCV_30_TJA1080_DEV_ERROR_REPORT == STD_ON )
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_SETTRANSCEIVERMODE, FRTRCV_30_TJA1080_E_FR_NO_CONTROL_TRCV, "TCASE333507: 8. Assert FRTRCV_30_xxx_E_FR_NO_CONTROL_TRCV DET error", 1u );
#endif
#endif

  /*-ANALYSIS-----------------------------------*/
  BteTestCase_SetState( BTETESTCASE_ANALYSIS );

  /*-STOP---------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STOP );
}
/* End of Test_DET */



/**********************************************************************************************************************
  Name:          Test_DET_333508
  Parameter:     
  Return value:  
  Description:   Verify API
**********************************************************************************************************************/
static void Test_DET_333508()
{
  /* Check expected configuration values */
  BteTestCase_SetState( BTETESTCASE_INIT );
  BteTestCase_SetData( TC_NAME, "DET Tests");
  BteTestCase_SetData( TC_ID, "TCASE-333508");
  BteTestCase_SetData( TC_DESCRIPTION, "Check API -> DET");

  /*-START--------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_PREPARE );
  FrTrcv_30_Tja1080_InitMemory();
  FrTrcv_30_Tja1080_Init();
  sprintf( text, "DrvTrans_Init called; no return value.");
  BteReport_Write(text);

  /*-EXECUTE------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_EXECUTE );

  /* -------------------- TCASE333508 CheckWakeupByTransceiver -------------------- */
  BteEventList_Clear();
  TscDet_EventMask_EnableAll();

  /* Gutfall */
  FrTrcv_30_Tja1080_CheckWakeupByTransceiver(0);
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_CHECKWAKEUPBYTRANSCEIVER, FRTRCV_30_TJA1080_E_FR_UNINIT, "TCASE333508: 2. Assert that no DET is called", 0u );

  /* Invalid Trcv Idx */
  BteEventList_Clear();
  FrTrcv_30_Tja1080_CheckWakeupByTransceiver(2);
#if ( FRTRCV_30_TJA1080_DEV_ERROR_REPORT == STD_ON )
# if(( FRTRCV_30_TJA1080_API_OPTIMIZATION == STD_OFF ) && (FRTRCV_30_TJA1080_DEV_ERROR_DETECT == STD_ON) )
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_CHECKWAKEUPBYTRANSCEIVER, FRTRCV_30_TJA1080_E_FR_INVALID_TRCVIDX, "TCASE333508: 4. Assert FRTRCV_30_xxx_E_FR_INVALID_TRCVIDX DET error", 1u );
# else
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_CHECKWAKEUPBYTRANSCEIVER, FRTRCV_30_TJA1080_E_FR_INVALID_TRCVIDX, "TCASE333508: 4. Assert no FRTRCV_30_xxx_E_FR_INVALID_TRCVIDX DET error", 0u );
# endif
#endif

  /*-ANALYSIS-----------------------------------*/
  BteTestCase_SetState( BTETESTCASE_ANALYSIS );

  /*-STOP---------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STOP );
}
/* End of Test_DET */


/**********************************************************************************************************************
  Name:          Test_DET_333509
  Parameter:     
  Return value:  
  Description:   Verify API
**********************************************************************************************************************/
static void Test_DET_333509()
{
  Std_ReturnType            retVal;

  /* Check expected configuration values */
  BteTestCase_SetState( BTETESTCASE_INIT );
  BteTestCase_SetData( TC_NAME, "DET Tests");
  BteTestCase_SetData( TC_ID, "TCASE-333509");
  BteTestCase_SetData( TC_DESCRIPTION, "Check API -> DET");

  /*-START--------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_PREPARE );
  FrTrcv_30_Tja1080_InitMemory();
  FrTrcv_30_Tja1080_Init();
  sprintf( text, "DrvTrans_Init called; no return value.");
  BteReport_Write(text);

  /*-EXECUTE------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_EXECUTE );

  /* -------------------- TCASE333509 DisableTransceiverBranch -------------------- */
  retVal = FrTrcv_30_Tja1080_DisableTransceiverBranch(0, 0);
  BteAssert_EQ( retVal, E_NOT_OK, "TCASE333509: 10. Assert that E_NOT_OK is returned" );
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_DISABLETRANSCEIVERBRANCH, FRTRCV_30_TJA1080_E_FR_UNINIT, "TCASE333509: 2. Assert that no DET is called", 0u );

  /*-ANALYSIS-----------------------------------*/
  BteTestCase_SetState( BTETESTCASE_ANALYSIS );

  /*-STOP---------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STOP );
}
/* End of Test_DET */


/**********************************************************************************************************************
  Name:          Test_DET_333510
  Parameter:     
  Return value:  
  Description:   Verify API
**********************************************************************************************************************/
static void Test_DET_333510()
{
  Std_ReturnType            retVal;

  /* Check expected configuration values */
  BteTestCase_SetState( BTETESTCASE_INIT );
  BteTestCase_SetData( TC_NAME, "DET Tests");
  BteTestCase_SetData( TC_ID, "TCASE-333510");
  BteTestCase_SetData( TC_DESCRIPTION, "Check API -> DET");

  /*-START--------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_PREPARE );
  FrTrcv_30_Tja1080_InitMemory();
  FrTrcv_30_Tja1080_Init();
  sprintf( text, "DrvTrans_Init called; no return value.");
  BteReport_Write(text);

  /*-EXECUTE------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_EXECUTE );

  /* -------------------- TCASE333510 EnableTransceiverBranch -------------------- */
  retVal = FrTrcv_30_Tja1080_EnableTransceiverBranch(0, 0);
  BteAssert_EQ( retVal, E_OK, "TCASE333510: 3. Assert that E_OK is returned" );
  TscTest_AssertEventOccurrenceEQ4Data(kTscDet_CI, kTscDet_Det_ReportError, FRTRCV_30_TJA1080_MODULE_ID, 0, FRTRCV_30_TJA1080_SID_ENABLETRANSCEIVERBRANCH, FRTRCV_30_TJA1080_E_FR_UNINIT, "TCASE333510: 2. Assert that no DET is called", 0u );

  /*-ANALYSIS-----------------------------------*/
  BteTestCase_SetState( BTETESTCASE_ANALYSIS );

  /*-STOP---------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STOP );
}
/* End of Test_DET */




/**********************************************************************************************************************
  Name:          Test_Init
  Parameter:     
  Return value:  
  Description:   Verify API
**********************************************************************************************************************/
static void Test_Init()
{
  FrTrcv_TrcvModeType       FrTrcv_TrcvMode;
  FrTrcv_TrcvWUReasonType   FrTrcv_TrcvWUReason;
  FrTrcv_TrcvWUReasonType   FrTrcv_TrcvWUReasonCompare;

  /* Check expected configuration values */
  BteTestCase_SetState( BTETESTCASE_INIT );
  BteTestCase_SetData( TC_NAME, "Init Tests");
  BteTestCase_SetData( TC_ID, "TCASE-21004");
  BteTestCase_SetData( TC_DESCRIPTION, "Init Tests");

  /*-START--------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_PREPARE );
  FrTrcv_30_Tja1080_InitMemory();
  FrTrcv_30_Tja1080_Init();
  sprintf( text, "Trcv_Init called; no return value.");
  BteReport_Write(text);

  /*-EXECUTE------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_EXECUTE );

  /* -------------------- TCASE21004 -------------------- */
  BteEventList_Clear();
  TscDet_EventMask_EnableAll();
  BteLog_EventMask_EnableAll( kTscAppl_CI );

  /* Initial mode change */
  FrTrcv_30_Tja1080_GetTransceiverMode(0, &FrTrcv_TrcvMode);
  BteAssert_EQ( FrTrcv_TrcvMode, FrTrcv_30_Tja1080_Config[0].FrTrcv_InitState, "TCASE21004: 20. Assert if default mode after FrTrcv_30_xxx_Init is as configured" );

  /* Initial wake up */
  BteEventList_Clear();
  FrTrcv_30_Tja1080_InitMemory();
  Dio_SetTransceiverStatusWord(0, 0, FRTRCV_30_TJA1080_REMOTEWAKEUP);
  Dio_Init(); /* Simulate Mode after ECU Reset */
  FrTrcv_30_Tja1080_Init();
  FrTrcv_TrcvWUReasonCompare = FRTRCV_WU_NOT_SUPPORTED;
  if( FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByBusUsed > 0u)
  {
    TscTest_AssertEventOccurrenceEQ1Data( kTscAppl_CI, kTscAppl_FrTrcv_EcuM_WUP, FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupSourceRef, "TCASE21004: 50. Assert that EcuM is called with the configured WakeupSourceRef", 1u );
    FrTrcv_TrcvWUReasonCompare = FRTRCV_WU_BY_BUS;
  }

  FrTrcv_30_Tja1080_GetTransceiverWUReason(0, &FrTrcv_TrcvWUReason);
  BteAssert_EQ( FrTrcv_TrcvWUReason, FrTrcv_TrcvWUReasonCompare, "TCASE21004: 60. Assert wakeup reason to be FRTRCV_WU_BY_BUS or FRTRCV_WU_NOT_SUPPORTED depending if wake up detection is enabled on channel" );

  /*-ANALYSIS-----------------------------------*/
  BteTestCase_SetState( BTETESTCASE_ANALYSIS );

  /*-STOP---------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STOP );
}
/* End of Test_Init */


/**********************************************************************************************************************
  Name:          Test_DEM
  Parameter:     
  Return value:  
  Description:   Verify API
**********************************************************************************************************************/
static void Test_DEM()
{
  uint32 FrTrcv_BusErrorState;
  Std_ReturnType retVal;

  /* Check expected configuration values */
  BteTestCase_SetState( BTETESTCASE_INIT );
  BteTestCase_SetData( TC_NAME, "DEM/Diagnosis Tests");
  BteTestCase_SetData( TC_ID, "TCASE-20848");
  BteTestCase_SetData( TC_DESCRIPTION, "DEM/Diagnosis Tests");

  /*-START--------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_PREPARE );
  FrTrcv_30_Tja1080_InitMemory();
  FrTrcv_30_Tja1080_Init();
  enableDemError = 0;
  sprintf( text, "DrvTrans_Init called; no return value.");
  BteReport_Write(text);

  /*-EXECUTE------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_EXECUTE );

  /* -------------------- TCASE20848 -------------------- */
  BteEventList_Clear();
  TscDet_EventMask_EnableAll();
  BteLog_EventMask_EnableAll( kTscDem_CI );

  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_NORMAL);
  Dio_SetTransceiverStatusWord(0, 1, FRTRCV_30_TJA1080_BUSERROR);
  if (FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByNodeUsedPolling == FRTRCV_WAKEUP_POLLING)
  {
    FrTrcv_30_Tja1080_MainFunction();
  } else
  {
    FrTrcv_30_Tja1080_CheckWakeupByTransceiver(0);
  }
  TscTest_AssertEventOccurrenceEQ2Data(kTscDem_CI, kTscDet_Dem_ReportError, DemConf_DemEventParameter_AutoCreatedDemEvent_FrTrcvChannel_FRTRCV_E_FR_ERRN_TRCV, DEM_EVENT_STATUS_PREFAILED, "TCASE20848: 4. Assert that Dem_ReportErrorStatus is called with error code FRTRCV_E_FR_ERRN_TRCV with DEM_EVENT_STATUS_PREFAILED", 1u );

  retVal = FrTrcv_30_Tja1080_GetTransceiverError(0, 0, &FrTrcv_BusErrorState);
  BteAssert_EQ( FRTRCV_30_TJA1080_BDE_GLOBAL, (FrTrcv_BusErrorState & FRTRCV_30_TJA1080_BDE_GLOBAL), "TCASE20848: 6. Assert that FRTRCV_30_xxx_BDE_GLOBAL is set" );
  BteAssert_EQ( FRTRCV_30_TJA1080_BDE_NOISE, (FrTrcv_BusErrorState & FRTRCV_30_TJA1080_BDE_NOISE), "TCASE20848: 7. Assert that the error reason (e.g. FRTRCV_30_xxx_BDE_NOISE) is set" );
  BteAssert_EQ( retVal, E_OK, "TCASE20848: 8. Assert that the API returned E_OK" );

  BteEventList_Clear();
  if (FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupByNodeUsedPolling == FRTRCV_WAKEUP_POLLING)
  {
    FrTrcv_30_Tja1080_MainFunction();
  } else
  {
    FrTrcv_30_Tja1080_CheckWakeupByTransceiver(0);
  }

  TscTest_AssertEventOccurrenceEQ2Data(kTscDem_CI, kTscDet_Dem_ReportError, DemConf_DemEventParameter_AutoCreatedDemEvent_FrTrcvChannel_FRTRCV_E_FR_ERRN_TRCV, DEM_EVENT_STATUS_PREPASSED , "TCASE20848: 11. Assert that Dem_ReportErrorStatus is called with error code FRTRCV_E_FR_ERRN_TRCV with DEM_EVENT_STATUS_PREPASSED", 1u );

  /*-ANALYSIS-----------------------------------*/
  BteTestCase_SetState( BTETESTCASE_ANALYSIS );

  /*-STOP---------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STOP );
}
/* End of Test_DEM */


/**********************************************************************************************************************
  Name:          Test_BranchHandling
  Parameter:     
  Return value:  
  Description:   Verify API
**********************************************************************************************************************/
static void Test_BranchHandling()
{
  Std_ReturnType            retVal;

  /* Check expected configuration values */
  BteTestCase_SetState( BTETESTCASE_INIT );
  BteTestCase_SetData( TC_NAME, "Branch Handling");
  BteTestCase_SetData( TC_ID, "TCASE-18151");
  BteTestCase_SetData( TC_DESCRIPTION, "Branch Handling");

  /*-START--------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_PREPARE );
  FrTrcv_30_Tja1080_InitMemory();
  FrTrcv_30_Tja1080_Init();
  sprintf( text, "DrvTrans_Init called; no return value.");
  BteReport_Write(text);

  /*-EXECUTE------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_EXECUTE );

  /* -------------------- TCASE-18151 CheckWakeupByTransceiver -------------------- */
  BteEventList_Clear();
  TscDet_EventMask_EnableAll();

  /* Limitation according to TC - no action performed */
  retVal = FrTrcv_30_Tja1080_EnableTransceiverBranch(0, 0);
  BteAssert_EQ( retVal, E_OK, "TCASE-18151: perform no action" );
  retVal = FrTrcv_30_Tja1080_DisableTransceiverBranch(0, 0);
  BteAssert_EQ( retVal, E_NOT_OK, "TCASE-18151: perform no action" );

  /*-ANALYSIS-----------------------------------*/
  BteTestCase_SetState( BTETESTCASE_ANALYSIS );

  /*-STOP---------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STOP );
}
/* End of Test_BranchHandling */


/**********************************************************************************************************************
  Name:          Test_MultiChannel
  Parameter:     
  Return value:  
  Description:   Verify API
**********************************************************************************************************************/
extern CONST(Dem_EventIdType, FRTRCV_30_TJA1080_CONST) FrTrcv_30_Tja1080_DEM_E_BusError_Channel[];
static void Test_MultiChannel()
{
#if ( FRTRCV_30_TJA1080_MAX_NUM_OF_BTR_BUSSES > 1 )
  FrTrcv_TrcvWUReasonType   FrTrcv_TrcvWUReason;
  FrTrcv_TrcvWUReasonType   FrTrcv_TrcvWUReasonCompare;
  FrTrcv_TrcvModeType       FrTrcv_TrcvMode;
  Std_ReturnType            retVal;
  uint32                    FrTrcv_BusErrorState;

  /* Check expected configuration values */
  BteTestCase_SetState( BTETESTCASE_INIT );
  BteTestCase_SetData( TC_NAME, "Multi Channel");
  BteTestCase_SetData( TC_ID, "TCASE-363434");
  BteTestCase_SetData( TC_DESCRIPTION, "Multi Channel");

  /*-START--------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_PREPARE );
  FrTrcv_30_Tja1080_InitMemory();
  FrTrcv_30_Tja1080_Init();
  sprintf( text, "DrvTrans_Init called; no return value.");
  BteReport_Write(text);

  /*-EXECUTE------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_EXECUTE );

  /* -------------------- TCASE-363434 -------------------- */
  BteEventList_Clear();
  TscDet_EventMask_EnableAll();

  /* Set/GetMode */
  retVal = FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_NORMAL);
  retVal = FrTrcv_30_Tja1080_SetTransceiverMode(1, FRTRCV_TRCVMODE_STANDBY);

  BteAssert_EQ(Dio_ReadChannel(Dio_FrTrcv_EN_A), STD_HIGH, "TCASE-363434: Mode not NORMAL" );
  BteAssert_EQ(Dio_ReadChannel(Dio_FrTrcv_STBN_A), STD_HIGH, "TCASE-363434: Mode not NORMAL" );

  BteAssert_EQ(Dio_ReadChannel(Dio_FrTrcv_EN_B), STD_LOW, "TCASE-363434: Mode not STANDBY" );
  BteAssert_EQ(Dio_ReadChannel(Dio_FrTrcv_STBN_B), STD_LOW, "TCASE-363434: Mode not STANDBY" );

  retVal = FrTrcv_30_Tja1080_GetTransceiverMode(0, &FrTrcv_TrcvMode);
  BteAssert_EQ( FrTrcv_TrcvMode, FRTRCV_TRCVMODE_NORMAL, "TCASE-363434: Assert that FRTRCV_TRCVMODE_NORMAL" );

  /* Check Wakeup */
  BteEventList_Clear();
  BteLog_EventMask_EnableAll( kTscAppl_CI );
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_STANDBY);
  FrTrcv_30_Tja1080_ClearTransceiverWakeup(0);
  FrTrcv_30_Tja1080_ClearTransceiverWakeup(1);
  Dio_SetTransceiverStatusWord(1, 0, FRTRCV_30_TJA1080_REMOTEWAKEUP);
  FrTrcv_30_Tja1080_CheckWakeupByTransceiver(0);
  TscTest_AssertEventOccurrenceEQ1Data( kTscAppl_CI, kTscAppl_FrTrcv_EcuM_WUP, FrTrcv_30_Tja1080_Config[0].FrTrcv_WakeupSourceRef, "TCASE-363434: Assert that EcuM is not called", 0u );
  FrTrcv_30_Tja1080_CheckWakeupByTransceiver(1);
  if( FrTrcv_30_Tja1080_Config[1].FrTrcv_WakeupByBusUsed > 0u)
  {
    TscTest_AssertEventOccurrenceEQ1Data( kTscAppl_CI, kTscAppl_FrTrcv_EcuM_WUP, FrTrcv_30_Tja1080_Config[1].FrTrcv_WakeupSourceRef, "TCASE-363434: Assert that EcuM is called", 1u );
  } else
  {
    TscTest_AssertEventOccurrenceEQ1Data( kTscAppl_CI, kTscAppl_FrTrcv_EcuM_WUP, FrTrcv_30_Tja1080_Config[1].FrTrcv_WakeupSourceRef, "TCASE-363434: Assert that EcuM is not called", 0u );
  }

  FrTrcv_30_Tja1080_GetTransceiverWUReason(0, &FrTrcv_TrcvWUReason);
  FrTrcv_TrcvWUReasonCompare = FRTRCV_WU_RESET;
  BteAssert_EQ( FrTrcv_TrcvWUReason, FrTrcv_TrcvWUReasonCompare, "TCASE-363434: Assert wakeup reason to be FRTRCV_WU_RESET or FRTRCV_WU_NOT_SUPPORTED depending if wake up detection is enabled on channel" );

  FrTrcv_30_Tja1080_GetTransceiverWUReason(1, &FrTrcv_TrcvWUReason);
  FrTrcv_TrcvWUReasonCompare = FRTRCV_WU_RESET;
  if( FrTrcv_30_Tja1080_Config[1].FrTrcv_WakeupByBusUsed > 0u)
  {
    FrTrcv_TrcvWUReasonCompare = FRTRCV_WU_BY_BUS;
  }
  BteAssert_EQ( FrTrcv_TrcvWUReason, FrTrcv_TrcvWUReasonCompare, "TCASE-363434: Assert wakeup reason to be FRTRCV_WU_RESET or FRTRCV_WU_NOT_SUPPORTED depending if wake up detection is enabled on channel" );

  /* Check Error */
# if FRTRCV_30_TJA1080_PROD_ERROR_DETECT == STD_ON
  BteEventList_Clear();
  BteLog_EventMask_EnableAll( kTscDem_CI );
  FrTrcv_30_Tja1080_SetTransceiverMode(0, FRTRCV_TRCVMODE_NORMAL);
  FrTrcv_30_Tja1080_SetTransceiverMode(1, FRTRCV_TRCVMODE_NORMAL);
  Dio_SetTransceiverStatusWord(1, 1, FRTRCV_30_TJA1080_BUSERROR);
  FrTrcv_30_Tja1080_CheckWakeupByTransceiver(0);
  TscTest_AssertEventOccurrenceEQ2Data(kTscDem_CI, kTscDet_Dem_ReportError, FrTrcv_30_Tja1080_DEM_E_BusError_Channel[0], DEM_EVENT_STATUS_PREFAILED, "TCASE-363434: Assert that Dem_ReportErrorStatus is called with error code FRTRCV_E_FR_ERRN_TRCV with DEM_EVENT_STATUS_PREFAILED", 0u );
  FrTrcv_30_Tja1080_CheckWakeupByTransceiver(1);
  TscTest_AssertEventOccurrenceEQ2Data(kTscDem_CI, kTscDet_Dem_ReportError, FrTrcv_30_Tja1080_DEM_E_BusError_Channel[1], DEM_EVENT_STATUS_PREFAILED, "TCASE-363434: Assert that Dem_ReportErrorStatus is called with error code FRTRCV_E_FR_ERRN_TRCV with DEM_EVENT_STATUS_PREFAILED", 1u );

  retVal = FrTrcv_30_Tja1080_GetTransceiverError(0, 0, &FrTrcv_BusErrorState);
  BteAssert_EQ( 0, FrTrcv_BusErrorState, "TCASE-363434: Assert that no error flag is set" );
  retVal = FrTrcv_30_Tja1080_GetTransceiverError(1, 0, &FrTrcv_BusErrorState);
  BteAssert_EQ( FRTRCV_30_TJA1080_BDE_GLOBAL, (FrTrcv_BusErrorState & FRTRCV_30_TJA1080_BDE_GLOBAL), "TCASE-363434: Assert that FRTRCV_30_xxx_BDE_GLOBAL is set" );
  BteAssert_EQ( FRTRCV_30_TJA1080_BDE_NOISE, (FrTrcv_BusErrorState & FRTRCV_30_TJA1080_BDE_NOISE), "TCASE-363434: Assert that the error reason (e.g. FRTRCV_30_xxx_BDE_NOISE) is set" );
# endif

  /*-ANALYSIS-----------------------------------*/
  BteTestCase_SetState( BTETESTCASE_ANALYSIS );

  /*-STOP---------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STOP );
#endif
}
/* End of Test_MultiChannel */




/* --- Test handling ------------------------------------------------------------------------------------------------*/
/**********************************************************************************************************************
  Name:         TscTest_Init
  Parameter:    ---
  Return value: ---
  Description:  
**********************************************************************************************************************/
static void TscTest_Init( void )
{
}

/**********************************************************************************************************************
  Name:         TscTest_Cyclic1ms
  Parameter:    ---
  Return value: ---
  Description:  
**********************************************************************************************************************/
static void TscTest_Cyclic1ms( void )
{
  static taskCounter = 0;

  taskCounter++;
  if( taskCounter == 100 )
  {
    taskCounter = 0;
  }

  TscTest_CyclicCheck();
}

/**********************************************************************************************************************
  Name:         TscTest_CyclicCheck
  Parameter:    ---
  Return value: ---
  Description:  
**********************************************************************************************************************/
static void TscTest_CyclicCheck( void)
{
}

/**********************************************************************************************************************
  Name:         TscTest_TestPlan
  Parameter:    
  Return value: 
  Description:  
  Note          This function is put at the end of the file to avoid the declaration of the large number of static 
                functions.
**********************************************************************************************************************/
static uint16 TscTest_TestPlan( void )
{ 
#if defined(ARDUINO)  
  ArdTest_Init(TRCV_MODE,ARD_COMPORT);
#endif
  BteTestPlan_Start();
    BteTestGroup_Start( "Functional" );
      
      BteTestGroup_Start("VERSIONS");
        TC_EmbeddedVersion();
        TC_EmbeddedConfiguration();
      BteTestGroup_End();//VERSIONS
      
      BteTestGroup_Start("FEATURES");

      Test_VersionInfoApi();
      Test_DET_343426();
      Test_DET_18149();
      Test_DET_371379();
      Test_DET_333504();
      Test_DET_333505();
      Test_DET_333506();
      Test_DET_333507();
      Test_DET_333508();
      Test_DET_333509();
      Test_DET_333510();
      Test_Init();
      Test_BranchHandling();
      Test_MultiChannel();

#if ( FRTRCV_30_TJA1080_WAKEUP_SUPPORT == STD_ON )
        Test_WakeUp();
        Test_WakeUpSleep();
#endif
      Test_ModeChange();

#if ( FRTRCV_30_TJA1080_PROD_ERROR_DETECT == STD_ON ) && ( FRTRCV_30_TJA1080_TRCV_DIAGNOSIS == STD_ON )
        Test_DEM();
#endif

      BteTestGroup_End();//FEATURES

    BteTestGroup_End();//Functional

    BteTestGroup_Start("Metrics");
      //BteEventCallContextList_WriteReport("[TC:TBD.00]");
      //BteEventTimingList_WriteReport("[TC:TBD.00]");
    BteTestGroup_End();//Metrics

  BteTestPlan_End();
#if defined(ARDUINO)  
  ArdTest_Deinit();
#endif
  return( BteTestPlan_GetResult() );
}

/**********************************************************************************************************************
  EOF
**********************************************************************************************************************/
