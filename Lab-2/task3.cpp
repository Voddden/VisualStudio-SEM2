#define _CRT_SECURE_NO_WARNINGS
#include "tasks.h"

/*
3. Перевернуть в файле число, номер которого задан с клавиатуры.
*/

int number_digits(int n)
{
	int count = 0;
	while (n) {
		n /= 10;
		count++;
	}

	return count;
}

void flip(int num, char* res) {
	
}

void task3(FILE* fp, char* filename) {
	fp = fopen(filename, "r");

	int length = countNumbers(fp, filename);
	int* arr = (int*)malloc(length * sizeof(int));
	for (int i = 0; i < length; ++i) {
		fscanf(fp, "%d", &arr[i]);
	}

	fclose(fp);

	int n = inputNatural("Введите номер числа для переворота: ");

	//arr[n - 1] = flip(arr[n - 1]);

	char flipRes[100];
	flip(arr[n-1], flipRes);
	int numDigits = number_digits(arr[n - 1]);
	flipRes[numDigits] = '\0';

	fp = fopen(filename, "w");
	for (int i = 0; i < length; ++i) {
		if (i == n - 1) {
			//fprintf(fp, "%s", flipRes);
			for (int j = 0; j < numDigits; ++j) {
				putc(flipRes[j] + 48, fp);
				//putc(' ', fp);
			}
			continue;
		}
		fprintf(fp, "%d ", arr[i]);
	}
	fclose(fp);

	printf("Переверот %d-го числа в файле: ", n);
	printFile(fp, filename);
}