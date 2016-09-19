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
         File:  BteReport.h
      Project:  zBte
       Module:  -
    Generator:  -
  Description:  
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
  1.00.00   2008-05-28  vismas                creation
  1.01.00   2009-11-11  vismas                added handling for trace report
**********************************************************************************************************************/

#ifndef V_BTEREPORT_HEADER
#define V_BTEREPORT_HEADER

/**********************************************************************************************************************
  Includes
**********************************************************************************************************************/
#include "v_cfg.h"
#include "v_def.h"
#include "BteCfg.h"
#include "BteEvent.h"

/**********************************************************************************************************************
  Version data
**********************************************************************************************************************/
#define BTEREPORT_VERSION                                                     0x0101
#define BTEREPORT_RELEASE_VERSION                                             0x00

/**********************************************************************************************************************
  Global data defines
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global typedefs
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global data prototypes (RAM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global data prototypes (ROM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global function prototypes
**********************************************************************************************************************/
void BteReport_Open( vuint8 *reportName );
void BteReport_Close( void );
void BteReport_Write( vuint8 *text );
void BteReport_WriteInfo( vuint8 *text );
void BteReport_WriteSect( vuint8 *text );
void BteReport_WriteElement( vuint8 *textType, vuint32 time, vuint8 *text );
void BteReport_WriteVersion( vuint8 *text, vuint8 main, vuint8 sub, vuint8 release );


void BteReport_StartTestCase(vuint8* id, vuint8* name, vuint8* description );
void BteReport_StartTestRun(vuint8* parameter );
void BteReport_StopTestCase(void);
void BteReport_StopTestRun(void);

void BteTraceReport_Write( vuint8 *text );
void BteTraceReport2_Write( vuint8 *text );
void BteTraceReport_WriteElement( tBteEvent *pEvent );
void BteReport_Select_TestcaseReport( void );
void BteReport_Select_MainReport( void );
void BteReport_Open_TestcaseReport( void );
void BteReport_Close_TestcaseReport( void );
void BteReport_Copy_Testcase2Main( void );

void BteTraceReport_Write( vuint8 *text );
void BteTraceReport_WriteElement( tBteEvent *pEvent );

#endif /* V_BTEREPORT_HEADER */
/**********************************************************************************************************************
  EOF
**********************************************************************************************************************/
