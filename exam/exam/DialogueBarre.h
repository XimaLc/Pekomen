#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class DialogueBarre
{
	sf::Font m_font;
	sf::Text m_text;

	sf::Texture* m_texture;
	sf::Sprite m_sprite;

public:
	float timer;
	bool isOpen;

	DialogueBarre();
	DialogueBarre(sf::Vector2f _pos, int scale, bool _isOpen);
	void setString(std::string _str);
	void Update(bool _closeIt);
	void Draw(sf::RenderWindow& _window);
};

