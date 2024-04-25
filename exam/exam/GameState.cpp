#include "GameState.h"
#include "StateManager.h"

GameState::~GameState()
{
}

GameState::GameState()
{
	m_healer = Pnj(HEALER, { 3,0 });

	m_player = new Player();

	gameHasFocus = true;
	hasMove = false;

	timer = 0.f;
	map.setLayersTexture();
	map.load("map");

}

GameState::GameState(Player& _player)
{
	m_player = &_player;
	m_healer = Pnj(HEALER, {3,0});

	gameHasFocus = true;
	hasMove = false;

	timer = 0.f;
	map.setLayersTexture();
	map.load("map");
}

void GameState::Update(sf::Vector2f _mousePos)
{
	if (hasMove)
	{
		hasMove = false;
		if (map.isInGrass(m_player->getPosition()))
		{
			int x = iRand(0, 100);
			if (x < 10)
				StateManager::ChangeState(WILD_POKEMON_STATE);
		}
	}
	timer += GetDeltaTime();
	m_inGameMenu.Update(_mousePos);
}

void GameState::Draw(sf::RenderWindow& _window)
{
	map.Draw(_window, {1, 2, 3, 4, 5});
	m_player->Draw(_window);
	m_healer.Draw(_window);
	m_inGameMenu.Draw(_window);
}

void GameState::HandleKeyboard(sf::Event _event)
{
	if (_event.key.code == sf::Keyboard::E && timer > 0.5f)
	{
		gameHasFocus = !gameHasFocus;
		m_inGameMenu.OpenCloseMenu(m_inGameMenu.isMenuOpen);
		timer = 0;
	}
	if (_event.key.code == sf::Keyboard::F && timer > 0.5f)
	{
		if (m_healer.getPosition() == lookingAt)
		{
			m_player->getTeam()->healAll();
		}
	}
	if (gameHasFocus)
	{
		if (_event.key.code == sf::Keyboard::D && timer > 0.1f)
		{
			if (m_player->getPosition().x < map.getWidth())
				if (map.canGo(m_player->getPosition(), { 1, 0 }))
				{
					m_player->move(1, 0);
					m_player->anim(1, 0);
					lookingAt = { m_player->getPosition().x + 1, m_player->getPosition().y };
					hasMove = true;
				}
			timer = 0.f;
		}
		if (_event.key.code == sf::Keyboard::Q && timer > 0.1f)
		{
			if (m_player->getPosition().x > 0)
				if (map.canGo(m_player->getPosition(), { -1, 0 }))
				{
					m_player->move(-1, 0);
					m_player->anim(-1, 0);
					lookingAt = { m_player->getPosition().x - 1, m_player->getPosition().y };
					hasMove = true;
				}
			timer = 0.f;
		}
		if (_event.key.code == sf::Keyboard::S && timer > 0.1f)
		{
			if (m_player->getPosition().y < map.getHeight())
				if (map.canGo(m_player->getPosition(), { 0, 1 }))
				{
					m_player->move(0, 1);
					m_player->anim(0, 1);
					lookingAt = { m_player->getPosition().x, m_player->getPosition().y + 1};
					hasMove = true;
				}
			timer = 0.f;
		}
		if (_event.key.code == sf::Keyboard::Z && timer > 0.1f)
		{
			if (m_player->getPosition().y > 0)
				if (map.canGo(m_player->getPosition(), { 0, -1 }))
				{
					m_player->move(0, -1);
					m_player->anim(0, -1);
					lookingAt = { m_player->getPosition().x, m_player->getPosition().y - 1 };
					hasMove = true;
				}
			timer = 0.f;
		}
	}
}
