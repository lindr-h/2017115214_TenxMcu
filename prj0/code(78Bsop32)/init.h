#ifndef _init_h
#define _init_h

#define P_led P1_1

#define D_ledOn  1  //高电位亮
#define D_ledOff 0   //低电位灭



#ifdef _init_c

#else

#endif


//
#define F_ledOn() P_led = D_ledOn
#define F_ledOff() P_led = D_ledOff
//Function
void SysInit();
void VarsInit();

void delayMs(uint16_t msCount);
#endif