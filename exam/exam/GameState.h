#pragma once
#include "InGameMenu.h"
#include "State.h"
#include "Bouton.h"
#include "Map.h"
#include "Player.h"

#include <SFML/Graphics.hpp>

class GameState : public State
{
	bool gameHasFocus;
	bool hasMove;
	static bool isPlayerInit;

	Player* m_player;

	InGameMenu m_inGameMenu;
	
	Map map;

	static sf::Texture playerTexture;
	
	float timer;
public:
	GameState();
	GameState(Player& _player);

	virtual void Update(sf::Vector2f _mousePos);
	virtual void Draw(sf::RenderWindow& _window);
	virtual void HandleKeyboard(sf::Event _event);
};