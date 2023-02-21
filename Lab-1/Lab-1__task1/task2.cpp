#define _CRT_SECURE_NO_WARNINGS
#include "tasks.h"

/*
2. Посчитать сумму чётных чисел.
*/

int arrLength(FILE* fp) {
	int size = 0, y;

	while (!feof(fp))
	{
		int z = fscanf(fp, "%d", &y);
		if (!z)
			continue;
		size++;
	}
	return size;
}

void task2(FILE* fp) {
	int size = arrLength(fp);
	int* arr = (int*)calloc(size, sizeof(int));

	rewind(fp);

	for (int i = 0; i < size; i++)
		fscanf(fp, "%d", &arr[i]);

	for (int i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
}