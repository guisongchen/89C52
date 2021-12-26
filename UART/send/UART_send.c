#include "UART_send.h"

void UART_send_init() { //9600bps@11.0592MHz
    SCON = 0x50;
    PCON &= 0x7F;

    // set timer 1 (UART use timer 1)
    TMOD &= 0x0F; // choose timer 1
    TMOD |= 0x20; // 8 bit automatic reload

    // set initial value of timer 1
    TL1 = 0xFD;
    TH1 = 0xFD;

    ET1 = 0; // disable timer 1 interrupt
    TR1 = 1; // start timer 1
		
	EA = 1; // CPU interrupt on
	ES = 1; // serial port interrupt on
}

void UART_sendByte(uchar byte) {
    SBUF = byte;
    while (TI == 0); // check flag
    TI = 0; // software reset
}