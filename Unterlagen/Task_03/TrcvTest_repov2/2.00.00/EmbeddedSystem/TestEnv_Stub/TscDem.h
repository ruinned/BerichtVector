
#ifndef DEM_H
#define DEM_H

#include "rte_type.h"

/**********************************************************************************************************************
  Global data defines
**********************************************************************************************************************/
#define kTscDem_CI                                                         0x08

/*--- test stimulation ----------------------------------------------------------------------------------------------*/
/*--- stub functions ------------------------------------------------------------------------------------------------*/
#define kTscDet_Dem_ReportError                                            0x80


#define DEM_EVENT_STATUS_FAILED   1
#define DEM_EVENT_STATUS_PREFAILED 2
#define DEM_EVENT_STATUS_PREPASSED 3

//#include "Dem_IntErrId.h"

#define DemConf_DemEventParameter_AutoCreatedDemEvent_FrTrcvChannel_FRTRCV_E_FR_ERRN_TRCV 0
#define DemConf_DemEventParameter_AutoCreatedDemEvent_FrTrcvChannel_FRTRCV_E_FR_ERRN_TRCV_0 0
#define DemConf_DemEventParameter_AutoCreatedDemEvent_FrTrcvChannel_FRTRCV_E_FR_ERRN_TRCV_1 1

#define DemConf_DemEventParameter_DEM_EVENT_E_FR_ERRN_TRCV_0 0
#define DemConf_DemEventParameter_DEM_EVENT_E_FR_ERRN_TRCV_1 1

#ifndef Dem_FRTRCV_30_TJA1080_E_FR_NO_CONTROL_TRCV
  #define Dem_FRTRCV_30_TJA1080_E_FR_NO_CONTROL_TRCV 0
#endif

#ifndef Dem_FRTRCV_30_TJA1080_E_FR_ERRN_TRCV0
  #define Dem_FRTRCV_30_TJA1080_E_FR_ERRN_TRCV0 0
#endif

#ifndef Dem_FRTRCV_30_TJA1080_E_FR_ERRN_TRCV1
  #define Dem_FRTRCV_30_TJA1080_E_FR_ERRN_TRCV1 1
#endif


#include "Std_Types.h"

//typedef uint8 Dem_EventIdType;
//typedef uint8 Dem_EventStatusType;

Std_ReturnType Dem_ReportErrorStatus(
 Dem_EventIdType EventId,
 uint8 EventStatus
);



#endif /* DEM_H */
/************   Organi, Version 3.6.2 Vector-Informatik GmbH  ************/
