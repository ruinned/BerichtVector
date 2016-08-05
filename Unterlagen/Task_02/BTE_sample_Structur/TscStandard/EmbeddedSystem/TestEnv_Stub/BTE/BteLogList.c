/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "BteLogList.h"
#include "BteCheck.h"

/***********************************************************************************************************************
Local data defines
***********************************************************************************************************************/

/***********************************************************************************************************************
Local macro defines
***********************************************************************************************************************/

/***********************************************************************************************************************
Local typedefs
***********************************************************************************************************************/
typedef struct stBteLogList 
{
  uint16     size;
  tBteEventLog   elem[kBteLogList_size];
} tBteLogList;

/***********************************************************************************************************************
Local data definitions (RAM)
***********************************************************************************************************************/
static tBteLogList BteLogList;

static uint8 BteLogArray[1000];


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
  BteLogList.size = 0;
}

//void BteLogList_ThroughputMessage( uint16 id )
//{
//  
//
//}

void BteLogList_AddTestcase( uint16 id )
{
  BteLogList.elem[BteLogList.size].code = 0x66;
  BteLogList.elem[BteLogList.size++].data = (uint32)id; 
  /* An dieser Stelle sollte der Code hin, der die Liste als ein dataArray verwaltet*/
  //BteLogArray[currentPosition]=0x66;
  //currentPosition++;
  //BteLogArray[currentPosition]=(uint8)(id>>8);
  //currentPosition++;
  //BteLogArray[currentPosition]=(uint8)(id & 0xFF);
  //currentPosition++;
}


/* Ueber *pEvent wird erkannt, ob ein neuer Event auftritt! */
void BteLogList_Add_Event( tBteEvent *pEvent )
{
  uint16 listIndex;

  listIndex = BteLogList.size;
  if( listIndex < kBteLogList_size ) // hier muss die Ueberpruefung auf Overflow noch angepasst werden
  {

    BteLogList.elem[BteLogList.size].code = ((uint16)pEvent->numParam<<8)|(uint16)pEvent->type;
    BteLogList.elem[BteLogList.size++].data = (((uint32)pEvent->time)<<16) | (((uint32)pEvent->comp)<<8) | (uint32)pEvent->code;

    switch(pEvent->numParam) 
    {
    case 1:			
      BteLogList.elem[BteLogList.size].code = 0x21;
      BteLogList.elem[BteLogList.size++].data = pEvent->data1;
      break;
    case 2:			
      BteLogList.elem[BteLogList.size].code = 0x21;
      BteLogList.elem[BteLogList.size++].data = pEvent->data1;

      BteLogList.elem[BteLogList.size].code = 0x22;
      BteLogList.elem[BteLogList.size++].data = pEvent->data2;
      break;
    case 3:			
      BteLogList.elem[BteLogList.size].code = 0x21;
      BteLogList.elem[BteLogList.size++].data = pEvent->data1;

      BteLogList.elem[BteLogList.size].code = 0x22;
      BteLogList.elem[BteLogList.size++].data = pEvent->data2;

      BteLogList.elem[BteLogList.size].code = 0x23;
      BteLogList.elem[BteLogList.size++].data = pEvent->data3; 
      break;		
    case 4:			
      BteLogList.elem[BteLogList.size].code = 0x21;
      BteLogList.elem[BteLogList.size++].data = pEvent->data1;

      BteLogList.elem[BteLogList.size].code = 0x22;
      BteLogList.elem[BteLogList.size++].data = pEvent->data2;

      BteLogList.elem[BteLogList.size].code = 0x23;
      BteLogList.elem[BteLogList.size++].data = pEvent->data3;

      BteLogList.elem[BteLogList.size].code = 0x24;
      BteLogList.elem[BteLogList.size++].data = pEvent->data4; 
      break;
    case 5:			
      BteLogList.elem[BteLogList.size].code = 0x21;
      BteLogList.elem[BteLogList.size++].data = pEvent->data1;

      BteLogList.elem[BteLogList.size].code = 0x22;
      BteLogList.elem[BteLogList.size++].data = pEvent->data2;

      BteLogList.elem[BteLogList.size].code = 0x23;
      BteLogList.elem[BteLogList.size++].data = pEvent->data3;

      BteLogList.elem[BteLogList.size].code = 0x24;
      BteLogList.elem[BteLogList.size++].data = pEvent->data4;

      BteLogList.elem[BteLogList.size].code = 0x25;
      BteLogList.elem[BteLogList.size++].data = pEvent->data5;  
      break;

    default:
      break;
    }


  }
  else
  {
    /* Report Event Overflow */
    BteError("BteEventList: Event Overflow - Increase Event List Size or Reduce Reported Events!!!");
  }
}

//void BteLogList_AddTCASE( uint16 id )
//{
//	BteLogList.elem[BteLogList.size].code = 0x66;
//	BteLogList.elem[BteLogList.size++].data = (uint32)id;  
//}

#include <stdio.h>
void BteLogList_WriteToFile( const char* filename ) 
{
  FILE* testF = fopen(filename, "wb");
  BteLogList.elem[BteLogList.size].code= 0x5C;	// ASCII symbol for \
  //BteLogList.elem[BteLogList.size].code= 0x1C;	
  BteLogList.elem[BteLogList.size++].data= 0x6E;	// ASCII symbol for n
  //BteLogList.elem[BteLogList.size++].data= 0x1C;
  fwrite(&BteLogList, sizeof(BteLogList), 1, testF);
  fclose(testF);
}
