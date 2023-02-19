#include <stdio.h>
#include <stdlib.h>
#include <locale>

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
    setlocale(LC_ALL, "ru");
    // создание и открытие файла
    errno_t err;
    FILE* file;
    err = fopen_s(&file, argv[1], "w");
    if (file == NULL) {
        printf("Error\n");
        return 1;
    }
    // запись строки целых чисел в файл
    int length = 100;
    char* message = (char*)malloc(length);
    printf("Enter integer numbers: ");
    gets_s(message, length);
    if (hasLetters(message)) {
        printf("Error! Letters are not allowed\n");
        return 1;
    }
    fflush(stdin);

    for (int i = 0; message[i] != '\0'; i++)
    {
        putc(message[i], file);
    }

    printf("\nFile has been written\n\n");

    //// вывод содержимого файла обратно в консоль

    // переоткрытие файла с режимом на чтение
    fclose(file);
    err = fopen_s(&file, argv[1], "r");

    printf("Чтение из файла: ");
    char c;
    while ((c = getc(file)) != EOF)
    {
        printf("%c", c);
    }
    printf("\n");
    fclose(file);
}