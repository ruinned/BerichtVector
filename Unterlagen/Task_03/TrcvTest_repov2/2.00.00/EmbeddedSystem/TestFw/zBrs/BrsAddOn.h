/*  *****   STARTSINGLE_OF_MULTIPLE_COMMENT    *****  */




/*****************************************************************************/
/**
 * \file    BrsAddOn.H
 * \brief   Basic Runtime System addons, Header
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
 * Check up BrsAddOn.c for description, author and history
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

#ifndef _BRSADDON_H_
#define _BRSADDON_H_

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
 * Description: This is the BRS AddOn support main and release version.
 *              The version numbers are BCD coded. E.g. a main version of 1.23 is
 *              coded with 0x0123, a release version of 9 is coded 0x09.
 */
/* ##V_CFG_MANAGEMENT ##CQProject : Brs_AddOn CQComponent : Implementation */
#define BRS_ADDON_VERSION          0x0304
#define BRS_ADDON_RELEASE_VERSION  0x01

#define BRSADDON_VERSION        BRS_ADDON_VERSION
#define BRSADDON_BUGFIX_VERSION BRS_ADDON_RELEASE_VERSION


/****************************************************************************/
#if defined( BRS_ENABLE_TESTADDON )
/*****************************************************************************
 * All handling below this line (execpt the export of the version constants)
 * is only enabled if the BrsAddOnis enabled!
 *****************************************************************************/

#if defined( BRS_ENABLE_TIMETEST )
 /*
  * Description: The BrsHw header provides all the necessary interfaces to
  *              the hardware specific files. Here it is especially for the
  *              time measurement support.
  *              This file is part of the BRS.
  */
 #include "BrsHw.H"
#endif /*BRS_ENABLE_TIMETEST*/

/*******************************************************************************
* Global typedefs
*******************************************************************************/
typedef struct stBrsAddOnEventHistory {
  vuint16 wEventTime;
  vuint16 wYourState;
  vuint8  bCI;
  vuint8  bYourEvent;
} tBrsAddOnEventHistory;

#if defined( BRS_ENABLE_TIMETEST )
 #if defined( BRS_ENABLE_TIMETEST_FREETIMER )

  #if defined( BRSHW_TIME_TIMERREGISTER_32BIT )
  typedef vuint32 tBrsAddOnTimerSize;
  #elif defined( BRSHW_TIME_TIMERREGISTER_16BIT )
  typedef vuint16 tBrsAddOnTimerSize;
  #elif defined( BRSHW_TIME_TIMERREGISTER_8BIT )
  typedef vuint8 tBrsAddOnTimerSize;
  #else
  #error "Unknown time register size for time test support"
  #endif
 /*
  * Description: Used only, if the  BRS time measurement support for "FREETIMER" is
  *              enabled. The size of the time stamp array is adopted to the 
  *              hardware specific time register size.
  */
  typedef struct {
   tBrsAddOnTimerSize StartTime;
   tBrsAddOnTimerSize StopTime;
   tBrsAddOnTimerSize MinTime;
   tBrsAddOnTimerSize MaxTime;
  } tBrsAddOnTimes;

 #endif /*BRS_ENABLE_TIMETEST_FREETIMER*/
#else
/* None used */
#endif /*BRS_ENABLE_TIMETEST*/

 
/*******************************************************************************
* Global defines
*******************************************************************************/
#if defined( BRS_ENABLE_TIMETEST )

 #if defined( BRS_ENABLE_TIMETEST_FREETIMER )
  #define BRSHW_TIME_STAMP_START(a)  { tBrsAddOnTimerSize val; BrsHwTimeGetFreeRunCounterValue(); BrsAddOnTimeData[(a)].StartTime = val; }
  #define BRSHW_TIME_STAMP_STOP(a)   { tBrsAddOnTimerSize val; BrsHwTimeGetFreeRunCounterValue(); BrsAddOnTimeData[(a)].StopTime = val; BrsAddOnTimeCalculate(a); }
 /*
  * Description: Pre- and postfix ports have to be added by the tool due to the 
  *              additional selection of ISR locks during the measurement.
  */
 #elif defined( BRS_ENABLE_TIMETEST_SCOPE )
  #define BRSHW_TIME_STAMP_START(a)  BrsHwTimeSetPortPin(a)
  #define BRSHW_TIME_STAMP_STOP(a)   BrsHwTimeClrPortPin(a)
 /*
  * Description: Up to 8 different time stamps are supported.
  */
 #elif defined( BRS_ENABLE_TIMETEST_PC )
  #define BRSHW_TIME_STAMP_START(a)  BrsHwTimeSetPort((a<<1)|1); BRSHW_TIME_STAMP_DELAY; BrsHwTimeSetPort((a<<1));
  #define BRSHW_TIME_STAMP_STOP(a)   BrsHwTimeSetPort((a<<1)|1); BRSHW_TIME_STAMP_DELAY; BrsHwTimeSetPort((a<<1));
 /*
  * Description: Up to 127 different time stamps are supported.
  */
 #else
  #error "Incorrect setting for time measurement support detected"
 #endif
 
#else /*BRS_ENABLE_TIMETEST*/
/* None used */
#endif /*BRS_ENABLE_TIMETEST*/

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
* Global typedefs
*******************************************************************************/


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
  extern volatile tBrsAddOnTimes BrsAddOnTimeData[BRS_TIMETEST_COUNT+1];

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
extern volatile vuint16 gwBrsAddOnTestRunTime;


/****************************************************************************
 * All handling above this line is only enabled if the BrsAddOn is enabled!
 * This is a "temporary enable" only to export the version constants!
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
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kBrsAddOnMainVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kBrsAddOnSubVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kBrsAddOnReleaseVersion;

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
  );


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
   );
 #endif /*BRS_ENABLE_TIMETEST_FREETIMER*/
#endif /*BRS_ENABLE_TIMETEST*/


#if defined( BRS_ENABLE_TIMETEST )
#  if defined( BRS_ENABLE_TIMETEST_FREETIMER )
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
  );
#  endif /* BRS_ENABLE_TIMETEST_FREETIMER */
#endif /*BRS_ENABLE_TIMETEST*/

#if defined( BRS_ENABLE_TIMETEST )
#  if defined( BRS_ENABLE_TIMETEST_FREETIMER )
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
static void BrsAddOnTimeSetResponse(
  vuint8 TimeStampMark
  );
#  endif /*BRS_ENABLE_TIMETEST_FREETIMER*/
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
  );

#if defined( BRS_ENABLE_TESTCONTROL )
/*******************************************************************************/
/**
 * \brief BrsAddOn time measurement command interpreter
 * \pre   The TestControlCenter and the module has to be initialized 
 *        and ready
 *
 * This function is called each time the TCC receives a time 
 * measurement request. It has to interpret the request and 
 * to answer immediately or ASAP.
 * The function is always available to prevent linker errors
 * and to much preprocessor checks in the TCC. It is called in BRS 
 * precopy function (ISR context!).
 */
vuint8 BrsAddOnTimeCmdInterpreter(
   void
   );
#endif /*BRS_ENABLE_TESTCONTROL*/


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
  );

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
  );

/*******************************************************************************/
/**
 * \brief  BrsAddOnGetTestTime returns the current value of the test time counter
 *
 * \attention The test time counter may be reset by any user at any time! 
 *            It is implemented as a simple 16 bit counter with a resolution similar
 *            to the BrsMain 1ms function. I.e. it will count 65536 [ms] since the 
 *            test starts and will restart with 0 again!
 */
vuint16 BrsAddOnGetTestTime( 
  void
  );

/*******************************************************************************/
/**
 * \brief  BrsAddOnClearEventHistory is used to clear the event history buffer.
 *
 * \attention It is strongly recommended to call this function on MAIN level only!
 */
void BrsAddOnClearEventHistory( 
  void
  );


/*******************************************************************************/
/**
 * \brief  BrsAddOnGetNrOfEventsInHistory is used to access the currently 
 *         stored numbers of events in the history buffer.
 */
vuint8 BrsAddOnGetNrOfEventsInHistory( 
  void
  );


/*******************************************************************************/
/**
 * \brief  BrsAddOnStoreEvent is used to store any event necessary for testing.
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
  );

/*******************************************************************************/
/**
 * \brief  BrsAddOnGetEvent is used to get any event that was stored in
 * BrsAddOnEventHistory before.
 * \param  GetEventPointer = Pointer to a Structure in the test application
 * which has same layout as structure stBrsAddOnEventHistory
 * \param  EventNumber = Number of the stored event
*/
vuint8 BrsAddOnGetEvent(
  tBrsAddOnEventHistory* GetEventPointerToTestStruct,
  vuint8 EventNumber
  ); 


/*******************************************************************************/
/**
 * \brief  BrsAddOnClearWarningHistory is used to clear the warning history buffer.
 *
 * \attention It is strongly recommended to call this function on MAIN level only!
 */
void BrsAddOnClearWarningHistory( 
  void
  );


/*******************************************************************************/
/**
 * \brief  BrsAddOnGetNrOfWarningsInHistory is used to access the currently 
 *         stored numbers of warnings in the history buffer.
 *
 * \retval The number of stored warnings in the history buffer is returned.
 */
vuint8 BrsAddOnGetNrOfWarningsInHistory( 
  void
  );


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
  );


/*******************************************************************************/
/**
 * \brief  BrsAddOnClearErrorHistory is used to clear the error history buffer.
 *
 * \attention It is strongly recommended to call this function on MAIN level only!
 */
void BrsAddOnClearErrorHistory( 
  void
  );


/*******************************************************************************/
/**
 * \brief  BrsAddOnGetNrOfErrorsInHistory is used to access the currently 
 *         stored numbers of errors in the history buffer.
 *
 * \retval The number of stored errors in the history buffer is returned.
 */
vuint8 BrsAddOnGetNrOfErrorsInHistory( 
  void
  );


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
  );


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
  );


/*******************************************************************************/
/**
 * \brief  BrsAddOnClearMsExceed is used to clear variable gwBrsAddOnTestMsExceed.
 */
void BrsAddOnClearMsExceed( 
  void
);


/*******************************************************************************/
/**
 * \brief  BrsAddOnIncMsExceed is used to increment variable gwBrsAddOnTestMsExceed.
 */
void BrsAddOnIncMsExceed( 
  void
);


/*******************************************************************************/
/**
 * \brief  BrsAddOnGetMsExceed is used to get the value of variable
 *         gwBrsAddOnTestMsExceed.
 */
vuint16 BrsAddOnGetMsExceed( 
  void
);



/****************************************************************************
 * All handling above this line is only enabled if the BrsAddOn is enabled!
 *****************************************************************************/
#endif /*BRS_ENABLE_TESTADDON*/
/*****************************************************************************/

#endif /*_BRSADDON_H_*/
/************   Organi, Version 3.6.8 Vector-Informatik GmbH  ************/
