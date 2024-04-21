#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Pokemon.h"

enum SIDES { OPPONENT, PLAYER };

class pokemonInGameInfoBar
{
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	Pokemon* m_pokemon;

	std::string m_pokemonNameS;
	sf::Text m_pokemonNameText;

public:
	pokemonInGameInfoBar();
	pokemonInGameInfoBar(int side);

	void setPokemon(Pokemon _pokemon);

	void Update();
	void Draw(sf::RenderWindow& _window);
};