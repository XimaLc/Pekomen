#pragma once
#include "InGameMenu.h"
#include "State.h"
#include "Bouton.h"
#include "Map.h"
#include "Player.h"

#include <SFML/Graphics.hpp>
class GameState : public State
{
	bool gameAsFocus;
	bool hasMove;

	InGameMenu m_inGameMenu;
	Map map;

	Player player;
	sf::Texture playerTexture;
	
	float timer;
public:
	GameState();

	virtual void Update(sf::Vector2f _mousePos);
	virtual void Draw(sf::RenderWindow& _window);
	virtual void HandleKeyboard(sf::Event _event);
	virtual void HandleEvent(sf::Event _event, sf::RenderWindow& _window);
};