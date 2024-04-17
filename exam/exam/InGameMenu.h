#pragma once
#include "tools.h"
#include <SFML/Graphics.hpp>
#include "Bouton.h"

class InGameMenu
{
	bool isMenuOpen;

	Bouton m_inGameOptionsBouton;
	Bouton m_inGameBagBouton;
	Bouton m_inGamePokemonBouton;
	Bouton m_inGameProfilBouton;
	Bouton m_inGameSaveBouton;
	Bouton m_inGamePokedexBouton;
	Bouton m_inGameLeaveBouton;
public:
	InGameMenu();

	void OpenClose();

	void Update(const sf::Vector2f _mousePos);
	void Draw(sf::RenderWindow& _window);
};

