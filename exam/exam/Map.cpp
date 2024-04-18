#include "Map.h"

void Map::setLayersTexture()
{
    layer1.setTexture("../Files/Textures/layer1.png");
    setSprites();
}

void Map::setSprites()
{
    layer1.setSpriteTexture();
}