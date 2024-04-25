#include "Entity.h"

void Entity::move(int x, int y)
{
    position.x += x;
    position.y += y;
}

void Entity::anim(int x, int y)
{
    if (x == 0 && y == 1)
        dir = down;
    else if (x == 0 && y == -1)
        dir = up;
    else if (x == 1 && y == 0)
        dir = right;
    else if (x == -1 && y == 0)
        dir = left;

    animState++;
    if (animState >= 2)
        animState = 0;
}
