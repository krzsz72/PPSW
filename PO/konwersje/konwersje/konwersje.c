#include <stdio.h>
#define NULL '\0'

void UIntToHexStr(unsigned int uiValue, char pcStr[]) {
	unsigned char i;
	for (i = 0; i < 4; i++)
	{
		pcStr[i] = (uiValue & 0xff);
		printf("hex %x\n",pcStr[i]);
		printf("znak %c  i=%i ||||  \n", pcStr[i],i);
		uiValue = (uiValue >> 4);
		printf("przes %x\n============\n", uiValue);

	}
	pcStr[i+1] = NULL;
	printf("wynik po forze: \n %i \n%s",uiValue, pcStr);

};


int main() {
	char str[] = "0x0000";
	UIntToHexStr(45067,str);
};