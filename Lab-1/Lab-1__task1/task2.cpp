#include "tasks.h"

/*
2. Посчитать сумму чётных чисел.
*/

void task2(FILE* fp) {
	const int length = 10;
	char* str[length];
	if (fread(str, sizeof(int), length, fp) != length) {
		if (feof(fp)) 
			printf("Premature end of file.");
		else 
			printf("File read error.");
	}

}