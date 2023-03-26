#define _CRT_SECURE_NO_WARNINGS
#include "addEquipment.h"
#include "scan-printEquipment.h"
#include "editEquipment.h"
#include "deleteEquipment.h"
#include "sortEquipment.h"
#include "..\ValidationLib\Validation.h"

/*
13) Пейнтбол. Содержится информация об оборудовании для игр — 
id, 
название, (name)
тип, (type)
количество на складе,
дата последней проверки. 

Проверить наличие на складе определенного
оборудования по неполному названию. Определить оборудование для проверки.

1.Реализовать все необходимые функции для использования типа данных —
добавление новой записи, (add)
вывод информации, (print)
изменение существующей записи, (edit)
удаление существующей записи, (delete)
сортировка по каждому из полей структуры (sort)

2.Добавить перечисление и одновременную сортировку по нескольким параметрам
*/

void main() {
	setlocale(LC_ALL, "ru");
	Equipment list[100] = {}; int size = 0;

	//add(list, size, 100, "Agun", "lasertype", 4, "02/06/2004");
	//add(list, size, 5, "Bwatergun", "very splashy", 10, "25/1/2023");
	//add(list, size, 10, "Cshovel", "pocket edition", 3, "21/3/2022");
	
	printf("Введите массив структур:\n");
	int g = 0;
	for (int i = 0; i < 100; ++i) {
		scanEquipment(list[i], i);
		g = inputNatural("1 - продолжить, 2 - завершить ввод");
		while (g != 1 && g != 2) {
			printf("Error! Try again\n");
			g = inputNatural("1 - продолжить, 2 - завершить ввод");
		}
		if (g == 2)
			break;
	}
	

	

	//editEquipment(list, size, 1, 228, "toy tank", "expensive", 9, "20/2/2023");

	//deleteEquipment(list, size, 0);

	sortByName(list, size);

	printList(list, size);

	
}