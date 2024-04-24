#pragma once
#include "tools.h"
#include <SFML/Graphics.hpp>
#include "SaveMenu.h"
#include "PokemonMenu.h"

class InGameMenu
{
	Bouton m_inGameOptionsBouton;
	Bouton m_inGameBagBouton;
    Bouton m_inGamePokemonBouton;
	Bouton m_inGameProfilBouton;
	Bouton m_inGameSaveBouton;
	Bouton m_inGamePokedexBouton;
	Bouton m_inGameLeaveBouton;

	SaveMenu m_saveMenu;
	PokemonMenu m_pokemonMenu;

	bool isPokemonMenuOpen;
public:
	bool isMenuOpen;

	InGameMenu();

	void closeAllMenu();

	void OpenCloseMenu(bool& _toSwitch);
	void OpenCloseOtherMenu(bool& _toSwitch);

	void Update(const sf::Vector2f _mousePos);
	void Draw(sf::RenderWindow& _window);
};

