#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale>

struct Equipment {
	unsigned long long id = 0;
	char name[50] = "blank";
	char type[50] = "blank";
	unsigned quantity = 0;
	char date[50] = "blank";
};