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
 *          File:  Rte_Dcm.h
 *        Config:  CanCanFr.dpa
 *   ECU-Project:  ECU_3
 *
 *     Generator:  MICROSAR RTE Generator Version 4.9.0
 *                 RTE Core Version 1.9.0
 *       License:  Unlimited license CBD0000000 for N/A
 *
 *   Description:  Application header file for SW-C <Dcm>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_DCM_H
# define _RTE_DCM_H

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

# include "Rte_Dcm_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_CAN00_f26020e5_DcmCommunicationControl_ComMConf_ComMChannel_CAN00_f26020e5(uint8 nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_CAN01_f26020e5_DcmCommunicationControl_ComMConf_ComMChannel_CAN01_f26020e5(uint8 nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_FlexrayCluster_1_f26020e5_DcmCommunicationControl_ComMConf_ComMChannel_FlexrayCluster_1_f26020e5(uint8 nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmControlDtcSetting_DcmControlDtcSetting(uint8 nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(uint8 nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmEcuReset_DcmEcuReset(uint8 nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_SwitchAck_Dcm_DcmEcuReset_DcmEcuReset(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_DATA0_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_DATA0_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_DATA0_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_DATA1_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_DATA1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_DATA1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_DID_0xF414_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_DID_0xF414_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_DID_0xF414_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_Example_IO_Control_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_Example_IO_Control_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_Example_IO_Control_ReturnControlToECU(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_Example_IO_Control_ShortTermAdjustment(P2CONST(uint8, AUTOMATIC, RTE_DCM_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_Example_IO_Control_ShortTermAdjustment(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DCM_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_Example_Only_VSG1_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_Example_Only_VSG1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_Example_Only_VSG1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_Example_Periodic_Data_Identifier_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_Example_Periodic_Data_Identifier_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_Example_Periodic_Data_Identifier_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_Example_ReadWriteData_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_Example_ReadWriteData_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_Example_ReadWriteData_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_Example_ReadWriteData_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DCM_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_Example_ReadWriteData_WriteData(P2CONST(Dcm_Data2ByteType, AUTOMATIC, RTE_DCM_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_Example_WriteOnlyDID_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DCM_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_Example_WriteOnlyDID_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DCM_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_TsiDcm_Write_Read_MF_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_TsiDcm_Write_Read_MF_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_TsiDcm_Write_Read_MF_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data8ByteType, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_TsiDcm_Write_Read_MF_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DCM_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_TsiDcm_Write_Read_MF_WriteData(P2CONST(Dcm_Data8ByteType, AUTOMATIC, RTE_DCM_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_TsiDcm_Write_Read_SF_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_TsiDcm_Write_Read_SF_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_TsiDcm_Write_Read_SF_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_TsiDcm_Write_Read_SF_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DCM_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Data_TsiDcm_Write_Read_SF_WriteData(P2CONST(Dcm_Data4ByteType, AUTOMATIC, RTE_DCM_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_Routine_Example_Routine_Control_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_Routine_Example_Routine_Control_Start(uint8 ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_Routine_Example_Routine_Control_Stop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_SecurityAccess_UnlockedL1_CompareKey(P2CONST(uint8, AUTOMATIC, RTE_DCM_APPL_DATA) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_SecurityAccess_UnlockedL1_CompareKey(P2CONST(Dcm_Data4ByteType, AUTOMATIC, RTE_DCM_APPL_DATA) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_SecurityAccess_UnlockedL1_GetSeed(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_SecurityAccess_UnlockedL1_GetSeed(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_DCM_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_DcmCommunicationControl_ComMConf_ComMChannel_CAN00_f26020e5_DcmCommunicationControl_ComMConf_ComMChannel_CAN00_f26020e5 Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_CAN00_f26020e5_DcmCommunicationControl_ComMConf_ComMChannel_CAN00_f26020e5
#  define Rte_Switch_DcmCommunicationControl_ComMConf_ComMChannel_CAN01_f26020e5_DcmCommunicationControl_ComMConf_ComMChannel_CAN01_f26020e5 Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_CAN01_f26020e5_DcmCommunicationControl_ComMConf_ComMChannel_CAN01_f26020e5
#  define Rte_Switch_DcmCommunicationControl_ComMConf_ComMChannel_FlexrayCluster_1_f26020e5_DcmCommunicationControl_ComMConf_ComMChannel_FlexrayCluster_1_f26020e5 Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_FlexrayCluster_1_f26020e5_DcmCommunicationControl_ComMConf_ComMChannel_FlexrayCluster_1_f26020e5
#  define Rte_Switch_DcmControlDtcSetting_DcmControlDtcSetting Rte_Switch_Dcm_DcmControlDtcSetting_DcmControlDtcSetting
#  define Rte_Switch_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl Rte_Switch_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl
#  define Rte_Switch_DcmEcuReset_DcmEcuReset Rte_Switch_Dcm_DcmEcuReset_DcmEcuReset


/**********************************************************************************************************************
 * Rte_Feedback_<p>_<m> (mode switch acknowledge)
 *********************************************************************************************************************/
#  define Rte_SwitchAck_DcmEcuReset_DcmEcuReset Rte_SwitchAck_Dcm_DcmEcuReset_DcmEcuReset


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_DataServices_Data_DATA0_ConditionCheckRead Rte_Call_Dcm_DataServices_Data_DATA0_ConditionCheckRead
#  define Rte_Call_DataServices_Data_DATA0_ReadData Rte_Call_Dcm_DataServices_Data_DATA0_ReadData
#  define Rte_Call_DataServices_Data_DATA1_ConditionCheckRead Rte_Call_Dcm_DataServices_Data_DATA1_ConditionCheckRead
#  define Rte_Call_DataServices_Data_DATA1_ReadData Rte_Call_Dcm_DataServices_Data_DATA1_ReadData
#  define Rte_Call_DataServices_Data_DID_0xF414_ConditionCheckRead Rte_Call_Dcm_DataServices_Data_DID_0xF414_ConditionCheckRead
#  define Rte_Call_DataServices_Data_DID_0xF414_ReadData Rte_Call_Dcm_DataServices_Data_DID_0xF414_ReadData
#  define Rte_Call_DataServices_Data_Example_IO_Control_ReadData Rte_Call_Dcm_DataServices_Data_Example_IO_Control_ReadData
#  define Rte_Call_DataServices_Data_Example_IO_Control_ReturnControlToECU Rte_Call_Dcm_DataServices_Data_Example_IO_Control_ReturnControlToECU
#  define Rte_Call_DataServices_Data_Example_IO_Control_ShortTermAdjustment Rte_Call_Dcm_DataServices_Data_Example_IO_Control_ShortTermAdjustment
#  define Rte_Call_DataServices_Data_Example_Only_VSG1_ConditionCheckRead Rte_Call_Dcm_DataServices_Data_Example_Only_VSG1_ConditionCheckRead
#  define Rte_Call_DataServices_Data_Example_Only_VSG1_ReadData Rte_Call_Dcm_DataServices_Data_Example_Only_VSG1_ReadData
#  define Rte_Call_DataServices_Data_Example_Periodic_Data_Identifier_ConditionCheckRead Rte_Call_Dcm_DataServices_Data_Example_Periodic_Data_Identifier_ConditionCheckRead
#  define Rte_Call_DataServices_Data_Example_Periodic_Data_Identifier_ReadData Rte_Call_Dcm_DataServices_Data_Example_Periodic_Data_Identifier_ReadData
#  define Rte_Call_DataServices_Data_Example_ReadWriteData_ConditionCheckRead Rte_Call_Dcm_DataServices_Data_Example_ReadWriteData_ConditionCheckRead
#  define Rte_Call_DataServices_Data_Example_ReadWriteData_ReadData Rte_Call_Dcm_DataServices_Data_Example_ReadWriteData_ReadData
#  define Rte_Call_DataServices_Data_Example_ReadWriteData_WriteData Rte_Call_Dcm_DataServices_Data_Example_ReadWriteData_WriteData
#  define Rte_Call_DataServices_Data_Example_WriteOnlyDID_WriteData Rte_Call_Dcm_DataServices_Data_Example_WriteOnlyDID_WriteData
#  define Rte_Call_DataServices_Data_TsiDcm_Write_Read_MF_ConditionCheckRead Rte_Call_Dcm_DataServices_Data_TsiDcm_Write_Read_MF_ConditionCheckRead
#  define Rte_Call_DataServices_Data_TsiDcm_Write_Read_MF_ReadData Rte_Call_Dcm_DataServices_Data_TsiDcm_Write_Read_MF_ReadData
#  define Rte_Call_DataServices_Data_TsiDcm_Write_Read_MF_WriteData Rte_Call_Dcm_DataServices_Data_TsiDcm_Write_Read_MF_WriteData
#  define Rte_Call_DataServices_Data_TsiDcm_Write_Read_SF_ConditionCheckRead Rte_Call_Dcm_DataServices_Data_TsiDcm_Write_Read_SF_ConditionCheckRead
#  define Rte_Call_DataServices_Data_TsiDcm_Write_Read_SF_ReadData Rte_Call_Dcm_DataServices_Data_TsiDcm_Write_Read_SF_ReadData
#  define Rte_Call_DataServices_Data_TsiDcm_Write_Read_SF_WriteData Rte_Call_Dcm_DataServices_Data_TsiDcm_Write_Read_SF_WriteData
#  define RTE_START_SEC_DEM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_DcmClearDTC(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_DEM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Dcm_DcmClearDTC Dem_DcmClearDTC
#  define RTE_START_SEC_DEM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_DcmEnableDTCSetting(Dem_DTCGroupType DTCGroup, Dem_DTCKindType DTCKind); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_DEM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Dcm_DcmEnableDTCSetting Dem_DcmEnableDTCSetting
#  define RTE_START_SEC_DEM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_DcmGetExtendedDataRecordByDTC(uint32 DTC, Dem_DTCOriginType DTCOrigin, uint8 ExtendedDataNumber, P2VAR(uint8, AUTOMATIC, RTE_DEM_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEM_APPL_VAR) BufSize); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_DEM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Dcm_DcmGetExtendedDataRecordByDTC Dem_DcmGetExtendedDataRecordByDTC
#  define RTE_START_SEC_DEM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_DcmGetFreezeFrameDataByDTC(uint32 DTC, Dem_DTCOriginType DTCOrigin, uint8 RecordNumber, P2VAR(uint8, AUTOMATIC, RTE_DEM_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEM_APPL_VAR) BufSize); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_DEM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Dcm_DcmGetFreezeFrameDataByDTC Dem_DcmGetFreezeFrameDataByDTC
#  define RTE_START_SEC_DEM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_DcmGetNextFilteredDTCAndFDC(P2VAR(uint32, AUTOMATIC, RTE_DEM_APPL_VAR) DTC, P2VAR(sint8, AUTOMATIC, RTE_DEM_APPL_VAR) DTCFaultDetectionCounter); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_DEM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Dcm_DcmGetNextFilteredDTCAndFDC Dem_DcmGetNextFilteredDTCAndFDC
#  define Rte_Call_RoutineServices_Routine_Example_Routine_Control_RequestResults Rte_Call_Dcm_RoutineServices_Routine_Example_Routine_Control_RequestResults
#  define Rte_Call_RoutineServices_Routine_Example_Routine_Control_Start Rte_Call_Dcm_RoutineServices_Routine_Example_Routine_Control_Start
#  define Rte_Call_RoutineServices_Routine_Example_Routine_Control_Stop Rte_Call_Dcm_RoutineServices_Routine_Example_Routine_Control_Stop
#  define Rte_Call_SecurityAccess_UnlockedL1_CompareKey Rte_Call_Dcm_SecurityAccess_UnlockedL1_CompareKey
#  define Rte_Call_SecurityAccess_UnlockedL1_GetSeed Rte_Call_Dcm_SecurityAccess_UnlockedL1_GetSeed


# endif /* !defined(RTE_CORE) */


# define Dcm_START_SEC_CODE
# include "Dcm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Dcm_MainFunction Dcm_MainFunction
#  define RTE_RUNNABLE_GetActiveProtocol Dcm_GetActiveProtocol
#  define RTE_RUNNABLE_GetSecurityLevel Dcm_GetSecurityLevel
#  define RTE_RUNNABLE_GetSesCtrlType Dcm_GetSesCtrlType
#  define RTE_RUNNABLE_ResetToDefaultSession Dcm_ResetToDefaultSession
#  define RTE_RUNNABLE_SetActiveDiagnostic Dcm_SetActiveDiagnostic
# endif

FUNC(void, Dcm_CODE) Dcm_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetActiveProtocol(P2VAR(Dcm_ProtocolType, AUTOMATIC, RTE_DCM_APPL_VAR) ActiveProtocol); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetSecurityLevel(P2VAR(Dcm_SecLevelType, AUTOMATIC, RTE_DCM_APPL_VAR) SecLevel); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetSesCtrlType(P2VAR(Dcm_SesCtrlType, AUTOMATIC, RTE_DCM_APPL_VAR) SesCtrlType); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_ResetToDefaultSession(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_SetActiveDiagnostic(boolean active); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define Dcm_STOP_SEC_CODE
# include "Dcm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DCMServices_E_NOT_OK (1U)

#  define RTE_E_DCMServices_E_OK (0U)

#  define RTE_E_DataServices_Data_DATA0_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_DATA0_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_DATA1_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_DATA1_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_DID_0xF414_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_DID_0xF414_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_Example_IO_Control_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_Example_IO_Control_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_Example_Only_VSG1_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_Example_Only_VSG1_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_Example_Periodic_Data_Identifier_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_Example_Periodic_Data_Identifier_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_Example_ReadWriteData_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_Example_ReadWriteData_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_Example_WriteOnlyDID_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_Example_WriteOnlyDID_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_TsiDcm_Write_Read_MF_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_TsiDcm_Write_Read_MF_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_TsiDcm_Write_Read_SF_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_TsiDcm_Write_Read_SF_E_NOT_OK (1U)

#  define RTE_E_DcmIf_DEM_CLEAR_BUSY (5U)

#  define RTE_E_DcmIf_DEM_CLEAR_FAILED (3U)

#  define RTE_E_DcmIf_DEM_CLEAR_MEMORY_ERROR (6U)

#  define RTE_E_DcmIf_DEM_CLEAR_PENDING (4U)

#  define RTE_E_DcmIf_DEM_CLEAR_WRONG_DTC (1U)

#  define RTE_E_DcmIf_DEM_CLEAR_WRONG_DTCORIGIN (2U)

#  define RTE_E_DcmIf_DEM_CONTROL_DTC_SETTING_N_OK (1U)

#  define RTE_E_DcmIf_DEM_CONTROL_DTC_WRONG_DTCGROUP (2U)

#  define RTE_E_DcmIf_DEM_FILTERED_NO_MATCHING_DTC (1U)

#  define RTE_E_DcmIf_DEM_GET_FFDATABYDTC_PENDING (5U)

#  define RTE_E_DcmIf_DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE (4U)

#  define RTE_E_DcmIf_DEM_GET_FFDATABYDTC_WRONG_DTC (1U)

#  define RTE_E_DcmIf_DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN (2U)

#  define RTE_E_DcmIf_DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER (3U)

#  define RTE_E_DcmIf_DEM_RECORD_PENDING (5U)

#  define RTE_E_DcmIf_DEM_RECORD_WRONG_BUFFERSIZE (4U)

#  define RTE_E_DcmIf_DEM_RECORD_WRONG_DTC (1U)

#  define RTE_E_DcmIf_DEM_RECORD_WRONG_DTCORIGIN (2U)

#  define RTE_E_DcmIf_DEM_RECORD_WRONG_NUMBER (3U)

#  define RTE_E_RoutineServices_Routine_Example_Routine_Control_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Example_Routine_Control_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Example_Routine_Control_E_NOT_OK (1U)

#  define RTE_E_SecurityAccess_UnlockedL1_DCM_E_COMPARE_KEY_FAILED (11U)

#  define RTE_E_SecurityAccess_UnlockedL1_DCM_E_PENDING (10U)

#  define RTE_E_SecurityAccess_UnlockedL1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_DCM_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
