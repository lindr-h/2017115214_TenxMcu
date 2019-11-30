#define __init_c
#include "includeAll.h"
//=============================================================================
void SysInit() {
   F_clearWDT();
  //时钟初始化
  CLKCON = 0x03; // Clock div1  7.3728Mhz
  STPPCK = 0;
  STPFCK = 0;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  SELFCK = 1;//系统时钟源选择。1:快时钟。
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();

  // IO 模式初始化
  P1MODL = 0xaa;//输出
  P1_0 = 1;
  // IO 状态初始化

  // T2 初始化  7.3728Mhz/2 = 3686400Hz
  //  3686400Hz/3686.4 = 1000Hz = 1ms timer2 interrupt
  TH2 = (65536 - 3686) / 256;
  RCP2H = TH2;
  TL2 = (65536 - 3686) % 256;
  RCP2L = TL2;
  TR2 = 1;   //允许Timer2 运行
  ET2 = 1;  //允许 Timer2 中断
  EA = 1;   //总中断使能控制
}
void VarsInit() {}