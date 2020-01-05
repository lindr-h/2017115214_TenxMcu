#define __tempAd_c

#include    "includeAll.h"
//39k Pull up VCC, 12bits Ad sample
//0c--99c
#define D_tableSize 100
//10K

   code const uint16_t adTable[D_tableSize]={
   3974,3968,3962,3955,3949,3942,3935,3927,3919,3911,3901,3892,3882,
   3873,3863,3853,3842,3831,3820,3808,3795,3782,3768,3753,3738,3723,
   3707,3692,3677,3663,3650,3633,3616,3599,3580,3560,3539,3517,3495,
   3471,3448,3424,3400,3376,3353,3332,3306,3281,3255,3229,3202,3176,
   3149,3122,3094,3066,3037,3007,2977,2945,2912,2881,2849,2817,2784,
   2751,2718,2684,2650,2616,2582,2548,2514,2480,2447,2413,2381,2349,
   2317,2285,2253,2221,2189,2157,2124,2091,2058,2024,1990,1955,1919,
   1885,1853,1821,1790,1759,1728,1698,1668,1638,
   };

//=============================================================================
void GetTemp(void)
{
//var
	static uint16_t adFilterResult = 2200;  //39K
	uint16_t adCurResult;
	uint8_t head, middle, end;

//code
	P3MODL |= 0xc0;  //ad0=P3.3
	CHSEL = CHSEL & 0x0F;   //AD0	p3.3
	OPTION = 0x04;   //ADC Clock Rate 10: SYSCLK/16
	CLRWDT = 1;
	ADSOC = 1;
	_nop_();
	_nop_();
	while (ADSOC) {
	}
	adCurResult = ADCDH;
	adCurResult <<= 4;
	head = ADTKDT;
	head >>= 4;
	adCurResult += head;
	if (adCurResult <= D_shortValue) {
		bAdShort = 1;
		bAdOff = 0;
		bKettleValid = 0;
		padInvalidTimer1 = D_padInvalidTime1;
		padInvalidTimer2 = D_padInvalidTime2;
		return;
	}else {
		bAdShort = 0;
		if (adCurResult >= D_offValue) {
			bAdOff = 1;
			bKettleValid = 0;
			padInvalidTimer2 = D_padInvalidTime2;
			padInvalidTimer1 = D_padInvalidTime1;
			curTemp = 56;
			return;
		}else {
			bAdOff = 0;
			if (bKettleValid == 0) {
				bTestWaterLevel = 1;
				testWaterLowCounter = 0;
				testWaterCounter = 0;
				padInvalidTimer2 = D_padInvalidTime2;
				padInvalidTimer1 = D_padInvalidTime1;
			}
			bKettleValid = 1;
			//??? AD??????
			adFilterResult = (adFilterResult * 7 + adCurResult) / 8;
			//adFilterResult = adCurResult;
			//???? ??AD?????? ? ??
			head = 0;
			end = D_tableSize - 1;
			middle = (head + end) / 2;
			
			while (head != end) {
				if (adFilterResult < adTable[middle]) {
					head = middle + 1;
					middle = (head + end) / 2;
				}else {
					if (adFilterResult > adTable[middle]) {              //
						end = middle;
						middle = (head + end) / 2;
					}else {
						// ==
						break;
					} //end if
				}// end if
			}//end while
			curTemp = middle ;
			if (curTemp >= 100) {
				curTemp = 99;
			}
			
		//	curTemp = 78;
			// if (curTemp >= 45) {
			//  waterLowAdThreshold = D_waterLowAd - 300;
			//  if (curTemp >= 80) {
			//      waterLowAdThreshold = D_waterLowAd - 1600;
			//  }
			// }else {
			//  waterLowAdThreshold = D_waterLowAd;
			// }
			waterLowAdThreshold = D_waterLowAd;
		}
	}
}
//=============================================================================
void TestWaterLevel()
{
	uint16_t adWaterLevel;
	uint8_t tmp;

//code
	P3MODL |= 0xc0;  //ad0=P3.3
	CHSEL = D_swChannel;   //AD0
	OPTION = 0x04;   //ADC Clock Rate 10: SYSCLK/16
	CLRWDT = 1;
	ADSOC = 1;
	_nop_();
	_nop_();
	while (ADSOC) {
	}
	adWaterLevel = ADCDH;
	adWaterLevel <<= 4;
	tmp = ADTKDT;
	tmp >>= 4;
	adWaterLevel += tmp;
	testWaterCounter++;
	if (adWaterLevel >= waterLowAdThreshold) {
		testWaterLowCounter++;
	}
	if (testWaterCounter >= D_testWaterCount) {
		if (testWaterLowCounter >= D_testWaterLowCount) {
			bWaterLow = 1;
		}else {
			bWaterLow = 0;
		}
		bTestWaterLevel = 0;
		testWaterCounter = 0;
		testWaterLowCounter = 0;
	}
}