#include "Infrared.h"

enum IR_STATE IR_state;
uint IR_counter;
uchar IR_repeatFlag;
uchar IR_dataFlag;

uchar IR_raw_data[4];
uchar IR_data_index;

uchar IR_address;
uchar IR_command;

void IR_init() {
    // init counter and outside interrupt
    timer_0_counter_init();
    INT0_init();
    IR_state = AVALIABLE;
    IR_counter = 0;
    IR_repeatFlag = 0;
    IR_dataFlag = 0;
    IR_data_index = 0;
    IR_raw_data[0] = 0;  // address
    IR_raw_data[1] = 0;  // ~address
    IR_raw_data[2] = 0;  // command
    IR_raw_data[3] = 0;  // ~command 
    IR_address = 0;
    IR_command = 0;
}

void INT0_routine() interrupt 0 {
    switch (IR_state)
    {
    case AVALIABLE:
        timer_0_set_counter(0);
        timer_0_counter_run(1);
        IR_state = WAIT;
        break;
    case WAIT:
        IR_counter = timer_0_get_counter();
        timer_0_set_counter(0);
        if (IR_counter > 12442-TIME_WINDOW && IR_counter < 12442+TIME_WINDOW) { // start
            IR_state = RECEIVE;
        } else if (IR_counter > 10368-TIME_WINDOW && IR_counter < 10368+TIME_WINDOW) { // repeat
            IR_repeatFlag = 1;
            timer_0_set_counter(0);
            IR_state = AVALIABLE;
        } else {
            IR_state = WAIT;
        }
        break;
    case RECEIVE:
        IR_counter = timer_0_get_counter();
        timer_0_set_counter(0);

        if (IR_counter > 1032-TIME_WINDOW && IR_counter < 1032+TIME_WINDOW) {
            // receive 0
            IR_raw_data[IR_data_index/8] &= ~(0x01 << (IR_data_index%8));
            IR_data_index++;
        } else if (IR_counter > 2074-TIME_WINDOW && IR_counter < 2074+TIME_WINDOW) {
            // receive 1
            IR_raw_data[IR_data_index/8] |= (0x01 << (IR_data_index%8));
            IR_data_index++;
        } else {
            IR_state = WAIT;
            IR_data_index = 0; // drop and restart
        }

        if (IR_data_index == 32) {
            IR_data_index = 0;

            // check raw data
            if (IR_raw_data[0]== ~IR_raw_data[1] && IR_raw_data[2]== ~IR_raw_data[3]) {
                IR_address = IR_raw_data[0];
                IR_command = IR_raw_data[2];
                IR_dataFlag = 1;
            }

            timer_0_set_counter(0);
            IR_state = AVALIABLE;
        }
        break;
    default:
        break;
    }
}

uchar IR_getRepeat() {
    if (IR_repeatFlag == 1) {
        IR_repeatFlag = 0;
        P1_0 = 0;
        return 1;
    } else {
        return 0;
    }
}

uchar IR_getData() {
    if (IR_dataFlag == 1) {
        IR_dataFlag = 0;
        return 1;
    } else {
        return 0;
    }
}

uchar IR_getAddress() {
    return IR_address;
}

uchar IR_getCommand() {
    return IR_command;
}