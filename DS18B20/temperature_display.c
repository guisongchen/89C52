#include "DS18B20.h"
#include "UART_send.h"

void main(){
    int t = 0x78;
    UART_send_init();
    while (1) {
        DS18B20_convertT();
        t = DS18B20_ReadT();
        UART_sendByte(t);
        DelayMS(1000);
    }
}