#define __init_c
#include "includeAll.h"
//=============================================================================
void SysInit() {
  //时钟初始化
  CLKCON = 0x03; // Clock div 1
  STPPCK = 0;//缺省，当将其设置为1时，将停止UART/Timer0/Timer1/Timer2/ADC在空闲模式的时钟
  STPFCK = 0;//缺省，当将其设置为1时将停止快时钟以节省慢钟/空闲
  _nop_();//延时1 μs
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  SELFCK = 1;//系统时钟源选择。0:慢时钟 1:快时钟。此位只有当 STPFCK = 0 才可以改变
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
P1MODL = 0xaa;//推挽输出
// IO 状态初始化
F_ledOff();
}
//=============================================================================
void VarsInit() {} 