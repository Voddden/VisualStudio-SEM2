#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
//#define _CRT_SECURE_NO_WARNINGS

/* В-7
 * 1. С клавиатуры заполнить файл целыми числами.*/

int hasLetters(char* str) {
    for (int i = 0; str[i] != '\0'; ++i)
        if (!('0' <= str[i] && str[i] <= '9' || str[i] == ' '))
            return 1;
    return 0;
}

int main(int argc, char* argv[])
{
    int length = 100;
    char* message = (char*)malloc(length);
    printf("Enter integer numbers:");
    gets_s(message, length);
    if (hasLetters(message)) {
        perror("Error! Letters are not allowed");
        return 1;
    }
    fflush(stdin);
    FILE* fp;
    fp = (FILE*)fopen_s(&fp, argv[1], "w");
    if (fp)
    {
        // посимвольно записываем в файл
        for (int i = 0; message[i] != '\0'; i++)
        {
            putc(message[i], fp);
        }
        fclose(fp);
        printf("File has been written\n");
    }
    else {
        perror("Null pointer reference");
    }
}