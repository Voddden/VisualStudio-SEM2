#define _CRT_SECURE_NO_WARNINGS
#include "tasks.h"

/* В-7
 * 1. С клавиатуры заполнить файл целыми числами.*/

int hasLetters(char* str) {
    for (int i = 0; str[i] != '\0'; ++i)
        if (!('0' <= str[i] && str[i] <= '9' || str[i] == ' '))
            return 1;
    return 0;
}

void task1(FILE* fp, char* filename) {
    fp = fopen(filename, "w");

    int length = 100;
    char* message = (char*)malloc(length);
    printf("Enter integer numbers: ");
    gets_s(message, length);
    if (hasLetters(message)) {
        printf("Error! Letters are not allowed\n");
        exit(0);
    }
    fflush(stdin);

    for (int i = 0; message[i] != '\0'; i++)
    {
        putc(message[i], fp);
    }

    printf("\nFile has been written\n\n");

    fclose(fp);
}