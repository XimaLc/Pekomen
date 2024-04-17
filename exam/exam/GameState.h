#pragma once
#include "State.h"
#include <SFML/Graphics.hpp>
class GameState : public State
{
	sf::RectangleShape shape;

public:
	GameState();
	
	virtual void Update(sf::Vector2f _mousePos) override;
	virtual void Draw(sf::RenderWindow& _window) override;
	virtual void HandleEvent(sf::Event _event, sf::RenderWindow& _window) override;
};