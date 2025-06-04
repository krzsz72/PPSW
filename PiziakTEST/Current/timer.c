#include <LPC21xx.H>
#include "timer.h"

#define T0_ENABLE_BM (1<<0)
#define T0_RESET_BM (1<<1)
#define T0MCR_INTERRUPT_BM (1<<0)
#define T0MCR_RESET_BM (1<<1)
#define T0_IR_MR0_BM (1<<0)

void InitTimer0(void){
	T0TCR = T0_ENABLE_BM; //ustawianie bitu wlaczenia timer0
	};


void WaitOnTimer0(unsigned int uiTime){

	T0TCR |= T0_RESET_BM; //ustawianie bitu resetu t0
	T0TCR &= ~(T0_RESET_BM); // kasowanie bitu resetu t0
	//1us
	while(T0TC<=uiTime*15){}; // dziala dopoki timer counter jest <= od ustawionego czasu
	
};

void InitTimer0Match0(unsigned int iDelayTime){
	
	T0MCR|=T0MCR_INTERRUPT_BM; //ustawienie zwracania flagi interrupt przez MR
	T0MCR|=T0MCR_RESET_BM; // zwracanie flagi reset przez MR
	T0MR0=iDelayTime*15; // wpisane wartosci dla ktorej MR0 sie zalaczy
	
	T0TCR |= T0_RESET_BM; // bit resetu
	T0TCR &= ~(T0_RESET_BM); // kasowanie bitu resetu
	T0TCR = T0_ENABLE_BM; //bit wlaczajacy
	
};

void WaitOnTimer0Match0(){

	while((T0IR&T0_IR_MR0_BM)==0){}; // oczekiwanie na flage interrupt
	
		T0IR = (1<<3);
		T0IR |= T0_IR_MR0_BM; //usuwanie flagi przerwania (wpisujac 1)

	
};

