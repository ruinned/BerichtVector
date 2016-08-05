/*  *****   STARTSINGLE_OF_MULTIPLE_COMMENT    *****  */




/*****************************************************************************
/**
 * @file    BrsHW.H
 * @brief   Basic Runtime System, HW specific file, Header
 *          This file encapsulates all hardware specific functions from the user.
 *          This includes management of common functions like power and PLL control,
 *          board specific LED and key support and management of used ports and the
 *          generation of the 1ms time base interrupt.
 *           
 *          This file supports osCAN with CANoe; Compiler is Visual C++
 *
 *  Check up BrsHw.c for description, author and history
 *  Version info: see BRSHW_VERSION, BRSHW_BUGFIX_VERSION
 *
 * @attention Please note:
 *  The demo and example program only shows special aspects of the software. 
 *  With regard to the fact that this program is meant for demonstration purposes 
 *  Vector Informatik´s liability shall be expressly excluded in cases of 
 *  ordinary negligence, to the extent admissible by law or statute. 
 *
 *****************************************************************************
 *               C O P Y R I G H T
 *****************************************************************************
 * Copyright (c) 2004 by Vector Informatik GmbH.      All rights reserved.
 *
 *                    Alle Rechte an der Software verbleiben bei der
 *                    Vector Informatik GmbH.
 *                    Vector Informatik GmbH räumt dem Lizenznehmer das unwider-
 *                    rufliche, geographisch und zeitlich nicht beschränkte,
 *                    jedoch nicht ausschließliche Nutzungsrecht innerhalb des
 *                    Lizenznehmers ein. Die Weitergabe des Nutzungsrechts
 *                    durch den Lizenznehmers ist auf dessen Zulieferer
 *                    beschränkt. Die Zulieferer sind zu verpflichten, die
 *                    Software nur im Rahmen von Projekten für den Lizenznehmer
 *                    zu verwenden; weitere Rechte der Zulieferer sind
 *                    auszuschließen.
 *****************************************************************************/

#ifndef _BRSHW_H_
#define _BRSHW_H_

/*******************************************************************************
* Module version
*******************************************************************************/
/*
 * Description: This is the BRS Test control center main and bug fix version. The 
 *              version numbers are BCD coded. E.g. a main version of 1.23 is 
 *              coded with 0x0123, a bug fix version of 9 is coded 0x09.
 */
#if defined( C_KOMMENTAR_VECTOR )
 /* CANbedded developers: Change the version numbers as specified for CANbedded modules. The
 *  first release of a file should have the version 0x0100 and bugfix version 0x00. Do not 
 *  forget to change the version number in the C file, too! */
#endif
#define BRSHW_VERSION        0x0106
#define BRSHW_BUGFIX_VERSION 0x06



/*******************************************************************************
* Global defines
*******************************************************************************/
/*
 * Description: Standard access to the supported LED. Values with a fix name should
 *              never be used for other purposes.
 */
#if defined( C_KOMMENTAR_VECTOR )
 /* CANbedded developers: This defines are hardware independent and must not be changed. */
#endif
#define BRSHW_LED_SYSTEM_OK   0
#define BRSHW_LED_1           1
#define BRSHW_LED_2           2
#define BRSHW_LED_3           3
#define BRSHW_LED_4           4
#define BRSHW_LED_5           5
#define BRSHW_LED_6           6
#define BRSHW_LED_7           7


/*
 * Description: On and Off value for argument 'NewState' in BrsHwSetLed.
 */
#if defined( C_KOMMENTAR_VECTOR )
 /* CANbedded developers: This defines are hardware independent and must not be changed. */
#endif
#define BRSHW_LED_ON          1
#define BRSHW_LED_OFF         0


/*
 * Description: This hardware platform supports a 16 bit free running timer for
 *              time measuring purposes.
 */
#if defined( C_KOMMENTAR_VECTOR )
 /* CANbedded developers: adopt this define to your hardware specific free running timer (this is
  * for the BRS time measurement support in the hardware independent files!)  */
#endif
#define BRSHW_TIME_TIMERREGISTER_16BIT


/*
 * Description: Hardware and compiler specific pre- and postfix code for the
 *              time measurement support. If there is no need for this, this
 *              has to be defined to nothing.
 */
#if defined( C_KOMMENTAR_VECTOR )
 /* CANbedded developers: adopt the defines for the to your hardware specific needs! This defines
  * are used for the time stamp generation via the time stamp setup tool (BrsTime.h) */
#endif
#define BRSHW_TIME_STAMP_PREFIX
#define BRSHW_TIME_STAMP_POSTFIX
#define BRSHW_TIME_STAMP_DELAY        asm nop;
 
 
/*
 * Description: The BrsCfg header is used to configure different types of
 *              tests and system setups. Therefore it must be included first
 *              in each BRS and test module.
 *              This file is part of the BRS.
 */
#if defined( C_KOMMENTAR_VECTOR )
 /* CANbedded developers: This include is hardware independent and must not be changed. */
#endif
#include "BrsCfg.H"

#if defined( BRS_ENABLE_TIMETEST )
  #if defined( C_KOMMENTAR_VECTOR )
  /*
   * Description: The BrsAddOn header is needet for TIME_STAMP_START/STOP 
   *              definitions
   */
  #endif
#include "BrsAddOn.h"
#endif
 
#if defined( C_KOMMENTAR_VECTOR )
/*
 * Description: The BrsTime header is used to configure the timing measurement
 *              part of the BRS.
 */
#endif
 
 

/*******************************************************************************
* Global variables
*******************************************************************************/
#if defined( C_KOMMENTAR_VECTOR )
 /* CANbedded developers: Specify your file specific extern/global variables used for the
  * time measurement support. See the APIs BrsHwTimeGetFreeRunCounterValue, BrsHwTimeSetPortPin,
  * BrsHwTimeClrPortPin and BrsHwTimeSetPort below for usage. Remember, that only the time
  * measurement support is allowed to use global variables and port access to runtime 
  * optimization! */
#endif


/*******************************************************************************
* Global const variables
*******************************************************************************/
/** 
 * @var kBrsMainMainVersion
 *      Stores the BCD coded main-version of this file.
 */
/**
 * @var kBrsMainSubVersion 
 *      Stores the BCD coded sub-version of this file.
 */
/** 
 * @var kBrsMainBugfixVersion 
 *      Stores the BCD coded release-version of this file.
 */
extern vuint8 MEMORY_ROM kBrsHwMainVersion;
extern vuint8 MEMORY_ROM kBrsHwSubVersion;
extern vuint8 MEMORY_ROM kBrsHwBugfixVersion;



/*******************************************************************************
* Globale function protoytpes
*******************************************************************************/
#if defined( C_KOMMENTAR_VECTOR )
 /* CANbedded developers: Function prototypes are hardware independent and must not be changed. */
#endif

/*******************************************************************************/
/**
 * @brief Hardware Initialization Routine
 *        Initialize hardware specific functions like PLL, power, IO-ports and other
 *        basic features.
 *
 * @pre   Must be called first of all init routines at power on
 *
 * @post  System is up and working
 */
void BrsHwHardwareInitPowerOn( 
  void 
);


/*******************************************************************************/
/**
 * @brief Initialization Routine for the time base clock
 *        Initialize timer generating the 1ms interrupt when there is no osCAN support.
 *
 * @pre   Must be called at power on, interrupt vector for 1ms interrupt must be correctly set.
 *
 * @post  Timenbase is initialized
 */
void BrsHwTimeBaseInitPowerOn(
  void
);


/*******************************************************************************
* NAME          : BrsHwDisableInterruptAtPowerOn
* CALLED BY     : main@BrsMain at power on initialization
* PRECONDITIONS : Must be the first function call in main@BrsMain
* PARAMETERS    : none
* RETURN VALUE  : none
* DESCRIPTION   : Disable the global system interrupt and initialize the INT 
*                 lock handler variables.
********************************************************************************/
void  BrsHwDisableInterruptAtPowerOn( 
  void 
);


/*******************************************************************************/
/**
 * @brief Routine to enable all interrupts during power on.
 *        Enable all interrupts.
 *
 * @pre   Must be called when all initializations are done
 */
void  BrsHwEnableInterruptAtPowerOn( 
  void 
);


/*******************************************************************************/
/**
 * @brief Routine to disable all interrupts
 * 
 * Disable all interrupts and store the state of the global INT flag into a local
 * variable when being called during "normal" operation. This state will be restored
 * when returning to normal operation.
 *
 * When detecting nested calls, i.e. one interrupt interrupts another, the state
 * needs not be saved.
 */
void BrsHwDisableInterrupt(
 void
);


/*******************************************************************************/
/**
 * @brief Routine to enable all interrupts
 * 
 * Restore the state of the global INT flag and enable all interrupts when returning
 * to "normal" operation.
 *
 * When returning from a nested call, the state must not be restored. When trying to
 * restore more often than having disabled, an exception will be raised and the system
 * will block.
 */
void BrsHwRestoreInterrupt(
 void
);


/*******************************************************************************/
/**
 * @brief Routine to control the software programmable LEDs on the EVA board
 * Switch a programmable LED on or off. BRS supports up to 8 LEDs depending on the
 * EVA board.
 *
 * @param[in] LedNumber may take any value in the range [0..7]. LED 0 is 
 *            reserved for system use, i.e. blinking to indicate a working system.
 * @param[in] NewState may take one of the predefined values BRSHW_LED_ON and 
 *            BRSHW_LED_OFF.
 */
void BrsHwSetLed(
  vuint8 LedNumber, 
  vuint8 NewState
);


/*******************************************************************************
/**
 * @brief Routine to check the state of all keys on the EVA board
 *
 * Check the state of all supported keys. Interpret the return value in the following
 * way:
 * - If key A is being pressed, bit 0 of the return value is 1, otherwise 0.
 * - If key B is being pressed, bit 1 of the return value is 1, otherwise 0.
 * - If key C is being pressed, bit 2 of the return value is 1, otherwise 0.
 * - If key D is being pressed, bit 3 of the return value is 1, otherwise 0.
 *
 * @retval Current state of all switches
 *
 * @attention This service is not supported for this platform and/or EVA board.
 */
vuint8 BrsHwCheckAllKeys(
  void
);


/*******************************************************************************/
/**
 * @brief Routine to check the state of key A on the EVA board
 * Check the state of key A, if supported. If key A is being pressed, the return
 * value is 1, otherwise 0.
 *
 * @retval Current state of the switch
 *
 * @attention This service is not supported for this platform and/or EVA board.
 */
vuint8 BrsHwCheckKeyA(
  void
);


/*******************************************************************************/
/**
 * @brief Routine to check the state of key B on the EVA board
 * Check the state of key B, if supported. If key B is being pressed, the return
 * value is 1, otherwise 0.
 *
 * @retval Current state of the switch
 *
 * @attention This service is not supported for this platform and/or EVA board.
 */
vuint8 BrsHwCheckKeyB(
  void
);


/*******************************************************************************/
/**
 * @brief Routine to check the state of key C on the EVA board
 * Check the state of key C, if supported. If key C is being pressed, the return
 * value is 1, otherwise 0.
 *
 * @retval Current state of the switch
 *
 * @attention This service is not supported for this platform and/or EVA board.
 */
vuint8 BrsHwCheckKeyC(
  void
);


/*******************************************************************************/
/**
 * @brief Routine to check the state of key D on the EVA board
 * Check the state of key D, if supported. If key D is being pressed, the return
 * value is 1, otherwise 0.
 *
 * @retval Current state of the switch
 *
 * @attention This service is not supported for this platform and/or EVA board.
 */
vuint8 BrsHwCheckKeyD(
  void
);


/*******************************************************************************/
/**
 * @brief Routine to measure the runtime of 100 NOP instructions
 *        This API is used for the BRS time measurement support to get a default
 *        time value for all measurments with this platform to be able to 
 *        compare time measurements on different dates based on this time result.
 *
 * @pre   Support for runtime measurement has to be enabled on the GenTool's BRS page.\n
 *        A valid measurement method has to be chosen in the BrsTimeGen tool.\n
 *        This file must have been organified with the option measure=1 in the [SPECIAL] section.
 */
void BrsHwTime100NOP(
  void
);


/*******************************************************************************
* NAME          : BrsHwSoftwareResetECU
* CALLED BY     : can driver testsuite
* PRECONDITIONS : none
* PARAMETERS    : none
* RETURN VALUE  : none
* DESCRIPTION   : restart ECU
********************************************************************************/
void BrsHwSoftwareResetECU( 
  void 
);


/*******************************************************************************
* Globale function like protoytpes/defines for optimization reason
*******************************************************************************/
#if defined( C_KOMMENTAR_VECTOR )
 /* CANbedded developers: Adopt the access to the 8 bit port used for the time
  * measurement support here! */
#endif

/*******************************************************************************
* NAME          : BrsHwTimeSetPort
* CALLED BY     : TimeMeasurement
* PRECONDITIONS : Time measurement with "PC" support is configured
* PARAMETERS    : New port value; see time measurement documentation for details.
* RETURN VALUE  : none
* DESCRIPTION   : This API is used for the BRS time measurement support. The
*                 function/macro supports the hardware port access for the
*                 measurement variants "PC".
********************************************************************************/
#define BrsHwTimeSetPort(val)


/*******************************************************************************
* NAME          : BrsHwTimeSetPortPin, BrsHwTimeClrPortPin
* CALLED BY     : TimeMeasurement
* PRECONDITIONS : Time measurement with "SCOPE" support is configured
* PARAMETERS    : New port pin value; see time measurement documentation for details.
* RETURN VALUE  : none
* DESCRIPTION   : This API is used for the BRS time measurement support. The
*                 function/macro supports the hardware port pin access for the
*                 measurement variants "SCOPE".
********************************************************************************/
#define BrsHwTimeSetPortPin(val)
#define BrsHwTimeClrPortPin(val)


/*******************************************************************************
* NAME          : BrsHwTimeGetFreeRunCounterValue
* CALLED BY     : TimeMeasurement
* PRECONDITIONS : Time measurement with "FREETIMER" support is configured
* PARAMETERS    : none
* RETURN VALUE  : New counter value. The variable 'val' must be defined!
* DESCRIPTION   : This API is used for the BRS time measurement support. The
*                 function/macro supports the hardware free running timer access 
*                 for the measurement variant "FREETIMER".
********************************************************************************/
#define BrsHwTimeGetFreeRunCounterValue() val = val



/*******************************************************************************
* Interrupt handler function protoytpes
*******************************************************************************/
#if defined( C_KOMMENTAR_VECTOR )
 /* CANbedded developers: The definition of the interrupt handler is hardware dependent and must
  * therefore be adopted to your compiler needs. It is possible to support more than one compiler
  * by the mean of ifdef and ORGANI. */
#endif

#if defined( BRS_ENABLE_OSEKOS )
/* This ISR function is not necessary if the OSEK OS is used! */
#else /*BRS_ENABLE_OSEKOS*/
/*******************************************************************************
* NAME          : BrsHwTimeBaseInterrupt
* CALLED BY     : Via interrupt vector table if the assigned timer has set its
*                 interrupt flag.
* PRECONDITIONS : none
* PARAMETERS    : none
* RETURN VALUE  : none
* DESCRIPTION   : Timer interrupt (PIT) for the 'FakeOS' 1ms time base generation.
********************************************************************************/
void BrsHwTimeBaseInterrupt(
 void
);
#endif /*BRS_ENABLE_OSEKOS*/


#if defined( VGEN_ENABLE_LIN_DRV ) 
/*******************************************************************************
* NAME          : BrsHwLinWakeupInterrupt
* CALLED BY     : External INT port if communication is detected on the LIN
* PRECONDITIONS : Node has to be waked up via the IN bus
* PARAMETERS    : none
* RETURN VALUE  : none
* DESCRIPTION   : If the node should be waked up via LIN, this port has to be
*                 connected to the LIN bus. A wakeup interrupt is called for
*                 detected communication. It is the job of the application to 
*                 start the LIN communication then.
********************************************************************************/
void BrsHwLinWakeupInterrupt(
 void
);
#endif /*VGEN_ENABLE_LIN_DRV*/


#if defined( VGEN_ENABLE_LIN_DRV ) 
/*******************************************************************************
* NAME          : BrsHwExtLinInterrupt
* CALLED BY     : --
* PRECONDITIONS : --
* PARAMETERS    : none
* RETURN VALUE  : none
* DESCRIPTION   : --
********************************************************************************/
void BrsHwExtLinInterrupt(
 void
);
#endif /*VGEN_ENABLE_LIN_DRV*/



/*******************************************************************************
* NAME          : BrsHwDummyInterrupt
* CALLED BY     : Unused entries in the interrupt vector table
* PRECONDITIONS : A wrong IRQ setting or an other malfunction has been occured
*                 and a undefined interrupt has been triggered.
* PARAMETERS    : none
* RETURN VALUE  : none
* DESCRIPTION   : The dummy interrupt handler has to be used to fill up the 
*                 interrupt vector table and to catch illegal interrupts in the 
*                 BRS exception handler.
********************************************************************************/
void BrsHwDummyInterrupt(
 void
);

/*******************************************************************************
* Transceiver Handling
*******************************************************************************/

/*******************************************************************************
* En Port
*******************************************************************************/

/*******************************************************************************
* NAME          : BrsHwSetTrcvEnPortToHigh
* CALLED BY     : BrsHwSetTrcvPortXXX or CCL
* PRECONDITIONS : CAN bus is used
* PARAMETERS    : CAN channel
* RETURN VALUE  : none
* DESCRIPTION   : Set the transceiver port RS to high
********************************************************************************/
void BrsHwSetTrcvEnPortToHigh(
  /*
   *  Description        : Number of CAN channel to be handled
   *  Direction          : in
   *  Modified           : no
   *  Val. range / Coding: 0..255
   */
  vuint8 channel
);

/*******************************************************************************
* NAME          : BrsHwSetTrcvEnPortToLow
* CALLED BY     : BrsHwSetTrcvPortXXX or CCL
* PRECONDITIONS : CAN bus is used
* PARAMETERS    : CAN channel
* RETURN VALUE  : none
* DESCRIPTION   : Set the transceiver port RS to low
********************************************************************************/
void BrsHwSetTrcvEnPortToLow(
  /*
   *  Description        : Number of CAN channel to be handled
   *  Direction          : in
   *  Modified           : no
   *  Val. range / Coding: 0..255
   */
  vuint8 channel
);

/*******************************************************************************
* NAME          : BrsHwSetTrcvEnPortMode
* CALLED BY     : BrsHwCanTrcvPortsInitPowerOn or CCL
* PRECONDITIONS : CAN bus is used
* PARAMETERS    : CAN channel
* RETURN VALUE  : none
* DESCRIPTION   : Set the transceiver port mode
********************************************************************************/
void BrsHwSetTrcvEnPortMode(
  /*
   *  Description        : Number of CAN channel to be handled
   *  Direction          : in
   *  Modified           : no
   *  Val. range / Coding: 0..255
   */
  vuint8 channel
);

/*******************************************************************************
* NAME          : BrsHwSetTrcvEnPortMode
* CALLED BY     : BrsHwCanTrcvPortsInitPowerOn or CCL
* PRECONDITIONS : CAN bus is used
* PARAMETERS    : CAN channel
* RETURN VALUE  : none
* DESCRIPTION   : Set the transceiver port direction
********************************************************************************/
void BrsHwSetTrcvEnDirection(
  /*
   *  Description        : Number of CAN channel to be handled
   *  Direction          : in
   *  Modified           : no
   *  Val. range / Coding: 0..255
   */
  vuint8 channel
);

#define BrsHwSetTrcvPortEnInitValue() 0

/*******************************************************************************
* Stb Port
*******************************************************************************/

/*******************************************************************************
* NAME          : BrsHwSetTrcvStbPortToHigh
* CALLED BY     : BrsHwSetTrcvPortXXX or CCL
* PRECONDITIONS : CAN bus is used
* PARAMETEStb    : CAN channel
* RETURN VALUE  : none
* DESCRIPTION   : Set the transceiver port Stb to high
********************************************************************************/
void BrsHwSetTrcvStbPortToHigh(
  /*
   *  Description        : Number of CAN channel to be handled
   *  Direction          : in
   *  Modified           : no
   *  Val. range / Coding: 0..255
   */
  vuint8 channel
);

/*******************************************************************************
* NAME          : BrsHwSetTrcvStbPortToLow
* CALLED BY     : BrsHwSetTrcvPortXXX or CCL
* PRECONDITIONS : CAN bus is used
* PARAMETEStb    : CAN channel
* RETURN VALUE  : none
* DESCRIPTION   : Set the transceiver port Stb to low
********************************************************************************/
void BrsHwSetTrcvStbPortToLow(
  /*
   *  Description        : Number of CAN channel to be handled
   *  Direction          : in
   *  Modified           : no
   *  Val. range / Coding: 0..255
   */
  vuint8 channel
);

/*******************************************************************************
* NAME          : BrsHwSetTrcvStbPortMode
* CALLED BY     : BrsHwCanTrcvPortsInitPowerOn or CCL
* PRECONDITIONS : CAN bus is used
* PARAMETEStb    : CAN channel
* RETURN VALUE  : none
* DESCRIPTION   : Set the transceiver port mode
********************************************************************************/
void BrsHwSetTrcvStbPortMode(
  /*
   *  Description        : Number of CAN channel to be handled
   *  Direction          : in
   *  Modified           : no
   *  Val. range / Coding: 0..255
   */
  vuint8 channel
);

/*******************************************************************************
* NAME          : BrsHwSetTrcvStbPortMode
* CALLED BY     : BrsHwCanTrcvPortsInitPowerOn or CCL
* PRECONDITIONS : CAN bus is used
* PARAMETEStb    : CAN channel
* RETURN VALUE  : none
* DESCRIPTION   : Set the transceiver port direction
********************************************************************************/
void BrsHwSetTrcvStbDirection(
  /*
   *  Description        : Number of CAN channel to be handled
   *  Direction          : in
   *  Modified           : no
   *  Val. range / Coding: 0..255
   */
  vuint8 channel
);


/*******************************************************************************
* Err Port
*******************************************************************************/

/*******************************************************************************
* NAME          : BrsHwSetTrcvStbPortToHigh
* CALLED BY     : BrsHwSetTrcvPortXXX or CCL
* PRECONDITIONS : CAN bus is used
* PARAMETEStb    : CAN channel
* RETURN VALUE  : none
* DESCRIPTION   : Set the transceiver port Stb to high
********************************************************************************/
vuint8 BrsHwGetTrcvErrPortValue(
  /*
   *  Description        : Number of CAN channel to be handled
   *  Direction          : in
   *  Modified           : no
   *  Val. range / Coding: 0..255
   */
  vuint8 channel
);

/*******************************************************************************
* NAME          : BrsHwSetTrcvStbPortMode
* CALLED BY     : BrsHwCanTrcvPortsInitPowerOn or CCL
* PRECONDITIONS : CAN bus is used
* PARAMETEStb    : CAN channel
* RETURN VALUE  : none
* DESCRIPTION   : Set the transceiver port mode
********************************************************************************/
void BrsHwSetTrcvErrPortMode(
  /*
   *  Description        : Number of CAN channel to be handled
   *  Direction          : in
   *  Modified           : no
   *  Val. range / Coding: 0..255
   */
  vuint8 channel
);

/*******************************************************************************
* NAME          : BrsHwSetTrcvStbPortMode
* CALLED BY     : BrsHwCanTrcvPortsInitPowerOn or CCL
* PRECONDITIONS : CAN bus is used
* PARAMETEStb    : CAN channel
* RETURN VALUE  : none
* DESCRIPTION   : Set the transceiver port direction
********************************************************************************/
void BrsHwSetTrcvErrDirection(
  /*
   *  Description        : Number of CAN channel to be handled
   *  Direction          : in
   *  Modified           : no
   *  Val. range / Coding: 0..255
   */
  vuint8 channel
);

#define BrsHwSetTrcvPortErrInitValue() 0

/*******************************************************************************
* Rs Port (High Speed)
*******************************************************************************/

#define BrsHwSetTrcvRsPortToHigh()     BrsHwSetTrcvEnPortToHigh((
#define BrsHwSetTrcvRsPortToLow()      BrsHwSetTrcvEnPortToLow()
#define BrsHwSetTrcvRsPortMode()       BrsHwSetTrcvEnPortMode() 
#define BrsHwSetTrcvRsDirection()      BrsHwSetTrcvEnDirection()
#define BrsHwSetTrcvPortStbInitValue() 0

/*******************************************************************************
* SLP Port (LIN)
*******************************************************************************/

#define BrsHwSetTrcvSlpPortToHigh()     BrsHwSetTrcvEnPortToHigh((
#define BrsHwSetTrcvSlpPortToLow()      BrsHwSetTrcvEnPortToLow()
#define BrsHwSetTrcvSlpPortMode()       BrsHwSetTrcvEnPortMode() 
#define BrsHwSetTrcvSlpDirection()      BrsHwSetTrcvEnDirection()
#define BrsHwSetTrcvPortSlpInitValue() 0

#pragma message ("HINT: Building for BullsEye Coverage may cause CANoe to crash at Startup. Solution: Delete resulting file test.cov and rebuild...")
#endif /*_BRSHW_H_*/
/************   Organi, Version 3.6.8 Vector-Informatik GmbH  ************/
