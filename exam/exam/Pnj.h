#pragma once
#include "Entity.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <functional>

enum PNJ_TYPE {HEALER, TRAINER, SHOP};

class Pnj : public Entity
{
	sf::Texture m_texture;
	std::function<void()> m_function;
public:
	Pnj();
	Pnj(PNJ_TYPE _type, sf::Vector2i _pos);

	

	virtual void Update();
	virtual void Draw(sf::RenderWindow& _window);
	void HandleEvent(sf::Event _event);
};

