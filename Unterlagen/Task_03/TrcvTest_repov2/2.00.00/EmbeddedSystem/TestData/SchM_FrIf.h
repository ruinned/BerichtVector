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
 *          File:  SchM_FrIf.h
 *        Config:  CanCanFr.dpa
 *   ECU-Project:  ECU_3
 *
 *     Generator:  MICROSAR RTE Generator Version 4.9.0
 *                 RTE Core Version 1.9.0
 *       License:  Unlimited license CBD0000000 for N/A
 *
 *   Description:  Header of BSW Scheduler for BSW Module <FrIf>
 *********************************************************************************************************************/
#ifndef SCHM_FRIF_H
# define SCHM_FRIF_H

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "SchM_FrIf_Type.h"

# include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_1.1_828, MD_Rte_Os */

# define FRIF_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, FRIF_CODE) FrIf_MainFunction_0(void); /* PRQA S 3451 */ /* MD_Rte_3451 */

# define FRIF_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

 /* PRQA S 3458 L1 */ /* MD_MSR_19.4 */
# define SchM_Enter_FrIf_FRIF_EXCLUSIVE_AREA_0() \
 { \
   SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */ \
 }
 /* PRQA L:L1 */

 /* PRQA S 3458 L1 */ /* MD_MSR_19.4 */
# define SchM_Exit_FrIf_FRIF_EXCLUSIVE_AREA_0() \
 { \
   ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */ \
 }
 /* PRQA L:L1 */

 /* PRQA S 3458 L1 */ /* MD_MSR_19.4 */
# define SchM_Enter_FrIf_FRIF_EXCLUSIVE_AREA_1() \
 { \
   SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */ \
 }
 /* PRQA L:L1 */

 /* PRQA S 3458 L1 */ /* MD_MSR_19.4 */
# define SchM_Exit_FrIf_FRIF_EXCLUSIVE_AREA_1() \
 { \
   ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */ \
 }
 /* PRQA L:L1 */

 /* PRQA S 3458 L1 */ /* MD_MSR_19.4 */
# define SchM_Enter_FrIf_FRIF_EXCLUSIVE_AREA_2() \
 { \
   SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */ \
 }
 /* PRQA L:L1 */

 /* PRQA S 3458 L1 */ /* MD_MSR_19.4 */
# define SchM_Exit_FrIf_FRIF_EXCLUSIVE_AREA_2() \
 { \
   ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */ \
 }
 /* PRQA L:L1 */


# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

#endif /* SCHM_FRIF_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
