/***********************************************************************************************************************
COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
Copyright (c) 2009 by Vector Informatik GmbH.                                                  All rights reserved.

This software is copyright protected and proprietary to Vector Informatik GmbH.
Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
All other rights remain with Vector Informatik GmbH.
-----------------------------------------------------------------------------------------------------------------------
FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
File:  BteCallContext.c
Project:  zBte
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
1.00.00   2007-12-01  vismas                creation
1.01.00   2009-11-11  vismas                added handling for exclusive areas
***********************************************************************************************************************/

#define V_BTECALLCONTEXT_SOURCE

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

#include "BteEvent.h"
#include "BteCallContext.h"
#include "BteTestHandler.h"
#include "BteCheck.h"
#include "BteReport.h"


/***********************************************************************************************************************
Version check
***********************************************************************************************************************/
#if ( BTECALLCONTEXT_VERSION != 0x0101 )
#error "Header and Source file are inconsistent (version)!"
#endif
#if ( BTECALLCONTEXT_RELEASE_VERSION != 0x00 )
#error "Header and Source file are inconsistent (release version)!"
#endif

/***********************************************************************************************************************
Local data defines
***********************************************************************************************************************/
/*--- Critical Section ----------------------------------------------------------------------------------------------*/
#define kBte_CriticalRelease                                                  0x10
#define kBte_CriticalLock                                                     0x20

#if defined ( kBteExclusiveAreaCount )
#else
#define kBteExclusiveAreaCount                                              5
#endif
#define kBte_ExclusiveArea_Entered                                           0x01
#define kBte_ExclusiveArea_Left                                              0x02

/*--- Call Context --------------------------------------------------------------------------------------------------*/
/*--- Call Context List ---------------------------------------------------------------------------------------------*/
#if defined ( kBteEventCallContextList_size )
#else
#define kBteEventCallContextList_size                                       100
#endif

/***********************************************************************************************************************
Local macro defines
***********************************************************************************************************************/

/***********************************************************************************************************************
Local typedefs
***********************************************************************************************************************/
/*--- Critical Section ----------------------------------------------------------------------------------------------*/
typedef struct
{
	uint8 Count;
} tBteExclusiveArea;

/*--- Call Context --------------------------------------------------------------------------------------------------*/
typedef struct stBteEventCallContext
{
	uint8 comp;
	uint8 code;
	uint8 name[100];
	uint8 type;
	uint8 context;
	uint8 exclusiveArea[kBteExclusiveAreaCount];
} tBteEventCallContext;

/*--- Call Context List ---------------------------------------------------------------------------------------------*/
typedef struct stBteEventCallContextList
{
	uint16               size;
	tBteEventCallContext  elem[kBteEventCallContextList_size];
} tBteEventCallContextList;

/***********************************************************************************************************************
Global data definitions (RAM)
***********************************************************************************************************************/

/***********************************************************************************************************************
Global data definitions (ROM)
***********************************************************************************************************************/

/***********************************************************************************************************************
Local data definitions (RAM)
***********************************************************************************************************************/
/*--- Critical Section ----------------------------------------------------------------------------------------------*/
static uint8 bteCriticalSection_Count;
static tBteExclusiveArea bteExclusiveArea[kBteExclusiveAreaCount];

/*--- Call Context --------------------------------------------------------------------------------------------------*/
static uint8 bteCallContext;

/*--- Call Context List ---------------------------------------------------------------------------------------------*/
static tBteEventCallContextList bteEventCallContextList;

/***********************************************************************************************************************
Local data definitions (ROM)
***********************************************************************************************************************/

/***********************************************************************************************************************
Local function prototypes
***********************************************************************************************************************/

/***********************************************************************************************************************
Global function definitions
***********************************************************************************************************************/
/*--- Critical Section ----------------------------------------------------------------------------------------------*/
/***********************************************************************************************************************
Name:         BteCriticalSection_Init
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteCriticalSection_Init( void )
{
	uint8 exclusiveArea;

	for( exclusiveArea=0; exclusiveArea<kBteExclusiveAreaCount; exclusiveArea++ )
	{
		bteExclusiveArea[exclusiveArea].Count = 0;
	}

	bteCriticalSection_Count = 0;

}

/***********************************************************************************************************************
Name:         BteCriticalSection_Enter
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteCriticalSection_Enter()
{
	bteCriticalSection_Count++;
	if( bteCriticalSection_Count>1 )
	{
		/* multiple locks */
	}
	if( bteCriticalSection_Count==1 )
	{
		/* first lock: critical section is entered */
	}
}

/***********************************************************************************************************************
Name:         BteCriticalSection_Leave
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteCriticalSection_Leave()
{
	if( bteCriticalSection_Count==0 )
	{
		BteError("Critical section is left although not entered before.");
	}
	bteCriticalSection_Count--;
	if( bteCriticalSection_Count==0 )
	{
		/* last release: critical section is left */
	}
}

/***********************************************************************************************************************
Name:         BteCriticalSection_Get
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
uint8 BteCriticalSection_Get( void )
{
	return( bteCriticalSection_Count );
}


/***********************************************************************************************************************
Name:         BteExclusiveArea_Enter
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteExclusiveArea_Enter(uint8 ExclusiveArea)
{
	bteExclusiveArea[ExclusiveArea].Count++;
	if( bteExclusiveArea[ExclusiveArea].Count>1 )
	{
		/* multiple locks */
	}
	if( bteExclusiveArea[ExclusiveArea].Count==1 )
	{
		/* first lock: critical section is entered */
	}
}

/***********************************************************************************************************************
Name:         BteExclusiveArea_Leave
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteExclusiveArea_Leave(uint8 ExclusiveArea)
{
	if( bteExclusiveArea[ExclusiveArea].Count==0 )
	{
		BteError("Exclusive Area is left although not entered before.");
	}
	bteExclusiveArea[ExclusiveArea].Count--;
	if( bteExclusiveArea[ExclusiveArea].Count==0 )
	{
		/* last release: critical section is left */
	}
}
/***********************************************************************************************************************
Name:         BteExclusiveArea_Get
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
uint8 BteExclusiveArea_Get(uint8 ExclusiveArea)
{
	return( bteExclusiveArea[ExclusiveArea].Count );
}

/*--- Call Context --------------------------------------------------------------------------------------------------*/
/***********************************************************************************************************************
Name:         BteCallContext_Set
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
void BteCallContext_Set( uint8 context )
{
	bteCallContext = context;
}

/***********************************************************************************************************************
Name:         BteCallContext_Get
Parameter:    
Return value: 
Description:  
***********************************************************************************************************************/
uint8 BteCallContext_Get( void )
{
	return( bteCallContext );
}

/*--- Call Context List ---------------------------------------------------------------------------------------------*/
/***********************************************************************************************************************
Name:         BteEventCallContextList_Clear
Parameter:    ---
Return value: ---
Description:  This function clears the list.
***********************************************************************************************************************/
void BteEventCallContextList_Clear( void )
{
	uint16 listIndex;
	uint8 exclusiveArea;

	for( listIndex=0; listIndex<kBteEventCallContextList_size; listIndex++ )
	{
		tBteEventCallContext *elem = &bteEventCallContextList.elem[listIndex];

		elem->code = 0x00;
		elem->comp = 0x00;
		elem->context = 0x00;
		elem->type = 0x00;
		for( exclusiveArea=0; exclusiveArea<kBteExclusiveAreaCount; exclusiveArea++ )
		{
			elem->exclusiveArea[exclusiveArea] = 0;
		}
		//#if defined ( USE_EXTERNAL_LOG )
		sprintf( elem->name, "---" );
		//#endif
	}
	bteEventCallContextList.size = 0;
}

/***********************************************************************************************************************
Name:         BteEventCallContextList_Add
Parameter:    *pEvent
Return value: ---
Description:  This function adds the current event call context to the list.
***********************************************************************************************************************/
void BteEventCallContextList_Add( tBteEvent *pEvent )
{
	uint16 listIndex;
	uint8 alreadyInList = 0;
	uint8 context;
	uint8 exclusiveArea;

	context = BteCallContext_Get();
	if( BteCriticalSection_Get() == 0 )
	{
		context |= kBte_CriticalRelease;
	}
	else
	{
		context |= kBte_CriticalLock;
	}

	for( listIndex=0; listIndex<bteEventCallContextList.size; listIndex++ )
	{
		tBteEventCallContext *elem = &bteEventCallContextList.elem[listIndex];
		if( (elem->code == pEvent->code) && 
			(elem->comp == pEvent->comp) )
		{
			alreadyInList = 1;
			elem->context |= context ;
			for( exclusiveArea=0; exclusiveArea<kBteExclusiveAreaCount; exclusiveArea++ )
			{
				if( BteExclusiveArea_Get(exclusiveArea) != 0 )
				{
					elem->exclusiveArea[exclusiveArea] |= kBte_ExclusiveArea_Entered;
				}
				else
				{
					elem->exclusiveArea[exclusiveArea] |= kBte_ExclusiveArea_Left;
				}
			}
		}
	}

	if( alreadyInList == 0 )
	{
		if( bteEventCallContextList.size < kBteEventCallContextList_size ) 
		{
			tBteEventCallContext *elem = &bteEventCallContextList.elem[bteEventCallContextList.size];

			elem->code = pEvent->code;
			elem->comp = pEvent->comp;
			elem->context = context;
			elem->type = pEvent->type;
			for( exclusiveArea=0; exclusiveArea<kBteExclusiveAreaCount; exclusiveArea++ )
			{
				if( BteExclusiveArea_Get(exclusiveArea) != 0 )
				{
					elem->exclusiveArea[exclusiveArea] |= kBte_ExclusiveArea_Entered;
				}
				else
				{
					elem->exclusiveArea[exclusiveArea] |= kBte_ExclusiveArea_Left;
				}
			}
			//#if defined ( USE_EXTERNAL_LOG )
			(void)sprintf(elem->name, pEvent->text_name);
			//#endif

			bteEventCallContextList.size++;
		}
	}
}

/***********************************************************************************************************************
Name:         BteEventCallContextList_WriteReport
Parameter:    ---
Return value: ---
Description:  This functions prints the list to XML report.
***********************************************************************************************************************/
void BteEventCallContextList_WriteReport( char *textTcId )
{
//#if defined ( USE_EXTERNAL_LOG )
	uint8 text[200];
	uint8 exclusiveAreaText[200];
	uint8 exclusiveAreaTextTemp[200];
	uint8 i;

	(void)sprintf(text, "<testcase id=\"%s\" name=\"\">", textTcId );
	BteReport_Write(text);
	BteTestRun_Begin("");
	BteReport_Write("<FunctionCallContext>");
	for( i=0; i< bteEventCallContextList.size; i++ )
	{
		uint8 exclusiveArea;
		tBteEventCallContext *callContext;
		callContext = &bteEventCallContextList.elem[i];

		(void)sprintf(exclusiveAreaText,"");
		for( exclusiveArea=0; exclusiveArea<kBteExclusiveAreaCount; exclusiveArea++ )
		{
			if( (callContext->exclusiveArea[exclusiveArea] & kBte_ExclusiveArea_Entered) != 0 )
			{
				(void)sprintf(exclusiveAreaTextTemp,"EA%d %s", exclusiveArea, exclusiveAreaText );
			}
			if( (callContext->exclusiveArea[exclusiveArea] & kBte_ExclusiveArea_Left) != 0 )
			{
				(void)sprintf(exclusiveAreaTextTemp,"notEA%d %s", exclusiveArea, exclusiveAreaText );
			}
			(void)sprintf(exclusiveAreaText,"%s", exclusiveAreaTextTemp);
		}


		(void)sprintf( text, "<function name=\"%s\" type=\"%d\" contextTask=\"%x\" contextIR=\"%x\" IRlocked=\"%x\" IRnotLocked=\"%x\" ExclusiveArea=\"%s\" ></function>"
			,callContext->name
			,callContext->type
			,( callContext->context & kBte_Task)
			,((callContext->context & kBte_IR) >> 1 ) 
			,((callContext->context & kBte_CriticalLock) >> 5 ) 
			,((callContext->context & kBte_CriticalRelease) >> 4 )
			,exclusiveAreaText );
		BteReport_Write(text);
	}
	BteReport_Write("</FunctionCallContext>");
	BteReport_Write("<result>ok</result>");
	BteTestRun_End();
	BteReport_Write("</testcase>");
//#endif
}

/***********************************************************************************************************************
Local function definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
EOF
***********************************************************************************************************************/
