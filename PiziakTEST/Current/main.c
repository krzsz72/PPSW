#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"

#define NULL '\0'

//zadanie: 5.2
//data: 16.04.2025


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


int main(){

	LedInit();	
	KeyboardInit();
	//5.2
	

	while(1){
				
		switch(eKeyboardRead()){
			case BUTTON_1:
				LedStepRight();
				Delay(250);
				break;
			case BUTTON_2:
				LedStepLeft();
				Delay(250);
				break;
			default:			
				break;
		};

	};
		
};


