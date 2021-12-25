#include "key_matrix.h"

uchar checkKeyMatrixRow() {
    uchar row = 0;
    if (P3_0 == 0) {
        DelayMS(20); // unbounce and stabilize
        while (P3_0 == 0);
        DelayMS(20); // unbounce and stabilize
        row = 1;
    } else if (P3_1 == 0) {
        DelayMS(20); // unbounce and stabilize
        while (P3_1 == 0);
        DelayMS(20); // unbounce and stabilize
        row = 2;
    } else if (P3_2 == 0) {
        DelayMS(20); // unbounce and stabilize
        while (P3_2 == 0);
        DelayMS(20); // unbounce and stabilize
        row = 3;
    } else if (P3_3 == 0) {
        DelayMS(20); // unbounce and stabilize
        while (P3_3 == 0);
        DelayMS(20); // unbounce and stabilize
        row = 4;
    }

    return row;
}

uchar getKeyNum() {
    uchar keyNum = 0;
    uchar col = 0;
    uchar row = 0;

    // do column scan
    P3 = 0xFF; // clo and row all set 1
    P3_4 = 0;
    if (P3 != 0xEF) {
        col = 1;
        row = checkKeyMatrixRow();
        keyNum = (row-1) * 4 + col;
    }

    P3 = 0xFF; // clo and row all set 1
    P3_5 = 0;
    if (P3 != 0xDF) {
        col = 2;
        row = checkKeyMatrixRow();
        keyNum = (row-1) * 4 + col;
    }

    P3 = 0xFF; // clo and row all set 1
    P3_6 = 0;
    if (P3 != 0xBF) {
        col = 3;
        row = checkKeyMatrixRow();
        keyNum = (row-1) * 4 + col;
    }

    P3 = 0xFF; // clo and row all set 1
    P3_7 = 0;
    if (P3 != 0x7F) {
        col = 4;
        row = checkKeyMatrixRow();
        keyNum = (row-1) * 4 + col;
    }

    return keyNum;
}