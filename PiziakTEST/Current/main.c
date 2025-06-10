#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"


#include <LPC21xx.H>
#define PIN_DETECTOR_BM (1<<10)


// zadanie 9.1
//	10.06.25

void DetectorInit(){
	
	IO0DIR &= ~(PIN_DETECTOR_BM);	
	
};
	
typedef enum {INACTIVE,ACTIVE} DetectorState;
DetectorState eReadDetector(){
		if((IO0PIN&PIN_DETECTOR_BM)==0){
				return ACTIVE;
				}
		else return INACTIVE;
};











void Automat(void){
	enum LedState{STOP,STEP_LEFT,STEP_RIGHT,CALIB};
	static enum LedState eLedState=CALIB;
	
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
        case CALIB:
          if(eReadDetector()==ACTIVE){
							eLedState=STOP;
						}
						else{
            LedStepRight();
            uiStepCounter++;        
            }
        break;

					}
};


int debugVar;

int main (){
	
//	unsigned int iMainLoopCtr;
	LedInit();	
	KeyboardInit();
	//InitTimer0();
	DetectorInit();
	
	Timer0Interrupts_Init(20000,&Automat);
	

	while(1){
			debugVar = eReadDetector();
		//	WaitOnTimer0(1000);
	}
}
