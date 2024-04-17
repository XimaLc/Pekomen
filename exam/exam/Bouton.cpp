#include "Bouton.h"
#include "tools.h"
#include "StateManager.h"

sf::Font Bouton::m_font;

Bouton::Bouton()
{
	m_currentState = BOUTON_BASE;
	timer = 0.f;
}

Bouton::Bouton(sf::Vector2f _pos, sf::Vector2f _size, std::string _string)
{
	m_currentState = BOUTON_BASE;

	m_font.loadFromFile("../Files/Fonts/Pokemon.ttf");

	m_shape.setPosition(_pos);
	m_shape.setSize(_size);

	m_text.setPosition(_pos.x + 20, _pos.y + 20);
	m_text.setString(_string);
	m_text.setFillColor(sf::Color::Black);

	timer = 0.f;
}

Bouton::Bouton(sf::Vector2f _pos, sf::Vector2f _size, std::string _string, sf::Color _color)
{
	m_currentState = BOUTON_BASE;

	m_font.loadFromFile("../Files/Fonts/Pokemon.ttf");

	m_shape.setPosition(_pos);
	m_shape.setSize(_size);
	m_shape.setFillColor(_color);

	m_text.setPosition(_pos.x + 20, _pos.y + 20);
	m_text.setString(_string);
	m_text.setFillColor(sf::Color::Black);

	timer = 0.f;
}

bool Bouton::isClicked()
{
	if (m_currentState == BOUTON_CLICKED)
		return true;
	
	return false;
}

void Bouton::useClickAction()
{
	m_onClickAction();
}

void Bouton::Update(const sf::Vector2f mousePos)
{
	timer += GetDeltaTime();
	if (m_shape.getGlobalBounds().contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_shape.setFillColor(sf::Color::Black);
		m_text.setFillColor(sf::Color::White);
		m_currentState = BOUTON_CLICKED;
	}
	else if (m_shape.getGlobalBounds().contains(mousePos))
	{
		m_text.setFillColor(sf::Color(0, 0, 0, 200));
		m_shape.setFillColor(sf::Color(211, 211, 211, 150));
		m_currentState = BOUTON_HOVER;
	}
	else
	{
		m_text.setFillColor(sf::Color::Black);
		m_shape.setFillColor(sf::Color(211, 211, 211, 255));
		m_currentState = BOUTON_BASE;
	}
}

void Bouton::Draw(sf::RenderWindow& _window)
{
	_window.draw(m_shape);
	
	m_text.setFont(m_font);
	_window.draw(m_text);
}

void Bouton::setOnClick(std::function<void()> _function)
{
	m_onClickAction = _function;
}
