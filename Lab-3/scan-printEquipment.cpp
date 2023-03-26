#define _CRT_SECURE_NO_WARNINGS
#include "EquipmentType.h"
#include "..\ValidationLib\Validation.h"

bool invalidDate(char* str) { // ��.��.����
	char s[100];
	strcpy(s, str);
	s[0] = '�'; s[1] = '�'; 
	s[3] = '�'; s[4] = '�'; 
	s[6] = '�'; s[7] = '�'; s[8] = '�'; s[9] = '�';
	int res = strcmp(str, s);
	if (res != 0)
		return true;
	else
		return false;
}

void scanEquipment(Equipment* stack, int size) {
	for (int i = 0; i < size; ++i) {
		printf("list[%d].id = ", i); stack[i].id = inputInteger("");
		printf("list[%d].name = ", i); scanf("%s", &stack[i].name);
		printf("list[%d].type = ", i); scanf("%s", &stack[i].type);
		printf("list[%d].quantity = ", i); stack[i].quantity = inputNaturalAnd0("");

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