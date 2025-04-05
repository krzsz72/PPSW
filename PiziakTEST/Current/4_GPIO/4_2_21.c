#include <LPC21xx.H>

#define NULL '\0'

//zadanie: 4.2.15
//data: 01.04.2025

//int ipin=0x10000; // pin P1.16
#define LED0_bm 0x10000 
#define LED1_bm 0x20000
#define LED2_bm 0x40000
#define LED3_bm 0x80000

#define S0_bm 0x10
#define S1_bm 0x40
#define S2_bm 0x20
#define S3_bm 0x80



static int debugVar;


void DelayOneMili(){
	unsigned long ulDelayCounter =0;
	for(ulDelayCounter =0; ulDelayCounter <1500;ulDelayCounter++){};

};

void Delay(unsigned long ulMili){
	unsigned long uldelayCount=0;
	for (uldelayCount = 0; uldelayCount<ulMili; uldelayCount++){
		DelayOneMili();
	}; // wskazanie stopera: 1.0000125 dla idelayCounter = 1500000
};



void LedInit(){
	IO1DIR|=LED0_bm|LED1_bm|LED2_bm|LED3_bm;
	IO1SET=LED0_bm;
};
void KeyboardInit(){
	IO0DIR &= ~(S0_bm|S1_bm|S2_bm|S3_bm);	
};

void LedOn(unsigned char ucLedIndex){

	IO1CLR=LED0_bm|LED1_bm|LED2_bm|LED3_bm;
	switch(ucLedIndex){
		case 0:
					IO1SET=LED0_bm;
			break;
		case 1:
					IO1SET=LED1_bm;
					break;
		case 2:
					IO1SET=LED2_bm;
					break;
		case 3:
					IO1SET=LED3_bm;
					break;
		};
};

enum KeyboardState{
	RELEASED,
	BUTTON_0,
	BUTTON_1,
	BUTTON_2,
	BUTTON_3,
};


enum KeyboardState eKeyboardRead(){
	enum KeyboardState eKeyboard = RELEASED;

	
	if((IO0PIN&S0_bm)==0){
		eKeyboard=BUTTON_0;
}else
	if((IO0PIN&S1_bm)==0){
		eKeyboard=BUTTON_1;
}else
	if((IO0PIN&S2_bm)==0){
		eKeyboard=BUTTON_2;
}else
	if((IO0PIN&S3_bm)==0){
		eKeyboard=BUTTON_3;
};

	return eKeyboard;
};





unsigned int uiStep;
void StepLeft(){
	uiStep++;
	LedOn(uiStep%4);
};
void StepRight(){
	uiStep--;
	LedOn(uiStep%4);
};

void LedStep(){
	
};


int main(){
	// 0000 0000 0000 0000 0001 0000 0000 0000
	// 0x00010000

	LedInit();	
	KeyboardInit();
	//4.2.20
	
	
	while(1){
	
		Delay(1000);
		StepRight();
	}
}
