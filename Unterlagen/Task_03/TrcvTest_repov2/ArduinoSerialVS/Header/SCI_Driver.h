#ifndef SCI_DRIVER_H
#define SCI_DRIVER_H

#include "Std_Types.h"

#define NOTARD_DEBUGGING

void Sci_Init(uint8);
void Sci_OpenCommPort(uint8*);
void Sci_CloseCommPort(void);
void Sci_Receive(uint8*,uint16);
void Sci_Transmit(uint8*,uint16);

#endif