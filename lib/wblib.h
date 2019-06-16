/***************************************************************************
 *                                                                         *
 * Copyright (c) 2008 Nuvoton Technology. All rights reserved.             *
 *                                                                         *
 ***************************************************************************/
 
/****************************************************************************
 * 
 * FILENAME
 *     WBLIB.h
 *
 * VERSION
 *     1.0
 *
 * DESCRIPTION
 *     The header file of NUC900 system library.
 *
 * DATA STRUCTURES
 *     None
 *
 * FUNCTIONS
 *     None
 *
 * HISTORY
 *     2008-06-26  Ver 1.0 draft by Min-Nan Cheng
 *
 * REMARK
 *     None
 **************************************************************************/
#ifndef _WBLIB_H
#define _WBLIB_H

#include "NUC900_reg.h"
#include "wberrcode.h"
#include "wbio.h"

//-- function return value
#define	   Successful  0
#define	   Fail        1

#define EXTERNAL_CRYSTAL_CLOCK  15000000


/* Define constants for use external IO in service parameters.  */
#define EXT0			0
#define EXT1			1
#define EXT2			2
#define EXT3			3
#define EXT4			4

#define SIZE_256K		4
#define SIZE_512K		5
#define SIZE_1M			6
#define SIZE_2M			7
#define SIZE_4M			8
#define SIZE_8M			9
#define SIZE_16M		10
#define SIZE_32M		11

#define BUS_DISABLE		12
#define BUS_BIT_8		13
#define BUS_BIT_16		14
#define BUS_BIT_32		15


/* Define the vector numbers associated with each interrupt */
typedef enum int_source_e
{
	IRQ_WDT=1,		// Watch Dog Timer
	IRQ_GROUP0,		// External Interrupt Group 0
	IRQ_GROUP1,		// External Interrupt Group 1
	IRQ_ACTL,		// Audio Controller Interrupt
	IRQ_LCD,		// LCD Controller Interrupt
	IRQ_RTC,		// RTC interrupt
	IRQ_UART0,		// UART 0 interrupt
	IRQ_UART1,		// UART 1 interrupt
	IRQ_UART2,		// UART 2 interrupt
	IRQ_UART3,		// UART 3 interrupt
	IRQ_UART4,		// UART 4 interrupt
	IRQ_TIMER0,		// Timer 0 interrupt
	IRQ_TIMER1,		// Timer 1 interrupt
	IRQ_T_GROUP,	// Timer Group interrupt
	IRQ_USBH_GROUP,	// USB Host group interrupt
	IRQ_EMCTX,		// EMC Tx interrupt
	IRQ_EMCRX,		// EMC Rx interrupt
	IRQ_GDMA_GROUP,	// GDMA Group interrupt
	IRQ_DMAC,		// DMA Controller interrupt
	IRQ_FMI,		// Flash Memory Interrupt
	IRQ_USBD,		// USB Device interrupt
	IRQ_ATAPI,		// ATAPI interrupt
	IRQ_G2D,		// 2D Graphic Engine interrupt
	IRQ_PCI,		// PCI Controller interrupt
	IRQ_SC_GROUP,	// Smart Card interrupt Group
	IRQ_I2C_GROUP,	// I2C interface interrupt Group
	IRQ_USI,		// Universal serial interface interrupt
	IRQ_PWM,		// PWM interrupt
	IRQ_KPI,		// Keypad interrupt
	IRQ_PS2_GROUP,	// PS2 Group interrupt
	IRQ_ADC			// ADC interrupt
} INT_SOURCE_E;

typedef enum int_source_group_e
{
	IRQ_PS2_PORT0	= 0x10000000,
	IRQ_PS2_PORT1	= 0x20000000,
	IRQ_I2C_LINE0	= 0x04000000,
	IRQ_I2C_LINE1	= 0x08000000,
	IRQ_SC_CARD0	= 0x01000000,
	IRQ_SC_CARD1	= 0x02000000,
	IRQ_COMMTX      = 0x00800000,
	IRQ_COMMRX      = 0x00400000,
	IRQ_GDMA_CH0	= 0x00100000,
	IRQ_GDMA_CH1	= 0x00200000,
	IRQ_TIMER2		= 0x00010000,
	IRQ_TIMER3		= 0x00020000,
	IRQ_TIMER4		= 0x00040000,
	IRQ_USBH_OHCI   = 0x00000200,
	IRQ_USBH_EHCI   = 0x00000100,
	IRQ_GROUP0_IRQ0	= 0x00000001,
	IRQ_GROUP0_IRQ1	= 0x00000002,
	IRQ_GROUP0_IRQ2	= 0x00000004,
	IRQ_GROUP0_IRQ3	= 0x00000008,
	IRQ_GROUP1_IRQ4	= 0x00000010,
	IRQ_GROUP1_IRQ5	= 0x00000020,
	IRQ_GROUP1_IRQ6	= 0x00000040,
	IRQ_GROUP1_IRQ7	= 0x00000080
} INT_SOURCE_GROUP_E;


typedef struct datetime_t
{
	UINT32	year;
	UINT32	mon;
	UINT32	day;
	UINT32	hour;
	UINT32	min;
	UINT32	sec;
} DateTime_T;

/* Define constants for use timer in service parameters.  */
#define TIMER0            0
#define TIMER1            1

#define ONE_SHOT_MODE     0
#define PERIODIC_MODE     1
#define TOGGLE_MODE       2

#define ONE_HALF_SECS     0
#define FIVE_SECS         1
#define TEN_SECS          2
#define TWENTY_SECS       3

/* Define constants for use UART in service parameters.  */
#define WB_UART_0		0
#define WB_UART_1		1
#define WB_UART_2		2
#define WB_UART_3		3
#define WB_UART_4		4

#define WB_DATA_BITS_5    0x00
#define WB_DATA_BITS_6    0x01
#define WB_DATA_BITS_7    0x02
#define WB_DATA_BITS_8    0x03

#define WB_STOP_BITS_1    0x00
#define WB_STOP_BITS_2    0x04

#define WB_PARITY_NONE    0x00
#define WB_PARITY_ODD     0x00
#define WB_PARITY_EVEN    0x10

//#define WB_DTR_Low        0x01
//#define WB_RTS_Low        0x02
//#define WB_MODEM_En       0x08

#define LEVEL_1_BYTE      0x00
#define LEVEL_4_BYTES     0x40
#define LEVEL_8_BYTES     0x80
#define LEVEL_14_BYTES    0xC0

/* Define constants for use AIC in service parameters.  */
#define WB_SWI                     0
#define WB_D_ABORT                 1
#define WB_I_ABORT                 2
#define WB_UNDEFINE                3

/* The parameters for sysSetInterruptPriorityLevel() and 
   sysInstallISR() use */
#define FIQ_LEVEL_0                0
#define IRQ_LEVEL_1                1
#define IRQ_LEVEL_2                2
#define IRQ_LEVEL_3                3
#define IRQ_LEVEL_4                4
#define IRQ_LEVEL_5                5
#define IRQ_LEVEL_6                6
#define IRQ_LEVEL_7                7

/* The parameters for sysSetGlobalInterrupt() use */
#define ENABLE_ALL_INTERRUPTS      0
#define DISABLE_ALL_INTERRUPTS     1

/* The parameters for sysSetInterruptType() use */
#define LOW_LEVEL_SENSITIVE        0x00
#define HIGH_LEVEL_SENSITIVE       0x40
#define NEGATIVE_EDGE_TRIGGER      0x80
#define POSITIVE_EDGE_TRIGGER      0xC0

/* The parameters for sysSetLocalInterrupt() use */
#define ENABLE_IRQ                 0x7F
#define ENABLE_FIQ                 0xBF
#define ENABLE_FIQ_IRQ             0x3F
#define DISABLE_IRQ                0x80
#define DISABLE_FIQ                0x40
#define DISABLE_FIQ_IRQ            0xC0

/* Define Cache type  */
#define CACHE_WRITE_BACK		0
#define CACHE_WRITE_THROUGH		1
#define CACHE_DISABLE			-1

#define MMU_DIRECT_MAPPING	0
#define MMU_INVERSE_MAPPING	1


/* Define constants for use Cache in service parameters.  */
#define CACHE_4M		2
#define CACHE_8M		3
#define CACHE_16M		4
#define CACHE_32M		5
#define I_CACHE			6
#define D_CACHE			7
#define I_D_CACHE		8


/* Define UART initialization data structure */
typedef struct UART_INIT_STRUCT
{
	UINT32		uart_no;
    UINT32		uiFreq;
    UINT32		uiBaudrate;
    UINT8		uiDataBits;
    UINT8		uiStopBits;
    UINT8		uiParity;
    UINT8		uiRxTriggerLevel;
} WB_UART_T;

extern UINT32 UART_BA;

/* UART return value */
#define WB_INVALID_PARITY       -1
#define WB_INVALID_DATA_BITS    -2
#define WB_INVALID_STOP_BITS    -3
#define WB_INVALID_BAUD         -4


/* Define PLL initialization data structure */
typedef struct PLL_INIT_STRUCT
{
	UINT32		pll0;		/* PLL0 output frequency */
    UINT32		pll1;		/* PLL1 output frequency */
    UINT32		cpu_src;	/* Select CPU clock from PLL0 or PLL1 */
    UINT32		ahb_clk;	/* the ratio of CPU : AHB clock */
    UINT32		apb_clk;	/* the ratio of AHB : APB clock */
} WB_PLL_T;


/* Define PLL freq. setting */
#define PLL_DISABLE	0x12B63
#define	PLL_66MHZ	0x2B63
#define	PLL_100MHZ	0x4F64
#define PLL_120MHZ	0x4F63
#define PLL_133MHZ	0x22A2
#define	PLL_166MHZ	0x4124
#define	PLL_200MHZ	0x4F24


/* Define CPU clock source */
#define CPU_FROM_PLL0			0
#define CPU_FROM_PLL1			1
#define CPU_FROM_PLL0_DIV_2		2
#define CPU_FROM_EXTAL15M		3


/* Define AHB clock */
#define	AHB_CPUCLK_1_1	0
#define	AHB_CPUCLK_1_2	1
#define	AHB_CPUCLK_1_4	2
#define	AHB_CPUCLK_1_8	3

/* Define APB clock */
#define APB_AHB_1_2		1
#define APB_AHB_1_4		2
#define APB_AHB_1_8		3

/* Define the constant values of PM */
#define WB_PM_IDLE		1
#define WB_PM_PD		2
#define WB_PM_MIDLE	    5

#define WB_PM_PD_IRQ_Fail			-1
#define WB_PM_Type_Fail			    -2
#define WB_PM_INVALID_IRQ_NUM		-3
#define WB_PM_CACHE_OFF				-4


/* Define system library Timer functions */
UINT32	sysGetTicks (INT32 nTimeNo);
INT32	sysResetTicks (INT32 nTimeNo);
INT32	sysUpdateTickCount(INT32 nTimeNo, UINT32 uCount);
INT32	sysSetTimerReferenceClock (INT32 nTimeNo, UINT32 uClockRate);
INT32	sysStartTimer (INT32 nTimeNo, UINT32 uTicksPerSecond, INT32 nOpMode);
INT32	sysStopTimer (INT32 nTimeNo);
VOID	sysClearWatchDogTimerCount (VOID);
VOID	sysClearWatchDogTimerInterruptStatus(VOID);
VOID	sysDisableWatchDogTimer (VOID);
VOID	sysDisableWatchDogTimerReset(VOID);
VOID	sysEnableWatchDogTimer (VOID);
VOID	sysEnableWatchDogTimerReset(VOID);
PVOID	sysInstallWatchDogTimerISR (INT32 nIntTypeLevel, PVOID pvNewISR);
INT32	sysSetWatchDogTimerInterval (INT32 nWdtInterval);
INT32	sysSetTimerEvent(INT32 nTimeNo, UINT32 uTimeTick, PVOID pvFun);
VOID	sysClearTimerEvent(INT32 nTimeNo, UINT32 uTimeEventNo);
VOID	sysSetLocalTime(DateTime_T ltime);
VOID	sysGetCurrentTime(DateTime_T *curTime);
VOID	sysDelay(UINT32 uTicks);

/* Define system library UART functions */
INT8	sysGetChar (VOID);
INT32	sysInitializeUART (WB_UART_T *uart);
VOID	sysPrintf (PINT8 pcStr,...);
VOID	sysprintf (PINT8 pcStr,...);
VOID	sysPutChar (UINT8 ucCh);

/* Define system library AIC functions */
INT32   sysDisableGroupInterrupt(INT_SOURCE_GROUP_E eIntNo);
INT32	sysDisableInterrupt (INT_SOURCE_E eIntNo);
INT32   sysEnableGroupInterrupt(INT_SOURCE_GROUP_E eIntNo);
INT32	sysEnableInterrupt (INT_SOURCE_E eIntNo);
BOOL	sysGetIBitState(VOID);
UINT32	sysGetInterruptEnableStatus(VOID);
PVOID	sysInstallExceptionHandler (INT32 nExceptType, PVOID pvNewHandler);
PVOID	sysInstallFiqHandler (PVOID pvNewISR);
PVOID	sysInstallIrqHandler (PVOID pvNewISR);
PVOID	sysInstallISR (INT32 nIntTypeLevel, INT_SOURCE_E eIntNo, PVOID pvNewISR);
INT32	sysSetGlobalInterrupt (INT32 nIntState);
INT32	sysSetInterruptPriorityLevel (INT_SOURCE_E eIntNo, UINT32 uIntLevel);
INT32	sysSetInterruptType (INT_SOURCE_E eIntNo, UINT32 uIntSourceType);
INT32	sysSetLocalInterrupt (INT32 nIntState);
INT32	sysSetAIC2SWMode(VOID);


/* Define system library Cache functions */
VOID	sysDisableCache(VOID);
INT32	sysEnableCache(UINT32 uCacheOpMode);
VOID	sysFlushCache(INT32 nCacheType);
BOOL	sysGetCacheState(VOID);
INT32	sysGetSdramSizebyMB(VOID);
VOID	sysInvalidCache(VOID);
INT32 	sysSetCachePages(UINT32 addr, INT32 size, INT32 cache_mode);


/* Define system clock functions */
INT32 sysGetPLLConfig(WB_PLL_T *sysClk);
INT32 sysSetPLLConfig(WB_PLL_T *sysClk);


/* Define system library External IO functions */
INT32	sysSetExternalIO(INT extNo, UINT32 extBaseAddr, UINT32 extSize, INT extBusWidth);
INT32	sysSetExternalIOTiming1(INT extNo, INT tACC, INT tACS);
INT32	sysSetExternalIOTiming2(INT extNo, INT tCOH, INT tCOS);


/* Define system power management functions */
VOID sysDisableAllPM_IRQ(VOID);
INT sysEnablePM_IRQ(INT irq_no);
INT sysPMStart(INT pd_type);

#endif  /* _WBLIB_H */

