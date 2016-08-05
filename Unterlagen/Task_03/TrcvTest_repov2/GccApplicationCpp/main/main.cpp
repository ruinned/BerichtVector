
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "HardwareSerial.h"
#include "Std_Types.h"
#include "Arduino.h"
#include "dio.h"
#include "protocol.h"

volatile uint32 msCounter;
volatile uint8  osTicks;
volatile uint8 mask = 0;
uint8  vAlive;

/* 1ms timer interrupt */
ISR(TIMER0_OVF_vect)
{
	osTicks++;
	msCounter++;
}



int main(void)
{
	msCounter = 0;
	
	/* First initialize all I/O ports for save initial state */
	dio_Init();
	protocol_Init();
	
	sei();
	/* Initialize timer subsystem */
	//init();
	
	/* Initialize serial interface for USB communication */
	Serial.begin(115200);
	
	/* start the SPI library: */
	//SPI.begin();
	
	/* Set up timer 0 as time base */
	/* 1ms cycle */
	OCR0A = 125-1;
	/* Fast PWM Mode */
	TCCR0A = _BV(WGM01) | _BV(WGM00);
	/* Prescaler 128 */
	TCCR0B = _BV(WGM02) | _BV(CS02) | _BV(CS00);
	/* Enable Interrupt */
	TIMSK0 = _BV(TOIE0);
	
	LEDA_TOGGLE();
	
	/* Enter endless loop */
	while(1)
	{
		while(osTicks > 0u)
		{  /* This is our 1ms task */
			osTicks--;
			vAlive++;
			if(vAlive >= 128)
			{
				vAlive -= 128;
			}
      protocol_Handler();
		}
	}
	
	return 0;
}

