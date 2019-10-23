#define __main_c
#include "includeAll.h"
//=============================================================================
void main() {
  SysInit();
  VarsInit();
  F_ledOn();
  DelayMs(500);
  F_turnOnWDT();//使能看门狗（看门狗复位360ms)
  while (1) {
    //喂狗（清零，否则看门狗溢出）
     F_clearWDT();
    // user coding
    //F_ledOff();
    //delayMs(500);
    //F_ledOn();
    //delayMs(500);
    //DelayMs(20);
    GetKeys();
    if (D_keyValue1 == keyValue) {
      F_ledNeg();
    }
    keyValue = D_keyNull;
  }
}
//=============================================================================
void DelayMs(uint16_t msCount) {
  uint16_t i, j;
  for (i = 0; i < msCount; i++) {
    for (j = 0; j < 1000; j++) {
      /* code */
       F_clearWDT();
    }
  }
}

