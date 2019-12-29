#ifndef __buzz_h
#define __buzz_h 
//Hal: exp: #define P_led P10 ----------------
#define P_buzz P1_5
//Const: exp: #define D_data 1 ---------------
#define D_buzzOn 1  //高电位响
#define D_buzzOff 0 //低点位不响
//Globle var ---------------------------------

#ifdef __buzz_c

#else

#endif

//Action Macro: exp: #define F_getData() -----
#define F_buzzOn()  P_buzz = D_buzzOn
#define F_buzzOff() P_buzz = D_buzzOff
//Function -----------------------------------
void showbell();
#endif