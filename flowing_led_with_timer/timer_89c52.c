#include "timer_89c52.h"

void timer_0_init() { // 1ms @ 11.0592MHz 12T
    // set TMOD
    TMOD &= 0xF0; // reset timer 1
    TMOD |= 0x01; // set timer mode for timer 1

    // set initial timer value
    TL1 = 0x66;
    TH1 = 0xFC;

    // set TCON bit by bit
    TF0 = 0;
    TR0 = 1; // Enable timer 1

    // set interrupt
    ET0 = 1;
    EA = 1;
    PT0 = 0; // priority
}

void timer_1_init() { // 1ms @ 11.0592MHz 12T
    // set TMOD
    TMOD &= 0x0F; // reset timer 1
    TMOD |= 0x10; // set timer mode for timer 1

    // set initial timer value
    TL1 = 0x66;
    TH1 = 0xFC;

    // set TCON bit by bit
    TF1 = 0;
    TR1 = 1; // Enable timer 1

    // set interrupt
    ET1 = 1;
    EA = 1;
    PT1 = 0; // priority
}