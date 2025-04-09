#include <LPC21xx.H>
#include "lancuchy.h"

#define NULL '\0'

char string[]="Ala ma kot\0a";
char string2[254];
enum CompResult TestOfCompare;

void CopyString(char pcSource[], char pcDestination[]) {
    unsigned char ucCharCounter = 0;
   
    for (ucCharCounter = 0; pcSource[ucCharCounter] != NULL; ucCharCounter++)
    {
        pcDestination[ucCharCounter] = pcSource[ucCharCounter];
    }
    pcDestination[ucCharCounter] = NULL;

};

enum CompResult {
    DIFFERENT,
    EQUAL
};

enum CompResult eCompareString(char pcStr1[], char pcStr2[]) {
    unsigned char ucCharCounter = 0;
    for (ucCharCounter = 0; pcStr1[ucCharCounter] != NULL; ucCharCounter++)
    {
        if (pcStr1[ucCharCounter] != pcStr2[ucCharCounter])
        {
            return DIFFERENT;
        };
    };
    return EQUAL;
}

void AppendString(char pcSourceStr[], char pcDestinationStr[]) {
    unsigned char ucCharCounter = 0;
    for (ucCharCounter = 0; pcDestinationStr[ucCharCounter] != NULL; ucCharCounter++)
    {
        //licznik dlugosci pcDestinationStr
    }
    CopyString(pcSourceStr, pcDestinationStr + ucCharCounter);
}

void ReplaceCharactersInString(char pcString[],char cOldChar, char cNewChar) {
    unsigned char ucCharCounter = 0;
    for (ucCharCounter = 0; pcString[ucCharCounter] != NULL; ucCharCounter++) {
        if (pcString[ucCharCounter] == cOldChar)
        {
            pcString[ucCharCounter] = cNewChar;
        }
    }
}


int main(){
	CopyString(string,string2);
	
	TestOfCompare = eCompareString(string,string2);
	
	AppendString(string,string2);
	
	ReplaceCharactersInString(string,'a','x');
	
	
	
	
}
