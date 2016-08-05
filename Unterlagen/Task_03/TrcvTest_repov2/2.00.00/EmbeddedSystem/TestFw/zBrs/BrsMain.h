/*  *****   STARTSINGLE_OF_MULTIPLE_COMMENT    *****  */






/*****************************************************************************/
/**
 * \file    BrsMain.H
 * \brief   Basic Runtime System Main, Header
 *
 * This is the main file of the Basic Runtime System (BRS).
 *                                
 * \attention Please note:
 *  The demo and example program only shows special aspects of the software. 
 *  With regard to the fact that this program is meant for demonstration purposes 
 *  Vector Informatik's liability shall be expressly excluded in cases of 
 *  ordinary negligence, to the extent admissible by law or statute. 
 *
 * Check up BrsMain.c for description, author and history
 * Version info: see BRSMAIN_VERSION, BRSMAIN_RELEASE_VERSION
 *
 *****************************************************************************
 *               C O P Y R I G H T
 *****************************************************************************
 * Copyright (c) 2007 by Vector Informatik GmbH.      All rights reserved.
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

#ifndef _BRSMAIN_H_
#define _BRSMAIN_H_

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
 * Description: This is the BRS main module main and release version.
 *              The version numbers are BCD coded. E.g. a main version of 1.23 is 
 *              coded with 0x0123, a release version of 9 is coded 0x09.
 */
/* ##V_CFG_MANAGEMENT ##CQProject : Brs_Main CQComponent : Implementation */
#define BRS_MAIN_VERSION          0x0303
#define BRS_MAIN_RELEASE_VERSION  0x05

#define BRSMAIN_VERSION        BRS_MAIN_VERSION
#define BRSMAIN_BUGFIX_VERSION BRS_MAIN_RELEASE_VERSION

/*******************************************************************************
* Global defines
*******************************************************************************/
/* Debug functions */
#ifdef BRS_ENABLE_USER_DEBUG 
  #define BrsAssertUser(p,e,m)         if (!(p)) BrsMainExceptionHandler((e), (m), (vuint16)__LINE__)
  #define BrsAssertUserDirect(e,m)     BrsMainExceptionHandler((e), (m), (vuint16)__LINE__)
#else
  #define BrsAssertUser(p,e,m) 
  #define BrsAssertUserDirect(e,m)
#endif

#ifdef BRS_ENABLE_INTERNAL_DEBUG 
  #define BrsAssertInternal(p,e,m)     if (!(p)) BrsMainExceptionHandler((e), (m), (vuint16)__LINE__)
  #define BrsAssertInternalDirect(e,m) BrsMainExceptionHandler((e), (m), (vuint16)__LINE__)
#else
  #define BrsAssertInternal(p,e,m)
  #define BrsAssertInternalDirect(e,m)
#endif


/*******************************************************************************
 * ErrorCodes for BrsMainExceptionHandler 
 * 0x00 to 0x7f are assigned to the BRS
 * 0x80 to 0xff are assigned to the application
 ******************************************************************************/
/* General error which is not assigned to a special error class */
#define kBrsUndefinedError                   0x00

/* No handler is installed in interrupt vector table for given interrupt */
#define kBrsInterruptHandlerNotInstalled     0x01

/* A GenTool setting is different to the excepted value */
#define kBrsWrongGenToolSettings             0x02

/* BrsHwRestoreInterrupt is called more often than BrsHwDisableInterrupt */
#define kBrsIllegalInterruptRestoration      0x03

/* Hardware configuration like clock setting is wrong */
#define kBrsIllegalHardwareConfiguration     0x04

/* Illegal parameter used like wrong channel parameter */
#define kBrsIllegalParameter                 0x05

/* Illegal TCC channel used */
#define kBrsTccChannelOutOfRange             0x06

/* Interrupt from unknown source occurred */
#define kBrsUnknownInterrupt                 0x07

/* CAN1 and CAN2 interrupts cannot be distinguished from each other */
#define kBrsAmbiguousInterruptSource         0x08

/* 
 * Description: Compatibility defines 
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


/*******************************************************************************
* Global variables
*******************************************************************************/
#if defined( BRS_ENABLE_OSEKOS )
#else
/**
 * \var gbBrsMainIsrMilliSecondFlag
 *      The BRS internal timing is based on a cyclic called function. The call 
 *      must be performed each 1ms. This is done by an endless loop polling 
 *      this variable for being '1'. The value is set to '1' by a periodic 
 *      interrupt function in the hardware dependent module HW_CTRL. The value 
 *      is cleared to '0', if the 1ms event has been handled. The separation of 
 *      hardware independent and hardware dependent parts is the only reason to 
 *      export this variable here.
 *      Values: 0, wait for next 1ms event; 1, 1ms event occured
 */
 extern volatile vuint8 gbBrsMainIsrMilliSecondFlag;
#endif /* BRS_ENABLE_OSEKOS */


/**
 * \var gbBrsMainExHandlerErrorCode
 *              The BRS supports a global exception handler. The caller specific  
 *              error code is stored in this global variables for easy access 
 *              via emulator and debugger tools.
 */
extern volatile vuint8  gbBrsMainExHandlerErrorCode;

/**
 * \var gbBrsMainExHandlerModuleCode
 *              The BRS supports a global exception handler. The callers module  
 *              code is stored in this global variables for easy access via 
 *              emulator and debugger tools.
 */
extern volatile vuint8  gbBrsMainExHandlerModuleCode;

/**
 * \var gwBrsMainExHandlerLineNumber
 *              The BRS supports a global exception handler. The line number of
 *              calling module is stored in this global variables for easy access via 
 *              emulator and debugger tools.
 */
extern volatile vuint16 gwBrsMainExHandlerLineNumber;


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
 * \var kBrsMainMainVersion
 *      Stores the BCD coded main-version of this file.
 */
 /**
 * \var kBrsMainSubVersion 
 *      Stores the BCD coded sub-version of this file.
 */
 /**
 * \var kBrsMainReleaseVersion 
 *      Stores the BCD coded release-version of this file.
 */
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kBrsMainMainVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kBrsMainSubVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kBrsMainReleaseVersion;

#if defined ( C_COMP_IAR_M16C )
  #if defined ( _NEAR_ )
  /* Normal segment usage */
  #pragma memory=default
  #endif
#endif /*C_COMP_IAR_M16C*/



/*******************************************************************************
* Function protoytpes
*******************************************************************************/


#define BRSERROR_MODULE_BRSHW      0x01
#define BRSERROR_MODULE_BRSMAIN    0x02
#define BRSERROR_MODULE_BRSOSEK    0x03
#define BRSERROR_MODULE_BRSADDON   0x04
#define BRSERROR_MODULE_BRSQNX     0x05
#define BRSERROR_MODULE_BRSCTRL    0x06

/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/**
 * \brief This is the central exeption handler of BRS.
 *        All BRS modules and all CANbedded specific fatal error handler will
 *        call this API in case an assertion has failed.
 *
 * \param[in] ErrorCode shall hold the caler specific error code (vuint8)
 * \param[in] ModuleCode shall describe the caller; please use the CI constant 
 *            as parameter (vuint8)
 * \param[in] LineNumber shall be the line where the assertion has failed, or, 
 *            if not available on caller location, the line where this API is 
 *            called from.
 *
 * \attention This function implements an endless loop with locked interrupts.
 *            The recommendation is to set a breakpoint on top of this function 
 *            to see if any assertion has failed during the code execution.
 *
 * \post      Due to an assertion has failed and the endless loop runs with
 *            locked global interrupts there will be no life after the call ...
 */
void BrsMainExceptionHandler( 
  vuint8  ErrorCode, 
  vuint8  ModuleCode, 
  vuint16 LineNumber
);

/*******************************************************************************/
/**
 * \brief This is the BRS 1ms cyclic function where all 1ms and slower calls 
 *        are made.
 *        The function will be called out of the endless loop in main() or by an
 *        OSEK/OS task running with a 1ms resolution.
 *        The user may implement own call cycles between 1ms and 20ms by comparing
 *        to the bBrsMainCallCounter1ms. This counter is reset each 20ms to 0.
 *
 * \attention The runtime within each call of the function shall be smaller than 
 *            1ms! Else the expected time base can not be kept constant by BRS.
 *            If there are multiple 10ms call cycles, split them to e.g. one call
 *            at 1ms and one at 11ms and the other to 3ms and 13ms.
 */
extern void BrsMainMilliSecondHandler( 
  void
);


/*******************************************************************************/
/**
 * \brief Background function which is called every time the msTask is not active
 * \pre   Has to be called as background task by the OS or by the main function
 */
extern void BrsMainBackgroundFunc( 
  void
);

#endif /*_BRSMAIN_H_*/
/*  STOPSINGLE_OF_MULTIPLE   */
/************   Organi, Version 3.6.8 Vector-Informatik GmbH  ************/
