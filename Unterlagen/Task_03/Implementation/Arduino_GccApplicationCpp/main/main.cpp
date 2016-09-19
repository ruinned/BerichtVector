/**********************************************************************************************************************
*  COPYRIGHT
*  -------------------------------------------------------------------------------------------------------------------
*  \verbatim
*  Copyright (c) 2016 by Vector Informatik GmbH.                                              All rights reserved.
*
*                This software is copyright protected and proprietary to Vector Informatik GmbH.
*                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
*                All other rights remain with Vector Informatik GmbH.
*  \endverbatim
*  -------------------------------------------------------------------------------------------------------------------
*  FILE DESCRIPTION
*  -----------------------------------------------------------------------------------------------------------------*/
/**     \file     main.c
*       \brief    Main source file of the embedded controller ATmega328P to initialize the needed modules
*
*       \details  Inside the main method take place the call of the module initialization methods
*
*********************************************************************************************************************/

/**********************************************************************************************************************
*  INCLUDES
*********************************************************************************************************************/
#include <avr/interrupt.h>
#include "HardwareSerial.h"
#include "Std_Types.h"
#include "trcvDio.h"
#include "protocol.h"

/**********************************************************************************************************************
*  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/*! \brief Configuration struct for serial port */
volatile uint8 osTicks;

/**********************************************************************************************************************
*  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

extern "C" {
  static void init_timer(void);
};

/**********************************************************************************************************************
*  LOCAL FUNCTIONS
**********************************************************************************************************************/
/***********************************************************************************************************************
*  init_timer()
**********************************************************************************************************************/
/*! \brief     Function to configurate the Timer/Counter0 module
*  \details    External clock source (16MHz) divided by prescaler (64) results in 250kHz (4us) timer resolution.
*              For the configured reg. OCR0A=250-1 the timer is incresed from0 until 249 and cleared again.
*              Timer interrupt is thus excecuted each 1ms.
*  \return     -
*  \pre        Module must be initialized
**********************************************************************************************************************/
static void init_timer()
{
  /* switch interrupt handling off */
  cli();
  /* ----- Implementation ----------------------------------------------- */
  /* Set up timer 0 as time base */
  // 1ms cycle
  TCCR0A = 0;   // set entire TCCR2A register to 0
  TCCR0B = 0;   // same for TCCR2B
  TCNT0  = 0;   // initialize counter value to 0
  OCR0A = 249;  // set compare match register = (16*10^6) / (1000*64) - 1 (must be <256)
  /* turn on CTC mode */
  TCCR0A |= _BV(WGM01);
  /* Set CS01 and CS00 bits for 64 prescaler */
  TCCR0B |= _BV(CS01) | _BV(CS00);
  /* enable timer compare interrupt */
  TIMSK0 |= _BV(OCIE0A);
  /* switch interrupt handling on */
  sei();
}

/**********************************************************************************************************************
*  GLOBAL FUNCTIONS
**********************************************************************************************************************/

/***********************************************************************************************************************
*  main()
**********************************************************************************************************************/
/*! \brief     Main function
*  \return     0
**********************************************************************************************************************/
int main(void)
{
  /* Set up timer 0 as time base */
  init_timer();

  /* Initialize all I/O ports and save initial state */
  protocol_Init();

  /* Initialize serial interface for USB communication */
  Serial.begin(115200);
  
  /* nter endless loop */
  while(1)
  {
    while(osTicks > 0u)
    {
      /* Call the protocol handler each 1ms and clear global interrupt variable*/
      osTicks--;
      protocol_Handler();
    }
  }
  return 0;
}

/***********************************************************************************************************************
*  ISR(TIMER0_COMPA_vect)
**********************************************************************************************************************/
/*! \brief     Interrupt handling of the timer interrupt when threshold OCR0A is reached
*  \details    Global variable is increase to indicate that task is ready to be executed. Resolution of timer interrupt is 1ms
*  \return     -
*  \pre        Module must be initialized
**********************************************************************************************************************/
ISR(TIMER0_COMPA_vect)
{
  /* variable report that task in while-loop is ready to be executed */
  osTicks++;
}