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
#include "trcvSpi.h"
#include "ArdComplexOp.h"

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
#define sciCOMPLEX_OP           0x40
#define sci_RESETALLDIOPINS     0x60
//#define sciCO_NR_SENDWU         0x01

#define sciCMD_OK               0x01
#define sciCMD_NOK              0x00
#define sciCMD_DONTCARE         0x00

/* io defined pins */
#define pinMODE                  0u


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

/**********************************************************************************************************************
*  GLOBAL DATA
**********************************************************************************************************************/
uint8  rxMessage[4];
uint8  txMessage[4];
uint8 TrcvType = 0xFF;
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
    txMessage[0] = 0x00;
    txMessage[1] = sciCMD_NOK;
    txMessage[2] = 0x00;
    txMessage[3] = 0x00;    
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
    uint8 nr;
    uint8 aa;
    uint8 aa2pc;
    uint16 data;
    uint8 ed;

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
      aa = rxMessage[1];
      TrcvType = aa;
      //change the initial transceiver pin configuration to DIO-Mode
      if(TrcvType == 0x00 || TrcvType == 0x01)
      {
        dio_config();        
      }
      txMessage[0] = sciTRCV_DEVICE_MODE;
      txMessage[1] = sciCMD_OK;
      txMessage[2] = sciCMD_DONTCARE;
      txMessage[3] = sciCMD_DONTCARE;
      Serial.write(txMessage, 4);
      break;

      case sciSET_DIO :
      nr = rxMessage[1];
      aa = rxMessage[3];
      txMessage[0] = sciSET_DIO;
      txMessage[1] = (TrcvType != 0xFF) ? sciCMD_OK : sciCMD_NOK;
      txMessage[2] = sciCMD_DONTCARE;
      txMessage[3] = sciCMD_DONTCARE;
      Serial.write(txMessage, 4);

      if(TrcvType != 0xFF)
      {
        switch(nr)
        {
          case pinMODE:
          switch(aa)
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
            dio_WriteChannel(nr, aa);            
          }break;
        }
      }
      break;

      case sciGET_DIO :
      /* direct mapping */
      /* requested I/O pin rxMessage[1] equals dio pin description */
      nr = rxMessage[1];
      aa2pc = (TrcvType != 0xFF) ? dio_ReadChannel(nr) : 0;
      txMessage[3] = aa2pc; //muss bei SPI angepasst werden
      txMessage[1] = (TrcvType != 0xFF) ? sciCMD_OK : sciCMD_NOK;
      txMessage[0] = sciGET_DIO;
      txMessage[2] = nr;
      Serial.write(txMessage, 4);
      break;

      case sciTRCV_STATUS_WORD :
      data = ((uint16)rxMessage[2] << 8) | rxMessage[3];
      aa = rxMessage[1];

      txMessage[0] = sciTRCV_STATUS_WORD;
      if(TrcvType != 0xFF)
      {
        if(TrcvType == 0x00 || TrcvType == 0x01)
        {          
          statusWord = trcvDio_ReadWord(0);
        }
        else
        {
          if(TrcvType == 0x80 || TrcvType == 0x81)
          {
            statusWord = trcvSpi_writeWord(data, aa);
          }
        }
        txMessage[1] = sciCMD_OK;
        txMessage[2] = (uint8)(statusWord >> 8);
        txMessage[3] = (uint8)(statusWord & 0xff);
      }
      else
      {
        txMessage[1] = sciCMD_NOK;
      }

      Serial.write(txMessage, 4);
      break;

      case sciCOMPLEX_OP :
      nr = rxMessage[1];
      ed = rxMessage[2];
      aa = rxMessage[3];
      
      txMessage[0] = sciCOMPLEX_OP;
      txMessage[1] = sciCMD_OK;
      txMessage[2] = sciCMD_DONTCARE;
      txMessage[3] = sciCMD_DONTCARE;

      Serial.write(txMessage, 4);
      switch(nr)
      {
        case dio_ForceTxEnTO:
        ArdComplexOp_forceTxEntimeout();
        break;

        case dio_ForceBusCollision:
        ArdComplexOp_forceBusCollition();
        break;

        case dio_VBatDis: 
        ArdCom_ComplexOP_ClampVbat(ed);                   
        break;

        case dio_SendRemoteWU:        
        ArdComplexOp_wakeUpPattern(aa);
        break;

        case dio_SendLocalWU:
        ArdComplexOp_lokalWakeUp();
        break;

        default:
        CLAMP_GND_BP_HIGH();
        CLAMP_GND_BM_HIGH();        
        break;
      }
      break;

      case sci_RESETALLDIOPINS:
      txMessage[0] = sci_RESETALLDIOPINS;
      txMessage[1] = sciCMD_OK;
      txMessage[2] = sciCMD_DONTCARE;
      txMessage[3] = sciCMD_DONTCARE;
      Serial.write(txMessage, 4);

      reset_dio();
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
      //LEDA_TOGGLE();
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
