#ifndef CCC_ONE_WIRE_H
#define CCC_ONE_WIRE_H

#include "common_header.h"

uchar OneWire_init();
void OneWire_sendBit(uchar b);
uchar OneWire_receiveBit();
void OneWire_sendByte(uchar byte);
uchar OneWire_receiveByte();

#endif // CCC_ONE_WIRE_H