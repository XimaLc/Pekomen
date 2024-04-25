#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>
#include <SFML/Graphics/Sprite.hpp>

enum DIRECTIONS { down, left, right, up };

class Entity
{
protected:
	std::string name;
	sf::Sprite sprite;

	sf::Vector2i position;

	int animState;
	int dir;

public:
	void move(int x, int y);
	void anim(int x, int y);
	
	virtual void Update() = 0;
	virtual void Draw(sf::RenderWindow& _window) = 0;
};

	