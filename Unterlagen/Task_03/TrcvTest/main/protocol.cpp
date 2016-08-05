/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2015 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  protocol.c
 *        \brief  protocol source file
 *
 *        \details basic input/output
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#define PROT_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <avr/io.h>
#include <avr/interrupt.h>
#include "protocol.h"
#include "Arduino.h"
#include "HardwareSerial.h"
#include "dio.h"
#include "trcvDio.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of protocol header file */
#if (  (PROT_SW_MAJOR_VERSION != (1u)) \
    || (PROT_SW_MINOR_VERSION != (0u)) \
    || (PROT_SW_PATCH_VERSION != (0u)) )
# error "Vendor specific version numbers of protocol.c and protocol.h are inconsistent"
#endif


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
#define SW_MAJOR_VERSION        0x01
#define SW_MINOR_VERSION        0x00
#define SW_PATCH_VERSION        0x00

#define sciTIMEOUT          32  /* in ms */
/* Commands from the PC */
#define sciCOMMAND_VERSION      0x00
#define sciTRCV_DEVICE_MODE     0x10
#define sciSET_DIO              0x20
#define sciGET_DIO              0x21
#define sciTRCV_STATUS_WORD     0x30
#define sciFORCE_ERROR          0x40

#define sciCMD_OK               0x00
#define sciCMD_NOK              0x01

/* io defined pins */
#define pinMODE                  1u
#define pinFR_TXD                2u
#define pinFR_TXD_int            3u
#define pinFR_TXEN               4u
#define pinFR_TXEN_int           5u
#define pinVin                   6u
#define pinCLAMP_GND_BP          7u
#define pinCLAMP_GND_BM          8u
#define pinSTDBY_int             9u
#define pinLED                  10u

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/* Preprocessor define STATIC is no longer available in Compiler.h in MSR4 - provide local define */
#if !defined (STATIC)
# define STATIC static
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/
uint8  rxMessage[4];
uint8  txMessage[4];

/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define PROT_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  protocol_InitMemory()
 **********************************************************************************************************************/
/*! \brief      Function for *_INIT_*-variable initialization
 *  \details    Service to initialize module global variables at power up. This function can be used to initialize the
 *              variables in *_INIT_* sections in case they are not initialized by the startup code.
 *  \pre        Module must not be initialized
 *  \pre        Function shall be called from task level
 **********************************************************************************************************************/
void protocol_InitMemory(void)
{
  /* ----- Implementation ----------------------------------------------- */

}  /* protocol_InitMemory() */


/**********************************************************************************************************************
 * protocol_Init()
 **********************************************************************************************************************/
/*! \brief      Initialization function
 *  \details    This function initializes the module protocol. It initializes all variables and and sets the module state to
 *              initialized.
 *  \param[in]  -
 *  \pre        Interrupts have to be disabled.
 *  \pre        The module has to be uninitialized.
 *  \pre        protocol_InitMemory has been called unless protocol_ModuleInitialized is initialized by start-up code.
 *  \note       Specification of module initialization
 **********************************************************************************************************************/
void protocol_Init(void)
{
}


/**********************************************************************************************************************
 * protocol_Dispatcher()
 **********************************************************************************************************************/
/*! \brief      
 *  \details    
 *              
 *  \param[in]  -
 *  \pre        
 *  \pre        The module has to be initialized.
 *  \pre        protocol_InitMemory has been called unless protocol_ModuleInitialized is initialized by start-up code.
 *  \note       
 **********************************************************************************************************************/
/* decode received frame */
void protocol_Dispatcher()
{
  uint16 statusWord;

  switch(rxMessage[0])
  {
    case sciCOMMAND_VERSION :
        txMessage[0] = sciCOMMAND_VERSION;
        txMessage[1] = SW_MAJOR_VERSION;
        txMessage[2] = SW_MINOR_VERSION;
        txMessage[3] = SW_PATCH_VERSION;
        Serial.write(txMessage, 4);
        break;

    case sciTRCV_DEVICE_MODE :
        txMessage[0] = sciTRCV_DEVICE_MODE;
        txMessage[1] = sciCMD_OK;
        txMessage[2] = 0x00;
        txMessage[3] = 0x00;
        Serial.write(txMessage, 4);
        break;

    case sciSET_DIO :
        txMessage[0] = sciSET_DIO;
        txMessage[1] = sciCMD_OK;
        txMessage[2] = 0x00;
        txMessage[3] = 0x00;
        Serial.write(txMessage, 4);

        switch(rxMessage[1])
        {
          case pinMODE: 
              switch(rxMessage[3])
              {
                case 0: disable();
                        EN_LOW();
                        STBN_LOW();
                        enable();
                        break;
                case 1: disable();
                        EN_LOW();
                        STBN_HIGH();
                        enable();
                        break;
                case 2: disable();
                        EN_HIGH();
                        STBN_LOW();
                        enable();
                        break;
                case 3: disable();
                        EN_HIGH();
                        STBN_HIGH();
                        enable();
                        break;
              } break;
          default:
          {
            /* direct mapping */
            /* requested I/O pin rxMessage[1] equals dio pin description */
            dio_WriteChannel(rxMessage[1], rxMessage[3]);
          }
        }
        break;

    case sciGET_DIO :
        /* direct mapping */
        /* requested I/O pin rxMessage[1] equals dio pin description */
        txMessage[3] = dio_ReadChannel(rxMessage[1]);
        txMessage[0] = sciGET_DIO;
        txMessage[1] = sciCMD_OK;
        txMessage[2] = 0x00;
        Serial.write(txMessage, 4);
        break;

    case sciTRCV_STATUS_WORD :
        statusWord = trcvDio_ReadWord(0);
        txMessage[0] = sciTRCV_STATUS_WORD;
        txMessage[1] = sciCMD_OK;
        txMessage[2] = (uint8)(statusWord >> 8);
        txMessage[3] = (uint8)statusWord;
        Serial.write(txMessage, 4);
        break;

    case sciFORCE_ERROR :
        txMessage[0] = sciFORCE_ERROR;
        txMessage[1] = sciCMD_OK;
        txMessage[2] = 0x00;
        txMessage[3] = 0x00;
        Serial.write(txMessage, 4);
        break;
  }
}




/**********************************************************************************************************************
 * protocol_Handler()
 **********************************************************************************************************************/
/*! \brief      
 *  \details    
 *              
 *  \param[in]  -
 *  \pre        
 *  \pre        The module has to be initialized.
 *  \pre        protocol_InitMemory has been called unless protocol_ModuleInitialized is initialized by start-up code.
 *  \note       
 **********************************************************************************************************************/
/* receive a single frame */
void protocol_Handler()
{
  static uint8 serialFlush;

  if( Serial.available() >= 4 )
  {
      /* Read a received frame */
      rxMessage[0] = Serial.read();
      rxMessage[1] = Serial.read();
      rxMessage[2] = Serial.read();
      rxMessage[3] = Serial.read();
      /* Decode protocol */
      protocol_Dispatcher();
  }
  else
  {
    /* Timout counter handling */
    if( Serial.available() > 0 )
    {
      serialFlush++;
    } else
    {
      serialFlush = 0;
    }
  }

  /* if timeout happened, reset receive buffer */
  if( serialFlush >= sciTIMEOUT )
  {
    while(Serial.available() > 0)
    { /* purge receive buffer */
      (void)Serial.read();
    }
    serialFlush = 0;
  }
}



#define PROT_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  END OF FILE: protocol.c
 *********************************************************************************************************************/
