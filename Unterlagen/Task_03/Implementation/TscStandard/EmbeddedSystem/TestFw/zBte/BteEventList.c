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
         File:  BteEventList.c
      Project:  BteTest
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
  1.01.00   2009-11-11  vismas                minor fixes
**********************************************************************************************************************/

#define V_BTEEVENTLIST_SOURCE

/**********************************************************************************************************************
  Includes
**********************************************************************************************************************/
#include "BteEventList.h"
#include "BteCheck.h"

/**********************************************************************************************************************
  Version check
**********************************************************************************************************************/
#if ( BTEEVENTLIST_VERSION != 0x0101 )
  #error "Header and Source file are inconsistent (version)!"
#endif
#if ( BTEEVENTLIST_RELEASE_VERSION != 0x00 )
  #error "Header and Source file are inconsistent (release version)!"
#endif

/**********************************************************************************************************************
  Local data defines
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local macro defines
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local typedefs
**********************************************************************************************************************/
typedef struct stBteEventList 
{
  vuint16     size;
  tBteEvent   elem[kBteEventList_size];
} tBteEventList;

/**********************************************************************************************************************
  Global data definitions (RAM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global data definitions (ROM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local data definitions (RAM)
**********************************************************************************************************************/
static tBteEventList bteEventList;

/**********************************************************************************************************************
  Local data definitions (ROM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local function prototypes
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global function definitions
**********************************************************************************************************************/
/**********************************************************************************************************************
  Name:         BteEventList_Clear
  Parameter:    
  Return value: 
  Description:  This function clears the event list.
**********************************************************************************************************************/
void BteEventList_Clear( void )
{
  vuint16 listIndex;

  for( listIndex=0; listIndex<kBteEventList_size; listIndex++ )
  {
    BteEvent_Init(&bteEventList.elem[listIndex]);
  }
  bteEventList.size = 0;
}

/**********************************************************************************************************************
  Name:         BteEventList_Add
  Parameter:    *pEvent
  Return value: ---
  Description:  This function adds an event to the event list (if the list is not full)
**********************************************************************************************************************/
void BteEventList_Add( tBteEvent *pEvent )
{
  vuint16 listIndex;

  listIndex = bteEventList.size;
  if( listIndex<kBteEventList_size ) 
  {
    BteEvent_Copy( pEvent, &bteEventList.elem[listIndex] );
    bteEventList.size++;
  }
  else
  {
      /* Report Event Overflow */
    BteError("BteEventList: Event Overflow - Increase Event List Size or Reduce Reported Events!!!");
  }
}

/**********************************************************************************************************************
  Name:         BteEventList_Get
  Parameter:    index of element in event list
  Return value: *pEvent
  Description:  This function returns a given element from the event list.
                If there is no element at the requested index, NULL is returned.
**********************************************************************************************************************/
tBteEvent* BteEventList_Get( vuint16 listIndex )
{
  tBteEvent *rval;
  vuint16 i;
  vuint16 count = 0;
  vuint16 realListIndex=0;
  
  if( listIndex<bteEventList.size )
  {
    for( i=0; i<bteEventList.size; i++ )
    {
      if( BteEventFilter_Apply( &bteEventList.elem[i] ) != 0 )
      {
        if( count == listIndex )
        {
          rval = &bteEventList.elem[realListIndex];
          break;
        }
        count++;
      }
      realListIndex++;
    }
    if( realListIndex == bteEventList.size )
    {
      rval = V_NULL;
    }
    else
    {
      rval = &bteEventList.elem[realListIndex];
    }
  }
  else
  {
    rval = V_NULL;
  }

  return( rval );
}

/**********************************************************************************************************************
  Name:         BteEventList_GetSize
  Parameter:    
  Return value: size of event list
  Description:  This function returns the occupied size of the event list.
                If set, a filter is applied.
**********************************************************************************************************************/
vuint16 BteEventList_GetSize( void )
{
  vuint16 count=0;
  vuint16 listIndex;

  for( listIndex=0; listIndex<bteEventList.size; listIndex++ )
  {
    if( BteEventFilter_Apply( &bteEventList.elem[listIndex] ) != 0 )
    {
      count++;
    }
  }

  return( count );
}

/**********************************************************************************************************************
  Name:         BteEventList_GetCount
  Parameter:    
  Return value: count of given events in event list
  Description:  
**********************************************************************************************************************/
vuint16 BteEventList_GetCount( vuint8 comp, vuint8 code )
{
  vuint16 count=0;

  vuint16 listIndex;

  for( listIndex=0; listIndex<bteEventList.size; listIndex++ )
  {
    if( (bteEventList.elem[listIndex].comp == comp) && (bteEventList.elem[listIndex].code == code) )
    {
      count++;
    }
  }

  return( count );
}


/**********************************************************************************************************************
  Name:         BteEventList_GetIndex
  Parameter:    occurence:    number of occurence
  Return value: index of x-th occurence
  Description:  This function returns the index of the x-th occurence in the list.
                If set, a filter is applied.
**********************************************************************************************************************/
vuint16 BteEventList_GetIndex( vuint8 occurence )
{
  vuint8 count = 0;
  vuint16 listIndex;

  for( listIndex=0; listIndex<bteEventList.size; listIndex++ )
  {
    if( BteEventFilter_Apply( &bteEventList.elem[listIndex] ) != 0 )
    {
      count++;
      if( count == occurence )
      {
        break;
      }
    }
  }

  return( listIndex );
}

/**********************************************************************************************************************
  Local function definitions
**********************************************************************************************************************/

/**********************************************************************************************************************
  EOF
**********************************************************************************************************************/
