#define _CRT_SECURE_NO_WARNINGS
#include "tasks.h"

/* В-7
 * 1. С клавиатуры заполнить файл целыми числами.*/

bool inputIsInvalid(char* str) {
    for (int i = 0; str[i] != '\0'; ++i)
        if (!('0' <= str[i] && str[i] <= '9' || str[i] == ' ' || str[i] == '\n'))
            return true;

    for (int i = 1; str[i] != '\0'; ++i) {
        if (str[i] == ' ' && str[i - 1] == ' ' || str[i] == '\n' && str[i-1] == '\n')
            return true;
    }

    return false;
}

void task1(FILE* fp, char* filename) {
    fp = fopen(filename, "w");


    int length = 100;
    char* message = (char*)malloc(length);
    printf("task1 - Enter integer numbers: ");
    gets_s(message, length);
    if (inputIsInvalid(message)) {
        printf("Invalid input! Try again\n");
        exit(1);
    }

    for (int i = 0; message[i] != '\0'; i++) {
        putc(message[i], fp);
    }

    //printf("\nFile has been written\n\n");

    fclose(fp);
}