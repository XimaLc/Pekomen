#pragma once
#include "Item.h"

enum BALL_TYPE { PEKOBALL, SUPERBALL, HYPERBALL, MAITREBALL};
class Ball : public Item
{
	float m_bonus;

public:
	Ball(int _id, std::string _name, int _bonus);

};

