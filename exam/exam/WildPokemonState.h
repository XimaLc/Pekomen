#pragma once
#include "Pokemon.h"
#include "CombatState.h"
#include "Player.h"

class WildPokemonState : public CombatState
{
	Player m_player;

public:
	WildPokemonState();

	void Update(sf::Vector2f _mousePos);
	void Draw(sf::RenderWindow& _window);
};

