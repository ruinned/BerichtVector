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
/**        \file  dio.h
 *        \brief  dio header file
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

#if !defined (DIO_H)
# define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include <avr/io.h>
# include "Std_Types.h"
# include "dio_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Vendor and module identification */
# define DIO_VENDOR_ID                           (30u)
# define DIO_MODULE_ID                           (0x00u)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define DIO_SW_MAJOR_VERSION                    (1u)
# define DIO_SW_MINOR_VERSION                    (0u)
# define DIO_SW_PATCH_VERSION                    (0u)

/* ----- API service IDs ----- */
/*! \brief Service ID: dio_Init() */
# define DIO_SID_INIT                            (0x00u)

/* ----- Error codes ----- */
/*! \brief Error code: API service dio_Init() called with wrong parameter  */
# define DIO_E_PARAM_CONFIG                      (0x0Au)
/*! \brief Error Code: API service used with an invalid channel identifier or channel was not configured for the
 * functionality of the calling API */
# define DIO_E_PARAM_CHANNEL                     (0x0Bu)
/*! \brief Error code: API service used with invalid value parameter */
# define DIO_E_PARAM_VALUE_PTR                   (0x0Cu)
/*! \brief Error code: API service used without module initialization */
# define DIO_E_UNINIT                            (0x10u)
/*! \brief Error code: The service dio_Init() is called while the module is already initialized  */
# define DIO_E_ALREADY_INITIALIZED               (0x11u)
/*! \brief Error code: API service called with NULL_PTR as parameter  */
# define DIO_E_NULL_POINTER                      (0x12u)

/* ----- Mapping of error reporting macro ----- */
# if (DIO_DEV_ERROR_DETECT == STD_ON)
#  define Dio_CheckDetErrorReturnVoid(CONDITION, API_ID, ERROR_CODE) \
  {  \
    if (!(CONDITION)) \
    {  \
      (void)Det_ReportError((uint16)DIO_MODULE_ID, (uint8)0x00, (uint8)(API_ID), (uint8)(ERROR_CODE)); \
      return; \
    } \
  } /* PRQA S 3458, 3109 */ /* MD_MSR_19.4, MD_MSR_14.3 */
#  define Dio_CheckDetErrorReturnValue(CONDITION, API_ID, ERROR_CODE, RET_VAL) \
  { \
    if (!(CONDITION)) \
    { \
      (void)Det_ReportError((uint16)DIO_MODULE_ID, (uint8)0x00, (uint8)(API_ID), (uint8)(ERROR_CODE)); \
      return (RET_VAL); \
    } \
  } /* PRQA S 3458 */ /* MD_MSR_19.4 */
# else
#  define Dio_CheckDetErrorReturnVoid(CONDITION, API_ID, ERROR_CODE)
#  define Dio_CheckDetErrorReturnValue(CONDITION, API_ID, ERROR_CODE, RET_VAL)
# endif

/* ----- Modes ----- */
# define DIO_UNINIT                              (0x00u)
# define DIO_INIT                                (0x01u)

#define STD_HIGH                                 (0x01)
#define STD_LOW                                  (0x00)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8 Dio_LevelType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define DIO_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#ifdef __cplusplus
extern "C"{
#endif

/* Service functions */
extern void dio_WriteChannel(uint8 Channel, uint8 value);
extern uint8 dio_ReadChannel(uint8 Channel);
extern void dio_InitMemory(void);
extern void dio_Init(void);

#ifdef __cplusplus
}
#endif

# define DIO_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */


#endif /* DIO_H */

/**********************************************************************************************************************
 *  END OF FILE: dio.h
 *********************************************************************************************************************/
