/* PRQA S 0883 ++ */
/***********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  Copyright (c) 2015 by Vector Informatik GmbH.                                                  All rights reserved.

                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
         File:  MemMap.h
      Project:  Tsc for SysService_Issm_Volvo_ab
       Module:  -
    Generator:  -
  Description:  
***********************************************************************************************************************/

/***********************************************************************************************************************
  AUTHOR IDENTITY
-----------------------------------------------------------------------------------------------------------------------
  Initials     Name                      Company
-----------------------------------------------------------------------------------------------------------------------
  vismas       Markus Schwarz            Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
-----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Change Id     Description
-----------------------------------------------------------------------------------------------------------------------
  1.00.00   2008-08-22  vismas                creation
  1.01.00   2009-05-06  vismas                updated to 1.05.00 of _MemMap.h
***********************************************************************************************************************/

/* NOTE: no include protection allowed here */

/***********************************************************************************************************************
  Includes
***********************************************************************************************************************/
/* PRQA S 0883 EOF */
#include "Mip_MemMap.inc"

/***********************************************************************************************************************
  Version data
***********************************************************************************************************************/

/***********************************************************************************************************************
  Checks
***********************************************************************************************************************/
#define MEMMAP_ERROR

/* Check code sections */
#if ( (defined CODE_SEC_OPEN)                            && \
     ((defined START_SEC_CODE                          ) || \
      (defined START_SEC_CODE_FAST                     ) || \
      (defined START_SEC_CODE_ISR                      )    \
      ))
  #error "MemMap.h: Close the former code segment before opening a new one."
#endif

/* Check const sections */
#if ( (defined CONST_SEC_OPEN)                           && \
     ((defined START_SEC_CONST_8                    ) || \
      (defined START_SEC_CONST_16                   ) || \
      (defined START_SEC_CONST_32                   ) || \
      (defined START_SEC_CONST_UNSPECIFIED             ) || \
      (defined START_SEC_CONST_FAST_8               ) || \
      (defined START_SEC_CONST_FAST_16              ) || \
      (defined START_SEC_CONST_FAST_32              ) || \
      (defined START_SEC_CONST_FAST_UNSPECIFIED        ) || \
      (defined START_SEC_CONST_PBCFG                   )    \
      ))
  #error "MemMap.h: Close the former const segment before opening a new one."
#endif

/* Check data sections */
#if ( (defined VAR_SEC_OPEN)                             && \
     ((defined START_SEC_VAR_INIT_8                 ) || \
      (defined START_SEC_VAR_INIT_16                ) || \
      (defined START_SEC_VAR_INIT_32                ) || \
      (defined START_SEC_VAR_INIT_UNSPECIFIED          ) || \
      (defined START_SEC_VAR_NOINIT_8               ) || \
      (defined START_SEC_VAR_NOINIT_16              ) || \
      (defined START_SEC_VAR_NOINIT_32              ) || \
      (defined START_SEC_VAR_NOINIT_UNSPECIFIED        ) || \
      (defined START_SEC_VAR_ZERO_INIT_8            ) || \
      (defined START_SEC_VAR_ZERO_INIT_16           ) || \
      (defined START_SEC_VAR_ZERO_INIT_32           ) || \
      (defined START_SEC_VAR_ZERO_INIT_UNSPECIFIED     ) || \
      (defined START_SEC_VAR_FAST_INIT_8            ) || \
      (defined START_SEC_VAR_FAST_INIT_16           ) || \
      (defined START_SEC_VAR_FAST_INIT_32           ) || \
      (defined START_SEC_VAR_FAST_INIT_UNSPECIFIED     ) || \
      (defined START_SEC_VAR_FAST_NOINIT_8          ) || \
      (defined START_SEC_VAR_FAST_NOINIT_16         ) || \
      (defined START_SEC_VAR_FAST_NOINIT_32         ) || \
      (defined START_SEC_VAR_FAST_NOINIT_UNSPECIFIED   ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_8       ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_16      ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_32      ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)    \
      ))
    #error "MemMap.h: Close the former variable segment before opening a new one."
#endif



/*------------------------------GLOBAL-START-SECTIONS------------------------------*/

/* Code section */
#ifdef START_SEC_CODE                          
    #define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CODE_FAST                     
    #define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CODE_FAST                     /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CODE_ISR                      
    #define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CODE_ISR                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif




/* Const section */
#ifdef START_SEC_CONST_8                    
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_8                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_16                   
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_16                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_32                   
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_32                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_UNSPECIFIED             
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_UNSPECIFIED             /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_FAST_8               
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_8               /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_FAST_16              
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_16              /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_FAST_32              
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_32              /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_FAST_UNSPECIFIED        
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_UNSPECIFIED        /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_PBCFG                   
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_PBCFG                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif



/* Var section */
#ifdef START_SEC_VAR_INIT_8                 
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_INIT_8                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_INIT_16                
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_INIT_16                /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_INIT_32                
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_INIT_32                /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_INIT_UNSPECIFIED          
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_INIT_UNSPECIFIED          /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_NOINIT_8               
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOINIT_8               /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_NOINIT_16              
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOINIT_16              /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_NOINIT_32              
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOINIT_32              /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOINIT_UNSPECIFIED        /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZERO_INIT_8            
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_ZERO_INIT_8            /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZERO_INIT_16           
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_ZERO_INIT_16           /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZERO_INIT_32           
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_ZERO_INIT_32           /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_ZERO_INIT_UNSPECIFIED     
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_ZERO_INIT_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_INIT_8            
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_INIT_8            /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_INIT_16           
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_INIT_16           /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_INIT_32           
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_INIT_32           /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_INIT_UNSPECIFIED     
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_INIT_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_8          
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_NOINIT_8          /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_16         
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_NOINIT_16         /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_32         
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_NOINIT_32         /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_UNSPECIFIED   
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_NOINIT_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_8       
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_ZERO_INIT_8       /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_16      
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_ZERO_INIT_16      /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_32      
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_ZERO_INIT_32      /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif



/*------------------------------GENERAL-STOP-SECTIONS-------------------------------*/

/*default segment for Code*/
#ifdef STOP_SEC_CODE
    #undef CODE_SEC_OPEN  /* PRQA S 0841 */ /* MD_MSR_19.6 */
/* Enter here a #pragma command for closing the specified section */
/* This should switch back to the default section */
/*    #pragma */
    #undef STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif

/*default segment for Constants*/
#ifdef STOP_SEC_CONST
    #undef CONST_SEC_OPEN
/* Enter here a #pragma command for closing the specified section */
/* This should switch back to the default section */
/*    #pragma */
    #undef STOP_SEC_CONST /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif

/*default segment for Datas*/
#ifdef STOP_SEC_VAR
    #undef VAR_SEC_OPEN
/* Enter here a #pragma command for closing the specified section */
/* This should switch back to the default section */
/*    #pragma */
    #undef STOP_SEC_VAR /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR
#endif

#ifdef MEMMAP_ERROR
  #error "MemMap.h, wrong pragma command"
#endif

/***********************************************************************************************************************
  Global macro defines
***********************************************************************************************************************/

/***********************************************************************************************************************
  Global typedefs
***********************************************************************************************************************/

/***********************************************************************************************************************
  Global data prototypes (RAM)
***********************************************************************************************************************/

/***********************************************************************************************************************
  Global data prototypes (ROM)
***********************************************************************************************************************/

/***********************************************************************************************************************
  Global function prototypes
***********************************************************************************************************************/

/***********************************************************************************************************************
  EOF
***********************************************************************************************************************/
/* PRQA S 0883 -- */
