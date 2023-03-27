#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"

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

#include <string>
#include <iostream>
using namespace std;

struct  Game
{
	int id;
	char name[100];
	char izdatel[100];
	char year[5];
	char price[100];
	int rating;

	union {
		struct
		{
			char* genre = (char*)malloc(100);
			char* age = (char*)malloc(100);
		} s1;

		struct {
			char* specs = (char*)malloc(100);
			enum {
				iOS,
				Android,
				Windows
			} e;
		} s2;
	} u;
};

void main() {
	Game list[100] = {1, "Hotline Miami", "Integral", "2023", "100$", 100};
	strcpy(list[0].u.s1.age, "18+");
	strcpy(list[0].u.s1.genre, "Action RPG");

	cout << list[0].u.s1.genre << endl << list[0].u.s1.age;
	//printf("hello world\n");
}