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
/**        \file  ArdCom.c
*        \brief  Arduino communication source file
*
*      \details  Component for dispatching the entry CUT-parameters
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
#include "TscArd.h"
#include "Sci.h"
#include <time.h>

/**********************************************************************************************************************
*  LOCAL CONSTANT MACROS
**********************************************************************************************************************/

#define TscArd_TRCV_COMMAND_VERSION        0x00
#define TscArd_TRCV_DEVICE_MODE       0x10
#define TscArd_TRCV_SET_DIO                0x20
#define TscArd_TRCV_GET_DIO                0x21
#define TscArd_TRCV_STATUS_WORD       0x30
#define TscArd_TRCV_COMPLEXOP              0x40
#define TscArd_TRCV_COMPLEXOP_REMOTEWU     0x41
#define TscArd_TRCV_COMPLEXOP_FORCECOL     0x42
#define TscArd_TRCV_COMPLEXOP_FORCETXTNTO  0x43
#define TscArd_TRCV_COMPLEXOP_VBATDIS      0x44
#define TscArd_TRCV_COMPLEXOP_LOCALWU      0x45
#define TscArd_TRCV_RESETALLDIOPINS        0x60

#define TscArd_ENABLE      1u
#define TscArd_DISABLE     0u

#define kTscArd_DontCare              0x00

/**********************************************************************************************************************
*  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/*! \brief buffer containing the read data */
static uint8  rxMessage[4];

/**********************************************************************************************************************
*  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/***********************************************************************************************************************
*  TscArd_WriteRead()
**********************************************************************************************************************/
/*! \brief     Function for coding the entry parameters to be sent. Sending and receving operation are also called.
*  \details    After codiing a sending operation of the relevant parameters to Arduino is called. At the same time a
*              a receving operation to get the operation results from the actions taken place in the arduino is implemented.
*              Synchron functionality. Application waits until requested data is received.
*              Received data is stored in global variable rxMessage.
*  \param[in]   transfer_0         transfer data 1
*  \param[in]   transfer_1         transfer data 2
*  \param[in]   transfer_2         transfer data 3
*  \param[in]   transfer_3         transfer data 4
*  \return     E_NOT_OK - error
*  \return     E_OK - success
*  \pre        Module must be initialized
**********************************************************************************************************************/
static StatusType TscArd_WriteRead(uint8 transfer_0, uint8 transfer_1, uint8 transfer_2, uint8 transfer_3);

/***********************************************************************************************************************
*  sleep()
**********************************************************************************************************************/
/*! \brief      Function for stopping the excecution for a given time
*  \details    The resolution of the time to stop the application is given in ms
*  \param[in]  mseconds     Given time to stop the excecution
*  \return     -
*  \pre        Module must be initialized
**********************************************************************************************************************/
static void sleep(uint32 mseconds);

/***********************************************************************************************************************
*  TscArd_ComplexOp()
**********************************************************************************************************************/
/*! \brief     Function for dispatching several additional methods.
*  \details    The dispatched methods are tasked with provoking error
*              conditions to set the trcv. status word to a desired value.
*  \param[in]  subId        Dispatching parameter
*              example      subId=TscArd_TRCV_COMPLEXOP_REMOTEWU
*                           subId=TscArd_TRCV_COMPLEXOP_FORCECOL, etc.
*  \param[in]  valueA       parameter to enable/disable a desired functionality.
*              example      valueA = TscArd_ENABLE/TscArd_DISABLE                        
*  \param[in]  valueB       parameter to indicate a number of repetitions for a specific method.
*  \return     -
*  \pre        Module must be initialized
**********************************************************************************************************************/
static void TscArd_ComplexOp(uint8 subId, uint8 valueA, uint8 valueB);

/**********************************************************************************************************************
*  LOCAL FUNCTIONS
**********************************************************************************************************************/

/***********************************************************************************************************************
*  TscArd_WriteRead()
**********************************************************************************************************************/
/*!
* \internal
* - #10 Opening the SerialPort
* - #20 receive the corresponding information of the in arduino board excecuted methode with the given parameter
* \endinternal
*/
static StatusType TscArd_WriteRead(uint8 transfer_0, uint8 transfer_1, uint8 transfer_2, uint8 transfer_3)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 TempChr[4] = {transfer_0, transfer_1, transfer_2, transfer_3};
  /* ----- Implementation ----------------------------------------------- */
  /* #10 transmit the corresponding information of the entry parameter */
  Sci_Transmit(TempChr, 4);
  /* #20 receive the corresponding information of the in arduino board excecuted methode with the given parameter */
  Sci_Receive(rxMessage, 4);
  return (rxMessage[1]) ? E_OK : E_NOT_OK;
}

/***********************************************************************************************************************
*  sleep()
**********************************************************************************************************************/
/*!
* \internal
* - #10 Opening the SerialPort
* - #20 receive the corresponding information of the in arduino board excecuted methode with the given parameter
* \endinternal
*/
static void sleep(uint32 mseconds)
{
  /* ----- Local Variables ---------------------------------------------- */
  clock_t goal = mseconds + clock();
  /* ----- Implementation ----------------------------------------------- */
  while (goal > clock());
}

static void TscArd_ComplexOp(uint8 subId, uint8 valueA, uint8 valueB)
{
  /* ----- Implementation ----------------------------------------------- */
  TscArd_WriteRead(TscArd_TRCV_COMPLEXOP,subId,valueA,valueB);
}

/**********************************************************************************************************************
*  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/***********************************************************************************************************************
*  TscArd_Init()
**********************************************************************************************************************/
/*!
* \internal
* - #10 initialize the serial communication through opening the configured arduino serial port
* - #20 send dummy bytes and wait until arduino has removed them
*   #30 initialization of the tranceiver device mode
* \endinternal
*/
void TscArd_Init()
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 initialize the serial communication through opening the configured arduino serial port */
  Sci_Init(ARD_COMPORT);
  /* #20 send dummy bytes and wait until arduino has removed them */  
  Sci_Transmit("",0);
  sleep(100);
  /* #30 initialization of the tranceiver device mode */    
  TscArd_SetTrcvDeviceMode(TRCV_MODE);
}

/***********************************************************************************************************************
*  ArdCom_Deinit()
**********************************************************************************************************************/
/*!
* \internal
* - #10 Close the configured arduino serial port
* \endinternal
*/
void TscArd_Deinit(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Close the configured arduino serial port */
  Sci_Deinit();
}

/***********************************************************************************************************************
*  TscArd_GetDio()
**********************************************************************************************************************/
/*!
* \internal
*   #10 send a specific message to arduino and receve an appropiate response
* \endinternal
*/
StatusType TscArd_GetDio(uint8 pin, uint8 *readValue)
{
  /* ----- Local Variables ---------------------------------------------- */
  StatusType status = E_NOT_OK;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 send a specific message to arduino and receve an appropiate response */ 
  status = TscArd_WriteRead(TscArd_TRCV_GET_DIO,pin,kTscArd_DontCare,kTscArd_DontCare);
  *readValue = rxMessage[3];
  return status;
}

/***********************************************************************************************************************
*  TscArd_SetDio()
**********************************************************************************************************************/
/*!
* \internal
*   #10 send a specific message to arduino and receve an appropiate response
* \endinternal
*/
StatusType TscArd_SetDio(uint8 pin, uint8 writeValue)
{
  /* ----- Local Variables ---------------------------------------------- */
  StatusType status = E_NOT_OK;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 send a specific message to arduino and receve an appropiate response */
  status = TscArd_WriteRead(TscArd_TRCV_SET_DIO,pin,kTscArd_DontCare,writeValue);
  return status;
}

/***********************************************************************************************************************
*  TscArd_SetTrcvDeviceMode()
**********************************************************************************************************************/
/*!
* \internal
*   #10 send a specific message to arduino and receve an appropiate response
* \endinternal
*/
StatusType TscArd_SetTrcvDeviceMode(uint8 mode)
{
  /* ----- Local Variables ---------------------------------------------- */
  StatusType status = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 send a specific message to arduino and receve an appropiate response */
  status = TscArd_WriteRead(TscArd_TRCV_DEVICE_MODE,mode,kTscArd_DontCare,kTscArd_DontCare);
  return status;
}

/***********************************************************************************************************************
*  TscArd_GetVersion()
**********************************************************************************************************************/
/*!
* \internal
*   #10 send a specific message to arduino and receve an appropiate response
* \endinternal
*/
void TscArd_GetVersion(Std_VersionInfoType *versioninfo)
{

  /* ----- Implementation ----------------------------------------------- */
  /* #10 send a specific message to arduino and receve an appropiate response */
  TscArd_WriteRead(TscArd_TRCV_COMMAND_VERSION,kTscArd_DontCare,kTscArd_DontCare,kTscArd_DontCare);
  versioninfo->sw_major_version = rxMessage[1];
  versioninfo->sw_minor_version = rxMessage[2];
  versioninfo->sw_patch_version = rxMessage[3];
}

/***********************************************************************************************************************
*  TscArd_WriteReadStatusWord()
**********************************************************************************************************************/
/*!
* \internal
*   #10 send a specific message to arduino and receve an appropiate response
* \endinternal
*/
StatusType TscArd_WriteReadStatusWord(uint16 *data, uint8 trcvIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StatusType status = E_NOT_OK;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 send a specific message to arduino and receve an appropiate response */
  status = TscArd_WriteRead(TscArd_TRCV_STATUS_WORD,trcvIdx,(uint8)(*data>>8),(uint8)(*data&0xFF));
  *data = ((uint16)rxMessage[2] << 8) | (uint16)rxMessage[3];
  return status;
}

/***********************************************************************************************************************
*  TscArd_WakeUpPattern()
**********************************************************************************************************************/
/*!
* \internal
* - #10 implement the TscArd_TRCV_COMPLEXOP_REMOTEWU operation to modify the transceiver status word
* \endinternal
*/
void TscArd_WakeUpPattern(uint8 nrOfRepetitions)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 implement the TscArd_TRCV_COMPLEXOP_REMOTEWU operation to modify the transceiver status word */
  TscArd_ComplexOp(TscArd_TRCV_COMPLEXOP_REMOTEWU, kTscArd_DontCare, nrOfRepetitions);
}

/***********************************************************************************************************************
*  TscArd_LokalWakeUp()
**********************************************************************************************************************/
/*!
* \internal
* - #10 implement the TscArd_TRCV_COMPLEXOP_LOCALWU operation to modify the transceiver status word
* \endinternal
*/
void TscArd_LokalWakeUp()
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 implement the TscArd_TRCV_COMPLEXOP_LOCALWU operation to modify the transceiver status word */
  TscArd_ComplexOp(TscArd_TRCV_COMPLEXOP_LOCALWU, kTscArd_DontCare, kTscArd_DontCare);
}

/***********************************************************************************************************************
*  TscArd_ForceBusCollision()
**********************************************************************************************************************/
/*!
* \internal
* - #10 implement the TscArd_TRCV_COMPLEXOP_FORCECOL operation to modify the transceiver status word
* \endinternal
*/
void TscArd_ForceBusCollision()
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 implement the TscArd_TRCV_COMPLEXOP_FORCECOL operation to modify the transceiver status word */
  TscArd_ComplexOp(TscArd_TRCV_COMPLEXOP_FORCECOL, kTscArd_DontCare, kTscArd_DontCare);
}

/***********************************************************************************************************************
*  TscArd_ForceTXENTimeout()
**********************************************************************************************************************/
/*!
* \internal
* - #10 implement the TscArd_TRCV_COMPLEXOP_FORCETXTNTO operation to modify the transceiver status word
* \endinternal
*/
void TscArd_ForceTXENTimeout()
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 implement the TscArd_TRCV_COMPLEXOP_FORCETXTNTO operation to modify the transceiver status word */
  TscArd_ComplexOp(TscArd_TRCV_COMPLEXOP_FORCETXTNTO, kTscArd_DontCare, kTscArd_DontCare);
}

/***********************************************************************************************************************
*  TscArd_ClampVbat()
**********************************************************************************************************************/
/*!
* \internal
* - #10 implement the TscArd_TRCV_COMPLEXOP_VBATDIS operation to modify the transceiver status word
* \endinternal
*/
void TscArd_ClampVbat(uint8 enableOrDisable)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 implement the TscArd_TRCV_COMPLEXOP_VBATDIS operation to modify the transceiver status word */
  TscArd_ComplexOp(TscArd_TRCV_COMPLEXOP_VBATDIS, enableOrDisable, kTscArd_DontCare);
}

/***********************************************************************************************************************
*  TscArd_ResetAllDioPins()
**********************************************************************************************************************/
/*!
* \internal
*   #10 send a specific message to arduino and receve an appropiate response
* \endinternal
*/
void TscArd_ResetAllDioPins()
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 send a specific message to arduino and receve an appropiate response */
  TscArd_WriteRead(TscArd_TRCV_RESETALLDIOPINS,kTscArd_DontCare,kTscArd_DontCare,kTscArd_DontCare);
}

/**********************************************************************************************************************
*  END OF FILE: ArdCom.c
*********************************************************************************************************************/