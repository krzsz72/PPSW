#include <LPC21xx.H>
#include "timer.h"

#define T0_ENABLE_BM (1<<0)
#define T0_RESET_BM (1<<1)


void InitTimer0(void){
	T0TCR = T0_ENABLE_BM;
	
};


void WaitOnTimer0(unsigned int uiTime){

	T0TCR |= T0_RESET_BM;
	T0TCR &= ~(T0_RESET_BM);
	//1us
	while(T0TC<=uiTime*15){};
	

};
