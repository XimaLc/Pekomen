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

	sf::Text m_pokemonNameText;

	static sf::Font m_font;

	int m_pokemonHp;
	int m_pokemonMaxHp;

	sf::Text m_pokemonHpText;
public:
	pokemonInGameInfoBar();
	pokemonInGameInfoBar(int side);

	~pokemonInGameInfoBar();

	void setPokemon(Pokemon _pokemon);

	void Update(int _hp);
	void Draw(sf::RenderWindow& _window);
};