#pragma once
#include "EquipmentType.h"
void add(Equipment* list, int& size, int _id, const char* _name, const  char* _type, unsigned _quantity, const char* _date) {
	++size;
	list[size - 1].id = 123;
	strcpy(list[size - 1].name, _name);
	strcpy(list[size - 1].type, _type);
	list[size - 1].quantity = _quantity;
	strcpy(list[size - 1].date, _date);
}