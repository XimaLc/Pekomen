#include "BallInventory.h"

BallInventory::BallInventory()
{
	m_balls[1] = 20;
	m_balls[2] = 0;
	m_balls[3] = 0;
	m_balls[4] = 0;
}

void BallInventory::addBall(int _ballId, int _amount)
{
	m_balls[_ballId] += _amount;
}

inline std::map<int, int> BallInventory::getBalls()
{
	return std::map<int, int>();
}
