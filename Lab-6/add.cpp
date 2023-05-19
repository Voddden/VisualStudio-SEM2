#define _CRT_SECURE_NO_WARNINGS
#include "add.h"

void add(list* head, const char _FIO[50], int _id, const char _date[50]) {
	list* newNode = new list;
	strcpy(newNode->FIO, _FIO);
	newNode->id = _id;
	strcpy(newNode->date, _date);

	// поиск хвоста списка:
	list* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->next = NULL;
}