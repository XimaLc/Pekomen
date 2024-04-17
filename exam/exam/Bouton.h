#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

enum BOUTON_STATE { BOUTON_BASE, BOUTON_HOVER, BOUTON_CLICKED};

class Bouton
{
	sf::RectangleShape m_shape;
	sf::Text m_text;
	sf::Color m_color;

	std::function<void()> m_onClickAction;

	int m_currentState;

	static sf::Font m_font;
public:
	float timer;

	Bouton();
	Bouton(sf::Vector2f _pos, sf::Vector2f _size, std::string _string);
	Bouton(sf::Vector2f _pos, sf::Vector2f _size, std::string _string, sf::Color _color);

	bool isClicked();
	
	void useClickAction();

	void setOnClick(std::function<void()> _function);
	void Update(sf::Vector2f mousePos);
	void Draw(sf::RenderWindow& _window);
};

