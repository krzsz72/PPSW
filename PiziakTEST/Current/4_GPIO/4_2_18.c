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

enum ButtonState{
	RELEASED,
	PRESSED
};

enum ButtonState eReadButton(){
	enum ButtonState S0 = RELEASED;

	if((IO0PIN&S0_bm)==0){         //0x03FFFFEF

		
		S0=PRESSED;
};

	return S0;
};




int main(){
	// 0000 0000 0000 0000 0001 0000 0000 0000
	// 0x00010000

	LedInit();	
	KeyboardInit();
	//4.2.18
	
	
	while(1){
	
				
		switch(eReadButton()){
			case 0:
				LedOn(0);
				break;
			case 1:
				LedOn(1);
				break;
		};
			
	
	}
}
