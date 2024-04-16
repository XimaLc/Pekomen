#pragma once
#include "State.h"
class GameState : public State
{
public:
	virtual void Update(sf::RenderWindow& _window) override;
	virtual void Draw(sf::RenderWindow& _window) override;
};

