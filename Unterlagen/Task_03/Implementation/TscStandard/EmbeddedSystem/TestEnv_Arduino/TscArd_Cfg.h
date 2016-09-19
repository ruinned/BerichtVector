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

#ifndef TSCARD_TRCV_CFG_H
#define TSCARD_TRCV_CFG_H

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* global define to supress in old code the included application files for 
   communication with arduino board */
#define ARDUINO

/* transceiver to be used SPI oder DIO com */
#define TRCV_MODE     0x00

/* serial port used for communication with arduino board */
#define ARD_COMPORT   4



#endif