#include "konwersje.h"
#include <stdio.h>
#define NULL '\0'
#define NIBBLE_BM 0xF

void UIntToHexStr(unsigned int uiValue, char pcStr[]) {
	unsigned char ucNibbleCounter;
	unsigned int uiCurrentNibble;
	pcStr[0] = '0';
	pcStr[1] = 'x';
	for (ucNibbleCounter = 0; ucNibbleCounter < 4; ucNibbleCounter++)
	{
		uiCurrentNibble = ((uiValue >> (4 * ucNibbleCounter) & NIBBLE_BM));
		if (uiCurrentNibble < 10)
		{
			pcStr[5 - ucNibbleCounter] = uiCurrentNibble + '0';
		}
		else
		{
			pcStr[5 - ucNibbleCounter] = uiCurrentNibble - 10 + 'A';
		}
	}
	pcStr[6] = NULL;
};

void TestOfUIntToHexStr() {
	char testString[7];
	int testInt = 65000;
	UIntToHexStr(testInt, testString);
	printf("\n====================\nliczba: %i\nteststring: %s\n", testInt, testString);

}

//enum Result { OK, ERROR };
enum Result eHexStringToUInt(char pcStr[], unsigned int* puiValue) {
	unsigned char ucNibbleCounter = 0;
	if ((pcStr[0] == '0') && (pcStr[1] == 'x') && (pcStr[2] != NULL))
	{
		for (ucNibbleCounter = 0; ucNibbleCounter <= 4; ucNibbleCounter++)
		{
			unsigned char ucCurrentChar = pcStr[ucNibbleCounter + 2];
			if (ucCurrentChar == NULL)
			{
				break;
			}
			else if (ucCurrentChar <= '9')
			{
				*puiValue |= ucCurrentChar - '0';
			}
			else
			{
				*puiValue |= ucCurrentChar - 'A' + 10;
			}
			*puiValue = *puiValue << 4;
			if (ucNibbleCounter == 4)
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

void TestOfeHexStringToUInt() {
	char input[] = "0xFDE8";
	unsigned int output = 0;
	printf("blad: %i\n", eHexStringToUInt(input, &output));
	printf("output: %i", output);

};

void AppendUIntToString(unsigned int uiValue, char pcDestinationStr[]) {
	unsigned char ucCharCounter = 0;
	for (ucCharCounter = 0; pcDestinationStr[ucCharCounter] != NULL; ucCharCounter++)
	{

	}
	UIntToHexStr(uiValue, pcDestinationStr + ucCharCounter);
};

void TestOfAppendUIntToString() {
	int test1 = 16;
	char str[254] = "Ala ma kota ";
	AppendUIntToString(test1, str);
	printf("test %s", str);
};
//
//int main() {
//	TestOfeHexStringToUInt();
//	//TestOfUIntToHexStr();
//};