#include "GameState.h"
#include "StateManager.h"

GameState::GameState()
{
	timer = 0.f;
	map.setLayersTexture();
	map.load("map");

	playerTexture.loadFromFile("../Files/Textures/player.png");
	player = Player("player", playerTexture);
}

void GameState::Update(sf::Vector2f _mousePos)
{
	if(hasMove)
		if (map.isInGrass(player.getPosition()))
		{
			int x = iRand(0, 10);
			if (x < 3)
				StateManager::ChangeState(WILD_POKEMON);
		}
	timer += GetDeltaTime();
	m_inGameMenu.Update(_mousePos);
}

void GameState::Draw(sf::RenderWindow& _window)
{
	map.Draw(_window, {1, 2, 3, 4, 5});
	player.Draw(_window);
	m_inGameMenu.Draw(_window);
}

void GameState::HandleKeyboard(sf::Event _event)
{
	if (_event.key.code == sf::Keyboard::E && timer > 0.5f)
	{
		gameAsFocus = false;
		m_inGameMenu.OpenCloseMenu(m_inGameMenu.isMenuOpen);
		timer = 0;
	}
	if (_event.key.code == sf::Keyboard::D && timer > 0.1f)
	{
		if (player.getPosition().x < map.getWidth())
			if (map.canGo(player.getPosition(), { 1, 0 }))
			{
				player.move(1, 0);
				player.anim(1, 0);
				hasMove = true;
			}
		timer = 0.f;
	}
	if (_event.key.code == sf::Keyboard::Q && timer > 0.1f)
	{
		if (player.getPosition().x > 0)
			if (map.canGo(player.getPosition(), { -1, 0 }))
			{
				player.move(-1, 0);
				player.anim(-1, 0);
				hasMove = true;
			}
		timer = 0.f;
	}
	if (_event.key.code == sf::Keyboard::S && timer > 0.1f)
	{
		if (player.getPosition().y < map.getHeight())
			if (map.canGo(player.getPosition(), { 0, 1 }))
			{
				player.move(0, 1);
				player.anim(0, 1);
				hasMove = true;
			}
		timer = 0.f;
	}
	if (_event.key.code == sf::Keyboard::Z && timer > 0.1f)
	{
		if (player.getPosition().y > 0)
			if (map.canGo(player.getPosition(), { 0, -1 }))
			{
				player.move(0, -1);
				player.anim(0, -1);
				hasMove = true;
			}
		timer = 0.f;
	}
}

void GameState::HandleEvent(sf::Event _event, sf::RenderWindow& _window)
{
}
