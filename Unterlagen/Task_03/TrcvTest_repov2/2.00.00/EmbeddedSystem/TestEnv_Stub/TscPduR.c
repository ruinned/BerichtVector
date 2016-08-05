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
         File:  TscPduR.c
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

#define V_TSCPDUR_SOURCE

/**********************************************************************************************************************
  Includes
**********************************************************************************************************************/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include "string.h"

#include "TscTest.h"
#include "TscPduR.h"
#include "TscAppl.h"

#include "BteLog.h"

/**********************************************************************************************************************
  Version check
**********************************************************************************************************************/
#if ( TSCPDUR_VERSION != 0x0100 )
  #error "Header and Source file are inconsistent (version)!"
#endif
#if ( TSCPDUR_RELEASE_VERSION != 0x00 )
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

ConnStateType ActiveConns[MAX_NUM_CONCURRENT_TRANSFERS];
ActiveConnIdxs[MAX_NUM_CONCURRENT_TRANSFERS];

/**********************************************************************************************************************
  Global data definitions (ROM)
**********************************************************************************************************************/
uint8 TestPayload[MAX_NUM_CONCURRENT_TRANSFERS][4096];

extern const ConnStateType connStateInitConst =
{
  BUFREQ_OK, /* BufReq_ReturnType rxBufReqRetVal; */
  BUFREQ_OK, /* BufReq_ReturnType txBufReqRetVal; */
  NULL_PTR, /* PduInfoType* rxPduInfoPtr; */
  NULL_PTR, /* PduInfoType* txPduInfoPtr; */
  {
    NULL_PTR,
    0
  }, /* PduInfoType rxPduInfo; */
  {
    NULL_PTR,
    0
  }, /* PduInfoType txPduInfo; */
  0, /* uint32 rxDataIdx; */
  0, /* uint32 txDataIdx; */
  FALSE, /* boolean txRetryActive; */
  FALSE, /* boolean rxRetryActive; */
  0x20u, /* uint8 txCFType; */
  0x20u, /* uint8 rxCFType; */
  1, /* uint8 txSN; */
  1, /* uint8 rxSN; */
  0, /* uint8 txCurrBS; */
  0, /* uint8 rxCurrBS; */
  0, /* uint8 rxStMin; */
  0, /* uint8 rxBlockSize; */
  0, /* uint8 rxFlowStatus; */
};

/**********************************************************************************************************************
  Local data definitions (RAM)
**********************************************************************************************************************/
static uint8 PduR_Buf1[4096];
static uint8 PduR_Buf2[4096];
static uint8 PduR_Buf3[4096];
static uint8 PduR_Buf4[4096];
static uint8 PduR_Buf5[4096];
static uint8 PduR_Buf6[4096];
static uint8 PduR_Buf7[4096];
static uint8 PduR_Buf8[4096];
static uint8 PduR_Buf9[4096];
static uint8 PduR_Buf10[4096];


/**********************************************************************************************************************
  Local data definitions (ROM)
**********************************************************************************************************************/
const uint8* PduR_Buffers[10] = {
  PduR_Buf1,
  PduR_Buf2,
  PduR_Buf3,
  PduR_Buf4,
  PduR_Buf5,
  PduR_Buf6,
  PduR_Buf7,
  PduR_Buf8,
  PduR_Buf9,
  PduR_Buf10,
};

/**********************************************************************************************************************
  Local function prototypes
**********************************************************************************************************************/
static void TscPduR_Event_Init( tBteEvent *pEvent );
static void TscPduR_EventMask_DisableAll( void );

/**********************************************************************************************************************
  Global function definition
**********************************************************************************************************************/
/*--- generic control -----------------------------------------------------------------------------------------------*/
/**********************************************************************************************************************
  Name:         TscPduR_InitializeActiveConns
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void TscPduR_InitializeActiveConns(void)
{
  int i = MAX_NUM_CONCURRENT_TRANSFERS;
  while(i > 0)
  {
    i--;
    ActiveConns[i] = connStateInitConst;
    ActiveConns[i].rxPduInfoPtr = &(ActiveConns[i].rxPduInfo);
    ActiveConns[i].txPduInfoPtr = &(ActiveConns[i].txPduInfo);
    ActiveConns[i].rxPduInfo.SduDataPtr = &(TestPayload[i][0]);
    ActiveConns[i].txPduInfo.SduDataPtr = &(TestPayload[i][0]);
    ActiveConnIdxs[i] = INVALID_CONN;
  }
}
/**********************************************************************************************************************
  Name:         TscPduR_Init
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void TscPduR_Init( void )
{
  /* set initial event mask */
  TscPduR_EventMask_DisableAll();
}

/**********************************************************************************************************************
  Name:         TscPduR_Cyclic1ms
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void TscPduR_Cyclic1ms()
{
}

/**********************************************************************************************************************
  Name:         TscPduR_EventMask_EnableAll
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void TscPduR_EventMask_EnableAll( void )
{
  BteLog_EventMask_EnableAll( kTscPduR_CI );
}

/**********************************************************************************************************************
  Name:         TscPduR_EventMask_DisableAll
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void TscPduR_EventMask_DisableAll( void )
{
  BteLog_EventMask_DisableAll( kTscPduR_CI );
}

/**********************************************************************************************************************
  Name:         TscPduR_EventMask_Enable
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void TscPduR_EventMask_Enable( uint8 eventId )
{
  BteLog_EventMask_Enable( kTscPduR_CI, eventId );
}

/**********************************************************************************************************************
  Name:         TscPduR_EventMask_Disable
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
void TscPduR_EventMask_Disable( uint8 eventId )
{
  BteLog_EventMask_Disable( kTscPduR_CI, eventId );
}

/*--- specific control ----------------------------------------------------------------------------------------------*/

/*--- test stimulation ----------------------------------------------------------------------------------------------*/

/*--- stub functions ------------------------------------------------------------------------------------------------*/

/**********************************************************************************************************************
  Name:         
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_FrTpProvideTxBuffer(PduIdType FrTpTxPduId, P2VAR(PduInfoTypeApplPtr, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr, uint16 Length)
{
  tBteEvent evnt;
  char Result[32];

  /*--- event handling ---*/
  TscPduR_Event_Init( &evnt );
  evnt.code = kTscPduR_PduR_FrTpProvideTxBuffer;
  evnt.data1 = (vuint8)FrTpTxPduId;
  evnt.data2 = Length;
  TscTest_PrintBufReqResult(ActiveConns[TscAppl_GetActiveConnIdx(FrTpTxPduId)].txBufReqRetVal, Result);
  (void)sprintf( evnt.text_param, "FrTpTxPduId: %d, PduInfoPtr: %d, Result: %s", FrTpTxPduId, (uint32)(PduInfoPtr), Result);
  (void)sprintf( evnt.text_name, "PduR_FrTpProvideTxBuffer");
  BteLog_Event_Log( &evnt );
  
  // Provide the desired buffer
  *PduInfoPtr = ActiveConns[TscAppl_GetActiveConnIdx(FrTpTxPduId)].txPduInfoPtr;
  return ActiveConns[TscAppl_GetActiveConnIdx(FrTpTxPduId)].txBufReqRetVal;
}

/**********************************************************************************************************************
  Name:         
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
BufReq_ReturnType PduR_FrTpProvideRxBuffer(PduIdType FrTpRxPduId, PduLengthType TpSduLength, PduInfoType **PduInfoPtr)
{
  tBteEvent evnt;
  char Result[32];

  /*--- event handling ---*/
  TscPduR_Event_Init( &evnt );
  evnt.code = kTscPduR_PduR_FrTpProvideRxBuffer;
  evnt.data1 = (vuint8)FrTpRxPduId;
  evnt.data2 = TpSduLength;
  (void)sprintf( evnt.text_param, "FrTpRxPduId: %d", FrTpRxPduId);
  TscTest_PrintBufReqResult(ActiveConns[TscAppl_GetActiveConnIdx(FrTpRxPduId)].rxBufReqRetVal, Result);
  (void)sprintf( evnt.text_name, "PduR_FrTpProvideRxBuffer(TpSduLength=%d) --> %s", TpSduLength, Result );
  BteLog_Event_Log( &evnt );
  
  // Provide the desired buffer
  *PduInfoPtr = ActiveConns[TscAppl_GetActiveConnIdx(FrTpRxPduId)].rxPduInfoPtr;
  return ActiveConns[TscAppl_GetActiveConnIdx(FrTpRxPduId)].rxBufReqRetVal;
}


/**********************************************************************************************************************
  Name:         
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
extern FUNC(void, PDUR_CODE) PduR_FrTpRxIndication(PduIdType FrTpRxPduId, NotifResultType NotifResult)
{
  char Result[32];
  tBteEvent evnt;
  
  /*--- event handling ---*/
  TscPduR_Event_Init( &evnt );
  evnt.code = kTscPduR_PduR_FrTpRxIndication;
  evnt.data1 = (vuint8)FrTpRxPduId;
  evnt.data2  = NotifResult;
  TscTest_PrintNotifResult(NotifResult, Result);
  (void)sprintf( evnt.text_param, "FrTpRxPduId: %d, NotifResult: %s", FrTpRxPduId, Result);
  (void)sprintf( evnt.text_name, "PduR_FrTpRxIndication" );
  BteLog_Event_Log( &evnt );
}

/**********************************************************************************************************************
  Name:         
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_FrTpTxConfirmation(PduIdType FrTpTxPduId, NotifResultType NotifResult)
{
  char Result[32];
  tBteEvent evnt;

  /*--- event handling ---*/
  TscPduR_Event_Init( &evnt );
  evnt.code = kTscPduR_PduR_FrTpTxConfirmation;
  evnt.data1 = (vuint8)FrTpTxPduId;
  evnt.data2 = NotifResult;
  TscTest_PrintNotifResult(NotifResult, Result);
  (void)sprintf( evnt.text_param, "FrTpTxPduId: %d, Result: %d (%s)"
                                  ,FrTpTxPduId, NotifResult, Result);
  (void)sprintf( evnt.text_name, "PduR_FrTpTxConfirmation" );

  BteLog_Event_Log( &evnt );
}
/**********************************************************************************************************************
  Local function definition
**********************************************************************************************************************/
/**********************************************************************************************************************
  Name:          TscPduR_Event_Init
  Parameter:     
  Return value:  
  Description:   
**********************************************************************************************************************/
static void TscPduR_Event_Init( tBteEvent *pEvent )
{
  BteEvent_Init( pEvent );
  pEvent->comp = kTscPduR_CI;
  pEvent->type = kBteEventType_Command;
}

/**********************************************************************************************************************
  EOF
**********************************************************************************************************************/

