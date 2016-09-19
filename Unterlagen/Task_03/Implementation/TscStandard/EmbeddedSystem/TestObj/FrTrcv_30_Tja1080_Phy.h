/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2016 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*  \file  FrTrcv_30_Tja1080_Phy.h
 *  \brief  MICROSAR FR Transceiver Driver
 *
 *  \details  FlexRay transceiver driver physical implementation header
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

#if !defined (FRTRCV_30_TJA180_PHY_H) /* COV_FRTRCV_30_TJA1080_PHY_MSR_HEADERGUARD */
# define FRTRCV_30_TJA180_PHY_H

# include "ComStack_Types.h"

# include "Dio.h"


# define FRTRCV_30_TJA1080_STATUS_INVERT_MASK 0xFFFFu


/*!
 * \internal
 * Hardware interface structures for the Transceiver status word bit description for the TJA1080, TJA1081 and NCV7381.
 * The single register is read via DIO
 *
 *  Hardware manuals: 
 *   - TJA1080A.pdf, Rev 6
 *   - TJA1081B.pdf, Rev 1
 *   - NCV7381-D.PDF, Rev 2
 *
 *  Errata sheets: -
 *
 *  Access mechanism:
 *   - DIO bit banging used for register access
 *
 *  Used registers: SR - Status Register
 *
 *  Hardware features related to independence or partitioning: -
 *
 *  Operating modes: 
 *   - refer to the states specified in the CAD
 *   - note: parts of the state machine are implemented in HW
 *
 *  Hardware diagnostics: - 
 *
 *  Specifics: 
 *   - Timing for Transceiver access must be ensured by the user via user call-back Appl_FrTrcv_30_Tja1080_Wait.
 *     Timing depends on used transceiver device.
 *
 * \endinternal
 */
/*! SR Register Bit Mask */
# define FRTRCV_30_TJA1080_LOCALWAKEUP     0x1000u /*<! Local wake up detected */
# define FRTRCV_30_TJA1080_REMOTEWAKEUP    0x0800u /*<! Remote wake up detected */
# define FRTRCV_30_TJA1080_NODE_CONFIG     0x0400u /*<! Node configuration flag */
# define FRTRCV_30_TJA1080_PWON            0x0200u /*<! Power on detected */
# define FRTRCV_30_TJA1080_BUSERROR        0x0100u /*<! Bus error detected */
# define FRTRCV_30_TJA1080_TEMPHIGH        0x0080u /*<! Temperature to high error detected */
# define FRTRCV_30_TJA1080_TEMPMEDIUM      0x0040u /*<! Temperature to high warning detected */
# define FRTRCV_30_TJA1080_TXEN_CLAMPED    0x0020u /*<! TXEN clamped flag */
# define FRTRCV_30_TJA1080_UVVBAT          0x0010u /*<! VBAT undervoltage detected */
# define FRTRCV_30_TJA1080_UVVCC           0x0008u /*<! VCC undervoltage detected */
# define FRTRCV_30_TJA1080_UVVIO           0x0004u /*<! VIO undervoltage detected */
# define FRTRCV_30_TJA1080_STARLOCKED      0x0002u /*<! Star-locked state has been entered */
# define FRTRCV_30_TJA1080_TRXDCOLLISION   0x0001u /*<! TRXD collision has been detected */

/*! Predefined timer indexes (0x01 - 0x0f) */
# define kFrTrcv_30_Tja1080_delay_tEN_half 0x01 /*<! This timer defines the delay time for tEN/2 */
# define kFrTrcv_30_Tja1080_delay_tDet     0x02 /*<! This timer defines the delay time for tDet(EN) */

/*! Structure used for the dio port configuration */
typedef struct
{
  Dio_ChannelType   TrcvPinEN;
  Dio_ChannelType   TrcvPinSTBN;
  Dio_ChannelType   TrcvPinERRN;
} FrTrcv_30_Tja1080_ChannelType;

/*! The Trcv status word containing the status bits */
typedef uint16 FrTrcv_30_Tja1080_StatusWordType;


# define FRTRCV_30_TJA1080_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */

# if ( FRTRCV_30_TJA1080_TRCV_DIAGNOSIS == STD_ON )
/* PRQA S 0777 3 */ /* MD_MSR_5.1_777 */
extern CONST(uint8, FRTRCV_30_TJA1080_CONST) FrTrcv_30_Tja1080_Phy_StatusMaskTableSize;
extern CONST(FrTrcv_30_Tja1080_StatusWordType, FRTRCV_30_TJA1080_CONST) FrTrcv_30_Tja1080_Phy_StatusMaskTable[]; /* PRQA S 3684 */ /* MD_FRTRCV_3684 */
extern CONST(uint32, FRTRCV_30_TJA1080_CONST) FrTrcv_30_Tja1080_Phy_ErrorTable[]; /* PRQA S 3684 */ /* MD_FRTRCV_3684 */
# endif

# define FRTRCV_30_TJA1080_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */


# define FRTRCV_30_TJA1080_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */

# if ( FRTRCV_30_TJA1080_WUPINT_CBK == STD_ON )
/***********************************************************************************************************************
 *  Appl_FrTrcv_30_Tja1080_DisableNotification()
 **********************************************************************************************************************/
/*! \brief       This call-out is called to disable ICU int for transceiver interrupt pin.
 *  \details     This call-out is called by the component in case interrupts shall be disabled for normal operation.
 *               This is relevant if RX pin is used for wake up detection
 *  \param[in]   Icu_Channel      The ICU port channel corresponding to the Transceiver index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      FRTRCV_30_TJA1080_WUPINT_CBK.
 *  \trace DSGN-FrTrcv22844
 **********************************************************************************************************************/
  FUNC(void, FRTRCV_30_TJA1080_CODE) Appl_FrTrcv_30_Tja1080_DisableNotification(uint8 Icu_Channel);
/***********************************************************************************************************************
 *  Appl_FrTrcv_30_Tja1080_EnableNotification()
 **********************************************************************************************************************/
/*! \brief       This call-out is called to disable ICU int for transceiver interrupt pin.
 *  \details     This call-out is called by the component in case interrupts shall be enabled for low power operation.
 *               This is relevant if RX pin is used for wake up detection
 *  \param[in]   Icu_Channel      The ICU port channel corresponding to the Transceiver index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      FRTRCV_30_TJA1080_WUPINT_CBK.
 **********************************************************************************************************************/
  FUNC(void, FRTRCV_30_TJA1080_CODE) Appl_FrTrcv_30_Tja1080_EnableNotification(uint8 Icu_Channel);
# endif

# if ( FRTRCV_30_TJA1080_USERDIO == STD_ON )
/***********************************************************************************************************************
 *  Appl_FrTrcv_30_Tja1080_Dio_WriteChannel()
 **********************************************************************************************************************/
/*! \brief       This call-out is called to write dio pin in application function.
 *  \details     This call-out is called by the component to set a dio pin to a specific level. It can be used if the
 *               standard DIO is to slow.
 *  \param[in]   channel          The port pin
 *  \param[in]   value            STD_HIGH or STD_LOW
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      FRTRCV_30_TJA1080_USERDIO.
 **********************************************************************************************************************/
  FUNC(void, FRTRCV_30_TJA1080_CODE) Appl_FrTrcv_30_Tja1080_Dio_WriteChannel(Dio_ChannelType channel, Dio_LevelType value);
/***********************************************************************************************************************
 *  Appl_FrTrcv_30_Tja1080_Dio_ReadChannel()
 **********************************************************************************************************************/
/*! \brief       This call-out is called to read dio pin in application function.
 *  \details     This call-out is called by the component to read a dio pin. It can be used if the
 *               standard DIO is to slow.
 *  \param[in]   channel          The port pin
 *  \return      STD_HIGH or STD_LOW
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      FRTRCV_30_TJA1080_USERDIO.
 **********************************************************************************************************************/
  FUNC(Dio_LevelType, FRTRCV_30_TJA1080_CODE) Appl_FrTrcv_30_Tja1080_Dio_ReadChannel(Dio_ChannelType channel);
# endif


/**********************************************************************************************************************
 * FrTrcv_30_Tja1080_Phy_Init()
 **********************************************************************************************************************/
/*! \brief       Initialization function
 *  \details     This function initializes the module Msn. It initializes all variables and sets the module state to
 *               initialized.
 *  \param[in]   FrTrcv_TrcvIdx The selected FlexRay bus transceiver
 *  \pre         Interrupts are disabled.
 *  \pre         FrTrcv_InitMemory has been called unless FrTrcv_ModuleInitialized is initialized by start-up code.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 **********************************************************************************************************************/
FUNC(void, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_Phy_Init( FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_ONLY );

/***********************************************************************************************************************
 *  FrTrcv_30_Tja1080_Phy_SetMode()
 **********************************************************************************************************************/
/*! \brief       This service function is to set the transceiver into a specific mode.
 *  \details     If the requested mode is not supported an equivalent mode is selected. If the mode change was not
 *               successful, E_NOT_OK is returned. Additionally user call-out are called to disable and enable interrupts
 *               for the transceiver device.
 *  \param[in]   FrTrcv_TrcvIdx      The transceiver to set into the requested mode
 *  \param[in]   FrTrcv_TrcvMode     The operation mode
 *  \return      E_NOT_OK - operation was not successful
 *  \return      E_OK - success
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 **********************************************************************************************************************/
FUNC(Std_ReturnType, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_Phy_SetMode( FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_FIRST FrTrcv_TrcvModeType FrTrcv_TrcvMode );

/***********************************************************************************************************************
 *  FrTrcv_30_Tja1080_Phy_GetMode()
 **********************************************************************************************************************/
/*! \brief       This service function is to get the transceiver mode.
 *  \details     This service function returns the current transceiver mode on the selected channel.
 *  \param[in]   FrTrcv_TrcvIdx      The transceiver to get the mode from.
 *  \param[out]  FrTrcv_TrcvModePtr  Output parameter reference, the operation mode. The pointer must be valid.
 *  \return      E_NOT_OK - operation was not successful
 *  \return      E_OK - success
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 **********************************************************************************************************************/
FUNC(void, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_Phy_GetMode( FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_FIRST P2VAR(FrTrcv_TrcvModeType, AUTOMATIC, FRTRCV_30_TJA1080_APPL_DATA) FrTrcv_TrcvModePtr );

/***********************************************************************************************************************
 *  FrTrcv_30_Tja1080_Phy_ReadStatusWord()
 **********************************************************************************************************************/
/*! \brief       This service function is to read the TJA1080 status word.
 *  \details     This function provides the current status word containing the error and wake up bits.
 *  \param[in]   FrTrcv_TrcvIdx      The selected transceiver.
 *  \param[out]  TrcvStatusWord      Output parameter reference, the status word. The pointer must be valid.
 *  \return      E_NOT_OK - operation was not successful
 *  \return      E_OK - success
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 **********************************************************************************************************************/
FUNC(void, FRTRCV_30_TJA1080_CODE) FrTrcv_30_Tja1080_Phy_ReadStatusWord( FRTRCV_30_TJA1080_CHANNEL_SYSTEMTYPE_FIRST FrTrcv_30_Tja1080_StatusWordType *TrcvStatusWord );

# define FRTRCV_30_TJA1080_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */


# if ( FRTRCV_30_TJA1080_API_OPTIMIZATION == STD_ON )
/* PRQA S 3453 6 */ /* MD_MSR_19.7 */
#  if !defined ( FRTRCV_30_TJA1080_PHY_SOURCE ) /* COV_FRTRCV_30_TJA1080_PHY_SOURCE */
#   define FrTrcv_30_Tja1080_Phy_Init(TrcvIdx)                                  FrTrcv_30_Tja1080_Phy_Init()
#  endif
#  define FrTrcv_30_Tja1080_Phy_SetMode(TrcvIdx, TrcvMode)                      FrTrcv_30_Tja1080_Phy_SetMode(TrcvMode)
#  define FrTrcv_30_Tja1080_Phy_GetMode(TrcvIdx, TrcvModePtr)                   FrTrcv_30_Tja1080_Phy_GetMode(TrcvModePtr)
#  define FrTrcv_30_Tja1080_Phy_ReadStatusWord(TrcvIdx, TrcvStatusWord)         FrTrcv_30_Tja1080_Phy_ReadStatusWord(TrcvStatusWord)
# endif /* #if ( FRTRCV_30_TJA1080_API_OPTIMIZATION == STD_ON ) */

#endif
  /* FRTRCV_30_TJA180_PHY_H */

/**********************************************************************************************************************
 *  END OF FILE: FrTrcv_30_Tja1080_Phy.h
 *********************************************************************************************************************/
