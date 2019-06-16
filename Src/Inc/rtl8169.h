
/* The capability table matches the chip table above. */
#define HAS_MII_XCVR	0x01
#define HAS_CHIP_XCVR	0x02
#define HAS_LNK_CHNG	0x04


/* The rest of these values should never change. */
//#define NUM_TX_DESC     4                       /* Number of Tx descriptor registers. */

#define InterFrameGap       0x03    /* 3 means InterFrameGap = the shortest one */

#define NUM_TX_DESC         1     /* Number of Tx descriptor registers*/
#define NUM_RX_DESC         8     /* Number of Rx descriptor registers*/


#define ETH_HDR_LEN	14
#define MTU_SIZE	1500

#define RX_PKT_LEN MTU_SIZE+ETH_HDR_LEN
#define HW_RX_PKT_LEN RX_PKT_LEN+8

/* Symbolic offsets to registers. */
// RTL8139_registers
#define MAC0				0          /* Ethernet hardware address. */
#define MAR0				8          /* Multicast filter. */
#define TxStatus0			0x10   /* Transmit status */
#define TxDescStartAddr		0x20   /* Tx descriptors address */
#define TxHDescStartAddr	0x28   /* Tx high priority descriptors address */
#define RxBuf				0x30
#define RxEarlyCnt			0x34
#define RxEarlyStatus		0x36
#define ChipCmd				0x37
#define TxPoll				0x38
#define IntrMask			0x3C
#define IntrStatus			0x3E
#define TxConfig			0x40
#define RxConfig			0x44
#define Timer				0x48   /* A general-purpose counter. */
#define RxMissed			0x4C   /* 24 bits valid, write clears. */
#define Cfg9346				0x50
#define Config0				0x51
#define Config1				0x52
#define Config2				0x53
#define Config3				0x54
#define Config4				0x55
#define Config5				0x56
#define MultiIntr			0x5C
#define PHYAR				0x60
#define PHYstatus			0x6C
#define RxMaxSize       	0xDA
#define CPlusCmd 			0xE0
#define RxDescStartAddr	    0xE4
#define ETThReg				0xEC

/*ChipCmdBits*/                        	
#define CmdReset			0x10
#define CmdRxEnb			0x08
#define CmdTxEnb			0x04
#define RxBufEmpty			0x01

/*Cfg9346Bits*/
#define Cfg9346_Lock		0x00
#define Cfg9346_Unlock		0xC0

/*RxConfigBits*/
#define RxCfgFIFOShift	13
#define	RxCfgDMAShift	8

/*TxConfigBits*/
#define TxInterFrameGapShift	24
#define	TxDMAShift 				8

/* Interrupt register bits, using my own meaningful names. */
//enum IntrStatusBits {
/*
#define PCIErr		0x8000
#define PCSTimeout	0x4000
#define RxFIFOOver	0x40
#define RxUnderrun	0x20
#define RxOverflow	0x10
#define TxErr		0x08
#define TxOK		0x04
#define RxErr		0x02
#define RxOK		0x01
*/

/*InterruptStatusBits*/
#define	SYSErr			0x8000
#define	PCSTimeout		0x4000
#define	SWInt			0x0100
#define	TxDescUnavail	0x80
#define	RxFIFOOver 		0x40
#define	LinkChg 		0x20
#define	RxOverflow 		0x10
#define	TxErr 			0x08
#define	TxOK 			0x04
#define	RxErr 			0x02
#define	RxOK 			0x01



/*RxStatusDesc*/
#define	RxRES  0x00200000
#define	RxCRC  0x00080000
#define	RxRUNT 0x00100000
#define	RxRWT  0x00400000

//enum rx_mode_bits {
#define AcceptErr		0x20
#define AcceptRunt		0x10
#define AcceptBroadcast	0x08
#define AcceptMulticast	0x04
#define AcceptMyPhys	0x02
#define AcceptAllPhys	0x01

/* Twister tuning parameters from RealTek.
   Completely undocumented, but required to tune bad links. */
//enum CSCRBits {
#define CSCR_LinkOKBit			0x0400
#define CSCR_LinkChangeBit		0x0800
#define CSCR_LinkStatusBits		0x0f000
#define CSCR_LinkDownOffCmd		0x003c0
#define CSCR_LinkDownCmd		0x0f3c0

//======================================================
/* Size of the in-memory receive ring. */
#define RX_BUF_LEN_IDX		3		/* 0==8K, 1==16K, 2==32K, 3==64K */
#define RX_BUF_LEN			(8192 << RX_BUF_LEN_IDX)
/* Size of the Tx bounce buffers -- must be at least (dev->mtu+14+4). */
#define TX_BUF_SIZE			1536

/* PCI Tuning Parameters
   Threshold is bytes transferred to chip before transmission starts. */
#define TX_FIFO_THRESH		256		/* In bytes, rounded down to 32 byte units. */

/* The following settings are log_2(bytes)-4:  0 == 16 bytes .. 6==1024. */
//#define RX_FIFO_THRESH		4		/* Rx buffer level before first PCI xfer.  */
#define RX_FIFO_THRESH		7		/* 7 means NO threshold, Rx buffer level before first PCI xfer.  */
#define RX_DMA_BURST		7		/* Maximum PCI burst, '4' is 256 bytes */
#define TX_DMA_BURST		7		/* Calculate as 16<<val. */
#define ETTh                0x3F    /* 0x3F means NO threshold */

/* Operational parameters that usually are not changed. */
/* Time in jiffies before concluding the transmitter is hung. */
#define TX_TIMEOUT			(4*HZ)

/*GIGABIT_PHY_registers*/
#define PHY_CTRL_REG 		 0
#define PHY_STAT_REG 		 1
#define PHY_AUTO_NEGO_REG 	 4
#define PHY_1000_CTRL_REG 	 9


/*rtl8169_PHYstatus (MAC offset 0x6C)*/
#define	TBI_Enable	 0x80
#define	TxFlowCtrl	 0x40
#define	RxFlowCtrl	 0x20
#define	_1000Mbps	 0x10
#define	_100Mbps	 0x08
#define	_10Mbps		 0x04
#define	LinkStatus	 0x02
#define	FullDup		 0x01



/*GIGABIT_PHY_REG_BIT*/
#define	PHY_Restart_Auto_Nego	 0x0200
#define	PHY_Enable_Auto_Nego	 0x1000

//PHY_STAT_REG = 1;
#define	PHY_Auto_Neco_Comp	 0x0020
#define PHY_Link_Up			 (1<<2)		

//PHY_AUTO_NEGO_REG = 4;
#define	PHY_Cap_10_Half		0x0020
#define	PHY_Cap_10_Full		0x0040
#define	PHY_Cap_100_Half	0x0080
#define	PHY_Cap_100_Full	0x0100

//PHY_1000_CTRL_REG = 9;
#define PHY_Cap_1000_Full	 0x0200
#define PHY_Cap_1000_Half	 0x0100
#define	PHY_Cap_PAUSE		 0x0400
#define PHY_Cap_ASYM_PAUSE	 0x0800
#define PHY_Cap_Null		 0x0



#define AUTONEG_ENABLE	1
#define AUTONEG_DISABLE 0

#define DUPLEX_FULL	0
#define DUPLEX_HALF	1

#define SPEED_10	0
#define SPEED_100	1
#define SPEED_1000	2

//======================================================
//RTL8169 status descriptor 
typedef struct TxDesc {
	UINT32		status;
	UINT32		vlan_tag;
	UINT32		buf_addr;
	UINT32		buf_Haddr;
} TXDESC;
typedef struct RxDesc {
	UINT32		status;
	UINT32		vlan_tag;
	UINT32		buf_addr;
	UINT32		buf_Haddr;
} RXDESC;

enum _DescStatusBit {
	OWNbit	= 0x80000000,
	EORbit	= 0x40000000,
	FSbit	= 0x20000000,
	LSbit	= 0x10000000
};


// MAC Frame Structure
typedef struct ETH_HEADER
{
	unsigned char	DestinationAddr[6] ;
	unsigned char	SourceAddr[6] ;
	unsigned char	LengthOrType[2] ;
} etheader;

typedef struct MACFrame
{
	etheader		Header ;
	unsigned char	LLCData[1506] ;
} sMACFrame;

struct net_stats
{
	unsigned int rx_packets;
	unsigned int tx_packets;
	unsigned int rx_bytes;
	unsigned int rx_errors;
	unsigned int tx_errors;
	unsigned int tx_bytes;
	unsigned int collisions;

	// detailed rx_errors
	unsigned int rx_length_errors;
	unsigned int rx_over_errors;
	unsigned int rx_fifo_errors;
	unsigned int rx_missed_errors;
	unsigned int rx_frame_errors;
	unsigned int rx_crc_errors;

	// detailed tx_errors
	unsigned int tx_aborted_errors;
	unsigned int tx_carrier_errors;
	unsigned int tx_fifo_errors;
	unsigned int tx_window_errors;
};


__align(4096) static TXDESC _TXDESCARRAY[NUM_TX_DESC];
__align(4096) static RXDESC _RXDESCARRAY[NUM_RX_DESC];
__align(4096) static UINT8 _RX_BUFFPTR[NUM_RX_DESC][HW_RX_PKT_LEN];
static sMACFrame _TX_BUFF;
BOOL volatile _TXOK_FLAG = TRUE;
BOOL volatile _RXOK_FLAG = FALSE;


//======================================================



