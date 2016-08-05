/***********************************************************************************************************************
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
/*!        \file  Mip.c
 *        \brief  Mip source file
 *      \details  Template component to demonstrate the usage of the MICROSAR C style guide. The token Mip/MIP always
 *                has to be read as "Module Short Name" and has to be replaced by the appropriate module prefix as
 *                defined by AUTOSAR, when this template is used for implementation.
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 **********************************************************************************************************************/

#define MIP_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "Mip.h"
#include "Mip_Cbk.h"
#include "SchM_Mip.h"
#if (MIP_DEV_ERROR_DETECT == STD_ON)
# include "Det.h"
#endif

/* SBSW_Mip_59 */
/*********************************************************************************************************************** 
 *  VERSION CHECK
 **********************************************************************************************************************/
/* Check the version of Mip header file */
#if (  (MIP_SW_MAJOR_VERSION != (3u)) \
    || (MIP_SW_MINOR_VERSION != (0u)) \
    || (MIP_SW_PATCH_VERSION != (0u)) )
# error "Vendor specific version numbers of <Mip>.c and <Mip>.h are inconsistent"
#endif

/* Check the version of the configuration header file */
#if (  (MIP_CFG_MAJOR_VERSION != (1u)) \
    || (MIP_CFG_MINOR_VERSION != (1u)) )
# error "Version numbers of <Mip>.c and <Mip>_Cfg.h are inconsistent!"
#endif

/***********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 ***********************************************************************************************************************/
/*! Example symbolic constant */
#define MIP_MY_SYMBOLIC_CONSTANT        (0x05u)
/*! Reset value for ... */
#define MIP_MY_RESETVALUE               (0x00u)

/***********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 ***********************************************************************************************************************/
#if !defined (MIP_LOCAL)
# define MIP_LOCAL static
#endif

#if !defined (MIP_LOCAL_INLINE)
# define MIP_LOCAL_INLINE LOCAL_INLINE
#endif

/***********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 ***********************************************************************************************************************/
 
/***********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 ***********************************************************************************************************************/
#define MIP_START_SEC_VAR_NOINIT_8
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Example local variable */
MIP_LOCAL VAR(uint8, MIP_VAR_NOINIT) Mip_LocalExampleValue; /* SBSW_Mip_100 */

#define MIP_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define MIP_START_SEC_VAR_ZERO_INIT_8
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Initialization state of the module */
#if (MIP_DEV_ERROR_DETECT == STD_ON)
MIP_LOCAL VAR(uint8, MIP_VAR_ZERO_INIT) Mip_ModuleInitialized = MIP_UNINIT;
#endif

#define MIP_STOP_SEC_VAR_ZERO_INIT_8
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define MIP_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Pointer to the current configuration */
MIP_LOCAL P2CONST(Mip_ConfigType, MIP_VAR_ZERO_INIT, MIP_PBCFG) Mip_ConfigSet_pt = NULL_PTR;

#define MIP_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  GLOBAL DATA
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 ***********************************************************************************************************************/
#define MIP_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
  Mip_StaticExampleFunction()
***********************************************************************************************************************/
/*! \brief      Example of a local function
 *  \details    This function is an example of a local (static) function. The occurrence of this description in the
 *              doxygen documentation can be enabled/disabled by the 'Extract Static' option.
 *  \param[in]  index                   Any index
 *  \return     0 - success
 *  \return     1 - error
 *  \pre        TBD
 *  \note       Add a note here.
 **********************************************************************************************************************/
MIP_LOCAL_INLINE FUNC(uint8, MIP_CODE) Mip_StaticExampleFunction(uint8 index);

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/
/*!
 * \internal
 * TEXT
 * \endinternal
 */
MIP_LOCAL_INLINE FUNC(uint8, MIP_CODE) Mip_StaticExampleFunction(uint8 index)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 myLocalVar;

  /* ----- Implementation ----------------------------------------------- */
  myLocalVar = (uint8)(index + (uint8)MIP_MY_SYMBOLIC_CONSTANT);

  return (myLocalVar);
}

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 *  Mip_InitMemory()
 ***********************************************************************************************************************/
/*!
 * \internal
 * Initialize the following variables with the corresponding values:
 * - Mip_ModuleInitialized = MIP_UNINIT
 * - Mip_ConfigSet_pt = NULL_PTR
 *
 * \endinternal
 */
FUNC(void, MIP_CODE) Mip_InitMemory(void)
{
  /* ----- Implementation ----------------------------------------------- */
#if (MIP_DEV_ERROR_DETECT == STD_ON)
  Mip_ModuleInitialized = MIP_UNINIT;
#endif
  Mip_ConfigSet_pt = NULL_PTR;
}

#if ( MIP_DEV_ERROR_DETECT == STD_ON )
#define Mip_ReportDet(a,b)     (void)Det_ReportError(MIP_MODULE_ID, MIP_INSTANCE_ID_DET, a, b)
#else
#define Mip_ReportDet(a,b)
#endif

/***********************************************************************************************************************
 * Mip_GlobalExampleFunction()
 ***********************************************************************************************************************/
/*! 
 * \internal
 * - Check if component is initialized
 * - Check Channel parameter validity against configuration
 * - Check Value parameter for NULL pointer
 *  -  
 * - Report error if applicable
 * \endinternal
 */
FUNC(uint8, MIP_CODE) Mip_GlobalExampleFunction(uint8 Channel, P2VAR(uint16, AUTOMATIC, MIP_APPL_VAR) Value)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = MIP_E_NO_ERROR;
  uint8_least myCounter;

  /* ----- Development Error Checks ------------------------------------- */
#if (MIP_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (Mip_ModuleInitialized == MIP_UNINIT)
  {
    errorId = MIP_E_UNINIT;
  }
  /* Check parameter 'Channel' */
  else if (Channel >= Mip_ConfigSet_pt->NrOfChannels)
  {
    errorId = MIP_E_PARAM_CHANNEL;
  }
  /* Check parameter 'Value' */
  else if (Value == NULL_PTR)
  {
    errorId = MIP_E_PARAM_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    for(myCounter = 0u; myCounter < Mip_ConfigSet_pt->NrOfChannels; myCounter++)
    {
      if(Channel == 0u)
      {
        *Value = MIP_MY_RESETVALUE; /* SBSW_Mip_60 */
        continue; /* PRQA S 770 */ /* MD_Mip_770 */
      }
      else
      {
        /* the following block needs to be protected by exclusive area */
        SchM_Enter_Mip_MIP_EXCLUSIVE_AREA_0();
        Mip_LocalExampleValue++;
        *Value = Mip_LocalExampleValue; /* SBSW_Mip_3 */
        SchM_Exit_Mip_MIP_EXCLUSIVE_AREA_0();
      }
    }
    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
#if (MIP_DEV_ERROR_REPORT == STD_ON)
  if (errorId != MIP_E_NO_ERROR)
  {
    /* SBSW_Mip_4 */
    Mip_ReportDet(MIP_SID_GLOBAL_EXAMPLE_FUNCTION, errorId);
  }
#else
  MIP_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */ /* SBSW_Mip_56 */
#endif

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */



/*!
 \internal
 - #10 irgendwelcher text / irgendwelcher text 2
 \endinternal 
 */

      /* PRQA S 3673 */            /* MD_LIN_HL_16.7 */
/***********************************************************************************************************************
 *  Mip_MainFunction()
 ***********************************************************************************************************************/
/*!
 * \internal
 * TEXT
 * \endinternal
 */
FUNC(void, MIP_CODE) Mip_MainFunction(void)
{
}

/***********************************************************************************************************************
 *  Mip_Init()
 ***********************************************************************************************************************/
/*!
 * \internal
 * - #100 Check if component is uninitialized
 * - #200 Check Value parameter for NULL pointer
 *  -  
 * - #300 Report error if applicable
 * \endinternal
 */
FUNC(void, MIP_CODE) Mip_Init(P2CONST(Mip_ConfigType, AUTOMATIC, MIP_PBCFG) ConfigPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = MIP_E_NO_ERROR;

   /* #100 Check if component is uninitialized */
   /* #200 Check Value parameter for NULL pointer */

  /* ----- Development Error Checks ------------------------------------- */
#if (MIP_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (Mip_ModuleInitialized == (uint8)MIP_INIT)
  {
    errorId = MIP_E_ALREADY_INITIALIZED;
  }
  /* Check parameter 'ConfigPtr' */
  else if (ConfigPtr == NULL_PTR)
  {
    errorId = MIP_E_PARAM_CONFIG;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    Mip_ConfigSet_pt = ConfigPtr;

    Mip_LocalExampleValue += Mip_StaticExampleFunction((uint8)0x03u); /* SBSW_Mip_5 */

#if (MIP_DEV_ERROR_DETECT == STD_ON)
    Mip_ModuleInitialized = (uint8)MIP_INIT;
#endif
  }

  /* ----- Development Error Report --------------------------------------- */
#if (MIP_DEV_ERROR_REPORT == STD_ON)
  if (errorId != MIP_E_NO_ERROR)
  {
    (void)Det_ReportError(MIP_MODULE_ID, MIP_INSTANCE_ID_DET, MIP_SID_INIT, errorId); /* SBSW_Mip_6 */
  }
#else
   MIP_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
   Mip_ConfigSet_pt = ConfigPtr;
   Mip_LocalExampleValue += Mip_StaticExampleFunction((uint8)0x03u);
#endif
} /*lint !e438 */ /* PRQA S 6080 */

#if (MIP_VERSION_INFO_API == STD_ON)
/***********************************************************************************************************************
 *  Mip_GetVersionInfo()
 ***********************************************************************************************************************/
/*!
 * \internal
 * - Check versioninfo for NULL pointer. Note: no uninit check is performed.
 *  - Set versioninfo with corresponding macros from component header.
 * - Report error if applicable.
 * \endinternal
 */
FUNC(void, MIP_CODE) Mip_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, MIP_APPL_VAR) versioninfo)
{
  uint8 errorId = MIP_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
# if (MIP_DEV_ERROR_DETECT == STD_ON)
  if (versioninfo == NULL_PTR)
  {
    errorId = MIP_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    versioninfo->vendorID = (MIP_VENDOR_ID); /* SBSW_Mip_7 */
    versioninfo->moduleID = (MIP_MODULE_ID); /* SBSW_Mip_8 */
    versioninfo->sw_major_version = (MIP_SW_MAJOR_VERSION); /* SBSW_Mip_9 */
    versioninfo->sw_minor_version = (MIP_SW_MINOR_VERSION); /* SBSW_Mip_10 */
    versioninfo->sw_patch_version = (MIP_SW_PATCH_VERSION); /* SBSW_Mip_11 */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (MIP_DEV_ERROR_REPORT == STD_ON)
  if (errorId != MIP_E_NO_ERROR)
  {
    (void)Det_ReportError(MIP_MODULE_ID, MIP_INSTANCE_ID_DET, MIP_SID_GET_VERSION_INFO, errorId); /* SBSW_Mip_12 */
  }
# else
  MIP_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */  /* SBSW_Mip_58 */ /* SBSW_Mip_58 */
# endif
}
#endif

/*!
 * \internal
 *  TEXT
 * \endinternal
 */
FUNC(Std_ReturnType, MIP_CODE) Mip_SampleA(void)
{
  return E_OK;
}
/*!
 * \internal
 *  TEXT
 * \endinternal
 */
FUNC(Std_ReturnType, MIP_CODE) Mip_SampleB(uint8 handleB)
{
  MIP_DUMMY_STATEMENT(handleB); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  return E_OK;
}

/*!
 * \internal
 *  TEXT
 * \endinternal
 */
FUNC(Std_ReturnType, MIP_CODE) Mip_SampleC( uint8 handle, uint16 ptr )
{
  MIP_DUMMY_STATEMENT(handle); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  MIP_DUMMY_STATEMENT(ptr); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  return E_OK;
}

/*!
 * \internal
 *  TEXT
 * \endinternal
 */
FUNC(Std_ReturnType, MIP_CODE) Mip_SampleD( uint8 handle, uint16 ptr )
{
  MIP_DUMMY_STATEMENT(handle); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  MIP_DUMMY_STATEMENT(ptr); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  return E_OK;
}

/**********************************************************************************************************************
 *  Nm_MainFunction()
 *********************************************************************************************************************/
/*! \fn          Nm_MainFunction
 *  \brief       Implements the processes of the NM Interface, which need a fix cyclic scheduling.
 *  \details     Implements the handling of coordinated networks of the NM Interface.
 *  \pre         Coordinator Support is enabled.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
 *  \trace       CREQ-610, SPEC-4107, SPEC-4110
 *********************************************************************************************************************/
/* The Nm_MainFunction definition is localized in Nm.c. The declaration is realized by SchM */




#if defined A
#if B == ON
/*!
 * \internal
 * TBD
 * \endinternal
 */
FUNC(void, MIP_CODE) Mip_UnInit( void )
{
}
#else
FUNC(void, MIP_CODE) Mip_UnInit( void )
{
}
#endif
#else
  FUNC(void, MIP_CODE) Mip_UnInit( void )
{
}

  #   endif

#define MIP_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  MISRA JUSTIFICATIONS
 **********************************************************************************************************************/
/* Justification for module-specific MISRA deviations:
  MD_Mip_770: rule 14.5
    Reason:     A 'continue' statement has been used for efficiency reasons.
    Risk:       Poor readability of the code, unpredicted program flow.
    Prevention: Program flow has been verified by component tests and review2.
  MD_Mip_771: rule 14.5
    Reason:     A 'continue' statement has been used for efficiency reasons.
    Prevention: Program flow has been verified by component tests and review3.
  MD_Mip_773: rule 14.5
    Risk:       Poor readability of the code, unpredicted program flow.
    Prevention: Program flow has been verified by component tests and review4.
  MD_Mip_775: rule 14.5
    Reason:     
    Prevention: Program flow has been verified by component tests and review5.
*/

/***********************************************************************************************************************
 *  SILENTBSW JUSTIFICATIONS
 **********************************************************************************************************************/
/* SBSW_JUSTIFICATION_BEGIN
  \ID SBSW_Mip_3
    \DESCRIPTION Any text
                  next line
    \COUNTERMEASURE \N ANY
                  and some more
  \ID SBSW_Mip_60
    \DESCRIPTION text ToDo text
    \COUNTERMEASURE \N textN \S textS \M textM
                    \R textR
                    \T TCASE-5678
                    
\ID SBSW_MSN_1
 \DESCRIPTION Write access to the CalcBS array, indexed by the RxHdl parameter.  
 The function expects RxHdl to be valid (< number of Rx SDUs).
 \COUNTERMEASURE \M CalcBS must match the number of Rx SDUs. Verify that:
 size of CalcBS[] == MSN_NUM_SDUS
\ID SBSW_MSN_READPARAMETER_PTR
 \DESCRIPTION The function writes to the 'value' pointer parameter.
 \COUNTERMEASURE \S Verify that the parameter 'value' points to a valid memory location.
 SMI-5678
                 \R A runtime check prevents dereferencing a NULL pointer.
                    
\ID SBSW_MSN_1234
 \DESCRIPTION Access to the given pointer.
 \COUNTERMEASURE \S [CM_MSN_123]
\ID SBSW_MSN_1234
 \DESCRIPTION Access to the given pointer.
 \COUNTERMEASURE \S [CM_MSN_123]
                    
SBSW_JUSTIFICATION_END */


/*
\CM CM_MSN_123 The given pointer ABC must be valid.
*/


/***********************************************************************************************************************
 *  END OF FILE: Mip.c
 **********************************************************************************************************************/
