/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_CtApFeatureValidation.h
 *        Config:  CanCanFr.dpa
 *   ECU-Project:  ECU_3
 *
 *     Generator:  MICROSAR RTE Generator Version 4.9.0
 *                 RTE Core Version 1.9.0
 *       License:  Unlimited license CBD0000000 for N/A
 *
 *   Description:  Application header file for SW-C <CtApFeatureValidation>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CTAPFEATUREVALIDATION_H
# define _RTE_CTAPFEATUREVALIDATION_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_CtApFeatureValidation_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(SG_sigGrpRx_0x22F_IL, RTE_VAR_NOINIT) Rte_CtApFeatureValidation_SG_sigGrpRx_0x22F_IL_SWC_SG_sigGrpRx_0x22F_IL; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_PiFEAT1618RxGroupSignalSubElementCfg5MappedDelegationPort_DeRxGroupSignalSubElementCfg5MappedDelegationPort (0U)
#  define Rte_InitValue_PiFEAT1618RxGroupSignalSubElementCfg5MappedNoDelegationPort_DeRxGroupSignalSubElementCfg5MappedNoDelegationPort (0U)
#  define Rte_InitValue_PiFEAT1618RxGroupSignalSubElementDevMapped_DeRxGroupSignalSubElementDevMapped (0U)
#  define Rte_InitValue_PiFEAT1618RxGroupSignalSubElementDevMapped_SWC_DeRxGroupSignalSubElementDevMapped (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApFeatureValidation_PiFEAT1618RxGroupSignalSubElementCfg5MappedDelegationPort_DeRxGroupSignalSubElementCfg5MappedDelegationPort(P2VAR(uint8, AUTOMATIC, RTE_CTAPFEATUREVALIDATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApFeatureValidation_PiFEAT1618RxGroupSignalSubElementDevMapped_DeRxGroupSignalSubElementDevMapped(P2VAR(uint16, AUTOMATIC, RTE_CTAPFEATUREVALIDATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApFeatureValidation_SG_sigGrpRx_0x22F_IL_SWC_SG_sigGrpRx_0x22F_IL(P2CONST(SG_sigGrpRx_0x22F_IL, AUTOMATIC, RTE_CTAPFEATUREVALIDATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_PiFEAT1618RxGroupSignalSubElementCfg5MappedDelegationPort_DeRxGroupSignalSubElementCfg5MappedDelegationPort Rte_Read_CtApFeatureValidation_PiFEAT1618RxGroupSignalSubElementCfg5MappedDelegationPort_DeRxGroupSignalSubElementCfg5MappedDelegationPort
#  define Rte_Read_PiFEAT1618RxGroupSignalSubElementCfg5MappedNoDelegationPort_DeRxGroupSignalSubElementCfg5MappedNoDelegationPort Rte_Read_CtApFeatureValidation_PiFEAT1618RxGroupSignalSubElementCfg5MappedNoDelegationPort_DeRxGroupSignalSubElementCfg5MappedNoDelegationPort
#  define Rte_Read_CtApFeatureValidation_PiFEAT1618RxGroupSignalSubElementCfg5MappedNoDelegationPort_DeRxGroupSignalSubElementCfg5MappedNoDelegationPort(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PiFEAT1618RxGroupSignalSubElementDevMapped_DeRxGroupSignalSubElementDevMapped Rte_Read_CtApFeatureValidation_PiFEAT1618RxGroupSignalSubElementDevMapped_DeRxGroupSignalSubElementDevMapped
#  define Rte_Read_PiFEAT1618RxGroupSignalSubElementDevMapped_SWC_DeRxGroupSignalSubElementDevMapped Rte_Read_CtApFeatureValidation_PiFEAT1618RxGroupSignalSubElementDevMapped_SWC_DeRxGroupSignalSubElementDevMapped
#  define Rte_Read_CtApFeatureValidation_PiFEAT1618RxGroupSignalSubElementDevMapped_SWC_DeRxGroupSignalSubElementDevMapped(data) (*(data) = Rte_CtApFeatureValidation_SG_sigGrpRx_0x22F_IL_SWC_SG_sigGrpRx_0x22F_IL.grpSig00Rx_0x22F_IL, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_SG_sigGrpRx_0x22F_IL_SWC_SG_sigGrpRx_0x22F_IL Rte_Write_CtApFeatureValidation_SG_sigGrpRx_0x22F_IL_SWC_SG_sigGrpRx_0x22F_IL


# endif /* !defined(RTE_CORE) */


# define CtApFeatureValidation_START_SEC_CODE
# include "CtApFeatureValidation_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CtApFeatureValidation_10ms CtApFeatureValidation_10ms
#  define RTE_RUNNABLE_CtApFeatureValidation_Init CtApFeatureValidation_Init
# endif

FUNC(void, CtApFeatureValidation_CODE) CtApFeatureValidation_10ms(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtApFeatureValidation_CODE) CtApFeatureValidation_Init(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define CtApFeatureValidation_STOP_SEC_CODE
# include "CtApFeatureValidation_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CTAPFEATUREVALIDATION_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
