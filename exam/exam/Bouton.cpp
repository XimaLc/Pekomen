#include "Bouton.h"
#include "tools.h"
#include "StateManager.h"
#include "DB.h"

sf::Font Bouton::m_font;

Bouton::Bouton()
{
	m_currentState = BOUTON_BASE;
	timer = 0.f;
}

Bouton::Bouton(sf::Vector2f _pos, sf::Vector2f _size, std::string _string)
{
	m_currentState = BOUTON_BASE;
	m_boutonType = STRING;

	m_font.loadFromFile("../Files/Fonts/Pokemon.ttf");

	m_shape.setPosition(_pos);
	m_shape.setSize(_size);
	m_shape.setOutlineColor(sf::Color::Black);
	m_shape.setOutlineThickness(-1.f);

	m_text.setPosition(_pos.x + 20, _pos.y + 20);
	m_text.setString(_string);
	m_text.setFillColor(sf::Color::Black);

	timer = 0.f;
}

Bouton::Bouton(sf::Vector2f _pos, sf::Vector2f _size, std::string _string, int string_type)
{
	m_currentState = BOUTON_BASE;
	m_boutonType = POKEMON_PATH;

	m_sprite.setScale(0.35, 0.35);
	m_sprite.setPosition(_pos.x + 15, _pos.y + 15);

	m_font.loadFromFile("../Files/Fonts/Pokemon.ttf");

	m_shape.setPosition(_pos);
	m_shape.setSize(_size);
	m_shape.setOutlineColor(sf::Color::Black);
	m_shape.setOutlineThickness(-1.f);

	if (string_type == POKEMON_PATH)
	{
		m_texture = DB::getTexture(_string);
	}
	else
	{
		m_text.setPosition(_pos.x + 20, _pos.y + 20);
		m_text.setString(_string);
		m_text.setFillColor(sf::Color::Black);
	}

	timer = 0.f;
}

//Bouton::Bouton(sf::Vector2f _pos, sf::Vector2f _size, sf::Sprite _sprite, sf::Vector2f _spriteSize)
//{
//	m_currentState = BOUTON_BASE;
//
//	m_font.loadFromFile("../Files/Fonts/Pokemon.ttf");
//
//	m_shape.setPosition(_pos);
//	m_shape.setSize(_size);
//	m_shape.setOutlineColor(sf::Color::Black);
//	m_shape.setOutlineThickness(-1.f);
//
//	timer = 0.f;
//}

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

void Bouton::setTexture(std::string _path, BOUTON_STRING_TYPE _type)
{
	if (_type == POKEMON_PATH)
	{
		m_texture = DB::getTexture(_path);
	}
}

void Bouton::useClickAction()
{
	m_onClickAction();
}

void Bouton::setString(std::string _str)
{
	m_text.setString(_str);
}

void Bouton::Update(const sf::Vector2f mousePos)
{
	timer += GetDeltaTime();
	if (m_shape.getGlobalBounds().contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_shape.setFillColor(sf::Color::Black);
		if (m_boutonType == STRING)
		{
			m_text.setFillColor(sf::Color::White);

		}
		else if (m_boutonType == POKEMON_PATH)
		{
			//		
		}
		m_currentState = BOUTON_CLICKED;
	}
	else if (m_shape.getGlobalBounds().contains(mousePos))
	{
		m_shape.setFillColor(sf::Color::Black);
		if (m_boutonType == STRING)
		{
			m_text.setFillColor(sf::Color(0, 0, 0, 200));

		}
		else if (m_boutonType == POKEMON_PATH)
		{
			//		
		}
		m_shape.setFillColor(sf::Color(211, 211, 211, 150));
		m_currentState = BOUTON_HOVER;
	}
	else
	{
		m_shape.setFillColor(sf::Color(211, 211, 211, 255));
		if (m_boutonType == STRING)
		{
			m_text.setFillColor(sf::Color::Black);
		}
		else if (m_boutonType == POKEMON_PATH)
		{
			//		
		}
		m_currentState = BOUTON_BASE;
	}
}

void Bouton::Draw(sf::RenderWindow& _window)
{
	_window.draw(m_shape);
	if (m_boutonType == STRING)
	{
		m_text.setFont(m_font);
		_window.draw(m_text);
	}
	else if (m_boutonType == POKEMON_PATH)
	{
		m_sprite.setTexture(*m_texture);
		_window.draw(m_sprite);
	}
}

Bouton::~Bouton()
{
	//if(m_texture != nullptr)
	//	delete m_texture; 
}

void Bouton::setOnClick(std::function<void()> _function)
{
	m_onClickAction = _function;
}
