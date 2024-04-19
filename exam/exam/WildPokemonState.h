#pragma once
#include "Pokemon.h"
#include "State.h"
class WildPokemonState : public State
{
	Pokemon opponent;
public:
	WildPokemonState();

	virtual void Update(sf::Vector2f _mousePos);
	virtual void Draw(sf::RenderWindow& _window);
	virtual void HandleKeyboard(sf::Event _event);
	virtual void HandleEvent(sf::Event _event, sf::RenderWindow& _window);
};

