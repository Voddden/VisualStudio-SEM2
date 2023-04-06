#define _CRT_SECURE_NO_WARNINGS
#include "EquipmentType.h"
#include "consoleInput.h"
#include "consoleOutput.h"
#include "defaultValues.h"

// id, название, тип, кол-во, дата
void main()
{
	setlocale(LC_ALL, "ru");
	Equipment arr[100] = {}; int size = 0;
	int unionType[100] = {};
	switch (inputNatural("1 - ввод с консоли, 2 - default значения\n")) {
	case 1:
		consoleInput(arr, size, unionType);
		break;
	case 2:
		defaultValues(arr, size, unionType);
		break;
	default:
		printf("Error! Invalid data"); exit(1);
	}
	
	printArr(arr, size, unionType);
}