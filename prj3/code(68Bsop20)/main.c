#define __main_c
#include "includeAll.h"
//=============================================================================

void main() {
	
  SysInit();//系统初始化
  VarsInit();//变量初始化
  //使能看门狗
  F_turnOnWDT();
  F_ledOn1();
	F_ledOn2();
  while (1) {
   //喂狗
   F_clearWDT();
   //业务代码
   TimeProcess();
   TaskSetting();
   TaskProcess();
  // DisplayProcess();
  }
}
void TimeProcess() {
  static uint8_t timer5ms = 0;
  static uint16_t second = 0;

   if (b1ms) {
    // 1ms 执行一次
    b1ms = 0;
    timer5ms++;
    second++;
  }
	 //每5ms以上获取一次键值
  if (timer5ms >= D_5ms) {
       GetKeys();	 
   }
  if (second >= D_1000ms) {
    // 1s 执行一次
    second = 0;
  }	  
}	
//=============================================================================
void TaskProcess() {}
//=============================================================================
void TaskSetting() {
	 if (D_keyValue1 == keyValue) {
		    F_ledNeg1();
		 }
  keyValue = D_keyNull;
}	
//=============================================================================
void DisplayProcess() {
    //F_ledOn1();
	  
}
void delayMs(uint16_t msCount) {
  uint16_t i, j;
  for (i = 0; i < msCount; i++) {
    for (j = 0; j < 1000; j++) {
      /* code */
      F_clearWDT();
    }
  }
}