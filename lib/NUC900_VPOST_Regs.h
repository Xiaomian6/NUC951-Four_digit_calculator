/***************************************************************************
 *                                                                         *
 * Copyright (c) 2007 - 2009 Nuvoton Technology Corp. All rights reserved.*
 *                                                                         *
 ***************************************************************************/
 
 
#ifndef _NUC900_VPOST_REGS_H_
#define _NUC900_VPOST_REGS_H_

#include "NUC900_vpost.h"
#include "NUC900_reg.h"

//#define NULL (0)

//#define HAVE_SAMSUNG_80_18BIT
//#define HAVE_SAMSUNG_80_16BIT
//#define HAVE_OPT_NTSC
//#define HAVE_OPT_NTSC_NONINT_PATCH
//#define HAVE_LPL_LB064
//#define HAVE_HS_121PX13
//#define HAVE_TOPPOLY_TD035
//#define HAVE_AUO_A025DL02
//#define HAVE_HIMAX_80_18BIT
//#define HAVE_TOPPOLY_TD035TTEA3
//#define HAVE_DATAIMAGE_FG0700A0DSSWAGT1
//#define HAVE_AUO_G104SN03
#define HAVE_AUO_A035QN02
//#define _MPU_VSYNC_TYPE

#ifdef HAVE_AUO_A025DL02
//#define _AUO_UPS051_MODE
//#define _AUO_CCIR656_MODE
//#define _AUO_UPS052_MODE
//#define _AUO_NTSC_MODE
#endif
/*VA_CRTC*/
#define CRTC_Retrace_Offset 64
#define CRTC_Retrace_HOffset 6





/*******************************************************************

	VPOST Register Definition

	[Naming Rules]

	  VPOSTB_xxx : Miscelleneous bit definition

********************************************************************/

/* bit definition of REG_LCM_DCCS register */
#define VPOSTB_HC_EN		((UINT32)1<<31)
#define VPOSTB_DISP_ON				(1<<25)
#define VPOSTB_OSD_HUP_1X			(0<<18)
#define VPOSTB_OSD_HUP_2X			(1<<18)
#define VPOSTB_OSD_VUP_1X			(0<<16)
#define VPOSTB_OSD_VUP_2X			(1<<16)
#define VPOSTB_OSD_VUP_4X			(2<<16)
#define VPOSTB_ITUEN 				(1<<15)
#define VPOSTB_OSD_SRC_YUV422		(0<<12)
#define VPOSTB_OSD_SRC_YCBCR422 	(1<<12)   
#define VPOSTB_OSD_SRC_RGB888		(2<<12)   
#define VPOSTB_OSD_SRC_RGB666		(3<<12)   
#define VPOSTB_OSD_SRC_RGB565		(4<<12)   
#define VPOSTB_OSD_SRC_RGB444_LOW	(5<<12)
#define VPOSTB_OSD_SRC_RGB444_HIGH	(7<<12)
#define VPOSTB_VA_SRC_YUV422		(0<<8 )
#define VPOSTB_VA_SRC_YCBCR422		(1<<8 )
#define VPOSTB_VA_SRC_RGB888		(2<<8 )
#define VPOSTB_VA_SRC_RGB666		(3<<8 )
#define VPOSTB_VA_SRC_RGB565		(4<<8 )
#define VPOSTB_VA_SRC_RGB444_LOW	(5<<8 )
#define VPOSTB_VA_SRC_RGB444_HIGH	(7<<8 )
#define VPOSTB_SINGLE				(1<<7 )
#define VPOSTB_FIELD_INTR			(1<<6 )
#define VPOSTB_CMD_ON				(1<<5 )
#define VPOSTB_DISP_INT_EN			(1<<4 )
#define VPOSTB_DISP_OUT_EN			(1<<3 )
#define VPOSTB_OSD_EN				(1<<2 )
#define VPOSTB_VA_EN 				(1<<1 )
#define VPOSTB_ENG_RST 			    (1)


/* bit definition of REG_LCM_DEV_CTRL register */
#define VPOSTB_CMDHIGH	(0)
#define VPOSTB_CMDLOW	((UINT32)1<<31)
#define VPOSTB_CM16t18LOW	(0) 
#define VPOSTB_CM16t18HIGH	((UINT32)1<<30) 
#define VPOSTB_CMD8    (0)
#define VPOSTB_CMD16    ((UINT32)1<<29)
#define VPOSTB_IM256K_9or18	(0)
#define VPOSTB_IM256K_8or16	((UINT32)1<<28)
#define VPOSTB_MPU80    (0)
#define VPOSTB_MPU68    (1<<27)
#define VPOSTB_DATA8or9   (0)
#define VPOSTB_DATA16or18   (1<<26)
#define VPOSTB_COLORTYPE_4K         (0)
#define VPOSTB_COLORTYPE_64K		(1<<24)
#define VPOSTB_COLORTYPE_256K		(2<<24)
#define VPOSTB_COLORTYPE_16M		(3<<24)
#define VPOSTB_LACE     (1<<23)
#define VPOSTB_VR_LACE  (1<<22)
#define VPOSTB_V_POL    (1<<21)
#define VPOSTB_H_POL    (1<<20)
#define VPOSTB_FAL_D    (1<<19)
#define VPOSTB_YUV2CCIR (1<<16)
#define VPOSTB_DEVICE_SYNC_YUV422		(0)
#define VPOSTB_DEVICE_SYNC_UNIPAC       (4<<5)
#define VPOSTB_DEVICE_SYNC_EPSON        (5<<5)
#define VPOSTB_DEVICE_SYNC_HIGHCOLOR	(6<<5)
#define VPOSTB_DEVICE_MPU               (7<<5)
#define VPOSTB_SWAP_YUYV	(1<<1)




/* bit definition of REG_LCM_MPU_CMD register */
#define VPOSTB_CMD_BUSY				((UINT32)1<<31)
#define VPOSTB_WR_RS                (1<<30)
#define VPOSTB_READ                 (1<<29)

/* bit definition of REG_LCM_INT_CS register */
#define VPOSTB_DISP_F_INT			(1<<31)
#define VPOSTB_DISP_F_STATUS        (1<<30)
#define VPOSTB_UNDERRUN_INT         (1<<29)
#define VPOSTB_BUS_ERROR_INT        (1<<28)
#define VPOSTB_FLY_ERR              (1<<27)
#define VPOSTB_UNDERRUN_EN          (1<<1)
#define VPOSTB_DISP_F_EN            (1)

/* bit definition of REG_LCM_VA_FBCTRL register */
#define VPOSTB_DB_EN	((UINT32)1<<31)
#define VPOSTB_FLY_EN	(1<<12)




/* bit definition of REG_LCM_OSD_OVERLAY register */
#define VPOSTB_BLI_ON 	(1<<9)
#define VPOSTB_CKEY_ON	(1<<8)
extern VOID * g_VAFrameBuf;
extern VOID * g_VAOrigFrameBuf;

BOOL vpostAllocVABuffer(PLCDFORMATEX plcdformatex,UINT32 nBytesPixel);
BOOL vpostFreeVABuffer(VOID);
VOID vpostSetOSDSrc(UINT16 ucOSDSrcType);
VOID vpostSetVASrc(UINT16 ucVASrcType);
VOID vpostSetDisplayMode(UINT8 ucvdismode);
INT vpostSetOSDBuffer(PUINT32);
VOID vpostLCDWriteAddr(UINT16 uscmd);
VOID vpostLCDWriteAddr9BIT(UINT16 uscmd);
VOID vpostLCDWriteData(UINT16 usdata);
VOID vpostLCDWriteData9BIT(UINT16 usdata);
UINT32 vpostLCDReadData(VOID);
VOID vpostOSDSetWindow(UINT32 usxstart,UINT32 usystart,UINT32 usxend,UINT32 usyend);
VOID vpostOSDEnable(VOID);


INT vpostLCMInit_TOPPOLY_TD035(PLCDFORMATEX plcdformatex);
INT vpostOSDInit_TOPPOLY_TD035(POSDFORMATEX);
INT vpostLCMDeinit_TOPPOLY_TD035(VOID);

INT vpostLCMInit_TOPPOLY_TD035TTEA3(PLCDFORMATEX plcdformatex);
INT vpostOSDInit_TOPPOLY_TD035TTEA3(POSDFORMATEX);
INT vpostLCMDeinit_TOPPOLY_TD035TTEA3(VOID);

INT vpostLCMInit_SAMSUNG_80_16BIT(PLCDFORMATEX plcdformatex);
INT vpostOSDInit_SAMSUNG_80_16BIT(POSDFORMATEX pOSDformatex);
INT vpostLCMDeinit_SAMSUNG_80_16BIT(VOID);

INT vpostLCMInit_HS_121PX13(PLCDFORMATEX plcdformatex);
INT vpostOSDInit_HS_121PX13(POSDFORMATEX pOSDformatex);

INT vpostLCMInit_AUO_A035QN02(PLCDFORMATEX plcdformatex);
INT vpostLCMDeinit_AUO_A035QN02(VOID);
INT vpostOSDInit_AUO_A035QN02(POSDFORMATEX pOSDformatex);

#endif /* _NUC900_VPOST_REGS_H_ */