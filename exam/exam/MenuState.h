#pragma once
#include "State.h"
class MenuState : public State
{
public:
	virtual void Update(sf::RenderWindow& _window);
	virtual void Draw(sf::RenderWindow& _window);
};

