#include "scan-printEquipment.h"

void inputGeneral(Equipment* arr, int& size) {
	printf("¬ведите массив структур:\n");
	int g = 0;
	for (int i = 0; i < 100; ++i) {
		scanEquipment(arr[i], i); ++size;
		g = inputNatural("1 - продолжить, 2 - завершить ввод\n");
		while (g != 1 && g != 2) {
			printf("Error! Try again\n");
			g = inputNatural("1 - продолжить, 2 - завершить ввод\n");
		}
		if (g == 2)
			break;
	}
}