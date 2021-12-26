#include "common_header.h"

void DelayMS(uint cnt)		//@11.0592MHz
{
	unsigned char i, j;
    while (cnt--) {
        _nop_();
        i = 2;
        j = 199;
        do
        {
            while (--j);
        } while (--i);
    }
}