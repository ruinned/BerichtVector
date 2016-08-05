/*****************************************************************************
| File Name:   DIO.H
| Description: API of the IO Driver
|****************************************************************************/
#ifndef  DIO_API_H
#define  DIO_API_H 

#include "Std_Types.h"
#include "TscDio_Types.h"
#include "Dio_Cfg.h"
#include "ArduinoCom.h"

void Dio_WriteChannel(Dio_ChannelType DioChannel,Dio_LevelType DioLevel);
Dio_LevelType Dio_ReadChannel(Dio_ChannelType DioChannel);

void Dio_SetTransceiverStatusWord(uint8 reg, uint8 shift, uint16 sw);
void Dio_Init(void);

#endif



