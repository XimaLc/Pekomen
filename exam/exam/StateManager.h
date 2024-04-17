#pragma once
#include <SFML/Graphics.hpp>
#include "MenuState.h"
#include "GameState.h"
#include "tools.h"

enum STATE { MENU, GAME };

class StateManager
{
	static State* m_currentState;

	sf::RenderWindow* m_window;
	sf::Event event;
	sf::Vector2f mousePos;

	bool isRunning;
public:
	StateManager();
	~StateManager();

	static void ChangeState(int _id);

	void Loop();
};