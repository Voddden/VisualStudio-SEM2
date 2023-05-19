#define _CRT_SECURE_NO_WARNINGS
#include "lib-header.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int day;
    int month;
    int year;
} date;
typedef struct
{
    long long id;
    date creationDate;
    char* nameStr;
} data;
typedef struct
{
    data* unit;
    void* next;
} listNode;
typedef struct
{
    listNode* listHead;
    int size;
} list;

void decList(list* myList)
{
    myList->listHead = NULL;
    myList->size = 0;
}
void invertList(list* myList)
{
    listNode* listIt, * buf;
    void* prev = NULL;
    listIt = myList->listHead;
    while (listIt != NULL)
    {
        buf = listIt->next;
        listIt->next = prev;
        prev = listIt;
        listIt = buf;
    }
    myList->listHead = prev;
}
void printData(data* unit)
{
    printf("|%13lli|%50s|%2i|%2i|%4i|\n", unit->id, unit->nameStr, unit->creationDate.day, unit->creationDate.month, unit->creationDate.year);
}
void printList(list* myList)
{
    int num;
    listNode* listIt, * buf;
    listIt = myList->listHead;
    printf("|------|-------------|--------------------------------------------------|----------|\n");
    printf("|����� |id           |���                                               |����      |\n");
    printf("|      |             |                                                  |----------|\n");
    printf("|      |             |                                                  |��|��|����|\n");
    printf("|------|-------------|--------------------------------------------------|----------|\n");
    num = 0;
    while (listIt != NULL)
    {
        num++;
        printf("|%6i", num);
        printData(listIt->unit);
        listIt = listIt->next;
    }
    printf("|------|-------------|--------------------------------------------------|----------|\n");
}
void enterName(char** str)
{
    char bufStr[52];
    int size;
    do
    {
        printf("������� ���: ");
        scanf("%51s", bufStr);
        fflush(stdin);
        size = strlen(bufStr);
        if (size < 51)
            break;
        printf("������� ������ ���������� ������ 51-�� �������\n");
    } while (1);
    *str = malloc(sizeof(char) * (size + 1));
    memcpy(*str, bufStr, sizeof(char) * size);
    (*str)[size] = '\0';
}
void enterDate(date* myDate)
{
    long long buf;
    do
        printf("������� ����� ���: ");
    while (!putI(&buf, 1, 31));
    myDate->day = buf;
    do
        printf("������� ����� ������: ");
    while (!putI(&buf, 1, 12));
    myDate->month = buf;
    do
        printf("������� ����� ����: ");
    while (!putI(&buf, 1, 9999));
    myDate->year = buf;
}
void enterData(data* unit)
{
    do
        printf("������� id: ");
    while (!putI(&unit->id, 0, 1e12));
    printf("\n");
    enterName(&unit->nameStr);
    printf("\n");
    printf("���� ���� ��������\n");
    printf("\n");
    enterDate(&unit->creationDate);
}
void addUnit(list* myList)
{
    long long num;
    listNode* listIt, * prev{}, * newNode;
    do
    {
        system("cls");
        printList(myList);
        printf("\n");
        printf("����� ������ �����, �� ��������� ��������� ������ �������� � ������\n");
        printf("������� ����� �������� �� �������� ��� �������� �������\n");
        printf("����� ������ ����� �� 1 ������, ��� ����� ���������� ��������\n");
        printf("����� ������� ����� ������� � �����\n");
        printf("\n");
        do
            printf("������� �����(��� 0 ��� ������ � ����): ");
        while (!putI(&num, 0, myList->size + 1));
        printf("\n");
        if (num == 0)
            return;
        myList->size++;
        listIt = myList->listHead;
        for (int i = 1; i < num; i++)
        {
            prev = listIt;
            listIt = listIt->next;
        }
        newNode = malloc(sizeof(listNode));
        newNode->unit = malloc(sizeof(data));
        enterData(newNode->unit);
        newNode->next = listIt;
        if (num == 1)
            myList->listHead = newNode;
        else
            prev->next = newNode;
    } while (1);

}
void freeListNode(listNode* unit)
{
    free(unit->unit->nameStr);
    free(unit->unit);
    free(unit);
}
void delUnit(list* myList)
{
    listNode* listIt, * prev;
    long long num;
    do
    {
        printList(myList);
        printf("\n");
        do
            printf("������� ����� ���������� ��������(��� 0 ��� ������ � ����): ");
        while (!putI(&num, 0, myList->size));
        if (num == 0)
            break;
        myList->size--;
        listIt = myList->listHead;
        for (int i = 1; i < num; i++)
        {
            prev = listIt;
            listIt = listIt->next;
        }
        if (num == 1)
            myList->listHead = listIt->next;
        else
            prev->next = listIt->next;
        freeListNode(listIt);
        system("cls");
    } while (1);
}
void invertTask(list* myList)
{
    printList(myList);
    printf("\n");
    invertList(myList);
    printList(myList);
}
void menu()
{
    long long num;
    list myList;
    decList(&myList);
    do
    {
        system("cls");
        printf("����� ���-�� �������:\n");
        printf("0.��������� ���������\n");
        printf("1.�������� �������\n");
        printf("2.������� �������\n");
        printf("3.������� ��� ��������\n");
        printf("4.������������� ��������\n");
        printf("\n");
        do
            printf("������� ����� ��������: ");
        while (!putI(&num, 0, 4));
        system("cls");
        switch (num)
        {
        case 1:
            addUnit(&myList);
            break;
        case 2:
            delUnit(&myList);
            break;
        case 3:
            printList(&myList);
            break;
        case 4:
            invertTask(&myList);
            break;
        default:;
        }
        if (num != 0)
            printf("\n");
        system("pause");
    } while (num != 0);
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    menu();
    return 0;
    /*
    listAddUnit(&myList,pos,&unit);
    listDeleteUnit(&myList,pos);
    invertList(&myList);
    */
    return 0;
}
