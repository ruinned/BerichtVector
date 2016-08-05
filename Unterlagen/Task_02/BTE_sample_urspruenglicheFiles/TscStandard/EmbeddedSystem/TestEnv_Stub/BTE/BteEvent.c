/***********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  Copyright (c) 2015 by Vector Informatik GmbH.                                                  All rights reserved.

                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
         File:  BteEvent.c
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
  1.01.00   2009-11-11  vismas                added handling for filter using tolerances
***********************************************************************************************************************/

#define V_BTEEVENT_SOURCE

/***********************************************************************************************************************
  Includes
***********************************************************************************************************************/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

#include "BteEvent.h"


/***********************************************************************************************************************
  Version check
***********************************************************************************************************************/
#if ( BTEEVENT_VERSION != 0x0101 )
  #error "Header and Source file are inconsistent (version)!"
#endif
#if ( BTEEVENT_RELEASE_VERSION != 0x00 )
  #error "Header and Source file are inconsistent (release version)!"
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
typedef struct stBteEventFilterElement
{
  tBteEventFilter_Operand  op;
  uint32 value1;
  uint32 value2;
} tBteEventFilterElement;

typedef struct stBteEventFilter
{
  tBteEventFilterElement time;
  tBteEventFilterElement comp;
  tBteEventFilterElement code;
  tBteEventFilterElement data1;
  tBteEventFilterElement data2;
  tBteEventFilterElement data3;
  tBteEventFilterElement data4;
  tBteEventFilterElement data5;
} tBteEventFilter;

/***********************************************************************************************************************
  Global data definitions (RAM)
***********************************************************************************************************************/

/***********************************************************************************************************************
  Global data definitions (ROM)
***********************************************************************************************************************/

/***********************************************************************************************************************
  Local data definitions (RAM)
***********************************************************************************************************************/
static tBteEventFilter bteEventFilter;

/***********************************************************************************************************************
  Local data definitions (ROM)
***********************************************************************************************************************/

/***********************************************************************************************************************
  Local function prototypes
***********************************************************************************************************************/
static uint8 BteEventListFilter_Apply( uint8 member, tBteEvent *pEvent );
static tBteEventFilterElement* BteEventListFilter_Get( tBteEventFilter_Element member );

/***********************************************************************************************************************
  Global function definitions
***********************************************************************************************************************/
/*--- Event ---------------------------------------------------------------------------------------------------------*/
/***********************************************************************************************************************
  Name:         BteEvent_Init
  Parameter:    *pEvent
  Return value: ---
  Description:  This function initializes the data elements of an event.
***********************************************************************************************************************/
void BteEvent_Init( tBteEvent *pEvent )
{
  pEvent->time  = 0xFFFFFFFF;
  pEvent->comp  = 0xFF;
  pEvent->code  = 0xFF;
  pEvent->data1 = 0xFF;
  pEvent->data2 = 0xFF;
  pEvent->data3 = 0xFF;
  pEvent->data4 = 0xFF;
  pEvent->data5 = 0xFF;
  pEvent->type  = kBteEventType_Default;
  (void)sprintf( pEvent->text_name, "---" );
  (void)sprintf( pEvent->text_param, "---" );
}





/***********************************************************************************************************************
  Name:         BteEvent_Copy
  Parameter:    *pEventSrc
                *pEventTrg
  Return value: ---
  Description:  This function copies an event.
***********************************************************************************************************************/
void BteEvent_Copy( tBteEvent *pEventSrc, tBteEvent *pEventTrg )
{
  pEventTrg->time  = pEventSrc->time;
  pEventTrg->comp  = pEventSrc->comp;
  pEventTrg->code  = pEventSrc->code;
  pEventTrg->data1 = pEventSrc->data1;
  pEventTrg->data2 = pEventSrc->data2;
  pEventTrg->data3 = pEventSrc->data3;
  pEventTrg->data4 = pEventSrc->data4;
  pEventTrg->data5 = pEventSrc->data5;
  sprintf( pEventTrg->text_name, pEventSrc->text_name );
  sprintf( pEventTrg->text_param, pEventSrc->text_param );
}

/*--- EventFilter ---------------------------------------------------------------------------------------------------*/
/***********************************************************************************************************************
  Name:         BteEventFilter_Clear
  Parameter:    
  Return value: 
  Description:  This function initializes the event list filter.
***********************************************************************************************************************/
void BteEventFilter_Clear( void )
{
  tBteEventFilter_Element element;

  for( element=kBte_TIME; element<=kBte_DATA5; element++ )
  {
    tBteEventFilterElement *pFilter;
    pFilter = BteEventListFilter_Get( element );
    if( pFilter != 0 )
    {
      pFilter->op = kBte_NR;
      pFilter->value1 = 0;
      pFilter->value2 = 0;
    }
  }
}

/***********************************************************************************************************************
  Name:         BteEventFilter_Set
  Parameter:    
  Return value: 
  Description:  This function sets a filter rule.
***********************************************************************************************************************/
void BteEventFilter_Set( tBteEventFilter_Element member, tBteEventFilter_Operand op, uint32 value1, uint32 value2 )
{
  tBteEventFilterElement* pFilter;

  pFilter = BteEventListFilter_Get( member );
  if( pFilter != 0 )
  {
    pFilter->op = op;
    pFilter->value1 = value1;
    pFilter->value2 = value2;
  }
}

/***********************************************************************************************************************
  Name:         BteEventFilter_Apply
  Parameter:    *pEvent
  Return value: 1:  match 
                0:  no match
  Description:  This function checks if the given event matches the currently defined filter.
***********************************************************************************************************************/
uint8 BteEventFilter_Apply( tBteEvent *pEvent )
{
  uint8 rval;

  if( ( BteEventListFilter_Apply(kBte_TIME,  pEvent) != 0 ) &&
      ( BteEventListFilter_Apply(kBte_COMP,  pEvent) != 0 ) &&
      ( BteEventListFilter_Apply(kBte_CODE,  pEvent) != 0 ) &&
      ( BteEventListFilter_Apply(kBte_DATA1, pEvent) != 0 ) &&
      ( BteEventListFilter_Apply(kBte_DATA2, pEvent) != 0 ) &&
      ( BteEventListFilter_Apply(kBte_DATA3, pEvent) != 0 ) &&
      ( BteEventListFilter_Apply(kBte_DATA4, pEvent) != 0 ) &&
      ( BteEventListFilter_Apply(kBte_DATA5, pEvent) != 0 ) )
  {
    rval = 1;
  }
  else
  {
    rval = 0;
  }
  return( rval );
}


/***********************************************************************************************************************
  Local function definitions
***********************************************************************************************************************/
/***********************************************************************************************************************
  Name:         BteEventListFilter_Apply
  Parameter:    
  Return value: 
  Description:  
***********************************************************************************************************************/
static uint8 BteEventListFilter_Apply( uint8 member, tBteEvent *pEvent )
{
  tBteEventFilterElement* pFilter;
  uint8 rval;
  uint32 listValue;

  rval = 0;
  
  /* get filter */
  pFilter = BteEventListFilter_Get( member );

  /* get current data set */
  switch( member )
  {
    case kBte_TIME:
      listValue = pEvent->time;
      break;
    case kBte_COMP:
      listValue = pEvent->comp;
      break;
    case kBte_CODE:
      listValue = pEvent->code;
      break;
    case kBte_DATA1:
      listValue = pEvent->data1;
      break;
    case kBte_DATA2:
      listValue = pEvent->data2;
      break;
    case kBte_DATA3:
      listValue = pEvent->data3;
      break;
    case kBte_DATA4:
      listValue = pEvent->data4;
      break;
    case kBte_DATA5:
      listValue = pEvent->data5;
      break;
    default:
      listValue = 0x00;
      break;
  }

  /* apply filter */
  switch( pFilter->op )
  {
    case kBte_NR:
      rval = 1;
      break;
    case kBte_EQ:
      if( listValue == pFilter->value1 )
      {
        rval = 1;
      }
      break;
    case kBte_NEQ:
      if( listValue != pFilter->value1 )
      {
        rval = 1;
      }
      break;
    case kBte_LT:
      if( listValue < pFilter->value1 )
      {
        rval = 1;
      }
      break;
    case kBte_GT:
      if( listValue > pFilter->value1 )
      {
        rval = 1;
      }
      break;
    case kBte_LE:
      if( listValue <= pFilter->value1 )
      {
        rval = 1;
      }
      break;
    case kBte_GE:
      if( listValue >= pFilter->value1 )
      {
        rval = 1;
      }
      break;
    case kBte_RANGE:
      if( (pFilter->value1 <= listValue) &&  
          (pFilter->value2 >= listValue) )
      {
        rval = 1;
      }
      break;
    case kBte_TOL:
      if( (listValue < (pFilter->value1*(100+(pFilter->value2))/100)) &&
          (listValue > (pFilter->value1*(100-(pFilter->value2))/100)) )
      {
        rval = 1;
      }
      break;
    case kBte_MASK:
      if( (listValue & (pFilter->value1)) == pFilter->value2 )
      {
        rval = 1;
      }
      break;
  }
  return( rval );
}

/***********************************************************************************************************************
  Name:         BteEventListFilter_Get
  Parameter:    
  Return value: 
  Description:  
***********************************************************************************************************************/
static tBteEventFilterElement* BteEventListFilter_Get( tBteEventFilter_Element member )
{
  tBteEventFilterElement *pFilter;

  switch( member )
  {
    case kBte_TIME:
      pFilter = &bteEventFilter.time;
      break;
    case kBte_COMP:
      pFilter = &bteEventFilter.comp;
      break;
    case kBte_CODE:
      pFilter = &bteEventFilter.code;
      break;
    case kBte_DATA1:
      pFilter = &bteEventFilter.data1;
      break;
    case kBte_DATA2:
      pFilter = &bteEventFilter.data2;
      break;
    case kBte_DATA3:
      pFilter = &bteEventFilter.data3;
      break;
    case kBte_DATA4:
      pFilter = &bteEventFilter.data4;
      break;
    case kBte_DATA5:
      pFilter = &bteEventFilter.data5;
      break;
    default:
      pFilter = 0x00;
  }

  return( pFilter );
}

/***********************************************************************************************************************
  EOF
***********************************************************************************************************************/
