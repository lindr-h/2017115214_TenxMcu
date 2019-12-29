#define __buzz_c 
#include "includeAll.h"


void showbell(){
	int i;
for(i = 0 ;i < 100; i++){
	 F_buzzOn();
	 delayMs(1);
	 F_buzzOff();
	 delayMs(1);
	  }
}