#include "sortEquipment.h"
#include "swapEquipment.h"

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

}