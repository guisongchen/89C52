#include "key_separate.h"

uchar getKeySeperateNum() {
    uchar keyNum = 0;
    if (P3_0 == 0) {
        DelayMS(20);
        while(P3_0);
        DelayMS(20);
        keyNum = 1;
    }
    if (P3_2 == 0) {
        DelayMS(20);
        while(P3_0);
        DelayMS(20);
        keyNum = 2;
    }
    if (P3_2 == 0) {
        DelayMS(20);
        while(P3_0);
        DelayMS(20);
        keyNum = 3;
    }
    if (P3_3 == 0) {
        DelayMS(20);
        while(P3_0);
        DelayMS(20);
        keyNum = 4;
    }

    return keyNum;
}