#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"
#include "timer.h"

#define NULL '\0'

//zadanie: 7.4
//data: 03.06.2025



	int main(){
	LedInit();	
	KeyboardInit();
	InitTimer0();
	//WaitOnTimer0(1000000);
		
	InitTimer0Match0(1000000);
	WaitOnTimer0Match0();
		
};


