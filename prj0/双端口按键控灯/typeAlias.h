#ifndef __typeAlias_h
#define __typeAlias_h
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long int uint32_t;
typedef char int8_t;
typedef short int16_t;
typedef long int32_t;

//看门狗定时器复位始终启用
#define F_turnOnWDT() CFGWL = (CFGWL & 0x3f) | 0xC0
//设置以清除看门狗定时器，H/W 自动在一个时钟周期清除它
#define F_clearWDT() CLRWDT = 1

#endif