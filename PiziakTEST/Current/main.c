#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"
#include "servo.c"


// zadanie 9.4
//	10.06.25


int main (){
	
	KeyboardInit();
	ServoInit(50);

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
