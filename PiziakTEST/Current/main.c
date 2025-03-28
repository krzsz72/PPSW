#include <LPC21xx.H>
#include <stdio.h>


int ipin=0x10000; // pin P1.16


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



int main(){
	// 0000 0000 0000 0000 0001 0000 0000 0000
	// 0x00010000
	IO1DIR=ipin;
	IO1SET=ipin;
	IO1CLR=ipin;
	

	
	while(1){
		IO1SET=ipin;
		Delay(500);
	
		IO1CLR=ipin;
		Delay(1000);

}
}
