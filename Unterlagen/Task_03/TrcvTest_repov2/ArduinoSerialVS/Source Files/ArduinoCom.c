#include "ArduinoCom.h"
#include "SCI_Driver.h"

static uint8  rxMessage[4];

void ArdCom_FillTxRx(uint8 *sendBuff);

void ArdCom_ComplexOp(uint8 nr, uint8 ed, uint8 aa);

void ArdCom_FillTxRx(uint8 *sendBuff)
{
  Sci_Transmit(sendBuff, 4);
  Sci_Receive(rxMessage, 4);
}

uint8 ArCom_DioReadChannel(uint8 nr, uint8 *aa)
{
  uint8 TempChr[4] = {0x21, nr, 0x00, 0x00};
  ArdCom_FillTxRx(TempChr);
  *aa = rxMessage[3];
  return rxMessage[1];
}

uint8 ArCom_DioWriteChannel(uint8 nr, uint8 aa)
{
  uint8 TempChr[4] = {0x20, nr, 0x00, aa};
  ArdCom_FillTxRx(TempChr);
  return rxMessage[1];
}

uint8 ArdCom_Transceiverdevicemode(uint8 aa)
{
  uint8 TempChr[4] = {0x10, aa, 0x00, 0x00};
  ArdCom_FillTxRx(TempChr);
  return rxMessage[1];
}

void ArdCom_GetVersion(ArdCom_VersionInfoType *versioninfo)
{
  uint8 TempChr[4] = {0x00, 0x00, 0x00, 0x00};
  ArdCom_FillTxRx(TempChr);
  versioninfo->sci_command_version = rxMessage[0];
  versioninfo->sw_major_version = rxMessage[1];
  versioninfo->sw_minor_version = rxMessage[2];
  versioninfo->sw_patch_version = rxMessage[3];
}

uint8 ArdCom_WriteReadTRCVStatusWord(uint8 aa, uint16 *data)
{
  uint8 TempChr[4] = {0x30, aa, (uint8)(*data>>8), (uint8)(*data&0xFF)};
  ArdCom_FillTxRx(TempChr);
  *data = ((uint16)rxMessage[2] << 8) | (uint16)rxMessage[3];
  return rxMessage[1];
}

void ArdCom_ComplexOp(uint8 nr, uint8 ed, uint8 aa)
{
  uint8 TempChr[4] = {0x40, nr, ed, aa};
  ArdCom_FillTxRx(TempChr);
}

void ArdCom_ComplexOp_WakeUpPattern(uint8 nrOfRepetitions)
{
  ArdCom_ComplexOp(0x00, arduino_DONTCARE, nrOfRepetitions);
}

void ArdCom_ComplexOp_LokalWakeUp()
{
  ArdCom_ComplexOp(0x04, arduino_DONTCARE, arduino_DONTCARE);
}

void ArdCom_ComplexOp_ForceBusCollision()
{
  ArdCom_ComplexOp(0x01, arduino_DONTCARE, arduino_DONTCARE);
}

void ArdCom_ComplexOp_ForceTXENTimeout()
{
  ArdCom_ComplexOp(0x02, arduino_DONTCARE, arduino_DONTCARE);
}

void ArdCom_ComplexOP_ClampVbat(uint8 enableOrDesable)
{
  ArdCom_ComplexOp(0x03, enableOrDesable, arduino_DONTCARE);
}

void ArCom_ResetAllDioPins()
{
  uint8 TempChr[4] = {0x60, 0x00, 0x00, 0x00};
  ArdCom_FillTxRx(TempChr);
}