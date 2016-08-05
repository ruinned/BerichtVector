#include <windows.h>
#include <stdio.h>
#include "SCI_Driver.h"

HANDLE hComm;



void Sci_Init(uint8 CommPort)
{
  BOOL Status;
  COMMTIMEOUTS timeouts = { 0 };
  DCB dcbSerialParams = { 0 }; // Initializing DCB structure  
  char CommPort_s[10];

  /*------------------------------- Opening the SerialPort ------------------------------*/

  sprintf(CommPort_s,"COM%d",CommPort);
  Sci_OpenCommPort(CommPort_s);

  /*------------------------------- Setting the Parameters for the SerialPort ------------------------------*/
  dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
  Status = GetCommState(hComm, &dcbSerialParams);

  // Configuring the DCB Structure
  dcbSerialParams.BaudRate = CBR_115200;  // Setting BaudRate = 115200
  dcbSerialParams.ByteSize = 8;         // Setting ByteSize = 8
  dcbSerialParams.StopBits = ONESTOPBIT;// Setting StopBits = 1
  dcbSerialParams.Parity   = NOPARITY;  // Setting Parity = None
  Status = SetCommState(hComm, &dcbSerialParams);

  if (Status == FALSE)
  {
    printf ("SetCommState failed with error %d.\n", GetLastError());
  }
  else
  {
    printf("\n   Setting DCB Structure Successfull\n");
    printf("\n       Baudrate = %d", dcbSerialParams.BaudRate);
    printf("\n       ByteSize = %d", dcbSerialParams.ByteSize);
    printf("\n       StopBits = %d", dcbSerialParams.StopBits);
    printf("\n       Parity   = %d", dcbSerialParams.Parity);
  }
  /*------------------------------------ Setting Timeouts --------------------------------------------------*/

  // setting timeouts
  timeouts.ReadIntervalTimeout         = 50; // in milliseconds
  timeouts.ReadTotalTimeoutConstant    = 50; // in milliseconds
  timeouts.ReadTotalTimeoutMultiplier  = 10; // in milliseconds
  timeouts.WriteTotalTimeoutConstant   = 50; // in milliseconds
  timeouts.WriteTotalTimeoutMultiplier = 10; // in milliseconds

  if (SetCommTimeouts(hComm, &timeouts) == FALSE)
  {
    printf("\n   Error! in Setting Time Outs");
  }
  else
  {
    printf("\n\n   Setting Serial Port Timeouts Successfull.\n");
  }

}

/*------------------------------- Opening the SerialPort ------------------------------*/
void Sci_OpenCommPort(uint8 *CommPort)
{

  hComm = CreateFile(CommPort,GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,NULL);
#if defined (ARD_DEBUGGING)
  if (hComm == INVALID_HANDLE_VALUE)
  {
    printf("CreateFile failed with error %d.\n", GetLastError());   
  }
  else 
  {
    printf("\n\n +==========================================+");
    printf("\n |  Serial Transmission (Win32 API)         |");
    printf("\n +==========================================+\n");
    printf("\n Opening serial port %s successful.\n", CommPort);
  }
#endif

}

void Sci_CloseCommPort()
{
  CloseHandle(hComm);
  #if defined (ARD_DEBUGGING)
  if (hComm == INVALID_HANDLE_VALUE)
  {
    printf ("CloseHandle failed with error %d.\n", GetLastError());    
  }
  printf("\n\n Closing ComPort successful.\n");
  printf("\n ==========================================\n\n\n");  
#endif
}


void Sci_Transmit(uint8 *ToSend, uint16 size)
{
  DWORD dNoOfBytesWritten = 0;     // No of bytes written to the port
  BOOL Status;

  Status = WriteFile(hComm, ToSend, size, &dNoOfBytesWritten, NULL);

#if defined (ARD_DEBUGGING)
  if (Status == TRUE)
  {
    if(dNoOfBytesWritten <= 1)
      printf("\n\n    %c - Written to %s", *ToSend, "COM3");
    else
      printf("\n\n    %x %x %x %x - Written to %s", ToSend[0],ToSend[1],ToSend[2],ToSend[3], "COM3");
  }
  else
  {
    printf("\n\n   Error %d in Writing to Serial Port", GetLastError());
  }
#endif

}

// Method blocks
void Sci_Receive(uint8 *ToSave, uint16 size)
{
  DWORD NoBytesRead = 0;                     // Bytes read by ReadFile()

  while(NoBytesRead != size)
    ReadFile(hComm, ToSave, size, &NoBytesRead, NULL); 
#if defined (ARD_DEBUGGING)
  printf("\n\n    Characters Received %x %x %x %x", ToSave[0],ToSave[1],ToSave[2],ToSave[3]);
#endif

}
