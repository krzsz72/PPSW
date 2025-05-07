#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"

#define NULL '\0'

//zadanie: 6.3
//data: 07.05.2025


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

	enum LedState{LED_LEFT,LED_RIGHT};
	enum LedState eLedState=LED_LEFT;

int main(){
	LedInit();	
	KeyboardInit();
	//6.3
	while(1){
		switch(eLedState){

				case LED_LEFT:
				LedStepLeft();
				eLedState ++;				
				break;
				case LED_RIGHT:
				LedStepRight();
				eLedState --;				
				break;
				
			}
		






		/*		
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
*/
	};
		
};


