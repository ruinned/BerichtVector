


/* Per default enable all pull-up resistors in the port configuration */
/* all pins are input by default */
/*
  PB5: Input SCK/EN pull-up
  PB4: Input MISO/ERRN pull-up
  PB3: Input MOSI/STBN pull-up
  PB2: Input CS1 pull-up
  PB1: Input FR_TXD pull-up
  PB0: Input FR_RXD pull-up
*/
#define DDRB_INIT       0x00
#define PORTB_INIT      0x3f

/* all pins are output */
/*
  PC5: Output LED 1 //an bei 0
  PC4: Output CS2/LOKAL_WU 1 
  PC3: Output STBY_int 1
  PC2: Output Clamp BM 0
  PC1: Output Clamp BP 0
  PC0: Output VBat 1
*/
#define DDRC_INIT       0x3f
#define PORTC_INIT      0x39

/*
  PD7: Input RXD_int
  PD6: Output TXD_int 1
  PD5: Output FR_TXEN 1
  PD4: Output FR_TXEN_int 1
  PD3: Input INTN2 pull-up
  PD2: Input INTN1 pull-up
  PD1: Input RS232 TXD
  PD0: Input RS232 RXD
*/
#define DDRD_INIT       0x70
#define PORTD_INIT      0x7c

#define LED_OFF() PORTC |= (_BV(PC5))
#define LED_ON()  PORTC &= (uint8)(~_BV(PC5))
#define LED_TOGGLE() PORTC ^= _BV(PC5)

#define LEDA_OFF() PORTB &= (uint8)(~_BV(PB5))
#define LEDA_ON() PORTB |= (_BV(PB5))
#define LEDA_TOGGLE() PORTB ^= _BV(PB5)

#define CS1_OFF() PORTB &= (uint8)(~_BV(PB2))
#define CS1_ON() PORTB |= _BV(PB2)

#define CS2_OFF() PORTC &= (uint8)(~_BV(PC4))
#define CS2_ON() PORTC |= _BV(PC4)

#define EN_HIGH() PORTB |= _BV(PB5)
#define EN_LOW()  PORTB &= (uint8)(~_BV(PB5))

#define STBN_HIGH() PORTB |= _BV(PB3)
#define STBN_LOW()  PORTB &= (uint8)(~_BV(PB3))

#define FR_TXD_HIGH() PORTB |= _BV(PB1)
#define FR_TXD_LOW()  PORTB &= (uint8)(~_BV(PB1))

#define ERRN_HIGH() PORTB |= _BV(PB4)
#define ERRN_LOW()  PORTB &= (uint8)(~_BV(PB4))

#define RXD_HIGH() PORTD |= _BV(PD0)
#define RXD_LOW()  PORTD &= (uint8)(~_BV(PD0))

#define TXD_HIGH() PORTD |= _BV(PD1)
#define TXD_LOW()  PORTD &= (uint8)(~_BV(PD1))

#define INTN1_HIGH() PORTD |= _BV(PD2)
#define INTN1_LOW()  PORTD &= (uint8)(~_BV(PD2))

#define INTN2_HIGH() PORTD |= _BV(PD3)
#define INTN2_LOW()  PORTD &= (uint8)(~_BV(PD3))

#define TXEN_int_HIGH() PORTD |= _BV(PD4)
#define TXEN_int_LOW()  PORTD &= (uint8)(~_BV(PD4))

#define FR_TXEN_HIGH() PORTD |= _BV(PD5)
#define FR_TXEN_LOW()  PORTD &= (uint8)(~_BV(PD5))

#define TXD_int_HIGH() PORTD |= _BV(PD6)
#define TXD_int_LOW()  PORTD &= (uint8)(~_BV(PD6))

#define RXD_int_HIGH() PORTD |= _BV(PD7)
#define RXD_int_LOW()  PORTD &= (uint8)(~_BV(PD7))

#define VinVBat_HIGH() PORTC |= _BV(PC0)
#define VinVBat_LOW()  PORTC &= (uint8)(~_BV(PC0))

#define CLAMP_GND_BP_HIGH() PORTC |= _BV(PC1)
#define CLAMP_GND_BP_LOW()  PORTC &= (uint8)(~_BV(PC1))

#define CLAMP_GND_BM_HIGH() PORTC |= _BV(PC2)
#define CLAMP_GND_BM_LOW()  PORTC &= (uint8)(~_BV(PC2))

#define STBY_int_HIGH() PORTC |= _BV(PC3)
#define STBY_int_LOW()  PORTC &= (uint8)(~_BV(PC3))

//#define DO(val)	

#define dio_FR_RXD          0u
#define dio_FR_TXD          1u
#define dio_CS1             2u
#define dio_STBN            3u
#define dio_ERRN            4u
#define dio_EN              5u
#define dio_RXD             6u
#define dio_TXD             7u
#define dio_INTN1           8u
#define dio_INTN2           9u
#define dio_TXEN_int        10u
#define dio_FR_TXEN         11u
#define dio_TXD_int         12u
#define dio_RXD_int         13u
#define dio_Vin             14u
#define dio_Clamp_GND_BP    15u
#define dio_Clamp_GND_BM    16u
#define dio_STBY_int        17u
#define dio_CS2             18u
#define dio_LED             19u



