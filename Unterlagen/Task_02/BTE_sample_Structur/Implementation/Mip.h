/***********************************************************************************************************************
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
/*!        \file  Mip.h
 *        \brief  Mip header file
 *      \details  Template component to demonstrate the usage of the MICROSAR C style guide. The token Mip/MIP always
 *                has to be read as "Module Short Name" and has to be replaced by the appropriate module prefix as
 *                defined by AUTOSAR, when this template is used for implementation.
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Hartmut Hoerner               vishh         Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  15.00.00  2016-001-14 vismas  -             generic component
 **********************************************************************************************************************/

#if !defined (MIP_H)
# define MIP_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
# include "Mip_Cfg.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/* Vendor and module identification */
# define MIP_VENDOR_ID                           (30u)
# define MIP_MODULE_ID                           (0x00u)

/* AUTOSAR Software specification version information */
# define MIP_AR_RELEASE_MAJOR_VERSION            (4u)
# define MIP_AR_RELEASE_MINOR_VERSION            (0u)
# define MIP_AR_RELEASE_REVISION_VERSION         (3u)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define MIP_SW_MAJOR_VERSION                    (3u)
# define MIP_SW_MINOR_VERSION                    (0u)
# define MIP_SW_PATCH_VERSION                    (0u)

# define MIP_INSTANCE_ID_DET                     (0x00u)

/* ----- API service IDs ----- */
/*!< Service ID: Mip_Init() */
# define MIP_SID_INIT                            (0x00u)
/*!< Service ID: Mip_GlobalExampleFunction() */
# define MIP_SID_GLOBAL_EXAMPLE_FUNCTION         (0x01u)
/*!< Service ID: Mip_GetVersionInfo() */
# define MIP_SID_GET_VERSION_INFO                (0x10u)

/* ----- Error codes ----- */
/*!
 *  /defgroup errorIDs Error IDs
 */
/*! used to check if no error occurred - use a value unequal to any error code */
# define MIP_E_NO_ERROR                          (0x00u)
/*! Error code: API service Mip_Init() called with wrong parameter */
# define MIP_E_PARAM                             (0x0Fu)
# define MIP_E_PARAM_CONFIG                      (0x0Au)
/*! Error Code: API service used with an invalid channel identifier or channel was not configured for the 
 *              functionality of the calling API */
# define MIP_E_PARAM_CHANNEL                     (0x0Bu)
/*! Error code: API service used with invalid value parameter */
# define MIP_E_PARAM_POINTER                     (0x0Cu)
/*! Error code: API service used without module initialization */
# define MIP_E_UNINIT                            (0x10u)
/*! Error code: The service Mip_Init() is called while the module is already initialized  */
# define MIP_E_ALREADY_INITIALIZED               (0x11u)
/*! Error code: API service called with NULL_PTR as parameter  */

/* ----- Modes ----- */
# define MIP_UNINIT                              (0x00u)
# define MIP_INIT                                (0x01u)

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/*! Example of a function-like macro */
# define MIP_DO_SOMETHING(XYZ, ABC)              ((XYZ) = (ABC) + 1) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

# define MIP_START_SEC_VAR_NOINIT_32
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Example global variable definition */
extern VAR(uint32, MIP_VAR_NOINIT) Mip_ExampleValue;

# define MIP_STOP_SEC_VAR_NOINIT_32
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define MIP_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  Mip_InitMemory()
 ***********************************************************************************************************************/
/*! \brief      Function for *_INIT_*-variable initialization
 *  \details    Service to initialize module global variables at power up. This function initializes the
 *              variables in *_INIT_* sections. Used in case they are not initialized by the startup code.
 *  \pre        Module is uninitialized.
 *  \reentrant  FALSE
 *  \synchronous  TRUE
 *  \context    TASK
 ***********************************************************************************************************************/
FUNC(void, MIP_CODE) Mip_InitMemory(void);

/***********************************************************************************************************************
 * Mip_Init()
 ***********************************************************************************************************************/
/*! \brief        Initialization function
 *  \details      This function initializes the module Mip. It initializes all variables and sets the module state to
 *                initialized.
 *  \param[in]    ConfigPtr               Configuration structure for initializing the module
 *  \pre          Interrupts are disabled.
 *  \pre          Module is uninitialized.
 *  \pre          Mip_InitMemory has been called unless Mip_ModuleInitialized is initialized by start-up code.
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 ***********************************************************************************************************************/
FUNC(void, MIP_CODE) Mip_Init(P2CONST(Mip_ConfigType, AUTOMATIC, MIP_PBCFG) ConfigPtr);

/***********************************************************************************************************************
 * Mip_MainFunction()
 ***********************************************************************************************************************/
/*! \brief        TBD
 *  \details      TBD
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          -
 ***********************************************************************************************************************/
FUNC(void, MIP_CODE) Mip_MainFunction(void);

/***********************************************************************************************************************
 *  Mip_GlobalExampleFunction()
 ***********************************************************************************************************************/
/*! \brief        Example of a global function
 *  \details      Example of a global function. The description of this function is always visible in
 *                the doxygen documentation.
 *  \param[in]    Channel                 Input parameter, must be in range of <?>.
 *  \param[out]   Value                   Output parameter reference, must not be NULL_PTR.
 *  \return       E_NOT_OK - function has been called with invalid parameters
 *  \return       E_OK - success
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          Module is initialized.
 *  \trace        CREQ-123, CREQ-456, CREQ-9999 any more text
 *  \trace        DSGN-56587
 *  \trace        SI-234
 ***********************************************************************************************************************/
FUNC(uint8, MIP_CODE) Mip_GlobalExampleFunction(uint8 Channel, P2VAR(uint16, AUTOMATIC, MIP_APPL_VAR) Value);


# if (MIP_VERSION_INFO_API == STD_ON)
/***********************************************************************************************************************
 *  Mip_GetVersionInfo()
 ***********************************************************************************************************************/
/*! \brief        Returns the version information
 *  \details      Mip_GetVersionInfo() returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]   versioninfo             Pointer to where to store the version information. Parameter must not be NULL.
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          -
 ***********************************************************************************************************************/
FUNC(void, MIP_CODE) Mip_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, MIP_APPL_VAR) versioninfo);
# endif

/***********************************************************************************************************************
 *  Mip_SampleA()
 ***********************************************************************************************************************/
/*! \brief        TBD
 *  \details      TBD
 *  \context      TASK
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, MIP_CODE) Mip_SampleA(void);

/***********************************************************************************************************************
 *  Mip_SampleB()
 ***********************************************************************************************************************/
/*! \brief        TBD
 *  \details      TBD
 *  \param[in]    
 *  \context      TASK
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, MIP_CODE) Mip_SampleB(uint8 handleB);

/***********************************************************************************************************************
 *  Mip_SampleC()
 ***********************************************************************************************************************/
/*! \brief        TBD
 *  \details      TBD
 *  \param[in]    
 *  \context      TASK
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, MIP_CODE) Mip_SampleC( uint8 handle, uint16 ptr );

/***********************************************************************************************************************
 *  Mip_SampleD()
 ***********************************************************************************************************************/
/*! \brief        TBD
 *  \details      TBD
 *  \param[in]    
 *  \context      TASK
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, MIP_CODE) Mip_SampleD( uint8 handle, uint16 ptr );

/***********************************************************************************************************************
 *  Mip_UnInit()
 ***********************************************************************************************************************/
/*! \brief        Mip_UnInit
 *  \details      TBD
 *  \param[out]   
 *  \context      TASK
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 ***********************************************************************************************************************/
FUNC(void, MIP_CODE) Mip_UnInit( void );



/***********************************************************************************************************************
 *  Mip_GlobalNotDeclaredFunction()
 ***********************************************************************************************************************/
/*! \fn         uint8 Mip_GlobalNotDeclaredFunction(uint8 Channel)
 *  \brief      Example of a global function
 *  \details    Example of a global function. The description of this function is always visible in
 *              the doxygen documentation.
 *  \param[in]  Channel                 Input parameter, must be in range of <?>.
 *  \return     E_NOT_OK - function has been called with invalid parameters
 *  \return     E_OK - success
 *  \context    TASK
 *  \reentrant  FALSE
 *  \synchronous  TRUE
 *  \pre        -
 *  \trace      CREQ-123, SI-234
 ***********************************************************************************************************************/

# define MIP_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  EXCLUSIVE AREA DEFINITION
 **********************************************************************************************************************/
/*! \page allEA Exclusive Areas
 * \exclusivearea CAN_EXCLUSIVE_AREA_1
 * Ensures consistency while modifying the interrupt counter and CAN interrupt lock registers.
 * \protects canCanInterruptCounter, CAN interrupt registers
 * \usedin Can_EnableControllerInterrupts, Can_DisableControllerInterrupts
 * \exclude Rx Interrupt, Can_MainFunction_Receive
 * \length SHORT The interrupt registers and a counter variable are modified.
 * \endexclusivearea
 *
 * \exclusivearea CAN_EXCLUSIVE_AREA_4
 * Ensures consistent entries when writing to the RxQueue.
 * \protects canRxQueueBuffer, canRxQueueInfo (write)
 * \usedin Can_EnableControllerInterrupts, Can_DisableControllerInterrupts
 * \exclude Rx Interrupt, Can_MainFunction_Receive
 * \length SHORT The CAN frame is copied to the RX queue.
 * \endexclusivearea
 */

#endif /* MIP_H */
/***********************************************************************************************************************
 *  END OF FILE: Mip.h
 **********************************************************************************************************************/
