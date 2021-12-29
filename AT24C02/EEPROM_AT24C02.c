#include "AT24C02.h"
#include "UART_send.h"

uchar byte;

void main() {
    AT24C02_writeByte(1, 0x56);
    DelayMS(5);
    byte = AT24C02_readByte(1);
    UART_send_init();

    while(1) {
        UART_sendByte(byte);
        DelayMS(1000);
    }
}