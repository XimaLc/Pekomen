#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include "Pokemon.h"
#include "tools.h"
enum BOUTON_STATE { BOUTON_BASE, BOUTON_HOVER, BOUTON_CLICKED};
enum BOUTON_TYPE { STRING, POKEMON_PATH, POKEMON_BOUTON, POKEBALL_BOUTON};


class Bouton
{
	sf::RectangleShape m_shape;
	sf::Text m_text;

	sf::Text m_levelText;

	sf::Color m_color;

	std::function<void()> m_onClickAction;

	int m_currentState;
	int m_boutonType;

	static sf::Font m_font;
	sf::Sprite m_sprite;
	sf::Texture* m_texture;

public:
	float timer;

	Bouton();
	Bouton(sf::Vector2f _pos, sf::Vector2f _size, std::string _string);
	Bouton(sf::Vector2f _pos, sf::Vector2f _size, Pokemon _pokemon);
	Bouton(sf::Vector2f _pos, sf::Vector2f _size, sf::IntRect, BOUTON_TYPE _boutonType);
	Bouton(sf::Vector2f _pos, sf::Vector2f _size, std::string _string, int string_type);
	Bouton(sf::Vector2f _pos, sf::Vector2f _size, std::string _string, sf::Color _color);

	bool isClicked();
	bool checkClick();

	void setPokemon(Pokemon _pokemon, BOUTON_TYPE _type);
	void useClickAction();

	void setString(std::string _str);

	void setOnClick(std::function<void()> _function);

	void Update(sf::Vector2f mousePos);
	inline void UpdateTimer() { timer += GetDeltaTime(); }

	void Draw(sf::RenderWindow& _window);

	~Bouton();
};

