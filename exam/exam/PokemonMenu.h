#pragma once
#include "Bouton.h"
#include "Player.h"

class PokemonMenu
{
	sf::RectangleShape m_backgroundShape;

	Bouton m_pokemon1Bouton;
	Bouton m_pokemon2Bouton;
	Bouton m_pokemon3Bouton;
	Bouton m_pokemon4Bouton;
	Bouton m_pokemon5Bouton;
	Bouton m_pokemon6Bouton;
	Bouton m_retour;
	
	Player m_player;
public:
	PokemonMenu();

	bool m_isPokemonMenuOpen;
	inline void OpenClose() { m_isPokemonMenuOpen = !m_isPokemonMenuOpen; }

	void Update(sf::Vector2f _mousePos);
	void Draw(sf::RenderWindow& _window);
};

