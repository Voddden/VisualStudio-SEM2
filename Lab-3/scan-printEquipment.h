#pragma once
#include "EquipmentType.h"

void print(Equipment equipment) {
	printf("id = %ld\nname = %s\ntype = %s\nquantity = %d\ndate = %s\n",
		equipment.id, equipment.name, equipment.type, equipment.quantity, equipment.date);
}

void printList(Equipment* list, const int size) {
	puts("Full list printing:");
	for (int i = 0; i < size; ++i) {
		printf("=============== list[%d]\n", i);
		print(list[i]);
		puts("===============");
	}
}

void swap(Equipment a1, Equipment a2) {
	int id_temp = a1.id;
	a1.id = a2.id;
	a2.id = id_temp;
	char name_temp[100];
	strcpy(name_temp, a1.name);
	strcpy(a1.name, a2.name);
	strcpy(a2.name, name_temp);
}