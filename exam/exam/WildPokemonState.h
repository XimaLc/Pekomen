#pragma once
#include "Pokemon.h"
#include "CombatState.h"
#include "Player.h"

class WildPokemonState : public CombatState
{
	Bouton m_pokeBallBouton;
	Bouton m_superBallBouton;
	Bouton m_hyperBallBouton;
	Bouton m_maitreBallBouton;

public:
	WildPokemonState();
	WildPokemonState(Player& _player);

	bool catchPokemon(int _id);

	void Update(sf::Vector2f _mousePos);
	void Draw(sf::RenderWindow& _window);
};

