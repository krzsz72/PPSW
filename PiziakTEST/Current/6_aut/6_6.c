#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"

#define NULL '\0'

//zadanie: 6.6
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

	enum LedState{STOP,STEP_LEFT,STEP_RIGHT};
	enum LedState eLedState=STOP;
	
	unsigned int uiStepCounter=0;
	
int main(){
	LedInit();	
	KeyboardInit();
	while(1){
		switch(eLedState){
				case STOP:
						if(eKeyboardRead()==BUTTON_0){
						eLedState=STEP_LEFT;
						}
						if(eKeyboardRead()==BUTTON_2){
						eLedState=STEP_RIGHT;
						}
				
				break;
				
				case STEP_LEFT:
					if(eKeyboardRead()==BUTTON_1){
						eLedState=STOP;
					}else{
						LedStepLeft();
						uiStepCounter++;				
						}
				break;
				case STEP_RIGHT:
					if(eKeyboardRead()==BUTTON_1){
						eLedState=STOP;
					}else{
						LedStepRight();
						uiStepCounter++;				
						}
				break;
			}
		Delay(100);






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


