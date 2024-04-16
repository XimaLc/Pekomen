#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class State
{
public:
	virtual void Update(sf::RenderWindow& _window) = 0;
	virtual void Draw(sf::RenderWindow& _window) = 0;
};

