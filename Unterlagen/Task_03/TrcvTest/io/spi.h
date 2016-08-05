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
/**        \file  spi.h
 *        \brief  spi header file
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

#if !defined (SPI_H)
# define SPI_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"
# include "spi_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Vendor and module identification */
# define SPI_VENDOR_ID                           (30u)
# define SPI_MODULE_ID                           (0x00u)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define SPI_SW_MAJOR_VERSION                    (1u)
# define SPI_SW_MINOR_VERSION                    (0u)
# define SPI_SW_PATCH_VERSION                    (0u)

/* ----- API service IDs ----- */
/*! \brief Service ID: spi_Init() */
# define SPI_SID_INIT                            (0x00u)

/* ----- Error codes ----- */
/*! \brief Error code: API service spi_Init() called with wrong parameter  */
# define SPI_E_PARAM_CONFIG                      (0x0Au)
/*! \brief Error Code: API service used with an invalid channel identifier or channel was not configured for the
 * functionality of the calling API */
# define SPI_E_PARAM_CHANNEL                     (0x0Bu)
/*! \brief Error code: API service used with invalid value parameter */
# define SPI_E_PARAM_VALUE_PTR                   (0x0Cu)
/*! \brief Error code: API service used without module initialization */
# define SPI_E_UNINIT                            (0x10u)
/*! \brief Error code: The service spi_Init() is called while the module is already initialized  */
# define SPI_E_ALREADY_INITIALIZED               (0x11u)
/*! \brief Error code: API service called with NULL_PTR as parameter  */
# define SPI_E_NULL_POINTER                      (0x12u)

/* ----- Mapping of error reporting macro ----- */
# if (SPI_DEV_ERROR_DETECT == STD_ON)
#  define Dio_CheckDetErrorReturnVoid(CONDITION, API_ID, ERROR_CODE) \
  {  \
    if (!(CONDITION)) \
    {  \
      (void)Det_ReportError((uint16)SPI_MODULE_ID, (uint8)0x00, (uint8)(API_ID), (uint8)(ERROR_CODE)); \
      return; \
    } \
  } /* PRQA S 3458, 3109 */ /* MD_MSR_19.4, MD_MSR_14.3 */
#  define Dio_CheckDetErrorReturnValue(CONDITION, API_ID, ERROR_CODE, RET_VAL) \
  { \
    if (!(CONDITION)) \
    { \
      (void)Det_ReportError((uint16)SPI_MODULE_ID, (uint8)0x00, (uint8)(API_ID), (uint8)(ERROR_CODE)); \
      return (RET_VAL); \
    } \
  } /* PRQA S 3458 */ /* MD_MSR_19.4 */
# else
#  define Dio_CheckDetErrorReturnVoid(CONDITION, API_ID, ERROR_CODE)
#  define Dio_CheckDetErrorReturnValue(CONDITION, API_ID, ERROR_CODE, RET_VAL)
# endif

/* ----- Modes ----- */
# define SPI_UNINIT                              (0x00u)
# define SPI_INIT                                (0x01u)

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

# define SPI_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#ifdef __cplusplus
extern "C"{
#endif

/* Service functions */
extern void spi_InitMemory(void);
extern void spi_Init(void);

extern uint8 spi_transfer(uint8 data);

#ifdef __cplusplus
}
#endif

# define SPI_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */


#endif /* SPI_H */

/**********************************************************************************************************************
 *  END OF FILE: spi.h
 *********************************************************************************************************************/
