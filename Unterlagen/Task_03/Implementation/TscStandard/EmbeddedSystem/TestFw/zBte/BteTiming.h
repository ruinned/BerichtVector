/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  Copyright (c) 2009 by Vector Informatik GmbH.                                                  All rights reserved.

                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
         File:  BteTiming.h
      Project:  zBte
       Module:  -
    Generator:  -
  Description:  
**********************************************************************************************************************/

/**********************************************************************************************************************
  AUTHOR IDENTITY
-----------------------------------------------------------------------------------------------------------------------
  Initials     Name                      Company
-----------------------------------------------------------------------------------------------------------------------
  vismas       Markus Schwarz            Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
-----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Change Id     Description
-----------------------------------------------------------------------------------------------------------------------
  1.00.00   2008-05-28  vismas                creation
  1.01.00   2009-11-11  vismas                minor corrections
**********************************************************************************************************************/

#ifndef V_BTETIMING_HEADER
#define V_BTETIMING_HEADER

/**********************************************************************************************************************
  Includes
**********************************************************************************************************************/
#include "v_cfg.h"
#include "v_def.h"
#include "BteCfg.h"
#include "BteEvent.h"

/**********************************************************************************************************************
  Version data
**********************************************************************************************************************/
#define BTETIMING_VERSION                                                     0x0101
#define BTETIMING_RELEASE_VERSION                                             0x00

/**********************************************************************************************************************
  Global data defines
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global typedefs
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global data prototypes (RAM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global data prototypes (ROM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global function prototypes
**********************************************************************************************************************/
/*--- Timer ---------------------------------------------------------------------------------------------------------*/
void BteTimer_Init( void );
void BteTimer_Start( void );
vuint32 BteTimer_Stop( void );

/*--- Event Timing List ---------------------------------------------------------------------------------------------*/
void BteEventTimingList_Clear( void );
void BteEventTimingList_Add( tBteEvent *pEvent, vuint32 time );
void BteEventTimingList_WriteReport( vuint8 *textTcId );

#endif /* V_BTETIMING_HEADER */
/**********************************************************************************************************************
  EOF
**********************************************************************************************************************/
