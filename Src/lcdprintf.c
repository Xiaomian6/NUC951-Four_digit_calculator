/***************************************************************************
 *                                                                         *
 * Copyright (c) 2008 Nuvoton Technolog. All rights reserved.              *
 *                                                                         *
 ***************************************************************************/
 
/****************************************************************************
* FILENAME
*   wb_uart.c
*
* VERSION
*   1.0
*
* DESCRIPTION
*   The UART related function of Nuvoton ARM9 MCU
*
* HISTORY
*   2008-06-25  Ver 1.0 draft by Min-Nan Cheng
*
* REMARK
*   None
 **************************************************************************/
#include <string.h>
#include <stdio.h>
#include "wblib.h"

#include "NUC900_vpost.h"
#include "NUC900_reg.h"

const UINT8 ascii_dz8x16[]={
	#include "ascii_dz2.txt"
};

const char bitmasks[8]={
	0x80,0x40,0x20,0x10,0x8,0x4,0x2,0x1
};

#define RGB_BLACK 0
#define RGB_WHITE 0xff00

#define MODE_WIDTH 40  //40*8=320
#define MODE_HEIGHT 15    //15*16=240;
#define CHAR_NUMPX 8
#define CHAR_NUMPY 16
#define CHAR_FIRST 0x20

/* How many lines to scroll by */
#define SCROLL_LINES 1

/* Hacky global state */
static volatile unsigned short *base_ptr = NULL;
static int cursor_x = 0;
static int cursor_y = 0;
static int lcd_c2pixel(int pos_x,int pos_y,char c);
static int text_lcd_putchar(int c);
static void text_lcd_init(void);

#define vaStart(list, param) list = (INT8*)((INT)&param + sizeof(param))
#define vaArg(list, type) ((type *)(list += sizeof(type)))[-1]

/* Global variables */
BOOL volatile _sys_bLCDInitial = FALSE;

static void
scroll(void)
{
    /* number of chars we are dropping when we do the scroll */
    int clear_chars = SCROLL_LINES * MODE_WIDTH;
    /* number of chars we need to move to perform the scroll. This all the lines
     * minus however many we drop */
    int scroll_chars = MODE_WIDTH * MODE_HEIGHT - clear_chars;
    /* copy the lines up. we skip the same number of characters that we will clear, and move the
     * rest to the top. cannot use memcpy as the regions almost certainly overlap */
    memmove((void*)base_ptr, (void*)&base_ptr[clear_chars*CHAR_NUMPY*CHAR_NUMPX], scroll_chars *CHAR_NUMPY*CHAR_NUMPX* sizeof(*base_ptr));
    /* now zero out the bottom lines that we got rid of */
    memset((void*)&base_ptr[scroll_chars*CHAR_NUMPY*CHAR_NUMPX], 0, clear_chars *CHAR_NUMPY*CHAR_NUMPX* sizeof(*base_ptr));
    /* move the virtual cursor up */
    cursor_y -= SCROLL_LINES;
}
static void 
text_lcd_init()
{
	LCDFORMATEX lcdformatex;
	lcdformatex.ucVASrcFormat = VA_SRC_RGB565;
    vpostLCMInit(&lcdformatex);
    base_ptr = (unsigned short *)vpostGetFrameBuffer(); 
   	//vpostClearVABuffer();
}
static int
text_lcd_putchar(int c)
{
    /* emulate various control characters */
    if (c == '\t') {
        text_lcd_putchar(' ');
        while (cursor_x % 4 != 0) {
            text_lcd_putchar(' ');
        }
    } else if (c == '\n') {
        cursor_y ++;
        /* assume a \r with a \n */
        cursor_x = 0;
    } else if (c == '\r') {
        cursor_x = 0;
    } else {
        /* 7<<8 constructs a nice neutral grey color. */
        //base_ptr[cursor_y * MODE_WIDTH + cursor_x] = ((char)c) | (7 << 8);
        lcd_c2pixel(cursor_x,cursor_y,c);
        cursor_x++;
    }
    if (cursor_x >= MODE_WIDTH) {
        cursor_x = 0;
        cursor_y++;
    }
    while (cursor_y >= MODE_HEIGHT) {
        scroll();
    }
    return 0;
}

void setXY(int a,int b){
cursor_x=a;
cursor_y=b;

}
static int lcd_c2pixel(int pos_x, int pos_y, char c)
{
	int step = CHAR_NUMPX*CHAR_NUMPY/8;
	//char dispmat[CHAR_NUMPY][CHAR_NUMPX];
	const unsigned char *dzdata;
	short val;
	int i,j,k,ind,n;
	
	dzdata = &ascii_dz8x16[(c-CHAR_FIRST)*step];
	for (k = 0;k<CHAR_NUMPY;k = k+8)
	{
		ind = (pos_y*MODE_WIDTH*CHAR_NUMPY+k*MODE_WIDTH+pos_x)*CHAR_NUMPX;
		ind = ind+8*MODE_WIDTH*CHAR_NUMPX-1; /*for the following first turn*/
		for (i = 0;i<CHAR_NUMPX;i++)
		{
			ind = ind-8*MODE_WIDTH*CHAR_NUMPX+1;
			for (j = k,n=0;j<k+8;j++,n++)
			{
				val = *dzdata&bitmasks[n]; 
				if(val)
				{
					//dispmat[j][i] = 'o';
					base_ptr[ind] = RGB_WHITE;
				}		
				else
				{
					//dispmat[j][i] = ' ';
					base_ptr[ind] = RGB_BLACK;
				}
				ind = ind+MODE_WIDTH*CHAR_NUMPX; 
			}
			dzdata++;	
		}
	}
	return 0;
}

#define _PutChar_f  text_lcd_putchar

static VOID sysPutString(INT8 *string)
{
    while (*string != '\0')
    {
        _PutChar_f(*string);
        string++;
    }
}


static VOID sysPutRepChar(INT8 c, INT count)
{
    while (count--)
        _PutChar_f(c);
}


static VOID sysPutStringReverse(INT8 *s, INT index)
{
    while ((index--) > 0)
        _PutChar_f(s[index]);
}


static VOID sysPutNumber(INT value, INT radix, INT width, INT8 fill)
{
    INT8    buffer[40];
    INT     bi = 0;
    UINT32  uvalue;
    UINT16  digit;
    UINT16  left = FALSE;
    UINT16  negative = FALSE;

    if (fill == 0)
        fill = ' ';

    if (width < 0)
    {
        width = -width;
        left = TRUE;
    }

    if (width < 0 || width > 80)
        width = 0;

    if (radix < 0)
    {
        radix = -radix;
        if (value < 0)
        {
            negative = TRUE;
            value = -value;
        }
    }

    uvalue = value;

    do
    {
        if (radix != 16)
        {
            digit = uvalue % radix;
            uvalue = uvalue / radix;
        }
        else
        {
            digit = uvalue & 0xf;
            uvalue = uvalue >> 4;
        }
        buffer[bi] = digit + ((digit <= 9) ? '0' : ('A' - 10));
        bi++;

        if (uvalue != 0)
        {
            if ((radix == 10)
                && ((bi == 3) || (bi == 7) || (bi == 11) | (bi == 15)))
            {
                buffer[bi++] = ',';
            }
        }
    }
    while (uvalue != 0);

    if (negative)
    {
        buffer[bi] = '-';
        bi += 1;
    }

    if (width <= bi)
        sysPutStringReverse(buffer, bi);
    else
    {
        width -= bi;
        if (!left)
            sysPutRepChar(fill, width);
        sysPutStringReverse(buffer, bi);
        if (left)
            sysPutRepChar(fill, width);
    }
}


static INT8 *FormatItem(INT8 *f, INT a)
{
    INT8   c;
    INT    fieldwidth = 0;
    INT    leftjust = FALSE;
    INT    radix = 0;
    INT8   fill = ' ';

    if (*f == '0')
        fill = '0';

    while ((c = *f++) != 0)
    {
        if (c >= '0' && c <= '9')
        {
            fieldwidth = (fieldwidth * 10) + (c - '0');
        }
        else
            switch (c)
            {
                case '\000':
                    return (--f);
                case '%':
                    _PutChar_f('%');
                    return (f);
                case '-':
                    leftjust = TRUE;
                    break;
                case 'c':
                    {
                        if (leftjust)
                            _PutChar_f(a & 0x7f);

                        if (fieldwidth > 0)
                            sysPutRepChar(fill, fieldwidth - 1);

                        if (!leftjust)
                            _PutChar_f(a & 0x7f);
                        return (f);
                    }
                case 's':
                    {
                        if (leftjust)
                            sysPutString((PINT8)a);

                        if (fieldwidth > strlen((PINT8)a))
                            sysPutRepChar(fill, fieldwidth - strlen((PINT8)a));

                        if (!leftjust)
                            sysPutString((PINT8)a);
                        return (f);
                    }
                case 'd':
                case 'i':
                    radix = -10;
                    break;
                case 'u':
                    radix = 10;
                    break;
                case 'x':
                    radix = 16;
                    break;
                case 'X':
                    radix = 16;
                    break;
                case 'o':
                    radix = 8;
                    break;
                default:
                    radix = 3;
                    break;      /* unknown switch! */
            }
        if (radix)
            break;
    }

    if (leftjust)
        fieldwidth = -fieldwidth;

    sysPutNumber(a, radix, fieldwidth, fill);

    return (f);
}

VOID lcdprintf(PINT8 pcStr,...)
{
    INT8  *argP;

    if (!_sys_bLCDInitial)
    {
    	text_lcd_init();
    }
    
    vaStart(argP, pcStr);       /* point at the end of the format string */
    while (*pcStr)
    {                       /* this works because args are all ints */
        if (*pcStr == '%')
            pcStr = FormatItem(pcStr + 1, vaArg(argP, INT));
        else
            _PutChar_f(*pcStr++);
    }
}

VOID lcdputchar(int pos_x,int pos_y,char c)
{
	lcd_c2pixel(pos_x,pos_y,c);
}
