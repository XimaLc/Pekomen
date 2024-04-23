#include "WildPokemonState.h"
#include "DB.h"

WildPokemonState::WildPokemonState()
{
	m_player = new Player();

	actualOpponentPkm = DB::getPokemonById(iRand(0, 163));
	actualOpponentPkm.setRandomMoves();
	setOpponentPkmTexture(actualOpponentPkm.getPath());
}

WildPokemonState::WildPokemonState(Player& _player)
{
	m_player = &_player;

	actualOpponentPkm = DB::getPokemonById(iRand(0, 163));
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
