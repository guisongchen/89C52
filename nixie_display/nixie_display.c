#include <REGX52.H>

#define uint unsigned int
#define uchar unsigned char

sbit posEnable = 0xA7;
sbit segEnable = 0xA6;

uchar code ledNum[]={ 
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

void Delay(uint cnt)		//@11.0592MHz
{
	unsigned char i, j;

    while (cnt--) {
        i = 2;
        j = 199;
        do
        {
            while (--j);
        } while (--i);
    }
}

void lightNixie(uchar pos, uchar num) {
    // choose which nixie should be light

    // pos:1->8  idx:0->7 
    pos = (pos-1) % 8; 
    // unsigned char mask = 0x01 << pos;
    posEnable = 1;
    P0 = ~(0x01 << pos);
    posEnable = 0;

    segEnable = 1;
    P0 = ledNum[num];
    segEnable = 0;

    Delay(1);
}

void main() {
    while (1) {
        lightNixie(1,2);
    }
}