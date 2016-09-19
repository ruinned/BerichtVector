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
/**        \file  Msn.h
 *        \brief  MSN Template header file
 *
 *      \details  Template component to demonstrate the usage of the MICROSAR C style guide. The token Msn/MSN always
 *                has to be read as "Module Short Name" and has to be replaced by the appropriate module prefix as
 *                defined by AUTOSAR, when this template is used for implementation.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Bernd Jesse                   visjs         Vector Informatik GmbH
 *  Matthias Fleischmann          visfn         Vector Informatik GmbH
 *  Hartmut Hoerner               vishh         Vector Informatik GmbH
 *  Tobias Schmid                 virtsd        Vector Informatik GmbH
 *  Markus Schwarz                vismas        Vector Informatik GmbH
 *  Christoph Ederer              vircer        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2004-07-08  visjs   ESCAN00012345 <Title of ESCAN00012345>
 *  01.01.00  2004-07-10  vishh   -             <Description without ESCAN00012345>
 *  02.00.00  2007-03-23  visfn   -             Update of the template
 *  02.01.00  2007-05-22  virtsd  -             Template adjusted to the needs of MICROSAR components
 *  02.02.00  2011-07-11  vismas  -             Removed constants (ClusterWG task 154)
 *  02.03.00  2013-07-13  vircer  -             Update to AUTOSAR 4
 *                                -             Addition of Msn_GetVersionInfo() and Msn_InitMemory()
 *                                -             Rework of Doxygen tags
 *  02.04.00  2014-08-19  vishh   -             Rework based on review comments
 *                                              Module version information changed to decimal
 *                                              history only in header file
*********************************************************************************************************************/


/* Configuration, interrupt handling and call-back headers use different names for the multiple inclusion protection
 * define, shown in this example. The appropriate names for these files can be taken from this list:
 *
 * Msn_Cfg.h:     MSN_CFG_H
 * Msn_Irq.h:     MSN_IRQ_H
 * Msn_Cbk.h:     MSN_CBK_H
 */
#if !defined (MSN_H)
# define MSN_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"
# include "Msn_Cfg.h"

# if (MSN_DEV_ERROR_DETECT == STD_ON)
#  include "Det.h"       /* Include Development Error Tracer */
# endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Vendor and module identification */
# define MSN_VENDOR_ID                           (30u)
# define MSN_MODULE_ID                           (0x00u)

/* AUTOSAR Software specification version information */
# define MSN_AR_RELEASE_MAJOR_VERSION            (0x04u)
# define MSN_AR_RELEASE_MINOR_VERSION            (0x00u)
# define MSN_AR_RELEASE_REVISION_VERSION         (0x03u)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define MSN_SW_MAJOR_VERSION                    (2u)
# define MSN_SW_MINOR_VERSION                    (4u)
# define MSN_SW_PATCH_VERSION                    (0u)

# define MSN_INSTANCE_ID_DET                     (0x00u)

/* ----- API service IDs ----- */
/*! \brief Service ID: Msn_Init() */
# define MSN_SID_INIT                            (0x00u)
/*! \brief Service ID: Msn_GlobalExampleFunction() */
# define MSN_SID_GLOBAL_EXAMPLE_FUNCTION         (0x01u)
/*! \brief Service ID: Msn_GetVersionInfo() */
# define MSN_SID_GET_VERSION_INFO                (0x10u)

/* ----- Error codes ----- */
/*! \brief Error code: API service Msn_Init() called with wrong parameter  */
# define MSN_E_PARAM_CONFIG                      (0x0Au)
/*! \brief Error Code: API service used with an invalid channel identifier or channel was not configured for the
 * functionality of the calling API */
# define MSN_E_PARAM_CHANNEL                     (0x0Bu)
/*! \brief Error code: API service used with invalid value parameter */
# define MSN_E_PARAM_VALUE_PTR                   (0x0Cu)
/*! \brief Error code: API service used without module initialization */
# define MSN_E_UNINIT                            (0x10u)
/*! \brief Error code: The service Msn_Init() is called while the module is already initialized  */
# define MSN_E_ALREADY_INITIALIZED               (0x11u)
/*! \brief Error code: API service called with NULL_PTR as parameter  */
# define MSN_E_NULL_POINTER                      (0x12u)

/* ----- Mapping of error reporting macro ----- */
# if (MSN_DEV_ERROR_DETECT == STD_ON)
#  define Msn_CheckDetErrorReturnVoid(CONDITION, API_ID, ERROR_CODE) \
  {  \
    if (!(CONDITION)) \
    {  \
      (void)Det_ReportError((uint16)MSN_MODULE_ID, (uint8)MSN_INSTANCE_ID_DET, (uint8)(API_ID), (uint8)(ERROR_CODE)); \
      return; \
    } \
  } /* PRQA S 3458, 3109 */ /* MD_MSR_19.4, MD_MSR_14.3 */
#  define Msn_CheckDetErrorReturnValue(CONDITION, API_ID, ERROR_CODE, RET_VAL) \
  { \
    if (!(CONDITION)) \
    { \
      (void)Det_ReportError((uint16)MSN_MODULE_ID, (uint8)MSN_INSTANCE_ID_DET, (uint8)(API_ID), (uint8)(ERROR_CODE)); \
      return (RET_VAL); \
    } \
  } /* PRQA S 3458 */ /* MD_MSR_19.4 */
# else
#  define Msn_CheckDetErrorReturnVoid(CONDITION, API_ID, ERROR_CODE)
#  define Msn_CheckDetErrorReturnValue(CONDITION, API_ID, ERROR_CODE, RET_VAL)
# endif

/* ----- Modes ----- */
# define MSN_UNINIT                              (0x00u)
# define MSN_INIT                                (0x01u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/*! \brief Example of a function-like macro */
# define MSN_DO_SOMETHING(XYZ, ABC)              ((XYZ) = (ABC) + 1) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! \brief      Example function pointer type definition */
typedef P2FUNC(void, MSN_APPL_CODE, Msn_NotificationType) (void);

/*! \brief Example struct type definition */
typedef struct
{
  uint32 Msn_MyStructValue1;
  uint32 Msn_MyStructValue2;
} Msn_ChannelConfigType;

/*! \brief Example struct type definition */
typedef struct
{
  uint8 NrOfChannels;
  P2CONST(Msn_ChannelConfigType, AUTOMATIC, MSN_PBCFG) ChannelConfig_t;
  Msn_NotificationType Notification_pt;
} Msn_ConfigType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

# define MSN_START_SEC_VAR_NOINIT_32BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! \brief Example global variable definition */
extern VAR(uint32, MSN_VAR_NOINIT) Msn_ExampleValue;

# define MSN_STOP_SEC_VAR_NOINIT_32BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define MSN_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Service functions */
FUNC(void, MSN_CODE) Msn_InitMemory(void);
FUNC(void, MSN_CODE) Msn_Init(P2CONST(Msn_ConfigType, AUTOMATIC, MSN_PBCFG) ConfigPtr);
FUNC(uint8, MSN_CODE) Msn_GlobalExampleFunction(uint8 Channel, P2VAR(uint16, AUTOMATIC, MSN_APPL_VAR) Value);
FUNC(void, MSN_CODE) Msn_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, MSN_APPL_VAR) versioninfo);

# define MSN_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */


#endif /* MSN_H */

/**********************************************************************************************************************
 *  END OF FILE: Msn.h
 *********************************************************************************************************************/
