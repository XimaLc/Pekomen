#pragma once
#include "tools.h"
#include <SFML/Graphics.hpp>

class InGameMenu
{
	bool isMenuOpen;

	sf::RectangleShape m_menuBackground;
public:
	InGameMenu();

	void Update();
	void Draw();
};

