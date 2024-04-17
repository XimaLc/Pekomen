#include "MenuState.h"
#include "StateManager.h"

MenuState::MenuState()
{
	m_playBouton = Bouton({ 860, 230 }, { 200, 80 }, "Jouer");
	m_optBouton = Bouton({ 860, 450 }, { 200, 80 }, "Options");
	m_leaveBouton = Bouton({ 860, 670 }, { 200, 80 }, "Quitter");

	auto playBoutonAction = [this]() { if (m_playBouton.timer > 1.f) { StateManager::ChangeState(GAME); } };
	m_playBouton.setOnClick(playBoutonAction);

	auto optBoutonAction = [this]() { if (m_optBouton.timer > 1.f) { std::cout << "Options" << std::endl; m_optBouton.timer = 0; }};
	m_optBouton.setOnClick(optBoutonAction);
}

void MenuState::Update(const sf::Vector2f _mousePos)
{
	m_playBouton.Update(_mousePos);
	m_optBouton.Update(_mousePos);
	m_leaveBouton.Update(_mousePos);

	if (m_playBouton.isClicked())
	{
		m_playBouton.useClickAction();
	}
	
	if (m_optBouton.isClicked())
	{
		m_optBouton.useClickAction();
	}
	
	if (m_leaveBouton.isClicked())
	{
		exit(0);
	}
}

void MenuState::Draw(sf::RenderWindow& _window)
{
	m_playBouton.Draw(_window);
	m_optBouton.Draw(_window);
	m_leaveBouton.Draw(_window);
}

void MenuState::HandleKeyboard(sf::Event _event)
{
}

void MenuState::HandleEvent(sf::Event _event, sf::RenderWindow& _window)
{
}