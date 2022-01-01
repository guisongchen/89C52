#include "INT0.h"

void INT0_init() {
    // set IE, enable interrupt
    EA = 1;
    EX0 = 1;

    // set interrupt periority
    PX0 = 1; // high

    // set TCON
    IT0 = 1; // 1: falling edge  0: low voltage
}