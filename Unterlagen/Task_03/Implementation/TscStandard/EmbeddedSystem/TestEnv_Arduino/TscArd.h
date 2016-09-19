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
/**        \file  TscArd.h
 *        \brief  Arduino communication header file
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


#ifndef TSCARD_TRCV_H
#define TSCARD_TRCV_H
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "TscArd_Cfg.h"

/**********************************************************************************************************************
*  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  TscArd_Init()
 **********************************************************************************************************************/
/*! \brief      Function for initialization of the serial communication with arduino board
 *  \details    Service to initialize the configurations options of the 
 *              correspondig serial communication port, which is defined in TscArd_Cfg. This service function includes  
 *              also the configuration of the correct ports for the control of the given Transceiver. 
 *  \pre        Module must not be initialized 
 **********************************************************************************************************************/
void TscArd_Init(void);

/***********************************************************************************************************************
 *  ArdCom_Deinit()
 **********************************************************************************************************************/
/*! \brief      Function for stopping the serial communication to the arduino board
 *  \details    Function for stopping the serial communication to the arduino board
 *  \pre        Module must be initialized 
 **********************************************************************************************************************/
void TscArd_Deinit(void);

/***********************************************************************************************************************
 *  TscArd_SetTrcvDeviceMode()
 **********************************************************************************************************************/
/*! \brief      Function for transmitting and setting the corresponding transceiver device mode
 *  \details    Function for transmitting and setting the corresponding transceiver device mode
 *  \param[in]  aa         device mode to be transmited
 *  \return     E_NOT_OK - error 
 *  \return     E_OK - success
 *  \pre        Module must be initialized 
 **********************************************************************************************************************/
StatusType TscArd_SetTrcvDeviceMode(uint8 aa);

/***********************************************************************************************************************
 *  TscArd_GetVersion()
 **********************************************************************************************************************/
/*! \brief      Returns the version information
 *  \details    TscArd_GetVersion() returns version information, vendor ID and AUTOSAR module 
 *              ID of the component.
 *  \param[out] versioninfo             Pointer to where to store the version information
 *  \pre        Module must be initialized  
 **********************************************************************************************************************/
void TscArd_GetVersion(Std_VersionInfoType *versioninfo);

/***********************************************************************************************************************
 *  TscArd_WriteReadStatusWord()
 **********************************************************************************************************************/
/*! \brief      Function for reading or writing a status word
 *  \details    Acording to the transceiver device it is posible to read the 
 *              status word from the transceiver via DIO or SPI interface. 
 *  \param[out] data            Pointer to the data to be sent. This 
 *                              pointer also indicates the place where the read
 *                              status word is going to be stored.
 *  \param[in]  trcvIdx         device mode to be transmited
 *  \return     E_NOT_OK - error 
 *  \return     E_OK - success
 *  \pre        Module must be initialized 
 **********************************************************************************************************************/
StatusType TscArd_WriteReadStatusWord(uint16 *data, uint8 trcvIdx);

/***********************************************************************************************************************
 *  TscArd_ClampVbat()
 **********************************************************************************************************************/
/*! \brief      Function for sending a TscArd_TRCV_COMPLEXOP_VBATDIS command to the arduino
 *  \details    Arduino clamps the VBAT-pin to GRD in order to set the trcv. status word accordingly   
 *  \param[in]  enableOrDesable              parameter to enable/disable a desired functionality.
 *                                           0 to clamp VBAT to GND
 *                                           1 to restore the normal state
 *  \return     -
 *  \pre        Module must be initialized 
 **********************************************************************************************************************/
void TscArd_ClampVbat(uint8 enableOrDesable);

/***********************************************************************************************************************
 *  TscArd_ForceTXENTimeout()
 **********************************************************************************************************************/
/*! \brief      Function for sending a TscArd_TRCV_COMPLEXOP_FORCETXTNTO command to the ardiuno
 *  \details    Arduino resets corresponding TXEN pin until for the corresponding time out
 *              flag in the trcv. status word is set
 *  \pre        Module must be initialized 
 **********************************************************************************************************************/
void TscArd_ForceTXENTimeout(void);

/***********************************************************************************************************************
 *  TscArd_WakeUpPattern()
 **********************************************************************************************************************/
/*! \brief      Function for sending a TscArd_TRCV_COMPLEXOP_REMOTEWU command to the ardiuno
 *  \details    Arduino controls the TXD line of the helping trcv. to send a remote wakeup pattern 
 *  \param[in]  nrOfRepetitions    parameter to indicate the number of times the wakeup pattern to
 *                                 be repeted
 *  \pre        Module must be initialized 
 **********************************************************************************************************************/
void TscArd_WakeUpPattern(uint8 nrOfRepetitions);

/***********************************************************************************************************************
 *  TscArd_LokalWakeUp()
 **********************************************************************************************************************/
/*! \brief      Function for sending a TscArd_TRCV_COMPLEXOP_LOCALWU command to the ardiuno
 *  \details    Arduino controls the WAKE pin of the trcv. to provoque a local wakeup pattern 
 *  \pre        Module must be initialized 
 **********************************************************************************************************************/
void TscArd_LokalWakeUp(void);

/***********************************************************************************************************************
 *  TscArd_ForceBusCollision()
 **********************************************************************************************************************/
/*! \brief      Function to provoque a bus collition in the bus line by means of a TscArd_TRCV_COMPLEXOP_FORCECOL command
 *  \details    Arduino controls the corresponding TXD pin of both the helping and test trcv. to provoque a 
 *              bus line collition. Bus error flag in the trcv. status word is set.
 *  \pre        Module must be initialized 
 **********************************************************************************************************************/
void TscArd_ForceBusCollision(void);

/***********************************************************************************************************************
 *  TscArd_GetDio()
 **********************************************************************************************************************/
/*! \brief      Function for reading the status of a given pin in a specific DIO channel
 *  \details    Function for reading the status of a given pin in a specific DIO channel  
 *  \param[in]  nr            Channel number
 *  \param[out] aa            Pointer to the variable where the pin status has to be stored
 *  \return     E_NOT_OK - error 
 *  \return     E_OK - success
 *  \pre        Module must be initialized 
 **********************************************************************************************************************/
StatusType TscArd_GetDio(uint8 pin, uint8 *readValue);

/***********************************************************************************************************************
 *  TscArd_SetDio()
 **********************************************************************************************************************/
/*! \brief      Function for changing the status of the given pin in a specific DIO Channel
 *  \details    Function for changing the status of the given pin in a specific DIO Channel
 *  \param[in]  nr       Channel number
 *  \param[in]  aa       Pin Status for the pin to be writen 
 *  \return     E_NOT_OK - error
 *  \return     E_OK - success
 *  \pre        Module must be initialized 
 **********************************************************************************************************************/
StatusType TscArd_SetDio(uint8 pin, uint8 writeValue);

/***********************************************************************************************************************
 *  TscArd_SetDio()
 **********************************************************************************************************************/
/*! \brief      Function for reseting the status of the DIO pins to the initial status
 *  \details    Function for reseting the status of the DIO pins to the initial status
 *  \param[in]  -
 *  \return     -
 *  \pre        Module must be initialized 
 **********************************************************************************************************************/
void TscArd_ResetAllDioPins(void);

#endif

/**********************************************************************************************************************
 *  END OF FILE: TscArd.h
 *********************************************************************************************************************/