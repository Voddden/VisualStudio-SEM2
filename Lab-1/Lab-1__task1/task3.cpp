#define _CRT_SECURE_NO_WARNINGS
#include "tasks.h"

/*
3. ������� ��� ������ �����.
*/

void printFile1(FILE* fp, char* filename) {
	fp = freopen(filename, "rb", fp);
	char c;
	while ((c = getc(fp)) != EOF)
	{
		printf("%c", c);
	}
	//printf("\n");
	fseek(fp, 0, SEEK_SET);
}

int numOdd(const int* arr, const int length) {

	int res = 0;
	for (int i = 0; i < length; ++i) {
		if (abs(arr[i]) % 2 == 1)
			++res;
	}
	return res;
}

void task3(FILE* fp, char* filename) {
	fp = fopen(filename, "rb");

	int length = countNumbers(fp);

	int* arr = (int*)malloc(length * sizeof(int)); // ������ ���� �����
	for (int i = 0; i < length; ++i) {
		fscanf(fp, "%d", &arr[i]);
	}
	fclose(fp);


	int length1 = numOdd(arr, length); // ���--�� �������� �����

	int* arr1 = (int*)malloc(length1 * sizeof(int)); // ������ �������� �����
	
	int k = 0;
	for (int i = 0; i < length; ++i) {
		if (abs(arr[i]) % 2 == 1) {
			arr1[k] = arr[i];
			++k;
		}
	}

	fp = fopen(filename, "wb");

	for (int i = 0; i < length1; ++i) {
		fprintf(fp, "%d", arr1[i]);
		if (i == length1 - 1)
			continue;
		fprintf(fp, " ");
	}

	fclose(fp);

	printf("task3 - �������� ������ �����: ");
	printFile1(fp, filename);
}