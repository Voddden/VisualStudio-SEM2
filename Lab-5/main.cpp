#include "push.h"
#include "pop.h"
#include "printStack.h"

/*
Лабораторная работа No5
Динамические структуры данных. Стек

Используя самописный стек, реализовать функции, решающие выданную задачу.
Оценка будет во многом зависеть от чистоты кода, понимания где он может

применяться.

Вариант#1
1) Преобразование выражения из инфиксной формы в префиксную.`
*/

void main()
{
	setlocale(LC_ALL, "ru");
	//FILO* head = NULL;
	//for (int i = 0; i < 5; ++i) {
	//	head = push(head);
	//}

	//printStack(head);

	//head = pop(head);
	//printf("Stack after pop:\n");
	//printStack(head);

	char buffer[100];
	printf("Введите инфиксную форму: ");
	gets_s(buffer, 100);
}