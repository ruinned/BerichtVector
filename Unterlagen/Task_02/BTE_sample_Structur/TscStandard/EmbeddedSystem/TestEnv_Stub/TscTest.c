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
vismas       Markus Schwarz            Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------------------------------------
Version   Date        Author  Change Id     Description
-----------------------------------------------------------------------------------------------------------------------
1.00.00   2011-08-01  vismas                creation
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

uint8 text[100]; 


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

#ifdef ECO_ACTIVE
  ECO_Init();
#endif

  rval = TscTest_TestPlan();

#ifdef ECO_ACTIVE
  ECO_PostProcessCoverage();
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
void TC_Info_EmbeddedVersion( void )
{

  /* Check expected configuration values */
  BteTestCase_SetState( BTETESTCASE_INIT );
  //# if defined (USE_EXTERNAL_LOG)
  BteTestCase_SetData( TC_NAME, "Version Information");
  BteTestCase_SetData( TC_ID, "[TC:Standard_Embedded.CheckVersion]");
  BteTestCase_SetTestCaseID( 9 );   // neue Methode wurde hinzugefuegt!! Soll diese Zahl ausgegeben werden oder der obere Text?
  BteTestCase_SetData( TC_DESCRIPTION, "Check if the version info ROM constants and the version defines match. Check that no BETA version is used.");
  //#endif
  /*-START--------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STARTTESTCASE );
  //# if defined (USE_EXTERNAL_LOG)
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
  //#endif

  /*-EXECUTE------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STARTTESTLOG );
  BteTestCase_SetState( BTETESTCASE_EXECUTE );

  //BteAssert_EQ(Mip_MainVersion,MIP_AR_RELEASE_MAJOR_VERSION,"Main Version matches");
  //BteAssert_EQ(Mip_SubVersion,MIP_AR_RELEASE_MINOR_VERSION,"Sub Version matches");
  //BteAssert_EQ(Mip_ReleaseVersion,MIP_AR_RELEASE_REVISION_VERSION,"Release Version matches");
  //# if defined (USE_EXTERNAL_LOG)
  BteAssert_NEQ(MIP_AR_RELEASE_REVISION_VERSION,0xFF,"No beta version");
  //#endif
  /*-STOP---------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STOP );

}
/*-------------------------------------------------------------------------------------------------------------------*/
void TC_Info_EmbeddedConfiguration( void )
{
  /* Check expected configuration values */
  BteTestCase_SetState( BTETESTCASE_INIT );
  //# if defined (USE_EXTERNAL_LOG)
  BteTestCase_SetData( TC_NAME, "Valid Configuration Values");
  BteTestCase_SetData( TC_ID, "[TC:Standard_Embedded.CheckConfiguration]");
  BteTestCase_SetTestCaseID( 8 ); // neue Methode wurde hinzugefuegt!! Soll diese Zahl ausgegeben werden oder der obere Text?
  BteTestCase_SetData( TC_DESCRIPTION, "Check if the feature switches are either enabled or disabled. Check that the parameter values are within the expected ranges.");
  //#endif

  /*-START--------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STARTTESTCASE );
  //#if defined (USE_EXTERNAL_LOG)
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
  //#endif
  /*-EXECUTE------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STARTTESTLOG );
  BteTestCase_SetState( BTETESTCASE_EXECUTE );


  /*-STOP---------------------------------------*/
  BteTestCase_SetState( BTETESTCASE_STOP );
}







static void TSEQ_Sample(void)
{

  //BteTestSequence_Begin("[TSEQ_Sample.001]",2);
  BteTestSequence_BeginID(2); // Der Anwender soll diese Methode verwenden
  BteTestSequence_End();

  //BteTestSequence_Begin("[TSEQ_Sample.002]",3);
  BteTestSequence_BeginID(3); // Der Anwender soll diese Methode verwenden

  //# if defined (USE_EXTERNAL_LOG)
  BteOk("Ok message");
  BteError("Error message");
  BteAssert_EQ( 24, 25, "A is equal B");
  BteAssert_NEQ( 24, 25, "A is not equal B");
  BteAssert_LE( 24, 25, "A is smaller than B");
  BteAssert_GE( 24, 25, "A is bigger than B");
  BteAssert_Range( 24, 20, 30, "A is in range");
  BteAssert_Tolerance( 24, 20, 10, "A is in tolerance");
  BteLog_Debug("Any message that can help to understand the event trace");
  //#endif
  BteTestSequence_End();

}

static void TSEQ_Sample1(void)
{
  //# if defined (USE_EXTERNAL_LOG)
  //BteTestSequence_Begin("[TCASE123a]",4);
  BteTestSequence_BeginID(4); // Der Anwender soll diese Methode verwenden
  BteOk("Ok message");
  BteTestSequence_End();
  //#endif
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
  //# if defined (USE_EXTERNAL_LOG)
  //BteTestSequence_Begin("[TSEQ_Mip_Init.001]",5);
  BteTestSequence_BeginID(5); // Der Anwender soll diese Methode verwenden
  //#endif
  TscEcuM_EventMask_Enable( kTscEcuM_GeneratorCompatibilityError );

#if defined ( MIP_USE_EXTENDED_ASR_VERSION_CHECK )
  BteEventFilter_Clear();
  BteEventFilter_Set( kBte_COMP, kBte_EQ, kTscEcuM_CI, 0x00 );
  BteEventFilter_Set( kBte_CODE, kBte_EQ, kTscEcuM_GeneratorCompatibilityError, 0x00 );

  //originalGeneratorVersion = Mip_ConfigStruct.GeneratorCompatibilityVersion;

  ///* good case */
  //BteLog_Debug("--- using an identical version");
  //BteEventList_Clear();
  //TscAppl_Mip_Init(0);
  //BteAssert_EQ( BteEventList_GetSize(), 0, "occurence(EcuM_GeneratorCompatibilityError())==0" );

  ///* bad case */
  //BteLog_Debug("--- using a lower main version");
  //BteEventList_Clear();
  //Mip_ConfigStruct.GeneratorCompatibilityVersion = originalGeneratorVersion - 0x010000;
  //TscAppl_Mip_Init(&Mip_ConfigStruct);
  //BteAssert_EQ( BteEventList_GetSize(), 1, "occurence(EcuM_GeneratorCompatibilityError())==1" );

  //BteLog_Debug("--- using a higher main version");
  //BteEventList_Clear();
  //Mip_ConfigStruct.GeneratorCompatibilityVersion = originalGeneratorVersion + 0x010000;
  //TscAppl_Mip_Init(&Mip_ConfigStruct);
  //BteAssert_EQ( BteEventList_GetSize(), 1, "occurence(EcuM_GeneratorCompatibilityError())==1" );

  //BteLog_Debug("--- using a lower sub version");
  //BteEventList_Clear();
  //Mip_ConfigStruct.GeneratorCompatibilityVersion = originalGeneratorVersion - 0x000100;
  //TscAppl_Mip_Init(&Mip_ConfigStruct);
  //BteAssert_EQ( BteEventList_GetSize(), 1, "occurence(EcuM_GeneratorCompatibilityError())==1" );

  //BteLog_Debug("--- using a higher sub version");
  //BteEventList_Clear();
  //Mip_ConfigStruct.GeneratorCompatibilityVersion = originalGeneratorVersion + 0x000100;
  //TscAppl_Mip_Init(&Mip_ConfigStruct);
  //BteAssert_EQ( BteEventList_GetSize(), 1, "occurence(EcuM_GeneratorCompatibilityError())==1" );

  //BteLog_Debug("--- using a lower release version");
  //BteEventList_Clear();
  //Mip_ConfigStruct.GeneratorCompatibilityVersion = originalGeneratorVersion - 0x000001;
  //TscAppl_Mip_Init(&Mip_ConfigStruct);
  //BteAssert_EQ( BteEventList_GetSize(), 1, "occurence(EcuM_GeneratorCompatibilityError())==1" );

  //BteLog_Debug("--- using a higher release version");
  //BteEventList_Clear();
  //Mip_ConfigStruct.GeneratorCompatibilityVersion = originalGeneratorVersion + 0x000001;
  //TscAppl_Mip_Init(&Mip_ConfigStruct);
  //if( (originalGeneratorVersion & 0x000000FF) != 0x000000FF )
  //{
  //  BteAssert_EQ( BteEventList_GetSize(), 0, "occurence(EcuM_GeneratorCompatibilityError())==0" );
  //}
  //else
  //{
  //  BteAssert_EQ( BteEventList_GetSize(), 1, "occurence(EcuM_GeneratorCompatibilityError())==1" );
  //}

  //  Mip_ConfigStruct.GeneratorCompatibilityVersion = originalGeneratorVersion;
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

  //# if defined (USE_EXTERNAL_LOG)
  BteTestCase_SetData( TC_PARAMETER, text );

  //BteTestSequence_Begin("[TSEQ_Mip_GetVersionInfo.001]",6);
  BteTestSequence_BeginID(6); // Der Anwender soll diese Methode verwenden
  //#endif
  TscDet_EventMask_Enable( kTscDet_Det_ReportError );
  TscDet_SetDetAsError(0);
  //# if defined (USE_EXTERNAL_LOG)
  BteLog_Debug("--- invalid parameter");
  //#endif
  TscAppl_Mip_GetVersionInfo(NULL_PTR);

  BteTestCase_NA("My Sample Justificatio");

  BteEventFilter_Clear();
  BteEventFilter_Set( kBte_COMP, kBte_EQ, kTscDet_CI, 0x00 );
  BteEventFilter_Set( kBte_CODE, kBte_EQ, kTscDet_Det_ReportError, 0x00 );
# if ( MIP_DEV_ERROR_DETECT == STD_ON )
  //# if defined (USE_EXTERNAL_LOG)
  BteAssert_EQ( BteEventList_GetSize(), 1, "There is a DET entry");
  //#endif
  BteEventFilter_Set( kBte_DATA1, kBte_EQ, MIP_MODULE_ID>>8, 0x00 );
  BteEventFilter_Set( kBte_DATA2, kBte_EQ, MIP_MODULE_ID&0xFF, 0x00 );
  BteEventFilter_Set( kBte_DATA4, kBte_EQ, MIP_SID_GET_VERSION_INFO, 0x00 );
  BteEventFilter_Set( kBte_DATA5, kBte_EQ, MIP_E_PARAM_POINTER, 0x00 );
  BteAssert_EQ( BteEventList_GetSize(), 1, "There is a DET entry for MIP module for API for event");
#else
  BteAssert_EQ( BteEventList_GetSize(), 0, "There is no DET entry");
#endif

  //# if defined (USE_EXTERNAL_LOG)
  BteLog_Debug("--- valid parameter");
  //#endif
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
  //# if defined (USE_EXTERNAL_LOG)
  BteAssert_EQ( BteEventList_GetSize(), 0, "There is no DET entry");

  BteAssert_EQ(  versionInfo.moduleID, MIP_MODULE_ID, "moduleID");
  BteAssert_EQ(  versionInfo.sw_major_version, MIP_SW_MAJOR_VERSION, "sw_major_version");
  BteAssert_EQ(  versionInfo.sw_minor_version, MIP_SW_MINOR_VERSION, "sw_minor_version");
  BteAssert_EQ(  versionInfo.sw_patch_version, MIP_SW_PATCH_VERSION, "sw_patch_version");
  BteAssert_EQ(  versionInfo.vendorID, 30, "vendorID");
  //#endif

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
  BteTestSequence_BeginID(7);

  TscDet_EventListMask_EnableAll();
  TscDet_EventLogMask_DisableAll();
  TscAppl_EventMask_EnableAll();
  //#if defined (USE_EXTERNAL_LOG)
  BteLog_Debug("DebugMessage");
  BteOk("Ok message");
  BteWait(100);
  BteError("MyError");
  //#endif
  TscAppl_Mip_GetVersionInfo(((Std_VersionInfoType *)0));
  TscAppl_Mip_GetVersionInfo(&ptr);
  //#if defined (USE_EXTERNAL_LOG)
  BteAssert_EQ(ptr.moduleID, 52428, "My Text");
  //#endif
  BteTestSequence_End();
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
    sprintf( text, "Variant %d", i );

    BteTestGroup_Start("General");
    TC_Info_EmbeddedVersion();
    TC_Info_EmbeddedConfiguration();
    BteTestGroup_End();

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
    //TSEQ_Mip_GetVersionInfo();
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


//#define kTscApplCheckConsistency 0x01

//BteTestHandler_BackgroundTest_Init(kTscApplCheckConsistency,"[TCASE0123]");
//BteTestHandler_BackgroundTest_Set(kTscApplCheckConsistency,0);
//BteTestHandler_BackgroundTest_Set(kTscApplCheckConsistency,0);
//BteTestHandler_BackgroundTest_Set(kTscApplCheckConsistency,0);
//BteTestHandler_BackgroundTest_Set(kTscApplCheckConsistency,0);
//BteTestHandler_BackgroundTest_Set(kTscApplCheckConsistency,1);


/*
BteTestSequence_Begin("TC_VersionRomData_001");
BteTCASE_Begin("[TCASE00003]");
BteAssert_EQ(E_OK,    0,    "");
BteAssert_EQ(E_NOT_OK,     1,  "");
BteTCASE_End();
BteTestSequence_End();



void TCASE_01102( void )
{
BteTestSequence_Begin("[TCASE01102]");
BteTCASE_Begin("TCASE01102");
BteAssert_EQ(Mip_MainVersion,    V_MIPPROJECT_VERSION >> 8,    "Main Version is ok");
BteAssert_EQ(Mip_SubVersion,     V_MIPPROJECT_VERSION & 0xFF,  "Sub Version is ok");
BteAssert_EQ(Mip_ReleaseVersion, V_MIPPROJECT_RELEASE_VERSION, "Release Version is ok");
BteTCASE_End();
BteTestSequence_End();

BteTestSequence_Begin("[TCASE01103]");
BteTCASE_Begin("TCASE01102");
BteAssert_EQ(Mip_MainVersion,    V_MIPPROJECT_VERSION >> 8,    "Main Version is ok");
BteAssert_EQ(Mip_SubVersion,     V_MIPPROJECT_VERSION & 0xFF,  "Sub Version is ok");
BteAssert_EQ(Mip_ReleaseVersion, V_MIPPROJECT_RELEASE_VERSION, "Release Version is ok");
BteTCASE_End();
BteTestSequence_End();
}

*/





///*-------------------------------------------------------------------------------------------------------------------*/
//uint8 TC_API_Issm_Init_003( void )
//{
//  uint8 rval;
//
//  BteTestCase_SetState( BTETESTCASE_INIT );
//  BteTestCase_SetData( TC_NAME, "TC_API_Issm_Init_003");
//  BteTestCase_SetData( TC_ID, "[TC:ISSM_0059.00]");
//  BteTestCase_SetData( TC_DESCRIPTION, "Check if configurations are compatible");
//  /*-START--------------------------------------*/
//  BteTestCase_SetState( BTETESTCASE_PREPARE );
//  /*-EXECUTE------------------------------------*/
//  BteTestCase_SetState( BTETESTCASE_EXECUTE );
//#if ( ISSM_CRC_CHECK == STD_ON )
//#if (ISSM_CONFIG_VARIANT == 3)
//  if((tscTest_CurrentPbConfig->Issm_PrecompileCRC == ISSM_PRECOMPILE_CRC) && 
//     (tscTest_CurrentPbConfig->Issm_LinktimeCRC == Issm_LinktimeCRC) )
//#else
//  if((Issm_Configuration.Issm_PrecompileCRC == ISSM_PRECOMPILE_CRC) && 
//     (Issm_Configuration.Issm_LinktimeCRC == Issm_LinktimeCRC) )
//#endif
//  {
//    rval = 0;
//  }
//  else
//  {
//    rval = 1;
//    if(Issm_Configuration.Issm_PrecompileCRC == ISSM_PRECOMPILE_CRC) 
//    {
//      BteError("Issm_PrecompileCRC does not match");
//    }
//    if(Issm_Configuration.Issm_LinktimeCRC == Issm_LinktimeCRC) 
//    {
//      BteError("Issm_LinktimeCRC does not match");
//    }
//  }
//#else
//  BteTestCase_NA("CRC not enabled");
//#endif
//  /*-STOP---------------------------------------*/
//  BteTestCase_SetState( BTETESTCASE_STOP );
//
//  return rval;
//}
///*-------------------------------------------------------------------------------------------------------------------*/
//void TC_API_Issm_Init_004( void )
//{
//#if defined (_TSC)
//#if ( ISSM_CRC_CHECK == STD_ON )
//#if (ISSM_CONFIG_VARIANT == 3)
//  Issm_ConfigType myIssmConfiguration;
//#else
//#define myIssmConfiguration     Issm_Configuration
//#endif
//#endif
//
//  BteTestCase_SetState( BTETESTCASE_INIT );
//  BteTestCase_SetData( TC_NAME, "TC_API_Issm_Init_004");
//  BteTestCase_SetData( TC_ID, "[TC:ISSM_0066.00]");
//  /*-START--------------------------------------*/
//  BteTestCase_SetState( BTETESTCASE_PREPARE );
//  TscEcuM_EventMask_Enable( kTscEcuM_GeneratorCompatibilityError );
//  /*-EXECUTE------------------------------------*/
//  BteTestCase_SetState( BTETESTCASE_EXECUTE );
//#if ( ISSM_CRC_CHECK == STD_ON )
//  BteEventFilter_Clear();
//  BteEventFilter_Set( kBte_COMP, kBte_EQ, kTscEcuM_CI, 0x00 );
//  BteEventFilter_Set( kBte_CODE, kBte_EQ, kTscEcuM_GeneratorCompatibilityError, 0x00 );
//
//  BteEventList_Clear();
//  TscTest_CopyConfiguration( &Issm_Configuration, &myIssmConfiguration );
//  myIssmConfiguration.Issm_PrecompileCRC = ISSM_PRECOMPILE_CRC;
//  TscAppl_Issm_Init(&myIssmConfiguration);
//  BteAssert_EQ( BteEventList_GetSize(), 0, "occurence(EcuM_GeneratorCompatibilityError())==0" );
//
//  BteEventList_Clear();
//  myIssmConfiguration.Issm_PrecompileCRC = ISSM_PRECOMPILE_CRC+1;
//  TscAppl_Issm_Init(&myIssmConfiguration);
//  BteAssert_EQ( BteEventList_GetSize(), 1, "occurence(EcuM_GeneratorCompatibilityError())==1" );
//
//  BteEventList_Clear();
//  myIssmConfiguration.Issm_PrecompileCRC = ISSM_PRECOMPILE_CRC-1;
//  TscAppl_Issm_Init(&myIssmConfiguration);
//  BteAssert_EQ( BteEventList_GetSize(), 1, "occurence(EcuM_GeneratorCompatibilityError())==1" );
//
//  BteEventList_Clear();
//  myIssmConfiguration.Issm_PrecompileCRC = ~ISSM_PRECOMPILE_CRC;
//  TscAppl_Issm_Init(&myIssmConfiguration);
//  BteAssert_EQ( BteEventList_GetSize(), 1, "occurence(EcuM_GeneratorCompatibilityError())==1" );
//
//  BteEventList_Clear();
//  myIssmConfiguration.Issm_PrecompileCRC = ISSM_PRECOMPILE_CRC & 0x123456;
//  TscAppl_Issm_Init(&myIssmConfiguration);
//  BteAssert_EQ( BteEventList_GetSize(), 1, "occurence(EcuM_GeneratorCompatibilityError())==1" );
//
//  myIssmConfiguration.Issm_PrecompileCRC = ISSM_PRECOMPILE_CRC;
//
//
//  BteEventList_Clear();
//  TscTest_CopyConfiguration( &Issm_Configuration, &myIssmConfiguration );
//  myIssmConfiguration.Issm_LinktimeCRC = Issm_LinktimeCRC;
//  TscAppl_Issm_Init(&myIssmConfiguration);
//  BteAssert_EQ( BteEventList_GetSize(), 0, "occurence(EcuM_GeneratorCompatibilityError())==0" );
//
//  BteEventList_Clear();
//  myIssmConfiguration.Issm_LinktimeCRC = Issm_LinktimeCRC+1;
//  TscAppl_Issm_Init(&myIssmConfiguration);
//  BteAssert_EQ( BteEventList_GetSize(), 1, "occurence(EcuM_GeneratorCompatibilityError())==1" );
//
//  BteEventList_Clear();
//  myIssmConfiguration.Issm_LinktimeCRC = Issm_LinktimeCRC-1;
//  TscAppl_Issm_Init(&myIssmConfiguration);
//  BteAssert_EQ( BteEventList_GetSize(), 1, "occurence(EcuM_GeneratorCompatibilityError())==1" );
//
//  BteEventList_Clear();
//  myIssmConfiguration.Issm_LinktimeCRC = ~Issm_LinktimeCRC;
//  TscAppl_Issm_Init(&myIssmConfiguration);
//  BteAssert_EQ( BteEventList_GetSize(), 1, "occurence(EcuM_GeneratorCompatibilityError())==1" );
//
//  BteEventList_Clear();
//  myIssmConfiguration.Issm_LinktimeCRC = Issm_LinktimeCRC & 0x123456;
//  TscAppl_Issm_Init(&myIssmConfiguration);
//  BteAssert_EQ( BteEventList_GetSize(), 1, "occurence(EcuM_GeneratorCompatibilityError())==1" );
//
//  myIssmConfiguration.Issm_LinktimeCRC = Issm_LinktimeCRC;
//
//
//#else
//  BteTestCase_NA("CRC not enabled");
//#endif
//  /*-STOP---------------------------------------*/
//  BteTestCase_SetState( BTETESTCASE_STOP );
//#endif
//}
//
///*-------------------------------------------------------------------------------------------------------------------*/
//void TC_API_Issm_MainFunction_001( void )
//{
//  BteTestCase_SetState( BTETESTCASE_INIT );
//  BteTestCase_SetData( TC_NAME, "TC_API_Issm_MainFunction_001");
//  BteTestCase_SetData( TC_ID, "[TC:ISSM_0057.00]");
//  BteTestCase_SetData( TC_DESCRIPTION, "call task function without being initialized");
//  /*-START--------------------------------------*/
//  BteTestCase_SetState( BTETESTCASE_PREPARE );
//  TscDet_EventMask_Enable( kTscDet_Det_ReportError );
//  /*-EXECUTE------------------------------------*/
//  BteTestCase_SetState( BTETESTCASE_EXECUTE );
//
//  /* good case */
//  TscAppl_Issm_MainFunction();
//  BteEventFilter_Clear();
//  BteEventFilter_Set( kBte_COMP, kBte_EQ, kTscDet_CI, 0x00 );
//  BteEventFilter_Set( kBte_CODE, kBte_EQ, kTscDet_Det_ReportError, 0x00 );
//  BteEventFilter_Set( kBte_DATA1, kBte_EQ, (uint8)(ISSM_MODULE_ID>>8), 0x00 );
//  BteEventFilter_Set( kBte_DATA2, kBte_EQ, (uint8)(ISSM_MODULE_ID&0xFF), 0x00 );
//  BteEventFilter_Set( kBte_DATA3, kBte_EQ, 0, 0x00 );
//  BteEventFilter_Set( kBte_DATA4, kBte_EQ, ISSM_MAINFCT_ID, 0x00 );
//  BteEventFilter_Set( kBte_DATA5, kBte_EQ, ISSM_E_UNINIT, 0x00 );
//  BteAssert_EQ( BteEventList_GetSize(), 0, "occurence(Det_ReportError())==0" );
//
//  /* bad case */
//  TscAppl_Issm_InitMemory();
//  TscAppl_Issm_MainFunction();
//  BteEventFilter_Clear();
//  BteEventFilter_Set( kBte_COMP, kBte_EQ, kTscDet_CI, 0x00 );
//  BteEventFilter_Set( kBte_CODE, kBte_EQ, kTscDet_Det_ReportError, 0x00 );
//  BteEventFilter_Set( kBte_DATA1, kBte_EQ, (uint8)(ISSM_MODULE_ID>>8), 0x00 );
//  BteEventFilter_Set( kBte_DATA2, kBte_EQ, (uint8)(ISSM_MODULE_ID&0xFF), 0x00 );
//  BteEventFilter_Set( kBte_DATA3, kBte_EQ, 0, 0x00 );
//  BteEventFilter_Set( kBte_DATA4, kBte_EQ, ISSM_MAINFCT_ID, 0x00 );
//  BteEventFilter_Set( kBte_DATA5, kBte_EQ, ISSM_E_UNINIT, 0x00 );
//  #if ( ISSM_DEV_ERROR_DETECT == STD_OFF )
//  BteAssert_EQ( BteEventList_GetSize(), 0, "occurence(Det_ReportError())==0" );
//  #else
//  BteAssert_EQ( BteEventList_GetSize(), 1, "occurence(Det_ReportError())==1" );
//  #endif
//
//  /*-STOP---------------------------------------*/
//  BteTestCase_SetState( BTETESTCASE_STOP );
//}
