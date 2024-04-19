#include "CombatState.h"
#include "StateManager.h"

CombatState::CombatState()
{
	timer = 0.f;

	m_backgroundTexture.loadFromFile("../Files/Textures/CombatBackground.png");
	m_backgroundSprite.setTexture(m_backgroundTexture);

	m_backgroundSprite.setTextureRect({ 0, 0, 220, 112 });
	m_backgroundSprite.setScale({ 8.9f, 8.f });

	m_attaqueBouton = Bouton({ 1500, 830 }, { 200, 100 }, "Attaquer");
	m_pokemonBouton = Bouton({ 1500, 930 }, { 200, 100 }, "Pokemon");
	m_sacBouton = Bouton({ 1700, 830 }, { 200, 100 }, "Sac");
	m_fuiteBouton = Bouton({ 1700, 930 }, { 200, 100 }, "Fuir");

	auto fuiteBoutonAction = [this]() {if (m_fuiteBouton.timer > 0.5f) { m_fuiteBouton.timer = 0; StateManager::ChangeState(GAME); }};
	m_fuiteBouton.setOnClick(fuiteBoutonAction);
}

void CombatState::CommonUpdate(sf::Vector2f _mousePos)
{
	timer += GetDeltaTime();
	
	m_attaqueBouton.Update(_mousePos);
	m_pokemonBouton.Update(_mousePos);
	m_sacBouton.Update(_mousePos);
	m_fuiteBouton.Update(_mousePos);

	if (m_fuiteBouton.isClicked())
	{
		m_fuiteBouton.useClickAction();
	}
}

void CombatState::CommonDraw(sf::RenderWindow& _window)
{
	_window.draw(m_backgroundSprite);

	m_attaqueBouton.Draw(_window);
	m_pokemonBouton.Draw(_window);
	m_sacBouton.Draw(_window);
	m_fuiteBouton.Draw(_window);
}

void CombatState::HandleKeyboard(sf::Event _event)
{
	if (_event.key.code == sf::Keyboard::Escape && timer > 0.5f)
	{
		timer = 0;
		StateManager::ChangeState(MENU);
	}
}

void CombatState::HandleEvent(sf::Event _event, sf::RenderWindow& _window)
{
}
