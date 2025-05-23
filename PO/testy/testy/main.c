#include "lancuchy.h"
#include "konwersje.h"
#include "dekodowanie.h"
#include "stdio.h"


//void TestOf_() {};

//-----------------
//	TESTY LANCUCHOW
//-----------------
void TestOf_eCompareString() {
	
	printf("\n\tTest1 - Identyczne stringi\n");
	    char str1[] = "Ala ma kota";
	    char str2[] = "Ala ma kota";
	
	    printf("\neCompare: String1 - %s , String2 - %s\n", str1, str2);
		if (eCompareString(str1,str2)==EQUAL)
		{
			printf("\nEQUAL\n");
		}
		else {
			printf("\nDIFFERRENT\n");
		}

	printf("\n\tTest2 - Rozne stringi\n");
		char str3[] = "Ala ma kota";
		char str4[] = "Ala ma k\0ota";

		printf("\neCompare: String1 - %s , String2 - %s\n", str3, str4);
		if (eCompareString(str3, str4) == EQUAL)
		{
			printf("\nEQUAL\n");
		}
		else {
			printf("\nDIFFERRENT\n");
		}

	//printf("\n\tTest3 - NULL na pocz¹tku\n");
	//	char str5[] = "\0";
	//	char str6[] = "Ala ma kota";

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
	printf("\n*********** TEST eCompareString ***********\n");
	TestOf_eCompareString();

	return 0;
};