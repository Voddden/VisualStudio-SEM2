#define _CRT_SECURE_NO_WARNINGS
#include "addEquipment.h"
#include "scan-printEquipment.h"
#include "editEquipment.h"
#include "deleteEquipment.h"
#include "sortEquipment.h"
#include "..\ValidationLib\Validation.h"
#include "partNameCheck.h"

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

void main() 
{
	// "id", "name", "type", "quantity", "date"
	setlocale(LC_ALL, "ru");
	Equipment list[100] = {}; int size = 0;

	add(list, size, 1, "watergun", "very splashy", 10, "08.03.2003");
	add(list, size, 2, "gun", "lasertype", 4, "09.03.2023");
	add(list, size, 3, "shovel", "pocket edition", 3, "05.03.1995");
	add(list, size, 4, "computer", "Asus", 50, "01.03.1945");
	add(list, size, 5, "lamp", "kinda cute", 6, "07.03.2023");

	editEquipment(list, size, 2, 10, "supergun", "incredible", 15, "03.08.2015");

	printf("������ �� ���������:\n");
	printList(list, size);



	sortById(list, size);
	//sortByName(list, size);
	//sortByType(list, size);
	//sortByQuantity(list, size);
	//sortByDate(list, size);

	partNameCheck(list, size);
}