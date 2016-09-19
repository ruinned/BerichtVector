/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2014 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Msn.c
 *        \brief  MSN Template source file
 *
 *      \details  Template component to demonstrate the usage of the MICROSAR C style guide. The token Msn/MSN always
 *                has to be read as "Module Short Name" and has to be replaced by the appropriate module prefix as
 *                defined by AUTOSAR, when this template is used for implementation.
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

/* Configuration, interrupt handling implementations differ from the source identification define used in this example.
 * The naming schemes for those files can be taken from this list:
 *
 * Msn_Cfg.c:     MSN_CFG_SOURCE
 * Msn_LCfg.c:    MSN_LCFG_SOURCE
 * Msn_PBCfg.c:   MSN_PBCFG_SOURCE
 * Msn_Irq.c:     MSN_IRQ_SOURCE
 */
#define MSN_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Msn.h"
#include "SchM_Msn.h"   /* Include scheduler module for critical sections */

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of Msn header file */
#if (  (MSN_SW_MAJOR_VERSION != (2u)) \
    || (MSN_SW_MINOR_VERSION != (4u)) \
    || (MSN_SW_PATCH_VERSION != (0u)) )
# error "Vendor specific version numbers of <Msn>.c and <Msn>.h are inconsistent"
#endif

/* Check the version of the configuration header file */
#if (  (MSN_CFG_MAJOR_VERSION != (1u)) \
    || (MSN_CFG_MINOR_VERSION != (1u)) )
# error "Version numbers of <Msn>.c and <Msn>_Cfg.h are inconsistent!"
#endif


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

/*! \brief Example symbolic constant */
#define MSN_MY_SYMBOLIC_CONSTANT        (0x05u)
/*! \brief Reset value for ... */
#define MSN_MY_RESETVALUE               (0x00u)

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

#define MSN_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! \brief Example local variable */
STATIC VAR(uint8, MSN_VAR_NOINIT) Msn_LocalExampleValue;

#define MSN_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define MSN_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! \brief Initialization state of the module */
STATIC VAR(uint8, MSN_VAR_ZERO_INIT) Msn_ModuleInitialized = MSN_UNINIT;

#define MSN_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define MSN_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! \brief Pointer to the current configuration */
STATIC P2CONST(Msn_ConfigType, MSN_VAR_ZERO_INIT, MSN_PBCFG) Msn_ConfigSet_pt = NULL_PTR;

#define MSN_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define MSN_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

STATIC FUNC(uint8, MSN_CODE) Msn_StaticExampleFunction(uint8 index);


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
  Msn_StaticExampleFunction()
**********************************************************************************************************************/
/*! \brief      Example of a local function
 *  \details    This function is an example of a local (static) function. The occurrence of this description in the
 *              doxygen documentation can be enabled/disabled by the 'Extract Static' option.
 *  \param[in]  index                   Any index
 *  \return     0 - success
 *  \return     1 - error
 *  \note       Add a note here.
 *********************************************************************************************************************/
STATIC FUNC(uint8, MSN_CODE) Msn_StaticExampleFunction(uint8 index)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 MyLocalVar;

  /* ----- Implementation ----------------------------------------------- */
  MyLocalVar = (uint8)(index + (uint8)MSN_MY_SYMBOLIC_CONSTANT);

  return (MyLocalVar);

}  /* Msn_StaticExampleFunction() */



/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Msn_InitMemory()
 **********************************************************************************************************************/
/*! \brief      Function for *_INIT_*-variable initialization
 *  \details    Service to initialize module global variables at power up. This function can be used to initialize the
 *              variables in *_INIT_* sections in case they are not initialized by the startup code.
 *  \pre        Module must not be initialized
 *  \pre        Function shall be called from task level
 **********************************************************************************************************************/
FUNC(void, MSN_CODE) Msn_InitMemory(void)
{
  /* ----- Implementation ----------------------------------------------- */
  Msn_ModuleInitialized = MSN_UNINIT;
  Msn_ConfigSet_pt = NULL_PTR;

}  /* Msn_InitMemory() */



/***********************************************************************************************************************
 *  Msn_GlobalExampleFunction()
 **********************************************************************************************************************/
/*! \brief      Example of a global function
 *  \details    This function is an example of a global function. The description of this function is always visible in
 *              the doxygen documentation.
 *  \param[in]  Channel                 Input parameter
 *  \param[out] Value                   Output parameter reference
 *  \return     E_NOT_OK - error
 *  \return     E_OK - success
 *  \pre        Input parameter 'Value' must not be NULL_PTR.
 *  \pre        Input parameter 'Channel' has to be valid.
 *  \pre        Module has to be initialized.
 *  \note       Requirement Specification example function.
 **********************************************************************************************************************/
FUNC(uint8, MSN_CODE) Msn_GlobalExampleFunction(uint8 Channel, P2VAR(uint16, AUTOMATIC, MSN_APPL_VAR) Value)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 MyCounter;

  /* ----- Development Error Checks ------------------------------------- */
  /* Check initialization state of the component */
  Msn_CheckDetErrorReturnValue(Msn_ModuleInitialized == (uint8)MSN_INIT,
    MSN_SID_GLOBAL_EXAMPLE_FUNCTION, MSN_E_UNINIT, E_NOT_OK); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* Check parameter 'Channel' */
  Msn_CheckDetErrorReturnValue(Channel < Msn_ConfigSet_pt->NrOfChannels,
    MSN_SID_GLOBAL_EXAMPLE_FUNCTION, MSN_E_PARAM_CHANNEL, E_NOT_OK); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* Check parameter 'Value' */
  Msn_CheckDetErrorReturnValue(Value != NULL_PTR,
    MSN_SID_GLOBAL_EXAMPLE_FUNCTION, MSN_E_PARAM_VALUE_PTR, E_NOT_OK); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  /* ----- Implementation ----------------------------------------------- */
  for(MyCounter = 0u; MyCounter < Msn_ConfigSet_pt->NrOfChannels; MyCounter++)
  {
    if(Channel != 0u)
    {
      /* the following block needs to be protected by exclusive area */
      SchM_Enter_Msn_MSN_EXCLUSIVE_AREA_0();
      Msn_LocalExampleValue++;
      *Value = Msn_LocalExampleValue;
      SchM_Exit_Msn_MSN_EXCLUSIVE_AREA_0();
    }
    else
    {
      *Value = MSN_MY_RESETVALUE;
      continue; /* PRQA S 770 */ /* MD_Msn_770 */
    }
  }

  return(E_OK);

} /* Msn_GlobalExampleFunction() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */ /* multiple return paths exist in DET checks */



/**********************************************************************************************************************
 * Msn_Init()
 **********************************************************************************************************************/
/*! \brief      Initialization function
 *  \details    This function initializes the module Msn. It initializes all variables and and sets the module state to
 *              initialized.
 *  \param[in]  ConfigPtr               Configuration structure for initializing the module
 *  \pre        Interrupts have to be disabled.
 *  \pre        The module has to be uninitialized.
 *  \pre        Msn_InitMemory has been called unless Msn_ModuleInitialized is initialized by start-up code.
 *  \note       Specification of module initialization
 **********************************************************************************************************************/
FUNC(void, MSN_CODE) Msn_Init(P2CONST(Msn_ConfigType, AUTOMATIC, MSN_PBCFG) ConfigPtr)
{

  /* ----- Development Error Checks ------------------------------------- */
  /* Check initialization state of the component */
  Msn_CheckDetErrorReturnVoid(Msn_ModuleInitialized == (uint8)MSN_UNINIT,
    MSN_SID_INIT, MSN_E_ALREADY_INITIALIZED); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* Check parameter 'ConfigPtr' */
  Msn_CheckDetErrorReturnVoid(ConfigPtr != NULL_PTR,
    MSN_SID_INIT, MSN_E_PARAM_CONFIG); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  /* ----- Implementation ----------------------------------------------- */
  Msn_ConfigSet_pt = ConfigPtr;

  Msn_LocalExampleValue = (uint8)ConfigPtr->ChannelConfig_t[0].Msn_MyStructValue1;

  Msn_LocalExampleValue += Msn_StaticExampleFunction((uint8)0x03u);

  Msn_ModuleInitialized = (uint8)MSN_INIT;

} /* Msn_Init() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */


#if (MSN_VERSION_INFO_API == STD_ON)
/***********************************************************************************************************************
 *  Msn_GetVersionInfo()
 **********************************************************************************************************************/
/*! \brief      Returns the version information
 *  \details    Msn_GetVersionInfo() returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out] versioninfo             Pointer to where to store the version information
 *  \pre        Input parameter must not be NULL.
 *  \pre        Function shall be called from task level
 **********************************************************************************************************************/
FUNC(void, MSN_CODE) Msn_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, MSN_APPL_VAR) versioninfo)
{
  /* ----- Development Error Checks ------------------------------------- */
  Msn_CheckDetErrorReturnVoid(NULL_PTR != versioninfo,
    MSN_SID_GET_VERSION_INFO, MSN_E_NULL_POINTER); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  /* ----- Implementation ----------------------------------------------- */
  versioninfo->vendorID = (MSN_VENDOR_ID);
  versioninfo->moduleID = (MSN_MODULE_ID);
  versioninfo->sw_major_version = (MSN_SW_MAJOR_VERSION);
  versioninfo->sw_minor_version = (MSN_SW_MINOR_VERSION);
  versioninfo->sw_patch_version = (MSN_SW_PATCH_VERSION);

} /* Msn_GetVersionInfo() */  /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif


#define MSN_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Justification for module-specific MISRA deviations:
 MD_Msn_770: rule 14.5
      Reason:     A 'continue' statement has been used for efficiency reasons.
      Risk:       Poor readability of the code, unpredicted program flow.
      Prevention: Program flow has been verified by component tests and review.
*/

/**********************************************************************************************************************
 *  END OF FILE: Msn.c
 *********************************************************************************************************************/
