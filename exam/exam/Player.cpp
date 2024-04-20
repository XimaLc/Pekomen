#include "Player.h"

void Player::Draw(sf::RenderWindow& window)
{
	sprite.setTextureRect(sf::IntRect(animState * 32, dir * 32, 32, 32));
	sprite.setPosition(position.x * 32, position.y * 32);
	window.draw(sprite);
}

void Player::Update()
{
}

void Player::move(int x, int y)
{
	position.x += x;
	position.y += y;
}

void Player::anim(int x, int y)
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

Player::Player(std::string _name, sf::Texture& _texture)
{
    m_playerTeam = new Team();

    name = _name;
    sprite.setTexture(_texture);
    sprite.setTextureRect({ 0, 0, 32, 32 });
    animState = 0;
    position = { 0, 0 };
    dir = 0;
    animState = 0;
}

Player::Player()
{
}
