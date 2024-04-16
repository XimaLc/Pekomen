#pragma once
#include "MenuState.h"
#include "GameState.h"

enum STATE { MENU, GAME };

class StateManager
{
	State* m_currentState;

public:
	StateManager();

	void ChangeState(int _id);

	void Update();
	void Draw();
};