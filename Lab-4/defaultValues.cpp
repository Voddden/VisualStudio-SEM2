#define _CRT_SECURE_NO_WARNINGS
#include "defaultValues.h"

void defaultValues(Equipment* arr, int& size, int* unionType) {
	// 1
	++size;

	arr[0].id = 11;
	strcpy(arr[0].name, "watergun");

	unionType[0] = 1;
	arr[0].type.s1.shootSpeed = 990;
	arr[0].type.s1.weight = 30;
	arr[0].type.s1.subtype1;

	arr[0].quantity = 77;
	strcpy(arr[0].date, "25.10.2022");

	// 2
	++size;

	arr[1].id = 22;
	strcpy(arr[1].name, "laser");

	unionType[1] = 2;
	strcpy(arr[1].type.s2.price, "300$");
	strcpy(arr[1].type.s2.purpose, "200$");

	arr[1].quantity = 10;
	strcpy(arr[1].date, "06.04.2023");

	// 3
	++size;

	arr[2].id = 34;
	strcpy(arr[2].name, "AK-74");

	unionType[2] = 1;
	arr[2].type.s1.shootSpeed = 880;
	arr[2].type.s1.weight = 50;
	arr[2].type.s1.subtype2;

	arr[2].quantity = 14;
	strcpy(arr[2].date, "02.11.1989");
}