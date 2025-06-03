#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"
#include "timer.h"

#define NULL '\0'

//zadanie: 7.4
//data: 03.06.2025


int debugVar;


void DelayOneMili(){
	unsigned long ulDelayCounter =0;
	for(ulDelayCounter =0; ulDelayCounter <7500;ulDelayCounter++){};

};

void Delay(unsigned long ulMili){
	unsigned long uldelayCount=0;
	for (uldelayCount = 0; uldelayCount<ulMili; uldelayCount++){
		DelayOneMili();
	}; // wskazanie stopera: 1.0000125 dla idelayCounter = 1500000
};		// dla mikrokontorlera wartosc jest inna: 7500 ~= 1ms

	enum LedState{STOP,STEP_LEFT,STEP_RIGHT,WIPER};
	enum LedState eLedState=STOP;
	
	unsigned int uiStepCounter=0;
	

	int main(){
	LedInit();	
	KeyboardInit();
	InitTimer0();
	WaitOnTimer0(1000000);
		
	InitTimer0Match0(1000000);
	WaitOnTimer0Match0();
		
};


