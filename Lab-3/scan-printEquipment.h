#pragma once
#include "EquipmentType.h"

bool invalidDate(char* str);

void scanEquipment(Equipment* stack, int size);

void printEquipment(Equipment equipment);

void printList(Equipment* list, const int size);