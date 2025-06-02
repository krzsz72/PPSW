#include <LPC21xx.H>
#include "timer.h"

#define timerEnableBM (1<<0)
#define timerResetBM (1<<1)


void InitTimer0(void){
	T0TCR |= timerEnableBM;
	
};


void WaitOnTimer0(unsigned int uiTime){

	T0TCR |=timerEnableBM;
	T0TCR &= ~(timerEnableBM);
	//1ms
	while(T0TC<uiTime*15){};
	

};