#define _CRT_SECURE_NO_WARNINGS
#include "TypeDefinition.h"

/*
4-6 ����������� �������� ������ ������� �� ������� �� �����, ������������ �����
��������� ������(��������� �������, ��������� union). ����������� �������
������ � ���������� ���������� �� ������ �� ����� �������.
 
6-8 ������������� ����������/���������� ������������ �������� ������. �������
������� ����������, ������ � ��.

13) ��������. ���������� ���������� �� ������������ ��� ��� � id, ��������, ���,
���������� �� ������, ���� ��������� ��������.
+ ����������� ���������� � �����(������, ������� � ��): 1 � ����������������, ���,
������(enum); 2 � ����������, ���������.
*/


void main() {
	setlocale(LC_ALL, "ru");
	printf("������� �����\n");
	Equipment f;
	f.number = inputNatural("number = ");
	switch (f.number)
	{
	case 1:
		;
		break;
	case 2:
		;
	}
}