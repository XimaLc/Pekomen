#include "WildPokemonState.h"
#include "DB.h"

WildPokemonState::WildPokemonState()
{
}

WildPokemonState::WildPokemonState(Player& _player) : CombatState(_player)
{
	actualOpponentPkm = DB::getPokemonById(iRand(0, 163));
	actualOpponentPkm.setRandomMoves();
	setOpponentPkmTexture(actualOpponentPkm.getPath());

	m_ballBouton.setOnClick([this]() {if (m_ballBouton.timer > 0.5f) { m_ballBouton.timer = 0; catchPokemon(); }});
}

bool WildPokemonState::catchPokemon()
{

}

void WildPokemonState::Update(sf::Vector2f _mousePos)
{
	CommonUpdate(_mousePos);
}

void WildPokemonState::Draw(sf::RenderWindow& _window)
{
	CommonDraw(_window);
}
