#include "DIO.h"
#include "ArduinoCom.h"

void Dio_WriteChannel(uint8 Channel, uint8 value)
{
  ArCom_DioWriteChannel(Channel, value);
}

uint8 Dio_ReadChannel(uint8 Channel)
{
  uint8 retVal = 0;
  ArCom_DioReadChannel(Channel, &retVal);
  return retVal;
}




