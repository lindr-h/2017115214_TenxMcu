#define __main_c
#include "includeAll.h"
//=============================================================================
void main() {
  SysInit();//系统初始化
  VarsInit();//变量初始化
  F_ledOn();
  delayMs(500);
  //使能看门狗
  F_turnOnWDT();

  while (1) {
   //清除看门狗定时器
   F_clearWDT();
   delayMs(20);
   GetKeys();
    if (D_keyValue1 == keyValue) {//当keyValue为1时，led灯电平改变
      F_ledNeg();
    }
    keyValue = D_keyNull;
  }	  
}	

//=============================================================================
void delayMs(uint16_t msCount) {
  uint16_t i, j;
  for (i = 0; i < msCount; i++) {
    for (j = 0; j < 1000; j++) {
      //清除看门狗定时器
      F_clearWDT();
    }
  }
}