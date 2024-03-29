#include "EquipmentType.h"
#include "consoleInput.h"
#include "consoleOutput.h"
#include "defaultValues.h"

#include "vzyatieOstatka.h"
#include "search.h"
#include "sortDate.h"
#include "unionSort.h"

/*
����������� �������� ������ ������� �� ������� �� �����, ������������ �����
��������� ������(��������� �������, ��������� union). 

����������� �������
������ � 
���������� ���������� �� ������ �� ����� �������.
*/

// id, ��������, ���, ���-��, ����
void main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");
	Equipment arr[100] = {}; int size = 0;
	int unionType[100] = {};
	switch (inputNatural("1 - ���� � �������, 2 - default ��������\n")) {
	case 1:
		consoleInput(arr, size, unionType);
		break;
	case 2:
		defaultValues(arr, size, unionType);
		break;
	default:
		printf("Error! Invalid data"); exit(1);
	}
	//consoleInput(arr, size, unionType);

	printArr(arr, size, unionType);

	switch (inputNatural("1 - ��������� �����, 2 - ����������\n")) {
	case 1:
		search(arr, size, unionType);
		break;
	case 2:
		break;
	default:
		puts("Error! Invalid data"); exit(1);
	}


	puts("\n");
	switch (inputNatural("1 - ��������� ����������, 2 - ����������\n")) {
	case 1:
		printf("\n\t\t--- ���������� ---\n");
		//sortDate(arr, size, unionType);
		unionSort(arr, size, unionType);
		printf("������ ����� ����������:\n\n");
		printArr(arr, size, unionType);
		break;
	case 2:
		break;
	default:
		printf("Error! Invalid data"); exit(1);
	}

	//int num  = inputNaturalAnd0("������� ����� ��� ������ �������: ");
	//int argvv = atoi(argv[1]);
	//int res = vzyatieOstatka(num, argvv);
	//printf("%d\n", res);
	//printf("\n%d", vzyatieOstatka(inputNatural("������� ����� ��� ������ �������: "), atoi(argv[1]))); exit(0);
}