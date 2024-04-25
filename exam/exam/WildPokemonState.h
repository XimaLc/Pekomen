#pragma once
#include "Pokemon.h"
#include "CombatState.h"
#include "Player.h"

class WildPokemonState : public CombatState
{
	

public:
	WildPokemonState();
	WildPokemonState(Player& _player);

	bool catchPokemon();


	void Update(sf::Vector2f _mousePos);
	void Draw(sf::RenderWindow& _window);
};

