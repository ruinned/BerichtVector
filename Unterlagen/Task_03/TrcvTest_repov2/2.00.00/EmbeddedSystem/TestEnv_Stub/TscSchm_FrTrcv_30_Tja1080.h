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
         File:  TscSchm_FrTrcv_30_Tja1080.h
      Project:  Tsc for Tp_AsrTpFr
       Module:  -
    Generator:  -
  Description:  Stub for Schm_FrTrcv_30_Tja1080
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
  1.00.00   2009-02-27  vismas                creation
**********************************************************************************************************************/

#ifndef V_TSCSCHM_FRTRCV_30_TJA1080_HEADER
#define V_TSCSCHM_FRTRCV_30_TJA1080_HEADER

/**********************************************************************************************************************
  Includes
**********************************************************************************************************************/
/*#if defined TSC_USECASE_CANBEDDED_COMMENT
#include "v_cfg.h"
#include "v_def.h"
#endif
#if defined TSC_USECASE_AUTOSAR_COMMENT*/
#include "Std_Types.h"
/*#endif*/
#include "Schm_FrTrcv_30_Tja1080.h"

#include "FrTrcv_30_Tja1080.h"


/**********************************************************************************************************************
  Version data
**********************************************************************************************************************/
#define TSCSCHM_FRTRCV_30_TJA1080_VERSION                                                     0x0100
#define TSCSCHM_FRTRCV_30_TJA1080_RELEASE_VERSION                                             0x00

/**********************************************************************************************************************
  Global configuration
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global data defines
**********************************************************************************************************************/
#define kTscSchm_FrTrcv_30_Tja1080_CI                                                         0x03

/*--- test stimulation ----------------------------------------------------------------------------------------------*/
/*--- stub functions ------------------------------------------------------------------------------------------------*/

/**********************************************************************************************************************
  Global macro defines
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
/*--- generic control -----------------------------------------------------------------------------------------------*/
extern void TscSchm_FrTrcv_30_Tja1080_Init( void );
extern void TscSchm_FrTrcv_30_Tja1080_Cyclic1ms( void );
extern void TscSchm_FrTrcv_30_Tja1080_EventMask_EnableAll( void );
extern void TscSchm_FrTrcv_30_Tja1080_EventMask_DisableAll( void );
extern void TscSchm_FrTrcv_30_Tja1080_EventMask_Enable( uint8 eventId );
extern void TscSchm_FrTrcv_30_Tja1080_EventMask_Disable( uint8 eventId );

/*--- specific control ----------------------------------------------------------------------------------------------*/

/*--- test stimulation ----------------------------------------------------------------------------------------------*/

/*--- stub functions ------------------------------------------------------------------------------------------------*/
/* prototypes defined in own header, e.g. can_inc.h */

#endif /* V_TSCSCHM_FRTRCV_30_TJA1080_HEADER */
/**********************************************************************************************************************
  EOF
**********************************************************************************************************************/