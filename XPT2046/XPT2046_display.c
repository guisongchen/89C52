#include "XPT2046.h"
#include "UART_send.h"

void main() {
    uint digit = 0x0030;
    UART_send_init();
    while (1) {
        digit = XPT2046_readAD(XPT2046_VBAT_8);
        UART_sendByte((uchar)digit);
        DelayMS(1000);
    }
}