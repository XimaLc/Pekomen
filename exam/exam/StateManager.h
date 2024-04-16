#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "MenuState.h"
#include "GameState.h"

enum STATE { MENU, GAME };

class StateManager
{
	State* m_currentState;
	sf::RenderWindow* m_window;
	bool isRunning;
public:
	StateManager();

	void ChangeState(int _id);
	void HandleEvent();
	void Update();
	void Draw();
};