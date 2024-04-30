#include "Radio.h"



Radio::Radio()
{
	m_texture.loadFromFile("../Files/Textures/radio.png");
	m_sprite.setPosition({10*32, 10*32});
}

void Radio::Update()
{

}

void Radio::Draw(sf::RenderWindow& _window)
{
	m_sprite.setTexture(m_texture);
	_window.draw(m_sprite);
}
