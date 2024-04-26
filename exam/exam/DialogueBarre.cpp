#include "DialogueBarre.h"
#include "DB.h"
#include "tools.h"

DialogueBarre::DialogueBarre()
{
	m_texture = nullptr;
	isOpen = false;
	timer = 0;
}

DialogueBarre::DialogueBarre(sf::Vector2f _pos, int scale, bool _isOpen)
{
	isOpen = _isOpen;
	timer = 0;
	m_font.loadFromFile("../Files/Fonts/Pokemon.ttf");

	m_texture = DB::getTexture(ACTION_BAR);
	m_sprite.setPosition(_pos);
	m_sprite.setScale(scale, 1);


	m_text.setFillColor(sf::Color::Yellow);
	m_text.setPosition(_pos.x + 100, _pos.y + 70);
	m_text.setString("");
}

void DialogueBarre::setString(std::string _str)
{
	timer = 0;
	m_text.setString(_str);
}

void DialogueBarre::Update(bool _closeIt)
{
	timer += GetDeltaTime();
	if (timer >= 3.f)
	{
		timer = 0;
		m_text.setString("");
		if(_closeIt)
			isOpen = false;
	}
}

void DialogueBarre::Draw(sf::RenderWindow& _window)
{
	m_sprite.setTexture(*m_texture);
	_window.draw(m_sprite);

	m_text.setFont(m_font);
	_window.draw(m_text);
}
