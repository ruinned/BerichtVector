/***********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2015 by Vector Informatik GmbH.                                               All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 * --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 * ------------------------------------------------------------------------------------------------------------------*/
/**     \file  TscDet.h
 *     \brief  TscStub header file for Det
 *   \details  
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *                              vismas           Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  ChangeId      Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  1.0       2014-11-19  vismas  ESCAN0000000  generated by EA
 **********************************************************************************************************************/

#if !defined(TSCDET_HEADER)
#define TSCDET_HEADER

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "Det.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/*--- Version Data --------------------------------------------------------------------------------------------------*/
#define TSCDET_MAJOR_VERSION                                                  (1U)
#define TSCDET_MINOR_VERSION                                                  (0U)
#define TSCDET_RELEASE_VERSION                                                (0U)

/*--- standard BTE data defines -------------------------------------------------------------------------------------*/
#define kTscDet_CI                                                                    0x02

/*--- wrapper function symbols --------------------------------------------------------------------------------------*/

/*--- stub function symbols -----------------------------------------------------------------------------------------*/
#define kTscDet_Det_ReportError                                                       0x01


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/
/*--- standard BTE macros -------------------------------------------------------------------------------------------*/
#define TscDet_EventMask_EnableAll()            BteLog_EventMask_EnableAll( kTscDet_CI )
#define TscDet_EventMask_DisableAll()           BteLog_EventMask_DisableAll( kTscDet_CI )
#define TscDet_EventMask_Enable(eventId)        BteLog_EventMask_Enable( kTscDet_CI, eventId )
#define TscDet_EventMask_Disable(eventId)       BteLog_EventMask_Disable( kTscDet_CI, eventId )
#define TscDet_EventListMask_EnableAll()        BteLog_EventListMask_EnableAll( kTscDet_CI )
#define TscDet_EventListMask_DisableAll()       BteLog_EventListMask_DisableAll( kTscDet_CI )
#define TscDet_EventListMask_Enable(eventId)    BteLog_EventListMask_Enable( kTscDet_CI, eventId )
#define TscDet_EventListMask_Disable(eventId)   BteLog_EventListMask_Disable( kTscDet_CI, eventId )
#define TscDet_EventLogMask_EnableAll()         BteLog_EventLogMask_EnableAll( kTscDet_CI )
#define TscDet_EventLogMask_DisableAll()        BteLog_EventLogMask_DisableAll( kTscDet_CI )
#define TscDet_EventLogMask_Enable(eventId)     BteLog_EventLogMask_Enable( kTscDet_CI, eventId )
#define TscDet_EventLogMask_Disable(eventId)    BteLog_EventLogMask_Disable( kTscDet_CI, eventId )



/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
/*--- standard BTE function prototypes ------------------------------------------------------------------------------*/
void TscDet_Init( void );
void TscDet_Cyclic1ms( void );

/*--- wrapper function prototypes -----------------------------------------------------------------------------------*/

/*--- stub function prototypes --------------------------------------------------------------------------------------*/
/* prototype for Det_ReportError defined in Det.h */

/*--- stub function control prototypes ------------------------------------------------------------------------------*/

/*--- stub assert event function prototypes -------------------------------------------------------------------------*/
void TscDet_SetDetAsError( uint8 value );

#endif /* TSCDET_HEADER */
/***********************************************************************************************************************
 *  END OF FILE
 **********************************************************************************************************************/

