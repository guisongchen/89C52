#include "ds1302.h"

// using jump wire connect j5 and P1_0 ~ P1_2
sbit DS1302_SCLK = P1^0; // use P1_0 may fail
sbit DS1302_IO = P1^1;
sbit DS1302_RST = P1^2;

void DS1302_init() {
    DS1302_RST = 0;
    DS1302_SCLK = 0;
}

 void DS1302_writeByte(uchar command, uchar byte) {
     uchar i = 0;
     DS1302_RST = 1; // enable
     for (i = 0; i < 8; i++) {
         DS1302_IO = command & (0x01 << i);
         DS1302_SCLK = 1; // clock up
         DS1302_SCLK = 0; // clock reset
     }

     for (i = 0; i < 8; i++) {
         DS1302_IO = byte & (0x01 << i);

         // write at rising edge
         DS1302_SCLK = 1; // clock up
         DS1302_SCLK = 0; // clock reset
     }

     DS1302_RST = 0; // disable
 }

 uchar DS1302_readByte(uchar command) {
     uchar i = 0;
     uchar byte = 0x00; // init 0 so only needs to set 1 according to IO

     DS1302_RST = 1; // enable
     for (i = 0; i < 8; i++) {
         DS1302_IO = command & (0x01 << i);

         // notice: reverse order to align with time squence
         // read mode: first write 8 bit command, then read 8 bit data
         // at the end of write and the begin of read
         // available signal: rising edge --> falling edge 
         DS1302_SCLK = 0;
         DS1302_SCLK = 1;
     }

     for (i = 0; i < 8; i++) {
         DS1302_SCLK = 1; // clock up
         DS1302_SCLK = 0; // clock reset
         if (DS1302_IO) {
             byte |= (0x01 << i);
         }
     }

     DS1302_RST = 0; // disable
     DS1302_IO = 0; // reset 0 otherwise read byte may be wrong
     return byte;
 }

 void DS1302_setTime(uchar hour, uchar minute, uchar second, uchar weekday) {
 	DS1302_writeByte(DS1302_WP,0x00); // turn off write protection
    
    DS1302_writeByte(DS1302_HOUR_WRITE, DecimalToBSD(hour));
    DS1302_writeByte(DS1302_MINUTE_WRITE, DecimalToBSD(minute));
    DS1302_writeByte(DS1302_SECOND_WRITE, DecimalToBSD(second));
    DS1302_writeByte(DS1302_WEEKDAY_WRITE, DecimalToBSD(weekday));

	DS1302_writeByte(DS1302_WP,0x80);    
 }