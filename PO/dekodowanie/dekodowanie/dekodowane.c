#include "lancuchy.h"
#define NULL '\0'




typedef enum TokenType {KEYWORD,NUMBER,STRING};
typedef enum KeywordCode { LD, ST, RST };

typedef union TokenValue {
	enum KeywordCode eKeyword;
	unsigned int uiNumber;
	char* pcString;
};

typedef struct Token {
	enum TokenType eType;
	union TokenValue uValue;
};

#define MAX_TOKEN_NR 3

struct Token asToken[MAX_TOKEN_NR];

#define MAX_KEYWORD_STRING_LTH 10
typedef struct Keyword
{
	enum KeywordCode eCode;
	char cString[MAX_KEYWORD_STRING_LTH + 1];
};
#define MAX_KEYWORD_NR 3
struct Keyword asKeywordList[MAX_KEYWORD_NR] = {
	{RST,"reset"},
	{LD, "load" },
	{ST, "store"}
};



unsigned char ucTokenNr;
unsigned char ucFindTokensInString(char* pcString) {
	enum TokenFinderState {TOKEN,DELIMITER};
	enum TokenFinderState eTokenFinderState = DELIMITER;

	unsigned char ucCharCounter;
	unsigned char ucCurrentChar;
	for (ucCharCounter = 0; ; ucCharCounter++)
	{
		ucCurrentChar = pcString[ucCharCounter];
		switch (eTokenFinderState)
		{
		case DELIMITER:
			if (ucCurrentChar!=' ' & ucCurrentChar!=NULL)
			{
				ucTokenNr++;
				eTokenFinderState = TOKEN;
			}
			else if (ucCurrentChar==' ')
			{
				eTokenFinderState = DELIMITER;
			}
			else
			{
				return ucTokenNr;
			}
			break;

		case TOKEN:
			if (ucCurrentChar==NULL)
			{
				return ucTokenNr;
			}
			else if (ucCurrentChar==' ')
			{
				eTokenFinderState = DELIMITER;
			}
			else
			{
				eTokenFinderState = TOKEN;
			}
			break;

		}
	}

};


enum Result {OK,ERROR};

enum Result eStringToKeyword(char pcStr[], enum KeywordCode *peKeywordCode) {




};

void DecodeTokens(void) {
	//dostaje ponullowane tokeny i je nazywa

};


void DecodeMsg(char *pcString) {

	ucFindTokensInString(pcString);

	printf("\ntoken nr: %i\n", ucTokenNr);

	ReplaceCharactersInString(pcString,' ',NULL);
	DecodeTokens();
	printf("string wej : %s", pcString);

};





int main() {
	char teststring[] = "load 0x20 immediately";
	DecodeMsg(teststring);
}