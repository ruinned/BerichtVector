/* Test Stub for Dio */

#include "TscDio.h"

#ifndef FRTRCV_CBK_MAJOR_VERSION
extern uint8 enableDemError;
# undef  BUSTRCV_E_OK
# define BUSTRCV_E_OK ((enableDemError == 1)?0x01:0x00)
#endif

