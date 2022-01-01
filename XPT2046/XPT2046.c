#include "XPT2046.h"

uint XPT2046_readAD(uchar command) {
    uchar i;
    uint digit = 0x0000;

    XPT2046_CS = 0;
    XPT2046_DCLK = 0;
    for (i = 0; i < 8; i++) {
        XPT2046_DIN = command & (0x80 >> i);
        XPT2046_DCLK = 1;
        XPT2046_DCLK = 0;
    }

    for (i = 0; i < 16; i++) {
        XPT2046_DCLK = 1;
        XPT2046_DCLK = 0;
        if (XPT2046_DOUT) {
            digit |= (0x8000 >> i);
        }
    }

    XPT2046_DCLK = 0;
    XPT2046_CS = 1;

    return digit >> 8; // 8 bit mode
}