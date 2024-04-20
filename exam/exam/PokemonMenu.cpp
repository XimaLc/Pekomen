#include "PokemonMenu.h"
#include "GameState.h"

PokemonMenu::PokemonMenu()
{
	m_player = GameState::getPlayer();

	m_backgroundShape.setSize({ 1520,880 });
	m_backgroundShape.setPosition({ 50,50 });
	m_backgroundShape.setFillColor(sf::Color(211, 211, 211));

	m_pokemon1Bouton = Bouton({ 100, 100 }, { 350, 350 }, m_player.getTeam()->getPokemons()[0].getPath(), POKEMON_PATH);
	m_pokemon2Bouton = Bouton({ 600, 100 }, { 350, 350 }, m_player.getTeam()->getPokemons()[1].getPath(), POKEMON_PATH);
	m_pokemon3Bouton = Bouton({ 1100, 100 }, { 350, 350 }, m_player.getTeam()->getPokemons()[2].getPath(), POKEMON_PATH);
	m_pokemon4Bouton = Bouton({ 100, 500 }, { 350, 350 }, m_player.getTeam()->getPokemons()[3].getPath(), POKEMON_PATH);
	m_pokemon5Bouton = Bouton({ 600, 500 }, { 350, 350 }, m_player.getTeam()->getPokemons()[4].getPath(), POKEMON_PATH);
	m_pokemon6Bouton = Bouton({ 1100, 500 }, { 350, 350 }, m_player.getTeam()->getPokemons()[5].getPath(), POKEMON_PATH);
	m_isPokemonMenuOpen = false;
}

void PokemonMenu::Update(sf::Vector2f _mousePos)
{
	m_pokemon1Bouton.Update(_mousePos);
	m_pokemon2Bouton.Update(_mousePos);
	m_pokemon3Bouton.Update(_mousePos);
	m_pokemon4Bouton.Update(_mousePos);
	m_pokemon5Bouton.Update(_mousePos);
	m_pokemon6Bouton.Update(_mousePos);
}

void PokemonMenu::Draw(sf::RenderWindow& _window)
{
	//_window.draw(m_backgroundShape);
	m_pokemon1Bouton.Draw(_window);
	m_pokemon2Bouton.Draw(_window);
	m_pokemon3Bouton.Draw(_window);
	m_pokemon4Bouton.Draw(_window);
	m_pokemon5Bouton.Draw(_window);
	m_pokemon6Bouton.Draw(_window);
}