#define _CRT_SECURE_NO_WARNINGS
#include "add.h"
using namespace std;
#include <iostream>
/*
7) Инвертировать однонаправленный список (внутри каждого элемента хранится ФИО, id
договора, дата создания), т.е. первый элемент становится последним, второй предпоследним и
т.д. Дополнительных массивов и списков не создавать.
*/

void main()
{
	list head;
	strcpy(head.FIO, "Vodnev Daniil Ivanovich");
	head.id = 1;
	strcpy(head.date, "02.06.2004");
	head.next = NULL;

	add(&head, "Karina Olejnik", 2, "06.08.2003");
	add(&head, "Ivanov Ivan Ivanovich", 3, "01.03.1945");
	add(&head, "Svetlana Smirnova Ivanovna", 4, "30.12.1999");
	
	
	cout << head.FIO << endl << head.id << endl << head.date << endl;
	cout << "-------------------\n";
	cout << head.next->FIO << endl << head.next->id << endl << head.next->date << endl;
	
}