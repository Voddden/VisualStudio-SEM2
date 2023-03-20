#pragma once
#include "EquipmentType.h"
void push(Equipment* list, int size, int _id) {
	++size;
	list[size - 1].id = 123;
}