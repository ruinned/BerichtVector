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
/**        \file  trcv.h
 *        \brief  trcv header file
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

#if !defined (TRCV_H)
# define TRCV_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Vendor and module identification */
# define TRCV_VENDOR_ID                           (30u)
# define TRCV_MODULE_ID                           (0x00u)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define TRCV_SW_MAJOR_VERSION                    (1u)
# define TRCV_SW_MINOR_VERSION                    (0u)
# define TRCV_SW_PATCH_VERSION                    (0u)

/* ----- API service IDs ----- */
/*! \brief Service ID: trcv_Init() */
# define TRCV_SID_INIT                            (0x00u)

/* ----- Error codes ----- */
/*! \brief Error code: API service trcv_Init() called with wrong parameter  */
# define TRCV_E_PARAM_CONFIG                      (0x0Au)
/*! \brief Error Code: API service used with an invalid channel identifier or channel was not configured for the
 * functionality of the calling API */
# define TRCV_E_PARAM_CHANNEL                     (0x0Bu)
/*! \brief Error code: API service used with invalid value parameter */
# define TRCV_E_PARAM_VALUE_PTR                   (0x0Cu)
/*! \brief Error code: API service used without module initialization */
# define TRCV_E_UNINIT                            (0x10u)
/*! \brief Error code: The service trcv_Init() is called while the module is already initialized  */
# define TRCV_E_ALREADY_INITIALIZED               (0x11u)
/*! \brief Error code: API service called with NULL_PTR as parameter  */
# define TRCV_E_NULL_POINTER                      (0x12u)

/* ----- Mapping of error reporting macro ----- */
# if (TRCV_DEV_ERROR_DETECT == STD_ON)
#  define Dio_CheckDetErrorReturnVoid(CONDITION, API_ID, ERROR_CODE) \
  {  \
    if (!(CONDITION)) \
    {  \
      (void)Det_ReportError((uint16)TRCV_MODULE_ID, (uint8)0x00, (uint8)(API_ID), (uint8)(ERROR_CODE)); \
      return; \
    } \
  } /* PRQA S 3458, 3109 */ /* MD_MSR_19.4, MD_MSR_14.3 */
#  define Dio_CheckDetErrorReturnValue(CONDITION, API_ID, ERROR_CODE, RET_VAL) \
  { \
    if (!(CONDITION)) \
    { \
      (void)Det_ReportError((uint16)TRCV_MODULE_ID, (uint8)0x00, (uint8)(API_ID), (uint8)(ERROR_CODE)); \
      return (RET_VAL); \
    } \
  } /* PRQA S 3458 */ /* MD_MSR_19.4 */
# else
#  define Dio_CheckDetErrorReturnVoid(CONDITION, API_ID, ERROR_CODE)
#  define Dio_CheckDetErrorReturnValue(CONDITION, API_ID, ERROR_CODE, RET_VAL)
# endif

/* ----- Modes ----- */
# define TRCV_UNINIT                              (0x00u)
# define TRCV_INIT                                (0x01u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint16 FrTrcv_30_Tja1080_StatusWordType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define TRCV_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#ifdef __cplusplus
extern "C"{
#endif

/* Service functions */
extern void trcvDio_InitMemory(void);
extern void trcvDio_Init(void);
extern uint16 trcvDio_ReadWord(uint8 device);
extern void trcvDio_up(void);
extern void trcvDio_down(void);

#ifdef __cplusplus
}
#endif

# define TRCV_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */


#endif /* TRCV_H */

/**********************************************************************************************************************
 *  END OF FILE: trcv.h
 *********************************************************************************************************************/
