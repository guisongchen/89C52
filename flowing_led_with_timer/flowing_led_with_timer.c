#include "timer_89c52.h"
#include "key_separate.h"

uchar led_mode;

void main(){
    uchar keyNum = 0;
    led_mode = 0;
    P1 = 0xFE;
    timer_1_init();
    while(1) {
        keyNum = getKeySeperateNum();
        if (keyNum != 0) {
            if (keyNum == 1) {
                led_mode++;
                led_mode %= 2;
            }
        }
    }
}

// timer 0 and 1 max timer range is 65ms, not enough
// so set timer 1 ms, repeat 1000 times

void timer_0_routine() interrupt 1 {
    static uint t0_count = 0; // static to save status
    // reload init timer
    TL0 = 0x66;
    TH0 = 0xFC;
    t0_count++;
    if (t0_count == 1000) {
        t0_count = 0;
        if (led_mode == 0)
            P1 = _crol_(P1, 1);
        if (led_mode == 1)
            P1 = _cror_(P1, 1);
    }
}

void timer_1_routine() interrupt 3 {
    static uint t1_count; // static to save status
    // reload init timer
    TL1 = 0x66;
    TH1 = 0xFC;
    t1_count++;
    if (t1_count == 1000) {
        t1_count = 0;
        if (led_mode == 0)
            P1 = _crol_(P1, 2);
        if (led_mode == 1)
            P1 = _cror_(P1, 2);
    }
}