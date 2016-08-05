/*  *****   STARTSINGLE_OF_MULTIPLE_COMMENT    *****  */




/*****************************************************************************/
/**
 * \file    BrsOsek.H
 * \brief   Basic Runtime System osCAN support, Header
 *
 *  This is the OSEK OS support file of the Basic Runtime System (BRS).
 *
 * \attention 
 *  CAUTION:     !!!! THIS IS ONLY A VERY SIMPLE EXAMPLE OF OSCAN USAGE !!!!
 *               !!!!      WHICH IS NOT RECOMMENDED FOR CUSTOMERS       !!!!
 *               It only shows compiling compatibility of CANbedded and osCAN
 *                                
 * \attention Please note:
 *  The demo and example program only shows special aspects of the software. 
 *  With regard to the fact that this program is meant for demonstration purposes 
 *  Vector Informatik's liability shall be expressly excluded in cases of 
 *  ordinary negligence, to the extent admissible by law or statute. 
 *
 * Check up BrsOSEK.c for description, author and history
 * Version info: see BRSOSEK_VERSION, BRSOSEK_RELEASE_VERSION
 *
 *****************************************************************************
 *               C O P Y R I G H T
 *****************************************************************************
 * Copyright (c) 2005 by Vector Informatik GmbH.           All rights reserved.
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

#ifndef _BRSOSEK_H_
#define _BRSOSEK_H_

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
/* ##V_CFG_MANAGEMENT ##CQProject : Brs_OSEK CQComponent : Implementation */
#define BRS_OSEK_VERSION          0x0202
#define BRS_OSEK_RELEASE_VERSION  0x03

#define BRSOSEK_VERSION        BRS_OSEK_VERSION
#define BRSOSEK_BUGFIX_VERSION BRS_OSEK_RELEASE_VERSION
 /*
 * Description: This is the BRS OSEK support module main and release version.
 *              version numbers are BCD coded. E.g. a main version of 1.23 is 
 *              coded with 0x0123, a release version of 9 is coded 0x09.
 */


/*******************************************************************************
* Global defines
*******************************************************************************/
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
 * \var kBrsOsekMainVersion
 *      Stores the BCD coded main-version of this file.
 */
 /**
 * \var kBrsOsekSubVersion 
 *      Stores the BCD coded sub-version of this file.
 */
 /**
 * \var kBrsOsekReleaseVersion 
 *      Stores the BCD coded release-version of this file.
 */
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kBrsOsekMainVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kBrsOsekSubVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kBrsOsekReleaseVersion;

#if defined ( C_COMP_IAR_M16C )
  #if defined ( _NEAR_ )
  /* Normal segment usage */
  #pragma memory=default
  #endif
#endif /*C_COMP_IAR_M16C*/



/*******************************************************************************
* Function protoytpes
*******************************************************************************/
/* None used */


#endif /*_BRSOSEK_H_*/

/*  *****   STOPSINGLE_OF_MULTIPLE   *****  */
/************   Organi, Version 3.6.8 Vector-Informatik GmbH  ************/
