/**********************************************************************************************************************
*  COPYRIGHT
*  -------------------------------------------------------------------------------------------------------------------
*  \verbatim
*  Copyright (c) 2016 by Vector Informatik GmbH.                                              All rights reserved.
*
*                This software is copyright protected and proprietary to Vector Informatik GmbH.
*                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
*                All other rights remain with Vector Informatik GmbH.
*  \endverbatim
*  -------------------------------------------------------------------------------------------------------------------
*  FILE DESCRIPTION
*  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Sci.c
*        \brief  SCI Driver source file
*
*      \details  Component to manage the communication between BTE and Arduino-Board
*
*********************************************************************************************************************/

/**********************************************************************************************************************
*  AUTHOR IDENTITY
*  -------------------------------------------------------------------------------------------------------------------
*  Name                          Initials      Company
*  -------------------------------------------------------------------------------------------------------------------
*  Samir Revelo                   visres       Vector Informatik GmbH
*  -------------------------------------------------------------------------------------------------------------------
*  REVISION HISTORY
*  -------------------------------------------------------------------------------------------------------------------
*  Version   Date        Author  Change Id     Description
*  -------------------------------------------------------------------------------------------------------------------
*  01.00.00  2016-08-08  visres                Creation
*********************************************************************************************************************/

/**********************************************************************************************************************
*  INCLUDES
*********************************************************************************************************************/
#include <windows.h>
#include <stdio.h>
#include "Sci.h"

/**********************************************************************************************************************
*  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/*! \brief Configuration struct for serial port */
static HANDLE hComm;

/**********************************************************************************************************************
*  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
*  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
*  GLOBAL FUNCTIONS
**********************************************************************************************************************/

/***********************************************************************************************************************
*  Sci_Init()
**********************************************************************************************************************/
/*!
* \internal
* - #10 Opening the SerialPort
* - #20 Configuring the DCB Structure
* - #30 setting the timeout conditions. Specifications in ms
* \endinternal
*/
void Sci_Init(uint8 CommPort)
{
  /* ----- Local Variables ---------------------------------------------- */
  BOOL Status;
  COMMTIMEOUTS timeouts = { 0 };
  DCB dcbSerialParams = { 0 }; 
  char CommPort_s[10];

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Opening the SerialPort */
  (void)sprintf(CommPort_s,"COM%d",CommPort);
  hComm = CreateFile(CommPort_s,GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,NULL);
#if defined (SCI_DEBUGGING)
  if (hComm == INVALID_HANDLE_VALUE)
  {
    printf("CreateFile failed with error %d.\n", GetLastError());   
  }
  else 
  {
    printf("\n\n +==========================================+");
    printf("\n |  Serial Transmission (Win32 API)         |");
    printf("\n +==========================================+\n");
    printf("\n Opening serial port %s successful.\n", CommPort_s);
  }
#endif

  /* #20 Configuring the DCB Structure */ 
  dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
  GetCommState(hComm, &dcbSerialParams);
  dcbSerialParams.BaudRate = CBR_115200;  
  dcbSerialParams.ByteSize = 8;         
  dcbSerialParams.StopBits = ONESTOPBIT;
  dcbSerialParams.Parity   = NOPARITY;  
  Status = SetCommState(hComm, &dcbSerialParams);

#if defined (SCI_DEBUGGING)
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
#endif

  /* #30 setting the timeout conditions. Specifications in ms */   
  timeouts.ReadIntervalTimeout         = 50; 
  timeouts.ReadTotalTimeoutConstant    = 50; 
  timeouts.ReadTotalTimeoutMultiplier  = 10; 
  timeouts.WriteTotalTimeoutConstant   = 50; 
  timeouts.WriteTotalTimeoutMultiplier = 10; 
  Status = SetCommTimeouts(hComm, &timeouts);

#if defined (SCI_DEBUGGING)
  if (Status == FALSE)
  {
    printf("\n   Error! in Setting Time Outs");
  }
  else
  {
    printf("\n\n   Setting Serial Port Timeouts Successfull.\n");
  }
#endif
}

/***********************************************************************************************************************
*  Sci_Deinit()
**********************************************************************************************************************/
/*!
* \internal
* - #10 Closing the serial port 
* \endinternal
*/
void Sci_Deinit()
{
  /* ----- Implementation ----------------------------------------------- */

  /* #10 Closing the serial port */   
  CloseHandle(hComm);
#if defined (SCI_DEBUGGING)
  if (hComm == INVALID_HANDLE_VALUE)
  {
    printf ("CloseHandle failed with error %d.\n", GetLastError());    
  }
  printf("\n\n Closing ComPort successful.\n");
  printf("\n ==========================================\n\n\n");  
#endif
}

/***********************************************************************************************************************
*  Sci_Transmit()
**********************************************************************************************************************/
/*!
* \internal
* - #10 write data to the serial port 
* \endinternal
*/
void Sci_Transmit(uint8 *ToSend, uint16 size)
{
  /* ----- Local Variables ---------------------------------------------- */
  DWORD dNoOfBytesWritten = 0;     
  BOOL Status;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 write data to the serial port */
  Status = WriteFile(hComm, ToSend, size, &dNoOfBytesWritten, NULL);

#if defined (SCI_DEBUGGING)
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

/***********************************************************************************************************************
*  Sci_Receive()
**********************************************************************************************************************/
/*!
* \internal
* - #10 receive data from the serial port 
* \endinternal
*/
void Sci_Receive(uint8 *ToSave, uint16 size)
{
  /* ----- Local Variables ---------------------------------------------- */
  // Bytes read by ReadFile()
  DWORD NoBytesRead = 0;                     

  /* ----- Implementation ----------------------------------------------- */

  /* #10 receive data from the serial port */
  while(NoBytesRead != size)
    ReadFile(hComm, ToSave, size, &NoBytesRead, NULL); 
#if defined (SCI_DEBUGGING)
  printf("\n\n    Characters Received %x %x %x %x", ToSave[0],ToSave[1],ToSave[2],ToSave[3]);
#endif

}

/**********************************************************************************************************************
 *  END OF FILE: Sci.c
 *********************************************************************************************************************/