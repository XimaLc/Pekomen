#include "WildPokemonState.h"
#include "DB.h"

WildPokemonState::WildPokemonState()
{
	actualPlayerPkm = m_player.getTeam()->getPokemons()[0];
	actualOpponentPkm = DB::getPokemonById(iRand(0, 163));
	setPlayerPkmTexture(actualPlayerPkm.getPath());
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
