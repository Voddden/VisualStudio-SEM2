#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
13) Пейнтбол. Содержится информация об оборудовании для игр — id, название, тип,
количество на складе, дата последней проверки. 

Проверить наличие на складе определенного
оборудования по неполному названию. Определить оборудование для проверки.

1.Реализовать все необходимые функции для использования типа данных —
добавление новой записи, вывод информации, изменение существующей записи,
удаление существующей записи, сортировка по каждому из полей структуры

2.Добавить перечисление и одновременную сортировку по нескольким параметрам
*/

struct Equipment {
	unsigned long long id = 0;
	char name[50] = "blank";
	char type[50] = "blank";
	int quantity = 0;
	char date[50] = "blank";
};

void Print(Equipment equipment) {
	printf("id = %ld\nname = %s\ntype = %s\nquantity = %d\ndate = %s\n",
		equipment.id, equipment.name, equipment.type, equipment.quantity, equipment.date);
}

bool availableInSorage(Equipment equipment) {
	return equipment.quantity;
}

void input(Equipment equipment) {

}

void main() {
	Equipment arr[100];

	arr[0]{24655, "ChillZone", "Important", 10, "02/05/2022"};
	//input(equipment);
	//if (availableInSorage(equipment)) {
	//	printf("equipment is available\n");
	//}
	//else {
	//	printf("equipment isn't available\n");
	//}
	


}