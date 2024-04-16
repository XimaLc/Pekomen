#pragma once
#include "State.h"
class GameState : public State
{
public:
	virtual void Update();
	virtual void Draw();
};

