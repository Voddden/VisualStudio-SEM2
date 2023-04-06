#define _CRT_SECURE_NO_WARNINGS
#include "addEquipment.h"
#include "scan-printEquipment.h"
#include "editEquipment.h"
#include "deleteEquipment.h"
#include "sortEquipment.h"
#include "..\ValidationLib\Validation.h"
#include "partNameCheck.h"
#include "complexSort.h"

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

	int choice = inputNatural("1 - ������ � ����������, 2 - default ��������\n");
	switch (choice) {
	case 1:
		inputGeneral(list, size);
		break;
	case 2:
		// 	printf("������ �� ���������:\n");
		add(list, size, 1, "gunwater", "lasertype", 10, "08.03.2003");
		add(list, size, 1, "gun", "aassd", 4, "09.03.2023");
		add(list, size, 3, "shovel", "pocket edition", 3, "05.03.1995");
		add(list, size, 4, "computer", "Asus", 50, "01.03.1945");
		add(list, size, 5, "lamp", "kinda cute", 6, "07.03.2023");

		editEquipment(list, size, 2, 10, "supergun", "incredible", 15, "03.08.2015");
		break;
	default:
		puts("Invalid input");
		exit(1);
	}

	printList(list, size);

	printf("������� ��� ����������:\n");
	int sortChoice = inputNatural("1 - no sort, 2 - IDsort, 3 - NAMEsort, 4 - TYPEsort, 5 - QUANTITYSORT, 6 - DATEsort, 7 - ������������� ����������\n");
	int res = 0;
	switch (sortChoice) {
	case 1:
		break;
	case 2:
		sortById(list, size);
		break;
	case 3:
		sortByName(list, size);
		break;
	case 4:
		sortByType(list, size);
		break;
	case 5:
		sortByQuantity(list, size);
		break;
	case 6:
		sortByDate(list, size);
		break;
	case 7:
		res = complexSort(list, size);
		if (res != 0) {
			puts("error! Invalid input\n");
			exit(0);
		}
		break;
	default:
		puts("Error! Invalid input");
		exit(1);
	}
	printList(list, size);


	partNameCheck(list, size);
}