#include <stdio.h>
#include "labba.c"

void EncodeForEmpty(){
    String str = CreateString(0);
    printf("\nTest for an empty string with Reverse encoding function(ReverCode): \n\n");
    String ResStr = EncodeString(ReverCode ,&str);
    printf("\nInitial string: \n\n");
    PrintString(&str);
    printf("\nResult: \n\n");
    PrintString(&ResStr);
}

void EncodeForNotEmpty(){
    String str = CreateString(4);
    str.data[0] = 'a';
    str.data[1] = 'b';
    str.data[2] = 'c';
    str.data[3] = 'd';
    String ResStr = EncodeString(ReverCode, &str);

    printf("\nInitial string: \n\n");
    PrintString(&str);
    printf("\nResult: \n\n");
    PrintString(&ResStr);
}

int main(){
    EncodeForEmpty();
    EncodeForNotEmpty();
}