#ifndef CCC_IIC_H
#define CCC_IIC_H

#include "common_header.h"

void IIC_start();
void IIC_stop();
void IIC_sendByte(uchar byte);
uchar IIC_receiveByte();
void IIC_sendAck(uchar ack); // answer:0  NOT answer:1
uchar IIC_receiveAck(); // answer:0  NOT answer:1


#endif // CCC_IIC_H