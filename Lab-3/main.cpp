#define _CRT_SECURE_NO_WARNINGS
#include "addEquipment.h"
#include "scan-printEquipment.h"
#include "editEquipment.h"
#include "deleteEquipment.h"
#include "sortEquipment.h"

/*
13) ��������. ���������� ���������� �� ������������ ��� ��� � 
id, 
��������, (name)
���, (type)
���������� �� ������,
���� ��������� ��������. 

��������� ������� �� ������ �������������
������������ �� ��������� ��������. ���������� ������������ ��� ��������.

1.����������� ��� ����������� ������� ��� ������������� ���� ������ �
���������� ����� ������, (add)
����� ����������, (print)
��������� ������������ ������, (edit)
�������� ������������ ������, (delete)
���������� �� ������� �� ����� ��������� (sort)

2.�������� ������������ � ������������� ���������� �� ���������� ����������
*/

void main() {
	Equipment stack[100] = {}; int size = 0;

	add(stack, size, 100, "Agun", "lasertype", 4, "02/06/2004");
	add(stack, size, 5, "Bwatergun", "very splashy", 10, "25/1/2023");
	add(stack, size, 10, "Cshovel", "pocket edition", 3, "21/3/2022");
	

	//editEquipment(stack, size, 1, 228, "toy tank", "expensive", 9, "20/2/2023");

	//deleteEquipment(stack, size, 0);

	sortByName(stack, size);

	printList(stack, size);

	
}