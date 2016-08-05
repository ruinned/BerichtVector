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
File:  BteReport.c
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
1.01.00   2009-11-11  vismas                added handling for trace report
***********************************************************************************************************************/

#define V_BTEREPORT_SOURCE

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "BteCfg.h"
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#if defined ( _V_RESSOURCE_ )
#else
#if defined ( BTE_ENABLE_TESTREPORT )
#include <windows.h>
#endif
#endif

#include "BteReport.h"
#include "BteLog.h"
#include "BteTestHandler.h"

/***********************************************************************************************************************
Version check
***********************************************************************************************************************/
#if ( BTEREPORT_VERSION != 0x0101 )
#error "Header and Source file are inconsistent (version)!"
#endif
#if ( BTEREPORT_RELEASE_VERSION != 0x00 )
#error "Header and Source file are inconsistent (release version)!"
#endif

/***********************************************************************************************************************
Local data defines
***********************************************************************************************************************/
#define kBteTextSize                                                          1000

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
#if defined ( BTE_ENABLE_TESTREPORT )
static FILE *pBteTestReport;
static FILE *pBteTestReportMain;
static FILE *pBteTestReportTestcase;
#endif

#if defined ( BTE_ENABLE_TRACEREPORT )
static FILE *pBteTraceReport;
#endif

/***********************************************************************************************************************
Local data definitions (ROM)
***********************************************************************************************************************/

/***********************************************************************************************************************
Local function prototypes
***********************************************************************************************************************/

/***********************************************************************************************************************
Global function definitions
***********************************************************************************************************************/
/***********************************************************************************************************************
Name:         BteReport_Init
Parameter:    reportName            name of the report
Return value: ---
Description:  This function closes any pending report and opens a new report with the given name.
***********************************************************************************************************************/
void BteReport_Open( uint8 *reportName )
{
#if defined ( BTE_ENABLE_TESTREPORT )
  /* check and close if there is still an open report */
  if( pBteTestReport != 0 )
  {
    BteReport_Close();
  }

  /* open new report */
  pBteTestReportMain = fopen( reportName, "w" );
  pBteTestReport = pBteTestReportMain;
#endif

#if defined ( BTE_ENABLE_TRACEREPORT )
  if( pBteTraceReport != 0 )
  {
    BteReport_Close();
  }

  /* open new report */
  pBteTraceReport = fopen( "TraceReport.csv", "w" );
  BteTraceReport_Write("Print;Time;Type;Name;Object File;Module;Caller Object File;Caller Module;OS Task;Values;Parameters" );

#endif
}

/***********************************************************************************************************************
Name:         BteReport_Close
Parameter:    ---
Return value: ---
Description:  This function closes the currently open report.
***********************************************************************************************************************/
void BteReport_Close( void )
{
#if defined ( BTE_ENABLE_TESTREPORT )
  /* close report */
  if( pBteTestReportMain != 0 )
  {
    fclose( pBteTestReportMain );
    pBteTestReport = 0;
    pBteTestReportMain = 0;
  }
#endif

}

//char* strReplace( char *search, char *replace, char *subject )
//{
//  int ldiff=0;
//  char *dest, *p = subject;
//  while(p=strstr(p,search))
//  {
//    ldiff += strlen(replace) - strlen(search);
//    ++p;
//  }
//  p=dest = strcpy(malloc(strlen(subject)+ldiff),subject);
//  while(p=strstr(p,search))
//  {
//    memmove(p+strlen(replace), p+strlen(search), strlen(p)-strlen(search)+1);
//    memmove(p, replace, strlen(replace));
//    p+= strlen(replace);
//  }
//  return dest;
//}

/***********************************************************************************************************************
Name:         BteTraceReport_Open
Parameter:    reportName            name of the report
Return value: ---
Description:  This function closes any pending report and opens a new report with the given name.
***********************************************************************************************************************/
void BteTraceReport_Open( char *reportName )
{
#if defined ( BTE_ENABLE_TRACEREPORT )
  uint16 i;
  for(i=0; i<strlen(reportName); i++ )
  {
    if( reportName[i]==':' ) reportName[i]='_';
  }

  /* open new report */
  pBteTraceReport = fopen( reportName, "w" );
  //  BteTraceReport_Write("Print;Time;Type;Name;Object File;Module;Caller Object File;Caller Module;OS Task;Values;Parameters" );

#endif
}

/***********************************************************************************************************************
Name:         BteTraceReport_Close
Parameter:    ---
Return value: ---
Description:  This function closes the currently open trace report.
***********************************************************************************************************************/
void BteTraceReport_Close(void)
{
#if defined ( BTE_ENABLE_TRACEREPORT )
  /* close report */
  if( pBteTraceReport != 0 )
  {
    fclose( pBteTraceReport );
  }
#endif
}

/***********************************************************************************************************************
Name:         BteReport_Select_TempReport
Parameter:    ---
Return value: ---
Description:  
***********************************************************************************************************************/
void BteReport_Select_TestcaseReport( void )
{
#if defined ( BTE_ENABLE_TESTREPORT )
  pBteTestReport = pBteTestReportTestcase;
#endif
}

/***********************************************************************************************************************
Name:         BteReport_Select_TempReport
Parameter:    ---
Return value: ---
Description:  
***********************************************************************************************************************/
void BteReport_Select_MainReport( void )
{
#if defined ( BTE_ENABLE_TESTREPORT )
  pBteTestReport = pBteTestReportMain;
#endif
}

/***********************************************************************************************************************
Name:         BteReport_Open_TestcaseReport
Parameter:    ---
Return value: ---
Description:  
***********************************************************************************************************************/
void BteReport_Open_TestcaseReport( void )
{
#if defined ( BTE_ENABLE_TESTREPORT )
  pBteTestReportTestcase = fopen( "report_Testcase.xml", "w" );
#endif
}

/***********************************************************************************************************************
Name:         BteReport_Close_TestcaseReport
Parameter:    ---
Return value: ---
Description:  
***********************************************************************************************************************/
void BteReport_Close_TestcaseReport( void )
{
#if defined ( BTE_ENABLE_TESTREPORT )
  if( pBteTestReportTestcase != 0 )
  {
    fclose( pBteTestReportTestcase );
  }
#endif
}

/***********************************************************************************************************************
Name:         BteReport_Copy_Testcase2Main
Parameter:    ---
Return value: ---
Description:  
***********************************************************************************************************************/
void BteReport_Copy_Testcase2Main( void )
{
#if defined ( BTE_ENABLE_TESTREPORT )
  char currentChar;
  pBteTestReportTestcase = fopen( "report_Testcase.xml", "r" );
  while( fscanf( pBteTestReportTestcase, "%c", &currentChar) != EOF)
  {
    fprintf( pBteTestReportMain, "%c", currentChar);
  }
#endif
}




//void BteReport_StartTestCase(uint8* id, uint8* name, uint8* description )
//{
//  uint8 tempText[kBteTextSize];
//  (void)sprintf( tempText, "<testcase id=\"%s\" name=\"%s\"> <description>%s</description>", id,
//                                                name,
//                                                description );
//  BteReport_Write(tempText);
//}



/***********************************************************************************************************************
Name:         BteReport_Write
Parameter:    
Return value: 
Description:  This function prints any text directly into the report.
***********************************************************************************************************************/
void BteReport_Write( char *text )
{
#if defined ( BTE_ENABLE_TESTREPORT )
  if( pBteTestReport != 0 ) 
  {
    fprintf( pBteTestReport, "%s\n",text );
  }
#endif
}

/***********************************************************************************************************************
Name:         BteReport_WriteInfo
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteReport_WriteInfo( char *text2 )
{
#if defined ( BTE_ENABLE_TESTREPORT )

  BteReport_WriteElement("info", BteTestCase_GetTime(), text2 );
#endif
}

/***********************************************************************************************************************
Name:         BteReport_WriteSect
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteReport_WriteSect( char *text2 )
{
#if defined ( BTE_ENABLE_TESTREPORT )

  BteReport_WriteElement("sect", BteTestCase_GetTime(), text2 );
#endif
}

/***********************************************************************************************************************
Name:         BteReport_WriteElement
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteReport_WriteElement( char *textType, uint32 time, char *text )
{
#if defined ( BTE_ENABLE_TESTREPORT )

  char text2[kBteTextSize];
  (void)sprintf( text2, "<Element type=\"%s\" time=\"%d\"> %s </Element>", textType, time, text );
  BteReport_Write( text2 );

#endif



}

/***********************************************************************************************************************
Name:         BteReport_WriteVersion
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteReport_WriteVersion( char *text, uint8 main, uint8 sub, uint8 release )
{
# if defined (BTE_ENABLE_TESTREPORT)
  char tempText[kBteTextSize];

  (void)sprintf( tempText, "<component name=\"%s\" version=\"%02X.%02X.%02X\"></component>", text, main, sub, release );
  BteReport_Write( tempText );
#endif
}

/***********************************************************************************************************************
Name:         BteTraceReport_WriteElement
Parameter:    
Return value: 
Description:  

Print;Time;Type;Name;Object File;Module;Caller Object File;Caller Module;OS Task;Values;Parameters
True;11000000;Enter;ComM_MainFunction;comm.obj;comm;comm.obj;comm;0;;UInt Channel = 0

***********************************************************************************************************************/
void BteTraceReport_WriteElement( tBteEvent *pEvent )
{
#if defined ( BTE_ENABLE_TRACEREPORT )
  uint8 text[kBteTextSize];
  uint8 target[50];
  uint8 source[50];
  uint8 trimmedParameter[100];
  uint8 i;

  if( pEvent->type == kBteEventType_Command )
  {
    (void)sprintf( source, "Appl");
    (void)sprintf( target, "DUT");
  } 
  else
  {
    (void)sprintf( source, "DUT");
    (void)sprintf( target, BteLog_GetStubName(pEvent->comp));
  }

  for(i=0; i<100; i++)
  {
    if( pEvent->text_param[i+1]==')' )
    {
      trimmedParameter[i]='\0';
    }
    else
    {
      trimmedParameter[i]=pEvent->text_param[i+1];
    }
  }


  (void)sprintf( text, "autonumber %d \"<b>t=0\"", pEvent->time  );
  BteTraceReport_Write(text);
  (void)sprintf( text, "%s -> %s : %s %s", source, target, pEvent->text_name, pEvent->text_param  );
  BteTraceReport_Write(text);


  //(void)sprintf( text, "True;%d;Enter;%s;%s.obj;%s;%s.obj;%s;0;;", pEvent->time, pEvent->text_name, target, target, source, source );
  //BteTraceReport_Write(text);
  //(void)sprintf( text, "True;%d;Exit;%s;%s.obj;%s;%s.obj;%s;0;;", pEvent->time, pEvent->text_name, target, target, source, source );
  //BteTraceReport_Write(text);
#endif
}

/***********************************************************************************************************************
Name:         BteTraceReport_Write
Parameter:    
Return value: 
Description:  This function prints any text directly into the report.
***********************************************************************************************************************/
void BteTraceReport_Write( char *text )
{
#if defined ( BTE_ENABLE_TRACEREPORT )
  if( pBteTraceReport != 0 ) 
  {
    fprintf( pBteTraceReport, "%s\n",text );
  }
#endif
}

/***********************************************************************************************************************
Local function definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
EOF
***********************************************************************************************************************/
