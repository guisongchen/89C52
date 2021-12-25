#include "key_matrix.h"
#include "nixie.h"

void main() {
    uchar keyNum = 0;
    uchar availableNum = 0;
    while (1) {
        keyNum = getKeyNum();
        if (keyNum != 0) { // make sure availableNum not be overwriten
            availableNum = keyNum;
        }
        lightNixie(1, availableNum / 10);
        lightNixie(2, availableNum % 10);
    }
}