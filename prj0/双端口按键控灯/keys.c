#define __keys_c
#include "includeAll.h"
//=============================================================================
void GetKeys() {
  //临时键值为0
  static uint8_t tmpKeyValue = D_keyNull;//静态局部变量初始化为0，每次执行函数保持上一次的执行时的值

   if (P_key1 == 0) {	 //按键真的按下，为低电平
     tmpKeyValue = D_keyValue1;
  } else {            //按键没有被按下，为高电平
    keyValue = tmpKeyValue;
    tmpKeyValue = D_keyNull;
  }
} 