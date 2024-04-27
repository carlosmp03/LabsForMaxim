#include <stdio.h>
#include "labba.c"
void TwoEmptyArraysTest(){
    String str1 = CreateString(0);
    String str2 = CreateString(0);
    String ResStr;
    printf("\nTest For 2 empty strings: \n");
    printf("\nFirst String: \n\n");
    PrintString(&str1);
    printf("\nSecond String: \n\n");
    PrintString(&str2);

    ResStr = Concat(&str1, &str2); 
    printf("\nResult: \n\n");
    PrintString(&ResStr);
}

void OneEmty(){
    String str1 = CreateString(0);
    String str2 = CreateString(4);
    String ResStr;
    str2.data[0] = 'a';
    str2.data[1] = 'b';
    str2.data[2] = 'c';
    str2.data[3] = 'd';
    
    printf("\nTest For 1 empty and 1 not empty strings: \n");
    printf("\nFirst String: \n\n");
    PrintString(&str1);
    printf("\nSecond String: \n\n");
    PrintString(&str2);

    ResStr = Concat(&str1, &str2); 
    printf("\nResult: \n\n");
    PrintString(&ResStr);
}

void TwoNotEmpty(){
    String str1 = CreateString(4);
    String str2 = CreateString(3);
    String ResStr;
    str1.data[0] = 'a';
    str1.data[1] = 'b';
    str1.data[2] = 'c';
    str1.data[3] = 'd';

    str2.data[0] = 'e';
    str2.data[1] = 'd';
    str2.data[2] = 'f';
    printf("Test For 2 not empty strings: \n");

    printf("\nFirst String: \n\n");
    PrintString(&str1);
    printf("\nSecond String: \n\n");
    PrintString(&str2);

    ResStr = Concat(&str1, &str2); 
    printf("\nResult: \n\n");
    PrintString(&ResStr);

}

int main(){
    TwoEmptyArraysTest();
    OneEmty();
    TwoNotEmpty();
}
