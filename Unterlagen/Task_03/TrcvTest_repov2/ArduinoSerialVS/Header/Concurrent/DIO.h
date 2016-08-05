#ifndef DIO_H
#define DIO_H

#include "Std_Types.h"

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

/* ----- Modes ----- */
#define STD_HIGH                                 (0x01)
#define STD_LOW                                  (0x00)

void Dio_WriteChannel(uint8 Channel, uint8 value);

uint8 Dio_ReadChannel(uint8 Channel);



#endif