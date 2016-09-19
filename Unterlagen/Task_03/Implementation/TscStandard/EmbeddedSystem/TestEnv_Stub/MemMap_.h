/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2007 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                Please note, that this file contains example configuration used by the 
 *                MICROSAR BSW. This code may influence the behaviour of the MICROSAR BSW
 *                in principle. Therefore, great care must be taken to verify
 *                the correctness of the implementation.
 *
 *                The contents of the originally delivered files are only examples resp. 
 *                implementation proposals. With regard to the fact that these functions
 *                are meant for demonstration purposes only, Vector Informatik's
 *                liability shall be expressly excluded in cases of ordinary negligence, 
 *                to the extent admissible by law or statute.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  _MemMap.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This File is a template for the MemMap.h
 *                This file has to be extended with the memory section defines for all BSW modules
 *                which where used.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Joachim Kalmbach              Jk            Vector Informatik
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2007-08-01  Jk                    Initial creation
 *  01.01.00  2007-12-14  Jk                    Component spesific defines filtering added
 *  01.01.02  2008-11-04  Jk                    Component spesific defines filtering added
 *  01.01.03  2008-12-17  Ht                    Improve list of components  (Tp_AsrTpCan,Tp_AsrTpFr,DrvMcu,DrvIcu added)
 *  01.01.04  2009-04-27  Ht                    improve list of components  (Cp_XcpOnCanAsr, Il_AsrIpduM, If_VxFblDcm,
 *                                              If_VxFblVpm_Volvo_ab, DrvFls added)
 *  01.01.05  2009-04-24  Msr                   Renamed J1939_AsrBase as TpJ1939_AsrBase
 *  01.01.06  2009-06-03  Ht                    Improve list of components (Adc, Dio, Gpt, Pwm, Spi, Wdg, Fls, Port, Fim)
 *  01.02.00  2009-08-01  Ht                    Improve list of components (Fee_30_Inst2, Can, ...Sub)
 *                                              Support filtering for RTE
 *  01.02.01  2009-08-18  HH                    replaced C++ comment by C comment
 *  01.02.02  2009-09-02  Lo                    add external Flash driver support
 *  01.02.03  2009-09-12  Lo                    add DrvFls_Mcs12xFslftm01ExtVx
 *                        Ht                    Improve list of components (CanTrcv_30_Tja1040dio,
 *                                                Eth, EthTrcv, EthIf, SoAd, TcpIp, EthSM)
 *  01.03.00  2009-10-30  Ht                    support R8: change EthTrcv to EthTrcv_30_Canoeemu
 *                                              support EthTrcv_30_Dp83848
 *                                              change CanTrcv_30_Xdio to CanTrcv_30___Your_Trcv__
 *                                              change CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1041
 *                                              change name FrTrcv to FrTrcv_30_Tja1080dio
 *                        Lo                    add Cp_AsrXcp
 *                        Ht                    add Cp_XcpOnFrAsr
 *  01.03.01  2010-01-13  Ht                    support SysService_AsrCal
 *  01.03.02  2010-02-15  Ht                    support SysService_SswRcs_Daimler, SysService_Tls, Tp_Http, 
 *                                                      SysService_Dns, SysService_Json, DrvTrans_GenericLindioAsr
 *                        Lo                    add Diag_AsrDem for all oems
 *                                              rename internal variables and filtermethods
 *  01.04.00  2010-03-04  Ht                    change name FrTrcv_30_Tja1080dio to FrTrcv_30_Tja1080
 *  01.04.01  2010-03-10  Ht                    support DrvTrans_GenericFrAsr, DrvTrans_As8223FrspiAsr, DrvEep and If_AsrIfEa
 *  01.04.02  2010-04-07  Lo                    change IfFee to real components and add If_AsrIfWdV85xNec01Sub
 *  01.04.03  2010-06-11  Ht                    add CanTrcv_30_Tja1043
 *                        Lo                    add Il_AsrIpduMEbBmwSub
 *  01.04.04  2010-08-24  Ht                    add CanTrcv_30_Tle62512G, DrvEep_XAt25128EAsr, Tp_AsrTpFrEbBmwSub
 *  01.05.00  2010-08-24  Ht                    support R10:
 *                                              change LinTrcv_30_Tle7259dio to LinTrcv_30_Tle7259
 *  01.05.01  2010-10-14  Ht                    add VStdLib, SysService_SswScc, SysService_IpBase, SysService_Crypto
 *  01.05.02  2010-10-20  Ht                    support comments for Package Merge Tool
 *  01.05.03  2010-11-03  Ht                    add SysService_E2eLibTttechSub, SysService_E2ePwTttechSub
 *  01.05.04  2010-11-16  Ht                    add SysService_Exi, DrvTrans_Int6400EthAsr, Cdd_AsrCdd_Fiat, Diag_AsrDem_Fiat
 *  01.05.05  2010-12-17  Ht                    add SysService_AsrSchM, DrvEep_XXStubAsr, DrvIcu_Tms570Tinhet01ExtVx
 *                                                  DrvWd_XTle4278gEAsr, DrvWd_XXStubAsr
 *  01.05.06  2011-02-17  Ht                    add DrvEed, SysService_AsrBswM
 *  01.05.07  2011-03-04  Ht                    add DrvTrans_Tja1055CandioAsr
 *                                              rename CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1040
 *                                              add SysService_XmlEngine
 *  01.06.00  2011-03-15  Ht                    support ASR4.0
 *                                              add Ccl_Asr4ComM, Ccl_Asr4SmCan, Nm_Asr4NmIf, Nm_AsrNmDirOsek
 *  01.06.01  2011-04-15  Ht                    add Diag_AsrDcm_<OEM>
 *  01.06.02  2011-06-17  Ht                    correct Diag_AsrDcm_<OEM>
 *                                              add Monitoring_AsrDlt and Monitoring_GenericMeasurement
 *  01.06.03  2011-09-20  Ht                    add DrvTrans_Tja1145CanSpiAsr, DrvTrans_E52013CanspiAsr, DrvFls_XXStubAsr,
 *                                              If_AsrIfFeeV85xNec05Sub, If_AsrIfFeeV85xNec06Sub, If_AsrIfFeeV85xNec07Sub
 *                                              SysService_AsrWdMTttechSub and If_AsrIfWdTttechSub
 *  01.06.04  2011-11-22  Ht                    add If_AsrIfFeeTiSub, 
 *                                              ESCAN00054718: add Cdd_AsrCdd
 *  01.06.05  2011-12-09  Ht                    add Tp_IpV4, Tp_IpV6
 *  01.06.06  2011-12-14  Ht                    add Monitoring_RuntimeMeasurement
 *  01.06.07  2012-01-03  Ht                    add DrvI2c, SysService_Asr4BswM
 *  01.06.08  2012-01-31  Ht                    add DrvTrans_Ar7000EthAsr, DrvTrans_GenericEthmiiAsr
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#undef MEM_VENDOR_ID
#undef MEM_AR_MAJOR_VERSION
#undef MEM_AR_MINOR_VERSION
#undef MEM_AR_PATCH_VERSION
#undef MEM_SW_MAJOR_VERSION
#undef MEM_SW_MINOR_VERSION
#undef MEM_SW_PATCH_VERSION

#define MEM_VENDOR_ID        (30u)

/* AUTOSAR Software Specification Version Information */
/* AUTOSAR Document version 1.1.0 part of release 3.0.1 */
#  define MEM_AR_MAJOR_VERSION       (1u)
#  define MEM_AR_MINOR_VERSION       (1u)
#  define MEM_AR_PATCH_VERSION       (0u)

#define MEM_SW_MAJOR_VERSION (1u)
#define MEM_SW_MINOR_VERSION (6u)
#define MEM_SW_PATCH_VERSION (8u)

#define MEMMAP_ERROR

/* Package Merger: Start Section MemMapModuleList */










/**********************************************************************************************************************
 *  COMM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef COMM_START_SEC_CODE
  #undef COMM_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef COMM_STOP_SEC_CODE
  #undef COMM_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef COMM_START_SEC_APPL_CODE
  #undef COMM_START_SEC_APPL_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef COMM_STOP_SEC_APPL_CODE
  #undef COMM_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef COMM_START_SEC_CONST_8BIT
# undef COMM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT                       /* mapped to default const 8bit section */
#endif
#ifdef COMM_STOP_SEC_CONST_8BIT
# undef COMM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST                             /* default const stop section */
#endif

#ifdef COMM_START_SEC_CONST_16BIT
# undef COMM_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef COMM_STOP_SEC_CONST_16BIT
# undef COMM_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef COMM_START_SEC_CONST_32BIT
# undef COMM_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef COMM_STOP_SEC_CONST_32BIT
# undef COMM_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef COMM_START_SEC_CONST_UNSPECIFIED
# undef COMM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef COMM_STOP_SEC_CONST_UNSPECIFIED
# undef COMM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef COMM_START_SEC_VAR_NOINIT_8BIT
# undef COMM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef COMM_STOP_SEC_VAR_NOINIT_8BIT
# undef COMM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef COMM_START_SEC_VAR_NOINIT_16BIT
# undef COMM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef COMM_STOP_SEC_VAR_NOINIT_16BIT
# undef COMM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef COMM_START_SEC_VAR_NOINIT_32BIT
# undef COMM_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef COMM_STOP_SEC_VAR_NOINIT_32BIT
# undef COMM_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef COMM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef COMM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef COMM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef COMM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef COMM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef COMM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef COMM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef COMM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR NVRAM sections */

#ifdef COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
# undef COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
# undef COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* Postbuild CFG CONST sections */

/* Root pointer to postbuild data */
#ifdef COMM_START_SEC_PBCFG_ROOT
# undef COMM_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef COMM_STOP_SEC_PBCFG_ROOT
# undef COMM_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif
/**********************************************************************************************************************
 *  COMM END
 *********************************************************************************************************************/









/**********************************************************************************************************************
 *  FrSM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FRSM_START_SEC_CODE
  #undef FRSM_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef FRSM_STOP_SEC_CODE
  #undef FRSM_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FRSM_START_SEC_CONST_8BIT
# undef FRSM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT                       /* mapped to default const 8bit section */
#endif
#ifdef FRSM_STOP_SEC_CONST_8BIT
# undef FRSM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST                             /* default const stop section */
#endif

#ifdef FRSM_START_SEC_CONST_16BIT
# undef FRSM_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT                       /* mapped to default const 8bit section */
#endif
#ifdef FRSM_STOP_SEC_CONST_16BIT
# undef FRSM_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST                             /* default const stop section */
#endif

#ifdef FRSM_START_SEC_CONST_32BIT
# undef FRSM_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef FRSM_STOP_SEC_CONST_32BIT
# undef FRSM_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef FRSM_START_SEC_CONST_UNSPECIFIED
# undef FRSM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FRSM_STOP_SEC_CONST_UNSPECIFIED
# undef FRSM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/* FAST CONST sections */



/* Postbuild CFG CONST sections */

/* Root pointer to postbuild data */
#ifdef FRSM_START_SEC_PBCFG_ROOT
# undef FRSM_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef FRSM_STOP_SEC_PBCFG_ROOT
# undef FRSM_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

/* Tables for postbuild data */
#ifdef FRSM_START_SEC_PBCFG
# undef FRSM_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef FRSM_STOP_SEC_PBCFG
# undef FRSM_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */


/* VAR NOINIT sections */

#ifdef FRSM_START_SEC_VAR_NOINIT_8BIT
# undef FRSM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef FRSM_STOP_SEC_VAR_NOINIT_8BIT
# undef FRSM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef FRSM_START_SEC_VAR_NOINIT_16BIT
# undef FRSM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef FRSM_STOP_SEC_VAR_NOINIT_16BIT
# undef FRSM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef FRSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FRSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef FRSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FRSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef FRSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef FRSM_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef FRSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FRSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

/* VAR FAST INIT sections */


/* VAR FAST NOINIT sections */


/* VAR FAST ZERO INIT sections */



/**********************************************************************************************************************
 *  FrSM END
 *********************************************************************************************************************/






/**********************************************************************************************************************
 *  Cdd_AsrCdd START 
 *********************************************************************************************************************/
/* Copy the memory mapping defines for each of your configured CDDs and replace the prefix _CDD with the MSN of your configured CDD as higher case. */

/*******  CODE sections **********************************************************************************************/

#ifdef _CDD_START_SEC_CODE
# undef _CDD_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef _CDD_STOP_SEC_CODE
# undef _CDD_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif

/* Add additional memory mapping defines for each of you configured CDDs here. */

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

/* FAST CONST sections */

/* Postbuild CFG CONST sections */

/* Root table for postbuild data */

/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

/* VAR NOINIT sections */

/* VAR ZERO INIT sections */

/* VAR FAST INIT sections */

/* VAR FAST NOINIT sections */

/* VAR FAST ZERO INIT sections */

/**********************************************************************************************************************
 *  Cdd_AsrCdd END
 *********************************************************************************************************************/





/**********************************************************************************************************************
 *  XCP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef XCP_START_SEC_CODE 
    #undef XCP_START_SEC_CODE 
    #define START_SEC_CODE
#endif

#ifdef XCP_STOP_SEC_CODE 
    #undef XCP_STOP_SEC_CODE 
    #define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef XCP_START_SEC_CONST_UNSPECIFIED
    #undef XCP_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef XCP_STOP_SEC_CONST_UNSPECIFIED
    #undef XCP_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

#ifdef XCP_START_SEC_CONST_16BIT 
    #undef XCP_START_SEC_CONST_16BIT 
    #define START_SEC_CONST_16BIT
#endif

#ifdef XCP_STOP_SEC_CONST_16BIT 
    #undef XCP_STOP_SEC_CONST_16BIT 
    #define STOP_SEC_CONST
#endif

#ifdef XCP_START_SEC_CONST_8BIT 
    #undef XCP_START_SEC_CONST_8BIT 
    #define START_SEC_CONST_8BIT
#endif

#ifdef XCP_STOP_SEC_CONST_8BIT 
    #undef XCP_STOP_SEC_CONST_8BIT 
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef XCP_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef XCP_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef XCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef XCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #define STOP_SEC_VAR
#endif

#ifdef XCP_START_SEC_VAR_NOINIT_8BIT 
    #undef XCP_START_SEC_VAR_NOINIT_8BIT 
    #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef XCP_STOP_SEC_VAR_NOINIT_8BIT 
    #undef XCP_STOP_SEC_VAR_NOINIT_8BIT 
    #define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  XCP END
 *********************************************************************************************************************/





/**********************************************************************************************************************
 *  FRXCP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FRXCP_START_SEC_CODE 
    #undef FRXCP_START_SEC_CODE 
    #define START_SEC_CODE
#endif

#ifdef FRXCP_STOP_SEC_CODE 
    #undef FRXCP_STOP_SEC_CODE 
    #define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FRXCP_START_SEC_CONST_UNSPECIFIED 
    #undef FRXCP_START_SEC_CONST_UNSPECIFIED 
    #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FRXCP_STOP_SEC_CONST_UNSPECIFIED 
    #undef FRXCP_STOP_SEC_CONST_UNSPECIFIED 
    #define STOP_SEC_CONST
#endif

#ifdef FRXCP_START_SEC_CONST_16BIT 
    #undef FRXCP_START_SEC_CONST_16BIT 
    #define START_SEC_CONST_16BIT
#endif

#ifdef FRXCP_STOP_SEC_CONST_16BIT 
    #undef FRXCP_STOP_SEC_CONST_16BIT 
    #define STOP_SEC_CONST
#endif

#ifdef FRXCP_START_SEC_CONST_8BIT 
    #undef FRXCP_START_SEC_CONST_8BIT 
    #define START_SEC_CONST_8BIT
#endif

#ifdef FRXCP_STOP_SEC_CONST_8BIT 
    #undef FRXCP_STOP_SEC_CONST_8BIT 
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef FRXCP_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef FRXCP_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef FRXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef FRXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #define STOP_SEC_VAR
#endif

#ifdef FRXCP_START_SEC_VAR_NOINIT_8BIT 
    #undef FRXCP_START_SEC_VAR_NOINIT_8BIT 
    #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef FRXCP_STOP_SEC_VAR_NOINIT_8BIT 
    #undef FRXCP_STOP_SEC_VAR_NOINIT_8BIT 
    #define STOP_SEC_VAR
#endif

#ifdef FRXCP_START_SEC_VAR_UNSPECIFIED
    #undef FRXCP_START_SEC_VAR_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef FRXCP_STOP_SEC_VAR_UNSPECIFIED
    #undef FRXCP_STOP_SEC_VAR_UNSPECIFIED
    #define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  FRXCP END
 *********************************************************************************************************************/




/* ==== Start sections mapping ==== */
#ifdef DCM_START_SEC_CONST_8BIT
# undef DCM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT                                        /*mapped to default const section */
#endif

#ifdef DCM_START_SEC_CONST_16BIT
# undef DCM_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT                                       /*mapped to default const section */
#endif

#ifdef DCM_START_SEC_CONST_32BIT
# undef DCM_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT                                       /*mapped to default const section */
#endif

#ifdef DCM_START_SEC_CONST_UNSPECIFIED
# undef DCM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED                                 /*mapped to default const section */
#endif

#ifdef DCM_START_SEC_VAR_NOINIT_8BIT
# undef DCM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT                                   /*mapped to default var section*/
#endif

#ifdef DCM_START_SEC_VAR_NOINIT_16BIT
# undef DCM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT                                  /*mapped to default var section*/
#endif

#ifdef DCM_START_SEC_VAR_NOINIT_32BIT
# undef DCM_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT                                  /*mapped to default var section*/
#endif

#ifdef DCM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef DCM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED                            /*mapped to default var section*/
#endif

#ifdef DCM_START_SEC_CODE
# undef DCM_START_SEC_CODE
# define START_SEC_CODE                                              /*mapped to default code section*/
#endif

#ifdef DCM_APPL_START_SEC_CODE
# undef DCM_APPL_START_SEC_CODE
# define START_SEC_CODE                                              /*default appl code section*/
#endif

/* ==== Stop sections mapping ==== */

#ifdef DCM_STOP_SEC_CONST_8BIT
# undef DCM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST                                              /*default const section */
#endif

#ifdef DCM_STOP_SEC_CONST_16BIT
# undef DCM_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST                                              /*default const section */
#endif

#ifdef DCM_STOP_SEC_CONST_32BIT
# undef DCM_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST                                              /*default const section */
#endif

#ifdef DCM_STOP_SEC_CONST_UNSPECIFIED
# undef DCM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST                                              /*default const section */
#endif

#ifdef DCM_STOP_SEC_VAR_NOINIT_8BIT
# undef DCM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR                                                /*default var section*/
#endif

#ifdef DCM_STOP_SEC_VAR_NOINIT_16BIT
# undef DCM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR                                                /*default var section*/
#endif

#ifdef DCM_STOP_SEC_VAR_NOINIT_32BIT
# undef DCM_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR                                                /*default var section*/
#endif

#ifdef DCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef DCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR                                                /*default var section*/
#endif

#ifdef DCM_STOP_SEC_CODE
# undef DCM_STOP_SEC_CODE
# define STOP_SEC_CODE                                               /*default code section*/
#endif

#ifdef DCM_APPL_STOP_SEC_CODE
# undef DCM_APPL_STOP_SEC_CODE
# define STOP_SEC_CODE                                               /*default appl code section*/
#endif












/** DEM ***************************************************************************/
/*---------------------START-MODULE-SPECIFIC-START-SECTIONS-----------------------*/
                                                              /* code section */
#if defined (DEM_START_SEC_CODE)
    #undef DEM_START_SEC_CODE
    #define START_SEC_CODE
#endif
                                                              /* vars initialized by startup code */
#if defined (DEM_START_SEC_VAR_8BIT)
    #undef DEM_START_SEC_VAR_8BIT
    #define START_SEC_VAR_INIT_8BIT
#endif
#if defined (DEM_START_SEC_VAR_32BIT)
    #undef DEM_START_SEC_VAR_32BIT
    #define START_SEC_VAR_INIT_32BIT
#endif
                                                              /* never initialized vars with high number of accesses */
#if defined (DEM_START_SEC_VAR_FAST_8BIT)
    #undef DEM_START_SEC_VAR_FAST_8BIT
    #define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined (DEM_START_SEC_VAR_FAST_16BIT)
    #undef DEM_START_SEC_VAR_FAST_16BIT
    #define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined (DEM_START_SEC_VAR_FAST_32BIT)
    #undef DEM_START_SEC_VAR_FAST_32BIT
    #define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
                                                              /* never initialized vars */
#if defined (DEM_START_SEC_VAR_NOINIT_8BIT)
    #undef DEM_START_SEC_VAR_NOINIT_8BIT
    #define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined (DEM_START_SEC_VAR_NOINIT_16BIT)
    #undef DEM_START_SEC_VAR_NOINIT_16BIT
    #define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined (DEM_START_SEC_VAR_NOINIT_UNSPECIFIED)
    #undef DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
                                                              /* vars saved in non volatile memory */
#if defined (DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED)
    #undef DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
    #define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
                                                              /* global or static constants */
#if defined (DEM_START_SEC_CONST_8BIT)
    #undef DEM_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT
#endif
#if defined (DEM_START_SEC_CONST_32BIT)
    #undef DEM_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#endif
#if defined (DEM_START_SEC_CONST_UNSPECIFIED)
    #undef DEM_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif
                                                              /* global or static constants (linktime) */
#if defined (DEM_START_SEC_CONST_LCFG)
    #undef DEM_START_SEC_CONST_LCFG
    #define START_SEC_CONST_UNSPECIFIED
#endif
                                                              /* global or static constants (postbuild) */
#if defined (DEM_START_SEC_PBCONST_ROOT)
    #undef DEM_START_SEC_PBCONST_ROOT
    #define START_SEC_CONST_PBCFG
#endif
#if defined (DEM_START_SEC_PBCONST)
    #undef DEM_START_SEC_PBCONST
    #define START_SEC_CONST_PBCFG
#endif
/*---------------------STOP-MODULE-SPECIFIC-START-SECTIONS------------------------*/

/*---------------------START-MODULE-SPECIFIC-STOP-SECTIONS------------------------*/

#if defined (DEM_STOP_SEC_CODE)
    #undef DEM_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

#if defined (DEM_STOP_SEC_VAR_8BIT)
    #undef DEM_STOP_SEC_VAR_8BIT
    #define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_32BIT)
    #undef DEM_STOP_SEC_VAR_32BIT
    #define STOP_SEC_VAR
#endif


#if defined (DEM_STOP_SEC_VAR_FAST_8BIT)
    #undef DEM_STOP_SEC_VAR_FAST_8BIT
    #define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_FAST_16BIT)
    #undef DEM_STOP_SEC_VAR_FAST_16BIT
    #define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_FAST_32BIT)
    #undef DEM_STOP_SEC_VAR_FAST_32BIT
    #define STOP_SEC_VAR
#endif

#if defined (DEM_STOP_SEC_VAR_NOINIT_8BIT)
    #undef DEM_STOP_SEC_VAR_NOINIT_8BIT
    #define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_NOINIT_16BIT)
    #undef DEM_STOP_SEC_VAR_NOINIT_16BIT
    #define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
    #undef DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

#if defined (DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED)
    #undef DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

#if defined (DEM_STOP_SEC_CONST_8BIT)
    #undef DEM_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST
#endif
#if defined (DEM_STOP_SEC_CONST_32BIT)
    #undef DEM_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST
#endif
#if defined (DEM_STOP_SEC_CONST_UNSPECIFIED)
    #undef DEM_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

#if defined (DEM_STOP_SEC_CONST_LCFG)
    #undef DEM_STOP_SEC_CONST_LCFG
    #define STOP_SEC_CONST
#endif

#if defined (DEM_STOP_SEC_PBCONST_ROOT)
    #undef DEM_STOP_SEC_PBCONST_ROOT
    #define STOP_SEC_CONST
#endif
#if defined (DEM_STOP_SEC_PBCONST)
    #undef DEM_STOP_SEC_PBCONST
    #define STOP_SEC_CONST
#endif
/*---------------------STOP-MODULE-SPECIFIC-STOP-SECTIONS------------------------*/
/** End of DEM *******************************************************************/








































/**********************************************************************************************************************
 *  FR START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FR_START_SEC_CODE
  #undef FR_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef FR_STOP_SEC_CODE
  #undef FR_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif


#ifdef FR_START_SEC_CODE_ISR
  #undef FR_START_SEC_CODE_ISR
  #define START_SEC_CODE_ISR                        /* mapped to default ISR code section */
#endif
#ifdef FR_STOP_SEC_CODE_ISR
  #undef FR_STOP_SEC_CODE_ISR
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef FR_APPL_START_SEC_CODE
    #undef FR_APPL_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef FR_APPL_STOP_SEC_CODE
    #undef FR_APPL_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FR_START_SEC_CONST_32BIT
# undef FR_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef FR_STOP_SEC_CONST_32BIT
# undef FR_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef FR_START_SEC_CONST_16BIT
# undef FR_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef FR_STOP_SEC_CONST_16BIT
# undef FR_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef FR_START_SEC_CONST_8BIT
# undef FR_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef FR_STOP_SEC_CONST_8BIT
# undef FR_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif


#ifdef FR_START_SEC_CONST_UNSPECIFIED
# undef FR_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FR_STOP_SEC_CONST_UNSPECIFIED
# undef FR_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#ifdef FR_START_SEC_PBCFG_ROOT
# undef FR_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef FR_STOP_SEC_PBCFG_ROOT
# undef FR_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

#ifdef FR_START_SEC_PBCFG
# undef FR_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef FR_STOP_SEC_PBCFG
# undef FR_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef FR_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FR_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef FR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR FAST NOINIT sections */

#ifdef FR_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FR_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef FR_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FR_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  FR END
 *********************************************************************************************************************/



















































/**********************************************************************************************************************
 *  FRTRCV START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FRTRCV_START_SEC_CODE 
    #undef FRTRCV_START_SEC_CODE 
    #define START_SEC_CODE
#endif

#ifdef FRTRCV_STOP_SEC_CODE 
    #undef FRTRCV_STOP_SEC_CODE 
    #define STOP_SEC_CODE
#endif

#ifdef FRTRCV_30_TJA1080_START_SEC_CODE 
    #undef FRTRCV_30_TJA1080_START_SEC_CODE 
    #define START_SEC_CODE
#endif

#ifdef FRTRCV_30_TJA1080_STOP_SEC_CODE 
    #undef FRTRCV_30_TJA1080_STOP_SEC_CODE 
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FRTRCV_START_SEC_CONST_UNSPECIFIED 
    #undef FRTRCV_START_SEC_CONST_UNSPECIFIED 
    #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FRTRCV_STOP_SEC_CONST_UNSPECIFIED 
    #undef FRTRCV_STOP_SEC_CONST_UNSPECIFIED 
    #define STOP_SEC_CONST
#endif

#ifdef FRTRCV_START_SEC_CONST_32BIT 
    #undef FRTRCV_START_SEC_CONST_32BIT 
    #define START_SEC_CONST_32BIT
#endif

#ifdef FRTRCV_STOP_SEC_CONST_32BIT 
    #undef FRTRCV_STOP_SEC_CONST_32BIT 
    #define STOP_SEC_CONST
#endif

#ifdef FRTRCV_START_SEC_CONST_16BIT 
    #undef FRTRCV_START_SEC_CONST_16BIT 
    #define START_SEC_CONST_16BIT
#endif

#ifdef FRTRCV_STOP_SEC_CONST_16BIT 
    #undef FRTRCV_STOP_SEC_CONST_16BIT 
    #define STOP_SEC_CONST
#endif

#ifdef FRTRCV_START_SEC_CONST_8BIT 
    #undef FRTRCV_START_SEC_CONST_8BIT 
    #define START_SEC_CONST_8BIT
#endif

#ifdef FRTRCV_STOP_SEC_CONST_8BIT 
    #undef FRTRCV_STOP_SEC_CONST_8BIT 
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef FRTRCV_START_SEC_VAR_ZERO_INIT_UNSPECIFIED 
    #undef FRTRCV_START_SEC_VAR_ZERO_INIT_UNSPECIFIED 
    #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef FRTRCV_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED 
    #undef FRTRCV_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED 
    #define STOP_SEC_VAR
#endif

#ifdef FRTRCV_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef FRTRCV_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef FRTRCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef FRTRCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #define STOP_SEC_VAR
#endif

#ifdef FRTRCV_START_SEC_VAR_NOINIT_32BIT 
    #undef FRTRCV_START_SEC_VAR_NOINIT_32BIT 
    #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef FRTRCV_STOP_SEC_VAR_NOINIT_32BIT 
    #undef FRTRCV_STOP_SEC_VAR_NOINIT_32BIT 
    #define STOP_SEC_VAR
#endif

#ifdef FRTRCV_START_SEC_VAR_NOINIT_8BIT 
    #undef FRTRCV_START_SEC_VAR_NOINIT_8BIT 
    #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef FRTRCV_STOP_SEC_VAR_NOINIT_8BIT 
    #undef FRTRCV_STOP_SEC_VAR_NOINIT_8BIT 
    #define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  FRTRCV END
 *********************************************************************************************************************/














/**********************************************************************************************************************
 *  PDUR START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef PDUR_START_SEC_CODE
# undef PDUR_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef PDUR_STOP_SEC_CODE
# undef PDUR_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef PDUR_START_SEC_CONST_8BIT
# undef PDUR_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef PDUR_STOP_SEC_CONST_8BIT
# undef PDUR_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef PDUR_START_SEC_CONST_16BIT
# undef PDUR_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef PDUR_STOP_SEC_CONST_16BIT
# undef PDUR_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef PDUR_START_SEC_CONST_32BIT
# undef PDUR_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef PDUR_STOP_SEC_CONST_32BIT
# undef PDUR_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef PDUR_START_SEC_CONST_UNSPECIFIED
# undef PDUR_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef PDUR_STOP_SEC_CONST_UNSPECIFIED
# undef PDUR_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */



/* Postbuild CFG CONST sections */

/* Root table for postbuild data */
#ifdef PDUR_START_SEC_PBCFG
# undef PDUR_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef PDUR_STOP_SEC_PBCFG
# undef PDUR_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef PDUR_START_SEC_PBCFG_ROOT
# undef PDUR_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef PDUR_STOP_SEC_PBCFG_ROOT
# undef PDUR_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef PDUR_START_SEC_VAR_NOINIT_BOOLEAN
# undef PDUR_START_SEC_VAR_NOINIT_BOOLEAN
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef PDUR_STOP_SEC_VAR_NOINIT_BOOLEAN
# undef PDUR_STOP_SEC_VAR_NOINIT_BOOLEAN
# define STOP_SEC_VAR
#endif

#ifdef PDUR_START_SEC_VAR_NOINIT_8BIT
# undef PDUR_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef PDUR_STOP_SEC_VAR_NOINIT_8BIT
# undef PDUR_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */



/* VAR FAST INIT sections */



/* VAR FAST NOINIT sections */


/* VAR FAST ZERO INIT sections */



/**********************************************************************************************************************
 *  PDUR END
 *********************************************************************************************************************/









/**********************************************************************************************************************
 *  FRIF START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FRIF_START_SEC_CODE
  #undef FRIF_START_SEC_CODE                        /* PRQA S 0841 */
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef FRIF_STOP_SEC_CODE
  #undef FRIF_STOP_SEC_CODE                         /* PRQA S 0841 */
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef FRIF_START_SEC_APPL_CODE
  #undef FRIF_START_SEC_APPL_CODE                   /* PRQA S 0841 */
  #define START_SEC_CODE                            /* mapped to default appl code section */
#endif
#ifdef FRIF_STOP_SEC_APPL_CODE
  #undef FRIF_STOP_SEC_APPL_CODE                    /* PRQA S 0841 */
  #define STOP_SEC_CODE                             /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FRIF_START_SEC_CONST_32BIT
# undef FRIF_START_SEC_CONST_32BIT                  /* PRQA S 0841 */
# define START_SEC_CONST_32BIT
#endif
#ifdef FRIF_STOP_SEC_CONST_32BIT
# undef FRIF_STOP_SEC_CONST_32BIT                   /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

#ifdef FRIF_START_SEC_CONST_UNSPECIFIED
# undef FRIF_START_SEC_CONST_UNSPECIFIED            /* PRQA S 0841 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FRIF_STOP_SEC_CONST_UNSPECIFIED  
# undef FRIF_STOP_SEC_CONST_UNSPECIFIED             /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

/* Postbuild CFG CONST sections */

#ifdef FRIF_START_SEC_PBCFG
# undef FRIF_START_SEC_PBCFG                        /* PRQA S 0841 */
# define START_SEC_CONST_PBCFG
#endif
#ifdef FRIF_STOP_SEC_PBCFG
# undef FRIF_STOP_SEC_PBCFG                         /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

#ifdef FRIF_START_SEC_PBCFG_ROOT
# undef FRIF_START_SEC_PBCFG_ROOT                   /* PRQA S 0841 */
# define START_SEC_CONST_PBCFG
#endif
#ifdef FRIF_STOP_SEC_PBCFG_ROOT
# undef FRIF_STOP_SEC_PBCFG_ROOT                    /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef FRIF_START_SEC_VAR_INIT_UNSPECIFIED
# undef FRIF_START_SEC_VAR_INIT_UNSPECIFIED         /* PRQA S 0841 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef FRIF_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FRIF_STOP_SEC_VAR_INIT_UNSPECIFIED          /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#ifdef FRIF_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FRIF_START_SEC_VAR_NOINIT_UNSPECIFIED       /* PRQA S 0841 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef FRIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FRIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED        /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef FRIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FRIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED    /* PRQA S 0841 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef FRIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FRIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED     /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  FRIF END
 *********************************************************************************************************************/




































/**********************************************************************************************************************
 *  Com START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef COM_START_SEC_CODE
# undef COM_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef COM_STOP_SEC_CODE
# undef COM_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif
/* COM application callback code section (Rte_Cbk.h)*/
#ifdef COM_START_SEC_APPL_CODE
# undef COM_START_SEC_APPL_CODE
# define START_SEC_CODE
#endif
#ifdef COM_STOP_SEC_APPL_CODE
# undef COM_STOP_SEC_APPL_CODE
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef COM_START_SEC_CONST_32BIT
# undef COM_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef COM_STOP_SEC_CONST_32BIT
# undef COM_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef COM_START_SEC_CONST_UNSPECIFIED
# undef COM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef COM_STOP_SEC_CONST_UNSPECIFIED
# undef COM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */



/* Postbuild CFG CONST sections */

/* Root table for postbuild data */
#ifdef COM_START_SEC_PBCFG_ROOT
# undef COM_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef COM_STOP_SEC_PBCFG_ROOT
# undef COM_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

#ifdef COM_START_SEC_PBCFG
# undef COM_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef COM_STOP_SEC_PBCFG
# undef COM_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef COM_START_SEC_VAR_INIT_UNSPECIFIED
# undef COM_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef COM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef COM_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef COM_START_SEC_VAR_NOINIT_BOOLEAN
# undef COM_START_SEC_VAR_NOINIT_BOOLEAN
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef COM_STOP_SEC_VAR_NOINIT_BOOLEAN
# undef COM_STOP_SEC_VAR_NOINIT_BOOLEAN
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_NOINIT_8BIT
# undef COM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef COM_STOP_SEC_VAR_NOINIT_8BIT
# undef COM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_NOINIT_16BIT
# undef COM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef COM_STOP_SEC_VAR_NOINIT_16BIT
# undef COM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef COM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef COM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef COM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */



/* VAR FAST INIT sections */



/* VAR FAST NOINIT sections */


/* VAR FAST ZERO INIT sections */



/**********************************************************************************************************************
 *  Com END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  IpduM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef IPDUM_START_SEC_CODE
# undef IPDUM_START_SEC_CODE
# define START_SEC_CODE         /* mapped to default code section */
#endif
#ifdef IPDUM_STOP_SEC_CODE
# undef IPDUM_STOP_SEC_CODE
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* Postbuild CFG CONST sections */

#ifdef IPDUM_START_SEC_PBCFG
# undef IPDUM_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef IPDUM_STOP_SEC_PBCFG
# undef IPDUM_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

/* Postbuild CFG struct sections */

#ifdef IPDUM_START_SEC_PBCFG_ROOT
# undef IPDUM_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef IPDUM_STOP_SEC_PBCFG_ROOT
# undef IPDUM_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef IPDUM_START_SEC_VAR_INIT_UNSPECIFIED
# undef IPDUM_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef IPDUM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef IPDUM_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef IPDUM_START_SEC_VAR_NOINIT_8BIT
# undef IPDUM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef IPDUM_STOP_SEC_VAR_NOINIT_8BIT
# undef IPDUM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef IPDUM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef IPDUM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef IPDUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef IPDUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  IpduM END
 *********************************************************************************************************************/





















/**********************************************************************************************************************
 *  FRNM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FRNM_START_SEC_CODE
    #undef FRNM_START_SEC_CODE
    #define START_SEC_CODE                              /*mapped to default code section*/
#endif
#ifdef FRNM_STOP_SEC_CODE
    #undef FRNM_STOP_SEC_CODE
    #define STOP_SEC_CODE                               /*default code stop section*/
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FRNM_START_SEC_CONST_8BIT
    #undef FRNM_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT                        /*mapped to default const section */
#endif
#ifdef FRNM_STOP_SEC_CONST_8BIT
    #undef FRNM_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST                              /*default const stop section*/
#endif

#ifdef FRNM_START_SEC_CONST_32BIT
    #undef FRNM_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT                       /*mapped to default const section */
#endif
#ifdef FRNM_STOP_SEC_CONST_32BIT
    #undef FRNM_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST                              /*default const stop section*/
#endif

#ifdef FRNM_START_SEC_CONST_UNSPECIFIED
    #undef FRNM_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED                 /*mapped to default const section */
#endif
#ifdef FRNM_STOP_SEC_CONST_UNSPECIFIED
    #undef FRNM_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST                              /*default const stop section*/
#endif

/* Postbuild CFG CONST sections */

#ifdef FRNM_START_SEC_PBCFG
    #undef FRNM_START_SEC_PBCFG
    #define START_SEC_CONST_PBCFG                       /*mapped to default postbuild section */
#endif
#ifdef FRNM_STOP_SEC_PBCFG
    #undef FRNM_STOP_SEC_PBCFG
    #define STOP_SEC_CONST                              /*default const stop section*/
#endif

#ifdef FRNM_START_SEC_PBCFG_ROOT
    #undef FRNM_START_SEC_PBCFG_ROOT
    #define START_SEC_CONST_PBCFG                       /*mapped to default postbuild section */
#endif
#ifdef FRNM_STOP_SEC_PBCFG_ROOT
    #undef FRNM_STOP_SEC_PBCFG_ROOT
    #define STOP_SEC_CONST                              /*default const stop section*/
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef FRNM_START_SEC_VAR_NOINIT_8BIT
    #undef FRNM_START_SEC_VAR_NOINIT_8BIT
    #define START_SEC_VAR_NOINIT_8BIT                   /*mapped to default var section*/
#endif
#ifdef FRNM_STOP_SEC_VAR_NOINIT_8BIT
    #undef FRNM_STOP_SEC_VAR_NOINIT_8BIT
    #define STOP_SEC_VAR                                /*default var stop section*/
#endif

#ifdef FRNM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef FRNM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED            /*mapped to default var section*/
#endif
#ifdef FRNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef FRNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR                                /*default var stop section*/
#endif

/* VAR FAST NOINIT sections */

#ifdef FRNM_START_SEC_VAR_FAST_NOINIT_8BIT
    #undef FRNM_START_SEC_VAR_FAST_NOINIT_8BIT
    #define START_SEC_VAR_FAST_NOINIT_8BIT              /*mapped to default var section*/
#endif
#ifdef FRNM_STOP_SEC_VAR_FAST_NOINIT_8BIT
    #undef FRNM_STOP_SEC_VAR_FAST_NOINIT_8BIT
    #define STOP_SEC_VAR                                /*default var stop section*/
#endif

#ifdef FRNM_START_SEC_VAR_FAST_NOINIT_16BIT
    #undef FRNM_START_SEC_VAR_FAST_NOINIT_16BIT
    #define START_SEC_VAR_FAST_NOINIT_16BIT             /*mapped to default var section*/
#endif
#ifdef FRNM_STOP_SEC_VAR_FAST_NOINIT_16BIT
    #undef FRNM_STOP_SEC_VAR_FAST_NOINIT_16BIT
    #define STOP_SEC_VAR                                /*default var stop section*/
#endif

#ifdef FRNM_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #undef FRNM_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED       /*mapped to default var section*/
#endif
#ifdef FRNM_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #undef FRNM_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR                                /*default var stop section*/
#endif

/* VAR FAST ZERO INIT sections */

#ifdef FRNM_START_SEC_VAR_FAST_ZERO_INIT_8BIT
    #undef FRNM_START_SEC_VAR_FAST_ZERO_INIT_8BIT
    #define START_SEC_VAR_FAST_ZERO_INIT_8BIT           /*mapped to default var section*/
#endif
#ifdef FRNM_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
    #undef FRNM_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
    #define STOP_SEC_VAR                                /*default var stop section*/
#endif

#ifdef FRNM_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
    #undef FRNM_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
    #define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED    /*mapped to default var section*/
#endif
#ifdef FRNM_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
    #undef FRNM_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
    #define STOP_SEC_VAR                                /*default var stop section*/
#endif

/**********************************************************************************************************************
 *  FRNM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  NM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef NM_START_SEC_CODE
    #undef NM_START_SEC_CODE
    #define START_SEC_CODE                              /*mapped to default code section*/
#endif
#ifdef NM_STOP_SEC_CODE
    #undef NM_STOP_SEC_CODE
    #define STOP_SEC_CODE                               /*default code stop section*/
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef NM_START_SEC_CONST_8BIT
    #undef NM_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT                        /*mapped to default const section */
#endif
#ifdef NM_STOP_SEC_CONST_8BIT
    #undef NM_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST                              /*default const stop section*/
#endif

#ifdef NM_START_SEC_CONST_32BIT
    #undef NM_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT                        /*mapped to default const section */
#endif
#ifdef NM_STOP_SEC_CONST_32BIT
    #undef NM_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST                              /*default const stop section*/
#endif

#ifdef NM_START_SEC_CONST_UNSPECIFIED
    #undef NM_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED                 /*mapped to default const section */
#endif
#ifdef NM_STOP_SEC_CONST_UNSPECIFIED
    #undef NM_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST                              /*default const stop section*/
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef NM_START_SEC_VAR_NOINIT_8BIT
    #undef NM_START_SEC_VAR_NOINIT_8BIT
    #define START_SEC_VAR_NOINIT_8BIT                   /*mapped to default var section*/
#endif
#ifdef NM_STOP_SEC_VAR_NOINIT_8BIT
    #undef NM_STOP_SEC_VAR_NOINIT_8BIT
    #define STOP_SEC_VAR                                /*default var stop section*/
#endif

/* VAR FAST NOINIT sections */

#ifdef NM_START_SEC_VAR_FAST_NOINIT_8BIT
    #undef NM_START_SEC_VAR_FAST_NOINIT_8BIT
    #define START_SEC_VAR_FAST_NOINIT_8BIT             /*mapped to default var section*/
#endif
#ifdef NM_STOP_SEC_VAR_FAST_NOINIT_8BIT
    #undef NM_STOP_SEC_VAR_FAST_NOINIT_8BIT
    #define STOP_SEC_VAR                                /*default var stop section*/
#endif

#ifdef NM_START_SEC_VAR_FAST_NOINIT_16BIT
    #undef NM_START_SEC_VAR_FAST_NOINIT_16BIT
    #define START_SEC_VAR_FAST_NOINIT_16BIT             /*mapped to default var section*/
#endif
#ifdef NM_STOP_SEC_VAR_FAST_NOINIT_16BIT
    #undef NM_STOP_SEC_VAR_FAST_NOINIT_16BIT
    #define STOP_SEC_VAR                                /*default var stop section*/
#endif

#ifdef NM_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #undef NM_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED       /*mapped to default var section*/
#endif
#ifdef NM_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #undef NM_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR                                /*default var stop section*/
#endif

/* VAR FAST ZERO INIT sections */

#ifdef NM_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
    #undef NM_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
    #define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED    /*mapped to default var section*/
#endif
#ifdef NM_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
    #undef NM_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
    #define STOP_SEC_VAR                                /*default var stop section*/
#endif

/**********************************************************************************************************************
 *  NM END
 *********************************************************************************************************************/







/**********************************************************************************************************************
 *  BSWM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef BSWM_START_SEC_CODE
    #undef BSWM_START_SEC_CODE
    #define START_SEC_CODE                   /*mapped to default code section*/
#endif

#ifdef BSWM_STOP_SEC_CODE
    #undef BSWM_STOP_SEC_CODE
    #define STOP_SEC_CODE                    /*default code stop section*/
#endif

#ifdef BSWM_START_SEC_CONST_UNSPECIFIED
    #undef BSWM_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef BSWM_STOP_SEC_CONST_UNSPECIFIED
    #undef BSWM_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

#ifdef BSWM_START_SEC_CONST_8BIT
    #undef BSWM_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT                    /*default code stop section*/
#endif

#ifdef BSWM_STOP_SEC_CONST_8BIT
    #undef BSWM_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST                    /*default code stop section*/
#endif

#ifdef BSWM_START_SEC_CONST_32BIT
    #undef BSWM_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT                    /*default code stop section*/
#endif

#ifdef BSWM_STOP_SEC_CONST_32BIT
    #undef BSWM_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST                    /*default code stop section*/
#endif

#ifdef BSWM_START_SEC_VAR_NOINIT_8BIT
    #undef BSWM_START_SEC_VAR_NOINIT_8BIT
    #define START_SEC_VAR_NOINIT_8BIT                   /*mapped to default code section*/
#endif

#ifdef BSWM_STOP_SEC_VAR_NOINIT_8BIT
    #undef BSWM_STOP_SEC_VAR_NOINIT_8BIT
    #define STOP_SEC_VAR                   /*mapped to default code section*/
#endif

#ifdef BSWM_START_SEC_VAR_NOINIT_32BIT
  #undef  BSWM_START_SEC_VAR_NOINIT_32BIT
    #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef BSWM_STOP_SEC_VAR_NOINIT_32BIT
# undef BSWM_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR                                                /*default var section*/
#endif

#ifdef BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED                   /*mapped to default code section*/
#endif

#ifdef BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR                   /*mapped to default code section*/
#endif

#ifdef BSWM_START_SEC_VAR_INIT_UNSPECIFIED
    #undef BSWM_START_SEC_VAR_INIT_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED                   /*mapped to default code section*/
#endif

#ifdef BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define STOP_SEC_VAR                   /*mapped to default code section*/
#endif


/**********************************************************************************************************************
 *  BSWM END
 *********************************************************************************************************************/






#ifdef DET_START_SEC_CODE
# undef DET_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef DET_STOP_SEC_CODE
# undef DET_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif

#ifdef DET_START_SEC_VAR_UNSPECIFIED
# undef DET_START_SEC_VAR_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef DET_STOP_SEC_VAR_UNSPECIFIED
# undef DET_STOP_SEC_VAR_UNSPECIFIED
# define STOP_SEC_VAR
#endif




/**********************************************************************************************************************
 *  SYSSERVICE_ASRECUM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef ECUM_START_SEC_CODE
# undef ECUM_START_SEC_CODE
# define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef ECUM_STOP_SEC_CODE
# undef ECUM_STOP_SEC_CODE
# define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef ECUM_START_SEC_CODE_SET_BOOT_TARGET
# undef ECUM_START_SEC_CODE_SET_BOOT_TARGET
# define START_SEC_CODE                            /* mapped to default fast code section */
#endif
#ifdef ECUM_STOP_SEC_CODE_SET_BOOT_TARGET
# undef ECUM_STOP_SEC_CODE_SET_BOOT_TARGET
# define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef ECUM_START_SEC_CODE_GET_BOOT_TARGET
# undef ECUM_START_SEC_CODE_GET_BOOT_TARGET
# define START_SEC_CODE                            /* mapped to default ISR code section */
#endif
#ifdef ECUM_STOP_SEC_CODE_GET_BOOT_TARGET
# undef ECUM_STOP_SEC_CODE_GET_BOOT_TARGET
# define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef ECUM_START_SEC_CONST_8BIT
# undef ECUM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT                       /* mapped to default const 8bit section */
#endif
#ifdef ECUM_STOP_SEC_CONST_8BIT
# undef ECUM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST                             /* default const stop section */
#endif

#ifdef ECUM_START_SEC_CONST_UNSPECIFIED
# undef ECUM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ECUM_STOP_SEC_CONST_UNSPECIFIED
# undef ECUM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/* FAST CONST sections */

/* Postbuild CFG CONST sections */

/* Root table for postbuild data */
#ifdef ECUM_START_SEC_CONST_PBCFG_ROOT
# undef ECUM_START_SEC_CONST_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef ECUM_STOP_SEC_CONST_PBCFG_ROOT
# undef ECUM_STOP_SEC_CONST_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

#ifdef ECUM_START_SEC_CONST_PBCFG
# undef ECUM_START_SEC_CONST_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef ECUM_STOP_SEC_CONST_PBCFG
# undef ECUM_STOP_SEC_CONST_PBCFG
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef ECUM_START_SEC_VAR_INIT_UNSPECIFIED
# undef ECUM_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef ECUM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef ECUM_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR NOINIT sections */

#ifdef ECUM_START_SEC_VAR_NOINIT_8BIT
# undef ECUM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_8BIT
# undef ECUM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ECUM_START_SEC_VAR_NOINIT_16BIT
# undef ECUM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_16BIT
# undef ECUM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ECUM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ECUM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ECUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

/* VAR FAST INIT sections */

/* VAR FAST NOINIT sections */

/* VAR FAST ZERO INIT sections */


/**********************************************************************************************************************
 *  SYSSERVICE_ASRECUM END
 *********************************************************************************************************************/


































/**********************************************************************************************************************
 *  SchM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef SCHM_START_SEC_CODE
# undef SCHM_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef SCHM_STOP_SEC_CODE
# undef SCHM_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef SCHM_START_SEC_CONST_8BIT
# undef SCHM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef SCHM_STOP_SEC_CONST_8BIT
# undef SCHM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef SCHM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SCHM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef SCHM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SCHM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR ZERO_INIT sections */

#ifdef SCHM_START_SEC_VAR_ZERO_INIT_8BIT
# undef SCHM_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef SCHM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef SCHM_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SchM END
 *********************************************************************************************************************/















/**********************************************************************************************************************
 *  TP_ASRTPFR START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined (FRTP_START_SEC_CODE)
   #undef      FRTP_START_SEC_CODE                    /* PRQA S 0841 */
   #define START_SEC_CODE
#endif

#if defined (FRTP_STOP_SEC_CODE)
   #undef      FRTP_STOP_SEC_CODE                     /* PRQA S 0841 */
   #define STOP_SEC_CODE
 #endif

/*******  CONST sections  ********************************************************************************************/

#if defined (FRTP_START_SEC_CONST_8BIT)
   #undef      FRTP_START_SEC_CONST_8BIT              /* PRQA S 0841 */
   #define START_SEC_CONST_8BIT
#endif

#if defined (FRTP_STOP_SEC_CONST_8BIT)
   #undef      FRTP_STOP_SEC_CONST_8BIT               /* PRQA S 0841 */
   #define STOP_SEC_CONST
#endif

#if defined (FRTP_START_SEC_CONST_16BIT)
   #undef      FRTP_START_SEC_CONST_16BIT             /* PRQA S 0841 */
   #define START_SEC_CONST_16BIT
#endif

#if defined (FRTP_STOP_SEC_CONST_16BIT)
   #undef      FRTP_STOP_SEC_CONST_16BIT              /* PRQA S 0841 */
   #define STOP_SEC_CONST
#endif

#if defined (FRTP_START_SEC_CONST_32BIT)
   #undef      FRTP_START_SEC_CONST_32BIT             /* PRQA S 0841 */
   #define START_SEC_CONST_32BIT
#endif

#if defined (FRTP_STOP_SEC_CONST_32BIT)
   #undef      FRTP_STOP_SEC_CONST_32BIT
   #define STOP_SEC_CONST
#endif

#if defined (FRTP_START_SEC_CONST_UNSPECIFIED)
   #undef      FRTP_START_SEC_CONST_UNSPECIFIED       /* PRQA S 0841 */
   #define START_SEC_CONST_UNSPECIFIED
#endif

#if defined (FRTP_STOP_SEC_CONST_UNSPECIFIED)
   #undef      FRTP_STOP_SEC_CONST_UNSPECIFIED        /* PRQA S 0841 */
   #define STOP_SEC_CONST
#endif

/* Postbuild CFG CONST sections */

#if defined (FRTP_START_SEC_PBCFG)
   #undef      FRTP_START_SEC_PBCFG                   /* PRQA S 0841 */   
   #define START_SEC_PBCFG
#endif

#if defined (FRTP_STOP_SEC_PBCFG)
   #undef      FRTP_STOP_SEC_PBCFG                    /* PRQA S 0841 */
   #define STOP_SEC_CONST
#endif

#if defined (FRTP_START_SEC_PBCFG_ROOT)
   #undef      FRTP_START_SEC_PBCFG_ROOT              /* PRQA S 0841 */
   #define START_SEC_CONST_PBCFG
#endif

#if defined (FRTP_STOP_SEC_PBCFG_ROOT)
   #undef      FRTP_STOP_SEC_PBCFG_ROOT               /* PRQA S 0841 */
   #define STOP_SEC_CONST
#endif

/*******  VAR sections ***********************************************************************************************/

/* VAR NOINIT sections */

#if defined (FRTP_START_SEC_VAR_NOINIT_8BIT)
   #undef      FRTP_START_SEC_VAR_NOINIT_8BIT         /* PRQA S 0841 */
   #define START_SEC_VAR_NOINIT_8BIT
#endif

#if defined (FRTP_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      FRTP_STOP_SEC_VAR_NOINIT_8BIT          /* PRQA S 0841 */
   #define STOP_SEC_VAR
#endif

#if defined (FRTP_START_SEC_VAR_NOINIT_16BIT)
   #undef      FRTP_START_SEC_VAR_NOINIT_16BIT        /* PRQA S 0841 */
   #define START_SEC_VAR_NOINIT_16BIT
#endif

#if defined (FRTP_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      FRTP_STOP_SEC_VAR_NOINIT_16BIT         /* PRQA S 0841 */
   #define STOP_SEC_VAR
#endif

#if defined (FRTP_START_SEC_VAR_NOINIT_32BIT)
   #undef      FRTP_START_SEC_VAR_NOINIT_32BIT        /* PRQA S 0841 */
   #define START_SEC_VAR_NOINIT_32BIT
#endif

#if defined (FRTP_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      FRTP_STOP_SEC_VAR_NOINIT_32BIT         /* PRQA S 0841 */
   #define STOP_SEC_VAR
#endif

#if defined (FRTP_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      FRTP_START_SEC_VAR_NOINIT_UNSPECIFIED  /* PRQA S 0841 */
   #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (FRTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      FRTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED   /* PRQA S 0841 */
   #define STOP_SEC_VAR
#endif








/**********************************************************************************************************************
 *  TP_ISO10681 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined (TP_ISO10681_START_SEC_CODE)
   #undef      TP_ISO10681_START_SEC_CODE                   /* PRQA S 0841 */
   #define START_SEC_CODE
#endif

#if defined (TP_ISO10681_STOP_SEC_CODE)
   #undef      TP_ISO10681_STOP_SEC_CODE                    /* PRQA S 0841 */
   #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

#if defined (TP_ISO10681_START_SEC_CONST_8BIT)
   #undef      TP_ISO10681_START_SEC_CONST_8BIT             /* PRQA S 0841 */
   #define START_SEC_CONST_8BIT
#endif

#if defined (TP_ISO10681_STOP_SEC_CONST_8BIT)
   #undef      TP_ISO10681_STOP_SEC_CONST_8BIT              /* PRQA S 0841 */
   #define STOP_SEC_CONST
#endif

#if defined (TP_ISO10681_START_SEC_CONST_16BIT)
   #undef      TP_ISO10681_START_SEC_CONST_16BIT            /* PRQA S 0841 */
   #define START_SEC_CONST_16BIT
#endif

#if defined (TP_ISO10681_STOP_SEC_CONST_16BIT)
   #undef      TP_ISO10681_STOP_SEC_CONST_16BIT             /* PRQA S 0841 */
   #define STOP_SEC_CONST
#endif

#if defined (TP_ISO10681_START_SEC_CONST_32BIT)
   #undef      TP_ISO10681_START_SEC_CONST_32BIT            /* PRQA S 0841 */
   #define START_SEC_CONST_32BIT
#endif

#if defined (TP_ISO10681_STOP_SEC_CONST_32BIT)
   #undef      TP_ISO10681_STOP_SEC_CONST_32BIT             /* PRQA S 0841 */
   #define STOP_SEC_CONST
#endif

#if defined (TP_ISO10681_START_SEC_CONST_UNSPECIFIED)
   #undef      TP_ISO10681_START_SEC_CONST_UNSPECIFIED      /* PRQA S 0841 */
   #define START_SEC_CONST_UNSPECIFIED
#endif

#if defined (TP_ISO10681_STOP_SEC_CONST_UNSPECIFIED)
   #undef      TP_ISO10681_STOP_SEC_CONST_UNSPECIFIED       /* PRQA S 0841 */
   #define STOP_SEC_CONST
#endif

/* Postbuild CFG CONST sections */

#if defined (TP_ISO10681_START_SEC_PBCFG)
   #undef      TP_ISO10681_START_SEC_PBCFG                  /* PRQA S 0841 */
   #define START_SEC_CONST_PBCFG
#endif

#if defined (TP_ISO10681_STOP_SEC_PBCFG)
   #undef      TP_ISO10681_STOP_SEC_PBCFG                   /* PRQA S 0841 */
   #define STOP_SEC_CONST
#endif

#if defined (TP_ISO10681_START_SEC_PBCFG_ROOT)
   #undef      TP_ISO10681_START_SEC_PBCFG_ROOT             /* PRQA S 0841 */
   #define START_SEC_CONST_PBCFG
#endif

#if defined (TP_ISO10681_STOP_SEC_PBCFG_ROOT)
   #undef      TP_ISO10681_STOP_SEC_PBCFG_ROOT              /* PRQA S 0841 */
   #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#if defined (TP_ISO10681_START_SEC_VAR_NOINIT_8BIT)
   #undef      TP_ISO10681_START_SEC_VAR_NOINIT_8BIT        /* PRQA S 0841 */
   #define START_SEC_VAR_NOINIT_8BIT
#endif

#if defined (TP_ISO10681_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      TP_ISO10681_STOP_SEC_VAR_NOINIT_8BIT         /* PRQA S 0841 */
   #define STOP_SEC_VAR
#endif

#if defined (TP_ISO10681_START_SEC_VAR_NOINIT_16BIT)
   #undef      TP_ISO10681_START_SEC_VAR_NOINIT_16BIT       /* PRQA S 0841 */
   #define START_SEC_VAR_NOINIT_16BIT
#endif

#if defined (TP_ISO10681_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      TP_ISO10681_STOP_SEC_VAR_NOINIT_16BIT        /* PRQA S 0841 */
   #define STOP_SEC_VAR
#endif

#if defined (TP_ISO10681_START_SEC_VAR_NOINIT_32BIT)
   #undef      TP_ISO10681_START_SEC_VAR_NOINIT_32BIT       /* PRQA S 0841 */
   #define START_SEC_VAR_NOINIT_32BIT
#endif

#if defined (TP_ISO10681_STOP_SEC_VAR_NOINIT_32BIT)         /* PRQA S 0841 */
   #undef      TP_ISO10681_STOP_SEC_VAR_NOINIT_32BIT
   #define STOP_SEC_VAR
#endif

#if defined (TP_ISO10681_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      TP_ISO10681_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */
   #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (TP_ISO10681_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      TP_ISO10681_STOP_SEC_VAR_NOINIT_UNSPECIFIED  /* PRQA S 0841 */
   #define STOP_SEC_VAR
#endif











/*-------------------------------------------------------------------------------------------------------------------*/
/* VStdLib start MemMap.inc                                                                                          */
/*-------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------- Code ---------------------------------------------------------------------------*/

#ifdef VSTDLIB_START_SEC_CODE                             /* CAN code */
# undef VSTDLIB_START_SEC_CODE                            /* PRQA S 0841 */
# define START_SEC_CODE                                   /* mapped to default code section */
#endif
#ifdef VSTDLIB_STOP_SEC_CODE
# undef VSTDLIB_STOP_SEC_CODE                             /* PRQA S 0841 */
# define STOP_SEC_CODE
#endif

/*---------------------------------- Const --------------------------------------------------------------------------*/

#ifdef VSTDLIB_START_SEC_CONST_UNSPECIFIED               /* CAN code */
# undef VSTDLIB_START_SEC_CONST_UNSPECIFIED              /* PRQA S 0841 */
# define START_SEC_CONST_UNSPECIFIED                     /* mapped to default code section */
#endif
#ifdef VSTDLIB_STOP_SEC_CONST_UNSPECIFIED  
# undef VSTDLIB_STOP_SEC_CONST_UNSPECIFIED               /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

/*---------------------------------- RAM ----------------------------------------------------------------------------*/

#ifdef VSTDLIB_START_SEC_VAR_NOINIT_UNSPECIFIED          /* CAN code */
# undef VSTDLIB_START_SEC_VAR_NOINIT_UNSPECIFIED         /* PRQA S 0841 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED                /* mapped to default code section */
#endif
#ifdef VSTDLIB_STOP_SEC_VAR_NOINIT_UNSPECIFIED  
# undef VSTDLIB_STOP_SEC_VAR_NOINIT_UNSPECIFIED          /* PRQA S 0841 */
# define STOP_SEC_VAR 
#endif

/*-------------------------------------------------------------------------------------------------------------------*/
/* VStdLib end MemMap.inc                                                                                            */
/*-------------------------------------------------------------------------------------------------------------------*/



/* Package Merger: Stop Section MemMapModuleList */ 

/*------------------------------GLOBAL-SECTIONS-----------------------------*/
/* Check code sections */
#if ( (defined CODE_SEC_OPEN)                            && \
     ((defined START_SEC_CODE                          ) || \
      (defined START_SEC_CODE_FAST                     ) || \
      (defined START_SEC_CODE_ISR                      )    \
      ))
    #error "MemMap.h: Close the former code segment before opening a new one."
#endif

/* Check const sections */
#if ( (defined CONST_SEC_OPEN)                           && \
     ((defined START_SEC_CONST_8BIT                    ) || \
      (defined START_SEC_CONST_16BIT                   ) || \
      (defined START_SEC_CONST_32BIT                   ) || \
      (defined START_SEC_CONST_UNSPECIFIED             ) || \
      (defined START_SEC_CONST_FAST_8BIT               ) || \
      (defined START_SEC_CONST_FAST_16BIT              ) || \
      (defined START_SEC_CONST_FAST_32BIT              ) || \
      (defined START_SEC_CONST_FAST_UNSPECIFIED        ) || \
      (defined START_SEC_CONST_PBCFG                   )    \
      ))
    #error "MemMap.h: Close the former const segment before opening a new one."
#endif

/* Check data sections */
#if ( (defined VAR_SEC_OPEN)                             && \
     ((defined START_SEC_VAR_INIT_8BIT                 ) || \
      (defined START_SEC_VAR_INIT_16BIT                ) || \
      (defined START_SEC_VAR_INIT_32BIT                ) || \
      (defined START_SEC_VAR_INIT_UNSPECIFIED          ) || \
      (defined START_SEC_VAR_NOINIT_8BIT               ) || \
      (defined START_SEC_VAR_NOINIT_16BIT              ) || \
      (defined START_SEC_VAR_NOINIT_32BIT              ) || \
      (defined START_SEC_VAR_NOINIT_UNSPECIFIED        ) || \
      (defined START_SEC_VAR_ZERO_INIT_8BIT            ) || \
      (defined START_SEC_VAR_ZERO_INIT_16BIT           ) || \
      (defined START_SEC_VAR_ZERO_INIT_32BIT           ) || \
      (defined START_SEC_VAR_ZERO_INIT_UNSPECIFIED     ) || \
      (defined START_SEC_VAR_FAST_INIT_8BIT            ) || \
      (defined START_SEC_VAR_FAST_INIT_16BIT           ) || \
      (defined START_SEC_VAR_FAST_INIT_32BIT           ) || \
      (defined START_SEC_VAR_FAST_INIT_UNSPECIFIED     ) || \
      (defined START_SEC_VAR_FAST_NOINIT_8BIT          ) || \
      (defined START_SEC_VAR_FAST_NOINIT_16BIT         ) || \
      (defined START_SEC_VAR_FAST_NOINIT_32BIT         ) || \
      (defined START_SEC_VAR_FAST_NOINIT_UNSPECIFIED   ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_8BIT       ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_16BIT      ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_32BIT      ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)    \
      ))
    #error "MemMap.h: Close the former variable segment before opening a new one."
#endif



/*------------------------------GLOBAL-START-SECTIONS------------------------------*/

/* Code section */
#ifdef START_SEC_CODE                          
    #define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CODE                          
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CODE_FAST                     
    #define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CODE_FAST                     
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CODE_ISR                      
    #define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CODE_ISR                      
    #undef MEMMAP_ERROR
#endif




/* Const section */
#ifdef START_SEC_CONST_8BIT                    
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_8BIT                    
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_16BIT                   
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_16BIT                   
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_32BIT                   
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_32BIT                   
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_UNSPECIFIED             
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_UNSPECIFIED             
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_FAST_8BIT               
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_8BIT               
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_FAST_16BIT              
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_16BIT              
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_FAST_32BIT              
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_32BIT              
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_FAST_UNSPECIFIED        
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_UNSPECIFIED        
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_PBCFG                   
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_PBCFG                   
    #undef MEMMAP_ERROR
#endif




/* Var section */
#ifdef START_SEC_VAR_INIT_8BIT                 
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_INIT_8BIT                 
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_INIT_16BIT                
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_INIT_16BIT                
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_INIT_32BIT                
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_INIT_32BIT                
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_INIT_UNSPECIFIED          
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_INIT_UNSPECIFIED          
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_NOINIT_8BIT               
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOINIT_8BIT               
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_NOINIT_16BIT              
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOINIT_16BIT              
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_NOINIT_32BIT              
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOINIT_32BIT              
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOINIT_UNSPECIFIED        
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZERO_INIT_8BIT            
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_ZERO_INIT_8BIT            
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZERO_INIT_16BIT           
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_ZERO_INIT_16BIT           
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZERO_INIT_32BIT           
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_ZERO_INIT_32BIT           
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZERO_INIT_UNSPECIFIED     
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_ZERO_INIT_UNSPECIFIED     
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_INIT_8BIT            
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_INIT_8BIT            
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_INIT_16BIT           
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_INIT_16BIT           
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_INIT_32BIT           
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_INIT_32BIT           
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_INIT_UNSPECIFIED     
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_INIT_UNSPECIFIED     
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_8BIT          
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_NOINIT_8BIT          
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_16BIT         
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_NOINIT_16BIT         
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_32BIT         
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_NOINIT_32BIT         
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_UNSPECIFIED   
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_NOINIT_UNSPECIFIED   
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_8BIT       
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_ZERO_INIT_8BIT       
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_16BIT      
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_ZERO_INIT_16BIT      
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_32BIT      
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_ZERO_INIT_32BIT      
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR
#endif



/*------------------------------GENERAL-STOP-SECTIONS-------------------------------*/

/*default segment for Code*/
#ifdef STOP_SEC_CODE
    #undef CODE_SEC_OPEN
/* Enter here a #pragma command for closing the specified section */
/* This should switch back to the default section */
/*    #pragma */
    #undef STOP_SEC_CODE
    #undef MEMMAP_ERROR
#endif

/*default segment for Constants*/
#ifdef STOP_SEC_CONST
    #undef CONST_SEC_OPEN
/* Enter here a #pragma command for closing the specified section */
/* This should switch back to the default section */
/*    #pragma */
    #undef STOP_SEC_CONST
    #undef MEMMAP_ERROR
#endif

/*default segment for Datas*/
#ifdef STOP_SEC_VAR
    #undef VAR_SEC_OPEN
/* Enter here a #pragma command for closing the specified section */
/* This should switch back to the default section */
/*    #pragma */
    #undef STOP_SEC_VAR
    #undef MEMMAP_ERROR
#endif


#ifdef MEMMAP_ERROR
    #error "MemMap.h, wrong pragma command"
#endif

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


/**********************************************************************************************************************
 *  END OF FILE: MemMap.h
 *********************************************************************************************************************/
/************   Organi, Version 3.9.1 Vector-Informatik GmbH  ************/
/************   Organi, Version 3.9.1 Vector-Informatik GmbH  ************/
