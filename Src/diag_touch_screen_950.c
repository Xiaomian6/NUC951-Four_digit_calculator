#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NUC900_reg.h"
#include "wblib.h"
#include "NUC900_vpost.h"
#include "NUC900_i2c.h"

#define I2C_NUMBER				2

#define I2C_FIFO_LEN			4
#define I2C_MAX_BUF_LEN			450
#define I2C_MAX_DATA_LEN		(I2C_MAX_BUF_LEN - 10)


#define GPIOH_DIR			(GPIO_BA+0x54)
#define GPIOH_DATAIN		(GPIO_BA+0x5C)

#define SYNC_TYPE

#define LEN                  8
#define SHIFT                3
#define AXIS_X1             30
#define AXIS_Y1             30 
#define AXIS_X2             30
#define AXIS_Y2             73   
#define AXIS_X3             30
#define AXIS_Y3            116
#define AXIS_X4            	73
#define AXIS_Y4            	30
#define AXIS_X5            	73
#define AXIS_Y5            	73
#define AXIS_X6            	73
#define AXIS_Y6            116
#define AXIS_X7            116
#define AXIS_Y7            	30
#define AXIS_X8            116
#define AXIS_Y8            	73
#define AXIS_X9            116
#define AXIS_Y9            116
#define AXIS_X10           159
#define AXIS_Y10           	30
#define AXIS_X11           159
#define AXIS_Y11            73
#define AXIS_X12           159
#define AXIS_Y12           116
#define AXIS_X13           202
#define AXIS_Y13           	30
#define AXIS_X14           202
#define AXIS_Y14           	73
#define AXIS_X15           202
#define AXIS_Y15           116
#define AXIS_X16           245
#define AXIS_Y16           	30


#define SYS_CLOCK			14318000

static int volatile LCD_BUFF_BASE;
#undef sysprintf
#define sysprintf printf


enum tsc2007_pd {
  PD_POWERDOWN = 0, /* penirq */
  PD_IREFOFF_ADCON = 1, /* no penirq */
  PD_IREFON_ADCOFF = 2, /* penirq */
  PD_IREFON_ADCON = 3, /* no penirq */
  PD_PENIRQ_ARM = PD_IREFON_ADCOFF,
  PD_PENIRQ_DISARM = PD_IREFON_ADCON
};

enum tsc2007_m {
  M_12BIT = 0,
  M_8BIT = 1
};

enum tsc2007_cmd {
  MEAS_TEMP0 = 0,
  MEAS_VBAT1 = 1,
  MEAS_IN1 = 2,
  MEAS_TEMP1 = 4,
  MEAS_VBAT2 = 5,
  MEAS_IN2 = 6,
  ACTIVATE_NX_DRIVERS = 8,
  ACTIVATE_NY_DRIVERS = 9,
  ACTIVATE_YNX_DRIVERS = 10,
  SETUP = 11,
  MEAS_XPOS = 12,
  MEAS_YPOS = 13,
  MEAS_Z1POS = 14,
  MEAS_Z2POS = 15
};

#define TSC2007_CMD(cn,pdn,m) (((cn) << 4) | ((pdn) << 2) | ((m) << 1))

static int first_time_test = 1;

char 	i2c_buff[1024];
volatile int  i2c_state, i2c_data_len, i2c_data_pos;
static volatile int  i2c_interrupt = 0;

static int bNackValid;

static int _Touch_Event = 0;

static int i2c_init(void);
VOID set_target(INT16 Center_X, INT16 Center_Y);
VOID reset_screen(VOID);
INT  ts_location_test(VOID);
INT  line_draw_test(VOID);
INT  get_touch_data(INT *x_pos, INT *y_pos);


static void delay_ticks(int tick)
{
	volatile int  t0;

	for (t0 = 0; t0 < tick * 1000; t0 ++)
	;	
}



void nirq0_irq()
{
	_Touch_Event = 1;
	sysDisableInterrupt(IRQ_GROUP0); 	
}


INT diag_touch_screen(void)
{  
    LCDFORMATEX lcdformatex;
    UINT32 		*pframbuf=NULL;
    int			i;
#if 0	
	WB_PLL_T 			sysClock;
	
	sysClock.pll0 = PLL_200MHZ;				//PLL0 output clock
	sysClock.pll1 = PLL_100MHZ;				//PLL1 output clock
	sysClock.cpu_src = CPU_FROM_PLL0;		//Select CPU clock source
	sysClock.ahb_clk = AHB_CPUCLK_1_2;		//Select AHB clock divider
	sysClock.apb_clk = APB_AHB_1_2;			//Select APB clock divider
	sysSetPLLConfig(&sysClock);				//Call system function call
#endif

	sysSetTimerReferenceClock (TIMER0, SYS_CLOCK);
	sysStartTimer(TIMER0, 100, PERIODIC_MODE);
	
	lcdformatex.ucVASrcFormat = VA_SRC_RGB565;
    vpostLCMInit(&lcdformatex);
	pframbuf = vpostGetFrameBuffer();
	LCD_BUFF_BASE = (int) pframbuf;
    for (i=0; i < 320*240; i++)
    {
       *pframbuf++ = 0;
    }	  

	if (!first_time_test)
		goto go_test;
   
    /* set GPIOH[3:0] for nIRQ[3:0] */
    //outpw(REG_MFSEL, inpw(REG_MFSEL) | 0x1000000);      

	/* install nIRQ0 interrupt */
	sysDisableInterrupt(IRQ_GROUP0); 	
	sysInstallISR(IRQ_LEVEL_1, IRQ_GROUP0, (PVOID)nirq0_irq);
	sysSetLocalInterrupt(ENABLE_IRQ);                            

	/* enable nIRQ0 group interrupt */
	outpw(REG_AIC_GEN, inpw(REG_AIC_GEN) | 0x01);  
            
    i2c_init();

	/* nIRQ0 must keep disable until tc2007 power down */
	//sysEnableInterrupt(IRQ_GROUP0); 	

go_test:
    
	if (ts_location_test() == 0)
	{
		sysprintf("Touch screen test OK.\n");
		//sysprintf("Press any key to continue next test...\n");
		//sysGetChar();
	}
	else
	{
		sysprintf("Press any key to exit test...\n");
		sysGetChar();
		return -1;
	}
	
	//line_draw_test();
	
    return 0;
}



static void i2c_Disable(void)	/* Disable i2c core and interrupt */
{
	outpw(REG_IIC0_CS, 0);
}


static void i2c_Enable(void)	/* Enable i2c core and interrupt */
{
	outpw(REG_IIC0_CS, 0x03);
}


static int i2c_IsBusFree(void)
{	
	if (((inpw(REG_IIC0_SWR) & 0x18) == 0x18) &&  //SDR and SCR keep high 
		((inpw(REG_IIC0_CS) & 0x0400) == 0))
	{  	
		//I2C_BUSY is false
		return 1;
	}
	else
	{		
		return 0;
	}

}


static int i2c_Command(int cmd)
{
	if (cmd & I2C_CMD_WRITE)
		bNackValid = 1;
	else
		bNackValid = 0;

	outpw(REG_IIC0_CMDR, cmd);

	return 0;

}

static int i2c_CalculateAddress(int mode)
{
	unsigned int addr;

	addr = 0x48;
	
	if (mode == I2C_STATE_WRITE)
		addr = ((addr << 1) & 0xfe);
	else
		addr = ((addr << 1) & 0xfe) | I2C_READ;

	i2c_buff[0] = addr & 0xff;
	return 0;	
}


static int i2c_read(unsigned char *buf, int count)
{	
	if (count == 0)
		return 0;
	
	if (!i2c_IsBusFree())
	{
		sysprintf("bus error\n");
		return -1;
	}
	
	if (count > I2C_MAX_BUF_LEN - 10)
		count = I2C_MAX_BUF_LEN - 10;

	i2c_state = I2C_STATE_READ;
	i2c_data_pos = 1;
	i2c_data_len = 1 + count + 1;/* plus 1 unused char */

	i2c_interrupt = 0;
	
	i2c_CalculateAddress(I2C_STATE_READ);
	i2c_Enable();
	outpw(REG_IIC0_TxR, i2c_buff[0] & 0xff	);
	i2c_Command(I2C_CMD_START | I2C_CMD_WRITE);

	while (!i2c_interrupt && (i2c_state != I2C_STATE_NOP)) ;

	i2c_Disable();

	memcpy(buf, i2c_buff + 2, count);
		
	return count;
}


static int i2c_write(unsigned char *buf, int count)
{	
	if (!i2c_IsBusFree())
		return -1;
	
	if (count > I2C_MAX_DATA_LEN)
		count = I2C_MAX_DATA_LEN;

	memcpy(i2c_buff + 1 , buf, count);
	
	i2c_state = I2C_STATE_WRITE;
	i2c_data_pos = 1;
	i2c_data_len = 1 + count;
	
	i2c_interrupt = 0;
	
	i2c_CalculateAddress(I2C_STATE_WRITE);		//put the first data byte into i2c_buff
	i2c_Enable();
	outpw(REG_IIC0_TxR, i2c_buff[0] & 0xff);	/* send first byte */
	i2c_Command(I2C_CMD_START | I2C_CMD_WRITE);

	while (!i2c_interrupt && (i2c_state != I2C_STATE_NOP)) ;
	
	i2c_Disable();

	return count;
}


void i2c_irq()
{
	int 	csr, val;

	//sysprintf("i2c interrupt.\n");
	
	i2c_interrupt = 1;

	csr = inpw(REG_IIC0_CS);
	csr |= 0x04;		/* mark interrupt flag */
	outpw(REG_IIC0_CS, csr);
		
	if (i2c_state == I2C_STATE_NOP)
	{
		sysprintf("i2c_irq - I2C_STATE_NOP\n");
		return;
	}

	//sysprintf("bNackValid = %d\n", bNackValid);

	if ((csr & 0x800) && bNackValid)
	{					/* NACK only valid in WRITE */
		sysprintf("NACK Error\n");
		i2c_Command(I2C_CMD_STOP);
		goto wake_up_quit;
	}
	else if (csr & 0x200)
	{					/* Arbitration lost */
		sysprintf("Arbitration lost\n");
		i2c_Command(I2C_CMD_STOP);
		goto wake_up_quit;
	}
	else if (!(csr & 0x100))
	{					/* transmit complete */
		if (i2c_data_pos < 1)
		{	
			/* send address state */
			//sysprintf("irq - Send Address\n");
			val = i2c_buff[i2c_data_pos++] & 0xff;
			outpw(REG_IIC0_TxR, val);
			i2c_Command(I2C_CMD_WRITE);
		}
		else if (i2c_state == I2C_STATE_READ)
		{	
			i2c_buff[i2c_data_pos++] = inpw(REG_IIC0_RxR) & 0xff;

			//sysprintf("Read Pos : [%02x]   Data : [%02x]\n", i2c_data_pos, i2c_buff[i2c_data_pos-1]);

			if (i2c_data_pos < i2c_data_len)
			{
				//sysprintf("Read Next\n");
				if (i2c_data_pos == i2c_data_len - 1)	/* last character */
					i2c_Command(I2C_CMD_READ |
									I2C_CMD_STOP |
									I2C_CMD_NACK);
				else
					i2c_Command(I2C_CMD_READ);
			}
			else
			{
				//sysprintf("Read Over \n");
				goto wake_up_quit;
			}
		}
		else if (i2c_state == I2C_STATE_WRITE)
		{	/* write data */
			if (i2c_data_pos < i2c_data_len)
			{
				//sysprintf("Write Pos : [%02x]   Data : [%02x]\n", i2c_data_pos, i2c_buff[i2c_data_pos]);

				val = i2c_buff[i2c_data_pos];

				outpw(REG_IIC0_TxR, val);
				
				if (i2c_data_pos == i2c_data_len - 1)	/* last character */
					i2c_Command(I2C_CMD_WRITE| I2C_CMD_STOP);				
				else
					i2c_Command(I2C_CMD_WRITE);

				i2c_data_pos ++;
			}
			else
			{
				//sysprintf("Write Over\n");
				goto wake_up_quit;
			}
		}

	}
	
	return;
	
wake_up_quit:
	i2c_state = I2C_STATE_NOP;
	//sysprintf("Wake up \n");
}



static int tsc2007_powerdown(void)
{
	//char 	c;
	unsigned char 	data[2];
	int 	count = 0;
		
	data[0] = TSC2007_CMD(MEAS_XPOS, PD_POWERDOWN, M_12BIT);
	//i2c_set_dev_address(0x48);
	//i2c_set_sub_address(c, 0);
	if (i2c_write(&data[0], 1) < 0)
		return 0;	
		
	return count;
}

static int i2c_SetSpeed(int sp)
{
	UINT32  reg;

	if ((sp != 100) && (sp != 400))
		return -1;

	reg = I2C_INPUT_CLOCK/(sp * 5) -1;
	outpw(REG_IIC0_DIVIDER, reg & 0xffff);
	return 0;
}


/* init i2c_dev after open */
static int i2c_ResetI2C(void)
{	
	return i2c_SetSpeed(100);
}


static int i2c_init(void)	/* init I2C channel */
{
	int  t0;
	
	outpw(REG_CLKEN, inpw(REG_CLKEN) | 0xC0000000);
	
	outpw(REG_MFSEL, ((inpw(REG_MFSEL) | 0x4000) & 0xFFFF4FFF));
	
	outpw(REG_AIC_GEN, inpw(REG_AIC_GEN) | 0x400000);

	sysInstallISR(IRQ_LEVEL_1, IRQ_I2C_GROUP, (PVOID)i2c_irq);
	sysSetLocalInterrupt(ENABLE_IRQ);                            
	sysEnableInterrupt(IRQ_I2C_GROUP); 	

	/* enable I2C group interrupt */
	outpw(REG_AIC_GEN, inpw(REG_AIC_GEN) | 0x0C000000);  
	
	if (i2c_ResetI2C())
	{
		sysprintf("\n\nFailed to init I2C!!\n");
		return -1;
	}
	
	t0 = sysGetTicks(TIMER0);
	while (sysGetTicks(TIMER0) - t0 < 30)
		;
	
	tsc2007_powerdown();
	
	return 0;	
}


VOID set_target(INT16 Center_X, INT16 Center_Y)
{
    //Center_X = 60;
    //Center_Y = 60; 
    INT16 X,Y;
    int i;
    
	i=0;
	Center_Y = 240 - Center_Y;
	//框

    for (X = (Center_X-20); X <= (Center_X+20); X++)
    {
       Y = Center_Y - 20;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
       Y = Center_Y + 20;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    }
    
    for (Y = (Center_Y-20); Y <= (Center_Y+20); Y++)
    {
       X = Center_X - 20;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
       X = Center_X + 20;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    }    
    //设置整个框是绿色的
    for (X = (Center_X-20+1); X < (Center_X+20); X++)
    {
       for (Y = (Center_Y-20+1); Y < (Center_Y+20); Y++)
       {
           *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0x07E0;
       }
    }
    //0
    if(Center_X==30&&Center_Y==210){
    //画符号
    for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y+7;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    }
    for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y-7;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    }
    
    for (Y = (Center_Y-7); Y <= (Center_Y+7); Y++)
    {
       X = Center_X+5;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    }   
     for (Y = (Center_Y-7); Y <= (Center_Y+7); Y++)
    {
       X = Center_X-5;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    }   
    }
    //1
	if(Center_X==30&&Center_Y==167)
	{
	for (Y = (Center_Y-7); Y <= (Center_Y+7); Y++)//竖
    {
       X = Center_X;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    }    
    }
    //2
	if(Center_X==30&&Center_Y==124)
	{
		for (Y = Center_Y; Y <= (Center_Y+7); Y++)
    {
       X = Center_X-5;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    }   
    for (Y = (Center_Y-7); Y <= Center_Y; Y++)
    {
       X = Center_X+5;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    }   
    for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y-7;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    }
     for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y+7;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    }
     for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    }
    
	}
	//3
	if(Center_X==73&&Center_Y==210)
	{
	for (Y = (Center_Y-7); Y <= (Center_Y+7); Y++)
    {
       X = Center_X+5;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    }    
    for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y-7;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    }
     for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y+7;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    }
     for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    }
	}
	//4
	if(Center_X==73&&Center_Y==167)
	{
		for (Y = Center_Y-7; Y <= (Center_Y); Y++)
    {
       X = Center_X-5;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    } 
    for (Y = (Center_Y-7); Y <= (Center_Y+7); Y++)
    {
       X = Center_X;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    } 
     for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    }
	}
	//5
	if(Center_X==73&&Center_Y==124)
	{
		for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    }
    for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y+7;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    }
    for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y-7;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    }
     for (Y = Center_Y-7; Y <= (Center_Y); Y++)
    {
       X = Center_X-5;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    } 
    for (Y = (Center_Y); Y <= Center_Y+7; Y++)
    {
       X = Center_X+5;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    } 
    
	}
	//6
	if(Center_X==116&&Center_Y==210)
	{
		for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
     }
       
        for (Y = (Center_Y-7); Y <= (Center_Y+7); Y++)
    {
       X = Center_X-5;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    } 
    
    for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y+7;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
     }
      for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y-7;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
     }
     for (Y = (Center_Y); Y <= (Center_Y+7); Y++)
    {
       X = Center_X+5;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    } 
	}
	//7
	if(Center_X==116&&Center_Y==167)
	{
		 for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y-7;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
     }
     
      for (Y = (Center_Y-7); Y <= (Center_Y+7); Y++)
    {
       X = Center_X+5;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    } 
	}
	//8
	if(Center_X==116&&Center_Y==124)
	{
	 for (Y = (Center_Y-7); Y <= (Center_Y+7); Y++)
    {
       X = Center_X+5;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    } 
    
     for (Y = (Center_Y-7); Y <= (Center_Y+7); Y++)
    {
       X = Center_X-5;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    } 
    for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y+7;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
     }
     for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
     }
     for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y-7;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
     }
	}
	//9
	if(Center_X==159&&Center_Y==210)
	{
	 for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y+7;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
     }
     for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
     }
     for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y-7;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
     }
      for (Y = (Center_Y-7); Y <= (Center_Y); Y++)
    {
       X = Center_X-5;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    } 
     for (Y = (Center_Y-7); Y <= (Center_Y+7); Y++)
    {
       X = Center_X+5;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    } 
	}
	//+
	if(Center_X==159&&Center_Y==167)
	{
		for (Y = (Center_Y-7); Y <= (Center_Y+7); Y++)
    {
       X = Center_X;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
    } 
    for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
     }
	}
	//-
	if(Center_X==159&&Center_Y==124)
	{
	for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
     }
	}
	//*
	if(Center_X==202&&Center_Y==210)
	{
		for (Y = (Center_Y-5); Y <= (Center_Y+5); Y++)
    {
    	
       X = Center_X-5+i;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
       i++;
    } 
    	i=0;
    	for (Y = (Center_Y-5); Y <= (Center_Y+5); Y++)
    {
    	
       X = Center_X+5-i;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
       i++;
    }
    	i=0; 
    	
	}
	// /
	if(Center_X==202&&Center_Y==167)
	{
		for (Y = (Center_Y-5); Y <= (Center_Y+5); Y++)
    {
    	
       X = Center_X+5-i;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
       i++;
    }
    i=0;
	}
	//=
	if(Center_X==202&&Center_Y==124)
	{
		for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y+2;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
     }
     for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y-2;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
     }
	}
	if(Center_X==245&&Center_Y==210)
	{
		for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y+2;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
     }
     for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
     }
     for (X = (Center_X-5); X <= (Center_X+5); X++)
    {
       Y = Center_Y-2;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xF800;
     }
     
	}
	//清零
	if(Center_X==02&&Center_Y==0)
	{
		for (Y = (Center_Y-5); Y <= (Center_Y+5); Y++)
    {
    	
       X = Center_X+5-i;
       *(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0x0000;
       i++;
    }
	}
	
}

VOID reset_screen(VOID)
{
	short *ptr;
	int i;
	
	ptr = (short*)LCD_BUFF_BASE;

    for(i=0;i<320*240;i++)
    {
    	*ptr++ = 0;
    }
}


// get x position(should disable PENIRQ before executing this command)
int tsc2007_read_xpos(void)
{ 
	unsigned char data[2];
	int count, value;
		
	data[0] = TSC2007_CMD(MEAS_XPOS, PD_PENIRQ_DISARM, M_12BIT);

	if (i2c_write(&data[0], 1) < 0)
		return 0;
		
	delay_ticks(100);
			
	if ((count = i2c_read(&data[0] ,2)) < 0)
		return 0;
	
	value = data[0];
	value <<= 4;
	value += (data[1] >> 4);
		
	return value;
}

//get y position(should disable PENIRQ before executing this command)
int tsc2007_read_ypos(void)
{
	unsigned char data[2];
	int count, value;
	
	data[0] = TSC2007_CMD(MEAS_YPOS, PD_PENIRQ_DISARM, M_12BIT);

	if (i2c_write(&data[0], 1) < 0)
		return 0;

	delay_ticks(100);
	
	if ((count = i2c_read(&data[0],2)) < 0)
		return 0;
		
	value = data[0];
	value <<= 4;
	value += (data[1] >> 4);
		
	return value;
}

//get pressure value(should disable PENIRQ before executing this command)
int tsc2007_read_zpos(void)
{
	unsigned char data[2];
	int count, value;
	
	data[0] = TSC2007_CMD(MEAS_Z1POS, PD_PENIRQ_DISARM, M_12BIT);

	if (i2c_write(&data[0], 1) < 0)
		return 0;

	delay_ticks(100);
	
	if ((count = i2c_read(&data[0],2)) < 0)
		return 0;
		
	value = data[0];
	value <<= 4;
	value += (data[1] >> 4);
	
	return value;
}



INT  get_touch_data(INT *x_pos, INT *y_pos)
{
	int  z_pos;

	sysDisableInterrupt(IRQ_GROUP0); 	
	
	z_pos = tsc2007_read_xpos();

	delay_ticks(10);

	*x_pos = tsc2007_read_ypos();

	delay_ticks(10);

	*y_pos = tsc2007_read_zpos();

	delay_ticks(10);
	
	tsc2007_powerdown();

	delay_ticks(10);

	sysEnableInterrupt(IRQ_GROUP0); 

	if ((z_pos < 500) && (*x_pos > 800))
		return -1;
		
	//sysprintf("(%d %d %d)\n", *x_pos, *y_pos, z_pos);
	
	return 0;
}


INT  ts_location_test()
{
	INT   location[16][2] = { AXIS_X1, AXIS_Y1, AXIS_X2, AXIS_Y2, AXIS_X3, AXIS_Y3, AXIS_X4, AXIS_Y4 ,AXIS_X5,AXIS_Y5,AXIS_X6,AXIS_Y6,
							 AXIS_X7,AXIS_Y7, AXIS_X8,AXIS_Y8, AXIS_X9,AXIS_Y9, AXIS_X10,AXIS_Y10,AXIS_X11, AXIS_Y11, AXIS_X12, AXIS_Y12, AXIS_X13, AXIS_Y13, AXIS_X14, AXIS_Y14 ,AXIS_X15,AXIS_Y15,AXIS_X16,AXIS_Y16};
	INT   loc_idx;
	INT   x=0,i,j=0,k=0;
	INT   x_pos, y_pos;
	INT   t0;
	int	  n=0;
	char  num1[4]={0,0,0,0};  //第一个操作数数组(最高支持4位)
	char  num2[4]={0,0,0,0};  //第二个操作数数组(最高支持4位)
	int   num3,num4,num5;     //操作数转化int(最高支持4位)
	int   flag=0;             //切换操作数数组标志
	
	
#if defined(NUC951)
	sysprintf("H/W Setting for touch screen test: Switch13 OFF. Switch14 ON\n");
#endif	
	
	
    	sysprintf("Please touch the %dst target on touch panel.\n", loc_idx+1);
    	sysprintf("If this test can not detect a touch inside the target in 60 seconds, the test failed.\n");
		sysprintf("\n\n\n");
		
		set_target(location[0][0],location[0][1]);
		set_target(location[1][0],location[1][1]);
		set_target(location[2][0],location[2][1]);
		set_target(location[3][0],location[3][1]);
		set_target(location[4][0],location[4][1]);
		set_target(location[5][0],location[5][1]);
		set_target(location[6][0],location[6][1]);
		set_target(location[7][0],location[7][1]);
		set_target(location[8][0],location[8][1]);
		set_target(location[9][0],location[9][1]);
		set_target(location[10][0],location[10][1]);
		set_target(location[11][0],location[11][1]);
		set_target(location[12][0],location[12][1]);
		set_target(location[13][0],location[13][1]);
		set_target(location[14][0],location[14][1]);
		set_target(location[15][0],location[15][1]);
		
		t0 = sysGetTicks(TIMER0);
		while (1)
		{
			sysEnableInterrupt(IRQ_GROUP0);
			
			
				if (get_touch_data(&x_pos, &y_pos) == 0)
				{
					if (x_pos < 400)  x_pos = 400;
					if (y_pos < 600)  y_pos = 600;
					
					x_pos = ((x_pos - 400) * 320) / (3700 - 400);
					y_pos = ((y_pos - 600) * 240) / (3600 - 600);
    			for (loc_idx = 0; loc_idx < 16; loc_idx++){
    				if ((x_pos <= (location[loc_idx][0] + 20)) && 
    					(x_pos >= (location[loc_idx][0] - 20)) && 
    					(y_pos <= (location[loc_idx][1] + 20)) &&
    					(y_pos >= (location[loc_idx][1] - 20)))
    				{
    					if(loc_idx<10){
    					lcdprintf("%d ",loc_idx);
    					  if(flag==0)
    					  {
    						num1[j]=loc_idx+'0';
    						j++;
    					  }else{
    					    num2[x]=loc_idx+'0';
    					    x++;
    					  }
    					}
    					if(loc_idx==10){   //加法运算
    					lcdprintf("+ ");
    					n=loc_idx;
    					flag=1;
    					}
    					if(loc_idx==11){  //减法运算
    					lcdprintf("- ");
    					n=loc_idx;
    					flag=1;
    					}
    					if(loc_idx==12){  //乘法运算
    					lcdprintf("* ");
    					n=loc_idx;
    					flag=1;
    					}
    					if(loc_idx==13){  //除法运算
    					lcdprintf("/ ");
    					n=loc_idx;
    					flag=1;
    					}
    					if(loc_idx==14){
    					lcdprintf("= ");
    						num3=atoi(num1);  //char数组截断转化为int
    					    num4=atoi(num2);
    						switch (n)
    						{
    						case 10:
    							lcdprintf("%d ",(num3+num4));
    							break;
    						case 11:
    							lcdprintf("%d ",(num3-num4));
    							break;
    						case 12:
    							lcdprintf("%d ",(num3*num4));
    							
    							break;
    						case 13:
    							lcdprintf("%d ",(num3/num4));
    							
    							break;
    						}
    						x=0;
    						j=0;
    						flag=0;
    					}
    					if(loc_idx==15){   //清除操作
    					for (i = 0;  i<= 39; i++)
   						 {
   						 	lcdputchar(i,0," ");
   						 	lcdputchar(i,1," ");
   						 }
   						 n=0;
   						 for(k=0;k<4;k++)
   						 {
   						 num1[k]='\0';
   						 num2[k]='\0';
   						 }
   						 setXY(0,0);
    					}
    					
    				}	
    				
    				}
    			}
    		}
			
			
	
	sysprintf("\n\nAll target test OK.\n\n");
	return 0;
}


INT  line_draw_test(VOID)
{
	INT   x_pos, y_pos, X, Y;
	INT   t0;
	
	reset_screen();

   	sysprintf("Free to draw on the touch panel ...\n");
   	sysprintf("This test will exit after 60 seconds.\n");
   	
	t0 = sysGetTicks(TIMER0);
   	while (1)
   	{
		sysEnableInterrupt(IRQ_GROUP0);
			
		if (_Touch_Event == 1)
		{
			if (get_touch_data(&x_pos, &y_pos) == 0)
			{
				if (x_pos < 500)  x_pos = 500;
				if (y_pos < 600)  y_pos = 600;
					
				x_pos = ((x_pos - 500) * 320) / (3600 - 500);
				y_pos = ((y_pos - 600) * 240) / (3600 - 600);
				
				if (x_pos < 2) x_pos = 2;
				if (x_pos > 317) x_pos = 317; 
				if (y_pos < 2) y_pos = 2;
				if (y_pos > 237) y_pos = 237;

    			for (X = (x_pos - 2); X < (x_pos + 2); X++)
    			{
       				for (Y = (y_pos - 2); Y < (y_pos + 2); Y++)
       				{
           				*(short*)(LCD_BUFF_BASE+(Y*320+X)*2) = (short)0xFFFF;
       				}
    			}
				
    			
    			_Touch_Event = 0;
    		}
    	}

		if (sysGetTicks(TIMER0) - t0 > 6000)
		{
			break;;
		}
   	}
   	
   	reset_screen();
   	return 0;
}


