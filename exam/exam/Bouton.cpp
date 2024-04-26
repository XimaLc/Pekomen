#include "Bouton.h"
#include "StateManager.h"
#include "DB.h"

sf::Font Bouton::m_font;

Bouton::Bouton()
{
	m_boutonType = STRING;
	m_currentState = BOUTON_BASE;
	m_texture = nullptr;
	timer = 0.f;
}

Bouton::Bouton(sf::Vector2f _pos, sf::Vector2f _size, std::string _string)
{
	m_currentState = BOUTON_BASE;
	m_boutonType = STRING;

	m_texture = nullptr;

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

Bouton::Bouton(sf::Vector2f _pos, sf::Vector2f _size, Pokemon _pokemon)
{
	m_currentState = BOUTON_BASE;
	m_boutonType = POKEMON_BOUTON;

	m_sprite.setScale(0.35f, 0.35f);
	m_sprite.setPosition(_pos.x + 15, _pos.y + 15);

	m_font.loadFromFile("../Files/Fonts/Pokemon.ttf");

	m_shape.setPosition(_pos);
	m_shape.setSize(_size);
	m_shape.setOutlineColor(sf::Color::Black);
	m_shape.setOutlineThickness(-1.f);

	m_text.setPosition(_pos.x + 220, _pos.y + 300);
	m_text.setFillColor(sf::Color::Black);
	m_text.setCharacterSize(30);

	m_levelText.setPosition(_pos.x + 2, _pos.y + 2);
	m_levelText.setFillColor(sf::Color::Black);
	m_levelText.setCharacterSize(30);

	m_texture = DB::getTexture(_pokemon.getPath());
	
	m_text.setString(std::to_string(_pokemon.getStat(CURRENTHP)) + " / " + std::to_string(_pokemon.getStat(HP)));

	timer = 0.f;
}

Bouton::Bouton(sf::Vector2f _pos, sf::Vector2f _size, sf::IntRect _intRect, BOUTON_TYPE _boutonType)
{
	m_currentState = BOUTON_BASE;
	m_texture = nullptr;
	timer = 0.f;

	m_font.loadFromFile("../Files/Fonts/Pokemon.ttf");

	m_boutonType = _boutonType;
	if (_boutonType == POKEBALL_BOUTON)
	{
		m_currentState = BOUTON_BASE;

		m_shape.setPosition(_pos);
		m_shape.setSize(_size);
		m_shape.setOutlineColor(sf::Color::Black);
		m_shape.setOutlineThickness(-1.f);

		m_texture = DB::getTexture(BALL);

		m_sprite.setTextureRect(_intRect);
		m_sprite.setPosition(_pos.x + 5, _pos.y + 5);

		m_text.setPosition(_pos.x + 80, _pos.y + 20);
		m_text.setFillColor(sf::Color::Black);
		m_text.setCharacterSize(40);
	}
}

Bouton::Bouton(sf::Vector2f _pos, sf::Vector2f _size, std::string _string, int string_type)
{
	m_texture = nullptr;

	m_currentState = BOUTON_BASE;
	m_boutonType = string_type;

	m_font.loadFromFile("../Files/Fonts/Pokemon.ttf");

	m_shape.setPosition(_pos);
	m_shape.setSize(_size);
	m_shape.setOutlineColor(sf::Color::Black);
	m_shape.setOutlineThickness(-1.f);

	if (string_type == POKEMON_PATH)
	{
		m_sprite.setScale(0.35f, 0.35f);
		m_sprite.setPosition(_pos.x + 15, _pos.y + 15);
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

Bouton::Bouton(sf::Vector2f _pos, sf::Vector2f _size, std::string _string, sf::Color _color)
{
	m_texture = nullptr;
	m_boutonType = STRING;

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

bool Bouton::checkClick()
{
	if (m_currentState == BOUTON_CLICKED)
	{
		m_onClickAction();
		return true;
	}

	return false;
}

void Bouton::setPokemon(Pokemon _pokemon, BOUTON_TYPE _type)
{
	m_texture = DB::getTexture(_pokemon.getPath());
	if (_type == POKEMON_BOUTON)
	{
		m_levelText.setString("Lvl. " + std::to_string(_pokemon.getStat(LVL)));
		m_text.setString(std::to_string(_pokemon.getStat(CURRENTHP)) + " / " + std::to_string(_pokemon.getStat(HP)));
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
		else if (m_boutonType == POKEMON_BOUTON)
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
		else if (m_boutonType == POKEMON_BOUTON)
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
		else if (m_boutonType == POKEMON_BOUTON)
		{
			//		
		}
		m_currentState = BOUTON_BASE;
	}
}

void Bouton::Draw(sf::RenderWindow& _window)
{
	_window.draw(m_shape);
	if (m_boutonType == STRING || m_boutonType == POKEBALL_BOUTON || m_boutonType == POKEMON_BOUTON)
	{
		m_text.setFont(m_font);
		_window.draw(m_text);
	}
	
	if (m_boutonType == POKEMON_BOUTON || m_boutonType == POKEMON_PATH || m_boutonType == POKEBALL_BOUTON)
	{
		m_sprite.setTexture(*m_texture);
		_window.draw(m_sprite);
	}

	if (m_boutonType == POKEMON_BOUTON)
	{
		m_levelText.setFont(m_font);
		_window.draw(m_levelText);
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
