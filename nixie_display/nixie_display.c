#include <REGX52.H>
#include <INTRINS.H>

#define uint unsigned int
#define uchar unsigned char

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

void Delay(uint cnt)		//@11.0592MHz
{
	unsigned char i, j;
    while (cnt--) {
        _nop_();
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
    posEnable = 1;
    P0 = ~(0x01 << pos);
    posEnable = 0;

    segEnable = 1;
    P0 = ledNum[num];
    segEnable = 0;   

    Delay(1); // this important, to display stable
}

void main() {
    // lightNixie(2,3);
    // uchar i = 0;
    while (1) {
        lightNixie(5, 1);
        Delay(200);
        lightNixie(6, 2);
        Delay(200);
    }
}