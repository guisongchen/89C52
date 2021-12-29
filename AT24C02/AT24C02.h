#ifndef CCC_AT24C02_H
#define CCC_AT24C02_H

#include "IIC.h"

#define AT24C02_ADDR_WRITE 0xA0
#define AT24C02_ADDR_READ 0xA1

void AT24C02_writeByte(uchar wordAddr, uchar byte);
uchar AT24C02_readByte(uchar wordAddr);

#endif // CCC_AT24C02_H