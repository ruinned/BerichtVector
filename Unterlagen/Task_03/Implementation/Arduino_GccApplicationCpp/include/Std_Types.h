/*------------------------------------------*/
/* gcc typedefinitions                      */
/* Diese definitions gelten fuer den gcc    */
/* mit der Compileroption -mshort           */
/*                                          */
/* File        : Std_Types.h                */
/* Author      : Andreas Herkommer          */
/* Last Update :		                    */
/*------------------------------------------*/

#ifndef STD_TYPES_H
#define STD_TYPES_H

//#include <avr/pgmspace.h>

#define enable() sei()
#define disable() cli()
#define TRUE  (0u==0u)
#define FALSE (1u==0u)

/* Byte order definition */
#define HIGH_BYTE_FIRST   0                 /* Big endian byte ordering       */
#define LOW_BYTE_FIRST    1                 /* Little endian byte ordering    */


/* Type for boolean values */
//typedef unsigned char       bool;
//typedef unsigned char       boolean;

/* Types for bitfields */
typedef unsigned char       bit8;
typedef unsigned short      bit16;
typedef unsigned long       bit32;

/* Types for integer values */

#if !defined ( uint8_t )
  typedef unsigned char       uint8_t;
#endif
#if !defined ( int8_t )
  typedef signed char         int8_t;
#endif
#if !defined ( uint16_t )
  typedef unsigned int        uint16_t;
#endif
#if !defined ( int16_t )
  typedef signed int          int16_t;
#endif
#if !defined ( uint32_t )
  typedef unsigned long       uint32_t;
#endif
#if !defined ( int32_t )
  typedef signed long         int32_t;
#endif
#if !defined ( uint64_t )
  typedef unsigned long long  uint64_t;
#endif
#if !defined ( int64_t )
  typedef signed long long    int64_t;
#endif

#if !defined ( uint8 )
  typedef unsigned char       uint8;
#endif
#if !defined ( sint8 )
  typedef signed char         sint8;
#endif
#if !defined ( uint16 )
  typedef unsigned int        uint16;
#endif
#if !defined ( sint16 )
  typedef signed int          sint16;
#endif
#if !defined ( uint32 )
  typedef unsigned long       uint32;
#endif
#if !defined ( sint32 )
  typedef signed long         sint32;
#endif


#if !defined ( uint8_least )
  typedef unsigned char       uint8_least;
#endif
#if !defined ( uint16_least )
  typedef unsigned int        uint16_least;
#endif
#if !defined ( uint32_least )
  typedef unsigned long       uint32_least;
#endif


/* Types for floating point values */
#if !defined ( real32 )
  typedef float               real32;
#endif
#if ! defined ( real64 )
  typedef double              real64;
#endif

/* Types for packed values */
typedef struct {uint8_t   l; int8_t   h;}  int16_s;
typedef struct {uint8_t   l; uint8_t   h;} uint16_s;
typedef struct {uint16_t  l; int16_t  h;}  int32_s;
typedef struct {uint16_t  l; uint16_t  h;} uint32_s;
typedef struct {uint32_t  l; int32_t  h;}  int64_s;
typedef struct {uint32_t  l; uint32_t  h;} uint64_s;
typedef struct {uint8_t ll; uint8_t lh; uint8_t hl; uint8_t hh;} u4b_s;
typedef struct {int8_t ll; int8_t lh; int8_t hl; int8_t hh;} s4b_s;

typedef union {int16_s  s16s; int16_t  s16;} int16_u;
typedef union {uint16_s u16s; uint16_t u16;} uint16_u;
typedef union {s4b_s s4bs; int32_s  s32s; int32_t  s32;} int32_u;
typedef union {u4b_s u4bs; uint32_s u32s; uint32_t u32;} uint32_u;
typedef union {int64_s  s64s; int64_t  s64;} int64_u;
typedef union {uint64_s u64s; uint64_t u64;} uint64_u;


#ifndef STATIC
  #define STATIC static
#endif

#ifndef STD_ON
  #define STD_ON 1u
#endif
#ifndef STD_OFF
  #define STD_OFF 0u
#endif

#ifndef NULL_PTR
  #define NULL_PTR    ((void *)0)   //!< null pointer value
#endif


#ifndef E_OK
  #define E_OK 0
#endif

#ifndef E_NOT_OK
  #define E_NOT_OK 1
#endif

#endif
  /* STD_TYPES_H */
