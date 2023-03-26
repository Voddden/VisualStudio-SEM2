#define _CRT_SECURE_NO_WARNINGS
#include "addEquipment.h"
#include "scan-printEquipment.h"
#include "editEquipment.h"
#include "deleteEquipment.h"
#include "sortEquipment.h"
#include "..\ValidationLib\Validation.h"
#include "hasInventory.h"

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

void main() 
{
	setlocale(LC_ALL, "ru");
	Equipment list[100] = {}; int size = 0;

	add(list, size, 1, "watergun", "very splashy", 10, "08.03.2003");
	add(list, size, 2, "gun", "lasertype", 4, "09.03.2023");
	add(list, size, 3, "shovel", "pocket edition", 3, "05.03.1995");
	add(list, size, 4, "computer", "Asus", 50, "01.03.1945");
	add(list, size, 5, "lamp", "kinda cute", 6, "07.03.2023");

	if (hasInventory("water")) {

	}
	else {
		printf("Такого оборудования в наличии нет\n");
	}

	//sortByDate(list, size);

	printList(list, size);

}