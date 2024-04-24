#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Bouton.h"
#include "Team.h"
class SaveMenu
{
	Bouton m_confirmSaveBouton;
	Bouton m_cancelSaveBouton;

	Team* m_team;
public:
	SaveMenu();

	bool isSaveMenuOpen;

	void OpenClose();

	void Update(sf::Vector2f _mousePos);
	void Draw(sf::RenderWindow& _window);
};

