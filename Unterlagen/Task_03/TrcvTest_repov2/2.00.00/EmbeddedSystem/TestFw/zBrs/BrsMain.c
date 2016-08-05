/*****************************************************************************/
/**
 * \file    BrsMain.C
 * \brief   Basic Runtime System Main, Code
 *
 * This is the main file of the Basic Runtime System (BRS).
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
 *****************************************************************************
 * \version     R E V I S I O N   H I S T O R Y
 *****************************************************************************
 - Date         Version Author  Description
 - **********   ******* ******  ************************************
 - 2002-08-14   1.00.00 Ra      First Version
 - 2002-08-26   1.01.00 Uf      ESCAN00003602: ShutdownOs for CANoe OSEK added
 - 2002-10-23   1.02.00 Uf      ESCAN00003988: StartupOs parameter changed
 - 2002-10-31   1.02.01 Uf      ESCAN00004045: changed parenthesis for 
                                               main/CANoeAPI_main
 - 2003-03-31   1.03.00 Get     ESCAN00005270: support for single channel, code
                                               doubled channel and indexed
                                               channel added
 - 2003-05-12   1.04.00 Get     Time measurement macros added before entering
                                main loop -> calibration of measurement PC
                                Main function has signature int(void) now
                                according to MISRA rules
                                Declaration of globally visible variables has
                                moved to BrsMain.h according to MISRA rules
 - 2003-05-12   1.04.00 Get     Time measurement macros added before entering
 - 2003-06-03   1.04.01 Uf      Error msg for canoe osCan emulation changed
 - 2003-07-24   1.05.00 Uf      Comments changed to doxygen style
                                EnableInterruptAtPowerOn moved
 - 2003-08-22   1.05.01 Ra      _BRS_MEMCPY needs a MEMORY_FAR for the SRC 
                                parameter due to e.g. FJ16
 - 2003-08-29   1.06.00 Ra      Include sequence changed! CANbedded and test 
                                code is now included before BRS.
                                Include for BrsStaMa.H now always enabled
                                Check for BrsStaMa version > 01.03.xx added
 - 2003-09-24   1.07.00 Uf      Added organi comments
 - 2003-11-06   1.08.00 Ra      Legal text added, comments
 - 2004-03-19   1.08.01 Uf      Moved BrsCtrlInitPowerOn and TimeMeasurement
                                initialization in front of StartOS
 - 2004-08-31   1.09.00 Bir     Measure CPU load + Debug support over P2.8-11 EVA_BOARD_VEBN00035
 - 2004-09-17   1.10.00 Uf      Platform specific code removed 
 - 2004-10-25   1.11.00 Uf      Added BackgroundTask
                                Added named Organi includes
 - 2004-10-26   1.12.00 Uf      ESCAN00009968: Support CAN driver without disabled
                                               queue in BRS TCC
                                Header changed to uniform style
 - 2004-11-18   2.00.00 Ra      BRS supports event, warning and error history buffer.
 - 2004-12-21   2.00.01 Uf      Osek header include added.
 - 2005-01-11   2.00.02 Uf      MISRA compliant doxygen attributes
 - 2005-03-16   2.00.03 Uf      Use v_memrom qualifier for const variables
 - 2005-03-22   2.00.04 Uf      Added START/STOPSINGLE comments
 - 2005-07-26   2.01.00 Uf      Added QNX support               
 - 2005-07-28   2.01.01 Uf      Fixed function call BrsQNXWaitTimer
 - 2005-08-11   3.00.00 Om      Support BRS on FBL
 - 2005-10-10   3.00.01 Om      Support BRS on FBL with GENy
 - 2005-11-09   3.00.02 Om      Added support for AUTOSAR Stack
 - 2005-11-18   3.00.03 Uf      Removed ticks in comments
 - 2005-11-28   3.00.04 Om      Adjusted AUTOSAR and FBL support
 - 2005-12-06   3.01.00 Uf      Added filter rule warnings
 - 2005-12-08   3.02.00 Om      Moved BRS_MEMCPY to BrsCtrl
 - 2007-01-08   3.03.00 Get     - Measurement of Millisecond by Tester
                                - Counting exceedings of 1ms of BrsMainMilliSecondHandler
 - 2007-01-31   3.03.01 Get     Test features decoupled from demo use-case
 - 2007-02-05   3.03.02 Get     Measurement of millisecond decoupled from driver
 - 2007-02-13   3.03.03 Fr      Ms measurement possible when CanDrv is in polling mode
 - 2007-04-05   3.03.04 Ms      Updated AUTOSAR Support
 - 2007-04-25   3.03.05 Fmi     moved BrsCtrlInitPowerOn before BrsMainInit.inc
 - 2008-02-06   3.03.06 Get     added call of BrsAddOnInitPowerOn
 - 2008-03-12   3.04.00 Get     Support of Autosar compliant initialization
 - 2008-04-17   3.04.01 dH      Support of Autosar 3.0 initialization sequence
 - 2008-04-29   3.04.02 Get     Corrections of VGEN_ENABLE switches
 *****************************************************************************/

/*lint -esym(552,gwBrsMainExHandlerLineNumber) */ /* Do not inform for unreferenced variable */
/*lint -esym(552,gbBrsMainExHandlerModuleCode) */ /* Do not inform for unreferenced variable */
/*lint -esym(552,gbBrsMainExHandlerErrorCode)  */ /* Do not inform for unreferenced variable */

/*lint -e537 */ /* Do not inform for repeated include file */
/*lint -e766 */ /* Do not inform for included but unused header files */

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


/*****************************************************************************
 * Include the CANbedded files 
 *****************************************************************************/

/*******************************************************************************
 * The container BrsMainInc.inc is included here                              
 *******************************************************************************/


/*****************************************************************************
| include the component header files
|****************************************************************************/


/*****************************************************************************
| Include the demo files
|****************************************************************************/
#include "TscEnv.h"

/*  STOPSINGLE_OF_MULTIPLE   */

/*  STARTSINGLE_OF_MULTIPLE  */
/*******************************************************************************
 * The container BrsMainInc.inc is included till here                          
 *******************************************************************************/

#include "V_Def.H"
#include "BrsMain.H"
#include "BrsHw.H"
#include "BrsStaMa.H"
#if defined( BRS_ENABLE_TESTCONTROL )
#include "BrsCtrl.H"
#endif
#if defined( BRS_ENABLE_TESTADDON )
#include "BrsAddOn.H"
#endif
#if defined ( V_OSTYPE_AUTOSAR )
# include "os.h"
#elif defined ( V_OSTYPE_OSEK ) || defined ( VGEN_CANGEN_VERSION )
# include <osek.h> 
#elif defined ( V_OSTYPE_NONE )
#else
# error "V_OSTYPE is not defined!"
#endif
#include "BrsOSEK.h"

/*******************************************************************************
 * Global variables
 *******************************************************************************/
/**
 * \var gbBrsMainExHandlerErrorCode
 *              The BRS supports a global exception handler. The caller specific  
 *              error code is stored in this global variables for easy access 
 *              via emulator and debugger tools.
 */
volatile vuint8 gbBrsMainExHandlerErrorCode;

/**
 * \var gbBrsMainExHandlerModuleCode
 *              The BRS supports a global exception handler. The callers module  
 *              code is stored in this global variables for easy access via 
 *              emulator and debugger tools.
 */
volatile vuint8 gbBrsMainExHandlerModuleCode;

/**
 * \var gwBrsMainExHandlerLineNumber
 *              The BRS supports a global exception handler. The line number of
 *              calling module is stored in this global variables for easy access via 
 *              emulator and debugger tools.
 */
volatile vuint16 gwBrsMainExHandlerLineNumber;


/******************************************************************************
 * Version check
 ******************************************************************************/
#if( BRS_MAIN_VERSION != 0x0303 )
  #error "Header and source file are inconsistent!"
#endif
#if( BRS_MAIN_RELEASE_VERSION != 0x05 )
  #error "Different release versions in Header and Source used!"
#endif

#  if( BRS_STAMA_VERSION < 0x0103 )
    #error "BRS needs at least BrsStaMa.H component with version >= 01.03.xx"
#  endif

/******************************************************************************
 * Other checks
 ******************************************************************************/
#if defined( BRS_ENABLE_TESTADDON )
  /* Compatibility check for BrsAddOn version */
  #if (BRS_ADDON_VERSION<0x0300)
    #error "Sorry, this version of BrsMain needs at least BrsAddOn 2.0 or later!"
  #endif
#endif

#if defined( BRS_ENABLE_TESTCONTROL )
  /* Compatibility check for BrsCtrl version */
  #if (BRS_CTRL_VERSION<0x0300)
    #error "Sorry, this version of BrsMain needs at least BrsCtrl 2.0 or later!"
  #endif
#endif

#if defined( BRS_ENABLE_OSEKOS )
  /* Compatibility check for BrsOSEK version */
  #if (BRS_OSEK_VERSION<0x0200)
    #error "Sorry, this version of BrsMain needs at least BrsOSEK 2.0 or later!"
  #endif
#endif


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
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kBrsMainMainVersion    = (vuint8)(BRS_MAIN_VERSION >> 8);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kBrsMainSubVersion     = (vuint8)(BRS_MAIN_VERSION); /*lint !e778 */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kBrsMainReleaseVersion = (vuint8)(BRS_MAIN_RELEASE_VERSION);

#if defined ( C_COMP_IAR_M16C )
  #if defined ( _NEAR_ )
  /* Normal segment usage */
  #pragma memory=default
  #endif
#endif /*C_COMP_IAR_M16C*/



/*******************************************************************************
 * Local variables
 *******************************************************************************/
/**
 * \var bBrsMainCallCounter1ms
 *      Millisecond counter (1ms grid) used within  BrsMainMilliSecondHandler to
 *      calculate slower timings between 1ms and 20ms.
 */
static vuint8 bBrsMainCallCounter1ms;

/**
 * \var bBrsMainCallCounter20ms
 *      Millisecond counter (20 ms grid) used within  BrsMainMilliSecondHandler to
 *      calculate slower timings between 20ms and 1000ms.
 */
static vuint8 bBrsMainCallCounter20ms;
 
/**
 * \var bBrsMainToggleLedCounter
 *      Counter for LED toggling within  BrsMainMilliSecondHandler
 */
static vuint8 bBrsMainToggleLedCounter;


/*******************************************************************************
 * Local const variables
 *******************************************************************************/
#if defined ( C_COMP_IAR_M16C )
  #if defined ( _NEAR_ )
  /* Set const data to const segment, don't initialize */
  #pragma memory=constseg(CONST_DATA) :far
  #endif
#endif /*C_COMP_IAR_M16C*/

/* None used */

#if defined ( C_COMP_IAR_M16C )
  #if defined ( _NEAR_ )
  /* Normal segment usage */
  #pragma memory=default
  #endif
#endif /*C_COMP_IAR_M16C*/



/*******************************************************************************
 * Prototypes of local functions 
 *******************************************************************************/

/*******************************************************************************
 * Function definitions
 *******************************************************************************/

/**
 * \brief This is the "main" of C where the startup code ended and the application 
 *        starts.
 *        This function is the correct place to initialize all hardware and the
 *        software modules "at power on" or "reset". 
 *        The code ensures, that the global interrupt is locked during the 
 *        execution of this function.
 *        If an OSEK/OS is used, the OS startup is called, else an endless loop
 *        is entered where the 1ms base time clock for further handling is 
 *        provided.
 *
 * \retval Always 0 (due to its the main, the return statement will never be reached)
 */
void CANoeAPI_Main(void)
{
  bBrsMainCallCounter1ms  = 0;
  bBrsMainCallCounter20ms = 0;
  bBrsMainToggleLedCounter = 0;

  gbBrsMainExHandlerModuleCode = 0;
  gwBrsMainExHandlerLineNumber = 0;

  #if defined( BRS_ENABLE_TESTADDON )
  gwBrsAddOnTestRunTime = 0;
  #endif

  BrsHwDisableInterruptAtPowerOn();

  BrsHwHardwareInitPowerOn();

  /*--- application-specific ---*/
  TscEnv_Init();

  #if defined( BRS_ENABLE_TESTCONTROL )
  BrsCtrlInitPowerOn();
  #endif

  BrsHwTime100NOP();
  BrsHwTime100NOP();

  StartOS(OSDEFAULTAPPMODE);
}

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
)
{
  BrsHwDisableInterrupt(); 
  gbBrsMainExHandlerErrorCode  = ErrorCode;
  gbBrsMainExHandlerModuleCode = ModuleCode;
  gwBrsMainExHandlerLineNumber = LineNumber;
  ShutdownOS(0);
}

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
void BrsMainMilliSecondHandler( void )
{
  #if defined( BRS_ENABLE_TESTADDON )
  gwBrsAddOnTestRunTime++;
  #endif

  bBrsMainCallCounter1ms++;

  #if defined( BRS_ENABLE_TESTCONTROL )
  BrsCtrlRetryTransmit();
  #endif

  /*--- application-specific ---*/
  TscEnv_Cyclic1ms();

  /** 20ms call cycle and reset of 1ms counter */
  if (bBrsMainCallCounter1ms == 20) {
    bBrsMainCallCounter1ms = 0;
    bBrsMainCallCounter20ms++;

    /** 500ms call cycle */
    if (bBrsMainCallCounter20ms == 25 ) {
        bBrsMainToggleLedCounter++;
        BrsHwSetLed(BRSHW_LED_SYSTEM_OK, (vuint8) (bBrsMainToggleLedCounter & 0x01));
        bBrsMainCallCounter20ms = 0;
    }
  }
}


/*******************************************************************************/
/**
 * \brief Background function which is called every time the msTask is not active
 * \pre   Has to be called as background task by the OS or by the main function
 */
void BrsMainBackgroundFunc( void )
{
}
