#include "hasInventory.h"

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
}