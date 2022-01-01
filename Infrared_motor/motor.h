#ifndef CCC_MOTOR_H
#define CCC_MOTOR_H

#include "common_header.h"
#include "timer_89c52.h"

void motor_init();
void motor_setSpeed(uchar speed);

#endif // CCC_MOTOR_H