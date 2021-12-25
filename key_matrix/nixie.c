#include "nixie.h"

sbit posEnable = 0xA7;
sbit segEnable = 0xA6;

uchar ledNum[]={ 
                0x3F,  //"0"
                0x06,  //"1"
                0x5B,  //"2"
                0x4F,  //"3"
                0x66,  //"4"
                0x6D,  //"5"
                0x7D,  //"6"
                0x07,  //"7"
                0x7F,  //"8"
                0x6F,  //"9"
};


void lightNixie(uchar position, uchar num) {
    // set nixie at position 'position' display 'num'

    // position:1->8  idx:0->7 
    position = (position-1) % 8; 
    posEnable = 1;
    P0 = ~(0x01 << position);
    posEnable = 0;

    segEnable = 1;
    P0 = ledNum[num];
    segEnable = 0;   

    DelayMS(1); // this important, to display stable
    P0 = 0xFF; // clear all position-bit to remove shadow
} 