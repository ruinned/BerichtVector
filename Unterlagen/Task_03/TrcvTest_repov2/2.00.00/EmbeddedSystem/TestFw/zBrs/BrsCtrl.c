/*  *****   STARTSINGLE_OF_MULTIPLE_COMMENT    *****  */




/*****************************************************************************/
/**
 * \file    BrsCtrl.C
 * \brief   BRS test control, Code
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
 *****************************************************************************
 * \author       A U T H O R   I D E N T I T Y
 *****************************************************************************
 - Initials     Name                      Company
 - ********     *********************     ************************************
 - Ra           Andreas Raisch            Vector Informatik GmbH
 - Uf           Ulrich Frank              Vector Informatik GmbH
 - Get          Matthias Gette            Vector Informatik GmbH
 - Mas          Markus Schwarz            Vector Informatik GmbH
 - Om           Oliver Meili              Vector Informatik GmbH
 - Hrs          Stefan Huebner            Vector Informatik GmbH
 *****************************************************************************
 * \version     R E V I S I O N   H I S T O R Y
 *****************************************************************************
 - Date         Version Author  Description
 - **********   ******* ******  ************************************
 - 2002-08-14   1.00.00 Ra      First Version
 - 2002-09-04   1.00.01 Uf      ESCAN00003659: RDBI/0xF7 allowed for all timers
 - 2003-03-31   1.01.00 Get     memcpy statements replaced by manual copy
                                statements (CAN to local buffer and vice versa)
                                Added ToolVersion report function
 - 2003-05-12   1.02.00 Get     some changes made according to MISRA rules
 - 2003-05-15   1.03.00 Uf      Fixed ToolVersion report function, changed RDI
 - 2003-05-22   1.04.00 Uf      Added C_COMP_XXX retrieval function
 - 2003-05-23   1.05.00 Uf      Validity check define for BrsVInfo
 - 2003-05-26   1.06.00 Ra      Access to CANgen and DBKOMgen versions added
                                Support for SDCOM added
 - 2003-06-13   1.06.01 Get     DBKOMgen version d - 2005-11-18   2.01.02 Uf      Removed ticks in comments
                                generated define -> fixed
 - 2003-06-17   1.07.00 Get     Added message to retrieve FRT resolution via TCC
 - 2003-06-30   1.07.01 Get     BrsCtrlPrecopy compiles even, if no driver has been
                                defined (CAN, LIN)
 - 2003-07-24   1.08.00 Uf      Comments changed to doxygen style
 - 2003-08-22   1.09.00 Ra      Some TCC defines added; BrsCmdInCAN_BusOff added
 - 2003-08-29   1.09.01 Ra      Include sequence changed to allow definition
                                of memory qualifiers in CAN_INC/LIN_INC.
 - 2003-09-10   1.09.02 Get     kBrsMacroAsemblerVersion renamed to
                                kBrsMacroAssemblerVersion
 - 2003-10-08   1.09.03 Uf      RMBA fixed to use huge pointer (MEMORY_HUGE)
 - 2003-10-17   1.09.04 Get     ESCAN00006810: Compilers may report an error
                                               when encountering an empty source file
 - 2003-11-06   1.10.00 Ra      Legal text added, comments 
 - 2004-01-15   1.11.00 Get     Function BrsCtrlSendPositiveResponse is now
                                globally visible.
 - 2004-01-15   1.11.01 Get     Corrected declaration for BrsCtrlSendPositiveResponse
 - 2004-02-01   1.12.00 Ra      CI handlers for DPM, CCP and XCP added; CIL changed to CCL
 - 2004-02-10   1.12.01 Uf      CIL changed to CCL
 - 2004-02-12   1.13.00 Uf      CI handlers added
 - 2004-03-12   1.13.01 Uf      Corrected typing error
 - 2004-03-29   1.14.00 Get     GENy in formation added in BrsCtrlBrsVersions.
                                Still to do: Add versions of GENy components
 - 2004-06-02   1.15.00 Get     TCC via LIN possible
 - 2004-06-29   1.16.00 Uf      Added support for _RELEASE_VERSION defines
 - 2004-10-26   1.17.00 Uf      ESCAN00009968: Support CAN driver with disabled
                                               queue in BRS TCC
                                Added support for new components
                                Header changed to uniform style
 - 2004-11-17   2.00.00 Ra      Access via TCC to event, warning and error 
                                history buffer added. Unused BrsCtrlCyclic10ms
                                removed.
 - 2004-12-16   2.00.01 Uf      BrsAddOn version check fixed
 - 2005-01-11   2.00.02 Uf      MISRA compliant doxygen attributes
 - 2005-01-20   2.00.03 Uf      ONMX support added
 - 2005-01-24   2.00.04 Ra      PCLint warnings removed
 - 2005-02-07   2.01.00 Get     Support for LIN 2.0 added
 - 2005-02-11   2.02.00 Get     DIAG_LIN, PSA-Station-Mgr, FIM, FNM, DCM added
 - 2005-03-16   2.03.00 Uf      Moved #include "can_inc.h" to header
                                Use v_memrom qualifier for const variables
 - 2005-03-17   2.04.00 Uf      Read access to C_CLIENT_<OEM> define
 - 2005-04-12   2.04.01 Get     Minor bugfix
 - 2005-02-11   2.05.00 Mas     NmAsr added, FNM changed to CCL
 - 2005-05-17   2.06.00 Get     Add multi channel support for LIN driver
 - 2005-05-30   2.06.01 Uf      VGEN_ENABLE_NM_ILNI renamed to VGEN_ENABLE_IL_NI
                                CANDesc checks modified
 - 2005-06-02   2.06.02 Mas     VGEN_ENABLE_SBC renamed to VGEN_ENABLE_SBC_DRV
 - 2005-06-09   2.06.03 Get     VGEN_ENABLE_NMBASIC renamed to VGEN_ENABLE_NM_BASIC
 - 2005-07-13   2.07.00 Uf      Added API BrsCtrl(De)ActivateCompUnderTest to set
                                state of testsuites
 - 2005-07-22   2.08.00 Uf      Added support for BrsQNX
 - 2005-07-28   2.09.00 Uf      Added support MOST 
 - 2005-08-16   2.10.00 Uf      Added NM_MAZDA
 - 2005-08-16   3.00.00 Om      Support for BRS on FBL
 - 2005-08-29   3.00.01 Uf      Fixed BrsCtrlDeactivateCompUnderTest declaration
 - 2005-08-30   3.00.02 Uf      Fixed error directive output
 - 2005-09-01   3.01.00 Uf      Added Geny version retrieval
 - 2005-09-13   3.01.01 Uf      CanTransmit result is evaluated always
 - 2005-10-10   3.01.02 Om      Support for BRS on FBL with GENy
 - 2005-11-08   3.01.03 Uf      Fixed RMBA service id
 - 2005-11-09   3.01.04 Om      Added support for AUTOSAR Stack
 - 2005-11-18   3.01.05 Uf      Removed ticks in comments
 - 2005-11-28   3.02.00 Om      Adjusted support for AUTOSAR and FBL
                                Changed bus interface handling
 - 2005-12-06   3.03.00 Uf      BrsCmdIn and BRSCTRL_CODE_ renaming to CQ Names
                                Added filter rule warnings
 - 2005-12-08   3.04.00 Om      Moved BRS_MEMCPY from BrsMain to BrsCtrl
 - 2005-12-15   3.05.00 Uf      Added librarian version scan support
                                Fixed BRS version scan (QNX)
 - 2005-12-22   3.05.01 Uf      Added new components
 - 2006-01-15   3.05.02 Uf      Fixed typo
 - 2006-01-16   3.06.00 Uf      Added CCL Communication Request Service
 - 2006-01-19   3.06.01 Uf      Fixed CCL Communication Request Service
 - 2006-01-30   3.07.00 Uf      Added VGEN_ENABLE_DIAG_FAULTMEMORY check
                                Added new components (to be done)
 - 2006-02-24   3.07.01 Uf      Renamed Common_VStdLib to VStdLib
 - 2006-03-03   3.08.00 Uf      Moved CCL Communication Request to BrsCtrl
                                Added support for DPM
 - 2006-03-06   3.08.01 Uf      Added component Nm_AsrNmCanWrapperExt again
 - 2006-03-07   3.08.02 Uf      Request/ReleaseCommunication Service call fixed
 - 2006-03-14   3.08.03 Mas     Added cast for BrsCtrlRequest/ReleaseCommunication
 - 2006-03-22   3.08.04 Uf      Fixed BrsCtrlRequest/ReleaseCommunication
 - 2006-04-10   3.08.05 Uf      Fixed defines for DPM
 - 2006-04-10   3.09.00 Uf      Added new OEMs
 - 2006-07-18   3.10.00 Uf      Added Diag_CanDescGgdaExt_Gm
                                Added Nm_Honda
 - 2006-07-20   3.10.01 Hrs     Fixed VGEN_ENABLE_DIAG_FAULTMEMORY check in .h
 - 2006-07-25   3.11.00 Get     BrsCtrlReleaseCommunication only possible for
                                externally wakeable NMs
 - 2006-09-06   3.11.01 Mas     Fixed encapsulation VGEN_... for Nm_PwrTrain_Vag
                                Renamed Nm_Honda to Nm_Bcan_Honda
                                Fixed comments in BrsCmdInzBrs
 - 2006-10-27   3.12.00 Svh     Added AUTOSAR Lin support, Il_AsrIfLin, Il_AsrCom
 - 2007-01-08   3.13.00 Get     Add support to measure exceedings of
                                BrsMainMilliSecondHandler
 - 2007-01-26   3.14.00 Mas     Added several new components
****************************************************************************/

/*lint -e537 */ /* Do not inform for repeated include file */
/*lint -e750 */ /* allow unreferenced macros */
/*lint -e714 */ /* allow unreferenced macros */
/*lint -e766 */ /* Do not inform for unused header file */
/*lint -e526 */

/*****************************************************************************
 * Include the files necessary for the Basic Runtime System (BRS)
 *****************************************************************************/

/*
 * Description: The BrsCfg header is used to configure different types of
 *              tests and system setups. Therefore it must be included first
 *              in each BRS and test module.
 *              This file is part of the BRS.
 */
#include "BrsCfg.H"

/*
 * Description: The V_Cfg header is generated by the generation tool. Important 
 *              information like CPU and compiler type, manufacturer information
 *              and a list of currently used CANbedded modules is defined here.
 */
#include "V_Cfg.H"


/****************************************************************************/
#if defined( BRS_ENABLE_TESTCONTROL )



/*****************************************************************************
 * Do all further handling only, if this module is used in the current 
 * configuration
 *****************************************************************************/

/*
 * Description: The V_Def header provides types and definitions common to all 
 *              VECTOR CANbedded modules. They may be already defined in
 *              CAN_INC.H or LIN_INC.H (e.g. MEMORY_ROM for FJ16LX).
 */
#include "V_Def.H"

/*
 * Description: The BrsCtrl header provides all the necessary interfaces to
 *              the test control center module. 
 *              This file is part of the BRS.
 */
#include "BrsCtrl.H"

#if defined( BRSCTRL_USE_CAN_DRV_ASR ) ||  /* should be V_STACKTYPE_AUTOSAR */ \
    defined( BRSCTRL_USE_LIN_DRV_ASR )
/*
 * Description: The ComStack_Types headers contains all the necessary data
 *              types for the AUTOSAR stack. It also includes as of now 
 *              v_def.h
 */
#  include "ComStack_Types.h"
#endif

#if defined( BRSCTRL_USE_CAN_DRV_ASR )
/*
 * Description: AUTOSAR CAN driver header.
 */
#  include "CanIf.h"
#endif

#if defined( BRSCTRL_USE_CAN_DRV_HIS )
/*
 * Description: CANbedded CAN driver header.
 */
#  include "can_inc.h"
#endif

#if defined( BRSCTRL_USE_LIN_DRV )
/*
 * Description: CANbedded LIN driver header.
 */
#  if defined ( VGEN_GENY )
#    include "LIN_API.H"
#  else
#    include "LIN_INC.H"
#  endif
#endif

#if defined( BRSCTRL_USE_LIN_DRV_ASR )
/*
 * Description: AUTOSAR CAN driver header.
 */
#  include "LinIf.h"
#endif

#if defined( BRSCTRL_UNKNOWN_INTERFACE )
#  error "Sorry, BRS TCC needs an interface to communicate!"
#endif


#if defined( BRSCTRL_USE_CAN_DRV_ASR ) /* should be V_STACKTYPE_AUTOSAR */
/*
 * Description: The ComStack_Types headers contains all the necessary data
 *              types for the AUTOSAR stack. It also includes as of now 
 *              v_def.h
 */
#  include "ComStack_Types.h"
#endif

#if defined( BRSCTRL_USE_HW )
/*
 * Description: The BrsHw header is only needed for version report.
 *              This file is part of the BRS.
 */
#  include "BrsHw.H"
#endif /* BRSCTRL_USE_HW */

#if defined( BRSCTRL_USE_MAIN )
/*
 * Description: The BrsMain header provides all the necessary interfaces to
 *              the main BRS module. 
 *              This file is part of the BRS.
 */
#  include "BrsMain.H"
#endif /* BRSCTRL_USE_MAIN */

#if defined( BRS_ENABLE_STATIONMANAGER )
/*
 * Description: The BrsStaMa header provides all the necessary interfaces to
 *              the station management. Please refer to the BrsStaMa module
 *              for details of the used station management algorithm.
 *              This file is part of the BRS.
 */
#  include "BrsStaMa.H"
#endif


#if defined( BRS_ENABLE_TESTADDON )
/*
 * Description: The BrsAddOn header provides all the necessary interfaces to
 *              the test support add on module. Please refer to the BrsAddOn
 *              module for details of the supported add on's.
 *              This file is part of the BRS.
 */
#  include "BrsAddOn.H"
#endif


#if defined( BRS_ENABLE_OSEKOS )
/*
 * Description: The BrsOSEK header provides all the necessary interfaces, if
 *              an OSEK operating system is used with the BRS instead of the
 *              BRS time base handler.
 */
#  include "BrsOSEK.h"
#endif
 
 
#if defined( BRS_ENABLE_TOOL_VERSIONINFO )
/*
 * Description: The BrsVInf header provides version output from the used tools
 *              like compiler, assembler and linker. It is generated by the
 *              MakeSupport (V > 3.8.0) if TOOL_VERSION_USED is set to 1 in
 *              the Makefile.project.part.defines and "ToolVersion support is 
 *              selected in the GenerationTool on the BRS page.
 */
 #define _BRS_V_INFO_VALID
 #include "BrsVInfo.h"
#endif

#if defined VGEN_GENY
/*
 * Description: The V_Par header provides GENy version information
 */
#  include "V_Par.h"
#endif

#if defined( VGEN_ENABLE_CCL )
/*
 * Description: Communication Control Layer header
 */
#  include "ccl_inc.h"
#endif

#if defined( VGEN_ENABLE_DPM )
/*
 * Description: This is the DPM header
 */
#include "dpm.h"
#endif


/******************************************************************************
 * Version check
 ******************************************************************************/
#if( BRS_CTRL_VERSION != 0x0314 )
#  error "Header and source file are inconsistent!"
#endif
#if( BRS_CTRL_RELEASE_VERSION != 0x00 )
#  error "Different release versions in Header and Source used!"
#endif


/******************************************************************************
 * other checks
 ******************************************************************************/
#if !defined( kBrsTccChannel )
  #error "kBrsTccChannel not available. Should be generated to BrsCfg.H, check gentool version!"
#endif
#if defined( BRSCTRL_USE_CAN_DRV_ASR ) || \
    defined( BRSCTRL_USE_CAN_DRV_HIS ) || \
    defined( BRSCTRL_USE_LIN_DRV )     || \
    defined( BRSCTRL_USE_LIN_DRV_ASR )
#  if !defined( BrsCtrlTstMsgTxHandle )
#    error "BrsCtrlTstMsgTxHandle not available. Should be generated to BrsCfg.H, check gentool version!"
#  endif
#endif /* BRSCTRL_USE_CAN_DRV_* || BRSCTRL_USE_LIN_DRV */

#if defined( BRS_ENABLE_TESTADDON )
  /* Compatibility check for BrsAddOn version */
  #if (BRS_ADDON_VERSION<0x0304)
    #error "Sorry, this version of BrsCtrl needs at least BrsAddOn 3.04 or later!"
  #endif
#endif

/*******************************************************************************
* Global defines
* _BRS_MEMCPY needs a MEMORY_FAR for the SRC parameter due to e.g. FJ16 with ROM
* tables in the far memory area (no mirror memory used). MEMORY_FAR may be 
* defined to nothing depending on the platform.
* Some compilers - e.g. Tasking for Tricore - do not allow explicit cast to
* near or far memory.
*******************************************************************************/
#if defined( VGEN_ENABLE_VSTDLIB )
#  define _BRS_MEMCPY(d,s,l) VStdMemCpyRamToRam((d),(s),(l))
#else
#  if defined( C_COMP_TASKING_TRICORE_TWINCAN )
#    define BRS_MEMCPY_SOURCE_ASSIGN(s) src=(vuint8 *) (s)
#  else
#    define BRS_MEMCPY_SOURCE_ASSIGN(s) src=(vuint8 MEMORY_FAR *) (s)
#  endif
#  define _BRS_MEMCPY(d,s,l)               \
          {                                \
              vuint8 len;                  \
              vuint8 *dst;                 \
              vuint8 MEMORY_FAR *src;      \
              len = (l);                   \
              dst = (vuint8 *) (d);        \
              BRS_MEMCPY_SOURCE_ASSIGN(s); \
              while(len--) {               \
                *dst++ = *src++;           \
              }                            \
          }
#endif /* VGEN_ENABLE_VSTDLIB */

/******************************************************************************
 * Local global function prototypes
 ******************************************************************************/
#if defined VGEN_GENY
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kGENyVersion[kGENyVersionNumberOfBytes];
#endif

/*******************************************************************************
* Global variables
*******************************************************************************/

/**
 * \var gbBrsCtrlMsgBuffer
 *      Global BRS Message Buffer used for test control data handling.
 */
vuint8 gbBrsCtrlMsgBuffer[8];

/**
 * \var gbBrsCtrlCompUnderTestCI
 *      Global TS state (holds CI of active component under test)
 */
vuint8 gbBrsCtrlCompUnderTestCI;

#if defined( BRSCTRL_USE_CAN_DRV_HIS ) || \
    defined( BRSCTRL_USE_CAN_DRV_ASR )
/**
 * \var gbBrsCtrlRetryTransmit
 *      This variable indicates whether the transmission has to be retried or not.
 */
vuint8 gbBrsCtrlRetryTransmit;
#endif /* BRSCTRL_USE_CAN_DRV_* */

#if defined( BRSCTRL_USE_CAN_DRV_ASR ) || \
    defined( BRSCTRL_USE_LIN_DRV_ASR )
/**
 * \var gbBrsCtrlTxMsgBuffer
 *      This variables contains a buffer for the PDU to be transmitted by the
 *      AUTOSAR CanIf.
 */
PduInfoType gbBrsCtrlTxMsgBuffer;
#endif /* BRSCTRL_USE_CAN_DRV_ASR || BRSCTRL_USE_LIN_DRV_ASR */


#if defined( BRSCTRL_USE_DIAG ) || \
    defined( BRSCTRL_USE_MOST_DRV )
static vuint8 *gbBrsCtrlTxMsgBuffer;
#endif

/**
 * \var gbBrsCtrlForceSleep
 *      This variables forces removement of bus request even if system is
 *      not wakeable externally
 */
vuint8 gbBrsCtrlForceSleep;

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
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kBrsCtrlMainVersion    = (vuint8)(BRS_CTRL_VERSION >> 8);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kBrsCtrlSubVersion     = (vuint8)(BRS_CTRL_VERSION); /*lint !e778 */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kBrsCtrlReleaseVersion = (vuint8)(BRS_CTRL_RELEASE_VERSION);

#if defined ( C_COMP_IAR_M16C )
  #if defined ( _NEAR_ )
  /* Normal segment usage */
  #pragma memory=default
  #endif
#endif /*C_COMP_IAR_M16C*/


/*******************************************************************************
* Local defines
*******************************************************************************/
#define BRSCTRL_FCT_LIN_INVALID_RQ_FRAME   0x80
#define BRSCTRL_RI_SET_COMP_UNDER_TEST     0x10
#define BRSCTRL_SET_CCL_COMM_REQUEST       0x20
#define BRSCTRL_SET_INTERNAL_STATE         0x00
#define BRSCTRL_SET_FORCE_SLEEP            0x20
#define BRSCTRL_MS_TASK_SUPERVISION        0x30

#define BRSCTRL_CHANNEL_IS_NON_WAKEABLE    0
#define BRSCTRL_CHANNEL_IS_WAKEABLE        1

/*
 * Description: This define is typically defined within V_DEF.H. If not - make it
 *              here known and set it to nothing. The platform does not need this 
 *              memory type!
 */
#ifndef MEMORY_HUGE
  #define MEMORY_HUGE
#endif

#if defined( BRSCTRL_USE_CAN_DRV_HIS )
#  define BrsTccCanTransmit(channel) _BrsTccCanTransmit(channel)
#  define _BrsTccCanTransmit(channel) CanTransmit_##channel
#endif /* BRSCTRL_USE_CAN_DRV_HIS */

/*******************************************************************************
* Local typedef
*******************************************************************************/
typedef enum eBrsCtrl_OEMType {
  kBrsCtrl_OEM_DBAG    =   0, /* Manufacturer = "DC"       */
  kBrsCtrl_OEM_VAG     =   1, /* Manufacturer = "VAG"      */
  kBrsCtrl_OEM_BMW     =   2, /* Manufacturer = "BMWAG"    */
  kBrsCtrl_OEM_PAG     =   3, /* Manufacturer = "PAG"      */
  kBrsCtrl_OEM_GM      =   4, /* Manufacturer = "GM"       */
  kBrsCtrl_OEM_FIAT    =   5, /* Manufacturer = "Fiat"     */
  kBrsCtrl_OEM_VECTOR  =   6, /* Manufacturer = "Vector"   */
  kBrsCtrl_OEM_DCNFZ   =   7, /* Manufacturer = "DC-Truck" */
  kBrsCtrl_OEM_FORD    =   8, /* Manufacturer = "Ford"     */
  kBrsCtrl_OEM_RENAULT =   9, /* Manufacturer = "Renault"  */
  kBrsCtrl_OEM_PSA     =  10, /* Manufacturer = "PSA"      */
  kBrsCtrl_OEM_SCANIA  =  11, /* Manufacturer = ""         */
  kBrsCtrl_OEM_MMC     =  12, /* Manufacturer = "MMC"      */
  kBrsCtrl_OEM_CLAAS   =  13, /* Manufacturer = ""         */
  kBrsCtrl_OEM_HYUNDAI =  14, /* Manufacturer = ""         */
  kBrsCtrl_OEM_DAF     =  15, /* Manufacturer = ""         */
  kBrsCtrl_OEM_SYMC    =  16, /* Manufacturer = ""         */
  kBrsCtrl_OEM_MAN     =  17, /* Manufacturer = ""         */
  kBrsCtrl_OEM_FAW     =  18, /* Manufacturer = ""         */
  kBrsCtrl_OEM_HONDA   = 128, /* Manufacturer = ""         */
  kBrsCtrl_OEM_UNKNOWN = 255  /* Manufacturer = ""         */
} eBrsCtrl_OEMType;

/*******************************************************************************
* Local variables
*******************************************************************************/


/*******************************************************************************
* Local const variables
*******************************************************************************/
#if defined ( C_COMP_IAR_M16C )
  #if defined ( _NEAR_ )
  /* Set const data to const segment, don't initialize */
  #pragma memory=constseg(CONST_DATA) :far
  #endif
#endif

/* None used */

#if defined ( C_COMP_IAR_M16C )
  #if defined ( _NEAR_ )
  /* Normal segment usage */
  #pragma memory=default
  #endif
#endif


/*******************************************************************************
* Prototypes of global functions 
*******************************************************************************/
#if defined( VGEN_ENABLE_CCL )
static vuint8 BrsCtrlRequestCommunication(
  eBrsCtrlBusType type, 
  vuint8 chnl, 
  vuint8 node
);
static vuint8 BrsCtrlReleaseCommunication(
  eBrsCtrlBusType type, 
  vuint8 chnl, 
  vuint8 node
);
#endif

/*******************************************************************************
* Prototypes of local functions 
*******************************************************************************/
static vuint8 BrsCtrlBrsVersions( 
  void 
);

#if defined( BRS_ENABLE_TOOL_VERSIONINFO )
static vuint8 BrsCtrlToolVersions(
  void 
);
#endif /* BRS_ENABLE_TOOL_VERSIONINFO */

static void BrsCmdInzBrs( 
  void 
);

static vuint8 BrsCtrlActivateCompUnderTest(
  vuint8 ci
);

static void BrsCtrlDeactivateCompUnderTest(
  void
);

#if defined( VGEN_ENABLE_NM_BASIC )  || \
    defined( VGEN_ENABLE_NM_JUNIOR )
static vuint8 BrsCtrlChannelIsExternallyWakeable(vuint8 chnl);
#endif

/*******************************************************************************
* Function definitions
*******************************************************************************/
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
)
{
#if defined( BRSCTRL_USE_CAN_DRV_ASR )
  gbBrsCtrlRetryTransmit = E_OK;
#endif

#if defined( BRSCTRL_USE_CAN_DRV_ASR ) || \
    defined( BRSCTRL_USE_LIN_DRV_ASR )
  gbBrsCtrlTxMsgBuffer.SduDataPtr = (uint8 *)&gbBrsCtrlMsgBuffer[0];
  gbBrsCtrlTxMsgBuffer.SduLength = 8;
#elif defined( BRSCTRL_USE_CAN_DRV_HIS )
  gbBrsCtrlRetryTransmit = kCanOk;
#elif defined( BRSCTRL_USE_MOST_DRV ) || \
      defined( BRSCTRL_USE_DIAG )
  gbBrsCtrlTxMsgBuffer = 0;
#endif
  gbBrsCtrlCompUnderTestCI = 0xFF;
  gbBrsCtrlForceSleep = 0;
}


/*******************************************************************************/
/**
 * \brief This APIis used by each test suite implementation to send an already
 *        prepared TCC response back.
 *
 * \attention Make sure the answer is valid! E.g. the 0x40 has been added to
 *            the requested SId.
 *
 * \post      The TCC will send its answer as soon as possible.
 */
void BrsCtrlSendResponse( 
  void 
)
{
#if defined( BRSCTRL_USE_CAN_DRV_ASR )
  gbBrsCtrlRetryTransmit = CanIf_Transmit(BrsCtrlTstMsgTxHandle, &gbBrsCtrlTxMsgBuffer);
#elif defined( BRSCTRL_USE_CAN_DRV_HIS )
  TxDataPtr pData;
#  if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  pData = CanGetTxDataPtr(BrsCtrlTstMsgTxHandle);
  _BRS_MEMCPY(pData, gbBrsCtrlMsgBuffer, 8);

  gbBrsCtrlRetryTransmit = CanTransmit(BrsCtrlTstMsgTxHandle);
#  else
  switch (kBrsTccChannel)  {
    /* It is possible that warnings "unreachable statement/code" appear at this line
     * when using code doubled CAN driver. TCC traffic is possible on just one channel,
     * which is determined by the switch statement evaluating a constant expression.
     * These warnings may be safely ignored.
     */
    case 0:
      pData = CanGetTxDataPtr(BrsCtrlTstMsgTxHandle);
      _BRS_MEMCPY(pData, gbBrsCtrlMsgBuffer, 8);
      break;
    default:
      BrsAssertUserDirect(kBrsTccChannelOutOfRange,BRSERROR_MODULE_BRSCTRL);
  }
#    if ( kCanNumberOfChannels == 1 )
  gbBrsCtrlRetryTransmit = CanTransmit(BrsCtrlTstMsgTxHandle);
#    else
  gbBrsCtrlRetryTransmit = BrsTccCanTransmit(kBrsTccChannel)(BrsCtrlTstMsgTxHandle);
#    endif
#  endif /* C_MULTIPLE_RECEIVE_CHANNEL */
#elif defined( BRSCTRL_USE_LIN_DRV ) 
  TxDataPtr pData = capbLinRxTxMsgDataPtr[BrsCtrlTstMsgTxHandle];  

  BrsHwDisableInterrupt();
  _BRS_MEMCPY(pData, gbBrsCtrlMsgBuffer, 8);
  BrsHwRestoreInterrupt();
#elif defined( BRSCTRL_USE_LIN_DRV_ASR )
/* data is requested in seperat function */
#elif defined( BRSCTRL_USE_MOST_DRV )
  BrsHwDisableInterrupt();
  _BRS_MEMCPY(gbBrsCtrlTxMsgBuffer, gbBrsCtrlMsgBuffer, 8);
  BrsHwRestoreInterrupt();
#elif defined( BRSCTRL_USE_DIAG )
  _BRS_MEMCPY(gbBrsCtrlTxMsgBuffer, gbBrsCtrlMsgBuffer, 8);
#endif /* BRSCTRL_USE_DIAG */

}

#if defined( BRSCTRL_USE_LIN_DRV_ASR )
void BrsCtrlRequestResponse(vuint8 * pData)
{
  BrsHwDisableInterrupt();
  _BRS_MEMCPY(pData, gbBrsCtrlMsgBuffer, 8);
  BrsHwRestoreInterrupt();
}
#endif

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
)
{
  gbBrsCtrlMsgBuffer[1] |= 0x40;

  BrsCtrlSendResponse();
}


/*******************************************************************************/
/**
 * \brief This API is used by each test suite implementation to send an NEGATIVE
 *        response to the TCC.
 *
 * \param[in] ErrorCode has tobe selected as specificed in the BrsCtrl header.
 *
 * \post      The TCC will send its answer as soon as possible.
 */
void BrsCtrlSendNegResponse(
  vuint8 ErrorCode
)
{
  gbBrsCtrlMsgBuffer[3] = ErrorCode;
  gbBrsCtrlMsgBuffer[2] = gbBrsCtrlMsgBuffer[1];
  gbBrsCtrlMsgBuffer[1] = gbBrsCtrlMsgBuffer[0];
  gbBrsCtrlMsgBuffer[0] = BRSCTRL_NACK;
  
  gbBrsCtrlMsgBuffer[4] = 0;
  gbBrsCtrlMsgBuffer[5] = 0;
  gbBrsCtrlMsgBuffer[6] = 0;
  gbBrsCtrlMsgBuffer[7] = 0;
  
  BrsCtrlSendResponse();
}

/*******************************************************************************/
/**
 * \brief This API is used by the TCC to retransmit a test message, which has
 *        not been transmitted in the previous try.
 *
 * \attention This function has to be called by the main communication task
 *             (usually BrsMainMilliSecondHandler).
 *
 * \post      The TCC tries to send the message immediately setting a global flag
 *            with the outcome.
 */
void BrsCtrlRetryTransmit(
  void
)
{
#if defined( BRSCTRL_USE_CAN_DRV_ASR )
  if (E_OK != gbBrsCtrlRetryTransmit) {
    gbBrsCtrlRetryTransmit = CanIf_Transmit(BrsCtrlTstMsgTxHandle, &gbBrsCtrlTxMsgBuffer);
  }
#elif defined( BRSCTRL_USE_CAN_DRV_HIS )
  if (kCanTxOk != gbBrsCtrlRetryTransmit) {
#  if defined( C_MULTIPLE_RECEIVE_CHANNEL ) || ( kCanNumberOfChannels == 1 )
    gbBrsCtrlRetryTransmit = CanTransmit(BrsCtrlTstMsgTxHandle);
#  else
    gbBrsCtrlRetryTransmit = BrsTccCanTransmit(kBrsTccChannel)(BrsCtrlTstMsgTxHandle);
#  endif
  }
#endif
}

/*******************************************************************************/
/**
 * \brief Precopy function of the test control message to implement the main 
 *        test request handler.
 *        This TCC handling is NOT secured against multiple message reception to 
 *        reduce the runtime overhead. To prevent multiple messages being received,
 *        the SERIALIZER DLL must be used.    
 *        (Possible failures due to double transmitted CAN  frames are not covered 
 *        by this approach!). The first byte (component id) of the message will be
 *        analyzed and the corresponding command interpreter will be called by 
 *        this function.
 *
 * \param[in] datPtr message buffer of the CAN/LIN message
 * 
 * \retval kCanNoCopyData/kLinNoCopyData to stop further driver hndling
 *
 * \pre   Received message must have DLC=8
 *
 * \post  The TCC will send its answer as soon as possible.
 */
#if defined( BRSCTRL_USE_CAN_DRV_ASR )
void BrsCtrl_RxIndication(PduIdType PduId, const uint8 *datPtr)
{
  const uint8 *src = datPtr;
#elif defined( BRSCTRL_USE_CAN_DRV_HIS )
#  if defined ( C_MULTIPLE_RECEIVE_BUFFER )
canuint8 BrsCtrlPrecopy(
  CanChipDataPtr datPtr
)
{
  CanChipDataPtr src = datPtr;
#  endif /* C_MULTIPLE_RECEIVE_BUFFER */
#  if defined ( C_SINGLE_RECEIVE_BUFFER )
#    define datPtr (&(*((canuint8 *)CanRDSPtr)))
canuint8 BrsCtrlPrecopy(
  canuint8 dataHandle
)
{
  canuint8* src = datPtr;
#  endif /* C_SINGLE_RECEIVE_BUFFER */
#  if defined( C_SINGLE_RECEIVE_CHANNEL )
#    define datPtr rxStruct->pChipData
canuint8 BrsCtrlPrecopy(
  CanRxInfoStructPtr rxStruct
)
{
  CanChipDataPtr src = datPtr;
#  endif /* C_SINGLE_RECEIVE_CHANNEL */
#  if defined( C_MULTIPLE_RECEIVE_CHANNEL )
#    define datPtr rxStruct->pChipData
canuint8 BrsCtrlPrecopy(
  CanRxInfoStructPtr rxStruct
)
{
  CanChipDataPtr src = datPtr;
#  endif /* C_MULTIPLE_RECEIVE_CHANNEL */
#elif defined( BRSCTRL_USE_LIN_DRV )
#  if defined( LIN_APITYPE_INDEXED )
canuint8 BrsCtrlPrecopy(
  tLinMsgBufferStruct MsgBufferStruct
)
{
  vuint8* src = MsgBufferStruct.pbMsgBuffer;
#  else
canuint8 BrsCtrlPrecopy(
  canuint8* rxBuffer
)
{
  vuint8* src = rxBuffer;
#  endif
#elif defined( BRSCTRL_USE_MOST_DRV ) || \
      defined( BRSCTRL_USE_DIAG )
canuint8 BrsCtrlPrecopy(
  vuint8 *Rx_Ptr, vuint8 *Tx_Ptr
)
{
  canuint8* src = Rx_Ptr;
#else
/* This is a dummy declaration, if no driver is being used */
vuint8 BrsCtrlPrecopy(
  vuint8 *datPtr
)
{
  canuint8* src = datPtr;
#endif

  vuint8 *dst = gbBrsCtrlMsgBuffer;
  vuint8 i = 8;

#if defined( BRSCTRL_USE_MOST_DRV ) || \
    defined( BRSCTRL_USE_DIAG )
  gbBrsCtrlTxMsgBuffer = Tx_Ptr;
#endif

  while (i--)
  {
      *dst++ = *src++;
  }

  switch( gbBrsCtrlMsgBuffer[0] ) {
#if defined( VGEN_ENABLE_CCL )
  case BRSCTRL_CODE_CCL:
    BrsCmdInCcl();
    break;
#endif
#if defined( VGEN_ENABLE_CCL_ASRCOMM )
  case BRSCTRL_CODE_CCL_ASRCOMM:
    BrsCmdInCcl_AsrComM();
    break;
#endif
#if defined( VGEN_ENABLE_CCLCOM )
  case BRSCTRL_CODE_CCL_CCLCOM:
    BrsCmdInCcl_CclCom();
    break;
#endif
#if defined( VGEN_ENABLE_DPM )
  case BRSCTRL_CODE_CCL_DPM:
    BrsCmdInCcl_Dpm();
    break;
#endif
  case BRSCTRL_CODE_COMMON_VDEF:
    BrsCmdInCommon_Vdef();
    break;
#if defined( VGEN_ENABLE_VSTDLIB )
  case BRSCTRL_CODE_VSTDLIB:
    BrsCmdInVStdLib();
    break;
#endif
#if defined( VGEN_ENABLE_CCP )
  case BRSCTRL_CODE_CP_CCP:
    BrsCmdInCp_Ccp();
    break;
#endif
#if defined( VGEN_ENABLE_XCP )
  case BRSCTRL_CODE_CP_XCP:
    BrsCmdInCp_Xcp();
    break;
#endif
#if defined( VGEN_ENABLE_XCPONCAN )
  case BRSCTRL_CODE_CP_XCPONCAN:
    BrsCmdInCp_XcpOnCan();
    break;
#endif
#if defined( VGEN_ENABLE_XCPONCANASR )
  case BRSCTRL_CODE_CP_XCPONCANASR:
    BrsCmdInCp_XcpOnCanAsr();
    break;
#endif
#if defined( VGEN_ENABLE_XCPONFR )
  case BRSCTRL_CODE_CP_XCPONFR:
    BrsCmdInCp_XcpOnFr();
    break;
#endif
#if defined( VGEN_ENABLE_XCPONLIN )
  case BRSCTRL_CODE_CP_XCPONLIN:
    BrsCmdInCp_XcpOnLin();
    break;
#endif
#if defined( VGEN_ENABLE_DIAG_STANDARD )
  case BRSCTRL_CODE_DIAG:
    BrsCmdInDiag();
    break;
#endif
#if defined( VGEN_ENABLE_COMSERV_DCM )
  case BRSCTRL_CODE_DIAG_ASRDCM:
    BrsCmdInDiag_AsrDcm();
    break;
#endif
#if defined( VGEN_ENABLE_DIAG_ASRDEM )
  case BRSCTRL_CODE_DIAG_ASRDEM:
    BrsCmdInDiag_AsrDem();
    break;
#endif
#if defined( VGEN_ENABLE_DIAG_CANDESC )     || \
    defined( VGEN_ENABLE_DIAG_CANDESC_DCM ) || \
    defined( VGEN_ENABLE_DIAG_CANDESC_KWP ) || \
    defined( VGEN_ENABLE_DIAG_CANDESC_UDS )
  case BRSCTRL_CODE_DIAG_CANDESC__COREBASE:
    BrsCmdInDiag_CanDesc__coreBase();
    break;
#endif
#if defined( VGEN_ENABLE_DIAG_CANDESC_BASIC )     || \
    defined( VGEN_ENABLE_DIAG_CANDESC_BASIC_DCM ) || \
    defined( VGEN_ENABLE_DIAG_CANDESC_BASIC_KWP ) || \
    defined( VGEN_ENABLE_DIAG_CANDESC_BASIC_UDS )
  case BRSCTRL_CODE_DIAG_CANDESC__COREBASIC:
    BrsCmdInDiag_CanDesc__coreBasic();
    break;
#endif
#if defined( VGEN_ENABLE_DIAG_CANDESCGGDAEXT_GM )
  case BRSCTRL_CODE_DIAG_CANDESCGGDAEXT_GM:
    BrsCmdInDiag_CanDescGgdaExt_Gm();
    break;
#endif
#if defined( VGEN_ENABLE_FRFM ) || \
    defined( VGEN_ENABLE_DIAG_FAULTMEMORY )
  case BRSCTRL_CODE_DIAG_FAULTMEMORY:
    BrsCmdInDiag_FaultMemory();
    break;
#endif
#if defined( VGEN_ENABLE_SDCOM ) 
  case BRSCTRL_CODE_DIAG_SDCOM_DC:
    BrsCmdInDiag_Sdcom_Dc();
    break;
#endif
#if defined( VGEN_ENABLE_DIAG_X ) 
  case BRSCTRL_CODE_DIAG_X:
    BrsCmdInDiag_X();
    break;
#endif
#if defined( VGEN_ENABLE_DIAGLIN ) 
  case BRSCTRL_CODE_DIAGLIN:
    BrsCmdInDiagLin();
    break;
#endif
#if defined( VGEN_ENABLE_CAN_DRV ) 
  case BRSCTRL_CODE_DRVCAN:
    BrsCmdInDrvCan();
    break;
  case BRSCTRL_CODE_DRVCAN_BUSOFF:
    BrsCmdInDrvCan_BusOff();
    break;
#endif
#if defined( VGEN_ENABLE_FBL_EEPDRV ) 
  case BRSCTRL_CODE_DRVEEP:
    BrsCmdInDrvEep();
    break;
#endif
#if defined( VGEN_ENABLE_DRV_FLEXRAY ) 
  case BRSCTRL_CODE_DRVFR:
    BrsCmdInDrvFr();
    break;
#endif
#if defined( VGEN_ENABLE_LIN_DRV ) 
  case BRSCTRL_CODE_DRVLIN:
    if ( BRSCTRL_FCT_LIN_INVALID_RQ_FRAME == gbBrsCtrlMsgBuffer[1] ) {
      BrsCtrlSendPosResponse();
    }
    else {
      BrsCmdInDrvLin();
    }
    break;
#  if defined( BRSCTRL_USE_LIN_DRV ) 
  case BRSCTRL_CODE_DRVSIO:
    BrsCmdInDrvSio();
    break;
#  endif
#endif
#if defined( VGEN_ENABLE_SPI ) 
  case BRSCTRL_CODE_DRVSPI:
    BrsCmdInDrvSpi();
    break;
#endif
#if defined( VGEN_ENABLE_SBC_DRV ) 
  case BRSCTRL_CODE_DRVTRANS:
    BrsCmdInDrvTrans();
    break;
#endif
#if defined( VGEN_ENABLE_FBL ) || \
    defined( VGEN_ENABLE_CANFBL )
  case BRSCTRL_CODE_FBLCAN:
    BrsCmdInFblCan();
    break;
  case BRSCTRL_CODE_FBLDIAG:
    BrsCmdInFblDiag();
    break;
  case BRSCTRL_CODE_FBLAPI:
    BrsCmdInFblApi();
    break;
  case BRSCTRL_CODE_FBLHW:
    BrsCmdInFblHw();
    break;
#endif
#if defined( VGEN_ENABLE_GW_AS_DC ) 
  case BRSCTRL_CODE_GW_ADMIN_DC:
    BrsCmdInGw_Admin_Dc();
    break;
#endif
#if defined( VGEN_ENABLE_GW_ASRPDUR ) 
  case BRSCTRL_CODE_GW_ASRPDUR:
    BrsCmdInGw_AsrPduR();
    break;
#endif
#if defined( VGEN_ENABLE_DCI ) 
  case BRSCTRL_CODE_GW_DYNAMICCANINTERFACE:
    BrsCmdInGw_DynamicCanInterface();
    break;
#endif
#if defined( VGEN_ENABLE_GW_DYNAMICFRINTERFACE ) 
  case BRSCTRL_CODE_GW_DYNAMICFRINTERFACE:
    BrsCmdInGw_DynamicFrInterface();
    break;
#endif
#if defined( VGEN_ENABLE_GW_CAN_DC ) 
  case BRSCTRL_CODE_GW_GATEWAY:
    BrsCmdInGw_Gateway();
    break;
#endif
#if defined( VGEN_ENABLE_IF_ASRIFCAN ) 
  case BRSCTRL_CODE_IF_ASRIFCAN:
    BrsCmdInIf_AsrIfCan();
    break;
#endif
#if defined( VGEN_ENABLE_IF_ASRIFLIN ) 
  case BRSCTRL_CODE_IF_ASRIFLIN:
    BrsCmdInIf_AsrIfLin();
    break;
#endif
#if defined( VGEN_ENABLE_IF_ASRIFFR )
  case BRSCTRL_CODE_IF_ASRIFFR:
    BrsCmdInIf_AsrIfFr();
    break;
#endif
#if defined( VGEN_ENABLE_IL_DBKOM )
  case BRSCTRL_CODE_IL_DBKOM:
    BrsCmdInIl_Dbkom();
    break;
#endif
#if defined( VGEN_ENABLE_DCPT )
  case BRSCTRL_CODE_IL_DBKOMPWRTRAINEXT_DC:
    BrsCmdInIl_DbkomPwrTrainExt_Dc();
    break;
#endif
#if defined( VGEN_ENABLE_IL_ASRCOM )
  case BRSCTRL_CODE_IL_ASRCOM:
    BrsCmdInIl_AsrCom();
    break;
#endif
#if defined( VGEN_ENABLE_ILFR_SIGIF_VECTOR )
  case BRSCTRL_CODE_ILFR_SIGIF_VECTOR:
    BrsCmdInIlFr_SigIf_Vector();
    break;
#endif
#if defined( VGEN_ENABLE_IL_GM )
  case BRSCTRL_CODE_IL_GMLAN2X:
    BrsCmdInIl_Gmlan2x();
    break;
#endif
#if defined( VGEN_ENABLE_IL_MM )
  case BRSCTRL_CODE_IL_MM_BMW:
    BrsCmdInIl_Mm_Bmw();
    break;
#endif
#if defined( VGEN_ENABLE_NM_ILNI ) || \
    defined( VGEN_ENABLE_IL_NI )
  case BRSCTRL_CODE_IL_NI_FORD:
    BrsCmdInIl_Ni_Ford();
    break;
#endif
#if defined( VGEN_ENABLE_IL_VECTOR )
  case BRSCTRL_CODE_IL_VECTOR:
    BrsCmdInIl_Vector();
    break;
#endif
#if defined( VGEN_ENABLE_NM_ASR_CAN )
  case BRSCTRL_CODE_NM_ASRNMCAN:
    BrsCmdInNm_AsrNmCan();
    break;
#endif
#if defined( VGEN_ENABLE_NM_ASR_CAN )
  case BRSCTRL_CODE_NM_ASRNMCANWRAPPEREXT:
    BrsCmdInNm_AsrNmCanWrapperExt();
    break;
#endif
#if defined( VGEN_ENABLE_NM_ASRNMFR )
  case BRSCTRL_CODE_NM_ASRNMFR:
    BrsCmdInNm_AsrNmFr();
    break;
#endif
#if defined( VGEN_ENABLE_NM_ASRNMFR_VAG )
  case BRSCTRL_CODE_NM_ASRNMFR_VAG:
    BrsCmdInNm_AsrNmFr_Vag();
    break;
#endif
#if defined( VGEN_ENABLE_NM_ASRNMIF )
  case BRSCTRL_CODE_NM_ASRNMIF:
    BrsCmdInNm_AsrNmIf();
    break;
#endif
#if defined( VGEN_ENABLE_NM_ASR_GENERIC )
  case BRSCTRL_CODE_NM_ASRNMGENERIC:
    BrsCmdInNm_AsrNmGeneric();
    break;
#endif
#if defined( VGEN_ENABLE_NM_ASR_GENERIC_VAG )
  case BRSCTRL_CODE_NM_ASRNMGENERIC_VAG:
    BrsCmdInNm_AsrNmGeneric_Vag();
    break;
#endif
#if defined( VGEN_ENABLE_NM_FIAT15  ) || \
    defined( VGEN_ENABLE_NM_FIAT30 )  || \
    defined( VGEN_ENABLE_NM_FIAT_MASTER )
  case BRSCTRL_CODE_NM_CLASSB_FIAT:
    BrsCmdInNm_ClassB_Fiat();
    break;
#endif
#if defined( VGEN_ENABLE_NM_OSEK_D )
  case BRSCTRL_CODE_NM_DIROSEK:
    BrsCmdInNm_DirOsek();
    break;
#endif
#if defined( VGEN_ENABLE_NM_OSEK_D_UD )
  case BRSCTRL_CODE_NM_DIROSEKUSERDATA_DC:
    BrsCmdInNm_DirOsekUserdata_Dc();
    break;
#endif
#if defined( VGEN_ENABLE_NM_GMLAN )
  case BRSCTRL_CODE_NM_GMLAN_GM:
    BrsCmdInNm_Gmlan_Gm();
    break;
#endif
#if defined( VGEN_ENABLE_NMVAGC )        || \
    defined( VGEN_ENABLE_NMVAGC_BASIC )  || \
    defined( VGEN_ENABLE_NMVAGC_MASTER ) || \
    defined( VGEN_ENABLE_NMVAGC_SLAVE )
  case BRSCTRL_CODE_NM_IND_VAG:
    BrsCmdInNm_Ind_Vag();
    break;
#endif
#if defined( VGEN_ENABLE_NM_OSEK_I )
  case BRSCTRL_CODE_NM_INDOSEK:
    BrsCmdInNm_IndOsek();
    break;
#endif
#if defined( VGEN_ENABLE_NM_IVLAN )
  case BRSCTRL_CODE_NM_IVLAN:
    BrsCmdInNm_Ivlan();
    break;
#endif
#if defined( VGEN_ENABLE_NM_JUNIOR )
  case BRSCTRL_CODE_NM_JUNIOR:
    BrsCmdInNm_Junior();
    break;
#endif
#if defined( VGEN_ENABLE_NM_FIATC ) || \
    defined( VGEN_ENABLE_NMFIATC_STD )
  case BRSCTRL_CODE_NM_PWRTRAIN_FIAT:
    BrsCmdInNm_PwrTrain_Fiat();
    break;
#endif
#if defined( VGEN_ENABLE_NM_MAZDA )
  case BRSCTRL_CODE_NM_PWRTRAIN_MAZDA:
    BrsCmdInNm_PwrTrain_Mazda();
    break;
#endif
#if defined( VGEN_ENABLE_NM_BCAN_HONDA )
  case BRSCTRL_CODE_NM_BCAN_HONDA:
    BrsCmdInNm_Bcan_Honda();
    break;
#endif
#if defined( VGEN_ENABLE_NM_PT )
  case BRSCTRL_CODE_NM_PWRTRAIN_MMC:
    BrsCmdInNm_PwrTrain_Mmc();
    break;
#endif
#if defined( VGEN_ENABLE_NMHIGH )
  case BRSCTRL_CODE_NM_PWRTRAIN_VAG:
    BrsCmdInNm_PwrTrain_Vag();
    break;
#endif
#if defined( VGEN_ENABLE_NM_BASIC )
  case BRSCTRL_CODE_NM_PWRTRAINBASIC:
    BrsCmdInNm_PwrTrainBasic();
    break;
#endif
#if defined( VGEN_ENABLE_NM_OSEK_I )
  case BRSCTRL_CODE_NM_STMGRINDOSEK_PSARENAULT:
    BrsCmdInNm_StMgrIndOsek_PsaRenault();
    break;
#endif
#if defined( VGEN_ENABLE_NM_OSEK_I )
  case BRSCTRL_CODE_NM_STMGRINDOSEK_LS:
    BrsCmdInNm_StMgrIndOsek_Ls();
    break;
#endif
#if defined( VGEN_ENABLE_NM_OSEK_I_HS )
  case BRSCTRL_CODE_NM_STMGRINDOSEK_HS:
    BrsCmdInNm_StMgrIndOsek_Hs();
    break;
#endif
#if defined( VGEN_ENABLE_QNX_WRAPPERMD )
  case BRSCTRL_CODE_QNX_WRAPPERMD:
    BrsCmdInQnx_WrapperMd();
    break;
#endif
#if defined( VGEN_ENABLE_QNX_WRAPPERQNX )
  case BRSCTRL_CODE_QNX_WRAPPERQNX:
    BrsCmdInQnx_WrapperQnx();
    break;
#endif
#if defined( VGEN_ENABLE_SAFETY_LAYERCAN )
  case BRSCTRL_CODE_SAFETY_LAYERCAN:
    BrsCmdInSaftey_LayerCan();
    break;
#endif
#if defined( VGEN_ENABLE_SYSSERVICE_ASRCRC )
  case BRSCTRL_CODE_SYSSERVICE_ASRCRC:
    BrsCmdInSysService_AsrCrc();
    break;
#endif
#if defined( VGEN_ENABLE_SYSSERVICE_ASRDET )
  case BRSCTRL_CODE_SYSSERVICE_ASRDET:
    BrsCmdInSysService_AsrDet();
    break;
#endif
#if defined( VGEN_ENABLE_SYSSERVICE_ASRECUM )
  case BRSCTRL_CODE_SYSSERVICE_ASRECUM:
    BrsCmdInSysService_AsrEcuM();
    break;
#endif
#if defined( VGEN_ENABLE_SYSSERVICE_ASRFIM )
  case BRSCTRL_CODE_SYSSERVICE_ASRFIM:
    BrsCmdInSysService_AsrFim();
    break;
#endif
#if defined( VGEN_ENABLE_SYSSERVICE_CMPR )
  case BRSCTRL_CODE_SYSSERVICE_CMPR:
    BrsCmdInSysService_Cmpr();
    break;
#endif
#if defined( VGEN_ENABLE_SYSSERVICE_CRC_BMW )
  case BRSCTRL_CODE_SYSSERVICE_CRC_BMW:
    BrsCmdInSysService_Crc_Bmw();
    break;
#endif
#if defined( VGEN_ENABLE_SYS_SERV_FIM )
  case BRSCTRL_CODE_SYSSERVICE_FIM_BMW:
    BrsCmdInSysService_Fim_Bmw();
    break;
#endif
#if defined( VGEN_ENABLE_TP_VW16 )
  case BRSCTRL_CODE_TP_16_VAG:
    BrsCmdInTp_16_Vag();
    break;
#endif
#if defined( VGEN_ENABLE_TP_VW20 )
  case BRSCTRL_CODE_TP_20_VAG:
    BrsCmdInTp_20_Vag();
    break;
#endif
#if defined( VGEN_ENABLE_TP_ASRTPCAN )
  case BRSCTRL_CODE_TP_ASRTPCAN:
    BrsCmdInTp_AsrTpCan();
    break;
#endif
#if defined( VGEN_ENABLE_TP_ASRTPFR )
  case BRSCTRL_CODE_TPFR_ASRTPFR:
    BrsCmdInTpFr_AsrTpFr();
    break;
#endif
#if defined( VGEN_ENABLE_TP_ISO_MC )
  case BRSCTRL_CODE_TP_ISO15765:
    BrsCmdInTp_Iso15765();
    break;
#endif
#if defined( VGEN_ENABLE_TP_ISO_SC )
  case BRSCTRL_CODE_TP_ISO15765SINGLECHANNEL:
    BrsCmdInTp_Iso15765SingleChannel();
    break;
#endif
#if defined( VGEN_ENABLE_TP_MCNET )
  case BRSCTRL_CODE_TP_MCNET:
    BrsCmdInTp_McNet();
    break;
#endif
#if defined( VGEN_ENABLE_TPLIN ) 
  case BRSCTRL_CODE_TPLIN:
    BrsCmdInTpLin();
    break;
#endif
#if defined( VGEN_ENABLE_CIO )
  case BRSCTRL_CODE_VDOCCL_COMMON:
    BrsCmdInVdoCcl_Common();
    break;
#endif
#if defined( VGEN_ENABLE_IL_CMHA )
  case BRSCTRL_CODE_VDOIL_CMH:
    BrsCmdInVdoIl_Cmh();
    break;
#endif
#if defined( VGEN_ENABLE_TP_IVLAN )
  case BRSCTRL_CODE_VDOTP_IVLAN:
    BrsCmdInVdoTp_Ivlan();
    break;
#endif

  case BRSCTRL_CODE_ZBRS:
    BrsCmdInzBrs();
    break;
 
  case BRSCTRL_CODE_ZTSI:
    BrsCmdInzTsi();
    break;

  default:
    /* Send negative response now */
    BrsCtrlSendNegResponse(BRSCTRL_ERROR_SNS);      
  }

#if defined( BRSCTRL_USE_CAN_DRV_ASR )
  return; /* AUTOSAR CanIf_RxIndication is void */
#elif defined( BRSCTRL_USE_CAN_DRV_HIS )
  return kCanNoCopyData;  /*Precopy function has finished with msg handling*/
#elif defined( BRSCTRL_USE_LIN_DRV )
  return kLinNoCopyData;  /*Precopy function has finished with msg handling*/
#elif defined( BRSCTRL_USE_MOST_DRV ) || \
      defined( BRSCTRL_USE_DIAG )
  return 1;  /*Precopy function has finished with msg handling*/
#else
  return 0;
#endif
}


/*******************************************************************************/
/**
 * \brief BRS local command interpreter
 *        Handles the TCC protocol part of the BRS component
 *
 * \pre   gbBrsCtrlMsgBuffer contains a 8 byte message
 *
 * \post  The TCC request to CI=BRS has been answered.
 */
static void BrsCmdInzBrs( 
  void 
)
{
  vuint8  errorCode = 0;
  vuint8  *msgptr;
  vuint32 longData;

  /* Service Id */
  switch( gbBrsCtrlMsgBuffer[1] ) {
    /**************************************************************************/
    /** SId 0x22 (READ DATA BY ID) */
    /**************************************************************************/
    case BRSCTRL_FCT_RDBI:
      /* byte 2 and 3 are fix for TCC usage in request          */
      /* access to record via recordDataIdentifier byte 4 and 5 */
      /* Description in FSTCC.doc 5.4                           */

      /* recordDataIdentifier is stored in  */
      gbBrsCtrlMsgBuffer[2] = gbBrsCtrlMsgBuffer[4];
      gbBrsCtrlMsgBuffer[3] = gbBrsCtrlMsgBuffer[5];

      switch (gbBrsCtrlMsgBuffer[4]) {
        #if defined( BRS_ENABLE_TESTADDON )
        /** - 0x22 0x10xx Access data stored in event, warning and error history buffer! */
        case 0x10:
          errorCode = BrsAddOnReadHistoryBufferInBrsCmd();
          break;
        #endif
        /** - 0x22 0xF0xx is a BRS local test command request */
        case 0xF0:
          errorCode = BrsCtrlBrsVersions();
          break;
          /*        case 0xF1:*/
          /* Read flag field */
          /*            break;*/
        #if defined( BRS_ENABLE_TIMETEST ) && \
            defined( BRS_ENABLE_TIMETEST_FREETIMER )
        /** - 0x22 0xF2xx return resolution in nano seconds of FRT */
        case 0xF2:
          errorCode = BrsAddOnTimeFRTNsResolution();
          break;
        #endif
        case 0xF3:
          switch( gbBrsCtrlMsgBuffer[5] ) {
          case 0x00:
            #if defined( C_CPUTYPE_LITTLEENDIAN )
            gbBrsCtrlMsgBuffer[4] = 0;
            #elif defined( C_CPUTYPE_BIGENDIAN )
            gbBrsCtrlMsgBuffer[4] = 1;
            #else
              #error "Neither C_CPUTYPE_LITTLEENDIAN nor C_CPUTYPE_BIGENDIAN is defined"
            #endif
            break;
          case 0x01:
            #if defined( C_CLIENT_DBAG )
            gbBrsCtrlMsgBuffer[4] = kBrsCtrl_OEM_DBAG;
            #elif defined( C_CLIENT_VAG )
            gbBrsCtrlMsgBuffer[4] = kBrsCtrl_OEM_VAG;
            #elif defined( C_CLIENT_BMWAG )
            gbBrsCtrlMsgBuffer[4] = kBrsCtrl_OEM_BMW;
            #elif defined( C_CLIENT_PAG )
            gbBrsCtrlMsgBuffer[4] = kBrsCtrl_OEM_PAG;
            #elif defined( C_CLIENT_GM )
            gbBrsCtrlMsgBuffer[4] = kBrsCtrl_OEM_GM;
            #elif defined( C_CLIENT_FIAT )
            gbBrsCtrlMsgBuffer[4] = kBrsCtrl_OEM_FIAT;
            #elif defined( C_CLIENT_VECTOR )
            gbBrsCtrlMsgBuffer[4] = kBrsCtrl_OEM_VECTOR;
            #elif defined( C_CLIENT_DCNFZ )
            gbBrsCtrlMsgBuffer[4] = kBrsCtrl_OEM_DCNFZ;
            #elif defined( C_CLIENT_FORD )
            gbBrsCtrlMsgBuffer[4] = kBrsCtrl_OEM_FORD;
            #elif defined( C_CLIENT_RENAULT )
            gbBrsCtrlMsgBuffer[4] = kBrsCtrl_OEM_RENAULT;
            #elif defined( C_CLIENT_PSA )
            gbBrsCtrlMsgBuffer[4] = kBrsCtrl_OEM_PSA;
            #elif defined( C_CLIENT_SCANIA )
            gbBrsCtrlMsgBuffer[4] = kBrsCtrl_OEM_SCANIA;
            #elif defined( C_CLIENT_MMC )
            gbBrsCtrlMsgBuffer[4] = kBrsCtrl_OEM_MMC;
            #elif defined( C_CLIENT_CLAAS )
            gbBrsCtrlMsgBuffer[4] = kBrsCtrl_OEM_CLAAS;
            #elif defined( C_CLIENT_HYUNDAI )
            gbBrsCtrlMsgBuffer[4] = kBrsCtrl_OEM_HYUNDAI;
            #elif defined( C_CLIENT_DAF )
            gbBrsCtrlMsgBuffer[4] = kBrsCtrl_OEM_DAF;
            #elif defined( C_CLIENT_SYMC )
            gbBrsCtrlMsgBuffer[4] = kBrsCtrl_OEM_SYMC;
            #elif defined( C_CLIENT_MAN )
            gbBrsCtrlMsgBuffer[4] = kBrsCtrl_OEM_MAN;
            #elif defined( C_CLIENT_FAW )
            gbBrsCtrlMsgBuffer[4] = kBrsCtrl_OEM_FAW;
            #elif defined( C_CLIENT_HONDA )
            gbBrsCtrlMsgBuffer[4] = kBrsCtrl_OEM_HONDA;
            #elif defined( C_CLIENT_NAC )
            gbBrsCtrlMsgBuffer[4] = kBrsCtrl_OEM_NAC;
            #elif defined( C_CLIENT_ISUZU )
            gbBrsCtrlMsgBuffer[4] = kBrsCtrl_OEM_ISUZU;
            #else
            gbBrsCtrlMsgBuffer[4] = kBrsCtrl_OEM_UNKNOWN;
            #endif
            break;

          default:
            /* Send negative response */
            errorCode = BRSCTRL_ERROR_SFNS;
            break;
          }
          break;

        #if defined( BRS_ENABLE_TESTADDON )
         #if defined( BRS_ENABLE_TIMETEST )
        /** - 0x22 0xF6xx is a BRS time measurement request */
        case 0xF6:
          #if defined( BRS_ENABLE_TIMETEST_FREETIMER )
        /** - 0x22 0xF7xx is a BRS time measurement request */
        case 0xF7:
          #endif /* BRS_ENABLE_TIMETEST_FREETIMER */
          errorCode = BrsAddOnTimeCmdInterpreter();
          break;
         #endif /* BRS_ENABLE_TIMETEST */
        #endif /* BRS_ENABLE_TESTADDON */
        #if defined( BRS_ENABLE_TOOL_VERSIONINFO )
        /** - 0x22 0xF8xx accesses the tool versions */
          case 0xF8:
            errorCode = BrsCtrlToolVersions();
            break;
        #endif /* BRS_ENABLE_TOOL_VERSIONINFO */
        default:
          /* Send negative response */
          errorCode = BRSCTRL_ERROR_SNS;            
          break;
      } /*switch(gbBrsCtrlMsgBuffer[4])*/
    break;

    /**************************************************************************/
    /** SId 0x2e (WRITE DATA BY ID) */
    /**************************************************************************/
    case BRSCTRL_FCT_WDBI:
      switch (gbBrsCtrlMsgBuffer[2]) {
      case  BRSCTRL_SET_INTERNAL_STATE:
        switch (gbBrsCtrlMsgBuffer[3]) {
        case  BRSCTRL_SET_FORCE_SLEEP:
          gbBrsCtrlForceSleep = gbBrsCtrlMsgBuffer[4];
          break;       
        default:
          errorCode = BRSCTRL_ERROR_SNS;
          break;
        }
        break;
  #if defined ( BRS_ENABLE_TESTCMDLIST )
      case 0x20:
        errorCode = BrsTestCmdList_SetInBrsCmd();
        break;
  #endif
      default:
        errorCode = BRSCTRL_ERROR_SNS;
        break;
      }
      break;

    /**************************************************************************/
    /** SId 0x31 (START ROUTINE) */
    /**************************************************************************/
    case BRSCTRL_FCT_STR:
      switch (gbBrsCtrlMsgBuffer[2]) {
      case  BRSCTRL_RI_SET_COMP_UNDER_TEST:
        errorCode = BrsCtrlActivateCompUnderTest(gbBrsCtrlMsgBuffer[6]);
        break;
      case  BRSCTRL_SET_CCL_COMM_REQUEST:
      #if defined( VGEN_ENABLE_CCL )
        errorCode = BrsCtrlRequestCommunication((eBrsCtrlBusType)gbBrsCtrlMsgBuffer[4], gbBrsCtrlMsgBuffer[5], gbBrsCtrlMsgBuffer[6]);
      #else
        ApplBrsRequestCommunication(0);
      #endif
      case BRSCTRL_MS_TASK_SUPERVISION:
        BrsAddOnClearMsExceed();
        break;
#if defined ( BRS_ENABLE_TESTCMDLIST )
      case 0x40:
        BrsTestCmdListHdlr_Start();
        break;
#endif
      default:
        errorCode = BRSCTRL_ERROR_CNCORSE;
        break;
      }
      break;


    /**************************************************************************/
    /** SId 0x32 (STOP ROUTINE) */
    /**************************************************************************/
    case BRSCTRL_FCT_STP:
      switch (gbBrsCtrlMsgBuffer[2]) {
      case BRSCTRL_RI_SET_COMP_UNDER_TEST:
        BrsCtrlDeactivateCompUnderTest();
        break;
      case  BRSCTRL_SET_CCL_COMM_REQUEST:
      #if defined( VGEN_ENABLE_CCL )
        errorCode = BrsCtrlReleaseCommunication((eBrsCtrlBusType)gbBrsCtrlMsgBuffer[4], gbBrsCtrlMsgBuffer[5], gbBrsCtrlMsgBuffer[6]);
      #else
        ApplBrsReleaseCommunication(0);
      #endif
      case BRSCTRL_MS_TASK_SUPERVISION:
        {
          vuint16 wTmp;

          wTmp = BrsAddOnGetMsExceed();
          gbBrsCtrlMsgBuffer[4] = 0;
          gbBrsCtrlMsgBuffer[5] = 0;
          gbBrsCtrlMsgBuffer[6] = (vuint8)((wTmp >> 8) & 0xFF);
          gbBrsCtrlMsgBuffer[7] = (vuint8)(wTmp & 0xFF);
        }
        break;
#if defined ( BRS_ENABLE_TESTCMDLIST )
      case 0x40:
        BrsTestCmdListHdlr_Stop();
        break;
#endif

      default:
        errorCode = BRSCTRL_ERROR_CNCORSE;
        break;
      }
      break;


    /**************************************************************************/
    /** SId 0x23 (READ MEMORY BY ADDRESS) */
    /**************************************************************************/
    case BRSCTRL_FCT_RMBA:
      /* byte 2 and 3 are fix for TCC usage in request */
      /* recordDataIdentifier is stored in byte 4 and 5 */
      longData = (((vuint32) gbBrsCtrlMsgBuffer[4]) << 24) |
                 (((vuint32) gbBrsCtrlMsgBuffer[5]) << 16) |
                 (((vuint32) gbBrsCtrlMsgBuffer[6]) <<  8) |
                 (((vuint32) gbBrsCtrlMsgBuffer[7]));

      msgptr = &gbBrsCtrlMsgBuffer[2];
      *msgptr = *((vuint8 MEMORY_HUGE *) longData);   msgptr++; /*lint !e511 */
      *msgptr = *((vuint8 MEMORY_HUGE *) longData+1); msgptr++; /*lint !e511 */
      *msgptr = *((vuint8 MEMORY_HUGE *) longData+2); msgptr++; /*lint !e511 */
      *msgptr = *((vuint8 MEMORY_HUGE *) longData+3);           /*lint !e511 */
      break;

    /**************************************************************************/
    /** SId 0x3d (WRITE MEMORY BY ADDRESS) */
    /**************************************************************************/
    case BRSCTRL_FCT_WMBA:
      longData = (((vuint32) gbBrsCtrlMsgBuffer[2]) << 24) |
                 (((vuint32) gbBrsCtrlMsgBuffer[3]) << 16) |
                 (((vuint32) gbBrsCtrlMsgBuffer[4]) <<  8) |
                 (((vuint32) gbBrsCtrlMsgBuffer[5]));
      *(vuint8 MEMORY_HUGE *) longData = gbBrsCtrlMsgBuffer[6]; /*lint !e511 */
      break;

    default:
      /* Service not supported - send in case that service is unknown *
       * or not supported by this component                           */
      errorCode = BRSCTRL_ERROR_SNS;
      break;
  } /*switch(gbBrsCtrlMsgBuffer[1])*/

  if ((vuint8)0 == errorCode) {
    BrsCtrlSendPosResponse();
  }
  else {
    BrsCtrlSendNegResponse(errorCode);
  }
}


/*****************************************************************************/
/**
 * \brief Access to all BRS versions via TCC
 *
 * \pre      gbBrsCtrlMsgBuffer contains a 8 byte message
 *
 * \retval   errorCode (0 if succesful)
 *
 * Retrieves BRS component versions
 */
static vuint8 BrsCtrlBrsVersions(
  void 
)
{
  vuint8  errorCode = 0;
  vuint8 *msgptr = &gbBrsCtrlMsgBuffer[4];

  switch( gbBrsCtrlMsgBuffer[5] ) {
    case 0x00:
      #if defined( BRSCTRL_USE_MAIN )
      *msgptr = kBrsMainMainVersion;     msgptr++;
      *msgptr = kBrsMainSubVersion;      msgptr++;
      *msgptr = kBrsMainReleaseVersion;  msgptr++;
      #else
      *msgptr = 0xFF;  msgptr++;
      *msgptr = 0xFF;  msgptr++;
      *msgptr = 0xFF;  msgptr++;
      #endif
      *msgptr = 0x01;
      break;
    case 0x01:
      *msgptr = kBrsCtrlMainVersion;     msgptr++;
      *msgptr = kBrsCtrlSubVersion;      msgptr++;
      *msgptr = kBrsCtrlReleaseVersion;  msgptr++;
      #if defined( BRSCTRL_USE_HW )
      *msgptr = 0x02;
      #else
      #  if defined( BRS_ENABLE_TESTADDON )
      *msgptr = 0x03;
      #  else
      *msgptr = 0x00;
      #  endif
      #endif
      break;
    #if defined( BRSCTRL_USE_HW )
    case 0x02:
      *msgptr = kBrsHwMainVersion;      msgptr++;
      *msgptr = kBrsHwSubVersion;       msgptr++;
      *msgptr = kBrsHwBugfixVersion;    msgptr++;
      #  if defined( BRS_ENABLE_TESTADDON )
      *msgptr = 0x03;
      #  elif defined( BRS_ENABLE_OSEKOS )
      *msgptr = 0x04;
      #  elif defined( BRS_ENABLE_STATIONMANAGER )
      *msgptr = 0x05;
      #  else 
      *msgptr = 0x00;
      #  endif
      break;
    #endif
    #if defined( BRS_ENABLE_TESTADDON )
    case 0x03:
      *msgptr = kBrsAddOnMainVersion;    msgptr++;
      *msgptr = kBrsAddOnSubVersion;     msgptr++;
      *msgptr = kBrsAddOnReleaseVersion; msgptr++;
      #if defined( BRS_ENABLE_OSEKOS )
      *msgptr = 0x04;
      #elif defined( BRS_ENABLE_STATIONMANAGER )
      *msgptr = 0x05;
      #else 
      *msgptr = 0x00;
      #endif
      break;
    #endif
    #if defined( BRS_ENABLE_OSEKOS )  
    case 0x04:
      *msgptr = kBrsOsekMainVersion;     msgptr++;
      *msgptr = kBrsOsekSubVersion;      msgptr++;
      *msgptr = kBrsOsekReleaseVersion;  msgptr++;
      #if defined( BRS_ENABLE_STATIONMANAGER )
      *msgptr = 0x05;
      #else 
      *msgptr = 0x00;
      #endif
      break;
    #endif
    #if defined( BRS_ENABLE_STATIONMANAGER )  
    case 0x05:
      *msgptr = kBrsStaMaMainVersion;    msgptr++;
      *msgptr = kBrsStaMaSubVersion;     msgptr++;
      *msgptr = kBrsStaMaReleaseVersion; msgptr++;
      *msgptr = 0x00;
      break;
    #endif
    case 0x20:
      #if defined( VGEN_CANGEN_VERSION )
      *msgptr = 0x01; msgptr++; /** CANgen*/
      *msgptr = 0x00; msgptr++;
      *msgptr = 0x00; msgptr++;
      *msgptr = 0x01;
      #elif defined( VGEN_DBKGEN_VERSION ) 
      *msgptr = 0x02; msgptr++; /** DBKOMgen*/
      *msgptr = 0x00; msgptr++;
      *msgptr = 0x00; msgptr++;
      *msgptr = 0x01;
      #elif defined( VGEN_GENY ) 
      *msgptr = 0x03; msgptr++; /** GENy*/
      *msgptr = 0x00; msgptr++;
      *msgptr = 0x00; msgptr++;
      *msgptr = 0x01;
      #else
      /* No tool version available for this generation tool version in V_CFG.H! */  
      *msgptr = 0x00; msgptr++; /** Unknown tool*/
      *msgptr = 0x00; msgptr++;
      *msgptr = 0x00; msgptr++;
      *msgptr = 0x00;
      #endif
      break;
    #if defined( VGEN_CANGEN_VERSION ) || defined( VGEN_DBKGEN_VERSION ) || defined( VGEN_GENY )
    case 0x21:
      #if defined( VGEN_CANGEN_VERSION )
      *msgptr = (vuint8)(VGEN_CANGEN_VERSION>>8);      msgptr++;
      *msgptr = (vuint8)(VGEN_CANGEN_VERSION);         msgptr++;
#if (VGEN_CANGEN_VERSION >= 0x0416) 
      *msgptr = (vuint8)(VGEN_CANGEN_RELEASE_VERSION); msgptr++;
#else
      *msgptr = (vuint8)(VGEN_CANGEN_BUGFIX_VERSION);  msgptr++;
#endif
      *msgptr = 0x00;
      #elif defined( VGEN_DBKGEN_VERSION ) 
      *msgptr = (vuint8)(VGEN_DBKGEN_VERSION>>8);      msgptr++;
      *msgptr = (vuint8)(VGEN_DBKGEN_VERSION);         msgptr++;
      *msgptr = (vuint8)(VGEN_DBKGEN_BUGFIX_VERSION);  msgptr++;
      *msgptr = 0x00;
      #elif defined( VGEN_GENY ) 
      *msgptr = (vuint8)(kGENyVersion[0]);             msgptr++;
      *msgptr = (vuint8)(kGENyVersion[1]);             msgptr++;
      *msgptr = (vuint8)(kGENyVersion[2]);             msgptr++;
      *msgptr = 0x02;
      #else
      /* No tool version available for this generation tool version in V_CFG.H */  
      #endif
      break;
    #endif
    #if defined( VGEN_GENY ) && (kGENyVersionNumberOfBytes > 3)
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
        {
            vuint8 i;
            vuint8 start = ( gbBrsCtrlMsgBuffer[5] - 0x21 ) * 3;
            vuint8 end   = start < (kGENyVersionNumberOfBytes - 3)? start + 3 : kGENyVersionNumberOfBytes;
            *(msgptr + 3) = (kGENyVersionNumberOfBytes == end)? 0 : ( 0x01 + ( gbBrsCtrlMsgBuffer[5] - 0x20 ));
            for (i=start; i<end; i++) {
                *msgptr = (vuint8)(kGENyVersion[i]); msgptr++;
            }
        }
        break;
    #endif
    case 0x2F:
      #if defined( VGEN_CANGEN_VERSION ) || \
          defined( VGEN_DBKGEN_VERSION ) 
        gbBrsCtrlMsgBuffer[4] = 3;
      #elif defined( VGEN_GENY ) 
        gbBrsCtrlMsgBuffer[4] = kGENyVersionNumberOfBytes;
      #else
        gbBrsCtrlMsgBuffer[4] = 0;
      #endif
        break;
    default:
      /* Send negative response now */
      errorCode = BRSCTRL_ERROR_SNS;
      break;
  }
  return errorCode;
}


#if defined( BRS_ENABLE_TOOL_VERSIONINFO )
/*****************************************************************************/
/**
 * \brief Access to Tool versions (e.g. compiler, assembler, linker, ...)
 *        Retrieves  Compiler/(Macro-)Assembler/Linker versions
 *
 * \pre      gbBrsCtrlMsgBuffer contains a 8 byte message
 *
 * \retval   errorCode (0 if succesful)
 */
static vuint8 BrsCtrlToolVersions (
  void 
)
{
  vuint8 errorCode = 0;
  vuint32 val;
  vuint8 *msgptr = &gbBrsCtrlMsgBuffer[4];
  vsint8 *strptr = 0;
  vsint8 *tool = 0;

  switch (gbBrsCtrlMsgBuffer[5] >> 1) {
  #if defined( BRS_ENABLE_COMPILER_VERSION )  
  case 0x00:
    tool = (vsint8 *) kBrsCompilerVersion;
    break;
  #if defined( BRS_ENABLE_FLAG_ACCESS )
  case 0x20:
    tool = (vsint8 *) kBrsCompilerOptimization;
    break;
  case 0x21:
    tool = (vsint8 *) kBrsCompilerWarning;
    break;
  case 0x22:
    tool = (vsint8 *) kBrsCompilerMemoryModel;
    break;
  case 0x23:
    tool = (vsint8 *) kBrsCompilerAdditional;
    break;
  #endif /* BRS_ENABLE_FLAG_ACCESS */
  #endif /* BRS_ENABLE_COMPILER_VERSION */
  #if defined( BRS_ENABLE_MACROASSEMBLER_VERSION )  
  case 0x01:
    tool = (vsint8 *) kBrsMacroAssemblerVersion;
    break;
  #if defined( BRS_ENABLE_FLAG_ACCESS )
  case 0x30:
    tool = (vsint8 *) kBrsMacroAssemblerVersion;
    break;
  case 0x31:
    tool = (vsint8 *) kBrsMacroAssemblerOptimization;
    break;
  case 0x32:
    tool = (vsint8 *) kBrsMacroAssemblerWarning;
    break;
  case 0x33:
    tool = (vsint8 *) kBrsMacroAssemblerAdditional;
    break;
  #endif /* BRS_ENABLE_FLAG_ACCESS */
  #endif /* BRS_ENABLE_MACROASSEMBLER_VERSION */
  #if defined( BRS_ENABLE_ASSEMBLER_VERSION )  
  case 0x02:
    tool = (vsint8 *) kBrsAssemblerVersion;
    break;
  #if defined( BRS_ENABLE_FLAG_ACCESS )
  case 0x40:
    tool = (vsint8 *) kBrsAssemblerVersion;
    break;
  case 0x41:
    tool = (vsint8 *) kBrsAssemblerOptimization;
    break;
  case 0x42:
    tool = (vsint8 *) kBrsAssemblerWarning;
    break;
  case 0x43:
    tool = (vsint8 *) kBrsAssemblerMemoryModel;
    break;
  #endif /* BRS_ENABLE_FLAG_ACCESS */
  #endif /* BRS_ENABLE_ASSEMBLER_VERSION */
  #if defined( BRS_ENABLE_LINKER_VERSION )  
  case 0x03:
    tool = (vsint8 *) kBrsLinkerVersion;
    break;
  #if defined( BRS_ENABLE_FLAG_ACCESS )
  case 0x50:
    tool = (vsint8 *) kBrsLinkerOptimization;
    break;
  case 0x51:
    tool = (vsint8 *) kBrsLinkerWarning;
    break;
  case 0x52:
    tool = (vsint8 *) kBrsLinkerMemoryModel;
    break;
  case 0x53:
    tool = (vsint8 *) kBrsLinkerAdditional;
    break;
  #endif /* BRS_ENABLE_FLAG_ACCESS */
  #endif /* BRS_ENABLE_LINKER_VERSION */
  #if defined( BRS_ENABLE_EXT_T1_VERSION )  
  case 0x04:
    tool = (vsint8 *) kBrsExtTool1Version;
    break;
  #if defined( BRS_ENABLE_FLAG_ACCESS )
  case 0x60:
    tool = (vsint8 *) kBrsExtTool1Parameter;
    break;
  #endif /* BRS_ENABLE_FLAG_ACCESS */
  #endif /* BRS_ENABLE_EXT_T1_VERSION */
  #if defined( BRS_ENABLE_EXT_T2_VERSION )  
  case 0x05:
    tool = (vsint8 *) kBrsExtTool2Version;
    break;
  #if defined( BRS_ENABLE_FLAG_ACCESS )
  case 0x70:
    tool = (vsint8 *) kBrsExtTool2Parameter;
    break;
  #endif /* BRS_ENABLE_FLAG_ACCESS */
  #endif /* BRS_ENABLE_EXT_T2_VERSION */
  #if defined( BRS_ENABLE_LIBRARIAN_VERSION )  
  case 0x06:
    tool = (vsint8 *) kBrsLibrarianVersion;
    break;
  #if defined( BRS_ENABLE_FLAG_ACCESS )
  case 0x80:
    tool = (vsint8 *) kBrsLibrarianParameter;
    break;
  #endif /* BRS_ENABLE_FLAG_ACCESS */
  #endif /* BRS_ENABLE_LIBRARIAN_VERSION */
  case 0x10:
    tool = (vsint8 *) kBrsCompilerDef;
    break;
  case 0x11:
    tool = (vsint8 *) kBrsControllerDef;
    break;
  default:
    /* negative response */
    errorCode = BRSCTRL_ERROR_SNS;
  }

  if (errorCode == 0) {
    if ((gbBrsCtrlMsgBuffer[5] % 2) == 0) {
      val = (vuint32) tool;
    } else {
      strptr = tool;
      /*lint --e(613)*/ while ((*strptr) != 0)  {/*lint !e613 */
        strptr++;              /*lint !e613 */ 
      };
      val = (vuint32)(strptr - tool);/*lint !e613 !e794 !e571 */
    }
    *msgptr = (vuint8) (val >> 24); msgptr++;
    *msgptr = (vuint8) (val >> 16); msgptr++;
    *msgptr = (vuint8) (val >>  8); msgptr++;
    *msgptr = (vuint8) (val);
  }

  return errorCode;
}
#endif /* BRS_ENABLE_TOOL_VERSIONINFO */


/*****************************************************************************/
/**
 * \brief Activates component under test.
 *        CIs are defined in the FS_BrsTestControlCenter.doc
 *        To activate a test for a specific component use the service STR 
 *        with the routine identifier BRSCTRL_RI_SET_COMP_UNDER_TEST and the
 *        CI as parameter in byte 6.
 *        To deactivate tests use the STP service with the same routine identifier.
 *        To check if a test if active for a component call 
 *        BrsTccIsCompUnderTest(BRSCTRL_CODE_<component name>) in your DUT code
 *
 * \retval   errorCode (0 if succesful)
 */
static vuint8 BrsCtrlActivateCompUnderTest(
  vuint8 ci
)
{
  vuint8 errorCode = 0;
  if (0xFF == gbBrsCtrlCompUnderTestCI)
  {
    gbBrsCtrlCompUnderTestCI = ci;
  }
  else 
  {
    errorCode = BRSCTRL_ERROR_CNCORSE;    
  }

  return errorCode;
}


/*****************************************************************************/
/**
 * \brief Deactivates component under test.
 *        To deactivate tests use the STP service with the routine identifier.
 *        BRSCTRL_RI_SET_COMP_UNDER_TEST.
 *
 * \retval   errorCode (0 if succesful)
 */
static void BrsCtrlDeactivateCompUnderTest(
  void
)
{
  gbBrsCtrlCompUnderTestCI = 0xFF;
}


#if defined ( VGEN_ENABLE_CCL)
#  if defined( VGEN_ENABLE_CAN_DRV )
#    if defined( VGEN_ENABLE_DPM )
#      define BrsCtrlRequest(bus,node,nr) DpmExternalRequest(DPM_Brs_Node##node##_##bus##nr)
#      define BrsCtrlRelease(bus,node,nr) DpmSleepRequest(DPM_Brs_Node##node##_##bus##nr)
#      if !defined( DPM_Brs_Node0_Can0 )
#        error "DPM user <Brs_Node0_Can0> is not set! Please adjust it in the GenTool!"
#      elif ( kCanNumberOfChannels > 1 ) && !defined( DPM_Brs_Node0_Can1 )
#        error "DPM user <Brs_Node0_Can1> is not set! Please adjust it in the GenTool!"
#      elif ( kCanNumberOfChannels > 2 ) && !defined( DPM_Brs_Node0_Can2 )
#        error "DPM user <Brs_Node0_Can2> is not set! Please adjust it in the GenTool!"
#      elif ( kCanNumberOfChannels > 3 ) && !defined( DPM_Brs_Node0_Can3 )
#        error "DPM user <Brs_Node0_Can3> is not set! Please adjust it in the GenTool!"
#      elif ( kCanNumberOfChannels > 4 ) && !defined( DPM_Brs_Node0_Can4 )
#        error "DPM user <Brs_Node0_Can4> is not set! Please adjust it in the GenTool!"
#      elif ( kCanNumberOfChannels > 5 ) && !defined( DPM_Brs_Node0_Can5 )
#        error "DPM user <Brs_Node0_Can5> is not set! Please adjust it in the GenTool!"
#      elif defined( kCanNumberOfNodes )
#        if ( kCanNumberOfNodes > 1 )
#          if !defined( DPM_Brs_Node1_Can0 )
#            error "DPM user <Brs_Node1_Can0> is not set! Please adjust it in the GenTool!"
#          elif ( kCanNumberOfChannels > 1 ) && !defined( DPM_Brs_Node1_Can1 )
#            error "DPM user <Brs_Node1_Can1> is not set! Please adjust it in the GenTool!"
#          elif ( kCanNumberOfChannels > 2 ) && !defined( DPM_Brs_Node1_Can2 )
#            error "DPM user <Brs_Node1_Can2> is not set! Please adjust it in the GenTool!"
#          elif ( kCanNumberOfChannels > 3 ) && !defined( DPM_Brs_Node1_Can3 )
#            error "DPM user <Brs_Node1_Can3> is not set! Please adjust it in the GenTool!"
#          elif ( kCanNumberOfChannels > 4 ) && !defined( DPM_Brs_Node1_Can4 )
#            error "DPM user <Brs_Node1_Can4> is not set! Please adjust it in the GenTool!"
#          elif ( kCanNumberOfChannels > 5 ) && !defined( DPM_Brs_Node1_Can5 )
#            error "DPM user <Brs_Node1_Can5> is not set! Please adjust it in the GenTool!"
#          endif
#        elif ( kCanNumberOfNodes > 2 )
#          if !defined( DPM_Brs_Node2_Can0 )
#            error "DPM user <Brs_Node2_Can0> is not set! Please adjust it in the GenTool!"
#          elif ( kCanNumberOfChannels > 1 ) && !defined( DPM_Brs_Node2_Can1 )
#            error "DPM user <Brs_Node2_Can1> is not set! Please adjust it in the GenTool!"
#          elif ( kCanNumberOfChannels > 2 ) && !defined( DPM_Brs_Node2_Can2 )
#            error "DPM user <Brs_Node2_Can2> is not set! Please adjust it in the GenTool!"
#          elif ( kCanNumberOfChannels > 3 ) && !defined( DPM_Brs_Node2_Can3 )
#            error "DPM user <Brs_Node2_Can3> is not set! Please adjust it in the GenTool!"
#          elif ( kCanNumberOfChannels > 4 ) && !defined( DPM_Brs_Node2_Can4 )
#            error "DPM user <Brs_Node2_Can4> is not set! Please adjust it in the GenTool!"
#          elif ( kCanNumberOfChannels > 5 ) && !defined( DPM_Brs_Node2_Can5 )
#            error "DPM user <Brs_Node2_Can5> is not set! Please adjust it in the GenTool!"
#          endif
#        endif /* defined( kCanNumberOfNodes ) */
#      endif /* defined( kCanNumberOfNodes ) */
#    else /* defined( VGEN_ENABLE_DPM ) */
#      define BrsCtrlRequest(bus,node,nr) CclSet_Brs_Node##node##_##bus##nr()
#      define BrsCtrlRelease(bus,node,nr) CclRel_Brs_Node##node##_##bus##nr()
#      if !defined( CclSet_Brs_Node0_Can0 )
#        error "CCL Communication Request <Brs_Node0_Can0> is not set! Please adjust it in the GenTool!"
#      elif ( kCanNumberOfChannels > 1 ) && !defined( CclSet_Brs_Node0_Can1 )
#        error "CCL Communication Request <Brs_Node0_Can1> is not set! Please adjust it in the GenTool!"
#      elif ( kCanNumberOfChannels > 2 ) && !defined( CclSet_Brs_Node0_Can2 )
#        error "CCL Communication Request <Brs_Node0_Can2> is not set! Please adjust it in the GenTool!"
#      elif ( kCanNumberOfChannels > 3 ) && !defined( CclSet_Brs_Node0_Can3 )
#        error "CCL Communication Request <Brs_Node0_Can3> is not set! Please adjust it in the GenTool!"
#      elif ( kCanNumberOfChannels > 4 ) && !defined( CclSet_Brs_Node0_Can4 )
#        error "CCL Communication Request <Brs_Node0_Can4> is not set! Please adjust it in the GenTool!"
#      elif ( kCanNumberOfChannels > 5 ) && !defined( CclSet_Brs_Node0_Can5 )
#        error "CCL Communication Request <Brs_Node0_Can5> is not set! Please adjust it in the GenTool!"
#      elif defined( kCanNumberOfNodes )
#        if ( kCanNumberOfNodes > 1 )
#          if !defined( CclSet_Brs_Node1_Can0 )
#            error "CCL Communication Request <Brs_Node1_Can0> is not set! Please adjust it in the GenTool!"
#          elif ( kCanNumberOfChannels > 1 ) && !defined( CclSet_Brs_Node1_Can1 )
#            error "CCL Communication Request <Brs_Node1_Can1> is not set! Please adjust it in the GenTool!"
#          elif ( kCanNumberOfChannels > 2 ) && !defined( CclSet_Brs_Node1_Can2 )
#            error "CCL Communication Request <Brs_Node1_Can2> is not set! Please adjust it in the GenTool!"
#          elif ( kCanNumberOfChannels > 3 ) && !defined( CclSet_Brs_Node1_Can3 )
#            error "CCL Communication Request <Brs_Node1_Can3> is not set! Please adjust it in the GenTool!"
#          elif ( kCanNumberOfChannels > 4 ) && !defined( CclSet_Brs_Node1_Can4 )
#            error "CCL Communication Request <Brs_Node1_Can4> is not set! Please adjust it in the GenTool!"
#          elif ( kCanNumberOfChannels > 5 ) && !defined( CclSet_Brs_Node1_Can5 )
#            error "CCL Communication Request <Brs_Node1_Can5> is not set! Please adjust it in the GenTool!"
#          endif
#        elif ( kCanNumberOfNodes > 1 )
#          if !defined( CclSet_Brs_Node2_Can0 )
#            error "CCL Communication Request <Brs_Node2_Can0> is not set! Please adjust it in the GenTool!"
#          elif ( kCanNumberOfChannels > 1 ) && !defined( CclSet_Brs_Node2_Can1 )
#            error "CCL Communication Request <Brs_Node2_Can1> is not set! Please adjust it in the GenTool!"
#          elif ( kCanNumberOfChannels > 2 ) && !defined( CclSet_Brs_Node2_Can2 )
#            error "CCL Communication Request <Brs_Node2_Can2> is not set! Please adjust it in the GenTool!"
#          elif ( kCanNumberOfChannels > 3 ) && !defined( CclSet_Brs_Node2_Can3 )
#            error "CCL Communication Request <Brs_Node2_Can3> is not set! Please adjust it in the GenTool!"
#          elif ( kCanNumberOfChannels > 4 ) && !defined( CclSet_Brs_Node2_Can4 )
#            error "CCL Communication Request <Brs_Node2_Can4> is not set! Please adjust it in the GenTool!"
#          elif ( kCanNumberOfChannels > 5 ) && !defined( CclSet_Brs_Node2_Can5 )
#            error "CCL Communication Request <Brs_Node2_Can5> is not set! Please adjust it in the GenTool!"
#          endif
#        endif /* defined( kCanNumberOfNodes ) */
#      endif /* defined( kCanNumberOfNodes ) */
#    endif /* !defined( VGEN_ENABLE_DPM ) */
#  endif /* !defined( VGEN_ENABLE_CAN_DRV ) */

/*****************************************************************************/
/**
 * \brief Request general BRS bus communication if CCL is used
 *        Use this request for testsuites if CCL is used to keep the bus awake
 *        Request name is: Brs_Node<nodenr>_<BusType><BusChannel>
 *
 * \retval   errorCode (0 if succesful)
 */
static vuint8 BrsCtrlRequestCommunication(
  eBrsCtrlBusType type, 
  vuint8 chnl, 
  vuint8 node
)
{
  vuint8 errorCode = 0;

#if defined( VGEN_ENABLE_CAN_DRV )
  if (type & eBrsCtrlBusTypeCAN) {
#  if defined( kCanNumberOfNodes )
    switch (node) {
    case 0:
#  endif /* defined( kCanNumberOfNodes ) */

      switch (chnl) {
      case 0:
        BrsCtrlRequest(Can, 0, 0);
        break;
#    if ( kCanNumberOfChannels > 1 )
      case 1:
        BrsCtrlRequest(Can, 0, 1);
        break;
#    endif /* ( kCanNumberOfChannels > 1 ) */
#    if ( kCanNumberOfChannels > 2 )
      case 2:
        BrsCtrlRequest(Can, 0, 2);
        break;
#    endif /* ( kCanNumberOfChannels > 2 ) */
#    if ( kCanNumberOfChannels > 3 )
      case 3:
        BrsCtrlRequest(Can, 0, 3);
        break;
#    endif /* ( kCanNumberOfChannels > 3 ) */
#    if ( kCanNumberOfChannels > 4 )
      case 4:
        BrsCtrlRequest(Can, 0, 4);
        break;
#    endif /* ( kCanNumberOfChannels > 4 ) */
#    if ( kCanNumberOfChannels > 5 )
      case 5:
        BrsCtrlRequest(Can, 0, 5);
        break;
#    endif /* ( kCanNumberOfChannels > 5 ) */
      case 0xFF:
        BrsCtrlRequest(Can, 0, 0);
#    if ( kCanNumberOfChannels > 1 )
        BrsCtrlRequest(Can, 0, 1);
#    endif
#    if ( kCanNumberOfChannels > 2 )
        BrsCtrlRequest(Can, 0, 2);
#    endif
#    if ( kCanNumberOfChannels > 3 )
        BrsCtrlRequest(Can, 0, 3);
#    endif
#    if ( kCanNumberOfChannels > 4 )
        BrsCtrlRequest(Can, 0, 4);
#    endif
#    if ( kCanNumberOfChannels > 5 )
        BrsCtrlRequest(Can, 0, 5);
#    endif
        break;
      default:
        errorCode = BRSCTRL_ERROR_CNCORSE;
        break;
      }

#  if defined( kCanNumberOfNodes )
      break;
#    if ( kCanNumberOfNodes > 1 )
    case 1:
      switch (chnl) {
      case 0:
        BrsCtrlRequest(Can, 1, 0);
        break;
#      if ( kCanNumberOfChannels > 1 )
      case 1:
        BrsCtrlRequest(Can, 1, 1);
        break;
#      endif /* ( kCanNumberOfChannels > 1 ) */
#      if ( kCanNumberOfChannels > 2 )
      case 2:
        BrsCtrlRequest(Can, 1, 2);
        break;
#      endif /* ( kCanNumberOfChannels > 2 ) */
#      if ( kCanNumberOfChannels > 3 )
      case 3:
        BrsCtrlRequest(Can, 1, 3);
        break;
#      endif /* ( kCanNumberOfChannels > 3 ) */
#      if ( kCanNumberOfChannels > 4 )
      case 4:
        BrsCtrlRequest(Can, 1, 4);
        break;
#      endif /* ( kCanNumberOfChannels > 4 ) */
#      if ( kCanNumberOfChannels > 5 )
      case 5:
        BrsCtrlRequest(Can, 1, 5);
        break;
#      endif /* ( kCanNumberOfChannels > 5 ) */
      case 0xFF:
        BrsCtrlRequest(Can, 1, 0);
#    if ( kCanNumberOfChannels > 1 )
        BrsCtrlRequest(Can, 1, 1);
#    endif
#    if ( kCanNumberOfChannels > 2 )
        BrsCtrlRequest(Can, 1, 2);
#    endif
#    if ( kCanNumberOfChannels > 3 )
        BrsCtrlRequest(Can, 1, 3);
#    endif
#    if ( kCanNumberOfChannels > 4 )
        BrsCtrlRequest(Can, 1, 4);
#    endif
#    if ( kCanNumberOfChannels > 5 )
        BrsCtrlRequest(Can, 1, 5);
#    endif
        break;
      default:
        errorCode = BRSCTRL_ERROR_CNCORSE;
        break;
      }
      break;
#    endif /* ( kCanNumberOfNodes > 1 ) */
#  endif /* defined( kCanNumberOfNodes ) */

#  if defined( kCanNumberOfNodes )
#    if ( kCanNumberOfNodes > 2 )
    case 2:
      switch (chnl) {
      case 0:
        BrsCtrlRequest(Can, 2, 0);
        break;
#      if ( kCanNumberOfChannels > 1 )
      case 1:
        BrsCtrlRequest(Can, 2, 1);
        break;
#      endif /* ( kCanNumberOfChannels > 1 ) */
#      if ( kCanNumberOfChannels > 2 )
      case 2:
        BrsCtrlRequest(Can, 2, 2);
        break;
#      endif /* ( kCanNumberOfChannels > 2 ) */
#      if ( kCanNumberOfChannels > 3 )
      case 3:
        BrsCtrlRequest(Can, 2, 3);
        break;
#      endif /* ( kCanNumberOfChannels > 3 ) */
#      if ( kCanNumberOfChannels > 4 )
      case 4:
        BrsCtrlRequest(Can, 2, 4);
        break;
#      endif /* ( kCanNumberOfChannels > 4 ) */
#      if ( kCanNumberOfChannels > 5 )
      case 5:
        BrsCtrlRequest(Can, 2, 5);
        break;
#      endif /* ( kCanNumberOfChannels > 5 ) */
      case 0xFF:
        BrsCtrlRequest(Can, 2, 0);
#    if ( kCanNumberOfChannels > 1 )
        BrsCtrlRequest(Can, 2, 1);
#    endif
#    if ( kCanNumberOfChannels > 2 )
        BrsCtrlRequest(Can, 2, 2);
#    endif
#    if ( kCanNumberOfChannels > 3 )
        BrsCtrlRequest(Can, 2, 3);
#    endif
#    if ( kCanNumberOfChannels > 4 )
        BrsCtrlRequest(Can, 2, 4);
#    endif
#    if ( kCanNumberOfChannels > 5 )
        BrsCtrlRequest(Can, 2, 5);
#    endif
        break;
      default:
        errorCode = BRSCTRL_ERROR_CNCORSE;
        break;
      }
      break;
#    endif /* ( kCanNumberOfNodes > 2 ) */
    default:
      errorCode = BRSCTRL_ERROR_CNCORSE;
      break;
    }
#  endif /* defined( kCanNumberOfNodes ) */
  }
#endif /* defined( VGEN_ENABLE_CAN_DRV ) */

  return errorCode;
}

/*****************************************************************************/
/**
 * \brief Release general BRS bus communication if CCL is used
 *
 * \retval   errorCode (0 if succesful)
 */
static vuint8 BrsCtrlReleaseCommunication(
  eBrsCtrlBusType type, 
  vuint8 chnl, 
  vuint8 node
)
{
  vuint8 errorCode = 0;

#if defined( VGEN_ENABLE_CAN_DRV )

#  if defined( VGEN_ENABLE_NM_JUNIOR )  || \
      defined( VGEN_ENABLE_NM_BASIC )
  if (0 == gbBrsCtrlForceSleep) {
    /* If the release request has been stated to a non-wakeable CAN channel, leave the channel awake... */
    if (BrsCtrlChannelIsExternallyWakeable(chnl) == BRSCTRL_CHANNEL_IS_NON_WAKEABLE) {
      return errorCode;
    }
  }
#  endif /* VGEN_ENABLE_NM_JUNIOR || VGEN_ENABLE_NM_BASIC */

  if (type & eBrsCtrlBusTypeCAN) {
#  if defined( kCanNumberOfNodes )
    switch (node) {
    case 0:
#  endif /* defined( kCanNumberOfNodes ) */

      switch (chnl) {
      case 0:
        BrsCtrlRelease(Can, 0, 0);
        break;
#    if ( kCanNumberOfChannels > 1 )
      case 1:
        BrsCtrlRelease(Can, 0, 1);
        break;
#    endif /* ( kCanNumberOfChannels > 1 ) */
#    if ( kCanNumberOfChannels > 2 )
      case 2:
        BrsCtrlRelease(Can, 0, 2);
        break;
#    endif /* ( kCanNumberOfChannels > 2 ) */
#    if ( kCanNumberOfChannels > 3 )
      case 3:
        BrsCtrlRelease(Can, 0, 3);
        break;
#    endif /* ( kCanNumberOfChannels > 3 ) */
#    if ( kCanNumberOfChannels > 4 )
      case 4:
        BrsCtrlRelease(Can, 0, 4);
        break;
#    endif /* ( kCanNumberOfChannels > 4 ) */
#    if ( kCanNumberOfChannels > 5 )
      case 5:
        BrsCtrlRelease(Can, 0, 5);
        break;
#    endif /* ( kCanNumberOfChannels > 5 ) */
      case 0xFF:
        BrsCtrlRelease(Can, 0, 0);
#    if ( kCanNumberOfChannels > 1 )
        BrsCtrlRelease(Can, 0, 1);
#    endif
#    if ( kCanNumberOfChannels > 2 )
        BrsCtrlRelease(Can, 0, 2);
#    endif
#    if ( kCanNumberOfChannels > 3 )
        BrsCtrlRelease(Can, 0, 3);
#    endif
#    if ( kCanNumberOfChannels > 4 )
        BrsCtrlRelease(Can, 0, 4);
#    endif
#    if ( kCanNumberOfChannels > 5 )
        BrsCtrlRelease(Can, 0, 5);
#    endif
        break;
      default:
        errorCode = BRSCTRL_ERROR_CNCORSE;
        break;
      }

#  if defined( kCanNumberOfNodes )
      break;
#    if ( kCanNumberOfNodes > 1 )
    case 1:
      switch (chnl) {
      case 0:
        BrsCtrlRelease(Can, 1, 0);
        break;
#      if ( kCanNumberOfChannels > 1 )
      case 1:
        BrsCtrlRelease(Can, 1, 1);
        break;
#      endif /* ( kCanNumberOfChannels > 1 ) */
#      if ( kCanNumberOfChannels > 2 )
      case 2:
        BrsCtrlRelease(Can, 1, 2);
        break;
#      endif /* ( kCanNumberOfChannels > 2 ) */
#      if ( kCanNumberOfChannels > 3 )
      case 3:
        BrsCtrlRelease(Can, 1, 3);
        break;
#      endif /* ( kCanNumberOfChannels > 3 ) */
#      if ( kCanNumberOfChannels > 4 )
      case 4:
        BrsCtrlRelease(Can, 1, 4);
        break;
#      endif /* ( kCanNumberOfChannels > 4 ) */
#      if ( kCanNumberOfChannels > 5 )
      case 5:
        BrsCtrlRelease(Can, 1, 5);
        break;
#      endif /* ( kCanNumberOfChannels > 5 ) */
      case 0xFF:
        BrsCtrlRelease(Can, 1, 0);
#    if ( kCanNumberOfChannels > 1 )
        BrsCtrlRelease(Can, 1, 1);
#    endif
#    if ( kCanNumberOfChannels > 2 )
        BrsCtrlRelease(Can, 1, 2);
#    endif
#    if ( kCanNumberOfChannels > 3 )
        BrsCtrlRelease(Can, 1, 3);
#    endif
#    if ( kCanNumberOfChannels > 4 )
        BrsCtrlRelease(Can, 1, 4);
#    endif
#    if ( kCanNumberOfChannels > 5 )
        BrsCtrlRelease(Can, 1, 5);
#    endif
        break;
      default:
        errorCode = BRSCTRL_ERROR_CNCORSE;
        break;
      }
      break;
#    endif /* ( kCanNumberOfNodes > 1 ) */
#  endif /* defined( kCanNumberOfNodes ) */

#  if defined( kCanNumberOfNodes )
#    if ( kCanNumberOfNodes > 2 )
    case 2:
      switch (chnl) {
      case 0:
        BrsCtrlRelease(Can, 2, 0);
        break;
#      if ( kCanNumberOfChannels > 1 )
      case 1:
        BrsCtrlRelease(Can, 2, 1);
        break;
#      endif /* ( kCanNumberOfChannels > 1 ) */
#      if ( kCanNumberOfChannels > 2 )
      case 2:
        BrsCtrlRelease(Can, 2, 2);
        break;
#      endif /* ( kCanNumberOfChannels > 2 ) */
#      if ( kCanNumberOfChannels > 3 )
      case 3:
        BrsCtrlRelease(Can, 2, 3);
        break;
#      endif /* ( kCanNumberOfChannels > 3 ) */
#      if ( kCanNumberOfChannels > 4 )
      case 4:
        BrsCtrlRelease(Can, 2, 4);
        break;
#      endif /* ( kCanNumberOfChannels > 4 ) */
#      if ( kCanNumberOfChannels > 5 )
      case 5:
        BrsCtrlRelease(Can, 2, 5);
        break;
#      endif /* ( kCanNumberOfChannels > 5 ) */
      case 0xFF:
        BrsCtrlRelease(Can, 2, 0);
#    if ( kCanNumberOfChannels > 1 )
        BrsCtrlRelease(Can, 2, 1);
#    endif
#    if ( kCanNumberOfChannels > 2 )
        BrsCtrlRelease(Can, 2, 2);
#    endif
#    if ( kCanNumberOfChannels > 3 )
        BrsCtrlRelease(Can, 2, 3);
#    endif
#    if ( kCanNumberOfChannels > 4 )
        BrsCtrlRelease(Can, 2, 4);
#    endif
#    if ( kCanNumberOfChannels > 5 )
        BrsCtrlRelease(Can, 2, 5);
#    endif
        break;
      default:
        errorCode = BRSCTRL_ERROR_CNCORSE;
        break;
      }
      break;
#    endif /* ( kCanNumberOfNodes > 2 ) */
    default:
      errorCode = BRSCTRL_ERROR_CNCORSE;
      break;
    }
#  endif /* defined( kCanNumberOfNodes ) */
  }
#endif /* defined( VGEN_ENABLE_CAN_DRV ) */

  return errorCode;
}
#endif /* defined ( VGEN_ENABLE_CCL) */

#if defined( VGEN_ENABLE_NM_JUNIOR )  || \
    defined( VGEN_ENABLE_NM_BASIC )
/*******************************************************************************/
/**
 * \brief Decides whether the requested CAN channel is externally wakeable,
 *        i.e. whether there is a non-wakeable NM running on this channel or not.
 *
 * \param[in] chnl holds the requested CAN channel index
 * 
 * \retval BRSCTRL_CHANNEL_IS_WAKEABLE/BRSCTRL_CHANNEL_IS_NON_WAKEABLE
 */
static vuint8 BrsCtrlChannelIsExternallyWakeable(vuint8 chnl) {
  vuint8 result;

  result = BRSCTRL_CHANNEL_IS_WAKEABLE;

#if defined( VGEN_ENABLE_NM_BASIC )
# if defined( NMBASIC_ENABLE_INDEXED_NM )

#  if defined( NMBASIC_ENABLE_CHANNEL_INDIRECTION )
  if ( NmBasicCanToNmIndirection[chnl] < cNmBasicNrOfChannels ) {
    /* An indexed NM-Basic is running on the requested CAN channel => CAN channel not wakeable */
    result = BRSCTRL_CHANNEL_IS_NON_WAKEABLE;
  }
#  else
  /* An indexed NM-BASIC is running on each CAN channel => no CAN channel wakeable... */
  result = BRSCTRL_CHANNEL_IS_NON_WAKEABLE;
#  endif /* NMBASIC_ENABLE_CHANNEL_INDIRECTION */

# else  /* NMBASIC_ENABLE_INDEXED_NM */

#  if ( cNmBasicNrOfChannels == kCanNumberOfChannels )
  /* A non-indexed NM-BASIC is running on each CAN channel => no CAN channel wakeable... */
  result = BRSCTRL_CHANNEL_IS_NON_WAKEABLE;
#  else
  if ( NMBASIC_CAN_CHANNEL == chnl ) {
    /* NM-Basic is running on the requested CAN channel => CAN channel not wakeable */
    result = BRSCTRL_CHANNEL_IS_NON_WAKEABLE;
  }
#  endif /* cNmBasicNrOfChannels == kCanNumberOfChannels */

# endif /* NMBASIC_ENABLE_INDEXED_NM */
#endif /* VGEN_ENABLE_NM_BASIC */

#if defined( VGEN_ENABLE_NM_JUNIOR )

  /* NM-Junior does not support channel indirection on indexed CAN channels */
# if ( kNmjNumberOfChannels == kCanNumberOfChannels )
  result = BRSCTRL_CHANNEL_IS_NON_WAKEABLE;
# else
  if ( chnl == NMJ_CAN_CHANNEL ) {
    /* NM-Junior is running on the requested CAN channel => CAN channel not wakeable */
    result = BRSCTRL_CHANNEL_IS_NON_WAKEABLE;
  }
# endif /* kNmjNumberOfChannels == kCanNumberOfChannels */

#endif /* VGEN_ENABLE_NM_JUNIOR */

  return result;
}
#endif /* VGEN_ENABLE_NM_JUNIOR || VGEN_ENABLE_NM_BASIC */

/*****************************************************************************
 * All handling till here is only done, if this module is used in the current 
 * configuration
 *****************************************************************************/
#else /*BRS_ENABLE_TESTCONTROL*/

/*****************************************************************************/
/**
 * \brief Empty dummy function to satisfy compiler if file is empty
 */
void BrsCtrlDummyFunction( void ) {
}

#endif /*BRS_ENABLE_TESTCONTROL*/

/*  *****   STOPSINGLE_OF_MULTIPLE_COMMENT    *****  */
/************   Organi, Version 3.6.8 Vector-Informatik GmbH  ************/
