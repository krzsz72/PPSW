#pragma once
#include <stdio.h>
#define NULL '\0'
#define NIBBLE_BM 0xF

void UIntToHexStr(unsigned int uiValue, char pcStr[]);

enum Result { OK, ERROR };
enum Result eHexStringToUInt(char pcStr[], unsigned int* puiValue);