#include <stdlib.h>
#include <stdio.h>

struct String {
    int len;
    char* data;
};

typedef struct String String;

typedef char* (*EncodeFuncPtr)(const char*, int);

String CreateString(int len) {
    String str;
    str.len = len;
    str.data = (char*)malloc(sizeof(char) * len);
    if (str.data == NULL) {
        printf("\nMemory allocation error\n");
        exit(EXIT_FAILURE);
    }
    return str;
}

void PrintString(const String* str) {
    for (int i = 0; i < str->len; ++i) {
        printf("%c", str->data[i]);
    }
    printf("\n");
}

String Concat(const String* str1, const String* str2) {
    String NewString = CreateString(str1->len + str2->len);
    for (int i = 0; i < str1->len; ++i) {
        NewString.data[i] = str1->data[i];
    }
    for (int i = 0; i < str2->len; ++i) {
        NewString.data[i + str1->len] = str2->data[i];
    }
    return NewString;
}

char* ReverCode(const char* str, int len) {
    char* encodedStr = (char*)malloc(sizeof(char) * (len + 1));
    if (encodedStr == NULL) {
        printf("\nMemory allocation error\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < len; ++i) {
        encodedStr[i] = str[len - i - 1];
    }
    encodedStr[len] = '\0'; // Null-terminate the string
    return encodedStr;
}

String EncodeString(EncodeFuncPtr encodeFunc, const String* str) {
    String encodedStr;
    encodedStr.len = str->len;
    encodedStr.data = encodeFunc((const char*)str->data, str->len); // вызов функции кодирования
    return encodedStr;
}

String SubString(const String* str, int i, int j) {
    if (j < i) {
        String emptyString = CreateString(0);
        return emptyString;
    }

    if (i < 0) {
        i = 0;
    }

    if (j > str->len) {
        j = str->len;
    }

    String substr = CreateString(j - i);
    for (int index = i; index < j; ++index)
        substr.data[index - i] = str->data[index];
    return substr;
}

/*

int main() {
    String str1;
    String str2;
    String str3;
    String str4;
    str1 = CreateString(5);
    str2 = CreateString(5);
    str1.data[0] = 'c';
    str1.data[1] = 'h';
    str1.data[2] = 'a';
    str1.data[3] = 'r';
    str1.data[4] = ' ';
    str2.data[0] = 'i';
    str2.data[1] = 's';
    str2.data[2] = ' ';
    str2.data[3] = 'o';
    str2.data[4] = 'k';
    str3 = Concatenate(&str1, &str2);
    PrintString(&str3);

    str4 = SubString(&str3, -1, 2);
    PrintString(&str4);

    free(str1.data);
    free(str2.data);
    free(str3.data);

    return 0;
}
*/