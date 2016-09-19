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
/**        \file  Sci.h
 *        \brief  SCI Driver header file
 *
 *      \details  Component to manage the communication between serial communication port and Arduino-Board
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

#ifndef SCI_H
#define SCI_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* console error debugging for initialisation of serial port */
//#define SCI_DEBUGGING

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/* Service functions */

/***********************************************************************************************************************
 *  Sci_Init()
 **********************************************************************************************************************/
/*! \brief      Function for configuration and opening of serial communication port
 *  \details    Service to initialize the configurations options of the 
 *              given serial communication port. This service function includes  
 *              also the opening of the serial communication port. 
 *  \param[in]  CommPort                 The selected serial communication port
 *  \pre        Module must not be initialized 
 **********************************************************************************************************************/
void Sci_Init(uint8);

/***********************************************************************************************************************
 *  Sci_Deinit()
 **********************************************************************************************************************/
/*! \brief      Function for closing the serial communication port
 *  \details    Function for closing the serial communication port
 *  \pre        Module must be initialized 
 **********************************************************************************************************************/
void Sci_Deinit(void);

/***********************************************************************************************************************
 *  Sci_Receive()
 **********************************************************************************************************************/
/*! \brief      Function for synchron data reception from serial communication port
 *  \details    Function works synchron. Application waits until requested data is received
 *  \param[out] ToSave               buffer to save incomming data
 *  \param[in]  size                 number of bytes to receive
 *  \pre        Module must be initialized 
 **********************************************************************************************************************/
void Sci_Receive(uint8*,uint16);

/***********************************************************************************************************************
 *  Sci_Transmit()
 **********************************************************************************************************************/
/*! \brief      Function for data transmition through serial communication port
 *  \details    Function works asynchron. Application sends data 
 *              and does not stop for completion of data transmition
 *  \param[out] ToSave               buffer to save incomming data
 *  \param[in]  size                 number of bytes to receive
 *  \pre        Module must be initialized 
 **********************************************************************************************************************/
void Sci_Transmit(uint8*,uint16);

#endif /* SCI_H */

/**********************************************************************************************************************
 *  END OF FILE: Sci.h
 *********************************************************************************************************************/