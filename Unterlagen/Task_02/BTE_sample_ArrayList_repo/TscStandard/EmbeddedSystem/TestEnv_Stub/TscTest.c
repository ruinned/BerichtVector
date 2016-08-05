/***********************************************************************************************************************
COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
Copyright (c) 2011 by Vector Informatik GmbH.                                                  All rights reserved.

This software is copyright protected and proprietary to Vector Informatik GmbH.
Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
All other rights remain with Vector Informatik GmbH.
-----------------------------------------------------------------------------------------------------------------------
FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
File:  TscTest.c
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
visres       Samir Revelo            Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------------------------------------
Version   Date        Author  Change Id     Description
-----------------------------------------------------------------------------------------------------------------------
1.00.00   2016-06-20  visres                creation
***********************************************************************************************************************/

#define V_TSCTEST_SOURCE

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "TscTest.h"

/* stub modules */
#include "TscAppl.h"
//#include "TscPbData.h"
#include "TscDem.h"
#include "TscDet.h"
#include "TscEcuM.h"
#include "TscSchM.h"

/* test framework */
#include "BteLog.h"
#include "BteTestHandler.h"
#include "BteReport.h"

/* Hardware Includes */
#if defined ( USE_HARDWARE )
#include "stm32f4xx_hal.h"
#include "stm32f4_discovery.h"
#endif

#ifdef ECO_ACTIVE
#include "ECO.h"
#endif

/***********************************************************************************************************************
Version check
***********************************************************************************************************************/
#if ( TSCTEST_VERSION != 0x0201 )
# error "Header and Source file are inconsistent (version)!"
#endif
#if ( TSCTEST_RELEASE_VERSION != 0x00 )
# error "Header and Source file are inconsistent (release version)!"
#endif

#if defined(USE_PRINTF)
  uint8 text[100];
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

/***********************************************************************************************************************
Local data definitions (ROM)
***********************************************************************************************************************/

/***********************************************************************************************************************
Local function prototypes
***********************************************************************************************************************/
/* --- Helper functions ----------------------------------------------------------------------------------------------*/
/* --- Test cases ---------------------------------------------------------------------------------------------------*/
/* --- Test handling ------------------------------------------------------------------------------------------------*/
static void TscTest_Init( void );
static void TscTest_Cyclic1ms( void );
static uint16 TscTest_TestPlan( void );

/***********************************************************************************************************************
Global function definitions
***********************************************************************************************************************/
/***********************************************************************************************************************
Name:         main
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
int main( void )
{
  int rval;


#if defined ( USE_HARDWARE )
  ConfigSTM32F4();
#endif

#ifdef ECO_ACTIVE
  ECO_Init();
#endif

  rval = TscTest_TestPlan();

#ifdef ECO_ACTIVE
  ECO_PostProcessCoverage();
#endif

#if defined (USE_HARDWARE)
  /* Infinite loop */
  while (1)
  {
    BSP_LED_Toggle(LED4);
    HAL_Delay(1000);
 }
#endif

  return rval;
}

/***********************************************************************************************************************
Name:         ApplBteTestCase_Init
Parameter:    ---
Return value: ---
Description:  
***********************************************************************************************************************/
void ApplBteTestCase_Init( void )
{
  /* TestEnv_Common */
  TscAppl_Init();

  /* TestEnv_Stub */
  TscDem_Init();
  TscDet_Init();
  TscEcuM_Init();
  TscSchM_Init();
  TscTest_Init();
  /* __STUBCODE_MARKER__ */

  /* CUT */
  TscAppl_Mip_InitMemory();
  TscAppl_Mip_Init(0);
}

/***********************************************************************************************************************
Name:         ApplBteTestCase_Cyclic1ms
Parameter:    ---
Return value: ---
Description:  
***********************************************************************************************************************/
void ApplBteTestCase_Cyclic1ms( void )
{
  /* TestEnv_Common */
  TscAppl_Cyclic1ms();

  /* TestEnv_Stub */
  TscDem_Cyclic1ms();
  TscDet_Cyclic1ms();
  TscEcuM_Cyclic1ms();
  TscSchM_Cyclic1ms();
  TscTest_Cyclic1ms();
  /* __STUBCODE_MARKER__ */
}

/***********************************************************************************************************************
Local function definitions
***********************************************************************************************************************/
/*---------------------------------------------------------------------------------------------------------------------
Helper functions
---------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------
Configuration
---------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------
Test cases
---------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------
General
---------------------------------------------------------------------------------------------------------------------*/
#if defined (RUN_ON_PC)
void TC_Info_EmbeddedVersion( void )
{

  /* Check expected configuration values */
  BteTestCase_SetState( BTETESTCASE_INIT );
  BteTestCase_SetData( TC_NAME, "Version Information");

#if defined (USE_INTERNAL_LOG)
  BteTestCase_SetData_ID( 9 ); // Der Anwender soll diese Methode verwenden
#else
  BteTestCase_SetData( TC_ID, "[TC:Standard_Embedded.CheckVersion]");
#endif


  BteTestCase_SetData( TC_DESCRIPTION, "Check if the version info ROM constants and the version defines match. Check that no BETA version is used.");
  /*-START--------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STARTTESTCASE );
  BteReport_Write("<EmbeddedVersion name=\"Version of embedded components\">");
  BteLog_VersionGroup_Begin("Test Object");
  BteReport_WriteVersion("Mip",MIP_AR_RELEASE_MAJOR_VERSION, MIP_AR_RELEASE_MINOR_VERSION, MIP_AR_RELEASE_REVISION_VERSION);
  BteLog_VersionGroup_End();
  BteLog_VersionGroup_Begin("Test Data");
  BteLog_VersionGroup_End();
  BteLog_VersionGroup_Begin("Test Environment");
  BteReport_WriteVersion("TscDem",TSCDEM_MAJOR_VERSION, TSCDEM_MINOR_VERSION, TSCDEM_RELEASE_VERSION  ); 
  BteReport_WriteVersion("TscDet",TSCDET_MAJOR_VERSION, TSCDET_MINOR_VERSION, TSCDET_RELEASE_VERSION  ); 
  BteReport_WriteVersion("TscEcuM",TSCECUM_VERSION>>8, TSCECUM_VERSION&0xFF, TSCECUM_RELEASE_VERSION  ); 
  BteReport_WriteVersion("TscSchM",TSCSCHM_VERSION>>8, TSCSCHM_VERSION&0xFF, TSCSCHM_RELEASE_VERSION  ); 
  BteReport_WriteVersion("TscTest",TSCTEST_VERSION>>8, TSCTEST_VERSION&0xFF, TSCTEST_RELEASE_VERSION  ); 
  BteLog_VersionGroup_End();
  BteReport_Write("</EmbeddedVersion>");

  /*-EXECUTE------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STARTTESTLOG );
  BteTestCase_SetState( BTETESTCASE_EXECUTE );

  //BteAssert_EQ(Mip_MainVersion,MIP_AR_RELEASE_MAJOR_VERSION,"Main Version matches");
  //BteAssert_EQ(Mip_SubVersion,MIP_AR_RELEASE_MINOR_VERSION,"Sub Version matches");
  //BteAssert_EQ(Mip_ReleaseVersion,MIP_AR_RELEASE_REVISION_VERSION,"Release Version matches");
  BteAssert_NEQ(MIP_AR_RELEASE_REVISION_VERSION,0xFF,"No beta version");
  /*-STOP---------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STOP );

}
/*-------------------------------------------------------------------------------------------------------------------*/
void TC_Info_EmbeddedConfiguration( void )
{
  /* Check expected configuration values */
  BteTestCase_SetState( BTETESTCASE_INIT );
  BteTestCase_SetData( TC_NAME, "Valid Configuration Values");

#if defined (USE_INTERNAL_LOG)
  BteTestCase_SetData_ID( 8 ); // Der Anwender soll diese Methode verwenden
#else
  BteTestCase_SetData( TC_ID, "[TC:Standard_Embedded.CheckConfiguration]");
#endif


  BteTestCase_SetData( TC_DESCRIPTION, "Check if the feature switches are either enabled or disabled. Check that the parameter values are within the expected ranges.");

  /*-START--------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STARTTESTCASE );
  BteReport_Write("<EmbeddedConfig name=\"Configuration of code\">");
  BteLog_ConfigGroup_Begin("PreCompiler");

#if ( ISSM_DEV_ERROR_DETECT==STD_ON )

  BteLog_WriteConfig("ISSM_DEV_ERROR_DETECT","STD_ON");
#else
  BteLog_WriteConfig("ISSM_DEV_ERROR_DETECT","STD_OFF");
#endif
#if ( ISSM_CRC_CHECK==STD_ON )
  BteLog_WriteConfig("ISSM_CRC_CHECK","STD_ON");
#else
  BteLog_WriteConfig("ISSM_CRC_CHECK","STD_OFF");
#endif
  BteLog_ConfigGroup_End();

  BteReport_Write("</EmbeddedConfig>");
  /*-EXECUTE------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STARTTESTLOG );
  BteTestCase_SetState( BTETESTCASE_EXECUTE );


  /*-STOP---------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STOP );
}
#endif

static void TSEQ_Sample(void)
{

#if defined (USE_INTERNAL_LOG)
  BteTestSequence_BeginID(2); // Der Anwender soll diese Methode verwenden
  BteTestSequence_BeginID(3); // Der Anwender soll diese Methode verwenden
#else
  BteTestSequence_Begin("[TSEQ_Sample.001]");
  BteTestSequence_Begin("[TSEQ_Sample.002]");
#endif

  BteOk("Ok message");
  BteError("Error message");
  BteAssert_EQ( 24, 25, "A is equal B");
  BteAssert_NEQ( 24, 25, "A is not equal B");
  BteAssert_LE( 24, 25, "A is smaller than B");
  BteAssert_GE( 24, 25, "A is bigger than B");
  BteAssert_Range( 24, 20, 30, "A is in range");
  BteAssert_Tolerance( 24, 20, 10, "A is in tolerance");
  BteLog_Debug("Any message that can help to understand the event trace");
  BteTestSequence_End();

}

static void TSEQ_Sample1(void)
{

#if defined (USE_INTERNAL_LOG)
  BteTestSequence_BeginID(4); // Der Anwender soll diese Methode verwenden
#else
  BteTestSequence_Begin("[TCASE123a]");
#endif

  BteOk("Ok message");
  BteTestSequence_End();
}


/*---------------------------------------------------------------------------------------------------------------------
Test handling
---------------------------------------------------------------------------------------------------------------------*/
/***********************************************************************************************************************
Name:         TscTest_Init
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
static void TscTest_Init( void )
{
  //TscAppl_EventMask_DisableAll();
  //TscEcuM_EventMask_DisableAll();
  //TscDet_EventMask_DisableAll();
  //TscSchM_EventMask_DisableAll();
}

/***********************************************************************************************************************
Name:         TscTest_Cyclic1ms
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
static void TscTest_Cyclic1ms( void )
{
  /* Add your generic invariant tests here... (e.g. to cyclically check for consistency) */
}

/***********************************************************************************************************************
Name:         TSEQ_VersionRomData
Description:  
***********************************************************************************************************************/
static void TSEQ_VersionRomData( void )
{
}

/***********************************************************************************************************************
Name:         TSEQ_Mip_Init
Description:  
***********************************************************************************************************************/
static void TSEQ_Mip_Init( void )
{
  //uint32 originalGeneratorVersion;

#if defined (USE_INTERNAL_LOG)
  BteTestSequence_BeginID(5); // Der Anwender soll diese Methode verwenden
#else
  BteTestSequence_Begin("[TSEQ_Mip_Init.001]");
#endif

  TscEcuM_EventMask_Enable( kTscEcuM_GeneratorCompatibilityError );

#if defined ( MIP_USE_EXTENDED_ASR_VERSION_CHECK )
  BteEventFilter_Clear();
  BteEventFilter_Set( kBte_COMP, kBte_EQ, kTscEcuM_CI, 0x00 );
  BteEventFilter_Set( kBte_CODE, kBte_EQ, kTscEcuM_GeneratorCompatibilityError, 0x00 );
#else
  BteTestCase_NA("MIP_USE_EXTENDED_ASR_VERSION_CHECK not defined");
#endif
  BteTestSequence_End();
}

/***********************************************************************************************************************
Name:         TSEQ_Mip_GetVersionInfo
Description:  
***********************************************************************************************************************/
static void TSEQ_Mip_GetVersionInfo(void)
{
  Std_VersionInfoType versionInfo;

#if defined (USE_INTERNAL_LOG)
  BteTestSequence_BeginID(6); // Der Anwender soll diese Methode verwenden
#else
  BteTestSequence_Begin("[TSEQ_Mip_GetVersionInfo.001]");
#endif


  TscDet_EventMask_Enable( kTscDet_Det_ReportError );
  TscDet_SetDetAsError(0);
  BteLog_Debug("--- invalid parameter");
  TscAppl_Mip_GetVersionInfo(NULL_PTR);

  BteTestCase_NA("My Sample Justificatio");

  BteEventFilter_Clear();
  BteEventFilter_Set( kBte_COMP, kBte_EQ, kTscDet_CI, 0x00 );
  BteEventFilter_Set( kBte_CODE, kBte_EQ, kTscDet_Det_ReportError, 0x00 );
#if ( MIP_DEV_ERROR_DETECT == STD_ON )
  BteAssert_EQ( BteEventList_GetSize(), 1, "There is a DET entry");
  BteEventFilter_Set( kBte_DATA1, kBte_EQ, MIP_MODULE_ID>>8, 0x00 );
  BteEventFilter_Set( kBte_DATA2, kBte_EQ, MIP_MODULE_ID&0xFF, 0x00 );
  BteEventFilter_Set( kBte_DATA4, kBte_EQ, MIP_SID_GET_VERSION_INFO, 0x00 );
  BteEventFilter_Set( kBte_DATA5, kBte_EQ, MIP_E_PARAM_POINTER, 0x00 );
  BteAssert_EQ( BteEventList_GetSize(), 1, "There is a DET entry for MIP module for API for event");
#else
  BteAssert_EQ( BteEventList_GetSize(), 0, "There is no DET entry");
#endif

  BteLog_Debug("--- valid parameter");
  BteEventList_Clear();
  versionInfo.moduleID = 0xFFFF;
  versionInfo.sw_major_version = 0xFF;
  versionInfo.sw_minor_version = 0xFF;
  versionInfo.sw_patch_version = 0xFF;
  versionInfo.vendorID = 0xFF;

  TscAppl_Mip_GetVersionInfo(&versionInfo);

  BteEventFilter_Clear();
  BteEventFilter_Set( kBte_COMP, kBte_EQ, kTscDet_CI, 0x00 );
  BteEventFilter_Set( kBte_CODE, kBte_EQ, kTscDet_Det_ReportError, 0x00 );
  BteAssert_EQ( BteEventList_GetSize(), 0, "There is no DET entry");

  BteAssert_EQ(  versionInfo.moduleID, MIP_MODULE_ID, "moduleID");
  BteAssert_EQ(  versionInfo.sw_major_version, MIP_SW_MAJOR_VERSION, "sw_major_version");
  BteAssert_EQ(  versionInfo.sw_minor_version, MIP_SW_MINOR_VERSION, "sw_minor_version");
  BteAssert_EQ(  versionInfo.sw_patch_version, MIP_SW_PATCH_VERSION, "sw_patch_version");
  BteAssert_EQ(  versionInfo.vendorID, 30, "vendorID");

  BteTestSequence_End();
}

/***********************************************************************************************************************
Name:         TscTest_TestPlan
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void TC_Samir()
{
  Std_VersionInfoType ptr;

  BteTestCase_SetState( BTETESTCASE_INIT );
#if defined (USE_INTERNAL_LOG)
  BteTestCase_SetData_ID( 1 );
#else
  BteTestCase_SetData( TC_ID, "TCASE-1");
#endif
  BteTestCase_SetState( BTETESTCASE_STARTTESTCASE );
  BteTestCase_SetState( BTETESTCASE_STARTTESTLOG );

  TscDet_EventListMask_EnableAll();
  TscDet_EventLogMask_DisableAll();
  TscAppl_EventMask_EnableAll();
  BteLog_Debug("DebugMessage");
  BteOk("Ok message");
  BteWait(100);
  BteError("MyError");
  TscAppl_Mip_GetVersionInfo(((Std_VersionInfoType *)0));
  TscAppl_Mip_GetVersionInfo(&ptr);
  BteAssert_EQ(ptr.moduleID, 52428, "My Text");
  BteTestCase_SetState( BTETESTCASE_STOP );

#if defined LATER

#if defined (USE_INTERNAL_LOG)
  BteTestSequence_BeginID( 2 );
#else
  BteTestSequence_Begin( "TCASE-2" );
#endif


  TscDet_EventListMask_EnableAll();
  TscDet_EventLogMask_DisableAll();
  TscAppl_EventMask_EnableAll();
  BteLog_Debug("DebugMessage");
  BteOk("Ok message");
  BteWait(100);
  BteError("MyError");
  TscAppl_Mip_GetVersionInfo(((Std_VersionInfoType *)0));
  TscAppl_Mip_GetVersionInfo(&ptr);
  BteAssert_EQ(ptr.moduleID, 52428, "My Text");
  BteTestSequence_End();
#endif
}

/***********************************************************************************************************************
Name:         TscTest_TestPlan
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
static uint16 TscTest_TestPlan( void )
{
  int i;
  BteTest_Begin();
  for( i=0; i<1; i++ )
  {
#if defined ( USE_PRINTF )
    sprintf( text, "Variant %d", i );
#endif

#if defined (RUN_ON_PC)
    BteTestGroup_Start("General");
    TC_Info_EmbeddedVersion();
    TC_Info_EmbeddedConfiguration();
    BteTestGroup_End();
#endif

    //BteTestGroup_Start("Sample");
    //  TSEQ_Sample();
    //  TSEQ_Sample1();
    //BteTestGroup_End();

    //BteTestGroup_Start("Data");
    //  TSEQ_VersionRomData();
    //BteTestGroup_End();

    BteTestGroup_Start("API");
    TC_Samir();
    //TSEQ_Mip_Init();
    TSEQ_Mip_GetVersionInfo();
    BteTestGroup_End();

    //BteTestGroup_Start("Metrics");
    //BteEventCallContextList_WriteReport("[TC:Standard_Embedded.FunctionCallContext]");
    //BteEventTimingList_WriteReport("[TC:Standard_Embedded.FunctionRuntime]");
    //BteTestGroup_End();

  }
  BteTest_End();
  BteLogList_WriteToFile("test.bin");
  return( BteTest_GetResult() );
}



/***********************************************************************************************************************
EOF
***********************************************************************************************************************/


