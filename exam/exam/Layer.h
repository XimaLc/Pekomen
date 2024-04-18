#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Layer
{
	sf::Texture texture;
	sf::Sprite sprite;

	std::vector<sf::Vector2i> tiles;
public:	
	void autotiling(int _x, int _y, int _width, int _height, bool _isReccursive);
	void setTexture(std::string _path);
	void setSpriteTexture();

};

