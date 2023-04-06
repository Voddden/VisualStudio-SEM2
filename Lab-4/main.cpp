#include "EquipmentType.h"
#include "consoleInput.h"
#include "consoleOutput.h"
#include "defaultValues.h"

#include "vzyatieOstatka.h"
#include "search.h"
#include "sortEquipment.h"

/*
Реализовать операцию взятия остатка от деления на число, передаваемое через
командную строку(отдельная функция, отдельный union). 

Реализовать функции
поиска и 
сортировки информации по одному из новых свойств.
*/

// id, название, тип, кол-во, дата
void main(int argc, int* argv[])
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

	search(arr, size, unionType);

	printf("\n--- Сортировка ---\n");
	sortDate(arr, size, unionType);
	printf("Массив после сортировки:\n\n");
	printArr(arr, size, unionType);
}