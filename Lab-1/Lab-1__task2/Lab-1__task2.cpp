﻿#include <stdio.h>
#include <stdlib.h>

/*
В-7
2.Посчитать сумму чётных чисел в файле
*/

int main(int argc, char* argv[])
{
    errno_t err;
    FILE* file;

    // Открытие (создание) файла для записи
    err = fopen_s(&file, argv[1], "w");
    if (err == 0)
    {
        printf("The file 'lab1-task2-file' was opened\n");
    }
    else
    {
        printf("error! nullptr");
    }
    // запись чисел в файл

    char msg[] = "1 2 3 4 5";
    for (int i = 0; msg[i] != '\0'; ++i) {
        putc(msg[i], file);
    }

    // считывание чисел из файла и вывод их суммы в консоль
    int g = 0;
    char c;
    char* nums = (char*)malloc(100);
    while ((c = getc(file)) != EOF)
    {
        arr[i] = c - 48;
        ++g;
    }
    nums[g] = '\0';

    // закрытие файла

    err = fclose(file);
}