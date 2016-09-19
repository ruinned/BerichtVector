/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: FrTrcv
 *           Program: 
 *          Customer: N/A
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: 
 *    License Scope : The usage is restricted to CBD0000000_D16
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: FrTrcv_30_Tja1080_Cfg.h
 *   Generation Time: 2016-03-08 11:38:45
 *           Project: CanCanFr - Version 1.0
 *          Delivery: CBD0000000_D16
 *      Tool Version: DaVinci Configurator  5.11.16 SP1
 *
 *
 *********************************************************************************************************************/


#if !defined(FRTRCV_30_TJA1080_CFG_H)
#define FRTRCV_30_TJA1080_CFG_H

/* -----------------------------------------------------------------------------
    &&&~ General Define Block
 ----------------------------------------------------------------------------- */

#ifndef FRTRCV_30_TJA1080_USE_DUMMY_FUNCTIONS
#define FRTRCV_30_TJA1080_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef FRTRCV_30_TJA1080_USE_DUMMY_STATEMENT
#define FRTRCV_30_TJA1080_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef FRTRCV_30_TJA1080_DUMMY_STATEMENT
#define FRTRCV_30_TJA1080_DUMMY_STATEMENT(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef FRTRCV_30_TJA1080_DUMMY_STATEMENT_CONST
#define FRTRCV_30_TJA1080_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef FRTRCV_30_TJA1080_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define FRTRCV_30_TJA1080_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef FRTRCV_30_TJA1080_ATOMIC_VARIABLE_ACCESS
#define FRTRCV_30_TJA1080_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef FRTRCV_30_TJA1080_PROCESSOR_CANOEEMU
#define FRTRCV_30_TJA1080_PROCESSOR_CANOEEMU
#endif
#ifndef FRTRCV_30_TJA1080_COMP_ANSI
#define FRTRCV_30_TJA1080_COMP_ANSI
#endif
#ifndef FRTRCV_30_TJA1080_GEN_GENERATOR_MSR
#define FRTRCV_30_TJA1080_GEN_GENERATOR_MSR
#endif
#ifndef FRTRCV_30_TJA1080_CPUTYPE_BITORDER_LSB2MSB
#define FRTRCV_30_TJA1080_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef FRTRCV_30_TJA1080_CONFIGURATION_VARIANT_PRECOMPILE
#define FRTRCV_30_TJA1080_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef FRTRCV_30_TJA1080_CONFIGURATION_VARIANT_LINKTIME
#define FRTRCV_30_TJA1080_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef FRTRCV_30_TJA1080_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define FRTRCV_30_TJA1080_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef FRTRCV_30_TJA1080_CONFIGURATION_VARIANT
#define FRTRCV_30_TJA1080_CONFIGURATION_VARIANT FRTRCV_30_TJA1080_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef FRTRCV_30_TJA1080_POSTBUILD_VARIANT_SUPPORT
#define FRTRCV_30_TJA1080_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* -----------------------------------------------------------------------------
    &&&~ Constants
 ----------------------------------------------------------------------------- */

/* START of Checksum include for
  - DrvTrans_Tja1080FrAsrPreCompileCRC */
#define FRTRCV_30_TJA1080_MAX_NUM_OF_BTR_BUSSES                2
/* AUTOSAR Version Info */
#define FRTRCV_30_TJA1080_AUTOSARVERSION   4
/* Main Function call cycle time in ms */
#define FRTRCV_30_TJA1080_MAIN_FUNCTION_CYCLE_TIME      5
/* Pre-processor switch to enable the single channel API */
#define FRTRCV_30_TJA1080_API_OPTIMIZATION              STD_OFF
/* Pre-processor switch to enable the Development Error Tracer. */
#define FRTRCV_30_TJA1080_DEV_ERROR_DETECT              STD_ON
#define FRTRCV_30_TJA1080_DEV_ERROR_REPORT              STD_ON
/* Pre-processor switch to enable the Diagnostic Event Manager. */
#define FRTRCV_30_TJA1080_PROD_ERROR_DETECT             STD_ON
/* Pre-processor switch to enable DEM user call-back */
#define FRTRCV_30_TJA1080_TRCV_DEM_CALLBACK             STD_ON
/* Pre-processor switch to enable version info support. ON/OFF */
#define FRTRCV_30_TJA1080_VERSION_INFO_API              STD_ON
/* Pre-processor switch to enable Transceiver Diagnosis. ON/OFF */
#define FRTRCV_30_TJA1080_TRCV_DIAGNOSIS                STD_ON
/* Pre-processor switch to enable WUP interrupt support. ON/OFF */
#define FRTRCV_30_TJA1080_WUPINT_CBK                    STD_OFF
/* Pre-processor switch to enable User DIO Support. ON/OFF */                                			 
#define FRTRCV_30_TJA1080_USERDIO						STD_OFF	
/* Pre-processor switch to enable Wakeup Support. ON/OFF */
#define FRTRCV_30_TJA1080_WAKEUP_SUPPORT                STD_ON
/* END of Checksum include for
  - DrvTrans_Tja1080FrAsrPreCompileCRC */



#endif /* FRTRCV_30_TJA1080_CFG_H */
    
