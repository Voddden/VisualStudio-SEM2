#define _CRT_SECURE_NO_WARNINGS
#include "addEquipment.h"
#include "scan-printEquipment.h"
#include "editEquipment.h"
#include "deleteEquipment.h"
#include "sortEquipment.h"
#include "..\ValidationLib\Validation.h"

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
	setlocale(LC_ALL, "ru");
	Equipment list[100] = {}; int size = 0;

	//add(list, size, 100, "Agun", "lasertype", 4, "02/06/2004");
	//add(list, size, 5, "Bwatergun", "very splashy", 10, "25/1/2023");
	//add(list, size, 10, "Cshovel", "pocket edition", 3, "21/3/2022");
	
	inputGeneral(list, size);

	//editEquipment(list, size, 1, 228, "toy tank", "expensive", 9, "20/2/2023");

	//deleteEquipment(list, size, 0);

	//sortByName(list, size);

	printList(list, size);

	
}