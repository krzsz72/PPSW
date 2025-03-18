#include <LPC21xx.H>
#include "lancuchy.h"

#define NULL '\0'

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
    unsigned char ucIndexCharToCopy = 0;
   
    for (ucIndexCharToCopy = 0; pcSource[ucIndexCharToCopy] != NULL; ucIndexCharToCopy++)
    {
        pcDestination[ucIndexCharToCopy] = pcSource[ucIndexCharToCopy];
    }
    pcDestination[ucIndexCharToCopy] = pcSource[ucIndexCharToCopy];

};

enum CompResult {
    DIFFERENT,
    EQUAL
};

enum CompResult eCompareString(char pcStr1[], char pcStr2[]) {
    unsigned char ucComparedChar = 0;
    for (ucComparedChar = 0; pcStr1[ucComparedChar] != NULL; ucComparedChar++)
    {
        if (pcStr1[ucComparedChar] != pcStr2[ucComparedChar])
        {
            return DIFFERENT;
        };
    };
    return EQUAL;
}

void AppendString(char pcSourceStr[], char pcDestinationStr[]) {
    unsigned char ucDestLen = 0;
    for (ucDestLen = 0; pcDestinationStr[ucDestLen] != NULL; ucDestLen++)
    {
        //licznik dlugosci pcDestinationStr
    }
    CopyString(pcSourceStr, pcDestinationStr + ucDestLen);
}

void ReplaceCharactersInString(char pcString[],char cOldChar, char cNewChar) {
    unsigned char ucIndexCharToReplace = 0;
    for (ucIndexCharToReplace = 0; pcString[ucIndexCharToReplace] != NULL; ucIndexCharToReplace++) {
        if (pcString[ucIndexCharToReplace] == cOldChar)
        {
            pcString[ucIndexCharToReplace] = cNewChar;
        }
    }
}


int main(){
	// 0000 0000 0000 0000 0001 0000 0000 0000
	// 0x00010000
	IO1DIR=ipin;
	IO1SET=ipin;
	IO1CLR=ipin;

	//TestOfCopyString();
	
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
