#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "..\..\ValidationLib\Validation.h"


struct Equipment {
	unsigned long long id = 0;
	char name[50] = "blank";
	char type[50] = "blank";
	unsigned quantity = 0;
	char date[50] = "blank";

	int number;
	union {
		struct {
			unsigned firingRate;
			unsigned weight;
		} s1;

		struct {
			char cause[50];
			char price[50];
		} s2;
	} u;
};