/***********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  Copyright (c) 2015 by Vector Informatik GmbH.                                                  All rights reserved.

                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
         File:  TscAppl.h
      Project:  Tsc for Mip
       Module:  -
    Generator:  -
  Description:  
***********************************************************************************************************************/

/***********************************************************************************************************************
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
  2.00.00   2008-08-22  vismas                creation
***********************************************************************************************************************/

#ifndef V_TSCAPPL_HEADER
#define V_TSCAPPL_HEADER

/***********************************************************************************************************************
  Includes
***********************************************************************************************************************/
#include "Mip.h"

/***********************************************************************************************************************
  Version data
***********************************************************************************************************************/
#define TSCAPPL_VERSION                                                       0x0200
#define TSCAPPL_RELEASE_VERSION                                               0x00

/***********************************************************************************************************************
  Global data defines
***********************************************************************************************************************/
#define kTscAppl_CI                                                           0x00

/*---------------------------------------------------------------------------------------------------------------------
  Event IDs
---------------------------------------------------------------------------------------------------------------------*/
/* Stimulation functions */
#define kTscAppl_Mip_InitMemory                                              0x01
#define kTscAppl_Mip_Init                                                    0x02
#define kTscAppl_Mip_MainFunction                                            0x03
#define kTscAppl_Mip_GetVersionInfo                                          0x04

/* Stub functions */
/* none */

/***********************************************************************************************************************
  Global macro defines
***********************************************************************************************************************/
#define TscAppl_EventMask_EnableAll()         BteLog_EventMask_EnableAll( kTscAppl_CI );
#define TscAppl_EventMask_DisableAll()        BteLog_EventMask_DisableAll( kTscAppl_CI );
#define TscAppl_EventMask_Enable(eventId)     BteLog_EventMask_Enable( kTscAppl_CI, eventId );
#define TscAppl_EventMask_Disable(eventId)    BteLog_EventMask_Disable( kTscAppl_CI, eventId );

/***********************************************************************************************************************
  Global typedefs
***********************************************************************************************************************/

/***********************************************************************************************************************
  Global data prototypes (RAM)
***********************************************************************************************************************/

/***********************************************************************************************************************
  Global data prototypes (ROM)
***********************************************************************************************************************/

/***********************************************************************************************************************
  Global function prototypes
***********************************************************************************************************************/
/*---------------------------------------------------------------------------------------------------------------------
  Generic control functions
---------------------------------------------------------------------------------------------------------------------*/
extern void TscAppl_Init( void );
extern void TscAppl_Cyclic1ms( void );

/*---------------------------------------------------------------------------------------------------------------------
  Specific control functions
---------------------------------------------------------------------------------------------------------------------*/
/* none */

/*---------------------------------------------------------------------------------------------------------------------
  Stimulation functions
---------------------------------------------------------------------------------------------------------------------*/
extern void TscAppl_Mip_InitMemory(void);
extern void TscAppl_Mip_Init(P2CONST(Mip_ConfigType, AUTOMATIC, MIP_PBCFG) config);
extern void TscAppl_Mip_MainFunction(void);
extern FUNC( void, MIP_CODE ) TscAppl_Mip_GetVersionInfo( P2VAR( Std_VersionInfoType, AUTOMATIC, MIP_APPL_VAR ) versioninfo);

/*---------------------------------------------------------------------------------------------------------------------
  Stub functions
---------------------------------------------------------------------------------------------------------------------*/
/* prototypes defined in "real" header */

#endif /* V_TSCAPPL_HEADER */
/***********************************************************************************************************************
  EOF
***********************************************************************************************************************/