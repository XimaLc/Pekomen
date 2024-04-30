#pragma once
#include <SFML/Graphics.hpp>

class Radio
{
	sf::Sprite m_sprite;
	sf::Texture m_texture;

public:
	Radio();

	void Update();
	void Draw(sf::RenderWindow& _window);
};

