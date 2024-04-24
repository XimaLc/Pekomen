#include "SaveMenu.h"
#include "InGameMenu.h"
#include "StateManager.h"

SaveMenu::SaveMenu()
{

	isSaveMenuOpen = false;

	m_team = StateManager::getPlayer().getTeam();

	m_confirmSaveBouton = Bouton({ 300, 400 }, { 200, 80 }, "Confirmer");
	m_cancelSaveBouton = Bouton({ 900, 400 }, { 200, 80 }, "Retour");
	
	m_confirmSaveBouton.setOnClick([this]() 
		{
			if (m_confirmSaveBouton.timer > 1.f) 
			{ 
				m_confirmSaveBouton.timer = 0; 
				m_team->save(); 
				isSaveMenuOpen = false; 
			}
		});

	m_cancelSaveBouton.setOnClick([this]() 
		{
			if (m_cancelSaveBouton.timer > 1.f) 
			{ 
				m_cancelSaveBouton.timer = 0; 
				isSaveMenuOpen = false; 
			}
		});
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
		m_confirmSaveBouton.Draw(_window);
		m_cancelSaveBouton.Draw(_window);
	}
}

