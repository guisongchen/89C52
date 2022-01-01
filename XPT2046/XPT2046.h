#ifndef CCC_XPT2046_H
#define CCC_XPT2046_H

#include "common_header.h"

#define XPT2046_VBAT_8	    0xAC // resistance
#define XPT2046_AUX_8		0xEC
#define XPT2046_XP_8		0x9C // photosensitive
#define XPT2046_YP_8		0xDC // thermal

sbit XPT2046_DIN=P2^0;
sbit XPT2046_CS=P3^7;
sbit XPT2046_DCLK=P2^1;
sbit XPT2046_DOUT=P2^5;

uint XPT2046_readAD(uchar command);

#endif // CCC_XPT2046_H