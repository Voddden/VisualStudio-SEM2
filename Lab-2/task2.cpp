#define _CRT_SECURE_NO_WARNINGS
#include "tasks.h"

/*
2. Определить максимальное число, записанное в файле (если таких чисел
несколько, вывести все)
*/

void task2(FILE* fp, char* filename) {
	fp = fopen(filename, "rb");

	int length = countNumbers(fp, filename);

	int* arr = (int*)malloc(length * sizeof(int));
	for (int i = 0; i < length; ++i) {
		fscanf(fp, "%d", &arr[i]);
	}
}