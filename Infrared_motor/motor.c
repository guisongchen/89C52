#include "motor.h"

sbit Motor_On = P1^0;

uchar counter, compare;

void motor_init() {
    timer_1_100us_init();
}

void motor_setSpeed(uchar speed) {
    compare = speed;
}

void timer_1_routine() interrupt 3 {
    // reload
    TL1 = 0xA4;
    TH1 = 0xFF;

    // pwm
    counter++;
    counter %= 100;
    if (counter < compare) {
        Motor_On = 0; // on
    } else {
        Motor_On = 1; // off
    }
}