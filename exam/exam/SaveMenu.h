#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Bouton.h"

class SaveMenu
{
	sf::RectangleShape shape;

	Bouton m_confirmSaveBouton;
	Bouton m_cancelSaveBouton;

public:
	SaveMenu();
	bool isSaveMenuOpen;

	void OpenClose();

	void Update(sf::Vector2f _mousePos);
	void Draw(sf::RenderWindow& _window);
};

