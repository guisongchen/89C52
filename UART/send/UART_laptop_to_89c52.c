#include "UART_send.h"

void main(){
    UART_send_init();
    while(1) {
    }
}

void UART_routine() interrupt 4 {
    if (RI == 1) { // send done
        P1 = ~SBUF;
        UART_sendByte(SBUF);
        RI = 0; // software reset
    }
}