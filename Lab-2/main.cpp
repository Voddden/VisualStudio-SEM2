#define _CRT_SECURE_NO_WARNINGS
#include "tasks.h"

char filename[100];

void checkF(FILE* fp) {
    if (fp == NULL) {
        printf("Null pointer error\n");
        exit(1);
    }
}



void main(int argc, char* argv[]) {
    strcpy(filename, argv[1]);
    setlocale(LC_ALL, "ru");
    // создание файла
    FILE* fp = fopen(argv[1], "w");
    checkF(fp);
    fputs("1 -14 0 3 -59 7 0", fp); // значения по умолчанию

    //// вывод изначального файла в консоль
    printf("Файл по умолчанию: ");
    printFile(fp, filename);

    fclose(fp);

    //// работа с файлом:

    // задача1: С клавиатуры заполнить файл числами. Вывести содержимое файла на экран
    task1(fp, argv[1]);
    // задача2: Определить максимальное число, записанное в файле (если таких чисел несколько, вывести все).
    //task2(fp, argv[1]); printf("\n");
    // задача3: Перевернуть в файле число, номер которого задан с клавиатуры.
    //task3(fp, argv[1]);
    ////

    puts("\n");
}