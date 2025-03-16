#include <LPC21xx.H>
#include "lancuchy.h"


#define NULL 0x0;

//int test;
int ipin=0x10000; // pin P1.16
int idelayCounter;

void Delay(unsigned long mili){
	unsigned long idelayCounter;
	unsigned long idelayMax;
	idelayMax = 1500000*mili/1000; //nawiasy psuja???
	
	for (idelayCounter = 0; idelayCounter<idelayMax; idelayCounter++){}; // wskazanie stopera: 1.0000125 dla idelayCounter = 1500000
};





void CopyString(char pcSource[], char pcDestination[]) {
    int i = 0;
    /*do
    {
        pcDestination[i] = pcSource[i];
        i++;
    } while (pcSource[i]!='\0');*/

    for (i = 0; pcSource[i] != 0x0; i++)
    {
        pcDestination[i] = pcSource[i];
    }
    pcDestination[i] = pcSource[i];

};


int main(){
	// 0000 0000 0000 0000 0001 0000 0000 0000
	// 0x00010000
	IO1DIR=ipin;
	IO1SET=ipin;
	IO1CLR=ipin;

	TestOfCopyString();
	
	//test = 99;

/*
	
	while(1){
		IO1SET=ipin;
		Delay(500);
	
		IO1CLR=ipin;
		idelayCounter=0;
		Delay(500);
		idelayCounter=0;

}*/
}
