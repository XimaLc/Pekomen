#pragma once
#include "BallInventory.h"

class Inventory
{
	BallInventory m_ballInventory;
public:
	Inventory();

	int getBallAmount(int _id);
		
};

