#ifndef OS_H
#define OS_H

#include "ComStack_Types.h"


#define osqRAM1
#define osqRAM2
#define osqRAM3


#define PROTOTYPETASK(x)      extern void x##func(void)
#define CALLTASK(x)           (void)x##func()

/* If the SchM-Generator is used (and SchMOsSupport is deactivated 
   replace the 2 definitions above with the following */
/*
#define PROTOTYPETASK(x)      extern void x##(void)
#define CALLTASK(x)           (void)x##()
*/

#define TASK(x)               void x##func(void)
#define ISR(x)                void x(void)
#define DeclareTask(TaskId)   extern osqRAM1 osqRAM2 TaskType osqRAM3 osNotUsed1##TaskId

#define SetRelAlarm(a, b, c)  0
#define CancelAlarm(a)        0
#define WaitEvent(a)          0
#define GetEvent(a, b)        0
#define ClearEvent(a)         0
#define GetResource(a)        0
#define ReleaseResource(a)    0
#define ShutdownOS(a)

#define OSTICKDURATION 1000

#ifndef OSDEFAULTAPPMODE
#define OSDEFAULTAPPMODE 0x01
#endif

typedef uint8              AppModeType;
typedef uint8              EventMaskType;

typedef uint16             osTaskIndexType;  
typedef osTaskIndexType    TaskType;

/* Inclusion of BrsHw.h makes our include structure fail -> define required function prototypes ourselves */
void SchM_SuspendAllInterrupts(void);
void SchM_ResumeAllInterrupts(void);

#define SuspendAllInterrupts  SchM_SuspendAllInterrupts
#define ResumeAllInterrupts   SchM_ResumeAllInterrupts

/* With activated OS Emulation we do not want to create the interrupt service routines with the ISR() macro in can_irq.c
 * For some platforms additional pragmas are required for interrupt functions
 * As the C_ENABLE_OSEK_OS_INTCAT2 is only used by CAN Drivers till now, we are able to redefine this switch.
 * (Does not affect library delivery as can_irq.c has to be delivered as source code)
 */
#if defined (C_ENABLE_OSEK_OS_INTCAT2)
# undef  C_ENABLE_OSEK_OS_INTCAT2
# if !defined (C_DISABLE_OSEK_OS_INTCAT2)
#  define C_DISABLE_OSEK_OS_INTCAT2
# endif
#endif

#endif
