/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2014 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  protocol.h
 *        \brief  protocol header file
 *
 *        \details basic input/output and port configuration
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Andreas Herkommer             vishr         Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2015-10-08  vishr   -             Creation
*********************************************************************************************************************/

#if !defined (PROT_H)
# define PROT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Vendor and module identification */
# define PROT_VENDOR_ID                           (30u)
# define PROT_MODULE_ID                           (0x00u)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define PROT_SW_MAJOR_VERSION                    (1u)
# define PROT_SW_MINOR_VERSION                    (0u)
# define PROT_SW_PATCH_VERSION                    (0u)

/* ----- API service IDs ----- */
/*! \brief Service ID: protocol_Init() */
# define PROT_SID_INIT                            (0x00u)

/* ----- Error codes ----- */
/*! \brief Error code: API service protocol_Init() called with wrong parameter  */
# define PROT_E_PARAM_CONFIG                      (0x0Au)
/*! \brief Error Code: API service used with an invalid channel identifier or channel was not configured for the
 * functionality of the calling API */
# define PROT_E_PARAM_CHANNEL                     (0x0Bu)
/*! \brief Error code: API service used with invalid value parameter */
# define PROT_E_PARAM_VALUE_PTR                   (0x0Cu)
/*! \brief Error code: API service used without module initialization */
# define PROT_E_UNINIT                            (0x10u)
/*! \brief Error code: The service protocol_Init() is called while the module is already initialized  */
# define PROT_E_ALREADY_INITIALIZED               (0x11u)
/*! \brief Error code: API service called with NULL_PTR as parameter  */
# define PROT_E_NULL_POINTER                      (0x12u)

/* ----- Mapping of error reporting macro ----- */
# if (PROT_DEV_ERROR_DETECT == STD_ON)
#  define Dio_CheckDetErrorReturnVoid(CONDITION, API_ID, ERROR_CODE) \
  {  \
    if (!(CONDITION)) \
    {  \
      (void)Det_ReportError((uint16)PROT_MODULE_ID, (uint8)0x00, (uint8)(API_ID), (uint8)(ERROR_CODE)); \
      return; \
    } \
  } /* PRQA S 3458, 3109 */ /* MD_MSR_19.4, MD_MSR_14.3 */
#  define Dio_CheckDetErrorReturnValue(CONDITION, API_ID, ERROR_CODE, RET_VAL) \
  { \
    if (!(CONDITION)) \
    { \
      (void)Det_ReportError((uint16)PROT_MODULE_ID, (uint8)0x00, (uint8)(API_ID), (uint8)(ERROR_CODE)); \
      return (RET_VAL); \
    } \
  } /* PRQA S 3458 */ /* MD_MSR_19.4 */
# else
#  define Dio_CheckDetErrorReturnVoid(CONDITION, API_ID, ERROR_CODE)
#  define Dio_CheckDetErrorReturnValue(CONDITION, API_ID, ERROR_CODE, RET_VAL)
# endif

/* ----- Modes ----- */
# define PROT_UNINIT                              (0x00u)
# define PROT_INIT                                (0x01u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define PROT_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#ifdef __cplusplus
extern "C"{
#endif

/* Service functions */
extern void protocol_Init(void);

extern void protocol_Dispatcher(void);
extern void protocol_Handler(void);

/* Complex Operations */
extern void protocol_ComplexOp_wakeUpPattern(uint8 aa);
extern void protocol_ComplexOp_lokalWakeUp(void);
extern void protocol_ComplexOp_forceBusCollition(void);
extern void protocol_ComplexOp_forceTxEntimeout(void);
extern void protocol_ComplexOp_ClampVbat(uint8 ed);

extern void protocol_GetVersion(void);
extern void protocol_Transceiverdevicemode(void);
extern void protocol_SetDIO(void);
extern void protocol_GetDIO(void);
extern void protocol_WriteReadTRCVStatusWord(void);
extern void protocol_ResetAllDioPins(void);

#ifdef __cplusplus
}
#endif

# define PROT_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */


#endif /* PROT_H */

/**********************************************************************************************************************
 *  END OF FILE: protocol.h
 *********************************************************************************************************************/
