
#define __keys_c
#include "includeAll.h"

//=============================================================================
void GetKeys() {
	static uint8_t tmpKeyValue = D_keyNull;
  //按键口 p10 设置为上拉输入
  P1MODL  = 0xa8;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();


  if (P_key1 == 0) {
    tmpKeyValue = D_keyValue1;
  }else{
    keyValue = tmpKeyValue ;
    tmpKeyValue = D_keyNull;  
}
//按键口P10,恢复为输出
P1MODL = 0xaa;
}