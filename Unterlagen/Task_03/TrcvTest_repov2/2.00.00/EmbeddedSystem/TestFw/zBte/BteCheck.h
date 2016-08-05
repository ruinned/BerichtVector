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
         File:  BteCheck.h
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
  1.01.00   2009-11-11  vismas                added check with configurable output format
**********************************************************************************************************************/

#ifndef V_BTECHECK_HEADER
#define V_BTECHECK_HEADER

/**********************************************************************************************************************
  Includes
**********************************************************************************************************************/
#include "v_cfg.h"
#include "v_def.h"
#include "BteCfg.h"

/**********************************************************************************************************************
  Version data
**********************************************************************************************************************/
#define BTECHECK_VERSION                         0x0101
#define BTECHECK_RELEASE_VERSION                 0x00

/**********************************************************************************************************************
  Global data defines
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global typedefs
**********************************************************************************************************************/
typedef enum
{
  dec,
  hex
} tBteAssertType;

/**********************************************************************************************************************
  Global data prototypes (RAM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global data prototypes (ROM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global function prototypes
**********************************************************************************************************************/
void BteAssert( vuint8 condition, vuint8 *text );
void BteAssert_EQ( vuint32 current, vuint32 expected, vuint8 *text );
void BteAssert2_EQ( vuint32 current, vuint32 expected, vuint8 *text, tBteAssertType type );
void BteAssert_NEQ( vuint32 current, vuint32 expected, vuint8 *text );
void BteAssert_LE( vuint32 current, vuint32 expected, vuint8 *text );
void BteAssert_GE( vuint32 current, vuint32 expected, vuint8 *text );
void BteAssert_Range( vuint32 current, vuint32 lowerRange, vuint32 upperRange, vuint8 *text );
void BteAssert_Tolerance( vuint32 current, vuint32 expected, vuint8 tolerance, vuint8 *text );


void BteOk( vuint8 *text );
void BteError( vuint8 *text );
void BteWarning( vuint8 *text );
void BteAvailableOk( vuint8 *text );
void BteAvailableError( vuint8 *text );
void BteNotAvailableOk( vuint8 *text );
void BteNotAvailableError( vuint8 *text );
void BteRangeOk( vuint8 *text );
void BteRangeError( vuint8 *text );
void BteMultipleOk( vuint8 *text );
void BteMultipleError( vuint8 *text );

#endif /* V_BTECHECK_HEADER */
/**********************************************************************************************************************
  EOF
**********************************************************************************************************************/
