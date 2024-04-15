#include <stdio.h>
#include "labba.c"

void NormalStrTest(){
    String str = CreateString(4);
    String ResStr;
    str.data[0] = 'a';
    str.data[1] = 'b';
    str.data[2] = 'c';
    str.data[3] = 'd';
    ResStr = SubString(&str, 1, 3);

    printf("\nTest for a normal not empty string(length = 4, substring = string[1, 3]): \n\n");

    printf("\nInitial string: \n\n");
    PrintString(&str);
    printf("\nResult: \n\n");
    PrintString(&ResStr);
}

void TestWithIndexOutOfRange(){
    String str = CreateString(4);
    str.data[0] = 'a';
    str.data[1] = 'b';
    str.data[2] = 'c';
    str.data[3] = 'd';
    String ResStr = SubString(&str, 1, 7);

    printf("\nTest for a normal not empty string but with substring index out of range(length of init string = 4, substring = string[1, 6]): \n\n");

    printf("\nInitial string: \n\n");
    PrintString(&str);
    printf("\nResult: \n\n");
    PrintString(&ResStr);
}

void TestWithTranposedIndexies(){
    String str = CreateString(4);
    str.data[0] = 'a';
    str.data[1] = 'b';
    str.data[2] = 'c';
    str.data[3] = 'd';
    String ResStr = SubString(&str, 3,  1);

    printf("\nTest for a normal not empty string but with substring indexies reversed(length of init string = 4: \n\n");

    printf("\nInitial string: \n\n");
    PrintString(&str);
    printf("\nResult: \n\n");
    PrintString(&ResStr);
}


int main(){
    NormalStrTest();
    TestWithIndexOutOfRange();
    TestWithTranposedIndexies();
}