#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "tasks.h"
void check(FILE* fp) {
    if (fp == NULL) {
        printf("Null pointer error\n");
        exit(1);
    }
}

void write(FILE* fp, const char* str) {
    int length = 100;
    char* message = (char*)malloc(length);
    //printf("Enter integer numbers: ");
    //gets_s(message, length);
    strcpy(message, "12345");
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
}


int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ru");
    // создание файла
    
    FILE* file = fopen(argv[1], "r");
    check(file);

    //char* Default = (char*)malloc(100);
    //strcpy(Default, "13 202 912 11");
    //fflush(stdin);
    //for (int i = 0; Default[i] != '\0'; i++)
    //{
    //    putc(Default[i], file);
    //}
    //write(file, "12345");

    //// вывод изначального файла в консоль:
    //file = freopen(argv[1], "r", file);
    printf("Файл по умолчанию: ");
    char c;
    while ((c = getc(file)) != EOF)
    {
        printf("%c", c);
    }
    printf("\n");

    //// работа с файлом:
    //file = freopen(argv[1], "w", file);
    // задача1: С клавиатуры заполнить файл целыми числами
    //task1(file);
    // задача2: Подсчитать сумму чётных чисел
    //task2(file);
    // задача3: Удалить все чётные числа
    //task3(file);
    // задача4: Отсортировать только числа большие заданного (по убыванию)
    //task4(file);
    ////
    
    // вывод преобразованного файла в консоль:
    //file = freopen(argv[1], "r", file);
    printf("Файл после вызова функций: ");
    char ch;
    while ((ch = getc(file)) != EOF)
    {
        printf("%c", ch);
    }
    printf("\n");

    fclose(file);
}