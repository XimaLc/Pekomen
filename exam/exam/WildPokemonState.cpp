#include "WildPokemonState.h"
#include "DB.h"
#include "StateManager.h"

WildPokemonState::WildPokemonState()
{
}

WildPokemonState::WildPokemonState(Player& _player) : CombatState(_player)
{
	actualOpponentPkm = DB::getPokemonById(iRand(0, 163));
	actualOpponentPkm.setRandomMoves();
	setOpponentPkmTexture(actualOpponentPkm.getPath());

	m_fuiteBouton.setOnClick([this]() {if (m_fuiteBouton.timer > 0.5f) { m_fuiteBouton.timer = 0; StateManager::ChangeState(GAME_STATE); }});
	m_ballBouton.setOnClick([this]() 
		{
			if (m_ballBouton.timer > 0.5f) 
			{ 
				m_ballBouton.timer = 0;
				m_isBallMenuOpen = true;
				m_isSacMenuOpen = false;
			}
		});

	m_pokeBallBouton = Bouton({ 1500, 830 }, { 200, 100 }, { 0,0,64,64 }, POKEBALL_BOUTON);
	m_superBallBouton = Bouton({ 1700, 830 }, { 200, 100 }, { 64,0,64,64 }, POKEBALL_BOUTON);
	m_hyperBallBouton = Bouton({ 1500, 930 }, { 200, 100 }, { 128,0,64,64 }, POKEBALL_BOUTON);
	m_maitreBallBouton = Bouton({ 1700, 930 }, { 200, 100 }, { 192,0,64,64 }, POKEBALL_BOUTON);
}

bool WildPokemonState::catchPokemon()
{
	return false;
}

void WildPokemonState::Update(sf::Vector2f _mousePos)
{
	CommonUpdate(_mousePos);
	if (m_isBallMenuOpen)
	{
		m_pokeBallBouton.Update(_mousePos);
		m_superBallBouton.Update(_mousePos);
		m_hyperBallBouton.Update(_mousePos);
		m_maitreBallBouton.Update(_mousePos);
		m_retourAttaqueBouton.Update(_mousePos);
	}
}

void WildPokemonState::Draw(sf::RenderWindow& _window)
{
	CommonDraw(_window);
	if (m_isBallMenuOpen)
	{
		m_pokeBallBouton.Draw(_window);
		m_superBallBouton.Draw(_window);
		m_hyperBallBouton.Draw(_window);
		m_maitreBallBouton.Draw(_window);
		m_retourAttaqueBouton.Draw(_window);
	}
}
