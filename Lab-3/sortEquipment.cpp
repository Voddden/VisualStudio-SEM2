#include "sortEquipment.h"
#include "swapEquipment.h"
#include "daysInMonth.h"

void sortById(Equipment* list, const int size) {
	for (int a = 0; a < size - 1; ++a)
		for (int b = 0; b < size - 1 - a; ++b)
			if (list[b].id > list[b + 1].id)
				swapEquipment(list[b], list[b + 1]);
}

void sortByName(Equipment* list, const int size) {
	for (int a = 0; a < size - 1; ++a)
		for (int b = 0; b < size - 1 - a; ++b)
			if (strcmp(list[b].name, list[b + 1].name))
				swapEquipment(list[b], list[b + 1]);
}

void sortByType(Equipment* list, const int size) {
	for (int a = 0; a < size - 1; ++a)
		for (int b = 0; b < size - 1 - a; ++b)
			if (strcmp(list[b].type, list[b + 1].type))
				swapEquipment(list[b], list[b + 1]);
}

void sortByQuantity(Equipment* list, const int size) {
	for (int a = 0; a < size - 1; ++a)
		for (int b = 0; b < size - 1 - a; ++b)
			if (list[b].quantity > list[b + 1].quantity)
				swapEquipment(list[b], list[b + 1]);
}



void sortByDate(Equipment* list, const int size) {
	// идея: перевести все даты в списке на кол-во дней от рождения Христа
	// для простоты, 
	int day = 0, month = 0, year = 0;
	day += ((int)list->date[0] - 48) * 10;
	day += ((int)list->date[1] - 48);

	month += ((int)list->date[3] - 48) * 10;
	month += (int)list->date[4] - 48;

	year += (int)list->date[6] - 48; 
	year += ((int)list->date[7] - 48) * 10; 
	year += ((int)list->date[8] - 48) * 100; 
	year += ((int)list->date[9] - 48) * 1000;

	int* days = (int*)calloc(size, sizeof(int));
	for (int i = 0; i < size; ++i) {
		days[i] += day;
		days[i] += month * daysInMonth(month);
		days[i] += year * 12 * daysInMonth(month);
	}
}