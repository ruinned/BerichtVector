/* Test Stub for FrIf */


#ifndef FRIF_H
#define FRIF_H

#include "Std_Types.h"
#include "ComStack_Types.h"


extern FUNC(void, CANIF_APPL_CODE) FrTp_TxConfirmation(PduIdType CanTxPduId);

FUNC(Std_ReturnType, CANIF_CODE) FrIf_Transmit(PduIdType FrTxPduId, P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_MSG_VAR)PduInfoPtr);


#endif