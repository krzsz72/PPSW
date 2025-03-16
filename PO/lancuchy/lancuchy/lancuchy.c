#include <stdio.h>
#define NULL 0x0;



void CopyString(char pcSource[], char pcDestination[]) {
    int i = 0;
    /*do
    {
        pcDestination[i] = pcSource[i];
        i++;
    } while (pcSource[i]!='\0');*/

    for (i = 0; pcSource[i] != 0x0; i++)
    {
        pcDestination[i] = pcSource[i];
    }
    pcDestination[i] = pcSource[i];

};


void TestOfCopyString() {
    char myString[] = "Hello\0world";
    char newString[254];
    int i;

    for (i = 0; i < 20;i++) {
        newString[i] = i;
    }


    CopyString(myString, newString);


};


int main() {
    // Define a string
    char myString[] = "nie lubie pointerow\0";
    char newString[254];
    for (int i = 0; i < 254; i++)
    {
       newString[i] = '\0';
    }
    printf("newString: %c\n", newString);
    printf("newString ascii: %d\n", newString);
        
    CopyString(myString, newString);
    printf(newString);

    for (int j = 0; ; j++)
    {
        printf("\nlitera %c | liczba %d",newString[j],newString[j]);
        if (newString[j]==0x0)
        {
            printf(" ------- [!] znaleziono null");
            break;
        }
    }


    //// Print header
    //printf("Character | ASCII Value | Memory Address\n");
    //printf("----------|-------------|---------------\n");

    //// Iterate through the string until the null terminator is found
    //for (int i = 0; ; i++) {
    //    // Print the character, its ASCII value, and its memory address
    //    printf("   '%c'    |     %d      | %p\n", myString[i], myString[i], (void*)&myString[i]);

    //    // Stop when the null terminator is reached
    //    if (myString[i] == '\0') {
    //        break;
    //    }
    //}
  /*  for (int i = 0; ; i++)
    {
        printf("%c", myString[i]);

        if (*(myString + i) == '\0')
        {
            break;
        }

    }*/
    return 0;
}