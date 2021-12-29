#include "IIC.h"

sbit IIC_SCL = P2^1;
sbit IIC_SDA = P2^0;

void IIC_start() {
    IIC_SDA = 1;
    IIC_SCL = 1;
    IIC_SDA = 0;
    IIC_SCL = 0;
}

void IIC_stop() {
    IIC_SDA = 0;
    IIC_SCL = 1;
    IIC_SDA = 1;
    IIC_SCL = 0;
}

void IIC_sendByte(uchar byte) {
    uchar i = 0;
    for (i = 0; i < 8; i++) {
        IIC_SCL = 0;
        IIC_SDA = byte & (0x80>>i);
        IIC_SCL = 1;
    }

    // must make sure SCL = 0 after sending
    IIC_SCL = 0;
}

uchar IIC_receiveByte() {
    uchar byte = 0x00;
    uchar i = 0;

    IIC_SDA = 1;
    for (i = 0; i < 8; i++) {
        IIC_SCL = 1;
        if (IIC_SDA)
            byte |= (0x80>>i);
        IIC_SCL = 0;
    }

    return byte;
}

void IIC_sendAck(uchar ack) {
    IIC_SDA = ack;
    IIC_SCL = 1;
    IIC_SCL = 0;
}

uchar IIC_receiveAck() {
    uchar ack;
    IIC_SDA = 1;
    IIC_SCL = 1;
    ack = IIC_SDA;
    IIC_SCL = 0;

    return ack;
}