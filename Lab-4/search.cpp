#include "search.h"
#include "consoleOutput.h"

// ��� ������ ��������. � ������ ��������� ���� ���� "��������". ������������ ������ �������� �������� ��������. 
// ��������� ������ ������� ��� ���� ������� ������������� ���������

bool isSimiliar(const char* Name, const char* partName) {
	for (int i = 0; partName[i] != '\0'; ++i) {
		if (Name[i] != partName[i])
			return false;
	}
	return true;
}

int hasInventory(Equipment* arr, const int size, const char* partName) {
	for (int i = 0; i < size; ++i) {
		if (isSimiliar(arr[i].name, partName)) {
			return i + 1;
		}
	}
	return 0;
}

void search(Equipment* arr, const int size, int* unionType) {
	printf("\n---����� ������������ �� ��������� ��������---\n������� �������� ��������: ");
	char partName[100] = {};
	gets_s(partName, 100);
	while (strnlen(partName, 100) < 3) {
		printf("������! � �������� �������� ������ ���� ������� 3 �������: ");
		gets_s(partName, 100);
	}
	if (int index = hasInventory(arr, size, partName)) {
		printf("������������ � ����� ��������� ����������:\n");
		printEquipment(arr[index - 1], index, unionType);
	}
	else {
		printf("������ ������������ � ������� ���\n");
	}
}