#include "GameState.h"

GameState::GameState()
{
	timer = 0.f;
}

void GameState::Update(sf::Vector2f _mousePos)
{
	timer += GetDeltaTime();
	m_inGameMenu.Update(_mousePos);
}

void GameState::Draw(sf::RenderWindow& _window)
{
	m_inGameMenu.Draw(_window);
}

void GameState::HandleKeyboard(sf::Event _event)
{
	if (_event.key.code == sf::Keyboard::E && timer > 0.5f)
	{
		gameAsFocus = false;
		m_inGameMenu.OpenClose();
		timer = 0;
	}
}

void GameState::HandleEvent(sf::Event _event, sf::RenderWindow& _window)
{
}
