#include "StateManager.h"

void StateManager::ChangeState(int _id)
{
	switch (_id)
	{
	case MENU:
		m_currentState = new MenuState();
		break;

	case GAME:
		m_currentState = new GameState();
		break;
	}
}