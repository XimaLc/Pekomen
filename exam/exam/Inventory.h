#pragma once
#include "BallInventory.h"

class Inventory
{
	BallInventory m_ballInventory;
public:
	Inventory();

	int getBallAmount(int _id);
	void withdrawBall(int _id);

		
};

