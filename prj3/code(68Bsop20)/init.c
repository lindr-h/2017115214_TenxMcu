#define __init_c 
#include "includeAll.h"
void SysInit() {
  //启动后，立即清除看门狗
  F_clearWDT();
  //时钟初始化
  CLKCON = 0x03; // Clock div 1  7.3728Mhz
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
  P1MODL = 0xaa;
  P1MODH = P14MOD_2 | P15MOD_2;
  P_led_com = 0; /* 根据电路图，con 口应恒为低 */
  P_led_1 = 0;
	P_led_2 = 0;
  P_buzz = 0;

  // IO 状态初始化
	 
  /* 数码管端口初始化 */
  //  SMGInit();
 
  /* LED 端口初始化 */
  P1MODH |= P14MOD_2;
  P3MODH |= P36MOD_2;


  // T2 初始化  7.3728Mhz/2 = 3686400Hz
  
  // 3686400Hz/3686.4 = 1000Hz = 1ms timer2 interrupt
	//定时3.686ms,高八位
  TH2 = (65536 - 3686) / 256;
	//RCP2H：Timer2 重载/捕获数据的高字节
  RCP2H = TH2;
  //定时3.686ms,低八位
  TL2 = (65536 - 3686) % 256;
	//RCP2L：Timer2 重载/捕获数据的低字节
  RCP2L = TL2;
	
	//TR2: :Timer2 运行控制      1:允许Timer2 运行
  TR2 = 1;
	//ET2: :Timer2 中断使能控制  1:允许 Timer2 中断
  ET2 = 1;
	//EA: :总中断使能控制        1:每个中断通过其各个中断控制位使能或禁止
  EA = 1;
}
//=============================================================================
void VarsInit() {}

void SMGInit(void)
{
	P1MODL = P12MOD_2 | P13MOD_2;
	P1MODH = P14MOD_2 | P17MOD_2;
	P3MODL = P32MOD_2;
	P3MODH = P34MOD_2 | P35MOD_2 | P36MOD_2;
} 