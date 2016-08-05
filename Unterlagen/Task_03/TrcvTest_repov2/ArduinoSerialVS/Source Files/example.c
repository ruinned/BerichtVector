#include "DIO.h"
#include "ArduinoCom.h"
#include "ArdTest.h"
#include <stdio.h>

int main()
{  

  uint16 statusWord;
  uint8 eingabe[6];
  int i;
  uint8 entry;
  uint8 nr;
  uint8 ed = 0;
  uint8 aa = 0;
  uint8 pinStatus;


#if defined(ARDUINO)  
  // Trcv is in normal mode as initial condition is defined by STBN=HIGH, EN=HIGH
  ArdTest_Init(TRCV_MODE, ARD_COMPORT);

  ArdCom_WriteReadTRCVStatusWord(TRCV_MODE, &statusWord);

  printf("\n\n +==========================================+");
  printf("\n  give any of the following entries:          ");
  printf("\n\n       0 = Send remote wake up command          ");
  printf("\n       6 = Send local wake up          ");
  printf("\n       1 = Force Bus Collision          ");
  printf("\n       2 = Force TxEN Time out Condition          ");
  printf("\n       3 = VBAT          ");
  printf("\n       4 = reset dio pins of test trcv and helping trcv (high as init cond.)           ");
  printf("\n       5 = get DIO-Pin state           ");
  printf("\n       else = Clamp BM or BP high          ");
  printf("\n +==========================================+\n\n");

  for(i = 0; i < 10; i++)
  {

    printf("\n\n give an entry please: \n\n");
    scanf("%d", eingabe);
    entry = eingabe[0];

    switch(entry)
    {
    case 0:
      // Transceiver in sleep mode versetzen
      Dio_WriteChannel(dio_STBN, STD_LOW); 
      Dio_WriteChannel(dio_EN, STD_LOW);
      ArdCom_WriteReadTRCVStatusWord(TRCV_MODE, &statusWord);
      // Fuenf mal, das Pattern wiederholen
      aa = 5;
      ArdCom_ComplexOp_WakeUpPattern(aa);
      ArdCom_WriteReadTRCVStatusWord(TRCV_MODE, &statusWord);
      Dio_WriteChannel(dio_STBN, STD_HIGH); 
      Dio_WriteChannel(dio_EN, STD_HIGH);
      break;
    case 6:
      // local wake up flag set only in low power mode
      Dio_WriteChannel(dio_STBN, STD_LOW); 
      Dio_WriteChannel(dio_EN, STD_HIGH);
      ArdCom_WriteReadTRCVStatusWord(TRCV_MODE, &statusWord);
      ArdCom_ComplexOp_LokalWakeUp();
      //Dio_WriteChannel(dio_STBN, STD_HIGH); 
      //Dio_WriteChannel(dio_EN, STD_HIGH);      
      break;
    case 1:
      ArdCom_ComplexOp_ForceBusCollision();
      break;
    case 2:
      ArdCom_ComplexOp_ForceTXENTimeout();
      break;
    case 3:
      printf("\n\n      VBAT entry Enable/Disable-Bit: 0 = VBAT to GND, 1 = VBAT equal Vin          \n\n");
      scanf("%d", eingabe);
      ed = eingabe[0];
      ArdCom_ComplexOP_ClampVbat(ed);
      break;
    case 5:
      printf("\n\n      Give the number of corresponding pin:       \n\n");
      scanf("%d", eingabe);
      nr = eingabe[0];
      ArCom_DioReadChannel(nr,&pinStatus);
      printf("\n\n %d Pin Status = %d", nr, pinStatus);
      break;
    case 4:
      ArCom_ResetAllDioPins();
      break;
    }
    ArdCom_WriteReadTRCVStatusWord(TRCV_MODE, &statusWord);
    printf("\n\n Status Word = %x", statusWord);
    ArdCom_WriteReadTRCVStatusWord(TRCV_MODE, &statusWord);
    printf("\n\n Status Word = %x", statusWord);
  }

  ArdTest_Deinit();

#endif

  return (0);

}







