#include "Map.h"

void Map::autotiling(int _layerID, int _x, int _y)
{
    if (_layerID == 1)
        layer1.autotiling(_x, _y, width, height, 0);

    if (_layerID == 2)
        layer2.autotiling(_x, _y, width, height, 0);
        
    if (_layerID == 3)
        layer3.autotiling(_x, _y, width, height, 0);

    if (_layerID == 4)
        layer4.autotiling(_x, _y, width, height, 0);

    //if(_layerId == 5)
        //Pas d'autotiling pour la layer5   
}

void Map::setLayersTexture()
{
    layer1.setTexture("../Files/Textures/Map/layer1.png");
    layer2.setTexture("../Files/Textures/Map/layer2.png");
    layer3.setTexture("../Files/Textures/Map/layer3.png");
    layer4.setTexture("../Files/Textures/Map/layer4.png");
    layer5.setTexture("../Files/Textures/Map/layer5.png");
    setSprites();
}

void Map::setSprites()
{
    layer1.setSpriteTexture();
    layer2.setSpriteTexture();
    layer3.setSpriteTexture();
    layer4.setSpriteTexture();
    layer5.setSpriteTexture();
}

void Map::load(std::string name = "map1")
{
    std::string tmp;
    std::string path = "../Files/Maps/" + name + ".txt";
    std::ifstream file(path, std::ios::in);
    if (file.is_open())
    {
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                file >> tmp;
                file.ignore();

                layer1.setTile(x, y, tmp[0], width);
                layer1.autotiling(x, y, width, height, false);

                layer2.setTile(x, y, tmp[1], width);
                layer2.autotiling(x, y, width, height, false);

                layer3.setTile(x, y, tmp[2], width);
                layer3.autotiling(x, y, width, height, false);

                layer4.setTile(x, y, tmp[3], width);
                layer4.autotiling(x, y, width, height, false);

                layer5.setTile(x, y, tmp[4], width);
            }
        }
        file.close();
    }
}

void Map::Draw(sf::RenderWindow& _window, std::vector<int> displayedLayers)
{
    for (int i = 0; i < displayedLayers.size(); i++)
    {
        if (displayedLayers[i] == 1)
            layer1.Draw(_window, width, height);
        else if (displayedLayers[i] == 2)
            layer2.Draw(_window, width, height);
        else if (displayedLayers[i] == 3)
            layer3.Draw(_window, width, height);
        else if (displayedLayers[i] == 4)
            layer4.Draw(_window, width, height);
        else if (displayedLayers[i] == 5)
            layer5.Draw(_window, width, height);
    }
}

bool Map::canGo(sf::Vector2i playerPos, sf::Vector2i direction)
{
    int tile = layer1.getTile({ playerPos.x + direction.x, playerPos.y + direction.y }, width);
    if (tile == 2)
        return false;

    tile = layer2.getTile({ playerPos.x + direction.x, playerPos.y + direction.y }, width);
    if (tile == 1)
        return false;

    tile = layer3.getTile({ playerPos.x + direction.x, playerPos.y + direction.y }, width);
    if (tile == 2)
        return false;

    tile = layer4.getTile({ playerPos.x + direction.x, playerPos.y + direction.y }, width);
    if (tile == 1)
        return false;

    tile = layer5.getTile({ playerPos.x + direction.x, playerPos.y + direction.y }, width);
    if (tile == 1 || tile == 2 || tile == 3 || tile == 5 || tile == 6 || tile == 22 || tile == 23 || tile == 24 || tile == 25 || tile == 26 || tile == 37 || tile == 38 || tile == 39)
        return false;

    return true;

}

void Map::setSpriteTextureRect(int _layerId, sf::IntRect _rect)
{
}

void Map::setSpritePosition(int _layerId, int _x, int _y)
{
}

bool Map::isInGrass(sf::Vector2i _pos)
{
    if (layer5.getTile(_pos, width) == 7)
        return true;

    return false;
}

Map::Map()
{
    height = 100;
    width = 100;

    layer1.fill(width, height);
    layer2.fill(width, height);
    layer3.fill(width, height);
    layer4.fill(width, height);
    layer5.fill(width, height);
}