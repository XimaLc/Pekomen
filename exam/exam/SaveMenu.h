#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class SaveMenu
{
	bool isOpen;
	sf::RectangleShape shape;

public:
	SaveMenu();

	void OpenClose();

	void Update();
	void Draw(sf::RenderWindow& _window);
};

