
#include "Inventory.h"

Inventory::Inventory()
{
	
}

int Inventory::getBallAmount(int _id)
{
	return m_ballInventory.getBallAmount(_id);
}
