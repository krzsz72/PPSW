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
	enum automatstate {TOKEN,DELIMITER};
	enum automatstate eautomatstate = DELIMITER;
	for (ucTokenNr = 0; ucTokenNr< MAX_TOKEN_NR; ucTokenNr++)
	{
		switch (eautomatstate)
		{
		case DELIMITER:
			break;
		case TOKEN:
			break;

		default:
			break;
		}
	}


};


enum eResult {OK,ERROR};

enum eResult eStringToKeyword(char pcStr[], enum KeywordCode *peKeywordCode) {




};

void DecodeTokens(void) {
	//dostaje ponullowane tokeny i je nazywa

};


void DecodeMsg(char *pcString) {

	ucFindTokensInString(pcString);
	ReplaceCharactersInString(pcString,' ',NULL);
	DecodeTokens();
	printf("string wej : %s", pcString);

};








int main() {
	char teststring[] = "load 0x20 immediately";
	DecodeMsg(teststring);
}