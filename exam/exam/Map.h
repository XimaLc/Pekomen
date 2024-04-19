#pragma once
#include "Layer.h"
#include <vector>
#include <fstream>
#include <SFML/Graphics/RenderWindow.hpp>

class Map
{
	int height;
	int width;

	Layer layer1;
	Layer layer2;
	Layer layer3;
	Layer layer4;
	Layer layer5;

public:
	Map();

	inline int getWidth() { return width; }
	inline int getHeight() { return height; }

	void autotiling(int _layderID, int _x, int _y);

	void setLayersTexture();
	void setSprites();
	void load(std::string name);

	void Draw(sf::RenderWindow& _window, std::vector<int> displayedLayers);

	bool canGo(sf::Vector2i playerPos, sf::Vector2i direction);
	

	void setSpriteTextureRect(int _layerId, sf::IntRect _rect);
	void setSpritePosition(int _layerId, int _x, int _y);
};

