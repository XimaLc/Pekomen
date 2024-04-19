#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Layer
{
	sf::Texture texture;
	sf::Sprite sprite;

	std::vector<sf::Vector2i> tiles;
public:	
	void autotiling(int _x, int _y, int _width, int _height, bool _isReccursive);
	void setSpriteTexture();
	void setTexture(std::string _path);

	std::vector<sf::Vector2i> getTiles();
	int getTile(sf::Vector2i _position, int width);

	void setTile(int x, int y, char tile, int width);

	void fill(int _width, int _height);

	void Draw(sf::RenderWindow& _window, int _width, int _height);


};

