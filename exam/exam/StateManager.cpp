#include "StateManager.h"
#include "DB.h"

State* StateManager::m_currentState;
GameState* StateManager::gameState;
Player StateManager::m_player;
bool StateManager::isRunning;

StateManager::StateManager()
{
	DB::loadTextures();
	playerTexture.loadFromFile("../Files/Textures/player.png");

	m_player = Player("Player", playerTexture);

	m_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Pekomen", Style::Fullscreen);
	gameState = new GameState(m_player);

	ChangeState(MENU_STATE);
	isRunning = true;
	Loop();
}

void StateManager::ChangeState(int _id)
{
	if (_id == GAME_STATE)
		delete m_currentState;
	switch (_id)
	{
	case MENU_STATE:
		m_currentState = new MenuState(m_player);;
		break;
	case GAME_STATE:
		if(gameState == nullptr)
			gameState = new GameState(m_player);
		m_currentState = gameState;
		break;
	case WILD_POKEMON_STATE:
		m_currentState = new WildPokemonState(m_player);
		break;
	case NEW_GAME_STATE:
		m_currentState = new NewGameState(m_player);
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
	delete gameState;
}