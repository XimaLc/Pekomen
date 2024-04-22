#include "WildPokemonState.h"
#include "DB.h"

WildPokemonState::WildPokemonState()
{
	actualOpponentPkm = DB::getPokemonById(iRand(0, 163));
	actualOpponentPkm.setRandomMoves();
	setOpponentPkmTexture(actualOpponentPkm.getPath());
}

void WildPokemonState::Update(sf::Vector2f _mousePos)
{
	CommonUpdate(_mousePos);
}

void WildPokemonState::Draw(sf::RenderWindow& _window)
{
	CommonDraw(_window);
}
