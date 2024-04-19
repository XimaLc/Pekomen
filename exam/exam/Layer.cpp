#include "Layer.h"

void Layer::autotiling(int _x, int _y, int _width, int _height, bool _isReccursive)
{
    int z = 0;

    if (_y > 0)
    {
        if (!(tiles[_x + (_y - 1) * _width].y == tiles[_x + _y * _width].y))
            z += 1;
        if (!_isReccursive)
            autotiling(_x, _y - 1, _width, _height, true);
    }
    else
        z += 1;
    if (_y < _height - 1)
    {
        if (!(tiles[_x + (_y + 1) * _width].y == tiles[_x + _y * _width].y))
            z += 4;
        if (!_isReccursive)
            autotiling(_x, _y + 1, _width, _height, true);
    }
    else
        z += 4;
    if (_x > 0)
    { 
        if (!(tiles[(_x - 1) + _y * _width].y == tiles[_x + _y * _width].y))
            z += 8;
        if (!_isReccursive)
            autotiling(_x - 1, _y, _width, _height, true);
    }
    else
        z += 8;
    if (_x < _height - 1)
    {
        if (!(tiles[(_x + 1) + _y * _width].y == tiles[_x + _y * _width].y))
            z += 2;
        if (!_isReccursive)
            autotiling(_x + 1, _y, _width, _height, true);
    }
    else
        z += 2;

    tiles[_x + _y * _width].x = z;
}

void Layer::setSpriteTexture()
{
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

void Layer::setTexture(std::string _file)
{
	texture.loadFromFile(_file);
}

std::vector<sf::Vector2i> Layer::getTiles()
{
    return tiles;
}

int Layer::getTile(sf::Vector2i _position, int width)
{
    return tiles[_position.x + _position.y * width].y;
}

void Layer::setTile(int x, int y, char tile, int width)
{
    int tileint = tile - '0';
    tiles[x + y * width].y = tileint;
    tiles[x + y * width].x = 0;
    //tiles.push_back({tileint,0 });
}

void Layer::fill(int _width, int _height)
{
    tiles.clear();
    for (int y2 = 0; y2 < _width; y2++)
    {
        for (int x2 = 0; x2 < _height; x2++)
        {
            tiles.push_back({ 0, 0 });
        }
    }
}

void Layer::Draw(sf::RenderWindow& _window, int _width, int _height)
{
    sf::IntRect rect;

    for (int y = 0; y < _height; y++)
    {
        for (int x = 0; x < _width; x++)
        {
            rect = sf::IntRect(32 * tiles[x + y * _width].x, 32 * tiles[x + y * _width].y, 32, 32);

            sprite.setTextureRect(rect);
            sprite.setPosition(x * 32, y * 32);
            _window.draw(sprite);
        }
    }
}
