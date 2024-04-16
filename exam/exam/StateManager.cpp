#include "StateManager.h"

StateManager::StateManager()
{
	m_window  = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Pekomen");
	ChangeState(GAME);
	isRunning = true;
	Update();
}

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

void StateManager::HandleEvent()
{

}

void StateManager::Update()
{
	while (isRunning)
	{
		HandleEvent();
		m_currentState->Update(*m_window);
		Draw();
	}
}

void StateManager::Draw()
{
	m_currentState->Draw(*m_window);
}