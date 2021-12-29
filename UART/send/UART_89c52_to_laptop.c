#include "UART_receive.h"

void main(){
    static uint cnt = 3;
    UART_receive_init();
    while(1) {
        UART_sendByte(cnt++);
        DelayMS(1000);
    }
}