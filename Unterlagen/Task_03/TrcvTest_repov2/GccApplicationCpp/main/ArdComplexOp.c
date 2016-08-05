/*
* ArdComplexOp.c
*
* Created: 2016-07-13 11:16:38
*  Author: visres
*/

#include "ArdComplexOp.h"
#include <util/delay.h>
#include <avr/io.h>
#include "dio_Cfg.h"
//#include "dio.h"

void ArdComplexOp_wakeUpPattern(uint8 aa)
{
  volatile uint8 i = 0;
  TXEN_int_LOW();
  _delay_us(100); // wait until tranceiver gets configured
  for ( ; i < aa; i++ )
  {
    TXD_int_LOW();
    TXEN_int_LOW();
    _delay_us(6);
    TXD_int_HIGH();
    TXEN_int_HIGH();
    _delay_us(18);
  }
  TXEN_int_HIGH();
}

void ArdComplexOp_lokalWakeUp()
{
  CS2_OFF();
  _delay_us(50);
  CS2_ON();
}

void ArdComplexOp_forceBusCollition()
{
  uint8 i = 0;
  TXEN_int_LOW();
  FR_TXEN_LOW();
  _delay_us(100);
  for ( ; i < 2; i++ )
  {
    TXD_int_HIGH();
    _delay_us(100);
    FR_TXD_HIGH();
    _delay_us(100);
    TXD_int_LOW();
    _delay_us(100);
    FR_TXD_LOW();
    _delay_us(100);
  }
  TXEN_int_HIGH();
  FR_TXEN_HIGH();
}

void ArdComplexOp_forceTxEntimeout()
{
  FR_TXEN_LOW();
  _delay_ms(20);
  FR_TXEN_HIGH();
}

void ArdCom_ComplexOP_ClampVbat(uint8 ed)
{
  if(ed == 0) 
    VinVBat_LOW(); 
  else
    VinVBat_HIGH();
}

