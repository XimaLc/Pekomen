#include "Pnj.h"

Pnj::Pnj()
{
}

Pnj::Pnj(PNJ_TYPE _type, sf::Vector2i _pos)
{
	if (_type == HEALER)
	{
		m_texture.loadFromFile("../Files/Textures/HealerTexture.png");
		position = _pos;
		sprite.setPosition(position.x * 32, position.y * 32);
		sprite.setTextureRect({ 32, 32, 32, 32 });
	}
	else if (_type == TRAINER)
		m_texture.loadFromFile("../Files/Textures/TrainerTexture.png");
	else if (_type == SHOP)
		m_texture.loadFromFile("../Files/Textures/ShopTexture.png");
}

void Pnj::Update()
{

}

void Pnj::Draw(sf::RenderWindow& _window)
{
	sprite.setTexture(m_texture);
	_window.draw(sprite);
}

void Pnj::HandleEvent(sf::Event _event)
{
}
