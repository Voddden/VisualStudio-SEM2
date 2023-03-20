#pragma once
#include "EquipmentType.h"

bool availableInSorage(Equipment equipment) {
	return equipment.quantity;
}