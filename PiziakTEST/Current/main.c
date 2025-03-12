#include <LPC21xx.H>
#include <stdio.h>

int test;
int ipin=0x10000; // pin P1.16
int idelayCounter;

void Delay(unsigned long mili){
	unsigned long idelayCounter;
	unsigned long idelayMax;
	idelayMax = 1500000*mili/1000; //nawiasy psuja???
	
	for (idelayCounter = 0; idelayCounter<idelayMax; idelayCounter++){}; // wskazanie stopera: 1.0000125 dla idelayCounter = 1500000
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
		idelayCounter=0;
		Delay(500);
		idelayCounter=0;

}
}
