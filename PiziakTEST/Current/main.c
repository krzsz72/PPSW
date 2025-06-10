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


enum ServoState {CALIB,IDLE,IN_PROGRESS};

struct Servo{
	enum ServoState eState;
	unsigned int uiCurrentPosition;
	unsigned int uiDesiredPosition;	
	
} sServo;








void Automat(void){
	enum LedState{IDLE,CALIB,IN_PROGRESS};
	static enum LedState eLedState=CALIB;
	
	//static unsigned int uiStepCounter=0;
	
	  switch(eLedState){
        case IDLE:
					if(sServo.uiCurrentPosition==sServo.uiDesiredPosition){
						eLedState=IDLE;
           }
					else eLedState=IN_PROGRESS;
        break;
        
        case IN_PROGRESS:
          if(sServo.uiCurrentPosition>sServo.uiDesiredPosition){
						LedStepLeft();
						sServo.uiCurrentPosition--;
						}
          if(sServo.uiCurrentPosition<sServo.uiDesiredPosition){
						LedStepRight();
						sServo.uiCurrentPosition++;
						}
					else{
            eLedState=IDLE;        
            }
        break;
        case CALIB:
          if(eReadDetector()==ACTIVE){
						sServo.uiCurrentPosition=0;
						sServo.uiDesiredPosition=0;
						
						eLedState=IDLE;
						}
						else{
            LedStepRight();//counterclockwise
            sServo.uiCurrentPosition++;        
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
