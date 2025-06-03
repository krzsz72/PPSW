#include <LPC21xx.H>
#include "timer.h"

#define T0_ENABLE_BM (1<<0)
#define T0_RESET_BM (1<<1)
#define T0MCR_INTERRUPT_BM (1<<0)
#define T0MCR_RESET_BM (1<<1)
#define T0_IR_MR0_BM (1<<0)

void InitTimer0(void){
	T0TCR = T0_ENABLE_BM;
	};


void WaitOnTimer0(unsigned int uiTime){

	T0TCR |= T0_RESET_BM;
	T0TCR &= ~(T0_RESET_BM);
	//1us
	while(T0TC<=uiTime*15){};
	
};

void InitTimer0Match0(unsigned int iDelayTime){
	
	T0MCR|=T0MCR_INTERRUPT_BM;
	T0MCR|=T0MCR_RESET_BM;
	T0MR0=iDelayTime*15;
	
	T0TCR |= T0_RESET_BM;
	T0TCR &= ~(T0_RESET_BM);
	T0TCR = T0_ENABLE_BM;
	
};

void WaitOnTimer0Match0(){

	while((T0IR&T0_IR_MR0_BM)==0){};
	T0IR = T0_IR_MR0_BM;

	
};

