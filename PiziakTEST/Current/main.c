#include <LPC21xx.H>

#define NULL '\0'
#define NIBBLE_BM 0xF

//zadanie: 4.2.26
//data: 05.04.2025

//int ipin=0x10000; // pin P1.16
#define LED0_bm 0x10000 
#define LED1_bm 0x20000
#define LED2_bm 0x40000
#define LED3_bm 0x80000

#define S0_bm 0x10
#define S1_bm 0x40
#define S2_bm 0x20
#define S3_bm 0x80



int debugVar;


void DelayOneMili(){
	unsigned long ulDelayCounter =0;
	for(ulDelayCounter =0; ulDelayCounter <7500;ulDelayCounter++){};

};

void Delay(unsigned long ulMili){
	unsigned long uldelayCount=0;
	for (uldelayCount = 0; uldelayCount<ulMili; uldelayCount++){
		DelayOneMili();
	}; // wskazanie stopera: 1.0000125 dla idelayCounter = 1500000
};		// dla mikrokontorlera wartosc jest inna: 7500 ~= 1ms

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

enum eStepDir{LEFT,RIGHT};
void LedStep(enum eStepDir eLedDir){
	static unsigned int uiStep;
	switch(eLedDir){
		case 0:
			uiStep++;
			LedOn(uiStep%4);
			break;
		case 1:
			uiStep--;
			LedOn(uiStep%4);
			break;
	};
};

void LedStepLeft(void){
	LedStep(LEFT);
};
void LedStepRight(void){
	LedStep(RIGHT);
};

void UIntToHexStr(unsigned int uiValue, char pcStr[]) {
	unsigned char ucNibbleCounter;
	unsigned int uiCurrentNibble = uiValue;
	pcStr[0] = '0';
	pcStr[1] = 'x';
	for (ucNibbleCounter = 0; ucNibbleCounter < 4; ucNibbleCounter++)
	{
		uiCurrentNibble = ((uiValue >> (4 * ucNibbleCounter) & NIBBLE_BM ));
		//printf("\nnibble: %i\n",uiCurrentNibble);
		if (uiCurrentNibble<10)
		{
			pcStr[5-ucNibbleCounter] = uiCurrentNibble + '0';
		}
		else
		{
			pcStr[5-ucNibbleCounter] = uiCurrentNibble - 10 + 'A';
		}
		//printf("hex %x\n",pcStr[5-ucNibbleCounter);
		//printf("znak %c \n i=%i \n", pcStr[5-ucNibbleCounter,ucNibbleCounter;
		//printf("przes %x\n============\n", nibble);

	}
	pcStr[6] = NULL;
	//printf("wynik po forze: \n %x \n string: %c",pcStr, pcStr);

};


void AppentUIntToString(unsigned int uiValue, char pcDestinationStr[]) {
	unsigned char i = 0;
	for (i = 0; pcDestinationStr[i] != NULL; i++)
	{

	}
	UIntToHexStr(uiValue, pcDestinationStr+i);
	
};

	int liczb=16;
	char str[254]="ala ma kota ";


int main(){
	// 0000 0000 0000 0000 0001 0000 0000 0000
	// 0x00010000

	LedInit();	
	KeyboardInit();
	//4.2.20
	
	AppentUIntToString(liczb,str);
	
	/*
	while(1){
		
		switch(eKeyboardRead()){
			case 2:
				LedStepRight();
				Delay(250);
				break;
			case 3:
				LedStepLeft();
				Delay(250);
				break;
		};

	};*/
		
}
