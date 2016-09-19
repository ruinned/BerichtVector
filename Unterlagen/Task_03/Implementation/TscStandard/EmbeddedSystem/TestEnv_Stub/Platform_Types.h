/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2008 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Platform_Types.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Provision of Platform Types for MPC5500
 *  
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *      
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Joachim Kalmbach              Jk            Vector Informatik
 *  Senol Cendere                 Ces           Vector Informatik
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2007-11-06  Jk                    Template creation
 *  01.01.00  2008-02-19  Ces                   Support MPC5500
 *  01.01.01  2008-12-03  Ces                   Removed boolean cast from define TRUE and define FALSE
                                                Added typedef sint64 and uint64
 *  01.01.02  2011-03-17  Ces                   Change sint32 and uint32
 *********************************************************************************************************************/
#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* ##V_CFG_MANAGEMENT ##CQProject : CommonAsr_Mpc5500 CQComponent : Impl_PlatformTypes */
#define COMMONASR_MPC5500_IMPL_PLATFORMTYPES_VERSION           0x0101u
#define COMMONASR_MPC5500_IMPL_PLATFORMTYPES_RELEASE_VERSION   0x02u

#define PLATFORM_VENDOR_ID    30u
 
/* AUTOSAR Software Specification Version Information */
#define PLATFORM_AR_MAJOR_VERSION       (2u)
#define PLATFORM_AR_MINOR_VERSION       (2u)
#define PLATFORM_AR_PATCH_VERSION       (1u)

/* Component Version Information */
#define PLATFORM_SW_MAJOR_VERSION       (1u)
#define PLATFORM_SW_MINOR_VERSION       (1u)
#define PLATFORM_SW_PATCH_VERSION       (2u) 


#define CPU_TYPE_8       8
#define CPU_TYPE_16      16
#define CPU_TYPE_32      32

#define MSB_FIRST        0    /* big endian bit ordering */
#define LSB_FIRST        1    /* little endian bit ordering */

#define HIGH_BYTE_FIRST  0    /* big endian byte ordering */
#define LOW_BYTE_FIRST   1    /* little endian byte ordering */

#ifndef TRUE
   #define TRUE   1
#endif

#ifndef FALSE
   #define FALSE  0
#endif

#define CPU_TYPE         CPU_TYPE_32

#define CPU_BIT_ORDER    MSB_FIRST

#define CPU_BYTE_ORDER   HIGH_BYTE_FIRST
                      
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef unsigned char       boolean; /*                 TRUE .. FALSE                */
typedef signed char         sint8;   /*                 -128 .. +127                 */
typedef unsigned char       uint8;   /*                    0 .. 255                  */
typedef signed short        sint16;  /*               -32768 .. +32767               */
typedef unsigned short      uint16;  /*                    0 .. 65535                */
typedef signed long         sint32;  /*          -2147483648 .. +2147483647          */
typedef unsigned long       uint32;  /*                    0 .. 4294967295           */
typedef signed long long    sint64;  /* -9223372036854775808 .. 9223372036854775807  */
typedef unsigned long long  uint64;  /*                    0 .. 18446744073709551615 */
                                      
typedef signed int          sint8_least;  /* At least 7 bit + 1 bit sign    */
typedef unsigned int        uint8_least;  /* At least 8 bit                 */
typedef signed int          sint16_least; /* At least 15 bit + 1 bit sign   */
typedef unsigned int        uint16_least; /* At least 16 bit                */
typedef signed long         sint32_least; /* At least 31 bit + 1 bit sign   */
typedef unsigned long       uint32_least; /* At least 32 bit                */
                                        
typedef float  float32;
typedef double float64;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* PLATFORM_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Platform_Types.h
 *********************************************************************************************************************/
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
