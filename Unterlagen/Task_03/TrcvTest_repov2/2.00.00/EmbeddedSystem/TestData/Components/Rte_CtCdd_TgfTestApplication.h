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
 *          File:  Rte_CtCdd_TgfTestApplication.h
 *        Config:  CanCanFr.dpa
 *   ECU-Project:  ECU_3
 *
 *     Generator:  MICROSAR RTE Generator Version 4.9.0
 *                 RTE Core Version 1.9.0
 *       License:  Unlimited license CBD0000000 for N/A
 *
 *   Description:  Application header file for SW-C <CtCdd_TgfTestApplication>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CTCDD_TGFTESTAPPLICATION_H
# define _RTE_CTCDD_TGFTESTAPPLICATION_H

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

# include "Rte_CtCdd_TgfTestApplication_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_PpCanRPGSig_1_DeCanRPGSig_1 (0U)
#  define Rte_InitValue_PpCanRPGSig_2_DeCanRPGSig_2 (0U)
#  define Rte_InitValue_PpCanRPGSig_3_DeCanRPGSig_3 (0U)
#  define Rte_InitValue_PpCanRPGSig_4_DeCanRPGSig_4 (0U)
#  define Rte_InitValue_PpCanRPGSig_5_DeCanRPGSig_5 (0U)
#  define Rte_InitValue_PpComCanSig_16Bit_13_DeComCanSig_16Bit_13 (0U)
#  define Rte_InitValue_PpComCanSig_16Bit_18_DeComCanSig_16Bit_18 (0U)
#  define Rte_InitValue_PpComCanSig_16bit_1_DeComCanSig_16bit_1 (0U)
#  define Rte_InitValue_PpComCanSig_16bit_2_DeComCanSig_16bit_2 (0U)
#  define Rte_InitValue_PpComFrSig_32Bit_2_DeComFrSig_32Bit_2 (0U)
#  define Rte_InitValue_PpGwCanCan_Can1Sig_32Bit1_DeGwCanCan_Can1Sig_32Bit1 (0U)
#  define Rte_InitValue_PpGwCanCan_Can1Sig_8Bit1_DeGwCanCan_Can1Sig_8Bit1 (0U)
#  define Rte_InitValue_PpGwCanCan_Can2Sig_16Bit1_DeGwCanCan_Can2Sig_16Bit1 (0U)
#  define Rte_InitValue_PpGwCanCan_Can2Sig_32Bit1_DeGwCanCan_Can2Sig_32Bit1 (0U)
#  define Rte_InitValue_PpGwCanCan_Can2Sig_8Bit2_DeGwCanCan_Can2Sig_8Bit2 (0U)
#  define Rte_InitValue_PpGwCanFr_Can2Sig_8Bit_3_DeGwCanFr_Can2Sig_8Bit_3 (0U)
#  define Rte_InitValue_PpGwCanFr_CanSig_16Bit_1_DeGwCanFr_CanSig_16Bit_1 (0U)
#  define Rte_InitValue_PpGwCanFr_CanSig_32Bit_1_DeGwCanFr_CanSig_32Bit_1 (0U)
#  define Rte_InitValue_PpGwCanFr_CanSig_8Bit_1_DeGwCanFr_CanSig_8Bit_1 (0U)
#  define Rte_InitValue_PpGwCanFr_CanSig_8Bit_2_DeGwCanFr_CanSig_8Bit_2 (0U)
#  define Rte_InitValue_PpGwCanSig_8Bit_1_DeGwCanSig_8Bit_1 (0U)
#  define Rte_InitValue_PpGwCanSig_8Bit_2_DeGwCanSig_8Bit_2 (0U)
#  define Rte_InitValue_PpGwFrSig_16Bit_2_DeGwFrSig_16Bit_2 (0U)
#  define Rte_InitValue_PpGwFrSig_32Bit_6_DeGwFrSig_32Bit_6 (0U)
#  define Rte_InitValue_PpGwFrSig_8Bit_3_DeGwFrSig_8Bit_3 (0U)
#  define Rte_InitValue_PpSig00Tx_0x3EE_IL_DeSig00Tx_0x3EE_IL (0U)
#  define Rte_InitValue_PpSig00Tx_0x756_DeSig00Tx_0x756 (0U)
#  define Rte_InitValue_PpSig_16Bit_17_DeSig_16Bit_17 (0U)
#  define Rte_InitValue_PpSig_16Bit_18_DeSig_16Bit_18 (0U)
#  define Rte_InitValue_PpSig_16Bit_19_DeSig_16Bit_19 (0U)
#  define Rte_InitValue_PpSig_16Bit_2_DeSig_16Bit_2 (0U)
#  define Rte_InitValue_PpSig_16Bit_20_DeSig_16Bit_20 (0U)
#  define Rte_InitValue_PpSig_16Bit_23_DeSig_16Bit_23 (0U)
#  define Rte_InitValue_PpSig_16Bit_4_DeSig_16Bit_4 (0U)
#  define Rte_InitValue_PpSig_16bit_10_DeSig_16bit_10 (0U)
#  define Rte_InitValue_PpSig_16bit_11_DeSig_16bit_11 (0U)
#  define Rte_InitValue_PpSig_16bit_16_DeSig_16bit_16 (0U)
#  define Rte_InitValue_PpSig_16bit_9_DeSig_16bit_9 (0U)
#  define Rte_InitValue_PpSig_32Bit_2_DeSig_32Bit_2 (0U)
#  define Rte_InitValue_PpSig_32Bit_21_DeSig_32Bit_21 (0U)
#  define Rte_InitValue_PpSig_32Bit_22_DeSig_32Bit_22 (0U)
#  define Rte_InitValue_PpSig_32Bit_3_DeSig_32Bit_3 (0U)
#  define Rte_InitValue_PpSig_32Bit_4_DeSig_32Bit_4 (0U)
#  define Rte_InitValue_PpSig_32bit_26_DeSig_32bit_26 (0U)
#  define Rte_InitValue_PpSig_8Bit_11_DeSig_8Bit_11 (0U)
#  define Rte_InitValue_PpSig_8Bit_13_DeSig_8Bit_13 (0U)
#  define Rte_InitValue_PpSig_8Bit_15_DeSig_8Bit_15 (0U)
#  define Rte_InitValue_PpSig_8Bit_16_DeSig_8Bit_16 (0U)
#  define Rte_InitValue_PpSig_8Bit_17_DeSig_8Bit_17 (0U)
#  define Rte_InitValue_PpSig_8Bit_18_DeSig_8Bit_18 (0U)
#  define Rte_InitValue_PpSig_8Bit_2_DeSig_8Bit_2 (0U)
#  define Rte_InitValue_PpSig_8Bit_20_DeSig_8Bit_20 (0U)
#  define Rte_InitValue_PpSig_8Bit_21_DeSig_8Bit_21 (0U)
#  define Rte_InitValue_PpSig_8Bit_22_DeSig_8Bit_22 (0U)
#  define Rte_InitValue_PpSig_8bit_10_DeSig_8bit_10 (0U)
#  define Rte_InitValue_PpSig_Bool_2_DeSig_Bool_2 (0U)
#  define Rte_InitValue_PpSig_Bool_3_DeSig_Bool_3 (0U)
#  define Rte_InitValue_PpSig_Bool_4_DeSig_Bool_4 (0U)
#  define Rte_InitValue_PpSig_Cdd_1_DeSig_Cdd_1 (0U)
#  define Rte_InitValue_PpSig_Cdd_2_DeSig_Cdd_2 (0U)
#  define Rte_InitValue_PpSig_Cdd_8Bit_1_DeSig_Cdd_8Bit_1 (0U)
#  define Rte_InitValue_PpSig_Cdd_8Bit_2_DeSig_Cdd_8Bit_2 (0U)
#  define Rte_InitValue_Pps00R0100D_A_b01r08_Des00R0100D_A_b01r08 (0U)
#  define Rte_InitValue_Pps00R0118D_A_b01r08_Des00R0118D_A_b01r08 (0U)
#  define Rte_InitValue_Pps00R142D_A_b00r08_Des00R142D_A_b00r08 (0U)
#  define Rte_InitValue_Pps00R142D_A_b01r08_Des00R142D_A_b01r08 (0U)
#  define Rte_InitValue_Pps00T0118D_A_b06r08_Des00T0118D_A_b06r08 (0U)
#  define Rte_InitValue_Pps00T044S_A_b01r04_Des00T044S_A_b01r04 (0U)
#  define Rte_InitValue_Pps00T044S_A_b02r04_Des00T044S_A_b02r04 (0U)
#  define Rte_InitValue_Pps00T044S_A_b03r04_Des00T044S_A_b03r04 (0U)
#  define Rte_InitValue_Pps01R0100D_A_b01r08_Des01R0100D_A_b01r08 (0U)
#  define Rte_InitValue_Pps01R0118D_A_b01r08_Des01R0118D_A_b01r08 (0U)
#  define Rte_InitValue_Pps01R142D_A_b00r08_Des01R142D_A_b00r08 (0U)
#  define Rte_InitValue_Pps01R142D_A_b01r08_Des01R142D_A_b01r08 (0U)
#  define Rte_InitValue_Pps01T0118D_A_b06r08_Des01T0118D_A_b06r08 (0U)
#  define Rte_InitValue_Pps01T028S_A_b00r08_Des01T028S_A_b00r08 (0U)
#  define Rte_InitValue_Pps01T044S_A_b01r04_Des01T044S_A_b01r04 (0U)
#  define Rte_InitValue_Pps01T044S_A_b02r04_Des01T044S_A_b02r04 (0U)
#  define Rte_InitValue_Pps01T044S_A_b03r04_Des01T044S_A_b03r04 (0U)
#  define Rte_InitValue_Pps02R0100D_A_b01r08_Des02R0100D_A_b01r08 (0U)
#  define Rte_InitValue_Pps02R0118D_A_b01r08_Des02R0118D_A_b01r08 (0U)
#  define Rte_InitValue_Pps02R142D_A_b00r08_Des02R142D_A_b00r08 (0U)
#  define Rte_InitValue_Pps02R142D_A_b01r08_Des02R142D_A_b01r08 (0U)
#  define Rte_InitValue_Pps02T0118D_A_b06r08_Des02T0118D_A_b06r08 (0U)
#  define Rte_InitValue_Pps02T028S_A_b00r08_Des02T028S_A_b00r08 (0U)
#  define Rte_InitValue_Pps02T044S_A_b01r04_Des02T044S_A_b01r04 (0U)
#  define Rte_InitValue_Pps02T044S_A_b02r04_Des02T044S_A_b02r04 (0U)
#  define Rte_InitValue_Pps02T044S_A_b03r04_Des02T044S_A_b03r04 (0U)
#  define Rte_InitValue_Pps03R0100D_A_b01r08_Des03R0100D_A_b01r08 (FALSE)
#  define Rte_InitValue_Pps03R0118D_A_b01r08_Des03R0118D_A_b01r08 (FALSE)
#  define Rte_InitValue_Pps03T0118D_A_b06r08_Des03T0118D_A_b06r08 (FALSE)
#  define Rte_InitValue_Pps03T044S_A_b01r04_Des03T044S_A_b01r04 (0U)
#  define Rte_InitValue_Pps03T044S_A_b02r04_Des03T044S_A_b02r04 (0U)
#  define Rte_InitValue_Pps03T044S_A_b03r04_Des03T044S_A_b03r04 (0U)
#  define Rte_InitValue_Pps04R0118D_A_b01r08_Des04R0118D_A_b01r08 (0U)
#  define Rte_InitValue_Pps04T0118D_A_b06r08_Des04T0118D_A_b06r08 (0U)
#  define Rte_InitValue_Pps04T044S_A_b01r04_Des04T044S_A_b01r04 (0U)
#  define Rte_InitValue_Pps04T044S_A_b02r04_Des04T044S_A_b02r04 (0U)
#  define Rte_InitValue_Pps04T044S_A_b03r04_Des04T044S_A_b03r04 (0U)
#  define Rte_InitValue_Pps05R0118D_A_b01r08_Des05R0118D_A_b01r08 (0U)
#  define Rte_InitValue_Pps05T0118D_A_b06r08_Des05T0118D_A_b06r08 (0U)
#  define Rte_InitValue_Pps05T044S_A_b01r04_Des05T044S_A_b01r04 (0U)
#  define Rte_InitValue_Pps05T044S_A_b02r04_Des05T044S_A_b02r04 (0U)
#  define Rte_InitValue_Pps05T044S_A_b03r04_Des05T044S_A_b03r04 (0U)
#  define Rte_InitValue_Pps06R0100D_A_b01r08_Des06R0100D_A_b01r08 (0U)
#  define Rte_InitValue_Pps06R0118D_A_b01r08_Des06R0118D_A_b01r08 (0U)
#  define Rte_InitValue_Pps06T0118D_A_b06r08_Des06T0118D_A_b06r08 (0U)
#  define Rte_InitValue_Pps07R0100D_A_b01r08_Des07R0100D_A_b01r08 (0U)
#  define Rte_InitValue_Pps07R0118D_A_b01r08_Des07R0118D_A_b01r08 (0U)
#  define Rte_InitValue_Pps07T0118D_A_b06r08_Des07T0118D_A_b06r08 (0U)
#  define Rte_InitValue_Pps0R0010S_A_b00r04_IPDUM_DynSig_0_Des0R0010S_A_b00r04_IPDUM_DynSig_0 (0U)
#  define Rte_InitValue_Pps0R0010S_A_b01r04_IPDUM_DynSig_0_Des0R0010S_A_b01r04_IPDUM_DynSig_0 (0U)
#  define Rte_InitValue_Pps0R0010S_A_b01r04_IPDUM_DynSig_1_Des0R0010S_A_b01r04_IPDUM_DynSig_1 (0U)
#  define Rte_InitValue_Pps0R0010S_A_b01r04_IPDUM_DynSig_2_Des0R0010S_A_b01r04_IPDUM_DynSig_2 (0U)
#  define Rte_InitValue_Pps0R0010S_A_b01r04_IPDUM_DynSig_3_Des0R0010S_A_b01r04_IPDUM_DynSig_3 (0U)
#  define Rte_InitValue_Pps0R0010S_A_b02r04_IPDUM_DynSig_0_Des0R0010S_A_b02r04_IPDUM_DynSig_0 (0U)
#  define Rte_InitValue_Pps0R0010S_A_b03r04_IPDUM_DynSig_0_Des0R0010S_A_b03r04_IPDUM_DynSig_0 (0U)
#  define Rte_InitValue_Pps0R0010S_A_b03r04_IPDUM_DynSig_1_Des0R0010S_A_b03r04_IPDUM_DynSig_1 (0U)
#  define Rte_InitValue_Pps0R0010S_A_b03r04_IPDUM_DynSig_2_Des0R0010S_A_b03r04_IPDUM_DynSig_2 (0U)
#  define Rte_InitValue_Pps0R0010S_A_b03r04_IPDUM_DynSig_3_Des0R0010S_A_b03r04_IPDUM_DynSig_3 (0U)
#  define Rte_InitValue_Pps0T0012S_A_b00r04_IPDUM_DynSig_0_Des0T0012S_A_b00r04_IPDUM_DynSig_0 (0U)
#  define Rte_InitValue_Pps0T0012S_A_b01r04_IPDUM_DynSig_0_Des0T0012S_A_b01r04_IPDUM_DynSig_0 (0U)
#  define Rte_InitValue_Pps0T0012S_A_b01r04_IPDUM_DynSig_1_Des0T0012S_A_b01r04_IPDUM_DynSig_1 (0U)
#  define Rte_InitValue_Pps0T0012S_A_b01r04_IPDUM_DynSig_2_Des0T0012S_A_b01r04_IPDUM_DynSig_2 (0U)
#  define Rte_InitValue_Pps0T0012S_A_b01r04_IPDUM_DynSig_3_Des0T0012S_A_b01r04_IPDUM_DynSig_3 (0U)
#  define Rte_InitValue_Pps0T0013S_A_b00r04_IPDUM_DynSig_0_Des0T0013S_A_b00r04_IPDUM_DynSig_0 (0U)
#  define Rte_InitValue_Pps0T0013S_A_b01r04_IPDUM_DynSig_0_Des0T0013S_A_b01r04_IPDUM_DynSig_0 (0U)
#  define Rte_InitValue_Pps0T0013S_A_b01r04_IPDUM_DynSig_1_Des0T0013S_A_b01r04_IPDUM_DynSig_1 (0U)
#  define Rte_InitValue_Pps0T0013S_A_b01r04_IPDUM_DynSig_2_Des0T0013S_A_b01r04_IPDUM_DynSig_2 (0U)
#  define Rte_InitValue_Pps0T0013S_A_b01r04_IPDUM_DynSig_3_Des0T0013S_A_b01r04_IPDUM_DynSig_3 (0U)
#  define Rte_InitValue_Pps0_p00R041S_A_b00r04_Des0_p00R041S_A_b00r04 (0U)
#  define Rte_InitValue_Pps0_p00R041S_A_b01r04_Des0_p00R041S_A_b01r04 (0U)
#  define Rte_InitValue_Pps0_p01R041S_A_b00r04_Des0_p01R041S_A_b00r04 (0U)
#  define Rte_InitValue_Pps10T030S_A_b00r08_Des10T030S_A_b00r08 (0U)
#  define Rte_InitValue_Pps10_p00R041S_A_b01r04_Des10_p00R041S_A_b01r04 (0U)
#  define Rte_InitValue_Pps11T030S_A_b00r08_Des11T030S_A_b00r08 (0U)
#  define Rte_InitValue_Pps11_p00R041S_A_b01r04_Des11_p00R041S_A_b01r04 (FALSE)
#  define Rte_InitValue_Pps12T030S_A_b00r08_Des12T030S_A_b00r08 (0U)
#  define Rte_InitValue_Pps12_p00R041S_A_b01r04_Des12_p00R041S_A_b01r04 (0U)
#  define Rte_InitValue_Pps13_p00R041S_A_b01r04_Des13_p00R041S_A_b01r04 (0U)
#  define Rte_InitValue_Pps1R0010S_A_b00r04_IPDUM_DynSig_0_Des1R0010S_A_b00r04_IPDUM_DynSig_0 (0U)
#  define Rte_InitValue_Pps1R0010S_A_b01r04_IPDUM_DynSig_0_Des1R0010S_A_b01r04_IPDUM_DynSig_0 (0U)
#  define Rte_InitValue_Pps1R0010S_A_b01r04_IPDUM_DynSig_1_Des1R0010S_A_b01r04_IPDUM_DynSig_1 (0U)
#  define Rte_InitValue_Pps1R0010S_A_b01r04_IPDUM_DynSig_2_Des1R0010S_A_b01r04_IPDUM_DynSig_2 (0U)
#  define Rte_InitValue_Pps1R0010S_A_b01r04_IPDUM_DynSig_3_Des1R0010S_A_b01r04_IPDUM_DynSig_3 (0U)
#  define Rte_InitValue_Pps1R0010S_A_b02r04_IPDUM_DynSig_0_Des1R0010S_A_b02r04_IPDUM_DynSig_0 (0U)
#  define Rte_InitValue_Pps1R0010S_A_b03r04_IPDUM_DynSig_0_Des1R0010S_A_b03r04_IPDUM_DynSig_0 (0U)
#  define Rte_InitValue_Pps1R0010S_A_b03r04_IPDUM_DynSig_1_Des1R0010S_A_b03r04_IPDUM_DynSig_1 (0U)
#  define Rte_InitValue_Pps1R0010S_A_b03r04_IPDUM_DynSig_2_Des1R0010S_A_b03r04_IPDUM_DynSig_2 (0U)
#  define Rte_InitValue_Pps1R0010S_A_b03r04_IPDUM_DynSig_3_Des1R0010S_A_b03r04_IPDUM_DynSig_3 (0U)
#  define Rte_InitValue_Pps1T0012S_A_b00r04_IPDUM_DynSig_0_Des1T0012S_A_b00r04_IPDUM_DynSig_0 (0U)
#  define Rte_InitValue_Pps1T0012S_A_b01r04_IPDUM_DynSig_0_Des1T0012S_A_b01r04_IPDUM_DynSig_0 (0U)
#  define Rte_InitValue_Pps1T0012S_A_b01r04_IPDUM_DynSig_1_Des1T0012S_A_b01r04_IPDUM_DynSig_1 (0U)
#  define Rte_InitValue_Pps1T0012S_A_b01r04_IPDUM_DynSig_2_Des1T0012S_A_b01r04_IPDUM_DynSig_2 (0U)
#  define Rte_InitValue_Pps1T0012S_A_b01r04_IPDUM_DynSig_3_Des1T0012S_A_b01r04_IPDUM_DynSig_3 (0U)
#  define Rte_InitValue_Pps1T0013S_A_b00r04_IPDUM_DynSig_0_Des1T0013S_A_b00r04_IPDUM_DynSig_0 (0U)
#  define Rte_InitValue_Pps1T0013S_A_b01r04_IPDUM_DynSig_0_Des1T0013S_A_b01r04_IPDUM_DynSig_0 (0U)
#  define Rte_InitValue_Pps1T0013S_A_b01r04_IPDUM_DynSig_1_Des1T0013S_A_b01r04_IPDUM_DynSig_1 (0U)
#  define Rte_InitValue_Pps1T0013S_A_b01r04_IPDUM_DynSig_2_Des1T0013S_A_b01r04_IPDUM_DynSig_2 (0U)
#  define Rte_InitValue_Pps1T0013S_A_b01r04_IPDUM_DynSig_3_Des1T0013S_A_b01r04_IPDUM_DynSig_3 (0U)
#  define Rte_InitValue_Pps1_p00R041S_A_b00r04_Des1_p00R041S_A_b00r04 (0U)
#  define Rte_InitValue_Pps1_p00R041S_A_b01r04_Des1_p00R041S_A_b01r04 (0U)
#  define Rte_InitValue_Pps1_p01R041S_A_b00r04_Des1_p01R041S_A_b00r04 (0U)
#  define Rte_InitValue_Pps2_p00R041S_A_b00r04_Des2_p00R041S_A_b00r04 (0U)
#  define Rte_InitValue_Pps2_p00R041S_A_b01r04_Des2_p00R041S_A_b01r04 (0U)
#  define Rte_InitValue_Pps2_p01R041S_A_b00r04_Des2_p01R041S_A_b00r04 (0U)
#  define Rte_InitValue_Pps3_p00R041S_A_b00r04_Des3_p00R041S_A_b00r04 (FALSE)
#  define Rte_InitValue_Pps3_p00R041S_A_b01r04_Des3_p00R041S_A_b01r04 (FALSE)
#  define Rte_InitValue_Pps3_p01R041S_A_b00r04_Des3_p01R041S_A_b00r04 (FALSE)
#  define Rte_InitValue_Pps4_p00R041S_A_b00r04_Des4_p00R041S_A_b00r04 (0U)
#  define Rte_InitValue_Pps4_p00R041S_A_b01r04_Des4_p00R041S_A_b01r04 (0U)
#  define Rte_InitValue_Pps4_p01R041S_A_b00r04_Des4_p01R041S_A_b00r04 (0U)
#  define Rte_InitValue_Pps5_p00R041S_A_b01r04_Des5_p00R041S_A_b01r04 (0U)
#  define Rte_InitValue_Pps6_p00R041S_A_b01r04_Des6_p00R041S_A_b01r04 (0U)
#  define Rte_InitValue_Pps7_p00R041S_A_b01r04_Des7_p00R041S_A_b01r04 (FALSE)
#  define Rte_InitValue_Pps8_p00R041S_A_b01r04_Des8_p00R041S_A_b01r04 (0U)
#  define Rte_InitValue_Pps9_p00R041S_A_b01r04_Des9_p00R041S_A_b01r04 (0U)
#  define Rte_InitValue_PpsR00108D_A_b00r04_DesR00108D_A_b00r04 (0U)
#  define Rte_InitValue_PpsR00108D_A_b02r04_DesR00108D_A_b02r04 (0U)
#  define Rte_InitValue_PpsR00109D_A_b00r04_DesR00109D_A_b00r04 (0U)
#  define Rte_InitValue_PpsR00109D_A_b02r04_DesR00109D_A_b02r04 (0U)
#  define Rte_InitValue_PpsR00110D_A_b00r04_DesR00110D_A_b00r04 (0U)
#  define Rte_InitValue_PpsR00110D_A_b02r04_DesR00110D_A_b02r04 (0U)
#  define Rte_InitValue_PpsR0112D_A_b03r04_DesR0112D_A_b03r04 (0U)
#  define Rte_InitValue_PpsR0114D_A_b01r04_DesR0114D_A_b01r04 (0U)
#  define Rte_InitValue_PpsT00120D_A_b00r01_DesT00120D_A_b00r01 (0U)
#  define Rte_InitValue_PpsT00124D_A_b00r01_DesT00124D_A_b00r01 (0U)
#  define Rte_InitValue_PpsT00126D_A_b00r01_DesT00126D_A_b00r01 (0U)
#  define Rte_InitValue_PpsT00130D_A_b00r01_DesT00130D_A_b00r01 (0U)
#  define Rte_InitValue_PpsT0137D_A_b00r02_DesT0137D_A_b00r02 (0U)
#  define Rte_InitValue_PpsT0138D_A_b00r03_DesT0138D_A_b00r03 (0U)
#  define Rte_InitValue_PpsT0232D_A_b00r02_DesT0232D_A_b00r02 (0U)
#  define Rte_InitValue_PpsT0233D_A_b00r04_DesT0233D_A_b00r04 (0U)
#  define Rte_InitValue_Pps_cnt_p00R041S_A_b00r04_Des_cnt_p00R041S_A_b00r04 (0U)
#  define Rte_InitValue_Pps_cnt_p00R041S_A_b01r04_Des_cnt_p00R041S_A_b01r04 (0U)
#  define Rte_InitValue_Pps_cnt_p01R041S_A_b00r04_Des_cnt_p01R041S_A_b00r04 (0U)
#  define Rte_InitValue_Pps_crc_p00R041S_A_b00r04_Des_crc_p00R041S_A_b00r04 (0U)
#  define Rte_InitValue_Pps_crc_p00R041S_A_b01r04_Des_crc_p00R041S_A_b01r04 (0U)
#  define Rte_InitValue_Pps_crc_p01R041S_A_b00r04_Des_crc_p01R041S_A_b00r04 (0U)
#  define Rte_InitValue_Ppsig00Rx_0x21C_IL_Desig00Rx_0x21C_IL (0U)
#  define Rte_InitValue_Ppsig00Rx_0x21D_IL_Desig00Rx_0x21D_IL (0U)
#  define Rte_InitValue_Ppsig00Rx_0x21E_IL_Desig00Rx_0x21E_IL (0U)
#  define Rte_InitValue_Ppsig00Rx_0x21F_IL_Desig00Rx_0x21F_IL (0U)
#  define Rte_InitValue_Ppsig00Rx_0x220_IL_Desig00Rx_0x220_IL (0U)
#  define Rte_InitValue_Ppsig00Rx_0x221_IL_Desig00Rx_0x221_IL (0U)
#  define Rte_InitValue_Ppsig00Rx_0x222_IL_Desig00Rx_0x222_IL (0)
#  define Rte_InitValue_Ppsig00Rx_0x223_IL_Desig00Rx_0x223_IL (0)
#  define Rte_InitValue_Ppsig00Rx_0x224_IL_Desig00Rx_0x224_IL (0)
#  define Rte_InitValue_Ppsig00Rx_0x225_IL_Desig00Rx_0x225_IL (0)
#  define Rte_InitValue_Ppsig00Rx_0x226_IL_Desig00Rx_0x226_IL (0)
#  define Rte_InitValue_Ppsig00Rx_0x227_IL_Desig00Rx_0x227_IL (0)
#  define Rte_InitValue_Ppsig00Rx_0x229_IL_Desig00Rx_0x229_IL (0U)
#  define Rte_InitValue_Ppsig00Rx_0x230_IL_Desig00Rx_0x230_IL (0U)
#  define Rte_InitValue_Ppsig00Rx_0x3EB_IL_Desig00Rx_0x3EB_IL (0U)
#  define Rte_InitValue_Ppsig00Rx_0x758_IL_Desig00Rx_0x758_IL (0U)
#  define Rte_InitValue_Ppsig00Rx_0x768_IL_Desig00Rx_0x768_IL (0U)
#  define Rte_InitValue_Ppsig00Rx_0x770_IL_Desig00Rx_0x770_IL (0U)
#  define Rte_InitValue_Ppsig00Tx_0x228_IL_Desig00Tx_0x228_IL (0U)
#  define Rte_InitValue_Ppsig00Tx_0x3C3_IL_Desig00Tx_0x3C3_IL (0U)
#  define Rte_InitValue_Ppsig00Tx_0x3C4_IL_Desig00Tx_0x3C4_IL (0U)
#  define Rte_InitValue_Ppsig00Tx_0x3DD_IL_Desig00Tx_0x3DD_IL (0U)
#  define Rte_InitValue_Ppsig00Tx_0x3DE_IL_Desig00Tx_0x3DE_IL (0U)
#  define Rte_InitValue_Ppsig00Tx_0x3EA_IL_Desig00Tx_0x3EA_IL (0U)
#  define Rte_InitValue_Ppsig00Tx_0x3EF_IL_Desig00Tx_0x3EF_IL (0U)
#  define Rte_InitValue_Ppsig00Tx_0x754_IL_Desig00Tx_0x754_IL (0U)
#  define Rte_InitValue_Ppsig00Tx_0x755_IL_Desig00Tx_0x755_IL (0U)
#  define Rte_InitValue_Ppsig00Tx_0x757_IL_Desig00Tx_0x757_IL (0U)
#  define Rte_InitValue_Ppsig00Tx_0x757_IL_CAN00_Desig00Tx_0x757_IL_CAN00 (0U)
#  define Rte_InitValue_Ppsig00Tx_0x765_IL_Desig00Tx_0x765_IL (0U)
#  define Rte_InitValue_Ppsig00Tx_0x767_IL_Desig00Tx_0x767_IL (0U)
#  define Rte_InitValue_Ppsig00Tx_0x769_IL_Desig00Tx_0x769_IL (0U)
#  define Rte_InitValue_Ppsig00Tx_0x771_IL_Desig00Tx_0x771_IL (0U)
#  define Rte_InitValue_Ppsig00Tx_0x772_IL_Desig00Tx_0x772_IL (0U)
#  define Rte_InitValue_Ppsig00Tx_0x774_IL_Desig00Tx_0x774_IL (0U)
#  define Rte_InitValue_Ppsig00_0x776_Desig00_0x776 (9)
#  define Rte_InitValue_Ppsig00_0x777_Desig00_0x777 (5U)
#  define Rte_InitValue_Ppsig00_0x780_Desig00_0x780 (0U)
#  define Rte_InitValue_Ppsig00_0x7A0_Desig00_0x7A0 (0U)
#  define Rte_InitValue_Ppsig00_0x7A1_Desig00_0x7A1 (0U)
#  define Rte_InitValue_Ppsig00_0x7A2_Desig00_0x7A2 (0U)
#  define Rte_InitValue_Ppsig00_0x7A3_Desig00_0x7A3 (0U)
#  define Rte_InitValue_Ppsig00_0x7A4_Desig00_0x7A4 (0U)
#  define Rte_InitValue_Ppsig00_Rx_0x22D_IL_Desig00_Rx_0x22D_IL (0U)
#  define Rte_InitValue_Ppsig00_Tx_0x22C_IL_Desig00_Tx_0x22C_IL (0U)
#  define Rte_InitValue_Ppsig01Rx_0x229_IL_Desig01Rx_0x229_IL (0U)
#  define Rte_InitValue_Ppsig01Rx_0x230_IL_Desig01Rx_0x230_IL (0U)
#  define Rte_InitValue_Ppsig01Rx_0x4C1_IL_Desig01Rx_0x4C1_IL (0U)
#  define Rte_InitValue_Ppsig01Rx_0x758_IL_Desig01Rx_0x758_IL (0U)
#  define Rte_InitValue_Ppsig01Rx_0x768_IL_Desig01Rx_0x768_IL (0U)
#  define Rte_InitValue_Ppsig01Rx_0x770_IL_Desig01Rx_0x770_IL (0U)
#  define Rte_InitValue_Ppsig01Rx_0x773_IL_Desig01Rx_0x773_IL (0U)
#  define Rte_InitValue_Ppsig01Rx_0x775_IL_Desig01Rx_0x775_IL (0U)
#  define Rte_InitValue_Ppsig01Tx_0x765_IL_Desig01Tx_0x765_IL (0U)
#  define Rte_InitValue_Ppsig01_0x776_Desig01_0x776 (7U)
#  define Rte_InitValue_Ppsig01_0x777_Desig01_0x777 (7U)
#  define Rte_InitValue_Ppsig01_0x780_Desig01_0x780 (0)
#  define Rte_InitValue_Ppsig01_0x7A1_Desig01_0x7A1 (0U)
#  define Rte_InitValue_Ppsig01_0x7A3_Desig01_0x7A3 (0U)
#  define Rte_InitValue_Ppsig02Rx_0x229_IL_Desig02Rx_0x229_IL (0U)
#  define Rte_InitValue_Ppsig02Rx_0x230_IL_Desig02Rx_0x230_IL (0U)
#  define Rte_InitValue_Ppsig02Rx_0x768_IL_Desig02Rx_0x768_IL (0U)
#  define Rte_InitValue_Ppsig02Rx_0x770_IL_Desig02Rx_0x770_IL (0U)
#  define Rte_InitValue_Ppsig02Rx_0x773_IL_Desig02Rx_0x773_IL (0U)
#  define Rte_InitValue_Ppsig02Rx_0x775_IL_Desig02Rx_0x775_IL (0U)
#  define Rte_InitValue_Ppsig02_0x780_Desig02_0x780 (0U)
#  define Rte_InitValue_Ppsig02_0x7A3_Desig02_0x7A3 (0U)
#  define Rte_InitValue_Ppsig03Rx_0x229_IL_Desig03Rx_0x229_IL (0U)
#  define Rte_InitValue_Ppsig03Rx_0x230_IL_Desig03Rx_0x230_IL (0U)
#  define Rte_InitValue_Ppsig03_0x780_Desig03_0x780 (99U)
#  define Rte_InitValue_Ppsig12Rx_0x766_IL_Desig12Rx_0x766_IL (0U)
#  define Rte_InitValue_Ppsig20Rx_0x766_IL_Desig20Rx_0x766_IL (0U)
#  define Rte_InitValue_Ppsig21Rx_0x766_IL_Desig21Rx_0x766_IL (0U)
#  define Rte_InitValue_Ppsig22Rx_0x766_IL_Desig22Rx_0x766_IL (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpComCanSig_16Bit_13_DeComCanSig_16Bit_13(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpComCanSig_16Bit_18_DeComCanSig_16Bit_18(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpComCanSig_16bit_2_DeComCanSig_16bit_2(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpComFrSig_32Bit_2_DeComFrSig_32Bit_2(P2VAR(It_Uint32_32bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpGwCanCan_Can1Sig_32Bit1_DeGwCanCan_Can1Sig_32Bit1(P2VAR(It_Uint32_32bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpGwCanCan_Can1Sig_8Bit1_DeGwCanCan_Can1Sig_8Bit1(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpGwCanCan_Can2Sig_16Bit1_DeGwCanCan_Can2Sig_16Bit1(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpGwCanCan_Can2Sig_32Bit1_DeGwCanCan_Can2Sig_32Bit1(P2VAR(It_Uint32_32bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpGwCanCan_Can2Sig_8Bit2_DeGwCanCan_Can2Sig_8Bit2(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpGwCanFr_Can2Sig_8Bit_3_DeGwCanFr_Can2Sig_8Bit_3(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpGwCanFr_CanSig_16Bit_1_DeGwCanFr_CanSig_16Bit_1(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpGwCanFr_CanSig_32Bit_1_DeGwCanFr_CanSig_32Bit_1(P2VAR(It_Uint32_32bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpGwCanFr_CanSig_8Bit_1_DeGwCanFr_CanSig_8Bit_1(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpGwCanFr_CanSig_8Bit_2_DeGwCanFr_CanSig_8Bit_2(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpGwFrSig_16Bit_2_DeGwFrSig_16Bit_2(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpGwFrSig_32Bit_6_DeGwFrSig_32Bit_6(P2VAR(It_Uint32_32bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpGwFrSig_8Bit_3_DeGwFrSig_8Bit_3(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpSig_16Bit_17_DeSig_16Bit_17(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpSig_16Bit_18_DeSig_16Bit_18(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpSig_16Bit_19_DeSig_16Bit_19(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpSig_16Bit_2_DeSig_16Bit_2(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpSig_16Bit_4_DeSig_16Bit_4(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpSig_32Bit_2_DeSig_32Bit_2(P2VAR(It_Uint32_32bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpSig_32Bit_21_DeSig_32Bit_21(P2VAR(It_Uint32_32bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpSig_32Bit_22_DeSig_32Bit_22(P2VAR(It_Uint32_32bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpSig_32Bit_4_DeSig_32Bit_4(P2VAR(It_Uint32_32bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpSig_32bit_26_DeSig_32bit_26(P2VAR(It_Uint32_32bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpSig_8Bit_13_DeSig_8Bit_13(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpSig_8Bit_15_DeSig_8Bit_15(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpSig_8Bit_16_DeSig_8Bit_16(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpSig_8Bit_17_DeSig_8Bit_17(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpSig_8Bit_18_DeSig_8Bit_18(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpSig_8Bit_2_DeSig_8Bit_2(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpSig_Bool_2_DeSig_Bool_2(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpSig_Bool_4_DeSig_Bool_4(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpSig_Cdd_2_DeSig_Cdd_2(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpSig_Cdd_8Bit_1_DeSig_Cdd_8Bit_1(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_CanComGrpSig_12_5cb96bc6_De_SG_CanComGrpSig_12_5cb96bc6(P2VAR(It_SG_CanComGrpSig_12_5cb96bc6, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_SigGrpRx_0x4C2_IL_27846a13_De_SG_SigGrpRx_0x4C2_IL_27846a13(P2VAR(It_SG_SigGrpRx_0x4C2_IL_27846a13, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R00108D_A_b01r04_SigGroup_3133230d_De_SG_sigGrp00R00108D_A_b01r04_SigGroup_3133230d(P2VAR(It_SG_sigGrp00R00108D_A_b01r04_SigGroup_3133230d, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R00108D_A_b03r04_SigGroup_9b3aeb86_De_SG_sigGrp00R00108D_A_b03r04_SigGroup_9b3aeb86(P2VAR(It_SG_sigGrp00R00108D_A_b03r04_SigGroup_9b3aeb86, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R00109D_A_b01r04_SigGroup_f0bdfccd_De_SG_sigGrp00R00109D_A_b01r04_SigGroup_f0bdfccd(P2VAR(It_SG_sigGrp00R00109D_A_b01r04_SigGroup_f0bdfccd, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R00109D_A_b03r04_SigGroup_5ab43446_De_SG_sigGrp00R00109D_A_b03r04_SigGroup_5ab43446(P2VAR(It_SG_sigGrp00R00109D_A_b03r04_SigGroup_5ab43446, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R00110D_A_b01r04_SigGroup_10558e27_De_SG_sigGrp00R00110D_A_b01r04_SigGroup_10558e27(P2VAR(It_SG_sigGrp00R00110D_A_b01r04_SigGroup_10558e27, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R00119D_A_b00r04_SigGroup_d3a4d7c7_De_SG_sigGrp00R00119D_A_b00r04_SigGroup_d3a4d7c7(P2VAR(It_SG_sigGrp00R00119D_A_b00r04_SigGroup_d3a4d7c7, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_0_872d77f7_De_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_0_872d77f7(P2VAR(It_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_0_872d77f7, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_1_f02a4761_De_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_1_f02a4761(P2VAR(It_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_1_f02a4761, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_2_692316db_De_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_2_692316db(P2VAR(It_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_2_692316db, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_3_1e24264d_De_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_3_1e24264d(P2VAR(It_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_3_1e24264d, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_0_50cff7af_De_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_0_50cff7af(P2VAR(It_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_0_50cff7af, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_1_27c8c739_De_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_1_27c8c739(P2VAR(It_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_1_27c8c739, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_2_bec19683_De_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_2_bec19683(P2VAR(It_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_2_bec19683, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_3_c9c6a615_De_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_3_c9c6a615(P2VAR(It_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_3_c9c6a615, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R0113D_A_b00r04_SigGroup_c74a02d7_De_SG_sigGrp00R0113D_A_b00r04_SigGroup_c74a02d7(P2VAR(It_SG_sigGrp00R0113D_A_b00r04_SigGroup_c74a02d7, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R0114D_A_b02r04_SigGroup_4478dfdf_De_SG_sigGrp00R0114D_A_b02r04_SigGroup_4478dfdf(P2VAR(It_SG_sigGrp00R0114D_A_b02r04_SigGroup_4478dfdf, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R0235D_A_b00r01_SigGroup_0e64ce4a_De_SG_sigGrp00R0235D_A_b00r01_SigGroup_0e64ce4a(P2VAR(It_SG_sigGrp00R0235D_A_b00r01_SigGroup_0e64ce4a, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R0236D_A_b00r01_SigGroup_9786a84b_De_SG_sigGrp00R0236D_A_b00r01_SigGroup_9786a84b(P2VAR(It_SG_sigGrp00R0236D_A_b00r01_SigGroup_9786a84b, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00T040S_A_b03r04_SigGroup_cc337b5f_De_SG_sigGrp00T040S_A_b03r04_SigGroup_cc337b5f(P2VAR(It_SG_sigGrp00T040S_A_b03r04_SigGroup_cc337b5f, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00_0x776_0a2bb6b7_De_SG_sigGrp00_0x776_0a2bb6b7(P2VAR(It_SG_sigGrp00_0x776_0a2bb6b7, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00_0x777_cba56977_De_SG_sigGrp00_0x777_cba56977(P2VAR(It_SG_sigGrp00_0x777_cba56977, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00_0x7A3_b00b3ee1_De_SG_sigGrp00_0x7A3_b00b3ee1(P2VAR(It_SG_sigGrp00_0x7A3_b00b3ee1, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp01_0x776_0a2bb6b7_De_SG_sigGrp01_0x776_0a2bb6b7(P2VAR(It_SG_sigGrp01_0x776_0a2bb6b7, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp01_0x777_cba56977_De_SG_sigGrp01_0x777_cba56977(P2VAR(It_SG_sigGrp01_0x777_cba56977, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp01_0x7A1_e8678720_De_SG_sigGrp01_0x7A1_e8678720(P2VAR(It_SG_sigGrp01_0x7A1_e8678720, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp01_0x7A5_58bef4a2_De_SG_sigGrp01_0x7A5_58bef4a2(P2VAR(It_SG_sigGrp01_0x7A5_58bef4a2, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp02_0x7A3_b00b3ee1_De_SG_sigGrp02_0x7A3_b00b3ee1(P2VAR(It_SG_sigGrp02_0x7A3_b00b3ee1, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp02_0x7A5_58bef4a2_De_SG_sigGrp02_0x7A5_58bef4a2(P2VAR(It_SG_sigGrp02_0x7A5_58bef4a2, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrpRx_0x231_IL_3ac9523b_De_SG_sigGrpRx_0x231_IL_3ac9523b(P2VAR(It_SG_sigGrpRx_0x231_IL_3ac9523b, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps00R0100D_A_b01r08_Des00R0100D_A_b01r08(P2VAR(It_Uint8_4bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps00R0118D_A_b01r08_Des00R0118D_A_b01r08(P2VAR(It_Uint8_4bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps00R142D_A_b00r08_Des00R142D_A_b00r08(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps00R142D_A_b01r08_Des00R142D_A_b01r08(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps00T044S_A_b01r04_Des00T044S_A_b01r04(P2VAR(It_Uint8_3bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps00T044S_A_b02r04_Des00T044S_A_b02r04(P2VAR(It_Uint8_3bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps00T044S_A_b03r04_Des00T044S_A_b03r04(P2VAR(It_Uint8_3bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps01R0100D_A_b01r08_Des01R0100D_A_b01r08(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps01R0118D_A_b01r08_Des01R0118D_A_b01r08(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps01R142D_A_b00r08_Des01R142D_A_b00r08(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps01R142D_A_b01r08_Des01R142D_A_b01r08(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps01T044S_A_b01r04_Des01T044S_A_b01r04(P2VAR(It_Uint8_5bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps01T044S_A_b02r04_Des01T044S_A_b02r04(P2VAR(It_Uint8_5bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps01T044S_A_b03r04_Des01T044S_A_b03r04(P2VAR(It_Uint8_5bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps02R0100D_A_b01r08_Des02R0100D_A_b01r08(P2VAR(It_Uint8_4bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps02R0118D_A_b01r08_Des02R0118D_A_b01r08(P2VAR(It_Uint8_4bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps02R142D_A_b00r08_Des02R142D_A_b00r08(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps02R142D_A_b01r08_Des02R142D_A_b01r08(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps02T044S_A_b01r04_Des02T044S_A_b01r04(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps02T044S_A_b02r04_Des02T044S_A_b02r04(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps02T044S_A_b03r04_Des02T044S_A_b03r04(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps03R0100D_A_b01r08_Des03R0100D_A_b01r08(P2VAR(It_Boolean_1bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps03R0118D_A_b01r08_Des03R0118D_A_b01r08(P2VAR(It_Boolean_1bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps03T044S_A_b01r04_Des03T044S_A_b01r04(P2VAR(It_Uint16_12bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps03T044S_A_b02r04_Des03T044S_A_b02r04(P2VAR(It_Uint16_12bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps03T044S_A_b03r04_Des03T044S_A_b03r04(P2VAR(It_Uint16_12bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps04R0118D_A_b01r08_Des04R0118D_A_b01r08(P2VAR(It_Uint8_3bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps04T044S_A_b01r04_Des04T044S_A_b01r04(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps04T044S_A_b02r04_Des04T044S_A_b02r04(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps04T044S_A_b03r04_Des04T044S_A_b03r04(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps05R0118D_A_b01r08_Des05R0118D_A_b01r08(P2VAR(It_Uint8_4bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps05T044S_A_b01r04_Des05T044S_A_b01r04(P2VAR(It_Uint32_24bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps05T044S_A_b02r04_Des05T044S_A_b02r04(P2VAR(It_Uint32_24bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps05T044S_A_b03r04_Des05T044S_A_b03r04(P2VAR(It_Uint32_24bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps06R0100D_A_b01r08_Des06R0100D_A_b01r08(P2VAR(It_Uint16_12bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps06R0118D_A_b01r08_Des06R0118D_A_b01r08(P2VAR(It_Uint16_12bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps07R0100D_A_b01r08_Des07R0100D_A_b01r08(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps07R0118D_A_b01r08_Des07R0118D_A_b01r08(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps0R0010S_A_b00r04_IPDUM_DynSig_0_Des0R0010S_A_b00r04_IPDUM_DynSig_0(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps0R0010S_A_b01r04_IPDUM_DynSig_0_Des0R0010S_A_b01r04_IPDUM_DynSig_0(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps0R0010S_A_b01r04_IPDUM_DynSig_1_Des0R0010S_A_b01r04_IPDUM_DynSig_1(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps0R0010S_A_b01r04_IPDUM_DynSig_2_Des0R0010S_A_b01r04_IPDUM_DynSig_2(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps0R0010S_A_b01r04_IPDUM_DynSig_3_Des0R0010S_A_b01r04_IPDUM_DynSig_3(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps0R0010S_A_b02r04_IPDUM_DynSig_0_Des0R0010S_A_b02r04_IPDUM_DynSig_0(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps0R0010S_A_b03r04_IPDUM_DynSig_0_Des0R0010S_A_b03r04_IPDUM_DynSig_0(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps0R0010S_A_b03r04_IPDUM_DynSig_1_Des0R0010S_A_b03r04_IPDUM_DynSig_1(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps0R0010S_A_b03r04_IPDUM_DynSig_2_Des0R0010S_A_b03r04_IPDUM_DynSig_2(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps0R0010S_A_b03r04_IPDUM_DynSig_3_Des0R0010S_A_b03r04_IPDUM_DynSig_3(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps0_p00R041S_A_b00r04_Des0_p00R041S_A_b00r04(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps0_p00R041S_A_b01r04_Des0_p00R041S_A_b01r04(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps0_p01R041S_A_b00r04_Des0_p01R041S_A_b00r04(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps10_p00R041S_A_b01r04_Des10_p00R041S_A_b01r04(P2VAR(It_Uint8_2bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps11_p00R041S_A_b01r04_Des11_p00R041S_A_b01r04(P2VAR(It_Boolean_1bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps12_p00R041S_A_b01r04_Des12_p00R041S_A_b01r04(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps13_p00R041S_A_b01r04_Des13_p00R041S_A_b01r04(P2VAR(It_Uint8_4bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps1R0010S_A_b00r04_IPDUM_DynSig_0_Des1R0010S_A_b00r04_IPDUM_DynSig_0(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps1R0010S_A_b01r04_IPDUM_DynSig_0_Des1R0010S_A_b01r04_IPDUM_DynSig_0(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps1R0010S_A_b01r04_IPDUM_DynSig_1_Des1R0010S_A_b01r04_IPDUM_DynSig_1(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps1R0010S_A_b01r04_IPDUM_DynSig_2_Des1R0010S_A_b01r04_IPDUM_DynSig_2(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps1R0010S_A_b01r04_IPDUM_DynSig_3_Des1R0010S_A_b01r04_IPDUM_DynSig_3(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps1R0010S_A_b02r04_IPDUM_DynSig_0_Des1R0010S_A_b02r04_IPDUM_DynSig_0(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps1R0010S_A_b03r04_IPDUM_DynSig_0_Des1R0010S_A_b03r04_IPDUM_DynSig_0(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps1R0010S_A_b03r04_IPDUM_DynSig_1_Des1R0010S_A_b03r04_IPDUM_DynSig_1(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps1R0010S_A_b03r04_IPDUM_DynSig_2_Des1R0010S_A_b03r04_IPDUM_DynSig_2(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps1R0010S_A_b03r04_IPDUM_DynSig_3_Des1R0010S_A_b03r04_IPDUM_DynSig_3(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps1_p00R041S_A_b00r04_Des1_p00R041S_A_b00r04(P2VAR(It_Uint8_4bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps1_p00R041S_A_b01r04_Des1_p00R041S_A_b01r04(P2VAR(It_Uint8_4bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps1_p01R041S_A_b00r04_Des1_p01R041S_A_b00r04(P2VAR(It_Uint8_4bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps2_p00R041S_A_b00r04_Des2_p00R041S_A_b00r04(P2VAR(It_Uint8_2bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps2_p00R041S_A_b01r04_Des2_p00R041S_A_b01r04(P2VAR(It_Uint8_2bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps2_p01R041S_A_b00r04_Des2_p01R041S_A_b00r04(P2VAR(It_Uint8_2bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps3_p00R041S_A_b00r04_Des3_p00R041S_A_b00r04(P2VAR(It_Boolean_1bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps3_p00R041S_A_b01r04_Des3_p00R041S_A_b01r04(P2VAR(It_Boolean_1bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps3_p01R041S_A_b00r04_Des3_p01R041S_A_b00r04(P2VAR(It_Boolean_1bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps4_p00R041S_A_b00r04_Des4_p00R041S_A_b00r04(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps4_p00R041S_A_b01r04_Des4_p00R041S_A_b01r04(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps4_p01R041S_A_b00r04_Des4_p01R041S_A_b00r04(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps5_p00R041S_A_b01r04_Des5_p00R041S_A_b01r04(P2VAR(It_Uint8_4bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps6_p00R041S_A_b01r04_Des6_p00R041S_A_b01r04(P2VAR(It_Uint8_2bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps7_p00R041S_A_b01r04_Des7_p00R041S_A_b01r04(P2VAR(It_Boolean_1bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps8_p00R041S_A_b01r04_Des8_p00R041S_A_b01r04(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps9_p00R041S_A_b01r04_Des9_p00R041S_A_b01r04(P2VAR(It_Uint8_4bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpsR00108D_A_b00r04_DesR00108D_A_b00r04(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpsR00108D_A_b02r04_DesR00108D_A_b02r04(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpsR00109D_A_b00r04_DesR00109D_A_b00r04(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpsR00109D_A_b02r04_DesR00109D_A_b02r04(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpsR00110D_A_b00r04_DesR00110D_A_b00r04(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpsR00110D_A_b02r04_DesR00110D_A_b02r04(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpsR0112D_A_b03r04_DesR0112D_A_b03r04(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_PpsR0114D_A_b01r04_DesR0114D_A_b01r04(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps_cnt_p00R041S_A_b00r04_Des_cnt_p00R041S_A_b00r04(P2VAR(It_Uint8_4bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps_cnt_p00R041S_A_b01r04_Des_cnt_p00R041S_A_b01r04(P2VAR(It_Uint8_4bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps_cnt_p01R041S_A_b00r04_Des_cnt_p01R041S_A_b00r04(P2VAR(It_Uint8_4bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps_crc_p00R041S_A_b00r04_Des_crc_p00R041S_A_b00r04(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps_crc_p00R041S_A_b01r04_Des_crc_p00R041S_A_b01r04(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Pps_crc_p01R041S_A_b00r04_Des_crc_p01R041S_A_b00r04(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig00Rx_0x21C_IL_Desig00Rx_0x21C_IL(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig00Rx_0x21E_IL_Desig00Rx_0x21E_IL(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig00Rx_0x220_IL_Desig00Rx_0x220_IL(P2VAR(It_Uint32_32bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig00Rx_0x222_IL_Desig00Rx_0x222_IL(P2VAR(It_Sint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig00Rx_0x224_IL_Desig00Rx_0x224_IL(P2VAR(It_Sint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig00Rx_0x226_IL_Desig00Rx_0x226_IL(P2VAR(It_Sint32_32bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig00Rx_0x229_IL_Desig00Rx_0x229_IL(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig00Rx_0x230_IL_Desig00Rx_0x230_IL(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig00Rx_0x3EB_IL_Desig00Rx_0x3EB_IL(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig00Rx_0x758_IL_Desig00Rx_0x758_IL(P2VAR(It_Uint32_24bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig00Rx_0x768_IL_Desig00Rx_0x768_IL(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig00Rx_0x770_IL_Desig00Rx_0x770_IL(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig00_0x776_Desig00_0x776(P2VAR(It_Sint16_15bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig00_0x777_Desig00_0x777(P2VAR(It_Uint16_13bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig00_0x780_Desig00_0x780(P2VAR(It_Uint8_4bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig00_0x7A1_Desig00_0x7A1(P2VAR(It_Uint8_2bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig00_0x7A3_Desig00_0x7A3(P2VAR(It_Uint8_2bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig00_Rx_0x22D_IL_Desig00_Rx_0x22D_IL(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig01Rx_0x229_IL_Desig01Rx_0x229_IL(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig01Rx_0x230_IL_Desig01Rx_0x230_IL(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig01Rx_0x4C1_IL_Desig01Rx_0x4C1_IL(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig01Rx_0x758_IL_Desig01Rx_0x758_IL(P2VAR(It_Uint32_32bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig01Rx_0x768_IL_Desig01Rx_0x768_IL(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig01Rx_0x770_IL_Desig01Rx_0x770_IL(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig01Rx_0x773_IL_Desig01Rx_0x773_IL(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig01Rx_0x775_IL_Desig01Rx_0x775_IL(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig01_0x776_Desig01_0x776(P2VAR(It_Uint8_3bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig01_0x777_Desig01_0x777(P2VAR(It_Uint8_3bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig01_0x780_Desig01_0x780(P2VAR(It_Sint8_7bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig01_0x7A1_Desig01_0x7A1(P2VAR(It_Uint8_3bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig01_0x7A3_Desig01_0x7A3(P2VAR(It_Uint8_3bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig02Rx_0x229_IL_Desig02Rx_0x229_IL(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig02Rx_0x230_IL_Desig02Rx_0x230_IL(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig02Rx_0x768_IL_Desig02Rx_0x768_IL(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig02Rx_0x770_IL_Desig02Rx_0x770_IL(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig02Rx_0x773_IL_Desig02Rx_0x773_IL(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig02Rx_0x775_IL_Desig02Rx_0x775_IL(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig02_0x780_Desig02_0x780(P2VAR(It_Uint16_9bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig02_0x7A3_Desig02_0x7A3(P2VAR(It_Uint8_4bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig03Rx_0x229_IL_Desig03Rx_0x229_IL(P2VAR(It_Uint8_8bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig03Rx_0x230_IL_Desig03Rx_0x230_IL(P2VAR(It_Uint32_32bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig03_0x780_Desig03_0x780(P2VAR(It_Uint16_12bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig12Rx_0x766_IL_Desig12Rx_0x766_IL(P2VAR(It_Uint8_3bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig20Rx_0x766_IL_Desig20Rx_0x766_IL(P2VAR(It_Uint8_4bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig21Rx_0x766_IL_Desig21Rx_0x766_IL(P2VAR(It_Uint16_12bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtCdd_TgfTestApplication_Ppsig22Rx_0x766_IL_Desig22Rx_0x766_IL(P2VAR(It_Uint16_16bit, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpCanRPGSig_1_DeCanRPGSig_1(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpCanRPGSig_2_DeCanRPGSig_2(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpCanRPGSig_3_DeCanRPGSig_3(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpCanRPGSig_4_DeCanRPGSig_4(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpCanRPGSig_5_DeCanRPGSig_5(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpComCanSig_16bit_1_DeComCanSig_16bit_1(It_Uint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpGwCanSig_8Bit_1_DeGwCanSig_8Bit_1(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpGwCanSig_8Bit_2_DeGwCanSig_8Bit_2(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpSig00Tx_0x3EE_IL_DeSig00Tx_0x3EE_IL(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpSig00Tx_0x756_DeSig00Tx_0x756(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpSig_16Bit_20_DeSig_16Bit_20(It_Uint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpSig_16Bit_23_DeSig_16Bit_23(It_Uint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpSig_16bit_10_DeSig_16bit_10(It_Uint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpSig_16bit_11_DeSig_16bit_11(It_Uint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpSig_16bit_16_DeSig_16bit_16(It_Uint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpSig_16bit_9_DeSig_16bit_9(It_Uint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpSig_32Bit_3_DeSig_32Bit_3(It_Uint32_32bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpSig_8Bit_11_DeSig_8Bit_11(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpSig_8Bit_20_DeSig_8Bit_20(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpSig_8Bit_21_DeSig_8Bit_21(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpSig_8Bit_22_DeSig_8Bit_22(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpSig_8bit_10_DeSig_8bit_10(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpSig_Bool_3_DeSig_Bool_3(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpSig_Cdd_1_DeSig_Cdd_1(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpSig_Cdd_8Bit_2_DeSig_Cdd_8Bit_2(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_CanComGrpSig_14_b40ca185_De_SG_CanComGrpSig_14_b40ca185(P2CONST(It_SG_CanComGrpSig_14_b40ca185, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_CanComGrpSig_15_75827e45_De_SG_CanComGrpSig_15_75827e45(P2CONST(It_SG_CanComGrpSig_15_75827e45, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00T00121D_A_b00r01_SigGroup_3d027919_De_SG_sigGrp00T00121D_A_b00r01_SigGroup_3d027919(P2CONST(It_SG_sigGrp00T00121D_A_b00r01_SigGroup_3d027919, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00T00125D_A_b00r01_SigGroup_8ddb0a9b_De_SG_sigGrp00T00125D_A_b00r01_SigGroup_8ddb0a9b(P2CONST(It_SG_sigGrp00T00125D_A_b00r01_SigGroup_8ddb0a9b, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00T00127D_A_b00r01_SigGroup_d5b7b35a_De_SG_sigGrp00T00127D_A_b00r01_SigGroup_d5b7b35a(P2CONST(It_SG_sigGrp00T00127D_A_b00r01_SigGroup_d5b7b35a, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00T00131D_A_b00r01_SigGroup_a6a73576_De_SG_sigGrp00T00131D_A_b00r01_SigGroup_a6a73576(P2CONST(It_SG_sigGrp00T00131D_A_b00r01_SigGroup_a6a73576, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00T0118D_A_b03r08_SigGroup_dd92b2a4_De_SG_sigGrp00T0118D_A_b03r08_SigGroup_dd92b2a4(P2CONST(It_SG_sigGrp00T0118D_A_b03r08_SigGroup_dd92b2a4, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00T0118D_A_b04r08_SigGroup_40458a1d_De_SG_sigGrp00T0118D_A_b04r08_SigGroup_40458a1d(P2CONST(It_SG_sigGrp00T0118D_A_b04r08_SigGroup_40458a1d, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00T094D_A_b00r08_SigGroup_3c347067_De_SG_sigGrp00T094D_A_b00r08_SigGroup_3c347067(P2CONST(It_SG_sigGrp00T094D_A_b00r08_SigGroup_3c347067, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00T094D_A_b01r08_SigGroup_84881702_De_SG_sigGrp00T094D_A_b01r08_SigGroup_84881702(P2CONST(It_SG_sigGrp00T094D_A_b01r08_SigGroup_84881702, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00T094D_A_b02r08_SigGroup_963db8ec_De_SG_sigGrp00T094D_A_b02r08_SigGroup_963db8ec(P2CONST(It_SG_sigGrp00T094D_A_b02r08_SigGroup_963db8ec, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00T094D_A_b03r08_SigGroup_2e81df89_De_SG_sigGrp00T094D_A_b03r08_SigGroup_2e81df89(P2CONST(It_SG_sigGrp00T094D_A_b03r08_SigGroup_2e81df89, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00T094D_A_b04r08_SigGroup_b356e730_De_SG_sigGrp00T094D_A_b04r08_SigGroup_b356e730(P2CONST(It_SG_sigGrp00T094D_A_b04r08_SigGroup_b356e730, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00_0x7A0_29e958e0_De_SG_sigGrp00_0x7A0_29e958e0(P2CONST(It_SG_sigGrp00_0x7A0_29e958e0, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00_0x7A4_ee371bf4_De_SG_sigGrp00_0x7A4_ee371bf4(P2CONST(It_SG_sigGrp00_0x7A4_ee371bf4, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp01T0118D_A_b03r08_SigGroup_73fa2335_De_SG_sigGrp01T0118D_A_b03r08_SigGroup_73fa2335(P2CONST(It_SG_sigGrp01T0118D_A_b03r08_SigGroup_73fa2335, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp01T0118D_A_b04r08_SigGroup_ee2d1b8c_De_SG_sigGrp01T0118D_A_b04r08_SigGroup_ee2d1b8c(P2CONST(It_SG_sigGrp01T0118D_A_b04r08_SigGroup_ee2d1b8c, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp01_0x7A0_29e958e0_De_SG_sigGrp01_0x7A0_29e958e0(P2CONST(It_SG_sigGrp01_0x7A0_29e958e0, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp01_0x7A2_0682d1b7_De_SG_sigGrp01_0x7A2_0682d1b7(P2CONST(It_SG_sigGrp01_0x7A2_0682d1b7, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp01_0x7A4_ee371bf4_De_SG_sigGrp01_0x7A4_ee371bf4(P2CONST(It_SG_sigGrp01_0x7A4_ee371bf4, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp02T0118D_A_b03r08_SigGroup_5a3297c7_De_SG_sigGrp02T0118D_A_b03r08_SigGroup_5a3297c7(P2CONST(It_SG_sigGrp02T0118D_A_b03r08_SigGroup_5a3297c7, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp02T0118D_A_b04r08_SigGroup_c7e5af7e_De_SG_sigGrp02T0118D_A_b04r08_SigGroup_c7e5af7e(P2CONST(It_SG_sigGrp02T0118D_A_b04r08_SigGroup_c7e5af7e, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp02_0x7A0_29e958e0_De_SG_sigGrp02_0x7A0_29e958e0(P2CONST(It_SG_sigGrp02_0x7A0_29e958e0, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp02_0x7A4_ee371bf4_De_SG_sigGrp02_0x7A4_ee371bf4(P2CONST(It_SG_sigGrp02_0x7A4_ee371bf4, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp03T0118D_A_b03r08_SigGroup_f45a0656_De_SG_sigGrp03T0118D_A_b03r08_SigGroup_f45a0656(P2CONST(It_SG_sigGrp03T0118D_A_b03r08_SigGroup_f45a0656, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp03T0118D_A_b04r08_SigGroup_698d3eef_De_SG_sigGrp03T0118D_A_b04r08_SigGroup_698d3eef(P2CONST(It_SG_sigGrp03T0118D_A_b04r08_SigGroup_698d3eef, AUTOMATIC, RTE_CTCDD_TGFTESTAPPLICATION_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps00T0118D_A_b06r08_Des00T0118D_A_b06r08(It_Uint8_4bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps01T0118D_A_b06r08_Des01T0118D_A_b06r08(It_Uint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps01T028S_A_b00r08_Des01T028S_A_b00r08(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps02T0118D_A_b06r08_Des02T0118D_A_b06r08(It_Uint8_4bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps02T028S_A_b00r08_Des02T028S_A_b00r08(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps03T0118D_A_b06r08_Des03T0118D_A_b06r08(It_Boolean_1bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps04T0118D_A_b06r08_Des04T0118D_A_b06r08(It_Uint8_3bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps05T0118D_A_b06r08_Des05T0118D_A_b06r08(It_Uint8_4bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps06T0118D_A_b06r08_Des06T0118D_A_b06r08(It_Uint16_12bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps07T0118D_A_b06r08_Des07T0118D_A_b06r08(It_Uint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps0T0012S_A_b00r04_IPDUM_DynSig_0_Des0T0012S_A_b00r04_IPDUM_DynSig_0(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps0T0012S_A_b01r04_IPDUM_DynSig_0_Des0T0012S_A_b01r04_IPDUM_DynSig_0(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps0T0012S_A_b01r04_IPDUM_DynSig_1_Des0T0012S_A_b01r04_IPDUM_DynSig_1(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps0T0012S_A_b01r04_IPDUM_DynSig_2_Des0T0012S_A_b01r04_IPDUM_DynSig_2(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps0T0012S_A_b01r04_IPDUM_DynSig_3_Des0T0012S_A_b01r04_IPDUM_DynSig_3(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps0T0013S_A_b00r04_IPDUM_DynSig_0_Des0T0013S_A_b00r04_IPDUM_DynSig_0(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps0T0013S_A_b01r04_IPDUM_DynSig_0_Des0T0013S_A_b01r04_IPDUM_DynSig_0(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps0T0013S_A_b01r04_IPDUM_DynSig_1_Des0T0013S_A_b01r04_IPDUM_DynSig_1(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps0T0013S_A_b01r04_IPDUM_DynSig_2_Des0T0013S_A_b01r04_IPDUM_DynSig_2(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps0T0013S_A_b01r04_IPDUM_DynSig_3_Des0T0013S_A_b01r04_IPDUM_DynSig_3(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps10T030S_A_b00r08_Des10T030S_A_b00r08(It_Uint8_2bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps11T030S_A_b00r08_Des11T030S_A_b00r08(It_Uint8_3bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps12T030S_A_b00r08_Des12T030S_A_b00r08(It_Uint8_4bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps1T0012S_A_b00r04_IPDUM_DynSig_0_Des1T0012S_A_b00r04_IPDUM_DynSig_0(It_Uint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps1T0012S_A_b01r04_IPDUM_DynSig_0_Des1T0012S_A_b01r04_IPDUM_DynSig_0(It_Uint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps1T0012S_A_b01r04_IPDUM_DynSig_1_Des1T0012S_A_b01r04_IPDUM_DynSig_1(It_Uint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps1T0012S_A_b01r04_IPDUM_DynSig_2_Des1T0012S_A_b01r04_IPDUM_DynSig_2(It_Uint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps1T0012S_A_b01r04_IPDUM_DynSig_3_Des1T0012S_A_b01r04_IPDUM_DynSig_3(It_Uint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps1T0013S_A_b00r04_IPDUM_DynSig_0_Des1T0013S_A_b00r04_IPDUM_DynSig_0(It_Uint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps1T0013S_A_b01r04_IPDUM_DynSig_0_Des1T0013S_A_b01r04_IPDUM_DynSig_0(It_Uint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps1T0013S_A_b01r04_IPDUM_DynSig_1_Des1T0013S_A_b01r04_IPDUM_DynSig_1(It_Uint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps1T0013S_A_b01r04_IPDUM_DynSig_2_Des1T0013S_A_b01r04_IPDUM_DynSig_2(It_Uint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Pps1T0013S_A_b01r04_IPDUM_DynSig_3_Des1T0013S_A_b01r04_IPDUM_DynSig_3(It_Uint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpsT00120D_A_b00r01_DesT00120D_A_b00r01(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpsT00124D_A_b00r01_DesT00124D_A_b00r01(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpsT00126D_A_b00r01_DesT00126D_A_b00r01(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpsT00130D_A_b00r01_DesT00130D_A_b00r01(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpsT0137D_A_b00r02_DesT0137D_A_b00r02(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpsT0138D_A_b00r03_DesT0138D_A_b00r03(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpsT0232D_A_b00r02_DesT0232D_A_b00r02(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_PpsT0233D_A_b00r04_DesT0233D_A_b00r04(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00Rx_0x21D_IL_Desig00Rx_0x21D_IL(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00Rx_0x21F_IL_Desig00Rx_0x21F_IL(It_Uint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00Rx_0x221_IL_Desig00Rx_0x221_IL(It_Uint32_32bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00Rx_0x223_IL_Desig00Rx_0x223_IL(It_Sint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00Rx_0x225_IL_Desig00Rx_0x225_IL(It_Sint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00Rx_0x227_IL_Desig00Rx_0x227_IL(It_Sint32_32bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x228_IL_Desig00Tx_0x228_IL(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x3C3_IL_Desig00Tx_0x3C3_IL(It_Uint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x3C4_IL_Desig00Tx_0x3C4_IL(It_Uint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x3DD_IL_Desig00Tx_0x3DD_IL(It_Uint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x3DE_IL_Desig00Tx_0x3DE_IL(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x3EA_IL_Desig00Tx_0x3EA_IL(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x3EF_IL_Desig00Tx_0x3EF_IL(It_Uint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x754_IL_Desig00Tx_0x754_IL(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x755_IL_Desig00Tx_0x755_IL(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x757_IL_Desig00Tx_0x757_IL(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x757_IL_CAN00_Desig00Tx_0x757_IL_CAN00(It_Uint32_24bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x765_IL_Desig00Tx_0x765_IL(It_Uint8_4bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x767_IL_Desig00Tx_0x767_IL(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x769_IL_Desig00Tx_0x769_IL(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x771_IL_Desig00Tx_0x771_IL(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x772_IL_Desig00Tx_0x772_IL(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x774_IL_Desig00Tx_0x774_IL(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00_0x7A0_Desig00_0x7A0(It_Uint8_2bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00_0x7A2_Desig00_0x7A2(It_Uint8_2bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00_0x7A4_Desig00_0x7A4(It_Uint8_2bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig00_Tx_0x22C_IL_Desig00_Tx_0x22C_IL(It_Uint8_8bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtCdd_TgfTestApplication_Ppsig01Tx_0x765_IL_Desig01Tx_0x765_IL(It_Uint16_16bit data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpCanRPGSig_1_DeCanRPGSig_1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpCanRPGSig_2_DeCanRPGSig_2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpCanRPGSig_3_DeCanRPGSig_3(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpCanRPGSig_4_DeCanRPGSig_4(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpCanRPGSig_5_DeCanRPGSig_5(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpComCanSig_16bit_1_DeComCanSig_16bit_1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpGwCanSig_8Bit_1_DeGwCanSig_8Bit_1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpGwCanSig_8Bit_2_DeGwCanSig_8Bit_2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpSig00Tx_0x3EE_IL_DeSig00Tx_0x3EE_IL(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpSig00Tx_0x756_DeSig00Tx_0x756(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpSig_16Bit_20_DeSig_16Bit_20(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpSig_16Bit_23_DeSig_16Bit_23(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpSig_16bit_10_DeSig_16bit_10(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpSig_16bit_11_DeSig_16bit_11(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpSig_16bit_16_DeSig_16bit_16(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpSig_16bit_9_DeSig_16bit_9(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpSig_32Bit_3_DeSig_32Bit_3(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpSig_8Bit_11_DeSig_8Bit_11(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpSig_8Bit_20_DeSig_8Bit_20(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpSig_8Bit_21_DeSig_8Bit_21(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpSig_8Bit_22_DeSig_8Bit_22(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpSig_8bit_10_DeSig_8bit_10(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpSig_Bool_3_DeSig_Bool_3(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpSig_Cdd_1_DeSig_Cdd_1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpSig_Cdd_8Bit_2_DeSig_Cdd_8Bit_2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps00T0118D_A_b06r08_Des00T0118D_A_b06r08(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps01T0118D_A_b06r08_Des01T0118D_A_b06r08(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps01T028S_A_b00r08_Des01T028S_A_b00r08(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps02T0118D_A_b06r08_Des02T0118D_A_b06r08(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps02T028S_A_b00r08_Des02T028S_A_b00r08(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps03T0118D_A_b06r08_Des03T0118D_A_b06r08(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps04T0118D_A_b06r08_Des04T0118D_A_b06r08(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps05T0118D_A_b06r08_Des05T0118D_A_b06r08(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps06T0118D_A_b06r08_Des06T0118D_A_b06r08(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps07T0118D_A_b06r08_Des07T0118D_A_b06r08(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps0T0012S_A_b00r04_IPDUM_DynSig_0_Des0T0012S_A_b00r04_IPDUM_DynSig_0(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps0T0012S_A_b01r04_IPDUM_DynSig_0_Des0T0012S_A_b01r04_IPDUM_DynSig_0(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps0T0012S_A_b01r04_IPDUM_DynSig_1_Des0T0012S_A_b01r04_IPDUM_DynSig_1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps0T0012S_A_b01r04_IPDUM_DynSig_2_Des0T0012S_A_b01r04_IPDUM_DynSig_2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps0T0012S_A_b01r04_IPDUM_DynSig_3_Des0T0012S_A_b01r04_IPDUM_DynSig_3(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps0T0013S_A_b00r04_IPDUM_DynSig_0_Des0T0013S_A_b00r04_IPDUM_DynSig_0(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps0T0013S_A_b01r04_IPDUM_DynSig_0_Des0T0013S_A_b01r04_IPDUM_DynSig_0(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps0T0013S_A_b01r04_IPDUM_DynSig_1_Des0T0013S_A_b01r04_IPDUM_DynSig_1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps0T0013S_A_b01r04_IPDUM_DynSig_2_Des0T0013S_A_b01r04_IPDUM_DynSig_2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps0T0013S_A_b01r04_IPDUM_DynSig_3_Des0T0013S_A_b01r04_IPDUM_DynSig_3(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps10T030S_A_b00r08_Des10T030S_A_b00r08(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps11T030S_A_b00r08_Des11T030S_A_b00r08(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps12T030S_A_b00r08_Des12T030S_A_b00r08(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps1T0012S_A_b00r04_IPDUM_DynSig_0_Des1T0012S_A_b00r04_IPDUM_DynSig_0(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps1T0012S_A_b01r04_IPDUM_DynSig_0_Des1T0012S_A_b01r04_IPDUM_DynSig_0(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps1T0012S_A_b01r04_IPDUM_DynSig_1_Des1T0012S_A_b01r04_IPDUM_DynSig_1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps1T0012S_A_b01r04_IPDUM_DynSig_2_Des1T0012S_A_b01r04_IPDUM_DynSig_2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps1T0012S_A_b01r04_IPDUM_DynSig_3_Des1T0012S_A_b01r04_IPDUM_DynSig_3(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps1T0013S_A_b00r04_IPDUM_DynSig_0_Des1T0013S_A_b00r04_IPDUM_DynSig_0(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps1T0013S_A_b01r04_IPDUM_DynSig_0_Des1T0013S_A_b01r04_IPDUM_DynSig_0(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps1T0013S_A_b01r04_IPDUM_DynSig_1_Des1T0013S_A_b01r04_IPDUM_DynSig_1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps1T0013S_A_b01r04_IPDUM_DynSig_2_Des1T0013S_A_b01r04_IPDUM_DynSig_2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Pps1T0013S_A_b01r04_IPDUM_DynSig_3_Des1T0013S_A_b01r04_IPDUM_DynSig_3(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpsT00120D_A_b00r01_DesT00120D_A_b00r01(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpsT00124D_A_b00r01_DesT00124D_A_b00r01(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpsT00126D_A_b00r01_DesT00126D_A_b00r01(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpsT00130D_A_b00r01_DesT00130D_A_b00r01(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpsT0137D_A_b00r02_DesT0137D_A_b00r02(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpsT0138D_A_b00r03_DesT0138D_A_b00r03(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpsT0232D_A_b00r02_DesT0232D_A_b00r02(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_PpsT0233D_A_b00r04_DesT0233D_A_b00r04(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Rx_0x21D_IL_Desig00Rx_0x21D_IL(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Rx_0x21F_IL_Desig00Rx_0x21F_IL(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Rx_0x221_IL_Desig00Rx_0x221_IL(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Rx_0x223_IL_Desig00Rx_0x223_IL(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Rx_0x225_IL_Desig00Rx_0x225_IL(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Rx_0x227_IL_Desig00Rx_0x227_IL(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x228_IL_Desig00Tx_0x228_IL(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x3C3_IL_Desig00Tx_0x3C3_IL(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x3C4_IL_Desig00Tx_0x3C4_IL(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x3DD_IL_Desig00Tx_0x3DD_IL(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x3DE_IL_Desig00Tx_0x3DE_IL(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x3EA_IL_Desig00Tx_0x3EA_IL(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x3EF_IL_Desig00Tx_0x3EF_IL(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x754_IL_Desig00Tx_0x754_IL(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x755_IL_Desig00Tx_0x755_IL(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x757_IL_Desig00Tx_0x757_IL(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x757_IL_CAN00_Desig00Tx_0x757_IL_CAN00(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x765_IL_Desig00Tx_0x765_IL(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x767_IL_Desig00Tx_0x767_IL(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x769_IL_Desig00Tx_0x769_IL(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x771_IL_Desig00Tx_0x771_IL(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x772_IL_Desig00Tx_0x772_IL(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x774_IL_Desig00Tx_0x774_IL(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00_0x7A0_Desig00_0x7A0(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00_0x7A2_Desig00_0x7A2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00_0x7A4_Desig00_0x7A4(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00_Tx_0x22C_IL_Desig00_Tx_0x22C_IL(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_CtCdd_TgfTestApplication_Ppsig01Tx_0x765_IL_Desig01Tx_0x765_IL(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_PpComCanSig_16Bit_13_DeComCanSig_16Bit_13 Rte_Read_CtCdd_TgfTestApplication_PpComCanSig_16Bit_13_DeComCanSig_16Bit_13
#  define Rte_Read_PpComCanSig_16Bit_18_DeComCanSig_16Bit_18 Rte_Read_CtCdd_TgfTestApplication_PpComCanSig_16Bit_18_DeComCanSig_16Bit_18
#  define Rte_Read_PpComCanSig_16bit_2_DeComCanSig_16bit_2 Rte_Read_CtCdd_TgfTestApplication_PpComCanSig_16bit_2_DeComCanSig_16bit_2
#  define Rte_Read_PpComFrSig_32Bit_2_DeComFrSig_32Bit_2 Rte_Read_CtCdd_TgfTestApplication_PpComFrSig_32Bit_2_DeComFrSig_32Bit_2
#  define Rte_Read_PpGwCanCan_Can1Sig_32Bit1_DeGwCanCan_Can1Sig_32Bit1 Rte_Read_CtCdd_TgfTestApplication_PpGwCanCan_Can1Sig_32Bit1_DeGwCanCan_Can1Sig_32Bit1
#  define Rte_Read_PpGwCanCan_Can1Sig_8Bit1_DeGwCanCan_Can1Sig_8Bit1 Rte_Read_CtCdd_TgfTestApplication_PpGwCanCan_Can1Sig_8Bit1_DeGwCanCan_Can1Sig_8Bit1
#  define Rte_Read_PpGwCanCan_Can2Sig_16Bit1_DeGwCanCan_Can2Sig_16Bit1 Rte_Read_CtCdd_TgfTestApplication_PpGwCanCan_Can2Sig_16Bit1_DeGwCanCan_Can2Sig_16Bit1
#  define Rte_Read_PpGwCanCan_Can2Sig_32Bit1_DeGwCanCan_Can2Sig_32Bit1 Rte_Read_CtCdd_TgfTestApplication_PpGwCanCan_Can2Sig_32Bit1_DeGwCanCan_Can2Sig_32Bit1
#  define Rte_Read_PpGwCanCan_Can2Sig_8Bit2_DeGwCanCan_Can2Sig_8Bit2 Rte_Read_CtCdd_TgfTestApplication_PpGwCanCan_Can2Sig_8Bit2_DeGwCanCan_Can2Sig_8Bit2
#  define Rte_Read_PpGwCanFr_Can2Sig_8Bit_3_DeGwCanFr_Can2Sig_8Bit_3 Rte_Read_CtCdd_TgfTestApplication_PpGwCanFr_Can2Sig_8Bit_3_DeGwCanFr_Can2Sig_8Bit_3
#  define Rte_Read_PpGwCanFr_CanSig_16Bit_1_DeGwCanFr_CanSig_16Bit_1 Rte_Read_CtCdd_TgfTestApplication_PpGwCanFr_CanSig_16Bit_1_DeGwCanFr_CanSig_16Bit_1
#  define Rte_Read_PpGwCanFr_CanSig_32Bit_1_DeGwCanFr_CanSig_32Bit_1 Rte_Read_CtCdd_TgfTestApplication_PpGwCanFr_CanSig_32Bit_1_DeGwCanFr_CanSig_32Bit_1
#  define Rte_Read_PpGwCanFr_CanSig_8Bit_1_DeGwCanFr_CanSig_8Bit_1 Rte_Read_CtCdd_TgfTestApplication_PpGwCanFr_CanSig_8Bit_1_DeGwCanFr_CanSig_8Bit_1
#  define Rte_Read_PpGwCanFr_CanSig_8Bit_2_DeGwCanFr_CanSig_8Bit_2 Rte_Read_CtCdd_TgfTestApplication_PpGwCanFr_CanSig_8Bit_2_DeGwCanFr_CanSig_8Bit_2
#  define Rte_Read_PpGwFrSig_16Bit_2_DeGwFrSig_16Bit_2 Rte_Read_CtCdd_TgfTestApplication_PpGwFrSig_16Bit_2_DeGwFrSig_16Bit_2
#  define Rte_Read_PpGwFrSig_32Bit_6_DeGwFrSig_32Bit_6 Rte_Read_CtCdd_TgfTestApplication_PpGwFrSig_32Bit_6_DeGwFrSig_32Bit_6
#  define Rte_Read_PpGwFrSig_8Bit_3_DeGwFrSig_8Bit_3 Rte_Read_CtCdd_TgfTestApplication_PpGwFrSig_8Bit_3_DeGwFrSig_8Bit_3
#  define Rte_Read_PpSig_16Bit_17_DeSig_16Bit_17 Rte_Read_CtCdd_TgfTestApplication_PpSig_16Bit_17_DeSig_16Bit_17
#  define Rte_Read_PpSig_16Bit_18_DeSig_16Bit_18 Rte_Read_CtCdd_TgfTestApplication_PpSig_16Bit_18_DeSig_16Bit_18
#  define Rte_Read_PpSig_16Bit_19_DeSig_16Bit_19 Rte_Read_CtCdd_TgfTestApplication_PpSig_16Bit_19_DeSig_16Bit_19
#  define Rte_Read_PpSig_16Bit_2_DeSig_16Bit_2 Rte_Read_CtCdd_TgfTestApplication_PpSig_16Bit_2_DeSig_16Bit_2
#  define Rte_Read_PpSig_16Bit_4_DeSig_16Bit_4 Rte_Read_CtCdd_TgfTestApplication_PpSig_16Bit_4_DeSig_16Bit_4
#  define Rte_Read_PpSig_32Bit_2_DeSig_32Bit_2 Rte_Read_CtCdd_TgfTestApplication_PpSig_32Bit_2_DeSig_32Bit_2
#  define Rte_Read_PpSig_32Bit_21_DeSig_32Bit_21 Rte_Read_CtCdd_TgfTestApplication_PpSig_32Bit_21_DeSig_32Bit_21
#  define Rte_Read_PpSig_32Bit_22_DeSig_32Bit_22 Rte_Read_CtCdd_TgfTestApplication_PpSig_32Bit_22_DeSig_32Bit_22
#  define Rte_Read_PpSig_32Bit_4_DeSig_32Bit_4 Rte_Read_CtCdd_TgfTestApplication_PpSig_32Bit_4_DeSig_32Bit_4
#  define Rte_Read_PpSig_32bit_26_DeSig_32bit_26 Rte_Read_CtCdd_TgfTestApplication_PpSig_32bit_26_DeSig_32bit_26
#  define Rte_Read_PpSig_8Bit_13_DeSig_8Bit_13 Rte_Read_CtCdd_TgfTestApplication_PpSig_8Bit_13_DeSig_8Bit_13
#  define Rte_Read_PpSig_8Bit_15_DeSig_8Bit_15 Rte_Read_CtCdd_TgfTestApplication_PpSig_8Bit_15_DeSig_8Bit_15
#  define Rte_Read_PpSig_8Bit_16_DeSig_8Bit_16 Rte_Read_CtCdd_TgfTestApplication_PpSig_8Bit_16_DeSig_8Bit_16
#  define Rte_Read_PpSig_8Bit_17_DeSig_8Bit_17 Rte_Read_CtCdd_TgfTestApplication_PpSig_8Bit_17_DeSig_8Bit_17
#  define Rte_Read_PpSig_8Bit_18_DeSig_8Bit_18 Rte_Read_CtCdd_TgfTestApplication_PpSig_8Bit_18_DeSig_8Bit_18
#  define Rte_Read_PpSig_8Bit_2_DeSig_8Bit_2 Rte_Read_CtCdd_TgfTestApplication_PpSig_8Bit_2_DeSig_8Bit_2
#  define Rte_Read_PpSig_Bool_2_DeSig_Bool_2 Rte_Read_CtCdd_TgfTestApplication_PpSig_Bool_2_DeSig_Bool_2
#  define Rte_Read_PpSig_Bool_4_DeSig_Bool_4 Rte_Read_CtCdd_TgfTestApplication_PpSig_Bool_4_DeSig_Bool_4
#  define Rte_Read_PpSig_Cdd_2_DeSig_Cdd_2 Rte_Read_CtCdd_TgfTestApplication_PpSig_Cdd_2_DeSig_Cdd_2
#  define Rte_Read_PpSig_Cdd_8Bit_1_DeSig_Cdd_8Bit_1 Rte_Read_CtCdd_TgfTestApplication_PpSig_Cdd_8Bit_1_DeSig_Cdd_8Bit_1
#  define Rte_Read_Pp_SG_CanComGrpSig_12_5cb96bc6_De_SG_CanComGrpSig_12_5cb96bc6 Rte_Read_CtCdd_TgfTestApplication_Pp_SG_CanComGrpSig_12_5cb96bc6_De_SG_CanComGrpSig_12_5cb96bc6
#  define Rte_Read_Pp_SG_SigGrpRx_0x4C2_IL_27846a13_De_SG_SigGrpRx_0x4C2_IL_27846a13 Rte_Read_CtCdd_TgfTestApplication_Pp_SG_SigGrpRx_0x4C2_IL_27846a13_De_SG_SigGrpRx_0x4C2_IL_27846a13
#  define Rte_Read_Pp_SG_sigGrp00R00108D_A_b01r04_SigGroup_3133230d_De_SG_sigGrp00R00108D_A_b01r04_SigGroup_3133230d Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R00108D_A_b01r04_SigGroup_3133230d_De_SG_sigGrp00R00108D_A_b01r04_SigGroup_3133230d
#  define Rte_Read_Pp_SG_sigGrp00R00108D_A_b03r04_SigGroup_9b3aeb86_De_SG_sigGrp00R00108D_A_b03r04_SigGroup_9b3aeb86 Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R00108D_A_b03r04_SigGroup_9b3aeb86_De_SG_sigGrp00R00108D_A_b03r04_SigGroup_9b3aeb86
#  define Rte_Read_Pp_SG_sigGrp00R00109D_A_b01r04_SigGroup_f0bdfccd_De_SG_sigGrp00R00109D_A_b01r04_SigGroup_f0bdfccd Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R00109D_A_b01r04_SigGroup_f0bdfccd_De_SG_sigGrp00R00109D_A_b01r04_SigGroup_f0bdfccd
#  define Rte_Read_Pp_SG_sigGrp00R00109D_A_b03r04_SigGroup_5ab43446_De_SG_sigGrp00R00109D_A_b03r04_SigGroup_5ab43446 Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R00109D_A_b03r04_SigGroup_5ab43446_De_SG_sigGrp00R00109D_A_b03r04_SigGroup_5ab43446
#  define Rte_Read_Pp_SG_sigGrp00R00110D_A_b01r04_SigGroup_10558e27_De_SG_sigGrp00R00110D_A_b01r04_SigGroup_10558e27 Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R00110D_A_b01r04_SigGroup_10558e27_De_SG_sigGrp00R00110D_A_b01r04_SigGroup_10558e27
#  define Rte_Read_Pp_SG_sigGrp00R00119D_A_b00r04_SigGroup_d3a4d7c7_De_SG_sigGrp00R00119D_A_b00r04_SigGroup_d3a4d7c7 Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R00119D_A_b00r04_SigGroup_d3a4d7c7_De_SG_sigGrp00R00119D_A_b00r04_SigGroup_d3a4d7c7
#  define Rte_Read_Pp_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_0_872d77f7_De_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_0_872d77f7 Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_0_872d77f7_De_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_0_872d77f7
#  define Rte_Read_Pp_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_1_f02a4761_De_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_1_f02a4761 Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_1_f02a4761_De_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_1_f02a4761
#  define Rte_Read_Pp_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_2_692316db_De_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_2_692316db Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_2_692316db_De_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_2_692316db
#  define Rte_Read_Pp_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_3_1e24264d_De_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_3_1e24264d Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_3_1e24264d_De_SG_sigGrp00R0011S_A_b00r04_IPDUM_DynSigGroup_3_1e24264d
#  define Rte_Read_Pp_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_0_50cff7af_De_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_0_50cff7af Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_0_50cff7af_De_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_0_50cff7af
#  define Rte_Read_Pp_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_1_27c8c739_De_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_1_27c8c739 Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_1_27c8c739_De_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_1_27c8c739
#  define Rte_Read_Pp_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_2_bec19683_De_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_2_bec19683 Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_2_bec19683_De_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_2_bec19683
#  define Rte_Read_Pp_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_3_c9c6a615_De_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_3_c9c6a615 Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_3_c9c6a615_De_SG_sigGrp00R0011S_A_b01r04_IPDUM_DynSigGroup_3_c9c6a615
#  define Rte_Read_Pp_SG_sigGrp00R0113D_A_b00r04_SigGroup_c74a02d7_De_SG_sigGrp00R0113D_A_b00r04_SigGroup_c74a02d7 Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R0113D_A_b00r04_SigGroup_c74a02d7_De_SG_sigGrp00R0113D_A_b00r04_SigGroup_c74a02d7
#  define Rte_Read_Pp_SG_sigGrp00R0114D_A_b02r04_SigGroup_4478dfdf_De_SG_sigGrp00R0114D_A_b02r04_SigGroup_4478dfdf Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R0114D_A_b02r04_SigGroup_4478dfdf_De_SG_sigGrp00R0114D_A_b02r04_SigGroup_4478dfdf
#  define Rte_Read_Pp_SG_sigGrp00R0235D_A_b00r01_SigGroup_0e64ce4a_De_SG_sigGrp00R0235D_A_b00r01_SigGroup_0e64ce4a Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R0235D_A_b00r01_SigGroup_0e64ce4a_De_SG_sigGrp00R0235D_A_b00r01_SigGroup_0e64ce4a
#  define Rte_Read_Pp_SG_sigGrp00R0236D_A_b00r01_SigGroup_9786a84b_De_SG_sigGrp00R0236D_A_b00r01_SigGroup_9786a84b Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00R0236D_A_b00r01_SigGroup_9786a84b_De_SG_sigGrp00R0236D_A_b00r01_SigGroup_9786a84b
#  define Rte_Read_Pp_SG_sigGrp00T040S_A_b03r04_SigGroup_cc337b5f_De_SG_sigGrp00T040S_A_b03r04_SigGroup_cc337b5f Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00T040S_A_b03r04_SigGroup_cc337b5f_De_SG_sigGrp00T040S_A_b03r04_SigGroup_cc337b5f
#  define Rte_Read_Pp_SG_sigGrp00_0x776_0a2bb6b7_De_SG_sigGrp00_0x776_0a2bb6b7 Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00_0x776_0a2bb6b7_De_SG_sigGrp00_0x776_0a2bb6b7
#  define Rte_Read_Pp_SG_sigGrp00_0x777_cba56977_De_SG_sigGrp00_0x777_cba56977 Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00_0x777_cba56977_De_SG_sigGrp00_0x777_cba56977
#  define Rte_Read_Pp_SG_sigGrp00_0x7A3_b00b3ee1_De_SG_sigGrp00_0x7A3_b00b3ee1 Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp00_0x7A3_b00b3ee1_De_SG_sigGrp00_0x7A3_b00b3ee1
#  define Rte_Read_Pp_SG_sigGrp01_0x776_0a2bb6b7_De_SG_sigGrp01_0x776_0a2bb6b7 Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp01_0x776_0a2bb6b7_De_SG_sigGrp01_0x776_0a2bb6b7
#  define Rte_Read_Pp_SG_sigGrp01_0x777_cba56977_De_SG_sigGrp01_0x777_cba56977 Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp01_0x777_cba56977_De_SG_sigGrp01_0x777_cba56977
#  define Rte_Read_Pp_SG_sigGrp01_0x7A1_e8678720_De_SG_sigGrp01_0x7A1_e8678720 Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp01_0x7A1_e8678720_De_SG_sigGrp01_0x7A1_e8678720
#  define Rte_Read_Pp_SG_sigGrp01_0x7A5_58bef4a2_De_SG_sigGrp01_0x7A5_58bef4a2 Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp01_0x7A5_58bef4a2_De_SG_sigGrp01_0x7A5_58bef4a2
#  define Rte_Read_Pp_SG_sigGrp02_0x7A3_b00b3ee1_De_SG_sigGrp02_0x7A3_b00b3ee1 Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp02_0x7A3_b00b3ee1_De_SG_sigGrp02_0x7A3_b00b3ee1
#  define Rte_Read_Pp_SG_sigGrp02_0x7A5_58bef4a2_De_SG_sigGrp02_0x7A5_58bef4a2 Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrp02_0x7A5_58bef4a2_De_SG_sigGrp02_0x7A5_58bef4a2
#  define Rte_Read_Pp_SG_sigGrpRx_0x231_IL_3ac9523b_De_SG_sigGrpRx_0x231_IL_3ac9523b Rte_Read_CtCdd_TgfTestApplication_Pp_SG_sigGrpRx_0x231_IL_3ac9523b_De_SG_sigGrpRx_0x231_IL_3ac9523b
#  define Rte_Read_Pps00R0100D_A_b01r08_Des00R0100D_A_b01r08 Rte_Read_CtCdd_TgfTestApplication_Pps00R0100D_A_b01r08_Des00R0100D_A_b01r08
#  define Rte_Read_Pps00R0118D_A_b01r08_Des00R0118D_A_b01r08 Rte_Read_CtCdd_TgfTestApplication_Pps00R0118D_A_b01r08_Des00R0118D_A_b01r08
#  define Rte_Read_Pps00R142D_A_b00r08_Des00R142D_A_b00r08 Rte_Read_CtCdd_TgfTestApplication_Pps00R142D_A_b00r08_Des00R142D_A_b00r08
#  define Rte_Read_Pps00R142D_A_b01r08_Des00R142D_A_b01r08 Rte_Read_CtCdd_TgfTestApplication_Pps00R142D_A_b01r08_Des00R142D_A_b01r08
#  define Rte_Read_Pps00T044S_A_b01r04_Des00T044S_A_b01r04 Rte_Read_CtCdd_TgfTestApplication_Pps00T044S_A_b01r04_Des00T044S_A_b01r04
#  define Rte_Read_Pps00T044S_A_b02r04_Des00T044S_A_b02r04 Rte_Read_CtCdd_TgfTestApplication_Pps00T044S_A_b02r04_Des00T044S_A_b02r04
#  define Rte_Read_Pps00T044S_A_b03r04_Des00T044S_A_b03r04 Rte_Read_CtCdd_TgfTestApplication_Pps00T044S_A_b03r04_Des00T044S_A_b03r04
#  define Rte_Read_Pps01R0100D_A_b01r08_Des01R0100D_A_b01r08 Rte_Read_CtCdd_TgfTestApplication_Pps01R0100D_A_b01r08_Des01R0100D_A_b01r08
#  define Rte_Read_Pps01R0118D_A_b01r08_Des01R0118D_A_b01r08 Rte_Read_CtCdd_TgfTestApplication_Pps01R0118D_A_b01r08_Des01R0118D_A_b01r08
#  define Rte_Read_Pps01R142D_A_b00r08_Des01R142D_A_b00r08 Rte_Read_CtCdd_TgfTestApplication_Pps01R142D_A_b00r08_Des01R142D_A_b00r08
#  define Rte_Read_Pps01R142D_A_b01r08_Des01R142D_A_b01r08 Rte_Read_CtCdd_TgfTestApplication_Pps01R142D_A_b01r08_Des01R142D_A_b01r08
#  define Rte_Read_Pps01T044S_A_b01r04_Des01T044S_A_b01r04 Rte_Read_CtCdd_TgfTestApplication_Pps01T044S_A_b01r04_Des01T044S_A_b01r04
#  define Rte_Read_Pps01T044S_A_b02r04_Des01T044S_A_b02r04 Rte_Read_CtCdd_TgfTestApplication_Pps01T044S_A_b02r04_Des01T044S_A_b02r04
#  define Rte_Read_Pps01T044S_A_b03r04_Des01T044S_A_b03r04 Rte_Read_CtCdd_TgfTestApplication_Pps01T044S_A_b03r04_Des01T044S_A_b03r04
#  define Rte_Read_Pps02R0100D_A_b01r08_Des02R0100D_A_b01r08 Rte_Read_CtCdd_TgfTestApplication_Pps02R0100D_A_b01r08_Des02R0100D_A_b01r08
#  define Rte_Read_Pps02R0118D_A_b01r08_Des02R0118D_A_b01r08 Rte_Read_CtCdd_TgfTestApplication_Pps02R0118D_A_b01r08_Des02R0118D_A_b01r08
#  define Rte_Read_Pps02R142D_A_b00r08_Des02R142D_A_b00r08 Rte_Read_CtCdd_TgfTestApplication_Pps02R142D_A_b00r08_Des02R142D_A_b00r08
#  define Rte_Read_Pps02R142D_A_b01r08_Des02R142D_A_b01r08 Rte_Read_CtCdd_TgfTestApplication_Pps02R142D_A_b01r08_Des02R142D_A_b01r08
#  define Rte_Read_Pps02T044S_A_b01r04_Des02T044S_A_b01r04 Rte_Read_CtCdd_TgfTestApplication_Pps02T044S_A_b01r04_Des02T044S_A_b01r04
#  define Rte_Read_Pps02T044S_A_b02r04_Des02T044S_A_b02r04 Rte_Read_CtCdd_TgfTestApplication_Pps02T044S_A_b02r04_Des02T044S_A_b02r04
#  define Rte_Read_Pps02T044S_A_b03r04_Des02T044S_A_b03r04 Rte_Read_CtCdd_TgfTestApplication_Pps02T044S_A_b03r04_Des02T044S_A_b03r04
#  define Rte_Read_Pps03R0100D_A_b01r08_Des03R0100D_A_b01r08 Rte_Read_CtCdd_TgfTestApplication_Pps03R0100D_A_b01r08_Des03R0100D_A_b01r08
#  define Rte_Read_Pps03R0118D_A_b01r08_Des03R0118D_A_b01r08 Rte_Read_CtCdd_TgfTestApplication_Pps03R0118D_A_b01r08_Des03R0118D_A_b01r08
#  define Rte_Read_Pps03T044S_A_b01r04_Des03T044S_A_b01r04 Rte_Read_CtCdd_TgfTestApplication_Pps03T044S_A_b01r04_Des03T044S_A_b01r04
#  define Rte_Read_Pps03T044S_A_b02r04_Des03T044S_A_b02r04 Rte_Read_CtCdd_TgfTestApplication_Pps03T044S_A_b02r04_Des03T044S_A_b02r04
#  define Rte_Read_Pps03T044S_A_b03r04_Des03T044S_A_b03r04 Rte_Read_CtCdd_TgfTestApplication_Pps03T044S_A_b03r04_Des03T044S_A_b03r04
#  define Rte_Read_Pps04R0118D_A_b01r08_Des04R0118D_A_b01r08 Rte_Read_CtCdd_TgfTestApplication_Pps04R0118D_A_b01r08_Des04R0118D_A_b01r08
#  define Rte_Read_Pps04T044S_A_b01r04_Des04T044S_A_b01r04 Rte_Read_CtCdd_TgfTestApplication_Pps04T044S_A_b01r04_Des04T044S_A_b01r04
#  define Rte_Read_Pps04T044S_A_b02r04_Des04T044S_A_b02r04 Rte_Read_CtCdd_TgfTestApplication_Pps04T044S_A_b02r04_Des04T044S_A_b02r04
#  define Rte_Read_Pps04T044S_A_b03r04_Des04T044S_A_b03r04 Rte_Read_CtCdd_TgfTestApplication_Pps04T044S_A_b03r04_Des04T044S_A_b03r04
#  define Rte_Read_Pps05R0118D_A_b01r08_Des05R0118D_A_b01r08 Rte_Read_CtCdd_TgfTestApplication_Pps05R0118D_A_b01r08_Des05R0118D_A_b01r08
#  define Rte_Read_Pps05T044S_A_b01r04_Des05T044S_A_b01r04 Rte_Read_CtCdd_TgfTestApplication_Pps05T044S_A_b01r04_Des05T044S_A_b01r04
#  define Rte_Read_Pps05T044S_A_b02r04_Des05T044S_A_b02r04 Rte_Read_CtCdd_TgfTestApplication_Pps05T044S_A_b02r04_Des05T044S_A_b02r04
#  define Rte_Read_Pps05T044S_A_b03r04_Des05T044S_A_b03r04 Rte_Read_CtCdd_TgfTestApplication_Pps05T044S_A_b03r04_Des05T044S_A_b03r04
#  define Rte_Read_Pps06R0100D_A_b01r08_Des06R0100D_A_b01r08 Rte_Read_CtCdd_TgfTestApplication_Pps06R0100D_A_b01r08_Des06R0100D_A_b01r08
#  define Rte_Read_Pps06R0118D_A_b01r08_Des06R0118D_A_b01r08 Rte_Read_CtCdd_TgfTestApplication_Pps06R0118D_A_b01r08_Des06R0118D_A_b01r08
#  define Rte_Read_Pps07R0100D_A_b01r08_Des07R0100D_A_b01r08 Rte_Read_CtCdd_TgfTestApplication_Pps07R0100D_A_b01r08_Des07R0100D_A_b01r08
#  define Rte_Read_Pps07R0118D_A_b01r08_Des07R0118D_A_b01r08 Rte_Read_CtCdd_TgfTestApplication_Pps07R0118D_A_b01r08_Des07R0118D_A_b01r08
#  define Rte_Read_Pps0R0010S_A_b00r04_IPDUM_DynSig_0_Des0R0010S_A_b00r04_IPDUM_DynSig_0 Rte_Read_CtCdd_TgfTestApplication_Pps0R0010S_A_b00r04_IPDUM_DynSig_0_Des0R0010S_A_b00r04_IPDUM_DynSig_0
#  define Rte_Read_Pps0R0010S_A_b01r04_IPDUM_DynSig_0_Des0R0010S_A_b01r04_IPDUM_DynSig_0 Rte_Read_CtCdd_TgfTestApplication_Pps0R0010S_A_b01r04_IPDUM_DynSig_0_Des0R0010S_A_b01r04_IPDUM_DynSig_0
#  define Rte_Read_Pps0R0010S_A_b01r04_IPDUM_DynSig_1_Des0R0010S_A_b01r04_IPDUM_DynSig_1 Rte_Read_CtCdd_TgfTestApplication_Pps0R0010S_A_b01r04_IPDUM_DynSig_1_Des0R0010S_A_b01r04_IPDUM_DynSig_1
#  define Rte_Read_Pps0R0010S_A_b01r04_IPDUM_DynSig_2_Des0R0010S_A_b01r04_IPDUM_DynSig_2 Rte_Read_CtCdd_TgfTestApplication_Pps0R0010S_A_b01r04_IPDUM_DynSig_2_Des0R0010S_A_b01r04_IPDUM_DynSig_2
#  define Rte_Read_Pps0R0010S_A_b01r04_IPDUM_DynSig_3_Des0R0010S_A_b01r04_IPDUM_DynSig_3 Rte_Read_CtCdd_TgfTestApplication_Pps0R0010S_A_b01r04_IPDUM_DynSig_3_Des0R0010S_A_b01r04_IPDUM_DynSig_3
#  define Rte_Read_Pps0R0010S_A_b02r04_IPDUM_DynSig_0_Des0R0010S_A_b02r04_IPDUM_DynSig_0 Rte_Read_CtCdd_TgfTestApplication_Pps0R0010S_A_b02r04_IPDUM_DynSig_0_Des0R0010S_A_b02r04_IPDUM_DynSig_0
#  define Rte_Read_Pps0R0010S_A_b03r04_IPDUM_DynSig_0_Des0R0010S_A_b03r04_IPDUM_DynSig_0 Rte_Read_CtCdd_TgfTestApplication_Pps0R0010S_A_b03r04_IPDUM_DynSig_0_Des0R0010S_A_b03r04_IPDUM_DynSig_0
#  define Rte_Read_Pps0R0010S_A_b03r04_IPDUM_DynSig_1_Des0R0010S_A_b03r04_IPDUM_DynSig_1 Rte_Read_CtCdd_TgfTestApplication_Pps0R0010S_A_b03r04_IPDUM_DynSig_1_Des0R0010S_A_b03r04_IPDUM_DynSig_1
#  define Rte_Read_Pps0R0010S_A_b03r04_IPDUM_DynSig_2_Des0R0010S_A_b03r04_IPDUM_DynSig_2 Rte_Read_CtCdd_TgfTestApplication_Pps0R0010S_A_b03r04_IPDUM_DynSig_2_Des0R0010S_A_b03r04_IPDUM_DynSig_2
#  define Rte_Read_Pps0R0010S_A_b03r04_IPDUM_DynSig_3_Des0R0010S_A_b03r04_IPDUM_DynSig_3 Rte_Read_CtCdd_TgfTestApplication_Pps0R0010S_A_b03r04_IPDUM_DynSig_3_Des0R0010S_A_b03r04_IPDUM_DynSig_3
#  define Rte_Read_Pps0_p00R041S_A_b00r04_Des0_p00R041S_A_b00r04 Rte_Read_CtCdd_TgfTestApplication_Pps0_p00R041S_A_b00r04_Des0_p00R041S_A_b00r04
#  define Rte_Read_Pps0_p00R041S_A_b01r04_Des0_p00R041S_A_b01r04 Rte_Read_CtCdd_TgfTestApplication_Pps0_p00R041S_A_b01r04_Des0_p00R041S_A_b01r04
#  define Rte_Read_Pps0_p01R041S_A_b00r04_Des0_p01R041S_A_b00r04 Rte_Read_CtCdd_TgfTestApplication_Pps0_p01R041S_A_b00r04_Des0_p01R041S_A_b00r04
#  define Rte_Read_Pps10_p00R041S_A_b01r04_Des10_p00R041S_A_b01r04 Rte_Read_CtCdd_TgfTestApplication_Pps10_p00R041S_A_b01r04_Des10_p00R041S_A_b01r04
#  define Rte_Read_Pps11_p00R041S_A_b01r04_Des11_p00R041S_A_b01r04 Rte_Read_CtCdd_TgfTestApplication_Pps11_p00R041S_A_b01r04_Des11_p00R041S_A_b01r04
#  define Rte_Read_Pps12_p00R041S_A_b01r04_Des12_p00R041S_A_b01r04 Rte_Read_CtCdd_TgfTestApplication_Pps12_p00R041S_A_b01r04_Des12_p00R041S_A_b01r04
#  define Rte_Read_Pps13_p00R041S_A_b01r04_Des13_p00R041S_A_b01r04 Rte_Read_CtCdd_TgfTestApplication_Pps13_p00R041S_A_b01r04_Des13_p00R041S_A_b01r04
#  define Rte_Read_Pps1R0010S_A_b00r04_IPDUM_DynSig_0_Des1R0010S_A_b00r04_IPDUM_DynSig_0 Rte_Read_CtCdd_TgfTestApplication_Pps1R0010S_A_b00r04_IPDUM_DynSig_0_Des1R0010S_A_b00r04_IPDUM_DynSig_0
#  define Rte_Read_Pps1R0010S_A_b01r04_IPDUM_DynSig_0_Des1R0010S_A_b01r04_IPDUM_DynSig_0 Rte_Read_CtCdd_TgfTestApplication_Pps1R0010S_A_b01r04_IPDUM_DynSig_0_Des1R0010S_A_b01r04_IPDUM_DynSig_0
#  define Rte_Read_Pps1R0010S_A_b01r04_IPDUM_DynSig_1_Des1R0010S_A_b01r04_IPDUM_DynSig_1 Rte_Read_CtCdd_TgfTestApplication_Pps1R0010S_A_b01r04_IPDUM_DynSig_1_Des1R0010S_A_b01r04_IPDUM_DynSig_1
#  define Rte_Read_Pps1R0010S_A_b01r04_IPDUM_DynSig_2_Des1R0010S_A_b01r04_IPDUM_DynSig_2 Rte_Read_CtCdd_TgfTestApplication_Pps1R0010S_A_b01r04_IPDUM_DynSig_2_Des1R0010S_A_b01r04_IPDUM_DynSig_2
#  define Rte_Read_Pps1R0010S_A_b01r04_IPDUM_DynSig_3_Des1R0010S_A_b01r04_IPDUM_DynSig_3 Rte_Read_CtCdd_TgfTestApplication_Pps1R0010S_A_b01r04_IPDUM_DynSig_3_Des1R0010S_A_b01r04_IPDUM_DynSig_3
#  define Rte_Read_Pps1R0010S_A_b02r04_IPDUM_DynSig_0_Des1R0010S_A_b02r04_IPDUM_DynSig_0 Rte_Read_CtCdd_TgfTestApplication_Pps1R0010S_A_b02r04_IPDUM_DynSig_0_Des1R0010S_A_b02r04_IPDUM_DynSig_0
#  define Rte_Read_Pps1R0010S_A_b03r04_IPDUM_DynSig_0_Des1R0010S_A_b03r04_IPDUM_DynSig_0 Rte_Read_CtCdd_TgfTestApplication_Pps1R0010S_A_b03r04_IPDUM_DynSig_0_Des1R0010S_A_b03r04_IPDUM_DynSig_0
#  define Rte_Read_Pps1R0010S_A_b03r04_IPDUM_DynSig_1_Des1R0010S_A_b03r04_IPDUM_DynSig_1 Rte_Read_CtCdd_TgfTestApplication_Pps1R0010S_A_b03r04_IPDUM_DynSig_1_Des1R0010S_A_b03r04_IPDUM_DynSig_1
#  define Rte_Read_Pps1R0010S_A_b03r04_IPDUM_DynSig_2_Des1R0010S_A_b03r04_IPDUM_DynSig_2 Rte_Read_CtCdd_TgfTestApplication_Pps1R0010S_A_b03r04_IPDUM_DynSig_2_Des1R0010S_A_b03r04_IPDUM_DynSig_2
#  define Rte_Read_Pps1R0010S_A_b03r04_IPDUM_DynSig_3_Des1R0010S_A_b03r04_IPDUM_DynSig_3 Rte_Read_CtCdd_TgfTestApplication_Pps1R0010S_A_b03r04_IPDUM_DynSig_3_Des1R0010S_A_b03r04_IPDUM_DynSig_3
#  define Rte_Read_Pps1_p00R041S_A_b00r04_Des1_p00R041S_A_b00r04 Rte_Read_CtCdd_TgfTestApplication_Pps1_p00R041S_A_b00r04_Des1_p00R041S_A_b00r04
#  define Rte_Read_Pps1_p00R041S_A_b01r04_Des1_p00R041S_A_b01r04 Rte_Read_CtCdd_TgfTestApplication_Pps1_p00R041S_A_b01r04_Des1_p00R041S_A_b01r04
#  define Rte_Read_Pps1_p01R041S_A_b00r04_Des1_p01R041S_A_b00r04 Rte_Read_CtCdd_TgfTestApplication_Pps1_p01R041S_A_b00r04_Des1_p01R041S_A_b00r04
#  define Rte_Read_Pps2_p00R041S_A_b00r04_Des2_p00R041S_A_b00r04 Rte_Read_CtCdd_TgfTestApplication_Pps2_p00R041S_A_b00r04_Des2_p00R041S_A_b00r04
#  define Rte_Read_Pps2_p00R041S_A_b01r04_Des2_p00R041S_A_b01r04 Rte_Read_CtCdd_TgfTestApplication_Pps2_p00R041S_A_b01r04_Des2_p00R041S_A_b01r04
#  define Rte_Read_Pps2_p01R041S_A_b00r04_Des2_p01R041S_A_b00r04 Rte_Read_CtCdd_TgfTestApplication_Pps2_p01R041S_A_b00r04_Des2_p01R041S_A_b00r04
#  define Rte_Read_Pps3_p00R041S_A_b00r04_Des3_p00R041S_A_b00r04 Rte_Read_CtCdd_TgfTestApplication_Pps3_p00R041S_A_b00r04_Des3_p00R041S_A_b00r04
#  define Rte_Read_Pps3_p00R041S_A_b01r04_Des3_p00R041S_A_b01r04 Rte_Read_CtCdd_TgfTestApplication_Pps3_p00R041S_A_b01r04_Des3_p00R041S_A_b01r04
#  define Rte_Read_Pps3_p01R041S_A_b00r04_Des3_p01R041S_A_b00r04 Rte_Read_CtCdd_TgfTestApplication_Pps3_p01R041S_A_b00r04_Des3_p01R041S_A_b00r04
#  define Rte_Read_Pps4_p00R041S_A_b00r04_Des4_p00R041S_A_b00r04 Rte_Read_CtCdd_TgfTestApplication_Pps4_p00R041S_A_b00r04_Des4_p00R041S_A_b00r04
#  define Rte_Read_Pps4_p00R041S_A_b01r04_Des4_p00R041S_A_b01r04 Rte_Read_CtCdd_TgfTestApplication_Pps4_p00R041S_A_b01r04_Des4_p00R041S_A_b01r04
#  define Rte_Read_Pps4_p01R041S_A_b00r04_Des4_p01R041S_A_b00r04 Rte_Read_CtCdd_TgfTestApplication_Pps4_p01R041S_A_b00r04_Des4_p01R041S_A_b00r04
#  define Rte_Read_Pps5_p00R041S_A_b01r04_Des5_p00R041S_A_b01r04 Rte_Read_CtCdd_TgfTestApplication_Pps5_p00R041S_A_b01r04_Des5_p00R041S_A_b01r04
#  define Rte_Read_Pps6_p00R041S_A_b01r04_Des6_p00R041S_A_b01r04 Rte_Read_CtCdd_TgfTestApplication_Pps6_p00R041S_A_b01r04_Des6_p00R041S_A_b01r04
#  define Rte_Read_Pps7_p00R041S_A_b01r04_Des7_p00R041S_A_b01r04 Rte_Read_CtCdd_TgfTestApplication_Pps7_p00R041S_A_b01r04_Des7_p00R041S_A_b01r04
#  define Rte_Read_Pps8_p00R041S_A_b01r04_Des8_p00R041S_A_b01r04 Rte_Read_CtCdd_TgfTestApplication_Pps8_p00R041S_A_b01r04_Des8_p00R041S_A_b01r04
#  define Rte_Read_Pps9_p00R041S_A_b01r04_Des9_p00R041S_A_b01r04 Rte_Read_CtCdd_TgfTestApplication_Pps9_p00R041S_A_b01r04_Des9_p00R041S_A_b01r04
#  define Rte_Read_PpsR00108D_A_b00r04_DesR00108D_A_b00r04 Rte_Read_CtCdd_TgfTestApplication_PpsR00108D_A_b00r04_DesR00108D_A_b00r04
#  define Rte_Read_PpsR00108D_A_b02r04_DesR00108D_A_b02r04 Rte_Read_CtCdd_TgfTestApplication_PpsR00108D_A_b02r04_DesR00108D_A_b02r04
#  define Rte_Read_PpsR00109D_A_b00r04_DesR00109D_A_b00r04 Rte_Read_CtCdd_TgfTestApplication_PpsR00109D_A_b00r04_DesR00109D_A_b00r04
#  define Rte_Read_PpsR00109D_A_b02r04_DesR00109D_A_b02r04 Rte_Read_CtCdd_TgfTestApplication_PpsR00109D_A_b02r04_DesR00109D_A_b02r04
#  define Rte_Read_PpsR00110D_A_b00r04_DesR00110D_A_b00r04 Rte_Read_CtCdd_TgfTestApplication_PpsR00110D_A_b00r04_DesR00110D_A_b00r04
#  define Rte_Read_PpsR00110D_A_b02r04_DesR00110D_A_b02r04 Rte_Read_CtCdd_TgfTestApplication_PpsR00110D_A_b02r04_DesR00110D_A_b02r04
#  define Rte_Read_PpsR0112D_A_b03r04_DesR0112D_A_b03r04 Rte_Read_CtCdd_TgfTestApplication_PpsR0112D_A_b03r04_DesR0112D_A_b03r04
#  define Rte_Read_PpsR0114D_A_b01r04_DesR0114D_A_b01r04 Rte_Read_CtCdd_TgfTestApplication_PpsR0114D_A_b01r04_DesR0114D_A_b01r04
#  define Rte_Read_Pps_cnt_p00R041S_A_b00r04_Des_cnt_p00R041S_A_b00r04 Rte_Read_CtCdd_TgfTestApplication_Pps_cnt_p00R041S_A_b00r04_Des_cnt_p00R041S_A_b00r04
#  define Rte_Read_Pps_cnt_p00R041S_A_b01r04_Des_cnt_p00R041S_A_b01r04 Rte_Read_CtCdd_TgfTestApplication_Pps_cnt_p00R041S_A_b01r04_Des_cnt_p00R041S_A_b01r04
#  define Rte_Read_Pps_cnt_p01R041S_A_b00r04_Des_cnt_p01R041S_A_b00r04 Rte_Read_CtCdd_TgfTestApplication_Pps_cnt_p01R041S_A_b00r04_Des_cnt_p01R041S_A_b00r04
#  define Rte_Read_Pps_crc_p00R041S_A_b00r04_Des_crc_p00R041S_A_b00r04 Rte_Read_CtCdd_TgfTestApplication_Pps_crc_p00R041S_A_b00r04_Des_crc_p00R041S_A_b00r04
#  define Rte_Read_Pps_crc_p00R041S_A_b01r04_Des_crc_p00R041S_A_b01r04 Rte_Read_CtCdd_TgfTestApplication_Pps_crc_p00R041S_A_b01r04_Des_crc_p00R041S_A_b01r04
#  define Rte_Read_Pps_crc_p01R041S_A_b00r04_Des_crc_p01R041S_A_b00r04 Rte_Read_CtCdd_TgfTestApplication_Pps_crc_p01R041S_A_b00r04_Des_crc_p01R041S_A_b00r04
#  define Rte_Read_Ppsig00Rx_0x21C_IL_Desig00Rx_0x21C_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig00Rx_0x21C_IL_Desig00Rx_0x21C_IL
#  define Rte_Read_Ppsig00Rx_0x21E_IL_Desig00Rx_0x21E_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig00Rx_0x21E_IL_Desig00Rx_0x21E_IL
#  define Rte_Read_Ppsig00Rx_0x220_IL_Desig00Rx_0x220_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig00Rx_0x220_IL_Desig00Rx_0x220_IL
#  define Rte_Read_Ppsig00Rx_0x222_IL_Desig00Rx_0x222_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig00Rx_0x222_IL_Desig00Rx_0x222_IL
#  define Rte_Read_Ppsig00Rx_0x224_IL_Desig00Rx_0x224_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig00Rx_0x224_IL_Desig00Rx_0x224_IL
#  define Rte_Read_Ppsig00Rx_0x226_IL_Desig00Rx_0x226_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig00Rx_0x226_IL_Desig00Rx_0x226_IL
#  define Rte_Read_Ppsig00Rx_0x229_IL_Desig00Rx_0x229_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig00Rx_0x229_IL_Desig00Rx_0x229_IL
#  define Rte_Read_Ppsig00Rx_0x230_IL_Desig00Rx_0x230_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig00Rx_0x230_IL_Desig00Rx_0x230_IL
#  define Rte_Read_Ppsig00Rx_0x3EB_IL_Desig00Rx_0x3EB_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig00Rx_0x3EB_IL_Desig00Rx_0x3EB_IL
#  define Rte_Read_Ppsig00Rx_0x758_IL_Desig00Rx_0x758_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig00Rx_0x758_IL_Desig00Rx_0x758_IL
#  define Rte_Read_Ppsig00Rx_0x768_IL_Desig00Rx_0x768_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig00Rx_0x768_IL_Desig00Rx_0x768_IL
#  define Rte_Read_Ppsig00Rx_0x770_IL_Desig00Rx_0x770_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig00Rx_0x770_IL_Desig00Rx_0x770_IL
#  define Rte_Read_Ppsig00_0x776_Desig00_0x776 Rte_Read_CtCdd_TgfTestApplication_Ppsig00_0x776_Desig00_0x776
#  define Rte_Read_Ppsig00_0x777_Desig00_0x777 Rte_Read_CtCdd_TgfTestApplication_Ppsig00_0x777_Desig00_0x777
#  define Rte_Read_Ppsig00_0x780_Desig00_0x780 Rte_Read_CtCdd_TgfTestApplication_Ppsig00_0x780_Desig00_0x780
#  define Rte_Read_Ppsig00_0x7A1_Desig00_0x7A1 Rte_Read_CtCdd_TgfTestApplication_Ppsig00_0x7A1_Desig00_0x7A1
#  define Rte_Read_Ppsig00_0x7A3_Desig00_0x7A3 Rte_Read_CtCdd_TgfTestApplication_Ppsig00_0x7A3_Desig00_0x7A3
#  define Rte_Read_Ppsig00_Rx_0x22D_IL_Desig00_Rx_0x22D_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig00_Rx_0x22D_IL_Desig00_Rx_0x22D_IL
#  define Rte_Read_Ppsig01Rx_0x229_IL_Desig01Rx_0x229_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig01Rx_0x229_IL_Desig01Rx_0x229_IL
#  define Rte_Read_Ppsig01Rx_0x230_IL_Desig01Rx_0x230_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig01Rx_0x230_IL_Desig01Rx_0x230_IL
#  define Rte_Read_Ppsig01Rx_0x4C1_IL_Desig01Rx_0x4C1_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig01Rx_0x4C1_IL_Desig01Rx_0x4C1_IL
#  define Rte_Read_Ppsig01Rx_0x758_IL_Desig01Rx_0x758_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig01Rx_0x758_IL_Desig01Rx_0x758_IL
#  define Rte_Read_Ppsig01Rx_0x768_IL_Desig01Rx_0x768_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig01Rx_0x768_IL_Desig01Rx_0x768_IL
#  define Rte_Read_Ppsig01Rx_0x770_IL_Desig01Rx_0x770_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig01Rx_0x770_IL_Desig01Rx_0x770_IL
#  define Rte_Read_Ppsig01Rx_0x773_IL_Desig01Rx_0x773_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig01Rx_0x773_IL_Desig01Rx_0x773_IL
#  define Rte_Read_Ppsig01Rx_0x775_IL_Desig01Rx_0x775_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig01Rx_0x775_IL_Desig01Rx_0x775_IL
#  define Rte_Read_Ppsig01_0x776_Desig01_0x776 Rte_Read_CtCdd_TgfTestApplication_Ppsig01_0x776_Desig01_0x776
#  define Rte_Read_Ppsig01_0x777_Desig01_0x777 Rte_Read_CtCdd_TgfTestApplication_Ppsig01_0x777_Desig01_0x777
#  define Rte_Read_Ppsig01_0x780_Desig01_0x780 Rte_Read_CtCdd_TgfTestApplication_Ppsig01_0x780_Desig01_0x780
#  define Rte_Read_Ppsig01_0x7A1_Desig01_0x7A1 Rte_Read_CtCdd_TgfTestApplication_Ppsig01_0x7A1_Desig01_0x7A1
#  define Rte_Read_Ppsig01_0x7A3_Desig01_0x7A3 Rte_Read_CtCdd_TgfTestApplication_Ppsig01_0x7A3_Desig01_0x7A3
#  define Rte_Read_Ppsig02Rx_0x229_IL_Desig02Rx_0x229_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig02Rx_0x229_IL_Desig02Rx_0x229_IL
#  define Rte_Read_Ppsig02Rx_0x230_IL_Desig02Rx_0x230_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig02Rx_0x230_IL_Desig02Rx_0x230_IL
#  define Rte_Read_Ppsig02Rx_0x768_IL_Desig02Rx_0x768_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig02Rx_0x768_IL_Desig02Rx_0x768_IL
#  define Rte_Read_Ppsig02Rx_0x770_IL_Desig02Rx_0x770_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig02Rx_0x770_IL_Desig02Rx_0x770_IL
#  define Rte_Read_Ppsig02Rx_0x773_IL_Desig02Rx_0x773_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig02Rx_0x773_IL_Desig02Rx_0x773_IL
#  define Rte_Read_Ppsig02Rx_0x775_IL_Desig02Rx_0x775_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig02Rx_0x775_IL_Desig02Rx_0x775_IL
#  define Rte_Read_Ppsig02_0x780_Desig02_0x780 Rte_Read_CtCdd_TgfTestApplication_Ppsig02_0x780_Desig02_0x780
#  define Rte_Read_Ppsig02_0x7A3_Desig02_0x7A3 Rte_Read_CtCdd_TgfTestApplication_Ppsig02_0x7A3_Desig02_0x7A3
#  define Rte_Read_Ppsig03Rx_0x229_IL_Desig03Rx_0x229_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig03Rx_0x229_IL_Desig03Rx_0x229_IL
#  define Rte_Read_Ppsig03Rx_0x230_IL_Desig03Rx_0x230_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig03Rx_0x230_IL_Desig03Rx_0x230_IL
#  define Rte_Read_Ppsig03_0x780_Desig03_0x780 Rte_Read_CtCdd_TgfTestApplication_Ppsig03_0x780_Desig03_0x780
#  define Rte_Read_Ppsig12Rx_0x766_IL_Desig12Rx_0x766_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig12Rx_0x766_IL_Desig12Rx_0x766_IL
#  define Rte_Read_Ppsig20Rx_0x766_IL_Desig20Rx_0x766_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig20Rx_0x766_IL_Desig20Rx_0x766_IL
#  define Rte_Read_Ppsig21Rx_0x766_IL_Desig21Rx_0x766_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig21Rx_0x766_IL_Desig21Rx_0x766_IL
#  define Rte_Read_Ppsig22Rx_0x766_IL_Desig22Rx_0x766_IL Rte_Read_CtCdd_TgfTestApplication_Ppsig22Rx_0x766_IL_Desig22Rx_0x766_IL


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_PpCanRPGSig_1_DeCanRPGSig_1 Rte_Write_CtCdd_TgfTestApplication_PpCanRPGSig_1_DeCanRPGSig_1
#  define Rte_Write_PpCanRPGSig_2_DeCanRPGSig_2 Rte_Write_CtCdd_TgfTestApplication_PpCanRPGSig_2_DeCanRPGSig_2
#  define Rte_Write_PpCanRPGSig_3_DeCanRPGSig_3 Rte_Write_CtCdd_TgfTestApplication_PpCanRPGSig_3_DeCanRPGSig_3
#  define Rte_Write_PpCanRPGSig_4_DeCanRPGSig_4 Rte_Write_CtCdd_TgfTestApplication_PpCanRPGSig_4_DeCanRPGSig_4
#  define Rte_Write_PpCanRPGSig_5_DeCanRPGSig_5 Rte_Write_CtCdd_TgfTestApplication_PpCanRPGSig_5_DeCanRPGSig_5
#  define Rte_Write_PpComCanSig_16bit_1_DeComCanSig_16bit_1 Rte_Write_CtCdd_TgfTestApplication_PpComCanSig_16bit_1_DeComCanSig_16bit_1
#  define Rte_Write_PpGwCanSig_8Bit_1_DeGwCanSig_8Bit_1 Rte_Write_CtCdd_TgfTestApplication_PpGwCanSig_8Bit_1_DeGwCanSig_8Bit_1
#  define Rte_Write_PpGwCanSig_8Bit_2_DeGwCanSig_8Bit_2 Rte_Write_CtCdd_TgfTestApplication_PpGwCanSig_8Bit_2_DeGwCanSig_8Bit_2
#  define Rte_Write_PpSig00Tx_0x3EE_IL_DeSig00Tx_0x3EE_IL Rte_Write_CtCdd_TgfTestApplication_PpSig00Tx_0x3EE_IL_DeSig00Tx_0x3EE_IL
#  define Rte_Write_PpSig00Tx_0x756_DeSig00Tx_0x756 Rte_Write_CtCdd_TgfTestApplication_PpSig00Tx_0x756_DeSig00Tx_0x756
#  define Rte_Write_PpSig_16Bit_20_DeSig_16Bit_20 Rte_Write_CtCdd_TgfTestApplication_PpSig_16Bit_20_DeSig_16Bit_20
#  define Rte_Write_PpSig_16Bit_23_DeSig_16Bit_23 Rte_Write_CtCdd_TgfTestApplication_PpSig_16Bit_23_DeSig_16Bit_23
#  define Rte_Write_PpSig_16bit_10_DeSig_16bit_10 Rte_Write_CtCdd_TgfTestApplication_PpSig_16bit_10_DeSig_16bit_10
#  define Rte_Write_PpSig_16bit_11_DeSig_16bit_11 Rte_Write_CtCdd_TgfTestApplication_PpSig_16bit_11_DeSig_16bit_11
#  define Rte_Write_PpSig_16bit_16_DeSig_16bit_16 Rte_Write_CtCdd_TgfTestApplication_PpSig_16bit_16_DeSig_16bit_16
#  define Rte_Write_PpSig_16bit_9_DeSig_16bit_9 Rte_Write_CtCdd_TgfTestApplication_PpSig_16bit_9_DeSig_16bit_9
#  define Rte_Write_PpSig_32Bit_3_DeSig_32Bit_3 Rte_Write_CtCdd_TgfTestApplication_PpSig_32Bit_3_DeSig_32Bit_3
#  define Rte_Write_PpSig_8Bit_11_DeSig_8Bit_11 Rte_Write_CtCdd_TgfTestApplication_PpSig_8Bit_11_DeSig_8Bit_11
#  define Rte_Write_PpSig_8Bit_20_DeSig_8Bit_20 Rte_Write_CtCdd_TgfTestApplication_PpSig_8Bit_20_DeSig_8Bit_20
#  define Rte_Write_PpSig_8Bit_21_DeSig_8Bit_21 Rte_Write_CtCdd_TgfTestApplication_PpSig_8Bit_21_DeSig_8Bit_21
#  define Rte_Write_PpSig_8Bit_22_DeSig_8Bit_22 Rte_Write_CtCdd_TgfTestApplication_PpSig_8Bit_22_DeSig_8Bit_22
#  define Rte_Write_PpSig_8bit_10_DeSig_8bit_10 Rte_Write_CtCdd_TgfTestApplication_PpSig_8bit_10_DeSig_8bit_10
#  define Rte_Write_PpSig_Bool_3_DeSig_Bool_3 Rte_Write_CtCdd_TgfTestApplication_PpSig_Bool_3_DeSig_Bool_3
#  define Rte_Write_PpSig_Cdd_1_DeSig_Cdd_1 Rte_Write_CtCdd_TgfTestApplication_PpSig_Cdd_1_DeSig_Cdd_1
#  define Rte_Write_PpSig_Cdd_8Bit_2_DeSig_Cdd_8Bit_2 Rte_Write_CtCdd_TgfTestApplication_PpSig_Cdd_8Bit_2_DeSig_Cdd_8Bit_2
#  define Rte_Write_Pp_SG_CanComGrpSig_14_b40ca185_De_SG_CanComGrpSig_14_b40ca185 Rte_Write_CtCdd_TgfTestApplication_Pp_SG_CanComGrpSig_14_b40ca185_De_SG_CanComGrpSig_14_b40ca185
#  define Rte_Write_Pp_SG_CanComGrpSig_15_75827e45_De_SG_CanComGrpSig_15_75827e45 Rte_Write_CtCdd_TgfTestApplication_Pp_SG_CanComGrpSig_15_75827e45_De_SG_CanComGrpSig_15_75827e45
#  define Rte_Write_Pp_SG_sigGrp00T00121D_A_b00r01_SigGroup_3d027919_De_SG_sigGrp00T00121D_A_b00r01_SigGroup_3d027919 Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00T00121D_A_b00r01_SigGroup_3d027919_De_SG_sigGrp00T00121D_A_b00r01_SigGroup_3d027919
#  define Rte_Write_Pp_SG_sigGrp00T00125D_A_b00r01_SigGroup_8ddb0a9b_De_SG_sigGrp00T00125D_A_b00r01_SigGroup_8ddb0a9b Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00T00125D_A_b00r01_SigGroup_8ddb0a9b_De_SG_sigGrp00T00125D_A_b00r01_SigGroup_8ddb0a9b
#  define Rte_Write_Pp_SG_sigGrp00T00127D_A_b00r01_SigGroup_d5b7b35a_De_SG_sigGrp00T00127D_A_b00r01_SigGroup_d5b7b35a Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00T00127D_A_b00r01_SigGroup_d5b7b35a_De_SG_sigGrp00T00127D_A_b00r01_SigGroup_d5b7b35a
#  define Rte_Write_Pp_SG_sigGrp00T00131D_A_b00r01_SigGroup_a6a73576_De_SG_sigGrp00T00131D_A_b00r01_SigGroup_a6a73576 Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00T00131D_A_b00r01_SigGroup_a6a73576_De_SG_sigGrp00T00131D_A_b00r01_SigGroup_a6a73576
#  define Rte_Write_Pp_SG_sigGrp00T0118D_A_b03r08_SigGroup_dd92b2a4_De_SG_sigGrp00T0118D_A_b03r08_SigGroup_dd92b2a4 Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00T0118D_A_b03r08_SigGroup_dd92b2a4_De_SG_sigGrp00T0118D_A_b03r08_SigGroup_dd92b2a4
#  define Rte_Write_Pp_SG_sigGrp00T0118D_A_b04r08_SigGroup_40458a1d_De_SG_sigGrp00T0118D_A_b04r08_SigGroup_40458a1d Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00T0118D_A_b04r08_SigGroup_40458a1d_De_SG_sigGrp00T0118D_A_b04r08_SigGroup_40458a1d
#  define Rte_Write_Pp_SG_sigGrp00T094D_A_b00r08_SigGroup_3c347067_De_SG_sigGrp00T094D_A_b00r08_SigGroup_3c347067 Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00T094D_A_b00r08_SigGroup_3c347067_De_SG_sigGrp00T094D_A_b00r08_SigGroup_3c347067
#  define Rte_Write_Pp_SG_sigGrp00T094D_A_b01r08_SigGroup_84881702_De_SG_sigGrp00T094D_A_b01r08_SigGroup_84881702 Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00T094D_A_b01r08_SigGroup_84881702_De_SG_sigGrp00T094D_A_b01r08_SigGroup_84881702
#  define Rte_Write_Pp_SG_sigGrp00T094D_A_b02r08_SigGroup_963db8ec_De_SG_sigGrp00T094D_A_b02r08_SigGroup_963db8ec Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00T094D_A_b02r08_SigGroup_963db8ec_De_SG_sigGrp00T094D_A_b02r08_SigGroup_963db8ec
#  define Rte_Write_Pp_SG_sigGrp00T094D_A_b03r08_SigGroup_2e81df89_De_SG_sigGrp00T094D_A_b03r08_SigGroup_2e81df89 Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00T094D_A_b03r08_SigGroup_2e81df89_De_SG_sigGrp00T094D_A_b03r08_SigGroup_2e81df89
#  define Rte_Write_Pp_SG_sigGrp00T094D_A_b04r08_SigGroup_b356e730_De_SG_sigGrp00T094D_A_b04r08_SigGroup_b356e730 Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00T094D_A_b04r08_SigGroup_b356e730_De_SG_sigGrp00T094D_A_b04r08_SigGroup_b356e730
#  define Rte_Write_Pp_SG_sigGrp00_0x7A0_29e958e0_De_SG_sigGrp00_0x7A0_29e958e0 Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00_0x7A0_29e958e0_De_SG_sigGrp00_0x7A0_29e958e0
#  define Rte_Write_Pp_SG_sigGrp00_0x7A4_ee371bf4_De_SG_sigGrp00_0x7A4_ee371bf4 Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp00_0x7A4_ee371bf4_De_SG_sigGrp00_0x7A4_ee371bf4
#  define Rte_Write_Pp_SG_sigGrp01T0118D_A_b03r08_SigGroup_73fa2335_De_SG_sigGrp01T0118D_A_b03r08_SigGroup_73fa2335 Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp01T0118D_A_b03r08_SigGroup_73fa2335_De_SG_sigGrp01T0118D_A_b03r08_SigGroup_73fa2335
#  define Rte_Write_Pp_SG_sigGrp01T0118D_A_b04r08_SigGroup_ee2d1b8c_De_SG_sigGrp01T0118D_A_b04r08_SigGroup_ee2d1b8c Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp01T0118D_A_b04r08_SigGroup_ee2d1b8c_De_SG_sigGrp01T0118D_A_b04r08_SigGroup_ee2d1b8c
#  define Rte_Write_Pp_SG_sigGrp01_0x7A0_29e958e0_De_SG_sigGrp01_0x7A0_29e958e0 Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp01_0x7A0_29e958e0_De_SG_sigGrp01_0x7A0_29e958e0
#  define Rte_Write_Pp_SG_sigGrp01_0x7A2_0682d1b7_De_SG_sigGrp01_0x7A2_0682d1b7 Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp01_0x7A2_0682d1b7_De_SG_sigGrp01_0x7A2_0682d1b7
#  define Rte_Write_Pp_SG_sigGrp01_0x7A4_ee371bf4_De_SG_sigGrp01_0x7A4_ee371bf4 Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp01_0x7A4_ee371bf4_De_SG_sigGrp01_0x7A4_ee371bf4
#  define Rte_Write_Pp_SG_sigGrp02T0118D_A_b03r08_SigGroup_5a3297c7_De_SG_sigGrp02T0118D_A_b03r08_SigGroup_5a3297c7 Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp02T0118D_A_b03r08_SigGroup_5a3297c7_De_SG_sigGrp02T0118D_A_b03r08_SigGroup_5a3297c7
#  define Rte_Write_Pp_SG_sigGrp02T0118D_A_b04r08_SigGroup_c7e5af7e_De_SG_sigGrp02T0118D_A_b04r08_SigGroup_c7e5af7e Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp02T0118D_A_b04r08_SigGroup_c7e5af7e_De_SG_sigGrp02T0118D_A_b04r08_SigGroup_c7e5af7e
#  define Rte_Write_Pp_SG_sigGrp02_0x7A0_29e958e0_De_SG_sigGrp02_0x7A0_29e958e0 Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp02_0x7A0_29e958e0_De_SG_sigGrp02_0x7A0_29e958e0
#  define Rte_Write_Pp_SG_sigGrp02_0x7A4_ee371bf4_De_SG_sigGrp02_0x7A4_ee371bf4 Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp02_0x7A4_ee371bf4_De_SG_sigGrp02_0x7A4_ee371bf4
#  define Rte_Write_Pp_SG_sigGrp03T0118D_A_b03r08_SigGroup_f45a0656_De_SG_sigGrp03T0118D_A_b03r08_SigGroup_f45a0656 Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp03T0118D_A_b03r08_SigGroup_f45a0656_De_SG_sigGrp03T0118D_A_b03r08_SigGroup_f45a0656
#  define Rte_Write_Pp_SG_sigGrp03T0118D_A_b04r08_SigGroup_698d3eef_De_SG_sigGrp03T0118D_A_b04r08_SigGroup_698d3eef Rte_Write_CtCdd_TgfTestApplication_Pp_SG_sigGrp03T0118D_A_b04r08_SigGroup_698d3eef_De_SG_sigGrp03T0118D_A_b04r08_SigGroup_698d3eef
#  define Rte_Write_Pps00T0118D_A_b06r08_Des00T0118D_A_b06r08 Rte_Write_CtCdd_TgfTestApplication_Pps00T0118D_A_b06r08_Des00T0118D_A_b06r08
#  define Rte_Write_Pps01T0118D_A_b06r08_Des01T0118D_A_b06r08 Rte_Write_CtCdd_TgfTestApplication_Pps01T0118D_A_b06r08_Des01T0118D_A_b06r08
#  define Rte_Write_Pps01T028S_A_b00r08_Des01T028S_A_b00r08 Rte_Write_CtCdd_TgfTestApplication_Pps01T028S_A_b00r08_Des01T028S_A_b00r08
#  define Rte_Write_Pps02T0118D_A_b06r08_Des02T0118D_A_b06r08 Rte_Write_CtCdd_TgfTestApplication_Pps02T0118D_A_b06r08_Des02T0118D_A_b06r08
#  define Rte_Write_Pps02T028S_A_b00r08_Des02T028S_A_b00r08 Rte_Write_CtCdd_TgfTestApplication_Pps02T028S_A_b00r08_Des02T028S_A_b00r08
#  define Rte_Write_Pps03T0118D_A_b06r08_Des03T0118D_A_b06r08 Rte_Write_CtCdd_TgfTestApplication_Pps03T0118D_A_b06r08_Des03T0118D_A_b06r08
#  define Rte_Write_Pps04T0118D_A_b06r08_Des04T0118D_A_b06r08 Rte_Write_CtCdd_TgfTestApplication_Pps04T0118D_A_b06r08_Des04T0118D_A_b06r08
#  define Rte_Write_Pps05T0118D_A_b06r08_Des05T0118D_A_b06r08 Rte_Write_CtCdd_TgfTestApplication_Pps05T0118D_A_b06r08_Des05T0118D_A_b06r08
#  define Rte_Write_Pps06T0118D_A_b06r08_Des06T0118D_A_b06r08 Rte_Write_CtCdd_TgfTestApplication_Pps06T0118D_A_b06r08_Des06T0118D_A_b06r08
#  define Rte_Write_Pps07T0118D_A_b06r08_Des07T0118D_A_b06r08 Rte_Write_CtCdd_TgfTestApplication_Pps07T0118D_A_b06r08_Des07T0118D_A_b06r08
#  define Rte_Write_Pps0T0012S_A_b00r04_IPDUM_DynSig_0_Des0T0012S_A_b00r04_IPDUM_DynSig_0 Rte_Write_CtCdd_TgfTestApplication_Pps0T0012S_A_b00r04_IPDUM_DynSig_0_Des0T0012S_A_b00r04_IPDUM_DynSig_0
#  define Rte_Write_Pps0T0012S_A_b01r04_IPDUM_DynSig_0_Des0T0012S_A_b01r04_IPDUM_DynSig_0 Rte_Write_CtCdd_TgfTestApplication_Pps0T0012S_A_b01r04_IPDUM_DynSig_0_Des0T0012S_A_b01r04_IPDUM_DynSig_0
#  define Rte_Write_Pps0T0012S_A_b01r04_IPDUM_DynSig_1_Des0T0012S_A_b01r04_IPDUM_DynSig_1 Rte_Write_CtCdd_TgfTestApplication_Pps0T0012S_A_b01r04_IPDUM_DynSig_1_Des0T0012S_A_b01r04_IPDUM_DynSig_1
#  define Rte_Write_Pps0T0012S_A_b01r04_IPDUM_DynSig_2_Des0T0012S_A_b01r04_IPDUM_DynSig_2 Rte_Write_CtCdd_TgfTestApplication_Pps0T0012S_A_b01r04_IPDUM_DynSig_2_Des0T0012S_A_b01r04_IPDUM_DynSig_2
#  define Rte_Write_Pps0T0012S_A_b01r04_IPDUM_DynSig_3_Des0T0012S_A_b01r04_IPDUM_DynSig_3 Rte_Write_CtCdd_TgfTestApplication_Pps0T0012S_A_b01r04_IPDUM_DynSig_3_Des0T0012S_A_b01r04_IPDUM_DynSig_3
#  define Rte_Write_Pps0T0013S_A_b00r04_IPDUM_DynSig_0_Des0T0013S_A_b00r04_IPDUM_DynSig_0 Rte_Write_CtCdd_TgfTestApplication_Pps0T0013S_A_b00r04_IPDUM_DynSig_0_Des0T0013S_A_b00r04_IPDUM_DynSig_0
#  define Rte_Write_Pps0T0013S_A_b01r04_IPDUM_DynSig_0_Des0T0013S_A_b01r04_IPDUM_DynSig_0 Rte_Write_CtCdd_TgfTestApplication_Pps0T0013S_A_b01r04_IPDUM_DynSig_0_Des0T0013S_A_b01r04_IPDUM_DynSig_0
#  define Rte_Write_Pps0T0013S_A_b01r04_IPDUM_DynSig_1_Des0T0013S_A_b01r04_IPDUM_DynSig_1 Rte_Write_CtCdd_TgfTestApplication_Pps0T0013S_A_b01r04_IPDUM_DynSig_1_Des0T0013S_A_b01r04_IPDUM_DynSig_1
#  define Rte_Write_Pps0T0013S_A_b01r04_IPDUM_DynSig_2_Des0T0013S_A_b01r04_IPDUM_DynSig_2 Rte_Write_CtCdd_TgfTestApplication_Pps0T0013S_A_b01r04_IPDUM_DynSig_2_Des0T0013S_A_b01r04_IPDUM_DynSig_2
#  define Rte_Write_Pps0T0013S_A_b01r04_IPDUM_DynSig_3_Des0T0013S_A_b01r04_IPDUM_DynSig_3 Rte_Write_CtCdd_TgfTestApplication_Pps0T0013S_A_b01r04_IPDUM_DynSig_3_Des0T0013S_A_b01r04_IPDUM_DynSig_3
#  define Rte_Write_Pps10T030S_A_b00r08_Des10T030S_A_b00r08 Rte_Write_CtCdd_TgfTestApplication_Pps10T030S_A_b00r08_Des10T030S_A_b00r08
#  define Rte_Write_Pps11T030S_A_b00r08_Des11T030S_A_b00r08 Rte_Write_CtCdd_TgfTestApplication_Pps11T030S_A_b00r08_Des11T030S_A_b00r08
#  define Rte_Write_Pps12T030S_A_b00r08_Des12T030S_A_b00r08 Rte_Write_CtCdd_TgfTestApplication_Pps12T030S_A_b00r08_Des12T030S_A_b00r08
#  define Rte_Write_Pps1T0012S_A_b00r04_IPDUM_DynSig_0_Des1T0012S_A_b00r04_IPDUM_DynSig_0 Rte_Write_CtCdd_TgfTestApplication_Pps1T0012S_A_b00r04_IPDUM_DynSig_0_Des1T0012S_A_b00r04_IPDUM_DynSig_0
#  define Rte_Write_Pps1T0012S_A_b01r04_IPDUM_DynSig_0_Des1T0012S_A_b01r04_IPDUM_DynSig_0 Rte_Write_CtCdd_TgfTestApplication_Pps1T0012S_A_b01r04_IPDUM_DynSig_0_Des1T0012S_A_b01r04_IPDUM_DynSig_0
#  define Rte_Write_Pps1T0012S_A_b01r04_IPDUM_DynSig_1_Des1T0012S_A_b01r04_IPDUM_DynSig_1 Rte_Write_CtCdd_TgfTestApplication_Pps1T0012S_A_b01r04_IPDUM_DynSig_1_Des1T0012S_A_b01r04_IPDUM_DynSig_1
#  define Rte_Write_Pps1T0012S_A_b01r04_IPDUM_DynSig_2_Des1T0012S_A_b01r04_IPDUM_DynSig_2 Rte_Write_CtCdd_TgfTestApplication_Pps1T0012S_A_b01r04_IPDUM_DynSig_2_Des1T0012S_A_b01r04_IPDUM_DynSig_2
#  define Rte_Write_Pps1T0012S_A_b01r04_IPDUM_DynSig_3_Des1T0012S_A_b01r04_IPDUM_DynSig_3 Rte_Write_CtCdd_TgfTestApplication_Pps1T0012S_A_b01r04_IPDUM_DynSig_3_Des1T0012S_A_b01r04_IPDUM_DynSig_3
#  define Rte_Write_Pps1T0013S_A_b00r04_IPDUM_DynSig_0_Des1T0013S_A_b00r04_IPDUM_DynSig_0 Rte_Write_CtCdd_TgfTestApplication_Pps1T0013S_A_b00r04_IPDUM_DynSig_0_Des1T0013S_A_b00r04_IPDUM_DynSig_0
#  define Rte_Write_Pps1T0013S_A_b01r04_IPDUM_DynSig_0_Des1T0013S_A_b01r04_IPDUM_DynSig_0 Rte_Write_CtCdd_TgfTestApplication_Pps1T0013S_A_b01r04_IPDUM_DynSig_0_Des1T0013S_A_b01r04_IPDUM_DynSig_0
#  define Rte_Write_Pps1T0013S_A_b01r04_IPDUM_DynSig_1_Des1T0013S_A_b01r04_IPDUM_DynSig_1 Rte_Write_CtCdd_TgfTestApplication_Pps1T0013S_A_b01r04_IPDUM_DynSig_1_Des1T0013S_A_b01r04_IPDUM_DynSig_1
#  define Rte_Write_Pps1T0013S_A_b01r04_IPDUM_DynSig_2_Des1T0013S_A_b01r04_IPDUM_DynSig_2 Rte_Write_CtCdd_TgfTestApplication_Pps1T0013S_A_b01r04_IPDUM_DynSig_2_Des1T0013S_A_b01r04_IPDUM_DynSig_2
#  define Rte_Write_Pps1T0013S_A_b01r04_IPDUM_DynSig_3_Des1T0013S_A_b01r04_IPDUM_DynSig_3 Rte_Write_CtCdd_TgfTestApplication_Pps1T0013S_A_b01r04_IPDUM_DynSig_3_Des1T0013S_A_b01r04_IPDUM_DynSig_3
#  define Rte_Write_PpsT00120D_A_b00r01_DesT00120D_A_b00r01 Rte_Write_CtCdd_TgfTestApplication_PpsT00120D_A_b00r01_DesT00120D_A_b00r01
#  define Rte_Write_PpsT00124D_A_b00r01_DesT00124D_A_b00r01 Rte_Write_CtCdd_TgfTestApplication_PpsT00124D_A_b00r01_DesT00124D_A_b00r01
#  define Rte_Write_PpsT00126D_A_b00r01_DesT00126D_A_b00r01 Rte_Write_CtCdd_TgfTestApplication_PpsT00126D_A_b00r01_DesT00126D_A_b00r01
#  define Rte_Write_PpsT00130D_A_b00r01_DesT00130D_A_b00r01 Rte_Write_CtCdd_TgfTestApplication_PpsT00130D_A_b00r01_DesT00130D_A_b00r01
#  define Rte_Write_PpsT0137D_A_b00r02_DesT0137D_A_b00r02 Rte_Write_CtCdd_TgfTestApplication_PpsT0137D_A_b00r02_DesT0137D_A_b00r02
#  define Rte_Write_PpsT0138D_A_b00r03_DesT0138D_A_b00r03 Rte_Write_CtCdd_TgfTestApplication_PpsT0138D_A_b00r03_DesT0138D_A_b00r03
#  define Rte_Write_PpsT0232D_A_b00r02_DesT0232D_A_b00r02 Rte_Write_CtCdd_TgfTestApplication_PpsT0232D_A_b00r02_DesT0232D_A_b00r02
#  define Rte_Write_PpsT0233D_A_b00r04_DesT0233D_A_b00r04 Rte_Write_CtCdd_TgfTestApplication_PpsT0233D_A_b00r04_DesT0233D_A_b00r04
#  define Rte_Write_Ppsig00Rx_0x21D_IL_Desig00Rx_0x21D_IL Rte_Write_CtCdd_TgfTestApplication_Ppsig00Rx_0x21D_IL_Desig00Rx_0x21D_IL
#  define Rte_Write_Ppsig00Rx_0x21F_IL_Desig00Rx_0x21F_IL Rte_Write_CtCdd_TgfTestApplication_Ppsig00Rx_0x21F_IL_Desig00Rx_0x21F_IL
#  define Rte_Write_Ppsig00Rx_0x221_IL_Desig00Rx_0x221_IL Rte_Write_CtCdd_TgfTestApplication_Ppsig00Rx_0x221_IL_Desig00Rx_0x221_IL
#  define Rte_Write_Ppsig00Rx_0x223_IL_Desig00Rx_0x223_IL Rte_Write_CtCdd_TgfTestApplication_Ppsig00Rx_0x223_IL_Desig00Rx_0x223_IL
#  define Rte_Write_Ppsig00Rx_0x225_IL_Desig00Rx_0x225_IL Rte_Write_CtCdd_TgfTestApplication_Ppsig00Rx_0x225_IL_Desig00Rx_0x225_IL
#  define Rte_Write_Ppsig00Rx_0x227_IL_Desig00Rx_0x227_IL Rte_Write_CtCdd_TgfTestApplication_Ppsig00Rx_0x227_IL_Desig00Rx_0x227_IL
#  define Rte_Write_Ppsig00Tx_0x228_IL_Desig00Tx_0x228_IL Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x228_IL_Desig00Tx_0x228_IL
#  define Rte_Write_Ppsig00Tx_0x3C3_IL_Desig00Tx_0x3C3_IL Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x3C3_IL_Desig00Tx_0x3C3_IL
#  define Rte_Write_Ppsig00Tx_0x3C4_IL_Desig00Tx_0x3C4_IL Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x3C4_IL_Desig00Tx_0x3C4_IL
#  define Rte_Write_Ppsig00Tx_0x3DD_IL_Desig00Tx_0x3DD_IL Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x3DD_IL_Desig00Tx_0x3DD_IL
#  define Rte_Write_Ppsig00Tx_0x3DE_IL_Desig00Tx_0x3DE_IL Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x3DE_IL_Desig00Tx_0x3DE_IL
#  define Rte_Write_Ppsig00Tx_0x3EA_IL_Desig00Tx_0x3EA_IL Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x3EA_IL_Desig00Tx_0x3EA_IL
#  define Rte_Write_Ppsig00Tx_0x3EF_IL_Desig00Tx_0x3EF_IL Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x3EF_IL_Desig00Tx_0x3EF_IL
#  define Rte_Write_Ppsig00Tx_0x754_IL_Desig00Tx_0x754_IL Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x754_IL_Desig00Tx_0x754_IL
#  define Rte_Write_Ppsig00Tx_0x755_IL_Desig00Tx_0x755_IL Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x755_IL_Desig00Tx_0x755_IL
#  define Rte_Write_Ppsig00Tx_0x757_IL_Desig00Tx_0x757_IL Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x757_IL_Desig00Tx_0x757_IL
#  define Rte_Write_Ppsig00Tx_0x757_IL_CAN00_Desig00Tx_0x757_IL_CAN00 Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x757_IL_CAN00_Desig00Tx_0x757_IL_CAN00
#  define Rte_Write_Ppsig00Tx_0x765_IL_Desig00Tx_0x765_IL Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x765_IL_Desig00Tx_0x765_IL
#  define Rte_Write_Ppsig00Tx_0x767_IL_Desig00Tx_0x767_IL Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x767_IL_Desig00Tx_0x767_IL
#  define Rte_Write_Ppsig00Tx_0x769_IL_Desig00Tx_0x769_IL Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x769_IL_Desig00Tx_0x769_IL
#  define Rte_Write_Ppsig00Tx_0x771_IL_Desig00Tx_0x771_IL Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x771_IL_Desig00Tx_0x771_IL
#  define Rte_Write_Ppsig00Tx_0x772_IL_Desig00Tx_0x772_IL Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x772_IL_Desig00Tx_0x772_IL
#  define Rte_Write_Ppsig00Tx_0x774_IL_Desig00Tx_0x774_IL Rte_Write_CtCdd_TgfTestApplication_Ppsig00Tx_0x774_IL_Desig00Tx_0x774_IL
#  define Rte_Write_Ppsig00_0x7A0_Desig00_0x7A0 Rte_Write_CtCdd_TgfTestApplication_Ppsig00_0x7A0_Desig00_0x7A0
#  define Rte_Write_Ppsig00_0x7A2_Desig00_0x7A2 Rte_Write_CtCdd_TgfTestApplication_Ppsig00_0x7A2_Desig00_0x7A2
#  define Rte_Write_Ppsig00_0x7A4_Desig00_0x7A4 Rte_Write_CtCdd_TgfTestApplication_Ppsig00_0x7A4_Desig00_0x7A4
#  define Rte_Write_Ppsig00_Tx_0x22C_IL_Desig00_Tx_0x22C_IL Rte_Write_CtCdd_TgfTestApplication_Ppsig00_Tx_0x22C_IL_Desig00_Tx_0x22C_IL
#  define Rte_Write_Ppsig01Tx_0x765_IL_Desig01Tx_0x765_IL Rte_Write_CtCdd_TgfTestApplication_Ppsig01Tx_0x765_IL_Desig01Tx_0x765_IL


/**********************************************************************************************************************
 * Rte_Feedback_<p>_<d> (explicit S/R communication status handling)
 *********************************************************************************************************************/
#  define Rte_Feedback_PpCanRPGSig_1_DeCanRPGSig_1 Rte_Feedback_CtCdd_TgfTestApplication_PpCanRPGSig_1_DeCanRPGSig_1
#  define Rte_Feedback_PpCanRPGSig_2_DeCanRPGSig_2 Rte_Feedback_CtCdd_TgfTestApplication_PpCanRPGSig_2_DeCanRPGSig_2
#  define Rte_Feedback_PpCanRPGSig_3_DeCanRPGSig_3 Rte_Feedback_CtCdd_TgfTestApplication_PpCanRPGSig_3_DeCanRPGSig_3
#  define Rte_Feedback_PpCanRPGSig_4_DeCanRPGSig_4 Rte_Feedback_CtCdd_TgfTestApplication_PpCanRPGSig_4_DeCanRPGSig_4
#  define Rte_Feedback_PpCanRPGSig_5_DeCanRPGSig_5 Rte_Feedback_CtCdd_TgfTestApplication_PpCanRPGSig_5_DeCanRPGSig_5
#  define Rte_Feedback_PpComCanSig_16bit_1_DeComCanSig_16bit_1 Rte_Feedback_CtCdd_TgfTestApplication_PpComCanSig_16bit_1_DeComCanSig_16bit_1
#  define Rte_Feedback_PpGwCanSig_8Bit_1_DeGwCanSig_8Bit_1 Rte_Feedback_CtCdd_TgfTestApplication_PpGwCanSig_8Bit_1_DeGwCanSig_8Bit_1
#  define Rte_Feedback_PpGwCanSig_8Bit_2_DeGwCanSig_8Bit_2 Rte_Feedback_CtCdd_TgfTestApplication_PpGwCanSig_8Bit_2_DeGwCanSig_8Bit_2
#  define Rte_Feedback_PpSig00Tx_0x3EE_IL_DeSig00Tx_0x3EE_IL Rte_Feedback_CtCdd_TgfTestApplication_PpSig00Tx_0x3EE_IL_DeSig00Tx_0x3EE_IL
#  define Rte_Feedback_PpSig00Tx_0x756_DeSig00Tx_0x756 Rte_Feedback_CtCdd_TgfTestApplication_PpSig00Tx_0x756_DeSig00Tx_0x756
#  define Rte_Feedback_PpSig_16Bit_20_DeSig_16Bit_20 Rte_Feedback_CtCdd_TgfTestApplication_PpSig_16Bit_20_DeSig_16Bit_20
#  define Rte_Feedback_PpSig_16Bit_23_DeSig_16Bit_23 Rte_Feedback_CtCdd_TgfTestApplication_PpSig_16Bit_23_DeSig_16Bit_23
#  define Rte_Feedback_PpSig_16bit_10_DeSig_16bit_10 Rte_Feedback_CtCdd_TgfTestApplication_PpSig_16bit_10_DeSig_16bit_10
#  define Rte_Feedback_PpSig_16bit_11_DeSig_16bit_11 Rte_Feedback_CtCdd_TgfTestApplication_PpSig_16bit_11_DeSig_16bit_11
#  define Rte_Feedback_PpSig_16bit_16_DeSig_16bit_16 Rte_Feedback_CtCdd_TgfTestApplication_PpSig_16bit_16_DeSig_16bit_16
#  define Rte_Feedback_PpSig_16bit_9_DeSig_16bit_9 Rte_Feedback_CtCdd_TgfTestApplication_PpSig_16bit_9_DeSig_16bit_9
#  define Rte_Feedback_PpSig_32Bit_3_DeSig_32Bit_3 Rte_Feedback_CtCdd_TgfTestApplication_PpSig_32Bit_3_DeSig_32Bit_3
#  define Rte_Feedback_PpSig_8Bit_11_DeSig_8Bit_11 Rte_Feedback_CtCdd_TgfTestApplication_PpSig_8Bit_11_DeSig_8Bit_11
#  define Rte_Feedback_PpSig_8Bit_20_DeSig_8Bit_20 Rte_Feedback_CtCdd_TgfTestApplication_PpSig_8Bit_20_DeSig_8Bit_20
#  define Rte_Feedback_PpSig_8Bit_21_DeSig_8Bit_21 Rte_Feedback_CtCdd_TgfTestApplication_PpSig_8Bit_21_DeSig_8Bit_21
#  define Rte_Feedback_PpSig_8Bit_22_DeSig_8Bit_22 Rte_Feedback_CtCdd_TgfTestApplication_PpSig_8Bit_22_DeSig_8Bit_22
#  define Rte_Feedback_PpSig_8bit_10_DeSig_8bit_10 Rte_Feedback_CtCdd_TgfTestApplication_PpSig_8bit_10_DeSig_8bit_10
#  define Rte_Feedback_PpSig_Bool_3_DeSig_Bool_3 Rte_Feedback_CtCdd_TgfTestApplication_PpSig_Bool_3_DeSig_Bool_3
#  define Rte_Feedback_PpSig_Cdd_1_DeSig_Cdd_1 Rte_Feedback_CtCdd_TgfTestApplication_PpSig_Cdd_1_DeSig_Cdd_1
#  define Rte_Feedback_PpSig_Cdd_8Bit_2_DeSig_Cdd_8Bit_2 Rte_Feedback_CtCdd_TgfTestApplication_PpSig_Cdd_8Bit_2_DeSig_Cdd_8Bit_2
#  define Rte_Feedback_Pps00T0118D_A_b06r08_Des00T0118D_A_b06r08 Rte_Feedback_CtCdd_TgfTestApplication_Pps00T0118D_A_b06r08_Des00T0118D_A_b06r08
#  define Rte_Feedback_Pps01T0118D_A_b06r08_Des01T0118D_A_b06r08 Rte_Feedback_CtCdd_TgfTestApplication_Pps01T0118D_A_b06r08_Des01T0118D_A_b06r08
#  define Rte_Feedback_Pps01T028S_A_b00r08_Des01T028S_A_b00r08 Rte_Feedback_CtCdd_TgfTestApplication_Pps01T028S_A_b00r08_Des01T028S_A_b00r08
#  define Rte_Feedback_Pps02T0118D_A_b06r08_Des02T0118D_A_b06r08 Rte_Feedback_CtCdd_TgfTestApplication_Pps02T0118D_A_b06r08_Des02T0118D_A_b06r08
#  define Rte_Feedback_Pps02T028S_A_b00r08_Des02T028S_A_b00r08 Rte_Feedback_CtCdd_TgfTestApplication_Pps02T028S_A_b00r08_Des02T028S_A_b00r08
#  define Rte_Feedback_Pps03T0118D_A_b06r08_Des03T0118D_A_b06r08 Rte_Feedback_CtCdd_TgfTestApplication_Pps03T0118D_A_b06r08_Des03T0118D_A_b06r08
#  define Rte_Feedback_Pps04T0118D_A_b06r08_Des04T0118D_A_b06r08 Rte_Feedback_CtCdd_TgfTestApplication_Pps04T0118D_A_b06r08_Des04T0118D_A_b06r08
#  define Rte_Feedback_Pps05T0118D_A_b06r08_Des05T0118D_A_b06r08 Rte_Feedback_CtCdd_TgfTestApplication_Pps05T0118D_A_b06r08_Des05T0118D_A_b06r08
#  define Rte_Feedback_Pps06T0118D_A_b06r08_Des06T0118D_A_b06r08 Rte_Feedback_CtCdd_TgfTestApplication_Pps06T0118D_A_b06r08_Des06T0118D_A_b06r08
#  define Rte_Feedback_Pps07T0118D_A_b06r08_Des07T0118D_A_b06r08 Rte_Feedback_CtCdd_TgfTestApplication_Pps07T0118D_A_b06r08_Des07T0118D_A_b06r08
#  define Rte_Feedback_Pps0T0012S_A_b00r04_IPDUM_DynSig_0_Des0T0012S_A_b00r04_IPDUM_DynSig_0 Rte_Feedback_CtCdd_TgfTestApplication_Pps0T0012S_A_b00r04_IPDUM_DynSig_0_Des0T0012S_A_b00r04_IPDUM_DynSig_0
#  define Rte_Feedback_Pps0T0012S_A_b01r04_IPDUM_DynSig_0_Des0T0012S_A_b01r04_IPDUM_DynSig_0 Rte_Feedback_CtCdd_TgfTestApplication_Pps0T0012S_A_b01r04_IPDUM_DynSig_0_Des0T0012S_A_b01r04_IPDUM_DynSig_0
#  define Rte_Feedback_Pps0T0012S_A_b01r04_IPDUM_DynSig_1_Des0T0012S_A_b01r04_IPDUM_DynSig_1 Rte_Feedback_CtCdd_TgfTestApplication_Pps0T0012S_A_b01r04_IPDUM_DynSig_1_Des0T0012S_A_b01r04_IPDUM_DynSig_1
#  define Rte_Feedback_Pps0T0012S_A_b01r04_IPDUM_DynSig_2_Des0T0012S_A_b01r04_IPDUM_DynSig_2 Rte_Feedback_CtCdd_TgfTestApplication_Pps0T0012S_A_b01r04_IPDUM_DynSig_2_Des0T0012S_A_b01r04_IPDUM_DynSig_2
#  define Rte_Feedback_Pps0T0012S_A_b01r04_IPDUM_DynSig_3_Des0T0012S_A_b01r04_IPDUM_DynSig_3 Rte_Feedback_CtCdd_TgfTestApplication_Pps0T0012S_A_b01r04_IPDUM_DynSig_3_Des0T0012S_A_b01r04_IPDUM_DynSig_3
#  define Rte_Feedback_Pps0T0013S_A_b00r04_IPDUM_DynSig_0_Des0T0013S_A_b00r04_IPDUM_DynSig_0 Rte_Feedback_CtCdd_TgfTestApplication_Pps0T0013S_A_b00r04_IPDUM_DynSig_0_Des0T0013S_A_b00r04_IPDUM_DynSig_0
#  define Rte_Feedback_Pps0T0013S_A_b01r04_IPDUM_DynSig_0_Des0T0013S_A_b01r04_IPDUM_DynSig_0 Rte_Feedback_CtCdd_TgfTestApplication_Pps0T0013S_A_b01r04_IPDUM_DynSig_0_Des0T0013S_A_b01r04_IPDUM_DynSig_0
#  define Rte_Feedback_Pps0T0013S_A_b01r04_IPDUM_DynSig_1_Des0T0013S_A_b01r04_IPDUM_DynSig_1 Rte_Feedback_CtCdd_TgfTestApplication_Pps0T0013S_A_b01r04_IPDUM_DynSig_1_Des0T0013S_A_b01r04_IPDUM_DynSig_1
#  define Rte_Feedback_Pps0T0013S_A_b01r04_IPDUM_DynSig_2_Des0T0013S_A_b01r04_IPDUM_DynSig_2 Rte_Feedback_CtCdd_TgfTestApplication_Pps0T0013S_A_b01r04_IPDUM_DynSig_2_Des0T0013S_A_b01r04_IPDUM_DynSig_2
#  define Rte_Feedback_Pps0T0013S_A_b01r04_IPDUM_DynSig_3_Des0T0013S_A_b01r04_IPDUM_DynSig_3 Rte_Feedback_CtCdd_TgfTestApplication_Pps0T0013S_A_b01r04_IPDUM_DynSig_3_Des0T0013S_A_b01r04_IPDUM_DynSig_3
#  define Rte_Feedback_Pps10T030S_A_b00r08_Des10T030S_A_b00r08 Rte_Feedback_CtCdd_TgfTestApplication_Pps10T030S_A_b00r08_Des10T030S_A_b00r08
#  define Rte_Feedback_Pps11T030S_A_b00r08_Des11T030S_A_b00r08 Rte_Feedback_CtCdd_TgfTestApplication_Pps11T030S_A_b00r08_Des11T030S_A_b00r08
#  define Rte_Feedback_Pps12T030S_A_b00r08_Des12T030S_A_b00r08 Rte_Feedback_CtCdd_TgfTestApplication_Pps12T030S_A_b00r08_Des12T030S_A_b00r08
#  define Rte_Feedback_Pps1T0012S_A_b00r04_IPDUM_DynSig_0_Des1T0012S_A_b00r04_IPDUM_DynSig_0 Rte_Feedback_CtCdd_TgfTestApplication_Pps1T0012S_A_b00r04_IPDUM_DynSig_0_Des1T0012S_A_b00r04_IPDUM_DynSig_0
#  define Rte_Feedback_Pps1T0012S_A_b01r04_IPDUM_DynSig_0_Des1T0012S_A_b01r04_IPDUM_DynSig_0 Rte_Feedback_CtCdd_TgfTestApplication_Pps1T0012S_A_b01r04_IPDUM_DynSig_0_Des1T0012S_A_b01r04_IPDUM_DynSig_0
#  define Rte_Feedback_Pps1T0012S_A_b01r04_IPDUM_DynSig_1_Des1T0012S_A_b01r04_IPDUM_DynSig_1 Rte_Feedback_CtCdd_TgfTestApplication_Pps1T0012S_A_b01r04_IPDUM_DynSig_1_Des1T0012S_A_b01r04_IPDUM_DynSig_1
#  define Rte_Feedback_Pps1T0012S_A_b01r04_IPDUM_DynSig_2_Des1T0012S_A_b01r04_IPDUM_DynSig_2 Rte_Feedback_CtCdd_TgfTestApplication_Pps1T0012S_A_b01r04_IPDUM_DynSig_2_Des1T0012S_A_b01r04_IPDUM_DynSig_2
#  define Rte_Feedback_Pps1T0012S_A_b01r04_IPDUM_DynSig_3_Des1T0012S_A_b01r04_IPDUM_DynSig_3 Rte_Feedback_CtCdd_TgfTestApplication_Pps1T0012S_A_b01r04_IPDUM_DynSig_3_Des1T0012S_A_b01r04_IPDUM_DynSig_3
#  define Rte_Feedback_Pps1T0013S_A_b00r04_IPDUM_DynSig_0_Des1T0013S_A_b00r04_IPDUM_DynSig_0 Rte_Feedback_CtCdd_TgfTestApplication_Pps1T0013S_A_b00r04_IPDUM_DynSig_0_Des1T0013S_A_b00r04_IPDUM_DynSig_0
#  define Rte_Feedback_Pps1T0013S_A_b01r04_IPDUM_DynSig_0_Des1T0013S_A_b01r04_IPDUM_DynSig_0 Rte_Feedback_CtCdd_TgfTestApplication_Pps1T0013S_A_b01r04_IPDUM_DynSig_0_Des1T0013S_A_b01r04_IPDUM_DynSig_0
#  define Rte_Feedback_Pps1T0013S_A_b01r04_IPDUM_DynSig_1_Des1T0013S_A_b01r04_IPDUM_DynSig_1 Rte_Feedback_CtCdd_TgfTestApplication_Pps1T0013S_A_b01r04_IPDUM_DynSig_1_Des1T0013S_A_b01r04_IPDUM_DynSig_1
#  define Rte_Feedback_Pps1T0013S_A_b01r04_IPDUM_DynSig_2_Des1T0013S_A_b01r04_IPDUM_DynSig_2 Rte_Feedback_CtCdd_TgfTestApplication_Pps1T0013S_A_b01r04_IPDUM_DynSig_2_Des1T0013S_A_b01r04_IPDUM_DynSig_2
#  define Rte_Feedback_Pps1T0013S_A_b01r04_IPDUM_DynSig_3_Des1T0013S_A_b01r04_IPDUM_DynSig_3 Rte_Feedback_CtCdd_TgfTestApplication_Pps1T0013S_A_b01r04_IPDUM_DynSig_3_Des1T0013S_A_b01r04_IPDUM_DynSig_3
#  define Rte_Feedback_PpsT00120D_A_b00r01_DesT00120D_A_b00r01 Rte_Feedback_CtCdd_TgfTestApplication_PpsT00120D_A_b00r01_DesT00120D_A_b00r01
#  define Rte_Feedback_PpsT00124D_A_b00r01_DesT00124D_A_b00r01 Rte_Feedback_CtCdd_TgfTestApplication_PpsT00124D_A_b00r01_DesT00124D_A_b00r01
#  define Rte_Feedback_PpsT00126D_A_b00r01_DesT00126D_A_b00r01 Rte_Feedback_CtCdd_TgfTestApplication_PpsT00126D_A_b00r01_DesT00126D_A_b00r01
#  define Rte_Feedback_PpsT00130D_A_b00r01_DesT00130D_A_b00r01 Rte_Feedback_CtCdd_TgfTestApplication_PpsT00130D_A_b00r01_DesT00130D_A_b00r01
#  define Rte_Feedback_PpsT0137D_A_b00r02_DesT0137D_A_b00r02 Rte_Feedback_CtCdd_TgfTestApplication_PpsT0137D_A_b00r02_DesT0137D_A_b00r02
#  define Rte_Feedback_PpsT0138D_A_b00r03_DesT0138D_A_b00r03 Rte_Feedback_CtCdd_TgfTestApplication_PpsT0138D_A_b00r03_DesT0138D_A_b00r03
#  define Rte_Feedback_PpsT0232D_A_b00r02_DesT0232D_A_b00r02 Rte_Feedback_CtCdd_TgfTestApplication_PpsT0232D_A_b00r02_DesT0232D_A_b00r02
#  define Rte_Feedback_PpsT0233D_A_b00r04_DesT0233D_A_b00r04 Rte_Feedback_CtCdd_TgfTestApplication_PpsT0233D_A_b00r04_DesT0233D_A_b00r04
#  define Rte_Feedback_Ppsig00Rx_0x21D_IL_Desig00Rx_0x21D_IL Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Rx_0x21D_IL_Desig00Rx_0x21D_IL
#  define Rte_Feedback_Ppsig00Rx_0x21F_IL_Desig00Rx_0x21F_IL Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Rx_0x21F_IL_Desig00Rx_0x21F_IL
#  define Rte_Feedback_Ppsig00Rx_0x221_IL_Desig00Rx_0x221_IL Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Rx_0x221_IL_Desig00Rx_0x221_IL
#  define Rte_Feedback_Ppsig00Rx_0x223_IL_Desig00Rx_0x223_IL Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Rx_0x223_IL_Desig00Rx_0x223_IL
#  define Rte_Feedback_Ppsig00Rx_0x225_IL_Desig00Rx_0x225_IL Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Rx_0x225_IL_Desig00Rx_0x225_IL
#  define Rte_Feedback_Ppsig00Rx_0x227_IL_Desig00Rx_0x227_IL Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Rx_0x227_IL_Desig00Rx_0x227_IL
#  define Rte_Feedback_Ppsig00Tx_0x228_IL_Desig00Tx_0x228_IL Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x228_IL_Desig00Tx_0x228_IL
#  define Rte_Feedback_Ppsig00Tx_0x3C3_IL_Desig00Tx_0x3C3_IL Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x3C3_IL_Desig00Tx_0x3C3_IL
#  define Rte_Feedback_Ppsig00Tx_0x3C4_IL_Desig00Tx_0x3C4_IL Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x3C4_IL_Desig00Tx_0x3C4_IL
#  define Rte_Feedback_Ppsig00Tx_0x3DD_IL_Desig00Tx_0x3DD_IL Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x3DD_IL_Desig00Tx_0x3DD_IL
#  define Rte_Feedback_Ppsig00Tx_0x3DE_IL_Desig00Tx_0x3DE_IL Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x3DE_IL_Desig00Tx_0x3DE_IL
#  define Rte_Feedback_Ppsig00Tx_0x3EA_IL_Desig00Tx_0x3EA_IL Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x3EA_IL_Desig00Tx_0x3EA_IL
#  define Rte_Feedback_Ppsig00Tx_0x3EF_IL_Desig00Tx_0x3EF_IL Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x3EF_IL_Desig00Tx_0x3EF_IL
#  define Rte_Feedback_Ppsig00Tx_0x754_IL_Desig00Tx_0x754_IL Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x754_IL_Desig00Tx_0x754_IL
#  define Rte_Feedback_Ppsig00Tx_0x755_IL_Desig00Tx_0x755_IL Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x755_IL_Desig00Tx_0x755_IL
#  define Rte_Feedback_Ppsig00Tx_0x757_IL_Desig00Tx_0x757_IL Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x757_IL_Desig00Tx_0x757_IL
#  define Rte_Feedback_Ppsig00Tx_0x757_IL_CAN00_Desig00Tx_0x757_IL_CAN00 Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x757_IL_CAN00_Desig00Tx_0x757_IL_CAN00
#  define Rte_Feedback_Ppsig00Tx_0x765_IL_Desig00Tx_0x765_IL Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x765_IL_Desig00Tx_0x765_IL
#  define Rte_Feedback_Ppsig00Tx_0x767_IL_Desig00Tx_0x767_IL Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x767_IL_Desig00Tx_0x767_IL
#  define Rte_Feedback_Ppsig00Tx_0x769_IL_Desig00Tx_0x769_IL Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x769_IL_Desig00Tx_0x769_IL
#  define Rte_Feedback_Ppsig00Tx_0x771_IL_Desig00Tx_0x771_IL Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x771_IL_Desig00Tx_0x771_IL
#  define Rte_Feedback_Ppsig00Tx_0x772_IL_Desig00Tx_0x772_IL Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x772_IL_Desig00Tx_0x772_IL
#  define Rte_Feedback_Ppsig00Tx_0x774_IL_Desig00Tx_0x774_IL Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00Tx_0x774_IL_Desig00Tx_0x774_IL
#  define Rte_Feedback_Ppsig00_0x7A0_Desig00_0x7A0 Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00_0x7A0_Desig00_0x7A0
#  define Rte_Feedback_Ppsig00_0x7A2_Desig00_0x7A2 Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00_0x7A2_Desig00_0x7A2
#  define Rte_Feedback_Ppsig00_0x7A4_Desig00_0x7A4 Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00_0x7A4_Desig00_0x7A4
#  define Rte_Feedback_Ppsig00_Tx_0x22C_IL_Desig00_Tx_0x22C_IL Rte_Feedback_CtCdd_TgfTestApplication_Ppsig00_Tx_0x22C_IL_Desig00_Tx_0x22C_IL
#  define Rte_Feedback_Ppsig01Tx_0x765_IL_Desig01Tx_0x765_IL Rte_Feedback_CtCdd_TgfTestApplication_Ppsig01Tx_0x765_IL_Desig01Tx_0x765_IL


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_COMM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_GetCurrentComMode(ComM_UserHandleType parg0, P2VAR(ComM_ModeType, AUTOMATIC, RTE_COMM_APPL_VAR) ComMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Tgf_UR_USR_CHNL_8571680a_GetCurrentComMode(arg1) (ComM_GetCurrentComMode((ComM_UserHandleType)1, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_COMM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_RequestComMode(ComM_UserHandleType parg0, ComM_ModeType ComMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Tgf_UR_USR_CHNL_8571680a_RequestComMode(arg1) (ComM_RequestComMode((ComM_UserHandleType)1, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_Tgf_UR_USR_CHNL_f276589c_GetCurrentComMode(arg1) (ComM_GetCurrentComMode((ComM_UserHandleType)0, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_Tgf_UR_USR_CHNL_f276589c_RequestComMode(arg1) (ComM_RequestComMode((ComM_UserHandleType)0, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_Tgf_UR_USR_FlexrayCluster_1_f26020e5_GetCurrentComMode(arg1) (ComM_GetCurrentComMode((ComM_UserHandleType)2, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_Tgf_UR_USR_FlexrayCluster_1_f26020e5_RequestComMode(arg1) (ComM_RequestComMode((ComM_UserHandleType)2, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define CtCdd_TgfTestApplication_START_SEC_CODE
# include "CtCdd_TgfTestApplication_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BrsCtrl_Tasklevel BrsCtrl_Tasklevel
#  define RTE_RUNNABLE_RxErrComCanSig_16Bit_13 RxErrComCanSig_16Bit_13
#  define RTE_RUNNABLE_RxErrComCanSig_16Bit_18 RxErrComCanSig_16Bit_18
#  define RTE_RUNNABLE_RxErrComCanSig_16bit_2 RxErrComCanSig_16bit_2
#  define RTE_RUNNABLE_RxErrComFrSig_32Bit_2 RxErrComFrSig_32Bit_2
#  define RTE_RUNNABLE_RxErrGwCanCan_Can1Sig_32Bit1 RxErrGwCanCan_Can1Sig_32Bit1
#  define RTE_RUNNABLE_RxErrGwCanCan_Can1Sig_8Bit1 RxErrGwCanCan_Can1Sig_8Bit1
#  define RTE_RUNNABLE_RxErrGwCanCan_Can2Sig_16Bit1 RxErrGwCanCan_Can2Sig_16Bit1
#  define RTE_RUNNABLE_RxErrGwCanCan_Can2Sig_32Bit1 RxErrGwCanCan_Can2Sig_32Bit1
#  define RTE_RUNNABLE_RxErrGwCanCan_Can2Sig_8Bit2 RxErrGwCanCan_Can2Sig_8Bit2
#  define RTE_RUNNABLE_RxErrGwCanFr_Can2Sig_8Bit_3 RxErrGwCanFr_Can2Sig_8Bit_3
#  define RTE_RUNNABLE_RxErrGwCanFr_CanSig_16Bit_1 RxErrGwCanFr_CanSig_16Bit_1
#  define RTE_RUNNABLE_RxErrGwCanFr_CanSig_32Bit_1 RxErrGwCanFr_CanSig_32Bit_1
#  define RTE_RUNNABLE_RxErrGwCanFr_CanSig_8Bit_1 RxErrGwCanFr_CanSig_8Bit_1
#  define RTE_RUNNABLE_RxErrGwCanFr_CanSig_8Bit_2 RxErrGwCanFr_CanSig_8Bit_2
#  define RTE_RUNNABLE_RxErrGwFrSig_16Bit_2 RxErrGwFrSig_16Bit_2
#  define RTE_RUNNABLE_RxErrGwFrSig_32Bit_6 RxErrGwFrSig_32Bit_6
#  define RTE_RUNNABLE_RxErrGwFrSig_8Bit_3 RxErrGwFrSig_8Bit_3
#  define RTE_RUNNABLE_RxErrSig_32Bit_2 RxErrSig_32Bit_2
#  define RTE_RUNNABLE_RxErrs03R0100D_A_b01r08 RxErrs03R0100D_A_b01r08
#  define RTE_RUNNABLE_RxErrs03R0118D_A_b01r08 RxErrs03R0118D_A_b01r08
#  define RTE_RUNNABLE_RxErrs11_p00R041S_A_b01r04 RxErrs11_p00R041S_A_b01r04
#  define RTE_RUNNABLE_RxErrs3_p00R041S_A_b00r04 RxErrs3_p00R041S_A_b00r04
#  define RTE_RUNNABLE_RxErrs3_p00R041S_A_b01r04 RxErrs3_p00R041S_A_b01r04
#  define RTE_RUNNABLE_RxErrs3_p01R041S_A_b00r04 RxErrs3_p01R041S_A_b00r04
#  define RTE_RUNNABLE_RxErrsig00Rx_0x222_IL RxErrsig00Rx_0x222_IL
#  define RTE_RUNNABLE_RxErrsig00Rx_0x224_IL RxErrsig00Rx_0x224_IL
#  define RTE_RUNNABLE_RxErrsig00Rx_0x226_IL RxErrsig00Rx_0x226_IL
#  define RTE_RUNNABLE_RxErrsig00_0x776 RxErrsig00_0x776
#  define RTE_RUNNABLE_RxErrsig01_0x780 RxErrsig01_0x780
#  define RTE_RUNNABLE_RxNtfyComCanSig_16Bit_13 RxNtfyComCanSig_16Bit_13
#  define RTE_RUNNABLE_RxNtfyComCanSig_16Bit_18 RxNtfyComCanSig_16Bit_18
#  define RTE_RUNNABLE_RxNtfyComCanSig_16bit_2 RxNtfyComCanSig_16bit_2
#  define RTE_RUNNABLE_RxNtfyComFrSig_32Bit_2 RxNtfyComFrSig_32Bit_2
#  define RTE_RUNNABLE_RxNtfyGwCanCan_Can1Sig_32Bit1 RxNtfyGwCanCan_Can1Sig_32Bit1
#  define RTE_RUNNABLE_RxNtfyGwCanCan_Can1Sig_8Bit1 RxNtfyGwCanCan_Can1Sig_8Bit1
#  define RTE_RUNNABLE_RxNtfyGwCanCan_Can2Sig_16Bit1 RxNtfyGwCanCan_Can2Sig_16Bit1
#  define RTE_RUNNABLE_RxNtfyGwCanCan_Can2Sig_32Bit1 RxNtfyGwCanCan_Can2Sig_32Bit1
#  define RTE_RUNNABLE_RxNtfyGwCanCan_Can2Sig_8Bit2 RxNtfyGwCanCan_Can2Sig_8Bit2
#  define RTE_RUNNABLE_RxNtfyGwCanFr_Can2Sig_8Bit_3 RxNtfyGwCanFr_Can2Sig_8Bit_3
#  define RTE_RUNNABLE_RxNtfyGwCanFr_CanSig_16Bit_1 RxNtfyGwCanFr_CanSig_16Bit_1
#  define RTE_RUNNABLE_RxNtfyGwCanFr_CanSig_32Bit_1 RxNtfyGwCanFr_CanSig_32Bit_1
#  define RTE_RUNNABLE_RxNtfyGwCanFr_CanSig_8Bit_1 RxNtfyGwCanFr_CanSig_8Bit_1
#  define RTE_RUNNABLE_RxNtfyGwCanFr_CanSig_8Bit_2 RxNtfyGwCanFr_CanSig_8Bit_2
#  define RTE_RUNNABLE_RxNtfyGwFrSig_16Bit_2 RxNtfyGwFrSig_16Bit_2
#  define RTE_RUNNABLE_RxNtfyGwFrSig_32Bit_6 RxNtfyGwFrSig_32Bit_6
#  define RTE_RUNNABLE_RxNtfyGwFrSig_8Bit_3 RxNtfyGwFrSig_8Bit_3
#  define RTE_RUNNABLE_RxNtfySig_32Bit_2 RxNtfySig_32Bit_2
#  define RTE_RUNNABLE_RxNtfys03R0100D_A_b01r08 RxNtfys03R0100D_A_b01r08
#  define RTE_RUNNABLE_RxNtfys03R0118D_A_b01r08 RxNtfys03R0118D_A_b01r08
#  define RTE_RUNNABLE_RxNtfys11_p00R041S_A_b01r04 RxNtfys11_p00R041S_A_b01r04
#  define RTE_RUNNABLE_RxNtfys3_p00R041S_A_b00r04 RxNtfys3_p00R041S_A_b00r04
#  define RTE_RUNNABLE_RxNtfys3_p00R041S_A_b01r04 RxNtfys3_p00R041S_A_b01r04
#  define RTE_RUNNABLE_RxNtfys3_p01R041S_A_b00r04 RxNtfys3_p01R041S_A_b00r04
#  define RTE_RUNNABLE_RxNtfysig00Rx_0x222_IL RxNtfysig00Rx_0x222_IL
#  define RTE_RUNNABLE_RxNtfysig00Rx_0x224_IL RxNtfysig00Rx_0x224_IL
#  define RTE_RUNNABLE_RxNtfysig00Rx_0x226_IL RxNtfysig00Rx_0x226_IL
#  define RTE_RUNNABLE_RxNtfysig00_0x776 RxNtfysig00_0x776
#  define RTE_RUNNABLE_RxNtfysig01_0x780 RxNtfysig01_0x780
#  define RTE_RUNNABLE_Tgf1Ms_Runnable Tgf1Ms_Runnable
#  define RTE_RUNNABLE_TxAckCanRPGSig_1 TxAckCanRPGSig_1
#  define RTE_RUNNABLE_TxAckCanRPGSig_2 TxAckCanRPGSig_2
#  define RTE_RUNNABLE_TxAckCanRPGSig_3 TxAckCanRPGSig_3
#  define RTE_RUNNABLE_TxAckCanRPGSig_4 TxAckCanRPGSig_4
#  define RTE_RUNNABLE_TxAckCanRPGSig_5 TxAckCanRPGSig_5
#  define RTE_RUNNABLE_TxAckComCanSig_16bit_1 TxAckComCanSig_16bit_1
#  define RTE_RUNNABLE_TxAckGwCanSig_8Bit_1 TxAckGwCanSig_8Bit_1
#  define RTE_RUNNABLE_TxAckSig_16Bit_20 TxAckSig_16Bit_20
#  define RTE_RUNNABLE_TxAckSig_16Bit_23 TxAckSig_16Bit_23
#  define RTE_RUNNABLE_TxAckSig_16bit_10 TxAckSig_16bit_10
#  define RTE_RUNNABLE_TxAckSig_16bit_11 TxAckSig_16bit_11
#  define RTE_RUNNABLE_TxAckSig_16bit_16 TxAckSig_16bit_16
#  define RTE_RUNNABLE_TxAckSig_32Bit_3 TxAckSig_32Bit_3
#  define RTE_RUNNABLE_TxAcks03T0118D_A_b06r08 TxAcks03T0118D_A_b06r08
#  define RTE_RUNNABLE_TxAcksig00Rx_0x221_IL TxAcksig00Rx_0x221_IL
#  define RTE_RUNNABLE_TxAcksig00Rx_0x223_IL TxAcksig00Rx_0x223_IL
#  define RTE_RUNNABLE_TxAcksig00Rx_0x225_IL TxAcksig00Rx_0x225_IL
#  define RTE_RUNNABLE_TxAcksig00Rx_0x227_IL TxAcksig00Rx_0x227_IL
#  define RTE_RUNNABLE_TxAcksig00Tx_0x757_IL_CAN00 TxAcksig00Tx_0x757_IL_CAN00
# endif

FUNC(void, CtCdd_TgfTestApplication_CODE) BrsCtrl_Tasklevel(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrComCanSig_16Bit_13(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrComCanSig_16Bit_18(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrComCanSig_16bit_2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrComFrSig_32Bit_2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrGwCanCan_Can1Sig_32Bit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrGwCanCan_Can1Sig_8Bit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrGwCanCan_Can2Sig_16Bit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrGwCanCan_Can2Sig_32Bit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrGwCanCan_Can2Sig_8Bit2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrGwCanFr_Can2Sig_8Bit_3(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrGwCanFr_CanSig_16Bit_1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrGwCanFr_CanSig_32Bit_1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrGwCanFr_CanSig_8Bit_1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrGwCanFr_CanSig_8Bit_2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrGwFrSig_16Bit_2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrGwFrSig_32Bit_6(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrGwFrSig_8Bit_3(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrSig_32Bit_2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrs03R0100D_A_b01r08(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrs03R0118D_A_b01r08(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrs11_p00R041S_A_b01r04(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrs3_p00R041S_A_b00r04(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrs3_p00R041S_A_b01r04(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrs3_p01R041S_A_b00r04(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrsig00Rx_0x222_IL(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrsig00Rx_0x224_IL(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrsig00Rx_0x226_IL(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrsig00_0x776(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxErrsig01_0x780(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfyComCanSig_16Bit_13(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfyComCanSig_16Bit_18(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfyComCanSig_16bit_2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfyComFrSig_32Bit_2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfyGwCanCan_Can1Sig_32Bit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfyGwCanCan_Can1Sig_8Bit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfyGwCanCan_Can2Sig_16Bit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfyGwCanCan_Can2Sig_32Bit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfyGwCanCan_Can2Sig_8Bit2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfyGwCanFr_Can2Sig_8Bit_3(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfyGwCanFr_CanSig_16Bit_1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfyGwCanFr_CanSig_32Bit_1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfyGwCanFr_CanSig_8Bit_1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfyGwCanFr_CanSig_8Bit_2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfyGwFrSig_16Bit_2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfyGwFrSig_32Bit_6(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfyGwFrSig_8Bit_3(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfySig_32Bit_2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfys03R0100D_A_b01r08(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfys03R0118D_A_b01r08(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfys11_p00R041S_A_b01r04(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfys3_p00R041S_A_b00r04(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfys3_p00R041S_A_b01r04(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfys3_p01R041S_A_b00r04(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfysig00Rx_0x222_IL(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfysig00Rx_0x224_IL(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfysig00Rx_0x226_IL(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfysig00_0x776(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) RxNtfysig01_0x780(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) Tgf1Ms_Runnable(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) TxAckCanRPGSig_1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) TxAckCanRPGSig_2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) TxAckCanRPGSig_3(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) TxAckCanRPGSig_4(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) TxAckCanRPGSig_5(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) TxAckComCanSig_16bit_1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) TxAckGwCanSig_8Bit_1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) TxAckSig_16Bit_20(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) TxAckSig_16Bit_23(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) TxAckSig_16bit_10(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) TxAckSig_16bit_11(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) TxAckSig_16bit_16(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) TxAckSig_32Bit_3(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) TxAcks03T0118D_A_b06r08(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) TxAcksig00Rx_0x221_IL(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) TxAcksig00Rx_0x223_IL(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) TxAcksig00Rx_0x225_IL(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) TxAcksig00Rx_0x227_IL(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtCdd_TgfTestApplication_CODE) TxAcksig00Tx_0x757_IL_CAN00(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define CtCdd_TgfTestApplication_STOP_SEC_CODE
# include "CtCdd_TgfTestApplication_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_ComM_UserRequest_E_MODE_LIMITATION (2U)

#  define RTE_E_ComM_UserRequest_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CTCDD_TGFTESTAPPLICATION_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
