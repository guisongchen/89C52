#include "one_wire.h"

sbit OneWire_DQ = P2^2;

uchar OneWire_init() {
    uchar i;
    uchar ack;

    // BUS pulling low
    OneWire_DQ = 1;
    OneWire_DQ = 0;
    // delay 500us
    i = 230;
    while (--i);

    // BUS pullup
    OneWire_DQ = 1;
    // delay 70us
    i = 32;
    while (--i);

    // read BUS
    ack = OneWire_DQ;

    // wait 500us while receving from slave machine
    i = 230;
    while (--i);    

    return ack;
}

void OneWire_sendBit(uchar b) {
    uchar i;

    // BUS pulling low
    OneWire_DQ = 0;

    // delay 10us
    i = 4;
    while (--i);

    // write to BUS
    OneWire_DQ = b;

    // delay 50us
    i = 22;
    while (--i);

    // BUS pullup
    OneWire_DQ = 1;
}

uchar OneWire_receiveBit() {
    uchar i;
    uchar b;

    // BUS pulling low
    OneWire_DQ = 0;

    // delay 5us
    i = 2;
    while (--i);

    // the maste must release the bus and then sample the bus state
    OneWire_DQ = 1;

     // delay 5us
    i = 2;
    while (--i);   

    // read bus
    b = OneWire_DQ;

    // delay 50us
    i = 22;
    while (--i);

    // BUS pullup
    OneWire_DQ = 1;

    return b;
}

void OneWire_sendByte(uchar byte) {
    uchar i;
    for (i = 0; i < 8; i++) {
        OneWire_sendBit(byte & (0x01 << i));
    }
}

uchar OneWire_receiveByte() {
    uchar i;
    uchar byte = 0x00;
    for (i = 0; i < 8; i++) {
        if (OneWire_receiveBit()) {
            byte |= (0x01 << i);
        }
    }

    return byte;
}