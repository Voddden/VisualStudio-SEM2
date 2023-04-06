#include ""

/*
ѕейнтбол. —одержитс€ информаци€ об оборудовании дл€ игр Ч id, название, тип,
количество на складе, дата последней проверки.
+ ”сложн€етс€ информаци€ с типом(оружие, техника и тд): 
1 Ч скорострельность, вес,
подтип(enum); 
2 Ч назначение, стоимость.
*/

void main() 
{
	// "id", "name", "type", "quantity", "date"
	setlocale(LC_ALL, "ru");
	Equipment list[100] = {}; int size = 0;


	inputGeneral(list, size);
		
	printArr(list, size);
}