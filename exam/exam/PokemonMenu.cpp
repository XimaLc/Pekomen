#include "PokemonMenu.h"
#include "StateManager.h"

PokemonMenu::PokemonMenu()
{
	m_player = StateManager::getPlayer2();

	m_pokemon1Bouton = Bouton({ 100, 100 }, { 350, 350 }, m_player->getTeam()->getPokemons()[0]);
	m_pokemon2Bouton = Bouton({ 600, 100 }, { 350, 350 }, m_player->getTeam()->getPokemons()[1]);
	m_pokemon3Bouton = Bouton({ 1100, 100 }, { 350, 350 },m_player->getTeam()->getPokemons()[2]);
	m_pokemon4Bouton = Bouton({ 100, 500 }, { 350, 350 }, m_player->getTeam()->getPokemons()[3]);
	m_pokemon5Bouton = Bouton({ 600, 500 }, { 350, 350 }, m_player->getTeam()->getPokemons()[4]);
	m_pokemon6Bouton = Bouton({ 1100, 500 }, { 350, 350 },m_player->getTeam()->getPokemons()[5]);

	m_isPokemonMenuOpen = false;
}

void PokemonMenu::OpenClose()
{
	m_isPokemonMenuOpen = !m_isPokemonMenuOpen;
}

void PokemonMenu::loadPlayer()
{
	m_pokemon1Bouton.setPokemon(m_player->getTeam()->getPokemons()[0], POKEMON_BOUTON);
	m_pokemon2Bouton.setPokemon(m_player->getTeam()->getPokemons()[1], POKEMON_BOUTON);
	m_pokemon3Bouton.setPokemon(m_player->getTeam()->getPokemons()[2], POKEMON_BOUTON);
	m_pokemon4Bouton.setPokemon(m_player->getTeam()->getPokemons()[3], POKEMON_BOUTON);
	m_pokemon5Bouton.setPokemon(m_player->getTeam()->getPokemons()[4], POKEMON_BOUTON);
	m_pokemon6Bouton.setPokemon(m_player->getTeam()->getPokemons()[5], POKEMON_BOUTON);
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
	m_pokemon1Bouton.Draw(_window);
	m_pokemon2Bouton.Draw(_window);
	m_pokemon3Bouton.Draw(_window);
	m_pokemon4Bouton.Draw(_window);
	m_pokemon5Bouton.Draw(_window);
	m_pokemon6Bouton.Draw(_window);
}