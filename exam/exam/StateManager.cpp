#include "StateManager.h"

State* StateManager::m_currentState;

StateManager::StateManager()
{
	m_window  = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Pekomen");
	ChangeState(GAME);
	isRunning = true;
	Loop();
}

void StateManager::ChangeState(int _id)
{
	delete m_currentState;
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

void StateManager::Loop()
{
	while (isRunning)
	{
		restartClock();
		while (m_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window->close();
			else if (event.type == sf::Event::KeyPressed)
				m_currentState->HandleKeyboard(event);
			else
				m_currentState->HandleEvent(event, *m_window);
		}

		mousePos = { static_cast<float>(sf::Mouse::getPosition(*m_window).x), static_cast<float>(sf::Mouse::getPosition(*m_window).y) };

		m_currentState->Update(sf::Vector2f{ mousePos });
		m_window->clear();
		m_currentState->Draw(*m_window);
		m_window->display();	
	}
} 

StateManager::~StateManager()
{
	delete m_currentState;
}