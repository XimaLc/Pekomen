#include "SaveMenu.h"

SaveMenu::SaveMenu()
{
	shape.setFillColor(sf::Color(211, 211, 211));
	shape.setSize({ 1500, 600 });
}

void SaveMenu::Update()
{
}

void SaveMenu::Draw(sf::RenderWindow& _window)
{
	_window.draw(shape);
}

