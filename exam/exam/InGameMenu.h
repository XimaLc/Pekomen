#pragma once
#include "tools.h"
#include <SFML/Graphics.hpp>
#include "Bouton.h"
#include "SaveMenu.h"

class InGameMenu
{
	bool isSaveMenuOpen;

	Bouton m_inGameOptionsBouton;
	Bouton m_inGameBagBouton;
	Bouton m_inGamePokemonBouton;
	Bouton m_inGameProfilBouton;
	Bouton m_inGameSaveBouton;
	Bouton m_inGamePokedexBouton;
	Bouton m_inGameLeaveBouton;

	SaveMenu m_saveMenu;
public:
	bool isMenuOpen;

	InGameMenu();

	void OpenClose(bool& _toSwitch);

	void Update(const sf::Vector2f _mousePos);
	void Draw(sf::RenderWindow& _window);
};

