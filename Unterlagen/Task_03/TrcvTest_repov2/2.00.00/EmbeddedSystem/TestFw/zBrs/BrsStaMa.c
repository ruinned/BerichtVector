/*  *****   STARTSINGLE_OF_MULTIPLE_COMMENT    *****  */




/*****************************************************************************/
/**
 * \file    BrsStaMa.C
 * \brief   BRS Station Manager Code
 *
 * This is an example implementation of a station management to handle the 
 * different application requests to the single network management API 
 * interface for bus wakeup and sleep handling. This example is able to handle 
 * up to 16 different application requests for network usage.
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
 - Ms           Gunnar Meiss              Vector Informatik GmbH
 *****************************************************************************
 * \version     R E V I S I O N   H I S T O R Y
 *****************************************************************************
 - Date         Version Author  Description
 - **********   ******* ******  ************************************
 - 2002-08-14   1.00.00 Ra      First Version
 - 2003-01-13   1.00.01 Uf      Changed NM_OSEKD defines according to 
                                FS_BrsGenToolSetup.doc
 - 2003-03-03   1.01.00 Get     code doubled feature added
                                (BrsStatManagerBusWakeUpEvent, BrsStatManagerGotoMode)
 - 2003-04-08   1.01.01 Get     removed C_SINGLE_RECEIVE_CHANNEL switch from body of
                                BrsStatManagerGotoMode.
 - 2003-07-23   1.02.00 Uf      Moved transceiver handling routines to BrsStaMa.c
                                Renamed BrsStatManagerXX functions to BrsStaMaXX
 - 2003-07-24   1.03.00 Uf      Comments changed to doxygen style
                                Support for OSEKNM of different customers
 - 2003-08-14   1.03.01 Uf      Transceiver function moved outside of 
                                BRS_ENABLE_STATIONMANAGER
 - 2003-08-19   1.03.02 Get     kBrsNmChannels evaluated instead of
                                kNmNumberOfChannels on code doubled systems.
 - 2003-10-17   1.03.03 Uf      CanTrcv default is only set if CAN driver is used
 - 2003-11-06   1.04.00 Ra      Legal text added, comments 
 - 2004-02-05   1.04.01 Ms      Added V_ENABLE_USE_DUMMY_STATEMENT for unused parameters
 - 2004-02-10   1.05.00 Uf      Transceiver Port Initialization
 - 2004-02-19   1.05.01 Uf      Transceiver Port Initialization fix
 - 2004-04-14   1.05.02 Uf      Transceiver Port Initialization fix
 - 2004-11-29   2.00.00 Ra      Usage of Vector types, DoxyGenSupport added
 - 2005-01-11   2.00.01 Uf      MISRA compliant doxygen attributes
 - 2005-03-16   2.00.02 Uf      Use v_memrom qualifier for const variables
 - 2005-11-18   2.00.03 Uf      Removed ticks in comments
 - 2005-12-06   2.01.00 Uf      Added filter rule warnings
 - 2006-11-02   2.01.01 Ms      Added AUTOSAR support
 - 2007-03-04   2.01.02 Ms      Updated AUTOSAR support
 *****************************************************************************/

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


/*
 * Description: The V_Def header provides types and definitions common to all 
 *              VECTOR CANbedded modules.
 */
#include "V_Def.H"

/*
 * Description: The BrsHw header provides all the necessary interfaces to
 *              the CPU and board hardware. This is e.g. port and timer access.
 *              This file is part of the BRS.
 */
#include "BrsHw.H"


/*
 * Description: The BrsStaMa header provides all the necessary interfaces to
 *              the station management module. 
 *              This file is part of the BRS.
 */
#include "BrsStaMa.H"


#if defined( VGEN_ENABLE_CAN_DRV ) 
/*
 * Description: The can_inc.h header provides the number of used can channels.
 */
# if defined ( VGEN_ENABLE_IF_ASRIFCAN )
#  include "CanProto.h"
# else
#  include "can_inc.h"
# endif
#endif


/******************************************************************************
 * Version check
 ******************************************************************************/
#if( BRS_STAMA_VERSION != 0x0201 )
  #error "Header and source file are inconsistent!"
#endif
#if( BRS_STAMA_RELEASE_VERSION != 0x02 )
  #error "Different release versions in Header and Source used!"
#endif


/*******************************************************************************
 * Global variables
 *******************************************************************************/
#if defined( C_KOMMENTAR_VECTOR )
 /* CANbedded developers: This definition is hardware independent and must not be changed. */
#endif


/****************************************************************************/
#if defined( BRS_ENABLE_STATIONMANAGER )
/*****************************************************************************
 * Do all further handling only, if this module is used in the current 
 * configuration
 *****************************************************************************/

#if defined( VGEN_ENABLE_NM_OSEK_D )
  /*
   * Description: The OSEK NM header will provide all the necessary interfaces
   *              to the OSEK network management.
   *              Add the code snipped below to you organi file and change the 
   *              CUSTOMER_XXX according to your needs
   * >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
   * CUSTOMER
   * CUSTOMER_XXX
   * *END
   * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
   */
  #include "nm_osek.h"
#else
  #error "The BrsStaMa module does not support the selected NM type!"
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
 * \var kBrsStaMaMainVersion
 *      Stores the BCD coded main-version of this file.
 */
/**
 * \var kBrsStaMaSubVersion 
 *      Stores the BCD coded sub-version of this file.
 */
/** 
 * \var kBrsStaMaReleaseVersion 
 *      Stores the BCD coded release-version of this file.
 */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kBrsStaMaMainVersion    = (vuint8)(BRS_STAMA_VERSION >> 8);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kBrsStaMaSubVersion     = (vuint8)(BRS_STAMA_VERSION); /*lint !e778 */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kBrsStaMaReleaseVersion = (vuint8)(BRS_STAMA_RELEASE_VERSION);

#if defined ( C_COMP_IAR_M16C )
  #if defined ( _NEAR_ )
  /* Normal segment usage */
  #pragma memory=default
  #endif
#endif /*C_COMP_IAR_M16C*/



/*******************************************************************************
 * Local variables
 *******************************************************************************/

/*****************************************************************************
 * All handling till here is only done, if this module is used in the current 
 * configuration
 *****************************************************************************/
#endif /*BRS_ENABLE_STATIONMANAGER*/

/** 
 * \var bBrsTrcvState
 *      This variable is used to trace the state of the tranceiver.
 * Values: See enum definition "tBrsTrcvState"
 */
static tBrsTrcvState bBrsTrcvState;

/****************************************************************************/
#if defined( BRS_ENABLE_STATIONMANAGER )
/*****************************************************************************
 * Do all further handling only, if this module is used in the current 
 * configuration
 *****************************************************************************/

/** 
 * \var bBrsStaMaBusWakeupReason
 *      The current wakeup reason is stored in this variable. The value is 
 *      returned by BrsStaMaGetWakeupEvent. The default value is 
 *      BRS_SM_WAKEUP_REASON_IS_UNKNOWN.
 * Values: See the definition of the wake up reasons in the module header.
 */
static vuint8 bBrsStaMaBusWakeupReason[kBrsNmChannels];

/** 
 * \var bBrsStaMaBusRequestsFlags
 *      All application request flags are stored here. If the value of this 
 *      variable changes from 0 to !0, the bus is waked up internally. If it 
 *      changes back to 0, the NM state will be changed to PREPARE_SLEEP.
 * Values: See definition of e.g. BRS_SM_APPL_REQ0 to BRS_SM_APPL_REQ15
 */
static vuint16 bBrsStaMaBusRequestsFlags[kBrsNmChannels];

/** 
 * \var bBrsStaMaBusIsAwake
 *        The station manager will use this variable to detect if the system is 
 *        already running. It will be set to '1' the first time the bus is enabled 
 *        and will be cleared to '0', if the bus changes to SLEEP.
 * Values: 0, if the bus is switched off; 1, if the bus is switched on
 */
static vuint8 bBrsStaMaBusIsAwake[kBrsNmChannels];
 


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

static void BrsStaMaGotoMode(
  NMModeName mode,
  vuint8 channel
);

/*******************************************************************************
 * Function definitions
 *******************************************************************************/

/*******************************************************************************/
/**
 * \brief Station Manager initialization at poweron/reset
 *
 * \param[in] channel selects the addressed bus
 *
 * \pre       Hardware (power supply and clocks) is initialized, global
 *            interrupts are disabled.
 *
 * \post      Station Manager is initialized and could be used now.
 */
void BrsStaMaInitPowerOn( 
  vuint8 channel 
)
{
  bBrsStaMaBusWakeupReason[channel] = BRS_SM_WAKEUP_REASON_IS_UNKNOWN;

  bBrsStaMaBusRequestsFlags[channel] = 0;

  bBrsStaMaBusIsAwake[channel] = 0;
}


/*******************************************************************************/
/**
 * \brief API to request bus communication
 *        This function has to be called, if an application module needs the bus 
 *        for working. If the network is in SLEEP state, it will be waked up by 
 *        this function call. If the network is already running, the NM state of 
 *        the own station is changed to !PRPEARE_SLEEP. The whole network will 
 *        not go to SLEEP, till the last pending network request is cleared!
 *        The BRS station manager is able to handle up to 16 different, 
 *        independent application "requesters". Each "requester" must use a unique 
 *        value. This allows also easily to detect the "reason" for a "hanging" 
 *        CAN bus request.
 *        If more than one bus has to be managed, the station manager has to be 
 *        handled for each bus separately.
 *
 * \param[in] bApplRequestIdentifier identifies the requester, which is bit coded 
 *            value 0x0001, 0x0002 ... 0x8000. See  example definition of e.g. 
 *            BRS_SM_APPL_REQ_1.
 * \param[in] bApplWakeupReason is the byte coded wakeup reason. See example 
 *            definition of e.g. BRS_SM_WAKEUP_REASON_IS_xxx.
 * \param[in] channel selects the bus to be requested
 *
 * \pre   System is completely initialized and powered.
 *
 * \post  The requested bus is now available to communicate.
 */
void BrsStaMaRequestBus( 
  vuint16 bApplRequestIdentifier,
  vuint8 bApplWakeupReason,
  vuint8 channel 
)
{
  if( bBrsStaMaBusIsAwake[channel]==0 ) {
    bBrsStaMaBusIsAwake[channel] = 1;
    /** This is the first bus request and the bus is currently NOT running. 
    *  Overwrite the wakeup reason with the current application wakeup 
    *  reason. */
    bBrsStaMaBusWakeupReason[channel] = bApplWakeupReason;
  }

  /* Bus request handling */
  if( bBrsStaMaBusRequestsFlags[channel]==0 ) {
    /** This is the first request for the bus by the application. Start the
    *  bus now. This has to be done by the network management API GotoMode. 
    *  GotoMode is allowed to be called in NM state SLEEP and NM state 
    *  SLEEP_INDICATION, so there is no difference if the bus is already 
    *  running or not. */
    BrsStaMaGotoMode(Awake, channel);
  }

  /** Mark the requesting application in the local flag field. */
  bBrsStaMaBusRequestsFlags[channel] |= bApplRequestIdentifier;
}


/*******************************************************************************/
/**
 * \brief API to release bus communication
 *        This function has to be called, if an application does not need the 
 *        bus anymore for its own work. Please note, that the application is not 
 *        allowed to stop working, until the bus has entered the SLEEP state. If 
 *        the API call realeases the last request BRS station manager flag, the 
 *        NM state of the own station is changed to PRPEARE_SLEEP. Please note, 
 *        that each application must use the identical flag name for requesting 
 *        and releasing the bus.
 *        If more than one bus has to be managed, the station manager has to be 
 *        handled for each bus separately.
 *
 * \param[in] bApplRequestIdentifier identifies the requester, which is bit coded 
 *            value 0x0001, 0x0002 ... 0x8000. See  example definition of e.g. 
 *            BRS_SM_APPL_REQ_1.
 * \param[in] channel selects the bus to be requested
 *
 * \pre   System is completely initialized and powered. The API call makes only
 *        sense if the addressed bus is already requested by the caller.
 *
 * \post  The bus request for the caller is now cleared. f it was the last caller,
 *        bus communication is set to PREPARE_SLEEP form the nodes view. If other
 *        callers are still requesting the bus, the communication state is not 
 *        changed.
 */
void BrsStaMaReleaseBus(
  vuint16 bApplRequestIdentifier,
  vuint8 channel 
)
{
  /** Clear the requesting application in the local flag field. */
  bBrsStaMaBusRequestsFlags[channel] &= (~bApplRequestIdentifier);

  if( bBrsStaMaBusRequestsFlags[channel]==0 ) {
    /** This is the last release for the bus by the application. Advise the NM
    *  to set the SLEEP_IND flag of the own station. The bus will go to sleep,
    *  if all stations are in SLEEP_IND state or, if the system is in state 
    *  LIMP_HOME immediately. */
    BrsStaMaGotoMode(BusSleep, channel);
  }
}


/*******************************************************************************/
/**
 * \brief Wakeup event handler
 *        The BRS station manager will be informed that the bus controller has 
 *        been waked up. The own node has to start and send and receive now 
 *        messages, too.
 *        If more than one bus has to be managed, the station manager has to be 
 *        handled for each bus separately.
 *        Called by:
 *        - Bus driver, if a wakeup is detected and notified by the bus controller 
 *        (e.g. CAN, LIN).
 *        - Application, if wakeup is detected by e.g. the INH port of e.g. the 
 *        low speed CAN transceiver.
 *
 * \param[in] channel selects the bus to be requested
 *
 * \pre   System is completely initialized and powered. A wakeup call is expected
 *        and allowed.
 *
 * \post  The bus request for the caller is now cleared. f it was the last caller,
 *        bus communication is set to PREPARE_SLEEP form the nodes view. If other
 *        callers are still requesting the bus, the communication state is not 
 *        changed.
 */
void BrsStaMaBusWakeUpEvent( 
  vuint8 channel 
)
{
  if( bBrsStaMaBusIsAwake[channel]==0 ) {
    bBrsStaMaBusIsAwake[channel] = 1;
    /* Set the wakeup reason "BUS" */
    bBrsStaMaBusWakeupReason[channel] = BRS_SM_WAKEUP_REASON_IS_BUS; 
  
#if defined(NM_ENABLE_INDEXED_NM)
    NmOsekInit( channel, NM_SLEEPIND );
#else
  /* The following #if-statement uses kBrsNmChannels instead of 
   * kNmNumberOfChannels, since the latter is only available with
   * _0, _1, _2,... on code multiplied systems. */
  #if (kBrsNmChannels>2)
   #error "Unsupported number of NM channels used for this example (only 2 possible)"
  #elif (kBrsNmChannels>1)
    switch (channel) {
     case 0:
       NmOsekInit_0( NM_SLEEPIND );
       break;
     case 1:
       NmOsekInit_1( NM_SLEEPIND );
       break;
    }
  #else /* kBrsNmChannels>2 */
    NmOsekInit( NM_SLEEPIND );
  #endif /* kBrsNmChannels>2 */
#endif /* NM_ENABLE_INDEXED_NM */
  } else {
    /** System is already waked up by application. Do not change the 
    *  current wakeup reason. */
  }
}


/*******************************************************************************/
/**
 * \brief Sleep event handler
 *        The BRS station manager will be informed that the network management 
 *        has changed to the NM state to SLEEP. In that state, the bus controller
 *        is halted and the transceiver is in SLEEP state, too. 
 *        If more than one bus has to be managed, the station manager has to be 
 *        handled for each bus separately.
 *
 * \param[in] channel selects the bus to be requested
 *
 * \pre   System is completely initialized and powered. All callers have released
 *        their bus requests and the NM has decided to enter SLEEP now.
 *
 * \post  The bus is asleep and the wakeup reason is cleared.
 */
void BrsStaMaBusSleepEvent( 
  vuint8 channel
)
{
  bBrsStaMaBusIsAwake[channel] = 0;
}


/*******************************************************************************/
/**
 * \brief API allows the access to the first detected wakeup event
 *        The BRS station manager will return the local stored wakeup reason for
 *        the ECU. The wakeup reason is stored internaly with the default value 
 *        BRS_SM_WAKEUP_REASON_IS_UNKNOWN. If a wakeup  reason is given by the 
 *        wakeup via bus or internal, the first value is stored and now returned.
 *
 * \param[in] channel selects the bus to be asked for the wakeup reason
 *
 * \retval Wakeup state stored in the station manager.
 *
 * \pre   System is completely initialized and powered. 
 */
vuint8 BrsStaMaGetWakeupEvent( 
  vuint8 channel
)
{
  return bBrsStaMaBusWakeupReason[channel];
}


/*******************************************************************************/
/**
 * \brief Local API to change mode of the attached NM. 
 *
 * \param[in] mode selects the next NM mode requested for the given bus.
 * \param[in] channel selects the bus to be changed in its settings.
 *
 * \pre   System is completely initialized and powered. 
 */
static void BrsStaMaGotoMode(
  NMModeName mode,
  vuint8 channel
)
{
#if defined(NM_ENABLE_INDEXED_NM)
    GotoMode( channel, mode );
#else 
  /* The following #if-statement uses kBrsNmChannels instead of 
   * kNmNumberOfChannels, since the latter is only available with
   * _0, _1, _2,... on code multiplied systems. */
  #if (kBrsNmChannels>2)
   #error "Unsupported number of NM channels used for this example (only 2 possible)"
  #else
   #if (kBrsNmChannels>1)
    switch (channel) {
     case 0:
      GotoMode_0( mode );
      break;
     case 1:
      GotoMode_1( mode );
      break;
    }
   #else /* kBrsNmChannels>1 */
# if defined ( V_ENABLE_USE_DUMMY_STATEMENT  )
   channel = channel;
# endif
   GotoMode( mode );
   #endif /* kBrsNmChannels>1 */
  #endif /* kBrsNmChannels>2 */
#endif /* NM_ENABLE_INDEXED_NM */
}

/*****************************************************************************
 * All handling till here is only done, if this module is used in the current 
 * configuration
 *****************************************************************************/
#endif /*BRS_ENABLE_STATIONMANAGER*/


/*******************************************************************************/
/**
 * \brief Initializes the transceiver ports to their startup setting
 *
 * \pre   Called during initialization, best before e.g. CAN driver initialization.
 * \post  Ports of attached transceiver are in their default position for startup.
 */
void BrsStaMaTrcvPortsInitPowerOn(
  void
)
{
  #if defined( C_KOMMENTAR_VECTOR )
  /* CANbedded developers: Add your port direction code below!  
   * Port.NSTB = output 
   * Port.EN   = output
   * Port.NERR = input */
  #endif

  #if defined( VGEN_ENABLE_CAN_DRV ) 
  vuint8 i;
  for (i=0; i<kCanNumberOfChannels; i++) {
    BrsHwSetTrcvEnPortMode(i);
    BrsHwSetTrcvStbPortMode(i);
    BrsHwSetTrcvErrPortMode(i);

    BrsHwSetTrcvEnDirection(i);
    BrsHwSetTrcvStbDirection(i);
    BrsHwSetTrcvErrDirection(i);

  #if defined( BRS_WAKEABLE_TRCV )
    BrsStaMaSetTrcvToNormal(i);
  #endif /* BRS_WAKEABLE_TRCV */
  #if defined( BRS_SINGLEWIRE_TRCV )
    BrsStaMaSetTrcvToHighSpeed(i);
  #endif /* BRS_SINGLEWIRE_TRCV */
  }
  #endif

  /* high speed transceiver is used, do nothing */

  #if defined( C_KOMMENTAR_VECTOR )
  /* CANbedded developers: Do not change/remove the assignement to bBrsTrcvState below! */
  #endif
  bBrsTrcvState = TrcvNormal;
}


#if defined( BRS_WAKEABLE_TRCV )
/*******************************************************************************/
/**
 * \brief Switchs the transceiver to its NORMAL mode
 *        NORMAL mode = working mode. The CAN communication is now possible. 
 *        The NORMAL mode behavior depends on the used transceiver type.
 *
 * \param[in] channel  selects bus number
 *
 * \pre   Called by e.g. NM in the ApplNmXxxx callbacks.
 *
 * \post  CAN bus transceiver is now ready to operate.
 */
/*******************************************************************************/
void BrsStaMaSetTrcvToNormal(
  vuint8 channel
)
{
  /** Set transceiver to NORMAL mode. */
  #if defined( C_KOMMENTAR_VECTOR )
  /* CANbedded developers: Add your port access code below!  
   * Port.NSTB = 1; First! 
   * Port.EN   = 1; Second! */
  #endif
  BrsHwSetTrcvStbPortToHigh(channel);
  BrsHwSetTrcvEnPortToHigh(channel);
  /** Transceiver is now in NORMAL mode. */

  #if defined( C_KOMMENTAR_VECTOR )
  /* CANbedded developers: Do not change/remove the assignement to bBrsTrcvState below! */
  #endif
  bBrsTrcvState = TrcvNormal;
}
#endif /* BRS_WAKEABLE_TRCV */


#if defined( VGEN_ENABLE_CAN_DRV ) 
  #if defined( BRS_WAKEABLE_TRCV )
    #if defined( BRS_LOWSPEED_TRCV  ) || \
        defined( BRS_HIGHSPEED_TRCV )
/*******************************************************************************/
/**
 * \brief sets the transceiver to its STANDBY mode. 
 *        STANDBY mode = no working mode. 
 *        The CAN communication is NOT possible anymore. The STANDBY behavior 
 *        depends on the used transceiver type.
 *
 * \param channel  selects bus number
 *
 * \pre   Called by e.g. NM in the ApplNmXxxx callbacks
 *
 * \post  CAN bus transceiver is now in STANDBY mode.
 */
/*******************************************************************************/
void BrsStaMaSetTrcvToStandby(
  vuint8 channel
)
{
  /** Set transceiver to STANDBY mode. */
    #if defined( C_KOMMENTAR_VECTOR )
        /* CANbedded developers: Add your port access code below!  
         * Port.EN   = 0; First! 
         * Port.NSTB = 0; Second! */
    #endif
    BrsHwSetTrcvEnPortToLow(channel);
    BrsHwSetTrcvStbPortToLow(channel);
  /** Transceiver is now in STANDBY mode. */

  #if defined( C_KOMMENTAR_VECTOR )
  /* CANbedded developers: Do not change/remove the assignement to bBrsTrcvState below! */
  #endif
  bBrsTrcvState = TrcvStandBy;
}
    #endif /* BRS_LOWSPEED_TRCV || BRS_HIGHSPEED_TRCV */
  #endif /* BRS_WAKEABLE_TRCV */
#endif /*VGEN_ENABLE_CAN_DRV*/
 

#if defined( BRS_WAKEABLE_TRCV )
/*******************************************************************************/
/**
 * \brief Sets the transceiver to its SLEEP mode. 
 *        SLEEP mode = no working mode. 
 *        The CAN communication is NOT possible anymore. The SLEEP behavior 
 *        depends on the used transceiver type.
 *
 * \param channel  selects bus number
 *
 * \pre   Called by e.g. NM in the ApplNmXxxx callbacks
 *
 * \post  CAN bus transceiver is now in SLEEP mode.
 */
/*******************************************************************************/
void BrsStaMaSetTrcvToSleep(
  vuint8 channel
)
{
  #if defined( C_KOMMENTAR_VECTOR )
  /* CANbedded developers: The bWaitLoop is necessary for the correct tranceiver handling, do not remove or change! */
  #endif
  vuint8 bWaitLoop;
  
  #if defined( BRS_LOWSPEED_TRCV ) || \
      defined( BRS_HIGHSPEED_TRCV )
  /** Set transceiver to SLEEP mode. */
  #if defined( C_KOMMENTAR_VECTOR )
  /* CANbedded developers: Set the transceivers EN port here to 1 */
  #endif
  BrsHwSetTrcvEnPortToHigh(channel);
  /** The EN=1 must be set for at least 50µs for correct transition to
  *  the transceiver SLEEP mode. Please adapt the loop value to the CPU
  *  power. The real time should be measured in the release system, too. */
  for(bWaitLoop=0; bWaitLoop<250; bWaitLoop++){};
  #if defined( C_KOMMENTAR_VECTOR )
  /* CANbedded developers: Set the transceivers EN port here to 0 again */
  #endif
  BrsHwSetTrcvEnPortToLow(channel);
  /** Transceiver is now in SLEEP mode. */
  #endif /* BRS_HIGHSPEED_TRCV || BRS_HIGHSPEED_TRCV */

  #if defined( BRS_SINGLEWIRE_TRCV )
  BrsHwSetTrcvStbPortToLow(channel);
  BrsHwSetTrcvEnPortToLow(channel);
  #endif /* BRS_SINGLEWIRE_TRCV */

  #if defined( C_KOMMENTAR_VECTOR )
  /* CANbedded developers: Do not change/remove the assignement to bBrsTrcvState below! */
  #endif
  bBrsTrcvState = TrcvSleep;
}
#endif /* BRS_WAKEABLE_TRCV */


#if defined( VGEN_ENABLE_CAN_DRV ) 
  #if defined( BRS_SINGLEWIRE_TRCV )
/*******************************************************************************/
/**
 * \brief Set the transceiver to its HIGHVOLTAGE mode.
 *
 * \param channel  selects bus number
 *
 * \pre   Called by e.g. NM in the ApplNmXxxx callbacks. Only for single wire 
 *        transceivers.
 *
 * \post  CAN bus transceiver is now in HIGHVOLTAGE mode.
 */
void BrsStaMaSetTrcvToHighVoltage(
  vuint8 channel
)
{
  #if defined( C_KOMMENTAR_VECTOR )
  /* CANbedded developers: The bWaitLoop is necessary for the correct tranceiver handling, do not remove or change! */
  #endif
  
  BrsHwSetTrcvStbPortToHigh(channel);
  BrsHwSetTrcvEnPortToLow(channel);

  #if defined( C_KOMMENTAR_VECTOR )
  /* CANbedded developers: Do not change/remove the assignement to bBrsTrcvState below! */
  #endif
  bBrsTrcvState = TrcvSleep;
}
  #endif /* BRS_SINGLEWIRE_TRCV */
#endif /*VGEN_ENABLE_CAN_DRV*/


#if defined( VGEN_ENABLE_CAN_DRV ) 
  #if defined( BRS_SINGLEWIRE_TRCV )
/*******************************************************************************/
/**
 * \brief Set the transceiver to its HIGHSPEED mode. 
 *        Only for single wire transceivers.
 *
 * \param channel  selects bus number
 *
 * \pre   Called by e.g. NM in the ApplNmXxxx callbacks
 *
 * \post  CAN bus transceiver is now in HIGHSPEED mode.
 */
void BrsStaMaSetTrcvToHighSpeed(
  vuint8 channel
)
{
  #if defined( C_KOMMENTAR_VECTOR )
  /* CANbedded developers: The bWaitLoop is necessary for the correct tranceiver handling, do not remove or change! */
  #endif
  
  BrsHwSetTrcvStbPortToLow(channel);
  BrsHwSetTrcvEnPortToHigh(channel);

  #if defined( C_KOMMENTAR_VECTOR )
  /* CANbedded developers: Do not change/remove the assignement to bBrsTrcvState below! */
  #endif
  bBrsTrcvState = TrcvSleep;
}
  #endif /* BRS_SINGLEWIRE_TRCV */
#endif /*VGEN_ENABLE_CAN_DRV*/


#if defined( VGEN_ENABLE_CAN_DRV ) 
  #if defined( BRS_WAKEABLE_TRCV )
    #if defined( BRS_LOWSPEED_TRCV  ) || \
        defined( BRS_HIGHSPEED_TRCV )
/*******************************************************************************/
/**
 * \brief BrsStaMaGetTrcvPortNERR 
 *        returns the current state of the transceiver port "ERROR". If the 
 *        transceiver has no ERROR port, the function returns 0.
 *
 * \param channel selects bus number
 *
 * \retval State read out of transceiver port "ERROR".
 *
 * \pre   Called by e.g. NM in the ApplNmXxxx callbacks
 */
vuint8 BrsStaMaGetTrcvPortNERR(
  vuint8 channel
)
{
  return BrsHwGetTrcvErrPortValue(channel);
}
    #endif /* BRS_LOWSPEED_TRCV || BRS_HIGHSPEED_TRCV */
  #endif /* BRS_WAKEABLE_TRCV */
#endif /*VGEN_ENABLE_CAN_DRV*/


/*******************************************************************************/
/**
 * \brief Returns the current state of the transceiver
 *        State is according to the API calls. This is for test purpose only!
 *
 * \param channel selects bus number
 *
 * \retval Transceiver state stored in the module.
 *
 * \pre   Called by e.g. test handlers
 */
tBrsTrcvState BrsStaMaGetTrcvState(
  vuint8 channel
)
{
# if defined ( V_ENABLE_USE_DUMMY_STATEMENT  )
  channel = channel; /* Ignore the parameter */
# endif
  
  return bBrsTrcvState;
}


/* STOPSINGLE_OF_MULTIPLE */
/************   Organi, Version 3.6.8 Vector-Informatik GmbH  ************/
