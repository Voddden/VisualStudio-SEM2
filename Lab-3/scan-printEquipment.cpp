#define _CRT_SECURE_NO_WARNINGS
#include "EquipmentType.h"
#include "..\ValidationLib\Validation.h"

bool invalidDate(char* str) { // ฤฤ.ฬฬ.รรรร
	char valid[] = "ฤฤ.ฬฬ.รรรร";

	char s[100] = {};
	strcpy(s, str);
	s[0] = 'ฤ'; s[1] = 'ฤ'; 
	s[3] = 'ฬ'; s[4] = 'ฬ'; 
	s[6] = 'ร'; s[7] = 'ร'; s[8] = 'ร'; s[9] = 'ร';
	for (int i = 0; i <= 10; ++i) {
		if (s[i] != valid[i])
			return true;
	}
	return false;
}

void scanEquipment(Equipment e, int i) {
	printf("list[%d].id = ", i); e.id = inputInteger("");
	printf("list[%d].name = ", i); scanf("%s", &e.name);
	printf("list[%d].type = ", i); scanf("%s", &e.type);
	printf("list[%d].quantity = ", i); e.quantity = inputNaturalAnd0("");

	printf("list[%d].date = ", i);
	scanf("%s", &e.date);
	while (invalidDate(e.date)) {
		printf("Error. Try again\n");

		printf("list[%d].date = ", i);
		scanf("%s", &e.date);
	}
}

void scanList(Equipment* stack, int& size) {
	for (int i = 0; i < size; ++i) {
		printf("list[%d].id = ", i); stack[i].id = inputInteger("1");
		printf("list[%d].name = ", i); scanf("%s", &stack[i].name);
		printf("list[%d].type = ", i); scanf("%s", &stack[i].type);
		printf("list[%d].quantity = ", i); stack[i].quantity = inputNaturalAnd0("1");

		printf("list[%d].date = ", i); 
		scanf("%s", &stack[i].date);
		while(invalidDate(stack[i].date)) {
			printf("Error. Try again\n");
			scanf("%s", &stack[i].date);
		}
	}
}

void printEquipment(Equipment equipment) {
	printf("id = %ld\nname = %s\ntype = %s\nquantity = %d\ndate = %s\n",
		equipment.id, equipment.name, equipment.type, equipment.quantity, equipment.date);
}

void printList(Equipment* list, const int size) {
	puts("Full stack printing:");
	for (int i = 0; i < size; ++i) {
		printf("=============== list[%d]\n", i);
		printEquipment(list[i]);
		puts("===============");
	}
}