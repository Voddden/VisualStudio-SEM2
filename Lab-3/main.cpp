#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
13) ��������. ���������� ���������� �� ������������ ��� ��� � id, ��������, ���,
���������� �� ������, ���� ��������� ��������. 

��������� ������� �� ������ �������������
������������ �� ��������� ��������. ���������� ������������ ��� ��������.

1.����������� ��� ����������� ������� ��� ������������� ���� ������ �
���������� ����� ������, ����� ����������, ��������� ������������ ������,
�������� ������������ ������, ���������� �� ������� �� ����� ���������

2.�������� ������������ � ������������� ���������� �� ���������� ����������
*/

struct Equipment {
	unsigned long long id = 0;
	char name[50] = "blank";
	char type[50] = "blank";
	int quantity = 0;
	char date[50] = "blank";
};

void Print(Equipment equipment) {
	printf("id = %ld\nname = %s\ntype = %s\nquantity = %d\ndate = %s\n",
		equipment.id, equipment.name, equipment.type, equipment.quantity, equipment.date);
}

bool availableInSorage(Equipment equipment) {
	return equipment.quantity;
}

void input(Equipment equipment) {

}

void main() {
	Equipment arr[100];

	arr[0]{24655, "ChillZone", "Important", 10, "02/05/2022"};
	//input(equipment);
	//if (availableInSorage(equipment)) {
	//	printf("equipment is available\n");
	//}
	//else {
	//	printf("equipment isn't available\n");
	//}
	


}