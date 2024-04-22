#include "pokemonInGameInfoBar.h"

sf::Font pokemonInGameInfoBar::m_font;

pokemonInGameInfoBar::pokemonInGameInfoBar()
{
	m_pokemon = new Pokemon();
}

pokemonInGameInfoBar::pokemonInGameInfoBar(int side)
{
	m_pokemon = new Pokemon();
	m_font.loadFromFile("../Files/Fonts/Pokemon.ttf");

	m_texture.loadFromFile("../Files/Textures/pokeBar.png");
	m_sprite.setScale(6,6);
	
	m_pokemonHpText.setFillColor(sf::Color::Black);

	if (side == OPPONENT)
	{
		m_sprite.setPosition(50, 50);
		m_pokemonNameText.setPosition(75, 75);
		m_pokemonHpText.setPosition(400, 150);
	}
	else if (side == PLAYER)
	{
		m_sprite.setPosition(900, 800); 
		m_pokemonNameText.setPosition(925, 825);
		m_pokemonHpText.setPosition(1250, 900);
	}

	m_pokemonNameText.setCharacterSize(40);
	m_pokemonNameText.setFillColor(sf::Color::Black);

}

pokemonInGameInfoBar::~pokemonInGameInfoBar()
{
	//delete m_pokemon;
}

void pokemonInGameInfoBar::setPokemon(Pokemon _pokemon)
{
	m_pokemon = &_pokemon;
	m_pokemonNameText.setString(m_pokemon->getName());
	m_pokemonMaxHp = m_pokemon->getStat(HP);
	m_pokemonHp = m_pokemon->getStat(CURRENTHP);
}

void pokemonInGameInfoBar::Update(int _hp)
{
	//CRASH POUR 
	m_pokemonHp = _hp;
	std::string tmp = "PV: " + std::to_string(m_pokemonHp) + "/" + std::to_string(m_pokemonMaxHp);
	m_pokemonHpText.setString(tmp);
}

void pokemonInGameInfoBar::Draw(sf::RenderWindow& _window)
{
	m_sprite.setTexture(m_texture);
	_window.draw(m_sprite);

	m_pokemonNameText.setFont(m_font);
	_window.draw(m_pokemonNameText);

	m_pokemonHpText.setFont(m_font);
	_window.draw(m_pokemonHpText);
}