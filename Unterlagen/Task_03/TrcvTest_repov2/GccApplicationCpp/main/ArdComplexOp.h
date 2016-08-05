/*
 * ArdCompexOp.h
 *
 * Created: 2016-07-13 11:16:58
 *  Author: visres
 */ 


#ifndef ARDCOMPLEXOP_H_
#define ARDCOMPLEXOP_H_

#include "Std_Types.h"

//Complex Operation
#define dio_SendRemoteWU              0u
#define dio_SendLocalWU              4u
#define dio_ForceBusCollision   1u
#define dio_ForceTxEnTO         2u
#define dio_VBatDis             3u

#ifdef __cplusplus
extern "C"{
#endif

extern void ArdComplexOp_wakeUpPattern(uint8 aa);

extern void ArdComplexOp_lokalWakeUp(void);

extern void ArdComplexOp_forceBusCollition(void);

extern void ArdComplexOp_forceTxEntimeout(void);

extern void ArdCom_ComplexOP_ClampVbat(uint8 ed);

#ifdef __cplusplus
}
#endif

#endif /* ARDCOMPEXOP_H_ */