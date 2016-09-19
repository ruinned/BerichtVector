
#include "TscDio.h"
#include "Dio_cfg.h"

static Dio_LevelType DioLevelStatus[8] =
{
  STD_LOW,
  STD_LOW,
  STD_LOW,
  STD_LOW,
  STD_LOW,
  STD_LOW,
  STD_LOW,
  STD_LOW  
};

uint16  TrcvStatusWord[2];


void Dio_WriteChannel(Dio_ChannelType DioChannel, Dio_LevelType DioLevel)
{
  if( STD_HIGH == DioLevel )
  {
    if( DioChannel == Dio_FrTrcv_EN_A )
    {
      /* Set EN Pin to high */
#if defined(ARDUINO) 
      //ArCom_DioWriteChannel(nr, aa);
      TscArd_SetDio(0x05, 0x01);
#endif
    }
    else
      if( DioChannel == Dio_FrTrcv_STBN_A )
      {
        /* Set STBN Pin to high */
#if defined(ARDUINO) 
        TscArd_SetDio(0x03, 0x01);
#endif
      }
  }
  else
  {
    if( DioChannel == Dio_FrTrcv_EN_A )
    {
      /* Set EN Pin to low */
#if defined(ARDUINO) 
      TscArd_SetDio(0x05, 0x00);
#endif
    }
    else
      if( DioChannel == Dio_FrTrcv_STBN_A )
      {
        /* Set STBN Pin to low */
#if defined(ARDUINO) 
        TscArd_SetDio(0x03, 0x00);
#endif
      }
  }

  DioLevelStatus[DioChannel] = DioLevel;
}

Dio_LevelType Dio_ReadChannel(Dio_ChannelType DioChannel)
{

  if( DioChannel == Dio_FrTrcv_ERRN_A )
  {  
#if defined(ARDUINO)  

    uint8 aa;
    TscArd_GetDio(0x04,&aa);
    return aa;

#else
    if((TrcvStatusWord[0] & 0x4000) > 0u)
    {
      TrcvStatusWord[0] <<= 1;
      TrcvStatusWord[0] |= 1;
      return(STD_HIGH);
    }
    else
    {
      TrcvStatusWord[0] <<= 1;
      TrcvStatusWord[0] |= 1;
      return(STD_LOW);
    }
#endif
    /* Read Pin ERRN and return STD_HIGH or STD_LOW */    
  }
  else
    if( DioChannel == Dio_FrTrcv_EN_A )
    {
      /* Read Pin EN and return STD_HIGH or STD_LOW */
#if defined(ARDUINO)  
      uint8 aa;
      TscArd_GetDio(0x05,&aa);
      return aa;
#endif
    }
    else
      if( DioChannel == Dio_FrTrcv_STBN_A )
      {
        /* Read Pin STBN and return STD_HIGH or STD_LOW */
#if defined(ARDUINO)  
        uint8 aa;
        TscArd_GetDio(0x03,&aa);
        return aa;
#endif
      }

      if( DioChannel == Dio_FrTrcv_ERRN_B )
      {
        if((TrcvStatusWord[1] & 0x4000) > 0u)
        {
          TrcvStatusWord[1] <<= 1;
          TrcvStatusWord[1] |= 1;
          return(STD_HIGH);
        }
        else
        {
          TrcvStatusWord[1] <<= 1;
          TrcvStatusWord[1] |= 1;
          return(STD_LOW);
        }
        /* Read Pin ERRN and return STD_HIGH or STD_LOW */
      }
      else
        if( DioChannel == Dio_FrTrcv_EN_B )
        {
          /* Read Pin EN and return STD_HIGH or STD_LOW */
        }
        else
          if( DioChannel == Dio_FrTrcv_STBN_B )
          {
            /* Read Pin STBN and return STD_HIGH or STD_LOW */
          }

          return( DioLevelStatus[DioChannel] );

}


void Dio_SetTransceiverStatusWord(uint8 reg, uint8 shift, uint16 sw)
{
#if defined(ARDUINO)  
  if(reg == 0){

    switch(sw){
    case 0x0800u:// FRTRCV_30_TJA1080_REMOTEWAKEUP
      TscArd_WakeUpPattern(5);
      break;
    case 0x0100u:// FRTRCV_30_TJA1080_BUSERROR
      TscArd_ForceBusCollision();      
      break;
    case 0x01000u:// FRTRCV_30_TJA1080_LOCALWAKEUP
      TscArd_LokalWakeUp();
      break;      
    }    
  }
  else
  {
    TrcvStatusWord[reg] = (sw) ^ 0xffff;
    if(shift > 0)
    {
      TrcvStatusWord[reg] <<= 1;
      TrcvStatusWord[reg] |= 1;
    }
  }
#else
  TrcvStatusWord[reg] = (sw) ^ 0xffff;
  if(shift > 0)
  {
    TrcvStatusWord[reg] <<= 1;
    TrcvStatusWord[reg] |= 1;
  }
#endif
}

void Dio_Init(void)
{
  uint8 i;
  for(i=0; i<sizeof(DioLevelStatus); i++)
  {
    DioLevelStatus[i] = STD_LOW;
  }
}