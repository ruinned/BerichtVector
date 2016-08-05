/*  *****   STARTSINGLE_OF_MULTIPLE_COMMENT    *****  */




/*****************************************************************************/
/**
 * \file    BrsAddOn.C
 * \brief   Basic Runtime System addons, Code
 *
 * This is the test support add on code file for the Basic Runtime System (BRS).
 *
 * This module offers test support functions like checksum calculation and 
 * 'time measurement' support. The 'time measurement' support is splitted in 
 * a hardware independent part (here) and a hardware specific part (see 
 * BrsHw files).
 * The module offers also standardised access to event, warning and error 
 * storage and a 1ms time measurement.
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
 - Dhf          Daniel Hof                Vector Informatik GmbH
 - Ms           Gunnar Meiss              Vector Informatik GmbH
 *****************************************************************************
 * \version     R E V I S I O N   H I S T O R Y
 *****************************************************************************
 - Date         Version Author  Description
 - **********   ******* ******  ************************************
 - 2002-08-14   1.00.00 Ra      First Version
 - 2002-09-04   1.00.01 Uf      ESCAN00003659: RDBI/0xF7 allowed for all timers
 - 2003-05-12   1.01.00 Get     Some changes made according to MISRA rules
 - 2003-06-17   1.02.00 Get     API added to retrieve FRT resolution
                                32bit Free Running Timer support added
 - 2003-07-24   1.03.00 Uf      Comments changed to doxygen style
 - 2003-10-17   1.03.01 Get     ESCAN00006810: Compilers may report an error
 -                              when encountering an empty source file
 - 2003-11-06   1.04.00 Ra      Legal text added, comments 
 - 2004-10-26   1.05.00 Uf      Header changed to uniform style
 - 2004-11-18   2.00.00 Ra      New functionality (event, warning and error 
                                tracing) added. BrsAddOnCyclic10ms removed.
 - 2005-01-11   2.00.01 Uf      MISRA compliant doxygen attributes
 - 2005-01-24   2.00.02 Ra      PCLint warning "for unreachable code" removed
 - 2005-02-07   2.01.00 Get     Support for LIN 2.0 added
 - 2005-02-22   2.02.00 Get     Encapsulation of BrsAddOnReadHistoryBufferInBrsCmd
                                in #if defined( BRS_ENABLE_TESTCONTROL ) ... #endif
 - 2005-03-16   2.02.01 Uf      New memory qualifier
 - 2005-03-16   2.02.02 Uf      Use v_memrom qualifier for const variables
 - 2005-08-11   3.00.00 Om      Support for BRS on FBL
 - 2005-10-10   3.00.01 Om      Support for BRS on FBL with GENy
 - 2005-11-18   3.00.02 Uf      Removed ticks in comments
 - 2005-11-28   3.00.03 Om      Removed FBL related ifdef's
 - 2005-12-06   3.01.00 Uf      Added filter rule warnings
 - 2005-12-06   3.02.00 Dhf/Uf  Event queue access interface added
 - 2006-03-28   3.02.01 Uf      Fixed BrsAddOnReadHistoryBufferInBrsCmd
 - 2006-10-27   3.03.00 Uf      Added AUTOSAR Lin support
 - 2006-11-02   3.03.01 Ms      Added AUTOSAR Can support
 - 2007-01-08   3.04.00 Get     Add support to measure exceedings of
                                BrsMainMilliSecondHandler
 - 2007-04-03   3.04.01 Ms      Updated AUTOSAR Support
 *****************************************************************************/

/*lint -e537 */ /* Do not inform for repeated include file */
/*lint -e551 */ /* Allow unaccessed variables */
/*lint -e766 */ /* Do not inform for unused header file */

/*lint -esym(564, BrsAddOnTimeData) */ /* Suppress warning "BrsAddOnTimeData depends on order of evaluation" */

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

#if defined( VGEN_ENABLE_CAN_DRV )
 /*
  * Description: CANbedded CAN driver header.
  */
# if defined ( VGEN_ENABLE_IF_ASRIFCAN )
#  include "CanProto.h"
# else
#  include "can_inc.h"
# endif
#endif /* VGEN_ENABLE_CAN_DRV */

#if defined (VGEN_ENABLE_LIN_DRV )
#  if defined (VGEN_ENABLE_IF_ASRIFLIN)
 /*
  * Description: Autosar LIN driver header.
  */
    #include "ComStack_Types.h"
    #include "Lin_Cfg.h"
#  else
 /*
  * Description: CANbedded LIN driver header.
  */
#    if defined ( VGEN_GENY )
#    include "LIN_API.H"
#    else
#    include "LIN_INC.H"
#    endif /* VGEN_GENY */
#   endif /* VGEN_ENABLE_IF_ASRIFLIN */
#endif /* VGEN_ENABLE_LIN_DRV */

/*
 * Description: The V_Def header provides types and definitions common to all 
 *              VECTOR CANbedded modules.
 */
#include "V_Def.H"

/*
 * Description: The BrsAddOn header provides all the necessary interfaces to
 *              the test support module. 
 *              This file is part of the BRS.
 */
#include "BrsAddOn.H"


#if defined( BRS_ENABLE_TESTCONTROL )
/*
 * Description: The BrsCtrl header provides all the necessary interfaces to
 *              the test control management. Please refer to the BrsCtrl module
 *              for details of the used test control handling.
 *              This file is part of the BRS.
 */
#include "BrsCtrl.H"
#endif


/******************************************************************************
 * Version check
 ******************************************************************************/
#if( BRS_ADDON_VERSION != 0x0304)
  #error "Header and source file are inconsistent!"
#endif
#if( BRS_ADDON_RELEASE_VERSION != 0x01 )
  #error "Different release versions in Header and Source used!"
#endif


/****************************************************************************/
#if defined( BRS_ENABLE_TESTADDON )
/*****************************************************************************
 * All handling below this line (execpt the export of the version constants)
 * is only enabled if the BrsAddOnis enabled!
 *****************************************************************************/


/******************************************************************************
 * BRS configuration check
 ******************************************************************************/
#if defined(  BRS_ENABLE_TIMETEST )
 #if defined(  BRS_ENABLE_TIMETEST_FREETIMER )
  #if defined(  BRS_ENABLE_TESTCONTROL )
   /* BRS configuration ok for time measurement */
  #else
   #error "BRS configuration NOT ok for time measurement"
  #endif /*BRS_ENABLE_TESTCONTROL*/
 #endif /*BRS_ENABLE_TIMETEST_FREETIMER*/
#endif /*BRS_ENABLE_TIMETEST*/


#if defined( BRS_ENABLE_TESTCONTROL )
  /* Compatibility check for BrsCtrl version */
  #if (BRS_CTRL_VERSION<0x0300)
    #error "Sorry, this version of BrsAddOn needs at least BrsCtrl 3.00 or later!"
  #endif
#endif /* BRS_ENABLE_TESTCONTROL */


/*******************************************************************************
 * Global variables
 *******************************************************************************/
#if defined( BRS_ENABLE_TIMETEST )
 #if defined( BRS_ENABLE_TIMETEST_FREETIMER )
 /**
  * \var BrsAddOnTimeData
  *      Used only, if the  BRS time measurement support for "FREETIMER" is
  *      enabled. If this is true, for each time stamp, an array index is used to
  *      store the different values to calculate the time difference. A '+1' is
  *      used to store also the calibration data in the array. The calibration 
  *      data is always the last time stamp in the array.
  *      Values: 0 to time register size. Time register size is hardware dependant.
  */
  volatile tBrsAddOnTimes BrsAddOnTimeData[BRS_TIMETEST_COUNT+1];

 #endif /*BRS_ENABLE_TIMETEST_FREETIMER*/
#else /*BRS_ENABLE_TIMETEST*/
/* None used */
#endif /*BRS_ENABLE_TIMETEST*/

 /**
  * \var gwBrsAddOnTestRunTime
  *       The BrsAddOn provides a 16 bit time counter to measure the runtime of a 
  *       test with the resolution of the BrsMain 1ms task. 
  *
  * \attention: The value of the variable is cleared by any test application 
  *             in the system! Make sure when and how to use this feature in your own test!
  */
volatile vuint16 gwBrsAddOnTestRunTime;

 /**
  * \var gwBrsAddOnTestMsExceed
  *       The BrsAddOn provides a 16 bit time counter to measure the number of times, which 
  *       the gbBrsMainIsrMilliSecondFlag exceeds the value of 1, i.e. the main millisecond
  *       task consumes too much runtime.
  */
volatile vuint16 gwBrsAddOnTestMsExceed;

/****************************************************************************
 * All handling above this line is only enabled if the BrsAddOn is enabled!
 * This is a "temporary enable" only to export the version constants and to 
 * make sure the file is NOT empty and irritates the compiler!
 *****************************************************************************/
#endif /*BRS_ENABLE_TESTADDON*/
/*****************************************************************************/


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
 * \var kBrsAddOnMainVersion
 *      Stores the BCD coded main-version of this file.
 */
 /**
 * \var kBrsAddOnSubVersion 
 *      Stores the BCD coded sub-version of this file.
 */
 /**
 * \var kBrsAddOnReleaseVersion 
 *      Stores the BCD coded release-version of this file.
 */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kBrsAddOnMainVersion    = (vuint8)(BRS_ADDON_VERSION >> 8);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kBrsAddOnSubVersion     = (vuint8)(BRS_ADDON_VERSION); /*lint !e778 */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kBrsAddOnReleaseVersion = (vuint8)(BRS_ADDON_RELEASE_VERSION);

#if defined ( C_COMP_IAR_M16C )
  #if defined ( _NEAR_ )
  /* Normal segment usage */
  #pragma memory=default
  #endif
#endif /*C_COMP_IAR_M16C*/


/****************************************************************************/
#if defined( BRS_ENABLE_TESTADDON )
/*****************************************************************************
 * All handling below this line is only enabled if the BrsAddOn is enabled!
 *****************************************************************************/


/*******************************************************************************
 * Local defines
 *******************************************************************************/

/*
 * Description: The default for event sampling is defined here. If no other
 *              define exists, the size is predefined. To change the setting
 *              just include a Brs-Preconfig file in your generated BrsCfg.H
 *              and define an other value; smaller if there is not enough RAM
 *              or larger if you have needs to store more than supported by
 *              default
 */
#if !defined(BRSADDON_MAX_EVENT_SAMPLES)
  #define BRSADDON_MAX_EVENT_SAMPLES 20
#endif
#if !(BRSADDON_MAX_EVENT_SAMPLES>0)
  #error "Configuration error in additional config file included in BrsCfg.H! Number of supported events must be at least 1!"
#endif
#if (BRSADDON_MAX_EVENT_SAMPLES>255)
  #error "Configuration error in additional config file included in BrsCfg.H! Number of supported events is max 255!"
#endif

#if !defined(BRSADDON_MAX_WARNING_SAMPLES)
  #define BRSADDON_MAX_WARNING_SAMPLES 20
#endif
#if !(BRSADDON_MAX_WARNING_SAMPLES>0)
  #error "Configuration error in additional config file included in BrsCfg.H! Number of supported warnings must be at least 1!"
#endif
#if (BRSADDON_MAX_WARNING_SAMPLES>255)
  #error "Configuration error in additional config file included in BrsCfg.H! Number of supported warnings is max 255!"
#endif
  
#if !defined(BRSADDON_MAX_ERROR_SAMPLES)
  #define BRSADDON_MAX_ERROR_SAMPLES 20
#endif
#if !(BRSADDON_MAX_ERROR_SAMPLES>0)
  #error "Configuration error in additional config file included in BrsCfg.H! Number of supported errors must be at least 1!"
#endif
#if (BRSADDON_MAX_ERROR_SAMPLES>255)
  #error "Configuration error in additional config file included in BrsCfg.H! Number of supported errors is max 255!"
#endif

/*******************************************************************************
* Local typedefs
*******************************************************************************/
typedef struct stBrsAddOnWarningHistory {
  vuint16 wEventTime;
  vuint16 wYourState;
  vuint8  bCI;
  vuint8  bYourWarningCode;
} tBrsAddOnWarningHistory;

typedef struct stBrsAddOnErrorHistory {
  vuint16 wEventTime;
  vuint16 wYourState;
  vuint8  bCI;
  vuint8  bYourErrorCode;
} tBrsAddOnErrorHistory;


/*******************************************************************************
 * Local variables
 *******************************************************************************/
#if defined( BRS_ENABLE_TIMETEST )
 #if defined( BRS_ENABLE_TIMETEST_FREETIMER )

 /**
  * \var bBrsAddOnTimeAnswerPending
  *      Shows if time measurement messages are pending
  *      Values: 1-true, 0-false
  */
 static volatile vuint8 bBrsAddOnTimeAnswerPending;

 /**
  * \var bBrsAddOnTimeStampNumber
  *      Shows which time measurement point is requested
  */
 static volatile vuint8 bBrsAddOnTimeStampNumber;

 #endif /*BRS_ENABLE_TIMETEST_FREETIMER*/
#endif /*BRS_ENABLE_TIMETEST*/


/**
 * \var bBrsAddOnNumOfStoredEvents
 *      This counter is used to count the up to now stored events in the 
 *       assigned event history buffer.
 */
static volatile vuint8 bBrsAddOnNumOfStoredEvents;

/**
 * \var bBrsAddOnNumOfStoredWarnings
 *      This counter is used to count the up to now stored warnings in the 
 *       assigned warning history buffer.
 */
static volatile vuint8 bBrsAddOnNumOfStoredWarnings;

/**
 * \var bBrsAddOnNumOfStoredErrors
 *      This counter is used to count the up to now stored errors in the 
 *      assigned error history buffer.
 */
static volatile vuint8 bBrsAddOnNumOfStoredErrors;

/**
 * \var sBrsAddOnEventSample
 *      The BrsAddOn provides a event history trace buffer.
 */
static volatile tBrsAddOnEventHistory sBrsAddOnEventSample[BRSADDON_MAX_EVENT_SAMPLES];

/**
 * \var sBrsAddOnWarningSample
 *      The BrsAddOn provides a event warning trace buffer.
 */
static volatile tBrsAddOnWarningHistory sBrsAddOnWarningSample[BRSADDON_MAX_WARNING_SAMPLES];

/**
 * \var sBrsAddOnErrorSample
 *      The BrsAddOn provides a error history trace buffer.
 */
static volatile tBrsAddOnErrorHistory sBrsAddOnErrorSample[BRSADDON_MAX_ERROR_SAMPLES];


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
 * Prototypes of local functions 
 *******************************************************************************/
#if defined( BRS_ENABLE_TIMETEST )
 #if defined( BRS_ENABLE_TIMETEST_FREETIMER )
/*******************************************************************************/
/**
 * \brief This API is used locally to send the TCC response for local time
 *        measurement.
 *        The TestControlCenter (TCC) is used to answer the tester request
 *        for the time mark settings.
 *
 * \param[in] TimeStampMark Number of the time stamp mark to be written in the 
 *            answer
 *
 * \pre       The TestControlCenter has to be initialized and ready  
 */
static void BrsAddOnTimeSetResponse(
   vuint8 TimeStampMark
);
 #endif /*BRS_DISABLE_TIMETEST_PC*/
#endif /*BRS_ENABLE_TIMETEST*/



/*******************************************************************************
 * Function definitions
 *******************************************************************************/

/*******************************************************************************/
/**
 * \brief BrsAddOn power on initialization
 *        This function has to be used to initialize the test support functions 
 *        at a power up situation. This is necessary to initialize all internal
 *        variables and states.
 *
 * \pre   Hardware (power supply and clocks) is initialized, global interrupts are disabled.
 *
 * \post   BrsAddOn is initialized and could be used now.
 */
void BrsAddOnInitPowerOn( 
  void 
)
{
  /** gwBrsAddOnTestRunTime will be set to 0 in BrsMain, function main */

  bBrsAddOnNumOfStoredEvents   = 0;
  bBrsAddOnNumOfStoredWarnings = 0;
  bBrsAddOnNumOfStoredErrors   = 0;
#if defined( BRS_ENABLE_TIMETEST )
  BrsAddOnResetTime();
#endif /* BRS_ENABLE_TIMETEST */
  gwBrsAddOnTestMsExceed       = 0;
}


#if defined( BRS_ENABLE_TIMETEST )
 #if defined( BRS_ENABLE_TIMETEST_FREETIMER )
/*******************************************************************************/
/**
 * \brief BrsAddOn time calculation
 *        Calculate Timings for given TimeStampMark. It is called by each time
 *        stamp stop mark macro
 *
 * \param[in] TimeStampMark is number of the time stamp mark to be calculated.
 *
 * \pre  System is running & initialized
 *
 */
void BrsAddOnTimeCalculate( 
  vuint8 TimeStampMark
)
{
  /* This variable must not be 'static' to allow the reentrance of the function! */
  tBrsAddOnTimerSize currentTime;

  /* By unsigned values the underflow case will be correctly calculated (Will be?) */
  currentTime = (tBrsAddOnTimerSize) (BrsAddOnTimeData[TimeStampMark].StopTime - BrsAddOnTimeData[TimeStampMark].StartTime);

  if (currentTime<BrsAddOnTimeData[TimeStampMark].MinTime) {
    BrsAddOnTimeData[TimeStampMark].MinTime = currentTime;
  }
  if (currentTime>BrsAddOnTimeData[TimeStampMark].MaxTime) {
    BrsAddOnTimeData[TimeStampMark].MaxTime = currentTime;
  }
}
 #endif /*BRS_ENABLE_TIMETEST_FREETIMER*/
#endif /*BRS_ENABLE_TIMETEST*/


#if defined( BRS_ENABLE_TESTCONTROL )
/*******************************************************************************/
/**
 * \brief BrsAddOn time measurement command interpreter
 *        This function is called each time the TCC receives a time measurement 
 *        request. It has to interpret the request and to answer immediately 
 *        or ASAP. The function is always available to prevent linker errors
 *        and to much preprocessor checks in the TCC. It is called in BRS 
 *        precopy function (ISR context!).
 *
 * \retval The error code notifies the BRS command handler if the answer is 
 *         already filled out or a TCC error code shall be send to the tester.
 *
 * \pre   The TestControlCenter and the module has to be initialized 
 *        and ready
 */
vuint8 BrsAddOnTimeCmdInterpreter(
   void
)
{
    vuint8  errorCode = 0;

/*lint -save -e764 */ /* Suppress "switch statement does not have a case" */
    switch ( gbBrsCtrlMsgBuffer[4]) {
    #if defined( BRS_ENABLE_TIMETEST )
    case 0xF6:
        switch ( gbBrsCtrlMsgBuffer[5]) {
        case 0x00:
            gbBrsCtrlMsgBuffer[4] = BRS_TIMETEST_COUNT;
            break;
        case 0x01:
            BrsHwDisableInterrupt();
            BrsAddOnResetTime();
            BrsHwRestoreInterrupt();
            break;
        case 0x02:
            BrsHwDisableInterrupt();
            BrsHwRestoreInterrupt();
            break;
        case 0x03:
            BrsHwTime100NOP();
            break;
        #if defined( BRS_ENABLE_TIMETEST_FREETIMER )
        case 0x04:
            #if defined( BRSHW_TIME_TIMERREGISTER_32BIT )
            gbBrsCtrlMsgBuffer[4] = 4;
            #elif defined( BRSHW_TIME_TIMERREGISTER_16BIT )
            gbBrsCtrlMsgBuffer[4] = 2;
            #elif defined( BRSHW_TIME_TIMERREGISTER_8BIT )
            gbBrsCtrlMsgBuffer[4] = 1;
            #else
              #error "Unknown time register size for time test support"
            #endif
            break;
        case 0x05:
            gbBrsCtrlMsgBuffer[4] = (vuint8) &BrsAddOnTimeData >> 24;
            gbBrsCtrlMsgBuffer[5] = (vuint8) &BrsAddOnTimeData >> 16;
            gbBrsCtrlMsgBuffer[6] = (vuint8) &BrsAddOnTimeData >>  8;
            gbBrsCtrlMsgBuffer[7] = (vuint8) &BrsAddOnTimeData;
            break;            
        #endif /* BRS_ENABLE_TIMETEST_FREETIMER */
        default:
            errorCode = BRSCTRL_ERROR_CNCORSE;
        }
        break;
    #if defined( BRS_ENABLE_TIMETEST_FREETIMER )
    case 0xF7:
        errorCode = BrsAddOnTimeSetResponse(gbBrsCtrlMsgBuffer[5]);
        break;
    #endif /* BRS_ENABLE_TIMETEST_FREETIMER */
    #endif /*BRS_ENABLE_TIMETEST*/
    default:
        errorCode = BRSCTRL_ERROR_CNCORSE;
    }
/*lint -restore */

    return errorCode;
}
#endif /*BRS_ENABLE_TESTCONTROL*/


#if defined( BRS_ENABLE_TIMETEST )
 #if defined( BRS_ENABLE_TIMETEST_FREETIMER )
/*******************************************************************************/
/**
 * \brief  Return free running timer resolution
 *         This function is called each time the TCC receives a request 
 *         about the resolution of the Free Running Timer. It is called in BRS 
 *         precopy function (ISR context!).
 *
 * \retval ErrorCode
 *
 * \pre    The TestControlCenter and the module has to be initialized and ready
 */
vuint8 BrsAddOnTimeFRTNsResolution(
   void
)
{
    vuint8  errorCode = 0;
    vuint16 resolution;

    switch ( gbBrsCtrlMsgBuffer[4]) {
    case 0xF2:
      #if defined( BrsHwFRTNsResolution )
        resolution = BrsHwFRTNsResolution();
      #else
        resolution = 0;
      #endif

        gbBrsCtrlMsgBuffer[4] = (vuint8)(resolution >> 8);
        gbBrsCtrlMsgBuffer[5] = (vuint8)(resolution);
        break;
    default:
        errorCode = BRSCTRL_ERROR_CNCORSE;
    }

    return errorCode;
}
 #endif /*BRS_ENABLE_TIMETEST_FREETIMER*/
#endif /*BRS_ENABLE_TIMETEST*/


#if defined( BRS_ENABLE_TIMETEST )
 #if defined( BRS_ENABLE_TIMETEST_FREETIMER )
/*******************************************************************************/
/**
 * \brief Return free running timer measurment response
 *        The TestControlCenter (TCC) is used to answer the tester request for 
 *        the time mark settings.
 *
 * \param  TimeStampMark is number of the time stamp mark to be written in the answer
 *
 * \retval ErrorCode
 *
 * \pre    The TestControlCenter and the module has to be initialized and ready
 */
static vuint8 BrsAddOnTimeSetResponse(
   vuint8 TimeStampMark
)
{
  vuint8 errorCode = 0;
  vuint8 read32bitVal = gbBrsCtrlMsgBuffer[7];

  if (TimeStampMark < BRS_TIMETEST_COUNT) {

    /** Guarantee the data consistency for the time measurement data in the transmit 
    *   message buffer by disabling all ISRs */
    BrsHwDisableInterrupt();
  
    gbBrsCtrlMsgBuffer[4] = (vuint8)(BrsAddOnTimeData[TimeStampMark].MaxTime >> 8);
    gbBrsCtrlMsgBuffer[5] = (vuint8)(BrsAddOnTimeData[TimeStampMark].MaxTime);
    gbBrsCtrlMsgBuffer[6] = (vuint8)(BrsAddOnTimeData[TimeStampMark].MinTime >> 8);
    gbBrsCtrlMsgBuffer[7] = (vuint8)(BrsAddOnTimeData[TimeStampMark].MinTime);
    
    /** Clear the up to now stored values for a new measurement cycle ... */
    #if defined( BRSHW_TIME_TIMERREGISTER_32BIT )
    if (0 != read32bitVal)
    {
      BrsAddOnTimeData[TimeStampMark].MinTime >>= 16;
      BrsAddOnTimeData[TimeStampMark].MaxTime >>= 16;
    }
    else /* defined( BRSHW_TIME_TIMERREGISTER_32BIT ) */
    #endif
    {
      BrsAddOnTimeData[TimeStampMark].MinTime = (tBrsAddOnTimerSize)0xFFFF;
      BrsAddOnTimeData[TimeStampMark].MaxTime = 0;
    }
  
    /** Transmit message buffer is consistent now, enable ISRs and send the message to the bus */
    BrsHwRestoreInterrupt();
  }
  else {
    errorCode    
  }
  return 
}
 #endif /*BRS_ENABLE_TIMETEST_FREETIMER*/
#endif /*BRS_ENABLE_TIMETEST*/


/*******************************************************************************/
/**
 * \brief  Initialize runtime timing measurement buffer
 *
 * \pre    This function has to be used to initialize the timing measurement 
 *         buffer for runtime measurement via ERIC, free running timer or scope.
 *         This is NOT the reset for the TCC test time counter!
 */
void BrsAddOnResetTime( 
  void 
)
{
#if defined( BRS_ENABLE_TIMETEST )
 #if defined( BRS_ENABLE_TIMETEST_FREETIMER )
  {
   vuint8 i = 0;

   for (i = 0; i<BRS_TIMETEST_COUNT; i++) {
    BrsAddOnTimeData[i].StartTime = 0;
    BrsAddOnTimeData[i].StopTime  = 0;
    BrsAddOnTimeData[i].MinTime   = (tBrsAddOnTimerSize)0xFFFF;
    BrsAddOnTimeData[i].MaxTime   = 0;
   }
  }
  bBrsAddOnTimeAnswerPending = 0;
  bBrsAddOnTimeStampNumber   = 0;
 #endif /*BRS_ENABLE_TIMETEST_FREETIMER*/
#endif /* BRS_ENABLE_TIMETEST */
}

/*******************************************************************************/
/**
 * \brief Calculate checksum over memory area
 *        This function calculates the checksum of a given Memory Range
 *
 * \param[in] wMsglength  Length of message to use for checksum calculation
 * \param[in] bpDataBuff  Dataptr to memory range
 *
 * \retval result of checksum calculation
 */
vuint8 BrsAddOnCalcCheckSum(
  vuint16 wMsglength, 
  vuint8* bpDataBuff
)
{
  vuint8 *bpBuf;
  vuint8 bResultCheckSum;
  vuint16 wLoopCnt;

  bpBuf = bpDataBuff;
  bResultCheckSum = 0;
        
  for( wLoopCnt=0; wLoopCnt<wMsglength; wLoopCnt++ ) {
    bResultCheckSum ^= (vuint8)(*bpBuf + wLoopCnt);
    bpBuf++;
  }

  return bResultCheckSum;
}


/*******************************************************************************/
/**
 * \brief  BrsAddOnResetTestTime resets the test time counter
 *
 * \attention The test time counter may be reset by any user at any time! 
 *            It is implemented as a simple 16 bit counter with a resolution similar
 *            to the BrsMain 1ms function. I.e. it will count 65536 [ms] since the 
 *            test starts and will restart with 0 again!
 */
void BrsAddOnResetTestTime( 
  void
)
{
  gwBrsAddOnTestRunTime = 0;
}

/*******************************************************************************/
/**
 * \brief  BrsAddOnGetTestTime returns the current value of the test time counter
 *
 * \retval The current value of the 1ms incremented counter gwBrsAddOnTestRunTime
 *         is returned to the caller.
 *
 * \attention The test time counter may be reset by any user at any time! 
 *            It is implemented as a simple 16 bit counter with a resolution similar
 *            to the BrsMain 1ms function. I.e. it will count 65536 [ms] since the 
 *            test starts and will restart with 0 again!
 */
vuint16 BrsAddOnGetTestTime( 
  void
)
{
  return gwBrsAddOnTestRunTime;
}

/*******************************************************************************/
/**
 * \brief  BrsAddOnClearEventHistory is used to clear the event history buffer.
 *
 * \attention It is strongly recommended to call this function on MAIN level only!
 */
void BrsAddOnClearEventHistory( 
  void
)
{
  for( bBrsAddOnNumOfStoredEvents=0; bBrsAddOnNumOfStoredEvents<BRSADDON_MAX_EVENT_SAMPLES; bBrsAddOnNumOfStoredEvents++ )  {
    sBrsAddOnEventSample[bBrsAddOnNumOfStoredEvents].wEventTime   = 0xFFFF; 
    sBrsAddOnEventSample[bBrsAddOnNumOfStoredEvents].wYourState   = 0xFFFF; 
    sBrsAddOnEventSample[bBrsAddOnNumOfStoredEvents].bCI          = 0xFF; 
    sBrsAddOnEventSample[bBrsAddOnNumOfStoredEvents].bYourEvent   = 0xFF; 
  }
  bBrsAddOnNumOfStoredEvents = 0;
}


/*******************************************************************************/
/**
 * \brief  BrsAddOnGetNrOfEventsInHistory is used to access the currently 
 *         stored numbers of events in the history buffer.
 *
 * \retval The number of stored events in the history buffer is returned.
 */
vuint8 BrsAddOnGetNrOfEventsInHistory( 
  void
)
{
  return bBrsAddOnNumOfStoredEvents;
}


/*******************************************************************************/
/**
 * \brief  BrsAddOnStoreEvent is used to store any event necessary for testing.
 *
 * \param  CI = Component ID, see BRS TCC documentation
 * \param  YourState = CI specific definiton of current state
 * \param  YourEvent = CI specific definiton of event
 *
 * \pre    The event is stored together with the current test time.
 */
void BrsAddOnStoreEvent( 
  vuint8  CI,
  vuint16 YourState,
  vuint8  YourEvent
)
{
  if( bBrsAddOnNumOfStoredEvents<BRSADDON_MAX_EVENT_SAMPLES ) {
    sBrsAddOnEventSample[bBrsAddOnNumOfStoredEvents].wEventTime = gwBrsAddOnTestRunTime;
    sBrsAddOnEventSample[bBrsAddOnNumOfStoredEvents].wYourState = YourState; 
    sBrsAddOnEventSample[bBrsAddOnNumOfStoredEvents].bCI        = CI;
    sBrsAddOnEventSample[bBrsAddOnNumOfStoredEvents].bYourEvent = YourEvent;
    bBrsAddOnNumOfStoredEvents++;
  }
}

/*******************************************************************************/
/**
 * \brief  BrsAddOnGetEvent is used to get any event that was stored in
 * BrsAddOnEventHistory before.
 * \param  GetEventPointerToTestStruct = Pointer to a structure in the test application
 * which has the type tBrsAddOnEventHistory
 * \param  EventNumber = Number of the stored event
 * \retval 1 if EventNumber is valid, 0 if it is invalid
*/

vuint8 BrsAddOnGetEvent(tBrsAddOnEventHistory* GetEventPointerToTestStruct, vuint8 EventNumber)
{
  vuint8 ret;
  ret = 0;
  if( EventNumber < BRSADDON_MAX_EVENT_SAMPLES ) {
    GetEventPointerToTestStruct->bCI=sBrsAddOnEventSample[EventNumber].bCI;
    GetEventPointerToTestStruct->bYourEvent=sBrsAddOnEventSample[EventNumber].bYourEvent;
    GetEventPointerToTestStruct->wEventTime=sBrsAddOnEventSample[EventNumber].wEventTime;
    GetEventPointerToTestStruct->wYourState=sBrsAddOnEventSample[EventNumber].wYourState;
    ret	=	1;
  }
  return ret;
}


/*******************************************************************************/
/**
 * \brief  BrsAddOnClearWarningHistory is used to clear the warning history buffer.
 *
 * \attention It is strongly recommended to call this function on MAIN level only!
 */
void BrsAddOnClearWarningHistory( 
  void
)
{
  for( bBrsAddOnNumOfStoredWarnings=0; bBrsAddOnNumOfStoredWarnings<BRSADDON_MAX_WARNING_SAMPLES; bBrsAddOnNumOfStoredWarnings++ )  {
    sBrsAddOnWarningSample[bBrsAddOnNumOfStoredWarnings].wEventTime       = 0xFFFF; 
    sBrsAddOnWarningSample[bBrsAddOnNumOfStoredWarnings].wYourState       = 0xFFFF; 
    sBrsAddOnWarningSample[bBrsAddOnNumOfStoredWarnings].bCI              = 0xFF; 
    sBrsAddOnWarningSample[bBrsAddOnNumOfStoredWarnings].bYourWarningCode = 0xFF; 
  }
  bBrsAddOnNumOfStoredWarnings = 0;
}


/*******************************************************************************/
/**
 * \brief  BrsAddOnGetNrOfWarningsInHistory is used to access the currently 
 *         stored numbers of warnings in the history buffer.
 *
 * \retval The number of stored warnings in the history buffer is returned.
 */
vuint8 BrsAddOnGetNrOfWarningsInHistory( 
  void
)
{
  return bBrsAddOnNumOfStoredWarnings;
}


/*******************************************************************************/
/**
 * \brief  BrsAddOnStoreWarning is used to store any warning detected during testing.
 *
 * \param  CI = Component ID, see BRS TCC documentation
 * \param  YourState = CI specific definiton of current state
 * \param  YourWarningCode = CI specific definiton of warning code
 *
 * \pre    The warning is stored together with the current test time.
 */
void BrsAddOnStoreWarning( 
  vuint8  CI,
  vuint16 YourState,
  vuint8  YourWarningCode
)
{
  if( bBrsAddOnNumOfStoredWarnings<BRSADDON_MAX_WARNING_SAMPLES ) {
    sBrsAddOnWarningSample[bBrsAddOnNumOfStoredWarnings].wEventTime         = gwBrsAddOnTestRunTime;
    sBrsAddOnWarningSample[bBrsAddOnNumOfStoredWarnings].wYourState       = YourState;
    sBrsAddOnWarningSample[bBrsAddOnNumOfStoredWarnings].bCI              = CI;
    sBrsAddOnWarningSample[bBrsAddOnNumOfStoredWarnings].bYourWarningCode = YourWarningCode;
    bBrsAddOnNumOfStoredWarnings++;
  }
}


/*******************************************************************************/
/**
 * \brief  BrsAddOnClearErrorHistory is used to clear the error history buffer.
 *
 * \attention It is strongly recommended to call this function on MAIN level only!
 */
void BrsAddOnClearErrorHistory( 
  void
)
{
  for( bBrsAddOnNumOfStoredErrors=0; bBrsAddOnNumOfStoredErrors<BRSADDON_MAX_ERROR_SAMPLES; bBrsAddOnNumOfStoredErrors++ )  {
    sBrsAddOnErrorSample[bBrsAddOnNumOfStoredErrors].wEventTime     = 0xFFFF;
    sBrsAddOnErrorSample[bBrsAddOnNumOfStoredErrors].wYourState     = 0xFFFF;
    sBrsAddOnErrorSample[bBrsAddOnNumOfStoredErrors].bCI            = 0xFF;
    sBrsAddOnErrorSample[bBrsAddOnNumOfStoredErrors].bYourErrorCode = 0xFF;
  }
  bBrsAddOnNumOfStoredErrors = 0;
}


/*******************************************************************************/
/**
 * \brief  BrsAddOnGetNrOfErrorsInHistory is used to access the currently 
 *         stored numbers of errors in the history buffer.
 *
 * \retval The number of stored errors in the history buffer is returned.
 */
vuint8 BrsAddOnGetNrOfErrorsInHistory( 
  void
)
{
  return bBrsAddOnNumOfStoredErrors;
}


/*******************************************************************************/
/**
 * \brief  BrsAddOnStoreError is used to store any error detected during testing.
 *
 * \param[in] CI = Component ID, see BRS TCC documentation
 * \param[in] YourState = CI specific definiton of current state
 * \param[in] YourErrorCode = CI specific definiton of error code
 *
 * \pre    The error is stored together with the current test time.
 */
void BrsAddOnStoreError( 
  vuint8  CI,
  vuint16 YourState,
  vuint8  YourErrorCode
)
{
  if( bBrsAddOnNumOfStoredErrors<BRSADDON_MAX_ERROR_SAMPLES ) {

    sBrsAddOnErrorSample[bBrsAddOnNumOfStoredErrors].wEventTime     = gwBrsAddOnTestRunTime;
    sBrsAddOnErrorSample[bBrsAddOnNumOfStoredErrors].wYourState     = YourState;
    sBrsAddOnErrorSample[bBrsAddOnNumOfStoredErrors].bCI            = CI;
    sBrsAddOnErrorSample[bBrsAddOnNumOfStoredErrors].bYourErrorCode = YourErrorCode;
    bBrsAddOnNumOfStoredErrors++;
  }
}

#if defined( BRS_ENABLE_TESTCONTROL )
/*******************************************************************************/
/**
 * \brief  BrsAddOnReadHistoryBufferInBrsCmd reads the currently requested entry
 *         in the BRS history buffer.
 *
 * \retval The error code notifies the BRS command handler if the answer is 
 *         already filled out or a TCC error code shall be send to the tester.
 *
 * \attention  Do NOT call this API within your test code! It is just used within 
 *             the BrsCtrl to access the local data!
 */
vuint8 BrsAddOnReadHistoryBufferInBrsCmd( 
  void 
)
{
  vuint8  errorCode = 0;
  vuint8  tempIndex = gbBrsCtrlMsgBuffer[7];
  vuint8  tempCI = 0;
  vuint16 tempVal = 0;

  /** Check for 0x10YY; YY is stored in gbBrsCtrlMsgBuffer[5] */
  /** Content of Req[4] is already in Resp[2] and Req[5] is in Resp[3],
   * so just do the data job here. gbBrsCtrlMsgBuffer[7] holds the
   * requested index within the array of interesst. */
  switch( gbBrsCtrlMsgBuffer[5] ) {
    case 0x00:
      gbBrsCtrlMsgBuffer[4] = bBrsAddOnNumOfStoredWarnings;
      gbBrsCtrlMsgBuffer[5] = bBrsAddOnNumOfStoredErrors;
      gbBrsCtrlMsgBuffer[6] = bBrsAddOnNumOfStoredEvents;
      gbBrsCtrlMsgBuffer[7] = 0x00;   
      /* set error code to value which is not used within this function. 
         will be reset before return */
      errorCode = 0x80;
      break;
    /* WARNING ACCESS */
    case 0x10:
      if( tempIndex<bBrsAddOnNumOfStoredWarnings ) {
        tempVal = sBrsAddOnWarningSample[ tempIndex ].wEventTime;
        tempCI  = sBrsAddOnWarningSample[ tempIndex ].bCI;
      } else {
        errorCode = BRSCTRL_ERROR_IMLOIF;
      }
      break;
    case 0x11:
      if( tempIndex<bBrsAddOnNumOfStoredWarnings ) {
        tempVal = sBrsAddOnWarningSample[ tempIndex ].wYourState;
        tempCI  = sBrsAddOnWarningSample[ tempIndex ].bCI;
      } else {
        errorCode = BRSCTRL_ERROR_IMLOIF;
      }
      break;
    case 0x12:
      if( tempIndex<bBrsAddOnNumOfStoredWarnings ) {
        tempVal = sBrsAddOnWarningSample[ tempIndex ].bYourWarningCode;
        tempCI  = sBrsAddOnWarningSample[ tempIndex ].bCI;
      } else {
        errorCode = BRSCTRL_ERROR_IMLOIF;
      }
      break;
    /* ERROR ACCESS */
    case 0x20:
      if( tempIndex<bBrsAddOnNumOfStoredErrors ) {
        tempVal = sBrsAddOnErrorSample[ tempIndex ].wEventTime;
        tempCI  = sBrsAddOnErrorSample[ tempIndex ].bCI;
      } else {
        errorCode = BRSCTRL_ERROR_IMLOIF;
      }
      break;
    case 0x21:
      if( tempIndex<bBrsAddOnNumOfStoredErrors ) {
        tempVal = sBrsAddOnErrorSample[ tempIndex ].wYourState;
        tempCI  = sBrsAddOnErrorSample[ tempIndex ].bCI;
      } else {
        errorCode = BRSCTRL_ERROR_IMLOIF;
      }
      break;
    case 0x22:
      if( tempIndex<bBrsAddOnNumOfStoredErrors ) {
        tempVal = sBrsAddOnErrorSample[ tempIndex ].bYourErrorCode;
        tempCI  = sBrsAddOnErrorSample[ tempIndex ].bCI;
      } else {
        errorCode = BRSCTRL_ERROR_IMLOIF;
      }
      break;
    /* EVENT ACCESS */
    case 0x30:
      if( tempIndex<bBrsAddOnNumOfStoredEvents ) {
        tempVal = sBrsAddOnEventSample[ tempIndex ].wEventTime;
        tempCI  = sBrsAddOnEventSample[ tempIndex ].bCI;
      } else {
        errorCode = BRSCTRL_ERROR_IMLOIF;
      }
      break;
    case 0x31:
      if( tempIndex<bBrsAddOnNumOfStoredEvents ) {
        tempVal = sBrsAddOnEventSample[ tempIndex ].wYourState;
        tempCI  = sBrsAddOnEventSample[ tempIndex ].bCI;
      } else {
        errorCode = BRSCTRL_ERROR_IMLOIF;
      }
      break;
    case 0x32:
      if( tempIndex<bBrsAddOnNumOfStoredEvents ) {
        tempVal = sBrsAddOnEventSample[ tempIndex ].bYourEvent;
        tempCI  = sBrsAddOnEventSample[ tempIndex ].bCI;
      } else {
        errorCode = BRSCTRL_ERROR_IMLOIF;
      }
      break;

    default:
      /* Send negative response now */
      errorCode = BRSCTRL_ERROR_SNS;
      break;
  }

  if( errorCode==0 ) {
    gbBrsCtrlMsgBuffer[4] = (vuint8)(tempVal>>8);
    gbBrsCtrlMsgBuffer[5] = (vuint8)(tempVal);
    gbBrsCtrlMsgBuffer[6] = tempCI;
    /** gbBrsCtrlMsgBuffer[7] stays unchanged and holds the requested index! */
  }
  else {
    errorCode &= 0x7F;
  }
  return errorCode;
}
#endif /*BRS_ENABLE_TESTCONTROL*/


/*******************************************************************************/
/**
 * \brief  BrsAddOnClearMsExceed is used to clear variable gwBrsAddOnTestMsExceed.
 */
void BrsAddOnClearMsExceed( 
  void
)
{
  gwBrsAddOnTestMsExceed = 0;
}


/*******************************************************************************/
/**
 * \brief  BrsAddOnIncMsExceed is used to increment variable gwBrsAddOnTestMsExceed.
 */
void BrsAddOnIncMsExceed( 
  void
)
{
  gwBrsAddOnTestMsExceed++;
}


/*******************************************************************************/
/**
 * \brief  BrsAddOnGetMsExceed is used to get the value of variable
 *         gwBrsAddOnTestMsExceed.
 */
vuint16 BrsAddOnGetMsExceed( 
  void
)
{
  return gwBrsAddOnTestMsExceed;
}



/****************************************************************************
 * All handling above this line is only enabled if the BrsAddOn is enabled!
 *****************************************************************************/
#endif /*BRS_ENABLE_TESTADDON*/
/************   Organi, Version 3.6.8 Vector-Informatik GmbH  ************/
