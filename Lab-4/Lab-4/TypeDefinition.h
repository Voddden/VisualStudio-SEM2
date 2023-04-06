#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "..\..\ValidationLib\Validation.h"


struct Equipment {
	int id = 0;
	char name[50] = "blank";
	typedef union {
		struct {
			int firingRate;
			int weight;
			enum subType
			{
				subtype1,
				subtype2,
				subtype3
			};
		} s1;

		struct {
			char purpose[50];
			char price[50];
		} s2;
	} type;
	unsigned quantity = 0;
	char date[50] = "blank";

	int number;

};