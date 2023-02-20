#include "tasks.h"

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ru");
    // создание файла
    errno_t err;
    FILE* file;
    err = fopen_s(&file, argv[1], "w");
    if (file == NULL) {
        printf("Error\n");
        return 1;
    }

    // задача1: ввод чисел в файл
    task1(file);
    // задача2: вывод суммы четных чисел
    task2(file);
    // задача3: Удалить все чётные числа.
    task3(file);
    // задача4: Отсортировать только числа большие заданного по убыванию
    task4(file);

    // вывод файла в консоль
    fclose(file);
    err = fopen_s(&file, argv[1], "r");

    printf("Чтение из файла: ");
    char c;
    while ((c = getc(file)) != EOF)
    {
        printf("%c", c);
    }
    printf("\n");

    // закрытие файла
    fclose(file);
}