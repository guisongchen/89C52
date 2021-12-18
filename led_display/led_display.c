#include <REGX52.H>

#define uchar unsigned char
#define uint unsigned int

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

void main() {
    uchar ledNum = 0;
    while (1) {
        if (P3_0 == 0) {
            Delay(20);
            while (P3_0 == 0);
            Delay(20);

            ledNum++;
            if (ledNum == 8)
                ledNum = 0;
            P1 = ~(0x01 << ledNum);
        }
        
        if (P3_1 == 0) {
            Delay(20);
            while (P3_1 == 0);
            Delay(20);

            if (ledNum == 0) {
                ledNum = 7;
            } else {
                ledNum--;
            }
            P1 = ~(0x01 << ledNum);
        }


    }
}