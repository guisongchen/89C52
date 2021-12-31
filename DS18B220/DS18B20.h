#ifndef CCC_DS18B20_H
#define CCC_DS18B20_H

#include "one_wire.h"

#define DS18B20_SKIP_ROM			0xCC
#define DS18B20_CONVERT_T			0x44
#define DS18B20_READ_SCRATCHPAD 	0xBE

void DS18B20_convertT();
int DS18B20_ReadT();

#endif // CCC_DS18B20_H