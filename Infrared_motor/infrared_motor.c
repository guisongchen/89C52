#include "motor.h"
#include "key_separate.h"
#include "nixie.h"
#include "Infrared.h"

// void main(){
//     uchar key = 0;
//     motor_init();
//     while (1) {
//         key = getKeySeperateNum();
//         if (key != 0) {
//             switch (key)
//             {
//             case 1:
//                 motor_setSpeed(0);
//                 break;
//             case 2:
//                 motor_setSpeed(50);
//                 break;            
//             case 3:
//                 motor_setSpeed(75);
//                 break;
//             case 4:
//                 motor_setSpeed(100);
//                 break;        
//             default:
//                 break;
//             }
//             lightNixie(1, key);
//         }
//     }

// }

void main(){
    uchar key = 0;
    motor_init();
    IR_init();
    while (1) {
        if (IR_getData()) {
            key = IR_getCommand();
            switch (key)
            {
            case IR_0:
                motor_setSpeed(0);
                lightNixie(1, 0);
                break;
            case IR_1:
                motor_setSpeed(30);
                lightNixie(1, 1);
                break;            
            case IR_2:
                motor_setSpeed(60);
                lightNixie(1, 2);
                break;
            case IR_3:
                motor_setSpeed(100);
                lightNixie(1, 3);
                break;        
            default:
                break;
            }
        }
    }

}