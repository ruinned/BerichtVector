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
         File:  TscPduR.h
      Project:  Tsc for FrTp
       Module:  -
    Generator:  -
  Description:  Stub for PduR
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

#ifndef V_TSCPDUR_HEADER
#define V_TSCPDUR_HEADER

/**********************************************************************************************************************
  Includes
**********************************************************************************************************************/
#include "Std_Types.h"
#include "PduR.h"


/**********************************************************************************************************************
  Version data
**********************************************************************************************************************/
#define TSCPDUR_VERSION                                                     0x0100
#define TSCPDUR_RELEASE_VERSION                                             0x00

/**********************************************************************************************************************
  Global configuration
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global data defines
**********************************************************************************************************************/
#define kTscPduR_CI                                                         0x02

/*--- stub functions ------------------------------------------------------------------------------------------------*/
#define kTscPduR_PduR_FrTpProvideRxBuffer           0x80
#define kTscPduR_PduR_FrTpProvideTxBuffer           0x81
#define kTscPduR_PduR_FrTpRxIndication              0x82
#define kTscPduR_PduR_FrTpTxConfirmation            0x83


/**********************************************************************************************************************
  Global macro defines
**********************************************************************************************************************/
#define MAX_NUM_CONCURRENT_TRANSFERS 10
#define INVALID_CONN (MAX_NUM_CONCURRENT_TRANSFERS)

/**********************************************************************************************************************
  Global typedefs
**********************************************************************************************************************/
typedef P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoTypeApplPtr;

typedef struct 
{
  BufReq_ReturnType rxBufReqRetVal;
  BufReq_ReturnType txBufReqRetVal;
  PduInfoType* rxPduInfoPtr;
  PduInfoType* txPduInfoPtr;
  PduInfoType rxPduInfo;
  PduInfoType txPduInfo;
  uint32 rxDataIdx;
  uint32 txDataIdx;
  boolean txRetryActive;
  boolean rxRetryActive;
  uint8 txCFType;
  uint8 rxCFType;
  uint8 txSN;
  uint8 rxSN;
  uint8 txCurrBS;
  uint8 rxCurrBS;
  uint8 rxStMin;
  uint8 rxBlockSize;
  uint8 rxFlowStatus;
} ConnStateType;

/**********************************************************************************************************************
  Global data prototypes (RAM)
**********************************************************************************************************************/
/* Payload handling */
extern uint8 TestPayload[MAX_NUM_CONCURRENT_TRANSFERS][4096];

extern const ConnStateType connStateInitConst;
extern ConnStateType ActiveConns[MAX_NUM_CONCURRENT_TRANSFERS];
extern ActiveConnIdxs[MAX_NUM_CONCURRENT_TRANSFERS];

/**********************************************************************************************************************
  Global data prototypes (ROM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global function prototypes
**********************************************************************************************************************/
/*--- generic control -----------------------------------------------------------------------------------------------*/
extern void TscPduR_InitializeActiveConns( void );
extern void TscPduR_Init( void );
extern void TscPduR_Cyclic1ms( void );
extern void TscPduR_EventMask_EnableAll( void );
extern void TscPduR_EventMask_DisableAll( void );
extern void TscPduR_EventMask_Enable( uint8 eventId );
extern void TscPduR_EventMask_Disable( uint8 eventId );

/*--- specific control ----------------------------------------------------------------------------------------------*/

/*--- test stimulation ----------------------------------------------------------------------------------------------*/
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_FrTpProvideTxBuffer(PduIdType FrTpTxPduId, P2VAR(PduInfoTypeApplPtr, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr, uint16 Length);
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_FrTpProvideRxBuffer(PduIdType FrTpRxPduId, PduLengthType TpSduLength, PduInfoType **PduInfoPtr);

/*--- stub functions ------------------------------------------------------------------------------------------------*/
/* prototypes defined in own header, e.g. can_inc.h */

#endif /* V_TSCPDUR_HEADER */
/**********************************************************************************************************************
  EOF
**********************************************************************************************************************/
