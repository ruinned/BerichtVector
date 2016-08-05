/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "BteLogList.h"
#include "BteCheck.h"
#include <stdio.h>

/***********************************************************************************************************************
Local data defines
***********************************************************************************************************************/

/***********************************************************************************************************************
Local macro defines
***********************************************************************************************************************/

/***********************************************************************************************************************
Local typedefs
***********************************************************************************************************************/

/***********************************************************************************************************************
Local data definitions (RAM)
***********************************************************************************************************************/

static volatile uint8 BteLogArray[kBteLogArray_size];

static uint16 kBteLogArray_position;


/***********************************************************************************************************************
Global function definitions
***********************************************************************************************************************/
/*--- Event ---------------------------------------------------------------------------------------------------------*/

/***********************************************************************************************************************
Name:         BteEventList_Clear
Parameter:    
Return value: 
Description:  This function clears the event list.
***********************************************************************************************************************/
void BteLogList_Clear( void )
{
  kBteLogArray_position = 0;
}

void BteLogList_Message( uint8 id , uint32 time)
{
  if (id == kBteMessageType_Ok)
  {
    BteLogArray[kBteLogArray_position++] = 0xFD;
  }
  else
  {
    BteLogArray[kBteLogArray_position++] = 0xFE;
  }
  BteLogList_Serialize32(time);
}

void BteLogList_AddTestcase( uint16 id )
{
  BteLogArray[kBteLogArray_position++] = 0xFF;
  BteLogList_Serialize16(id);  

}


/* Ueber *pEvent wird erkannt, ob ein neuer Event auftritt! */
void BteLogList_AddEvent( tBteEvent *pEvent )
{

  if( kBteLogArray_position < kBteLogArray_size ) // hier muss die Ueberpruefung auf Overflow noch angepasst werden
  {
    /* Wenn kein Parameter uebergeben worden ist */    
    
    BteLogArray[kBteLogArray_position++] = (pEvent->numParam<<4)|(pEvent->type);  // Anzahl Parameter und Event-type
    
    BteLogArray[kBteLogArray_position++] = pEvent->comp;  // ID des Events
    BteLogArray[kBteLogArray_position++] = pEvent->code;  // ID des Events

    BteLogList_Serialize32(pEvent->time); // Zeit des Events
    
    if(pEvent->numParam >= 1 )
    {
      BteLogList_Serialize32(pEvent->data1);

      if(pEvent->numParam >= 2 )
      {
        BteLogList_Serialize32(pEvent->data2);

        if(pEvent->numParam >= 3)
        {
          BteLogList_Serialize32(pEvent->data3);

          if(pEvent->numParam >= 4)
          {
            BteLogList_Serialize32(pEvent->data4);

            if(pEvent->numParam == 5)
            {
              BteLogList_Serialize32(pEvent->data5);
            }
          }
        }
      }
    }
  }
  else
  {
    /* Report Event Overflow */
    BteError("BteEventList: Event Overflow - Increase Event List Size or Reduce Reported Events!!!");
  }
}


void BteLogList_Serialize32(uint32 data)
{
  BteLogArray[kBteLogArray_position++] = (uint8)(data>>24);
  BteLogArray[kBteLogArray_position++] = (uint8)((data>>16) & 0xFF);
  BteLogArray[kBteLogArray_position++] = (uint8)((data>>8) & 0xFF);
  BteLogArray[kBteLogArray_position++] = (uint8)(data & 0xFF);
}

void BteLogList_Serialize16(uint16 data)
{
  BteLogArray[kBteLogArray_position++] = (uint8)((data>>8) & 0xFF);
  BteLogArray[kBteLogArray_position++] = (uint8)(data & 0xFF);
}


void BteLogList_WriteToFile( const char* filename ) 
{
#if defined ( BTE_ENABLE_TESTREPORT )
  FILE* testF = fopen(filename, "wb");
#endif
  BteLogArray[kBteLogArray_position++] = 0x5C;  // ASCII symbol for backslash
  BteLogArray[kBteLogArray_position++] = 0x6E;  // ASCII symbol for n
  BteLogArray[kBteLogArray_position++] = 0x5C;  // ASCII symbol for backslash
  BteLogArray[kBteLogArray_position++] = 0x6E;  // ASCII symbol for n
#if defined ( BTE_ENABLE_TESTREPORT )  
  fwrite(BteLogArray, sizeof(BteLogArray), 1, testF);
  fclose(testF);
#endif
}
