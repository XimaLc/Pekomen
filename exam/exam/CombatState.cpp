#include "CombatState.h"
#include "StateManager.h"
#include "GameState.h"

CombatState::CombatState()
{
	m_playerInfoBar = pokemonInGameInfoBar(PLAYER);
	m_opponentInfoBar = pokemonInGameInfoBar(OPPONENT);

	actualPlayerPkm = m_player->getTeam()->getPokemons()[0];
	setPlayerPkmTexture(actualPlayerPkm.getPath());

	m_opponentPkmSprite.setPosition(1300, 250);
	m_opponentPkmSprite.setScale(0.5, 0.5);

	m_playerPkmSprite.setPosition(200, 600);
	m_playerPkmSprite.setScale(0.5, 0.5);

	timer = 0.f;

	m_backgroundTexture.loadFromFile("../Files/Textures/CombatBackground.png");
	m_backgroundSprite.setTexture(m_backgroundTexture);

	m_backgroundSprite.setTextureRect({ 0, 0, 220, 112 });
	m_backgroundSprite.setScale({ 8.9f, 9.6f });

	m_attaqueBouton = Bouton({ 1500, 830 }, { 200, 100 }, "Attaquer");
	m_pokemonBouton = Bouton({ 1500, 930 }, { 200, 100 }, "Pokemon");
	m_sacBouton = Bouton({ 1700, 830 }, { 200, 100 }, "Sac");
	m_fuiteBouton = Bouton({ 1700, 930 }, { 200, 100 }, "Fuir");

	auto pokemonBoutonAction = [this]() {if (m_pokemonBouton.timer > 0.5f) { m_pokemonBouton.timer = 0; m_pokemonMenu.OpenClose(); }};
	m_pokemonBouton.setOnClick(pokemonBoutonAction);

	auto fuiteBoutonAction = [this]() {if (m_fuiteBouton.timer > 0.5f) { m_fuiteBouton.timer = 0; StateManager::ChangeState(GAME); }};
	m_fuiteBouton.setOnClick(fuiteBoutonAction);

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
	m_playerInfoBar.setPokemon(actualPlayerPkm);
}

void CombatState::CommonUpdate(sf::Vector2f _mousePos)
{
	timer += GetDeltaTime();
	
	if (inCombat)
	{
		m_opponentInfoBar.Update(actualOpponentPkm.getStat(CURRENTHP));
		m_playerInfoBar.Update(actualPlayerPkm.getStat(CURRENTHP));
	}
	
	m_attaqueBouton.Update(_mousePos);
	m_pokemonBouton.Update(_mousePos);
	m_sacBouton.Update(_mousePos);
	m_fuiteBouton.Update(_mousePos);

	if (m_pokemonMenu.m_isPokemonMenuOpen)
		m_pokemonMenu.Update(_mousePos);

	if (m_fuiteBouton.isClicked())
	{
		m_fuiteBouton.useClickAction();
		inCombat == false;
	}

	if (m_pokemonBouton.isClicked())
		m_pokemonBouton.useClickAction();
}

void CombatState::CommonDraw(sf::RenderWindow& _window)
{
	_window.draw(m_backgroundSprite);

	m_attaqueBouton.Draw(_window);
	m_pokemonBouton.Draw(_window);
	m_sacBouton.Draw(_window);
	m_fuiteBouton.Draw(_window);

	if (actualOpponentPkm.getIsAlive())
	{
		m_opponentPkmSprite.setTexture(*m_opponentPkmTexture);
		_window.draw(m_opponentPkmSprite);
		m_opponentInfoBar.Draw(_window);
	}
	
	if (actualPlayerPkm.getIsAlive())
	{
		m_playerPkmSprite.setTexture(*m_playerPkmTexture);
		_window.draw(m_playerPkmSprite);
		m_playerInfoBar.Draw(_window);
	}

	if (m_pokemonMenu.m_isPokemonMenuOpen)
		m_pokemonMenu.Draw(_window);
}

void CombatState::HandleKeyboard(sf::Event _event)
{
	if (_event.key.code == sf::Keyboard::Escape && timer > 0.5f)
	{
		timer = 0;
		StateManager::ChangeState(MENU);
	}
}