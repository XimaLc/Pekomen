#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include "Pokemon.h"

enum BOUTON_STATE { BOUTON_BASE, BOUTON_HOVER, BOUTON_CLICKED};
enum BOUTON_STRING_TYPE { STRING, POKEMON_PATH, POKEMON_BOUTON};


class Bouton
{
	sf::RectangleShape m_shape;
	sf::Text m_text;
	sf::Text m_levelText;

	sf::Color m_color;

	std::function<void()> m_onClickAction;

	int m_currentState;
	int m_boutonType;

	sf::Texture* m_texture;
	sf::Sprite m_sprite;

	static sf::Font m_font;

public:
	float timer;

	Bouton();
	Bouton(sf::Vector2f _pos, sf::Vector2f _size, std::string _string);
	Bouton(sf::Vector2f _pos, sf::Vector2f _size, Pokemon _pokemon);
	Bouton(sf::Vector2f _pos, sf::Vector2f _size, std::string _string, int string_type);
	Bouton(sf::Vector2f _pos, sf::Vector2f _size, std::string _string, sf::Color _color);

	bool isClicked();

	void setPokemon(Pokemon _pokemon, BOUTON_STRING_TYPE _type);
	void useClickAction();

	void setString(std::string _str);

	void setOnClick(std::function<void()> _function);
	void Update(sf::Vector2f mousePos);
	void Draw(sf::RenderWindow& _window);

	~Bouton();
};

