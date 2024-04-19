#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>
#include <SFML/Graphics/Sprite.hpp>

class Entity
{
protected:
	std::string name;
	sf::Sprite sprite;
public:
	virtual void Update() = 0;
	virtual void Draw(sf::RenderWindow& _window) = 0;
};

	