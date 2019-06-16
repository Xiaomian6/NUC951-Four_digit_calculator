/******************************************************************************
 *                                                                          
 * Copyright (c) 2008 Nuvoton Technology. All rights reserved.             
 *                                                                         
 * FILENAME
 *     NUC900_reg.h
 *
 * VERSION
 *     1.0
 *
 * DESCRIPTION
 *     This file contains the general register map of Nuvoton NUC900 processor. 
 *     Some registers are not defined for specific processor.
 *     
 *
 * HISTORY
 *     2008-06-19	Ver 1.0 Created by Min-Nan Cheng
 *
 * REMARK
 *     None
 *     
 ******************************************************************************/
#ifndef _NUC900_H
#define _NUC900_H


/*
   Register map
*/
#define    GCR_BA    0xB0000000 /* Global Control */
#define    CLK_BA    0xB0000200 /* Clock Control */
#define    EBI_BA    0xB0001000 /* EBI Control */
#define    PCI_BA    0xB0002000 /* PCI Control */
#define    EMC_BA    0xB0003000 /* Ethernet MAC */
#define    GDMA_BA   0xB0004000 /* GDMA control */
#define    USBH_BA   0xB0005000 /* USB Host Control */
#define    USBD_BA   0xB0006000 /* USB Device Control */
#define    USBO_BA   0xB0007000 /* OHCI USH Control */
#define    LCM_BA    0xB0008000 /* Display, LCM Interface */
#define    ACTL_BA   0xB0009000 /* Audio Control */
#define    ATA_BA    0xB000A000 /* ATA Interface Control */
#define    GE_BA     0xB000B000 /* 2-D Graphic Engine */
#define    DMAC_BA   0xB000C000 /* DMA Control */
#define    FMI_BA    0xB000D000 /* Flash Memory Card Interface */
#define    UART0_BA  0xB8000000 /* UART0 Control (console) */
#define    UART1_BA  0xB8000100 /* UART1 Control (Bluetooth) */
#define    UART2_BA  0xB8000200 /* UART2 Control (IrDA) */
#define    UART3_BA  0xB8000300 /* UART3 Control (micro-printer) */
#define    UART4_BA  0xB8000400 /* UART4 Control (console) */
#define    TMR_BA    0xB8001000 /* Timer */
#define    AIC_BA    0xB8002000 /* Interrupt Controller */
#define    GPIO_BA   0xB8003000 /* GPIO Control */
#define    RTC_BA    0xB8004000 /* Real Time Clock Control */
#define    SC_BA     0xB8005000 /* Smart Card Control */
#define    I2C0_BA   0xB8006000 /* I2C 0 Control */
#define    I2C1_BA   0xB8006100 /* I2C 1 Control */
#define    USI_BA    0xB8006200 /* Universal Serial Interface */
#define    PWM_BA    0xB8007000 /* Pulse Width Modulation (PWM) Control */
#define    KPI_BA    0xB8008000 /* Keypad Interface Control */
#define    PS2_BA    0xB8009000 /* PS2 Interface Control */
#define    ADC_BA    0xB800A000 /* ADC Control */

 
/*                                                             
  Global Control Registers  
*/
#define    REG_PDID     	(GCR_BA+0x000)  /* Product Identifier Register */
#define    REG_PWRON		(GCR_BA+0x004)  /* Power-On Setting Register */
#define    REG_ARBCON		(GCR_BA+0x008)  /* Arbitration Control Register */
#define    REG_MFSEL		(GCR_BA+0x00C)  /* Multiple Function Pin Select Register */
#define    REG_EBIDPE   	(GCR_BA+0x010)  /* EBI Data Pin Pull-up/down Enable Register */
#define    REG_LCDDPE   	(GCR_BA+0x014)  /* LCD Data Pin Pull-up/down Enable Register */
#define    REG_GPIOCPE  	(GCR_BA+0x018)  /* GPIOC Pin Pull-up/down Enable Register */
#define    REG_GPIODPE  	(GCR_BA+0x01C)  /* GPIOD Pin Pull-up/down Enable Register */
#define    REG_GPIOEPE 		(GCR_BA+0x020)  /* GPIOE Pin Pull-up/down Enable Register */
#define    REG_GPIOFPE  	(GCR_BA+0x024)  /* GPIOF Pin Pull-up/down Enable Register */
#define    REG_GPIOGPE  	(GCR_BA+0x028)  /* GPIOG Pin Pull-up/down Enable Register */
#define    REG_GPIOHPE  	(GCR_BA+0x02C)  /* GPIOH Pin Pull-up/down Enable Register */
#define    REG_GPIOIPE  	(GCR_BA+0x030)  /* GPIOI Pin Pull-up/down Enable Register */
#define    REG_GTMP1    	(GCR_BA+0x034)  /* General Temporary Register 1 */
#define    REG_GTMP2    	(GCR_BA+0x038)  /* General Temporary Register 2 */
#define    REG_GTMP3   		(GCR_BA+0x03C)  /* General Temporary Register 3 */

#define    rPDID			(*(unsigned int volatile *)REG_PDID)
#define    rPWRON			(*(unsigned int volatile *)REG_PWRON)
#define    rARBCON			(*(unsigned int volatile *)REG_ARBCON)
#define    rMFSEL			(*(unsigned int volatile *)REG_MFSEL)
#define    rEBIDPE   		(*(unsigned int volatile *)REG_EBIDPE)
#define    rLCDDPE   		(*(unsigned int volatile *)REG_LCDDPE)
#define    rGPIOCPE  		(*(unsigned int volatile *)REG_GPIOCPE)
#define    rGPIODPE  		(*(unsigned int volatile *)REG_GPIODPE)
#define    rGPIOEPE  		(*(unsigned int volatile *)REG_GPIOEPE)
#define    rGPIOFPE  		(*(unsigned int volatile *)REG_GPIOFPE)
#define    rGPIOGPE  		(*(unsigned int volatile *)REG_GPIOGPE)
#define    rGPIOHPE  		(*(unsigned int volatile *)REG_GPIOHPE)
#define    rGPIOIPE  		(*(unsigned int volatile *)REG_GPIOIPE)
#define    rGTMP1    		(*(unsigned int volatile *)REG_GTMP1)
#define    rGTMP2    		(*(unsigned int volatile *)REG_GTMP2)
#define    rGTMP3    		(*(unsigned int volatile *)REG_GTMP3)


/*                                                            
  Clock Control Registers  
*/
#define    REG_CLKEN		(CLK_BA+0x00) /* Clock Enable Register */
#define    REG_CLKSEL		(CLK_BA+0x04) /* Clock Select Register */
#define    REG_CLKDIV		(CLK_BA+0x08) /* Clock Divider Control Register */
#define    REG_PLLCON0		(CLK_BA+0x0C) /* PLL Control Register 0 */
#define    REG_PLLCON1		(CLK_BA+0x10) /* PLL Control Register 1 */
#define    REG_PMCON		(CLK_BA+0x14) /* Power Management Control Register */
#define    REG_IRQWAKECON	(CLK_BA+0x18) /* IRQ Wakeup Control Register */
#define    REG_IRQWAKEFLAG	(CLK_BA+0x1C) /* IRQ Wakeup Flag Register */
#define    REG_IPSRST		(CLK_BA+0x20) /* IP Software Reset Register */
#define    REG_CLKEN1		(CLK_BA+0x24) /* Clock Enable Register 1 */
#define    REG_CLKDIV1		(CLK_BA+0x28) /* Clock Divider Control Register 1 */

#define    rCLKEN			(*(unsigned int volatile *)REG_CLKEN)
#define    rCLKSEL			(*(unsigned int volatile *)REG_CLKSEL)
#define    rCLKDIV			(*(unsigned int volatile *)REG_CLKDIV)
#define    rPLLCON0			(*(unsigned int volatile *)REG_PLLCON0)
#define    rPLLCON1			(*(unsigned int volatile *)REG_PLLCON1)
#define    rPMCON			(*(unsigned int volatile *)REG_PMCON)
#define    rIRQWAKECON		(*(unsigned int volatile *)REG_IRQWAKECON)
#define    rIRQWAKEFLAG		(*(unsigned int volatile *)REG_IRQWAKEFLAG)
#define    rIPSRST			(*(unsigned int volatile *)REG_IPSRST)
#define    rCLKEN1			(*(unsigned int volatile *)REG_CLKEN1)
#define    rCLKDIV1			(*(unsigned int volatile *)REG_CLKDIV1)

/*
  EBI Control Registers  
*/
#define    REG_EBICON		(EBI_BA+0x000)  /* EBI control register */
#define    REG_ROMCON		(EBI_BA+0x004)  /* ROM/FLASH control register */
#define    REG_SDCONF0		(EBI_BA+0x008)  /* SDRAM bank 0 configuration register */
#define    REG_SDCONF1		(EBI_BA+0x00C)  /* SDRAM bank 1 configuration register */
#define    REG_SDTIME0		(EBI_BA+0x010)  /* SDRAM bank 0 timing control register */
#define    REG_SDTIME1		(EBI_BA+0x014)  /* SDRAM bank 1 timing control register */
#define    REG_EXT0CON		(EBI_BA+0x018)  /* External I/O 0 control register */
#define    REG_EXT1CON		(EBI_BA+0x01C)  /* External I/O 1 control register */
#define    REG_EXT2CON		(EBI_BA+0x020)  /* External I/O 2 control register */
#define    REG_EXT3CON		(EBI_BA+0x024)  /* External I/O 3 control register */
#define    REG_EXT4CON		(EBI_BA+0x028)  /* External I/O 4 control register */
#define    REG_CKSKEW		(EBI_BA+0x02C)  /* Clock skew control register */

#define    rEBICON			(*(unsigned int volatile *)REG_EBICON)
#define    rROMCON			(*(unsigned int volatile *)REG_ROMCON)
#define    rSDCONF0			(*(unsigned int volatile *)REG_SDCONF0)
#define    rSDCONF1			(*(unsigned int volatile *)REG_SDCONF1)
#define    rSDTIME0			(*(unsigned int volatile *)REG_SDTIME0)
#define    rSDTIME1			(*(unsigned int volatile *)REG_SDTIME1)
#define    rEXT0CON			(*(unsigned int volatile *)REG_EXT1CON)
#define    rEXT2CON			(*(unsigned int volatile *)REG_EXT2CON)
#define    rEXT3CON			(*(unsigned int volatile *)REG_EXT3CON)
#define    rEXT4CON			(*(unsigned int volatile *)REG_EXT4CON)
#define    rCKSKEW			(*(unsigned int volatile *)REG_CKSKEW)


/*                                                              
 PCI Control Registers  
*/
#define REG_PCICTR			(PCI_BA + 0x000)    /* PCI Control Register */
#define REG_PCISTR			(PCI_BA + 0x004)    /* PCI Status Register */
#define REG_PCILATIMER		(PCI_BA + 0x008)    /* PCI Latency Timer Register */
#define REG_PCIINTEN		(PCI_BA + 0x010)    /* PCI Interrupt Enable Register */
#define REG_PCIINT			(PCI_BA + 0x014)    /* PCI Interrupt Flag Register */
#define REG_CFGADDR			(PCI_BA + 0x020)    /* Configuration Address Register */
#define REG_CFGDATA			(PCI_BA + 0x024)    /* Configuration Data Register */
#define REG_PCIARB			(PCI_BA + 0x04C)    /* PCI Arbitration Register */
#define REG_PCIBIST			(PCI_BA + 0x050)    /* PCI FIFO BIST Register */

#define rPCICTR				(*(unsigned int volatile *)REG_PCICTR)
#define rPCISTR				(*(unsigned int volatile *)REG_PCISTR)
#define rPCILATIMER			(*(unsigned int volatile *)REG_PCILATIMER)
#define rPCIINTEN			(*(unsigned int volatile *)REG_PCIINTEN)
#define rPCIINT				(*(unsigned int volatile *)REG_PCIINT)
#define rCFGADDR			(*(unsigned int volatile *)REG_CFGADDR)
#define rCFGDATA			(*(unsigned int volatile *)REG_CFGDATA)
#define rPCIARB				(*(unsigned int volatile *)REG_PCIARB)
#define rPCIBIST			(*(unsigned int volatile *)REG_PCIBIST)


/*
  EMAC Registers
*/
#define     REG_CAMCMR		(EMC_BA+0x000)	/* CAM Command Register */
#define     REG_CAMEN		(EMC_BA+0x004)	/* CAM Enable Register */
#define     REG_CAM0M_Base	(EMC_BA+0x008)  /* CAM0 Most Significant Word Register */
#define     REG_CAM0L_Base	(EMC_BA+0x00c)  /* CAM0 Least Significant Word Register */
#define     REG_CAMxM_Reg(x)(REG_CAM0M_Base+x*0x8)	/* CAMx Most Significant Word Register */
#define     REG_CAMxL_Reg(x)(REG_CAM0L_Base+x*0x8)	/* CAMx Least Significant Word Register */
#define     REG_TXDLSA		(EMC_BA+0x088)	/* Transmit Descriptor Link List Start Address Register */
#define     REG_RXDLSA		(EMC_BA+0x08C)	/* Receive Descriptor Link List Start Address Register */
#define     REG_MCMDR		(EMC_BA+0x090)	/* MAC Command Register */
#define     REG_MIID		(EMC_BA+0x094)	/* MII Management Data Register */
#define     REG_MIIDA		(EMC_BA+0x098)	/* MII Management Control and Address Register */
#define     REG_FFTCR		(EMC_BA+0x09C)	/* FIFO Threshold Control Register */
#define     REG_TSDR		(EMC_BA+0x0a0)	/* Transmit Start Demand Register */
#define     REG_RSDR		(EMC_BA+0x0a4)	/* Receive Start Demand Register */
#define     REG_DMARFC		(EMC_BA+0x0a8)	/* Maximum Receive Frame Control Register */
#define     REG_MIEN		(EMC_BA+0x0ac)	/* MAC Interrupt Enable Register */
#define     REG_MISTA		(EMC_BA+0x0b0)	/* MAC Interrupt Status Register */
#define     REG_MGSTA		(EMC_BA+0x0b4)	/* MAC General Status Register */
#define     REG_MPCNT		(EMC_BA+0x0b8)	/* Missed Packet Count Register */
#define     REG_MRPC		(EMC_BA+0x0bc)	/* MAC Receive Pause Count Register */
#define     REG_MRPCC		(EMC_BA+0x0c0)	/* MAC Receive Pause Current Count Register */
#define     REG_MREPC		(EMC_BA+0x0c4)	/* MAC Remote Pause Count Register */
#define     REG_DMARFS		(EMC_BA+0x0c8)	/* DMA Receive Frame Status Register */
#define     REG_CTXDSA		(EMC_BA+0x0cc)	/* Current Transmit Descriptor Start Address Register */
#define     REG_CTXBSA		(EMC_BA+0x0d0)	/* Current Transmit Buffer Start Address Register */
#define     REG_CRXDSA		(EMC_BA+0x0d4)	/* Current Receive Descriptor Start Address Register */
#define     REG_CRXBSA		(EMC_BA+0x0d8)	/* Current Receive Buffer Start Address Register */
	
#define     rCAMCMR			(*(unsigned int volatile *)REG_CAMCMR)
#define     rCAMEN			(*(unsigned int volatile *)REG_CAMEN)
#define     rCAM0M_Base		(*(unsigned int volatile *)REG_CAM0M_Base)
#define     rCAM0L_Base		(*(unsigned int volatile *)REG_CAM0L_Base)
#define     rCAMxM_Reg(x)	(*(unsigned int volatile *)(REG_CAM0M_Base+x*0x8))	
#define     rCAMxL_Reg(x)	(*(unsigned int volatile *)(REG_CAM0L_Base+x*0x8))	
#define     rTXDLSA			(*(unsigned int volatile *)REG_TXDLSA)
#define     rRXDLSA			(*(unsigned int volatile *)REG_RXDLSA)
#define     rMCMDR			(*(unsigned int volatile *)REG_MCMDR)
#define     rMIID			(*(unsigned int volatile *)REG_MIID)
#define     rMIIDA			(*(unsigned int volatile *)REG_MIIDA)
#define     rFFTCR			(*(unsigned int volatile *)REG_FFTCR)
#define     rTSDR			(*(unsigned int volatile *)REG_TSDR)
#define     rRSDR			(*(unsigned int volatile *)REG_RSDR)
#define     rDMARFC			(*(unsigned int volatile *)REG_DMARFC)
#define     rMIEN			(*(unsigned int volatile *)REG_MIEN)
#define     rMISTA			(*(unsigned int volatile *)REG_MISTA)
#define     rMGSTA			(*(unsigned int volatile *)REG_MGSTA)
#define     rMPCNT			(*(unsigned int volatile *)REG_MPCNT)
#define     rMRPC			(*(unsigned int volatile *)REG_MRPC)
#define     rMRPCC			(*(unsigned int volatile *)REG_MRPCC)
#define     rMREPC			(*(unsigned int volatile *)REG_MREPC)
#define     rDMARFS			(*(unsigned int volatile *)REG_DMARFS)
#define     rCTXDSA			(*(unsigned int volatile *)REG_CTXDSA)
#define     rCTXBSA			(*(unsigned int volatile *)REG_CTXBSA)
#define     rCRXDSA			(*(unsigned int volatile *)REG_CRXDSA)
#define     rCRXBSA			(*(unsigned int volatile *)REG_CRXBSA)


/*
  GDMA Registers
*/
#define     REG_GDMA_CTL0	(GDMA_BA+0x000)  /* Channel 0 Control Register */
#define     REG_GDMA_SRCB0	(GDMA_BA+0x004)  /* Channel 0 Source Base Address Register */
#define     REG_GDMA_DSTB0	(GDMA_BA+0x008)  /* Channel 0 Destination Base Address Register */
#define     REG_GDMA_TCNT0	(GDMA_BA+0x00C)  /* Channel 0 Transfer Count Register */
#define     REG_GDMA_CSRC0	(GDMA_BA+0x010)  /* Channel 0 Current Source Address Register */
#define     REG_GDMA_CDST0	(GDMA_BA+0x014)  /* Channel 0 Current Destination Address Register */
#define     REG_GDMA_CTCNT0	(GDMA_BA+0x018)  /* Channel 0 Current Transfer Count Register */
#define     REG_GDMA_DADR0	(GDMA_BA+0x01C)  /* Channel 0 Descriptor Address Register */
#define     REG_GDMA_CTL1	(GDMA_BA+0x020)  /* Channel 1 Control Register */
#define     REG_GDMA_SRCB1	(GDMA_BA+0x024)  /* Channel 1 Source Base Address Register */
#define     REG_GDMA_DSTB1	(GDMA_BA+0x028)  /* Channel 1 Destination Base Address Register */
#define     REG_GDMA_TCNT1	(GDMA_BA+0x02C)  /* Channel 1 Transfer Count Register */
#define     REG_GDMA_CSRC1	(GDMA_BA+0x030)  /* Channel 1 Current Source Address Register */
#define     REG_GDMA_CDST1	(GDMA_BA+0x034)  /* Channel 1 Current Destination Address Register */
#define     REG_GDMA_CTCNT1	(GDMA_BA+0x038)  /* Channel 1 Current Transfer Count Register */
#define     REG_GDMA_DADR1	(GDMA_BA+0x03C)  /* Channel 1 Descriptor Address Register */
#define     REG_GDMA_INTBUF0    (GDMA_BA+0x080)  /* GDMA Internal Buffer Word 0 */
#define     REG_GDMA_INTBUF1    (GDMA_BA+0x084)  /* GDMA Internal Buffer Word 1 */
#define     REG_GDMA_INTBUF2    (GDMA_BA+0x088)  /* GDMA Internal Buffer Word 2 */
#define     REG_GDMA_INTBUF3    (GDMA_BA+0x08C)  /* GDMA Internal Buffer Word 3 */
#define     REG_GDMA_INTBUF4    (GDMA_BA+0x090)  /* GDMA Internal Buffer Word 4 */
#define     REG_GDMA_INTBUF5    (GDMA_BA+0x094)  /* GDMA Internal Buffer Word 5 */
#define     REG_GDMA_INTBUF6    (GDMA_BA+0x098)  /* GDMA Internal Buffer Word 6 */
#define     REG_GDMA_INTBUF7    (GDMA_BA+0x09C)  /* GDMA Internal Buffer Word 7 */
#define     REG_GDMA_INTCS	(GDMA_BA+0x0A0)  /* Interrupt Control and Status Register */

#define     rCTL0			(*(unsigned int volatile *)REG_GDMA_CTL0)
#define     rSRCB0			(*(unsigned int volatile *)REG_GDMA_SRCB0)
#define     rDSTB0			(*(unsigned int volatile *)REG_GDMA_DSTB0)
#define     rTCNT0			(*(unsigned int volatile *)REG_GDMA_TCNT0)
#define     rCSRC0			(*(unsigned int volatile *)REG_GDMA_CSRC0)
#define     rCDST0			(*(unsigned int volatile *)REG_GDMA_CDST0)
#define     rCTCNT0			(*(unsigned int volatile *)REG_GDMA_CTCNT0)
#define     rDADR0			(*(unsigned int volatile *)REG_GDMA_DADR0)
#define     rCTL1			(*(unsigned int volatile *)REG_GDMA_CTL1)
#define     rSRCB1			(*(unsigned int volatile *)REG_GDMA_SRCB1)
#define     rDSTB1			(*(unsigned int volatile *)REG_GDMA_DSTB1)
#define     rTCNT1			(*(unsigned int volatile *)REG_GDMA_TCNT1)
#define     rCSRC1			(*(unsigned int volatile *)REG_GDMA_CSRC1)
#define     rCDST1			(*(unsigned int volatile *)REG_GDMA_CDST1)
#define     rCTCNT1			(*(unsigned int volatile *)REG_GDMA_CTCNT1)
#define     rDADR1			(*(unsigned int volatile *)REG_GDMA_DADR1)
#define     rINTBUF0    	(*(unsigned int volatile *)REG_GDMA_INTBUF0)   
#define     rINTBUF1    	(*(unsigned int volatile *)REG_GDMA_INTBUF1)
#define     rINTBUF2   		(*(unsigned int volatile *)REG_GDMA_INTBUF2)
#define     rINTBUF3    	(*(unsigned int volatile *)REG_GDMA_INTBUF3)
#define     rINTBUF4    	(*(unsigned int volatile *)REG_GDMA_INTBUF4)
#define     rINTBUF5    	(*(unsigned int volatile *)REG_GDMA_INTBUF5)
#define     rINTBUF6   		(*(unsigned int volatile *)REG_GDMA_INTBUF6)
#define     rINTBUF7    	(*(unsigned int volatile *)REG_GDMA_INTBUF7)
#define     rINTCS			(*(unsigned int volatile *)REG_GDMA_INTCS)


/*
  USBH Registers
*/
#define     REG_EHCVNR		(USBH_BA+0x000)  /* EHCI Version Number Register */
#define     REG_EHCSPR		(USBH_BA+0x004)  /* EHCI Structural Parameters Register */
#define     REG_EHCCPR		(USBH_BA+0x008)  /* EHCI Capability Parameters Register */
#define     REG_UCMDR		(USBH_BA+0x020)  /* USB Command Register */
#define     REG_USTSR		(USBH_BA+0x024)  /* USB Status Register */
#define     REG_UIENR		(USBH_BA+0x028)  /* USB Interrupt Enable Register */
#define     REG_UFINDR		(USBH_BA+0x02C)  /* USB Frame Index Register */
#define     REG_UPFLBAR		(USBH_BA+0x034)  /* USB Periodic Frame List Base Address Register */
#define     REG_UCALAR		(USBH_BA+0x038)  /* USB Current Asynchronous List Address Register */
#define     REG_UASSTR		(USBH_BA+0x03C)  /* USB Asynchronous Schedule Sleep Timer Register */
#define     REG_UCFGR		(USBH_BA+0x060)  /* USB Configure Flag Register */
#define     REG_UPSCR0		(USBH_BA+0x064)  /* USB Port 0 Status and Control Register */
#define     REG_UPSCR1		(USBH_BA+0x068)  /* USB Port 1 Status and Control Register */
#define     REG_USBPCR0		(USBH_BA+0x0C4)  /* USB PHY 0 Control Register */
#define     REG_USBPCR1		(USBH_BA+0x0C8)  /* USB PHY 1 Control Register */

#define     rEHCVNR			(*(unsigned int volatile *)REG_EHCVNR)
#define     rEHCSPR			(*(unsigned int volatile *)REG_EHCSPR)
#define     rEHCCPR			(*(unsigned int volatile *)REG_EHCCPR)
#define     rUCMDR			(*(unsigned int volatile *)REG_UCMDR)
#define     rUSTSR			(*(unsigned int volatile *)REG_USTSR)
#define     rUIENR			(*(unsigned int volatile *)REG_UIENR)
#define     rUFINDR			(*(unsigned int volatile *)REG_UFINDR)
#define     rUPFLBAR		(*(unsigned int volatile *)REG_UPFLBAR)
#define     rUCALAR			(*(unsigned int volatile *)REG_UCALAR)
#define     rUASSTR			(*(unsigned int volatile *)REG_UASSTR)
#define     rUCFGR			(*(unsigned int volatile *)REG_UCFGR)
#define     rUPSCR0			(*(unsigned int volatile *)REG_UPSCR0)
#define     rUPSCR1			(*(unsigned int volatile *)REG_UPSCR1)
#define     rUSBPCR0		(*(unsigned int volatile *)REG_USBPCR0)
#define     rUSBPCR1		(*(unsigned int volatile *)REG_USBPCR1)


/*
USBH OHCI Registers
*/
#define     REG_HcRev		(USBO_BA+0x000)  /* Host Controller Revision Register */
#define     REG_HcControl	(USBO_BA+0x004)  /* Host Controller Control Register */
#define     REG_HcComSts	(USBO_BA+0x008)  /* Host Controller Command Status Register */
#define     REG_HcIntSts	(USBO_BA+0x00C)  /* Host Controller Interrupt Status Register */
#define     REG_HcIntEn		(USBO_BA+0x010)  /* Host Controller Interrupt Enable Register */
#define     REG_HcIntDis	(USBO_BA+0x014)  /* Host Controller Interrupt Disable Register */
#define     REG_HcHCCA		(USBO_BA+0x018)  /* Host Controller Communication Area Register */
#define     REG_HcPerCED	(USBO_BA+0x01C)  /* Host Controller Period Current ED Register */
#define     REG_HcCtrHED	(USBO_BA+0x020)  /* Host Controller Control Head ED Registerr */
#define     REG_HcCtrCED	(USBO_BA+0x024)  /* Host Controller Control Current ED Register */
#define     REG_HcBlkHED	(USBO_BA+0x028)  /* Host Controller Bulk Head ED Register */
#define     REG_HcBlkCED	(USBO_BA+0x02C)	 /* Host Controller Bulk Current ED Register */
#define     REG_HcDoneH		(USBO_BA+0x030)	 /* Host Controller Done Head Register */
#define     REG_HcFmIntv	(USBO_BA+0x034)	 /* Host Controller Frame Interval Register */
#define     REG_HcFmRem		(USBO_BA+0x038)	 /* Host Controller Frame Remaining Register */
#define     REG_HcFNum		(USBO_BA+0x03C)	 /* Host Controller Frame Number Register */
#define     REG_HcPerSt		(USBO_BA+0x040)	 /* Host Controller Periodic Start Register */
#define     REG_HcLSTH		(USBO_BA+0x044)	 /* Host Controller Low Speed Threshold Register */
#define     REG_HcRhDeA		(USBO_BA+0x048)	 /* Host Controller Root Hub Descriptor A Register */
#define     REG_HcRhDeB		(USBO_BA+0x04C)	 /* Host Controller Root Hub Descriptor B Register */
#define     REG_HcRhSts		(USBO_BA+0x050)	 /* Host Controller Root Hub Status Register */
#define     REG_HcRhPrt1	(USBO_BA+0x054)	 /* Host Controller Root Hub Port Status [1] */
#define     REG_HcRhPrt2	(USBO_BA+0x058)	 /* Host Controller Root Hub Port Status [2] */
#define     REG_OpModEn		(USBO_BA+0x204)	 /* USB Operational Mode Enable Register */

#define     rHcRev			(*(unsigned int volatile *)REG_HcRev)
#define     rHcControl		(*(unsigned int volatile *)REG_HcControl)
#define     rHcComSts		(*(unsigned int volatile *)REG_HcComSts)
#define     rHcIntSts		(*(unsigned int volatile *)REG_HcIntSts)
#define     rHcIntEn		(*(unsigned int volatile *)REG_HcIntEn)
#define     rHcIntDis		(*(unsigned int volatile *)REG_HcIntDis)
#define     rHcHCCA			(*(unsigned int volatile *)REG_HcHCCA)
#define     rHcPerCED		(*(unsigned int volatile *)REG_HcPerCED)
#define     rHcCtrHED		(*(unsigned int volatile *)REG_HcCtrHED)
#define     rHcCtrCED		(*(unsigned int volatile *)REG_HcCtrCED)
#define     rHcBlkHED		(*(unsigned int volatile *)REG_HcBlkHED)
#define     rHcBlkCED		(*(unsigned int volatile *)REG_HcBlkCED)
#define     rHcDoneH		(*(unsigned int volatile *)REG_HcDoneH)
#define     rHcFmIntv		(*(unsigned int volatile *)REG_HcFmIntv)
#define     rHcFmRem		(*(unsigned int volatile *)REG_HcFmRem)
#define     rHcFNum			(*(unsigned int volatile *)REG_HcFNum)
#define     rHcPerSt		(*(unsigned int volatile *)REG_HcPerSt)
#define     rHcLSTH			(*(unsigned int volatile *)REG_HcLSTH)
#define     rHcRhDeA		(*(unsigned int volatile *)REG_HcRhDeA)
#define     rHcRhDeB		(*(unsigned int volatile *)REG_HcRhDeB)
#define     rHcRhSts		(*(unsigned int volatile *)REG_HcRhSts)
#define     rHcRhPrt1		(*(unsigned int volatile *)REG_HcRhPrt1)
#define     rHcRhPrt2		(*(unsigned int volatile *)REG_HcRhPrt2)
#define     rOpModEn		(*(unsigned int volatile *)REG_OpModEn)


/*
USB Device Control Registers  
*/
#define     REG_USBD_IRQ_STAT		(USBD_BA+0x00)  /* interrupt status register */
#define     REG_USBD_IRQ_ENB_L		(USBD_BA+0x08)  /* interrupt enable low register */
#define     REG_USBD_USBIRQ_STAT	(USBD_BA+0x10)  /* usb interrupt status register */
#define     REG_USBD_IRQ_ENB		(USBD_BA+0x14)  /* usb interrupt enable register */
#define     REG_USBD_OPER			(USBD_BA+0x18)  /* usb operation register */
#define     REG_USBD_FRAME_CNT		(USBD_BA+0x1C)	/* usb frame count register */
#define     REG_USBD_ADDR			(USBD_BA+0x20)  /* usb address register */
#define     REG_USBD_CEP_DATA_BUF	(USBD_BA+0x28)  /* control-ep data buffer register */
#define     REG_USBD_CEP_CTRL_STAT	(USBD_BA+0x2C)  /* control-ep control and status register */
#define     REG_USBD_CEP_IRQ_ENB	(USBD_BA+0x30)  /* control-ep interrupt enable register */
#define     REG_USBD_CEP_IRQ_STAT	(USBD_BA+0x34)  /* control-ep interrupt status register */
#define     REG_USBD_IN_TRNSFR_CNT	(USBD_BA+0x38)  /* in-transfer data count register */
#define     REG_USBD_OUT_TRNSFR_CNT	(USBD_BA+0x3C)  /* out-transfer data count register */
#define     REG_USBD_CEP_CNT		(USBD_BA+0x40)  /* control-ep data count register */
#define     REG_USBD_SETUP1_0		(USBD_BA+0x44)  /* setup byte1 & byte0 register */
#define     REG_USBD_SETUP3_2		(USBD_BA+0x48)  /* setup byte3 & byte2 register */
#define     REG_USBD_SETUP5_4		(USBD_BA+0x4C)  /* setup byte5 & byte4 register */
#define     REG_USBD_SETUP7_6		(USBD_BA+0x50)  /* setup byte7 & byte6 register */
#define     REG_USBD_CEP_START_ADDR	(USBD_BA+0x54)  /* control-ep ram start address register */
#define     REG_USBD_CEP_END_ADDR	(USBD_BA+0x58)  /* control-ep ram end address register */
#define     REG_USBD_DMA_CTRL_STS	(USBD_BA+0x5C)  /* dma control and status register */
#define     REG_USBD_DMA_CNT		(USBD_BA+0x60)  /* dma count register */
#define     REG_USBD_EPA_DATA_BUF	(USBD_BA+0x64)  /* endpoint A data buffer register */
#define     REG_USBD_EPA_IRQ_STAT	(USBD_BA+0x68)  /* endpoint A interrupt status register */
#define     REG_USBD_EPA_IRQ_ENB	(USBD_BA+0x6C)  /* endpoint A interrupt enable register */
#define     REG_USBD_EPA_DATA_CNT	(USBD_BA+0x70)  /* data count available in endpoint A buffer */
#define     REG_USBD_EPA_RSP_SC		(USBD_BA+0x74)  /* endpoint A response register set/clear */
#define     REG_USBD_EPA_MPS		(USBD_BA+0x78)  /* endpoint A max packet size register */
#define     REG_USBD_EPA_TRF_CNT	(USBD_BA+0x7C)  /* endpoint A transfer count register */
#define     REG_USBD_EPA_CFG		(USBD_BA+0x80)  /* endpoint A configuration register */
#define     REG_USBD_EPA_START_ADDR	(USBD_BA+0x84)  /* endpoint A ram start address register */
#define     REG_USBD_EPA_END_ADDR	(USBD_BA+0x88)  /* endpoint A ram end address register */
#define     REG_USBD_EPB_DATA_BUF	(USBD_BA+0x8C)  /* endpoint B data buffer register */
#define     REG_USBD_EPB_IRQ_STAT	(USBD_BA+0x90)  /* endpoint B interrupt status register */
#define     REG_USBD_EPB_IRQ_ENB	(USBD_BA+0x94)  /* endpoint B interrupt enable register */
#define     REG_USBD_EPB_DATA_CNT	(USBD_BA+0x98)  /* data count available in endpoint B buffer */
#define     REG_USBD_EPB_RSP_SC		(USBD_BA+0x9C)  /* endpoint B response register set/clear */
#define     REG_USBD_EPB_MPS		(USBD_BA+0xA0)  /* endpoint B max packet size register */
#define     REG_USBD_EPB_TRF_CNT	(USBD_BA+0xA4)  /* endpoint B transfer count register */
#define     REG_USBD_EPB_CFG		(USBD_BA+0xA8)  /* endpoint B configuration register */
#define     REG_USBD_EPB_START_ADDR	(USBD_BA+0xAC)  /* endpoint B ram start address register */
#define     REG_USBD_EPB_END_ADDR	(USBD_BA+0xB0)  /* endpoint B ram end address register */
#define     REG_USBD_EPC_DATA_BUF	(USBD_BA+0xB4)  /* endpoint C data buffer register */
#define     REG_USBD_EPC_IRQ_STAT	(USBD_BA+0xB8)  /* endpoint C interrupt status register */
#define     REG_USBD_EPC_IRQ_ENB	(USBD_BA+0xBC)  /* endpoint C interrupt enable register */
#define     REG_USBD_EPC_DATA_CNT	(USBD_BA+0xC0)  /* data count available in endpoint C buffer */
#define     REG_USBD_EPC_RSP_SC		(USBD_BA+0xC4)  /* endpoint C response register set/clear */
#define     REG_USBD_EPC_MPS		(USBD_BA+0xC8)  /* endpoint C max packet size register */
#define     REG_USBD_EPC_TRF_CNT	(USBD_BA+0xCC)  /* endpoint C transfer count register */
#define     REG_USBD_EPC_CFG		(USBD_BA+0xD0)  /* endpoint C configuration register */
#define     REG_USBD_EPC_START_ADDR	(USBD_BA+0xD4)  /* endpoint C ram start address register */
#define     REG_USBD_EPC_END_ADDR	(USBD_BA+0xD8)  /* endpoint C ram end address register */
#define     REG_USBD_EPD_DATA_BUF	(USBD_BA+0xDC)  /* endpoint D data buffer register */
#define     REG_USBD_EPD_IRQ_STAT	(USBD_BA+0xE0)  /* endpoint D interrupt status register */
#define     REG_USBD_EPD_IRQ_ENB	(USBD_BA+0xE4)  /* endpoint D interrupt enable register */
#define     REG_USBD_EPD_DATA_CNT	(USBD_BA+0xE8)  /* data count available in endpoint D buffer */
#define     REG_USBD_EPD_RSP_SC		(USBD_BA+0xEC)  /* endpoint D response register set/clear */
#define     REG_USBD_EPD_MPS		(USBD_BA+0xF0)  /* endpoint D max packet size register */
#define     REG_USBD_EPD_TRF_CNT	(USBD_BA+0xF4)  /* endpoint D transfer count register */
#define     REG_USBD_EPD_CFG		(USBD_BA+0xF8)  /* endpoint D configuration register */
#define     REG_USBD_EPD_START_ADDR	(USBD_BA+0xFC)  /* endpoint D ram start address register */
#define     REG_USBD_EPD_END_ADDR	(USBD_BA+0x100) /* endpoint D ram end address register */
#define     REG_USBD_EPE_DATA_BUF	(USBD_BA+0x104) /* endpoint E data buffer register */
#define     REG_USBD_EPE_IRQ_STAT	(USBD_BA+0x108) /* endpoint E interrupt status register */
#define     REG_USBD_EPE_IRQ_ENB	(USBD_BA+0x10C)	/* endpoint E interrupt enable register */
#define     REG_USBD_EPE_DATA_CNT	(USBD_BA+0x110) /* data count available in endpoint E buffer */
#define     REG_USBD_EPE_RSP_SC		(USBD_BA+0x114) /* endpoint E response register set/clear */
#define     REG_USBD_EPE_MPS		(USBD_BA+0x118) /* endpoint E max packet size register */
#define     REG_USBD_EPE_TRF_CNT	(USBD_BA+0x11C) /* endpoint E transfer count register */
#define     REG_USBD_EPE_CFG		(USBD_BA+0x120) /* endpoint E configuration register */
#define     REG_USBD_EPE_START_ADDR	(USBD_BA+0x124) /* endpoint E ram start address register */
#define     REG_USBD_EPE_END_ADDR	(USBD_BA+0x128) /* endpoint E ram end address register */
#define     REG_USBD_EPF_DATA_BUF	(USBD_BA+0x12C) /* endpoint F data buffer register */
#define     REG_USBD_EPF_IRQ_STAT	(USBD_BA+0x130) /* endpoint F interrupt status register */
#define     REG_USBD_EPF_IRQ_ENB	(USBD_BA+0x134) /* endpoint F interrupt enable register */
#define     REG_USBD_EPF_DATA_CNT	(USBD_BA+0x138) /* data count available in endpoint F buffer */
#define     REG_USBD_EPF_RSP_SC		(USBD_BA+0x13C)	/* endpoint F response register set/clear */
#define     REG_USBD_EPF_MPS		(USBD_BA+0x140) /* endpoint F max packet size register */
#define     REG_USBD_EPF_TRF_CNT	(USBD_BA+0x144) /* endpoint F transfer count register */
#define     REG_USBD_EPF_CFG		(USBD_BA+0x148) /* endpoint F configuration register */
#define     REG_USBD_EPF_START_ADDR	(USBD_BA+0x14C) /* endpoint F ram start address register */
#define     REG_USBD_EPF_END_ADDR	(USBD_BA+0x150) /* endpoint F ram end address register */
#define     REG_USBD_AHB_DMA_ADDR	(USBD_BA+0x700) /* AHB_DMA address register */
#define     REG_USBD_PHY_CTL		(USBD_BA+0x704) /* USB PHY control register */


#define     rIRQ_STAT		(*(unsigned int volatile *)REG_USBD_IRQ_STAT)
#define     rIRQ_ENB_L		(*(unsigned int volatile *)REG_USBD_IRQ_ENB_L)
#define     rUSBIRQ_STAT	(*(unsigned int volatile *)REG_USBD_USBIRQ_STAT)
#define     rIRQ_ENB		(*(unsigned int volatile *)REG_USBD_IRQ_ENB)
#define     rOPER			(*(unsigned int volatile *)REG_USBD_OPER)
#define     rFRAME_CNT		(*(unsigned int volatile *)REG_USBD_FRAME_CNT)
#define     rADDR			(*(unsigned int volatile *)REG_USBD_ADDR)
#define     rCEP_DATA_BUF	(*(unsigned int volatile *)REG_USBD_CEP_DATA_BUF)
#define     rCEP_CTRL_STAT	(*(unsigned int volatile *)REG_USBD_CEP_CTRL_STAT)
#define     rCEP_IRQ_ENB	(*(unsigned int volatile *)REG_USBD_CEP_IRQ_ENB)
#define     rCEP_IRQ_STAT	(*(unsigned int volatile *)REG_USBD_CEP_IRQ_STAT)
#define     rIN_TRNSFR_CNT	(*(unsigned int volatile *)REG_USBD_IN_TRNSFR_CNT)
#define     rOUT_TRNSFR_CNT	(*(unsigned int volatile *)REG_USBD_OUT_TRNSFR_CNT)
#define     rCEP_CNT		(*(unsigned int volatile *)REG_USBD_CEP_CNT)
#define     rSETUP1_0		(*(unsigned int volatile *)REG_USBD_SETUP1_0)
#define     rSETUP3_2		(*(unsigned int volatile *)REG_USBD_SETUP3_2)
#define     rSETUP5_4		(*(unsigned int volatile *)REG_USBD_SETUP5_4)
#define     rSETUP7_6		(*(unsigned int volatile *)REG_USBD_SETUP7_6)
#define     rCEP_START_ADDR	(*(unsigned int volatile *)REG_USBD_CEP_START_ADDR)
#define     rCEP_END_ADDR	(*(unsigned int volatile *)REG_USBD_CEP_END_ADDR)
#define     rDMA_CTRL_STS	(*(unsigned int volatile *)REG_USBD_DMA_CTRL_STS)
#define     rDMA_CNT		(*(unsigned int volatile *)REG_USBD_DMA_CNT)
#define     rEPA_DATA_BUF	(*(unsigned int volatile *)REG_USBD_EPA_DATA_BUF)
#define     rEPA_IRQ_STAT	(*(unsigned int volatile *)REG_USBD_EPA_IRQ_STAT)
#define     rEPA_IRQ_ENB	(*(unsigned int volatile *)REG_USBD_EPA_IRQ_ENB)
#define     rEPA_DATA_CNT	(*(unsigned int volatile *)REG_USBD_EPA_DATA_CNT)
#define     rEPA_RSP_SC		(*(unsigned int volatile *)REG_USBD_EPA_RSP_SC)
#define     rEPA_MPS		(*(unsigned int volatile *)REG_USBD_EPA_MPS)
#define     rEPA_TRF_CNT	(*(unsigned int volatile *)REG_USBD_EPA_TRF_CNT)
#define     rEPA_CFG		(*(unsigned int volatile *)REG_USBD_EPA_CFG)
#define     rEPA_START_ADDR	(*(unsigned int volatile *)REG_USBD_EPA_START_ADDR)
#define     rEPA_END_ADDR	(*(unsigned int volatile *)REG_USBD_EPA_END_ADDR)
#define     rEPB_DATA_BUF	(*(unsigned int volatile *)REG_USBD_EPB_DATA_BUF)
#define     rEPB_IRQ_STAT	(*(unsigned int volatile *)REG_USBD_EPB_IRQ_STAT)
#define     rEPB_IRQ_ENB	(*(unsigned int volatile *)REG_USBD_EPB_IRQ_ENB)
#define     rEPB_DATA_CNT	(*(unsigned int volatile *)REG_USBD_EPB_DATA_CNT)
#define     rEPB_RSP_SC		(*(unsigned int volatile *)REG_USBD_EPB_RSP_SC)
#define     rEPB_MPS		(*(unsigned int volatile *)REG_USBD_EPB_MPS)
#define     rEPB_TRF_CNT	(*(unsigned int volatile *)REG_USBD_EPB_TRF_CNT)
#define     rEPB_CFG		(*(unsigned int volatile *)REG_USBD_EPB_CFG)
#define     rEPB_START_ADDR	(*(unsigned int volatile *)REG_USBD_EPB_START_ADDR)
#define     rEPB_END_ADDR	(*(unsigned int volatile *)REG_USBD_EPB_END_ADDR)
#define     rEPC_DATA_BUF	(*(unsigned int volatile *)REG_USBD_EPC_DATA_BUF)
#define     rEPC_IRQ_STAT	(*(unsigned int volatile *)REG_USBD_EPC_IRQ_STAT)
#define     rEPC_IRQ_ENB	(*(unsigned int volatile *)REG_USBD_EPC_IRQ_ENB)
#define     rEPC_DATA_CNT	(*(unsigned int volatile *)REG_USBD_EPC_DATA_CNT)
#define     rEPC_RSP_SC		(*(unsigned int volatile *)REG_USBD_EPC_RSP_SC)
#define     rEPC_MPS		(*(unsigned int volatile *)REG_USBD_EPC_MPS)
#define     rEPC_TRF_CNT	(*(unsigned int volatile *)REG_USBD_EPC_TRF_CNT)
#define     rEPC_CFG		(*(unsigned int volatile *)REG_USBD_EPC_CFG)
#define     rEPC_START_ADDR	(*(unsigned int volatile *)REG_USBD_EPC_START_ADDR)
#define     rEPC_END_ADDR	(*(unsigned int volatile *)REG_USBD_EPC_END_ADDR)
#define     rEPD_DATA_BUF	(*(unsigned int volatile *)REG_USBD_EPD_DATA_BUF)
#define     rEPD_IRQ_STAT	(*(unsigned int volatile *)REG_USBD_EPD_IRQ_STAT)
#define     rEPD_IRQ_ENB	(*(unsigned int volatile *)REG_USBD_EPD_IRQ_ENB)
#define     rEPD_DATA_CNT	(*(unsigned int volatile *)REG_USBD_EPD_DATA_CNT)
#define     rEPD_RSP_SC		(*(unsigned int volatile *)REG_USBD_EPD_RSP_SC)
#define     rEPD_MPS		(*(unsigned int volatile *)REG_USBD_EPD_MPS)
#define     rEPD_TRF_CNT	(*(unsigned int volatile *)REG_USBD_EPD_TRF_CNT)
#define     rEPD_CFG		(*(unsigned int volatile *)REG_USBD_EPD_CFG)
#define     rEPD_START_ADDR	(*(unsigned int volatile *)REG_USBD_EPD_START_ADDR)
#define     rEPD_END_ADDR	(*(unsigned int volatile *)REG_USBD_EPD_END_ADDR)
#define     rEPE_DATA_BUF	(*(unsigned int volatile *)REG_USBD_EPE_DATA_BUF)
#define     rEPE_IRQ_STAT	(*(unsigned int volatile *)REG_USBD_EPE_IRQ_STAT)
#define     rEPE_IRQ_ENB	(*(unsigned int volatile *)REG_USBD_EPE_IRQ_ENB)
#define     rEPE_DATA_CNT	(*(unsigned int volatile *)REG_USBD_EPE_DATA_CNT)
#define     rEPE_RSP_SC		(*(unsigned int volatile *)REG_USBD_EPE_RSP_SC)
#define     rEPE_MPS		(*(unsigned int volatile *)REG_USBD_EPE_MPS)
#define     rEPE_TRF_CNT	(*(unsigned int volatile *)REG_USBD_EPE_TRF_CNT)
#define     rEPE_CFG		(*(unsigned int volatile *)REG_USBD_EPE_CFG)
#define     rEPE_START_ADDR	(*(unsigned int volatile *)REG_USBD_EPE_START_ADDR)
#define     rEPE_END_ADDR	(*(unsigned int volatile *)REG_USBD_EPE_END_ADDR)
#define     rEPF_DATA_BUF	(*(unsigned int volatile *)REG_USBD_EPF_DATA_BUF)
#define     rEPF_IRQ_STAT	(*(unsigned int volatile *)REG_USBD_EPF_IRQ_STAT)
#define     rEPF_IRQ_ENB	(*(unsigned int volatile *)REG_USBD_EPF_IRQ_ENB)
#define     rEPF_DATA_CNT	(*(unsigned int volatile *)REG_USBD_EPF_DATA_CNT)
#define     rEPF_RSP_SC		(*(unsigned int volatile *)REG_USBD_EPF_RSP_SC)
#define     rEPF_MPS		(*(unsigned int volatile *)REG_USBD_EPF_MPS)
#define     rEPF_TRF_CNT	(*(unsigned int volatile *)REG_USBD_EPF_TRF_CNT)
#define     rEPF_CFG		(*(unsigned int volatile *)REG_USBD_EPF_CFG)
#define     rEPF_START_ADDR	(*(unsigned int volatile *)REG_USBD_EPF_START_ADDR)
#define     rEPF_END_ADDR	(*(unsigned int volatile *)REG_USBD_EPF_END_ADDR)
#define     rAHB_DMA_ADDR	(*(unsigned int volatile *)REG_USBD_AHB_DMA_ADDR)
#define     rUSB_PHY_CTL	(*(unsigned int volatile *)REG_USB_PHY_CTL)


/*                                                              
  LCM Control Registers  
*/
#define     REG_LCM_DCCS	 	(LCM_BA+0x00)  /* Display Controller Control/Status Register */
#define     REG_LCM_DEV_CTRL 	(LCM_BA+0x04)  /* Display Output Device Control Register */
#define     REG_LCM_MPU_CMD	 	(LCM_BA+0x08)  /* MPU-Interface LCD Write Command */
#define     REG_LCM_INT_CS	 	(LCM_BA+0x0c)  /* Interrupt Control/Status Register */
#define     REG_LCM_CRTC_SIZE   (LCM_BA+0x10)  /* CRTC Display Size Control Register */
#define     REG_LCM_CRTC_DEND   (LCM_BA+0x14)  /* CRTC Display Enable End */
#define     REG_LCM_CRTC_HR	 	(LCM_BA+0x18)  /* CRTC Internal Horizontal Retrace Control Register */
#define     REG_LCM_CRTC_HSYNC  (LCM_BA+0x1C)  /* CRTC Horizontal Sync Control Register */
#define     REG_LCM_CRTC_VR	 	(LCM_BA+0x20)  /* CRTC Internal Vertical Retrace Control Register */
#define     REG_LCM_VA_BADDR0   (LCM_BA+0x24)  /* Video Stream Frame Buffer-0 Starting Address */
#define     REG_LCM_VA_BADDR1   (LCM_BA+0x28)  /* Video Stream Frame Buffer-1 Starting Address */
#define     REG_LCM_VA_FBCTRL   (LCM_BA+0x2C)  /* Video Stream Frame Buffer Control Register */
#define     REG_LCM_VA_SCALE    (LCM_BA+0x30)  /* Video Stream Scaling Control Register */
#define     REG_LCM_VA_WIN      (LCM_BA+0x38)  /* Image Stream Active Window Coordinates */
#define     REG_LCM_VA_STUFF    (LCM_BA+0x3C)  /* Image Stream Stuff Pixel */
#define     REG_LCM_OSD_WINS    (LCM_BA+0x40)  /* OSD Window Starting Coordinates */
#define     REG_LCM_OSD_WINE    (LCM_BA+0x44)  /* OSD Window Ending Coordinates */
#define     REG_LCM_OSD_BADDR   (LCM_BA+0x48)  /* OSD Stream Frame Buffer Starting Address */
#define     REG_LCM_OSD_FBCTRL  (LCM_BA+0x4c)  /* OSD Stream Frame Buffer Control Register */
#define     REG_LCM_OSD_OVERLAY (LCM_BA+0x50)  /* OSD Overlay Control Register */
#define     REG_LCM_OSD_CKEY    (LCM_BA+0x54)  /* OSD Overlay Color-Key Pattern Register */
#define     REG_LCM_OSD_CMASK   (LCM_BA+0x58)  /* OSD Overlay Color-Key Mask Register */
#define     REG_LCM_OSD_SKIP1   (LCM_BA+0x5C)  /* OSD Window Skip1 Register */
#define     REG_LCM_OSD_SKIP2   (LCM_BA+0x60)  /* OSD Window Skip2 Register */
#define     REG_LCM_OSD_SCALE   (LCM_BA+0x64)  /* OSD horizontal up scaling control register */
#define     REG_LCM_MPU_VSYNC   (LCM_BA+0x68)  /* MPU Vsync control register */
#define     REG_LCM_HC_CTRL	 	(LCM_BA+0x6C)  /* Hardware cursor control Register */
#define     REG_LCM_HC_POS    	(LCM_BA+0x70)  /* Hardware cursot tip point potison on va picture */
#define     REG_LCM_HC_WBCTRL   (LCM_BA+0x74)  /* Hardware Cursor Window Buffer Control Register */
#define     REG_LCM_HC_BADDR    (LCM_BA+0x78)  /* Hardware cursor memory base address register */
#define     REG_LCM_HC_COLOR0   (LCM_BA+0x7C)  /* Hardware cursor color ram register mapped to bpp = 0 */
#define     REG_LCM_HC_COLOR1   (LCM_BA+0x80)  /* Hardware cursor color ram register mapped to bpp = 1 */
#define     REG_LCM_HC_COLOR2   (LCM_BA+0x84)  /* Hardware cursor color ram register mapped to bpp = 2 */
#define     REG_LCM_HC_COLOR3   (LCM_BA+0x88)  /* Hardware cursor color ram register mapped to bpp = 3 */

#define     rDCCS			(*(unsigned int volatile *)REG_LCM_DCCS)
#define     rDEV_CTRL   	(*(unsigned int volatile *)REG_LCM_DEV_CTRL)
#define     rMPU_CMD	 	(*(unsigned int volatile *)REG_LCM_MPU_CMD)
#define     rINT_CS	 		(*(unsigned int volatile *)REG_LCM_INT_CS)
#define     rCRTC_SIZE   	(*(unsigned int volatile *)REG_LCM_CRTC_SIZE)
#define     rCRTC_DEND   	(*(unsigned int volatile *)REG_LCM_CRTC_DEND)
#define     rCRTC_HR	 	(*(unsigned int volatile *)REG_LCM_CRTC_HR)
#define     rCRTC_HSYNC  	(*(unsigned int volatile *)REG_LCM_CRTC_HSYNC)
#define     rCRTC_VR	 	(*(unsigned int volatile *)REG_LCM_CRTC_VR)
#define     rVA_BADDR0   	(*(unsigned int volatile *)REG_LCM_VA_BADDR0)
#define     rVA_BADDR1  	(*(unsigned int volatile *)REG_LCM_VA_BADDR1)
#define     rVA_FBCTRL   	(*(unsigned int volatile *)REG_LCM_VA_FBCTRL)
#define     rVA_SCALE    	(*(unsigned int volatile *)REG_LCM_VA_SCALE)
#define     rVA_WIN      	(*(unsigned int volatile *)REG_LCM_VA_WIN)
#define     rVA_STUFF    	(*(unsigned int volatile *)REG_LCM_VA_STUFF)
#define     rOSD_WINS    	(*(unsigned int volatile *)REG_LCM_OSD_WINS)
#define     rOSD_WINE    	(*(unsigned int volatile *)REG_LCM_OSD_WINE)
#define     rOSD_BADDR   	(*(unsigned int volatile *)REG_LCM_OSD_BADDR)
#define     rOSD_FBCTRL  	(*(unsigned int volatile *)REG_LCM_OSD_FBCTRL)
#define     rOSD_OVERLAY 	(*(unsigned int volatile *)REG_LCM_OSD_OVERLAY)
#define     rOSD_CKEY    	(*(unsigned int volatile *)REG_LCM_OSD_CKEY)
#define     rOSD_CMASK   	(*(unsigned int volatile *)REG_LCM_OSD_CMASK)
#define     rOSD_SKIP1   	(*(unsigned int volatile *)REG_LCM_OSD_SKIP1)
#define     rOSD_SKIP2   	(*(unsigned int volatile *)REG_LCM_OSD_SKIP2)
#define     rOSD_SCALE   	(*(unsigned int volatile *)REG_LCM_OSD_SCALE)
#define     rMPU_VSYNC   	(*(unsigned int volatile *)REG_LCM_MPU_VSYNC)
#define     rHC_CTRL	 	(*(unsigned int volatile *)REG_LCM_HC_CTRL)
#define     rHC_POS    		(*(unsigned int volatile *)REG_LCM_HC_POS)
#define     rHC_WBCTRL  	(*(unsigned int volatile *)REG_LCM_HC_WBCTRL)
#define     rHC_BADDR    	(*(unsigned int volatile *)REG_LCM_HC_BADDR)
#define     rHC_COLOR0   	(*(unsigned int volatile *)REG_LCM_HC_COLOR0)
#define     rHC_COLOR1   	(*(unsigned int volatile *)REG_LCM_HC_COLOR1)
#define     rHC_COLOR2   	(*(unsigned int volatile *)REG_LCM_HC_COLOR2)
#define     rHC_COLOR3   	(*(unsigned int volatile *)REG_LCM_HC_COLOR3)


/*
  Audio Interface Control Registers  
*/
#define     REG_ACTL_CON		(ACTL_BA+0x00)  /* Audio controller control register */
#define     REG_ACTL_RESET		(ACTL_BA+0x04)  /* Sub block reset control register */
#define     REG_ACTL_RDSTB		(ACTL_BA+0x08)  /* DMA destination base address register for record */
#define     REG_ACTL_RDST_LENGTH	(ACTL_BA+0x0C)  /* DMA destination length register for record */
#define     REG_ACTL_RDSTC          (ACTL_BA+0x10)  /* DMA destination current address */
#define     REG_ACTL_RSR		(ACTL_BA+0x14)  /* Record status register */
#define     REG_ACTL_PDSTB		(ACTL_BA+0x18)  /* DMA destination base address register for play */
#define     REG_ACTL_PDST_LENGTH	(ACTL_BA+0x1C)  /* DMA destination length register for play */
#define     REG_ACTL_PDSTC		(ACTL_BA+0x20)  /* DMA destination current address register for play */
#define     REG_ACTL_PSR		(ACTL_BA+0x24)  /* Play status register */
#define     REG_ACTL_IISCON		(ACTL_BA+0x28)  /* IIS control register */
#define     REG_ACTL_ACCON		(ACTL_BA+0x2C)  /* AC-link control register */
#define     REG_ACTL_ACOS0		(ACTL_BA+0x30)  /* AC-link out slot 0 */
#define     REG_ACTL_ACOS1		(ACTL_BA+0x34)  /* AC-link out slot 1 */
#define     REG_ACTL_ACOS2		(ACTL_BA+0x38)  /* AC-link out slot 2 */
#define     REG_ACTL_ACIS0		(ACTL_BA+0x3C)  /* AC-link in slot 0 */
#define     REG_ACTL_ACIS1		(ACTL_BA+0x40)  /* AC-link in slot 1 */
#define     REG_ACTL_ACIS2		(ACTL_BA+0x44)  /* AC-link in slot 2 */
#define     REG_ACTL_COUNTER	(ACTL_BA+0x48)  /* DMA counter down values */

#define     rACTL_CON			(*(unsigned int volatile *)REG_ACTL_CON)
#define     rACTL_RESET			(*(unsigned int volatile *)REG_ACTL_RESET)
#define     rACTL_RDSTB			(*(unsigned int volatile *)REG_ACTL_RDSTB)
#define     rACTL_RDST_LENGTH	(*(unsigned int volatile *)REG_ACTL_RDST_LENGTH)
#define     rACTL_RDSTC         (*(unsigned int volatile *)REG_ACTL_RDSTC)
#define     rACTL_RSR			(*(unsigned int volatile *)REG_ACTL_RSR)
#define     rACTL_PDSTB			(*(unsigned int volatile *)REG_ACTL_PDSTB)
#define     rACTL_PDST_LENGTH	(*(unsigned int volatile *)REG_ACTL_PDST_LENGTH)
#define     rACTL_PDSTC			(*(unsigned int volatile *)REG_ACTL_PDSTC)
#define     rACTL_PSR			(*(unsigned int volatile *)REG_ACTL_PSR)
#define     rACTL_IISCON		(*(unsigned int volatile *)REG_ACTL_IISCON)
#define     rACTL_ACCON			(*(unsigned int volatile *)REG_ACTL_ACCON)
#define     rACTL_ACOS0			(*(unsigned int volatile *)REG_ACTL_ACOS0)
#define     rACTL_ACOS1			(*(unsigned int volatile *)REG_ACTL_ACOS1)
#define     rACTL_ACOS2			(*(unsigned int volatile *)REG_ACTL_ACOS2)
#define     rACTL_ACIS0			(*(unsigned int volatile *)REG_ACTL_ACIS0)
#define     rACTL_ACIS1			(*(unsigned int volatile *)REG_ACTL_ACIS1)
#define     rACTL_ACIS2			(*(unsigned int volatile *)REG_ACTL_ACIS2)
#define     rACTL_COUNTER		(*(unsigned int volatile *)REG_ACTL_COUNTER)


/*
  2-D Graphic Engine Control Registers  
*/
#define     REG_2D_GETG			(GE_BA+0x00)  /* Graphic Engine Trigger Control Register */
#define     REG_2D_GEXYSORG		(GE_BA+0x04)  /* Graphic Engine XY Mode Source Origin Starting Register */
#define     REG_2D_TileXY_VHSF	(GE_BA+0x08)  /* Graphic Engine Tile Width/Height or V/H Scale Factor N/M */
#define     REG_2D_GERRXY		(GE_BA+0x0C)  /* Graphic Engine Rotate Reference Point XY Address */
#define     REG_2D_GEINTS		(GE_BA+0x10)  /* Graphic Engine Interrupt Status Register */
#define     REG_2D_GEPLS		(GE_BA+0x14)  /* Graphic Engine Pattern Location Starting Address Register */
#define     REG_2D_GEBER		(GE_BA+0x18)  /* GE Bresenham Error Term Stepping Constant Register */
#define     REG_2D_GEBIR		(GE_BA+0x1C)  /* GE Bresenham Initial Error, Pixel Count Major M Register */
#define     REG_2D_GEC			(GE_BA+0x20)  /* Graphic Engine Control Register */
#define     REG_2D_GEBC			(GE_BA+0x24)  /* Graphic Engine Background Color Register */
#define     REG_2D_GEFC			(GE_BA+0x28)  /* Graphic Engine Foreground Color Register */
#define     REG_2D_GETC			(GE_BA+0x2C)  /* Graphic Engine Transparency Color Register */
#define     REG_2D_GETCM		(GE_BA+0x30)  /* Graphic Engine Transparency Color Mask Register */
#define     REG_2D_GEXYDORG		(GE_BA+0x34)  /* Graphic Engine XY Mode Display Origin Starting Register */
#define     REG_2D_GESDP		(GE_BA+0x38)  /* Graphic Engine Source/Destination Pitch Register */
#define     REG_2D_GESSXYL		(GE_BA+0x3C)  /* Graphic Engine Source Start XY/Linear Address Register */
#define     REG_2D_GEDSXYL		(GE_BA+0x40)  /* Graphic Engine Destination Start XY/Linear Register */
#define     REG_2D_GEDIXYL		(GE_BA+0x44)  /* Graphic Engine Dimension XY/Linear Register */
#define     REG_2D_GECBTL		(GE_BA+0x48)  /* Graphic Engine Clipping Boundary Top/Left Register */
#define     REG_2D_GECBBR		(GE_BA+0x4C)  /* Graphic Engine Clipping Boundary Bottom/Right Register */
#define     REG_2D_GEPTNA		(GE_BA+0x50)  /* Graphic Engine Pattern A Register */
#define     REG_2D_GEPTNB		(GE_BA+0x54)  /* Graphic Engine Pattern B Register */
#define     REG_2D_GEWPM		(GE_BA+0x58)  /* Graphic Engine Write Plane Mask Register */
#define     REG_2D_GEMC			(GE_BA+0x5C)  /* Graphic Engine Miscellaneous Control Register */

#define     rGETG			(*(unsigned int volatile *)REG_2D_GETG)
#define     rGEXYSORG		(*(unsigned int volatile *)REG_2D_GEXYSORG)
#define     rTileXY_VHSF	(*(unsigned int volatile *)REG_2D_TileXY_VHSF)
#define     rGERRXY			(*(unsigned int volatile *)REG_2D_GERRXY)
#define     rGEINTS			(*(unsigned int volatile *)REG_2D_GEINTS)
#define     rGEPLS			(*(unsigned int volatile *)REG_2D_GEPLS)
#define     rGEBER			(*(unsigned int volatile *)REG_2D_GEBER)
#define     rGEBIR			(*(unsigned int volatile *)REG_2D_GEBIR)
#define     rGEC			(*(unsigned int volatile *)REG_2D_GEC)
#define     rGEBC			(*(unsigned int volatile *)REG_2D_GEBC)
#define     rGEFC			(*(unsigned int volatile *)REG_2D_GEFC)
#define     rGETC			(*(unsigned int volatile *)REG_2D_GETC)
#define     rGETCM			(*(unsigned int volatile *)REG_2D_GETCM)
#define     rGEXYDORG		(*(unsigned int volatile *)REG_2D_GEXYDORG)
#define     rGESDP			(*(unsigned int volatile *)REG_2D_GESDP)
#define     rGESSXYL		(*(unsigned int volatile *)REG_2D_GESSXYL)
#define     rGEDSXYL		(*(unsigned int volatile *)REG_2D_GEDSXYL)
#define     rGEDIXYL		(*(unsigned int volatile *)REG_2D_GEDIXYL)
#define     rGECBTL			(*(unsigned int volatile *)REG_2D_GECBTL)
#define     rGECBBR			(*(unsigned int volatile *)REG_2D_GECBBR)
#define     rGEPTNA			(*(unsigned int volatile *)REG_2D_GEPTNA)
#define     rGEPTNB			(*(unsigned int volatile *)REG_2D_GEPTNB)
#define     rGEWPM			(*(unsigned int volatile *)REG_2D_GEWPM)
#define     rGEMC			(*(unsigned int volatile *)REG_2D_GEMC)


/*
  DMAC Control Registers
*/
#define     REG_FB0			(DMAC_BA+0x000)  /* DMAC Control and Status Register */
#define     REG_DMACCSR		(DMAC_BA+0x800)  /* DMAC Control and Status Register */
#define     REG_DMACSAR1	(DMAC_BA+0x804)  /* DMAC Transfer Starting Address Register 1 */
#define     REG_DMACSAR2	(DMAC_BA+0x808)  /* DMAC Transfer Starting Address Register 2 */
#define     REG_DMACBCR		(DMAC_BA+0x80C)  /* DMAC Transfer Byte Count Register */
#define     REG_DMACIER		(DMAC_BA+0x810)  /* DMAC Interrupt Enable Register */
#define     REG_DMACISR		(DMAC_BA+0x814)  /* DMAC Interrupt Status Register */

#define     rDMACCSR		(*(unsigned int volatile *)REG_DMACCSR)
#define     rDMACSAR1		(*(unsigned int volatile *)REG_DMACSAR1)
#define     rDMACSAR2		(*(unsigned int volatile *)REG_DMACSAR2)
#define     rDMACBCR		(*(unsigned int volatile *)REG_DMACBCR)
#define     rDMACIER		(*(unsigned int volatile *)REG_DMACIER)
#define     rDMACISR		(*(unsigned int volatile *)REG_DMACISR)


/*
  Flash Memory Interface Control Registers  
*/
#define     REG_FMICSR		(FMI_BA+0x000)   /* Global Control and Status Register */
#define     REG_FMIIER		(FMI_BA+0x004)   /* Global Interrupt Control Register */
#define     REG_FMIISR		(FMI_BA+0x008)   /* Global Interrupt Status Register */

/* Secure Digit Registers */
#define     REG_SDCSR		(FMI_BA+0x020)   /* SD control and status register */
#define     REG_SDARG		(FMI_BA+0x024)   /* SD command argument register */
#define     REG_SDIER		(FMI_BA+0x028)   /* SD interrupt enable register */
#define     REG_SDISR		(FMI_BA+0x02C)   /* SD interrupt status register */
#define     REG_SDRSP0		(FMI_BA+0x030)   /* SD receive response token register 0 */
#define     REG_SDRSP1		(FMI_BA+0x034)   /* SD receive response token register 1 */
#define     REG_SDBLEN		(FMI_BA+0x038)   /* SD block length register */
 
/* Memory Stick Registers */
#define     REG_MSCSR		(FMI_BA+0x060)   /* MS control and status register */
#define     REG_MSIER		(FMI_BA+0x064)   /* MS interrupt control register */
#define     REG_MSISR		(FMI_BA+0x068)   /* MS interrupt status register */
#define     REG_MSBUF1		(FMI_BA+0x06C)   /* Memory stick register buffer 1 */
#define     REG_MSBUF2		(FMI_BA+0x070)   /* Memory stick register buffer 2 */

/* NAND-type Flash Registers */
#define     REG_SMCSR		(FMI_BA+0x0A0)   /* NAND Flash Control and Status Register */
#define     REG_SMTCR		(FMI_BA+0x0A4)   /* NAND Flash Timing Control Register */
#define     REG_SMIER		(FMI_BA+0x0A8)   /* NAND Flash Interrupt Control Register */
#define     REG_SMISR		(FMI_BA+0x0AC)   /* NAND Flash Interrupt Status Register */
#define     REG_SMCMD		(FMI_BA+0x0B0)   /* NAND Flash Command Port Register */
#define     REG_SMADDR		(FMI_BA+0x0B4)   /* NAND Flash Address Port Register */
#define     REG_SMDATA		(FMI_BA+0x0B8)   /* NAND Flash Data Port Register */
#define     REG_SMECC0		(FMI_BA+0x0BC)   /* NAND Flash Error Correction Code 0 Register */
#define     REG_SMECC1		(FMI_BA+0x0C0)   /* NAND Flash Error Correction Code 1 Register */
#define     REG_SMECC2		(FMI_BA+0x0C4)   /* NAND Flash Error Correction Code 2 Register */
#define     REG_SMECC3		(FMI_BA+0x0C8)   /* NAND Flash a Error Correction Code 3 Register */
#define     REG_SMRA_0		(FMI_BA+0x0CC)   /* NAND Flash Redundant Area Register */
#define     REG_SMRA_1		(FMI_BA+0x0D0)
#define     REG_SMRA_2		(FMI_BA+0x0D4)
#define     REG_SMRA_3		(FMI_BA+0x0D8)
#define     REG_SMRA_4		(FMI_BA+0x0DC)
#define     REG_SMRA_5		(FMI_BA+0x0E0)
#define     REG_SMRA_6		(FMI_BA+0x0E4)
#define     REG_SMRA_7		(FMI_BA+0x0E8)
#define     REG_SMRA_8		(FMI_BA+0x0EC)
#define     REG_SMRA_9		(FMI_BA+0x0F0)
#define     REG_SMRA_10		(FMI_BA+0x0F4)
#define     REG_SMRA_11		(FMI_BA+0x0F8)
#define     REG_SMRA_12		(FMI_BA+0x0FC)
#define     REG_SMRA_13		(FMI_BA+0x100)
#define     REG_SMRA_14		(FMI_BA+0x104)
#define     REG_SMRA_15		(FMI_BA+0x108)   /* NAND Flash Redundant Area Register */
#define     REG_SMECCAD0	(FMI_BA+0x10C)   /* NAND Flash ECC Correction Address 0 */
#define     REG_SMECCAD1	(FMI_BA+0x110)   /* NAND Flash ECC Correction Address 1 */
#define     REG_ECC4ST		(FMI_BA+0x114)   /* ECC4 Correction Status */
#define     REG_ECC4F1A1	(FMI_BA+0x118)   /* ECC4 Field 1 Error Address 1 */
#define     REG_ECC4F1A2	(FMI_BA+0x11C)   /* ECC4 Field 1 Error Address 2 */
#define     REG_ECC4F1D		(FMI_BA+0x120)   /* ECC4 Field 1 Error Data */
#define     REG_ECC4F2A1	(FMI_BA+0x124)   /* ECC4 Field 2 Error Address 1 */
#define     REG_ECC4F2A2	(FMI_BA+0x128)   /* ECC4 Field 2 Error Address 2 */
#define     REG_ECC4F2D		(FMI_BA+0x12C)   /* ECC4 Field 2 Error Data */
#define     REG_ECC4F3A1	(FMI_BA+0x130)   /* ECC4 Field 3 Error Address 1 */
#define     REG_ECC4F3A2	(FMI_BA+0x134)   /* ECC4 Field 3 Error Address 2 */
#define     REG_ECC4F3D		(FMI_BA+0x138)   /* ECC4 Field 3 Error Data */
#define     REG_ECC4F4A1	(FMI_BA+0x13C)   /* ECC4 Field 4 Error Address 1 */
#define     REG_ECC4F4A2	(FMI_BA+0x140)   /* ECC4 Field 4 Error Address 2 */
#define     REG_ECC4F4D		(FMI_BA+0x144)   /* ECC4 Field 4 Error Data */




#define     rFMICSR			(*(unsigned int volatile *)REG_FMICSR)
#define     rFMIIER			(*(unsigned int volatile *)REG_FMIIER)
#define     rFMIISR			(*(unsigned int volatile *)REG_FMIISR)
/* Secure Digit Registers */
#define     rSDCSR			(*(unsigned int volatile *)REG_SDCSR)
#define     rSDARG			(*(unsigned int volatile *)REG_SDARG)
#define     rSDIER			(*(unsigned int volatile *)REG_SDIER)
#define     rSDISR			(*(unsigned int volatile *)REG_SDISR)
#define     rSDRSP0			(*(unsigned int volatile *)REG_SDRSP0)
#define     rSDRSP1			(*(unsigned int volatile *)REG_SDRSP1)
#define     rSDBLEN			(*(unsigned int volatile *)REG_SDBLEN)
/* Memory Stick Registers */
#define     rMSCSR			(*(unsigned int volatile *)REG_MSCSR)
#define     rMSIER			(*(unsigned int volatile *)REG_MSIER)
#define     rMSISR			(*(unsigned int volatile *)REG_MSISR)
#define     rMSBUF1			(*(unsigned int volatile *)REG_MSBUF1)
#define     rMSBUF2			(*(unsigned int volatile *)REG_MSBUF2)
/* NAND-type Flash Registers */
#define     rSMCSR			(*(unsigned int volatile *)REG_SMCSR)
#define     rSMTCR			(*(unsigned int volatile *)REG_SMTCR)
#define     rSMIER			(*(unsigned int volatile *)REG_SMIER)
#define     rSMISR			(*(unsigned int volatile *)REG_SMISR)
#define     rSMCMD			(*(unsigned int volatile *)REG_SMCMD)
#define     rSMADDR			(*(unsigned int volatile *)REG_SMADDR)
#define     rSMDATA			(*(unsigned int volatile *)REG_SMDATA)
#define     rSMECC0			(*(unsigned int volatile *)REG_SMECC0)
#define     rSMECC1			(*(unsigned int volatile *)REG_SMECC1)
#define     rSMECC2			(*(unsigned int volatile *)REG_SMECC2)
#define     rSMECC3			(*(unsigned int volatile *)REG_SMECC3)
#define     rSMRA_0			(*(unsigned int volatile *)REG_SMRA_0)
#define     rSMRA_1			(*(unsigned int volatile *)REG_SMRA_1)
#define     rSMRA_2			(*(unsigned int volatile *)REG_SMRA_2)
#define     rSMRA_3			(*(unsigned int volatile *)REG_SMRA_3)
#define     rSMRA_4			(*(unsigned int volatile *)REG_SMRA_4)
#define     rSMRA_5			(*(unsigned int volatile *)REG_SMRA_5)
#define     rSMRA_6			(*(unsigned int volatile *)REG_SMRA_6)
#define     rSMRA_7			(*(unsigned int volatile *)REG_SMRA_7)
#define     rSMRA_8			(*(unsigned int volatile *)REG_SMRA_8)
#define     rSMRA_9			(*(unsigned int volatile *)REG_SMRA_9)
#define     rSMRA_10		(*(unsigned int volatile *)REG_SMRA_10)
#define     rSMRA_11		(*(unsigned int volatile *)REG_SMRA_11)
#define     rSMRA_12		(*(unsigned int volatile *)REG_SMRA_12)
#define     rSMRA_13		(*(unsigned int volatile *)REG_SMRA_13)
#define     rSMRA_14		(*(unsigned int volatile *)REG_SMRA_14)
#define     rSMRA_15		(*(unsigned int volatile *)REG_SMRA_15)
#define     rSMECCAD0		(*(unsigned int volatile *)REG_SMECCAD0)
#define     rSMECCAD1		(*(unsigned int volatile *)REG_SMECCAD1)
#define     rECC4ST			(*(unsigned int volatile *)REG_ECC4ST)
#define     rECC4F1A1		(*(unsigned int volatile *)REG_ECC4F1A1)
#define     rECC4F1A2		(*(unsigned int volatile *)REG_ECC4F1A2)
#define     rECC4F1D		(*(unsigned int volatile *)REG_ECC4F1D)
#define     rECC4F2A1		(*(unsigned int volatile *)REG_ECC4F2A1)
#define     rECC4F2A2		(*(unsigned int volatile *)REG_ECC4F2A2)
#define     rECC4F2D		(*(unsigned int volatile *)REG_ECC4F2D)
#define     rECC4F3A1		(*(unsigned int volatile *)REG_ECC4F3A1)
#define     rECC4F3A2		(*(unsigned int volatile *)REG_ECC4F3A2)
#define     rECC4F3D		(*(unsigned int volatile *)REG_ECC4F3D)
#define     rECC4F4A1		(*(unsigned int volatile *)REG_ECC4F4A1)
#define     rECC4F4A2		(*(unsigned int volatile *)REG_ECC4F4A2)
#define     rECC4F4D		(*(unsigned int volatile *)REG_ECC4F4D)


/*
  UART0 Control Registers
*/
#define     REG_UART0_RBR	(UART0_BA+0x00)  /* Receive Buffer Register */
#define     REG_UART0_THR	(UART0_BA+0x00)  /* Transmit Holding Register */
#define     REG_UART0_IER	(UART0_BA+0x04)  /* Interrupt Enable Register */
#define     REG_UART0_DLL	(UART0_BA+0x00)  /* Divisor Latch Register (LS) */
#define     REG_UART0_DLM	(UART0_BA+0x04)  /* Divisor Latch Register (MS) */
#define     REG_UART0_IIR	(UART0_BA+0x08)  /* Interrupt Identification Register */
#define     REG_UART0_FCR	(UART0_BA+0x08)  /* FIFO Control Register */
#define     REG_UART0_LCR	(UART0_BA+0x0C)  /* Line Control Register */
#define     REG_UART0_MCR	(UART0_BA+0x10)  /* Modem Control Register */
#define     REG_UART0_LSR	(UART0_BA+0x14)  /* Line Status Register */
#define     REG_UART0_MSR	(UART0_BA+0x18)  /* MODEM Status Register */
#define     REG_UART0_TOR	(UART0_BA+0x1C)  /* Time Out Register */

#define     rUART0_RBR		(*(unsigned int volatile *)REG_UART0_RBR)
#define     rUART0_THR		(*(unsigned int volatile *)REG_UART0_THR)
#define     rUART0_IER		(*(unsigned int volatile *)REG_UART0_IER)
#define     rUART0_DLL		(*(unsigned int volatile *)REG_UART0_DLL)
#define     rUART0_DLM		(*(unsigned int volatile *)REG_UART0_DLM)
#define     rUART0_IIR		(*(unsigned int volatile *)REG_UART0_IIR)
#define     rUART0_FCR		(*(unsigned int volatile *)REG_UART0_FCR)
#define     rUART0_LCR		(*(unsigned int volatile *)REG_UART0_LCR)
#define     rUART0_MCR		(*(unsigned int volatile *)REG_UART0_MCR)
#define     rUART0_LSR		(*(unsigned int volatile *)REG_UART0_LSR)
#define     rUART0_MSR		(*(unsigned int volatile *)REG_UART0_MSR)
#define     rUART0_TOR		(*(unsigned int volatile *)REG_UART0_TOR)

/*
  UART1 Control Registers
*/
#define     REG_UART1_RBR	(UART1_BA+0x00)  /* Receive Buffer Register */
#define     REG_UART1_THR	(UART1_BA+0x00)  /* Transmit Holding Register */
#define     REG_UART1_IER	(UART1_BA+0x04)  /* Interrupt Enable Register */
#define     REG_UART1_DLL	(UART1_BA+0x00)  /* Divisor Latch Register (LS) */
#define     REG_UART1_DLM	(UART1_BA+0x04)  /* Divisor Latch Register (MS) */
#define     REG_UART1_IIR	(UART1_BA+0x08)  /* Interrupt Identification Register */
#define     REG_UART1_FCR	(UART1_BA+0x08)  /* FIFO Control Register */
#define     REG_UART1_LCR	(UART1_BA+0x0C)  /* Line Control Register */
#define     REG_UART1_MCR	(UART1_BA+0x10)  /* Modem Control Register */
#define     REG_UART1_LSR	(UART1_BA+0x14)  /* Line Status Register */
#define     REG_UART1_MSR	(UART1_BA+0x18)  /* MODEM Status Register */
#define     REG_UART1_TOR	(UART1_BA+0x1C)  /* Time Out Register */

#define     rUART1_RBR		(*(unsigned int volatile *)REG_UART1_RBR)
#define     rUART1_THR		(*(unsigned int volatile *)REG_UART1_THR)
#define     rUART1_IER		(*(unsigned int volatile *)REG_UART1_IER)
#define     rUART1_DLL		(*(unsigned int volatile *)REG_UART1_DLL)
#define     rUART1_DLM		(*(unsigned int volatile *)REG_UART1_DLM)
#define     rUART1_IIR		(*(unsigned int volatile *)REG_UART1_IIR)
#define     rUART1_FCR		(*(unsigned int volatile *)REG_UART1_FCR)
#define     rUART1_LCR		(*(unsigned int volatile *)REG_UART1_LCR)
#define     rUART1_MCR		(*(unsigned int volatile *)REG_UART1_MCR)
#define     rUART1_LSR		(*(unsigned int volatile *)REG_UART1_LSR)
#define     rUART1_MSR		(*(unsigned int volatile *)REG_UART1_MSR)
#define     rUART1_TOR		(*(unsigned int volatile *)REG_UART1_TOR)


/*
  UART2 Control Registers
*/
#define     REG_UART2_RBR	(UART2_BA+0x00)  /* Receive Buffer Register */
#define     REG_UART2_THR	(UART2_BA+0x00)  /* Transmit Holding Register */
#define     REG_UART2_IER	(UART2_BA+0x04)  /* Interrupt Enable Register */
#define     REG_UART2_DLL	(UART2_BA+0x00)  /* Divisor Latch Register (LS) */
#define     REG_UART2_DLM	(UART2_BA+0x04)  /* Divisor Latch Register (MS) */
#define     REG_UART2_IIR	(UART2_BA+0x08)  /* Interrupt Identification Register */
#define     REG_UART2_FCR	(UART2_BA+0x08)  /* FIFO Control Register */
#define     REG_UART2_LCR	(UART2_BA+0x0C)  /* Line Control Register */
#define     REG_UART2_MCR	(UART2_BA+0x10)  /* Modem Control Register */
#define     REG_UART2_LSR	(UART2_BA+0x14)  /* Line Status Register */
#define     REG_UART2_MSR	(UART2_BA+0x18)  /* MODEM Status Register */
#define     REG_UART2_TOR	(UART2_BA+0x1C)  /* Time Out Register */
#define     REG_UART2_IRCR	(UART2_BA+0x20)  /* IrDA Control Register */

#define     rUART2_RBR		(*(unsigned int volatile *)REG_UART2_RBR)
#define     rUART2_THR		(*(unsigned int volatile *)REG_UART2_THR)
#define     rUART2_IER		(*(unsigned int volatile *)REG_UART2_IER)
#define     rUART2_DLL		(*(unsigned int volatile *)REG_UART2_DLL)
#define     rUART2_DLM		(*(unsigned int volatile *)REG_UART2_DLM)
#define     rUART2_IIR		(*(unsigned int volatile *)REG_UART2_IIR)
#define     rUART2_FCR		(*(unsigned int volatile *)REG_UART2_FCR)
#define     rUART2_LCR		(*(unsigned int volatile *)REG_UART2_LCR)
#define     rUART2_MCR		(*(unsigned int volatile *)REG_UART2_MCR)
#define     rUART2_LSR		(*(unsigned int volatile *)REG_UART2_LSR)
#define     rUART2_MSR		(*(unsigned int volatile *)REG_UART2_MSR)
#define     rUART2_TOR		(*(unsigned int volatile *)REG_UART2_TOR)
#define     rUART2_IRCR		(*(unsigned int volatile *)REG_UART2_IRCR)

/*
  UART3 Control Registers
*/
#define     REG_UART3_RBR	(UART3_BA+0x00)  /* Receive Buffer Register */
#define     REG_UART3_THR	(UART3_BA+0x00)  /* Transmit Holding Register */
#define     REG_UART3_IER	(UART3_BA+0x04)  /* Interrupt Enable Register */
#define     REG_UART3_DLL	(UART3_BA+0x00)  /* Divisor Latch Register (LS) */
#define     REG_UART3_DLM	(UART3_BA+0x04)  /* Divisor Latch Register (MS) */
#define     REG_UART3_IIR	(UART3_BA+0x08)  /* Interrupt Identification Register */
#define     REG_UART3_FCR	(UART3_BA+0x08)  /* FIFO Control Register */
#define     REG_UART3_LCR	(UART3_BA+0x0C)  /* Line Control Register */
#define     REG_UART3_MCR	(UART3_BA+0x10)  /* Modem Control Register */
#define     REG_UART3_LSR	(UART3_BA+0x14)  /* Line Status Register */
#define     REG_UART3_MSR	(UART3_BA+0x18)  /* MODEM Status Register */
#define     REG_UART3_TOR	(UART3_BA+0x1C)  /* Time Out Register */

#define     rUART3_RBR		(*(unsigned int volatile *)REG_UART3_RBR)
#define     rUART3_THR		(*(unsigned int volatile *)REG_UART3_THR)
#define     rUART3_IER		(*(unsigned int volatile *)REG_UART3_IER)
#define     rUART3_DLL		(*(unsigned int volatile *)REG_UART3_DLL)
#define     rUART3_DLM		(*(unsigned int volatile *)REG_UART3_DLM)
#define     rUART3_IIR		(*(unsigned int volatile *)REG_UART3_IIR)
#define     rUART3_FCR		(*(unsigned int volatile *)REG_UART3_FCR)
#define     rUART3_LCR		(*(unsigned int volatile *)REG_UART3_LCR)
#define     rUART3_MCR		(*(unsigned int volatile *)REG_UART3_MCR)
#define     rUART3_LSR		(*(unsigned int volatile *)REG_UART3_LSR)
#define     rUART3_MSR		(*(unsigned int volatile *)REG_UART3_MSR)
#define     rUART3_TOR		(*(unsigned int volatile *)REG_UART3_TOR)


/*
  UART4 Control Registers
*/
#define     REG_UART4_RBR	(UART4_BA+0x00)  /* Receive Buffer Register */
#define     REG_UART4_THR	(UART4_BA+0x00)  /* Transmit Holding Register */
#define     REG_UART4_IER	(UART4_BA+0x04)  /* Interrupt Enable Register */
#define     REG_UART4_DLL	(UART4_BA+0x00)  /* Divisor Latch Register (LS) */
#define     REG_UART4_DLM	(UART4_BA+0x04)  /* Divisor Latch Register (MS) */
#define     REG_UART4_IIR	(UART4_BA+0x08)  /* Interrupt Identification Register */
#define     REG_UART4_FCR	(UART4_BA+0x08)  /* FIFO Control Register */
#define     REG_UART4_LCR	(UART4_BA+0x0C)  /* Line Control Register */
#define     REG_UART4_MCR	(UART4_BA+0x10)  /* Modem Control Register */
#define     REG_UART4_LSR	(UART4_BA+0x14)  /* Line Status Register */
#define     REG_UART4_MSR	(UART4_BA+0x18)  /* MODEM Status Register */
#define     REG_UART4_TOR	(UART4_BA+0x1C)  /* Time Out Register */

#define     rUART4_RBR		(*(unsigned int volatile *)REG_UART4_RBR)
#define     rUART4_THR		(*(unsigned int volatile *)REG_UART4_THR)
#define     rUART4_IER		(*(unsigned int volatile *)REG_UART4_IER)
#define     rUART4_DLL		(*(unsigned int volatile *)REG_UART4_DLL)
#define     rUART4_DLM		(*(unsigned int volatile *)REG_UART4_DLM)
#define     rUART4_IIR		(*(unsigned int volatile *)REG_UART4_IIR)
#define     rUART4_FCR		(*(unsigned int volatile *)REG_UART4_FCR)
#define     rUART4_LCR		(*(unsigned int volatile *)REG_UART4_LCR)
#define     rUART4_MCR		(*(unsigned int volatile *)REG_UART4_MCR)
#define     rUART4_LSR		(*(unsigned int volatile *)REG_UART4_LSR)
#define     rUART4_MSR		(*(unsigned int volatile *)REG_UART4_MSR)
#define     rUART4_TOR		(*(unsigned int volatile *)REG_UART4_TOR)


/* 
  Timer Control Registers 
*/
#define     REG_TCSR0		(TMR_BA+0x00)  /* Timer Control and Status Register 0 */
#define     REG_TCSR1		(TMR_BA+0x04)  /* Timer Control and Status Register 1 */
#define     REG_TICR0		(TMR_BA+0x08)  /* Timer Initial Control Register 0 */
#define     REG_TICR1		(TMR_BA+0x0C)  /* Timer Initial Control Register 1 */
#define     REG_TDR0		(TMR_BA+0x10)  /* Timer Data Register 0 */
#define     REG_TDR1		(TMR_BA+0x14)  /* Timer Data Register 1 */
#define     REG_TISR		(TMR_BA+0x18)  /* Timer Interrupt Status Register */
#define     REG_WTCR		(TMR_BA+0x1C)  /* Watchdog Timer Control Register */
#define     REG_TCSR2		(TMR_BA+0x20)  /* Timer Control and Status Register 2 */
#define     REG_TCSR3		(TMR_BA+0x24)  /* Timer Control and Status Register 3 */
#define     REG_TICR2		(TMR_BA+0x28)  /* Timer Initial Control Register 2 */
#define     REG_TICR3		(TMR_BA+0x2C)  /* Timer Initial Control Register 3 */
#define     REG_TDR2		(TMR_BA+0x30)  /* Timer Data Register 2 */
#define     REG_TDR3		(TMR_BA+0x34)  /* Timer Data Register 3 */
#define     REG_TCSR4		(TMR_BA+0x40)  /* Timer Control and Status Register 4 */
#define     REG_TICR4		(TMR_BA+0x48)  /* Timer Initial Control Register 4 */
#define     REG_TDR4		(TMR_BA+0x50)  /* Timer Data Register 4 */

#define     rTCSR0			(*(unsigned int volatile *)REG_TCSR0)
#define     rTCSR1			(*(unsigned int volatile *)REG_TCSR1)
#define     rTICR0			(*(unsigned int volatile *)REG_TICR0)
#define     rTICR1			(*(unsigned int volatile *)REG_TICR1)
#define     rTDR0			(*(unsigned int volatile *)REG_TDR0)
#define     rTDR1			(*(unsigned int volatile *)REG_TDR1)
#define     rTISR			(*(unsigned int volatile *)REG_TISR)
#define     rWTCR			(*(unsigned int volatile *)REG_WTCR)
#define     rTCSR2			(*(unsigned int volatile *)REG_TCSR2)
#define     rTCSR3			(*(unsigned int volatile *)REG_TCSR3)
#define     rTICR2			(*(unsigned int volatile *)REG_TICR2)
#define     rTICR3			(*(unsigned int volatile *)REG_TICR3)
#define     rTDR2			(*(unsigned int volatile *)REG_TDR2)
#define     rTDR3			(*(unsigned int volatile *)REG_TDR3)
#define     rTCSR4			(*(unsigned int volatile *)REG_TCSR4)
#define     rTICR4			(*(unsigned int volatile *)REG_TICR4)
#define     rTDR4			(*(unsigned int volatile *)REG_TDR4)


/*
  Advance Interrupt Controller (AIC) Registers
*/
#define     REG_AIC_SCR1    (AIC_BA+0x04)    /* Source control register 1 */
#define     REG_AIC_SCR2    (AIC_BA+0x08)    /* Source control register 2 */
#define     REG_AIC_SCR3    (AIC_BA+0x0C)    /* Source control register 3 */
#define     REG_AIC_SCR4    (AIC_BA+0x10)    /* Source control register 4 */
#define     REG_AIC_SCR5    (AIC_BA+0x14)    /* Source control register 5 */
#define     REG_AIC_SCR6    (AIC_BA+0x18)    /* Source control register 6 */
#define     REG_AIC_SCR7    (AIC_BA+0x1C)    /* Source control register 7 */
#define     REG_AIC_SCR8    (AIC_BA+0x20)    /* Source control register 8 */
#define     REG_AIC_SCR9    (AIC_BA+0x24)    /* Source control register 9 */
#define     REG_AIC_SCR10   (AIC_BA+0x28)    /* Source control register 10 */
#define     REG_AIC_SCR11   (AIC_BA+0x2C)    /* Source control register 11 */
#define     REG_AIC_SCR12   (AIC_BA+0x30)    /* Source control register 12 */
#define     REG_AIC_SCR13   (AIC_BA+0x34)    /* Source control register 13 */
#define     REG_AIC_SCR14   (AIC_BA+0x38)    /* Source control register 14 */
#define     REG_AIC_SCR15   (AIC_BA+0x3C)    /* Source control register 15 */
#define     REG_AIC_SCR16   (AIC_BA+0x40)    /* Source control register 16 */
#define     REG_AIC_SCR17   (AIC_BA+0x44)    /* Source control register 17 */
#define     REG_AIC_SCR18   (AIC_BA+0x48)    /* Source control register 18 */
#define     REG_AIC_SCR19   (AIC_BA+0x4C)    /* Source control register 19 */
#define     REG_AIC_SCR20   (AIC_BA+0x50)    /* Source control register 20 */
#define     REG_AIC_SCR21   (AIC_BA+0x54)    /* Source control register 21 */
#define     REG_AIC_SCR22   (AIC_BA+0x58)    /* Source control register 22 */
#define     REG_AIC_SCR23   (AIC_BA+0x5C)    /* Source control register 23 */
#define     REG_AIC_SCR24   (AIC_BA+0x60)    /* Source control register 24 */
#define     REG_AIC_SCR25   (AIC_BA+0x64)    /* Source control register 25 */
#define     REG_AIC_SCR26   (AIC_BA+0x68)    /* Source control register 26 */
#define     REG_AIC_SCR27   (AIC_BA+0x6C)    /* Source control register 27 */
#define     REG_AIC_SCR28   (AIC_BA+0x70)    /* Source control register 28 */
#define     REG_AIC_SCR29   (AIC_BA+0x74)    /* Source control register 29 */
#define     REG_AIC_SCR30   (AIC_BA+0x78)    /* Source control register 30 */
#define     REG_AIC_SCR31   (AIC_BA+0x7C)    /* Source control register 31 */
#define     REG_AIC_IRQSC   (AIC_BA+0x80)    /* External Interrupt Control Register */
#define     REG_AIC_GEN     (AIC_BA+0x84)    /* Interrupt Group Enable Control Register */
#define     REG_AIC_GASR    (AIC_BA+0x88)    /* Interrupt Group Active Status Register */
#define     REG_AIC_GSCR    (AIC_BA+0x8C)    /* Interrupt Group Status Clear Register */
#define     REG_AIC_IRSR    (AIC_BA+0x100)   /* Interrupt raw status register */
#define     REG_AIC_IASR    (AIC_BA+0x104)   /* Interrupt active status register */
#define     REG_AIC_ISR     (AIC_BA+0x108)   /* Interrupt status register */
#define     REG_AIC_IPER    (AIC_BA+0x10C)   /* Interrupt priority encoding register */
#define     REG_AIC_ISNR    (AIC_BA+0x110)   /* Interrupt source number register */
#define     REG_AIC_IMR     (AIC_BA+0x114)   /* Interrupt mask register */
#define     REG_AIC_OISR    (AIC_BA+0x118)   /* Output interrupt status register */
#define     REG_AIC_MECR    (AIC_BA+0x120)   /* Mask enable command register */
#define     REG_AIC_MDCR    (AIC_BA+0x124)   /* Mask disable command register */
#define     REG_AIC_EOSCR   (AIC_BA+0x130)   /* End of service command register */

#define     rAIC_SCR1    (*(unsigned int volatile *)REG_AIC_SCR1)
#define     rAIC_SCR2    (*(unsigned int volatile *)REG_AIC_SCR2)
#define     rAIC_SCR3    (*(unsigned int volatile *)REG_AIC_SCR3)
#define     rAIC_SCR4    (*(unsigned int volatile *)REG_AIC_SCR4)
#define     rAIC_SCR5    (*(unsigned int volatile *)REG_AIC_SCR5)
#define     rAIC_SCR6    (*(unsigned int volatile *)REG_AIC_SCR6)
#define     rAIC_SCR7    (*(unsigned int volatile *)REG_AIC_SCR7)
#define     rAIC_SCR8    (*(unsigned int volatile *)REG_AIC_SCR8)
#define     rAIC_SCR9    (*(unsigned int volatile *)REG_AIC_SCR9)
#define     rAIC_SCR10   (*(unsigned int volatile *)REG_AIC_SCR10)
#define     rAIC_SCR11   (*(unsigned int volatile *)REG_AIC_SCR11)
#define     rAIC_SCR12   (*(unsigned int volatile *)REG_AIC_SCR12)
#define     rAIC_SCR13   (*(unsigned int volatile *)REG_AIC_SCR13)
#define     rAIC_SCR14   (*(unsigned int volatile *)REG_AIC_SCR14)
#define     rAIC_SCR15   (*(unsigned int volatile *)REG_AIC_SCR15)
#define     rAIC_SCR16   (*(unsigned int volatile *)REG_AIC_SCR16)
#define     rAIC_SCR17   (*(unsigned int volatile *)REG_AIC_SCR17)
#define     rAIC_SCR18   (*(unsigned int volatile *)REG_AIC_SCR18)
#define     rAIC_SCR19   (*(unsigned int volatile *)REG_AIC_SCR19)
#define     rAIC_SCR20   (*(unsigned int volatile *)REG_AIC_SCR20)
#define     rAIC_SCR21   (*(unsigned int volatile *)REG_AIC_SCR21)
#define     rAIC_SCR22   (*(unsigned int volatile *)REG_AIC_SCR22)
#define     rAIC_SCR23   (*(unsigned int volatile *)REG_AIC_SCR23)
#define     rAIC_SCR24   (*(unsigned int volatile *)REG_AIC_SCR24)
#define     rAIC_SCR25   (*(unsigned int volatile *)REG_AIC_SCR25)
#define     rAIC_SCR26   (*(unsigned int volatile *)REG_AIC_SCR26)
#define     rAIC_SCR27   (*(unsigned int volatile *)REG_AIC_SCR27)
#define     rAIC_SCR28   (*(unsigned int volatile *)REG_AIC_SCR28)
#define     rAIC_SCR29   (*(unsigned int volatile *)REG_AIC_SCR29)
#define     rAIC_SCR30   (*(unsigned int volatile *)REG_AIC_SCR30)
#define     rAIC_SCR31   (*(unsigned int volatile *)REG_AIC_SCR31)
#define     rAIC_IRQSC   (*(unsigned int volatile *)REG_AIC_IRQSC)
#define     rAIC_GEN     (*(unsigned int volatile *)REG_AIC_GEN)
#define     rAIC_GASR    (*(unsigned int volatile *)REG_AIC_GASR)
#define     rAIC_GSCR    (*(unsigned int volatile *)REG_AIC_GSCR)
#define     rAIC_IRSR    (*(unsigned int volatile *)REG_AIC_IRSR)
#define     rAIC_IASR    (*(unsigned int volatile *)REG_AIC_IASR)
#define     rAIC_ISR     (*(unsigned int volatile *)REG_AIC_ISR)
#define     rAIC_IPER    (*(unsigned int volatile *)REG_AIC_IPER)
#define     rAIC_ISNR    (*(unsigned int volatile *)REG_AIC_ISNR)
#define     rAIC_IMR     (*(unsigned int volatile *)REG_AIC_IMR)
#define     rAIC_OISR    (*(unsigned int volatile *)REG_AIC_OISR)
#define     rAIC_MECR    (*(unsigned int volatile *)REG_AIC_MECR)
#define     rAIC_MDCR    (*(unsigned int volatile *)REG_AIC_MDCR)
#define     rAIC_EOSCR   (*(unsigned int volatile *)REG_AIC_EOSCR)


/*
  GPIO Control Registers  
*/
#define     REG_GPIOC_DIR		(GPIO_BA+0x04)  /* GPIO portC direction control register */
#define     REG_GPIOC_DATAOUT	(GPIO_BA+0x08)  /* GPIO portC data output register */
#define     REG_GPIOC_DATAIN	(GPIO_BA+0x0C)  /* GPIO portC data input register */
#define     REG_GPIOD_DIR		(GPIO_BA+0x14)  /* GPIO portD direction control register */
#define     REG_GPIOD_DATAOUT	(GPIO_BA+0x18)  /* GPIO portD data output register */
#define     REG_GPIOD_DATAIN	(GPIO_BA+0x1C)  /* GPIO portD data input register */
#define     REG_GPIOE_DIR		(GPIO_BA+0x24)  /* GPIO portE direction control register */
#define     REG_GPIOE_DATAOUT	(GPIO_BA+0x28)  /* GPIO portE data output register */
#define     REG_GPIOE_DATAIN	(GPIO_BA+0x2C)  /* GPIO portE data input register */
#define     REG_GPIOF_DIR		(GPIO_BA+0x34)  /* GPIO portF direction control register */
#define     REG_GPIOF_DATAOUT	(GPIO_BA+0x38)  /* GPIO portF data output register */
#define     REG_GPIOF_DATAIN	(GPIO_BA+0x3C)  /* GPIO portF data input register */
#define     REG_GPIOG_DIR		(GPIO_BA+0x44)  /* GPIO portG direction control register */
#define     REG_GPIOG_DATAOUT	(GPIO_BA+0x48)  /* GPIO portG data output register */
#define     REG_GPIOG_DATAIN	(GPIO_BA+0x4C)  /* GPIO portG data input register */
#define     REG_GPIOH_DBNCE		(GPIO_BA+0x50)  /* GPIO portH input debounce control reg. */
#define     REG_GPIOH_DIR		(GPIO_BA+0x54)  /* GPIO portH direction control register */
#define     REG_GPIOH_DATAOUT	(GPIO_BA+0x58)  /* GPIO portH data output register */
#define     REG_GPIOH_DATAIN	(GPIO_BA+0x5C)  /* GPIO portH data input register */
#define     REG_GPIOI_DIR		(GPIO_BA+0x64)  /* GPIO portI direction control register */
#define     REG_GPIOI_DATAOU	(GPIO_BA+0x68)  /* GPIO portI data output register */
#define     REG_GPIOI_DATAIN	(GPIO_BA+0x6C)  /* GPIO portI data input register */

#define     rGPIOC_DIR			(*(unsigned int volatile *)REG_GPIOC_DIR)
#define     rGPIOC_DATAOUT		(*(unsigned int volatile *)REG_GPIOC_DATAOUT)
#define     rGPIOC_DATAIN		(*(unsigned int volatile *)REG_GPIOC_DATAIN)
#define     rGPIOD_DIR			(*(unsigned int volatile *)REG_GPIOD_DIR)
#define     rGPIOD_DATAOUT		(*(unsigned int volatile *)REG_GPIOD_DATAOUT)
#define     rGPIOD_DATAIN		(*(unsigned int volatile *)REG_GPIOD_DATAIN)
#define     rGPIOE_DIR			(*(unsigned int volatile *)REG_GPIOE_DIR)
#define     rGPIOE_DATAOUT		(*(unsigned int volatile *)REG_GPIOE_DATAOUT)
#define     rGPIOE_DATAIN		(*(unsigned int volatile *)REG_GPIOE_DATAIN)
#define     rGPIOF_DIR			(*(unsigned int volatile *)REG_GPIOF_DIR)
#define     rGPIOF_DATAOUT		(*(unsigned int volatile *)REG_GPIOF_DATAOUT)
#define     rGPIOF_DATAIN		(*(unsigned int volatile *)REG_GPIOF_DATAIN)
#define     rGPIOG_DIR			(*(unsigned int volatile *)REG_GPIOG_DIR)
#define     rGPIOG_DATAOUT		(*(unsigned int volatile *)REG_GPIOG_DATAOUT)
#define     rGPIOG_DATAIN		(*(unsigned int volatile *)REG_GPIOG_DATAIN)
#define     rGPIOH_DBNCE		(*(unsigned int volatile *)REG_GPIOH_DBNCE)
#define     rGPIOH_DIR			(*(unsigned int volatile *)REG_GPIOH_DIR)
#define     rGPIOH_DATAOUT		(*(unsigned int volatile *)REG_GPIOH_DATAOUT)
#define     rGPIOH_DATAIN		(*(unsigned int volatile *)REG_GPIOH_DATAIN)
#define     rGPIOI_DIR			(*(unsigned int volatile *)REG_GPIOI_DIR)
#define     rGPIOI_DATAOU		(*(unsigned int volatile *)REG_GPIOI_DATAOU)
#define     rGPIOI_DATAIN		(*(unsigned int volatile *)REG_GPIOI_DATAIN)


/* 
  RTC Control Registers
*/
#define     REG_RTC_INIR	(RTC_BA+0x00)   /* RTC Initiation Register */
#define     REG_RTC_AER		(RTC_BA+0x04)   /* RTC Access Enable Register */
#define     REG_RTC_FCR		(RTC_BA+0x08)   /* RTC Frequency Compensation Register */
#define     REG_RTC_TLR		(RTC_BA+0x0C)   /* Time Loading Register */
#define     REG_RTC_CLR		(RTC_BA+0x10)   /* Calendar Loading Register */
#define     REG_RTC_TSSR	(RTC_BA+0x14)   /* Time Scale Selection Register */
#define     REG_RTC_DWR		(RTC_BA+0x18)   /* Day of the Week Register */
#define     REG_RTC_TAR		(RTC_BA+0x1C)   /* Time Alarm Register */
#define     REG_RTC_CAR		(RTC_BA+0x20)   /* Calendar Alarm Register */
#define     REG_RTC_LIR		(RTC_BA+0x24)   /* Leap year Indicator Register */
#define     REG_RTC_RIER	(RTC_BA+0x28)   /* RTC Interrupt Enable Register */
#define     REG_RTC_RIIR	(RTC_BA+0x2C)   /* RTC Interrupt Indicator Register */
#define     REG_RTC_TTR		(RTC_BA+0x30)   /* RTC Time Tick Register */

#define     rRTC_INIR		(*(unsigned int volatile *)REG_RTC_INIR)
#define     rRTC_AER		(*(unsigned int volatile *)REG_RTC_AER)
#define     rRTC_FCR		(*(unsigned int volatile *)REG_RTC_FCR)
#define     rRTC_TLR		(*(unsigned int volatile *)REG_RTC_TLR)
#define     rRTC_CLR		(*(unsigned int volatile *)REG_RTC_CLR)
#define     rRTC_TSSR		(*(unsigned int volatile *)REG_RTC_TSSR)
#define     rRTC_DWR		(*(unsigned int volatile *)REG_RTC_DWR)
#define     rRTC_TAR		(*(unsigned int volatile *)REG_RTC_TAR)
#define     rRTC_CAR		(*(unsigned int volatile *)REG_RTC_CAR)
#define     rRTC_LIR		(*(unsigned int volatile *)REG_RTC_LIR)
#define     rRTC_RIER		(*(unsigned int volatile *)REG_RTC_RIER)
#define     rRTC_RIIR		(*(unsigned int volatile *)REG_RTC_RIIR)
#define     rRTC_TTR		(*(unsigned int volatile *)REG_RTC_TTR)


/*
  SmartCard Controller Registers
*/
#define     REG_SC0_RBR		(SC_BA+0x000)   /* Receive Buffer Register */
#define     REG_SC0_TBR		(SC_BA+0x000)   /* Transmit Buffer Register */
#define     REG_SC0_IER		(SC_BA+0x004)   /* Interrupt Enable Register */
#define     REG_SC0_ISR		(SC_BA+0x008)   /* Interrupt Status Register */
#define     REG_SC0_SCFR	(SC_BA+0x008)   /* FIFO Control Register */
#define     REG_SC0_BLL		(SC_BA+0x000)   /* Baud Rate Divisor Latch Reg. (LB) */
#define     REG_SC0_BLH		(SC_BA+0x004)   /* Baud Rate Divisor Latch Reg. (HB) */
#define     REG_SC0_IDR		(SC_BA+0x008)   /* Card ID Number Register */
#define     REG_SC0_CCR		(SC_BA+0x00C)   /* Card Control Register */
#define     REG_SC0_CBR		(SC_BA+0x010)   /* Clock Base Register */
#define     REG_SC0_CSR		(SC_BA+0x014)   /* Card Status Register */
#define     REG_SC0_GTR		(SC_BA+0x018)   /* Guard Time Register */
#define     REG_SC0_ECR		(SC_BA+0x01C)   /* Extended Control Register */
#define     REG_SC0_TEST	(SC_BA+0x020)   /* SC Reset Test Mode Register */
#define     REG_SC0_TOC		(SC_BA+0x028)   /* Time out Configuration Register */
#define     REG_SC0_TOIR0	(SC_BA+0x02C)   /* Time out Initial Register 0 */
#define     REG_SC0_TOIR1	(SC_BA+0x030)   /* Time out Initial Register 1 */
#define     REG_SC0_TOIR2	(SC_BA+0x034)   /* Time out Initial Register 2 */
#define     REG_SC0_TOD0	(SC_BA+0x038)   /* Time out Data Register 0 */
#define     REG_SC0_TOD1	(SC_BA+0x03C)   /* Time out Data Register 1 */
#define     REG_SC0_TOD2	(SC_BA+0x040)   /* Time out Data Register 2 */
#define     REG_SC0_BTOR	(SC_BA+0x044)   /* Buffer Time out Data Register */
#define     REG_SC1_RBR		(SC_BA+0x800)   /* Receive Buffer Register */
#define     REG_SC1_TBR		(SC_BA+0x800)   /* Transmit Buffer Register */
#define     REG_SC1_IER		(SC_BA+0x804)   /* Interrupt Enable Register */
#define     REG_SC1_ISR		(SC_BA+0x808)   /* Interrupt Status Register */
#define     REG_SC1_SCFR	(SC_BA+0x808)   /* FIFO Control Register */
#define     REG_SC1_BLL		(SC_BA+0x800)   /* Baud Rate Divisor Latch Reg. (LB) */
#define     REG_SC1_BLH		(SC_BA+0x804)   /* Baud Rate Divisor Latch Reg. (HB) */
#define     REG_SC1_IDR		(SC_BA+0x808)   /* Card ID Number Register */
#define     REG_SC1_CCR		(SC_BA+0x80C)   /* Card Control Register */
#define     REG_SC1_CBR		(SC_BA+0x810)   /* Clock Base Register */
#define     REG_SC1_CSR		(SC_BA+0x814)   /* Card Status Register */
#define     REG_SC1_GTR		(SC_BA+0x818)   /* Guard Time Register */
#define     REG_SC1_ECR		(SC_BA+0x81C)   /* Extended Control Register */
#define     REG_SC1_TEST	(SC_BA+0x820)   /* SC Reset Test Mode Register */
#define     REG_SC1_TOC		(SC_BA+0x828)   /* Time out Configuration Register */
#define     REG_SC1_TOIR0	(SC_BA+0x82C)   /* Time out Initial Register 0 */
#define     REG_SC1_TOIR1	(SC_BA+0x830)   /* Time out Initial Register 1 */
#define     REG_SC1_TOIR2	(SC_BA+0x834)   /* Time out Initial Register 2 */
#define     REG_SC1_TOD0	(SC_BA+0x838)   /* Time out Data Register 0 */
#define     REG_SC1_TOD1	(SC_BA+0x83C)   /* Time out Data Register 1 */
#define     REG_SC1_TOD2	(SC_BA+0x840)   /* Time out Data Register 2 */
#define     REG_SC1_BTOR	(SC_BA+0x844)   /* Buffer Time out Data Register */

#define     rSC0_RBR		(*(unsigned int volatile *)REG_SC0_RBR)
#define     rSC0_TBR		(*(unsigned int volatile *)REG_SC0_TBR)
#define     rSC0_IER		(*(unsigned int volatile *)REG_SC0_IER)
#define     rSC0_ISR		(*(unsigned int volatile *)REG_SC0_ISR)
#define     rSC0_SCFR		(*(unsigned int volatile *)REG_SC0_SCFR)
#define     rSC0_BLL		(*(unsigned int volatile *)REG_SC0_BLL)
#define     rSC0_BLH		(*(unsigned int volatile *)REG_SC0_BLH)
#define     rSC0_IDR		(*(unsigned int volatile *)REG_SC0_IDR)
#define     rSC0_CCR		(*(unsigned int volatile *)REG_SC0_CCR)
#define     rSC0_CBR		(*(unsigned int volatile *)REG_SC0_CBR)
#define     rSC0_CSR		(*(unsigned int volatile *)REG_SC0_CSR)
#define     rSC0_GTR		(*(unsigned int volatile *)REG_SC0_GTR)
#define     rSC0_ECR		(*(unsigned int volatile *)REG_SC0_ECR)
#define     rSC0_TEST		(*(unsigned int volatile *)REG_SC0_TEST)
#define     rSC0_TOC		(*(unsigned int volatile *)REG_SC0_TOC)
#define     rSC0_TOIR0		(*(unsigned int volatile *)REG_SC0_TOIR0)
#define     rSC0_TOIR1		(*(unsigned int volatile *)REG_SC0_TOIR1)
#define     rSC0_TOIR2		(*(unsigned int volatile *)REG_SC0_TOIR2)
#define     rSC0_TOD0		(*(unsigned int volatile *)REG_SC0_TOD0)
#define     rSC0_TOD1		(*(unsigned int volatile *)REG_SC0_TOD1)
#define     rSC0_TOD2		(*(unsigned int volatile *)REG_SC0_TOD2)
#define     rSC0_BTOR		(*(unsigned int volatile *)REG_SC0_BTOR)
#define     rSC1_RBR		(*(unsigned int volatile *)REG_SC1_RBR)
#define     rSC1_TBR		(*(unsigned int volatile *)REG_SC1_TBR)
#define     rSC1_IER		(*(unsigned int volatile *)REG_SC1_IER)
#define     rSC1_ISR		(*(unsigned int volatile *)REG_SC1_ISR)
#define     rSC1_SCFR		(*(unsigned int volatile *)REG_SC1_SCFR)
#define     rSC1_BLL		(*(unsigned int volatile *)REG_SC1_BLL)
#define     rSC1_BLH		(*(unsigned int volatile *)REG_SC1_BLH)
#define     rSC1_IDR		(*(unsigned int volatile *)REG_SC1_IDR)
#define     rSC1_CCR		(*(unsigned int volatile *)REG_SC1_CCR)
#define     rSC1_CBR		(*(unsigned int volatile *)REG_SC1_CBR)
#define     rSC1_CSR		(*(unsigned int volatile *)REG_SC1_CSR)
#define     rSC1_GTR		(*(unsigned int volatile *)REG_SC1_GTR)
#define     rSC1_ECR		(*(unsigned int volatile *)REG_SC1_ECR)
#define     rSC1_TEST		(*(unsigned int volatile *)REG_SC1_TEST)
#define     rSC1_TOC		(*(unsigned int volatile *)REG_SC1_TOC)
#define     rSC1_TOIR0		(*(unsigned int volatile *)REG_SC1_TOIR0)
#define     rSC1_TOIR1		(*(unsigned int volatile *)REG_SC1_TOIR1)
#define     rSC1_TOIR2		(*(unsigned int volatile *)REG_SC1_TOIR2)
#define     rSC1_TOD0		(*(unsigned int volatile *)REG_SC1_TOD0)
#define     rSC1_TOD1		(*(unsigned int volatile *)REG_SC1_TOD1)
#define     rSC1_TOD2		(*(unsigned int volatile *)REG_SC1_TOD2)
#define     rSC1_BTOR		(*(unsigned int volatile *)REG_SC1_BTOR)


/*
  I2C 0 Control Registers
*/
#define     REG_IIC0_CS			(I2C0_BA+0x00)  /* Control and Status Register */
#define     REG_IIC0_DIVIDER	(I2C0_BA+0x04)  /* Clock Prescale Register */
#define     REG_IIC0_CMDR		(I2C0_BA+0x08)  /* Command Register */
#define     REG_IIC0_SWR		(I2C0_BA+0x0C)  /* Software Mode Control Register */
#define     REG_IIC0_RxR		(I2C0_BA+0x10)  /* Data Receive Register */
#define     REG_IIC0_TxR		(I2C0_BA+0x14)  /* Data Transmit Register */

#define     rIIC0_CS			(*(unsigned int volatile *)REG_IIC0_CS)
#define     rIIC0_DIVIDER		(*(unsigned int volatile *)REG_IIC0_DIVIDER)
#define     rIIC0_CMDR			(*(unsigned int volatile *)REG_IIC0_CMDR)
#define     rIIC0_SWR			(*(unsigned int volatile *)REG_IIC0_SWR)
#define     rIIC0_RxR			(*(unsigned int volatile *)REG_IIC0_RxR)
#define     rIIC0_TxR			(*(unsigned int volatile *)REG_IIC0_TxR)


/*
  I2C 1 Control Registers
*/
#define     REG_IIC1_CS			(I2C1_BA+0x00)  /* Control and Status Register */
#define     REG_IIC1_DIVIDER	(I2C1_BA+0x04)  /* Clock Prescale Register */
#define     REG_IIC1_CMDR		(I2C1_BA+0x08)  /* Command Register */
#define     REG_IIC1_SWR		(I2C1_BA+0x0C)  /* Software Mode Control Register */
#define     REG_IIC1_RxR		(I2C1_BA+0x10)  /* Data Receive Register */
#define     REG_IIC1_TxR		(I2C1_BA+0x14)  /* Data Transmit Register */

#define     rIIC1_CS			(*(unsigned int volatile *)REG_IIC1_CS)
#define     rIIC1_DIVIDER		(*(unsigned int volatile *)REG_IIC1_DIVIDER)
#define     rIIC1_CMDR			(*(unsigned int volatile *)REG_IIC1_CMDR)
#define     rIIC1_SWR			(*(unsigned int volatile *)REG_IIC1_SWR)
#define     rIIC1_RxR			(*(unsigned int volatile *)REG_IIC1_RxR)
#define     rIIC1_TxR			(*(unsigned int volatile *)REG_IIC1_TxR)


/* 
  USI Control Registers
*/
#define     REG_USI_CNTRL	(USI_BA+0x00)  /* Control and Status Register */
#define     REG_USI_DIVIDER	(USI_BA+0x04)  /* Clock Divider Register */
#define     REG_USI_SSR		(USI_BA+0x08)  /* Slave Select Register */
#define     REG_USI_Rx0		(USI_BA+0x10)  /* Data Receive Register 0 */
#define     REG_USI_Rx1		(USI_BA+0x14)  /* Data Receive Register 1 */
#define     REG_USI_Rx2		(USI_BA+0x18)  /* Data Receive Register 2 */
#define     REG_USI_Rx3		(USI_BA+0x1C)  /* Data Receive Register 3 */
#define     REG_USI_Tx0		(USI_BA+0x10)  /* Data Transmit Register 0 */
#define     REG_USI_Tx1		(USI_BA+0x14)  /* Data Transmit Register 1 */
#define     REG_USI_Tx2		(USI_BA+0x18)  /* Data Transmit Register 2 */
#define     REG_USI_Tx3		(USI_BA+0x1C)  /* Data Transmit Register 3 */

#define     rUSI_CNTRL		(*(unsigned int volatile *)REG_USI_CNTRL)
#define     rUSI_DIVIDER	(*(unsigned int volatile *)REG_USI_DIVIDER)
#define     rUSI_SSR		(*(unsigned int volatile *)REG_USI_SSR)
#define     rUSI_Rx0		(*(unsigned int volatile *)REG_USI_Rx0)
#define     rUSI_Rx1		(*(unsigned int volatile *)REG_USI_Rx1)
#define     rUSI_Rx2		(*(unsigned int volatile *)REG_USI_Rx2)
#define     rUSI_Rx3		(*(unsigned int volatile *)REG_USI_Rx3)
#define     rUSI_Tx0		(*(unsigned int volatile *)REG_USI_Tx0)
#define     rUSI_Tx1		(*(unsigned int volatile *)REG_USI_Tx1)
#define     rUSI_Tx2		(*(unsigned int volatile *)REG_USI_Tx2)
#define     rUSI_Tx3		(*(unsigned int volatile *)REG_USI_Tx3)


/*
  PWM Control Registers
*/
#define     REG_PWM_PPR		(PWM_BA+0x00)  /* PWM Pre-scale Register 0 */
#define     REG_PWM_CSR		(PWM_BA+0x04)  /* PWM Clock Select Register */
#define     REG_PWM_PCR		(PWM_BA+0x08)  /* PWM Control Register */
#define     REG_PWM_CNR0	(PWM_BA+0x0C)  /* PWM Counter Register 0 */
#define     REG_PWM_CMR0	(PWM_BA+0x10)  /* PWM Comparator Register 0 */
#define     REG_PWM_PDR0	(PWM_BA+0x14)  /* PWM Data Register 0 */
#define     REG_PWM_CNR1	(PWM_BA+0x18)  /* PWM Counter Register 1 */
#define     REG_PWM_CMR1	(PWM_BA+0x1C)  /* PWM Comparator Register 1 */
#define     REG_PWM_PDR1	(PWM_BA+0x20)  /* PWM Data Register 1 */
#define     REG_PWM_CNR2	(PWM_BA+0x24)  /* PWM Counter Register 2 */
#define     REG_PWM_CMR2	(PWM_BA+0x28)  /* PWM Comparator Register 2 */
#define     REG_PWM_PDR2	(PWM_BA+0x2C)  /* PWM Data Register 2 */
#define     REG_PWM_CNR3	(PWM_BA+0x30)  /* PWM Counter Register 3 */
#define     REG_PWM_CMR3	(PWM_BA+0x34)  /* PWM Comparator Register 3 */
#define     REG_PWM_PDR3	(PWM_BA+0x38)  /* PWM Data Register 3 */
#define     REG_PWM_PIER	(PWM_BA+0x3C)  /* PWM Timer Interrupt Enable Register */
#define     REG_PWM_PIIR	(PWM_BA+0x40)  /* PWM Timer Interrupt Identification Register */

#define     rPWM_PPR		(*(unsigned int volatile *)REG_PWM_PPR)
#define     rPWM_CSR		(*(unsigned int volatile *)REG_PWM_CSR)
#define     rPWM_PCR		(*(unsigned int volatile *)REG_PWM_PCR)
#define     rPWM_CNR0		(*(unsigned int volatile *)REG_PWM_CNR0)
#define     rPWM_CMR0		(*(unsigned int volatile *)REG_PWM_CMR0)
#define     rPWM_PDR0		(*(unsigned int volatile *)REG_PWM_PDR0)
#define     rPWM_CNR1		(*(unsigned int volatile *)REG_PWM_CNR1)
#define     rPWM_CMR1		(*(unsigned int volatile *)REG_PWM_CMR1)
#define     rPWM_PDR1		(*(unsigned int volatile *)REG_PWM_PDR1)
#define     rPWM_CNR2		(*(unsigned int volatile *)REG_PWM_CNR2)
#define     rPWM_CMR2		(*(unsigned int volatile *)REG_PWM_CMR2)
#define     rPWM_PDR2		(*(unsigned int volatile *)REG_PWM_PDR2)
#define     rPWM_CNR3		(*(unsigned int volatile *)REG_PWM_CNR3)
#define     rPWM_CMR3		(*(unsigned int volatile *)REG_PWM_CMR3)
#define     rPWM_PDR3		(*(unsigned int volatile *)REG_PWM_PDR3)
#define     rPWM_PIER		(*(unsigned int volatile *)REG_PWM_PIER)
#define     rPWM_PIIR		(*(unsigned int volatile *)REG_PWM_PIIR)


/*
  KPI Control Registers
*/
#define     REG_KPI_CONF	(KPI_BA+0x00)  /* Keypad controller configuration Register */
#define     REG_KPI_3KCONF	(KPI_BA+0x04)  /* Keypad controller 3-keys configuration register */
#define     REG_KPI_LPCONF	(KPI_BA+0x08)  /* Keypad controller low power configuration register */
#define     REG_KPI_STATUS	(KPI_BA+0x0C)  /* Keypad controller status register */

#define     rKPI_CONF	(*(unsigned int volatile *)REG_KPI_CONF)
#define     rKPI_3KCONF	(*(unsigned int volatile *)REG_KPI_3KCONF)
#define     rKPI_LPCONF	(*(unsigned int volatile *)REG_KPI_LPCONF)
#define     rKPI_STATUS	(*(unsigned int volatile *)REG_KPI_STATUS)


/*
  PS2 Control Registers
*/
#define     REG_PS2_CMD0		(PS2_BA+0x000)  /* PS2 port 0 Host Controller Command Register */
#define     REG_PS2_STS0		(PS2_BA+0x004)  /* PS2 port 0 Host Controller Status Register */
#define     REG_PS2_SCANCODE0	(PS2_BA+0x008)  /* PS2 port 0 Host Controller Rx Scan Code Register */
#define     REG_PS2_ASCII0		(PS2_BA+0x00C)  /* PS2 port 0 Host Controller Rx ASCII Code */
#define     REG_PS2_CMD1		(PS2_BA+0x100)  /* PS2 port 1 Host Controller Command Register */
#define     REG_PS2_STS1		(PS2_BA+0x104)  /* PS2 port 1 Host Controller Status Register */
#define     REG_PS2_SCANCODE1	(PS2_BA+0x108)  /* PS2 port 1 Host Controller Rx Scan Code Register */
#define     REG_PS2_ASCII1		(PS2_BA+0x10C)  /* PS2 port 1 Host Controller Rx ASCII Code */
 
#define     rPS2_CMD0			(*(unsigned int volatile *)REG_PS2_CMD0)
#define     rPS2_STS0			(*(unsigned int volatile *)REG_PS2_STS0)
#define     rPS2_SCANCODE0		(*(unsigned int volatile *)REG_PS2_SCANCODE0)
#define     rPS2_ASCII0			(*(unsigned int volatile *)REG_PS2_ASCII0)
#define     rPS2_CMD1			(*(unsigned int volatile *)REG_PS2_CMD1)
#define     rPS2_STS1			(*(unsigned int volatile *)REG_PS2_STS1)
#define     rPS2_SCANCODE1		(*(unsigned int volatile *)REG_PS2_SCANCODE1)
#define     rPS2_ASCII1			(*(unsigned int volatile *)REG_PS2_ASCII1)
 
 
/*
  ADC Control Registers
*/
#define     REG_ADC_CON		(ADC_BA+0x00)  /* ADC control register */
#define     REG_ADC_TSC		(ADC_BA+0x04)  /* Touch screen control register */
#define     REG_ADC_DLY		(ADC_BA+0x08)  /* ADC delay register */
#define     REG_ADC_XDATA	(ADC_BA+0x0C)  /* ADC XDATA register */
#define     REG_ADC_YDATA	(ADC_BA+0x10)  /* ADC YDATA register */
#define     REG_ADC_LV_CON	(ADC_BA+0x14)  /* Low Voltage Detector Control register */
#define     REG_ADC_LV_STS	(ADC_BA+0x18)  /* Low Voltage Detector Status register */

#define     rADC_CON		(*(unsigned int volatile *)REG_ADC_CON)
#define     rADC_TSC		(*(unsigned int volatile *)REG_ADC_TSC)
#define     rADC_DLY		(*(unsigned int volatile *)REG_ADC_DLY)
#define     rADC_XDATA		(*(unsigned int volatile *)REG_ADC_XDATA)
#define     rADC_YDATA		(*(unsigned int volatile *)REG_ADC_YDATA)
#define     rADC_LV_CON		(*(unsigned int volatile *)REG_ADC_LV_CON)
#define     rADC_LV_STS		(*(unsigned int volatile *)REG_ADC_LV_STS)

#endif /* _NUC900_H */