#include "timer_89c52.h"

void timer_0_init() { // 1ms @ 11.0592MHz 12T
    // set TMOD
    TMOD &= 0xF0; // reset timer 0
    TMOD |= 0x01; // set timer mode for timer 0

    // set initial timer value
    TL0 = 0x66;
    TH0 = 0xFC;

    // set TCON bit by bit
    TF0 = 0;
    TR0 = 1; // Enable timer 0

    // set interrupt
    ET0 = 1;
    EA = 1;
    PT0 = 0; // priority
}

void timer_0_counter_init() { // 1ms @ 11.0592MHz 12T
    // set TMOD
    TMOD &= 0xF0; // reset timer 0
    TMOD |= 0x01; // use timer mode!!

    // set initial timer value
    TL0 = 0x00;
    TH0 = 0x00;

    // set TCON bit by bit
    TF0 = 0;
    TR0 = 0; // init as disable
}

void timer_0_set_counter(uint cnt) {
    TH0 = cnt / 256;
    TL0 = cnt % 256;
}

uint timer_0_get_counter() {
    return (TH0 << 8) | TL0;
}

void timer_0_counter_run(uchar flag) {
    TR0 = flag;
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

void timer_1_100us_init() { // 100us @ 11.0592MHz 12T
    // set TMOD
    TMOD &= 0x0F; // reset timer 1
    TMOD |= 0x10; // set timer mode for timer 1

    // set initial timer value
    TL1 = 0xA4;
    TH1 = 0xFF;

    // set TCON bit by bit
    TF1 = 0;
    TR1 = 1; // Enable timer 1

    // set interrupt
    ET1 = 1;
    EA = 1;
    PT1 = 0; // priority
}