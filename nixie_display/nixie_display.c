#include "nixie.h"

void main() {
    uchar i = 0;
    while (1) {
        for (i = 1; i <=8; i++) {
            lightNixie(i, i);
            // Delay(200);
        }
    }
}