#include "CombatState.h"
#include "StateManager.h"
#include "GameState.h"

CombatState::CombatState()
{
	inCombat = false;
	timer = 0.f;

	m_player = new Player();
}

CombatState::CombatState(Player& _player)
{
	m_isMainMenuOpen = true;
	m_isAttaqueMenuOpen = m_isPokemonMenuOpen = m_isSacMenuOpen = false;

	m_player = &_player;

	m_playerInfoBar = pokemonInGameInfoBar(PLAYER);
	m_opponentInfoBar = pokemonInGameInfoBar(OPPONENT);

	actualPlayerPkm = 0;
	setPlayerPkmTexture(m_player->getTeam()->getPokemons()[actualPlayerPkm].getPath());

	m_opponentPkmSprite.setPosition(1300, 100);
	m_opponentPkmSprite.setScale(0.5, 0.5);

	m_playerPkmSprite.setPosition(200, 600);
	m_playerPkmSprite.setScale(0.5, 0.5);

	timer = 0.f;

	m_backgroundTexture.loadFromFile("../Files/Textures/CombatBackground.png");
	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setPosition(0, -350);

	m_backgroundSprite.setTextureRect({ 0, 0, 220, 112 });
	m_backgroundSprite.setScale({ 8.9f, 13.f });

	m_attaqueBouton = Bouton({ 1500, 830 }, { 200, 100 }, "Attaquer");
	m_attaqueBouton.setOnClick([this]() 
		{
			if (m_isMainMenuOpen && m_attaqueBouton.timer > 0.5f) 
			{ 
				m_attaqueBouton.timer = 0; 
				m_isMainMenuOpen = false;
				m_isPokemonMenuOpen = false;
				m_isAttaqueMenuOpen = true;
			}
		});

	m_sacBouton = Bouton({ 1700, 830 }, { 200, 100 }, "Sac");
	m_sacBouton.setOnClick([this]()
		{
			if (m_sacBouton.timer > 0.5f) 
			{ 
				m_sacBouton.timer = 0;
				m_isMainMenuOpen = false;
				m_isPokemonMenuOpen = false;
				m_isSacMenuOpen = true; 
			}
		});

	m_pokemonBouton = Bouton({ 1500, 930 }, { 200, 100 }, "Pokemon");
	m_pokemonBouton.setOnClick([this]() 
		{
			if (m_pokemonBouton.timer > 0.5f) 
			{ 
				m_pokemonBouton.timer = 0;  
				m_isPokemonMenuOpen = !m_isPokemonMenuOpen;
			}
		});

	m_fuiteBouton = Bouton({ 1700, 930 }, { 200, 100 }, "Fuir");

	m_retourAttaqueBouton = Bouton({ 1400, 930 }, { 100, 100 }, "Back");
	m_retourAttaqueBouton.setOnClick([this]() 
		{
			if (m_retourAttaqueBouton.timer > 0.5) 
			{ 
				m_retourAttaqueBouton.timer = 0; 
				m_isAttaqueMenuOpen = false;
				m_isSacMenuOpen = false;
				m_isBallMenuOpen = false;
				m_isMainMenuOpen = true;
			}
		});

	m_move1Bouton = Bouton({ 1500, 830 }, { 200, 100 }, m_player->getTeam()->getPokemons()[actualPlayerPkm].getMoves()[0].getName());
	m_move1Bouton.setOnClick([this]() 
		{
			if (m_move1Bouton.timer > 0.5f && m_attaqueBouton.timer > 0.5f) 
			{ 
				m_move1Bouton.timer = 0; 
				m_attaqueBouton.timer = 0;
				nextMove = m_player->getTeam()->getPokemons()[actualPlayerPkm].getMoves()[0]; 
				TurnAction(); 
			}
		});
	
	m_move2Bouton = Bouton({ 1500, 930 }, { 200, 100 }, m_player->getTeam()->getPokemons()[actualPlayerPkm].getMoves()[1].getName());
	m_move2Bouton.setOnClick([this]() {if (m_move2Bouton.timer > 0.5) { m_move2Bouton.timer = 0; nextMove = m_player->getTeam()->getPokemons()[actualPlayerPkm].getMoves()[1]; TurnAction(); }});
	
	m_move3Bouton = Bouton({ 1700, 830 }, { 200, 100 }, m_player->getTeam()->getPokemons()[actualPlayerPkm].getMoves()[2].getName());
	m_move3Bouton.setOnClick([this]() {if (m_move3Bouton.timer > 0.5) { m_move3Bouton.timer = 0; nextMove = m_player->getTeam()->getPokemons()[actualPlayerPkm].getMoves()[2]; TurnAction(); }});
	
	m_move4Bouton = Bouton({ 1700, 930 }, { 200, 100 }, m_player->getTeam()->getPokemons()[actualPlayerPkm].getMoves()[3].getName());
	m_move4Bouton.setOnClick([this]() {if (m_move4Bouton.timer > 0.5) { m_move4Bouton.timer = 0; nextMove = m_player->getTeam()->getPokemons()[actualPlayerPkm].getMoves()[3]; TurnAction(); }});

	m_ballBouton = Bouton({ 1500, 830 }, { 200, 200 }, "BALLS");

	m_soinBouton = Bouton({1700, 830}, {200, 200}, "SOINS");
	m_soinBouton.setOnClick([this]() 
		{
			if (m_soinBouton.timer > 0.5f && m_sacBouton.timer > 0.5f) 
			{ 
				m_soinBouton.timer = 0; 
				//OUVRIR MENU ITEM SOIN
			}
		});

	inCombat = true;
}

CombatState::~CombatState()
{
	delete m_opponentPkmTexture;
	delete m_playerPkmTexture;
}

void CombatState::setOpponentPkmTexture(std::string _path)
{
	m_opponentPkmTexture = DB::getTexture(_path);
	m_opponentInfoBar.setPokemon(actualOpponentPkm);
}

void CombatState::setPlayerPkmTexture(std::string _path)
{
	m_playerPkmTexture = DB::getTexture(_path);
	m_playerInfoBar.setPokemon(m_player->getTeam()->getPokemons()[actualPlayerPkm]);
}

void CombatState::Attaque(int _damages, Pokemon& _target)
{
	_target.takeDamages(_damages);
}

void CombatState::TurnAction()
{
	int x = iRand(1, 4);

	if (m_player->getTeam()->getPokemons()[actualPlayerPkm].getStat(SPD) > actualOpponentPkm.getStat(SPD))
	{
		if (m_player->getTeam()->getPokemons()[actualPlayerPkm].getIsAlive())
		{
			Attaque(nextMove.getPower(), actualOpponentPkm);
			std::cout << m_player->getTeam()->getPokemons()[actualPlayerPkm].getName() << " a mis " << std::to_string(nextMove.getPower()) << " degats;" << std::endl;
		}
		if (actualOpponentPkm.getIsAlive())
		{
			Attaque(actualOpponentPkm.getMoves()[x].getPower(), m_player->getTeam()->getPokemons()[actualPlayerPkm]);
			std::cout << actualOpponentPkm.getName() << " a mis " << std::to_string(actualOpponentPkm.getMoves()[x].getPower()) << " degats;" << std::endl;
		}
	}
	else if (m_player->getTeam()->getPokemons()[actualPlayerPkm].getStat(SPD) < actualOpponentPkm.getStat(SPD))
	{
		if (actualOpponentPkm.getIsAlive())
		{
			Attaque(actualOpponentPkm.getMoves()[x].getPower(), m_player->getTeam()->getPokemons()[actualPlayerPkm]);
			std::cout << actualOpponentPkm.getName() << " a mis " << std::to_string(actualOpponentPkm.getMoves()[x].getPower()) << " degats;" << std::endl;
		}
		
		if (m_player->getTeam()->getPokemons()[actualPlayerPkm].getIsAlive())
		{
			Attaque(nextMove.getPower(), actualOpponentPkm);
			std::cout << m_player->getTeam()->getPokemons()[actualPlayerPkm].getName() << " a mis " << std::to_string(nextMove.getPower()) << " degats;" << std::endl;
		}
	}
}

void CombatState::CommonUpdate(sf::Vector2f _mousePos)
{
	timer += GetDeltaTime();

	if (inCombat)
	{
		m_opponentInfoBar.Update(actualOpponentPkm.getStat(CURRENTHP));
		m_playerInfoBar.Update(m_player->getTeam()->getPokemons()[actualPlayerPkm].getStat(CURRENTHP));
	}

	if (m_isMainMenuOpen)
	{
		m_attaqueBouton.Update(_mousePos);
		m_pokemonBouton.Update(_mousePos);
		m_sacBouton.Update(_mousePos);
		m_fuiteBouton.Update(_mousePos);

		if (m_isPokemonMenuOpen)
			m_pokemonMenu.Update(_mousePos);
	}
	else if (m_isAttaqueMenuOpen)
	{
		m_attaqueBouton.UpdateTimer();
		m_move1Bouton.Update(_mousePos);
		m_move2Bouton.Update(_mousePos);
		m_move3Bouton.Update(_mousePos);
		m_move4Bouton.Update(_mousePos);
		m_retourAttaqueBouton.Update(_mousePos);
	}
	else if (m_isSacMenuOpen)
	{
		m_sacBouton.UpdateTimer();
		m_ballBouton.Update(_mousePos);
		m_soinBouton.Update(_mousePos);
		m_retourAttaqueBouton.Update(_mousePos);
	}

	if (!m_isAttaqueMenuOpen) {}
	else if (m_move1Bouton.checkClick()) {}
	//else if (m_move2Bouton.checkClick()) {}
	//else if (m_move3Bouton.checkClick()) {}
	//else if (m_move4Bouton.checkClick()) {}
	
	if(!m_isSacMenuOpen) {}
	else if (m_ballBouton.checkClick()) {}
	else if (m_soinBouton.checkClick()) {}
	
	if(m_attaqueBouton.checkClick()) {}
	else if (m_pokemonBouton.checkClick()) {}
	else if (m_sacBouton.checkClick()) {}

	if (m_retourAttaqueBouton.checkClick()) {}

	if (inCombat && !actualOpponentPkm.getIsAlive())
	{
		m_player->getTeam()->getPokemons()[actualPlayerPkm].giveXp(50);
		m_player->getTeam()->evolvePokemons();
		StateManager::ChangeState(GAME_STATE);
		inCombat = false;
	}
	else if (inCombat && !m_player->getTeam()->getPokemons()[actualPlayerPkm].getIsAlive())
	{
		StateManager::ChangeState(GAME_STATE);
		inCombat = false;
	}
	else if (m_fuiteBouton.checkClick()) {}
}

void CombatState::CommonDraw(sf::RenderWindow& _window)
{
	_window.draw(m_backgroundSprite);

	if (actualOpponentPkm.getIsAlive())
	{
		m_opponentPkmSprite.setTexture(*m_opponentPkmTexture);
		_window.draw(m_opponentPkmSprite);
		m_opponentInfoBar.Draw(_window);
	}
	if (m_player->getTeam()->getPokemons()[actualPlayerPkm].getIsAlive())
	{
		m_playerPkmSprite.setTexture(*m_playerPkmTexture);
		_window.draw(m_playerPkmSprite);
		m_playerInfoBar.Draw(_window);
	}

	if (m_isMainMenuOpen)
	{
		m_attaqueBouton.Draw(_window);
		m_pokemonBouton.Draw(_window);
		m_sacBouton.Draw(_window);
		m_fuiteBouton.Draw(_window);
		if (m_isPokemonMenuOpen)
			m_pokemonMenu.Draw(_window);
	}
	else if (m_isAttaqueMenuOpen)
	{
		m_move1Bouton.Draw(_window);
		m_move2Bouton.Draw(_window);
		m_move3Bouton.Draw(_window);
		m_move4Bouton.Draw(_window);
		m_retourAttaqueBouton.Draw(_window);
	}
	else if (m_isSacMenuOpen)
	{
		m_ballBouton.Draw(_window);
		m_soinBouton.Draw(_window);
		m_retourAttaqueBouton.Draw(_window);
	}
}

void CombatState::HandleKeyboard(sf::Event _event)
{
	if (_event.key.code == sf::Keyboard::Escape && timer > 0.5f)
	{
		timer = 0;
		StateManager::ChangeState(MENU_STATE);
	}
}