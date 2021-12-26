#ifndef CCC_DS1302_H
#define CCC_DS1302_H
#include "common_header.h"

#define DS1302_SECOND_WRITE		0x80
#define DS1302_MINUTE_WRITE		0x82
#define DS1302_HOUR_WRITE		0x84
#define DS1302_DAY_WRITE		0x86
#define DS1302_MONTH_WRITE		0x88
#define DS1302_WEEKDAY_WRITE	0x8A
#define DS1302_YEAR_WRITE		0x8C

#define DS1302_SECOND_READ		0x81
#define DS1302_MINUTE_READ	    0x83
#define DS1302_HOUR_READ	    0x85
#define DS1302_DAY_READ	        0x87
#define DS1302_MONTH_READ	    0x89
#define DS1302_WEEKDAY_READ	    0x8B
#define DS1302_YEAR_READ	    0x8D

#define DS1302_WP			    0x8E

void DS1302_init();
void DS1302_writeByte(uchar command, uchar byte);
uchar DS1302_readByte(uchar command);
void DS1302_setTime(uchar hour, uchar minute, uchar second, uchar weekday);

#endif // CCC_DS1302_H