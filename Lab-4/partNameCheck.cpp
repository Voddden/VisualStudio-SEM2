#include "partNameCheck.h"
#include "EquipmentType.h"
#include "scan-printEquipment.h"

// ��� ������ ��������. � ������ ��������� ���� ���� "��������". ������������ ������ �������� �������� ��������. 
// ��������� ������ ������� ��� ���� ������� ������������� ���������

bool isSimiliar(const char* Name, const char* partName) {
	for (int i = 0; partName[i] != '\0'; ++i) {
		if (Name[i] != partName[i])
			return false;
	}
	return true;
}

int hasInventory(Equipment* list, const int size, const char* partName) {
	for (int i = 0; i < size; ++i) {
		if (isSimiliar(list[i].name, partName)) {
			return i + 1;
		}
	}
	return 0;
}

void partNameCheck(Equipment* list, const int size) {
	printf("---����� ������������ �� ��������� ��������---\n������� �������� ��������: ");
	char partName[100] = {};
	gets_s(partName, 100);
	while (strnlen(partName, 100) < 3) {
		printf("������! � �������� �������� ������ ���� ������� 3 �������: ");
		gets_s(partName, 100);
	}
	if (int index = hasInventory(list, size, partName)) {
		printf("������������ � ����� ��������� ����������:\n");
		printEquipment(list[index - 1]);
	}
	else {
		printf("������ ������������ � ������� ���\n");
	}
}