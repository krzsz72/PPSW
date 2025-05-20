#pragma once
#include <stdio.h>
#define NULL '\0'



void CopyString(char pcSource[], char pcDestination[]);


enum CompResult {
    DIFFERENT,
    EQUAL
};

enum CompResult eCompareString(char pcStr1[], char pcStr2[]);

void AppendString(char pcSourceStr[], char pcDestinationStr[]);


void ReplaceCharactersInString(char pcString[], char cOldChar, char cNewChar);
