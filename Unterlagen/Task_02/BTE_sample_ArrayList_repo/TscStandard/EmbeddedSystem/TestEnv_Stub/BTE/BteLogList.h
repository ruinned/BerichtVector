#ifndef BTELOGLIST_HEADER
#define BTELOGLIST_HEADER

/***********************************************************************************************************************
  Includes
***********************************************************************************************************************/
#include "Bte.h"
#include "BteEvent.h"

/***********************************************************************************************************************
  Global configuration
***********************************************************************************************************************/

#define kBteLogArray_size                   1000

/***********************************************************************************************************************
  Global typedefs
***********************************************************************************************************************/

typedef enum 
{
  kBteMessageType_Ok, //0x00
  kBteMessageType_Error,   //0x01
} tBteMessageType;

/***********************************************************************************************************************
  Global function prototypes
***********************************************************************************************************************/
/*--- List ---------------------------------------------------------------------------------------------------------*/
void BteLogList_AddTestcase( uint16 id);

void BteLogList_Clear( void );

void BteLogList_Serialize32(uint32 data);
void BteLogList_Serialize16(uint16 data);
/*--- Event ---------------------------------------------------------------------------------------------------------*/
void BteLogList_AddEvent( tBteEvent *pEvent );
/* Debug */
void BteLogList_WriteToFile( const char* filename );
void BteLogList_Message( uint8 id , uint32 time );


// Methoden, die in anderen Files eingebunden werden
// BteTestHandler File
void BteTestCase_SetData_ID( uint16 id_num );
void BteTestCase_ResetData_ID(void);
void BteTestSequence_BeginID( uint16 id ); // neue Methode
void BteTestSequence_PreBegin(void);
void BteTestSequence_BeginReport(uint8 *id);
void BteTestSequence_Begin_Intern(void);

#endif /* BTELOGLIST_HEADER */
