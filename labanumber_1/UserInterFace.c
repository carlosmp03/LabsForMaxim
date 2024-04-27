#include <stdio.h>
#include <stdlib.h>
#include "labba.c" 

int main() {
    int option;
    int size1, size2;
    String str1, str2;

    printf("\nWelcome to the UserInterface.\n");
    printf("\nPlease Enter the size of the first and second string with a space in between: \n");
    scanf("%d %d", &size1, &size2);

    str1 = CreateString(size1);
    printf("\nPlease Enter the First string:\n");
    for (int i = 0; i < str1.len; ++i) {
        char c;
        scanf(" %c", &c);
        str1.data[i] = c;
    }

    printf("\nPlease Enter the Second string:\n");
    str2 = CreateString(size2);
    for (int i = 0; i < str2.len; ++i) {
        char c;
        scanf(" %c", &c);
        str2.data[i] = c;
    }

    do {
        printf("\nPlease select an option:\n");
        printf("1. Concatenate strings and print\n");
        printf("2. Encode strings and print\n");
        printf("3. Extract and print substrings\n");
        printf("4. Exit\n");

        scanf("%d", &option);

        switch (option) {
            case 1: {
                String NewString = Concat(&str1, &str2);
                printf("\nConcatenated String:\n");
                PrintString(&NewString);
                free(NewString.data);
                break;
            }
            case 2: {
                String encodedStr1 = EncodeString(ReverCode, &str1);
                String encodedStr2 = EncodeString(ReverCode, &str2);

                printf("\nEncoded String 1:\n");
                PrintString(&encodedStr1);

                printf("\nEncoded String 2:\n");
                PrintString(&encodedStr2);

                free(encodedStr1.data);
                free(encodedStr2.data);
                break;
            }
            case 3: {
                int i, j;
                printf("\nEnter the starting index for substring 1: ");
                scanf("%d", &i);
                printf("Enter the ending index for substring 1: ");
                scanf("%d", &j);
                String substr1 = SubString(&str1, i, j);
                printf("\nSubstring 1:\n");
                PrintString(&substr1);
                free(substr1.data);

                printf("\nEnter the starting index for substring 2: ");
                scanf("%d", &i);
                printf("Enter the ending index for substring 2: ");
                scanf("%d", &j);
                String substr2 = SubString(&str2, i, j);
                printf("\nSubstring 2:\n");
                PrintString(&substr2);
                free(substr2.data);
                break;
            }
            case 4:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    } while (option != 4);

    free(str1.data);
    free(str2.data);

    return 0;
}
