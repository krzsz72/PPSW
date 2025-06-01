#include "lancuchy.h"
#include "konwersje.h"
#include "dekodowanie.h"
#include "stdio.h"
#define NULL '\0'

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

//-----------------
//	TESTY LANCUCHOW
//-----------------
void TestOf_CopyString() {
	char str1[] = "ul";
	char str2[254];
	char str3[] = "test";
	char str4[]="\0";

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
	char cTest1Str1[] = "Ala ma kota";
	char cTest1Str2[] = "Ala ma kota";
	char cTest2Str1[] = "Ala ma k\0ota";

	printf("\neCompareString\n\n");

	printf("Test1 - ");
	//dwa idemtyczne string
	   // printf("\neCompare: String1 - %s , String2 - %s\n", ucTest1Str1, ucTest1Str2);
		if (eCompareString(cTest1Str1,cTest1Str2)==EQUAL)
		{
			printf("OK\n");
		}
		else {
			printf("ERROR\n");
		}

	printf("Test2 - ");
	//dwa rozne stringi, jeden dodatkowo przedwczesnie zakonczony NULLEM

		//printf("\neCompare: String1 - %s , String2 - %s\n", ucTest1Str1, ucTest2Str1);
		if (eCompareString(cTest1Str1, cTest2Str1) == DIFFERENT)
		{
			printf("OK\n");
		}
		else {
			printf("ERROR\n");
		}

	//printf("\n\tTest3 - NULL na pocz¹tku\n");
	//	char str5[] = "\0";
	//	char str6[] = "Ala ma kota";
	//
	//	printf("\neCompare: String1 - %s , String2 - %s\n", str5, str6);
	//	if (eCompareString(str5, str6) == EQUAL)
	//	{
	//		printf("\nEQUAL\n");
	//	}
	//	else {
	//		printf("\nDIFFERRENT\n");
	//	}
	
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
	char str1[] = "Ala ma 99 kotów!";
	char str2[] = "Ala ma 99 kotów!";

	printf("\nReplaceCharatersInString\n\n");

	printf("Test 1 - ");
	//zamiana znaku a na x
	ReplaceCharactersInString(str1, 'a', 'x');
	if (eCompareString(str1,"Alx mx 99 kotów!") == EQUAL) printf("OK\n"); else printf("ERROR\n");

	printf("Test 2 - ");
	//zamiana znaku a na NULL
	ReplaceCharactersInString(str2, 'a', NULL);
	if (eCompareString(str2, "Al") == EQUAL) printf("OK\n"); else printf("ERROR\n");

};

//-----------------
//	TESTY KONWERSJI
//-----------------

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
	char errStr2[] = "0x";

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
	if (eHexStringToUInt(errStr2, &uint1)==ERROR) printf("OK\n"); else printf("ERROR\n");
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



//-----------------
//	TESTY DEKODOWANIA
//-----------------



void main() {
	printf("\n*********** TESTY LANCUCHOW ***********\n");
	TestOf_CopyString();
	TestOf_eCompareString();
	TestOf_AppendString();
	TestOf_ReplaceCharatersInString();

	printf("\n*********** TESTY KONWERSJI ***********\n");
	TestOf_UIntToHexStr();
	TestOf_eHexStringToUInt();
	TestOf_AppendUIntToString();

	printf("\n*********** TESTY DEKODOWANIA ***********\n");

	return 0;
};