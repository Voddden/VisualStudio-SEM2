#define _CRT_SECURE_NO_WARNINGS
#include "tasks.h"

/*
2. ��������� ����� ������ �����.
*/

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
	printf("task2 - ����� ������ = %d", sum);
	
	fclose(fp);
}