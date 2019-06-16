/***************************************************************************
 *                                                                         *
 * Copyright (c) 2007 - 2009 Nuvoton Technology Corp. All rights reserved.*
 *                                                                         *
 ***************************************************************************/
 

#ifndef _NUC900_VPOST_H_
#define _NUC900_VPOST_H_

#define IRQ_LCD 1

#define OTF_BUF_2L	(0)
#define OTF_BUF_4L	(1<<13)
#define OTF_BUF_8L	(2<<13)
#define OTF_BUF_16L	(3<<13)

#define OSD_VUP_1X  (0)
#define OSD_VUP_2X  (1)
#define OSD_VUP_4X  (2)


#define VA_SRC_YUV422		(0<<8 )
#define VA_SRC_YCBCR422		(1<<8 )
#define VA_SRC_RGB888		(2<<8 )
#define VA_SRC_RGB666		(3<<8 )
#define VA_SRC_RGB565		(4<<8 )
#define VA_SRC_RGB444_LOW	(5<<8 )
#define VA_SRC_RGB444_HIGH	(7<<8 )

#define OSD_SRC_YUV422		(0<<12)	
#define OSD_SRC_YCBCR422    (1<<12)
#define OSD_SRC_RGB888      (2<<12)
#define OSD_SRC_RGB666      (3<<12)
#define OSD_SRC_RGB565      (4<<12)
#define OSD_SRC_RGB444_LOW	(5<<12)
#define OSD_SRC_RGB444_HIGH (7<<12)
#define OSD_SRC_RGB332      (6<<12)

//Parameters of vpostOSDSetOverlay
#define DISPLAY_VIDEO			(0)
#define DISPLAY_OSD				(1)
#define DISPLAY_SYNTHESIZED		(2)


#define VA_SCALE_INTERPOLATION	(0)
#define VA_SCALE_DUPLICATION	(1<<15)

typedef INT (VA_CB_FUNC_T)(UINT8 *, UINT32);


typedef enum va_hcmode_e
{
	HC_MODE0,			//32X32X2bpp 4 color
	HC_MODE1,			//32X32X2bpp 3 color and 1 transparent
	HC_MODE2,			//64X64X2bpp 4 color
	HC_MODE3,			//64X64X2bpp 3 color and 1 transparent
	HC_MODE4,			//128X128X1bpp 2 color
	HC_MODE5			//128X128X1bpp 1 color and 1 transparent
} VA_HCMODE_E;

typedef struct
{
    UINT32 ucVASrcFormat;         //User input Display source format
    UINT32 nScreenWidth;          //Driver output,LCD width
    UINT32 nScreenHeight;         //Driver output,LCD height
    UINT32 nFrameBufferSize;      //Driver output,Frame buffer size(malloc by driver)
    UINT8 ucROT90;                //Rotate 90 degree or not
}LCDFORMATEX,*PLCDFORMATEX;

typedef struct
{
    UINT32 ucOSDSrcFormat;         //User input, OSD source format
    UINT32 nXstart;                //User input, OSD X axis position
    UINT32 nYstart;                //User input, OSD Y axis position
    UINT32 nOSDWidth;              //User input, OSD width
    UINT32 nOSDHeight;             //User input, OSD height
    UINT32 nImageWidth;            //User input, The width of OSD source image width
    PUINT32 pFrameBuffer;          //User input, The address of OSD source image 
}OSDFORMATEX,*POSDFORMATEX;

#define LCM_ERR_ID		0xFFFF0400	/* LCM library ID */

/* error code */
#define ERR_NULL_BUF 							(LCM_ERR_ID | 0x04)	//error memory location
#define ERR_NO_DEVICE							(LCM_ERR_ID | 0x05)	//error no device
#define ERR_BAD_PARAMETER                       (LCM_ERR_ID | 0x06) //error for bad parameter
#define ERR_POWER_STATE							(LCM_ERR_ID | 0x07)	//error power state control

/* NUC900_VPOST.C */
//VOID vpostVASetDisplayBuff(UINT32 uSrcBuffAddr0, UINT32 uSrcBuffAddr1);
//INT  vpostEnable(VA_DEV_E eDisplayDev);
//INT  vpostLCMInit(VA_CB_FUNC_T *fnCallBack,UINT16 ucVASrcType,UINT8 ucVADisMode,UINT16 usVAPicWidth,UINT8 ucROT90);
INT  vpostLCMInit(PLCDFORMATEX plcdformatex);           //Initialize and enable the Video part of LCM
INT  vpostLCMDeinit(VOID);                               //Deinitialize and enable the Video part of LCM
INT  vpostOSDInit(POSDFORMATEX posdformatex);           //Initialize and enable the OSD part of LCM
INT  vpostOSDDeinit(VOID);                                  //Deinitialize and enable the OSD part of LCM
VOID *vpostGetFrameBuffer(VOID);                        //Get the frame buffer of the Video
VOID vpostOSDSetOverlay(UINT8 ucOSDDisplayMatch,UINT8 ucOSDDisplayUnMatch,UINT32 uCKey,UINT32 uCMask,UINT8 ucOSDSynW);
VOID vpostOSDSetBlinking(UINT8 ucOSD_Blink_Vcnt);
VOID vpostOSDDisableBlinking(VOID);
VOID vpostOSDScalingCtrl(UINT8 ucHIntegral,UINT16 usHDecimal,UINT8 ucVScall);
VOID vpostVAScalingCtrl(UINT8 ucHIntegral,UINT16 usHDecimal,UINT8 ucVIntegral,UINT16 usVDecimal,UINT8 ucmode);
VOID vpostVAStartTrigger(void);
VOID vpostVAStopTrigger(void);
VOID vpostHCInit(UINT32 *uCursorBMPBuff,VA_HCMODE_E ucMode);
void vpostDeInit(void);
VOID vpostHCPosCtrl(UINT32 uCursorX, UINT32 uCursorY);

#endif /* _NUC900_VPOST_H_ */