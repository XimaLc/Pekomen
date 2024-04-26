#include "Player.h"

void Player::Draw(sf::RenderWindow& window)
{
	sprite.setTextureRect(sf::IntRect(animState * 32, dir * 32, 32, 32));
	sprite.setPosition(position.x * 32.f, position.y * 32.f);
	window.draw(sprite);
}

void Player::Update()
{
}

void Player::addStarter(int _type)
{
    m_playerTeam->addStarter(_type);
}

void Player::healTeam()
{
    m_playerTeam->healAll();
}

Player::Player(std::string _name, sf::Texture& _texture)
{
    m_playerTeam = new Team();
    m_playerInventory = new Inventory();

    sprite.setTextureRect({ 0, 0, 32, 32 });
    sprite.setTexture(_texture);
    position = { 0, 0 };
    animState = 0;
    animState = 0;
    name = _name;
    dir = 0;
}

Player::Player()
{
}

Player::~Player()
{
    //delete m_playerTeam;
}
