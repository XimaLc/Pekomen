#include "SaveMenu.h"
#include "InGameMenu.h"
#include "StateManager.h"

SaveMenu::SaveMenu()
{
	isSaveMenuOpen = false;

	m_team = StateManager::getPlayer().getTeam();

	m_confirmSaveBouton = Bouton({ 300, 650 }, { 200, 80 }, "Confirmer");
	m_cancelSaveBouton = Bouton({ 900, 650 }, { 200, 80 }, "Retour");
	
	auto confirmSaveAction = [this]() {if (m_confirmSaveBouton.timer > 1.f) { m_confirmSaveBouton.timer = 0; m_team->save(); isSaveMenuOpen = false; }};
	m_confirmSaveBouton.setOnClick(confirmSaveAction);

	auto cancelSaveAction = [this]() {if (m_cancelSaveBouton.timer > 1.f) { m_cancelSaveBouton.timer = 0; isSaveMenuOpen = false; }};
	m_cancelSaveBouton.setOnClick(cancelSaveAction);
}

void SaveMenu::OpenClose()
{
	isSaveMenuOpen = !isSaveMenuOpen;
}

void SaveMenu::Update(sf::Vector2f _mousePos)
{
	m_confirmSaveBouton.Update(_mousePos);
	m_cancelSaveBouton.Update(_mousePos);

	if (m_confirmSaveBouton.isClicked())
		m_confirmSaveBouton.useClickAction();

	if (m_cancelSaveBouton.isClicked())
		m_cancelSaveBouton.useClickAction();
}

void SaveMenu::Draw(sf::RenderWindow& _window)
{
	if (isSaveMenuOpen)
	{
		_window.draw(shape);
		m_confirmSaveBouton.Draw(_window);
		m_cancelSaveBouton.Draw(_window);
	}
}

