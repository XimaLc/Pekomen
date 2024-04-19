#pragma once
#include "Pokemon.h"
#include "CombatState.h"
class WildPokemonState : public CombatState
{
	Pokemon opponent;
public:
	WildPokemonState();

	void Update(sf::Vector2f _mousePos);
	void Draw(sf::RenderWindow& _window);
	virtual void HandleEvent(sf::Event _event, sf::RenderWindow& _window);
};

