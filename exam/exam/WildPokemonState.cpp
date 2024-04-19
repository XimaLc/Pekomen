#include "WildPokemonState.h"
#include "DB.h"

WildPokemonState::WildPokemonState()
{
	actualOpponent = DB::getPokemonById(iRand(0, 163));
}

void WildPokemonState::Update(sf::Vector2f _mousePos)
{
	CommonUpdate(_mousePos);
}

void WildPokemonState::Draw(sf::RenderWindow& _window)
{
	CommonDraw(_window);
	actualOpponent.Draw(_window);
}

void WildPokemonState::HandleEvent(sf::Event _event, sf::RenderWindow& _window)
{
}
