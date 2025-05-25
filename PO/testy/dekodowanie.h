#pragma once
#include "lancuchy.h"
#include "konwersje.h"
#define NULL '\0'

//
//typedef enum TokenType { KEYWORD, NUMBER, STRING };
//typedef enum KeywordCode { LD, ST, RST };
//
//typedef union TokenValue {
//	enum KeywordCode eKeyword;
//	unsigned int uiNumber;
//	char* pcString;
//};
//
//typedef struct Token {
//	enum TokenType eType;
//	union TokenValue uValue;
//};

#define MAX_TOKEN_NR 3

//struct Token asToken[MAX_TOKEN_NR];

//
//#define MAX_KEYWORD_STRING_LTH 10
//typedef struct Keyword
//{
//	enum KeywordCode eCode;
//	char cString[MAX_KEYWORD_STRING_LTH + 1];
//};
//#define MAX_KEYWORD_NR 3
//struct Keyword asKeywordList[MAX_KEYWORD_NR] = {
//	{RST,"reset"},
//	{LD, "load" },
//	{ST, "store"}
//};


unsigned char ucTokenNr;
unsigned char ucFindTokensInString(char* pcString);


//enum Result {OK,ERROR}; z modulu konwersje
enum Result eStringToKeyword(char pcStr[], enum KeywordCode* peKeywordCode);

void DecodeTokens(void);

void DecodeMsg(char* pcString);