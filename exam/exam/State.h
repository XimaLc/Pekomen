#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "tools.h"

class State
{
public:
	virtual void Update(const sf::Vector2f _mousePo) = 0;
	virtual void Draw(sf::RenderWindow& _window) = 0;
	virtual void HandleKeyboard(sf::Event _event) = 0;
	virtual void HandleEvent(sf::Event _event, sf::RenderWindow& _window) = 0;
};