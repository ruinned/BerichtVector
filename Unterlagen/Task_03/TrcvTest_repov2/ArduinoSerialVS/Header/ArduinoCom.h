#ifndef ARDUINOCOM_H
#define ARDUINOCOM_H

#include "Std_Types.h"

typedef struct
{
   uint8  sci_command_version;
   uint8  sw_major_version;
   uint8  sw_minor_version;
   uint8  sw_patch_version;
} ArdCom_VersionInfoType;

/**********************************************************************************************************************
*  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#define arduino_DONTCARE         0x00


uint8 ArdCom_Transceiverdevicemode(uint8 aa);

void ArdCom_GetVersion(ArdCom_VersionInfoType *versioninfo);

uint8 ArdCom_WriteReadTRCVStatusWord(uint8 aa, uint16 *data);

void ArdCom_ComplexOP_ClampVbat(uint8 enableOrDesable);
void ArdCom_ComplexOp_ForceTXENTimeout(void);
void ArdCom_ComplexOp_WakeUpPattern(uint8 nrOfRepetitions);
void ArdCom_ComplexOp_LokalWakeUp(void);
void ArdCom_ComplexOp_ForceBusCollision(void);

uint8 ArCom_DioReadChannel(uint8 nr, uint8 *aa);

uint8 ArCom_DioWriteChannel(uint8 nr, uint8 aa);

void ArCom_ResetAllDioPins(void);

#endif