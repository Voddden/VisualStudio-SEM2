#define _CRT_SECURE_NO_WARNINGS
#include "tasks.h"

/*
2. Посчитать сумму чётных чисел.
*/

int numberCount(FILE* input) {
	fseek(input, 0, SEEK_SET);
	int counter = 0;
	while (true) {
		int value;
		if (fscanf(input, "%d", &value) == 1)
			counter++;
		if (feof(input))
			break;
	}
	return counter;
}

void read_numbers(FILE* input, int size, int* numbers) {
	fseek(input, 0, SEEK_SET);
	for (int i = 0; i < size; ++i) {
		fscanf(input, "%d", &numbers[i]);
	}
}

void task2(FILE* fp) {

	int length = numberCount(fp);
	int* arr = (int*)malloc(length*sizeof(int));
	read_numbers(fp, length, arr);

}