#define __dig_display_c 
#include "includeAll.h"
 
 /* 0~9 数字的数码管编码 */
/* 从左到右 依次为 dp g f e d c b a */
const uint8_t number_code[11] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

 void dig_Display(uint8_t number)
{
    uint16_t i;

     for (i = 0; i < 200; i++)
    {
        dig_One_Display(2, number / 10);
        delayMs(5);
        dig_One_Display(1, number % 10);
        delayMs(5);
        //F_clearWDT();
    }
}

 static void dig_One_Display(uint8_t position, uint8_t number)
{
    /* 选择数码管的位置 */
    /* 根据电路图，电平为低时该位被选中 */
    if (position == 1)
    {
        P_SMG_com1 = 0;
        P_SMG_com2 = 1;
    }
    else if (position == 2)
    {
        P_SMG_com1 = 1;
        P_SMG_com2 = 0;
    }

     /* 数据显示 */
    P_SMG_A = 0x01 & (number_code[number] >> 0);
    P_SMG_B = 0x01 & (number_code[number] >> 1);
    P_SMG_C = 0x01 & (number_code[number] >> 2);
    P_SMG_D = 0x01 & (number_code[number] >> 3);
    P_SMG_E = 0x01 & (number_code[number] >> 4);
    P_SMG_F = 0x01 & (number_code[number] >> 5);
    P_SMG_G = 0x01 & (number_code[number] >> 6);
    P_SMG_DG = 0x01 & (number_code[number] >> 7);
}
void SMG_Disable(void)
{
    P_SMG_com1 = 0;
    P_SMG_com2 = 0;
    P_SMG_A = 0x00;
    P_SMG_B = 0x00;
    P_SMG_C = 0x00;
    P_SMG_D = 0x00;
    P_SMG_E = 0x00;
    P_SMG_F = 0x00;
    P_SMG_G = 0x00;
    P_SMG_DG = 0x00;
    P_SMG_com1 = 1;
    P_SMG_com2 = 1;
} 