#include "ds1302.h"
#include "nixie.h"

void main(){
    static uchar temp = 0;
    DS1302_init();
    DS1302_setTime(23, 59, 10, 7); // 23:59:10 SUNDAY
    while (1) {
        temp = BSDToDecimal(DS1302_readByte(DS1302_HOUR_READ));
        lightNixie(1, temp/10);
        lightNixie(2, temp%10);

        temp = BSDToDecimal(DS1302_readByte(DS1302_MINUTE_READ));
        lightNixie(3, temp/10);
        lightNixie(4, temp%10);

        temp = BSDToDecimal(DS1302_readByte(DS1302_SECOND_READ));
        lightNixie(5, temp/10);
        lightNixie(6, temp%10);

        temp = BSDToDecimal(DS1302_readByte(DS1302_WEEKDAY_READ));
        lightNixie(7, temp);
    }
}