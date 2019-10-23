
#define __keys_c
#include "includeAll.h"

//=============================================================================
void GetKeys() {
	static uint8_t tmpKeyValue = D_keyNull;

  DelayMs(5);
  if (P_key1 == 0) {
    tmpKeyValue = D_keyValue1;
  }else{
    keyValue = tmpKeyValue ;
    tmpKeyValue = D_keyNull;  
}
}