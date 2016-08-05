/*  *****   STARTSINGLE_OF_MULTIPLE_COMMENT    *****  */




/*****************************************************************************/
/**
 * \file    BrsCtrl.H
 * \brief   BRS test control, Header
 *
 * This is the Test Control Center (TCC) code file for the Basic Runtime System (BRS)
 *
 * The TCC is responsible for the test handling via the network. It is able to 
 * handle one request at a time. 
 *
 * \attention Please note:
 *  The demo and example program only shows special aspects of the software. 
 *  With regard to the fact that this program is meant for demonstration purposes 
 *  Vector Informatik's liability shall be expressly excluded in cases of 
 *  ordinary negligence, to the extent admissible by law or statute. 
 *
 *  Please note, that this header must be included always AFTER the include of
 *  V_CFG.H and V_DEF.H to make all the headers known to this file!
 *
 *                               
 * Check up BrsCtrl.c for description, author and history
 * Version info: see BRSCTRL_VERSION, BRSCTRL_RELEASE_VERSION
 *
 *****************************************************************************
 *               C O P Y R I G H T
 *****************************************************************************
 * Copyright (c) 2005 by Vector Informatik GmbH.      All rights reserved.
 *
 *       This software is copyright protected and 
 *       proporietary to Vector Informatik GmbH.
 *       Vector Informatik GmbH grants to you only
 *       those rights as set out in the license conditions.
 *       All other rights remain with Vector Informatik GmbH.
 * 
 *       Diese Software ist urheberrechtlich geschuetzt. 
 *       Vector Informatik GmbH raeumt Ihnen an dieser Software nur 
 *       die in den Lizenzbedingungen ausdruecklich genannten Rechte ein.
 *       Alle anderen Rechte verbleiben bei Vector Informatik GmbH.
 *
 *****************************************************************************/

#ifndef _BRSCTRL_H_
#define _BRSCTRL_H_

/*
 * Description: The BrsCfg header is used to configure different types of
 *              tests and system setups. Therefore it must be included first
 *              in each BRS and test module. It is always included in each header
 *              to make sure all BRS switches are really known!
 *              This file is part of the BRS.
 */
#include "BrsCfg.H"


/*******************************************************************************
* Module version
*******************************************************************************/
/*
 * Description: This is the BRS Test control center main and release fix version.
 *              The version numbers are BCD coded. E.g. a main version of 1.23 is 
 *              coded with 0x0123, a release version of 9 is coded 0x09.
 */
/* ##V_CFG_MANAGEMENT ##CQProject : Brs_Ctrl CQComponent : Implementation */
#define BRS_CTRL_VERSION          0x0314
#define BRS_CTRL_RELEASE_VERSION  0x00

#define BRSCTRL_VERSION        BRS_CTRL_VERSION
#define BRSCTRL_BUGFIX_VERSION BRS_CTRL_RELEASE_VERSION



/*******************************************************************************
* Global defines
*******************************************************************************/
#if defined( BRS_ENABLE_TESTCONTROL )


/*
 * Description: All TCC error codes to be used with own tests are listed here:
 */
#define BRSCTRL_ERROR_SNS          0x11
#define BRSCTRL_ERROR_SFNS         0x12
#define BRSCTRL_ERROR_IMLOIF       0x13
#define BRSCTRL_ERROR_BRR          0x21
#define BRSCTRL_ERROR_CNCORSE      0x22
#define BRSCTRL_ERROR_ROOR         0x31
                                   
#define BRSCTRL_FCT_RDBI           0x22
#define BRSCTRL_FCT_RMBA           0x23
#define BRSCTRL_FCT_WDBI           0x2e
#define BRSCTRL_FCT_WMBA           0x2d
#define BRSCTRL_FCT_STR            0x31
#define BRSCTRL_FCT_STP            0x32
#define BRSCTRL_FCT_RRR            0x33

/*
 * Description: Negative response code for TCC requests
 */
#define BRSCTRL_NACK               0x7F


/*
 * Description: All CI codes to be used with TCC are listed here
 *              Use these defines in your application. Don't use
 *              The compatibility defines below!
 */
#define BRSCTRL_CODE_CCL                        0x50
#define BRSCTRL_CODE_CCL_ASRCOMM                0x52
#define BRSCTRL_CODE_CCL_CCLCOM                 0x53
#define BRSCTRL_CODE_CCL_DPM                    0x68
#define BRSCTRL_CODE_COMMON_VDEF                0xA1
#define BRSCTRL_CODE_VSTDLIB                    0xA2
#define BRSCTRL_CODE_CP_CCP                     0x65
#define BRSCTRL_CODE_CP_XCP                     0x66
#define BRSCTRL_CODE_CP_XCPONCAN                0x6B
#define BRSCTRL_CODE_CP_XCPONCANASR             0x6E
#define BRSCTRL_CODE_CP_XCPONFR                 0x6D
#define BRSCTRL_CODE_CP_XCPONLIN                0x6C
#define BRSCTRL_CODE_DIAG                       0x40
#define BRSCTRL_CODE_DIAG_ASRDCM                0xB2
#define BRSCTRL_CODE_DIAG_ASRDEM                0x49
#define BRSCTRL_CODE_DIAG_CANDESC__COREBASE     0x42
#define BRSCTRL_CODE_DIAG_CANDESC__COREBASIC    0x43
#define BRSCTRL_CODE_DIAG_CANDESCGGDAEXT_GM     0x44
#define BRSCTRL_CODE_DIAG_FAULTMEMORY           0x69
#define BRSCTRL_CODE_DIAG_SDCOM_DC              0x46
#define BRSCTRL_CODE_DIAG_X                     0x41
#define BRSCTRL_CODE_DIAGLIN                    0x47
#define BRSCTRL_CODE_DRVCAN                     0x00
#define BRSCTRL_CODE_DRVCAN_BUSOFF              0x01
#define BRSCTRL_CODE_DRVEEP                     0x71
#define BRSCTRL_CODE_DRVFR                      0x0C
#define BRSCTRL_CODE_DRVLIN                     0x05
#define BRSCTRL_CODE_DRVSIO                     0x06
#define BRSCTRL_CODE_DRVSPI                     0x61
#define BRSCTRL_CODE_DRVTRANS                   0x60
#define BRSCTRL_CODE_FBLAPI                     0x75
#define BRSCTRL_CODE_FBLCAN                     0x70
#define BRSCTRL_CODE_FBLDIAG                    0x48
#define BRSCTRL_CODE_FBLHW                      0x76
#define BRSCTRL_CODE_GW_ADMIN_DC                0x37
#define BRSCTRL_CODE_GW_ASRPDUR                 0xB4
#define BRSCTRL_CODE_GW_DYNAMICCANINTERFACE     0x39
#define BRSCTRL_CODE_GW_DYNAMICFRINTERFACE      0x3D
#define BRSCTRL_CODE_GW_GATEWAY                 0x38
#define BRSCTRL_CODE_IF_ASRIFCAN                0x02
#define BRSCTRL_CODE_IF_ASRIFLIN                0x07
#define BRSCTRL_CODE_IF_ASRIFFR                 0x0D
#define BRSCTRL_CODE_IL_ASRCOM                  0x18
#define BRSCTRL_CODE_IL_DBKOM                   0x12
#define BRSCTRL_CODE_IL_DBKOMPWRTRAINEXT_DC     0x13
#define BRSCTRL_CODE_IL_GMLAN2X                 0x11
#define BRSCTRL_CODE_IL_MM_BMW                  0x14
#define BRSCTRL_CODE_IL_NI_FORD                 0x16
#define BRSCTRL_CODE_IL_VECTOR                  0x10
#define BRSCTRL_CODE_ILFR_SIGIF_VECTOR          0x19
#define BRSCTRL_CODE_NM_ASRNMCAN                0x96
#define BRSCTRL_CODE_NM_ASRNMCANWRAPPEREXT      0x98
#define BRSCTRL_CODE_NM_ASRNMIF                 0x9C
#define BRSCTRL_CODE_NM_ASRNMFR                 0x25
#define BRSCTRL_CODE_NM_ASRNMFR_VAG             0x9D
#define BRSCTRL_CODE_NM_ASRNMGENERIC            0x95
#define BRSCTRL_CODE_NM_ASRNMGENERIC_VAG        0x9B
#define BRSCTRL_CODE_NM_CLASSB_FIAT             0x24
#define BRSCTRL_CODE_NM_DIROSEK                 0x20
#define BRSCTRL_CODE_NM_DIROSEKUSERDATA_DC      0x17
#define BRSCTRL_CODE_NM_GMLAN_GM                0x22
#define BRSCTRL_CODE_NM_IND_VAG                 0x2C
#define BRSCTRL_CODE_NM_INDOSEK                 0x21
#define BRSCTRL_CODE_NM_IVLAN                   0x23
#define BRSCTRL_CODE_NM_JUNIOR                  0x26
#define BRSCTRL_CODE_NM_PWRTRAIN_FIAT           0x28
#define BRSCTRL_CODE_NM_PWRTRAIN_MAZDA          0x97
#define BRSCTRL_CODE_NM_BCAN_HONDA              0x27
#define BRSCTRL_CODE_NM_PWRTRAIN_MMC            0x2D
#define BRSCTRL_CODE_NM_PWRTRAIN_VAG            0x2E
#define BRSCTRL_CODE_NM_PWRTRAINBASIC           0x93
#define BRSCTRL_CODE_NM_STMGRINDOSEK_PSARENAULT 0x94
#define BRSCTRL_CODE_NM_STMGRINDOSEK_LS         0x99
#define BRSCTRL_CODE_NM_STMGRINDOSEK_HS         0x9A
#define BRSCTRL_CODE_QNX_WRAPPERMD              0x80
#define BRSCTRL_CODE_QNX_WRAPPERQNX             0x81
#define BRSCTRL_CODE_SAFETY_LAYERCAN            0xB8
#define BRSCTRL_CODE_SYSSERVICE_ASRCRC          0xB5
#define BRSCTRL_CODE_SYSSERVICE_ASRDET          0xA3
#define BRSCTRL_CODE_SYSSERVICE_ASRECUM         0xB3
#define BRSCTRL_CODE_SYSSERVICE_ASRFIM          0xB7
#define BRSCTRL_CODE_SYSSERVICE_CMPR            0xB6
#define BRSCTRL_CODE_SYSSERVICE_CRC_BMW         0xB1
#define BRSCTRL_CODE_SYSSERVICE_FIM_BMW         0xB0
#define BRSCTRL_CODE_TP_16_VAG                  0x32
#define BRSCTRL_CODE_TP_20_VAG                  0x33
#define BRSCTRL_CODE_TP_ASRTPCAN                0x3A
#define BRSCTRL_CODE_TPFR_ASRTPFR               0x3B
#define BRSCTRL_CODE_TP_ISO15765                0x31
#define BRSCTRL_CODE_TP_ISO15765SINGLECHANNEL   0x30
#define BRSCTRL_CODE_TP_MCNET                   0x34
#define BRSCTRL_CODE_TPLIN                      0x35
#define BRSCTRL_CODE_VDOCCL_COMMON              0x51
#define BRSCTRL_CODE_VDOIL_CMH                  0x15
#define BRSCTRL_CODE_VDOTP_IVLAN                0x36
#define BRSCTRL_CODE_ZBRS                       0xF0
#define BRSCTRL_CODE_ZTSI                       0xA0

/*
 * Description: Compatibility defines used to keep compatibility
 *              with older testsuites. Names used for BRSCTRL_CODE
 *              and BrsCmdIn have changed to ClearQuest names.
 *              Don't use old names any more!
 */
#define BRSCTRL_CODE_DPM             BRSCTRL_CODE_CCL_DPM
#define BRSCTRL_CODE_CCP             BRSCTRL_CODE_CP_CCP
#define BRSCTRL_CODE_XCP             BRSCTRL_CODE_CP_XCP
#define BRSCTRL_CODE_AUTOSAR_DCM     BRSCTRL_CODE_DIAG_ASRDCM
#define BRSCTRL_CODE_CANDESC         BRSCTRL_CODE_DIAG_CANDESC__COREBASE
#define BRSCTRL_CODE_CANDESC_BASIC   BRSCTRL_CODE_DIAG_CANDESC__COREBASIC
#define BRSCTRL_CODE_FRFM            BRSCTRL_CODE_DIAG_FAULTMEMORY
#define BRSCTRL_CODE_SDCOM           BRSCTRL_CODE_DIAG_SDCOM_DC
#define BRSCTRL_CODE_DIAG_LIN        BRSCTRL_CODE_DIAGLIN
#define BRSCTRL_CODE_CAN_DRV         BRSCTRL_CODE_DRVCAN
#define BRSCTRL_CODE_FBL_EEPDRV      BRSCTRL_CODE_DRVEEP
#define BRSCTRL_CODE_DRV_FLEXRAY     BRSCTRL_CODE_DRVFR
#define BRSCTRL_CODE_LIN_DRV         BRSCTRL_CODE_DRVLIN
#define BRSCTRL_CODE_SPI             BRSCTRL_CODE_DRVSPI
#define BRSCTRL_CODE_SBC             BRSCTRL_CODE_DRVTRANS
#define BRSCTRL_CODE_FBL             BRSCTRL_CODE_FBLAPI
#define BRSCTRL_CODE_GW_AS_DC        BRSCTRL_CODE_GW_ADMIN_DC
#define BRSCTRL_CODE_GW_CAN_DC       BRSCTRL_CODE_GW_GATEWAY
#define BRSCTRL_CODE_IL_GM           BRSCTRL_CODE_IL_GMLAN2X
#define BRSCTRL_CODE_IL_MM           BRSCTRL_CODE_IL_MM_BMW
#define BRSCTRL_CODE_IL_NI           BRSCTRL_CODE_IL_NI_FORD
#define BRSCTRL_CODE_NM_FIAT15       BRSCTRL_CODE_NM_CLASSB_FIAT
#define BRSCTRL_CODE_NM_FIAT30       BRSCTRL_CODE_NM_CLASSB_FIAT
#define BRSCTRL_CODE_NM_FIAT_MASTER  BRSCTRL_CODE_NM_CLASSB_FIAT
#define BRSCTRL_CODE_NM_OSEK_D       BRSCTRL_CODE_NM_DIROSEK
#define BRSCTRL_CODE_NM_OSEK_D_UD    BRSCTRL_CODE_NM_DIROSEKUSERDATA_DC
#define BRSCTRL_CODE_NM_GMLAN        BRSCTRL_CODE_NM_GMLAN_GM
#define BRSCTRL_CODE_NM_VAGC         BRSCTRL_CODE_NM_IND_VAG
#define BRSCTRL_CODE_NM_OSEK_I       BRSCTRL_CODE_NM_INDOSEK
#define BRSCTRL_CODE_NM_FIATC        BRSCTRL_CODE_NM_PWRTRAIN_FIAT
#define BRSCTRL_CODE_NM_MAZDA        BRSCTRL_CODE_NM_PWRTRAIN_MAZDA
#define BRSCTRL_CODE_NM_PT           BRSCTRL_CODE_NM_PWRTRAIN_MMC
#define BRSCTRL_CODE_NMH             BRSCTRL_CODE_NM_PWRTRAIN_VAG
#define BRSCTRL_CODE_NM_BASIC        BRSCTRL_CODE_NM_PWRTRAINBASIC
#define BRSCTRL_CODE_SYSSERVICE_FIM  BRSCTRL_CODE_SYSSERVICE_FIM_BMW
#define BRSCTRL_CODE_STAT_MGR        BRSCTRL_CODE_NM_STMGRINDOSEK_PSARENAULT
#define BRSCTRL_CODE_TP_ASRTPFR      BRSCTRL_CODE_TPFR_ASRTPFR
#define BRSCTRL_CODE_TP_VW16         BRSCTRL_CODE_TP_16_VAG
#define BRSCTRL_CODE_TP_VW20         BRSCTRL_CODE_TP_20_VAG
#define BRSCTRL_CODE_TP_ISO_MC       BRSCTRL_CODE_TP_ISO15765
#define BRSCTRL_CODE_TP_ISO_SC       BRSCTRL_CODE_TP_ISO15765SINGLECHANNEL
#define BRSCTRL_CODE_TP_ISO_LIN      BRSCTRL_CODE_TPLIN
#define BRSCTRL_CODE_CIO             BRSCTRL_CODE_VDOCCL_COMMON
#define BRSCTRL_CODE_IL_CMHA         BRSCTRL_CODE_VDOIL_CMH
#define BRSCTRL_CODE_TP_IVLAN        BRSCTRL_CODE_VDOTP_IVLAN
#define BRSCTRL_CODE_BRS             BRSCTRL_CODE_ZBRS
#define BRSCTRL_CODE_COMMON_VSTDLIB  BRSCTRL_CODE_VSTDLIB

#define BrsCmdInCCL                  BrsCmdInCcl
#define BrsCmdInDPM                  BrsCmdInCcl_Dpm
#define BrsCmdInCCP                  BrsCmdInCp_Ccp
#define BrsCmdInXCP                  BrsCmdInCp_Xcp
#define BrsCmdInDIAG                 BrsCmdInDiag
#define BrsCmdInDCM                  BrsCmdInDiag_AsrDcm
#define BrsCmdInCANDESC              BrsCmdInDiag_CanDesc__coreBase
#define BrsCmdInCANDESC_BASIC        BrsCmdInDiag_CanDesc__coreBasic
#define BrsCmdInFRFM                 BrsCmdInDiag_FaultMemory
#define BrsCmdInSDCOM                BrsCmdInDiag_Sdcom_Dc
#define BrsCmdInDIAG_X               BrsCmdInDiag_X
#define BrsCmdInTP_DIAG              BrsCmdInDiagLin
#define BrsCmdInCAN                  BrsCmdInDrvCan
#define BrsCmdInCAN_BusOff           BrsCmdInDrvCan_BusOff
#define BrsCmdInFBL_EEPDRV           BrsCmdInDrvEep
#define BrsCmdInDRV_FLEXRAY          BrsCmdInDrvFr
#define BrsCmdInLIN                  BrsCmdInDrvLin
#define BrsCmdInSIO                  BrsCmdInDrvSio
#define BrsCmdInSPI                  BrsCmdInDrvSpi
#define BrsCmdInSBC                  BrsCmdInDrvTrans
#define BrsCmdInFBL                  BrsCmdInFblApi
#define BrsCmdInDiagFBL              BrsCmdInFblCan
#define BrsCmdInFBLApi               BrsCmdInFblDiag
#define BrsCmdInFBLHW                BrsCmdInFblHw
#define BrsCmdInGW_AS_DC             BrsCmdInGw_Admin_Dc
#define BrsCmdInGW_CAN_DC            BrsCmdInGw_Gateway
#define BrsCmdInIf_AsrIfCan          BrsCmdInIf_AsrIfCan
#define BrsCmdInIf_AsrIfFr           BrsCmdInIf_AsrIfFr
#define BrsCmdInDBKOM                BrsCmdInIl_Dbkom
#define BrsCmdInMM                   BrsCmdInIl_Mm_Bmw
#define BrsCmdInIL_NI                BrsCmdInIl_Ni_Ford
#define BrsCmdInIL_VECTOR            BrsCmdInIl_Vector
#define BrsCmdInNM_ASRNMCAN          BrsCmdInNm_AsrNmCan
#define BrsCmdInNM_ASRNMGENERIC      BrsCmdInNm_AsrNmGeneric
#define BrsCmdInNMFIAT15             BrsCmdInNm_ClassB_Fiat
#define BrsCmdInNMFIAT30             BrsCmdInNm_ClassB_Fiat
#define BrsCmdInNMFIAT_MASTER        BrsCmdInNm_ClassB_Fiat
#define BrsCmdInNMOSEK_D             BrsCmdInNm_DirOsek
#define BrsCmdInNMOSEK_D_UD          BrsCmdInNm_DirOsekUserdata_Dc
#define BrsCmdInNMGMLAN              BrsCmdInNm_Gmlan_Gm
#define BrsCmdInNMVAGC               BrsCmdInNm_Ind_Vag
#define BrsCmdInNMOSEK_I             BrsCmdInNm_IndOsek
#define BrsCmdInNMIVLAN              BrsCmdInNm_Ivlan
#define BrsCmdInNMJUNIOR             BrsCmdInNm_Junior
#define BrsCmdInNMFIATC              BrsCmdInNm_PwrTrain_Fiat
#define BrsCmdInNMFIATC_STD          BrsCmdInNm_PwrTrain_Fiat
#define BrsCmdInNM_MAZDA             BrsCmdInNm_PwrTrain_Mazda
#define BrsCmdInNMPT                 BrsCmdInNm_PwrTrain_Mmc
#define BrsCmdInNMH                  BrsCmdInNm_PwrTrain_Vag
#define BrsCmdInNM_BASIC             BrsCmdInNm_PwrTrainBasic
#define BrsCmdInFIM                  BrsCmdInSysService_Fim_Bmw
#define BrsCmdInSTAT_MGR             BrsCmdInNm_StMgrIndOsek_PsaRenault
#define BrsCmdInTP_VW16              BrsCmdInTp_16_Vag
#define BrsCmdInTP_VW20              BrsCmdInTp_20_Vag
#define BrsCmdInTP_ISO_MC            BrsCmdInTp_Iso15765
#define BrsCmdInTP_ISO_SC            BrsCmdInTp_Iso15765SingleChannel
#define BrsCmdInTP_MCNET             BrsCmdInTp_McNet
#define BrsCmdInTP_ISO_LIN           BrsCmdInTpLin
#define BrsCmdInCIO                  BrsCmdInVdoCcl_Common
#define BrsCmdInCMHA                 BrsCmdInVdoIl_Cmh
#define BrsCmdInTp_AsrTpFr           BrsCmdInTpFr_AsrTpFr
#define BrsCmdInTP_IVLAN             BrsCmdInVdoTp_Ivlan
#define BrsCmdInCommon_VStdLib       BrsCmdInVStdLib

/* 
 * Description: V_MEMROMX defines are defined in v_def.h
 *              As they might be missing in former deliveries these compatibiliy
 *              defines are introduces here.
 */
#ifndef V_MEMROM0 
#define V_MEMROM0
#endif

#ifndef V_MEMROM1
#define V_MEMROM1
#endif

#ifndef V_MEMROM2
#define V_MEMROM2 MEMORY_ROM
#endif

/*
 * Description: Interface definition defines (BRSCTRL_USE_*)
 *              used for selecting the necessary precopy routine depending
 *              on the available bus interface.
 */
#define BRSCTRL_USE_HW
#define BRSCTRL_USE_MAIN

#if defined( VGEN_ENABLE_CAN_DRV )
#  if defined( VGEN_ENABLE_IF_ASRIFCAN )
#    define BRSCTRL_USE_CAN_DRV_ASR
#  elif defined( VGEN_ENABLE_FBL ) || \
        defined( VGEN_ENABLE_CANFBL )
#    define BRSCTRL_USE_DIAG
#    if defined( BRS_ENABLE_OSEKOS )
#    else
#      undef BRSCTRL_USE_HW
#      undef BRSCTRL_USE_MAIN
#    endif
#  else
#    define BRSCTRL_USE_CAN_DRV_HIS
#  endif
#elif defined( VGEN_ENABLE_LIN_DRV )
#  if defined( VGEN_ENABLE_IF_ASRIFLIN )
#    define BRSCTRL_USE_LIN_DRV_ASR
#  else
#    define BRSCTRL_USE_LIN_DRV
#  endif
#elif defined( VGEN_ENABLE_MOST_DRV )
#  define BRSCTRL_USE_MOST_DRV
#elif defined( VGEN_ENABLE_FBL ) || \
      defined( VGEN_ENABLE_CANFBL )
#  define BRSCTRL_USE_DIAG
#  if defined( BRS_ENABLE_OSEKOS )
#  else
#    undef  BRSCTRL_USE_HW
#    undef  BRSCTRL_USE_MAIN
#  endif
#else
#  define BRSCTRL_UNKNOWN_INTERFACE
#endif
#endif /*BRS_ENABLE_TESTCONTROL*/

/*******************************************************************************
* Global types
*******************************************************************************/
#if defined( VGEN_ENABLE_CCL )
typedef enum eBrsCtrlBusType {
  eBrsCtrlBusTypeCAN=1,
  eBrsCtrlBusTypeLIN=2,
  eBrsCtrlBusTypeALL=0xFF
} eBrsCtrlBusType;
#endif

/*******************************************************************************
* Global variables
*******************************************************************************/

/****************************************************************************/
#if defined( BRS_ENABLE_TESTCONTROL )
/**
 * \var gbBrsCtrlMsgBuffer
 *      Global BRS Message Buffer used for test control data handling.
 */
extern vuint8 gbBrsCtrlMsgBuffer[8];

/**
 * \var gbBrsCtrlCompUnderTestCI
 *      Global TS state (holds ci of active component under test)
 */
extern vuint8 gbBrsCtrlCompUnderTestCI;

#if defined( VGEN_ENABLE_CAN_DRV_ASR ) || \
    defined( VGEN_ENABLE_CAN_DRV_HIS )
/**
 * \var gbBrsCtrlRetryTransmit
 *      This variable indicates whether the transmission has to be retried or not.
 */
extern vuint8 gbBrsCtrlRetryTransmit;
#endif /*VGEN_ENABLE_CAN_DRV_* */
#endif /*BRS_ENABLE_TESTCONTROL*/


/*******************************************************************************
* Global const variables
*******************************************************************************/
#if defined ( C_COMP_IAR_M16C )
#if defined ( _NEAR_ )
 /* Set const data to const segment, don't initialize */
 #pragma memory=constseg(CONST_DATA) :far
#endif
#endif /*C_COMP_IAR_M16C*/

/** 
 * \var kBrsCtrlMainVersion
 *      Stores the BCD coded main-version of this file.
 */
 /**
 * \var kBrsCtrlSubVersion 
 *      Stores the BCD coded sub-version of this file.
 */
 /**
 * \var kBrsCtrlReleaseVersion 
 *      Stores the BCD coded release-version of this file.
 */
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kBrsCtrlMainVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kBrsCtrlSubVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kBrsCtrlReleaseVersion;

#if defined ( C_COMP_IAR_M16C )
#if defined ( _NEAR_ )
  /* Normal segment usage */
  #pragma memory=default
#endif
#endif /*C_COMP_IAR_M16C*/



#if defined( BRSCTRL_USE_CAN_DRV_HIS )
/*
 * Description: CANbedded CAN driver header.
 */
#  include "can_inc.h"
#endif /* BRSCTRL_USE_CAN_DRV_* */

/*****************************************************************************/
/**
 * \brief Check if a ITS is running.
 *        Call with BRSCTRL_CODE_<component name> as parameter
 *        
 * \retval true if test is running for this component, false otherwise
 */
#define BrsTccIsCompUnderTest(ci) (gbBrsCtrlCompUnderTestCI == (ci))

/*******************************************************************************
* Function protoytpes
*******************************************************************************/

#if defined( BRS_ENABLE_TESTCONTROL )
/*******************************************************************************/
/**
 * \brief BrsCtrl initialization at poweron/reset
 *        This function has to be used to initialize the TCC at a power up 
 *        situation. This is necessary to initialize all TCC internal variables 
 *        and states.
 *
 * \pre       Hardware (power supply and clocks) is initialized, global
 *            interrupts are disabled.
 *
 * \post      BrsCtrl is initialized and could be used now.
 */
void BrsCtrlInitPowerOn( 
  void 
);


/*******************************************************************************/
/**
 * \brief This API is used by each test suite implementation to send an already
 *        prepared TCC response back.
 *
 * \attention Don't use this function directly. Use BrsCtrlSendPosResponse or 
 *            BrsCtrlSendNegResponse instead!
 *
 * \post      The TCC will send its answer as soon as possible.
 */
void BrsCtrlSendResponse( 
  void 
);


/*******************************************************************************/
/**
 * \brief This API is used by each test suite implementation to send an POSITIV
 *        response to the TCC. The 0x40 will be added to the SId here.
 *
 * \attention Make sure the answer is valid! E.g. the 0x40 has NOT been added
 *            the requested SId in the calling test suite!
 *
 * \post      The TCC will send its answer as soon as possible.
 */
void BrsCtrlSendPosResponse( 
  void
);


/*******************************************************************************/
/**
 * \brief This API is used by each test suite implementation to send an NEGATIV
 *        response to the TCC.
 *
 * \param[in] ErrorCode has to be selected as specificed in the BrsCtrl header.
 *
 * \post      The TCC will send its answer as soon as possible.
 */
void BrsCtrlSendNegResponse(
  vuint8 ErrorCode
);

/*****************************************************************************/
/**
 * \brief Retry transmission of TCC response if transmission queue is deactivated
 *        If the transmission of the TCC response failes
 *        it has to be retried till it is transmitted.
 *        If the pre conditions are not all set, this funtion returns immediately
 *
 * \pre CAN is used, transmit queue is enabled and the testcontrol is enabled 
 *
 * \attentention This function has to be called periodically
 *               (usually BrsMainMilliSecondHandler).
 *
 * \post      The TCC tries to send the message immediately setting a global flag
 *            with the outcome.
 */
void BrsCtrlRetryTransmit(
  void
);

#if defined( BRSCTRL_USE_DIAG )
vuint8 BrsCtrlPrecopy( vuint8 *Rx_Ptr, vuint8 *Tx_Ptr );
#elif defined( VGEN_ENABLE_IF_ASRIFLIN )
vuint8 BrsCtrlPrecopy( vuint8 *datPtr );
void BrsCtrlRequestResponse(vuint8 * pData);
void BrsCtrlConfirmation(void);
#endif

/*******************************************************************************/
/**
 * \brief Local command interpreter for <component>
 *        Handles the TCC Protocol part of the <component>
 *
 * \pre   gbBrsCtrlMsgBuffer contains a 8 byte message
 *
 * \post  The TCC request to CI=BRS has been answered.
 */
#if defined( VGEN_ENABLE_CCL )
void BrsCmdInCcl( void );
#endif
#if defined( VGEN_ENABLE_CCL_ASRCOMM )
void BrsCmdInCcl_AsrComM( void );
#endif
#if defined( VGEN_ENABLE_CCLCOM )
void BrsCmdInCcl_CclCom( void );
#endif
#if defined( VGEN_ENABLE_DPM )
void BrsCmdInCcl_Dpm( void );
#endif
void BrsCmdInCommon_Vdef( void );
#if defined( VGEN_ENABLE_VSTDLIB )
void BrsCmdInVStdLib( void );
#endif
#if defined( VGEN_ENABLE_CCP )
void BrsCmdInCp_Ccp( void );
#endif
#if defined( VGEN_ENABLE_XCP )
void BrsCmdInCp_Xcp( void );
#endif
#if defined( VGEN_ENABLE_XCPONCAN )
void BrsCmdInCp_XcpOnCan( void );
#endif
#if defined( VGEN_ENABLE_XCPONCANASR )
void BrsCmdInCp_XcpOnCanAsr(void );
#endif
#if defined( VGEN_ENABLE_XCPONFR )
void BrsCmdInCp_XcpOnFr( void );
#endif
#if defined( VGEN_ENABLE_XCPONLIN )
void BrsCmdInCp_XcpOnLin( void );
#endif
#if defined( VGEN_ENABLE_DIAG_STANDARD )
void BrsCmdInDiag( void );
#endif
#if defined( VGEN_ENABLE_COMSERV_DCM )
void BrsCmdInDiag_AsrDcm( void );
#endif
#if defined( VGEN_ENABLE_DIAG_ASRDEM )
void BrsCmdInDiag_AsrDem( void );
#endif
#if defined( VGEN_ENABLE_DIAG_CANDESC )     || \
    defined( VGEN_ENABLE_DIAG_CANDESC_DCM ) || \
    defined( VGEN_ENABLE_DIAG_CANDESC_KWP ) || \
    defined( VGEN_ENABLE_DIAG_CANDESC_UDS )
void BrsCmdInDiag_CanDesc__coreBase( void );
#endif
#if defined( VGEN_ENABLE_DIAG_CANDESC_BASIC )     || \
    defined( VGEN_ENABLE_DIAG_CANDESC_BASIC_DCM ) || \
    defined( VGEN_ENABLE_DIAG_CANDESC_BASIC_KWP ) || \
    defined( VGEN_ENABLE_DIAG_CANDESC_BASIC_UDS )
void BrsCmdInDiag_CanDesc__coreBasic( void );
#endif
#if defined( VGEN_ENABLE_DIAG_CANDESCGGDAEXT_GM )
void BrsCmdInDiag_CanDescGgdaExt_Gm( void );
#endif
#if defined( VGEN_ENABLE_FRFM ) || \
    defined( VGEN_ENABLE_DIAG_FAULTMEMORY )
void BrsCmdInDiag_FaultMemory( void );
#endif
#if defined( VGEN_ENABLE_SDCOM ) 
void BrsCmdInDiag_Sdcom_Dc( void );
#endif
#if defined( VGEN_ENABLE_DIAG_X ) 
void BrsCmdInDiag_X( void );
#endif
#if defined( VGEN_ENABLE_DIAGLIN ) 
void BrsCmdInDiagLin( void );
#endif
#if defined( VGEN_ENABLE_CAN_DRV ) 
void BrsCmdInDrvCan( void );
void BrsCmdInDrvCan_BusOff( void );
#endif
#if defined( VGEN_ENABLE_FBL_EEPDRV ) 
void BrsCmdInDrvEep( void );
#endif
#if defined( VGEN_ENABLE_DRV_FLEXRAY ) 
void BrsCmdInDrvFr( void );
#endif
#if defined( VGEN_ENABLE_LIN_DRV ) 
void BrsCmdInDrvLin( void );
#  if defined ( BRSCTRL_USE_LIN_DRV )
void BrsCmdInDrvSio( void );
#  endif
#endif
#if defined( VGEN_ENABLE_SPI ) 
void BrsCmdInDrvSpi( void );
#endif
#if defined( VGEN_ENABLE_SBC_DRV ) 
void BrsCmdInDrvTrans( void );
#endif
#if defined( VGEN_ENABLE_FBL ) || \
    defined( VGEN_ENABLE_CANFBL )
void BrsCmdInFblCan( void );
void BrsCmdInFblDiag( void );
void BrsCmdInFblApi( void );
void BrsCmdInFblHw( void );
#endif
#if defined( VGEN_ENABLE_GW_AS_DC ) 
void BrsCmdInGw_Admin_Dc( void );
#endif
#if defined( VGEN_ENABLE_GW_ASRPDUR ) 
void BrsCmdInGw_AsrPduR( void );
#endif
#if defined( VGEN_ENABLE_DCI ) 
void BrsCmdInGw_DynamicCanInterface( void );
#endif
#if defined( VGEN_ENABLE_GW_DYNAMICFRINTERFACE ) 
void BrsCmdInGw_DynamicFrInterface( void );
#endif
#if defined( VGEN_ENABLE_GW_CAN_DC ) 
void BrsCmdInGw_Gateway( void );
#endif
#if defined( VGEN_ENABLE_IF_ASRIFCAN ) 
void BrsCmdInIf_AsrIfCan( void );
#endif
#if defined( VGEN_ENABLE_IF_ASRIFLIN ) 
void BrsCmdInIf_AsrIfLin( void );
#endif
#if defined( VGEN_ENABLE_IF_ASRIFFR )
void BrsCmdInIf_AsrIfFr( void );
#endif
#if defined( VGEN_ENABLE_IL_ASRCOM )
void BrsCmdInIl_AsrCom( void );
#endif
#if defined( VGEN_ENABLE_IL_DBKOM )
void BrsCmdInIl_Dbkom( void );
#endif
#if defined( VGEN_ENABLE_IL_DBKOMPWRTRAINEXT_DC )
void BrsCmdInIl_DbkomPwrTrainExt_Dc( void );
#endif
#if defined( VGEN_ENABLE_IL_GM )
void BrsCmdInIl_Gmlan2x( void );
#endif
#if defined( VGEN_ENABLE_IL_MM )
void BrsCmdInIl_Mm_Bmw( void );
#endif
#if defined( VGEN_ENABLE_ILFR_SIGIF_VECTOR )
void BrsCmdInIlFr_SigIf_Vector( void );
#endif
#if defined( VGEN_ENABLE_NM_ILNI ) || \
    defined( VGEN_ENABLE_IL_NI )
void BrsCmdInIl_Ni_Ford( void );
#endif
#if defined( VGEN_ENABLE_IL_VECTOR )
void BrsCmdInIl_Vector( void );
#endif
#if defined( VGEN_ENABLE_NM_ASR_CAN )
void BrsCmdInNm_AsrNmCan( void );
#endif
#if defined( VGEN_ENABLE_NM_ASRNMCANWRAPPEREXT )
void BrsCmdInNm_AsrNmCanWrapperExt( void );
#endif
#if defined( VGEN_ENABLE_NM_ASRNMFR )
void BrsCmdInNm_AsrNmFr( void );
#endif
#if defined( VGEN_ENABLE_NM_ASRNMFR_VAG )
void BrsCmdInNm_AsrNmFr_Vag( void );
#endif
#if defined( VGEN_ENABLE_NM_ASRIF )
void BrsCmdInNm_AsrNmIf( void );
#endif
#if defined( VGEN_ENABLE_NM_ASR_GENERIC )
void BrsCmdInNm_AsrNmGeneric( void );
#endif
#if defined( VGEN_ENABLE_NM_ASR_GENERIC_VAG )
void BrsCmdInNm_AsrNmGeneric_Vag( void );
#endif
#if defined( VGEN_ENABLE_NM_FIAT15  ) || \
    defined( VGEN_ENABLE_NM_FIAT30 )  || \
    defined( VGEN_ENABLE_NM_FIAT_MASTER )
void BrsCmdInNm_ClassB_Fiat( void );
#endif
#if defined( VGEN_ENABLE_NM_OSEK_D )
void BrsCmdInNm_DirOsek( void );
#endif
#if defined( VGEN_ENABLE_NM_OSEK_D_UD )
void BrsCmdInNm_DirOsekUserdata_Dc( void );
#endif
#if defined( VGEN_ENABLE_NM_GMLAN )
void BrsCmdInNm_Gmlan_Gm( void );
#endif
#if defined( VGEN_ENABLE_NMVAGC )        || \
    defined( VGEN_ENABLE_NMVAGC_BASIC )  || \
    defined( VGEN_ENABLE_NMVAGC_MASTER ) || \
    defined( VGEN_ENABLE_NMVAGC_SLAVE )
void BrsCmdInNm_Ind_Vag( void );
#endif
#if defined( VGEN_ENABLE_NM_OSEK_I )
void BrsCmdInNm_IndOsek( void );
#endif
#if defined( VGEN_ENABLE_NM_IVLAN )
void BrsCmdInNm_Ivlan( void );
#endif
#if defined( VGEN_ENABLE_NM_JUNIOR )
void BrsCmdInNm_Junior( void );
#endif
#if defined( VGEN_ENABLE_NM_FIATC ) || \
    defined( VGEN_ENABLE_NMFIATC_STD )
void BrsCmdInNm_PwrTrain_Fiat( void );
#endif
#if defined( VGEN_ENABLE_NM_MAZDA )
void BrsCmdInNm_PwrTrain_Mazda( void );
#endif
#if defined( VGEN_ENABLE_NM_BCAN_HONDA )
void BrsCmdInNm_Bcan_Honda( void );
#endif
#if defined( VGEN_ENABLE_NM_PT )
void BrsCmdInNm_PwrTrain_Mmc( void );
#endif
#if defined( VGEN_ENABLE_NMHIGH )
void BrsCmdInNm_PwrTrain_Vag( void );
#endif
#if defined( VGEN_ENABLE_NM_BASIC )
void BrsCmdInNm_PwrTrainBasic( void );
#endif
#if defined( VGEN_ENABLE_NM_OSEK_I )
void BrsCmdInNm_StMgrIndOsek_PsaRenault( void );
#endif
#if defined( VGEN_ENABLE_NM_OSEK_I )
void BrsCmdInNm_StMgrIndOsek_Ls( void );
#endif
#if defined( VGEN_ENABLE_NM_OSEK_I_HS )
void BrsCmdInNm_StMgrIndOsek_Hs( void );
#endif
#if defined( VGEN_ENABLE_QNX_WRAPPERMD )
void BrsCmdInQnx_WrapperMd( void );
#endif
#if defined( VGEN_ENABLE_QNX_WRAPPERQNX )
void BrsCmdInQnx_WrapperQnx( void );
#endif
#if defined( VGEN_ENABLE_SAFETY_LAYERCAN )
void BrsCmdInSysSafety_LayerCan( void );
#endif
#if defined( VGEN_ENABLE_SYSSERVICE_ASRCRC )
void BrsCmdInSysService_AsrCrc( void );
#endif
#if defined( VGEN_ENABLE_SYSSERVICE_ASRDET )
void BrsCmdInSysService_AsrDet( void );
#endif
#if defined( VGEN_ENABLE_SYSSERVICE_ASRECUM )
void BrsCmdInSysService_AsrEcuM( void );
#endif
#if defined( VGEN_ENABLE_SYSSERVICE_ASRFIM )
void BrsCmdInSysService_AsrFim( void );
#endif
#if defined( VGEN_ENABLE_SYS_SERV_FIM )
void BrsCmdInSysService_Fim_Bmw( void );
#endif
#if defined( VGEN_ENABLE_SYSSERVICE_CMPR )
void BrsCmdInSysService_Cmpr( void );
#endif
#if defined( VGEN_ENABLE_SYSSERVICE_CRC_BMW )
void BrsCmdInSysService_Crc_Bmw( void );
#endif
#if defined( VGEN_ENABLE_TP_VW16 )
void BrsCmdInTp_16_Vag( void );
#endif
#if defined( VGEN_ENABLE_TP_VW20 )
void BrsCmdInTp_20_Vag( void );
#endif
#if defined( VGEN_ENABLE_TP_ASRTPCAN )
void BrsCmdInTp_AsrTpCan( void );
#endif
#if defined( VGEN_ENABLE_TP_ASRTPFR )
void BrsCmdInTpFr_AsrTpFr( void );
#endif
#if defined( VGEN_ENABLE_TP_ISO_MC )
void BrsCmdInTp_Iso15765( void );
#endif
#if defined( VGEN_ENABLE_TP_ISO_SC )
void BrsCmdInTp_Iso15765SingleChannel( void );
#endif
#if defined( VGEN_ENABLE_TP_MCNET )
void BrsCmdInTp_McNet( void );
#endif
#if defined( VGEN_ENABLE_TPLIN ) 
void BrsCmdInTpLin( void );
#endif
#if defined( VGEN_ENABLE_CIO )
void BrsCmdInVdoCcl_Common( void );
#endif
#if defined( VGEN_ENABLE_IL_CMHA )
void BrsCmdInVdoIl_Cmh( void );
#endif
#if defined( VGEN_ENABLE_TP_IVLAN )
void BrsCmdInVdoTp_Ivlan( void );
#endif
void BrsCmdInzTsi( void );

void ApplBrsRequestCommunication( vuint8 channel );
void ApplBrsReleaseCommunication( vuint8 channel );


#endif /*BRS_ENABLE_TESTCONTROL*/

#endif /*_BRSCTRL_H_*/
/************   Organi, Version 3.6.8 Vector-Informatik GmbH  ************/
