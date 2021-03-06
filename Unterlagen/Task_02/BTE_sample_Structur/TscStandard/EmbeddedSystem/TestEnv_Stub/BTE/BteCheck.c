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
File:  BteCheck.c
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
1.01.00   2009-11-11  vismas                added check with configurable output format
***********************************************************************************************************************/

#define V_BTECHECK_SOURCE

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

#include "BteCheck.h"


#include "BteReport.h"
#include "BteTestHandler.h"

/***********************************************************************************************************************
Version check
***********************************************************************************************************************/
#if ( BTECHECK_VERSION != 0x0101 )
#error "Header and Source file are inconsistent (version)!"
#endif
#if ( BTECHECK_RELEASE_VERSION != 0x00 )
#error "Header and Source file are inconsistent (release version)!"
#endif

/***********************************************************************************************************************
Local data defines
***********************************************************************************************************************/
#define kBteTextSize                                                          300

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

/***********************************************************************************************************************
Global function definitions
***********************************************************************************************************************/
/***********************************************************************************************************************
Name:         BteAssert
Parameter:    
Return value: ---
Description:  
***********************************************************************************************************************/
void BteAssert( uint8 condition, char *text )
{
  if( condition == 0 )
  {
    BteError( text );
  }
  else
  {
    BteOk( text );
  }
}

/***********************************************************************************************************************
Name:         BteAssert_EQ
Parameter:    
Return value: ---
Description:  
***********************************************************************************************************************/
void BteAssert_EQ( uint32 current, uint32 expected, char *text )
{
# if defined (USE_EXTERNAL_LOG)
  char tempText[kBteTextSize];

  sprintf( tempText, "%s: %d == %d", text, current, expected );
  if( current == expected )
  {
    BteOk( tempText );
  }
  else
  {
    BteError( tempText );
  }
#endif
}

/***********************************************************************************************************************
Name:         BteAssert2_EQ
Parameter:    
Return value: ---
Description:  
***********************************************************************************************************************/
void BteAssert2_EQ( uint32 current, uint32 expected, char *text, tBteAssertType type )
{
# if defined (USE_EXTERNAL_LOG)
  char tempText[kBteTextSize];

  switch( type )
  {
  case dec:
    sprintf( tempText, "%s: %d == %d", text, current, expected );
    break;
  case hex:
    sprintf( tempText, "%s: 0x%x == 0x%x", text, current, expected );
    break;
  }
  if( current == expected )
  {
    BteOk( tempText );
  }
  else
  {
    BteError( tempText );
  }
#endif
}


/***********************************************************************************************************************
Name:         BteAssert_NEQ
Parameter:    
Return value: ---
Description:  
***********************************************************************************************************************/
void BteAssert_NEQ( uint32 current, uint32 expected, char *text )
{
# if defined (USE_EXTERNAL_LOG)
  char tempText[kBteTextSize];

  sprintf( tempText, "%s: %d != %d", text, current, expected );
  if( current != expected )
  {
    BteOk( tempText );
  }
  else
  {
    BteError( tempText );
  }
#endif
}


/***********************************************************************************************************************
Name:         BteAssert_LE
Parameter:    
Return value: ---
Description:  
***********************************************************************************************************************/
void BteAssert_LE( uint32 current, uint32 expected, char *text )
{
# if defined (USE_EXTERNAL_LOG)
  char tempText[kBteTextSize];

  sprintf( tempText, "%s: %d LE %d", text, current, expected );
  if( current <= expected )
  {
    BteOk( tempText );
  }
  else
  {
    BteError( tempText );
  }
#endif
}

/***********************************************************************************************************************
Name:         BteAssert_GE
Parameter:    
Return value: ---
Description:  
***********************************************************************************************************************/
void BteAssert_GE( uint32 current, uint32 expected, char *text )
{
# if defined (USE_EXTERNAL_LOG)
  char tempText[kBteTextSize];

  sprintf( tempText, "%s: %d GE %d", text, current, expected );
  if( current >= expected )
  {
    BteOk( tempText );
  }
  else
  {
    BteError( tempText );
  }
#endif
}

/***********************************************************************************************************************
Name:         BteAssert_Range
Parameter:    
Return value: ---
Description:  
***********************************************************************************************************************/
void BteAssert_Range( uint32 current, uint32 lowerRange, uint32 upperRange, char *text )
{
# if defined (USE_EXTERNAL_LOG)
  char tempText[kBteTextSize];

  sprintf( tempText, "%s: %d LE %d LE %d", text, lowerRange, current, upperRange );
  if( (current >= lowerRange) &&
    (current <= upperRange) )
  {
    BteOk( tempText );
  }
  else
  {
    BteError( tempText );
  }
#endif
}

/***********************************************************************************************************************
Name:         BteAssert_Tolerance
Parameter:    
Return value: ---
Description:  
***********************************************************************************************************************/
void BteAssert_Tolerance( uint32 current, uint32 expected, uint8 tolerance, char *text )
{
# if defined (USE_EXTERNAL_LOG)
  char tempText[kBteTextSize];

  (void)sprintf( tempText, "%s: %d == %d +-%dpercent", text, current, expected, tolerance );
  if( (current >= expected*(100-tolerance)/(100)) &&
    (current <= expected*(100+tolerance)/(100)) )
  {
    BteOk( tempText );
  }
  else
  {
    BteError( tempText );
  }
#endif
}

/***********************************************************************************************************************
Name:         BteOk
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteOk( char *text )
{
# if defined (USE_EXTERNAL_LOG)
  char text2[300];
  BteReport_WriteElement( "ok", BteTestCase_GetTime(), text );
  (void)sprintf(text2," note right of Appl #lime: Ok: %s ", text);
  BteTraceReport_Write(text2);
#endif
}

/***********************************************************************************************************************
Name:         BteError
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteError( char *text )
{
# if defined (USE_EXTERNAL_LOG)
  char text2[300];
  (void)sprintf(text2," note right of Appl #red: Fail: %s", text);
  BteTraceReport_Write(text2);

  BteReport_WriteElement( "fail", BteTestCase_GetTime(), text );
  BteTestRun_Error();
#endif
  // hier sollte ich Markus addMessage-Methode eingeben, damit zum Biespiel die von der BTE hindurchgerückte 
}

/***********************************************************************************************************************
Name:         BteWarning
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteWarning( char *text )
{
  BteReport_WriteElement( "warn", BteTestCase_GetTime(), text );
  BteTestRun_Warning();
}

/***********************************************************************************************************************
Name:         BteAvailableOk
Parameter:    
Return value: ---
Description:  
***********************************************************************************************************************/
void BteAvailableOk( char *text )
{
# if defined (USE_EXTERNAL_LOG)
  char output[kBteTextSize];
  sprintf( output, "%s is available (as expected)", text );
  BteOk( output );
#endif
}

/***********************************************************************************************************************
Name:         BteAvailableError
Parameter:    
Return value: ---
Description:  
***********************************************************************************************************************/
void BteAvailableError( char *text )
{
# if defined (USE_EXTERNAL_LOG)
  char output[100];
  sprintf( output, "%s is not available (but expected)", text );
  BteError( output );
#endif
}

/***********************************************************************************************************************
Name:         BteNotAvailableOk
Parameter:    
Return value: ---
Description:  
***********************************************************************************************************************/
void BteNotAvailableOk( char *text )
{
# if defined (USE_EXTERNAL_LOG)
  char output[kBteTextSize];
  sprintf( output, "%s is not available (as expected)", text );
  BteOk( output );
#endif
}

/***********************************************************************************************************************
Name:         BteNotAvailableError
Parameter:    
Return value: ---
Description:  
***********************************************************************************************************************/
void BteNotAvailableError( char *text )
{
# if defined (USE_EXTERNAL_LOG)
  char output[kBteTextSize];
  sprintf( output, "%s is available (but not expected)", text );
  BteError( output );
#endif
}

/***********************************************************************************************************************
Name:         BteRangeOk
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteRangeOk( char *text )
{
# if defined (USE_EXTERNAL_LOG)
  char output[kBteTextSize];
  sprintf( output, "%s value is in expected range", text );
  BteOk( output );
#endif
}

/***********************************************************************************************************************
Name:         BteRangeError
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteRangeError( char *text )
{
# if defined (USE_EXTERNAL_LOG)
  char output[kBteTextSize];
  sprintf( output, "%s value is not in expected range", text );
  BteError( output );
#endif
}

/***********************************************************************************************************************
Name:         BteMultipleOk
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteMultipleOk( char *text )
{
# if defined (USE_EXTERNAL_LOG)
  char output[kBteTextSize];
  sprintf( output, "%s value is not multiply defined", text );
  BteOk( output );
#endif
}

/***********************************************************************************************************************
Name:         BteMultipleError
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteMultipleError( char *text )
{
# if defined (USE_EXTERNAL_LOG)
  char output[kBteTextSize];
  sprintf( output, "%s value is multiply defined", text );
  BteError( output );
#endif
}

/***********************************************************************************************************************
Local function definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
EOF
***********************************************************************************************************************/
