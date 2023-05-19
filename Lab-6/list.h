#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct list {
	char FIO[50] = {};
	int id;
	char date[50] = {};
	list* next;
};