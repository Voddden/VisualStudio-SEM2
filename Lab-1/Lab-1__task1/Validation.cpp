#include "Validation.h"

#include <stdio.h>
#include <stdlib.h>

double Pow(long num, long deg) {
    double result = 1;

    if (deg < 0) {
        deg = -deg;
        for (long i = 0; i < deg; i++) {
            result *= num;
        }

        return 1 / result;
    }
    else {
        for (long i = 0; i < deg; i++) {
            result *= num;
        }

        return result;
    }
}

double parseFractPartToDouble(const char* str) {
    int g = 0;
    while (str[g] != '.' && str[g] != ',' && str[g] != '\0') ++g;
    int whole_digits = g; // ���-�� ���� � ����� �����
    int u = g;
    for (; str[u] != '\0'; ++u);
    int all_digits = u - 1; // ���-�� ���� ������ � �����
    int fract_digits = all_digits - whole_digits; // ���-�� ���� � ������� �����

    int arr_int_size = fract_digits;
    int* arr_int = (int*)malloc(arr_int_size * sizeof(int));
    for (int i = 0; i < arr_int_size; ++i) {
        arr_int[i] = str[i + whole_digits + 1] - 48;
    }

    double result = 0;
    int razryad = -1;
    for (int i = 0; i < arr_int_size; ++i) {
        result += arr_int[i] * Pow(10, razryad);
        --razryad;
    }
    free(arr_int);
    return result;
}

double parseWholePartToDouble(const char* str) {
    int g = 0;
    while (str[g] != '.' && str[g] != ',' && str[g] != '\0') ++g; // g = ���������� ���� � ����� �����

    int arr_int_size = g;
    int* arr_int = (int*)malloc(arr_int_size * sizeof(int));
    for (int i = 0; i < arr_int_size; ++i) {
        arr_int[i] = str[i] - 48;
    }
    double result = 0;

    int razryad = arr_int_size - 1;
    for (int i = 0; i < arr_int_size; ++i) {
        result += arr_int[i] * Pow(10, razryad);
        --razryad;
    }
    free(arr_int);
    return result;
}

bool inputIsInvalidDueToDigitAbsence(const char* str) {
    int num_of_digits = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if ('0' <= str[i] && str[i] <= '9')
        {
            ++num_of_digits;
        }
    }
    if (num_of_digits == 0)
        return true;
    else
        return false;
}

bool inputIsInvalidDueToMinuses(const char* str) {
    for (int i = 1; str[i] != '\0'; ++i) {
        if (str[i] == '-')
            return true;
    }
    return false;
}

bool inputIsInvalidDueToSeparators(const char* str) {
    int number_of_separators = 0;
    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] == '.' || str[i] == ',')
            ++number_of_separators;
    if (number_of_separators > 1)
        return true;
    else
        return false;
}

bool inputIsInvalidDueToLetters(const char* str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' &&
            str[i] != '3' && str[i] != '4' && str[i] != '5' &&
            str[i] != '6' && str[i] != '7' && str[i] != '8' &&
            str[i] != '9' && str[i] != '.' && str[i] != ',' && str[i] != '-')
        {
            return true;
        }
    }
    return false;
}

double inputReal(const char* prompt) {
    const int length = 100;
    char input[length] = {};
    //system("cls");
    rewind(stdin);
    printf("%s", prompt);

    //gets_s(input, length);
    gets_s(input, length);

    // ����� ����������� �������
    while (inputIsInvalidDueToLetters(input) ||
        inputIsInvalidDueToSeparators(input) ||
        inputIsInvalidDueToMinuses(input) ||
        inputIsInvalidDueToDigitAbsence(input))
    {
        //system("cls");
        printf("Error. Try again\n%s", prompt);
        //gets_s(input, length);
        gets_s(input, length);
    }

    char input_unsigned[length] = {};
    bool numIsSigned = false;

    if (input[0] == '-') {
        for (int i = 0; i < length - 1; ++i) {
            input_unsigned[i] = input[i + 1];
        }
        numIsSigned = true;
    }
    else {
        for (int i = 0; i < length; ++i) {
            input_unsigned[i] = input[i];
        }
    }

    double res = 0;
    // ������� ����� �����:
    res += parseWholePartToDouble(input_unsigned);
    // ������� ������� �����:
    res += parseFractPartToDouble(input_unsigned);
    //������������ �����:
    if (numIsSigned)
        res *= -1;

    return res;
}

double inputRealPositive(const char* prompt) {
    double res = inputReal(prompt);
    while (res <= 0) {
        //system("cls");
        printf("Error. Try again\n");
        res = inputReal(prompt);
    }
    return res;
}

int inputInteger(const char* prompt) {
    double res = inputReal(prompt);
    while ((int)res != res) {
        printf("Error. Try again\n");
        res = inputReal(prompt);
    }
    return (int)res;
}

int inputNatural(const char* prompt) {
    double res = inputReal(prompt);
    while (res <= 0 || (int)res != res) {
        //system("cls");
        printf("Error. Try again\n");
        res = inputReal(prompt);
    }
    return (int)res;
}