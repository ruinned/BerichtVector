/*  *****   STARTSINGLE_OF_MULTIPLE_COMMENT    *****  */




/*****************************************************************************
| Project Name: Vector Basic Runtime System for CANbedded
|    File Name: BrsIntTb.C
|
|  Description: This is the hardware specific interrupt vector table for the 
|               Basic Runtime System (BRS). It covers the usage of CAN and/or
|               LIN in one system.
|               This file supports:
|               Microsoft VisualC
|
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2002 by Vector Informatik GmbH.      All rights reserved.
|
|                    Alle Rechte an der Software verbleiben bei der
|                    Vector Informatik GmbH.
|                    Vector Informatik GmbH r�umt dem Lizenznehmer das unwider-
|                    rufliche, geographisch und zeitlich nicht beschr�nkte,
|                    jedoch nicht ausschlie�liche Nutzungsrecht innerhalb des
|                    Lizenznehmers ein. Die Weitergabe des Nutzungsrechts
|                    durch den Lizenznehmers ist auf dessen Zulieferer
|                    beschr�nkt. Die Zulieferer sind zu verpflichten, die
|                    Software nur im Rahmen von Projekten f�r den Lizenznehmer
|                    zu verwenden; weitere Rechte der Zulieferer sind
|                    auszuschlie�en.
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     ------------------------------------
| Ra           Andreas Raisch            Vector Informatik GmbH
| UF           Ulrich Frank              Vector Informatik GmbH
| Ms           Gunnar Meiss              Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date         Version Author  Description
| --------     ------- ------  --------------------------------------------------
| 02-08-14     1.00    Ra      First Version
| 2006-11-02   1.00.01 Ms      Added AUTOSAR support
|****************************************************************************/

/*****************************************************************************
| Include the files necessary for the Basic Runtime System (BRS)
|****************************************************************************/

#include "BrsCfg.H"
 /*
 * Description: The BrsCfg header is used to configure different types of
 *              tests and system setups. Therefore it must be included first
 *              in each BRS and test module.
 *              This file is part of the BRS.
 */


#include "V_Cfg.H"
 /*
 * Description: The V_Cfg header is generated by the generation tool. Important 
 *              information like CPU and compiler type, manufacturer information
 *              and a list of currently used CANbedded modules is defined here.
 */


#include "V_Def.H"
 /*
 * Description: The V_Def header provides types and definitions common to all 
 *              VECTOR CANbedded modules.
 */


#include "BrsHW.H"
 /*
 * Description: The BrsHW header provides all the necessary interfaces to
 *              the micros harwdare features like ports, timers, LEDs, ... 
 *              This file is part of the BRS.
 */


#ifdef VGEN_ENABLE_CAN_DRV
# if defined ( VGEN_ENABLE_IF_ASRIFCAN )
#  include "CanProto.h"
# else
 /*
 * Description: The CAN driver header will provide all the necessary interfaces 
 *              to the driver and API functions. This header will be include
 *              with other high level modules like IL, TP or DIAG, too.
 */
#  include "can_inc.h"
# endif
#endif

#ifdef VGEN_ENABLE_LIN_DRV
#include "lin_inc.h"
 /*
 * Description: The LIN driver header will provide all the necessary interfaces 
 *              to the driver and API functions.
 */
#endif


/******************************************************************************
| Version check
|*****************************************************************************/
/* No header, therefore no version check */

/**
 * @file    BrsIntTb.C
 * @brief   BRS file containing the interupt vector table of this hardware
 *
 * This file contains the interrupt vector table of the used hardware. It is
 * part of the Basic Runtime System (BRS), platform specific part.
 */

/************   Organi, Version 3.6.8 Vector-Informatik GmbH  ************/
/************   Organi, Version 3.6.8 Vector-Informatik GmbH  ************/
