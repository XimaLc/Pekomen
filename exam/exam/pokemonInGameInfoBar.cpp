#include "pokemonInGameInfoBar.h"

pokemonInGameInfoBar::pokemonInGameInfoBar()
{
	m_pokemon = new Pokemon();
}

pokemonInGameInfoBar::pokemonInGameInfoBar(int side)
{
	m_pokemon = new Pokemon();

	m_texture.loadFromFile("../Files/Textures/pokeBar.png");

	m_sprite.setScale(6,6);
	m_sprite.setPosition(50, 50);

	m_pokemonNameText.setFillColor(sf::Color::Black);
	m_pokemonNameText.setPosition(60, 60);
}

void pokemonInGameInfoBar::setPokemon(Pokemon _pokemon)
{
	m_pokemon = &_pokemon;
}

void pokemonInGameInfoBar::Update()
{
}

void pokemonInGameInfoBar::Draw(sf::RenderWindow& _window)
{
	m_sprite.setTexture(m_texture);
	_window.draw(m_sprite);

	m_pokemonNameText.setString(m_pokemonNameS);
	_window.draw(m_pokemonNameText);
}