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
#include <avr/interrupt.h>
#include <util/delay.h>
#include "protocol.h"
#include "HardwareSerial.h"
#include "dio.h"
#include "trcvDio.h"
#include "trcvSpi.h"

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

#define PROTOCOL_TIMEOUT          32  /* in ms */
/* Commands from the PC */
#define PROTOCOL_COMMAND_VERSION              0x00
#define PROTOCOL_TRCV_DEVICE_MODE             0x10
#define PROTOCOL_SET_DIO                      0x20
#define PROTOCOL_GET_DIO                      0x21
#define PROTOCOL_TRCV_STATUS_WORD             0x30
#define PROTOCOL_COMPLEXOP                    0x40
#define PROTOCOL_COMPLEXOP_REMOTEWU           0x41
#define PROTOCOL_COMPLEXOP_FORCECOL           0x42
#define PROTOCOL_COMPLEXOP_FORCETXTNTO        0x43
#define PROTOCOL_COMPLEXOP_VBATDIS            0x44
#define PROTOCOL_COMPLEXOP_LOCALWU            0x45
#define PROTOCOL_RESETALLDIOPINS              0x60
//#define PROTOCOL_CO_NR_SENDWU         0x01

#define PROTOCOL_CMD_OK               0x01
#define PROTOCOL_CMD_NOK              0x00
#define PROTOCOL_CMD_DONTCARE         0x00

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
static uint8  rxMessage[4];
static uint8 TrcvType = 0xFF;
/**********************************************************************************************************************
*  GLOBAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
*  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

#define PROT_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


static void protocol_ComplexOp(void);
static void protocol_sendMessage(uint8,uint8,uint8,uint8);


/**********************************************************************************************************************
*  LOCAL FUNCTIONS
**********************************************************************************************************************/

/***********************************************************************************************************************
*  protocol_ComplexOp()
**********************************************************************************************************************/
/*! \brief     Function for dispatching several additional error provoking methods.
*  \details    The dispatched methods are tasked with provoking error
*              conditions to set the transceiver status word to a desired value.
*  \param[in]  -
*  \return     -
*  \pre        Module must be initialized
**********************************************************************************************************************/
static void protocol_ComplexOp()
{
  uint8 nr_local = rxMessage[1];
  uint8 ed_local = rxMessage[2];
  uint8 aa_local = rxMessage[3];

  switch(nr_local)
  {
    case PROTOCOL_COMPLEXOP_FORCETXTNTO:
      protocol_ComplexOp_forceTxEntimeout();
    break;

    case PROTOCOL_COMPLEXOP_FORCECOL:
      protocol_ComplexOp_forceBusCollition();
    break;

    case PROTOCOL_COMPLEXOP_VBATDIS:
      protocol_ComplexOp_ClampVbat(ed_local);
    break;

    case PROTOCOL_COMPLEXOP_REMOTEWU:
      protocol_ComplexOp_wakeUpPattern(aa_local);
    break;

    case PROTOCOL_COMPLEXOP_LOCALWU:
      protocol_ComplexOp_lokalWakeUp();
    break;

    default:
    CLAMP_GND_BP_HIGH();
    CLAMP_GND_BM_HIGH();
    break;
  }
  protocol_sendMessage(PROTOCOL_COMPLEXOP, PROTOCOL_CMD_OK, PROTOCOL_CMD_DONTCARE, PROTOCOL_CMD_DONTCARE);
}

/***********************************************************************************************************************
*  protocol_sendMessage()
**********************************************************************************************************************/
/*! \brief     Function for coding the entry parameters to be sent. Sending and receving operation are also called.
*  \details    Function to dispatch a coded message
*  \param[in]   transfer_0         transfer data 1
*  \param[in]   transfer_1         transfer data 2
*  \param[in]   transfer_2         transfer data 3
*  \param[in]   transfer_3         transfer data 4
*  \return     E_NOT_OK - error
*  \return     E_OK - success
*  \pre        Module must be initialized
**********************************************************************************************************************/
static void protocol_sendMessage(uint8 transfer_0, uint8 transfer_1, uint8 transfer_2, uint8 transfer_3)
{
  uint8 TempChr[4] = {transfer_0, transfer_1, transfer_2, transfer_3};
  Serial.write(TempChr, 4);
}

/**********************************************************************************************************************
*  GLOBAL FUNCTIONS
**********************************************************************************************************************/

  /**********************************************************************************************************************
  * protocol_Init()
  **********************************************************************************************************************/
  /*! \brief      Initialization function
  *  \details    This function initializes the module protocol. It initializes all variables and and sets the module state to
  *              initialized.
  *  \param[in]  -
  *  \pre        The module has to be uninitialized.
  *  \pre        protocol_InitMemory has been called unless protocol_ModuleInitialized is initialized by start-up code.
  *  \note       Specification of module initialization
  **********************************************************************************************************************/
  void protocol_Init(void)
  {
    rxMessage[0]=0x00;
    rxMessage[1]=0x00;
    rxMessage[2]=0x00;
    rxMessage[3]=0x00;
  }

  /**********************************************************************************************************************
  * protocol_Dispatcher()
  **********************************************************************************************************************/
  /*! \brief     Function to decode the incoming command data from the PC.
  *  \details    The incoming data contains the commands to be executed by the arduino. 
  *              Certain configuration and service functions are thus further called by this method.
  *  \param[in]  -
  *  \pre
  *  \pre        The module has to be initialized.
  *  \pre        protocol_Init has been called.
  *  \note
  **********************************************************************************************************************/
  void protocol_Dispatcher()
  {
    /* decode received frame */
    switch(rxMessage[0])
    {
      case PROTOCOL_COMMAND_VERSION :
        protocol_GetVersion();
      break;

      case PROTOCOL_TRCV_DEVICE_MODE :
        protocol_Transceiverdevicemode();
      break;

      case PROTOCOL_SET_DIO :      
        protocol_SetDIO();
      break;

      case PROTOCOL_GET_DIO :
        protocol_GetDIO();
      break;

      case PROTOCOL_TRCV_STATUS_WORD :
        protocol_WriteReadTRCVStatusWord();
      break;

      case PROTOCOL_COMPLEXOP :
        protocol_ComplexOp();
      break;

      case PROTOCOL_RESETALLDIOPINS:
        protocol_ResetAllDioPins();
      break;
    }
  }


  /**********************************************************************************************************************
  * protocol_Handler()
  **********************************************************************************************************************/
  /*! \brief     Function to receive and control the data flow between PC and Arduino.
  *  \details    Checks if 4 data frames are received from the PC, then the this function calls the protocol dispatcher. 
  *              If not, it waits for further incoming data until timeout condition if fulfilled the incomplete data to dispose.
  *  \param[in]  -
  *  \pre
  *  \pre        The module has to be initialized.
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
      /* timeout counter handling */
      if( Serial.available() > 0 )
      {
        serialFlush++;
      } 
      else
      {
        serialFlush = 0;
      }
    }

    /* if timeout happened, reset receive buffer */
    if( serialFlush >= PROTOCOL_TIMEOUT )
    {
      while(Serial.available() > 0)
      { /* purge receive buffer */
        (void)Serial.read();
      }
      serialFlush = 0;
    }
  }

  /***********************************************************************************************************************
 *  protocol_ComplexOp_wakeUpPattern()
 **********************************************************************************************************************/
/*! \brief      Function for sending a remote wake up command to the testing transceiver
 *  \details    Arduino controls the TXD line of the helping transceiver to send a remote wakeup pattern 
 *  \param[in]  aa       parameter to indicate the number of times the wakeup pattern to
 *                       be repeated
 *  \pre        Module must be initialized 
 **********************************************************************************************************************/
  void protocol_ComplexOp_wakeUpPattern(uint8 aa)
  {
    volatile uint8 i = 0;
    TXEN_int_LOW();
    _delay_us(100); // wait until transceiver gets configured
    for ( ; i < aa; i++ )
    {
      TXD_int_LOW();
      TXEN_int_LOW();
      _delay_us(6);
      TXD_int_HIGH();
      TXEN_int_HIGH();
      _delay_us(18);
    }
    TXEN_int_HIGH();
  }

 /***********************************************************************************************************************
 *  protocol_ComplexOp_lokalWakeUp()
 **********************************************************************************************************************/
/*! \brief      Function for executing a local wake up command of the testing transceiver
 *  \details    Arduino controls the WAKE pin of the transceiver to provoke a local wakeup pattern 
 *  \pre        Module must be initialized 
 **********************************************************************************************************************/
  void protocol_ComplexOp_lokalWakeUp()
  {
    CS2_OFF();
    _delay_us(50);
    CS2_ON();
  }

 /***********************************************************************************************************************
 *  TscArd_ForceBusCollision()
 **********************************************************************************************************************/
/*! \brief      Function to provoke a bus collision in the bus line by means of a corresponding command coming from the PC.
 *  \details    Arduino controls the corresponding TXD pin of both the helping and test trcv. to provoke a 
 *              bus line collision. Bus error flag in the transceiver status word is set.
 *  \pre        Module must be initialized 
 **********************************************************************************************************************/
  void protocol_ComplexOp_forceBusCollition()
  {
    uint8 i = 0;
    TXEN_int_LOW();
    FR_TXEN_LOW();
    _delay_us(100);
    for ( ; i < 2; i++ )
    {
      TXD_int_HIGH();
      _delay_us(100);
      FR_TXD_HIGH();
      _delay_us(100);
      TXD_int_LOW();
      _delay_us(100);
      FR_TXD_LOW();
      _delay_us(100);
    }
    TXEN_int_HIGH();
    FR_TXEN_HIGH();
  }

/***********************************************************************************************************************
 *  protocol_ComplexOp_forceTxEntimeout()
 **********************************************************************************************************************/
/*! \brief      Function to force a TX line timeout condition in the status register of the transceiver
 *  \details    Arduino resets corresponding TXEN pin until the corresponding time out
 *              flag in the transceiver status word is set
 *  \pre        Module must be initialized 
 **********************************************************************************************************************/
  void protocol_ComplexOp_forceTxEntimeout()
  {
    FR_TXEN_LOW();
    _delay_ms(20);
    FR_TXEN_HIGH();
  }

 /***********************************************************************************************************************
 *  TscArd_ClampVbat()
 **********************************************************************************************************************/
/*! \brief      Function for clamping the VBAT pin of the transceiver to GND
 *  \details    Arduino clamps the VBAT-pin to GRD in order to set the transceiver status word accordingly   
 *  \param[in]  ed              parameter to enable/disable a desired functionality.
 *                              0 to clamp VBAT to GND
 *                              1 to restore the normal state
 *  \return     -
 *  \pre        Module must be initialized 
 **********************************************************************************************************************/
  void protocol_ComplexOp_ClampVbat(uint8 ed)
  {
    /* clamp VBAT to GND */
    if (ed == 0)
    {
      VinVBat_LOW();
    } 
    /* set VBAT again to the normal state */
    else
    {
      VinVBat_HIGH();
    }
  }

  /**********************************************************************************************************************
  * protocol_GetVersion()
  **********************************************************************************************************************/
  /*! \brief     Returns the version information
  *  \details    protocol_GetVersion() returns version information, vendor ID and AUTOSAR module ID of the component.
  *  \param[in]  -
  *  \pre        The module has not to be initialized.
  **********************************************************************************************************************/
  void protocol_GetVersion()
  {
    protocol_sendMessage(PROTOCOL_COMMAND_VERSION, SW_MAJOR_VERSION, SW_MINOR_VERSION, SW_PATCH_VERSION);
  }

  /**********************************************************************************************************************
  * protocol_Transceiverdevicemode()
  **********************************************************************************************************************/
  /*! \brief     Configuration of the trasceiver device
  *  \details    Function for transmitting and setting the corresponding transceiver device mode
  *  \param[in]  -
  *  \pre        The module has to be initialized.
  **********************************************************************************************************************/
  void protocol_Transceiverdevicemode()
  {
    /* ----- Local Variables ---------------------------------------------- */
    uint8 aa_local = rxMessage[1];
    /* ----- Implementation ----------------------------------------------- */
    TrcvType = aa_local;
    /* change the initial transceiver pin configuration to DIO-Mode */
    trcvDio_Init(TrcvType);

    protocol_sendMessage(PROTOCOL_TRCV_DEVICE_MODE,PROTOCOL_CMD_OK,PROTOCOL_CMD_DONTCARE,PROTOCOL_CMD_DONTCARE);
  }

  /**********************************************************************************************************************
  * protocol_SetDIO()
  **********************************************************************************************************************/
  /*! \brief     Set or reset the status of a given pin
  *  \details    The corresponding DIO Channel is analysed and the corresponding DIO Pin will be set/reset
  *  \param[in]  -
  *  \pre        The module has to be initialized.
  **********************************************************************************************************************/
  void protocol_SetDIO()
  {
    uint8 nr_local = rxMessage[1];
    uint8 aa_local = rxMessage[3];
    if(TrcvType != 0xFF)
    {
      switch(nr_local)
      {
        case pinMODE:
          disable();
          switch(aa_local)
          {
            case 0: 
              EN_LOW();
              STBN_LOW();
              break;
            case 1: 
              EN_LOW();
              STBN_HIGH();
              break;
            case 2: 
              EN_HIGH();
              STBN_LOW();
              break;
            case 3: 
              EN_HIGH();
              STBN_HIGH();
              break;
          } 
          enable();
          break;
        default:
          /* direct mapping */
          /* requested I/O pin rxMessage[1] equals dio pin description */
          dio_WriteChannel(nr_local, aa_local);
          break;
      }
    }
    if (TrcvType == 0xFF)
    {
      protocol_sendMessage(PROTOCOL_SET_DIO, PROTOCOL_CMD_NOK, PROTOCOL_CMD_DONTCARE, PROTOCOL_CMD_DONTCARE);
    } 
    else
    {
      protocol_sendMessage(PROTOCOL_SET_DIO, PROTOCOL_CMD_OK, PROTOCOL_CMD_DONTCARE, PROTOCOL_CMD_DONTCARE);
    }    
  }

  /**********************************************************************************************************************
  * protocol_GetDIO()
  **********************************************************************************************************************/
  /*! \brief     Get the status of a given pin
  *  \details    The corresponding DIO Channel is analyzed and the status of corresponding DIO Pin will be read
  *  \param[in]  -
  *  \pre        The module has to be initialized.
  **********************************************************************************************************************/
  void protocol_GetDIO()
  {
    uint8 nr_local = rxMessage[1];
    uint8 aa_local;

    if (TrcvType == 0xFF)
    {
      protocol_sendMessage(PROTOCOL_GET_DIO, PROTOCOL_CMD_NOK, rxMessage[1], 0);
    }
    else
    {
      aa_local = dio_ReadChannel(nr_local);
      protocol_sendMessage(PROTOCOL_GET_DIO, PROTOCOL_CMD_OK, rxMessage[1], aa_local);
    }    
  }

  /**********************************************************************************************************************
  * protocol_WriteReadTRCVStatusWord()
  **********************************************************************************************************************/
  /*! \brief     read the status word of the transceiver device
  *  \details    In case of Trcv Tja1080 the corresponding signal across the EN pin for the transceiver is generated.
  *              In case of Trcv with SPI interface the read command is send and a read operation of the status word is implemented
  *  \param[in]  -
  *  \pre        The module has to be initialized.
  **********************************************************************************************************************/
  void protocol_WriteReadTRCVStatusWord()
  {
    uint16 statusWord = 0;
    uint16 data_local = ((uint16)rxMessage[2] << 8) | rxMessage[3];
    uint8 aa_local = rxMessage[1];
    uint8 txMessage_local[4];
    txMessage_local[0] = PROTOCOL_TRCV_STATUS_WORD;
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
          statusWord = trcvSpi_writeWord(data_local, aa_local);
        }
      }
      txMessage_local[1] = PROTOCOL_CMD_OK;
      txMessage_local[2] = (uint8)(statusWord >> 8);
      txMessage_local[3] = (uint8)(statusWord & 0xff);
    }
    else
    {
      txMessage_local[1] = PROTOCOL_CMD_NOK;
      txMessage_local[2] = PROTOCOL_CMD_DONTCARE;
      txMessage_local[3] = PROTOCOL_CMD_DONTCARE;
    }
    protocol_sendMessage(txMessage_local[0], txMessage_local[1], txMessage_local[2], txMessage_local[3]);
  }

    /**********************************************************************************************************************
  * protocol_ResetAllDioPins()
  **********************************************************************************************************************/
  /*! \brief     Function for reseting the status of the DIO pins to the initial status
  *  \details    Function for reseting the status of the DIO pins to the initial status
  *  \param[in]  -
  *  \pre        The module has to be initialized.
  **********************************************************************************************************************/
  void protocol_ResetAllDioPins()
  {
    protocol_sendMessage(PROTOCOL_RESETALLDIOPINS, PROTOCOL_CMD_OK, PROTOCOL_CMD_DONTCARE, PROTOCOL_CMD_DONTCARE);
    dio_ResetPins();
  }
  
  #define PROT_STOP_SEC_CODE
  #include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

  /**********************************************************************************************************************
  *  END OF FILE: protocol.c
  *********************************************************************************************************************/
