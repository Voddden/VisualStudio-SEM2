#define _CRT_SECURE_NO_WARNINGS
#include "tasks.h"

/*
2. Посчитать сумму чётных чисел.
*/

int countNumbers(FILE* fp) {
	fseek(fp, 0, SEEK_SET);
	char c;
	int res = 0;
	while ((c = getc(fp)) != EOF) {
		if (c == ' ' || c == '\n')
			++res;
	}
	fseek(fp, 0, SEEK_SET);
	return (res + 1);
}

void task2(FILE* fp, char* filename) {
	fp = fopen(filename, "r");

	int length = countNumbers(fp);

	int* arr = (int*)malloc(length * sizeof(int));
	for (int i = 0; i < length; ++i) {
		fscanf(fp, "%d", &arr[i]);
	}

	int sum = 0;
	for (int i = 0; i < length; ++i) {
		if (arr[i] % 2 == 0) {
			sum += arr[i];
		}
	}
	printf("task2: сумма = %d", sum);
	
	fclose(fp);
}