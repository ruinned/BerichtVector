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
         File:  TscDet.h
      Project:  Tsc for CddMirror
       Module:  -
    Generator:  -
  Description:  Stub for Det
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

#ifndef V_TSCDET_HEADER
#define V_TSCDET_HEADER

/**********************************************************************************************************************
  Includes
**********************************************************************************************************************/
#include "Std_Types.h"
#include "Det.h"


/**********************************************************************************************************************
  Version data
**********************************************************************************************************************/
#define TSCDET_VERSION                                                     0x0100
#define TSCDET_RELEASE_VERSION                                             0x00

/**********************************************************************************************************************
  Global configuration
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global data defines
**********************************************************************************************************************/
#define kTscDet_CI                                                         0x06

/*--- test stimulation ----------------------------------------------------------------------------------------------*/
/*--- stub functions ------------------------------------------------------------------------------------------------*/
#define kTscDet_Det_ReportError                                            0x80

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
extern void TscDet_Init( void );
extern void TscDet_Cyclic1ms( void );
extern void TscDet_EventMask_EnableAll( void );
extern void TscDet_EventMask_DisableAll( void );
extern void TscDet_EventMask_Enable( uint8 eventId );
extern void TscDet_EventMask_Disable( uint8 eventId );

/*--- specific control ----------------------------------------------------------------------------------------------*/

/*--- test stimulation ----------------------------------------------------------------------------------------------*/

/*--- stub functions ------------------------------------------------------------------------------------------------*/
extern void Det_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);
/* prototypes defined in own header, e.g. can_inc.h */

#endif /* V_TSCDET_HEADER */
/**********************************************************************************************************************
  EOF
**********************************************************************************************************************/
