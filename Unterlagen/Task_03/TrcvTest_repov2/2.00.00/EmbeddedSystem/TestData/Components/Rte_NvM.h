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
 *          File:  Rte_NvM.h
 *        Config:  CanCanFr.dpa
 *   ECU-Project:  ECU_3
 *
 *     Generator:  MICROSAR RTE Generator Version 4.9.0
 *                 RTE Core Version 1.9.0
 *       License:  Unlimited license CBD0000000 for N/A
 *
 *   Description:  Application header file for SW-C <NvM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_NVM_H
# define _RTE_NVM_H

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

# include "Rte_NvM_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvmBlockDescriptor1_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvmBlockDescriptor10_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvmBlockDescriptor11_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvmBlockDescriptor12_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvmBlockDescriptor2_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvmBlockDescriptor3_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvmBlockDescriptor4_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvmBlockDescriptor5_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvmBlockDescriptor6_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvmBlockDescriptor7_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvmBlockDescriptor8_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvmBlockDescriptor9_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_TgfData_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_TgfData_ErrorEntries_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_TgfData_ParamValues_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_NvM_RpNotifyJobEnd_NvmBlockDescriptor1_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvmBlockDescriptor1_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvmBlockDescriptor10_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvmBlockDescriptor10_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvmBlockDescriptor11_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvmBlockDescriptor11_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvmBlockDescriptor12_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvmBlockDescriptor12_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvmBlockDescriptor2_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvmBlockDescriptor2_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvmBlockDescriptor3_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvmBlockDescriptor3_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvmBlockDescriptor4_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvmBlockDescriptor4_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvmBlockDescriptor5_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvmBlockDescriptor5_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvmBlockDescriptor6_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvmBlockDescriptor6_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvmBlockDescriptor7_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvmBlockDescriptor7_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvmBlockDescriptor8_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvmBlockDescriptor8_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvmBlockDescriptor9_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvmBlockDescriptor9_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_TgfData_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_TgfData_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_TgfData_ErrorEntries_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_TgfData_ErrorEntries_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_TgfData_ParamValues_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_TgfData_ParamValues_JobFinished


# endif /* !defined(RTE_CORE) */


# define NvM_START_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_EraseBlock NvM_EraseNvBlock
#  define RTE_RUNNABLE_GetDataIndex NvM_GetDataIndex
#  define RTE_RUNNABLE_GetErrorStatus NvM_GetErrorStatus
#  define RTE_RUNNABLE_InvalidateNvBlock NvM_InvalidateNvBlock
#  define RTE_RUNNABLE_NvM_MainFunction NvM_MainFunction
#  define RTE_RUNNABLE_ReadBlock NvM_ReadBlock
#  define RTE_RUNNABLE_RestoreBlockDefaults NvM_RestoreBlockDefaults
#  define RTE_RUNNABLE_SetBlockProtection NvM_SetBlockProtection
#  define RTE_RUNNABLE_SetDataIndex NvM_SetDataIndex
#  define RTE_RUNNABLE_SetRamBlockStatus NvM_SetRamBlockStatus
#  define RTE_RUNNABLE_WriteBlock NvM_WriteBlock
# endif

FUNC(Std_ReturnType, NvM_CODE) NvM_EraseNvBlock(NvM_BlockIdType parg0); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, NvM_CODE) NvM_GetDataIndex(NvM_BlockIdType parg0, P2VAR(uint8, AUTOMATIC, RTE_NVM_APPL_VAR) DataIndex); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, NvM_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, NvM_CODE) NvM_InvalidateNvBlock(NvM_BlockIdType parg0); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(void, NvM_CODE) NvM_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, NvM_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, NvM_CODE) NvM_RestoreBlockDefaults(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, NvM_CODE) NvM_SetBlockProtection(NvM_BlockIdType parg0, boolean ProtectionEnabled); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, NvM_CODE) NvM_SetDataIndex(NvM_BlockIdType parg0, uint8 DataIndex); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, NvM_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, NvM_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */

# define NvM_STOP_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvMAdministration_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_DS_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_DS_Defs_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_NVM_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_1330:  MISRA rule: 16.4
     Reason:     The RTE Generator uses default names for parameter identifiers of port defined arguments of service modules.
                 Therefore the parameter identifiers in the function declaration differs from those of the implementation of the BSW module.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
