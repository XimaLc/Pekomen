#include "WildPokemonState.h"
#include "DB.h"
#include "GameState.h"

WildPokemonState::WildPokemonState()
{
	m_player = GameState::getPlayer();
	//actualOpponent = DB::getPokemonById(iRand(0, 163));
}

void WildPokemonState::Update(sf::Vector2f _mousePos)
{
	CommonUpdate(_mousePos);
}

void WildPokemonState::Draw(sf::RenderWindow& _window)
{
	CommonDraw(_window);
	//actualOpponent.Draw(_window);
}
