#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"


#include <LPC21xx.H>
#define PIN_DETECTOR_BM (1<<10)


// zadanie 9.3
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
//	enum LedState{IDLE,CALIB,IN_PROGRESS};
	//static enum LedState eLedState=CALIB;
	
	//static unsigned int uiStepCounter=0;
	
	  switch(sServo.eState){
        case IDLE:
					if(sServo.uiCurrentPosition==sServo.uiDesiredPosition){
						sServo.eState=IDLE;
           }
					else sServo.eState=IN_PROGRESS;
        break;
        
        case IN_PROGRESS:
          if(sServo.uiCurrentPosition<sServo.uiDesiredPosition){
						LedStepLeft();
						sServo.uiCurrentPosition++;
						}
          if(sServo.uiCurrentPosition>sServo.uiDesiredPosition){
						LedStepRight();
						sServo.uiCurrentPosition--;
						}
					else{
            sServo.eState=IDLE;        
            }
        break;
        case CALIB:
          if(eReadDetector()==ACTIVE){
						sServo.uiCurrentPosition=0;
						sServo.uiDesiredPosition=0;
						
						sServo.eState=IDLE;
						}
						else{
            LedStepRight();//counterclockwise
            sServo.uiCurrentPosition++;        
            }
        break;

					}
};


int debugVar;



void ServoInit(unsigned int uiServoFrequency){
	LedInit();	
	DetectorInit();
	
	Timer0Interrupts_Init(1000000/uiServoFrequency,&Automat);

};

void ServoCalib(){
	sServo.eState=CALIB;
};

void ServoGoTo(unsigned int uiPosition){
	sServo.uiDesiredPosition=uiPosition;
};



int main (){
	
//	unsigned int iMainLoopCtr;
	KeyboardInit();
	//InitTimer0();
	
	

	while(1){

		switch(eKeyboardRead()){
			case BUTTON_0:
				ServoCalib();
				break;
			case BUTTON_1:
				ServoGoTo(12);
				break;
			case BUTTON_2:
				ServoGoTo(24);
				break;
			case BUTTON_3:
				ServoGoTo(36);
				break;

};







	}
}
