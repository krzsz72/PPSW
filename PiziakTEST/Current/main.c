#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"



void Automat(void){
	enum LedState{STOP,STEP_LEFT,STEP_RIGHT};
	static enum LedState eLedState=STOP;
	
	static unsigned int uiStepCounter=0;
	
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
};

int main (){
	
	unsigned int iMainLoopCtr;
	LedInit();	
	KeyboardInit();

	Timer0Interrupts_Init(20000,&Automat);
	

	while(1){
	 	iMainLoopCtr++;
		
	}
}
