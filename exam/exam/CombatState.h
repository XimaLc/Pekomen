#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Team.h"
#include "State.h"
#include "Bouton.h"
#include "PokemonMenu.h"

class CombatState : public State
{
protected:
	sf::Sprite m_backgroundSprite;
	sf::Texture m_backgroundTexture;

	PokemonMenu m_pokemonMenu;

	Bouton m_attaqueBouton;
	Bouton m_pokemonBouton;
	Bouton m_sacBouton;
	Bouton m_fuiteBouton;
	
	//Pokemon actualOpponent;
	//Pokemon actualPokemon;

	//sf::Texture pokemonTexture;
	//sf::Texture pokemonTexture2;

	float timer;
public:
	CombatState();

	virtual void CommonUpdate(sf::Vector2f _mousePos);
	virtual void CommonDraw(sf::RenderWindow& _window);
	virtual void HandleKeyboard(sf::Event _event);
};

