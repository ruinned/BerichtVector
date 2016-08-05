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
         File:  TscFrIf.c
      Project:  TscFrTp
       Module:  -
    Generator:  -
  Description:  Component test suite for component CddMirror
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
  1.00.00   2009-02-27  vismas                creation
**********************************************************************************************************************/

#define V_TSCCANIF_SOURCE

/**********************************************************************************************************************
  Includes
**********************************************************************************************************************/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include "string.h"

#include "TscFrIf.h"
#include "TscAppl.h"

#include "BteLog.h"

/**********************************************************************************************************************
  Version check
**********************************************************************************************************************/
#if ( TSCFRIF_VERSION != 0x0100 )
  #error "Header and Source file are inconsistent (version)!"
#endif
#if ( TSCFRIF_RELEASE_VERSION != 0x00 )
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

/**********************************************************************************************************************
  Global data definitions (RAM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global data definitions (ROM)
**********************************************************************************************************************/
ActiveFrIfTxPduType ActiveFrIfTxPdus[MAX_FRIF_TX_PDUS];
ActiveFrIfRxPduType ActiveFrIfRxPdus[MAX_FRIF_RX_PDUS];

const ActiveFrIfTxPduType ActiveFrIfTxPduInitConst = 
{
  E_OK, /* Std_ReturnType retVal; */
  FALSE, /* boolean toBeSentToDut; */
  FALSE, /* boolean transmitCalled; */
  FALSE, /* boolean wasTriggered; */
  FALSE, /* boolean wasConfirmed; */
  {
    NULL_PTR,
    0
  },/* PduInfoType pduInfo; */
  0,/* PduLengthType pduLenCfgrd; */
  {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  } /* char payload[254]; */
};

const ActiveFrIfRxPduType ActiveFrIfRxPduInitConst = 
{
  FALSE, /* boolean toBeSentToDut */
  {
    NULL_PTR,
    0
  }, /* PduInfoType pduInfo; */
  0, /*PduLengthType pduLenCfgrd; */
  {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  } /* char payload[254]; */
};
/**********************************************************************************************************************
  Local data definitions (RAM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local data definitions (ROM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local function prototypes
**********************************************************************************************************************/
static void TscFrIf_Event_Init( tBteEvent *pEvent );
static void TscFrIf_Event_Log( tBteEvent *pEvent );

/**********************************************************************************************************************
  Global function definition
**********************************************************************************************************************/


/**********************************************************************************************************************
  Name:         TscFrIf_Init
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void TscFrIf_Init( void )
{
  /* set initial event mask */
  TscFrIf_EventMask_DisableAll();
}

/**********************************************************************************************************************
  Name:         TscFrIf_Cyclic1ms
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void TscFrIf_Cyclic1ms()
{
}

/**********************************************************************************************************************
  Name:         TscFrIf_EventMask_EnableAll
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void TscFrIf_EventMask_EnableAll( void )
{
  BteLog_EventMask_EnableAll( kTscFrIf_CI );
}

/**********************************************************************************************************************
  Name:         TscFrIf_EventMask_DisableAll
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void TscFrIf_EventMask_DisableAll( void )
{
  BteLog_EventMask_DisableAll( kTscFrIf_CI );
}

/**********************************************************************************************************************
  Name:         TscFrIf_EventMask_Enable
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void TscFrIf_EventMask_Enable( uint8 eventId )
{
  BteLog_EventMask_Enable( kTscFrIf_CI, eventId );
}

/**********************************************************************************************************************
  Name:         TscFrIf_EventMask_Disable
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void TscFrIf_EventMask_Disable( uint8 eventId )
{
  BteLog_EventMask_Disable( kTscFrIf_CI, eventId );
}

/*--- specific control ----------------------------------------------------------------------------------------------*/

/*--- test stimulation ----------------------------------------------------------------------------------------------*/

/*--- stub functions ------------------------------------------------------------------------------------------------*/


/**********************************************************************************************************************
  Name:         FrIf_Transmit
  Parameter:    
  Return value: 
  Description:  
  Check:                                              comp       , code                  , data1                               , data2
                TscTest_AssertEventOccurrenceEQ2Data( kTscFrIf_CI, kTscFrIf_FrIf_Transmit, TscFrIf_GetFrIfTxPduIdFromFrTpIdx(0), ActiveFrIfTxPdus[0].pduInfo.SduLength, "FrIf_Transmit", 1);
**********************************************************************************************************************/
Std_ReturnType FrIf_Transmit(PduIdType FrIfTxPduId, P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_MSG_VAR)PduInfoPtr)
{
  tBteEvent evnt;
  
  //  Find zero-based pdu:
  int FrTpPduIdx = TscFrIf_GetFrTpIdxFromFrIfTxPduId(FrIfTxPduId);

  /*--- event handling ---*/
  TscFrIf_Event_Init( &evnt );
  evnt.code = kTscFrIf_FrIf_Transmit;
  evnt.data1 = FrIfTxPduId;
  evnt.data2 = PduInfoPtr->SduLength;
  //memcpy(evnt.data_pdu, PduInfoPtr->SduDataPtr, (uint8)PduInfoPtr->SduLength );
  memcpy(ActiveFrIfTxPdus[FrTpPduIdx].pduInfo.SduDataPtr, PduInfoPtr->SduDataPtr, (uint8)PduInfoPtr->SduLength );
  (void)sprintf( evnt.text_param, "(FrIfTxPduId: %d, FrTpPduIdx:%d, SduLength:%d) ==> %s" , FrIfTxPduId, FrTpPduIdx, PduInfoPtr->SduLength, ((ActiveFrIfTxPdus[FrTpPduIdx].retVal)?"E_NOT_OK":"E_OK"));
  (void)sprintf( evnt.text_name, "FrIf_Transmit" );
  TscFrIf_Event_Log( &evnt );
  
  if(TRUE == FrTp_TxPdus[FrTpPduIdx].FrTp_IsDecoupPdu)
  {
    ActiveFrIfTxPdus[FrTpPduIdx].transmitCalled = TRUE;
    ActiveFrIfTxPdus[FrTpPduIdx].wasTriggered = FALSE;/* wnk at 2012-04-16 hinzugef. */
  }
  else
  {
    ActiveFrIfTxPdus[FrTpPduIdx].wasTriggered = TRUE;
  }
  ActiveFrIfTxPdus[FrTpPduIdx].wasConfirmed = FALSE;/* wnk at 2012-04-16 hinzugef. */

  return ActiveFrIfTxPdus[FrTpPduIdx].retVal;
}


/**********************************************************************************************************************
  Local function definition
**********************************************************************************************************************/
/**********************************************************************************************************************
  Name:          TscFrIf_Event_Init
  Parameter:     
  Return value:  
  Description:   
**********************************************************************************************************************/
static void TscFrIf_Event_Init( tBteEvent *pEvent )
{
  BteEvent_Init( pEvent );
  pEvent->comp = kTscFrIf_CI;
}

/**********************************************************************************************************************
  Name:          TscFrIf_Event_Log
  Parameter:     
  Return value:  
  Description:   
**********************************************************************************************************************/
static void TscFrIf_Event_Log( tBteEvent *pEvent )
{
  BteLog_Event_Log( pEvent );
}

/**********************************************************************************************************************
  EOF
**********************************************************************************************************************/

