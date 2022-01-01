#include "INT0.h"
#include "key_separate.h"
#include "nixie.h"
#include "Infrared.h"

uchar num;
uchar command;
uchar address;

void main() {
    uchar i;
    uchar hundred, ten, unit;
    
    num = 0;
    command = 0;
    address = 0;

    IR_init();
    while (1) {
        if (IR_getData() || IR_getRepeat()) { // data exist
            address = IR_getAddress();
            command = IR_getCommand();

            if (command == IR_VOL_MINUS) {
                num--;
            }

            if (command == IR_VOL_ADD) {
                num++;
            }

            hundred = num / 100;
            ten = (num - hundred*100)/10;
            unit = num % 10;
        }

        lightNixie(1, (address >> 4));
        lightNixie(2, (address & 0x0F));
        lightNixie(3, (command >> 4));
        lightNixie(4, (command & 0x0F));
        lightNixie(5, hundred);
        lightNixie(6, ten);
        lightNixie(7, unit);

    }
}