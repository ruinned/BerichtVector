/*  *****   STARTSINGLE_OF_MULTIPLE_COMMENT    *****  */




/*****************************************************************************/
/**
 * \file    BrsStaMa.H
 * \brief   BRS Station Manager Header
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
 * Check up BrsStaMa.c for description, author and history
 * Version info: see BRSSTAMA_VERSION, BRSSTAMA_RELEASE_VERSION
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

#ifndef _BRSSTAMA_H_
#define _BRSSTAMA_H_

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
 * Description: This is the BRS station manager main and release fix version.
 *              The version numbers are BCD coded. E.g. a main version of 1.23 is 
 *              coded with 0x0123, a release version of 9 is coded 0x09.
 */
/* ##V_CFG_MANAGEMENT ##CQProject : Brs_StaMa CQComponent : Implementation */
#define BRS_STAMA_VERSION          0x0201
#define BRS_STAMA_RELEASE_VERSION  0x02

#define BRSSTAMA_VERSION        BRS_STAMA_VERSION
#define BRSSTAMA_BUGFIX_VERSION BRS_STAMA_RELEASE_VERSION


/*
 * Description: Check if transceiver is selected 
 */
#if defined( BRS_TRANSCEIVER_251  ) || \
    defined( BRS_TRANSCEIVER_1020 ) || \
    defined( BRS_TRANSCEIVER_1041 ) || \
    defined( BRS_TRANSCEIVER_1050 ) || \
    defined( BRS_TRANSCEIVER_1053 ) || \
    defined( BRS_TRANSCEIVER_1054 ) || \
    defined( BRS_TRANSCEIVER_5790 )
#else
  #if defined( VGEN_ENABLE_CAN_DRV )
    /*  No transceiver selected - select low speed for default */
    #define BRS_TRANSCEIVER_1054
  #endif
#endif

/*
 * Description: Check bus interface is configured for corresponding transceiver
 */
#if defined( BRS_TRANSCEIVER_251  ) || \
    defined( BRS_TRANSCEIVER_1041 ) || \
    defined( BRS_TRANSCEIVER_1050 ) || \
    defined( BRS_TRANSCEIVER_1053 ) || \
    defined( BRS_TRANSCEIVER_1054 ) || \
    defined( BRS_TRANSCEIVER_5790 )
  #if defined( VGEN_ENABLE_CAN_DRV )
    #define BRS_CAN_TRCV
  #else
    #error "CAN transceiver is selected but system is not configured for CAN (CAN driver not enabled)"
  #endif
#endif

#if defined( BRS_TRANSCEIVER_1020 )
  #if defined( VGEN_ENABLE_LIN_DRV )
    #define BRS_LIN_TCVR
    #error "LIN is currently not supported!!!"
  #else
    #error "LIN transceiver is selected but system is not configured for LIN (LIN driver not enabled)"
  #endif
#endif


/*
 * Description: set transceiver specific details - high speed/low speed, wakeable...
 */
#if defined( BRS_TRANSCEIVER_251 )
  #define BRS_HIGHSPEED_TRCV
#endif

#if defined( BRS_TRANSCEIVER_1020 )
  #define BRS_LIN_TCVR
  #define BRS_WAKEABLE_TRCV
#endif

#if defined( BRS_TRANSCEIVER_1040 )
  #define BRS_HIGHSPEED_TRCV
#endif

#if defined( BRS_TRANSCEIVER_1041 )
  #define BRS_HIGHSPEED_TRCV
  #define BRS_WAKEABLE_TRCV
#endif

#if defined( BRS_TRANSCEIVER_1050 )
  #define BRS_HIGHSPEED_TRCV
#endif

#if defined( BRS_TRANSCEIVER_1053 )
  #define BRS_LOWSPEED_TRCV
  #define BRS_WAKEABLE_TRCV
#endif

#if defined( BRS_TRANSCEIVER_1054 )
  #define BRS_LOWSPEED_TRCV
  #define BRS_WAKEABLE_TRCV
#endif

#if defined( BRS_TRANSCEIVER_5790 )
  #define BRS_SINGLEWIRE_TRCV
  #define BRS_WAKEABLE_TRCV
#endif


/*******************************************************************************
* Global typdefs and enums
*******************************************************************************/
 /*
 * Description: The state of the CAN and/or LIN transceiver is traced for debug 
 *              and test purpose. This enum is used to describe the allowed values.
 *              Please note, that not all states are valid for CAN and LIN and each
 *              transceiver type!
 */
typedef enum {
 TrcvSleep = 0,
 TrcvStandBy,
 TrcvNormal,
 TrcvHighVoltage
} tBrsTrcvState;


/****************************************************************************/
#if defined( BRS_ENABLE_STATIONMANAGER )
/*****************************************************************************
 * Do all further handling only, if this module is used in the current 
 * configuration
 *****************************************************************************/

/*******************************************************************************
* Global defines
*******************************************************************************/
/*
 * Description: The BRS station manager provides a bit field to handle the
 *              CAN network requests of different application modules (e.g.
 *              diagnostic handler and other application parts).
 *              Each application module which is requesting the bus needs a
 *              own, unique request identifier. Those are specified here in 
 *              an example (anonymouse) way.
 * Values     : 0x0001, 0x0002, ... 0x8000
 */
#define BRS_SM_APPL_REQ0   0x0001
#define BRS_SM_APPL_REQ1   0x0002
#define BRS_SM_APPL_REQ2   0x0004
#define BRS_SM_APPL_REQ3   0x0008
#define BRS_SM_APPL_REQ4   0x0010
#define BRS_SM_APPL_REQ5   0x0020
#define BRS_SM_APPL_REQ6   0x0040
#define BRS_SM_APPL_REQ7   0x0080
#define BRS_SM_APPL_REQ8   0x0100
#define BRS_SM_APPL_REQ9   0x0200
#define BRS_SM_APPL_REQ10  0x0400
#define BRS_SM_APPL_REQ11  0x0800
#define BRS_SM_APPL_REQ12  0x1000
#define BRS_SM_APPL_REQ13  0x2000
#define BRS_SM_APPL_REQ14  0x4000
#define BRS_SM_APPL_REQ15  0x8000


/*
 * Description: The wakeup reason is stored by BRS station manager and 
 *              could be read via e.g. diagnostic or could be used for 
 *              manufacturer specific coding of e.g. the NM alive message.
 *              The list here is just an example for test purpose. Please  
 *              refer to the manufacturers and ECUs requirement documentation.
 *              In case the BRS detects a wake up by CAN, the value of 
 *              BRS_SM_WAKEUP_REASON_IS_CAN is used. The other values could 
 *              be used as the second argument for the API function 
 *              BrsStatManagerRequestCan().
 * Values     : --
 */
#define BRS_SM_WAKEUP_REASON_IS_UNKNOWN  0x00
#define BRS_SM_WAKEUP_REASON_IS_BUS      0x01
#define BRS_SM_WAKEUP_REASON_IS_KL15     0x02
#define BRS_SM_WAKEUP_REASON_IS_INT      0x04
#define BRS_SM_WAKEUP_REASON_IS_EXT      0x08

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
/* None used */



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
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kBrsStaMaMainVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kBrsStaMaSubVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kBrsStaMaReleaseVersion;

#if defined ( C_COMP_IAR_M16C )
  #if defined ( _NEAR_ )
  /* Normal segment usage */
  #pragma memory=default
  #endif
#endif /*C_COMP_IAR_M16C*/



/*******************************************************************************
* Function protoytpes
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
);


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
);


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
);



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
);


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
);


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
);

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
);


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
);
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
);
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
);
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
);
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
);
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
);
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
);



#endif /*_BRSSTAMA_H_*/

/* STOPSINGLE_OF_MULTIPLE */
/************   Organi, Version 3.6.8 Vector-Informatik GmbH  ************/
