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
         File:  TscFrIf.h
      Project:  Tsc for FrTp
       Module:  -
    Generator:  -
  Description:  Stub for FrIf
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

#ifndef V_TSCCANIF_HEADER
#define V_TSCCANIF_HEADER

/**********************************************************************************************************************
  Includes
**********************************************************************************************************************/
#include "Std_Types.h"
#include "FrIf.h"
#include "TscTest.h"


/**********************************************************************************************************************
  Version data
**********************************************************************************************************************/
#define TSCFRIF_VERSION                                                     0x0100
#define TSCFRIF_RELEASE_VERSION                                             0x00

/**********************************************************************************************************************
  Global configuration
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global data defines
**********************************************************************************************************************/
#define kTscFrIf_CI                                                         0x01

/*--- stub functions ------------------------------------------------------------------------------------------------*/
#define kTscFrIf_FrIf_Transmit                                              0x80


/**********************************************************************************************************************
  Global macro defines
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global typedefs
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global data prototypes (RAM)
**********************************************************************************************************************/
#define MAX_FRIF_TX_PDUS 50
#define MAX_FRIF_RX_PDUS 50

typedef struct
{
  Std_ReturnType retVal;
  boolean toBeSentToDut;
  boolean transmitCalled;
  boolean wasTriggered;
  boolean wasConfirmed;
  PduInfoType pduInfo;
  PduLengthType pduLenCfgrd;
  char payload[254];
} ActiveFrIfTxPduType;

typedef struct
{
  boolean toBeSentToDut;
  PduInfoType pduInfo;
  PduLengthType pduLenCfgrd;
  char payload[254];
} ActiveFrIfRxPduType;

extern const ActiveFrIfTxPduType ActiveFrIfTxPduInitConst;
extern const ActiveFrIfRxPduType ActiveFrIfRxPduInitConst;

extern ActiveFrIfTxPduType ActiveFrIfTxPdus[MAX_FRIF_TX_PDUS];
extern ActiveFrIfRxPduType ActiveFrIfRxPdus[MAX_FRIF_RX_PDUS];

static uint8 txPayload[MAX_FRIF_TX_PDUS][254];

/**********************************************************************************************************************
  Global data prototypes (ROM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global function prototypes
**********************************************************************************************************************/
/*--- generic control -----------------------------------------------------------------------------------------------*/
extern void TscFrIf_Init( void );
extern void TscFrIf_Cyclic1ms( void );
extern void TscFrIf_EventMask_EnableAll( void );
extern void TscFrIf_EventMask_DisableAll( void );
extern void TscFrIf_EventMask_Enable( uint8 eventId );
extern void TscFrIf_EventMask_Disable( uint8 eventId );

/*--- specific control ----------------------------------------------------------------------------------------------*/

/*--- test stimulation ----------------------------------------------------------------------------------------------*/
extern int TscFrIf_GetPduLenForConn(int conn, boolean isTx);
extern int TscFrIf_GetFrIfTxPduIdFromFrTpIdx(int idx);
extern int TscFrIf_GetFrTpIdxFromFrIfTxPduId(int idx);
extern int TscFrIf_GetFrIfRxPduIdForConn(int conn);
extern int TscFrIf_GetTxConfedFrIfTxPduIdx(int conn);
extern int TscFrIf_GetTxConfedFrIfTxPduIdx(int conn);
extern int TscFrIf_GetFrIfTxPduByLocConnIdx(int conn, int locIdx);
extern int TscFrIf_GetMaxLocConnIdxForFrIfTxPdus(int conn, int locIdx);
extern void TscFrIf_InitializeTxPdus(void);
extern void TscFrIf_InitializeRxPdus(void);
extern void TscFrIf_CallTriggerTransmit();
extern void TscFrIf_CallTxConfirmation();
extern void TscFrIf_CallRxIndication();

/*--- stub functions ------------------------------------------------------------------------------------------------*/
/* prototypes defined in own header, e.g. can_inc.h */

#endif /* V_TSCCANIF_HEADER */
/**********************************************************************************************************************
  EOF
**********************************************************************************************************************/
