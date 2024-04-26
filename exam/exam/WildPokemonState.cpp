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
	m_pokeBallBouton.setOnClick([this]()
		{
			if (m_pokeBallBouton.timer > 0.5f)
			{
				if (m_player->getInventory().getBallAmount(1) >= 1)
					catchPokemon(1);
			}
		});


	m_superBallBouton = Bouton({ 1700, 830 }, { 200, 100 }, { 64,0,64,64 }, POKEBALL_BOUTON);
	m_superBallBouton.setOnClick([this]()
		{
			if (m_superBallBouton.timer > 0.5f)
			{
				if(m_player->getInventory().getBallAmount(2) >= 1) 
					catchPokemon(2);
			}
		});

	m_hyperBallBouton = Bouton({ 1500, 930 }, { 200, 100 }, { 128,0,64,64 }, POKEBALL_BOUTON);
	m_hyperBallBouton.setOnClick([this]()
		{
			if (m_hyperBallBouton.timer > 0.5f)
			{
				if (m_player->getInventory().getBallAmount(3) >= 1)
					catchPokemon(3);
			}
		});

	m_maitreBallBouton = Bouton({ 1700, 930 }, { 200, 100 }, { 192,0,64,64 }, POKEBALL_BOUTON);
	m_maitreBallBouton.setOnClick([this]()
		{
			if (m_maitreBallBouton.timer > 0.5f)
			{
				if (m_player->getInventory().getBallAmount(4) >= 1)
					catchPokemon(4);
			}
		});
}

bool WildPokemonState::catchPokemon(int _id)
{
	float x{ fRand(1, 100) };
	float bonus = DB::getBallByID(_id).getBonus();
	m_player->getInventory().withdrawBall(_id);
	if (x < bonus)
	{
		//Ajouter le pokemon a l'équipe si pas full
		return true;
	}
	return false;
}

void WildPokemonState::Update(sf::Vector2f _mousePos)
{
	
	if (m_isBallMenuOpen)
	{
		m_pokeBallBouton.Update(_mousePos);
		m_pokeBallBouton.setString(" x" + std::to_string(m_player->getInventory().getBallAmount(1)));
		m_superBallBouton.Update(_mousePos);
		m_superBallBouton.setString(" x" + std::to_string(m_player->getInventory().getBallAmount(2)));
		m_hyperBallBouton.Update(_mousePos);
		m_hyperBallBouton.setString(" x" + std::to_string(m_player->getInventory().getBallAmount(3)));
		m_maitreBallBouton.Update(_mousePos);
		m_maitreBallBouton.setString(" x" + std::to_string(m_player->getInventory().getBallAmount(4)));
		m_retourAttaqueBouton.Update(_mousePos);
	}

	if(!m_isBallMenuOpen) {}
	else if (m_pokeBallBouton.checkClick()) {}
	else if (m_superBallBouton.checkClick()) {}
	else if (m_hyperBallBouton.checkClick()) {}
	else if (m_maitreBallBouton.checkClick()) {}

	CommonUpdate(_mousePos);
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
