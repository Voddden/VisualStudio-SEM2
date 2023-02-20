#define _CRT_SECURE_NO_WARNINGS

#include "tasks.h"

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ru");
    // создание файла
    
    //FILE* file;
    //errno_t err = fopen_s(&file, argv[1], "w");
    FILE* file = fopen(argv[1], "w");
    if (file == NULL) {
        printf("Error\n");
        return 1;
    }

    //// вывод изначального файла в консоль:
    //err = freopen_s(&file, argv[1], "r", file);
    printf("Файл по умолчанию: ");
    char c;
    while ((c = getc(file)) != EOF)
    {
        printf("%c", c);
    }
    printf("\n");

    //// работа с файлом:
   // err = freopen_s(&file, argv[1], "w", file);
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
    //err = freopen_s(&file, argv[1], "r", file);
    printf("Файл после преобразования: ");
    char ch;
    while ((ch = getc(file)) != EOF)
    {
        printf("%c", ch);
    }
    printf("\n");

    fclose(file);
}