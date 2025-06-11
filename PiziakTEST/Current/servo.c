#include <LPC21xx.H>
#include "servo.h"
#include "timer_interrupts.h"
#include "led.h"

#define PIN_DETECTOR_BM (1<<10)


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


enum ServoState {CALIB,IDLE,IN_PROGRESS,OFFSET};
struct Servo{
	enum ServoState eState;
	unsigned int uiCurrentPosition;
	unsigned int uiDesiredPosition;	
} sServo;



void Automat(void){
	
	  switch(sServo.eState){
			
			  case CALIB:
          if(eReadDetector()==ACTIVE){
						sServo.uiCurrentPosition=0;				
						sServo.uiDesiredPosition=0;
						sServo.eState=OFFSET;
						
						}
						else{
						sServo.eState=CALIB;
            LedStepRight();//counterclockwise
            }
        break;

			  case OFFSET:
					if(sServo.uiCurrentPosition==12){
						sServo.uiCurrentPosition=0;
						sServo.uiDesiredPosition=0;
						sServo.eState=IDLE;
            }
					else{
						LedStepLeft();
						sServo.uiCurrentPosition++;
						sServo.eState=OFFSET;
						}
        break;
						
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
          else if(sServo.uiCurrentPosition>sServo.uiDesiredPosition){
						LedStepRight();
						sServo.uiCurrentPosition--;
						}
					else{
            sServo.eState=IDLE;        
            }
        break;

					}
};




void ServoInit(unsigned int uiServoFrequency){
	LedInit();	
	DetectorInit();
	
	Timer0Interrupts_Init(1000000/uiServoFrequency,&Automat);
	while(sServo.eState==CALIB){};

};

void ServoCalib(){
	sServo.eState=CALIB;

};

void ServoGoTo(unsigned int uiPosition){
	sServo.uiDesiredPosition=uiPosition;
	sServo.eState=IN_PROGRESS;
	while(sServo.eState==IN_PROGRESS){};

};


