#include <stdio.h>
#define NULL '\0'



void CopyString(char pcSource[], char pcDestination[]) {
    unsigned char ucIndexCharToCopy = 0;
   
    for (ucIndexCharToCopy = 0; pcSource[ucIndexCharToCopy] != NULL; ucIndexCharToCopy++)
    {
        pcDestination[ucIndexCharToCopy] = pcSource[ucIndexCharToCopy];
    }
    pcDestination[ucIndexCharToCopy] = pcSource[ucIndexCharToCopy];

};
//------^^^^^^^^^^^^^ Copy string alt
/*do
   {
       pcDestination[i] = pcSource[i];
       i++;
   } while (pcSource[i]!='\0');*/


enum CompResult {
    DIFFERENT,
    EQUAL
};

enum CompResult eCompareString(char pcStr1[], char pcStr2[]) {
    unsigned char ucComparedChar = 0;
    for (ucComparedChar = 0; pcStr1[ucComparedChar] != NULL; ucComparedChar++)
    {
        if (pcStr1[ucComparedChar] != pcStr2[ucComparedChar])
        {
            return DIFFERENT;
        };
    };
    return EQUAL;
}

void AppendString(char pcSourceStr[], char pcDestinationStr[]) {
    unsigned char ucDestLen = 0;
    for (ucDestLen = 0; pcDestinationStr[ucDestLen] != NULL; ucDestLen++)
    {
        //licznik dlugosci pcDestinationStr
    }
    CopyString(pcSourceStr, pcDestinationStr + ucDestLen);
}

void ReplaceCharactersInString(char pcString[],char cOldChar, char cNewChar) {
    unsigned char ucIndexCharToReplace = 0;
    for (ucIndexCharToReplace = 0; pcString[ucIndexCharToReplace] != NULL; ucIndexCharToReplace++) {
        if (pcString[ucIndexCharToReplace] == cOldChar)
        {
            pcString[ucIndexCharToReplace] = cNewChar;
        }
    }
}

void TestOfCopyString() {
    printf("\n*********** TEST CopyString ***********\n");
    char myString[] = "Hello\0world";
    char newString[254];
    int i;

    /*for (i = 0; i < 20;i++) {
        newString[i] = i;
    }*/
    //CopyString(myString, newString);
    //char myString[] = "nie lubie pointerow\0";
    //char newString[254];
    for (i = 0; i < 254; i++)
    {
        newString[i] = '\0';
    }
    /*printf("\nnewString: %c\n", newString);
    printf("\nnewString ascii: %d\n", newString);*/

    CopyString(myString, newString);
    printf(newString);

    for (int j = 0; ; j++)
    {
        printf("\nlitera %c | liczba %d", newString[j], newString[j]);
        if (newString[j] == NULL)
        {
            printf(" ------- [!] znaleziono null\n");
            break;
        }
    }
};

void TestOfeCompareString() {
    printf("\n*********** TEST eCompareString ***********\n");

    char str1[] = "Ala ma kota";
    char str2[] = "Ala ma kota";

    printf("\neCompare String %s , %s\n", str1, str2);
    printf("DIFFERENT = 0 | EQUAL = 1\nCompResult: %i\n", eCompareString(str1, str2));

}

void TestOfAppendString() {
    printf("\n*********** TEST AppendString ***********\n");

    char str1[] = " ma kota";
    unsigned char str2[254] = "Ala";

    AppendString(str1, str2);
    printf("\nstr2 + str1: %s\n", str2);
}

void TestOfReplaceCharactersInString() {
    printf("\n*********** TEST ReplaceCharactersInString ***********\n");

    char str1[] = "Ala ma Kota";
    ReplaceCharactersInString(str1, 'a', 'x');
    printf("\n Po zamianie liter: %s\n", str1);
}

int main() {
    TestOfCopyString();
    TestOfeCompareString();
    TestOfAppendString();
    TestOfReplaceCharactersInString();
    return 0;
}