#include "lancuchy.h"
#include "konwersje.h"
#define NULL '\0'


typedef enum TokenType { KEYWORD, NUMBER, STRING };
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
	enum TokenFinderState { TOKEN, DELIMITER };
	enum TokenFinderState eTokenFinderState = DELIMITER;

	unsigned char ucCharCounter;
	unsigned char ucCurrentChar;
	for (ucCharCounter = 0; ; ucCharCounter++)
	{
		ucCurrentChar = pcString[ucCharCounter];
		switch (eTokenFinderState)
		{
		case DELIMITER:
			if (ucCurrentChar != ' ' & ucCurrentChar != NULL)
			{
				eTokenFinderState = TOKEN;
				asToken[ucTokenNr].uValue.pcString = pcString + ucCharCounter;
				ucTokenNr++;
			}
			else if (ucCurrentChar == ' ')
			{
				eTokenFinderState = DELIMITER;
			}
			else
			{
				return ucTokenNr;
			}
			break;

		case TOKEN:
			if (ucCurrentChar == NULL)
			{
				return ucTokenNr;
			}
			else if (ucCurrentChar == ' ')
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


//enum Result {OK,ERROR}; z modulu konwersje
enum Result eStringToKeyword(char pcStr[], enum KeywordCode* peKeywordCode) {

	for (unsigned char ucKeywordCount = 0; ucKeywordCount < MAX_KEYWORD_NR; ucKeywordCount++)
	{
		if (eCompareString(pcStr, asKeywordList[ucKeywordCount].cString) == EQUAL)
		{
			*peKeywordCode = asKeywordList[ucKeywordCount].eCode;
			return OK;
		}
	}
	return ERROR;
};


void DecodeTokens(void) {
	//dostaje ponullowane tokeny i je nazywa
	enum KeywordCode eTokenCode;
	unsigned int uiTokenNumber = 0;
	struct Token* psCurrentToken;

	for (unsigned char ucTokenCounter = 0; ucTokenCounter < ucTokenNr; ucTokenCounter++)
	{
		psCurrentToken = &asToken[ucTokenCounter];
		//printf("\ntoken: %x\n",psCurrentToken);
		if (eStringToKeyword(psCurrentToken->uValue.pcString, &eTokenCode) == OK)
		{
			psCurrentToken->eType = KEYWORD;
			psCurrentToken->uValue.eKeyword = eTokenCode;

			//printf("\neTokenCode : %i\n", eTokenCode);
		}
		else if (eHexStringToUInt(psCurrentToken->uValue.pcString, &uiTokenNumber) == OK)
		{
			psCurrentToken->eType = NUMBER;
			psCurrentToken->uValue.uiNumber = uiTokenNumber;
			//printf("uiTokenNumber %i",uiTokenNumber);
		}
		else
		{
			psCurrentToken->eType = STRING;
		}
	}
};


void DecodeMsg(char* pcString) {

	ucFindTokensInString(pcString);
	ReplaceCharactersInString(pcString, ' ', NULL);
	DecodeTokens();
	//printf("string wej : %s", pcString);

};



//
////char litera;
//int main() {
//	char teststring[] = "load 0x20 immediately";
//	DecodeMsg(teststring);
//
//
//}