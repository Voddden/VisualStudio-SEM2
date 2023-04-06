#define _CRT_SECURE_NO_WARNINGS
#include "addEquipment.h"

void add(Equipment* list, int& size, int _id, const char* _name, unsigned _quantity, const char* _date) {
	++size;
	list[size - 1].id = _id;
	strcpy(list[size - 1].name, _name);
	
	list[size - 1].quantity = _quantity;
	strcpy(list[size - 1].date, _date);

	switch (inputNatural("1 - "))
	{
	default:
		break;
	}
}

void scanEquipment(Equipment& e, int i) {
	printf("list[%d].id = ", i); e.id = inputInteger("");
	printf("list[%d].name = ", i); gets_s(e.name, 100);
	//printf("list[%d].type = ", i); gets_s(e.type, 100);
	printf("list[%d].quantity = ", i); e.quantity = inputNaturalAnd0("");
	printf("формат: ДД.ММ.ГГГГ\nlist[%d].date = ", i);
	gets_s(e.date, 100);
	while (invalidDate(e.date)) {
		printf("Error. Try again\n");
		gets_s(e.date, 100);
	}
	fflush(stdin);
	rewind(stdin);

	switch (inputNatural("1 - скорострельность, вес, подтип. 2 - назначение стоимость\n")) {
	case 1:
		break;
	case 2:
		break;
	default:

	}
}

void inputGeneral(Equipment* arr, int& size) {
	printf("Введите массив структур:\n");
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