#include "AT24C02.h"

void AT24C02_writeByte(uchar wordAddr, uchar byte) {
    IIC_start();
    IIC_sendByte(AT24C02_ADDR_WRITE); // slave machine address(WRITE)
    IIC_receiveAck();
    IIC_sendByte(wordAddr);
    IIC_receiveAck();
    IIC_sendByte(byte);
    IIC_receiveAck();
    IIC_stop();
}

uchar AT24C02_readByte(uchar wordAddr) {
    uchar byte;

    // set slave address and set read target address
    IIC_start();
    IIC_sendByte(AT24C02_ADDR_WRITE); // slave machine address(WRITE mode)
    IIC_receiveAck();
    IIC_sendByte(wordAddr);
    IIC_receiveAck();

    // read from target address
    IIC_start();
    IIC_sendByte(AT24C02_ADDR_READ); // slave machine address(READ mode)
    IIC_receiveAck();
    byte = IIC_receiveByte();
    IIC_sendAck(1);

    // stop
    IIC_stop();
    return byte;
}