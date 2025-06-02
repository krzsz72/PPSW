#include "lancuchy.h"
#include "konwersje.h"
#include "dekodowanie.h"
#include "stdio.h"
#define NULL '\0'


//--------------------
//	TESTY LANCUCHOW
//--------------------
void TestOf_CopyString() {
	char str1[] = "ul";
	char str2[254];
	char str3[] = "test";
	char str4[] = "";

	printf("\nCopyString\n\n");

	printf("Test 1 - ");
	//przewidziane uzycie
	CopyString(str1, str2);
	if (eCompareString(str1,str2) == EQUAL) printf("OK\n"); else printf("ERROR\n");

	printf("Test 2 - ");
	//nadpisywanie stringa docelowego przez krotszy zrodlowy
	CopyString(str1, str3);
	if (eCompareString(str1,str3) == EQUAL) printf("OK\n"); else printf("ERROR\n");
	
	printf("Test 3 - ");
	//string zrodlowy rowny null
	CopyString(str4, str3);
	if (eCompareString(str4, str3) == EQUAL) printf("OK\n"); else printf("ERROR\n");

};

void TestOf_eCompareString() {
	char str1[] = "Ala ma kota";
	char str2[] = "Ala ma kota";
	char str3[] = "Ala";
	char str4[] = "";

	printf("\neCompareString\n\n");

	printf("Test1 - ");
	//dwa idemtyczne string
	if (eCompareString(str1, str2) == EQUAL) printf("OK\n"); else printf("ERROR\n");

	printf("Test2 - ");
	//dwa rozne stringi
	if (eCompareString(str1, str3) == DIFFERENT) printf("OK\n"); else printf("ERROR\n");

	printf("Test3 - ");
	//NULL na pocz¹tku
	if (eCompareString(str1, str4) == DIFFERENT) printf("OK\n"); else printf("ERROR\n");

}

void TestOf_AppendString() {
	char cSourceString[] = "test1";
	char cDestString[254]="";
	char cEmptyString[] = "";

	printf("\nAppendString\n\n");

	printf("Test 1 - ");
	//dopisanie do pustego stringa
	AppendString(cSourceString, cDestString);
	if (eCompareString(cDestString, cSourceString) == EQUAL) printf("OK\n"); else printf("ERROR\n");

	printf("Test 2 - ");
	//dopisanie do niepustego stringa
	AppendString(cSourceString, cDestString);
	if (eCompareString(cDestString, "test1test1") == EQUAL) printf("OK\n"); else printf("ERROR\n");

	printf("Test 3 - ");
	//dopisanie pustego stringa
	AppendString(cEmptyString, cSourceString);
	if (eCompareString(cSourceString, cSourceString) == EQUAL) printf("OK\n"); else printf("ERROR\n");

	//printf("Test 4 - ");
	////dopisanie do mniejszego stringa
	//AppendString(cSourceString, cEmptyString);
	//if (eCompareString(cEmptyString, cSourceString) == EQUAL) printf("OK\n"); else printf("ERROR\n");
};

void TestOf_ReplaceCharatersInString() {
	char str1[] = "Ala ma kota";
	char str2[] = "Ala ma kota";

	printf("\nReplaceCharatersInString\n\n");

	printf("Test 1 - ");
	//zamiana znaku a na x
	ReplaceCharactersInString(str1, 'a', 'x');
	if (eCompareString(str1,"Alx mx kotx") == EQUAL) printf("OK\n"); else printf("ERROR\n");

	printf("Test 2 - ");
	//zamiana znaku a na NULL
	ReplaceCharactersInString(str2, 'a', NULL);
	if (eCompareString(str2, "Al") == EQUAL) printf("OK\n"); else printf("ERROR\n");

};

//--------------------
//	TESTY KONWERSJI
//--------------------
void TestOf_UIntToHexStr() {
	unsigned int uint = 0xFDE8;
	char str1[254];
	unsigned int num0= 0;
	char str2[] = "test string";

	printf("\nUIntToHexStr\n\n");

	printf("Test 1 - ");
	//zamiana liczby 65000 na hex
	UIntToHexStr(uint, str1);
	if (eCompareString(str1, "0xFDE8") == EQUAL) printf("OK\n"); else printf("ERROR\n");
	
	printf("Test 2 - ");
	//nadpisanie niepustego stringa
	UIntToHexStr(num0, str2);
	if (eCompareString(str2, "0x0000") == EQUAL) printf("OK\n"); else printf("ERROR\n");
};


void TestOf_eHexStringToUInt() {
	unsigned int uint1 = 0;
	char str1[] = "0xFDE8";
	unsigned int uint2 = 0xFFFFFF;
	char str2[] = "0x";

	printf("\neHexStringToUInt\n\n");

	printf("Test 1 - ");
	//zamiana str1 i wpisanie w uint1
	eHexStringToUInt(str1, &uint1);
	if (uint1 == 0xFDE8) printf("OK\n"); else printf("ERROR\n");

	printf("Test 2 - ");
	//niepusty docelowy int
	eHexStringToUInt(str1, &uint2);
	if (uint2 == 0xFDE8) printf("OK\n"); else printf("ERROR\n");

	printf("Test 3 - ");
	//nieprawdilowy format string
	if (eHexStringToUInt(str2, &uint1)==ERROR) printf("OK\n"); else printf("ERROR\n");
};


void TestOf_AppendUIntToString() {
	unsigned int uint1 = 0xFDE8;
	char str1[254] = "";
	unsigned int num0 = 0;

	printf("\nAppendUIntToString\n\n");

	printf("Test 1 - ");
	//dopisanie do pustego stringa
	AppendUIntToString(uint1,str1);
	if (eCompareString("0xFDE8", str1) == EQUAL) printf("OK\n"); else printf("ERROR\n");

	printf("Test 2 - ");
	//dopisanie do niepustego stringa
	AppendUIntToString(uint1, str1);
	if (eCompareString("0xFDE80xFDE8", str1) == EQUAL) printf("OK\n"); else printf("ERROR\n");

	printf("Test 3 - ");
	//dopisanie 0 do stringa
	AppendUIntToString(num0, str1);
	if (eCompareString("0xFDE80xFDE80x0000", str1) == EQUAL) printf("OK\n"); else printf("ERROR\n");
};


//--------------------
//	TESTY DEKODOWANIA
//--------------------
void TestOf_ucFindTokensInString() {
	char str1[] = "";
	char str2[] = "   load reset";
	char str3[] = "load    reset";
	char str4[] = "load 0x20 immediately reset";

	printf("\nucFindTokensInString\n\n");

	printf("Test 1 - ");
	//pusty komunikat
	ucTokenNr = 0;
	ucFindTokensInString(str1);
	if (ucTokenNr == 0) printf("OK\n"); else printf("ERROR\n");
	
	printf("Test 2 - ");
	//komunikat rozpoczynajacy sie delimami
	ucTokenNr = 0;
	ucFindTokensInString(str2);
	if (ucTokenNr == 2
		&& eCompareString("load reset", asToken[0].uValue.pcString) == EQUAL
		&& eCompareString("reset", asToken[1].uValue.pcString) == EQUAL
		) printf("OK\n"); else printf("ERROR\n");

	printf("Test 3 - ");
	//komunikat rozdzielony kilkoma delimami
	ucTokenNr = 0;
	ucFindTokensInString(str3);
	if (ucTokenNr == 2
		&& eCompareString("load    reset", asToken[0].uValue.pcString) == EQUAL
		&& eCompareString("reset", asToken[1].uValue.pcString) == EQUAL
		) printf("OK\n"); else printf("ERROR\n");

	printf("Test 4 - ");
	//komunikat o czterech tokenach
	ucTokenNr = 0;
	ucFindTokensInString(str4);
	if (ucTokenNr == 4
		&& eCompareString("load 0x20 immediately reset", asToken[0].uValue.pcString) == EQUAL
		&& eCompareString("0x20 immediately reset", asToken[1].uValue.pcString) == EQUAL
		&& eCompareString("immediately reset", asToken[2].uValue.pcString) == EQUAL
		) printf("OK\n"); else printf("ERROR\n");

};

void TestOf_eStringToKeyword() {
	char str1[] = "load";
	char str2[] = "test";
	char str3[] = "";
	enum KeywordCode kod;

	printf("\neStringToKeyword\n\n");

	printf("Test 1 - ");
	//poprawne odnalezienie keyworda
	if (eStringToKeyword(str1,&kod) == OK
		&& kod==LD
		) printf("OK\n"); else printf("ERROR\n");

	printf("Test 2 - ");
	//niepoprawny keyword
	if (eStringToKeyword(str2, &kod) == ERROR) printf("OK\n"); else printf("ERROR\n");

	printf("Test 3 - ");
	//pusty string
	if (eStringToKeyword(str3, &kod) == ERROR) printf("OK\n"); else printf("ERROR\n");
};


void TestOf_DecodeTokens() {
	asToken[0].uValue.pcString = "load";
	asToken[1].uValue.pcString = "0x20";
	asToken[2].uValue.pcString = "immediately";
	ucTokenNr = 3;

	printf("\nDecodeTokens\n\n");
	
	printf("Test 1 - ");
	//keyword
	DecodeTokens();
	if (asToken[0].eType == KEYWORD && asToken[0].uValue.eKeyword == LD) printf("OK\n"); else printf("ERROR\n");

	printf("Test 2 - ");
	//number
	if (asToken[1].eType == NUMBER && asToken[1].uValue.uiNumber == 0x20) printf("OK\n"); else printf("ERROR\n");

	printf("Test 3 - ");
	//ani keyword ani number
	if (asToken[2].eType == STRING && eCompareString(asToken[2].uValue.pcString, "immediately")) printf("OK\n"); else printf("ERROR\n");

	printf("Test 4 - ");
	//null
	asToken[0].uValue.pcString = "";
	asToken[1].uValue.pcString = "";
	asToken[2].uValue.pcString = "";
	ucTokenNr = 3;
	DecodeTokens();
	if (asToken[0].eType == STRING && eCompareString(asToken[0].uValue.pcString, "")
		&& asToken[1].eType == STRING && eCompareString(asToken[1].uValue.pcString, "")
		&& asToken[2].eType == STRING && eCompareString(asToken[2].uValue.pcString, "")
		) printf("OK\n"); else printf("ERROR\n");

};


void TestOf_DecodeMsg() {
	ucTokenNr = 0;
	char str1[] = "load 0x20 immediately";
	char str2[] = "";
	
	printf("\nDecodeMsg\n\n");

	printf("Test 1 - ");
	//poprawny typ komunikatu
	DecodeMsg(str1);
	if (ucTokenNr==3
		&& asToken[0].eType == KEYWORD && asToken[0].uValue.eKeyword == LD
		&& asToken[1].eType == NUMBER && asToken[1].uValue.uiNumber == 0x20
		&& asToken[2].eType == STRING && eCompareString(asToken[2].uValue.pcString, "immediately")
		) printf("OK\n"); else printf("ERROR\n");

	printf("Test 2 - ");
	//pusty komunikat
	ucTokenNr = 0;
	DecodeMsg(str2);
	if (ucTokenNr==0) printf("OK\n"); else printf("ERROR\n");
};


//
//void TestOf_() {
//	//zmienne
//
//	printf("\n\n\n");
//
//	printf("Test 1 - ");
//	//
//
//	if (eCompareString(str1,str3) == EQUAL) printf("OK\n"); else printf("ERROR\n");
//};

void main() {
	printf("\n*********** TESTY LANCUCHOW	 ***********\n");
	TestOf_CopyString();
	TestOf_eCompareString();
	TestOf_AppendString();
	TestOf_ReplaceCharatersInString();

	printf("\n*********** TESTY KONWERSJI	 ***********\n");
	TestOf_UIntToHexStr();
	TestOf_eHexStringToUInt();
	TestOf_AppendUIntToString();

	printf("\n*********** TESTY DEKODOWANIA	 ***********\n");
	TestOf_ucFindTokensInString();
	TestOf_eStringToKeyword();
	TestOf_DecodeTokens();
	TestOf_DecodeMsg();

	return 0;
};
