#ifndef __display_h
#define __display_h
// Hal: exp: #define P_led_1 P1.1 -----------------
#define P_led_1 P1_4
#define P_led_2 P3_6
#define P_led_com P1_0
// Const: exp: #define D_data 1 ----------------
#define D_ledOn1 1  //高电位亮
#define D_ledOff1 0 //低点位灭
#define D_ledOn2 1  //高电位亮
#define D_ledOff2 0 //低点位灭
// Globle Var -----------------------------------------
#ifdef __display_c
#else

#endif

// Action Macro: exp: #define F_getData() ------
#define F_ledOn1() P_led_1 = D_ledOn1
#define F_ledOff1() P_led_1 = D_ledOff1
#define F_ledNeg1() P_led_1 = ~P_led_1
#define F_ledOn2() P_led_2 = D_ledOn2
#define F_ledOff2() P_led_2 = D_ledOff2
#define F_ledNeg2() P_led_2 = ~P_led_2
// Function ------------------------------------
extern void LED_Disable(void);
#endif