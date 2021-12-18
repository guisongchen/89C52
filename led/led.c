#include <REG52.H>
#include <INTRINS.H>

#define uchar unsigned char
#define uint unsigned int

void delay(uint cnt) {
    uint i, j;
    for (i = cnt; i > 0; i--) {
        for (j = 120; j > 0; j--) {}
    }
}

void main() {
    uint i;
    uchar state = 0xfe;
    P1 = state;
    delay(500);
    while(1) {
        for (i = 0; i < 8; i++) {
            state = _crol_(state, 1);
            P1 = state;
            delay(500);
        }
    }
}