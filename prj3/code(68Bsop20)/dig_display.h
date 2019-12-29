#ifndef __dig_display_h
#define __dig_display_h 
//Hal: exp: #define P_led P10 ----------------
#define P_SMG_com1 P1_1
#define P_SMG_com2 P1_6
#define P_SMG_A P1_4
#define P_SMG_B P3_4
#define P_SMG_C P3_5
#define P_SMG_D P1_7
#define P_SMG_E P3_6
#define P_SMG_F P1_2
#define P_SMG_G P3_2
#define P_SMG_DG P1_3

//Const: exp: #define D_data 1 ---------------
  //code  char  seg[10]={0xC0,0XF0,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};

//Globle var ---------------------------------

#ifdef __dig_display_c

#else
//extern code  char  seg[]; 
#endif

//Action Macro: exp: #define F_getData() -----


//Function -----------------------------------
static void dig_One_Display(uint8_t position, uint8_t number);
extern void dig_Disable(void);
extern void dig_Display(uint8_t number);

#endif