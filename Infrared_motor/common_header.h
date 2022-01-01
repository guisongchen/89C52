#ifndef CCC_COMMON_HEADER_H
#define CCC_COMMON_HEADER_H

#include <REGX52.H>
#include <INTRINS.H>

#define uint unsigned int
#define uchar unsigned char

void DelayMS(uint cnt);		//@11.0592MHz
uchar BSDToDecimal(uchar num);
uchar DecimalToBSD(uchar num);

#endif // CCC_COMMON_HEADER_H