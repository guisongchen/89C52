#include "DS18B20.h"

void DS18B20_convertT() {
    OneWire_init();
    OneWire_sendByte(DS18B20_SKIP_ROM);
    OneWire_sendByte(DS18B20_CONVERT_T);
}

int DS18B20_ReadT() {
	unsigned char TLSB,TMSB;
	int Temp;
	// float T;
	OneWire_init();
	OneWire_sendByte(DS18B20_SKIP_ROM);
	OneWire_sendByte(DS18B20_READ_SCRATCHPAD);
	TLSB=OneWire_receiveByte();
	TMSB=OneWire_receiveByte();
	Temp=(TMSB<<8)|TLSB; // with float bits
	// T=Temp/16.0; // to float
	// return (int)(T); // to int
    return Temp;
}
