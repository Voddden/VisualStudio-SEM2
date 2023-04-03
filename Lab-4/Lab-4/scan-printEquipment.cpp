#include "scan-printEquipment.h"

void printEquipment(Equipment equipment) {
	puts("===============");
	printf("id = %ld\nname = %s\ntype = %s\nquantity = %d\ndate = %s\n",
		equipment.id, equipment.name, equipment.type, equipment.quantity, equipment.date);
	puts("===============");
}