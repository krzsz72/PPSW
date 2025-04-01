#include <LPC21xx.H>
#include <stdio.h>


//zadanie: 4.2.15
//data: 01.04.2025

//int ipin=0x10000; // pin P1.16
#define LED0_bm 0x10000 
#define LED1_bm 0x20000
#define LED2_bm 0x40000
#define LED3_bm 0x80000


void DelayOneMili(){
	unsigned long uldelayCounter =0;
	for(uldelayCounter =0; uldelayCounter <1500;uldelayCounter++){};

};

void Delay(unsigned long mili){
	unsigned long uldelayCount=0;
	for (uldelayCount = 0; uldelayCount<mili; uldelayCount++){
		DelayOneMili();
	}; // wskazanie stopera: 1.0000125 dla idelayCounter = 1500000
};



void LedInit(){
	IO1DIR|=LED0_bm|LED1_bm|LED2_bm|LED3_bm;
	IO1SET=LED0_bm;
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








int main(){
	// 0000 0000 0000 0000 0001 0000 0000 0000
	// 0x00010000

	LedInit();	
	
	
	while(1){
		unsigned char i =0;
		for(i=0; i<4; i++){
		LedOn(i);
		Delay(250);
		};

}
}
