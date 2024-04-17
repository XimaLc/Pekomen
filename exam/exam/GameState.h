#pragma once
#include "InGameMenu.h"
#include "State.h"
#include "Bouton.h"
#include <SFML/Graphics.hpp>
class GameState : public State
{
	bool gameAsFocus;
	
	InGameMenu m_inGameMenu;

	float timer;
public:
	GameState();
	
	virtual void Update(sf::Vector2f _mousePos);
	virtual void Draw(sf::RenderWindow& _window);
	virtual void HandleKeyboard(sf::Event _event);
	virtual void HandleEvent(sf::Event _event, sf::RenderWindow& _window);
};