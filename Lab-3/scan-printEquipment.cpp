#define _CRT_SECURE_NO_WARNINGS
#include "EquipmentType.h"
#include "..\ValidationLib\Validation.h"

bool invalidDate(char* str) { // ��.��.����
	char valid[] = "��.��.����";

	char s[100] = {};
	strcpy(s, str);
	s[0] = '�'; s[1] = '�'; 
	s[3] = '�'; s[4] = '�'; 
	s[6] = '�'; s[7] = '�'; s[8] = '�'; s[9] = '�';
	for (int i = 0; i <= 10; ++i) {
		if (s[i] != valid[i])
			return true;
	}
	return false;
}

void scanEquipment(Equipment& e, int i) {
	printf("list[%d].id = ", i); e.id = inputInteger(""); 
	printf("list[%d].name = ", i); gets_s(e.name, 100);
	printf("list[%d].type = ", i); gets_s(e.type, 100);
	printf("list[%d].quantity = ", i); e.quantity = inputNaturalAnd0("");

	printf("������: ��.��.���\nlist[%d].date = ", i);
	gets_s(e.date, 100);
	while (invalidDate(e.date)) {
		printf("Error. Try again\n");

		printf("������: ��.��.���\nlist[%d].date = ", i);
		gets_s(e.date, 100);
	}
	fflush(stdin);
	rewind(stdin);
}

void inputGeneral(Equipment* list, int& size) {
	printf("������� ������ ��������:\n");
	int g = 0;
	for (int i = 0; i < 100; ++i) {
		scanEquipment(list[i], i); ++size;
		g = inputNatural("1 - ����������, 2 - ��������� ����\n");
		while (g != 1 && g != 2) {
			printf("Error! Try again\n");
			g = inputNatural("1 - ����������, 2 - ��������� ����\n");
		}
		if (g == 2)
			break;
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
	puts("Full list printing:");
	for (int i = 0; i < size; ++i) {
		printf("=============== list[%d]\n", i);
		printEquipment(list[i]);
		puts("===============");
	}
}