#include ""

/*
��������. ���������� ���������� �� ������������ ��� ��� � id, ��������, ���,
���������� �� ������, ���� ��������� ��������.
+ ����������� ���������� � �����(������, ������� � ��): 
1 � ����������������, ���,
������(enum); 
2 � ����������, ���������.
*/

void main() 
{
	// "id", "name", "type", "quantity", "date"
	setlocale(LC_ALL, "ru");
	Equipment list[100] = {}; int size = 0;


	inputGeneral(list, size);
		
	printArr(list, size);
}