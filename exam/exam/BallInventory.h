#pragma once
#include "Ball.h"
#include <map>

class BallInventory
{
	std::map<int, int> m_balls;

public:
	BallInventory();

	void addBall(int _ballId, int _amount);

	inline int getBallAmount(int _id) { return m_balls[_id]; }

	inline std::map<int, int> getBalls();
};