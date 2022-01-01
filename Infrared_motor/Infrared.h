#ifndef CCC_INFRARED_H
#define CCC_INFRARED_H

#include "INT0.h"
#include "timer_89c52.h"

#define TIME_WINDOW 500

#define IR_POWER		0x45
#define IR_MODE			0x46
#define IR_MUTE			0x47
#define IR_START_STOP	0x44
#define IR_PREVIOUS		0x40
#define IR_NEXT			0x43
#define IR_EQ			0x09
#define IR_VOL_MINUS	0x07
#define IR_VOL_ADD		0x15
#define IR_0			0x16
#define IR_RPT			0x19
#define IR_USD			0x0D
#define IR_1			0x0C
#define IR_2			0x18
#define IR_3			0x5E
#define IR_4			0x08
#define IR_5			0x1C
#define IR_6			0x5A
#define IR_7			0x42
#define IR_8			0x52
#define IR_9			0x4A

enum IR_STATE {
    AVALIABLE = 0, // avaliable
    WAIT, // waitting for start or repeat singal
    RECEIVE, // receive data
};

void IR_init();
uchar IR_getRepeat();
uchar IR_getData();
uchar IR_getAddress();
uchar IR_getCommand();


#endif // CCC_INFRARED_H