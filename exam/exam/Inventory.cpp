
#include "Inventory.h"

Inventory::Inventory()
{
	
}

int Inventory::getBallAmount(int _id)
{
	return m_ballInventory.getBallAmount(_id);
}

void Inventory::withdrawBall(int _id)
{
	m_ballInventory.withdrawBall(_id);
}