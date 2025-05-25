#include "lancuchy.h"
#include "konwersje.h"
#include "dekodowanie.h"
#include "stdio.h"

//
//void TestOf_() {
//	//zmienne
//
//	printf("\n\n");
//
//	printf("Test 1 - ");
//	//
//
//	if (true) printf("OK\n") else printf("ERROR\n");
//};

//-----------------
//	TESTY LANCUCHOW
//-----------------
void TestOf_CopyString() {
	unsigned char str1[] = "ul";
	unsigned char str2[254];

	printf("CopyString\n\n");

	printf("Test 1 - ");
	//niepusty str1<str2

	if (str2)	printf("OK\n");	else printf("ERROR\n");


};
void TestOf_eCompareString() {
	printf("eCompareString\n\n");
	char ucTest1Str1[] = "Ala ma kota";
	char ucTest1Str2[] = "Ala ma kota";
	char ucTest2Str1[] = "Ala ma k\0ota";


	printf("Test1 - ");
	//dwa idemtyczne string
	   // printf("\neCompare: String1 - %s , String2 - %s\n", ucTest1Str1, ucTest1Str2);
		if (eCompareString(ucTest1Str1,ucTest1Str2)==EQUAL)
		{
			printf("OK\n");
		}
		else {
			printf("ERROR\n");
		}

	printf("Test2 - ");
	//dwa rozne stringi, jeden dodatkowo przedwczesnie zakonczony NULLEM

		//printf("\neCompare: String1 - %s , String2 - %s\n", ucTest1Str1, ucTest2Str1);
		if (eCompareString(ucTest1Str1, ucTest2Str1) == DIFFERENT)
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







void main() {
	printf("\n*********** TESTY LANCUCHOW ***********\n");
	TestOf_CopyString();

	TestOf_eCompareString();
	

	return 0;
};