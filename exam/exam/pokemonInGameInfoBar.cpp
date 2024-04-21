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
	

	if (side == OPPONENT)
	{
		m_sprite.setPosition(50, 50);
		m_pokemonNameText.setPosition(60, 60);
	}
	else if (side == PLAYER)
	{
		m_sprite.setPosition(900, 800); 
		m_pokemonNameText.setPosition(910, 810);
	}

	m_pokemonNameText.setCharacterSize(50);
	m_pokemonNameText.setFillColor(sf::Color::Black);

}

void pokemonInGameInfoBar::setPokemon(Pokemon _pokemon)
{
	m_pokemon = &_pokemon;
	m_pokemonNameS = m_pokemon->getName();
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