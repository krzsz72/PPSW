#include "konwersje.h"
#define NULL '\0'
#define NIBBLE_BM 0xF

void UIntToHexStr(unsigned int uiValue, char pcStr[]) {
	unsigned char ucNibbleCounter;
	unsigned int uiCurrentNibble;
	pcStr[0] = '0';
	pcStr[1] = 'x';
	for (ucNibbleCounter = 0; ucNibbleCounter < 4; ucNibbleCounter++)
	{
		uiCurrentNibble = ((uiValue >> (4 * ucNibbleCounter) & NIBBLE_BM ));
		if (uiCurrentNibble<10)
		{
			pcStr[5-ucNibbleCounter] = uiCurrentNibble + '0';
		}
		else
		{
			pcStr[5-ucNibbleCounter] = uiCurrentNibble - 10 + 'A';
		}
	}
	pcStr[6] = NULL;
};



//enum Result {OK,ERROR};
enum Result eHexStringToUInt(char pcStr[], unsigned int* puiValue) {
	unsigned char ucNibbleCounter= 0;
	if ( (pcStr[0] == '0') && (pcStr[1] == 'x') && (pcStr[2]!=NULL) )
	{
		for (ucNibbleCounter = 0; ucNibbleCounter <= 4; ucNibbleCounter++)
		{
			unsigned char ucCurrentChar = pcStr[ucNibbleCounter + 2];
			if (ucCurrentChar==NULL)
			{
				break;
			}
			else if (ucCurrentChar<='9')
			{
				*puiValue |= ucCurrentChar-'0';
			}
			else
			{
				*puiValue |= ucCurrentChar -'A'+10;
			}
			*puiValue = *puiValue << 4;
			if (ucNibbleCounter==4)
			{
				return ERROR;
			}
		}
		*puiValue = *puiValue >> 4;
		return OK;
	}
	else
	{
		return ERROR;
	}
};



void AppendUIntToString(unsigned int uiValue, char pcDestinationStr[]) {
	unsigned char ucCharCounter = 0;
	for (ucCharCounter = 0; pcDestinationStr[ucCharCounter] != NULL; ucCharCounter++)
	{

	}
	UIntToHexStr(uiValue, pcDestinationStr+ucCharCounter);
};
