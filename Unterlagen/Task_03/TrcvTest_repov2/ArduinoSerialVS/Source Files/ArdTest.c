#include "ArdTest.h"
#include "ArduinoCom.h"
#include "SCI_Driver.h"
#include <time.h>

void sleep(unsigned int mseconds);

void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void ArdTest_Init(uint8 mode, uint8 ComPort)
{
  Sci_Init(ComPort);
  //send dummy bytes and wait until arduino has removed them
  Sci_Transmit("",0);
  sleep(250);
  //initialization of the tranceiver mode
  ArdCom_Transceiverdevicemode(mode);
}

void ArdTest_Deinit()
{
  Sci_CloseCommPort();
}