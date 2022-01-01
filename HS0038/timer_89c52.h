#ifndef CCC_TIMER_89C52_H
#define CCC_TIMER_89C52_H

#include "common_header.h"

void timer_0_init();
void timer_0_counter_init();
void timer_0_set_counter(uint cnt);
uint timer_0_get_counter();
void timer_0_counter_run(uchar flag);

void timer_1_init();

#endif // CCC_TIMER_89C52_H