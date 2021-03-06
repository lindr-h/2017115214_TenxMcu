#define __main_c
#include "includeAll.h"
//=============================================================================
void main() {           //循环一次约1/10ms
  SysInit();   //系统初始化
  VarsInit();   //变量初始化
  
  F_turnOnWDT();//使能看门狗（看门狗复位360ms)
  while (1) {
    //喂狗（清零，否则看门狗溢出）
     F_clearWDT();//10-20ms清零一次，否则溢出
     //业务代码
    TimeProcess();
    TaskSetting();
    TaskProcess();
    //DisplayProcess();
    }
}
//=============================================================================
void TimeProcess() {   //基于时间片的调度框架
  static uint8_t timer5ms = 0;
  static uint16_t second = 0;

  if (b1ms) {
    // 每  1ms 执行一次
    b1ms = 0;     //位变量，执行就是一条指令，不会产生脏数据
    timer5ms++;
    second++;
  }
  if (timer5ms >= D_5ms) {
    //5ms 执行一次
    timer5ms = 0;
    GetKeys();
    }
  if (second >= D_1000ms) {
    // 1s 执行一次
    second = 0;
    vData = 0;
  }
  vData +=gData;
  if (vData > 100) {
    F_ledOn();
  } else {
    F_ledOff();
  }
}
//=============================================================================
void TaskProcess() {}
//=============================================================================
void TaskSetting() {
  if (D_keyValue1 == keyValue) {
    bLedFlash = ~bLedFlash;
  }
  keyValue = D_keyNull;
}
//=============================================================================
void DisplayProcess() {
  // F_ledOn();
	 if (bLedFlash) {
    F_ledOn();
  } else {
    F_ledOff();
  }
} 
