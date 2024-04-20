#include "SaveMenu.h"
#include "InGameMenu.h"

SaveMenu::SaveMenu()
{
	shape.setFillColor(sf::Color(211, 211, 211));
	shape.setSize({ 1500, 600 });
	shape.setPosition({ 20, 20 });

	m_confirmSaveBouton = Bouton({ 300, 650 }, { 200, 80 }, "Confirmer");
	m_cancelSaveBouton = Bouton({ 900, 650 }, { 200, 80 }, "Retour");
	
	auto cancelSaveBouton = [this]() {if (m_cancelSaveBouton.timer > 1.f) { m_cancelSaveBouton.timer = 0; ; }};
	m_cancelSaveBouton.setOnClick(cancelSaveBouton);
}

void SaveMenu::OpenClose()
{
	isSaveMenuOpen = !isSaveMenuOpen;
}

void SaveMenu::Update(sf::Vector2f _mousePos)
{
	m_confirmSaveBouton.Update(_mousePos);
	m_cancelSaveBouton.Update(_mousePos);
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

